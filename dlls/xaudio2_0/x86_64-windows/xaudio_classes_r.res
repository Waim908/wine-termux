        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{FAC23F48-31F5-45A8-B49B-5225D61401AA}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{FAC23F48-31F5-45A8-B49B-5225D61401DB}' = s 'XAudio2Debug'
        {
        }
        '{C0C56F46-29B1-44E9-9939-A32CE86867E2}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{6F6EA3A9-2CF5-41CF-91C1-2170B1540063}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  