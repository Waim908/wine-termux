        ��  ��                    d   W I N E _ R E G I S T R Y   W B E M D I S P _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{172BDDF8-CEEA-11D1-8B05-00600806D9B6}' = s 'WinMGMTS'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'WINMGMTS.1'
            VersionIndependentProgId = s 'WINMGMTS'
        }
    }
    'WINMGMTS.1' = s 'WinMGMTS'
    {
        CLSID = s '{172BDDF8-CEEA-11D1-8B05-00600806D9B6}'
    }
    'WINMGMTS' = s 'WinMGMTS'
    {
        CLSID = s '{172BDDF8-CEEA-11D1-8B05-00600806D9B6}'
        CurVer = s 'WINMGMTS.1'
    }
}
   