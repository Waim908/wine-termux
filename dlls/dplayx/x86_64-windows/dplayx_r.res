        ��  ��                    P   W I N E _ R E G I S T R Y   D P L A Y X _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{D1EB6D20-8923-11D0-9D97-00A0C90A43CB}' = s 'DirectPlay Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{2FE8F810-B2A5-11D0-A787-0000F803ABFC}' = s 'DirectPlayLobby Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 