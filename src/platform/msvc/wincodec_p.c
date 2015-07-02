

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri May 08 17:33:54 2015
 */
/* Compiler settings for wincodec.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "wincodec.h"

#define TYPE_FORMAT_STRING_SIZE   4135                              
#define PROC_FORMAT_STRING_SIZE   8141                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   6            

typedef struct _wincodec_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } wincodec_MIDL_TYPE_FORMAT_STRING;

typedef struct _wincodec_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } wincodec_MIDL_PROC_FORMAT_STRING;

typedef struct _wincodec_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } wincodec_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const wincodec_MIDL_TYPE_FORMAT_STRING wincodec__MIDL_TypeFormatString;
extern const wincodec_MIDL_PROC_FORMAT_STRING wincodec__MIDL_ProcFormatString;
extern const wincodec_MIDL_EXPR_FORMAT_STRING wincodec__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPalette_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPalette_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapSource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapSource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICFormatConverter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICFormatConverter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPlanarFormatConverter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPlanarFormatConverter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapScaler_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapScaler_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapClipper_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapClipper_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapFlipRotator_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapFlipRotator_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapLock_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapLock_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmap_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmap_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICColorContext_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICColorContext_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICColorTransform_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICColorTransform_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICFastMetadataEncoder_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICFastMetadataEncoder_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICEnumMetadataItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICEnumMetadataItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICMetadataQueryReader_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICMetadataQueryReader_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICMetadataQueryWriter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICMetadataQueryWriter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapEncoder_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapEncoder_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapFrameEncode_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapFrameEncode_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPlanarBitmapFrameEncode_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPlanarBitmapFrameEncode_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapDecoder_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapDecoder_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapSourceTransform_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapSourceTransform_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPlanarBitmapSourceTransform_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPlanarBitmapSourceTransform_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapFrameDecode_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapFrameDecode_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICProgressiveLevelControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICProgressiveLevelControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICProgressCallback_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICProgressCallback_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapCodecProgressNotification_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapCodecProgressNotification_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IWICBitmapCodecProgressNotification_Remote_RegisterProgressNotification_Proxy( 
    IWICBitmapCodecProgressNotification * This,
    /* [unique][in] */ IWICProgressCallback *pICallback,
    /* [in] */ DWORD dwProgressFlags)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &wincodec__MIDL_ProcFormatString.Format[3952],
                  ( unsigned char * )This,
                  pICallback,
                  dwProgressFlags);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IWICBitmapCodecProgressNotification_Remote_RegisterProgressNotification_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IWICBitmapCodecProgressNotification *This;
        IWICProgressCallback *pICallback;
        DWORD dwProgressFlags;
        char Pad0[4];
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IWICBitmapCodecProgressNotification_RegisterProgressNotification_Stub(
                                                                                (IWICBitmapCodecProgressNotification *) pParamStruct->This,
                                                                                pParamStruct->pICallback,
                                                                                pParamStruct->dwProgressFlags);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICComponentInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICComponentInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICFormatConverterInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICFormatConverterInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapCodecInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapCodecInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapEncoderInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapEncoderInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICBitmapDecoderInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICBitmapDecoderInfo_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IWICBitmapDecoderInfo_Remote_GetPatterns_Proxy( 
    IWICBitmapDecoderInfo * This,
    /* [size_is][size_is][out] */ WICBitmapPattern **ppPatterns,
    /* [out] */ UINT *pcPatterns)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &wincodec__MIDL_ProcFormatString.Format[4970],
                  ( unsigned char * )This,
                  ppPatterns,
                  pcPatterns);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IWICBitmapDecoderInfo_Remote_GetPatterns_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IWICBitmapDecoderInfo *This;
        WICBitmapPattern **ppPatterns;
        UINT *pcPatterns;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IWICBitmapDecoderInfo_GetPatterns_Stub(
                                                 (IWICBitmapDecoderInfo *) pParamStruct->This,
                                                 pParamStruct->ppPatterns,
                                                 pParamStruct->pcPatterns);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPixelFormatInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPixelFormatInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICPixelFormatInfo2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICPixelFormatInfo2_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICImagingFactory_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICImagingFactory_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICDevelopRawNotificationCallback_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICDevelopRawNotificationCallback_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICDevelopRaw_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICDevelopRaw_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IWICDevelopRaw_Remote_QueryRawCapabilitiesInfo_Proxy( 
    IWICDevelopRaw * This,
    /* [out][in] */ WICRawCapabilitiesInfo *pInfo)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &wincodec__MIDL_ProcFormatString.Format[6594],
                  ( unsigned char * )This,
                  pInfo);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IWICDevelopRaw_Remote_QueryRawCapabilitiesInfo_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IWICDevelopRaw *This;
        WICRawCapabilitiesInfo *pInfo;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IWICDevelopRaw_QueryRawCapabilitiesInfo_Stub((IWICDevelopRaw *) pParamStruct->This,pParamStruct->pInfo);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IWICDevelopRaw_Remote_SetToneCurve_Proxy( 
    IWICDevelopRaw * This,
    /* [in] */ UINT cPoints,
    /* [size_is][in] */ const WICRawToneCurvePoint *aPoints)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &wincodec__MIDL_ProcFormatString.Format[7542],
                  ( unsigned char * )This,
                  cPoints,
                  aPoints);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IWICDevelopRaw_Remote_SetToneCurve_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IWICDevelopRaw *This;
        UINT cPoints;
        char Pad0[4];
        const WICRawToneCurvePoint *aPoints;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IWICDevelopRaw_SetToneCurve_Stub(
                                           (IWICDevelopRaw *) pParamStruct->This,
                                           pParamStruct->cPoints,
                                           pParamStruct->aPoints);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IWICDevelopRaw_Remote_GetToneCurve_Proxy( 
    IWICDevelopRaw * This,
    /* [out] */ UINT *pcPoints,
    /* [size_is][size_is][out] */ WICRawToneCurvePoint **paPoints)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &wincodec__MIDL_ProcFormatString.Format[7586],
                  ( unsigned char * )This,
                  pcPoints,
                  paPoints);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IWICDevelopRaw_Remote_GetToneCurve_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IWICDevelopRaw *This;
        UINT *pcPoints;
        WICRawToneCurvePoint **paPoints;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IWICDevelopRaw_GetToneCurve_Stub(
                                           (IWICDevelopRaw *) pParamStruct->This,
                                           pParamStruct->pcPoints,
                                           pParamStruct->paPoints);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICDdsDecoder_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICDdsDecoder_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICDdsEncoder_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICDdsEncoder_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWICDdsFrameDecode_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWICDdsFrameDecode_ProxyInfo;


extern const EXPR_EVAL ExprEvalRoutines[];
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const wincodec_MIDL_PROC_FORMAT_STRING wincodec__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure InitializePredefined */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0xe ),	/* 14 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ePaletteType */

/* 26 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 28 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 30 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter fAddTransparentColor */

/* 32 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeCustom */

/* 44 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x4 ),	/* 4 */
/* 52 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	NdrFcShort( 0x8 ),	/* 8 */
/* 58 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 60 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x1 ),	/* 1 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pColors */

/* 70 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 72 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 74 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter cCount */

/* 76 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 78 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 80 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 82 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 84 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 86 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromBitmap */

/* 88 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 90 */	NdrFcLong( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x5 ),	/* 5 */
/* 96 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 98 */	NdrFcShort( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 102 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pISurface */

/* 114 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 118 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter cCount */

/* 120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 122 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter fAddTransparentColor */

/* 126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 134 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyPalette */


	/* Procedure InitializeFromPalette */

/* 138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x6 ),	/* 6 */
/* 146 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIPalette */


	/* Parameter pIPalette */

/* 164 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 168 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */


	/* Return value */

/* 170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 172 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetType */

/* 176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x7 ),	/* 7 */
/* 184 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x22 ),	/* 34 */
/* 190 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 192 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pePaletteType */

/* 202 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 206 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 210 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetExifColorSpace */


	/* Procedure GetColorCount */

/* 214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 222 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x24 ),	/* 36 */
/* 228 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 230 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */


	/* Parameter pcCount */

/* 240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColors */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x9 ),	/* 9 */
/* 260 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	NdrFcShort( 0x24 ),	/* 36 */
/* 266 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 268 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 270 */	NdrFcShort( 0x1 ),	/* 1 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cCount */

/* 278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pColors */

/* 284 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 288 */	NdrFcShort( 0x42 ),	/* Type Offset=66 */

	/* Parameter pcActualColors */

/* 290 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 292 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 298 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsBlackWhite */

/* 302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0xa ),	/* 10 */
/* 310 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x24 ),	/* 36 */
/* 316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 318 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfIsBlackWhite */

/* 328 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 336 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsGrayscale */

/* 340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0xb ),	/* 11 */
/* 348 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x24 ),	/* 36 */
/* 354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 356 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfIsGrayscale */

/* 366 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFrameCount */


	/* Procedure HasAlpha */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0xc ),	/* 12 */
/* 386 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x24 ),	/* 36 */
/* 392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 394 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCount */


	/* Parameter pfHasAlpha */

/* 404 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 406 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 412 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSizeInBlocks */


	/* Procedure GetSize */


	/* Procedure GetSize */

/* 416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x3 ),	/* 3 */
/* 424 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0x40 ),	/* 64 */
/* 430 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 432 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWidthInBlocks */


	/* Parameter puiWidth */


	/* Parameter puiWidth */

/* 442 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHeightInBlocks */


	/* Parameter puiHeight */


	/* Parameter puiHeight */

/* 448 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 450 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 456 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCLSID */


	/* Procedure GetContainerFormat */


	/* Procedure GetPixelFormat */

/* 460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x4 ),	/* 4 */
/* 468 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x4c ),	/* 76 */
/* 474 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 476 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pclsid */


	/* Parameter pguidContainerFormat */


	/* Parameter pPixelFormat */

/* 486 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 490 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResolution */

/* 498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x5 ),	/* 5 */
/* 506 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x50 ),	/* 80 */
/* 512 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 514 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDpiX */

/* 524 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 528 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pDpiY */

/* 530 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 532 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 534 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 538 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyPixels */

/* 542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x7 ),	/* 7 */
/* 550 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 552 */	NdrFcShort( 0x44 ),	/* 68 */
/* 554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 556 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 558 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 560 */	NdrFcShort( 0x1 ),	/* 1 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prc */

/* 568 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 570 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 572 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter cbStride */

/* 574 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 576 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbBufferSize */

/* 580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 582 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbBuffer */

/* 586 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 588 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 590 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Return value */

/* 592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 594 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 606 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 608 */	NdrFcShort( 0x60 ),	/* 96 */
/* 610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 612 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 614 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x800 ),	/* 2048 */

	/* Parameter pISource */

/* 624 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 628 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter dstFormat */

/* 630 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 632 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 634 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter dither */

/* 636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 638 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 640 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pIPalette */

/* 642 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 644 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 646 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter alphaThresholdPercent */

/* 648 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 650 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 652 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter paletteTranslate */

/* 654 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 656 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 658 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 662 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CanConvert */

/* 666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x9 ),	/* 9 */
/* 674 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 676 */	NdrFcShort( 0x88 ),	/* 136 */
/* 678 */	NdrFcShort( 0x24 ),	/* 36 */
/* 680 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 682 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter srcPixelFormat */

/* 692 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 696 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter dstPixelFormat */

/* 698 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 700 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 702 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter pfCanConvert */

/* 704 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 706 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 712 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 724 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 726 */	NdrFcShort( 0x68 ),	/* 104 */
/* 728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 730 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 732 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x1 ),	/* 1 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x2000 ),	/* 8192 */

	/* Parameter ppPlanes */

/* 742 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 746 */	NdrFcShort( 0x8e ),	/* Type Offset=142 */

	/* Parameter cPlanes */

/* 748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 750 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dstFormat */

/* 754 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 756 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 758 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter dither */

/* 760 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 762 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 764 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pIPalette */

/* 766 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 768 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 770 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Parameter alphaThresholdPercent */

/* 772 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 774 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 776 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter paletteTranslate */

/* 778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 780 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 782 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 784 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 786 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CanConvert */

/* 790 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x9 ),	/* 9 */
/* 798 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 800 */	NdrFcShort( 0x4c ),	/* 76 */
/* 802 */	NdrFcShort( 0x24 ),	/* 36 */
/* 804 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 806 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSrcPixelFormats */

/* 816 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 820 */	NdrFcShort( 0xa8 ),	/* Type Offset=168 */

	/* Parameter cSrcPlanes */

/* 822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 824 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dstPixelFormat */

/* 828 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 830 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 832 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter pfCanConvert */

/* 834 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 836 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 856 */	NdrFcShort( 0x16 ),	/* 22 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 862 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pISource */

/* 872 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 874 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 876 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter uiWidth */

/* 878 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 880 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 886 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mode */

/* 890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 892 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 894 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 898 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 910 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 912 */	NdrFcShort( 0x34 ),	/* 52 */
/* 914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 916 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pISource */

/* 928 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 930 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 932 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter prc */

/* 934 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 938 */	NdrFcShort( 0x6c ),	/* Type Offset=108 */

	/* Return value */

/* 940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 942 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 956 */	NdrFcShort( 0x6 ),	/* 6 */
/* 958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 960 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 962 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pISource */

/* 972 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 976 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter options */

/* 978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 980 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 982 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentLevel */


	/* Procedure GetStride */

/* 990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x4 ),	/* 4 */
/* 998 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1004 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1006 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pnLevel */


	/* Parameter pcbStride */

/* 1016 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDataPointer */

/* 1028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1036 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1042 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1044 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcbBufferSize */

/* 1054 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1056 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppbData */

/* 1060 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1062 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1064 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Return value */

/* 1066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1068 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPixelFormat */

/* 1072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1080 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1086 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1088 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPixelFormat */

/* 1098 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1102 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Lock */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1118 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1120 */	NdrFcShort( 0x3c ),	/* 60 */
/* 1122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1124 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1126 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prcLock */

/* 1136 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 1138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1140 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter flags */

/* 1142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1144 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppILock */

/* 1148 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1150 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1152 */	NdrFcShort( 0xd2 ),	/* Type Offset=210 */

	/* Return value */

/* 1154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1156 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPalette */

/* 1160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1168 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1174 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1176 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIPalette */

/* 1186 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1190 */	NdrFcShort( 0x24 ),	/* Type Offset=36 */

	/* Return value */

/* 1192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1194 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResolution */

/* 1198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0xa ),	/* 10 */
/* 1206 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1208 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1214 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0x28 ),	/* 40 */

	/* Parameter dpiX */

/* 1224 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1228 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dpiY */

/* 1230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1232 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1234 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromFilename */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1250 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1256 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1258 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzFilename */

/* 1268 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1270 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1272 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Return value */

/* 1274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1276 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromMemory */

/* 1280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1288 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1294 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1296 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbBuffer */

/* 1306 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1310 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Parameter cbBufferSize */

/* 1312 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1314 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1320 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCurrentLevel */


	/* Procedure InitializeFromExifColorSpace */

/* 1324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1332 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1340 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nLevel */


	/* Parameter value */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetType */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1370 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1378 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 1388 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 1390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1392 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 1394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1396 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetProfileBytes */

/* 1400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1408 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1414 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1416 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1420 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cbBuffer */

/* 1426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbBuffer */

/* 1432 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 1434 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1436 */	NdrFcShort( 0xfc ),	/* Type Offset=252 */

	/* Parameter pcbActual */

/* 1438 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1440 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1446 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 1450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1458 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1460 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1466 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIBitmapSource */

/* 1476 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1480 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter pIContextSource */

/* 1482 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1484 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1486 */	NdrFcShort( 0x10c ),	/* Type Offset=268 */

	/* Parameter pIContextDest */

/* 1488 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1490 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1492 */	NdrFcShort( 0x10c ),	/* Type Offset=268 */

	/* Parameter pixelFmtDest */

/* 1494 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1496 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1498 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1514 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMetadataQueryWriter */

/* 1538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1546 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1552 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1554 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIMetadataQueryWriter */

/* 1564 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1568 */	NdrFcShort( 0x11e ),	/* Type Offset=286 */

	/* Return value */

/* 1570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1572 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromIStream */

/* 1576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0xe ),	/* 14 */
/* 1584 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1590 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1592 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 1602 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1604 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1606 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Return value */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromFilename */

/* 1614 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0xf ),	/* 15 */
/* 1622 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1626 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1628 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1630 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzFileName */

/* 1640 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1642 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1644 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter dwDesiredAccess */

/* 1646 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1648 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1654 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromMemory */

/* 1658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1666 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1668 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1672 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1674 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbBuffer */

/* 1684 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1688 */	NdrFcShort( 0x148 ),	/* Type Offset=328 */

	/* Parameter cbBufferSize */

/* 1690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1692 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1698 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitializeFromIStreamRegion */

/* 1702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1710 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1712 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1716 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1718 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 1728 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1732 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Parameter ulOffset */

/* 1734 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1736 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1738 */	NdrFcShort( 0x152 ),	/* Type Offset=338 */

	/* Parameter ulMaxSize */

/* 1740 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1742 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1744 */	NdrFcShort( 0x152 ),	/* Type Offset=338 */

	/* Return value */

/* 1746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1748 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 1752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1760 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 1762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1764 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1766 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1768 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1770 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1772 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 1778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1780 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgeltSchema */

/* 1784 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 1786 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1788 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter rgeltId */

/* 1790 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1792 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1794 */	NdrFcShort( 0xa62 ),	/* Type Offset=2658 */

	/* Parameter rgeltValue */

/* 1796 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 1798 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1800 */	NdrFcShort( 0xa62 ),	/* Type Offset=2658 */

	/* Parameter pceltFetched */

/* 1802 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1804 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1810 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */

/* 1814 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1820 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1822 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1828 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1830 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 1840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1842 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1848 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1860 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1866 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1868 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1892 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1898 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1900 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIEnumMetadataItem */

/* 1910 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1912 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1914 */	NdrFcShort( 0xa7c ),	/* Type Offset=2684 */

	/* Return value */

/* 1916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1918 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContainerFormat */

/* 1922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1930 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1934 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1936 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1938 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pguidContainerFormat */

/* 1948 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1952 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 1954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLocation */

/* 1960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1968 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1972 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1974 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1976 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1978 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1980 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchMaxLength */

/* 1986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzNamespace */

/* 1992 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 1994 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1996 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActualLength */

/* 1998 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2000 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMetadataByName */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2018 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2026 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2028 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2030 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzName */

/* 2036 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2038 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2040 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter pvarValue */

/* 2042 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 2044 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2046 */	NdrFcShort( 0xaa2 ),	/* Type Offset=2722 */

	/* Return value */

/* 2048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2050 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEnumerator */

/* 2054 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2060 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2062 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2068 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2070 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIEnumString */

/* 2080 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2084 */	NdrFcShort( 0xaa6 ),	/* Type Offset=2726 */

	/* Return value */

/* 2086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2088 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMetadataByName */

/* 2092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2098 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2100 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2106 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2108 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzName */

/* 2118 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2122 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter pvarValue */

/* 2124 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2126 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2128 */	NdrFcShort( 0xa50 ),	/* Type Offset=2640 */

	/* Return value */

/* 2130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2132 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveMetadataByName */

/* 2136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2144 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2150 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2152 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzName */

/* 2162 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2166 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Return value */

/* 2168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2170 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 2174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2182 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2184 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2188 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2190 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 2200 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2204 */	NdrFcShort( 0x134 ),	/* Type Offset=308 */

	/* Parameter cacheOption */

/* 2206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2208 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2210 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 2212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2214 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEncoderInfo */

/* 2218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2224 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2226 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2232 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2234 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIEncoderInfo */

/* 2244 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2248 */	NdrFcShort( 0xac0 ),	/* Type Offset=2752 */

	/* Return value */

/* 2250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColorContexts */

/* 2256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2264 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2270 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2272 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2276 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cCount */

/* 2282 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIColorContext */

/* 2288 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2290 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2292 */	NdrFcShort( 0xaec ),	/* Type Offset=2796 */

	/* Return value */

/* 2294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2296 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyPalette */


	/* Procedure SetPalette */

/* 2300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2308 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2314 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2316 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIPalette */


	/* Parameter pIPalette */

/* 2326 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2328 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2330 */	NdrFcShort( 0xb02 ),	/* Type Offset=2818 */

	/* Return value */


	/* Return value */

/* 2332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2334 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThumbnail */

/* 2338 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2346 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2352 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2354 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIThumbnail */

/* 2364 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2368 */	NdrFcShort( 0xb14 ),	/* Type Offset=2836 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThumbnail */


	/* Procedure SetPreview */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2384 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2392 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIThumbnail */


	/* Parameter pIPreview */

/* 2402 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2406 */	NdrFcShort( 0xb14 ),	/* Type Offset=2836 */

	/* Return value */


	/* Return value */

/* 2408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateNewFrame */

/* 2414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0xa ),	/* 10 */
/* 2422 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2428 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2430 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2438 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIFrameEncode */

/* 2440 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2444 */	NdrFcShort( 0xb26 ),	/* Type Offset=2854 */

	/* Parameter ppIEncoderOptions */

/* 2446 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2448 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2450 */	NdrFcShort( 0xb3c ),	/* Type Offset=2876 */

	/* Return value */

