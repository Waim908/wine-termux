        ��  ��                  �  P   W I N E _ R E G I S T R Y   D I N P U T 8 _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{25E609E4-B259-11CF-BFC7-444553540000}' = s 'DirectInput8 Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{25E609E5-B259-11CF-BFC7-444553540000}' = s 'DirectInputDevice8 Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
