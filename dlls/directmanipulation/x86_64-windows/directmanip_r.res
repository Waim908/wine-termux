        ��  ��                  C  X   W I N E _ R E G I S T R Y   D I R E C T M A N I P _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{54E211B6-3650-4F75-8334-FA359598E1C5}' = s 'DirectManipulationManager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{99793286-77CC-4B57-96DB-3B354F6F9FB5}' = s 'DirectManipulationSharedManager'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{79DEA627-A08A-43AC-8EF5-6900B9299126}' = s 'DCompManipulationCompositor'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 