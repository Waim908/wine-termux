/*** Autogenerated by WIDL 9.21 from dlls/jscript/jsdisp.idl - Do not edit ***/

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

#ifndef __jsdisp_h__
#define __jsdisp_h__

/* Forward declarations */

#ifndef __IWineJSDispatch_FWD_DEFINED__
#define __IWineJSDispatch_FWD_DEFINED__
typedef interface IWineJSDispatch IWineJSDispatch;
#ifdef __cplusplus
interface IWineJSDispatch;
#endif /* __cplusplus */
#endif

#ifndef __IWineJSDispatchHost_FWD_DEFINED__
#define __IWineJSDispatchHost_FWD_DEFINED__
typedef interface IWineJSDispatchHost IWineJSDispatchHost;
#ifdef __cplusplus
interface IWineJSDispatchHost;
#endif /* __cplusplus */
#endif

#ifndef __IWineJScript_FWD_DEFINED__
#define __IWineJScript_FWD_DEFINED__
typedef interface IWineJScript IWineJScript;
#ifdef __cplusplus
interface IWineJScript;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <dispex.h>

#ifdef __cplusplus
extern "C" {
#endif

struct property_info {
    UINT32 id;
    UINT32 flags;
    const WCHAR *name;
    UINT32 index;
    UINT32 iid;
};
#define PROPF_METHOD (0x100)

#define PROPF_CONSTR (0x200)

#define PROPF_ENUMERABLE (0x400)

#define PROPF_WRITABLE (0x800)

#define PROPF_CONFIGURABLE (0x1000)

#define PROPF_PUBLIC_MASK ((PROPF_ENUMERABLE | PROPF_WRITABLE) | PROPF_CONFIGURABLE)

#define HOSTOBJ_CONSTRUCTOR (0x1)

#ifndef __IWineJSDispatchHost_FWD_DEFINED__
#define __IWineJSDispatchHost_FWD_DEFINED__
typedef interface IWineJSDispatchHost IWineJSDispatchHost;
#ifdef __cplusplus
interface IWineJSDispatchHost;
#endif /* __cplusplus */
#endif

/*****************************************************************************
 * IWineJSDispatch interface
 */
#ifndef __IWineJSDispatch_INTERFACE_DEFINED__
#define __IWineJSDispatch_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineJSDispatch, 0xd359f2fe, 0x5531, 0x741b, 0xa4,0x1a, 0x5c,0xf9,0x2e,0xdc,0x97,0x1c);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("d359f2fe-5531-741b-a41a-5cf92edc971c")
IWineJSDispatch : public IDispatchEx
{
    virtual void STDMETHODCALLTYPE Free(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetScriptGlobal(
        IWineJSDispatchHost **ret) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineJSDispatch, 0xd359f2fe, 0x5531, 0x741b, 0xa4,0x1a, 0x5c,0xf9,0x2e,0xdc,0x97,0x1c)
#endif
#else
typedef struct IWineJSDispatchVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineJSDispatch *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineJSDispatch *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineJSDispatch *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IWineJSDispatch *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IWineJSDispatch *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IWineJSDispatch *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IWineJSDispatch *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IDispatchEx methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDispID)(
        IWineJSDispatch *This,
        BSTR bstrName,
        DWORD grfdex,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *InvokeEx)(
        IWineJSDispatch *This,
        DISPID id,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pdp,
        VARIANT *pvarRes,
        EXCEPINFO *pei,
        IServiceProvider *pspCaller);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByName)(
        IWineJSDispatch *This,
        BSTR bstrName,
        DWORD grfdex);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByDispID)(
        IWineJSDispatch *This,
        DISPID id);

    HRESULT (STDMETHODCALLTYPE *GetMemberProperties)(
        IWineJSDispatch *This,
        DISPID id,
        DWORD grfdexFetch,
        DWORD *pgrfdex);

    HRESULT (STDMETHODCALLTYPE *GetMemberName)(
        IWineJSDispatch *This,
        DISPID id,
        BSTR *pbstrName);

    HRESULT (STDMETHODCALLTYPE *GetNextDispID)(
        IWineJSDispatch *This,
        DWORD grfdex,
        DISPID id,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *GetNameSpaceParent)(
        IWineJSDispatch *This,
        IUnknown **ppunk);

    /*** IWineJSDispatch methods ***/
    void (STDMETHODCALLTYPE *Free)(
        IWineJSDispatch *This);

    HRESULT (STDMETHODCALLTYPE *GetScriptGlobal)(
        IWineJSDispatch *This,
        IWineJSDispatchHost **ret);

    END_INTERFACE
} IWineJSDispatchVtbl;

