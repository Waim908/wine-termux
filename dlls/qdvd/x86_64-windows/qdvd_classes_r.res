        ��  ��                  }  \   W I N E _ R E G I S T R Y   Q D V D _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{FCC152B7-F372-11D0-8E00-00C04FD7C08B}' = s 'DVD Graph Builder'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{9B8C4620-2C1A-11D0-8493-00A02438AD48}' = s 'DVD Navigator Filter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   