/* 2452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2454 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 2458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0xb ),	/* 11 */
/* 2466 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2474 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMetadataQueryWriter */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0xc ),	/* 12 */
/* 2498 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2504 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2506 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIMetadataQueryWriter */

/* 2516 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2520 */	NdrFcShort( 0xb52 ),	/* Type Offset=2898 */

	/* Return value */

/* 2522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2524 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 2528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2534 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2536 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2542 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2544 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIEncoderOptions */

/* 2554 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2558 */	NdrFcShort( 0xb40 ),	/* Type Offset=2880 */

	/* Return value */

/* 2560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */

/* 2566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2574 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2576 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2580 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2582 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uiWidth */

/* 2592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 2598 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2600 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2606 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetResolution */

/* 2610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2618 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2620 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2624 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2634 */	NdrFcShort( 0x28 ),	/* 40 */

	/* Parameter dpiX */

/* 2636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2640 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter dpiY */

/* 2642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2644 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2646 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2650 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPixelFormat */

/* 2654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2662 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2664 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2666 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2670 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPixelFormat */

/* 2680 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 2682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2684 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 2686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2688 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColorContexts */

/* 2692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2700 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2706 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2708 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cCount */

/* 2718 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIColorContext */

/* 2724 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2726 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2728 */	NdrFcShort( 0xaec ),	/* Type Offset=2796 */

	/* Return value */

/* 2730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2732 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPalette */

/* 2736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2744 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2750 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIPalette */

/* 2762 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2766 */	NdrFcShort( 0xb02 ),	/* Type Offset=2818 */

	/* Return value */

/* 2768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WritePixels */

/* 2774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2780 */	NdrFcShort( 0xa ),	/* 10 */
/* 2782 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 2784 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2788 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2790 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2794 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lineCount */

/* 2800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbStride */

/* 2806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbBufferSize */

/* 2812 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2814 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbPixels */

/* 2818 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2820 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2822 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Return value */

/* 2824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2826 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteSource */

/* 2830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2836 */	NdrFcShort( 0xb ),	/* 11 */
/* 2838 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2840 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2844 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2846 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIBitmapSource */

/* 2856 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2858 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2860 */	NdrFcShort( 0xb14 ),	/* Type Offset=2836 */

	/* Parameter prc */

/* 2862 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 2864 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2866 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Return value */

/* 2868 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2870 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 2874 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2880 */	NdrFcShort( 0xc ),	/* 12 */
/* 2882 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2888 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2890 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMetadataQueryWriter */

/* 2906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0xd ),	/* 13 */
/* 2914 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2920 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIMetadataQueryWriter */

/* 2932 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2936 */	NdrFcShort( 0xb52 ),	/* Type Offset=2898 */

	/* Return value */

/* 2938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2940 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WritePixels */

/* 2944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2950 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2952 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2954 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2958 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2960 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lineCount */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPlanes */

/* 2976 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2978 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2980 */	NdrFcShort( 0xb8c ),	/* Type Offset=2956 */

	/* Parameter cPlanes */

/* 2982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2984 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2990 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteSource */

/* 2994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3002 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3004 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3008 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3010 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPlanes */

/* 3020 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3024 */	NdrFcShort( 0xba6 ),	/* Type Offset=2982 */

	/* Parameter cPlanes */

/* 3026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3028 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter prcSource */

/* 3032 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3034 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3036 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Return value */

/* 3038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3040 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryCapability */

/* 3044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3050 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3052 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3058 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3060 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 3070 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3074 */	NdrFcShort( 0xbbc ),	/* Type Offset=3004 */

	/* Parameter pdwCapability */

/* 3076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3078 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3084 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Initialize */

/* 3088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3094 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3096 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3098 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3102 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 3114 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3118 */	NdrFcShort( 0xbbc ),	/* Type Offset=3004 */

	/* Parameter cacheOptions */

/* 3120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3122 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3124 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 3126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContainerFormat */

/* 3132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3140 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3148 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pguidContainerFormat */

/* 3158 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3162 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 3164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3166 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDecoderInfo */

/* 3170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3178 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3184 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3186 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIDecoderInfo */

/* 3196 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3200 */	NdrFcShort( 0xbce ),	/* Type Offset=3022 */

	/* Return value */

/* 3202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3204 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMetadataQueryReader */


	/* Procedure GetMetadataQueryReader */

/* 3208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3216 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3222 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIMetadataQueryReader */


	/* Parameter ppIMetadataQueryReader */

/* 3234 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3238 */	NdrFcShort( 0xbe4 ),	/* Type Offset=3044 */

	/* Return value */


	/* Return value */

/* 3240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3242 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreview */

/* 3246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3252 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3254 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3260 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapSource */

/* 3272 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3276 */	NdrFcShort( 0xbfa ),	/* Type Offset=3066 */

	/* Return value */

/* 3278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColorContexts */

/* 3284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3290 */	NdrFcShort( 0xa ),	/* 10 */
/* 3292 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3296 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3298 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3300 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3302 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3304 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cCount */

/* 3310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3312 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIColorContexts */

/* 3316 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 3318 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3320 */	NdrFcShort( 0xbfe ),	/* Type Offset=3070 */

	/* Parameter pcActualCount */

/* 3322 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3324 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3330 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetThumbnail */

/* 3334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3340 */	NdrFcShort( 0xb ),	/* 11 */
/* 3342 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3348 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3350 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIThumbnail */

/* 3360 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3364 */	NdrFcShort( 0xbfa ),	/* Type Offset=3066 */

	/* Return value */

/* 3366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3368 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFrame */

/* 3372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0xd ),	/* 13 */
/* 3380 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3386 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3388 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 3398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIBitmapFrame */

/* 3404 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3406 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3408 */	NdrFcShort( 0xc18 ),	/* Type Offset=3096 */

	/* Return value */

/* 3410 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3412 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyPixels */

/* 3416 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3424 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 3426 */	NdrFcShort( 0x9e ),	/* 158 */
/* 3428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3430 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x9,		/* 9 */
/* 3432 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3434 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prc */

/* 3442 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3446 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter uiWidth */

/* 3448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3450 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 3454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3456 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pguidDstFormat */

/* 3460 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3462 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3464 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter dstTransform */

/* 3466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3468 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3470 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter nStride */

/* 3472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3474 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbBufferSize */

/* 3478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3480 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbBuffer */

/* 3484 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3486 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3488 */	NdrFcShort( 0xc36 ),	/* Type Offset=3126 */

	/* Return value */

/* 3490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3492 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClosestSize */

/* 3496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3504 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3506 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3508 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3510 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3512 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter puiWidth */

/* 3522 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3524 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puiHeight */

/* 3528 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3530 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3536 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClosestPixelFormat */

/* 3540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3546 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3548 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3550 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3552 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3554 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3556 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pguidDstFormat */

/* 3566 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 3568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3570 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 3572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3574 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesSupportTransform */

/* 3578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3584 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3586 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3588 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3590 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3592 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3594 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dstTransform */

/* 3604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3608 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pfIsSupported */

/* 3610 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3612 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3616 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3618 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesSupportTransform */

/* 3622 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3630 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
/* 3632 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3634 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3636 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3638 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3640 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3642 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3646 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter puiWidth */

/* 3648 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter puiHeight */

/* 3654 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3656 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dstTransform */

/* 3660 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3662 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3664 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dstPlanarOptions */

/* 3666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3668 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3670 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pguidDstFormats */

/* 3672 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3674 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3676 */	NdrFcShort( 0xc4a ),	/* Type Offset=3146 */

	/* Parameter pPlaneDescriptions */

/* 3678 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3680 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3682 */	NdrFcShort( 0xc70 ),	/* Type Offset=3184 */

	/* Parameter cPlanes */

/* 3684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3686 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pfIsSupported */

/* 3690 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3692 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3698 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyPixels */

/* 3702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3708 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3710 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 3712 */	NdrFcShort( 0x58 ),	/* 88 */
/* 3714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3716 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 3718 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3722 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prcSource */

/* 3728 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3732 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter uiWidth */

/* 3734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3736 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 3740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3742 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dstTransform */

/* 3746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3748 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3750 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dstPlanarOptions */

/* 3752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3754 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3756 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pDstPlanes */

/* 3758 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3760 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 3762 */	NdrFcShort( 0xc8a ),	/* Type Offset=3210 */

	/* Parameter cPlanes */

/* 3764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3766 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3772 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 3774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColorContexts */

/* 3776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3782 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3784 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3788 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3790 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3792 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3794 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3796 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cCount */

/* 3802 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIColorContexts */

/* 3808 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 3810 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3812 */	NdrFcShort( 0xbfe ),	/* Type Offset=3070 */

	/* Parameter pcActualCount */

/* 3814 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3816 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3822 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetThumbnail */

/* 3826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3832 */	NdrFcShort( 0xa ),	/* 10 */
/* 3834 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3840 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3842 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIThumbnail */

/* 3852 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3856 */	NdrFcShort( 0xbfa ),	/* Type Offset=3066 */

	/* Return value */

/* 3858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3860 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLevelCount */

/* 3864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3870 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3872 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3876 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3880 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcLevels */

/* 3890 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3892 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3898 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Notify */

/* 3902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3908 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3910 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3912 */	NdrFcShort( 0x1e ),	/* 30 */
/* 3914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 3918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3926 */	NdrFcShort( 0x80 ),	/* 128 */

	/* Parameter uFrameNum */

/* 3928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3930 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter operation */

/* 3934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3938 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter dblProgress */

/* 3940 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3942 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3944 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3948 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remote_RegisterProgressNotification */

/* 3952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3958 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3960 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3966 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3968 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pICallback */

/* 3978 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3982 */	NdrFcShort( 0xca0 ),	/* Type Offset=3232 */

	/* Parameter dwProgressFlags */

/* 3984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3992 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetComponentType */

/* 3996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4008 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4010 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4012 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pType */

/* 4022 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 4024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4026 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 4028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4030 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSigningStatus */

/* 4034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4040 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4042 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4048 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4050 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStatus */

/* 4060 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4068 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAuthor */

/* 4072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4078 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4080 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4084 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4086 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4088 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4090 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4092 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchAuthor */

/* 4098 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzAuthor */

/* 4104 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4108 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4110 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4112 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4118 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVendorGUID */

/* 4122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4130 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4134 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4136 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4138 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4146 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pguidVendor */

/* 4148 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4152 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 4154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4156 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVersion */

/* 4160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4168 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4172 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4174 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4176 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4178 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4180 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchVersion */

/* 4186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzVersion */

/* 4192 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4194 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4196 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4198 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4200 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4206 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSpecVersion */

/* 4210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4218 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4222 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4224 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4226 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4228 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4230 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchSpecVersion */

/* 4236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzSpecVersion */

/* 4242 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4244 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4246 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4248 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4250 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4256 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFriendlyName */

/* 4260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4266 */	NdrFcShort( 0xa ),	/* 10 */
/* 4268 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4272 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4274 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4276 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4278 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4280 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchFriendlyName */

/* 4286 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzFriendlyName */

/* 4292 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4294 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4296 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4298 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4300 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4306 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPixelFormats */

/* 4310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4316 */	NdrFcShort( 0xb ),	/* 11 */
/* 4318 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4322 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4324 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4326 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cFormats */

/* 4336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pPixelFormatGUIDs */

/* 4342 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4344 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4346 */	NdrFcShort( 0xcb2 ),	/* Type Offset=3250 */

	/* Parameter pcActual */

/* 4348 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4350 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4356 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInstance */

/* 4360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0xc ),	/* 12 */
/* 4368 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4374 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4376 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIConverter */

/* 4386 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4390 */	NdrFcShort( 0xccc ),	/* Type Offset=3276 */

	/* Return value */

/* 4392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4394 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFormatGUID */


	/* Procedure GetContainerFormat */

/* 4398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4404 */	NdrFcShort( 0xb ),	/* 11 */
/* 4406 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4410 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4412 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4414 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFormat */


	/* Parameter pguidContainerFormat */

/* 4424 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4428 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */


	/* Return value */

/* 4430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4432 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPixelFormats */

/* 4436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4442 */	NdrFcShort( 0xc ),	/* 12 */
/* 4444 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4448 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4450 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4452 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4454 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4456 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cFormats */

/* 4462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pguidPixelFormats */

/* 4468 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4470 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4472 */	NdrFcShort( 0xcb2 ),	/* Type Offset=3250 */

	/* Parameter pcActual */

/* 4474 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4476 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4482 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColorManagementVersion */

/* 4486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4492 */	NdrFcShort( 0xd ),	/* 13 */
/* 4494 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4498 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4500 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4502 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4506 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4510 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchColorManagementVersion */

/* 4512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzColorManagementVersion */

/* 4518 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4522 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4524 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4526 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4532 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceManufacturer */

/* 4536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4542 */	NdrFcShort( 0xe ),	/* 14 */
/* 4544 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4548 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4550 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4552 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4554 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4556 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchDeviceManufacturer */

/* 4562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzDeviceManufacturer */

/* 4568 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4572 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4574 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4576 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4582 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceModels */

/* 4586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4592 */	NdrFcShort( 0xf ),	/* 15 */
/* 4594 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4596 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4598 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4600 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4602 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4606 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchDeviceModels */

/* 4612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzDeviceModels */

/* 4618 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4620 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4622 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4624 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4626 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4632 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMimeTypes */

/* 4636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4642 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4644 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4648 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4650 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4652 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4654 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4656 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchMimeTypes */

/* 4662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzMimeTypes */

/* 4668 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4670 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4672 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4674 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4676 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4682 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFileExtensions */

/* 4686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4694 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4698 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4700 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4702 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4704 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4706 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cchFileExtensions */

/* 4712 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wzFileExtensions */

/* 4718 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 4720 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4722 */	NdrFcShort( 0xa92 ),	/* Type Offset=2706 */

	/* Parameter pcchActual */

/* 4724 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4726 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4732 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesSupportAnimation */

/* 4736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4742 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4744 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4748 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4750 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfSupportAnimation */

/* 4762 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesSupportChromakey */

/* 4774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4780 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4782 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4786 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4790 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfSupportChromakey */

/* 4800 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesSupportLossless */

/* 4812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4818 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4820 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4824 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4826 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4828 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfSupportLossless */

/* 4838 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4846 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWhitePointKelvin */


	/* Procedure DoesSupportMultiframe */

/* 4850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4856 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4858 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4862 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4864 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4866 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWhitePointKelvin */


	/* Parameter pfSupportMultiframe */

/* 4876 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 4882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MatchesMimeType */

/* 4888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4894 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4896 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4902 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4904 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzMimeType */

/* 4914 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4918 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter pfMatches */

/* 4920 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4922 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4928 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInstance */

/* 4932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4938 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4940 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4946 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4948 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapEncoder */

/* 4958 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4960 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4962 */	NdrFcShort( 0xce2 ),	/* Type Offset=3298 */

	/* Return value */

/* 4964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4966 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remote_GetPatterns */

/* 4970 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4978 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4982 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4984 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4986 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPatterns */

/* 4996 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5000 */	NdrFcShort( 0xcf8 ),	/* Type Offset=3320 */

	/* Parameter pcPatterns */

/* 5002 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5010 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MatchesPattern */

/* 5014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5020 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5022 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5026 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5028 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5030 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5038 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 5040 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5042 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5044 */	NdrFcShort( 0xbbc ),	/* Type Offset=3004 */

	/* Parameter pfMatches */

/* 5046 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5048 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5054 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInstance */

/* 5058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5064 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5066 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5072 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5074 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5082 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapDecoder */

/* 5084 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5086 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5088 */	NdrFcShort( 0xd3e ),	/* Type Offset=3390 */

	/* Return value */

/* 5090 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5092 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetColorContext */

/* 5096 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5098 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5102 */	NdrFcShort( 0xc ),	/* 12 */
/* 5104 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5110 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5112 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIColorContext */

/* 5122 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5124 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5126 */	NdrFcShort( 0xd54 ),	/* Type Offset=3412 */

	/* Return value */

/* 5128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5130 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBitsPerPixel */

/* 5134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5140 */	NdrFcShort( 0xd ),	/* 13 */
/* 5142 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5146 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5148 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5150 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter puiBitsPerPixel */

/* 5160 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5168 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChannelCount */

/* 5172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5178 */	NdrFcShort( 0xe ),	/* 14 */
/* 5180 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5184 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5188 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter puiChannelCount */

/* 5198 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetChannelMask */

/* 5210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5216 */	NdrFcShort( 0xf ),	/* 15 */
/* 5218 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 5220 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5222 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5224 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5226 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 5228 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5230 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uiChannelIndex */

/* 5236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbMaskBuffer */

/* 5242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5244 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbMaskBuffer */

/* 5248 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 5250 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5252 */	NdrFcShort( 0xd6a ),	/* Type Offset=3434 */

	/* Parameter pcbActual */

/* 5254 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5256 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5262 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SupportsTransparency */

/* 5266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5272 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5274 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5282 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pfSupportsTransparency */

/* 5292 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5300 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNumericRepresentation */

/* 5304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5310 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5312 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5316 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5318 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5320 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNumericRepresentation */

/* 5330 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 5332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5334 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 5336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5338 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDecoderFromFilename */

/* 5342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5348 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5350 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 5352 */	NdrFcShort( 0x52 ),	/* 82 */
/* 5354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5356 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 5358 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter wzFilename */

/* 5368 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5372 */	NdrFcShort( 0xea ),	/* Type Offset=234 */

	/* Parameter pguidVendor */

/* 5374 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5378 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter dwDesiredAccess */

/* 5380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5382 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter metadataOptions */

/* 5386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5388 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5390 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIDecoder */

/* 5392 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5394 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5396 */	NdrFcShort( 0xd3e ),	/* Type Offset=3390 */

	/* Return value */

/* 5398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5400 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 5402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDecoderFromStream */

/* 5404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5410 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5412 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 5414 */	NdrFcShort( 0x4a ),	/* 74 */
/* 5416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5418 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5420 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIStream */

/* 5430 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5434 */	NdrFcShort( 0xbbc ),	/* Type Offset=3004 */

	/* Parameter pguidVendor */

/* 5436 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5438 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5440 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter metadataOptions */

/* 5442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5444 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5446 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIDecoder */

/* 5448 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5450 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5452 */	NdrFcShort( 0xd3e ),	/* Type Offset=3390 */

	/* Return value */

/* 5454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5456 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDecoderFromFileHandle */

/* 5460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5466 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5468 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 5470 */	NdrFcShort( 0x52 ),	/* 82 */
/* 5472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5474 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 5476 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5484 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hFile */

/* 5486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5490 */	0xb9,		/* FC_UINT3264 */
			0x0,		/* 0 */

	/* Parameter pguidVendor */

/* 5492 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5496 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter metadataOptions */

/* 5498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5500 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5502 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIDecoder */

/* 5504 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5506 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5508 */	NdrFcShort( 0xd3e ),	/* Type Offset=3390 */

	/* Return value */

/* 5510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5512 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateComponentInfo */

/* 5516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5522 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5524 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5526 */	NdrFcShort( 0x44 ),	/* 68 */
/* 5528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5530 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter clsidComponent */

/* 5542 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5546 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter ppIInfo */

/* 5548 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5550 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5552 */	NdrFcShort( 0xd7a ),	/* Type Offset=3450 */

	/* Return value */

/* 5554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5556 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateDecoder */

/* 5560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5566 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5568 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5570 */	NdrFcShort( 0x88 ),	/* 136 */
/* 5572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5574 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 5576 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guidContainerFormat */

/* 5586 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5588 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5590 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter pguidVendor */

/* 5592 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5594 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5596 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter ppIDecoder */

/* 5598 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5600 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5602 */	NdrFcShort( 0xd3e ),	/* Type Offset=3390 */

	/* Return value */

/* 5604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5606 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateEncoder */

/* 5610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5618 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5620 */	NdrFcShort( 0x88 ),	/* 136 */
/* 5622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5624 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 5626 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guidContainerFormat */

/* 5636 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5638 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5640 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter pguidVendor */

/* 5642 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5644 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5646 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter ppIEncoder */

/* 5648 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5650 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5652 */	NdrFcShort( 0xce2 ),	/* Type Offset=3298 */

	/* Return value */

/* 5654 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5656 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreatePalette */

/* 5660 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5662 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5666 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5668 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5674 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5676 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIPalette */

/* 5686 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5690 */	NdrFcShort( 0xd90 ),	/* Type Offset=3472 */

	/* Return value */

/* 5692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5694 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFormatConverter */

/* 5698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5704 */	NdrFcShort( 0xa ),	/* 10 */
/* 5706 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5712 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5714 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIFormatConverter */

/* 5724 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5726 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5728 */	NdrFcShort( 0xccc ),	/* Type Offset=3276 */

	/* Return value */

/* 5730 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5732 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5734 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapScaler */

/* 5736 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5738 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5742 */	NdrFcShort( 0xb ),	/* 11 */
/* 5744 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5750 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5752 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapScaler */

/* 5762 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5766 */	NdrFcShort( 0xd94 ),	/* Type Offset=3476 */

	/* Return value */

/* 5768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapClipper */

/* 5774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5780 */	NdrFcShort( 0xc ),	/* 12 */
/* 5782 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5788 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5790 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapClipper */

/* 5800 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5804 */	NdrFcShort( 0xdaa ),	/* Type Offset=3498 */

	/* Return value */

