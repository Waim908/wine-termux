        ��  ��                  v  P   W I N E _ R E G I S T R Y   D X D I A G N _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{A65B8071-3BFE-4213-9A5B-491DA4461CA7}' = s 'DxDiagProvider Class'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'DxDiag.DxDiagProvider.1'
            VersionIndependentProgId = s 'DxDiag.DxDiagProvider'
        }
    }
    'DxDiag.DxDiagProvider.1' = s 'DxDiagProvider Class'
    {
        CLSID = s '{A65B8071-3BFE-4213-9A5B-491DA4461CA7}'
    }
    'DxDiag.DxDiagProvider' = s 'DxDiagProvider Class'
    {
        CLSID = s '{A65B8071-3BFE-4213-9A5B-491DA4461CA7}'
        CurVer = s 'DxDiag.DxDiagProvider.1'
    }
}
  