interface IWineJSDispatch {
    CONST_VTBL IWineJSDispatchVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineJSDispatch_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineJSDispatch_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineJSDispatch_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IWineJSDispatch_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWineJSDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWineJSDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWineJSDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IDispatchEx methods ***/
#define IWineJSDispatch_GetDispID(This,bstrName,grfdex,pid) (This)->lpVtbl->GetDispID(This,bstrName,grfdex,pid)
#define IWineJSDispatch_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller) (This)->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)
#define IWineJSDispatch_DeleteMemberByName(This,bstrName,grfdex) (This)->lpVtbl->DeleteMemberByName(This,bstrName,grfdex)
#define IWineJSDispatch_DeleteMemberByDispID(This,id) (This)->lpVtbl->DeleteMemberByDispID(This,id)
#define IWineJSDispatch_GetMemberProperties(This,id,grfdexFetch,pgrfdex) (This)->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex)
#define IWineJSDispatch_GetMemberName(This,id,pbstrName) (This)->lpVtbl->GetMemberName(This,id,pbstrName)
#define IWineJSDispatch_GetNextDispID(This,grfdex,id,pid) (This)->lpVtbl->GetNextDispID(This,grfdex,id,pid)
#define IWineJSDispatch_GetNameSpaceParent(This,ppunk) (This)->lpVtbl->GetNameSpaceParent(This,ppunk)
/*** IWineJSDispatch methods ***/
#define IWineJSDispatch_Free(This) (This)->lpVtbl->Free(This)
#define IWineJSDispatch_GetScriptGlobal(This,ret) (This)->lpVtbl->GetScriptGlobal(This,ret)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineJSDispatch_QueryInterface(IWineJSDispatch* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineJSDispatch_AddRef(IWineJSDispatch* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineJSDispatch_Release(IWineJSDispatch* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static inline HRESULT IWineJSDispatch_GetTypeInfoCount(IWineJSDispatch* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static inline HRESULT IWineJSDispatch_GetTypeInfo(IWineJSDispatch* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static inline HRESULT IWineJSDispatch_GetIDsOfNames(IWineJSDispatch* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static inline HRESULT IWineJSDispatch_Invoke(IWineJSDispatch* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IDispatchEx methods ***/
static inline HRESULT IWineJSDispatch_GetDispID(IWineJSDispatch* This,BSTR bstrName,DWORD grfdex,DISPID *pid) {
    return This->lpVtbl->GetDispID(This,bstrName,grfdex,pid);
}
static inline HRESULT IWineJSDispatch_InvokeEx(IWineJSDispatch* This,DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller) {
    return This->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller);
}
static inline HRESULT IWineJSDispatch_DeleteMemberByName(IWineJSDispatch* This,BSTR bstrName,DWORD grfdex) {
    return This->lpVtbl->DeleteMemberByName(This,bstrName,grfdex);
}
static inline HRESULT IWineJSDispatch_DeleteMemberByDispID(IWineJSDispatch* This,DISPID id) {
    return This->lpVtbl->DeleteMemberByDispID(This,id);
}
static inline HRESULT IWineJSDispatch_GetMemberProperties(IWineJSDispatch* This,DISPID id,DWORD grfdexFetch,DWORD *pgrfdex) {
    return This->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex);
}
static inline HRESULT IWineJSDispatch_GetMemberName(IWineJSDispatch* This,DISPID id,BSTR *pbstrName) {
    return This->lpVtbl->GetMemberName(This,id,pbstrName);
}
static inline HRESULT IWineJSDispatch_GetNextDispID(IWineJSDispatch* This,DWORD grfdex,DISPID id,DISPID *pid) {
    return This->lpVtbl->GetNextDispID(This,grfdex,id,pid);
}
static inline HRESULT IWineJSDispatch_GetNameSpaceParent(IWineJSDispatch* This,IUnknown **ppunk) {
    return This->lpVtbl->GetNameSpaceParent(This,ppunk);
}
/*** IWineJSDispatch methods ***/
static inline void IWineJSDispatch_Free(IWineJSDispatch* This) {
    This->lpVtbl->Free(This);
}
static inline HRESULT IWineJSDispatch_GetScriptGlobal(IWineJSDispatch* This,IWineJSDispatchHost **ret) {
    return This->lpVtbl->GetScriptGlobal(This,ret);
}
#endif
#endif

