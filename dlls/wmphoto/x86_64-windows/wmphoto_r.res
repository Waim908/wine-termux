        ��  ��                  v  P   W I N E _ R E G I S T R Y   W M P H O T O _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{A26CEC36-234C-4950-AE16-E34AACE71D0D}' = s 'WIC WMP Decoder'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{AC4CE3CB-E1C1-44CD-8215-5A1665509EC2}' = s 'WIC WMP Encoder'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  