/*** Autogenerated by WIDL 9.21 from dlls/evr/evr_classes.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __evr_classes_h__
#define __evr_classes_h__

/* Forward declarations */

#ifndef __EnhancedVideoRenderer_FWD_DEFINED__
#define __EnhancedVideoRenderer_FWD_DEFINED__
#ifdef __cplusplus
typedef class EnhancedVideoRenderer EnhancedVideoRenderer;
#else
typedef struct EnhancedVideoRenderer EnhancedVideoRenderer;
#endif /* defined __cplusplus */
#endif /* defined __EnhancedVideoRenderer_FWD_DEFINED__ */

#ifndef __MFVideoMixer9_FWD_DEFINED__
#define __MFVideoMixer9_FWD_DEFINED__
#ifdef __cplusplus
typedef class MFVideoMixer9 MFVideoMixer9;
#else
typedef struct MFVideoMixer9 MFVideoMixer9;
#endif /* defined __cplusplus */
#endif /* defined __MFVideoMixer9_FWD_DEFINED__ */

#ifndef __MFVideoPresenter9_FWD_DEFINED__
#define __MFVideoPresenter9_FWD_DEFINED__
#ifdef __cplusplus
typedef class MFVideoPresenter9 MFVideoPresenter9;
#else
typedef struct MFVideoPresenter9 MFVideoPresenter9;
#endif /* defined __cplusplus */
#endif /* defined __MFVideoPresenter9_FWD_DEFINED__ */

/* Headers for imported files */


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * EnhancedVideoRenderer coclass
 */

DEFINE_GUID(CLSID_EnhancedVideoRenderer, 0xfa10746c, 0x9b63, 0x4b6c, 0xbc,0x49, 0xfc,0x30,0x0e,0xa5,0xf2,0x56);

#ifdef __cplusplus
class DECLSPEC_UUID("fa10746c-9b63-4b6c-bc49-fc300ea5f256") EnhancedVideoRenderer;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(EnhancedVideoRenderer, 0xfa10746c, 0x9b63, 0x4b6c, 0xbc,0x49, 0xfc,0x30,0x0e,0xa5,0xf2,0x56)
#endif
#endif

/*****************************************************************************
 * MFVideoMixer9 coclass
 */

DEFINE_GUID(CLSID_MFVideoMixer9, 0xe474e05a, 0xab65, 0x4f6a, 0x82,0x7c, 0x21,0x8b,0x1b,0xaa,0xf3,0x1f);

#ifdef __cplusplus
class DECLSPEC_UUID("e474e05a-ab65-4f6a-827c-218b1baaf31f") MFVideoMixer9;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(MFVideoMixer9, 0xe474e05a, 0xab65, 0x4f6a, 0x82,0x7c, 0x21,0x8b,0x1b,0xaa,0xf3,0x1f)
#endif
#endif

/*****************************************************************************
 * MFVideoPresenter9 coclass
 */

DEFINE_GUID(CLSID_MFVideoPresenter9, 0x98455561, 0x5136, 0x4d28, 0xab,0x08, 0x4c,0xee,0x40,0xea,0x27,0x81);

#ifdef __cplusplus
class DECLSPEC_UUID("98455561-5136-4d28-ab08-4cee40ea2781") MFVideoPresenter9;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(MFVideoPresenter9, 0x98455561, 0x5136, 0x4d28, 0xab,0x08, 0x4c,0xee,0x40,0xea,0x27,0x81)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __evr_classes_h__ */
