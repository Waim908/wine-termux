        ��  ��                  �  <   W I N E _ D A T A _ F I L E   ��       0           [Version]
Signature="$CHICAGO$"
ClassGuid={4d36e97d-e325-11ce-bfc1-08002be10318}
Class=System

[Manufacturer]
Wine=mfg_section

[mfg_section]
Wine HID bus driver=device_section,root\winebus

[device_section.Services]
AddService = winebus,0x2,svc_section

[svc_section]
Description="Wine HID bus driver"
DisplayName="Wine HID bus"
ServiceBinary="%12%\winebus.sys"
LoadOrderGroup="WinePlugPlay"
ServiceType=1
StartType=3
ErrorControl=1
  