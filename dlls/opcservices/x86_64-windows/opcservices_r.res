        ��  ��                  �   X   W I N E _ R E G I S T R Y   O P C S E R V I C E S _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{6B2D6BA0-9F3E-4F27-920B-313CC426A39E}' = s 'OpcFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  