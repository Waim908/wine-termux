/*** Autogenerated by WIDL 9.21 from dlls/combase/irpcss.idl - Do not edit ***/
#include <string.h>

#include "irpcss.h"

#define TYPE_FORMAT_STRING_SIZE 243
#define PROC_FORMAT_STRING_SIZE 565

typedef struct _MIDL_TYPE_FORMAT_STRING
{
    short Pad;
    unsigned char Format[TYPE_FORMAT_STRING_SIZE];
} MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
{
    short Pad;
    unsigned char Format[PROC_FORMAT_STRING_SIZE];
} MIDL_PROC_FORMAT_STRING;


static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;

/*****************************************************************************
 * Irot interface
 */

static const RPC_CLIENT_INTERFACE Irot___RpcClientInterface =
{
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x7a98c254,0x6808,0x11cf,{0xb7,0x3b,0x00,0xaa,0x00,0xb6,0x77,0xa8}},{0,2}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0,
};
RPC_IF_HANDLE Irot_v0_2_c_ifspec = (RPC_IF_HANDLE)& Irot___RpcClientInterface;

static const MIDL_STUB_DESC Irot_StubDesc;

static RPC_BINDING_HANDLE Irot__MIDL_AutoBindHandle;

HRESULT __cdecl IrotRegister(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    const InterfaceData *object,
    const InterfaceData *moniker,
    const FILETIME *time,
    DWORD grfFlags,
    IrotCookie *cookie,
    IrotContextHandle *ctxt_handle)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[0],
                              h,
                              moniker_data,
                              object,
                              moniker,
                              time,
                              grfFlags,
                              cookie,
                              ctxt_handle );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotRevoke(
    IrotHandle h,
    IrotCookie cookie,
    IrotContextHandle *ctxt_handle,
    PInterfaceData *object,
    PInterfaceData *moniker)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[78],
                              h,
                              cookie,
                              ctxt_handle,
                              object,
                              moniker );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotIsRunning(
    IrotHandle h,
    const MonikerComparisonData *moniker_data)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[138],
                              h,
                              moniker_data );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotGetObject(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    PInterfaceData *obj,
    IrotCookie *cookie)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[180],
                              h,
                              moniker_data,
                              obj,
                              cookie );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotNoteChangeTime(
    IrotHandle h,
    IrotCookie cookie,
    const FILETIME *time)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[234],
                              h,
                              cookie,
                              time );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotGetTimeOfLastChange(
    IrotHandle h,
    const MonikerComparisonData *moniker_data,
    FILETIME *time)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[282],
                              h,
                              moniker_data,
                              time );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl IrotEnumRunning(
    IrotHandle h,
    PInterfaceList *list)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irot_StubDesc,
                              &__MIDL_ProcFormatString.Format[330],
                              h,
                              list );
    return (HRESULT)_RetVal.Simple;
}

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_STUB_DESC Irot_StubDesc =
{
    (void *)& Irot___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    {
        &Irot__MIDL_AutoBindHandle,
    },
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x50200ca, /* MIDL Version 5.2.202 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
};

/*****************************************************************************
 * ObjectRpcBaseTypes interface
 */

/*****************************************************************************
 * Irpcss interface
 */

static const RPC_CLIENT_INTERFACE Irpcss___RpcClientInterface =
{
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x85da4974,0xedc7,0x40ff,{0xba,0xd4,0x9c,0x45,0x25,0xa8,0xd0,0x44}},{0,0}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0,
};
RPC_IF_HANDLE Irpcss_v0_0_c_ifspec = (RPC_IF_HANDLE)& Irpcss___RpcClientInterface;

static const MIDL_STUB_DESC Irpcss_StubDesc;

static RPC_BINDING_HANDLE Irpcss__MIDL_AutoBindHandle;

