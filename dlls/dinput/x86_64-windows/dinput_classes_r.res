        ��  ��                  �  `   W I N E _ R E G I S T R Y   D I N P U T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{25E609E0-B259-11CF-BFC7-444553540000}' = s 'DirectInput Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{25E609E1-B259-11CF-BFC7-444553540000}' = s 'DirectInputDevice Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  