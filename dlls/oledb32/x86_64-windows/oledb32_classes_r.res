        ��  ��                  �  `   W I N E _ R E G I S T R Y   O L E D B 3 2 _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{C8B522D1-5CF3-11CE-ADE5-00AA0044773D}' = s 'OLE DB Data Conversion Library'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSDADC.1'
            VersionIndependentProgId = s 'MSDADC'
        }
        '{C8B522CF-5CF3-11CE-ADE5-00AA0044773D}' = s 'OLE DB Error Collection Service'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'MSDAER.1'
            VersionIndependentProgId = s 'MSDAER'
        }
        '{2048EEE6-7FA2-11D0-9E6A-00A0C9138C29}' = s 'OLE DB Row Position Library'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'RowPosition.RowPosition.1'
            VersionIndependentProgId = s 'RowPosition.RowPosition'
        }
    }
    'MSDADC.1' = s 'OLE DB Data Conversion Library'
    {
        CLSID = s '{C8B522D1-5CF3-11CE-ADE5-00AA0044773D}'
    }
    'MSDADC' = s 'OLE DB Data Conversion Library'
    {
        CLSID = s '{C8B522D1-5CF3-11CE-ADE5-00AA0044773D}'
        CurVer = s 'MSDADC.1'
    }
    'MSDAER.1' = s 'OLE DB Error Collection Service'
    {
        CLSID = s '{C8B522CF-5CF3-11CE-ADE5-00AA0044773D}'
    }
    'MSDAER' = s 'OLE DB Error Collection Service'
    {
        CLSID = s '{C8B522CF-5CF3-11CE-ADE5-00AA0044773D}'
        CurVer = s 'MSDAER.1'
    }
    'RowPosition.RowPosition.1' = s 'OLE DB Row Position Library'
    {
        CLSID = s '{2048EEE6-7FA2-11D0-9E6A-00A0C9138C29}'
    }
    'RowPosition.RowPosition' = s 'OLE DB Row Position Library'
    {
        CLSID = s '{2048EEE6-7FA2-11D0-9E6A-00A0C9138C29}'
        CurVer = s 'RowPosition.RowPosition.1'
    }
}
 