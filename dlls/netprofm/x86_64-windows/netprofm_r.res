        ��  ��                  �   T   W I N E _ R E G I S T R Y   N E T P R O F M _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{DCB00C01-570F-4A9B-8D69-199FDBA5723B}' = s 'NetworkListManager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  