        ��  ��                  P  P   W I N E _ R E G I S T R Y   C L A S S E S _ R _ R E S                   HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove WindowsRuntime
            {
                NoRemove ActivatableClassId
                {
                    ForceRemove Windows.Security.Cryptography.CryptographicBuffer
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Security.Credentials.KeyCredentialManager
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
