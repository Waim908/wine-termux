        ��  ��                  2  T   W I N E _ R E G I S T R Y   M F S R C S N K _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{7AFA253E-F823-42F6-A5D9-714BDE467412}' = s 'AVI Byte Stream Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{36F99745-23C9-4C9C-8DD5-CC31CE964390}' = s 'MF WAVE Sink Factory'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{42C9B9F5-16FC-47EF-AF22-DA05F7C842E3}' = s 'WAV Byte Stream Handler'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  