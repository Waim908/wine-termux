        ��  ��                  �  \   W I N E _ R E G I S T R Y   E X P L O R E R F R A M E _ R _ R E S                   HKCR
{
    NoRemove CLSID
    {
        '{AE054212-3535-4430-83ED-D501AA6680E6}' = s 'Shell Name Space ListView'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
        '{56FDF344-FD6D-11D0-958A-006097C9A090}' = s 'Task Bar Communication'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Apartment' }
        }
    }
}
   