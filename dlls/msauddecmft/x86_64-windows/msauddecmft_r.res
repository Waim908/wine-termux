        ��  ��                  �   X   W I N E _ R E G I S T R Y   M S A U D D E C M F T _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{32D186A7-218F-4C75-8876-DD77273A8999}' = s 'CMSAACDecMFT'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