/* 5806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFlipRotator */

/* 5812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5818 */	NdrFcShort( 0xd ),	/* 13 */
/* 5820 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5826 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5828 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIBitmapFlipRotator */

/* 5838 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5842 */	NdrFcShort( 0xdc0 ),	/* Type Offset=3520 */

	/* Return value */

/* 5844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5846 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateStream */

/* 5850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5856 */	NdrFcShort( 0xe ),	/* 14 */
/* 5858 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5864 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5866 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIWICStream */

/* 5876 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5880 */	NdrFcShort( 0xdd6 ),	/* Type Offset=3542 */

	/* Return value */

/* 5882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateColorContext */

/* 5888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5894 */	NdrFcShort( 0xf ),	/* 15 */
/* 5896 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5902 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5904 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIWICColorContext */

/* 5914 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5918 */	NdrFcShort( 0xdec ),	/* Type Offset=3564 */

	/* Return value */

/* 5920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5922 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateColorTransformer */

/* 5926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5932 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5934 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5940 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5942 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5950 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIWICColorTransform */

/* 5952 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5956 */	NdrFcShort( 0xdf0 ),	/* Type Offset=3568 */

	/* Return value */

/* 5958 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5960 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmap */

/* 5964 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5966 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5970 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5972 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 5974 */	NdrFcShort( 0x5a ),	/* 90 */
/* 5976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5978 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 5980 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uiWidth */

/* 5990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 5996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5998 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pixelFormat */

/* 6002 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 6004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6006 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter option */

/* 6008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6010 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6012 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIBitmap */

/* 6014 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6016 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6018 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6022 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 6024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFromSource */

/* 6026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6032 */	NdrFcShort( 0x12 ),	/* 18 */
/* 6034 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6036 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6040 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6042 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIBitmapSource */

/* 6052 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6056 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter option */

/* 6058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6060 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6062 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIBitmap */

/* 6064 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6066 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6068 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6072 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFromSourceRect */

/* 6076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6082 */	NdrFcShort( 0x13 ),	/* 19 */
/* 6084 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 6086 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6090 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 6092 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIBitmapSource */

/* 6102 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6106 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter x */

/* 6108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 6114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6116 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter width */

/* 6120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6122 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter height */

/* 6126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6128 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIBitmap */

/* 6132 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6134 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 6136 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6140 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 6142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFromMemory */

/* 6144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6150 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6152 */	NdrFcShort( 0x48 ),	/* x86 Stack size/offset = 72 */
/* 6154 */	NdrFcShort( 0x64 ),	/* 100 */
/* 6156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 6160 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6164 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uiWidth */

/* 6170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter uiHeight */

/* 6176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6178 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pixelFormat */

/* 6182 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 6184 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6186 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter cbStride */

/* 6188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6190 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbBufferSize */

/* 6194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6196 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbBuffer */

/* 6200 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6202 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 6204 */	NdrFcShort( 0xe20 ),	/* Type Offset=3616 */

	/* Parameter ppIBitmap */

/* 6206 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6208 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 6210 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6214 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 6216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFromHBITMAP */

/* 6218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6224 */	NdrFcShort( 0x15 ),	/* 21 */
/* 6226 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 6228 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6232 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 6234 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6238 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hBitmap */

/* 6244 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6248 */	NdrFcShort( 0xe68 ),	/* Type Offset=3688 */

	/* Parameter hPalette */

/* 6250 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6254 */	NdrFcShort( 0xeb8 ),	/* Type Offset=3768 */

	/* Parameter options */

/* 6256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6258 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6260 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter ppIBitmap */

/* 6262 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6264 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6266 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6270 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBitmapFromHICON */

/* 6274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6280 */	NdrFcShort( 0x16 ),	/* 22 */
/* 6282 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6288 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6290 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 6292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6294 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hIcon */

/* 6300 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6304 */	NdrFcShort( 0xeda ),	/* Type Offset=3802 */

	/* Parameter ppIBitmap */

/* 6306 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6308 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6310 */	NdrFcShort( 0xe06 ),	/* Type Offset=3590 */

	/* Return value */

/* 6312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6314 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateComponentEnumerator */

/* 6318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6324 */	NdrFcShort( 0x17 ),	/* 23 */
/* 6326 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6328 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6332 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 6334 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter componentTypes */

/* 6344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter options */

/* 6350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6352 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIEnumUnknown */

/* 6356 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6358 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6360 */	NdrFcShort( 0xee4 ),	/* Type Offset=3812 */

	/* Return value */

/* 6362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6364 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFastMetadataEncoderFromDecoder */

/* 6368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6374 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6376 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6382 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6384 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIDecoder */

/* 6394 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6398 */	NdrFcShort( 0xefa ),	/* Type Offset=3834 */

	/* Parameter ppIFastEncoder */

/* 6400 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6402 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6404 */	NdrFcShort( 0xf0c ),	/* Type Offset=3852 */

	/* Return value */

/* 6406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6408 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFastMetadataEncoderFromFrameDecode */

/* 6412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6418 */	NdrFcShort( 0x19 ),	/* 25 */
/* 6420 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6426 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6428 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIFrameDecoder */

/* 6438 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6442 */	NdrFcShort( 0xf22 ),	/* Type Offset=3874 */

	/* Parameter ppIFastEncoder */

/* 6444 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6446 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6448 */	NdrFcShort( 0xf0c ),	/* Type Offset=3852 */

	/* Return value */

/* 6450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6452 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateQueryWriter */

/* 6456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6462 */	NdrFcShort( 0x1a ),	/* 26 */
/* 6464 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6466 */	NdrFcShort( 0x88 ),	/* 136 */
/* 6468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6470 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 6472 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guidMetadataFormat */

/* 6482 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 6484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6486 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter pguidVendor */

/* 6488 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 6490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6492 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter ppIQueryWriter */

/* 6494 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6496 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6498 */	NdrFcShort( 0xf34 ),	/* Type Offset=3892 */

	/* Return value */

/* 6500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6502 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateQueryWriterFromReader */

/* 6506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6512 */	NdrFcShort( 0x1b ),	/* 27 */
/* 6514 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6516 */	NdrFcShort( 0x44 ),	/* 68 */
/* 6518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6520 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pIQueryReader */

/* 6532 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6536 */	NdrFcShort( 0xf4a ),	/* Type Offset=3914 */

	/* Parameter pguidVendor */

/* 6538 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 6540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6542 */	NdrFcShort( 0xc2e ),	/* Type Offset=3118 */

	/* Parameter ppIQueryWriter */

/* 6544 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6546 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6548 */	NdrFcShort( 0xf34 ),	/* Type Offset=3892 */

	/* Return value */

/* 6550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6552 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Notify */

/* 6556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6562 */	NdrFcShort( 0x3 ),	/* 3 */
/* 6564 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6570 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6572 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter NotificationMask */

/* 6582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6590 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remote_QueryRawCapabilitiesInfo */

/* 6594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6600 */	NdrFcShort( 0xb ),	/* 11 */
/* 6602 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6608 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6610 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pInfo */

/* 6620 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 6622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6624 */	NdrFcShort( 0xf60 ),	/* Type Offset=3936 */

	/* Return value */

/* 6626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6628 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadParameterSet */

/* 6632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6638 */	NdrFcShort( 0xc ),	/* 12 */
/* 6640 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6642 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6646 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6648 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ParameterSet */

/* 6658 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6660 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6662 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 6664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6666 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentParameterSet */

/* 6670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6676 */	NdrFcShort( 0xd ),	/* 13 */
/* 6678 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6682 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6684 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 6686 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCurrentParameterSet */

/* 6696 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 6698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6700 */	NdrFcShort( 0xf7c ),	/* Type Offset=3964 */

	/* Return value */

/* 6702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6704 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExposureCompensation */

/* 6708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6714 */	NdrFcShort( 0xe ),	/* 14 */
/* 6716 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6718 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6722 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6724 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6732 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter ev */

/* 6734 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6738 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 6740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6742 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetExposureCompensation */

/* 6746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6752 */	NdrFcShort( 0xf ),	/* 15 */
/* 6754 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6758 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6762 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6770 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEV */

/* 6772 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6776 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 6778 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6780 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6782 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWhitePointRGB */

/* 6784 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6790 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6792 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6794 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6798 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 6800 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Red */

/* 6810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6812 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Green */

/* 6816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6818 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Blue */

/* 6822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6824 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6830 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWhitePointRGB */

/* 6834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6840 */	NdrFcShort( 0x11 ),	/* 17 */
/* 6842 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6846 */	NdrFcShort( 0x5c ),	/* 92 */
/* 6848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 6850 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRed */

/* 6860 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6862 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pGreen */

/* 6866 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6868 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBlue */

/* 6872 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6874 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6880 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNamedWhitePoint */

/* 6884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6890 */	NdrFcShort( 0x12 ),	/* 18 */
/* 6892 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6894 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6898 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6900 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter WhitePoint */

/* 6910 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6912 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6914 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 6916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6918 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNamedWhitePoint */

/* 6922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6928 */	NdrFcShort( 0x13 ),	/* 19 */
/* 6930 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6934 */	NdrFcShort( 0x22 ),	/* 34 */
/* 6936 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6938 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWhitePoint */

/* 6948 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 6950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6952 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 6954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWhitePointKelvin */

/* 6960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6966 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6968 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 6976 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter WhitePointKelvin */

/* 6986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6994 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetKelvinRangeInfo */

/* 6998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7004 */	NdrFcShort( 0x16 ),	/* 22 */
/* 7006 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7010 */	NdrFcShort( 0x5c ),	/* 92 */
/* 7012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 7014 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMinKelvinTemp */

/* 7024 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7026 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMaxKelvinTemp */

/* 7030 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7032 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pKelvinTempStepValue */

/* 7036 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7038 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7044 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetContrast */

/* 7048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7054 */	NdrFcShort( 0x17 ),	/* 23 */
/* 7056 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7058 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7062 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7064 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7072 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Contrast */

/* 7074 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7078 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7082 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContrast */

/* 7086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7092 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7094 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7098 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7102 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pContrast */

/* 7112 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7116 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGamma */

/* 7124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7130 */	NdrFcShort( 0x19 ),	/* 25 */
/* 7132 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7134 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7138 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7140 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7148 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Gamma */

/* 7150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7154 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGamma */

/* 7162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7168 */	NdrFcShort( 0x1a ),	/* 26 */
/* 7170 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7174 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7176 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7178 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pGamma */

/* 7188 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7192 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7196 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSharpness */

/* 7200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7206 */	NdrFcShort( 0x1b ),	/* 27 */
/* 7208 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7210 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7214 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7216 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7224 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Sharpness */

/* 7226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7230 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7234 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSharpness */

/* 7238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7244 */	NdrFcShort( 0x1c ),	/* 28 */
/* 7246 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7250 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7254 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSharpness */

/* 7264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7268 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7272 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSaturation */

/* 7276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7282 */	NdrFcShort( 0x1d ),	/* 29 */
/* 7284 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7286 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7292 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7300 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Saturation */

/* 7302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7306 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7310 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSaturation */

/* 7314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7320 */	NdrFcShort( 0x1e ),	/* 30 */
/* 7322 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7326 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7330 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSaturation */

/* 7340 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7344 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7348 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTint */

/* 7352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7358 */	NdrFcShort( 0x1f ),	/* 31 */
/* 7360 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7362 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7366 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7368 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7376 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Tint */

/* 7378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7382 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7386 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTint */

/* 7390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7396 */	NdrFcShort( 0x20 ),	/* 32 */
/* 7398 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7402 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7404 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7406 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTint */

/* 7416 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7420 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7424 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNoiseReduction */

/* 7428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7434 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7436 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7438 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7442 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7444 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7452 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter NoiseReduction */

/* 7454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7458 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNoiseReduction */

/* 7466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7472 */	NdrFcShort( 0x22 ),	/* 34 */
/* 7474 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7478 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7480 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7482 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNoiseReduction */

/* 7492 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7496 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7500 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDestinationColorContext */

/* 7504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7510 */	NdrFcShort( 0x23 ),	/* 35 */
/* 7512 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7518 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7520 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pColorContext */

/* 7530 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7534 */	NdrFcShort( 0x10c ),	/* Type Offset=268 */

	/* Return value */

/* 7536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7538 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remote_SetToneCurve */

/* 7542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7548 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7550 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7556 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 7558 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 7560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7562 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cPoints */

/* 7568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7570 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter aPoints */

/* 7574 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7576 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7578 */	NdrFcShort( 0xf9e ),	/* Type Offset=3998 */

	/* Return value */

/* 7580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7582 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remote_GetToneCurve */

/* 7586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7592 */	NdrFcShort( 0x25 ),	/* 37 */
/* 7594 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7598 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7600 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 7602 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 7604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 7606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcPoints */

/* 7612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter paPoints */

/* 7618 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 7620 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7622 */	NdrFcShort( 0xfb4 ),	/* Type Offset=4020 */

	/* Return value */

/* 7624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7626 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRotation */

/* 7630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7636 */	NdrFcShort( 0x26 ),	/* 38 */
/* 7638 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7640 */	NdrFcShort( 0x10 ),	/* 16 */
/* 7642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7644 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7646 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7654 */	NdrFcShort( 0x8 ),	/* 8 */

	/* Parameter Rotation */

/* 7656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7660 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7664 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRotation */

/* 7668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7674 */	NdrFcShort( 0x27 ),	/* 39 */
/* 7676 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7680 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7682 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7684 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRotation */

/* 7694 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 7696 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7698 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7702 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRenderMode */

/* 7706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7712 */	NdrFcShort( 0x28 ),	/* 40 */
/* 7714 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7716 */	NdrFcShort( 0x6 ),	/* 6 */
/* 7718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7720 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7722 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter RenderMode */

/* 7732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7736 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 7738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7740 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRenderMode */

/* 7744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7750 */	NdrFcShort( 0x29 ),	/* 41 */
/* 7752 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7756 */	NdrFcShort( 0x22 ),	/* 34 */
/* 7758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 7760 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRenderMode */

/* 7770 */	NdrFcShort( 0x2010 ),	/* Flags:  out, srv alloc size=8 */
/* 7772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7774 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 7776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7778 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetNotificationCallback */

/* 7782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7788 */	NdrFcShort( 0x2a ),	/* 42 */
/* 7790 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7796 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7798 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7806 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCallback */

/* 7808 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 7810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7812 */	NdrFcShort( 0xfd2 ),	/* Type Offset=4050 */

	/* Return value */

/* 7814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7816 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParameters */

/* 7820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7826 */	NdrFcShort( 0x3 ),	/* 3 */
/* 7828 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7834 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7836 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pParameters */

/* 7846 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 7848 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7850 */	NdrFcShort( 0xfe8 ),	/* Type Offset=4072 */

	/* Return value */

/* 7852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7854 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFrame */

/* 7858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7864 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7866 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 7868 */	NdrFcShort( 0x18 ),	/* 24 */
/* 7870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7872 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 7874 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arrayIndex */

/* 7884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter mipLevel */

/* 7890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7892 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter sliceIndex */

/* 7896 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7898 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppIBitmapFrame */

/* 7902 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 7904 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 7906 */	NdrFcShort( 0xc18 ),	/* Type Offset=3096 */

	/* Return value */

/* 7908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7910 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 7912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetParameters */

/* 7914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7920 */	NdrFcShort( 0x3 ),	/* 3 */
/* 7922 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7928 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 7930 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pParameters */

/* 7940 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7942 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7944 */	NdrFcShort( 0xfe8 ),	/* Type Offset=4072 */

	/* Return value */

/* 7946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7948 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParameters */

/* 7952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 7960 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7966 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 7968 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 7970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pParameters */

/* 7978 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 7980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7982 */	NdrFcShort( 0xfe8 ),	/* Type Offset=4072 */

	/* Return value */

/* 7984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateNewFrame */

/* 7990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7996 */	NdrFcShort( 0x5 ),	/* 5 */
/* 7998 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 8000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8002 */	NdrFcShort( 0x5c ),	/* 92 */
/* 8004 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 8006 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppIFrameEncode */

/* 8016 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 8018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8020 */	NdrFcShort( 0xffe ),	/* Type Offset=4094 */

	/* Parameter pArrayIndex */

/* 8022 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMipLevel */

/* 8028 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8030 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSliceIndex */

/* 8034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 8036 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8040 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8042 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 8044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFormatInfo */

/* 8046 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8048 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8052 */	NdrFcShort( 0x4 ),	/* 4 */
/* 8054 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8060 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 8062 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 8064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFormatInfo */

/* 8072 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 8074 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8076 */	NdrFcShort( 0x1018 ),	/* Type Offset=4120 */

	/* Return value */

/* 8078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyBlocks */

/* 8084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8090 */	NdrFcShort( 0x5 ),	/* 5 */
/* 8092 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 8094 */	NdrFcShort( 0x44 ),	/* 68 */
/* 8096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8098 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 8100 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 8102 */	NdrFcShort( 0x1 ),	/* 1 */
/* 8104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prcBoundsInBlocks */

/* 8110 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 8112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8114 */	NdrFcShort( 0x68 ),	/* Type Offset=104 */

	/* Parameter cbStride */

/* 8116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8118 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbBufferSize */

/* 8122 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8124 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbBuffer */

/* 8128 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 8130 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 8132 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Return value */

/* 8134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8136 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 8138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const wincodec_MIDL_TYPE_FORMAT_STRING wincodec__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/*  8 */	NdrFcShort( 0x4 ),	/* 4 */
/* 10 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 14 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 16 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 18 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 20 */	NdrFcLong( 0x120 ),	/* 288 */
/* 24 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 26 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 28 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 30 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 32 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 34 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 36 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 38 */	NdrFcLong( 0x40 ),	/* 64 */
/* 42 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 44 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 46 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 48 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 50 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 52 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 58 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 60 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 62 */	
			0x11, 0x0,	/* FC_RP */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 68 */	NdrFcShort( 0x4 ),	/* 4 */
/* 70 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 72 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 74 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 76 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 78 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 80 */	NdrFcShort( 0x8 ),	/* Offset= 8 (88) */
/* 82 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 88 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 90 */	NdrFcShort( 0x10 ),	/* 16 */
/* 92 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 94 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 96 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (82) */
			0x5b,		/* FC_END */
/* 100 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 102 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 104 */	
			0x12, 0x0,	/* FC_UP */
/* 106 */	NdrFcShort( 0x2 ),	/* Offset= 2 (108) */
/* 108 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 110 */	NdrFcShort( 0x10 ),	/* 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 114 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 116 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 118 */	
			0x11, 0x0,	/* FC_RP */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 124 */	NdrFcShort( 0x1 ),	/* 1 */
/* 126 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 130 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 132 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 134 */	
			0x11, 0x0,	/* FC_RP */
/* 136 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (88) */
/* 138 */	
			0x11, 0x0,	/* FC_RP */
/* 140 */	NdrFcShort( 0x2 ),	/* Offset= 2 (142) */
/* 142 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 150 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 152 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 156 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 158 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 160 */	NdrFcShort( 0xff72 ),	/* Offset= -142 (18) */
/* 162 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 164 */	
			0x11, 0x0,	/* FC_RP */
/* 166 */	NdrFcShort( 0x2 ),	/* Offset= 2 (168) */
/* 168 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 176 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 178 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 182 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 184 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 186 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (88) */
/* 188 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 190 */	
			0x11, 0x0,	/* FC_RP */
/* 192 */	NdrFcShort( 0xffac ),	/* Offset= -84 (108) */
/* 194 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 196 */	NdrFcShort( 0x4 ),	/* Offset= 4 (200) */
/* 198 */	0xb9,		/* FC_UINT3264 */
			0x5c,		/* FC_PAD */
/* 200 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	NdrFcShort( 0x4 ),	/* 4 */
/* 208 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (198) */
/* 210 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (214) */
/* 214 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 216 */	NdrFcLong( 0x123 ),	/* 291 */
/* 220 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 222 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 224 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 226 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 228 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 230 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 232 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 234 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 236 */	
			0x11, 0x0,	/* FC_RP */
/* 238 */	NdrFcShort( 0x2 ),	/* Offset= 2 (240) */
/* 240 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 242 */	NdrFcShort( 0x1 ),	/* 1 */
/* 244 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 248 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 250 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 252 */	
			0x12, 0x0,	/* FC_UP */
/* 254 */	NdrFcShort( 0x2 ),	/* Offset= 2 (256) */
/* 256 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 258 */	NdrFcShort( 0x1 ),	/* 1 */
/* 260 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 264 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 266 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 268 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 270 */	NdrFcLong( 0x3c613a02 ),	/* 1013004802 */
/* 274 */	NdrFcShort( 0x34b2 ),	/* 13490 */
/* 276 */	NdrFcShort( 0x44ea ),	/* 17642 */
/* 278 */	0x9a,		/* 154 */
			0x7c,		/* 124 */
/* 280 */	0x45,		/* 69 */
			0xae,		/* 174 */
/* 282 */	0xa9,		/* 169 */
			0xc6,		/* 198 */
/* 284 */	0xfd,		/* 253 */
			0x6d,		/* 109 */
/* 286 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 288 */	NdrFcShort( 0x2 ),	/* Offset= 2 (290) */
/* 290 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 292 */	NdrFcLong( 0xa721791a ),	/* -1490978534 */
/* 296 */	NdrFcShort( 0xdef ),	/* 3567 */
/* 298 */	NdrFcShort( 0x4d06 ),	/* 19718 */
/* 300 */	0xbd,		/* 189 */
			0x91,		/* 145 */
