        ��  ��                  �  X   W I N E _ R E G I S T R Y   I E F R A M E _ V 1 _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{871C5380-42A0-1069-A2EA-08002B30309D}' = s 'Internet'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3C374A40-BAE4-11CF-BF7D-00AA006946EE}' = s 'Microsoft Url History Service'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{FBF23B40-E3F0-101B-8488-00AA003E56F8}' = s 'Internet Shortcut'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'InternetShortcut'
        }
    }
    'InternetShortcut' = s 'Internet Shortcut'
    {
        CLSID = s '{FBF23B40-E3F0-101B-8488-00AA003E56F8}'
    }
}
   