HRESULT __cdecl irpcss_server_register(
    handle_t handle,
    const GUID *clsid,
    unsigned int flags,
    PMInterfacePointer object,
    unsigned int *cookie)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irpcss_StubDesc,
                              &__MIDL_ProcFormatString.Format[372],
                              handle,
                              clsid,
                              flags,
                              object,
                              cookie );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl irpcss_server_revoke(
    handle_t handle,
    unsigned int cookie)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irpcss_StubDesc,
                              &__MIDL_ProcFormatString.Format[432],
                              handle,
                              cookie );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl irpcss_get_class_object(
    handle_t handle,
    const GUID *clsid,
    PMInterfacePointer *object)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irpcss_StubDesc,
                              &__MIDL_ProcFormatString.Format[474],
                              handle,
                              clsid,
                              object );
    return (HRESULT)_RetVal.Simple;
}

HRESULT __cdecl irpcss_get_thread_seq_id(
    handle_t handle,
    DWORD *sequence_id)
{
    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2( &Irpcss_StubDesc,
                              &__MIDL_ProcFormatString.Format[522],
                              handle,
                              sequence_id );
    return (HRESULT)_RetVal.Simple;
}

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_STUB_DESC Irpcss_StubDesc =
{
    (void *)& Irpcss___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    {
        &Irpcss__MIDL_AutoBindHandle,
    },
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x50200ca, /* MIDL Version 5.2.202 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
};


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
{
    0,
    {
/* 0 (procedure Irot::IrotRegister) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x0),	/* method 0 */
        NdrFcShort(0x48),	/* stack size = 72 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x14),	/* client buffer = 20 */
        NdrFcShort(0x28),	/* server buffer = 40 */
        0x46,
        0x08,	/* 8 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 30 (parameter moniker_data) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xe),	/* type offset = 14 */
/* 36 (parameter object) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x26),	/* type offset = 38 */
/* 42 (parameter moniker) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x18),	/* stack offset = 24 */
        NdrFcShort(0x26),	/* type offset = 38 */
/* 48 (parameter time) */
        NdrFcShort(0x10a),	/* flags: must free, in, simple ref */
        NdrFcShort(0x20),	/* stack offset = 32 */
        NdrFcShort(0x36),	/* type offset = 54 */
/* 54 (parameter grfFlags) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x28),	/* stack offset = 40 */
        0x08,	/* FC_LONG */
        0x0,
/* 60 (parameter cookie) */
        NdrFcShort(0x2150),	/* flags: out, base type, simple ref, srv size=8 */
        NdrFcShort(0x30),	/* stack offset = 48 */
        0x09,	/* FC_ULONG */
        0x0,
/* 66 (parameter ctxt_handle) */
        NdrFcShort(0x110),	/* flags: out, simple ref */
        NdrFcShort(0x38),	/* stack offset = 56 */
        NdrFcShort(0x4a),	/* type offset = 74 */
/* 72 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x40),	/* stack offset = 64 */
        0x08,	/* FC_LONG */
        0x0,
/* 78 (procedure Irot::IrotRevoke) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x1),	/* method 1 */
        NdrFcShort(0x30),	/* stack size = 48 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x20),	/* client buffer = 32 */
        NdrFcShort(0x20),	/* server buffer = 32 */
        0x45,
        0x05,	/* 5 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 108 (parameter cookie) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x08,	/* FC_LONG */
        0x0,
/* 114 (parameter ctxt_handle) */
        NdrFcShort(0x118),	/* flags: in, out, simple ref */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x52),	/* type offset = 82 */
/* 120 (parameter object) */
        NdrFcShort(0x2013),	/* flags: must size, must free, out, srv size=8 */
        NdrFcShort(0x18),	/* stack offset = 24 */
        NdrFcShort(0x5a),	/* type offset = 90 */
/* 126 (parameter moniker) */
        NdrFcShort(0x2013),	/* flags: must size, must free, out, srv size=8 */
        NdrFcShort(0x20),	/* stack offset = 32 */
        NdrFcShort(0x62),	/* type offset = 98 */
/* 132 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x28),	/* stack offset = 40 */
        0x08,	/* FC_LONG */
        0x0,
/* 138 (procedure Irot::IrotIsRunning) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x2),	/* method 2 */
        NdrFcShort(0x18),	/* stack size = 24 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x46,
        0x02,	/* 2 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 168 (parameter moniker_data) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xe),	/* type offset = 14 */
