        ��  ��                  �   X   W I N E _ R E G I S T R Y   M F A S F S R C S N K _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{41457294-644C-4298-A28A-BD69F2C0CF3B}' = s 'ASF Byte Stream Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 