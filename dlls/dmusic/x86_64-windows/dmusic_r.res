        ��  ��                  �  P   W I N E _ R E G I S T R Y   D M U S I C _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{636B9F10-0C7D-11D1-95B2-0020AFDC7421}' = s 'DirectMusic'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusic.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusic'
        }
        '{480FF4B0-28B2-11D1-BEF7-00C04FBF8FEF}' = s 'DirectMusicCollection'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicCollection.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicCollection'
        }
    }
    'Microsoft.DirectMusic.1' = s 'DirectMusic'
    {
        CLSID = s '{636B9F10-0C7D-11D1-95B2-0020AFDC7421}'
    }
    'Microsoft.DirectMusic' = s 'DirectMusic'
    {
        CLSID = s '{636B9F10-0C7D-11D1-95B2-0020AFDC7421}'
        CurVer = s 'Microsoft.DirectMusic.1'
    }
    'Microsoft.DirectMusicCollection.1' = s 'DirectMusicCollection'
    {
        CLSID = s '{480FF4B0-28B2-11D1-BEF7-00C04FBF8FEF}'
    }
    'Microsoft.DirectMusicCollection' = s 'DirectMusicCollection'
    {
        CLSID = s '{480FF4B0-28B2-11D1-BEF7-00C04FBF8FEF}'
        CurVer = s 'Microsoft.DirectMusicCollection.1'
    }
}
