        ��  ��                  0  `   W I N E _ R E G I S T R Y   M S D A S Q L _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{C8B522CB-5CF3-11CE-ADE5-00AA0044773D}' = s 'MSDASQL'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSDASQL.1'
            VersionIndependentProgId = s 'MSDASQL'
        }
        '{C8B522CD-5CF3-11CE-ADE5-00AA0044773D}' = s 'MSDASQLEnumerator'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSDASQLEnumerator.1'
            VersionIndependentProgId = s 'MSDASQLEnumerator'
        }
    }
    'MSDASQL.1' = s 'MSDASQL'
    {
        CLSID = s '{C8B522CB-5CF3-11CE-ADE5-00AA0044773D}'
    }
    'MSDASQL' = s 'MSDASQL'
    {
        CLSID = s '{C8B522CB-5CF3-11CE-ADE5-00AA0044773D}'
        CurVer = s 'MSDASQL.1'
    }
    'MSDASQLEnumerator.1' = s 'MSDASQLEnumerator'
    {
        CLSID = s '{C8B522CD-5CF3-11CE-ADE5-00AA0044773D}'
    }
    'MSDASQLEnumerator' = s 'MSDASQLEnumerator'
    {
        CLSID = s '{C8B522CD-5CF3-11CE-ADE5-00AA0044773D}'
        CurVer = s 'MSDASQLEnumerator.1'
    }
}