/* 302 */	0x21,		/* 33 */
			0x18,		/* 24 */
/* 304 */	0xbf,		/* 191 */
			0x1d,		/* 29 */
/* 306 */	0xb1,		/* 177 */
			0xb,		/* 11 */
/* 308 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 310 */	NdrFcLong( 0xc ),	/* 12 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 320 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 322 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 324 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 326 */	0xb9,		/* FC_UINT3264 */
			0x5c,		/* FC_PAD */
/* 328 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 334 */	NdrFcShort( 0x4 ),	/* 4 */
/* 336 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (326) */
/* 338 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 342 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 344 */	
			0x12, 0x0,	/* FC_UP */
/* 346 */	NdrFcShort( 0x908 ),	/* Offset= 2312 (2658) */
/* 348 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x7,		/* FC_USHORT */
/* 350 */	0x0,		/* Corr desc:  field,  */
			0x59,		/* FC_CALLBACK */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 356 */	NdrFcShort( 0x2 ),	/* Offset= 2 (358) */
/* 358 */	NdrFcShort( 0x10 ),	/* 16 */
/* 360 */	NdrFcShort( 0x61 ),	/* 97 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* Offset= 0 (366) */
/* 368 */	NdrFcLong( 0x1 ),	/* 1 */
/* 372 */	NdrFcShort( 0x0 ),	/* Offset= 0 (372) */
/* 374 */	NdrFcLong( 0x10 ),	/* 16 */
/* 378 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 380 */	NdrFcLong( 0x11 ),	/* 17 */
/* 384 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 386 */	NdrFcLong( 0x2 ),	/* 2 */
/* 390 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 392 */	NdrFcLong( 0x12 ),	/* 18 */
/* 396 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 398 */	NdrFcLong( 0x3 ),	/* 3 */
/* 402 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 404 */	NdrFcLong( 0x13 ),	/* 19 */
/* 408 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 410 */	NdrFcLong( 0x16 ),	/* 22 */
/* 414 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 416 */	NdrFcLong( 0x17 ),	/* 23 */
/* 420 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 422 */	NdrFcLong( 0xe ),	/* 14 */
/* 426 */	NdrFcShort( 0xffa8 ),	/* Offset= -88 (338) */
/* 428 */	NdrFcLong( 0x14 ),	/* 20 */
/* 432 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (338) */
/* 434 */	NdrFcLong( 0x15 ),	/* 21 */
/* 438 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (338) */
/* 440 */	NdrFcLong( 0x4 ),	/* 4 */
/* 444 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 446 */	NdrFcLong( 0x5 ),	/* 5 */
/* 450 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 452 */	NdrFcLong( 0xb ),	/* 11 */
/* 456 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 458 */	NdrFcLong( 0xffff ),	/* 65535 */
/* 462 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 464 */	NdrFcLong( 0xa ),	/* 10 */
/* 468 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 470 */	NdrFcLong( 0x6 ),	/* 6 */
/* 474 */	NdrFcShort( 0xff78 ),	/* Offset= -136 (338) */
/* 476 */	NdrFcLong( 0x7 ),	/* 7 */
/* 480 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 482 */	NdrFcLong( 0x40 ),	/* 64 */
/* 486 */	NdrFcShort( 0x1cc ),	/* Offset= 460 (946) */
/* 488 */	NdrFcLong( 0x48 ),	/* 72 */
/* 492 */	NdrFcShort( 0x1ce ),	/* Offset= 462 (954) */
/* 494 */	NdrFcLong( 0x47 ),	/* 71 */
/* 498 */	NdrFcShort( 0x1cc ),	/* Offset= 460 (958) */
/* 500 */	NdrFcLong( 0x8 ),	/* 8 */
/* 504 */	NdrFcShort( 0x200 ),	/* Offset= 512 (1016) */
/* 506 */	NdrFcLong( 0xfff ),	/* 4095 */
/* 510 */	NdrFcShort( 0x210 ),	/* Offset= 528 (1038) */
/* 512 */	NdrFcLong( 0x41 ),	/* 65 */
/* 516 */	NdrFcShort( 0x21a ),	/* Offset= 538 (1054) */
/* 518 */	NdrFcLong( 0x46 ),	/* 70 */
/* 522 */	NdrFcShort( 0x214 ),	/* Offset= 532 (1054) */
/* 524 */	NdrFcLong( 0x1e ),	/* 30 */
/* 528 */	NdrFcShort( 0x21e ),	/* Offset= 542 (1070) */
/* 530 */	NdrFcLong( 0x1f ),	/* 31 */
/* 534 */	NdrFcShort( 0x21c ),	/* Offset= 540 (1074) */
/* 536 */	NdrFcLong( 0xd ),	/* 13 */
/* 540 */	NdrFcShort( 0x21a ),	/* Offset= 538 (1078) */
/* 542 */	NdrFcLong( 0x9 ),	/* 9 */
/* 546 */	NdrFcShort( 0x226 ),	/* Offset= 550 (1096) */
/* 548 */	NdrFcLong( 0x42 ),	/* 66 */
/* 552 */	NdrFcShort( 0xff0c ),	/* Offset= -244 (308) */
/* 554 */	NdrFcLong( 0x44 ),	/* 68 */
/* 558 */	NdrFcShort( 0xff06 ),	/* Offset= -250 (308) */
/* 560 */	NdrFcLong( 0x43 ),	/* 67 */
/* 564 */	NdrFcShort( 0x226 ),	/* Offset= 550 (1114) */
/* 566 */	NdrFcLong( 0x45 ),	/* 69 */
/* 570 */	NdrFcShort( 0x220 ),	/* Offset= 544 (1114) */
/* 572 */	NdrFcLong( 0x49 ),	/* 73 */
/* 576 */	NdrFcShort( 0x22c ),	/* Offset= 556 (1132) */
/* 578 */	NdrFcLong( 0x2010 ),	/* 8208 */
/* 582 */	NdrFcShort( 0x5aa ),	/* Offset= 1450 (2032) */
/* 584 */	NdrFcLong( 0x2011 ),	/* 8209 */
/* 588 */	NdrFcShort( 0x5a4 ),	/* Offset= 1444 (2032) */
/* 590 */	NdrFcLong( 0x2002 ),	/* 8194 */
/* 594 */	NdrFcShort( 0x59e ),	/* Offset= 1438 (2032) */
/* 596 */	NdrFcLong( 0x2012 ),	/* 8210 */
/* 600 */	NdrFcShort( 0x598 ),	/* Offset= 1432 (2032) */
/* 602 */	NdrFcLong( 0x2003 ),	/* 8195 */
/* 606 */	NdrFcShort( 0x592 ),	/* Offset= 1426 (2032) */
/* 608 */	NdrFcLong( 0x2013 ),	/* 8211 */
/* 612 */	NdrFcShort( 0x58c ),	/* Offset= 1420 (2032) */
/* 614 */	NdrFcLong( 0x2016 ),	/* 8214 */
/* 618 */	NdrFcShort( 0x586 ),	/* Offset= 1414 (2032) */
/* 620 */	NdrFcLong( 0x2017 ),	/* 8215 */
/* 624 */	NdrFcShort( 0x580 ),	/* Offset= 1408 (2032) */
/* 626 */	NdrFcLong( 0x2004 ),	/* 8196 */
/* 630 */	NdrFcShort( 0x57a ),	/* Offset= 1402 (2032) */
/* 632 */	NdrFcLong( 0x2005 ),	/* 8197 */
/* 636 */	NdrFcShort( 0x574 ),	/* Offset= 1396 (2032) */
/* 638 */	NdrFcLong( 0x2006 ),	/* 8198 */
/* 642 */	NdrFcShort( 0x56e ),	/* Offset= 1390 (2032) */
/* 644 */	NdrFcLong( 0x2007 ),	/* 8199 */
/* 648 */	NdrFcShort( 0x568 ),	/* Offset= 1384 (2032) */
/* 650 */	NdrFcLong( 0x2008 ),	/* 8200 */
/* 654 */	NdrFcShort( 0x562 ),	/* Offset= 1378 (2032) */
/* 656 */	NdrFcLong( 0x200b ),	/* 8203 */
/* 660 */	NdrFcShort( 0x55c ),	/* Offset= 1372 (2032) */
/* 662 */	NdrFcLong( 0x200e ),	/* 8206 */
/* 666 */	NdrFcShort( 0x556 ),	/* Offset= 1366 (2032) */
/* 668 */	NdrFcLong( 0x2009 ),	/* 8201 */
/* 672 */	NdrFcShort( 0x550 ),	/* Offset= 1360 (2032) */
/* 674 */	NdrFcLong( 0x200d ),	/* 8205 */
/* 678 */	NdrFcShort( 0x54a ),	/* Offset= 1354 (2032) */
/* 680 */	NdrFcLong( 0x200a ),	/* 8202 */
/* 684 */	NdrFcShort( 0x544 ),	/* Offset= 1348 (2032) */
/* 686 */	NdrFcLong( 0x200c ),	/* 8204 */
/* 690 */	NdrFcShort( 0x53e ),	/* Offset= 1342 (2032) */
/* 692 */	NdrFcLong( 0x1010 ),	/* 4112 */
/* 696 */	NdrFcShort( 0x54e ),	/* Offset= 1358 (2054) */
/* 698 */	NdrFcLong( 0x1011 ),	/* 4113 */
/* 702 */	NdrFcShort( 0x558 ),	/* Offset= 1368 (2070) */
/* 704 */	NdrFcLong( 0x1002 ),	/* 4098 */
/* 708 */	NdrFcShort( 0x562 ),	/* Offset= 1378 (2086) */
/* 710 */	NdrFcLong( 0x1012 ),	/* 4114 */
/* 714 */	NdrFcShort( 0x56c ),	/* Offset= 1388 (2102) */
/* 716 */	NdrFcLong( 0x1003 ),	/* 4099 */
/* 720 */	NdrFcShort( 0x576 ),	/* Offset= 1398 (2118) */
/* 722 */	NdrFcLong( 0x1013 ),	/* 4115 */
/* 726 */	NdrFcShort( 0x580 ),	/* Offset= 1408 (2134) */
/* 728 */	NdrFcLong( 0x1014 ),	/* 4116 */
/* 732 */	NdrFcShort( 0x5a0 ),	/* Offset= 1440 (2172) */
/* 734 */	NdrFcLong( 0x1015 ),	/* 4117 */
/* 738 */	NdrFcShort( 0x5aa ),	/* Offset= 1450 (2188) */
/* 740 */	NdrFcLong( 0x1004 ),	/* 4100 */
/* 744 */	NdrFcShort( 0x5c0 ),	/* Offset= 1472 (2216) */
/* 746 */	NdrFcLong( 0x1005 ),	/* 4101 */
/* 750 */	NdrFcShort( 0x5d6 ),	/* Offset= 1494 (2244) */
/* 752 */	NdrFcLong( 0x100b ),	/* 4107 */
/* 756 */	NdrFcShort( 0x5e0 ),	/* Offset= 1504 (2260) */
/* 758 */	NdrFcLong( 0x100a ),	/* 4106 */
/* 762 */	NdrFcShort( 0x5ea ),	/* Offset= 1514 (2276) */
/* 764 */	NdrFcLong( 0x1006 ),	/* 4102 */
/* 768 */	NdrFcShort( 0x5f4 ),	/* Offset= 1524 (2292) */
/* 770 */	NdrFcLong( 0x1007 ),	/* 4103 */
/* 774 */	NdrFcShort( 0x5fe ),	/* Offset= 1534 (2308) */
/* 776 */	NdrFcLong( 0x1040 ),	/* 4160 */
/* 780 */	NdrFcShort( 0x61e ),	/* Offset= 1566 (2346) */
/* 782 */	NdrFcLong( 0x1048 ),	/* 4168 */
/* 786 */	NdrFcShort( 0x63e ),	/* Offset= 1598 (2384) */
/* 788 */	NdrFcLong( 0x1047 ),	/* 4167 */
/* 792 */	NdrFcShort( 0x65e ),	/* Offset= 1630 (2422) */
/* 794 */	NdrFcLong( 0x1008 ),	/* 4104 */
/* 798 */	NdrFcShort( 0x67e ),	/* Offset= 1662 (2460) */
/* 800 */	NdrFcLong( 0x1fff ),	/* 8191 */
/* 804 */	NdrFcShort( 0x69e ),	/* Offset= 1694 (2498) */
/* 806 */	NdrFcLong( 0x101e ),	/* 4126 */
/* 810 */	NdrFcShort( 0x6be ),	/* Offset= 1726 (2536) */
/* 812 */	NdrFcLong( 0x101f ),	/* 4127 */
/* 816 */	NdrFcShort( 0x6de ),	/* Offset= 1758 (2574) */
/* 818 */	NdrFcLong( 0x100c ),	/* 4108 */
/* 822 */	NdrFcShort( 0x6fe ),	/* Offset= 1790 (2612) */
/* 824 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 828 */	NdrFcShort( 0x3b6 ),	/* Offset= 950 (1778) */
/* 830 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 834 */	NdrFcShort( 0x3b0 ),	/* Offset= 944 (1778) */
/* 836 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 840 */	NdrFcShort( 0x364 ),	/* Offset= 868 (1708) */
/* 842 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 846 */	NdrFcShort( 0x35e ),	/* Offset= 862 (1708) */
/* 848 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 852 */	NdrFcShort( 0x35c ),	/* Offset= 860 (1712) */
/* 854 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 858 */	NdrFcShort( 0x356 ),	/* Offset= 854 (1712) */
/* 860 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 864 */	NdrFcShort( 0x350 ),	/* Offset= 848 (1712) */
/* 866 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 870 */	NdrFcShort( 0x34a ),	/* Offset= 842 (1712) */
/* 872 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 876 */	NdrFcShort( 0x34c ),	/* Offset= 844 (1720) */
/* 878 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 882 */	NdrFcShort( 0x34a ),	/* Offset= 842 (1724) */
/* 884 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 888 */	NdrFcShort( 0x334 ),	/* Offset= 820 (1708) */
/* 890 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 894 */	NdrFcShort( 0x370 ),	/* Offset= 880 (1774) */
/* 896 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 900 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1712) */
/* 902 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 906 */	NdrFcShort( 0x336 ),	/* Offset= 822 (1728) */
/* 908 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 912 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1724) */
/* 914 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 918 */	NdrFcShort( 0x6ae ),	/* Offset= 1710 (2628) */
/* 920 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 924 */	NdrFcShort( 0x32c ),	/* Offset= 812 (1736) */
/* 926 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 930 */	NdrFcShort( 0x32a ),	/* Offset= 810 (1740) */
/* 932 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 936 */	NdrFcShort( 0x6a0 ),	/* Offset= 1696 (2632) */
/* 938 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 942 */	NdrFcShort( 0x69e ),	/* Offset= 1694 (2636) */
/* 944 */	NdrFcShort( 0xffff ),	/* Offset= -1 (943) */
/* 946 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 950 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 952 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 954 */	
			0x13, 0x0,	/* FC_OP */
/* 956 */	NdrFcShort( 0xfc9c ),	/* Offset= -868 (88) */
/* 958 */	
			0x13, 0x0,	/* FC_OP */
/* 960 */	NdrFcShort( 0xe ),	/* Offset= 14 (974) */
/* 962 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 964 */	NdrFcShort( 0x1 ),	/* 1 */
/* 966 */	0x10,		/* Corr desc:  field pointer,  */
			0x59,		/* FC_CALLBACK */
/* 968 */	NdrFcShort( 0x1 ),	/* 1 */
/* 970 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 972 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 974 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 976 */	NdrFcShort( 0x10 ),	/* 16 */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x6 ),	/* Offset= 6 (986) */
/* 982 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 984 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 986 */	
			0x13, 0x0,	/* FC_OP */
/* 988 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (962) */
/* 990 */	
			0x13, 0x0,	/* FC_OP */
/* 992 */	NdrFcShort( 0xe ),	/* Offset= 14 (1006) */
/* 994 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 996 */	NdrFcShort( 0x2 ),	/* 2 */
/* 998 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 1000 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 1002 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1004 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1006 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (994) */
/* 1012 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1014 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1016 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1020 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0xffde ),	/* Offset= -34 (990) */
/* 1026 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1028 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1030 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1036 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1038 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1040 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1050) */
/* 1046 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1048 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1050 */	
			0x13, 0x0,	/* FC_OP */
/* 1052 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1026) */
/* 1054 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1056 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1066) */
/* 1062 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1064 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1066 */	
			0x13, 0x0,	/* FC_OP */
/* 1068 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (1026) */
/* 1070 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1072 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1074 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1076 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1078 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1090 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1092 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1094 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1096 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1098 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1106 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1108 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1110 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1112 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1114 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1116 */	NdrFcLong( 0xb ),	/* 11 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1126 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1128 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1130 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1132 */	
			0x13, 0x0,	/* FC_OP */
/* 1134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1136) */
/* 1136 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1138 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0xc ),	/* Offset= 12 (1154) */
/* 1144 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1146 */	NdrFcShort( 0xfbde ),	/* Offset= -1058 (88) */
/* 1148 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1150 */	NdrFcShort( 0xfcb6 ),	/* Offset= -842 (308) */
/* 1152 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1154 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1156 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1158) */
/* 1158 */	
			0x13, 0x0,	/* FC_OP */
/* 1160 */	NdrFcShort( 0x356 ),	/* Offset= 854 (2014) */
/* 1162 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 1164 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1166 */	NdrFcShort( 0xa ),	/* 10 */
/* 1168 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1172 */	NdrFcShort( 0x50 ),	/* Offset= 80 (1252) */
/* 1174 */	NdrFcLong( 0xd ),	/* 13 */
/* 1178 */	NdrFcShort( 0x70 ),	/* Offset= 112 (1290) */
/* 1180 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1184 */	NdrFcShort( 0x90 ),	/* Offset= 144 (1328) */
/* 1186 */	NdrFcLong( 0xc ),	/* 12 */
/* 1190 */	NdrFcShort( 0x27a ),	/* Offset= 634 (1824) */
/* 1192 */	NdrFcLong( 0x24 ),	/* 36 */
/* 1196 */	NdrFcShort( 0x29a ),	/* Offset= 666 (1862) */
/* 1198 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 1202 */	NdrFcShort( 0x2a4 ),	/* Offset= 676 (1878) */
/* 1204 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1208 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (1898) */
/* 1210 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1214 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (1926) */
/* 1216 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1220 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1954) */
/* 1222 */	NdrFcLong( 0x14 ),	/* 20 */
/* 1226 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (1982) */
/* 1228 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1227) */
/* 1230 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1240 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1244 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1246 */	
			0x13, 0x0,	/* FC_OP */
/* 1248 */	NdrFcShort( 0xff0e ),	/* Offset= -242 (1006) */
/* 1250 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1252 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1254 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1264) */
/* 1260 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1262 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1264 */	
			0x11, 0x0,	/* FC_RP */
/* 1266 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1230) */
/* 1268 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1272 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1278 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1282 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1284 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1286 */	NdrFcShort( 0xff30 ),	/* Offset= -208 (1078) */
/* 1288 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1290 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1292 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1302) */
/* 1298 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1300 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1302 */	
			0x11, 0x0,	/* FC_RP */
/* 1304 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1268) */
/* 1306 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1316 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1320 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1322 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1324 */	NdrFcShort( 0xff1c ),	/* Offset= -228 (1096) */
/* 1326 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1328 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1330 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1340) */
/* 1336 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1338 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1340 */	
			0x11, 0x0,	/* FC_RP */
