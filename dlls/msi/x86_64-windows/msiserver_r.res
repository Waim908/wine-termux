        ��  ��                  =	  T   W I N E _ R E G I S T R Y   M S I S E R V E R _ R _ R E S                   HKCR
{
    NoRemove Interface
    {
        '{000C101C-0000-0000-C000-000000000046}' = s 'IMsiServer'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{000C103E-0000-0000-C000-000000000046}'
        }
        '{000C101D-0000-0000-C000-000000000046}' = s 'IMsiMessage'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{000C103E-0000-0000-C000-000000000046}'
        }
        '{000C1025-0000-0000-C000-000000000046}' = s 'IMsiCustomAction'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{000C103E-0000-0000-C000-000000000046}'
        }
        '{000C1033-0000-0000-C000-000000000046}' = s 'IMsiRemoteAPI'
        {
            NumMethods = s 3
            ProxyStubClsid32 = s '{000C103E-0000-0000-C000-000000000046}'
        }
    }
    NoRemove CLSID
    {
        '{000C101C-0000-0000-C000-000000000046}' = s 'Msi install server'
        {
            ProgId = s 'IMsiServer'
        }
        '{000C101D-0000-0000-C000-000000000046}' = s 'Microsoft Windows Installer Message RPC'
        {
            ProgId = s 'WindowsInstaller.Message'
        }
        '{000C103E-0000-0000-C000-000000000046}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{000C1090-0000-0000-C000-000000000046}' = s 'Microsoft Windows Installer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
            ProgId = s 'WindowsInstaller.Installer'
        }
        '{000C1082-0000-0000-C000-000000000046}' = s 'MsiTransform'
        {
        }
        '{000C1084-0000-0000-C000-000000000046}' = s 'MsiDatabase'
        {
        }
        '{000C1086-0000-0000-C000-000000000046}' = s 'MsiPatch'
        {
        }
        '{000C1094-0000-0000-C000-000000000046}' = s 'MsiServerX3'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
    'IMsiServer' = s 'Msi install server'
    {
        CLSID = s '{000C101C-0000-0000-C000-000000000046}'
    }
    'WindowsInstaller.Message' = s 'Microsoft Windows Installer Message RPC'
    {
        CLSID = s '{000C101D-0000-0000-C000-000000000046}'
    }
    'WindowsInstaller.Installer' = s 'Microsoft Windows Installer'
    {
        CLSID = s '{000C1090-0000-0000-C000-000000000046}'
    }
}
   