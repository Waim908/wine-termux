        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{E21A7345-EB21-468E-BE50-804DB97CF708}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{F7A76C21-53D4-46BB-AC53-8B459CAE46BD}' = s 'XAudio2Debug'
        {
        }
        '{C1E3F122-A2EA-442C-854F-20D98F8357A1}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{F4769300-B949-4DF9-B333-00D33932E9A6}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  