/* 1342 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1306) */
/* 1344 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 1346 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1348 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1350 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1352 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1354) */
/* 1354 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1356 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1358 */	NdrFcLong( 0x14 ),	/* 20 */
/* 1362 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1364 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1368 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1370 */	NdrFcLong( 0x11 ),	/* 17 */
/* 1374 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 1376 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1380 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1382 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1386 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 1388 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1392 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 1394 */	NdrFcLong( 0xb ),	/* 11 */
/* 1398 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1400 */	NdrFcLong( 0xa ),	/* 10 */
/* 1404 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1406 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1410 */	NdrFcShort( 0xfbd0 ),	/* Offset= -1072 (338) */
/* 1412 */	NdrFcLong( 0x7 ),	/* 7 */
/* 1416 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 1418 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1422 */	NdrFcShort( 0xfe50 ),	/* Offset= -432 (990) */
/* 1424 */	NdrFcLong( 0xd ),	/* 13 */
/* 1428 */	NdrFcShort( 0xfea2 ),	/* Offset= -350 (1078) */
/* 1430 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1434 */	NdrFcShort( 0xfeae ),	/* Offset= -338 (1096) */
/* 1436 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 1440 */	NdrFcShort( 0xca ),	/* Offset= 202 (1642) */
/* 1442 */	NdrFcLong( 0x24 ),	/* 36 */
/* 1446 */	NdrFcShort( 0xcc ),	/* Offset= 204 (1650) */
/* 1448 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 1452 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (1650) */
/* 1454 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 1458 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (1704) */
/* 1460 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 1464 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (1708) */
/* 1466 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 1470 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (1712) */
/* 1472 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 1476 */	NdrFcShort( 0xf0 ),	/* Offset= 240 (1716) */
/* 1478 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 1482 */	NdrFcShort( 0xee ),	/* Offset= 238 (1720) */
/* 1484 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 1488 */	NdrFcShort( 0xec ),	/* Offset= 236 (1724) */
/* 1490 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 1494 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (1708) */
/* 1496 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 1500 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (1712) */
/* 1502 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 1506 */	NdrFcShort( 0xde ),	/* Offset= 222 (1728) */
/* 1508 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 1512 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (1724) */
/* 1514 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 1518 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (1732) */
/* 1520 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 1524 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (1736) */
/* 1526 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 1530 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (1740) */
/* 1532 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 1536 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (1744) */
/* 1538 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 1542 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (1756) */
/* 1544 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1548 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1550 */	NdrFcLong( 0x12 ),	/* 18 */
/* 1554 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1556 */	NdrFcLong( 0x13 ),	/* 19 */
/* 1560 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1562 */	NdrFcLong( 0x15 ),	/* 21 */
/* 1566 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1568 */	NdrFcLong( 0x16 ),	/* 22 */
/* 1572 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1574 */	NdrFcLong( 0x17 ),	/* 23 */
/* 1578 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1580 */	NdrFcLong( 0xe ),	/* 14 */
/* 1584 */	NdrFcShort( 0xb4 ),	/* Offset= 180 (1764) */
/* 1586 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 1590 */	NdrFcShort( 0xb8 ),	/* Offset= 184 (1774) */
/* 1592 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 1596 */	NdrFcShort( 0xb6 ),	/* Offset= 182 (1778) */
/* 1598 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 1602 */	NdrFcShort( 0x6a ),	/* Offset= 106 (1708) */
/* 1604 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 1608 */	NdrFcShort( 0x68 ),	/* Offset= 104 (1712) */
/* 1610 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 1614 */	NdrFcShort( 0x66 ),	/* Offset= 102 (1716) */
/* 1616 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 1620 */	NdrFcShort( 0x5c ),	/* Offset= 92 (1712) */
/* 1622 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 1626 */	NdrFcShort( 0x56 ),	/* Offset= 86 (1712) */
/* 1628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1632) */
/* 1634 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1638 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1638) */
/* 1640 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1639) */
/* 1642 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1644 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1646) */
/* 1646 */	
			0x13, 0x0,	/* FC_OP */
/* 1648 */	NdrFcShort( 0x16e ),	/* Offset= 366 (2014) */
/* 1650 */	
			0x13, 0x0,	/* FC_OP */
/* 1652 */	NdrFcShort( 0x20 ),	/* Offset= 32 (1684) */
/* 1654 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1656 */	NdrFcLong( 0x2f ),	/* 47 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1666 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1668 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1670 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1672 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1674 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1676 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1678 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1680 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1682 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1684 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1686 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0xa ),	/* Offset= 10 (1700) */
/* 1692 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1694 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1696 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (1654) */
/* 1698 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1700 */	
			0x13, 0x0,	/* FC_OP */
/* 1702 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1672) */
/* 1704 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1706 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1708 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1710 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1712 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1714 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1716 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1718 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1720 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1722 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1724 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1726 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1728 */	
			0x13, 0x0,	/* FC_OP */
/* 1730 */	NdrFcShort( 0xfa90 ),	/* Offset= -1392 (338) */
/* 1732 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1734 */	NdrFcShort( 0xfd18 ),	/* Offset= -744 (990) */
/* 1736 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1738 */	NdrFcShort( 0xfd6c ),	/* Offset= -660 (1078) */
/* 1740 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1742 */	NdrFcShort( 0xfd7a ),	/* Offset= -646 (1096) */
/* 1744 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1746 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1748) */
/* 1748 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1750 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1752) */
/* 1752 */	
			0x13, 0x0,	/* FC_OP */
/* 1754 */	NdrFcShort( 0x104 ),	/* Offset= 260 (2014) */
/* 1756 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1758 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1760) */
/* 1760 */	
			0x13, 0x0,	/* FC_OP */
/* 1762 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1782) */
/* 1764 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1766 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1768 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1770 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1772 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1774 */	
			0x13, 0x0,	/* FC_OP */
/* 1776 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1764) */
/* 1778 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1780 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1782 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1784 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1788) */
/* 1790 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1792 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1794 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1796 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1798 */	NdrFcShort( 0xfe3a ),	/* Offset= -454 (1344) */
/* 1800 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1802 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1810 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1812 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1816 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1818 */	
			0x13, 0x0,	/* FC_OP */
/* 1820 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1782) */
/* 1822 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1824 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1826 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1836) */
/* 1832 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1834 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1836 */	
			0x11, 0x0,	/* FC_RP */
/* 1838 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1802) */
/* 1840 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1844 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1850 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1854 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1856 */	
			0x13, 0x0,	/* FC_OP */
/* 1858 */	NdrFcShort( 0xff52 ),	/* Offset= -174 (1684) */
/* 1860 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1862 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1864 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1874) */
/* 1870 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1872 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1874 */	
			0x11, 0x0,	/* FC_RP */
/* 1876 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1840) */
/* 1878 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1880 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0xa ),	/* Offset= 10 (1894) */
/* 1886 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1888 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1890 */	0x0,		/* 0 */
			NdrFcShort( 0xf8f5 ),	/* Offset= -1803 (88) */
			0x5b,		/* FC_END */
/* 1894 */	
			0x11, 0x0,	/* FC_RP */
/* 1896 */	NdrFcShort( 0xfd8c ),	/* Offset= -628 (1268) */
/* 1898 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1900 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1910) */
/* 1906 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1908 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1910 */	
			0x13, 0x0,	/* FC_OP */
/* 1912 */	NdrFcShort( 0xfc8a ),	/* Offset= -886 (1026) */
/* 1914 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1916 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1918 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1924 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1926 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1928 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1938) */
/* 1934 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1936 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1938 */	
			0x13, 0x0,	/* FC_OP */
/* 1940 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1914) */
/* 1942 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1946 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1952 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1954 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1956 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1966) */
/* 1962 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1964 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1966 */	
			0x13, 0x0,	/* FC_OP */
/* 1968 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1942) */
/* 1970 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1974 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1978 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1980 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1982 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1984 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1994) */
/* 1990 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1992 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1994 */	
			0x13, 0x0,	/* FC_OP */
/* 1996 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1970) */
/* 1998 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2002 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 2004 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 2006 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2008 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2010 */	NdrFcShort( 0xfbd8 ),	/* Offset= -1064 (946) */
/* 2012 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2014 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2016 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2018 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1998) */
/* 2020 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2020) */
/* 2022 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2024 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2026 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2028 */	0x0,		/* 0 */
			NdrFcShort( 0xfc9d ),	/* Offset= -867 (1162) */
			0x5b,		/* FC_END */
/* 2032 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 2034 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0xfc8a ),	/* Offset= -886 (1154) */
/* 2042 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2044 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2046 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2052 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2054 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2056 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2060 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2066) */
/* 2062 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2064 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2066 */	
			0x13, 0x0,	/* FC_OP */
/* 2068 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2042) */
/* 2070 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2072 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2082) */
/* 2078 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2080 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2082 */	
			0x13, 0x0,	/* FC_OP */
/* 2084 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (2042) */
/* 2086 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2088 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2098) */
/* 2094 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2096 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2098 */	
			0x13, 0x0,	/* FC_OP */
/* 2100 */	NdrFcShort( 0xff46 ),	/* Offset= -186 (1914) */
/* 2102 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2104 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2108 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2114) */
/* 2110 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2112 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2114 */	
			0x13, 0x0,	/* FC_OP */
/* 2116 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (1914) */
/* 2118 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2120 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2130) */
/* 2126 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2128 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2130 */	
			0x13, 0x0,	/* FC_OP */
/* 2132 */	NdrFcShort( 0xff42 ),	/* Offset= -190 (1942) */
/* 2134 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2136 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2146) */
/* 2142 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2144 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2146 */	
			0x13, 0x0,	/* FC_OP */
/* 2148 */	NdrFcShort( 0xff32 ),	/* Offset= -206 (1942) */
/* 2150 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2154 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2160 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2164 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2166 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2168 */	NdrFcShort( 0xf8da ),	/* Offset= -1830 (338) */
/* 2170 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2172 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2174 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2184) */
/* 2180 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2182 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2184 */	
			0x13, 0x0,	/* FC_OP */
/* 2186 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2150) */
/* 2188 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2190 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2200) */
/* 2196 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2198 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2200 */	
			0x13, 0x0,	/* FC_OP */
/* 2202 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (2150) */
/* 2204 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2206 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2208 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2214 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 2216 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2228) */
/* 2224 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2226 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2228 */	
			0x13, 0x0,	/* FC_OP */
/* 2230 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2204) */
/* 2232 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 2234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2236 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2240 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2242 */	0xc,		/* FC_DOUBLE */
			0x5b,		/* FC_END */
/* 2244 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2246 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2256) */
/* 2252 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2254 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2256 */	
			0x13, 0x0,	/* FC_OP */
/* 2258 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2232) */
/* 2260 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2262 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2272) */
/* 2268 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2270 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2272 */	
			0x13, 0x0,	/* FC_OP */
/* 2274 */	NdrFcShort( 0xfe98 ),	/* Offset= -360 (1914) */
/* 2276 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2278 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2288) */
/* 2284 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2286 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2288 */	
			0x13, 0x0,	/* FC_OP */
/* 2290 */	NdrFcShort( 0xfea4 ),	/* Offset= -348 (1942) */
/* 2292 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2294 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2304) */
/* 2300 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2302 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2304 */	
			0x13, 0x0,	/* FC_OP */
/* 2306 */	NdrFcShort( 0xff64 ),	/* Offset= -156 (2150) */
/* 2308 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2310 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2314 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2320) */
/* 2316 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2318 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2320 */	
			0x13, 0x0,	/* FC_OP */
/* 2322 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (2232) */
/* 2324 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2328 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2332 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2334 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2338 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2340 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2342 */	NdrFcShort( 0xfa8c ),	/* Offset= -1396 (946) */
/* 2344 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2346 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2348 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2358) */
/* 2354 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2356 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2358 */	
			0x13, 0x0,	/* FC_OP */
/* 2360 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2324) */
/* 2362 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2366 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2372 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2376 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2378 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2380 */	NdrFcShort( 0xf70c ),	/* Offset= -2292 (88) */
/* 2382 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2384 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2386 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2396) */
/* 2392 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2394 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2396 */	
			0x13, 0x0,	/* FC_OP */
/* 2398 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2362) */
/* 2400 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2408 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2410 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2414 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2416 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2418 */	NdrFcShort( 0xfa5c ),	/* Offset= -1444 (974) */
/* 2420 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2422 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2424 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2428 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2434) */
/* 2430 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2432 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2434 */	
			0x13, 0x0,	/* FC_OP */
/* 2436 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2400) */
/* 2438 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2442 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2448 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2452 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2454 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2456 */	NdrFcShort( 0xfa60 ),	/* Offset= -1440 (1016) */
/* 2458 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2460 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2462 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2466 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2472) */
/* 2468 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2470 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2472 */	
			0x13, 0x0,	/* FC_OP */
/* 2474 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2438) */
/* 2476 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2484 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2486 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2490 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2494 */	NdrFcShort( 0xfa50 ),	/* Offset= -1456 (1038) */
/* 2496 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2498 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2500 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2510) */
/* 2506 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2508 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2510 */	
			0x13, 0x0,	/* FC_OP */
/* 2512 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2476) */
/* 2514 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2518 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2522 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2524 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2528 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2530 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2532 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 2534 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2536 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2538 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2548) */
/* 2544 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2546 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2548 */	
			0x13, 0x0,	/* FC_OP */
/* 2550 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2514) */
/* 2552 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2556 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2560 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2562 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2566 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2568 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2570 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2572 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2574 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2576 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2586) */
/* 2582 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2584 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2586 */	
			0x13, 0x0,	/* FC_OP */
/* 2588 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2552) */
/* 2590 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 2592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2594 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2598 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2600 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2604 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2606 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2608 */	NdrFcShort( 0x20 ),	/* Offset= 32 (2640) */
/* 2610 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2612 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2614 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2618 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2624) */
/* 2620 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2622 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 2624 */	
			0x13, 0x0,	/* FC_OP */
/* 2626 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2590) */
/* 2628 */	
			0x13, 0x0,	/* FC_OP */
/* 2630 */	NdrFcShort( 0xf9b2 ),	/* Offset= -1614 (1016) */
/* 2632 */	
			0x13, 0x0,	/* FC_OP */
/* 2634 */	NdrFcShort( 0xfda6 ),	/* Offset= -602 (2032) */
/* 2636 */	
			0x13, 0x0,	/* FC_OP */
/* 2638 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2640) */
/* 2640 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 2642 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2646) */
/* 2648 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 2650 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 2652 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2654 */	NdrFcShort( 0xf6fe ),	/* Offset= -2306 (348) */
/* 2656 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2658 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2662 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2666 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2668 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2672 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2674 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2676 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2640) */
/* 2678 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2680 */	
			0x11, 0x0,	/* FC_RP */
/* 2682 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (2658) */
/* 2684 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2686 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2688) */
/* 2688 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2690 */	NdrFcLong( 0xdc2bb46d ),	/* -601115539 */
/* 2694 */	NdrFcShort( 0x3f07 ),	/* 16135 */
/* 2696 */	NdrFcShort( 0x481e ),	/* 18462 */
/* 2698 */	0x86,		/* 134 */
			0x25,		/* 37 */
/* 2700 */	0x22,		/* 34 */
			0xc,		/* 12 */
/* 2702 */	0x4a,		/* 74 */
			0xed,		/* 237 */
/* 2704 */	0xbb,		/* 187 */
			0x33,		/* 51 */
/* 2706 */	
			0x12, 0x0,	/* FC_UP */
/* 2708 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2710) */
/* 2710 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 2712 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2714 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2716 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2718 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2720 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 2722 */	
			0x12, 0x0,	/* FC_UP */
/* 2724 */	NdrFcShort( 0xffac ),	/* Offset= -84 (2640) */
/* 2726 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2728 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2730) */
/* 2730 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2732 */	NdrFcLong( 0x101 ),	/* 257 */
/* 2736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 2742 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2744 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2746 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 2748 */	
			0x11, 0x0,	/* FC_RP */
/* 2750 */	NdrFcShort( 0xff92 ),	/* Offset= -110 (2640) */
/* 2752 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2754 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2756) */
/* 2756 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2758 */	NdrFcLong( 0x94c9b4ee ),	/* -1798720274 */
/* 2762 */	NdrFcShort( 0xa09f ),	/* -24417 */
/* 2764 */	NdrFcShort( 0x4f92 ),	/* 20370 */
/* 2766 */	0x8a,		/* 138 */
			0x1e,		/* 30 */
/* 2768 */	0x4a,		/* 74 */
			0x9b,		/* 155 */
/* 2770 */	0xce,		/* 206 */
			0x7e,		/* 126 */
/* 2772 */	0x76,		/* 118 */
			0xfb,		/* 251 */
/* 2774 */	
			0x11, 0x0,	/* FC_RP */
/* 2776 */	NdrFcShort( 0x14 ),	/* Offset= 20 (2796) */
/* 2778 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2780 */	NdrFcLong( 0x3c613a02 ),	/* 1013004802 */
/* 2784 */	NdrFcShort( 0x34b2 ),	/* 13490 */
/* 2786 */	NdrFcShort( 0x44ea ),	/* 17642 */
/* 2788 */	0x9a,		/* 154 */
			0x7c,		/* 124 */
/* 2790 */	0x45,		/* 69 */
			0xae,		/* 174 */
/* 2792 */	0xa9,		/* 169 */
			0xc6,		/* 198 */
/* 2794 */	0xfd,		/* 253 */
			0x6d,		/* 109 */
/* 2796 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2804 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2806 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2810 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2812 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2814 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2778) */
/* 2816 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2818 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2820 */	NdrFcLong( 0x40 ),	/* 64 */
/* 2824 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 2826 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 2828 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 2830 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 2832 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 2834 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 2836 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2838 */	NdrFcLong( 0x120 ),	/* 288 */
/* 2842 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 2844 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 2846 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 2848 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 2850 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 2852 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 2854 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2856 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2858) */
/* 2858 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2860 */	NdrFcLong( 0x105 ),	/* 261 */
/* 2864 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 2866 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 2868 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 2870 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 2872 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 2874 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 2876 */	
			0x12, 0x14,	/* FC_UP [alloced_on_stack] [pointer_deref] */
/* 2878 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2880) */
/* 2880 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2882 */	NdrFcLong( 0x22f55882 ),	/* 586504322 */
/* 2886 */	NdrFcShort( 0x280b ),	/* 10251 */
/* 2888 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 2890 */	0xa8,		/* 168 */
			0xa9,		/* 169 */
/* 2892 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 2894 */	0xc9,		/* 201 */
			0xc,		/* 12 */
/* 2896 */	0x20,		/* 32 */
			0x4,		/* 4 */
/* 2898 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2900 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2902) */
/* 2902 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2904 */	NdrFcLong( 0xa721791a ),	/* -1490978534 */
/* 2908 */	NdrFcShort( 0xdef ),	/* 3567 */
/* 2910 */	NdrFcShort( 0x4d06 ),	/* 19718 */
/* 2912 */	0xbd,		/* 189 */
			0x91,		/* 145 */
/* 2914 */	0x21,		/* 33 */
			0x18,		/* 24 */
/* 2916 */	0xbf,		/* 191 */
			0x1d,		/* 29 */
/* 2918 */	0xb1,		/* 177 */
			0xb,		/* 11 */
/* 2920 */	
			0x11, 0x0,	/* FC_RP */
/* 2922 */	NdrFcShort( 0x22 ),	/* Offset= 34 (2956) */
/* 2924 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2926 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2928 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2930 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2932 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2934 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 2936 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2938 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2942 */	NdrFcShort( 0xa ),	/* Offset= 10 (2952) */
/* 2944 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2946 */	NdrFcShort( 0xf4d6 ),	/* Offset= -2858 (88) */
/* 2948 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 2950 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2952 */	
			0x12, 0x0,	/* FC_UP */
/* 2954 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (2924) */
/* 2956 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2960 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2962 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2964 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2966 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2970 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2974 */	NdrFcShort( 0xffda ),	/* Offset= -38 (2936) */
/* 2976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2978 */	
			0x11, 0x0,	/* FC_RP */
/* 2980 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2982) */
/* 2982 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2986 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2988 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2990 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2992 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2996 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2998 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3000 */	NdrFcShort( 0xff5c ),	/* Offset= -164 (2836) */
/* 3002 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3004 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3006 */	NdrFcLong( 0xc ),	/* 12 */
/* 3010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3014 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 3016 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3018 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3020 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 3022 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3024 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3026) */
/* 3026 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3028 */	NdrFcLong( 0xd8cd007f ),	/* -657653633 */
/* 3032 */	NdrFcShort( 0xd08f ),	/* -12145 */
/* 3034 */	NdrFcShort( 0x4191 ),	/* 16785 */
/* 3036 */	0x9b,		/* 155 */
			0xfc,		/* 252 */
/* 3038 */	0x23,		/* 35 */
			0x6e,		/* 110 */
/* 3040 */	0xa7,		/* 167 */
			0xf0,		/* 240 */
/* 3042 */	0xe4,		/* 228 */
			0xb5,		/* 181 */
/* 3044 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3046 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3048) */
/* 3048 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3050 */	NdrFcLong( 0x30989668 ),	/* 815306344 */
/* 3054 */	NdrFcShort( 0xe1c9 ),	/* -7735 */
/* 3056 */	NdrFcShort( 0x4597 ),	/* 17815 */
/* 3058 */	0xb3,		/* 179 */
			0x95,		/* 149 */
/* 3060 */	0x45,		/* 69 */
			0x8e,		/* 142 */
/* 3062 */	0xed,		/* 237 */
			0xb8,		/* 184 */
/* 3064 */	0x8,		/* 8 */
			0xdf,		/* 223 */
/* 3066 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3068 */	NdrFcShort( 0xff18 ),	/* Offset= -232 (2836) */
/* 3070 */	
			0x12, 0x0,	/* FC_UP */
/* 3072 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3074) */
/* 3074 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3078 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3082 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3084 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3088 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3090 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3092 */	NdrFcShort( 0xf4f8 ),	/* Offset= -2824 (268) */
/* 3094 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3096 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3098 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3100) */
/* 3100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3102 */	NdrFcLong( 0x3b16811b ),	/* 991330587 */
/* 3106 */	NdrFcShort( 0x6a43 ),	/* 27203 */
/* 3108 */	NdrFcShort( 0x4ec9 ),	/* 20169 */
/* 3110 */	0xa8,		/* 168 */
			0x13,		/* 19 */
/* 3112 */	0x3d,		/* 61 */
			0x93,		/* 147 */
/* 3114 */	0xc,		/* 12 */
			0x13,		/* 19 */
/* 3116 */	0xb9,		/* 185 */
			0x40,		/* 64 */
/* 3118 */	
			0x12, 0x0,	/* FC_UP */
/* 3120 */	NdrFcShort( 0xf428 ),	/* Offset= -3032 (88) */
/* 3122 */	
			0x11, 0x0,	/* FC_RP */
/* 3124 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3126) */
/* 3126 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3128 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3130 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3132 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3134 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3136 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 3138 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 3140 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 3142 */	
			0x11, 0x0,	/* FC_RP */
