        ��  ��                  �
  `   W I N E _ R E G I S T R Y   O L E A U T 3 2 _ O A I D L _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{00020400-0000-0000-C000-000000000046}' = s 'IDispatch'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020404-0000-0000-C000-000000000046}' = s 'IEnumVARIANT'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020403-0000-0000-C000-000000000046}' = s 'ITypeComp'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020401-0000-0000-C000-000000000046}' = s 'ITypeInfo'
        {
            NumMethods = s 22
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020412-0000-0000-C000-000000000046}' = s 'ITypeInfo2'
        {
            NumMethods = s 37
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020402-0000-0000-C000-000000000046}' = s 'ITypeLib'
        {
            NumMethods = s 13
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{00020411-0000-0000-C000-000000000046}' = s 'ITypeLib2'
        {
            NumMethods = s 17
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{1CF2B120-547D-101B-8E65-08002B2BD119}' = s 'IErrorInfo'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{22F03340-547D-101B-8E65-08002B2BD119}' = s 'ICreateErrorInfo'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{DF0B3D60-548F-101B-8E65-08002B2BD119}' = s 'ISupportErrorInfo'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{0000002E-0000-0000-C000-000000000046}' = s 'ITypeFactory'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{3127CA40-446E-11CE-8135-00AA004BB851}' = s 'IErrorLog'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
        '{55272A00-42CB-11CE-8135-00AA004BB851}' = s 'IPropertyBag'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{B196B286-BAB4-101A-B69C-00AA00341D07}'
        }
    }
    NoRemove CLSID
    {
        '{B196B286-BAB4-101A-B69C-00AA00341D07}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 