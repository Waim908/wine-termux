        ��  ��                  k  \   W I N E _ R E G I S T R Y   M S T A S K _ L O C A L _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{148BD52A-A2AB-11CE-B11F-00AA00530503}' = s 'CTaskScheduler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{148BD520-A2AB-11CE-B11F-00AA00530503}' = s 'CTask'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 