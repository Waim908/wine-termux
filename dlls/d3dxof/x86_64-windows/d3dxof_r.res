        ��  ��                  �   P   W I N E _ R E G I S T R Y   D 3 D X O F _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{4516EC43-8F20-11D0-9B6D-0000C0781BC3}' = s 'DirectX File'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
