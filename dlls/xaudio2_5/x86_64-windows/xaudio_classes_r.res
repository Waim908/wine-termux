        ��  ��                  j  `   W I N E _ R E G I S T R Y   X A U D I O _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{4C9B6DDE-6809-46E6-A278-9B6A97588670}' = s 'XAudio2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{715BDD1A-AA82-436B-B0FA-6ACEA39BD0A1}' = s 'XAudio2Debug'
        {
        }
        '{2139E6DA-C341-4774-9AC3-B4E026347F64}' = s 'AudioVolumeMeter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{D06DF0D0-8518-441E-822F-5451D5C595B8}' = s 'AudioReverb'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  