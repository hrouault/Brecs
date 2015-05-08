/* TODO

    [ ] ascii to wide character copy for filenames
    [ ] write multiple frames to tiff
    [ ] test what happens if file already exists
        [ ] test behavior in event of failure
    [ ] test that float pixel type works when lzw is off

    [ ] Decoder

*/

#include <windows.h>
#include <wincodec.h>
#include <strsafe.h>
#include <stdint.h>

#define ERR(e) do{if(!(e)) {onerr(#e,__FILE__,__LINE__,__FUNCTION__); goto Error;}}while(0)
#define CALL(obj,f,...) ERR(SUCCEEDED((obj)->lpVtbl->f((obj),__VA_ARGS__)))
#define CALL0(obj,f)    ERR(SUCCEEDED((obj)->lpVtbl->f(obj)))
#define RELEASE(obj)    (obj)->lpVtbl->Release((obj))

static void onerr(const char* expr,const char*file,int line,const char* function) {
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
                    ,"%s(%d) - %s()\n\tExpression evaluated to false\n\t%s\n\t%s\n"
                    ,file,line,function,expr,emsg);
                    
    OutputDebugString(str);
    MessageBox(0,str,"Error", MB_OK);
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

/* Readers */

uint16_t * opentiff(const char * fname, int * sx, int * sy, int * sz)
{
    init();
exit(-1);
}

float * opentiff_f(const char * fname, int * sx, int * sy, int * sz)
{
    init();
exit(-1);
}

/* Writers */

void writetiff_f(const char * fname, int sx, int sy, int sz, float * img)
{
    init();
exit(-1);
}

void writetiff_gray(const char * fname, int sx, int sy, int sz, uint16_t * img)
{
    init();
    /* Used? -- only by genpsf */
exit(-1);
}

void writetiff_rgb(const char * fname, int sx, int sy, int sz, uint8_t * img)
{
    IWICBitmapEncoder *encoder;
    IWICBitmapFrameEncode *frame;
    IWICStream *stream;
    IPropertyBag2 *props;

    init();

    CALL(factory,CreateEncoder,&GUID_ContainerFormatTiff,NULL,&encoder);
    CALL(factory,CreateStream,&stream);
    CopyFileA(fname,"backup.tmp",FALSE);
    CALL(stream,InitializeFromFilenameA,fname,GENERIC_WRITE);
    CALL(encoder,Initialize,(IStream*)stream,WICBitmapEncoderNoCache);
    CALL(encoder,CreateNewFrame,&frame,&props);

    { 
        /* Set properties: See Note (1) below */
        PROPBAG2 option={0};
        VARIANT v;
        VariantInit(&v);
        v.vt   = VT_UI1;
        v.bVal = WICTiffCompressionLZW;
        option.pstrName=L"TiffCompressionMethod";
        CALL(props,Write,1,&option,&v);
        CALL(frame,Initialize,props);
    }

    CALL(frame,SetSize,sx,sy);
    {
        /* Some pixel formats don't work.  See Note (2) below */
        WICPixelFormatGUID fmt = GUID_WICPixelFormat24bppBGR;
        CALL(frame, SetPixelFormat, &fmt); /* might coerce the requested pixel format */
        ERR(IsEqualGUID(&fmt,&GUID_WICPixelFormat24bppBGR));
    }

    {
        unsigned short* buf=0;
        ERR(buf=VirtualAlloc(NULL,sizeof(*buf)*512*512,MEM_COMMIT,PAGE_READWRITE));
        {for(int i=0;i<512*512;++i) buf[i]=i&0xffff;}
        CALL(frame,WritePixels,512,512*sizeof(*buf),sizeof(*buf)*512*512,(BYTE*)buf);
        VirtualFree(buf,0,MEM_RELEASE);
    }

    CALL0(frame,Commit);
    CALL0(encoder,Commit);

    RELEASE(frame);
    RELEASE(stream);
    RELEASE(encoder);
    DeleteFileA("backup.tmp");
Error:;
    CopyFileA("backup.tmp",fname,FALSE);
    DeleteFileA("backup.tmp");
    exit(-1);
}
