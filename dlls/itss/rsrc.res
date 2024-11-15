        ��  ��                  �  8   W I N E _ R E G I S T R Y   ��     0           HKCR
{
    ForceRemove '.its' = s 'ITS File'
    ForceRemove 'ITS FILE' = s 'Internet Document Set'
    {
        DefaultIcon = s '%MODULE%,0'
    }
    ForceRemove MSITStore = s 'Microsoft InfoTech Protocol for IE 3.0'
    {
        CLSID = s '{9D148290-B9C8-11D0-A4CC-0000F80149F6}'
        CurVer = s 'MSITStore1.0'
    }
    ForceRemove ITSProtocol = s 'Microsoft InfoTech Protocols for IE 4.0'
    {
        CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}'
        CurVer = s 'ITSProtocol1.0'
    }
    ForceRemove MSFSStore = s 'Microsoft InfoTech IStorage for Win32 Files'
    {
        CLSID = s '{D54EEE56-AAAB-11D0-9E1D-00A0C922E6EC}'
        CurVer = s 'MSFSStore1.0'
    }
    NoRemove PROTOCOLS
    {
        NoRemove Handler
        {
            ForceRemove its = s 'its: Asychronous Pluggable Protocol Handler'
            {
                val CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}'
            }
            ForceRemove ms-its = s 'ms-its: Asychronous Pluggable Protocol Handler'
            {
                val CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}'
            }
        }
        NoRemove 'Name-Space Handler'
        {
            ForceRemove mk = s 'NameSpace Filter for MK:@MSITStore:...'
            {
                '*' { val CLSID = s '{9D148291-B9C8-11D0-A4CC-0000F80149F6}' }
            }
        }
    }
    NoRemove CLSID
    {
        '{5D02926A-212E-11D0-9DF9-00A0C922E6EC}' { NotInsertable }
        '{9D148290-B9C8-11D0-A4CC-0000F80149F6}' { NotInsertable }
        '{9D148291-B9C8-11D0-A4CC-0000F80149F6}' { NotInsertable }
        '{D54EEE56-AAAB-11D0-9E1D-00A0C922E6EC}' { NotInsertable }
    }
}
   