        ��  ��                  -  \   W I N E _ R E G I S T R Y   D D R A W _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{D7B70EE0-4340-11CF-B063-0020AFC2CD35}' = s 'DirectDraw Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{3C305196-50DB-11D3-9CFE-00C04FD930C5}' = s 'DirectDraw 7 Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{593817A0-7DB3-11CF-A2DE-00AA00B93356}' = s 'DirectDraw Clipper Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   