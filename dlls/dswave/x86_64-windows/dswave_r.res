        ��  ��                  �  P   W I N E _ R E G I S T R Y   D S W A V E _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{8A667154-F9CB-11D2-AD8A-0060B0575ABC}' = s 'Microsoft DirectSound Wave'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Microsoft.DirectSoundWave.1'
            VersionIndependentProgId = s 'Microsoft.DirectSoundWave'
        }
    }
    'Microsoft.DirectSoundWave.1' = s 'Microsoft DirectSound Wave'
    {
        CLSID = s '{8A667154-F9CB-11D2-AD8A-0060B0575ABC}'
    }
    'Microsoft.DirectSoundWave' = s 'Microsoft DirectSound Wave'
    {
        CLSID = s '{8A667154-F9CB-11D2-AD8A-0060B0575ABC}'
        CurVer = s 'Microsoft.DirectSoundWave.1'
    }
}
 