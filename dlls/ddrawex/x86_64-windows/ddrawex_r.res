        ��  ��                  �   P   W I N E _ R E G I S T R Y   D D R A W E X _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{4FD2A832-86C8-11D0-8FCA-00C04FD9189D}' = s 'DirectDrawFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   