#endif


#endif  /* __IWineJSDispatch_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWineJSDispatchHost interface
 */
#ifndef __IWineJSDispatchHost_INTERFACE_DEFINED__
#define __IWineJSDispatchHost_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineJSDispatchHost, 0xb1ebc544, 0x6644, 0x40c6, 0x97,0xf6, 0xcc,0xd9,0xcc,0x32,0xbf,0xba);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("b1ebc544-6644-40c6-97f6-ccd9cc32bfba")
IWineJSDispatchHost : public IDispatchEx
{
    virtual HRESULT STDMETHODCALLTYPE GetJSDispatch(
        IWineJSDispatch **ret) = 0;

    virtual HRESULT STDMETHODCALLTYPE LookupProperty(
        const WCHAR *name,
        DWORD flags,
        struct property_info *desc) = 0;

    virtual HRESULT STDMETHODCALLTYPE NextProperty(
        DISPID id,
        struct property_info *desc) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetProperty(
        DISPID id,
        LCID lcid,
        VARIANT *r,
        EXCEPINFO *ei,
        IServiceProvider *caller) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProperty(
        DISPID id,
        LCID lcid,
        VARIANT *v,
        EXCEPINFO *ei,
        IServiceProvider *caller) = 0;

    virtual HRESULT STDMETHODCALLTYPE DeleteProperty(
        DISPID id) = 0;

    virtual HRESULT STDMETHODCALLTYPE ConfigureProperty(
        DISPID id,
        UINT32 flags) = 0;

    virtual HRESULT STDMETHODCALLTYPE CallFunction(
        DISPID id,
        UINT32 iid,
        DWORD flags,
        DISPPARAMS *dp,
        VARIANT *ret,
        EXCEPINFO *ei,
        IServiceProvider *caller) = 0;

    virtual HRESULT STDMETHODCALLTYPE Construct(
        LCID lcid,
        DWORD flags,
        DISPPARAMS *dp,
        VARIANT *ret,
        EXCEPINFO *ei,
        IServiceProvider *caller) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetOuterDispatch(
        IWineJSDispatchHost **ret) = 0;

    virtual HRESULT STDMETHODCALLTYPE ToString(
        BSTR *str) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineJSDispatchHost, 0xb1ebc544, 0x6644, 0x40c6, 0x97,0xf6, 0xcc,0xd9,0xcc,0x32,0xbf,0xba)
