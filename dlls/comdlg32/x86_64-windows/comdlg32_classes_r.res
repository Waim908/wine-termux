        ��  ��                  �  d   W I N E _ R E G I S T R Y   C O M D L G 3 2 _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7}' = s 'File Open Dialog'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{C0B4E2F3-BA21-4773-8DBA-335EC946EB8B}' = s 'File Save Dialog'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
  