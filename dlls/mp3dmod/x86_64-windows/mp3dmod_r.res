        ��  ��                  �   P   W I N E _ R E G I S T R Y   M P 3 D M O D _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{BBEEA841-0A63-4F52-A7AB-A9B3A84ED38A}' = s 'CMP3DecMediaObject'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  