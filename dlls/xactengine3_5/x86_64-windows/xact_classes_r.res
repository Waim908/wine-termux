        ��  ��                  �   \   W I N E _ R E G I S T R Y   X A C T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{074B110F-7F58-4743-AEA5-12F15B5074ED}' = s 'XACTEngine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  