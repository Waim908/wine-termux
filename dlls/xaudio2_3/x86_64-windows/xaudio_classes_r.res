        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{4C5E637A-16C7-4DE3-9C46-5ED22181962D}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{EF0AA05D-8075-4E5D-BEAD-45BE0C3CCBB3}' = s 'XAudio2Debug'
        {
        }
        '{E180344B-AC83-4483-959E-18A5C56A5E19}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{9CAB402C-1D37-44B4-886D-FA4F36170A4C}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  