        ��  ��                  �  `   W I N E _ R E G I S T R Y   I N S E N G _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{6E449686-C509-11CF-AAFA-00AA00B6015C}' = s 'Microsoft Active Setup Engine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{BFC880F1-7484-11D0-8309-00AA00B6015C}' = s 'Download Site Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
