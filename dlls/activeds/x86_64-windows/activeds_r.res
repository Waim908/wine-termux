        ��  ��                  �  T   W I N E _ R E G I S T R Y   A C T I V E D S _ R _ R E S                     HKCR
{
    NoRemove CLSID
    {
        '{080D0D78-F421-11D0-A36E-00C04FB950DC}' = s 'ADs LDAP Pathname Descriptor Object'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
            ProgId = s 'Pathname'
        }
    }
    'Pathname' = s 'ADs LDAP Pathname Descriptor Object'
    {
        CLSID = s '{080D0D78-F421-11D0-A36E-00C04FB950DC}'
    }
}
   