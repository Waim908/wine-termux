        ��  ��                  K  `   W I N E _ R E G I S T R Y   C O M S V C S _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{ECABAFC6-7F19-11D2-978E-0000F8757E2A}' = s 'New Moniker'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'new'
        }
    }
    'new' = s 'New Moniker'
    {
        CLSID = s '{ECABAFC6-7F19-11D2-978E-0000F8757E2A}'
    }
}
 