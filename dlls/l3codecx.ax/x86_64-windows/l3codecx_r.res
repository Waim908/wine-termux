        ��  ��                  �   T   W I N E _ R E G I S T R Y   L 3 C O D E C X _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{38BE3000-DBF4-11D0-860E-00A024CFEF6D}' = s 'MPEG Layer-3 Decoder'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
