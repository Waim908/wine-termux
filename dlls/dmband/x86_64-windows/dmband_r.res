        ��  ��                  �  P   W I N E _ R E G I S T R Y   D M B A N D _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{79BA9E00-B6EE-11D1-86BE-00C04FBF8FEF}' = s 'DirectMusicBand'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicBand.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicBand'
        }
        '{D2AC2894-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicBandTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicBandTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicBandTrack'
        }
    }
    'Microsoft.DirectMusicBand.1' = s 'DirectMusicBand'
    {
        CLSID = s '{79BA9E00-B6EE-11D1-86BE-00C04FBF8FEF}'
    }
    'Microsoft.DirectMusicBand' = s 'DirectMusicBand'
    {
        CLSID = s '{79BA9E00-B6EE-11D1-86BE-00C04FBF8FEF}'
        CurVer = s 'Microsoft.DirectMusicBand.1'
    }
    'Microsoft.DirectMusicBandTrack.1' = s 'DirectMusicBandTrack'
    {
        CLSID = s '{D2AC2894-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicBandTrack' = s 'DirectMusicBandTrack'
    {
        CLSID = s '{D2AC2894-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicBandTrack.1'
    }
}
