        ��  ��                    8   W I N E _ R E G I S T R Y   ��     0           HKLM
{
    NoRemove Software
    {
        NoRemove Microsoft
        {
            NoRemove ADs
            {
                NoRemove Providers
                {
                    ForceRemove 'LDAP' = s 'LDAPNamespace'
                }
            }
        }
    }
}
   