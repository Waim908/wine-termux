        ��  ��                  �  T   W I N E _ R E G I S T R Y   D M C O M P O S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{D2AC288F-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicChordMap'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicChordMap.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicChordMap'
        }
        '{D2AC2890-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicComposer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicComposer.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicComposer'
        }
        '{D2AC2896-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicChordMapTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicChordMapTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicChordMapTrack'
        }
        '{D30BCC65-60E8-11D1-A7CE-00A0C913F73C}' = s 'DirectMusicTemplate'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicTemplate.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicTemplate'
        }
        '{F17E8672-C3B4-11D1-870B-00600893B1BD}' = s 'DirectMusicSignPostTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSignPostTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSignPostTrack'
        }
    }
    'Microsoft.DirectMusicChordMap.1' = s 'DirectMusicChordMap'
    {
        CLSID = s '{D2AC288F-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicChordMap' = s 'DirectMusicChordMap'
    {
        CLSID = s '{D2AC288F-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicChordMap.1'
    }
    'Microsoft.DirectMusicComposer.1' = s 'DirectMusicComposer'
    {
        CLSID = s '{D2AC2890-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicComposer' = s 'DirectMusicComposer'
    {
        CLSID = s '{D2AC2890-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicComposer.1'
    }
    'Microsoft.DirectMusicChordMapTrack.1' = s 'DirectMusicChordMapTrack'
    {
        CLSID = s '{D2AC2896-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicChordMapTrack' = s 'DirectMusicChordMapTrack'
    {
        CLSID = s '{D2AC2896-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicChordMapTrack.1'
    }
    'Microsoft.DirectMusicTemplate.1' = s 'DirectMusicTemplate'
    {
        CLSID = s '{D30BCC65-60E8-11D1-A7CE-00A0C913F73C}'
    }
    'Microsoft.DirectMusicTemplate' = s 'DirectMusicTemplate'
    {
        CLSID = s '{D30BCC65-60E8-11D1-A7CE-00A0C913F73C}'
        CurVer = s 'Microsoft.DirectMusicTemplate.1'
    }
    'Microsoft.DirectMusicSignPostTrack.1' = s 'DirectMusicSignPostTrack'
    {
        CLSID = s '{F17E8672-C3B4-11D1-870B-00600893B1BD}'
    }
    'Microsoft.DirectMusicSignPostTrack' = s 'DirectMusicSignPostTrack'
    {
        CLSID = s '{F17E8672-C3B4-11D1-870B-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicSignPostTrack.1'
    }
}
  