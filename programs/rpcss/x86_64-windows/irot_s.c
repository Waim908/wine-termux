/*** Autogenerated by WIDL 9.21 from programs/rpcss/irot.idl - Do not edit ***/
#include <string.h>

#include "irot.h"

#define TYPE_FORMAT_STRING_SIZE 177
#define PROC_FORMAT_STRING_SIZE 373

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

static const NDR_RUNDOWN RundownRoutines[] =
{
    IrotContextHandle_rundown
};

/*****************************************************************************
 * Irot interface
 */

static RPC_DISPATCH_TABLE Irot_v0_2_DispatchTable;
static const MIDL_SERVER_INFO Irot_ServerInfo;

static const RPC_SERVER_INTERFACE Irot___RpcServerInterface =
{
    sizeof(RPC_SERVER_INTERFACE),
    {{0x7a98c254,0x6808,0x11cf,{0xb7,0x3b,0x00,0xaa,0x00,0xb6,0x77,0xa8}},{0,2}},
    {{0x8a885d04,0x1ceb,0x11c9,{0x9f,0xe8,0x08,0x00,0x2b,0x10,0x48,0x60}},{2,0}},
    &Irot_v0_2_DispatchTable,
    0,
    0,
    0,
    &Irot_ServerInfo,
    0,
};
RPC_IF_HANDLE Irot_v0_2_s_ifspec = (RPC_IF_HANDLE)& Irot___RpcServerInterface;

static const MIDL_STUB_DESC Irot_StubDesc;

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const unsigned short Irot_FormatStringOffsetTable[] =
{
    0,  /* IrotRegister */
    78,  /* IrotRevoke */
    138,  /* IrotIsRunning */
    180,  /* IrotGetObject */
    234,  /* IrotNoteChangeTime */
    282,  /* IrotGetTimeOfLastChange */
    330,  /* IrotEnumRunning */
};

static const MIDL_STUB_DESC Irot_StubDesc =
{
    (void *)& Irot___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    {
        0,
    },
    RundownRoutines,
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

static RPC_DISPATCH_FUNCTION Irot_table[] =
{
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
};
static RPC_DISPATCH_TABLE Irot_v0_2_DispatchTable =
{
    7,
    Irot_table
};

static const SERVER_ROUTINE Irot_ServerRoutineTable[] =
{
    (void *)IrotRegister,
    (void *)IrotRevoke,
    (void *)IrotIsRunning,
    (void *)IrotGetObject,
    (void *)IrotNoteChangeTime,
    (void *)IrotGetTimeOfLastChange,
    (void *)IrotEnumRunning,
};

static const MIDL_SERVER_INFO Irot_ServerInfo =
{
    &Irot_StubDesc,
    Irot_ServerRoutineTable,
    __MIDL_ProcFormatString.Format,
    Irot_FormatStringOffsetTable,
    0,
    0,
    0,
    0
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
        0x0
    }
};
