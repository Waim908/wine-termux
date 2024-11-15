        ��  ��                  �%  L   W I N E _ R E G I S T R Y   D M I M E _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{D2AC2881-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicPerformance'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicPerformance.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicPerformance'
        }
        '{D2AC2882-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicSegment'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSegment.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSegment'
        }
        '{D2AC2883-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicSegmentState'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSegmentState.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSegmentState'
        }
        '{D2AC2884-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicGraph'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicGraph.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicGraph'
        }
        '{D2AC2885-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicTempoTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicTempoTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicTempoTrack'
        }
        '{D2AC2886-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicSeqTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSeqTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSeqTrack'
        }
        '{D2AC2887-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicSysExTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSysExTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSysExTrack'
        }
        '{D2AC2888-B39B-11D1-8704-00600893B1BD}' = s 'DirectMusicTimeSigTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicTimeSigTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicTimeSigTrack'
        }
        '{AED5F0A5-D972-483D-A384-649DFEB9C181}' = s 'DirectMusicSong'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSong.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSong'
        }
        '{4BE0537B-5C19-11D3-8BDC-00600893B1B6}' = s 'DirectMusicParamControlTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicParamControlTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicParamControlTrack'
        }
        '{55A8FD00-4288-11D3-9BD1-8A0D61C88835}' = s 'DirectMusicMarkerTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicMarkerTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicMarkerTrack'
        }
        '{995C1CF5-54FF-11D3-8BDA-00600893B1B6}' = s 'DirectMusicLyricsTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicLyricsTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicLyricsTrack'
        }
        '{BAE4D665-4EA1-11D3-8BDA-00600893B1B6}' = s 'DirectMusicSegTriggerTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicSegTriggerTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicSegTriggerTrack'
        }
        '{EE0B9CA0-A81E-11D3-9BD1-0080C7150A74}' = s 'DirectMusicAudioPath'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicAudioPath.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicAudioPath'
        }
        '{EED36461-9EA5-11D3-9BD1-0080C7150A74}' = s 'DirectMusicWaveTrack'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectMusicWaveTrack.1'
            VersionIndependentProgId = s 'Microsoft.DirectMusicWaveTrack'
        }
    }
    'Microsoft.DirectMusicPerformance.1' = s 'DirectMusicPerformance'
    {
        CLSID = s '{D2AC2881-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicPerformance' = s 'DirectMusicPerformance'
    {
        CLSID = s '{D2AC2881-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicPerformance.1'
    }
    'Microsoft.DirectMusicSegment.1' = s 'DirectMusicSegment'
    {
        CLSID = s '{D2AC2882-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicSegment' = s 'DirectMusicSegment'
    {
        CLSID = s '{D2AC2882-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicSegment.1'
    }
    'Microsoft.DirectMusicSegmentState.1' = s 'DirectMusicSegmentState'
    {
        CLSID = s '{D2AC2883-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicSegmentState' = s 'DirectMusicSegmentState'
    {
        CLSID = s '{D2AC2883-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicSegmentState.1'
    }
    'Microsoft.DirectMusicGraph.1' = s 'DirectMusicGraph'
    {
        CLSID = s '{D2AC2884-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicGraph' = s 'DirectMusicGraph'
    {
        CLSID = s '{D2AC2884-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicGraph.1'
    }
    'Microsoft.DirectMusicTempoTrack.1' = s 'DirectMusicTempoTrack'
    {
        CLSID = s '{D2AC2885-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicTempoTrack' = s 'DirectMusicTempoTrack'
    {
        CLSID = s '{D2AC2885-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicTempoTrack.1'
    }
    'Microsoft.DirectMusicSeqTrack.1' = s 'DirectMusicSeqTrack'
    {
        CLSID = s '{D2AC2886-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicSeqTrack' = s 'DirectMusicSeqTrack'
    {
        CLSID = s '{D2AC2886-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicSeqTrack.1'
    }
    'Microsoft.DirectMusicSysExTrack.1' = s 'DirectMusicSysExTrack'
    {
        CLSID = s '{D2AC2887-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicSysExTrack' = s 'DirectMusicSysExTrack'
    {
        CLSID = s '{D2AC2887-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicSysExTrack.1'
    }
    'Microsoft.DirectMusicTimeSigTrack.1' = s 'DirectMusicTimeSigTrack'
    {
        CLSID = s '{D2AC2888-B39B-11D1-8704-00600893B1BD}'
    }
    'Microsoft.DirectMusicTimeSigTrack' = s 'DirectMusicTimeSigTrack'
    {
        CLSID = s '{D2AC2888-B39B-11D1-8704-00600893B1BD}'
        CurVer = s 'Microsoft.DirectMusicTimeSigTrack.1'
    }
    'Microsoft.DirectMusicSong.1' = s 'DirectMusicSong'
    {
        CLSID = s '{AED5F0A5-D972-483D-A384-649DFEB9C181}'
    }
    'Microsoft.DirectMusicSong' = s 'DirectMusicSong'
    {
        CLSID = s '{AED5F0A5-D972-483D-A384-649DFEB9C181}'
        CurVer = s 'Microsoft.DirectMusicSong.1'
    }
    'Microsoft.DirectMusicParamControlTrack.1' = s 'DirectMusicParamControlTrack'
    {
        CLSID = s '{4BE0537B-5C19-11D3-8BDC-00600893B1B6}'
    }
    'Microsoft.DirectMusicParamControlTrack' = s 'DirectMusicParamControlTrack'
    {
        CLSID = s '{4BE0537B-5C19-11D3-8BDC-00600893B1B6}'
        CurVer = s 'Microsoft.DirectMusicParamControlTrack.1'
    }
    'Microsoft.DirectMusicMarkerTrack.1' = s 'DirectMusicMarkerTrack'
    {
        CLSID = s '{55A8FD00-4288-11D3-9BD1-8A0D61C88835}'
    }
    'Microsoft.DirectMusicMarkerTrack' = s 'DirectMusicMarkerTrack'
    {
        CLSID = s '{55A8FD00-4288-11D3-9BD1-8A0D61C88835}'
        CurVer = s 'Microsoft.DirectMusicMarkerTrack.1'
    }
    'Microsoft.DirectMusicLyricsTrack.1' = s 'DirectMusicLyricsTrack'
    {
        CLSID = s '{995C1CF5-54FF-11D3-8BDA-00600893B1B6}'
    }
    'Microsoft.DirectMusicLyricsTrack' = s 'DirectMusicLyricsTrack'
    {
        CLSID = s '{995C1CF5-54FF-11D3-8BDA-00600893B1B6}'
        CurVer = s 'Microsoft.DirectMusicLyricsTrack.1'
    }
    'Microsoft.DirectMusicSegTriggerTrack.1' = s 'DirectMusicSegTriggerTrack'
    {
        CLSID = s '{BAE4D665-4EA1-11D3-8BDA-00600893B1B6}'
    }
    'Microsoft.DirectMusicSegTriggerTrack' = s 'DirectMusicSegTriggerTrack'
    {
        CLSID = s '{BAE4D665-4EA1-11D3-8BDA-00600893B1B6}'
        CurVer = s 'Microsoft.DirectMusicSegTriggerTrack.1'
    }
    'Microsoft.DirectMusicAudioPath.1' = s 'DirectMusicAudioPath'
    {
        CLSID = s '{EE0B9CA0-A81E-11D3-9BD1-0080C7150A74}'
    }
    'Microsoft.DirectMusicAudioPath' = s 'DirectMusicAudioPath'
    {
        CLSID = s '{EE0B9CA0-A81E-11D3-9BD1-0080C7150A74}'
        CurVer = s 'Microsoft.DirectMusicAudioPath.1'
    }
    'Microsoft.DirectMusicWaveTrack.1' = s 'DirectMusicWaveTrack'
    {
        CLSID = s '{EED36461-9EA5-11D3-9BD1-0080C7150A74}'
    }
    'Microsoft.DirectMusicWaveTrack' = s 'DirectMusicWaveTrack'
    {
        CLSID = s '{EED36461-9EA5-11D3-9BD1-0080C7150A74}'
        CurVer = s 'Microsoft.DirectMusicWaveTrack.1'
    }
}
  