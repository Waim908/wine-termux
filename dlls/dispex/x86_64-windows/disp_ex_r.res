        ��  ��                  �  P   W I N E _ R E G I S T R Y   D I S P _ E X _ R _ R E S                   HKCR
{
    NoRemove Interface
    {
        '{A6EF9860-C720-11D0-9337-00A0C90DCAA9}' = s 'IDispatchEx'
        {
            NumMethods = s 15
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
        '{A6EF9861-C720-11D0-9337-00A0C90DCAA9}' = s 'IDispError'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
        '{A6EF9862-C720-11D0-9337-00A0C90DCAA9}' = s 'IVariantChangeType'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
        '{CA04B7E6-0D21-11D1-8CC5-00C04FC2B085}' = s 'IObjectIdentity'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
        '{C5598E60-B307-11D1-B27D-006008C3FBFB}' = s 'ICanHandleException'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
        '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}' = s 'IProvideRuntimeContext'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}'
        }
    }
    NoRemove CLSID
    {
        '{10E2414A-EC59-49D2-BC51-5ADD2C36FEBC}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