#endif
#else
typedef struct IWineJSDispatchHostVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineJSDispatchHost *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineJSDispatchHost *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineJSDispatchHost *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        IWineJSDispatchHost *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        IWineJSDispatchHost *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        IWineJSDispatchHost *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        IWineJSDispatchHost *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** IDispatchEx methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDispID)(
        IWineJSDispatchHost *This,
        BSTR bstrName,
        DWORD grfdex,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *InvokeEx)(
        IWineJSDispatchHost *This,
        DISPID id,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pdp,
        VARIANT *pvarRes,
        EXCEPINFO *pei,
        IServiceProvider *pspCaller);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByName)(
        IWineJSDispatchHost *This,
        BSTR bstrName,
        DWORD grfdex);

    HRESULT (STDMETHODCALLTYPE *DeleteMemberByDispID)(
        IWineJSDispatchHost *This,
        DISPID id);

    HRESULT (STDMETHODCALLTYPE *GetMemberProperties)(
        IWineJSDispatchHost *This,
        DISPID id,
        DWORD grfdexFetch,
        DWORD *pgrfdex);

    HRESULT (STDMETHODCALLTYPE *GetMemberName)(
        IWineJSDispatchHost *This,
        DISPID id,
        BSTR *pbstrName);

    HRESULT (STDMETHODCALLTYPE *GetNextDispID)(
        IWineJSDispatchHost *This,
        DWORD grfdex,
        DISPID id,
        DISPID *pid);

    HRESULT (STDMETHODCALLTYPE *GetNameSpaceParent)(
        IWineJSDispatchHost *This,
        IUnknown **ppunk);

    /*** IWineJSDispatchHost methods ***/
    HRESULT (STDMETHODCALLTYPE *GetJSDispatch)(
        IWineJSDispatchHost *This,
        IWineJSDispatch **ret);

    HRESULT (STDMETHODCALLTYPE *LookupProperty)(
        IWineJSDispatchHost *This,
        const WCHAR *name,
        DWORD flags,
        struct property_info *desc);

    HRESULT (STDMETHODCALLTYPE *NextProperty)(
        IWineJSDispatchHost *This,
        DISPID id,
        struct property_info *desc);

    HRESULT (STDMETHODCALLTYPE *GetProperty)(
        IWineJSDispatchHost *This,
        DISPID id,
        LCID lcid,
        VARIANT *r,
        EXCEPINFO *ei,
        IServiceProvider *caller);

    HRESULT (STDMETHODCALLTYPE *SetProperty)(
        IWineJSDispatchHost *This,
        DISPID id,
        LCID lcid,
        VARIANT *v,
        EXCEPINFO *ei,
        IServiceProvider *caller);

    HRESULT (STDMETHODCALLTYPE *DeleteProperty)(
        IWineJSDispatchHost *This,
        DISPID id);

    HRESULT (STDMETHODCALLTYPE *ConfigureProperty)(
        IWineJSDispatchHost *This,
        DISPID id,
        UINT32 flags);

    HRESULT (STDMETHODCALLTYPE *CallFunction)(
        IWineJSDispatchHost *This,
        DISPID id,
        UINT32 iid,
        DWORD flags,
        DISPPARAMS *dp,
        VARIANT *ret,
        EXCEPINFO *ei,
        IServiceProvider *caller);

    HRESULT (STDMETHODCALLTYPE *Construct)(
        IWineJSDispatchHost *This,
        LCID lcid,
        DWORD flags,
        DISPPARAMS *dp,
        VARIANT *ret,
        EXCEPINFO *ei,
        IServiceProvider *caller);

    HRESULT (STDMETHODCALLTYPE *GetOuterDispatch)(
        IWineJSDispatchHost *This,
        IWineJSDispatchHost **ret);

    HRESULT (STDMETHODCALLTYPE *ToString)(
        IWineJSDispatchHost *This,
        BSTR *str);

    END_INTERFACE
} IWineJSDispatchHostVtbl;

