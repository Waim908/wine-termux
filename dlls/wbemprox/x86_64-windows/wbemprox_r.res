        ��  ��                  (  T   W I N E _ R E G I S T R Y   W B E M P R O X _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{4590F811-1D3A-11D0-891F-00AA004B2E24}' = s 'WBEM Locator'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{674B6698-EE92-11D0-AD71-00C04FD8FDFF}' = s 'WBEM Call Context'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
        '{CB8555CC-9128-11D1-AD9B-00C04FD8FDFF}' = s 'WBEM Administrative Locator'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
