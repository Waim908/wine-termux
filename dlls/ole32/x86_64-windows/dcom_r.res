        ��  ��                  o  L   W I N E _ R E G I S T R Y   D C O M _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{00000131-0000-0000-C000-000000000046}' = s 'IRemUnknown'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000142-0000-0000-C000-000000000046}' = s 'IRemUnknown2'
        {
            NumMethods = s 7
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
 