interface IWineJSDispatchHost {
    CONST_VTBL IWineJSDispatchHostVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineJSDispatchHost_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineJSDispatchHost_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineJSDispatchHost_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define IWineJSDispatchHost_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWineJSDispatchHost_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWineJSDispatchHost_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWineJSDispatchHost_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** IDispatchEx methods ***/
#define IWineJSDispatchHost_GetDispID(This,bstrName,grfdex,pid) (This)->lpVtbl->GetDispID(This,bstrName,grfdex,pid)
#define IWineJSDispatchHost_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller) (This)->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)
#define IWineJSDispatchHost_DeleteMemberByName(This,bstrName,grfdex) (This)->lpVtbl->DeleteMemberByName(This,bstrName,grfdex)
#define IWineJSDispatchHost_DeleteMemberByDispID(This,id) (This)->lpVtbl->DeleteMemberByDispID(This,id)
#define IWineJSDispatchHost_GetMemberProperties(This,id,grfdexFetch,pgrfdex) (This)->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex)
#define IWineJSDispatchHost_GetMemberName(This,id,pbstrName) (This)->lpVtbl->GetMemberName(This,id,pbstrName)
#define IWineJSDispatchHost_GetNextDispID(This,grfdex,id,pid) (This)->lpVtbl->GetNextDispID(This,grfdex,id,pid)
#define IWineJSDispatchHost_GetNameSpaceParent(This,ppunk) (This)->lpVtbl->GetNameSpaceParent(This,ppunk)
/*** IWineJSDispatchHost methods ***/
#define IWineJSDispatchHost_GetJSDispatch(This,ret) (This)->lpVtbl->GetJSDispatch(This,ret)
#define IWineJSDispatchHost_LookupProperty(This,name,flags,desc) (This)->lpVtbl->LookupProperty(This,name,flags,desc)
#define IWineJSDispatchHost_NextProperty(This,id,desc) (This)->lpVtbl->NextProperty(This,id,desc)
#define IWineJSDispatchHost_GetProperty(This,id,lcid,r,ei,caller) (This)->lpVtbl->GetProperty(This,id,lcid,r,ei,caller)
#define IWineJSDispatchHost_SetProperty(This,id,lcid,v,ei,caller) (This)->lpVtbl->SetProperty(This,id,lcid,v,ei,caller)
#define IWineJSDispatchHost_DeleteProperty(This,id) (This)->lpVtbl->DeleteProperty(This,id)
#define IWineJSDispatchHost_ConfigureProperty(This,id,flags) (This)->lpVtbl->ConfigureProperty(This,id,flags)
#define IWineJSDispatchHost_CallFunction(This,id,iid,flags,dp,ret,ei,caller) (This)->lpVtbl->CallFunction(This,id,iid,flags,dp,ret,ei,caller)
#define IWineJSDispatchHost_Construct(This,lcid,flags,dp,ret,ei,caller) (This)->lpVtbl->Construct(This,lcid,flags,dp,ret,ei,caller)
#define IWineJSDispatchHost_GetOuterDispatch(This,ret) (This)->lpVtbl->GetOuterDispatch(This,ret)
#define IWineJSDispatchHost_ToString(This,str) (This)->lpVtbl->ToString(This,str)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineJSDispatchHost_QueryInterface(IWineJSDispatchHost* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineJSDispatchHost_AddRef(IWineJSDispatchHost* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineJSDispatchHost_Release(IWineJSDispatchHost* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static inline HRESULT IWineJSDispatchHost_GetTypeInfoCount(IWineJSDispatchHost* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static inline HRESULT IWineJSDispatchHost_GetTypeInfo(IWineJSDispatchHost* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static inline HRESULT IWineJSDispatchHost_GetIDsOfNames(IWineJSDispatchHost* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static inline HRESULT IWineJSDispatchHost_Invoke(IWineJSDispatchHost* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** IDispatchEx methods ***/
static inline HRESULT IWineJSDispatchHost_GetDispID(IWineJSDispatchHost* This,BSTR bstrName,DWORD grfdex,DISPID *pid) {
    return This->lpVtbl->GetDispID(This,bstrName,grfdex,pid);
}
static inline HRESULT IWineJSDispatchHost_InvokeEx(IWineJSDispatchHost* This,DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller) {
    return This->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller);
}
static inline HRESULT IWineJSDispatchHost_DeleteMemberByName(IWineJSDispatchHost* This,BSTR bstrName,DWORD grfdex) {
    return This->lpVtbl->DeleteMemberByName(This,bstrName,grfdex);
}
static inline HRESULT IWineJSDispatchHost_DeleteMemberByDispID(IWineJSDispatchHost* This,DISPID id) {
    return This->lpVtbl->DeleteMemberByDispID(This,id);
}
static inline HRESULT IWineJSDispatchHost_GetMemberProperties(IWineJSDispatchHost* This,DISPID id,DWORD grfdexFetch,DWORD *pgrfdex) {
    return This->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex);
}
static inline HRESULT IWineJSDispatchHost_GetMemberName(IWineJSDispatchHost* This,DISPID id,BSTR *pbstrName) {
    return This->lpVtbl->GetMemberName(This,id,pbstrName);
}
static inline HRESULT IWineJSDispatchHost_GetNextDispID(IWineJSDispatchHost* This,DWORD grfdex,DISPID id,DISPID *pid) {
    return This->lpVtbl->GetNextDispID(This,grfdex,id,pid);
}
static inline HRESULT IWineJSDispatchHost_GetNameSpaceParent(IWineJSDispatchHost* This,IUnknown **ppunk) {
    return This->lpVtbl->GetNameSpaceParent(This,ppunk);
}
/*** IWineJSDispatchHost methods ***/
static inline HRESULT IWineJSDispatchHost_GetJSDispatch(IWineJSDispatchHost* This,IWineJSDispatch **ret) {
    return This->lpVtbl->GetJSDispatch(This,ret);
}
static inline HRESULT IWineJSDispatchHost_LookupProperty(IWineJSDispatchHost* This,const WCHAR *name,DWORD flags,struct property_info *desc) {
    return This->lpVtbl->LookupProperty(This,name,flags,desc);
}
static inline HRESULT IWineJSDispatchHost_NextProperty(IWineJSDispatchHost* This,DISPID id,struct property_info *desc) {
    return This->lpVtbl->NextProperty(This,id,desc);
}
static inline HRESULT IWineJSDispatchHost_GetProperty(IWineJSDispatchHost* This,DISPID id,LCID lcid,VARIANT *r,EXCEPINFO *ei,IServiceProvider *caller) {
    return This->lpVtbl->GetProperty(This,id,lcid,r,ei,caller);
}
static inline HRESULT IWineJSDispatchHost_SetProperty(IWineJSDispatchHost* This,DISPID id,LCID lcid,VARIANT *v,EXCEPINFO *ei,IServiceProvider *caller) {
    return This->lpVtbl->SetProperty(This,id,lcid,v,ei,caller);
}
static inline HRESULT IWineJSDispatchHost_DeleteProperty(IWineJSDispatchHost* This,DISPID id) {
    return This->lpVtbl->DeleteProperty(This,id);
}
static inline HRESULT IWineJSDispatchHost_ConfigureProperty(IWineJSDispatchHost* This,DISPID id,UINT32 flags) {
    return This->lpVtbl->ConfigureProperty(This,id,flags);
}
static inline HRESULT IWineJSDispatchHost_CallFunction(IWineJSDispatchHost* This,DISPID id,UINT32 iid,DWORD flags,DISPPARAMS *dp,VARIANT *ret,EXCEPINFO *ei,IServiceProvider *caller) {
    return This->lpVtbl->CallFunction(This,id,iid,flags,dp,ret,ei,caller);
}
static inline HRESULT IWineJSDispatchHost_Construct(IWineJSDispatchHost* This,LCID lcid,DWORD flags,DISPPARAMS *dp,VARIANT *ret,EXCEPINFO *ei,IServiceProvider *caller) {
    return This->lpVtbl->Construct(This,lcid,flags,dp,ret,ei,caller);
}
static inline HRESULT IWineJSDispatchHost_GetOuterDispatch(IWineJSDispatchHost* This,IWineJSDispatchHost **ret) {
    return This->lpVtbl->GetOuterDispatch(This,ret);
}
static inline HRESULT IWineJSDispatchHost_ToString(IWineJSDispatchHost* This,BSTR *str) {
    return This->lpVtbl->ToString(This,str);
}
#endif
#endif

