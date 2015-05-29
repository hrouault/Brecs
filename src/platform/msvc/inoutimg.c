

#include <windows.h>
#include <wincodec.h>
#include <strsafe.h>
#include <stdint.h>
#include "brecs_memory.h"

#define ERR(e) do{if(!(e)) {onerr(1,#e,__FILE__,__LINE__,__FUNCTION__); goto Error;}}while(0)
#define WARN(e) do{if(!(e)) {onerr(0,#e,__FILE__,__LINE__,__FUNCTION__); }}while(0)
#define CALL(obj,f,...) ERR(SUCCEEDED((obj)->lpVtbl->f((obj),__VA_ARGS__)))
#define CALL0(obj,f)    ERR(SUCCEEDED((obj)->lpVtbl->f(obj)))
#define RELEASE(obj)    (obj)->lpVtbl->Release((obj))

static void onerr(int iserror,const char* expr,const char*file,int line,const char* function) {
    int ecode=GetLastError();
    char emsg[1024]={0},
         str[1024]={0};
    FormatMessage(  FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
                    0, /* source */
                    ecode, /* id */
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), /* lang id */
                    emsg,
                    sizeof(emsg),
                    0);
    StringCbPrintf(str,sizeof(str)
                    ,"%s(%d) - %s()\n\tExpression evaluated to false\n\t%s\n\tLast Windows Error Message: %s\n"
                    ,file,line,function,expr,emsg);
                    
    OutputDebugString(str);
    MessageBox(0,str,iserror?"Error":"Warning", MB_OK);
    /* PostQuitMessage(1); */ /* Closes windows */
}

static IWICImagingFactory *factory=0;

static void init() {
    if(!factory) {
        CoInitialize(0);
        ERR(SUCCEEDED(CoCreateInstance(&CLSID_WICImagingFactory,0,CLSCTX_INPROC_SERVER,&IID_IWICImagingFactory,&factory)));
    }
    return;
Error:
    exit(-1);
}

/* Not thread safe 

   Assumes the string to convert was received from the console.
*/
static wchar_t* wide(const char* fname) {
    static wchar_t *buf=0;
    static int len=0;
    int n;
    ERR(n=MultiByteToWideChar(GetConsoleCP(),0,fname,(int)strlen(fname),buf,0));
    if(len<n) {
        if(buf)
            VirtualFree(buf,0,MEM_RELEASE);
        ERR(buf=VirtualAlloc(0,(n+1)*sizeof(wchar_t),MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));
        len=n;
    }
    ERR(MultiByteToWideChar(GetConsoleCP(),0,fname,(int)strlen(fname),buf,len));
    return buf;
Error:
    exit(-1);
    return 0;
}

/* Readers */

static void* readtiff_(const char * fname, int * sx_, int * sy_, int * sz_,
                int Bpp, WICPixelFormatGUID pixfmt) {
    unsigned sx,sy,sz;
    uint8_t* buf=0,*img;
    IWICBitmapDecoder *decoder=0;

    init();
    CALL(factory,CreateDecoderFromFilename,
         wide(fname),0,GENERIC_READ,
         WICDecodeMetadataCacheOnDemand,&decoder);
    CALL(decoder,GetFrameCount,&sz);
    { for(unsigned iframe=0;iframe<sz;++iframe,img+=sx*sy*Bpp) {
        IWICBitmapFrameDecode *frame;
        IWICFormatConverter *converter;
        CALL(factory,CreateFormatConverter,&converter);
        CALL(decoder,GetFrame,iframe,&frame); // the frame is an IWICBitmapSource
        if(buf==0) {
            CALL(frame,GetSize,&sx,&sy);
            ERR(buf=brecs_alloc(sx*sy*sz*Bpp));
            img=buf;
        }
        CALL(converter,Initialize,(IWICBitmapSource*)frame,
             &pixfmt,
             WICBitmapDitherTypeNone,
             0,
             0.0f,
             WICBitmapPaletteTypeCustom);
        CALL(converter,CopyPixels,0,sx*Bpp,sx*sy*Bpp,(BYTE*)img);
        RELEASE(converter);
        RELEASE(frame);
    }}
    RELEASE(decoder);
    *sx_=sx;
    *sy_=sy;
    *sz_=sz;
    return buf;
Error:;
    return 0;
}

