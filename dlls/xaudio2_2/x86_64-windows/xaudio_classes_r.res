        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{B802058A-464A-42DB-BC10-B650D6F2586A}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{97DFB7E7-5161-4015-87A9-C79E6A1952CC}' = s 'XAudio2Debug'
        {
        }
        '{F5CA7B34-8055-42C0-B836-216129EB7E30}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{629CF0DE-3ECC-41E7-9926-F7E43EEBEC51}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  