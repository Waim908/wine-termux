/*** Autogenerated by WIDL 9.21 from dlls/ieproxy/ieproxy_perhist.idl - Do not edit ***/

#define __midl_proxy
#include "objbase.h"

#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif

#define USE_STUBLESS_PROXY
#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error This code needs a newer version of rpcproxy.h
#endif /* __RPCPROXY_H_VERSION__ */

#include "ieproxy_perhist.h"

#define TYPE_FORMAT_STRING_SIZE 61
#define PROC_FORMAT_STRING_SIZE 159

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

static const MIDL_STUB_DESC Object_StubDesc;

/*****************************************************************************
 * IPersistHistory interface
 */
static const unsigned short IPersistHistory_FormatStringOffsetTable[] =
{
    (unsigned short)-1,  /* IPersist::GetClassID */
    0,  /* IPersistHistory::LoadHistory */
    44,  /* IPersistHistory::SaveHistory */
    82,  /* IPersistHistory::SetPositionCookie */
    120,  /* IPersistHistory::GetPositionCookie */
};

static const MIDL_STUBLESS_PROXY_INFO IPersistHistory_ProxyInfo =
{
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IPersistHistory_FormatStringOffsetTable[-3],
    0,
    0,
    0
};

static CINTERFACE_PROXY_VTABLE(8) _IPersistHistoryProxyVtbl =
{
    {
        &IPersistHistory_ProxyInfo,
        &IID_IPersistHistory,
    },
    {
        IUnknown_QueryInterface_Proxy,
        IUnknown_AddRef_Proxy,
        IUnknown_Release_Proxy,
        0,  /* IPersist::GetClassID */
        (void *)-1,  /* IPersistHistory::LoadHistory */
        (void *)-1,  /* IPersistHistory::SaveHistory */
        (void *)-1,  /* IPersistHistory::SetPositionCookie */
        (void *)-1,  /* IPersistHistory::GetPositionCookie */
    }
};

static const MIDL_SERVER_INFO IPersistHistory_ServerInfo =
{
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IPersistHistory_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
};

static const PRPC_STUB_FUNCTION IPersistHistory_table[] =
{
    STUB_FORWARDING_FUNCTION,
    (PRPC_STUB_FUNCTION)NdrStubCall2,
    (PRPC_STUB_FUNCTION)NdrStubCall2,
    (PRPC_STUB_FUNCTION)NdrStubCall2,
    (PRPC_STUB_FUNCTION)NdrStubCall2
};

static CInterfaceStubVtbl _IPersistHistoryStubVtbl =
{
    {
        &IID_IPersistHistory,
        &IPersistHistory_ServerInfo,
        8,
        &IPersistHistory_table[-3]
    },
    {
        CStdStubBuffer_DELEGATING_METHODS
    }
};