/* 174 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 180 (procedure Irot::IrotGetObject) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x3),	/* method 3 */
        NdrFcShort(0x28),	/* stack size = 40 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x10),	/* server buffer = 16 */
        0x47,
        0x04,	/* 4 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 210 (parameter moniker_data) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xe),	/* type offset = 14 */
/* 216 (parameter obj) */
        NdrFcShort(0x2013),	/* flags: must size, must free, out, srv size=8 */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x72),	/* type offset = 114 */
/* 222 (parameter cookie) */
        NdrFcShort(0x2150),	/* flags: out, base type, simple ref, srv size=8 */
        NdrFcShort(0x18),	/* stack offset = 24 */
        0x09,	/* FC_ULONG */
        0x0,
/* 228 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x20),	/* stack offset = 32 */
        0x08,	/* FC_LONG */
        0x0,
/* 234 (procedure Irot::IrotNoteChangeTime) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x4),	/* method 4 */
        NdrFcShort(0x20),	/* stack size = 32 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x14),	/* client buffer = 20 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x44,
        0x03,	/* 3 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 264 (parameter cookie) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x08,	/* FC_LONG */
        0x0,
/* 270 (parameter time) */
        NdrFcShort(0x10a),	/* flags: must free, in, simple ref */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x36),	/* type offset = 54 */
/* 276 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x18),	/* stack offset = 24 */
        0x08,	/* FC_LONG */
        0x0,
/* 282 (procedure Irot::IrotGetTimeOfLastChange) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x5),	/* method 5 */
        NdrFcShort(0x20),	/* stack size = 32 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x14),	/* server buffer = 20 */
        0x46,
        0x03,	/* 3 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 312 (parameter moniker_data) */
        NdrFcShort(0x10b),	/* flags: must size, must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xe),	/* type offset = 14 */
/* 318 (parameter time) */
        NdrFcShort(0x2112),	/* flags: must free, out, simple ref, srv size=8 */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x36),	/* type offset = 54 */
/* 324 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x18),	/* stack offset = 24 */
        0x08,	/* FC_LONG */
        0x0,
/* 330 (procedure Irot::IrotEnumRunning) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x6),	/* method 6 */
        NdrFcShort(0x18),	/* stack size = 24 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x45,
        0x02,	/* 2 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 360 (parameter list) */
        NdrFcShort(0x2013),	/* flags: must size, must free, out, srv size=8 */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xac),	/* type offset = 172 */
/* 366 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 372 (procedure Irpcss::irpcss_server_register) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x0),	/* method 0 */
        NdrFcShort(0x30),	/* stack size = 48 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x1c),	/* client buffer = 28 */
        NdrFcShort(0x10),	/* server buffer = 16 */
        0x46,
        0x05,	/* 5 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 402 (parameter clsid) */
        NdrFcShort(0x10a),	/* flags: must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xb6),	/* type offset = 182 */
/* 408 (parameter flags) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 414 (parameter object) */
        NdrFcShort(0xb),	/* flags: must size, must free, in */
        NdrFcShort(0x18),	/* stack offset = 24 */
        NdrFcShort(0xda),	/* type offset = 218 */
/* 420 (parameter cookie) */
        NdrFcShort(0x2150),	/* flags: out, base type, simple ref, srv size=8 */
        NdrFcShort(0x20),	/* stack offset = 32 */
        0x09,	/* FC_ULONG */
        0x0,
/* 426 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x28),	/* stack offset = 40 */
        0x08,	/* FC_LONG */
        0x0,
/* 432 (procedure Irpcss::irpcss_server_revoke) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x1),	/* method 1 */
        NdrFcShort(0x18),	/* stack size = 24 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x8),	/* client buffer = 8 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x44,
        0x02,	/* 2 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 462 (parameter cookie) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x08,	/* FC_LONG */
        0x0,
/* 468 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 474 (procedure Irpcss::irpcss_get_class_object) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x2),	/* method 2 */
        NdrFcShort(0x20),	/* stack size = 32 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x14),	/* client buffer = 20 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x45,
        0x03,	/* 3 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 504 (parameter clsid) */
        NdrFcShort(0x10a),	/* flags: must free, in, simple ref */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0xb6),	/* type offset = 182 */
