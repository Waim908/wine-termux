        ��  ��                  �  P   W I N E _ R E G I S T R Y   C L A S S E S _ R _ R E S                   HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove WindowsRuntime
            {
                NoRemove ActivatableClassId
                {
                    ForceRemove Windows.Foundation.Collections.ValueSet
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Foundation.Deferral
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Foundation.MemoryBuffer
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Foundation.PropertyValue
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Foundation.Uri
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Foundation.WwwFormUrlDecoder
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
   