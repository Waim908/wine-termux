/*** Autogenerated by WIDL 9.21 from test_reg.idl - Do not edit ***/

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

MIDL_DEFINE_GUID(IID, LIBID_register_test, 0xa2cfdbd3, 0x2bbf, 0x4b1c, 0xa4,0x14, 0x5a,0x59,0x04,0xe6,0x34,0xc9);
MIDL_DEFINE_GUID(IID, IID_Inon_ole, 0x06c1f5f0, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Inon_ole_from_disp, 0x06c1f5f1, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Iole, 0x06c1f5f2, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Iole_from_disp, 0x06c1f5f3, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Inon_ole_dual, 0x06c1f5f4, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Iole_dual, 0x06c1f5f5, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Inon_ole_dual_from_disp, 0x06c1f5f6, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_Iole_dual_from_disp, 0x06c1f5f7, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, DIID_Idisp, 0x06c1f5f8, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, DIID_Idisp_from_non_ole_iface, 0x06c1f5f9, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, DIID_Idisp_from_ole_from_disp_iface, 0x06c1f5fa, 0xea49, 0x44f9, 0x8e,0x3b, 0x4b,0xe0,0x0c,0x7a,0x06,0x89);
MIDL_DEFINE_GUID(IID, IID_ICollection, 0xfed318b2, 0xc2ed, 0x11e7, 0xab,0xc4, 0xce,0xc2,0x78,0xb6,0xb5,0x0a);
MIDL_DEFINE_GUID(IID, IID_IInvokeTest, 0xf1b68c3b, 0x02a3, 0x4110, 0xbc,0x4c, 0xcf,0x9b,0xc7,0xe7,0xf1,0x77);

#ifdef __cplusplus
}
#endif

#undef MIDL_DEFINE_GUID
