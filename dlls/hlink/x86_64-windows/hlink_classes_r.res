        ��  ��                    \   W I N E _ R E G I S T R Y   H L I N K _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{79EAC9D0-BAF9-11CE-8C82-00AA004BA90B}' = s 'StdHlink'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{79EAC9D1-BAF9-11CE-8C82-00AA004BA90B}' = s 'StdHlinkBrowseContext'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
 