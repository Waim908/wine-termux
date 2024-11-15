        ��  ��                  �  8   W I N E _ R E G I S T R Y   ��     0           HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove Cryptography
            {
                NoRemove Defaults
                {
                    NoRemove Provider
                    {
                        ForceRemove 'Microsoft Base DSS Cryptographic Provider'
                        {
                            val 'Image Path' = s '%MODULE%'
                            val 'Type' = d 3
                        }
                        ForceRemove 'Microsoft Base DSS and Diffie-Hellman Cryptographic Provider'
                        {
                            val 'Image Path' = s '%MODULE%'
                            val 'Type' = d 13
                        }
                        ForceRemove 'Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider'
                        {
                            val 'Image Path' = s '%MODULE%'
                            val 'Type' = d 13
                        }
                        ForceRemove 'Microsoft DH SChannel Cryptographic Provider'
                        {
                            val 'Image Path' = s '%MODULE%'
                            val 'Type' = d 18
                        }
                    }
                    NoRemove 'Provider Types'
                    {
                        ForceRemove 'Type 003'
                        {
                            val 'Name' = s 'Microsoft Base DSS Cryptographic Provider'
                            val 'TypeName' = s 'DSS Signature'
                        }
                        ForceRemove 'Type 013'
                        {
                            val 'Name' = s 'Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider'
                            val 'TypeName' = s 'DSS Signature with Diffie-Hellman Key Exchange'
                        }
                        ForceRemove 'Type 018'
                        {
                            val 'Name' = s 'Microsoft DH SChannel Cryptographic Provider'
                            val 'TypeName' = s 'Diffie-Hellman SChannel'
                        }
                    }
                }
            }
        }
    }
}
  