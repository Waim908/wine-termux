/*** Autogenerated by WIDL 9.21 from dlls/uiautomationcore/uia_classes.idl - Do not edit ***/

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

#ifndef __uia_classes_h__
#define __uia_classes_h__

/* Forward declarations */

#ifndef __IWineUiaEventAdviser_FWD_DEFINED__
#define __IWineUiaEventAdviser_FWD_DEFINED__
typedef interface IWineUiaEventAdviser IWineUiaEventAdviser;
#ifdef __cplusplus
interface IWineUiaEventAdviser;
#endif /* __cplusplus */
#endif

#ifndef __IWineUiaEvent_FWD_DEFINED__
#define __IWineUiaEvent_FWD_DEFINED__
typedef interface IWineUiaEvent IWineUiaEvent;
#ifdef __cplusplus
interface IWineUiaEvent;
#endif /* __cplusplus */
#endif

#ifndef __IWineUiaProvider_FWD_DEFINED__
#define __IWineUiaProvider_FWD_DEFINED__
typedef interface IWineUiaProvider IWineUiaProvider;
#ifdef __cplusplus
interface IWineUiaProvider;
#endif /* __cplusplus */
#endif

#ifndef __IWineUiaNode_FWD_DEFINED__
#define __IWineUiaNode_FWD_DEFINED__
typedef interface IWineUiaNode IWineUiaNode;
#ifdef __cplusplus
interface IWineUiaNode;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <oaidl.h>
#include <uiautomationcore.h>

#ifdef __cplusplus
extern "C" {
#endif

struct uia_prop_info {
    const GUID *guid;
    int prop_id;
    int prop_type;
    int type;
    int pattern_id;
};
struct uia_event_info {
    const GUID *guid;
    int event_id;
    int event_arg_type;
};
struct uia_pattern_info {
    const GUID *guid;
    int pattern_id;
    const GUID *pattern_iid;
};
struct uia_control_type_info {
    const GUID *guid;
    int control_type_id;
};
#ifndef __UIA_wine_private_LIBRARY_DEFINED__
#define __UIA_wine_private_LIBRARY_DEFINED__

DEFINE_GUID(LIBID_UIA_wine_private, 0x8a9ca8eb, 0x856b, 0x43d9, 0xab,0xd7, 0x4a,0x59,0x00,0x54,0x06,0x4f);

/*****************************************************************************
 * IWineUiaEventAdviser interface
 */
#ifndef __IWineUiaEventAdviser_INTERFACE_DEFINED__
#define __IWineUiaEventAdviser_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineUiaEventAdviser, 0x9a754e12, 0xe570, 0x49ab, 0xb2,0x23, 0x6f,0x68,0x71,0x00,0x7d,0x28);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("9a754e12-e570-49ab-b223-6f6871007d28")
IWineUiaEventAdviser : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE advise(
        BOOL advise_added,
        LONG_PTR huiaevent) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineUiaEventAdviser, 0x9a754e12, 0xe570, 0x49ab, 0xb2,0x23, 0x6f,0x68,0x71,0x00,0x7d,0x28)
#endif
#else
typedef struct IWineUiaEventAdviserVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineUiaEventAdviser *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineUiaEventAdviser *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineUiaEventAdviser *This);

    /*** IWineUiaEventAdviser methods ***/
    HRESULT (STDMETHODCALLTYPE *advise)(
        IWineUiaEventAdviser *This,
        BOOL advise_added,
        LONG_PTR huiaevent);

    END_INTERFACE
} IWineUiaEventAdviserVtbl;