uint16_t * opentiff(const char * fname, int * sx, int * sy, int * sz)
{
    return readtiff_(fname,sx,sy,sz,2,GUID_WICPixelFormat16bppGray);
}

float * opentiff_f(const char * fname, int * sx, int * sy, int * sz)
{
    return readtiff_(fname,sx,sy,sz,4,GUID_WICPixelFormat32bppGrayFloat);
}

/* Writers */

static void writetiff_(const char * fname, int sx, int sy, int sz, 
                  uint8_t * img, int Bpp,
                  WICPixelFormatGUID pixfmt,
                  enum WICTiffCompressionOption compression) {
    IWICBitmapEncoder *encoder;
    IWICBitmapFrameEncode *frame;
    IWICStream *stream;
    IPropertyBag2 *props;
    const unsigned plane_stride_bytes = Bpp*sx*sy;

    init();

    CALL(factory,CreateEncoder,&GUID_ContainerFormatTiff,NULL,&encoder);
    CALL(factory,CreateStream,&stream);
    //CopyFileA(fname,"backup.tmp",FALSE);
    CALL(stream,InitializeFromFilename,wide(fname),GENERIC_WRITE);
    CALL(encoder,Initialize,(IStream*)stream,WICBitmapEncoderNoCache);

    { for(int z=0;z<sz;++z,img+=plane_stride_bytes){
        CALL(encoder,CreateNewFrame,&frame,&props);
        { 
            /* Set properties: See Note (1) below */
            PROPBAG2 option={0};
            VARIANT v;
            VariantInit(&v);
            v.vt   = VT_UI1;
            v.bVal = compression;
            option.pstrName=L"TiffCompressionMethod";
            CALL(props,Write,1,&option,&v);
        }
        CALL(frame,Initialize,props);
        CALL(frame,SetSize,sx,sy);
        {
            /* Some pixel formats don't work. */
            WICPixelFormatGUID fmt = pixfmt;
            CALL(frame, SetPixelFormat, &fmt); /* might coerce the requested pixel format */
            WARN(IsEqualGUID(&fmt,&pixfmt));
        }
        CALL(frame,WritePixels,sy,sx*Bpp,plane_stride_bytes,(BYTE*)img);
        CALL0(frame,Commit);
    }}

    CALL0(encoder,Commit);

    RELEASE(frame);
    RELEASE(stream);
    RELEASE(encoder);
    //DeleteFileA("backup.tmp");
Error:;
    //CopyFileA("backup.tmp",fname,FALSE);
    //DeleteFileA("backup.tmp");
    exit(-1);

}

void writetiff_f(const char * fname, int sx, int sy, int sz, float * img)
{
    writetiff_(fname,sx,sy,sz,(uint8_t*)img,4,
               GUID_WICPixelFormat32bppGrayFloat,WICTiffCompressionNone);
}

/* Used? -- only by genpsf */
void writetiff_gray(const char * fname, int sx, int sy, int sz, uint16_t * img)
{
    writetiff_(fname,sx,sy,sz,(uint8_t*)img,2,
               GUID_WICPixelFormat16bppGray,WICTiffCompressionDontCare);
}

void writetiff_rgb(const char * fname, int sx, int sy, int sz, uint8_t * img)
{
    //writetiff_(fname,sx,sy,sz,img,3,GUID_WICPixelFormat24bppBGR,WICTiffCompressionNone);
    //writetiff_(fname,sx,sy,sz,img,3,GUID_WICPixelFormat24bppBGR,WICTiffCompressionLZW);
    writetiff_(fname,sx,sy,sz,img,3,
               GUID_WICPixelFormat24bppBGR,WICTiffCompressionDontCare);
}


/* TODO (ngc: May 2015)
[x] ascii to wide character copy for filenames
[x] write multiple frames to tiff
[x] test what happens if file already exists
[~] test behavior in event of failure
    Leave off by default.  Can comment back in if desired and in a position to test.
[x] encoding a float pixel type does NOT work with WIC at the moment.
    I think it coerces to grey16

[x] Decoder
[x] Buffer allocation for decoder: which allocator to choose? which free 
    is used?
*/