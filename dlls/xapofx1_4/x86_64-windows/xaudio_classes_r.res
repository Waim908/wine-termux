        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{3EDA9B49-2085-498B-9BB2-39A6778493DE}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{47199894-7CC2-444D-9873-CED2562CC60E}' = s 'XAudio2Debug'
        {
        }
        '{E48C5A3F-93EF-43BB-A092-2C7CEB946F27}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{CECEC95A-D894-491A-BEE3-5E106FB59F2D}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  