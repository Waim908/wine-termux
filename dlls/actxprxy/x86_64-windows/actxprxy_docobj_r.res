        ��  ��                  A  `   W I N E _ R E G I S T R Y   A C T X P R X Y _ D O C O B J _ R _ R E S                   HKCR
{
    NoRemove Interface
    {
        '{B722BCC5-4E68-101B-A2BC-00AA00404770}' = s 'IOleDocument'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCC7-4E68-101B-A2BC-00AA00404770}' = s 'IOleDocumentSite'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCC6-4E68-101B-A2BC-00AA00404770}' = s 'IOleDocumentView'
        {
            NumMethods = s 16
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCC8-4E68-101B-A2BC-00AA00404770}' = s 'IEnumOleDocumentViews'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCCB-4E68-101B-A2BC-00AA00404770}' = s 'IOleCommandTarget'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCCA-4E68-101B-A2BC-00AA00404770}' = s 'IContinueCallback'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
        '{B722BCC9-4E68-101B-A2BC-00AA00404770}' = s 'IPrint'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}'
        }
    }
    NoRemove CLSID
    {
        '{B8DA6310-E19B-11D0-933C-00A0C90DCAA9}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
   