/* 510 (parameter object) */
        NdrFcShort(0x2013),	/* flags: must size, must free, out, srv size=8 */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0xea),	/* type offset = 234 */
/* 516 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x18),	/* stack offset = 24 */
        0x08,	/* FC_LONG */
        0x0,
/* 522 (procedure Irpcss::irpcss_get_thread_seq_id) */
        0x00,	/* explicit handle */
        0x48,
        NdrFcLong(0x0),
        NdrFcShort(0x3),	/* method 3 */
        NdrFcShort(0x18),	/* stack size = 24 */
        0x32,	/* FC_BIND_PRIMITIVE */
        0x00,
        NdrFcShort(0x0),	/* stack offset = 0 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x10),	/* server buffer = 16 */
        0x44,
        0x02,	/* 2 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 552 (parameter sequence_id) */
        NdrFcShort(0x2150),	/* flags: out, base type, simple ref, srv size=8 */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x09,	/* FC_ULONG */
        0x0,
/* 558 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
        0x0
    }
};

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),
/* 2 (BYTE[]) */
        0x1b,	/* FC_CARRAY */
        0x0,	/* 0 */
        NdrFcShort(0x1),	/* 1 */
        0x9,	/* Corr desc: field ulCntData, FC_ULONG */
        0x0,	/* no operators */
        NdrFcShort(0xfffc),	/* offset = -4 */
        NdrFcShort(0x1),
        0x01,	/* FC_BYTE */
        0x5b,	/* FC_END */
/* 14 (MonikerComparisonData) */
        0x17,	/* FC_CSTRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x4),	/* 4 */
        NdrFcShort(0xfff0),	/* Offset= -16 (2) */
        0x08,	/* FC_LONG */
        0x5b,	/* FC_END */
/* 22 (const MonikerComparisonData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff6),	/* Offset= -10 (14) */
/* 26 (BYTE[]) */
        0x1b,	/* FC_CARRAY */
        0x0,	/* 0 */
        NdrFcShort(0x1),	/* 1 */
        0x9,	/* Corr desc: field ulCntData, FC_ULONG */
        0x0,	/* no operators */
        NdrFcShort(0xfffc),	/* offset = -4 */
        NdrFcShort(0x1),
        0x01,	/* FC_BYTE */
        0x5b,	/* FC_END */
/* 38 (InterfaceData) */
        0x17,	/* FC_CSTRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x4),	/* 4 */
        NdrFcShort(0xfff0),	/* Offset= -16 (26) */
        0x08,	/* FC_LONG */
        0x5b,	/* FC_END */
/* 46 (const InterfaceData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff6),	/* Offset= -10 (38) */
/* 50 (const InterfaceData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff2),	/* Offset= -14 (38) */
/* 54 (FILETIME) */
        0x15,	/* FC_STRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x8),	/* 8 */
        0x08,	/* FC_LONG */
        0x08,	/* FC_LONG */
        0x5c,	/* FC_PAD */
        0x5b,	/* FC_END */
/* 62 (const FILETIME *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff6),	/* Offset= -10 (54) */
/* 66 (IrotCookie *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
/* 70 (IrotContextHandle *) */
        0x11, 0x0,	/* FC_RP */
        NdrFcShort(0x2),	 /* Offset= 2 (74) */
/* 74 */
        0x30,	/* FC_BIND_CONTEXT */
        0xa8,	/* Context flags: strict, out, via ptr, */
        0x0,	/* rundown routine */
        0, /* FIXME: param num */
/* 78 (IrotContextHandle *) */
        0x11, 0x0,	/* FC_RP */
        NdrFcShort(0x2),	 /* Offset= 2 (82) */
/* 82 */
        0x30,	/* FC_BIND_CONTEXT */
        0xe8,	/* Context flags: strict, out, in, via ptr, */
        0x0,	/* rundown routine */
        0, /* FIXME: param num */