/* 3144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3146) */
/* 3146 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3152 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3154 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3156 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3160 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3162 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3164 */	NdrFcShort( 0xf3fc ),	/* Offset= -3076 (88) */
/* 3166 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3168 */	
			0x11, 0x0,	/* FC_RP */
/* 3170 */	NdrFcShort( 0xe ),	/* Offset= 14 (3184) */
/* 3172 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 3174 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3176 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3178 */	NdrFcShort( 0xf3ee ),	/* Offset= -3090 (88) */
/* 3180 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3182 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3184 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3190 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3192 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3194 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3198 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3200 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3202 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (3172) */
/* 3204 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3206 */	
			0x11, 0x0,	/* FC_RP */
/* 3208 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3210) */
/* 3210 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3214 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3216 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 3218 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3220 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3224 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3226 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3228 */	NdrFcShort( 0xfedc ),	/* Offset= -292 (2936) */
/* 3230 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3232 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3234 */	NdrFcLong( 0x4776f9cd ),	/* 1198979533 */
/* 3238 */	NdrFcShort( 0x9517 ),	/* -27369 */
/* 3240 */	NdrFcShort( 0x45fa ),	/* 17914 */
/* 3242 */	0xbf,		/* 191 */
			0x24,		/* 36 */
/* 3244 */	0xe8,		/* 232 */
			0x9c,		/* 156 */
/* 3246 */	0x5e,		/* 94 */
			0xc5,		/* 197 */
/* 3248 */	0xc6,		/* 198 */
			0xc,		/* 12 */
/* 3250 */	
			0x12, 0x0,	/* FC_UP */
/* 3252 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3254) */
/* 3254 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3258 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3262 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3264 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3268 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3270 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3272 */	NdrFcShort( 0xf390 ),	/* Offset= -3184 (88) */
/* 3274 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3276 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3278 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3280) */
/* 3280 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3282 */	NdrFcLong( 0x301 ),	/* 769 */
/* 3286 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 3288 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 3290 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 3292 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 3294 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 3296 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 3298 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3300 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3302) */
/* 3302 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3304 */	NdrFcLong( 0x103 ),	/* 259 */
/* 3308 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 3310 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 3312 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 3314 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 3316 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 3318 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 3320 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 3322 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3324) */
/* 3324 */	
			0x13, 0x0,	/* FC_OP */
/* 3326 */	NdrFcShort( 0x2a ),	/* Offset= 42 (3368) */
/* 3328 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3332 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 3334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3336 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3338 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 3340 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 3342 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3346 */	NdrFcShort( 0xe ),	/* Offset= 14 (3360) */
/* 3348 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3350 */	NdrFcShort( 0xf43c ),	/* Offset= -3012 (338) */
/* 3352 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3354 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 3356 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 3358 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3360 */	
			0x13, 0x0,	/* FC_OP */
/* 3362 */	NdrFcShort( 0xffde ),	/* Offset= -34 (3328) */
/* 3364 */	
			0x13, 0x0,	/* FC_OP */
/* 3366 */	NdrFcShort( 0xffda ),	/* Offset= -38 (3328) */
/* 3368 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3372 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 3374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3376 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3378 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3382 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3384 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3386 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (3340) */
/* 3388 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3390 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3392 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3394) */
/* 3394 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3396 */	NdrFcLong( 0x9edde9e7 ),	/* -1629623833 */
/* 3400 */	NdrFcShort( 0x8dee ),	/* -29202 */
/* 3402 */	NdrFcShort( 0x47ea ),	/* 18410 */
/* 3404 */	0x99,		/* 153 */
			0xdf,		/* 223 */
/* 3406 */	0xe6,		/* 230 */
			0xfa,		/* 250 */
/* 3408 */	0xf2,		/* 242 */
			0xed,		/* 237 */
/* 3410 */	0x44,		/* 68 */
			0xbf,		/* 191 */
/* 3412 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3414 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3416) */
/* 3416 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3418 */	NdrFcLong( 0x3c613a02 ),	/* 1013004802 */
/* 3422 */	NdrFcShort( 0x34b2 ),	/* 13490 */
/* 3424 */	NdrFcShort( 0x44ea ),	/* 17642 */
/* 3426 */	0x9a,		/* 154 */
			0x7c,		/* 124 */
/* 3428 */	0x45,		/* 69 */
			0xae,		/* 174 */
/* 3430 */	0xa9,		/* 169 */
			0xc6,		/* 198 */
/* 3432 */	0xfd,		/* 253 */
			0x6d,		/* 109 */
/* 3434 */	
			0x12, 0x0,	/* FC_UP */
/* 3436 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3438) */
/* 3438 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3440 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3442 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3446 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3448 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 3450 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3452 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3454) */
/* 3454 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3456 */	NdrFcLong( 0x23bc3f0a ),	/* 599539466 */
/* 3460 */	NdrFcShort( 0x698b ),	/* 27019 */
/* 3462 */	NdrFcShort( 0x4357 ),	/* 17239 */
/* 3464 */	0x88,		/* 136 */
			0x6b,		/* 107 */
/* 3466 */	0xf2,		/* 242 */
			0x4d,		/* 77 */
/* 3468 */	0x50,		/* 80 */
			0x67,		/* 103 */
/* 3470 */	0x13,		/* 19 */
			0x34,		/* 52 */
/* 3472 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3474 */	NdrFcShort( 0xfd70 ),	/* Offset= -656 (2818) */
/* 3476 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3478 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3480) */
/* 3480 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3482 */	NdrFcLong( 0x302 ),	/* 770 */
/* 3486 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 3488 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 3490 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 3492 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 3494 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 3496 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 3498 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3500 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3502) */
/* 3502 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3504 */	NdrFcLong( 0xe4fbcf03 ),	/* -453259517 */
/* 3508 */	NdrFcShort( 0x223d ),	/* 8765 */
/* 3510 */	NdrFcShort( 0x4e81 ),	/* 20097 */
/* 3512 */	0x93,		/* 147 */
			0x33,		/* 51 */
/* 3514 */	0xd6,		/* 214 */
			0x35,		/* 53 */
/* 3516 */	0x55,		/* 85 */
			0x6d,		/* 109 */
/* 3518 */	0xd1,		/* 209 */
			0xb5,		/* 181 */
/* 3520 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3522 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3524) */
/* 3524 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3526 */	NdrFcLong( 0x5009834f ),	/* 1342800719 */
/* 3530 */	NdrFcShort( 0x2d6a ),	/* 11626 */
/* 3532 */	NdrFcShort( 0x41ce ),	/* 16846 */
/* 3534 */	0x9e,		/* 158 */
			0x1b,		/* 27 */
/* 3536 */	0x17,		/* 23 */
			0xc5,		/* 197 */
/* 3538 */	0xaf,		/* 175 */
			0xf7,		/* 247 */
/* 3540 */	0xa7,		/* 167 */
			0x82,		/* 130 */
/* 3542 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3544 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3546) */
/* 3546 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3548 */	NdrFcLong( 0x135ff860 ),	/* 325056608 */
/* 3552 */	NdrFcShort( 0x22b7 ),	/* 8887 */
/* 3554 */	NdrFcShort( 0x4ddf ),	/* 19935 */
/* 3556 */	0xb0,		/* 176 */
			0xf6,		/* 246 */
/* 3558 */	0x21,		/* 33 */
			0x8f,		/* 143 */
/* 3560 */	0x4f,		/* 79 */
			0x29,		/* 41 */
/* 3562 */	0x9a,		/* 154 */
			0x43,		/* 67 */
/* 3564 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3566 */	NdrFcShort( 0xf31e ),	/* Offset= -3298 (268) */
/* 3568 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3570 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3572) */
/* 3572 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3574 */	NdrFcLong( 0xb66f034f ),	/* -1234238641 */
/* 3578 */	NdrFcShort( 0xd0e2 ),	/* -12062 */
/* 3580 */	NdrFcShort( 0x40ab ),	/* 16555 */
/* 3582 */	0xb4,		/* 180 */
			0x36,		/* 54 */
/* 3584 */	0x6d,		/* 109 */
			0xe3,		/* 227 */
/* 3586 */	0x9e,		/* 158 */
			0x32,		/* 50 */
/* 3588 */	0x1a,		/* 26 */
			0x94,		/* 148 */
/* 3590 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3592 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3594) */
/* 3594 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3596 */	NdrFcLong( 0x121 ),	/* 289 */
/* 3600 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 3602 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 3604 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 3606 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 3608 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 3610 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 3612 */	
			0x11, 0x0,	/* FC_RP */
/* 3614 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3616) */
/* 3616 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3618 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3620 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 3622 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3624 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3626 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 3628 */	
			0x12, 0x0,	/* FC_UP */
/* 3630 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3632) */
/* 3632 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 3634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3636 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3638 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 3642 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 3644 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 3648 */	NdrFcShort( 0xa ),	/* Offset= 10 (3658) */
/* 3650 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 3654 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 3656 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3655) */
/* 3658 */	
			0x12, 0x0,	/* FC_UP */
/* 3660 */	NdrFcShort( 0xe ),	/* Offset= 14 (3674) */
/* 3662 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3664 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3666 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 3668 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 3670 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3672 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 3674 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 3676 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3678 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (3662) */
/* 3680 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3682 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3684 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 3686 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3688 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 3690 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3696 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (3628) */
/* 3698 */	
			0x12, 0x0,	/* FC_UP */
/* 3700 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3702) */
/* 3702 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 3704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3706 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3708 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 3712 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 3714 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 3718 */	NdrFcShort( 0xa ),	/* Offset= 10 (3728) */
/* 3720 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 3724 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 3726 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3725) */
/* 3728 */	
			0x12, 0x0,	/* FC_UP */
/* 3730 */	NdrFcShort( 0x1c ),	/* Offset= 28 (3758) */
/* 3732 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 3734 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3736 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 3738 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 3740 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3742 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3744 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3746 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 3748 */	NdrFcShort( 0xfffe ),	/* -2 */
/* 3750 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3752 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3754 */	NdrFcShort( 0xffea ),	/* Offset= -22 (3732) */
/* 3756 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3758 */	
			0x17,		/* FC_CSTRUCT */
			0x1,		/* 1 */
/* 3760 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3762 */	NdrFcShort( 0xffec ),	/* Offset= -20 (3742) */
/* 3764 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 3766 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3768 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 3770 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3776 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (3698) */
/* 3778 */	
			0x12, 0x0,	/* FC_UP */
/* 3780 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3782) */
/* 3782 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 3784 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3786 */	NdrFcShort( 0x2 ),	/* 2 */
/* 3788 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 3792 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 3794 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 3798 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 3800 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3799) */
/* 3802 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 3804 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3810 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (3778) */
/* 3812 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3814 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3816) */
/* 3816 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3818 */	NdrFcLong( 0x100 ),	/* 256 */
/* 3822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3826 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 3828 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3830 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3832 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 3834 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3836 */	NdrFcLong( 0x9edde9e7 ),	/* -1629623833 */
/* 3840 */	NdrFcShort( 0x8dee ),	/* -29202 */
/* 3842 */	NdrFcShort( 0x47ea ),	/* 18410 */
/* 3844 */	0x99,		/* 153 */
			0xdf,		/* 223 */
/* 3846 */	0xe6,		/* 230 */
			0xfa,		/* 250 */
/* 3848 */	0xf2,		/* 242 */
			0xed,		/* 237 */
/* 3850 */	0x44,		/* 68 */
			0xbf,		/* 191 */
/* 3852 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3854 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3856) */
/* 3856 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3858 */	NdrFcLong( 0xb84e2c09 ),	/* -1202836471 */
/* 3862 */	NdrFcShort( 0x78c9 ),	/* 30921 */
/* 3864 */	NdrFcShort( 0x4ac4 ),	/* 19140 */
/* 3866 */	0x8b,		/* 139 */
			0xd3,		/* 211 */
/* 3868 */	0x52,		/* 82 */
			0x4a,		/* 74 */
/* 3870 */	0xe1,		/* 225 */
			0x66,		/* 102 */
/* 3872 */	0x3a,		/* 58 */
			0x2f,		/* 47 */
/* 3874 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3876 */	NdrFcLong( 0x3b16811b ),	/* 991330587 */
/* 3880 */	NdrFcShort( 0x6a43 ),	/* 27203 */
/* 3882 */	NdrFcShort( 0x4ec9 ),	/* 20169 */
/* 3884 */	0xa8,		/* 168 */
			0x13,		/* 19 */
/* 3886 */	0x3d,		/* 61 */
			0x93,		/* 147 */
/* 3888 */	0xc,		/* 12 */
			0x13,		/* 19 */
/* 3890 */	0xb9,		/* 185 */
			0x40,		/* 64 */
/* 3892 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3894 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3896) */
/* 3896 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3898 */	NdrFcLong( 0xa721791a ),	/* -1490978534 */
/* 3902 */	NdrFcShort( 0xdef ),	/* 3567 */
/* 3904 */	NdrFcShort( 0x4d06 ),	/* 19718 */
/* 3906 */	0xbd,		/* 189 */
			0x91,		/* 145 */
/* 3908 */	0x21,		/* 33 */
			0x18,		/* 24 */
/* 3910 */	0xbf,		/* 191 */
			0x1d,		/* 29 */
/* 3912 */	0xb1,		/* 177 */
			0xb,		/* 11 */
/* 3914 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3916 */	NdrFcLong( 0x30989668 ),	/* 815306344 */
/* 3920 */	NdrFcShort( 0xe1c9 ),	/* -7735 */
/* 3922 */	NdrFcShort( 0x4597 ),	/* 17815 */
/* 3924 */	0xb3,		/* 179 */
			0x95,		/* 149 */
/* 3926 */	0x45,		/* 69 */
			0x8e,		/* 142 */
/* 3928 */	0xed,		/* 237 */
			0xb8,		/* 184 */
/* 3930 */	0x8,		/* 8 */
			0xdf,		/* 223 */
/* 3932 */	
			0x11, 0x0,	/* FC_RP */
/* 3934 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3936) */
/* 3936 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3938 */	NdrFcShort( 0x48 ),	/* 72 */
/* 3940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3942 */	NdrFcShort( 0x0 ),	/* Offset= 0 (3942) */
/* 3944 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3946 */	0x8,		/* FC_LONG */
			0xd,		/* FC_ENUM16 */
/* 3948 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3950 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 3952 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3954 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3956 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3958 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3960 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 3962 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3964 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 3966 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3968) */
/* 3968 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 3970 */	NdrFcLong( 0x22f55882 ),	/* 586504322 */
/* 3974 */	NdrFcShort( 0x280b ),	/* 10251 */
/* 3976 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 3978 */	0xa8,		/* 168 */
			0xa9,		/* 169 */
/* 3980 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 3982 */	0xc9,		/* 201 */
			0xc,		/* 12 */
/* 3984 */	0x20,		/* 32 */
			0x4,		/* 4 */
/* 3986 */	
			0x11, 0x0,	/* FC_RP */
/* 3988 */	NdrFcShort( 0xa ),	/* Offset= 10 (3998) */
/* 3990 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 3992 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3994 */	0xc,		/* FC_DOUBLE */
			0xc,		/* FC_DOUBLE */
/* 3996 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3998 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4002 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 4004 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4006 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4008 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4012 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4014 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4016 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (3990) */
/* 4018 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4020 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 4022 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4024) */
/* 4024 */	
			0x13, 0x0,	/* FC_OP */
/* 4026 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4028) */
/* 4028 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 4030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4032 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 4034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4036 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4038 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4042 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4044 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4046 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3990) */
/* 4048 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4050 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 4052 */	NdrFcLong( 0x95c75a6e ),	/* -1782097298 */
/* 4056 */	NdrFcShort( 0x3e8c ),	/* 16012 */
/* 4058 */	NdrFcShort( 0x4ec2 ),	/* 20162 */
/* 4060 */	0x85,		/* 133 */
			0xa8,		/* 168 */
/* 4062 */	0xae,		/* 174 */
			0xbc,		/* 188 */
/* 4064 */	0xc5,		/* 197 */
			0x51,		/* 81 */
/* 4066 */	0xe5,		/* 229 */
			0x9b,		/* 155 */
/* 4068 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 4070 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4072) */
/* 4072 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4074 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4078 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4078) */
/* 4080 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4082 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4084 */	0x8,		/* FC_LONG */
			0xd,		/* FC_ENUM16 */
/* 4086 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 4088 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4090 */	
			0x11, 0x0,	/* FC_RP */
/* 4092 */	NdrFcShort( 0xffec ),	/* Offset= -20 (4072) */
/* 4094 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 4096 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4098) */
/* 4098 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 4100 */	NdrFcLong( 0x105 ),	/* 261 */
/* 4104 */	NdrFcShort( 0xa8f2 ),	/* -22286 */
/* 4106 */	NdrFcShort( 0x4877 ),	/* 18551 */
/* 4108 */	0xba,		/* 186 */
			0xa,		/* 10 */
/* 4110 */	0xfd,		/* 253 */
			0x2b,		/* 43 */
/* 4112 */	0x66,		/* 102 */
			0x45,		/* 69 */
/* 4114 */	0xfb,		/* 251 */
			0x94,		/* 148 */
/* 4116 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 4118 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4120) */
/* 4120 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4122 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4126 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4126) */
/* 4128 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 4130 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4132 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            WICInProcPointer_UserSize
            ,WICInProcPointer_UserMarshal
            ,WICInProcPointer_UserUnmarshal
            ,WICInProcPointer_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            HBITMAP_UserSize
            ,HBITMAP_UserMarshal
            ,HBITMAP_UserUnmarshal
            ,HBITMAP_UserFree
            },
            {
            HPALETTE_UserSize
            ,HPALETTE_UserMarshal
            ,HPALETTE_UserUnmarshal
            ,HPALETTE_UserFree
            },
            {
            HICON_UserSize
            ,HICON_UserMarshal
            ,HICON_UserUnmarshal
            ,HICON_UserFree
            }

        };


static void __RPC_USER IWICEnumMetadataItem_PROPVARIANTExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    PROPVARIANT *pS	=	( PROPVARIANT * )(( pStubMsg->StackTop - 8 ) );
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = (ULONG_PTR) ( ( unsigned short  )pS->vt );
}

static void __RPC_USER IWICEnumMetadataItem_CLIPDATAExprEval_0001( PMIDL_STUB_MESSAGE pStubMsg )
{
    CLIPDATA *pS	=	( CLIPDATA * )pStubMsg->StackTop;
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = (ULONG_PTR) ( ( pS->cbSize - 4 )  );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IWICEnumMetadataItem_PROPVARIANTExprEval_0000
    ,IWICEnumMetadataItem_CLIPDATAExprEval_0001
    };



/* Standard interface: __MIDL_itf_wincodec_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWICPalette, ver. 0.0,
   GUID={0x00000040,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPalette_FormatStringOffsetTable[] =
    {
    0,
    44,
    88,
    138,
    176,
    214,
    252,
    302,
    340,
    378
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPalette_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPalette_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPalette_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPalette_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWICPaletteProxyVtbl = 
{
    &IWICPalette_ProxyInfo,
    &IID_IWICPalette,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICPalette::InitializePredefined */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::InitializeCustom */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::InitializeFromBitmap */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::InitializeFromPalette */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::GetType */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::GetColorCount */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::GetColors */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::IsBlackWhite */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::IsGrayscale */ ,
    (void *) (INT_PTR) -1 /* IWICPalette::HasAlpha */
};

