        ��  ��                  $  @   ��
 A P P X M A N I F E S T . X M L         0           <?xml version="1.0" encoding="utf-8"?>
<Package xmlns="http://schemas.microsoft.com/appx/manifest/foundation/windows10"
         xmlns:uap="http://schemas.microsoft.com/appx/manifest/uap/windows10"
         xmlns:rescap="http://schemas.microsoft.com/appx/manifest/foundation/windows10/restrictedcapabilities">
    <Identity Name="WineTest" Publisher="CN=Wine, O=The Wine Project, C=US" Version="1.0.0.0" ProcessorArchitecture="neutral" />
    <Properties>
        <DisplayName>WineTest</DisplayName>
        <PublisherDisplayName>The Wine Project</PublisherDisplayName>
        <Description>Reserved</Description>
        <Logo>logo.png</Logo>
    </Properties>
    <Resources>
        <Resource Language="en-us" />
    </Resources>
    <Dependencies>
        <TargetDeviceFamily Name="Windows.Desktop" MinVersion="10.0.0.0" MaxVersionTested="10.0.65535.0" />
    </Dependencies>
    <Capabilities>
        <rescap:Capability Name="runFullTrust" />
    </Capabilities>
    <Applications>
        <Application Id="WineTest" Executable="application.exe" EntryPoint="Windows.FullTrustApplication">
            <uap:VisualElements BackgroundColor="transparent" DisplayName="WineTest" Square150x150Logo="logo.png" Square44x44Logo="logo.png" Description="WineTest" />
        </Application>
    </Applications>
</Package>
