        ��  ��                    8   W I N E _ R E G I S T R Y   ��     0           HKCR
{
    NoRemove PROTOCOLS
    {
        NoRemove Handler
        {
            ForceRemove mhtml = s 'MHTML Asynchronous Pluggable Protocol Handler'
            {
                val CLSID = s '{05300401-bcbc-11d0-85e3-00c04fd85ab4}'
            }
        }
    }
}
  