        ��  ��                  �  `   W I N E _ R E G I S T R Y   I E P R O X Y _ P E R H I S T _ R _ R E S                   HKCR
{
    NoRemove Interface
    {
        '{91A565C1-E38F-11D0-94BF-00A0C9055CBF}' = s 'IPersistHistory'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{A4A1A128-768F-41E0-BF75-E4FDDD701CBA}'
        }
    }
    NoRemove CLSID
    {
        '{A4A1A128-768F-41E0-BF75-E4FDDD701CBA}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
