        ��  ��                  �  d   W I N E _ R E G I S T R Y   A C T X P R X Y _ S H L D I S P _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{3D8B0590-F691-11D2-8EA9-006097DF5BD4}' = s 'IAsyncOperation'
        {
            NumMethods = s 8
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
