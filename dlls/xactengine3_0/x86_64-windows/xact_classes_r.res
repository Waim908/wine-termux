        ��  ��                  �   \   W I N E _ R E G I S T R Y   X A C T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{3B80EE2A-B0F5-4780-9E30-90CB39685B03}' = s 'XACTEngine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  