        ��  ��                  3  P   W I N E _ R E G I S T R Y   C L A S S E S _ R _ R E S                   HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove WindowsRuntime
            {
                NoRemove ActivatableClassId
                {
                    ForceRemove Windows.Globalization.Calendar
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Globalization.ApplicationLanguages
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Globalization.Language
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Globalization.GeographicRegion
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.System.UserProfile.GlobalizationPreferences
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
 