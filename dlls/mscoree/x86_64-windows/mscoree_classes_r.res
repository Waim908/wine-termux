        ��  ��                  �  `   W I N E _ R E G I S T R Y   M S C O R E E _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{90F1A06E-7712-4762-86B5-7A5EBA6BDB01}' = s 'Microsoft Common Language Runtime Host V2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'CLRMetaData.CLRRuntimeHost.1'
            VersionIndependentProgId = s 'CLRMetaData.CLRRuntimeHost'
        }
        '{90F1A06E-7712-4762-86B5-7A5EBA6BDB02}' = s 'Microsoft Common Language Runtime Host V2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'CLRMetaData.CLRRuntimeHost.2'
            VersionIndependentProgId = s 'CLRMetaData.CLRRuntimeHost'
        }
        '{E5CB7A31-7512-11D2-89CE-0080C792E5D8}' = s 'Microsoft Common Language Runtime Meta Data'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'CLRMetaData.CorMetaDataDispenser.2'
            VersionIndependentProgId = s 'CLRMetaData.CorMetaDataDispenser'
        }
        '{1EC2DE53-75CC-11D2-9775-00A0C9B4D50C}' = s 'Microsoft Common Language Runtime Meta Data'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'CLRMetaData.CorMetaDataDispenserRuntime.2'
            VersionIndependentProgId = s 'CLRMetaData.CorMetaDataDispenserRuntime'
        }
        '{CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}' = s 'Microsoft Common Language Runtime Host'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'CLRMetaData.CorRuntimeHost.2'
            VersionIndependentProgId = s 'CLRMetaData.CorRuntimeHost'
        }
    }
    'CLRMetaData.CLRRuntimeHost.1' = s 'Microsoft Common Language Runtime Host V2'
    {
        CLSID = s '{90F1A06E-7712-4762-86B5-7A5EBA6BDB01}'
    }
    'CLRMetaData.CLRRuntimeHost' = s 'Microsoft Common Language Runtime Host V2'
    {
        CLSID = s '{90F1A06E-7712-4762-86B5-7A5EBA6BDB01}'
        CurVer = s 'CLRMetaData.CLRRuntimeHost.1'
    }
    'CLRMetaData.CLRRuntimeHost.2' = s 'Microsoft Common Language Runtime Host V2'
    {
        CLSID = s '{90F1A06E-7712-4762-86B5-7A5EBA6BDB02}'
    }
    'CLRMetaData.CLRRuntimeHost' = s 'Microsoft Common Language Runtime Host V2'
    {
        CLSID = s '{90F1A06E-7712-4762-86B5-7A5EBA6BDB02}'
        CurVer = s 'CLRMetaData.CLRRuntimeHost.2'
    }
    'CLRMetaData.CorMetaDataDispenser.2' = s 'Microsoft Common Language Runtime Meta Data'
    {
        CLSID = s '{E5CB7A31-7512-11D2-89CE-0080C792E5D8}'
    }
    'CLRMetaData.CorMetaDataDispenser' = s 'Microsoft Common Language Runtime Meta Data'
    {
        CLSID = s '{E5CB7A31-7512-11D2-89CE-0080C792E5D8}'
        CurVer = s 'CLRMetaData.CorMetaDataDispenser.2'
    }
    'CLRMetaData.CorMetaDataDispenserRuntime.2' = s 'Microsoft Common Language Runtime Meta Data'
    {
        CLSID = s '{1EC2DE53-75CC-11D2-9775-00A0C9B4D50C}'
    }
    'CLRMetaData.CorMetaDataDispenserRuntime' = s 'Microsoft Common Language Runtime Meta Data'
    {
        CLSID = s '{1EC2DE53-75CC-11D2-9775-00A0C9B4D50C}'
        CurVer = s 'CLRMetaData.CorMetaDataDispenserRuntime.2'
    }
    'CLRMetaData.CorRuntimeHost.2' = s 'Microsoft Common Language Runtime Host'
    {
        CLSID = s '{CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}'
    }
    'CLRMetaData.CorRuntimeHost' = s 'Microsoft Common Language Runtime Host'
    {
        CLSID = s '{CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}'
        CurVer = s 'CLRMetaData.CorRuntimeHost.2'
    }
}
 