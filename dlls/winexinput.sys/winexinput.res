        ��  ��                  �  <   W I N E _ D A T A _ F I L E   ��       0           [Version]
Signature="$CHICAGO$"
ClassGuid={4d36e97d-e325-11ce-bfc1-08002be10318}
Class=System

[Manufacturer]
Wine=mfg_section

[mfg_section]
Wine XInput compatible device=device_section,WINEBUS\WINE_COMP_XINPUT

[device_section.Services]
AddService = xinput,0x2,svc_section

[svc_section]
Description="Wine XInput device driver"
DisplayName="Wine XInput"
ServiceBinary="%12%\winexinput.sys"
LoadOrderGroup="WinePlugPlay"
ServiceType=1
StartType=3
ErrorControl=1
 