const CInterfaceStubVtbl _IWICPaletteStubVtbl =
{
    &IID_IWICPalette,
    &IWICPalette_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapSource, ver. 0.0,
   GUID={0x00000120,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapSource_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapSource_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapSource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapSource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapSource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IWICBitmapSourceProxyVtbl = 
{
    &IWICBitmapSource_ProxyInfo,
    &IID_IWICBitmapSource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */
};

const CInterfaceStubVtbl _IWICBitmapSourceStubVtbl =
{
    &IID_IWICBitmapSource,
    &IWICBitmapSource_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICFormatConverter, ver. 0.0,
   GUID={0x00000301,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICFormatConverter_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    598,
    666
    };

static const MIDL_STUBLESS_PROXY_INFO IWICFormatConverter_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFormatConverter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICFormatConverter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFormatConverter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IWICFormatConverterProxyVtbl = 
{
    &IWICFormatConverter_ProxyInfo,
    &IID_IWICFormatConverter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICFormatConverter::Initialize */ ,
    (void *) (INT_PTR) -1 /* IWICFormatConverter::CanConvert */
};

const CInterfaceStubVtbl _IWICFormatConverterStubVtbl =
{
    &IID_IWICFormatConverter,
    &IWICFormatConverter_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICPlanarFormatConverter, ver. 0.0,
   GUID={0xBEBEE9CB,0x83B0,0x4DCC,{0x81,0x32,0xB0,0xAA,0xA5,0x5E,0xAC,0x96}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPlanarFormatConverter_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    716,
    790
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPlanarFormatConverter_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarFormatConverter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPlanarFormatConverter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarFormatConverter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IWICPlanarFormatConverterProxyVtbl = 
{
    &IWICPlanarFormatConverter_ProxyInfo,
    &IID_IWICPlanarFormatConverter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICPlanarFormatConverter::Initialize */ ,
    (void *) (INT_PTR) -1 /* IWICPlanarFormatConverter::CanConvert */
};

const CInterfaceStubVtbl _IWICPlanarFormatConverterStubVtbl =
{
    &IID_IWICPlanarFormatConverter,
    &IWICPlanarFormatConverter_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapScaler, ver. 0.0,
   GUID={0x00000302,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapScaler_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    846
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapScaler_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapScaler_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapScaler_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapScaler_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICBitmapScalerProxyVtbl = 
{
    &IWICBitmapScaler_ProxyInfo,
    &IID_IWICBitmapScaler,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapScaler::Initialize */
};

const CInterfaceStubVtbl _IWICBitmapScalerStubVtbl =
{
    &IID_IWICBitmapScaler,
    &IWICBitmapScaler_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapClipper, ver. 0.0,
   GUID={0xE4FBCF03,0x223D,0x4e81,{0x93,0x33,0xD6,0x35,0x55,0x6D,0xD1,0xB5}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapClipper_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    902
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapClipper_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapClipper_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapClipper_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapClipper_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICBitmapClipperProxyVtbl = 
{
    &IWICBitmapClipper_ProxyInfo,
    &IID_IWICBitmapClipper,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapClipper::Initialize */
};

const CInterfaceStubVtbl _IWICBitmapClipperStubVtbl =
{
    &IID_IWICBitmapClipper,
    &IWICBitmapClipper_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapFlipRotator, ver. 0.0,
   GUID={0x5009834F,0x2D6A,0x41ce,{0x9E,0x1B,0x17,0xC5,0xAF,0xF7,0xA7,0x82}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapFlipRotator_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    946
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapFlipRotator_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFlipRotator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapFlipRotator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFlipRotator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICBitmapFlipRotatorProxyVtbl = 
{
    &IWICBitmapFlipRotator_ProxyInfo,
    &IID_IWICBitmapFlipRotator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFlipRotator::Initialize */
};

const CInterfaceStubVtbl _IWICBitmapFlipRotatorStubVtbl =
{
    &IID_IWICBitmapFlipRotator,
    &IWICBitmapFlipRotator_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapLock, ver. 0.0,
   GUID={0x00000123,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapLock_FormatStringOffsetTable[] =
    {
    416,
    990,
    1028,
    1072
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapLock_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapLock_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapLock_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapLock_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWICBitmapLockProxyVtbl = 
{
    &IWICBitmapLock_ProxyInfo,
    &IID_IWICBitmapLock,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapLock::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapLock::GetStride */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapLock::GetDataPointer */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapLock::GetPixelFormat */
};

const CInterfaceStubVtbl _IWICBitmapLockStubVtbl =
{
    &IID_IWICBitmapLock,
    &IWICBitmapLock_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmap, ver. 0.0,
   GUID={0x00000121,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmap_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    1110,
    1160,
    1198
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmap_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmap_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmap_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmap_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IWICBitmapProxyVtbl = 
{
    &IWICBitmap_ProxyInfo,
    &IID_IWICBitmap,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmap::Lock */ ,
    (void *) (INT_PTR) -1 /* IWICBitmap::SetPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmap::SetResolution */
};

const CInterfaceStubVtbl _IWICBitmapStubVtbl =
{
    &IID_IWICBitmap,
    &IWICBitmap_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICColorContext, ver. 0.0,
   GUID={0x3C613A02,0x34B2,0x44ea,{0x9A,0x7C,0x45,0xAE,0xA9,0xC6,0xFD,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IWICColorContext_FormatStringOffsetTable[] =
    {
    1242,
    1280,
    1324,
    1362,
    1400,
    214
    };

static const MIDL_STUBLESS_PROXY_INFO IWICColorContext_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICColorContext_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICColorContext_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICColorContext_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICColorContextProxyVtbl = 
{
    &IWICColorContext_ProxyInfo,
    &IID_IWICColorContext,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICColorContext::InitializeFromFilename */ ,
    (void *) (INT_PTR) -1 /* IWICColorContext::InitializeFromMemory */ ,
    (void *) (INT_PTR) -1 /* IWICColorContext::InitializeFromExifColorSpace */ ,
    (void *) (INT_PTR) -1 /* IWICColorContext::GetType */ ,
    (void *) (INT_PTR) -1 /* IWICColorContext::GetProfileBytes */ ,
    (void *) (INT_PTR) -1 /* IWICColorContext::GetExifColorSpace */
};

const CInterfaceStubVtbl _IWICColorContextStubVtbl =
{
    &IID_IWICColorContext,
    &IWICColorContext_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICColorTransform, ver. 0.0,
   GUID={0xB66F034F,0xD0E2,0x40ab,{0xB4,0x36,0x6D,0xE3,0x9E,0x32,0x1A,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICColorTransform_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    1450
    };

static const MIDL_STUBLESS_PROXY_INFO IWICColorTransform_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICColorTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICColorTransform_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICColorTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICColorTransformProxyVtbl = 
{
    &IWICColorTransform_ProxyInfo,
    &IID_IWICColorTransform,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICColorTransform::Initialize */
};

const CInterfaceStubVtbl _IWICColorTransformStubVtbl =
{
    &IID_IWICColorTransform,
    &IWICColorTransform_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICFastMetadataEncoder, ver. 0.0,
   GUID={0xB84E2C09,0x78C9,0x4AC4,{0x8B,0xD3,0x52,0x4A,0xE1,0x66,0x3A,0x2F}} */

#pragma code_seg(".orpc")
static const unsigned short IWICFastMetadataEncoder_FormatStringOffsetTable[] =
    {
    1506,
    1538
    };

static const MIDL_STUBLESS_PROXY_INFO IWICFastMetadataEncoder_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFastMetadataEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICFastMetadataEncoder_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFastMetadataEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWICFastMetadataEncoderProxyVtbl = 
{
    &IWICFastMetadataEncoder_ProxyInfo,
    &IID_IWICFastMetadataEncoder,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICFastMetadataEncoder::Commit */ ,
    (void *) (INT_PTR) -1 /* IWICFastMetadataEncoder::GetMetadataQueryWriter */
};

const CInterfaceStubVtbl _IWICFastMetadataEncoderStubVtbl =
{
    &IID_IWICFastMetadataEncoder,
    &IWICFastMetadataEncoder_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISequentialStream, ver. 0.0,
   GUID={0x0c733a30,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}} */


/* Object interface: IStream, ver. 0.0,
   GUID={0x0000000c,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWICStream, ver. 0.0,
   GUID={0x135FF860,0x22B7,0x4ddf,{0xB0,0xF6,0x21,0x8F,0x4F,0x29,0x9A,0x43}} */

#pragma code_seg(".orpc")
static const unsigned short IWICStream_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1576,
    1614,
    1658,
    1702
    };

static const MIDL_STUBLESS_PROXY_INFO IWICStream_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IWICStreamProxyVtbl = 
{
    &IWICStream_ProxyInfo,
    &IID_IWICStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* ISequentialStream_Read_Proxy */ ,
    0 /* ISequentialStream_Write_Proxy */ ,
    0 /* IStream_Seek_Proxy */ ,
    0 /* IStream::SetSize */ ,
    0 /* IStream_CopyTo_Proxy */ ,
    0 /* IStream::Commit */ ,
    0 /* IStream::Revert */ ,
    0 /* IStream::LockRegion */ ,
    0 /* IStream::UnlockRegion */ ,
    0 /* IStream::Stat */ ,
    0 /* IStream::Clone */ ,
    (void *) (INT_PTR) -1 /* IWICStream::InitializeFromIStream */ ,
    (void *) (INT_PTR) -1 /* IWICStream::InitializeFromFilename */ ,
    (void *) (INT_PTR) -1 /* IWICStream::InitializeFromMemory */ ,
    (void *) (INT_PTR) -1 /* IWICStream::InitializeFromIStreamRegion */
};


static const PRPC_STUB_FUNCTION IWICStream_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IWICStreamStubVtbl =
{
    &IID_IWICStream,
    &IWICStream_ServerInfo,
    18,
    &IWICStream_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWICEnumMetadataItem, ver. 0.0,
   GUID={0xDC2BB46D,0x3F07,0x481E,{0x86,0x25,0x22,0x0C,0x4A,0xED,0xBB,0x33}} */

#pragma code_seg(".orpc")
static const unsigned short IWICEnumMetadataItem_FormatStringOffsetTable[] =
    {
    1752,
    1814,
    1852,
    1884
    };

static const MIDL_STUBLESS_PROXY_INFO IWICEnumMetadataItem_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICEnumMetadataItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICEnumMetadataItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICEnumMetadataItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWICEnumMetadataItemProxyVtbl = 
{
    &IWICEnumMetadataItem_ProxyInfo,
    &IID_IWICEnumMetadataItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICEnumMetadataItem::Next */ ,
    (void *) (INT_PTR) -1 /* IWICEnumMetadataItem::Skip */ ,
    (void *) (INT_PTR) -1 /* IWICEnumMetadataItem::Reset */ ,
    (void *) (INT_PTR) -1 /* IWICEnumMetadataItem::Clone */
};

const CInterfaceStubVtbl _IWICEnumMetadataItemStubVtbl =
{
    &IID_IWICEnumMetadataItem,
    &IWICEnumMetadataItem_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICMetadataQueryReader, ver. 0.0,
   GUID={0x30989668,0xE1C9,0x4597,{0xB3,0x95,0x45,0x8E,0xED,0xB8,0x08,0xDF}} */

#pragma code_seg(".orpc")
static const unsigned short IWICMetadataQueryReader_FormatStringOffsetTable[] =
    {
    1922,
    1960,
    2010,
    2054
    };

static const MIDL_STUBLESS_PROXY_INFO IWICMetadataQueryReader_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICMetadataQueryReader_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICMetadataQueryReader_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICMetadataQueryReader_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWICMetadataQueryReaderProxyVtbl = 
{
    &IWICMetadataQueryReader_ProxyInfo,
    &IID_IWICMetadataQueryReader,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetMetadataByName */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetEnumerator */
};

const CInterfaceStubVtbl _IWICMetadataQueryReaderStubVtbl =
{
    &IID_IWICMetadataQueryReader,
    &IWICMetadataQueryReader_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICMetadataQueryWriter, ver. 0.0,
   GUID={0xA721791A,0x0DEF,0x4d06,{0xBD,0x91,0x21,0x18,0xBF,0x1D,0xB1,0x0B}} */

#pragma code_seg(".orpc")
static const unsigned short IWICMetadataQueryWriter_FormatStringOffsetTable[] =
    {
    1922,
    1960,
    2010,
    2054,
    2092,
    2136
    };

static const MIDL_STUBLESS_PROXY_INFO IWICMetadataQueryWriter_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICMetadataQueryWriter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICMetadataQueryWriter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICMetadataQueryWriter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWICMetadataQueryWriterProxyVtbl = 
{
    &IWICMetadataQueryWriter_ProxyInfo,
    &IID_IWICMetadataQueryWriter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetLocation */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetMetadataByName */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryReader::GetEnumerator */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryWriter::SetMetadataByName */ ,
    (void *) (INT_PTR) -1 /* IWICMetadataQueryWriter::RemoveMetadataByName */
};

const CInterfaceStubVtbl _IWICMetadataQueryWriterStubVtbl =
{
    &IID_IWICMetadataQueryWriter,
    &IWICMetadataQueryWriter_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapEncoder, ver. 0.0,
   GUID={0x00000103,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapEncoder_FormatStringOffsetTable[] =
    {
    2174,
    460,
    2218,
    2256,
    2300,
    2338,
    2376,
    2414,
    2458,
    2490
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapEncoder_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapEncoder_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWICBitmapEncoderProxyVtbl = 
{
    &IWICBitmapEncoder_ProxyInfo,
    &IID_IWICBitmapEncoder,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::Initialize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::GetEncoderInfo */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::SetColorContexts */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::SetPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::SetThumbnail */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::SetPreview */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::CreateNewFrame */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::Commit */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoder::GetMetadataQueryWriter */
};

const CInterfaceStubVtbl _IWICBitmapEncoderStubVtbl =
{
    &IID_IWICBitmapEncoder,
    &IWICBitmapEncoder_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapFrameEncode, ver. 0.0,
   GUID={0x00000105,0xa8f2,0x4877,{0xba,0x0a,0xfd,0x2b,0x66,0x45,0xfb,0x94}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapFrameEncode_FormatStringOffsetTable[] =
    {
    2528,
    2566,
    2610,
    2654,
    2692,
    2736,
    2376,
    2774,
    2830,
    2874,
    2906
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapFrameEncode_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFrameEncode_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapFrameEncode_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFrameEncode_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IWICBitmapFrameEncodeProxyVtbl = 
{
    &IWICBitmapFrameEncode_ProxyInfo,
    &IID_IWICBitmapFrameEncode,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::Initialize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetColorContexts */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::SetThumbnail */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::WritePixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::WriteSource */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::Commit */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameEncode::GetMetadataQueryWriter */
};

const CInterfaceStubVtbl _IWICBitmapFrameEncodeStubVtbl =
{
    &IID_IWICBitmapFrameEncode,
    &IWICBitmapFrameEncode_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICPlanarBitmapFrameEncode, ver. 0.0,
   GUID={0xF928B7B8,0x2221,0x40C1,{0xB7,0x2E,0x7E,0x82,0xF1,0x97,0x4D,0x1A}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPlanarBitmapFrameEncode_FormatStringOffsetTable[] =
    {
    2944,
    2994
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPlanarBitmapFrameEncode_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarBitmapFrameEncode_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPlanarBitmapFrameEncode_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarBitmapFrameEncode_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWICPlanarBitmapFrameEncodeProxyVtbl = 
{
    &IWICPlanarBitmapFrameEncode_ProxyInfo,
    &IID_IWICPlanarBitmapFrameEncode,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICPlanarBitmapFrameEncode::WritePixels */ ,
    (void *) (INT_PTR) -1 /* IWICPlanarBitmapFrameEncode::WriteSource */
};

const CInterfaceStubVtbl _IWICPlanarBitmapFrameEncodeStubVtbl =
{
    &IID_IWICPlanarBitmapFrameEncode,
    &IWICPlanarBitmapFrameEncode_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_wincodec_0000_0019, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICImageEncoder, ver. 0.0,
   GUID={0x04C75BF8,0x3CE1,0x473B,{0xAC,0xC5,0x3C,0xC4,0xF5,0xE9,0x49,0x99}} */


/* Standard interface: __MIDL_itf_wincodec_0000_0020, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICBitmapDecoder, ver. 0.0,
   GUID={0x9EDDE9E7,0x8DEE,0x47ea,{0x99,0xDF,0xE6,0xFA,0xF2,0xED,0x44,0xBF}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapDecoder_FormatStringOffsetTable[] =
    {
    3044,
    3088,
    3132,
    3170,
    2300,
    3208,
    3246,
    3284,
    3334,
    378,
    3372
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapDecoder_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapDecoder_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapDecoder_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapDecoder_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IWICBitmapDecoderProxyVtbl = 
{
    &IWICBitmapDecoder_ProxyInfo,
    &IID_IWICBitmapDecoder,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::QueryCapability */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::Initialize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetDecoderInfo */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetMetadataQueryReader */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetPreview */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetColorContexts */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetThumbnail */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetFrameCount */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoder::GetFrame */
};

const CInterfaceStubVtbl _IWICBitmapDecoderStubVtbl =
{
    &IID_IWICBitmapDecoder,
    &IWICBitmapDecoder_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapSourceTransform, ver. 0.0,
   GUID={0x3B16811B,0x6A43,0x4ec9,{0xB7,0x13,0x3D,0x5A,0x0C,0x13,0xB9,0x40}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapSourceTransform_FormatStringOffsetTable[] =
    {
    3416,
    3496,
    3540,
    3578
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapSourceTransform_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapSourceTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapSourceTransform_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapSourceTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWICBitmapSourceTransformProxyVtbl = 
{
    &IWICBitmapSourceTransform_ProxyInfo,
    &IID_IWICBitmapSourceTransform,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSourceTransform::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSourceTransform::GetClosestSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSourceTransform::GetClosestPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSourceTransform::DoesSupportTransform */
};

const CInterfaceStubVtbl _IWICBitmapSourceTransformStubVtbl =
{
    &IID_IWICBitmapSourceTransform,
    &IWICBitmapSourceTransform_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICPlanarBitmapSourceTransform, ver. 0.0,
   GUID={0x3AFF9CCE,0xBE95,0x4303,{0xB9,0x27,0xE7,0xD1,0x6F,0xF4,0xA6,0x13}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPlanarBitmapSourceTransform_FormatStringOffsetTable[] =
    {
    3622,
    3702
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPlanarBitmapSourceTransform_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarBitmapSourceTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPlanarBitmapSourceTransform_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPlanarBitmapSourceTransform_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWICPlanarBitmapSourceTransformProxyVtbl = 
{
    &IWICPlanarBitmapSourceTransform_ProxyInfo,
    &IID_IWICPlanarBitmapSourceTransform,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICPlanarBitmapSourceTransform::DoesSupportTransform */ ,
    (void *) (INT_PTR) -1 /* IWICPlanarBitmapSourceTransform::CopyPixels */
};

const CInterfaceStubVtbl _IWICPlanarBitmapSourceTransformStubVtbl =
{
    &IID_IWICPlanarBitmapSourceTransform,
    &IWICPlanarBitmapSourceTransform_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapFrameDecode, ver. 0.0,
   GUID={0x3B16811B,0x6A43,0x4ec9,{0xA8,0x13,0x3D,0x93,0x0C,0x13,0xB9,0x40}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapFrameDecode_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    3208,
    3776,
    3826
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapFrameDecode_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFrameDecode_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapFrameDecode_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapFrameDecode_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IWICBitmapFrameDecodeProxyVtbl = 
{
    &IWICBitmapFrameDecode_ProxyInfo,
    &IID_IWICBitmapFrameDecode,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetMetadataQueryReader */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetColorContexts */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetThumbnail */
};

const CInterfaceStubVtbl _IWICBitmapFrameDecodeStubVtbl =
{
    &IID_IWICBitmapFrameDecode,
    &IWICBitmapFrameDecode_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICProgressiveLevelControl, ver. 0.0,
   GUID={0xDAAC296F,0x7AA5,0x4dbf,{0x8D,0x15,0x22,0x5C,0x59,0x76,0xF8,0x91}} */

#pragma code_seg(".orpc")
static const unsigned short IWICProgressiveLevelControl_FormatStringOffsetTable[] =
    {
    3864,
    990,
    1324
    };

static const MIDL_STUBLESS_PROXY_INFO IWICProgressiveLevelControl_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICProgressiveLevelControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICProgressiveLevelControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICProgressiveLevelControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IWICProgressiveLevelControlProxyVtbl = 
{
    &IWICProgressiveLevelControl_ProxyInfo,
    &IID_IWICProgressiveLevelControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICProgressiveLevelControl::GetLevelCount */ ,
    (void *) (INT_PTR) -1 /* IWICProgressiveLevelControl::GetCurrentLevel */ ,
    (void *) (INT_PTR) -1 /* IWICProgressiveLevelControl::SetCurrentLevel */
};

const CInterfaceStubVtbl _IWICProgressiveLevelControlStubVtbl =
{
    &IID_IWICProgressiveLevelControl,
    &IWICProgressiveLevelControl_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICProgressCallback, ver. 0.0,
   GUID={0x4776F9CD,0x9517,0x45FA,{0xBF,0x24,0xE8,0x9C,0x5E,0xC5,0xC6,0x0C}} */

#pragma code_seg(".orpc")
static const unsigned short IWICProgressCallback_FormatStringOffsetTable[] =
    {
    3902
    };

static const MIDL_STUBLESS_PROXY_INFO IWICProgressCallback_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICProgressCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICProgressCallback_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICProgressCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWICProgressCallbackProxyVtbl = 
{
    &IWICProgressCallback_ProxyInfo,
    &IID_IWICProgressCallback,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICProgressCallback::Notify */
};

const CInterfaceStubVtbl _IWICProgressCallbackStubVtbl =
{
    &IID_IWICProgressCallback,
    &IWICProgressCallback_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapCodecProgressNotification, ver. 0.0,
   GUID={0x64C1024E,0xC3CF,0x4462,{0x80,0x78,0x88,0xC2,0xB1,0x1C,0x46,0xD9}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapCodecProgressNotification_FormatStringOffsetTable[] =
    {
    3952
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapCodecProgressNotification_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapCodecProgressNotification_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IWICBitmapCodecProgressNotification_StubThunkTable[] = 
    {
    IWICBitmapCodecProgressNotification_Remote_RegisterProgressNotification_Thunk
    };

static const MIDL_SERVER_INFO IWICBitmapCodecProgressNotification_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapCodecProgressNotification_FormatStringOffsetTable[-3],
    &IWICBitmapCodecProgressNotification_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWICBitmapCodecProgressNotificationProxyVtbl = 
{
    &IWICBitmapCodecProgressNotification_ProxyInfo,
    &IID_IWICBitmapCodecProgressNotification,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IWICBitmapCodecProgressNotification_RegisterProgressNotification_Proxy
};

const CInterfaceStubVtbl _IWICBitmapCodecProgressNotificationStubVtbl =
{
    &IID_IWICBitmapCodecProgressNotification,
    &IWICBitmapCodecProgressNotification_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICComponentInfo, ver. 0.0,
   GUID={0x23BC3F0A,0x698B,0x4357,{0x88,0x6B,0xF2,0x4D,0x50,0x67,0x13,0x34}} */

#pragma code_seg(".orpc")
static const unsigned short IWICComponentInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260
    };

static const MIDL_STUBLESS_PROXY_INFO IWICComponentInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICComponentInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICComponentInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICComponentInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IWICComponentInfoProxyVtbl = 
{
    &IWICComponentInfo_ProxyInfo,
    &IID_IWICComponentInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */
};

const CInterfaceStubVtbl _IWICComponentInfoStubVtbl =
{
    &IID_IWICComponentInfo,
    &IWICComponentInfo_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICFormatConverterInfo, ver. 0.0,
   GUID={0x9F34FB65,0x13F4,0x4f15,{0xBC,0x57,0x37,0x26,0xB5,0xE5,0x3D,0x9F}} */

#pragma code_seg(".orpc")
static const unsigned short IWICFormatConverterInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4310,
    4360
    };

static const MIDL_STUBLESS_PROXY_INFO IWICFormatConverterInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFormatConverterInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICFormatConverterInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICFormatConverterInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWICFormatConverterInfoProxyVtbl = 
{
    &IWICFormatConverterInfo_ProxyInfo,
    &IID_IWICFormatConverterInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICFormatConverterInfo::GetPixelFormats */ ,
    (void *) (INT_PTR) -1 /* IWICFormatConverterInfo::CreateInstance */
};

const CInterfaceStubVtbl _IWICFormatConverterInfoStubVtbl =
{
    &IID_IWICFormatConverterInfo,
    &IWICFormatConverterInfo_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapCodecInfo, ver. 0.0,
   GUID={0xE87A44C4,0xB76E,0x4c47,{0x8B,0x09,0x29,0x8E,0xB1,0x2A,0x27,0x14}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapCodecInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4398,
    4436,
    4486,
    4536,
    4586,
    4636,
    4686,
    4736,
    4774,
    4812,
    4850,
    4888
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapCodecInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapCodecInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapCodecInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapCodecInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IWICBitmapCodecInfoProxyVtbl = 
{
    &IWICBitmapCodecInfo_ProxyInfo,
    &IID_IWICBitmapCodecInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetPixelFormats */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetColorManagementVersion */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceManufacturer */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceModels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetMimeTypes */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetFileExtensions */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportAnimation */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportChromakey */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportLossless */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportMultiframe */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::MatchesMimeType */
};

const CInterfaceStubVtbl _IWICBitmapCodecInfoStubVtbl =
{
    &IID_IWICBitmapCodecInfo,
    &IWICBitmapCodecInfo_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapEncoderInfo, ver. 0.0,
   GUID={0x94C9B4EE,0xA09F,0x4f92,{0x8A,0x1E,0x4A,0x9B,0xCE,0x7E,0x76,0xFB}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapEncoderInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4398,
    4436,
    4486,
    4536,
    4586,
    4636,
    4686,
    4736,
    4774,
    4812,
    4850,
    4888,
    4932
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapEncoderInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapEncoderInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICBitmapEncoderInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapEncoderInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IWICBitmapEncoderInfoProxyVtbl = 
{
    &IWICBitmapEncoderInfo_ProxyInfo,
    &IID_IWICBitmapEncoderInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetPixelFormats */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetColorManagementVersion */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceManufacturer */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceModels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetMimeTypes */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetFileExtensions */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportAnimation */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportChromakey */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportLossless */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportMultiframe */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::MatchesMimeType */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapEncoderInfo::CreateInstance */
};

const CInterfaceStubVtbl _IWICBitmapEncoderInfoStubVtbl =
{
    &IID_IWICBitmapEncoderInfo,
    &IWICBitmapEncoderInfo_ServerInfo,
    24,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICBitmapDecoderInfo, ver. 0.0,
   GUID={0xD8CD007F,0xD08F,0x4191,{0x9B,0xFC,0x23,0x6E,0xA7,0xF0,0xE4,0xB5}} */

#pragma code_seg(".orpc")
static const unsigned short IWICBitmapDecoderInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4398,
    4436,
    4486,
    4536,
    4586,
    4636,
    4686,
    4736,
    4774,
    4812,
    4850,
    4888,
    4970,
    5014,
    5058
    };

static const MIDL_STUBLESS_PROXY_INFO IWICBitmapDecoderInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapDecoderInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IWICBitmapDecoderInfo_StubThunkTable[] = 
    {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    IWICBitmapDecoderInfo_Remote_GetPatterns_Thunk,
    0,
    0
    };

static const MIDL_SERVER_INFO IWICBitmapDecoderInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICBitmapDecoderInfo_FormatStringOffsetTable[-3],
    &IWICBitmapDecoderInfo_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(26) _IWICBitmapDecoderInfoProxyVtbl = 
{
    &IWICBitmapDecoderInfo_ProxyInfo,
    &IID_IWICBitmapDecoderInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetContainerFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetPixelFormats */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetColorManagementVersion */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceManufacturer */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetDeviceModels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetMimeTypes */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::GetFileExtensions */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportAnimation */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportChromakey */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportLossless */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::DoesSupportMultiframe */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapCodecInfo::MatchesMimeType */ ,
    IWICBitmapDecoderInfo_GetPatterns_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoderInfo::MatchesPattern */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapDecoderInfo::CreateInstance */
};

const CInterfaceStubVtbl _IWICBitmapDecoderInfoStubVtbl =
{
    &IID_IWICBitmapDecoderInfo,
    &IWICBitmapDecoderInfo_ServerInfo,
    26,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICPixelFormatInfo, ver. 0.0,
   GUID={0xE8EDA601,0x3D48,0x431a,{0xAB,0x44,0x69,0x05,0x9B,0xE8,0x8B,0xBE}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPixelFormatInfo_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4398,
    5096,
    5134,
    5172,
    5210
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPixelFormatInfo_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPixelFormatInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPixelFormatInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPixelFormatInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _IWICPixelFormatInfoProxyVtbl = 
{
    &IWICPixelFormatInfo_ProxyInfo,
    &IID_IWICPixelFormatInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetFormatGUID */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetColorContext */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetBitsPerPixel */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetChannelCount */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetChannelMask */
};

const CInterfaceStubVtbl _IWICPixelFormatInfoStubVtbl =
{
    &IID_IWICPixelFormatInfo,
    &IWICPixelFormatInfo_ServerInfo,
    16,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICPixelFormatInfo2, ver. 0.0,
   GUID={0xA9DB33A2,0xAF5F,0x43C7,{0xB6,0x79,0x74,0xF5,0x98,0x4B,0x5A,0xA4}} */

#pragma code_seg(".orpc")
static const unsigned short IWICPixelFormatInfo2_FormatStringOffsetTable[] =
    {
    3996,
    460,
    4034,
    4072,
    4122,
    4160,
    4210,
    4260,
    4398,
    5096,
    5134,
    5172,
    5210,
    5266,
    5304
    };

static const MIDL_STUBLESS_PROXY_INFO IWICPixelFormatInfo2_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPixelFormatInfo2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICPixelFormatInfo2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICPixelFormatInfo2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IWICPixelFormatInfo2ProxyVtbl = 
{
    &IWICPixelFormatInfo2_ProxyInfo,
    &IID_IWICPixelFormatInfo2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetComponentType */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetCLSID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSigningStatus */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetAuthor */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVendorGUID */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetSpecVersion */ ,
    (void *) (INT_PTR) -1 /* IWICComponentInfo::GetFriendlyName */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetFormatGUID */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetColorContext */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetBitsPerPixel */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetChannelCount */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo::GetChannelMask */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo2::SupportsTransparency */ ,
    (void *) (INT_PTR) -1 /* IWICPixelFormatInfo2::GetNumericRepresentation */
};

const CInterfaceStubVtbl _IWICPixelFormatInfo2StubVtbl =
{
    &IID_IWICPixelFormatInfo2,
    &IWICPixelFormatInfo2_ServerInfo,
    18,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICImagingFactory, ver. 0.0,
   GUID={0xec5ec8a9,0xc395,0x4314,{0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70}} */

#pragma code_seg(".orpc")
static const unsigned short IWICImagingFactory_FormatStringOffsetTable[] =
    {
    5342,
    5404,
    5460,
    5516,
    5560,
    5610,
    5660,
    5698,
    5736,
    5774,
    5812,
    5850,
    5888,
    5926,
    5964,
    6026,
    6076,
    6144,
    6218,
    6274,
    6318,
    6368,
    6412,
    6456,
    6506
    };

static const MIDL_STUBLESS_PROXY_INFO IWICImagingFactory_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICImagingFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICImagingFactory_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICImagingFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(28) _IWICImagingFactoryProxyVtbl = 
{
    &IWICImagingFactory_ProxyInfo,
    &IID_IWICImagingFactory,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateDecoderFromFilename */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateDecoderFromStream */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateDecoderFromFileHandle */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateComponentInfo */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateDecoder */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateEncoder */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreatePalette */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateFormatConverter */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapScaler */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapClipper */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFlipRotator */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateStream */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateColorContext */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateColorTransformer */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmap */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFromSource */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFromSourceRect */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFromMemory */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFromHBITMAP */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateBitmapFromHICON */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateComponentEnumerator */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateFastMetadataEncoderFromDecoder */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateFastMetadataEncoderFromFrameDecode */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateQueryWriter */ ,
    (void *) (INT_PTR) -1 /* IWICImagingFactory::CreateQueryWriterFromReader */
};

const CInterfaceStubVtbl _IWICImagingFactoryStubVtbl =
{
    &IID_IWICImagingFactory,
    &IWICImagingFactory_ServerInfo,
    28,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_wincodec_0000_0035, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICImagingFactory2, ver. 0.0,
   GUID={0x7B816B45,0x1996,0x4476,{0xB1,0x32,0xDE,0x9E,0x24,0x7C,0x8A,0xF0}} */


/* Standard interface: __MIDL_itf_wincodec_0000_0036, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICDevelopRawNotificationCallback, ver. 0.0,
   GUID={0x95c75a6e,0x3e8c,0x4ec2,{0x85,0xa8,0xae,0xbc,0xc5,0x51,0xe5,0x9b}} */

#pragma code_seg(".orpc")
static const unsigned short IWICDevelopRawNotificationCallback_FormatStringOffsetTable[] =
    {
    6556
    };

static const MIDL_STUBLESS_PROXY_INFO IWICDevelopRawNotificationCallback_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDevelopRawNotificationCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICDevelopRawNotificationCallback_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDevelopRawNotificationCallback_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWICDevelopRawNotificationCallbackProxyVtbl = 
{
    &IWICDevelopRawNotificationCallback_ProxyInfo,
    &IID_IWICDevelopRawNotificationCallback,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDevelopRawNotificationCallback::Notify */
};

const CInterfaceStubVtbl _IWICDevelopRawNotificationCallbackStubVtbl =
{
    &IID_IWICDevelopRawNotificationCallback,
    &IWICDevelopRawNotificationCallback_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICDevelopRaw, ver. 0.0,
   GUID={0xfbec5e44,0xf7be,0x4b65,{0xb7,0xf8,0xc0,0xc8,0x1f,0xef,0x02,0x6d}} */

#pragma code_seg(".orpc")
static const unsigned short IWICDevelopRaw_FormatStringOffsetTable[] =
    {
    416,
    460,
    498,
    138,
    542,
    3208,
    3776,
    3826,
    6594,
    6632,
    6670,
    6708,
    6746,
    6784,
    6834,
    6884,
    6922,
    6960,
    4850,
    6998,
    7048,
    7086,
    7124,
    7162,
    7200,
    7238,
    7276,
    7314,
    7352,
    7390,
    7428,
    7466,
    7504,
    7542,
    7586,
    7630,
    7668,
    7706,
    7744,
    7782
    };

static const MIDL_STUBLESS_PROXY_INFO IWICDevelopRaw_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDevelopRaw_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IWICDevelopRaw_StubThunkTable[] = 
    {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    IWICDevelopRaw_Remote_QueryRawCapabilitiesInfo_Thunk,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    IWICDevelopRaw_Remote_SetToneCurve_Thunk,
    IWICDevelopRaw_Remote_GetToneCurve_Thunk,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IWICDevelopRaw_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDevelopRaw_FormatStringOffsetTable[-3],
    &IWICDevelopRaw_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(43) _IWICDevelopRawProxyVtbl = 
{
    &IWICDevelopRaw_ProxyInfo,
    &IID_IWICDevelopRaw,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetSize */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetPixelFormat */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::GetResolution */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPalette */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapSource::CopyPixels */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetMetadataQueryReader */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetColorContexts */ ,
    (void *) (INT_PTR) -1 /* IWICBitmapFrameDecode::GetThumbnail */ ,
    IWICDevelopRaw_QueryRawCapabilitiesInfo_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::LoadParameterSet */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetCurrentParameterSet */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetExposureCompensation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetExposureCompensation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetWhitePointRGB */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetWhitePointRGB */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetNamedWhitePoint */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetNamedWhitePoint */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetWhitePointKelvin */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetWhitePointKelvin */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetKelvinRangeInfo */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetContrast */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetContrast */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetGamma */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetGamma */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetSharpness */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetSharpness */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetSaturation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetSaturation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetTint */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetTint */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetNoiseReduction */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetNoiseReduction */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetDestinationColorContext */ ,
    IWICDevelopRaw_SetToneCurve_Proxy ,
    IWICDevelopRaw_GetToneCurve_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetRotation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetRotation */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetRenderMode */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::GetRenderMode */ ,
    (void *) (INT_PTR) -1 /* IWICDevelopRaw::SetNotificationCallback */
};

const CInterfaceStubVtbl _IWICDevelopRawStubVtbl =
{
    &IID_IWICDevelopRaw,
    &IWICDevelopRaw_ServerInfo,
    43,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_wincodec_0000_0038, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICDdsDecoder, ver. 0.0,
   GUID={0x409cd537,0x8532,0x40cb,{0x97,0x74,0xe2,0xfe,0xb2,0xdf,0x4e,0x9c}} */

#pragma code_seg(".orpc")
static const unsigned short IWICDdsDecoder_FormatStringOffsetTable[] =
    {
    7820,
    7858
    };

static const MIDL_STUBLESS_PROXY_INFO IWICDdsDecoder_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsDecoder_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICDdsDecoder_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsDecoder_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWICDdsDecoderProxyVtbl = 
{
    &IWICDdsDecoder_ProxyInfo,
    &IID_IWICDdsDecoder,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDdsDecoder::GetParameters */ ,
    (void *) (INT_PTR) -1 /* IWICDdsDecoder::GetFrame */
};

const CInterfaceStubVtbl _IWICDdsDecoderStubVtbl =
{
    &IID_IWICDdsDecoder,
    &IWICDdsDecoder_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWICDdsEncoder, ver. 0.0,
   GUID={0x5cacdb4c,0x407e,0x41b3,{0xb9,0x36,0xd0,0xf0,0x10,0xcd,0x67,0x32}} */

#pragma code_seg(".orpc")
static const unsigned short IWICDdsEncoder_FormatStringOffsetTable[] =
    {
    7914,
    7952,
    7990
    };

static const MIDL_STUBLESS_PROXY_INFO IWICDdsEncoder_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICDdsEncoder_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsEncoder_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IWICDdsEncoderProxyVtbl = 
{
    &IWICDdsEncoder_ProxyInfo,
    &IID_IWICDdsEncoder,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDdsEncoder::SetParameters */ ,
    (void *) (INT_PTR) -1 /* IWICDdsEncoder::GetParameters */ ,
    (void *) (INT_PTR) -1 /* IWICDdsEncoder::CreateNewFrame */
};

const CInterfaceStubVtbl _IWICDdsEncoderStubVtbl =
{
    &IID_IWICDdsEncoder,
    &IWICDdsEncoder_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_wincodec_0000_0040, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IWICDdsFrameDecode, ver. 0.0,
   GUID={0x3d4c0c61,0x18a4,0x41e4,{0xbd,0x80,0x48,0x1a,0x4f,0xc9,0xf4,0x64}} */

#pragma code_seg(".orpc")
static const unsigned short IWICDdsFrameDecode_FormatStringOffsetTable[] =
    {
    416,
    8046,
    8084
    };

static const MIDL_STUBLESS_PROXY_INFO IWICDdsFrameDecode_ProxyInfo =
    {
    &Object_StubDesc,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsFrameDecode_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWICDdsFrameDecode_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    wincodec__MIDL_ProcFormatString.Format,
    &IWICDdsFrameDecode_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IWICDdsFrameDecodeProxyVtbl = 
{
    &IWICDdsFrameDecode_ProxyInfo,
    &IID_IWICDdsFrameDecode,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWICDdsFrameDecode::GetSizeInBlocks */ ,
    (void *) (INT_PTR) -1 /* IWICDdsFrameDecode::GetFormatInfo */ ,
    (void *) (INT_PTR) -1 /* IWICDdsFrameDecode::CopyBlocks */
};

const CInterfaceStubVtbl _IWICDdsFrameDecodeStubVtbl =
{
    &IID_IWICDdsFrameDecode,
    &IWICDdsFrameDecode_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    ExprEvalRoutines,
    0,
    wincodec__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _wincodec_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IWICFormatConverterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPixelFormatInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapScalerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICColorContextProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapEncoderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapClipperProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapFrameEncodeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICFastMetadataEncoderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICComponentInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICMetadataQueryWriterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapFrameDecodeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapSourceTransformProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapSourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapLockProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICDdsDecoderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPaletteProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICDevelopRawProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICDdsEncoderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapCodecProgressNotificationProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICColorTransformProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapFlipRotatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICDdsFrameDecodeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICFormatConverterInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICMetadataQueryReaderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICEnumMetadataItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICDevelopRawNotificationCallbackProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICProgressiveLevelControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapDecoderInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPixelFormatInfo2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICImagingFactoryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPlanarBitmapFrameEncodeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapCodecInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPlanarFormatConverterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICProgressCallbackProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICPlanarBitmapSourceTransformProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapDecoderProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWICBitmapEncoderInfoProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _wincodec_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IWICFormatConverterStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPixelFormatInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapScalerStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICColorContextStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapEncoderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapClipperStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapFrameEncodeStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICFastMetadataEncoderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICComponentInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICMetadataQueryWriterStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapFrameDecodeStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapSourceTransformStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapSourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapLockStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICDdsDecoderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPaletteStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICDevelopRawStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICDdsEncoderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapCodecProgressNotificationStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICColorTransformStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapFlipRotatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICDdsFrameDecodeStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICFormatConverterInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICMetadataQueryReaderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICEnumMetadataItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICDevelopRawNotificationCallbackStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICProgressiveLevelControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapDecoderInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPixelFormatInfo2StubVtbl,
    ( CInterfaceStubVtbl *) &_IWICImagingFactoryStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPlanarBitmapFrameEncodeStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapCodecInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPlanarFormatConverterStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICProgressCallbackStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICPlanarBitmapSourceTransformStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapDecoderStubVtbl,
    ( CInterfaceStubVtbl *) &_IWICBitmapEncoderInfoStubVtbl,
    0
};

PCInterfaceName const _wincodec_InterfaceNamesList[] = 
{
    "IWICFormatConverter",
    "IWICPixelFormatInfo",
    "IWICBitmapScaler",
    "IWICColorContext",
    "IWICBitmapEncoder",
    "IWICBitmapClipper",
    "IWICBitmapFrameEncode",
    "IWICFastMetadataEncoder",
    "IWICComponentInfo",
    "IWICMetadataQueryWriter",
    "IWICBitmapFrameDecode",
    "IWICBitmapSourceTransform",
    "IWICBitmapSource",
    "IWICBitmap",
    "IWICBitmapLock",
    "IWICDdsDecoder",
    "IWICPalette",
    "IWICDevelopRaw",
    "IWICDdsEncoder",
    "IWICBitmapCodecProgressNotification",
    "IWICColorTransform",
    "IWICBitmapFlipRotator",
    "IWICStream",
    "IWICDdsFrameDecode",
    "IWICFormatConverterInfo",
    "IWICMetadataQueryReader",
    "IWICEnumMetadataItem",
    "IWICDevelopRawNotificationCallback",
    "IWICProgressiveLevelControl",
    "IWICBitmapDecoderInfo",
    "IWICPixelFormatInfo2",
    "IWICImagingFactory",
    "IWICPlanarBitmapFrameEncode",
    "IWICBitmapCodecInfo",
    "IWICPlanarFormatConverter",
    "IWICProgressCallback",
    "IWICPlanarBitmapSourceTransform",
    "IWICBitmapDecoder",
    "IWICBitmapEncoderInfo",
    0
};

const IID *  const _wincodec_BaseIIDList[] = 
{
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    &IID_IStream,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};


#define _wincodec_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _wincodec, pIID, n)

int __stdcall _wincodec_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _wincodec, 39, 32 )
    IID_BS_LOOKUP_NEXT_TEST( _wincodec, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _wincodec, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _wincodec, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _wincodec, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _wincodec, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _wincodec, 39, *pIndex )
    
}

const ExtendedProxyFileInfo wincodec_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _wincodec_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _wincodec_StubVtblList,
    (const PCInterfaceName * ) & _wincodec_InterfaceNamesList,
    (const IID ** ) & _wincodec_BaseIIDList,
    & _wincodec_IID_Lookup, 
    39,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

