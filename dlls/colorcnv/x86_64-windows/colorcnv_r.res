        ��  ��                  �   T   W I N E _ R E G I S T R Y   C O L O R C N V _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{98230571-0087-4204-B020-3282538E57D3}' = s 'CColorConvertDMO'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
