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
                    ForceRemove Windows.UI.Core.CoreCursor
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.UI.Core.CoreWindow
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.UI.Input.PointerPoint
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.UI.ViewManagement.UISettings
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.UI.ViewManagement.UIViewSettings
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.UI.ViewManagement.InputPane
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
  