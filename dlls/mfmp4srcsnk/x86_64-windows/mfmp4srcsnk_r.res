        ��  ��                  9  X   W I N E _ R E G I S T R Y   M F M P 4 S R C S N K _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{271C3902-6095-4C45-A22F-20091816EE9E}' = s 'MPEG4 Byte Stream Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{11275A82-5E5A-47FD-A01C-3683C12FB196}' = s 'MFMP3SinkClassFactory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{A22C4FC7-6E91-4E1D-89E9-53B2667B72BA}' = s 'MF MPEG4 Sink Class Factory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   