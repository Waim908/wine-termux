        ��  ��                  �  `   W I N E _ R E G I S T R Y   O L E A C C _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{618736E0-3C3D-11CF-810C-00AA00389B71}' = s 'IAccessible'
        {
            NumMethods = s 28
            ProxyStubClsid32 = s '{03022430-ABC4-11D0-BDE2-00AA001A1953}'
        }
        '{03022430-ABC4-11D0-BDE2-00AA001A1953}' = s 'IAccessibleHandler'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{03022430-ABC4-11D0-BDE2-00AA001A1953}'
        }
        '{7852B78D-1CFD-41C1-A615-9C0C85960B5F}' = s 'IAccIdentity'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{03022430-ABC4-11D0-BDE2-00AA001A1953}'
        }
        '{76C0DBBB-15E0-4E7B-B61B-20EEEA2001E0}' = s 'IAccPropServer'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{03022430-ABC4-11D0-BDE2-00AA001A1953}'
        }
        '{6E26E776-04F0-495D-80E4-3330352E3169}' = s 'IAccPropServices'
        {
            NumMethods = s 18
            ProxyStubClsid32 = s '{03022430-ABC4-11D0-BDE2-00AA001A1953}'
        }
    }
    NoRemove CLSID
    {
        '{03022430-ABC4-11D0-BDE2-00AA001A1953}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  