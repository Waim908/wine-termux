        ��  ��                  W  8   W I N E _ R E G I S T R Y   ��     0           HKCR
{
    NoRemove AppID
    {
        '{A1F4E726-8CF1-11D1-BF92-0060081ED811}' = s 'WIA Device Manager'
        {
            val LocalService = s 'stisvc'
        }
    }
    NoRemove CLSID
    {
        '{A1F4E726-8CF1-11D1-BF92-0060081ED811}'
        {
            val AppID = s '{A1F4E726-8CF1-11D1-BF92-0060081ED811}'
        }
    }
}
 