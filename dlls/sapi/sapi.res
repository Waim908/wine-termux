        ��  ��                  d  8   W I N E _ R E G I S T R Y   ��     0           HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove Speech
            {
                NoRemove AudioInput
                {
                    val DefaultDefaultTokenId = s 'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput\TokenEnums\MMAudioIn\'
                    NoRemove TokenEnums
                    {
                        NoRemove MMAudioIn
                        {
                            val CLSID = s '{AB1890A0-E91F-11D2-BB91-00C04F8EE6C0}'
                        }
                    }
                }
                NoRemove AudioOutput
                {
                    val DefaultDefaultTokenId = s 'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput\TokenEnums\MMAudioOut\'
                    NoRemove TokenEnums
                    {
                        NoRemove MMAudioOut
                        {
                            val CLSID = s '{AB1890A0-E91F-11D2-BB91-00C04F8EE6C0}'
                        }
                    }
                }
                NoRemove Voices
                {
                    NoRemove Tokens
                    {
                        NoRemove 'Wine Default Voice'
                        {
                            NoRemove Attributes
                        }
                    }
                }
            }
        }
    }
}