static const MIDL_STUB_DESC Object_StubDesc =
{
    0,
    NdrOleAllocate,
    NdrOleFree,
    {0}, 0, 0, 0, 0,
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

#if !defined(__RPC_WIN64__)
#error Invalid build platform for this proxy.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
{
    0,
    {
/* 0 (procedure IPersistHistory::LoadHistory) */
        0x33,	/* FC_AUTO_HANDLE */
        0x6c,
        NdrFcLong(0x0),
        NdrFcShort(0x4),	/* method 4 */
        NdrFcShort(0x20),	/* stack size = 32 */
        NdrFcShort(0x0),	/* client buffer = 0 */
        NdrFcShort(0x8),	/* server buffer = 8 */
        0x46,
        0x03,	/* 3 params */
        0x0a,
        0x01,
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
        NdrFcShort(0x0),
/* 26 (parameter pStream) */
        NdrFcShort(0xb),	/* flags: must size, must free, in */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0x2),	/* type offset = 2 */
/* 32 (parameter pbc) */
        NdrFcShort(0xb),	/* flags: must size, must free, in */
        NdrFcShort(0x10),	/* stack offset = 16 */
        NdrFcShort(0x14),	/* type offset = 20 */
/* 38 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x18),	/* stack offset = 24 */
        0x08,	/* FC_LONG */
        0x0,
/* 44 (procedure IPersistHistory::SaveHistory) */
        0x33,	/* FC_AUTO_HANDLE */
        0x6c,
        NdrFcLong(0x0),
        NdrFcShort(0x5),	/* method 5 */
        NdrFcShort(0x18),	/* stack size = 24 */
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
/* 70 (parameter pStream) */
        NdrFcShort(0xb),	/* flags: must size, must free, in */
        NdrFcShort(0x8),	/* stack offset = 8 */
        NdrFcShort(0x26),	/* type offset = 38 */
/* 76 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 82 (procedure IPersistHistory::SetPositionCookie) */
        0x33,	/* FC_AUTO_HANDLE */
        0x6c,
        NdrFcLong(0x0),
        NdrFcShort(0x6),	/* method 6 */
        NdrFcShort(0x18),	/* stack size = 24 */
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
/* 108 (parameter dwPositioncookie) */
        NdrFcShort(0x48),	/* flags: in, base type */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x08,	/* FC_LONG */
        0x0,
/* 114 (return value) */
        NdrFcShort(0x70),	/* flags: out, return, base type */
        NdrFcShort(0x10),	/* stack offset = 16 */
        0x08,	/* FC_LONG */
        0x0,
/* 120 (procedure IPersistHistory::GetPositionCookie) */
        0x33,	/* FC_AUTO_HANDLE */
        0x6c,
        NdrFcLong(0x0),
        NdrFcShort(0x7),	/* method 7 */
        NdrFcShort(0x18),	/* stack size = 24 */
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
/* 146 (parameter pdwPositioncookie) */
        NdrFcShort(0x2150),	/* flags: out, base type, simple ref, srv size=8 */
        NdrFcShort(0x8),	/* stack offset = 8 */
        0x09,	/* FC_ULONG */
        0x0,
/* 152 (return value) */
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
/* 2 (IStream *) */
        0x2f,	/* FC_IP */
        0x5a,	/* FC_CONSTANT_IID */
        NdrFcLong(0x0000000c),
        NdrFcShort(0x0000),
        NdrFcShort(0x0000),
        0xc0,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x46,

/* 20 (IBindCtx *) */
        0x2f,	/* FC_IP */
        0x5a,	/* FC_CONSTANT_IID */
        NdrFcLong(0x0000000e),
        NdrFcShort(0x0000),
        NdrFcShort(0x0000),
        0xc0,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x46,

/* 38 (IStream *) */
        0x2f,	/* FC_IP */
        0x5a,	/* FC_CONSTANT_IID */
        NdrFcLong(0x0000000c),
        NdrFcShort(0x0000),
        NdrFcShort(0x0000),
        0xc0,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x46,

/* 56 (DWORD *) */
        0x11, 0x8,	/* FC_RP [simple_pointer] */
        0x09,	/* FC_ULONG */
        0x5c,	/* FC_PAD */
        0x0
    }
};

static const CInterfaceProxyVtbl* const _ieproxy_perhist_ProxyVtblList[] =
{
    (const CInterfaceProxyVtbl*)&_IPersistHistoryProxyVtbl,
    0
};

static const CInterfaceStubVtbl* const _ieproxy_perhist_StubVtblList[] =
{
    &_IPersistHistoryStubVtbl,
    0
};

static PCInterfaceName const _ieproxy_perhist_InterfaceNamesList[] =
{
    "IPersistHistory",
    0
};

static const IID * _ieproxy_perhist_BaseIIDList[] =
{
    &IID_IPersist,  /* IPersistHistory */
    0
};

static int __stdcall _ieproxy_perhist_IID_Lookup(const IID* pIID, int* pIndex)
{
    int low = 0, high = 0;

    while (low <= high)
    {
        int pos = (low + high) / 2;
        int res = IID_GENERIC_CHECK_IID(_ieproxy_perhist, pIID, pos);
        if (!res) { *pIndex = pos; return 1; }
        if (res > 0) low = pos + 1;
        else high = pos - 1;
    }
    return 0;
}

const ExtendedProxyFileInfo ieproxy_perhist_ProxyFileInfo =
{
    (const PCInterfaceProxyVtblList*)_ieproxy_perhist_ProxyVtblList,
    (const PCInterfaceStubVtblList*)_ieproxy_perhist_StubVtblList,
    _ieproxy_perhist_InterfaceNamesList,
    _ieproxy_perhist_BaseIIDList,
    _ieproxy_perhist_IID_Lookup,
    1,
    2,
    0,
    0,
    0,
    0
};
