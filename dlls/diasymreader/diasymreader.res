        ��  ��                  ,  8   W I N E _ R E G I S T R Y   ��     0           HKCR
{
    NoRemove CLSID
    {
        '{0ae2deb0-f901-478b-bb9f-881ee8066788}'
        {
            InProcServer32 = s 'mscoree.dll'
            {
                val ThreadingModel = s 'Both'
                '4.0.30319'
                {
                    val 'ImplementedInThisVersion' = s ''
                }
                ProgID = s 'CorSymWriter_SxS'
                Server = s 'diasymreader.dll'
            }
        }
    }
    'CorSymWriter_SxS' = s 'NDP SymWriter'
    {
        CLSID = s '{0ae2deb0-f901-478b-bb9f-881ee8066788}'
    }
}
