        ��  ��                  �  d   W I N E _ R E G I S T R Y   V B S C R I P T _ C L A S S E S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{3F4DACA4-160D-11D2-A8E9-00104B365C9F}' = s 'VBScript Regular Expression'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'VBScript.RegExp'
            Version = s '5.5'
        }
        '{B54F3741-5B07-11CF-A4B0-00AA004A55E8}' = s 'VB Script Language'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'VBScript'
        }
        '{B54F3742-5B07-11CF-A4B0-00AA004A55E8}' = s 'VB Script Language Authoring'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'VBScript Author'
        }
        '{B54F3743-5B07-11CF-A4B0-00AA004A55E8}' = s 'VB Script Language Encoding'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'VBScript.Encode'
        }
    }
    'VBScript.RegExp' = s 'VBScript Regular Expression'
    {
        CLSID = s '{3F4DACA4-160D-11D2-A8E9-00104B365C9F}'
    }
    'VBScript' = s 'VB Script Language'
    {
        CLSID = s '{B54F3741-5B07-11CF-A4B0-00AA004A55E8}'
    }
    'VBScript Author' = s 'VB Script Language Authoring'
    {
        CLSID = s '{B54F3742-5B07-11CF-A4B0-00AA004A55E8}'
    }
    'VBScript.Encode' = s 'VB Script Language Encoding'
    {
        CLSID = s '{B54F3743-5B07-11CF-A4B0-00AA004A55E8}'
    }
}
   