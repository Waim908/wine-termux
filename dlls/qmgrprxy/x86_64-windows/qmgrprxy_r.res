        ��  ��                  %  T   W I N E _ R E G I S T R Y   Q M G R P R X Y _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{01B7BD23-FB88-4A77-8490-5891D3E4653A}' = s 'IBackgroundCopyFile'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{CA51E165-C365-424C-8D41-24AAA4FF3C40}' = s 'IEnumBackgroundCopyFiles'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{19C613A0-FCB8-4F28-81AE-897C3D078F81}' = s 'IBackgroundCopyError'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{37668D37-507E-4160-9316-26306D150B12}' = s 'IBackgroundCopyJob'
        {
            NumMethods = s 35
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{1AF4F612-3B71-466F-8F58-7B6F73AC57AD}' = s 'IEnumBackgroundCopyJobs'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{97EA99C7-0186-4AD4-8DF9-C5B4E0ED6B22}' = s 'IBackgroundCopyCallback'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}' = s 'IBackgroundCopyManager'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{54B50739-686F-45EB-9DFF-D6A9A0FAA9AF}' = s 'IBackgroundCopyJob2'
        {
            NumMethods = s 43
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{443C8934-90FF-48ED-BCDE-26F5C7450042}' = s 'IBackgroundCopyJob3'
        {
            NumMethods = s 47
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{83E81B93-0873-474D-8A8C-F2018B1A939C}' = s 'IBackgroundCopyFile2'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{F1BD1079-9F01-4BDC-8036-F09B70095066}' = s 'IBackgroundCopyJobHttpOptions'
        {
            NumMethods = s 11
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{659CDEAC-489E-11D9-A9CD-000D56965251}' = s 'IBackgroundCopyCallback2'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
        '{659CDEAE-489E-11D9-A9CD-000D56965251}' = s 'IBackgroundCopyJob4'
        {
            NumMethods = s 53
            ProxyStubClsid32 = s '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}'
        }
    }
    NoRemove CLSID
    {
        '{5CE34C0D-0DC9-4C1F-897C-DAA1B78CEE7C}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   