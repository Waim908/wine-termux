        ��  ��                  '  X   W I N E _ R E G I S T R Y   E V R _ C L A S S E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{FA10746C-9B63-4B6C-BC49-FC300EA5F256}' = s 'Enhanced Video Renderer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{E474E05A-AB65-4F6A-827C-218B1BAAF31F}' = s 'MF Video Mixer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{98455561-5136-4D28-AB08-4CEE40EA2781}' = s 'MF Video Presenter'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
 