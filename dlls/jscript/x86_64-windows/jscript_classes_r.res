        ��  ��                  	  `   W I N E _ R E G I S T R Y   J S C R I P T _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{F414C260-6AC0-11CF-B6D1-00AA00BBBB58}' = s 'JScript Language'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'JScript'
        }
        '{F414C261-6AC0-11CF-B6D1-00AA00BBBB58}' = s 'JScript Language Authoring'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'JScript Author'
        }
        '{F414C262-6AC0-11CF-B6D1-00AA00BBBB58}' = s 'JScript Language Encoding'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'JScript.Encode'
        }
    }
    'JScript' = s 'JScript Language'
    {
        CLSID = s '{F414C260-6AC0-11CF-B6D1-00AA00BBBB58}'
    }
    'JScript Author' = s 'JScript Language Authoring'
    {
        CLSID = s '{F414C261-6AC0-11CF-B6D1-00AA00BBBB58}'
    }
    'JScript.Encode' = s 'JScript Language Encoding'
    {
        CLSID = s '{F414C262-6AC0-11CF-B6D1-00AA00BBBB58}'
    }
}
   