/* 86 (PInterfaceData) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xffce),	/* Offset= -50 (38) */
/* 90 (PInterfaceData *) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfffa),	/* Offset= -6 (86) */
/* 94 (PInterfaceData) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xffc6),	/* Offset= -58 (38) */
/* 98 (PInterfaceData *) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfffa),	/* Offset= -6 (94) */
/* 102 (const MonikerComparisonData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffa6),	/* Offset= -90 (14) */
/* 106 (const MonikerComparisonData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffa2),	/* Offset= -94 (14) */
/* 110 (PInterfaceData) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xffb6),	/* Offset= -74 (38) */
/* 114 (PInterfaceData *) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfffa),	/* Offset= -6 (110) */
/* 118 (IrotCookie *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
/* 122 (const FILETIME *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffba),	/* Offset= -70 (54) */
/* 126 (const MonikerComparisonData *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xff8e),	/* Offset= -114 (14) */
/* 130 (FILETIME *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffb2),	/* Offset= -78 (54) */
/* 134 (PInterfaceData[]) */
        0x21,	/* FC_BOGUS_ARRAY */
        0x3,	/* 3 */
        NdrFcShort(0x0),	/* 0 */
        0x9,	/* Corr desc: field size, FC_ULONG */
        0x0,	/* no operators */
        NdrFcShort(0xfff8),	/* offset = -8 */
        NdrFcShort(0x1),
        NdrFcLong(0xffffffff),	/* -1 */
        NdrFcShort(0x0),
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xff8e),	/* Offset= -114 (38) */
        0x5c,	/* FC_PAD */
        0x5b,	/* FC_END */
/* 156 (InterfaceList) */
        0x1a,	/* FC_BOGUS_STRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x8),	/* 8 */
        NdrFcShort(0xffe6),	/* Offset= -26 (134) */
        NdrFcShort(0x0),	/* Offset= 0 (162) */
        0x08,	/* FC_LONG */
        0x40,	/* FC_STRUCTPAD4 */
        0x5c,	/* FC_PAD */
        0x5b,	/* FC_END */
/* 168 (PInterfaceList) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xfff2),	/* Offset= -14 (156) */
/* 172 (PInterfaceList *) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfffa),	/* Offset= -6 (168) */
/* 176 (byte[8]) */
        0x1d,	/* FC_SMFARRAY */
        0x0,	/* 0 */
        NdrFcShort(0x8),	/* 8 */
        0x01,	/* FC_BYTE */
        0x5b,	/* FC_END */
/* 182 (GUID) */
        0x15,	/* FC_STRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x10),	/* 16 */
        0x08,	/* FC_LONG */
        0x06,	/* FC_SHORT */
        0x06,	/* FC_SHORT */
        0x4c,	/* FC_EMBEDDED_COMPLEX */
        0x0,
        NdrFcShort(0xfff1),	/* Offset= -15 (176) */
        0x5b,	/* FC_END */
/* 194 (const GUID *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xfff2),	/* Offset= -14 (182) */
/* 198 (BYTE[]) */
        0x1b,	/* FC_CARRAY */
        0x0,	/* 0 */
        NdrFcShort(0x1),	/* 1 */
        0x9,	/* Corr desc: field ulCntData, FC_ULONG */
        0x0,	/* no operators */
        NdrFcShort(0xfffc),	/* offset = -4 */
        NdrFcShort(0x1),
        0x01,	/* FC_BYTE */
        0x5b,	/* FC_END */
/* 210 (MInterfacePointer) */
        0x17,	/* FC_CSTRUCT */
        0x3,	/* 3 */
        NdrFcShort(0x4),	/* 4 */
        NdrFcShort(0xfff0),	/* Offset= -16 (198) */
        0x08,	/* FC_LONG */
        0x5b,	/* FC_END */
/* 218 (PMInterfacePointer) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xfff6),	/* Offset= -10 (210) */
/* 222 (unsigned int *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
/* 226 (const GUID *) */
        0x11, 0x0,		/* FC_RP */
        NdrFcShort(0xffd2),	/* Offset= -46 (182) */
/* 230 (PMInterfacePointer) */
        0x12, 0x0,		/* FC_UP */
        NdrFcShort(0xffea),	/* Offset= -22 (210) */
/* 234 (PMInterfacePointer *) */
        0x11, 0x14,		/* FC_RP [allocated_on_stack] [pointer_deref] */
        NdrFcShort(0xfffa),	/* Offset= -6 (230) */
/* 238 (DWORD *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
        0x0
    }
};

