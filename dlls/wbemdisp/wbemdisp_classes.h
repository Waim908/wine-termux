/*** Autogenerated by WIDL 9.21 from dlls/wbemdisp/wbemdisp_classes.idl - Do not edit ***/

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

#ifndef __wbemdisp_classes_h__
#define __wbemdisp_classes_h__

/* Forward declarations */

#ifndef __WinMGMTS_FWD_DEFINED__
#define __WinMGMTS_FWD_DEFINED__
#ifdef __cplusplus
typedef class WinMGMTS WinMGMTS;
#else
typedef struct WinMGMTS WinMGMTS;
#endif /* defined __cplusplus */
#endif /* defined __WinMGMTS_FWD_DEFINED__ */

/* Headers for imported files */


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * WinMGMTS coclass
 */

DEFINE_GUID(CLSID_WinMGMTS, 0x172bddf8, 0xceea, 0x11d1, 0x8b,0x05, 0x00,0x60,0x08,0x06,0xd9,0xb6);

#ifdef __cplusplus
class DECLSPEC_UUID("172bddf8-ceea-11d1-8b05-00600806d9b6") WinMGMTS;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(WinMGMTS, 0x172bddf8, 0xceea, 0x11d1, 0x8b,0x05, 0x00,0x60,0x08,0x06,0xd9,0xb6)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wbemdisp_classes_h__ */