interface IWineUiaEventAdviser {
    CONST_VTBL IWineUiaEventAdviserVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineUiaEventAdviser_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineUiaEventAdviser_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineUiaEventAdviser_Release(This) (This)->lpVtbl->Release(This)
/*** IWineUiaEventAdviser methods ***/
#define IWineUiaEventAdviser_advise(This,advise_added,huiaevent) (This)->lpVtbl->advise(This,advise_added,huiaevent)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineUiaEventAdviser_QueryInterface(IWineUiaEventAdviser* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineUiaEventAdviser_AddRef(IWineUiaEventAdviser* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineUiaEventAdviser_Release(IWineUiaEventAdviser* This) {
    return This->lpVtbl->Release(This);
}
/*** IWineUiaEventAdviser methods ***/
static inline HRESULT IWineUiaEventAdviser_advise(IWineUiaEventAdviser* This,BOOL advise_added,LONG_PTR huiaevent) {
    return This->lpVtbl->advise(This,advise_added,huiaevent);
}
#endif
#endif

#endif


#endif  /* __IWineUiaEventAdviser_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWineUiaEvent interface
 */
#ifndef __IWineUiaEvent_INTERFACE_DEFINED__
#define __IWineUiaEvent_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineUiaEvent, 0x5e60162c, 0xab0e, 0x4e22, 0xa6,0x1d, 0x3a,0x3a,0xcd,0x44,0x2a,0xba);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("5e60162c-ab0e-4e22-a61d-3a3acd442aba")
IWineUiaEvent : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE advise_events(
        BOOL advise_added,
        LONG adviser_start_idx) = 0;

    virtual HRESULT STDMETHODCALLTYPE set_event_data(
        const GUID *event_guid,
        LONG scope,
        VARIANT runtime_id,
        IWineUiaEvent *event_iface) = 0;

    virtual HRESULT STDMETHODCALLTYPE raise_event(
        VARIANT in_node,
        VARIANT in_nav_start_node) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineUiaEvent, 0x5e60162c, 0xab0e, 0x4e22, 0xa6,0x1d, 0x3a,0x3a,0xcd,0x44,0x2a,0xba)
#endif
#else
typedef struct IWineUiaEventVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineUiaEvent *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineUiaEvent *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineUiaEvent *This);

    /*** IWineUiaEvent methods ***/
    HRESULT (STDMETHODCALLTYPE *advise_events)(
        IWineUiaEvent *This,
        BOOL advise_added,
        LONG adviser_start_idx);

    HRESULT (STDMETHODCALLTYPE *set_event_data)(
        IWineUiaEvent *This,
        const GUID *event_guid,
        LONG scope,
        VARIANT runtime_id,
        IWineUiaEvent *event_iface);

    HRESULT (STDMETHODCALLTYPE *raise_event)(
        IWineUiaEvent *This,
        VARIANT in_node,
        VARIANT in_nav_start_node);

    END_INTERFACE
} IWineUiaEventVtbl;

interface IWineUiaEvent {
    CONST_VTBL IWineUiaEventVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineUiaEvent_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineUiaEvent_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineUiaEvent_Release(This) (This)->lpVtbl->Release(This)
/*** IWineUiaEvent methods ***/
#define IWineUiaEvent_advise_events(This,advise_added,adviser_start_idx) (This)->lpVtbl->advise_events(This,advise_added,adviser_start_idx)
#define IWineUiaEvent_set_event_data(This,event_guid,scope,runtime_id,event_iface) (This)->lpVtbl->set_event_data(This,event_guid,scope,runtime_id,event_iface)
#define IWineUiaEvent_raise_event(This,in_node,in_nav_start_node) (This)->lpVtbl->raise_event(This,in_node,in_nav_start_node)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineUiaEvent_QueryInterface(IWineUiaEvent* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineUiaEvent_AddRef(IWineUiaEvent* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineUiaEvent_Release(IWineUiaEvent* This) {
    return This->lpVtbl->Release(This);
}
/*** IWineUiaEvent methods ***/
static inline HRESULT IWineUiaEvent_advise_events(IWineUiaEvent* This,BOOL advise_added,LONG adviser_start_idx) {
    return This->lpVtbl->advise_events(This,advise_added,adviser_start_idx);
}
static inline HRESULT IWineUiaEvent_set_event_data(IWineUiaEvent* This,const GUID *event_guid,LONG scope,VARIANT runtime_id,IWineUiaEvent *event_iface) {
    return This->lpVtbl->set_event_data(This,event_guid,scope,runtime_id,event_iface);
}
static inline HRESULT IWineUiaEvent_raise_event(IWineUiaEvent* This,VARIANT in_node,VARIANT in_nav_start_node) {
    return This->lpVtbl->raise_event(This,in_node,in_nav_start_node);
}
#endif
#endif

