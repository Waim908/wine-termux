        ��  ��                  �  P   W I N E _ R E G I S T R Y   D M S Y N T H _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{58C2B4D0-46E7-11D1-89AC-00A0C9054129}' = s 'DirectMusicSynth'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSynth.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSynth'
        }
        '{AEC17CE3-A514-11D1-AFA6-00AA0024D8B6}' = s 'DirectMusicSynthSink'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSynthSink.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSynthSink'
        }
    }
    'Microsoft.DirectMusicSynth.1' = s 'DirectMusicSynth'
    {
        CLSID = s '{58C2B4D0-46E7-11D1-89AC-00A0C9054129}'
    }
    'Microsoft.DirectMusicSynth' = s 'DirectMusicSynth'
    {
        CLSID = s '{58C2B4D0-46E7-11D1-89AC-00A0C9054129}'
        CurVer = s 'Microsoft.DirectMusicSynth.1'
    }
    'Microsoft.DirectMusicSynthSink.1' = s 'DirectMusicSynthSink'
    {
        CLSID = s '{AEC17CE3-A514-11D1-AFA6-00AA0024D8B6}'
    }
    'Microsoft.DirectMusicSynthSink' = s 'DirectMusicSynthSink'
    {
        CLSID = s '{AEC17CE3-A514-11D1-AFA6-00AA0024D8B6}'
        CurVer = s 'Microsoft.DirectMusicSynthSink.1'
    }
}
