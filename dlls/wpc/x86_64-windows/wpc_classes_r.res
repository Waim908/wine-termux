        ��  ��                  �   X   W I N E _ R E G I S T R Y   W P C _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{E77CC89B-7401-4C04-8CED-149DB35ADD04}' = s 'WindowsParentalControls class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   