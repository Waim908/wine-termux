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
                    ForceRemove Windows.Graphics.Capture.Direct3D11CaptureFramePool
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Graphics.Capture.GraphicsCaptureItem
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                    ForceRemove Windows.Graphics.Capture.GraphicsCaptureSession
                    {
                        val 'DllPath' = s '%MODULE%'
                    }
                }
            }
        }
    }
}
  