        ��  ��                  �   T   W I N E _ R E G I S T R Y   M F H 2 6 4 E N C _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{6CA50344-051A-4DED-9779-A43305165E35}' = s 'CMSH264EncoderMFT'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   