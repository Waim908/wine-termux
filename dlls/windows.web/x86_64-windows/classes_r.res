        ��  ��                  �  P   W I N E _ R E G I S T R Y   C L A S S E S _ R _ R E S                   HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove WindowsRuntime
            {
                NoRemove ActivatableClassId
                {
                    ForceRemove Windows.Data.Json.JsonArray
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Data.Json.JsonObject
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Data.Json.JsonValue
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
  