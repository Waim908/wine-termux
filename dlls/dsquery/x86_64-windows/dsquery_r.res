        ��  ��                  �   P   W I N E _ R E G I S T R Y   D S Q U E R Y _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{83BC5EC0-6F2A-11D0-A1C4-00AA00C16E65}' = s 'CommonQuery'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
