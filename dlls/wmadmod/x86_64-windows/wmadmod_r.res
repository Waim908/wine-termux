        ��  ��                  �   P   W I N E _ R E G I S T R Y   W M A D M O D _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{2EEB4ADF-4578-4D10-BCA7-BB955F56320A}' = s 'CWMADecMediaObject'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  