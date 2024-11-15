/*** Autogenerated by WIDL 9.21 from qmgr_local.idl - Do not edit ***/

#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
    DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#elif defined(__cplusplus)

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
    EXTERN_C const type DECLSPEC_SELECTANY name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#else

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
    const type DECLSPEC_SELECTANY name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif

#ifdef __cplusplus
extern "C" {
#endif

MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyFile, 0x01b7bd23, 0xfb88, 0x4a77, 0x84,0x90, 0x58,0x91,0xd3,0xe4,0x65,0x3a);
MIDL_DEFINE_GUID(IID, IID_IEnumBackgroundCopyFiles, 0xca51e165, 0xc365, 0x424c, 0x8d,0x41, 0x24,0xaa,0xa4,0xff,0x3c,0x40);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyError, 0x19c613a0, 0xfcb8, 0x4f28, 0x81,0xae, 0x89,0x7c,0x3d,0x07,0x8f,0x81);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJob, 0x37668d37, 0x507e, 0x4160, 0x93,0x16, 0x26,0x30,0x6d,0x15,0x0b,0x12);
MIDL_DEFINE_GUID(IID, IID_IEnumBackgroundCopyJobs, 0x1af4f612, 0x3b71, 0x466f, 0x8f,0x58, 0x7b,0x6f,0x73,0xac,0x57,0xad);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyCallback, 0x97ea99c7, 0x0186, 0x4ad4, 0x8d,0xf9, 0xc5,0xb4,0xe0,0xed,0x6b,0x22);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyManager, 0x5ce34c0d, 0x0dc9, 0x4c1f, 0x89,0x7c, 0xda,0xa1,0xb7,0x8c,0xee,0x7c);
MIDL_DEFINE_GUID(IID, LIBID_BackgroundCopyManager, 0x1deeb74f, 0x7915, 0x4560, 0xb5,0x58, 0x91,0x8c,0x83,0xf1,0x76,0xa6);
MIDL_DEFINE_GUID(CLSID, CLSID_BackgroundCopyManager, 0x4991d34b, 0x80a1, 0x4291, 0x83,0xb6, 0x33,0x28,0x36,0x6b,0x90,0x97);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJob2, 0x54b50739, 0x686f, 0x45eb, 0x9d,0xff, 0xd6,0xa9,0xa0,0xfa,0xa9,0xaf);
MIDL_DEFINE_GUID(IID, LIBID_BackgroundCopyManager1_5, 0xea9319ea, 0xc628, 0x480f, 0x83,0x31, 0x76,0x8f,0xac,0x39,0x7e,0x4e);
MIDL_DEFINE_GUID(CLSID, CLSID_BackgroundCopyManager1_5, 0xf087771f, 0xd74f, 0x4c1a, 0xbb,0x8a, 0xe1,0x6a,0xca,0x91,0x24,0xea);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJob3, 0x443c8934, 0x90ff, 0x48ed, 0xbc,0xde, 0x26,0xf5,0xc7,0x45,0x00,0x42);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyFile2, 0x83e81b93, 0x0873, 0x474d, 0x8a,0x8c, 0xf2,0x01,0x8b,0x1a,0x93,0x9c);
MIDL_DEFINE_GUID(IID, LIBID_BackgroundCopyManager2_0, 0x2289a9af, 0xdc96, 0x486e, 0xb2,0x68, 0x89,0xc9,0xe3,0x39,0x7c,0x3d);
MIDL_DEFINE_GUID(CLSID, CLSID_BackgroundCopyManager2_0, 0x6d18ad12, 0xbde3, 0x4393, 0xb3,0x11, 0x09,0x9c,0x34,0x6e,0x6d,0xf9);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJobHttpOptions, 0xf1bd1079, 0x9f01, 0x4bdc, 0x80,0x36, 0xf0,0x9b,0x70,0x09,0x50,0x66);
MIDL_DEFINE_GUID(IID, LIBID_BackgroundCopyManager2_5, 0x4974177c, 0x3bb6, 0x4c37, 0x9f,0xf0, 0x6b,0x74,0x26,0xf0,0xab,0xa9);
MIDL_DEFINE_GUID(CLSID, CLSID_BackgroundCopyManager2_5, 0x03ca98d6, 0xff5d, 0x49b8, 0xab,0xc6, 0x03,0xdd,0x84,0x12,0x70,0x20);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyCallback2, 0x659cdeac, 0x489e, 0x11d9, 0xa9,0xcd, 0x00,0x0d,0x56,0x96,0x52,0x51);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJob4, 0x659cdeae, 0x489e, 0x11d9, 0xa9,0xcd, 0x00,0x0d,0x56,0x96,0x52,0x51);
MIDL_DEFINE_GUID(IID, LIBID_BackgroundCopyManager3_0, 0x659cdea6, 0x489e, 0x11d9, 0xa9,0xcd, 0x00,0x0d,0x56,0x96,0x52,0x51);
MIDL_DEFINE_GUID(CLSID, CLSID_BackgroundCopyManager3_0, 0x659cdea7, 0x489e, 0x11d9, 0xa9,0xcd, 0x00,0x0d,0x56,0x96,0x52,0x51);
MIDL_DEFINE_GUID(IID, IID_IBackgroundCopyJob5, 0xe847030c, 0xbbba, 0x4657, 0xaf,0x6d, 0x48,0x4a,0xa4,0x2b,0xf1,0xfe);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID
