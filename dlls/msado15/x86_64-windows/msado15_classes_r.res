        ��  ��                  R  `   W I N E _ R E G I S T R Y   M S A D O 1 5 _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{00000507-0000-0010-8000-00AA006D2EA4}' = s 'Command'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'ADODB.Command.6.0'
            VersionIndependentProgId = s 'ADODB.Command'
        }
        '{00000514-0000-0010-8000-00AA006D2EA4}' = s 'Connection'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'ADODB.Connection.6.0'
            VersionIndependentProgId = s 'ADODB.Connection'
        }
        '{00000535-0000-0010-8000-00AA006D2EA4}' = s 'Recordset'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'ADODB.Recordset.6.0'
            VersionIndependentProgId = s 'ADODB.Recordset'
        }
        '{00000566-0000-0010-8000-00AA006D2EA4}' = s 'Stream'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'ADODB.Stream.6.0'
            VersionIndependentProgId = s 'ADODB.Stream'
        }
    }
    'ADODB.Command.6.0' = s 'Command'
    {
        CLSID = s '{00000507-0000-0010-8000-00AA006D2EA4}'
    }
    'ADODB.Command' = s 'Command'
    {
        CLSID = s '{00000507-0000-0010-8000-00AA006D2EA4}'
        CurVer = s 'ADODB.Command.6.0'
    }
    'ADODB.Connection.6.0' = s 'Connection'
    {
        CLSID = s '{00000514-0000-0010-8000-00AA006D2EA4}'
    }
    'ADODB.Connection' = s 'Connection'
    {
        CLSID = s '{00000514-0000-0010-8000-00AA006D2EA4}'
        CurVer = s 'ADODB.Connection.6.0'
    }
    'ADODB.Recordset.6.0' = s 'Recordset'
    {
        CLSID = s '{00000535-0000-0010-8000-00AA006D2EA4}'
    }
    'ADODB.Recordset' = s 'Recordset'
    {
        CLSID = s '{00000535-0000-0010-8000-00AA006D2EA4}'
        CurVer = s 'ADODB.Recordset.6.0'
    }
    'ADODB.Stream.6.0' = s 'Stream'
    {
        CLSID = s '{00000566-0000-0010-8000-00AA006D2EA4}'
    }
    'ADODB.Stream' = s 'Stream'
    {
        CLSID = s '{00000566-0000-0010-8000-00AA006D2EA4}'
        CurVer = s 'ADODB.Stream.6.0'
    }
}
  