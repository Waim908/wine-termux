        ��  ��                  �  \   W I N E _ R E G I S T R Y   O L E 3 2 _ U N K N W N _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{00000000-0000-0000-C000-000000000046}' = s 'IUnknown'
        '{00000001-0000-0000-C000-000000000046}' = s 'IClassFactory'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
    }
    NoRemove CLSID
    {
        '{00000320-0000-0000-C000-000000000046}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  