        ��  ��                  	  L   W I N E _ R E G I S T R Y   I T S S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{9D148290-B9C8-11D0-A4CC-0000F80149F6}' = s 'Microsoft InfoTech Protocol for IE 3.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSITFS1.0'
            VersionIndependentProgId = s 'MSITFS'
        }
        '{9D148291-B9C8-11D0-A4CC-0000F80149F6}' = s 'Microsoft InfoTech Protocol for IE 4.0'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSITFS1.0'
            VersionIndependentProgId = s 'MSITFS'
        }
        '{D54EEE56-AAAB-11D0-9E1D-00A0C922E6EC}' = s 'Microsoft InfoTech IStorage for Win32 Files'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSITFS1.0'
            VersionIndependentProgId = s 'MSITFS'
        }
        '{5D02926A-212E-11D0-9DF9-00A0C922E6EC}' = s 'Microsoft InfoTech IStorage System'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSITFS1.0'
            VersionIndependentProgId = s 'MSITFS'
        }
    }
    'MSITFS1.0' = s 'Microsoft InfoTech Protocol for IE 3.0'
    {
        CLSID = s '{9D148290-B9C8-11D0-A4CC-0000F80149F6}'
    }
    'MSITFS' = s 'Microsoft InfoTech Protocol for IE 3.0'
    {
        CLSID = s '{9D148290-B9C8-11D0-A4CC-0000F80149F6}'
        CurVer = s 'MSITFS1.0'
    }
    'MSITFS1.0' = s 'Microsoft InfoTech Protocol for IE 4.0'
    {
        CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}'
    }
    'MSITFS' = s 'Microsoft InfoTech Protocol for IE 4.0'
    {
        CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}'
        CurVer = s 'MSITFS1.0'
    }
    'MSITFS1.0' = s 'Microsoft InfoTech IStorage for Win32 Files'
    {
        CLSID = s '{D54EEE56-AAAB-11D0-9E1D-00A0C922E6EC}'
    }
    'MSITFS' = s 'Microsoft InfoTech IStorage for Win32 Files'
    {
        CLSID = s '{D54EEE56-AAAB-11D0-9E1D-00A0C922E6EC}'
        CurVer = s 'MSITFS1.0'
    }
    'MSITFS1.0' = s 'Microsoft InfoTech IStorage System'
    {
        CLSID = s '{5D02926A-212E-11D0-9DF9-00A0C922E6EC}'
    }
    'MSITFS' = s 'Microsoft InfoTech IStorage System'
    {
        CLSID = s '{5D02926A-212E-11D0-9DF9-00A0C922E6EC}'
        CurVer = s 'MSITFS1.0'
    }
}
 