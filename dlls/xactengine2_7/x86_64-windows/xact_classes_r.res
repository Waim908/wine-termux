        ��  ��                  �   \   W I N E _ R E G I S T R Y   X A C T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{CD0D66EC-8057-43F5-ACBD-66DFB36FD78C}' = s 'XACTEngine'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  