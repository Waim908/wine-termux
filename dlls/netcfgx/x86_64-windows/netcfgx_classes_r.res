        ��  ��                  �   `   W I N E _ R E G I S T R Y   N E T C F G X _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{5B035261-40F9-11D1-AAEC-00805FC1270E}' = s 'Network Configuration Component Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  