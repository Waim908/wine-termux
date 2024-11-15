        ��  ��                  <  `   W I N E _ R E G I S T R Y   D E V E N U M _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{62BE5D10-60EB-11D0-BD3B-00A0C911CE86}' = s 'System Device Enum'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{4315D437-5B8C-11D0-BD3B-00A0C911CE86}' = s 'DeviceMoniker'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'device.1'
            VersionIndependentProgId = s 'device'
        }
        '{33D9A761-90C8-11D0-BD43-00A0C911CE86}' = s 'ACM Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{33D9A760-90C8-11D0-BD43-00A0C911CE86}' = s 'ICM Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{083863F1-70DE-11D0-BD40-00A0C911CE86}' = s 'ActiveMovie Filter Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{860BB310-5D01-11D0-BD3B-00A0C911CE86}' = s 'VFW Capture Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{33D9A762-90C8-11D0-BD43-00A0C911CE86}' = s 'WaveIn Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{E0F158E1-CB04-11D0-BD4E-00A0C911CE86}' = s 'WaveOut and DSound Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{4EFE2452-168A-11D1-BC76-00C04FB9453B}' = s 'MidiOut Class Manager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{DA4E3DA0-D07D-11D0-BD50-00A0C911CE86}' = s 'ActiveMovie Filter Categories'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
    'device.1' = s 'DeviceMoniker'
    {
        CLSID = s '{4315D437-5B8C-11D0-BD3B-00A0C911CE86}'
    }
    'device' = s 'DeviceMoniker'
    {
        CLSID = s '{4315D437-5B8C-11D0-BD3B-00A0C911CE86}'
        CurVer = s 'device.1'
    }
}
