        ��  ��                  �  <   W I N E _ D A T A _ F I L E   ��       0           [Version]
Signature="$CHICAGO$"
ClassGuid={4d36e97d-e325-11ce-bfc1-08002be10318}
Class=System

[Manufacturer]
Wine=mfg_section

[mfg_section]
Wine USB bus driver=device_section,root\wineusb

[device_section.Services]
AddService = wineusb,0x2,svc_section

[svc_section]
Description="Wine USB bus driver"
DisplayName="Wine USB bus"
ServiceBinary="%12%\wineusb.sys"
LoadOrderGroup="WinePlugPlay"
ServiceType=1
StartType=3
ErrorControl=1
  