        ��  ��                  �
  X   W I N E _ R E G I S T R Y   R O W _ S E R V E R _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{38248178-CF6D-11DE-ABE5-000C2916D865}' = s 'IWineRowServer'
        {
            NumMethods = s 25
            ProxyStubClsid32 = s '{06210E88-01F5-11D1-B512-0080C781C384}'
        }
    }
    NoRemove CLSID
    {
        '{06210E88-01F5-11D1-B512-0080C781C384}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{38248178-CF6D-11DE-ABE5-000C2916D865}' = s 'Wine OLE DB Row Server'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'WINEDBROWPRX.AsServer.1'
            VersionIndependentProgId = s 'WINEDBROWPRX.AsServer'
        }
        '{38248179-CF6D-11DE-ABE5-000C2916D865}' = s 'Wine OLE DB Row Proxy'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'WINEDBROWPRX.AsProxy.1'
            VersionIndependentProgId = s 'WINEDBROWPRX.AsProxy'
        }
        '{3824817A-CF6D-11DE-ABE5-000C2916D865}' = s 'Wine OLE DB Rowset Server'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'WINEDBRSTPRX.AsServer.1'
            VersionIndependentProgId = s 'WINEDBRSTPRX.AsServer'
        }
        '{3824817B-CF6D-11DE-ABE5-000C2916D865}' = s 'Wine OLE DB Rowset Proxy'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'WINEDBRSTPRX.AsProxy.1'
            VersionIndependentProgId = s 'WINEDBRSTPRX.AsProxy'
        }
    }
    'WINEDBROWPRX.AsServer.1' = s 'Wine OLE DB Row Server'
    {
        CLSID = s '{38248178-CF6D-11DE-ABE5-000C2916D865}'
    }
    'WINEDBROWPRX.AsServer' = s 'Wine OLE DB Row Server'
    {
        CLSID = s '{38248178-CF6D-11DE-ABE5-000C2916D865}'
        CurVer = s 'WINEDBROWPRX.AsServer.1'
    }
    'WINEDBROWPRX.AsProxy.1' = s 'Wine OLE DB Row Proxy'
    {
        CLSID = s '{38248179-CF6D-11DE-ABE5-000C2916D865}'
    }
    'WINEDBROWPRX.AsProxy' = s 'Wine OLE DB Row Proxy'
    {
        CLSID = s '{38248179-CF6D-11DE-ABE5-000C2916D865}'
        CurVer = s 'WINEDBROWPRX.AsProxy.1'
    }
    'WINEDBRSTPRX.AsServer.1' = s 'Wine OLE DB Rowset Server'
    {
        CLSID = s '{3824817A-CF6D-11DE-ABE5-000C2916D865}'
    }
    'WINEDBRSTPRX.AsServer' = s 'Wine OLE DB Rowset Server'
    {
        CLSID = s '{3824817A-CF6D-11DE-ABE5-000C2916D865}'
        CurVer = s 'WINEDBRSTPRX.AsServer.1'
    }
    'WINEDBRSTPRX.AsProxy.1' = s 'Wine OLE DB Rowset Proxy'
    {
        CLSID = s '{3824817B-CF6D-11DE-ABE5-000C2916D865}'
    }
    'WINEDBRSTPRX.AsProxy' = s 'Wine OLE DB Rowset Proxy'
    {
        CLSID = s '{3824817B-CF6D-11DE-ABE5-000C2916D865}'
        CurVer = s 'WINEDBRSTPRX.AsProxy.1'
    }
}
  