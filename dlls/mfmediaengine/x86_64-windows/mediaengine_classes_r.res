        ��  ��                  �   h   W I N E _ R E G I S T R Y   M E D I A E N G I N E _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{B44392DA-499B-446B-A4CB-005FEAD0E6D5}' = s 'Media Engine Class Factory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  