        ��  ��                  �  d   W I N E _ R E G I S T R Y   U I R I B B O N _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{926749FA-2615-4987-8845-C33E65F2B957}' = s 'UIRibbonFramework Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{0F7434B6-59B6-4250-999E-D168D6AE4293}' = s 'UIRibbonImageFromBitmapFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
