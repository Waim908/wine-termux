        ��  ��                    \   W I N E _ R E G I S T R Y   U R L M O N _ U R L M O N _ R _ R E S                   HKCR
{
    NoRemove Interface
    {
        '{79EAC9C0-BAF9-11CE-8C82-00AA004BA90B}' = s 'IBinding'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9C1-BAF9-11CE-8C82-00AA004BA90B}' = s 'IBindStatusCallback'
        {
            NumMethods = s 11
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{AAA74EF9-8EE7-4659-88D9-F8C504DA73CC}' = s 'IBindStatusCallbackEx'
        {
            NumMethods = s 12
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9D0-BAF9-11CE-8C82-00AA004BA90B}' = s 'IAuthenticate'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{2AD1EDAF-D83D-48B5-9ADF-03DBE19F53BD}' = s 'IAuthenticateEx'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9D2-BAF9-11CE-8C82-00AA004BA90B}' = s 'IHttpNegotiate'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{4F9F9FCB-E0F4-48EB-B7AB-FA2EA9365CB4}' = s 'IHttpNegotiate2'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{FC4801A1-2BA9-11CF-A229-00AA003D7352}' = s 'IBindHost'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9D6-BAFA-11CE-8C82-00AA004BA90B}' = s 'IWinInetInfo'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9D8-BAFA-11CE-8C82-00AA004BA90B}' = s 'IWinInetHttpInfo'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9C9-BAF9-11CE-8C82-00AA004BA90B}' = s 'IPersistMoniker'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{A5CA5F7F-1847-4D87-9C5B-918509F7511D}' = s 'IMonikerProp'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{79EAC9EE-BAF9-11CE-8C82-00AA004BA90B}' = s 'IInternetSecurityManager'
        {
            NumMethods = s 11
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{F164EDF1-CC7C-4F0D-9A94-34222625C393}' = s 'IInternetSecurityManagerEx'
        {
            NumMethods = s 12
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{F1E50292-A795-4117-8E09-2B560A72AC60}' = s 'IInternetSecurityManagerEx2'
        {
            NumMethods = s 16
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
        '{A39EE748-6A27-4817-A6F2-13914BEF5890}' = s 'IUri'
        {
            NumMethods = s 28
            ProxyStubClsid32 = s '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}'
        }
    }
    NoRemove CLSID
    {
        '{79EAC9E0-BAF9-11CE-8C82-00AA004BA90B}' = s 'URL Moniker'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E2-BAF9-11CE-8C82-00AA004BA90B}' = s 'http: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E3-BAF9-11CE-8C82-00AA004BA90B}' = s 'ftp: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E4-BAF9-11CE-8C82-00AA004BA90B}' = s 'gopher: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E5-BAF9-11CE-8C82-00AA004BA90B}' = s 'https: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E6-BAF9-11CE-8C82-00AA004BA90B}' = s 'mk: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9E7-BAF9-11CE-8C82-00AA004BA90B}' = s 'file:, local: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3DD53D40-7B8B-11D0-B013-00AA0059CE02}' = s 'CDL: Asynchronous Pluggable Protocol Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{7B8A2D94-0AC9-11D1-896C-00C04FB6BFC4}' = s 'Security Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{7B8A2D95-0AC9-11D1-896C-00C04FB6BFC4}' = s 'URL Zone Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{79EAC9F1-BAF9-11CE-8C82-00AA004BA90B}' = s 'URLMoniker ProxyStub Factory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{8F6B0360-B80D-11D0-A9B3-006097942311}' = s 'AP lzdhtml encoding/decoding Filter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{DF2FCE13-25EC-45BB-9D4C-CECD47C2430C}' = s 'CUri'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
  