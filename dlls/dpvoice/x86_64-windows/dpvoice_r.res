        ��  ��                  S  P   W I N E _ R E G I S T R Y   D P V O I C E _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{B9F3EB85-B781-4AC1-8D90-93A05EE37D7D}' = s 'DirectPlayVoice Client Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'DirectPlayVoice.Client.1'
            VersionIndependentProgId = s 'DirectPlayVoice.Client'
        }
        '{D3F5B8E6-9B78-4A4C-94EA-CA2397B663D3}' = s 'DirectPlayVoice Server Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'DirectPlayVoice.Server.1'
            VersionIndependentProgId = s 'DirectPlayVoice.Server'
        }
        '{0F0F094B-B01C-4091-A14D-DD0CD807711A}' = s 'DirectPlayVoice Test Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'DirectPlayVoice.Test.1'
            VersionIndependentProgId = s 'DirectPlayVoice.Test'
        }
    }
    'DirectPlayVoice.Client.1' = s 'DirectPlayVoice Client Object'
    {
        CLSID = s '{B9F3EB85-B781-4AC1-8D90-93A05EE37D7D}'
    }
    'DirectPlayVoice.Client' = s 'DirectPlayVoice Client Object'
    {
        CLSID = s '{B9F3EB85-B781-4AC1-8D90-93A05EE37D7D}'
        CurVer = s 'DirectPlayVoice.Client.1'
    }
    'DirectPlayVoice.Server.1' = s 'DirectPlayVoice Server Object'
    {
        CLSID = s '{D3F5B8E6-9B78-4A4C-94EA-CA2397B663D3}'
    }
    'DirectPlayVoice.Server' = s 'DirectPlayVoice Server Object'
    {
        CLSID = s '{D3F5B8E6-9B78-4A4C-94EA-CA2397B663D3}'
        CurVer = s 'DirectPlayVoice.Server.1'
    }
    'DirectPlayVoice.Test.1' = s 'DirectPlayVoice Test Object'
    {
        CLSID = s '{0F0F094B-B01C-4091-A14D-DD0CD807711A}'
    }
    'DirectPlayVoice.Test' = s 'DirectPlayVoice Test Object'
    {
        CLSID = s '{0F0F094B-B01C-4091-A14D-DD0CD807711A}'
        CurVer = s 'DirectPlayVoice.Test.1'
    }
}
 