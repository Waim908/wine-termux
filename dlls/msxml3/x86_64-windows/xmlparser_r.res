        ��  ��                     T   W I N E _ R E G I S T R Y   X M L P A R S E R _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{F5078F19-C551-11D3-89B9-0000F81FE221}' = s 'XML Parser'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Msxml2.XMLParser'
            Version = s '3.0'
            VersionIndependentProgId = s 'Msxml2.XMLParser'
        }
        '{F5078F20-C551-11D3-89B9-0000F81FE221}' = s 'XML Parser 2.6'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Msxml2.XMLParser.2.6'
            Version = s '2.6'
            VersionIndependentProgId = s 'Msxml2.XMLParser'
        }
        '{F5078F31-C551-11D3-89B9-0000F81FE221}' = s 'XML Parser 3.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Msxml2.XMLParser.3.0'
            Version = s '3.0'
            VersionIndependentProgId = s 'Msxml2.XMLParser'
        }
        '{48123BC4-99D9-11D1-A6B3-00C04FD91555}' = s 'XML Document'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'xmlfile'
            Version = s '1.0'
        }
    }
    'Msxml2.XMLParser' = s 'XML Parser'
    {
        CLSID = s '{F5078F19-C551-11D3-89B9-0000F81FE221}'
    }
    'Msxml2.XMLParser' = s 'XML Parser'
    {
        CLSID = s '{F5078F19-C551-11D3-89B9-0000F81FE221}'
    }
    'Msxml2.XMLParser.2.6' = s 'XML Parser 2.6'
    {
        CLSID = s '{F5078F20-C551-11D3-89B9-0000F81FE221}'
    }
    'Msxml2.XMLParser' = s 'XML Parser 2.6'
    {
        CLSID = s '{F5078F20-C551-11D3-89B9-0000F81FE221}'
        CurVer = s 'Msxml2.XMLParser.2.6'
    }
    'Msxml2.XMLParser.3.0' = s 'XML Parser 3.0'
    {
        CLSID = s '{F5078F31-C551-11D3-89B9-0000F81FE221}'
    }
    'Msxml2.XMLParser' = s 'XML Parser 3.0'
    {
        CLSID = s '{F5078F31-C551-11D3-89B9-0000F81FE221}'
        CurVer = s 'Msxml2.XMLParser.3.0'
    }
    'xmlfile' = s 'XML Document'
    {
        CLSID = s '{48123BC4-99D9-11D1-A6B3-00C04FD91555}'
    }
}
