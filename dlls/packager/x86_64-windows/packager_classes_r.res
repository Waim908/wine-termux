        ��  ��                  P  d   W I N E _ R E G I S T R Y   P A C K A G E R _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{F20DA720-C02F-11CE-927B-0800095AE340}' = s 'Package'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'Package'
        }
    }
    'Package' = s 'Package'
    {
        CLSID = s '{F20DA720-C02F-11CE-927B-0800095AE340}'
    }
}