#endif


#endif  /* __IWineUiaEvent_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWineUiaProvider interface
 */
#ifndef __IWineUiaProvider_INTERFACE_DEFINED__
#define __IWineUiaProvider_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineUiaProvider, 0x57865755, 0x6c05, 0x4522, 0x98,0xdf, 0x4c,0xa6,0x58,0xb7,0x68,0xef);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("57865755-6c05-4522-98df-4ca658b768ef")
IWineUiaProvider : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE get_prop_val(
        const struct uia_prop_info *prop_info,
        VARIANT *ret_val) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_prov_opts(
        int *out_opts) = 0;

    virtual HRESULT STDMETHODCALLTYPE has_parent(
        BOOL *out_val) = 0;

    virtual HRESULT STDMETHODCALLTYPE navigate(
        int nav_dir,
        VARIANT *ret_val) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_focus(
        LONG flags,
        VARIANT *ret_val) = 0;

    virtual HRESULT STDMETHODCALLTYPE attach_event(
        LONG_PTR huiaevent) = 0;

    virtual HRESULT STDMETHODCALLTYPE respond_to_win_event(
        DWORD win_event,
        ULONG hwnd,
        LONG obj_id,
        LONG child_id,
        IProxyProviderWinEventSink *sink) = 0;

    virtual HRESULT STDMETHODCALLTYPE create_node_from_prov(
        LONG flags,
        VARIANT *ret_val) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineUiaProvider, 0x57865755, 0x6c05, 0x4522, 0x98,0xdf, 0x4c,0xa6,0x58,0xb7,0x68,0xef)
#endif
#else
typedef struct IWineUiaProviderVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineUiaProvider *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineUiaProvider *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineUiaProvider *This);

    /*** IWineUiaProvider methods ***/
    HRESULT (STDMETHODCALLTYPE *get_prop_val)(
        IWineUiaProvider *This,
        const struct uia_prop_info *prop_info,
        VARIANT *ret_val);

    HRESULT (STDMETHODCALLTYPE *get_prov_opts)(
        IWineUiaProvider *This,
        int *out_opts);

    HRESULT (STDMETHODCALLTYPE *has_parent)(
        IWineUiaProvider *This,
        BOOL *out_val);

    HRESULT (STDMETHODCALLTYPE *navigate)(
        IWineUiaProvider *This,
        int nav_dir,
        VARIANT *ret_val);

    HRESULT (STDMETHODCALLTYPE *get_focus)(
        IWineUiaProvider *This,
        LONG flags,
        VARIANT *ret_val);

    HRESULT (STDMETHODCALLTYPE *attach_event)(
        IWineUiaProvider *This,
        LONG_PTR huiaevent);

    HRESULT (STDMETHODCALLTYPE *respond_to_win_event)(
        IWineUiaProvider *This,
        DWORD win_event,
        ULONG hwnd,
        LONG obj_id,
        LONG child_id,
        IProxyProviderWinEventSink *sink);

    HRESULT (STDMETHODCALLTYPE *create_node_from_prov)(
        IWineUiaProvider *This,
        LONG flags,
        VARIANT *ret_val);

    END_INTERFACE
} IWineUiaProviderVtbl;

