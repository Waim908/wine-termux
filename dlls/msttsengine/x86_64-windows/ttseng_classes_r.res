        ��  ��                  �   `   W I N E _ R E G I S T R Y   T T S E N G _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{C64501F6-E6E6-451F-A150-25D0839BC510}' = s 'Microsoft SAPI/SpeechFX TTS Engine Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
