        ��  ��                  u  \   W I N E _ R E G I S T R Y   Q A S F _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{94297043-BD82-4DFD-B0DE-8177739C6D20}' = s 'DMOWrapperFilter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{187463A0-5BB7-11D3-ACBE-0080C75E246E}' = s 'WM ASF Reader'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   