#endif


#endif  /* __IWineJSDispatchHost_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWineJScript interface
 */
#ifndef __IWineJScript_INTERFACE_DEFINED__
#define __IWineJScript_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWineJScript, 0xd359f2fe, 0x5531, 0x741b, 0xa4,0x1a, 0x5c,0xf9,0x2e,0xdc,0x97,0x1d);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("d359f2fe-5531-741b-a41a-5cf92edc971d")
IWineJScript : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE InitHostObject(
        IWineJSDispatchHost *host_obj,
        IWineJSDispatch *prototype,
        UINT32 flags,
        IWineJSDispatch **ret) = 0;

    virtual HRESULT STDMETHODCALLTYPE InitHostConstructor(
        IWineJSDispatchHost *constr,
        IWineJSDispatch *prototype,
        IWineJSDispatch **ret) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWineJScript, 0xd359f2fe, 0x5531, 0x741b, 0xa4,0x1a, 0x5c,0xf9,0x2e,0xdc,0x97,0x1d)
#endif
#else
typedef struct IWineJScriptVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWineJScript *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWineJScript *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWineJScript *This);

    /*** IWineJScript methods ***/
    HRESULT (STDMETHODCALLTYPE *InitHostObject)(
        IWineJScript *This,
        IWineJSDispatchHost *host_obj,
        IWineJSDispatch *prototype,
        UINT32 flags,
        IWineJSDispatch **ret);

    HRESULT (STDMETHODCALLTYPE *InitHostConstructor)(
        IWineJScript *This,
        IWineJSDispatchHost *constr,
        IWineJSDispatch *prototype,
        IWineJSDispatch **ret);

    END_INTERFACE
} IWineJScriptVtbl;

