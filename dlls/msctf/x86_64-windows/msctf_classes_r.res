        ��  ��                  �  \   W I N E _ R E G I S T R Y   M S C T F _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{529A9E6B-6587-4F23-AB9E-9C7D683E3C50}' = s 'TF_ThreadMgr'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{33C53A50-F456-4884-B049-85FD643ECFED}' = s 'TF_InputProcessorProfiles'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{A4B544A1-438D-4B41-9325-869523E2D6C7}' = s 'TF_CategoryMgr'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{EBB08C45-6C4A-4FDC-AE53-4EB8C4C7DB8E}' = s 'TF_LangBarMgr'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{3CE74DE4-53D3-4D74-8B83-431B3828BA53}' = s 'TF_DisplayAttributeMgr'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
 