        ��  ��                  �   \   W I N E _ R E G I S T R Y   X A C T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{962F5027-99BE-4692-A468-85802CF8DE61}' = s 'XACTEngine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  