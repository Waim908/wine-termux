        ��  ��                    \   W I N E _ R E G I S T R Y   O L E 3 2 _ O L E I D L _ R _ R E S                     HKCR
{
    NoRemove Interface
    {
        '{00000114-0000-0000-C000-000000000046}' = s 'IOleWindow'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000113-0000-0000-C000-000000000046}' = s 'IOleInPlaceObject'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000115-0000-0000-C000-000000000046}' = s 'IOleInPlaceUIWindow'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000116-0000-0000-C000-000000000046}' = s 'IOleInPlaceFrame'
        {
            NumMethods = s 15
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000117-0000-0000-C000-000000000046}' = s 'IOleInPlaceActiveObject'
        {
            NumMethods = s 10
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000119-0000-0000-C000-000000000046}' = s 'IOleInPlaceSite'
        {
            NumMethods = s 15
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000011A-0000-0000-C000-000000000046}' = s 'IParseDisplayName'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000011B-0000-0000-C000-000000000046}' = s 'IOleContainer'
        {
            NumMethods = s 6
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000011C-0000-0000-C000-000000000046}' = s 'IOleItemContainer'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000011D-0000-0000-C000-000000000046}' = s 'IOleLink'
        {
            NumMethods = s 14
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000118-0000-0000-C000-000000000046}' = s 'IOleClientSite'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000011E-0000-0000-C000-000000000046}' = s 'IOleCache'
        {
            NumMethods = s 8
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000128-0000-0000-C000-000000000046}' = s 'IOleCache2'
        {
            NumMethods = s 10
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000129-0000-0000-C000-000000000046}' = s 'IOleCacheControl'
        {
            NumMethods = s 5
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000104-0000-0000-C000-000000000046}' = s 'IEnumOLEVERB'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000112-0000-0000-C000-000000000046}' = s 'IOleObject'
        {
            NumMethods = s 24
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000012A-0000-0000-C000-000000000046}' = s 'IContinue'
        {
            NumMethods = s 4
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{0000010D-0000-0000-C000-000000000046}' = s 'IViewObject'
        {
            NumMethods = s 9
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000127-0000-0000-C000-000000000046}' = s 'IViewObject2'
        {
            NumMethods = s 10
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
        '{00000122-0000-0000-C000-000000000046}' = s 'IDropTarget'
        {
            NumMethods = s 7
            ProxyStubClsid32 = s '{00000320-0000-0000-C000-000000000046}'
        }
    }
    NoRemove CLSID
    {
        '{00000320-0000-0000-C000-000000000046}' = s 'PSFactoryBuffer'
        {
            InprocServer32 = s '%MODULE%' { val ThreadingModel = s 'Both' }
        }
    }
}
  