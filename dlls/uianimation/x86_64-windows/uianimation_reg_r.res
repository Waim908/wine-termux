        ��  ��                  �  `   W I N E _ R E G I S T R Y   U I A N I M A T I O N _ R E G _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{BFCD4A0C-06B6-4384-B768-0DAA792C380E}' = s 'UIAnimationTimer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{4C1FC63A-695C-47E8-A339-1A194BE3D0B8}' = s 'UIAnimationManager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{8A9B1CDD-FCD7-419C-8B44-42FD17DB1887}' = s 'UIAnimationTransitionFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{1D6322AD-AA85-4EF5-A828-86D71067D145}' = s 'UIAnimationTransitionLibrary'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  