interface IWineUiaProvider {
    CONST_VTBL IWineUiaProviderVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineUiaProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineUiaProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineUiaProvider_Release(This) (This)->lpVtbl->Release(This)
/*** IWineUiaProvider methods ***/
#define IWineUiaProvider_get_prop_val(This,prop_info,ret_val) (This)->lpVtbl->get_prop_val(This,prop_info,ret_val)
#define IWineUiaProvider_get_prov_opts(This,out_opts) (This)->lpVtbl->get_prov_opts(This,out_opts)
#define IWineUiaProvider_has_parent(This,out_val) (This)->lpVtbl->has_parent(This,out_val)
#define IWineUiaProvider_navigate(This,nav_dir,ret_val) (This)->lpVtbl->navigate(This,nav_dir,ret_val)
#define IWineUiaProvider_get_focus(This,flags,ret_val) (This)->lpVtbl->get_focus(This,flags,ret_val)
#define IWineUiaProvider_attach_event(This,huiaevent) (This)->lpVtbl->attach_event(This,huiaevent)
#define IWineUiaProvider_respond_to_win_event(This,win_event,hwnd,obj_id,child_id,sink) (This)->lpVtbl->respond_to_win_event(This,win_event,hwnd,obj_id,child_id,sink)
#define IWineUiaProvider_create_node_from_prov(This,flags,ret_val) (This)->lpVtbl->create_node_from_prov(This,flags,ret_val)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineUiaProvider_QueryInterface(IWineUiaProvider* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineUiaProvider_AddRef(IWineUiaProvider* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineUiaProvider_Release(IWineUiaProvider* This) {
    return This->lpVtbl->Release(This);
}
/*** IWineUiaProvider methods ***/
static inline HRESULT IWineUiaProvider_get_prop_val(IWineUiaProvider* This,const struct uia_prop_info *prop_info,VARIANT *ret_val) {
    return This->lpVtbl->get_prop_val(This,prop_info,ret_val);
}
static inline HRESULT IWineUiaProvider_get_prov_opts(IWineUiaProvider* This,int *out_opts) {
    return This->lpVtbl->get_prov_opts(This,out_opts);
}
static inline HRESULT IWineUiaProvider_has_parent(IWineUiaProvider* This,BOOL *out_val) {
    return This->lpVtbl->has_parent(This,out_val);
}
static inline HRESULT IWineUiaProvider_navigate(IWineUiaProvider* This,int nav_dir,VARIANT *ret_val) {
    return This->lpVtbl->navigate(This,nav_dir,ret_val);
}
static inline HRESULT IWineUiaProvider_get_focus(IWineUiaProvider* This,LONG flags,VARIANT *ret_val) {
    return This->lpVtbl->get_focus(This,flags,ret_val);
}
static inline HRESULT IWineUiaProvider_attach_event(IWineUiaProvider* This,LONG_PTR huiaevent) {
    return This->lpVtbl->attach_event(This,huiaevent);
}
static inline HRESULT IWineUiaProvider_respond_to_win_event(IWineUiaProvider* This,DWORD win_event,ULONG hwnd,LONG obj_id,LONG child_id,IProxyProviderWinEventSink *sink) {
    return This->lpVtbl->respond_to_win_event(This,win_event,hwnd,obj_id,child_id,sink);
}
static inline HRESULT IWineUiaProvider_create_node_from_prov(IWineUiaProvider* This,LONG flags,VARIANT *ret_val) {
    return This->lpVtbl->create_node_from_prov(This,flags,ret_val);
}
#endif
#endif

#endif


#endif  /* __IWineUiaProvider_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWineUiaNode interface
 */
#ifndef __IWineUiaNode_INTERFACE_DEFINED__
#define __IWineUiaNode_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineUiaNode, 0xbccb6799, 0xd831, 0x4057, 0xbd,0x50, 0x64,0x25,0x82,0x3f,0xf1,0xa3);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("bccb6799-d831-4057-bd50-6425823ff1a3")
IWineUiaNode : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE get_provider(
        int idx,
        IWineUiaProvider **out_prov) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_prop_val(
        const GUID *prop_guid,
        VARIANT *ret_val) = 0;

    virtual HRESULT STDMETHODCALLTYPE disconnect(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_hwnd(
        ULONG *out_hwnd) = 0;

    virtual HRESULT STDMETHODCALLTYPE attach_event(
        LONG proc_id,
        LONG event_cookie,
        IWineUiaEvent **ret_event) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineUiaNode, 0xbccb6799, 0xd831, 0x4057, 0xbd,0x50, 0x64,0x25,0x82,0x3f,0xf1,0xa3)
