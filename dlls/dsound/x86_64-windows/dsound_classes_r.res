        ��  ��                  P  `   W I N E _ R E G I S T R Y   D S O U N D _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{47D4D946-62E8-11CF-93BC-444553540000}' = s 'DirectSound Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}' = s 'DirectSound 8.0 Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{B2F586D4-5558-49D1-A07B-3249DBBB33C2}' = s 'DirectSoundBufferConfig Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{B0210780-89CD-11D0-AF08-00A0C925CD16}' = s 'DirectSoundCapture Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}' = s 'DirectSoundCapture 8.0 Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{FEA4300C-7959-4147-B26A-2377B9E7A91D}' = s 'DirectSoundFullDuplex Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
