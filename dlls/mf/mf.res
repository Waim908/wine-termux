        ��  ��                  �  8   W I N E _ R E G I S T R Y   ��     0           HKLM
{
    NoRemove 'Software'
    {
        NoRemove 'Microsoft'
        {
            NoRemove 'Windows Media Foundation'
            {
                NoRemove 'SchemeHandlers'
                {
                    'file:'
                    {
                        val '{477ec299-1421-4bdd-971f-7ccb933f21ad}' = s 'File Scheme Handler'
                    }
                    'http:'
                    {
                        val '{9ec4b4f9-3029-45ad-947b-344de2a249e2}' = s 'Urlmon Scheme Handler'
                    }
                    'https:'
                    {
                        val '{9ec4b4f9-3029-45ad-947b-344de2a249e2}' = s 'Urlmon Scheme Handler'
                    }
                }
            }
        }
    }
}
  