#endif
#else
typedef struct IWineUiaNodeVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineUiaNode *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineUiaNode *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineUiaNode *This);

    /*** IWineUiaNode methods ***/
    HRESULT (STDMETHODCALLTYPE *get_provider)(
        IWineUiaNode *This,
        int idx,
        IWineUiaProvider **out_prov);

    HRESULT (STDMETHODCALLTYPE *get_prop_val)(
        IWineUiaNode *This,
        const GUID *prop_guid,
        VARIANT *ret_val);

    HRESULT (STDMETHODCALLTYPE *disconnect)(
        IWineUiaNode *This);

    HRESULT (STDMETHODCALLTYPE *get_hwnd)(
        IWineUiaNode *This,
        ULONG *out_hwnd);

    HRESULT (STDMETHODCALLTYPE *attach_event)(
        IWineUiaNode *This,
        LONG proc_id,
        LONG event_cookie,
        IWineUiaEvent **ret_event);

    END_INTERFACE
} IWineUiaNodeVtbl;

interface IWineUiaNode {
    CONST_VTBL IWineUiaNodeVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineUiaNode_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineUiaNode_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineUiaNode_Release(This) (This)->lpVtbl->Release(This)
/*** IWineUiaNode methods ***/
#define IWineUiaNode_get_provider(This,idx,out_prov) (This)->lpVtbl->get_provider(This,idx,out_prov)
#define IWineUiaNode_get_prop_val(This,prop_guid,ret_val) (This)->lpVtbl->get_prop_val(This,prop_guid,ret_val)
#define IWineUiaNode_disconnect(This) (This)->lpVtbl->disconnect(This)
#define IWineUiaNode_get_hwnd(This,out_hwnd) (This)->lpVtbl->get_hwnd(This,out_hwnd)
#define IWineUiaNode_attach_event(This,proc_id,event_cookie,ret_event) (This)->lpVtbl->attach_event(This,proc_id,event_cookie,ret_event)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineUiaNode_QueryInterface(IWineUiaNode* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineUiaNode_AddRef(IWineUiaNode* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineUiaNode_Release(IWineUiaNode* This) {
    return This->lpVtbl->Release(This);
}
/*** IWineUiaNode methods ***/
static inline HRESULT IWineUiaNode_get_provider(IWineUiaNode* This,int idx,IWineUiaProvider **out_prov) {
    return This->lpVtbl->get_provider(This,idx,out_prov);
}
static inline HRESULT IWineUiaNode_get_prop_val(IWineUiaNode* This,const GUID *prop_guid,VARIANT *ret_val) {
    return This->lpVtbl->get_prop_val(This,prop_guid,ret_val);
}
static inline HRESULT IWineUiaNode_disconnect(IWineUiaNode* This) {
    return This->lpVtbl->disconnect(This);
}
static inline HRESULT IWineUiaNode_get_hwnd(IWineUiaNode* This,ULONG *out_hwnd) {
    return This->lpVtbl->get_hwnd(This,out_hwnd);
}
static inline HRESULT IWineUiaNode_attach_event(IWineUiaNode* This,LONG proc_id,LONG event_cookie,IWineUiaEvent **ret_event) {
    return This->lpVtbl->attach_event(This,proc_id,event_cookie,ret_event);
}
#endif
#endif

#endif


#endif  /* __IWineUiaNode_INTERFACE_DEFINED__ */

#endif /* __UIA_wine_private_LIBRARY_DEFINED__ */
/* Begin additional prototypes for all interfaces */

ULONG           __RPC_USER VARIANT_UserSize     (ULONG *, ULONG, VARIANT *);
unsigned char * __RPC_USER VARIANT_UserMarshal  (ULONG *, unsigned char *, VARIANT *);
unsigned char * __RPC_USER VARIANT_UserUnmarshal(ULONG *, unsigned char *, VARIANT *);
void            __RPC_USER VARIANT_UserFree     (ULONG *, VARIANT *);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __uia_classes_h__ */