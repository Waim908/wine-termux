        ��  ��                  �   \   W I N E _ R E G I S T R Y   X A C T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{BC3E0FC6-2E0D-4C45-BC61-D9C328319BD8}' = s 'XACTEngine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  