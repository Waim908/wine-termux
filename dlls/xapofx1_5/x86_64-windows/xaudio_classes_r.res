        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{5A508685-A254-4FBA-9B82-9A24B00306AF}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{DB05EA35-0329-4D4B-A53A-6DEAD03D3852}' = s 'XAudio2Debug'
        {
        }
        '{CAC1105F-619B-4D04-831A-44E1CBF12D57}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{6A93130E-1D53-41D1-A9CF-E758800BB179}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  