        ��  ��                     l   W I N E _ R E G I S T R Y   I E P R O X Y _ I E A U T O M A T I O N _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{ACC84351-04FF-44F9-B23F-655ED168C6D5}' = s 'IInternetExplorerManager'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{A4A1A128-768F-41E0-BF75-E4FDDD701CBA}'
        }
    }
    NoRemove CLSID
    {
        '{DF4FCC34-067A-4E0A-8352-4A1A5095346E}' = s 'InternetExplorerManager'
        {
        }
        '{A4A1A128-768F-41E0-BF75-E4FDDD701CBA}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
