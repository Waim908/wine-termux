        ��  ��                  �  <   W I N E _ D A T A _ F I L E   ��       0           [Version]
Signature="$CHICAGO$"
ClassGuid={745a17a0-74d3-11d0-b6fe-00a0c90f57da}
Class=HIDClass

[Manufacturer]
Wine=mfg_section

[mfg_section]
Wine HID compatible device=device_section,WINEBUS\WINE_COMP_HID

[device_section.Services]
AddService = winehid,0x2,svc_section

[svc_section]
Description="Wine HID Minidriver"
DisplayName="Wine HID"
ServiceBinary="%12%\winehid.sys"
LoadOrderGroup="WinePlugPlay"
ServiceType=1
StartType=3
ErrorControl=1