interface IWineJScript {
    CONST_VTBL IWineJScriptVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IWineJScript_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWineJScript_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWineJScript_Release(This) (This)->lpVtbl->Release(This)
/*** IWineJScript methods ***/
#define IWineJScript_InitHostObject(This,host_obj,prototype,flags,ret) (This)->lpVtbl->InitHostObject(This,host_obj,prototype,flags,ret)
#define IWineJScript_InitHostConstructor(This,constr,prototype,ret) (This)->lpVtbl->InitHostConstructor(This,constr,prototype,ret)
#else
/*** IUnknown methods ***/
static inline HRESULT IWineJScript_QueryInterface(IWineJScript* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IWineJScript_AddRef(IWineJScript* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IWineJScript_Release(IWineJScript* This) {
    return This->lpVtbl->Release(This);
}
/*** IWineJScript methods ***/
static inline HRESULT IWineJScript_InitHostObject(IWineJScript* This,IWineJSDispatchHost *host_obj,IWineJSDispatch *prototype,UINT32 flags,IWineJSDispatch **ret) {
    return This->lpVtbl->InitHostObject(This,host_obj,prototype,flags,ret);
}
static inline HRESULT IWineJScript_InitHostConstructor(IWineJScript* This,IWineJSDispatchHost *constr,IWineJSDispatch *prototype,IWineJSDispatch **ret) {
    return This->lpVtbl->InitHostConstructor(This,constr,prototype,ret);
}
#endif
#endif

#endif


#endif  /* __IWineJScript_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __jsdisp_h__ */