        ��  ��                  }  H   W I N E _ R E G I S T R Y   M F _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{477EC299-1421-4BDD-971F-7CCB933F21AD}' = s 'File scheme handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{9EC4B4F9-3029-45AD-947B-344DE2A249E2}' = s 'UrlmonSchemePlugin'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   