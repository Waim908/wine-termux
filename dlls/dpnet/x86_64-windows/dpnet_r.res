        ��  ��                  �  L   W I N E _ R E G I S T R Y   D P N E T _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{743F1DC6-5ABA-429F-8BDF-C54D03253DC2}' = s 'DirectPlay8Client Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{DA825E1B-6830-43D7-835D-0B5AD82956A2}' = s 'DirectPlay8Server Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{286F484D-375E-4458-A272-B138E2F80A6A}' = s 'DirectPlay8Peer Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{934A9523-A3CA-4BC5-ADA0-D6D95D979421}' = s 'DirectPlay8Address Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{667955AD-6B3B-43CA-B949-BC69B5BAFF7F}' = s 'DirectPlay8LobbiedApplication Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{3B2B6775-70B6-45AF-8DEA-A209C69559F3}' = s 'DirectPlay8LobbyClient Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'DirectPlay8Lobby.LobbyClient.1'
            VersionIndependentProgId = s 'DirectPlay8Lobby.LobbyClient'
        }
        '{FC47060E-6153-4B34-B975-8E4121EB7F3C}' = s 'DirectPlay8 Thread Pool Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
    'DirectPlay8Lobby.LobbyClient.1' = s 'DirectPlay8LobbyClient Object'
    {
        CLSID = s '{3B2B6775-70B6-45AF-8DEA-A209C69559F3}'
    }
    'DirectPlay8Lobby.LobbyClient' = s 'DirectPlay8LobbyClient Object'
    {
        CLSID = s '{3B2B6775-70B6-45AF-8DEA-A209C69559F3}'
        CurVer = s 'DirectPlay8Lobby.LobbyClient.1'
    }
}
