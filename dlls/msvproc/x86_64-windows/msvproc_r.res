        ��  ��                  �   P   W I N E _ R E G I S T R Y   M S V P R O C _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{88753B26-5B24-49BD-B2E7-0C445C78C982}' = s 'VideoProcessorMFT'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   