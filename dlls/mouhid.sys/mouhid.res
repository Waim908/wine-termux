        ��  ��                  �  <   W I N E _ D A T A _ F I L E   ��       0           [Version]
Signature="$CHICAGO$"
ClassGuid={4d36e97d-e325-11ce-bfc1-08002be10318}
Class=System

[Manufacturer]
Wine=mfg_section

[mfg_section]
HID touch screen device=device_section,HID_DEVICE_UP:000D_U:0004

[device_section.Services]
AddService = mouhid,0x2,svc_section

[svc_section]
Description="Wine HID mouse device driver"
DisplayName="Wine HID mouse"
ServiceBinary="%12%\mouhid.sys"
LoadOrderGroup="WinePlugPlay"
ServiceType=1
StartType=3
ErrorControl=1
