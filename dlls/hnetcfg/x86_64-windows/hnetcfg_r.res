        ��  ��                  Y	  P   W I N E _ R E G I S T R Y   H N E T C F G _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{304CE942-6E39-40D8-943A-B913C40C9CD4}' = s 'HNetCfg.FwMgr'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwMgr'
        }
        '{EC9846B3-2762-4A6B-A214-6ACB603462D2}' = s 'HNetCfg.FwAuthorizedApplication'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwAuthorizedApplication'
        }
        '{0CA545C6-37AD-4A6C-BF92-9F7610067EF5}' = s 'HNetCfg.FwOpenPort'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwOpenPort'
        }
        '{E2B3C97F-6AE1-41AC-817A-F6F92166D7DD}' = s 'HNetCfg.FwPolicy2'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwPolicy2'
        }
        '{2C5BC43E-3369-4C33-AB0C-BE9469677AF4}' = s 'HNetCfg.FwRule'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwRule'
        }
        '{9D745ED8-C514-4D1D-BF42-751FED2D5AC7}' = s 'HNetCfg.FwProduct'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwProduct'
        }
        '{CC19079B-8272-4D73-BB70-CDB533527B61}' = s 'HNetCfg.FwProducts'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'HNetCfg.FwProducts'
        }
    }
    'HNetCfg.FwMgr' = s 'HNetCfg.FwMgr'
    {
        CLSID = s '{304CE942-6E39-40D8-943A-B913C40C9CD4}'
    }
    'HNetCfg.FwAuthorizedApplication' = s 'HNetCfg.FwAuthorizedApplication'
    {
        CLSID = s '{EC9846B3-2762-4A6B-A214-6ACB603462D2}'
    }
    'HNetCfg.FwOpenPort' = s 'HNetCfg.FwOpenPort'
    {
        CLSID = s '{0CA545C6-37AD-4A6C-BF92-9F7610067EF5}'
    }
    'HNetCfg.FwPolicy2' = s 'HNetCfg.FwPolicy2'
    {
        CLSID = s '{E2B3C97F-6AE1-41AC-817A-F6F92166D7DD}'
    }
    'HNetCfg.FwRule' = s 'HNetCfg.FwRule'
    {
        CLSID = s '{2C5BC43E-3369-4C33-AB0C-BE9469677AF4}'
    }
    'HNetCfg.FwProduct' = s 'HNetCfg.FwProduct'
    {
        CLSID = s '{9D745ED8-C514-4D1D-BF42-751FED2D5AC7}'
    }
    'HNetCfg.FwProducts' = s 'HNetCfg.FwProducts'
    {
        CLSID = s '{CC19079B-8272-4D73-BB70-CDB533527B61}'
    }
}
   