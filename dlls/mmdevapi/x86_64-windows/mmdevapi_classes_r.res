        ��  ��                  �   d   W I N E _ R E G I S T R Y   M M D E V A P I _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{BCDE0395-E52F-467C-8E3D-C4579291692E}' = s 'MMDeviceEnumerator class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
