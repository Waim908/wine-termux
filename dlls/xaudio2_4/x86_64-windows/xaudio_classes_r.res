        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{03219E78-5BC3-44D1-B92E-F63D89CC6526}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{4256535C-1EA4-4D4B-8AD5-F9DB762ECA9E}' = s 'XAudio2Debug'
        {
        }
        '{C7338B95-52B8-4542-AA79-42EB016C8C1C}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{8BB7778B-645B-4475-9A73-1DE3170BD3AF}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  