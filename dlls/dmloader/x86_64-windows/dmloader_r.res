        ��  ��                  �  T   W I N E _ R E G I S T R Y   D M L O A D E R _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{D2AC2892-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicLoader'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicLoader.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicLoader'
        }
        '{9301E380-1F22-11D3-8226-D2FA76255D47}' = s 'DirectMusicContainer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicContainer.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicContainer'
        }
    }
    'Microsoft.DirectMusicLoader.1' = s 'DirectMusicLoader'
    {
        CLSID = s '{D2AC2892-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicLoader' = s 'DirectMusicLoader'
    {
        CLSID = s '{D2AC2892-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicLoader.1'
    }
    'Microsoft.DirectMusicContainer.1' = s 'DirectMusicContainer'
    {
        CLSID = s '{9301E380-1F22-11D3-8226-D2FA76255D47}'
    }
    'Microsoft.DirectMusicContainer' = s 'DirectMusicContainer'
    {
        CLSID = s '{9301E380-1F22-11D3-8226-D2FA76255D47}'
        CurVer = s 'Microsoft.DirectMusicContainer.1'
    }
}
