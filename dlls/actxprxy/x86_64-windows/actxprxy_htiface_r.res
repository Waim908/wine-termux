        ��  ��                  :  d   W I N E _ R E G I S T R Y   A C T X P R X Y _ H T I F A C E _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{D5F78C80-5252-11CF-90FA-00AA0042106E}' = s 'ITargetFrame'
        {
            NumMethods = s 17
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{9216E421-2BF5-11D0-82B4-00A0C90C29C5}' = s 'ITargetFramePriv'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B2C867E6-69D6-46F2-A611-DED9A4BD7FEF}' = s 'ITargetFramePriv2'
        {
            NumMethods = s 10
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
    }
    NoRemove CLSID
    {
        '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  