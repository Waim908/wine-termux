        ��  ��                  8  \   W I N E _ R E G I S T R Y   M L A N G _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{275C23E2-3747-11D0-9FEA-00AA003F8646}' = s 'Multi Language Support'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{C04D65CF-B70D-11D0-B188-00AA0038C969}' = s 'Multi Language String'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{D66D6F99-CDAA-11D0-B822-00C04FC9B31F}' = s 'Multi Language ConvertCharset'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
