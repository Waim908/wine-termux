        ��  ��                  �   X   W I N E _ R E G I S T R Y   M F _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{48E2ED0F-98C2-4A37-BED5-166312DDD83F}' = s 'MFReadWriteClassFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 