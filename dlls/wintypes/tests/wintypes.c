/*
 * Copyright 2022 Zhiyi Zhang for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#define COBJMACROS
#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "winerror.h"
#include "winstring.h"

#include "initguid.h"
#include "roapi.h"
#include "rometadataresolution.h"

#define WIDL_using_Windows_Foundation
#define WIDL_using_Windows_Foundation_Metadata
#include "windows.foundation.metadata.h"
#include "wintypes_test.h"

#include "wine/test.h"

static BOOL is_wow64;

static void test_IApiInformationStatics(void)
{
    static const struct
    {
        const WCHAR *name;
        unsigned int max_major;
    }
    present_contracts[] =
    {
        { L"Windows.Foundation.UniversalApiContract", 10, },
    };

    static const WCHAR *class_name = L"Windows.Foundation.Metadata.ApiInformation";
    IAgileObject *agile_object = NULL, *tmp_agile_object = NULL;
    IInspectable *inspectable = NULL, *tmp_inspectable = NULL;
    IApiInformationStatics *statics = NULL;
    IActivationFactory *factory = NULL;
    HSTRING str, str2;
    unsigned int i, j;
    BOOLEAN ret;
    HRESULT hr;

    hr = RoInitialize(RO_INIT_MULTITHREADED);
    ok(hr == S_OK, "RoInitialize failed, hr %#lx.\n", hr);

    hr = WindowsCreateString(class_name, wcslen(class_name), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = RoGetActivationFactory(str, &IID_IActivationFactory, (void **)&factory);
    ok(hr == S_OK || broken(hr == REGDB_E_CLASSNOTREG), "RoGetActivationFactory failed, hr %#lx.\n", hr);
    WindowsDeleteString(str);
    if (hr == REGDB_E_CLASSNOTREG)
    {
        win_skip("%s runtimeclass not registered, skipping tests.\n", wine_dbgstr_w(class_name));
        RoUninitialize();
        return;
    }

    hr = IActivationFactory_QueryInterface(factory, &IID_IInspectable, (void **)&inspectable);
    ok(hr == S_OK, "QueryInterface IID_IInspectable failed, hr %#lx.\n", hr);

    hr = IActivationFactory_QueryInterface(factory, &IID_IAgileObject, (void **)&agile_object);
    ok(hr == S_OK, "QueryInterface IID_IAgileObject failed, hr %#lx.\n", hr);

    hr = IActivationFactory_QueryInterface(factory, &IID_IApiInformationStatics, (void **)&statics);
    ok(hr == S_OK, "QueryInterface IID_IApiInformationStatics failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_QueryInterface(statics, &IID_IInspectable, (void **)&tmp_inspectable);
    ok(hr == S_OK, "QueryInterface IID_IInspectable failed, hr %#lx.\n", hr);
    ok(tmp_inspectable == inspectable, "QueryInterface IID_IInspectable returned %p, expected %p.\n",
            tmp_inspectable, inspectable);
    IInspectable_Release(tmp_inspectable);

    hr = IApiInformationStatics_QueryInterface(statics, &IID_IAgileObject, (void **)&tmp_agile_object);
    ok(hr == S_OK, "QueryInterface IID_IAgileObject failed, hr %#lx.\n", hr);
    ok(tmp_agile_object == agile_object, "QueryInterface IID_IAgileObject returned %p, expected %p.\n",
            tmp_agile_object, agile_object);
    IAgileObject_Release(tmp_agile_object);

    /* IsTypePresent() */
    hr = WindowsCreateString(L"Windows.Foundation.FoundationContract",
            wcslen(L"Windows.Foundation.FoundationContract"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsTypePresent(statics, NULL, &ret);
    ok(hr == E_INVALIDARG, "IsTypePresent failed, hr %#lx.\n", hr);

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsTypePresent(statics, str, NULL);
    ok(hr == E_INVALIDARG, "IsTypePresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsTypePresent(statics, str, &ret);
    todo_wine
    ok(hr == S_OK, "IsTypePresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsTypePresent returned FALSE.\n");

    WindowsDeleteString(str);

    /* IsMethodPresent() */
    hr = WindowsCreateString(L"Windows.Foundation.Metadata.IApiInformationStatics",
            wcslen(L"Windows.Foundation.Metadata.IApiInformationStatics"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"IsTypePresent", wcslen(L"IsTypePresent"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsMethodPresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsMethodPresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsMethodPresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsMethodPresent returned TRUE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsMethodPresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsMethodPresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsMethodPresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsMethodPresent returned FALSE.\n");

    /* IsMethodPresentWithArity() */
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, NULL, str2, 1, &ret);
    ok(hr == E_INVALIDARG, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, str, NULL, 1, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsMethodPresentWithArity returned FALSE.\n");

    ret = TRUE;
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, str, str2, 0, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsMethodPresentWithArity returned FALSE.\n");

    ret = TRUE;
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, str, str2, 2, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsMethodPresentWithArity returned FALSE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, str, str2, 1, NULL);
    ok(hr == E_INVALIDARG, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsMethodPresentWithArity(statics, str, str2, 1, &ret);
    todo_wine
    ok(hr == S_OK, "IsMethodPresentWithArity failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsMethodPresentWithArity returned FALSE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsEventPresent() */
    hr = WindowsCreateString(L"Windows.Devices.Enumeration.IDeviceWatcher",
            wcslen(L"Windows.Devices.Enumeration.IDeviceWatcher"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"Added", wcslen(L"Added"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsEventPresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsEventPresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsEventPresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsEventPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsEventPresent returned FALSE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsEventPresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsEventPresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsEventPresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsEventPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsEventPresent returned FALSE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsPropertyPresent() */
    hr = WindowsCreateString(L"Windows.Devices.Enumeration.IDeviceWatcher",
            wcslen(L"Windows.Devices.Enumeration.IDeviceWatcher"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"Status", wcslen(L"Status"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsPropertyPresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsPropertyPresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsPropertyPresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsPropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsPropertyPresent returned TRUE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsPropertyPresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsPropertyPresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsPropertyPresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsPropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsPropertyPresent returned FALSE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsReadOnlyPropertyPresent() */
    hr = WindowsCreateString(L"Windows.Devices.Enumeration.IDeviceWatcher",
            wcslen(L"Windows.Devices.Enumeration.IDeviceWatcher"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"Id", wcslen(L"Id"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsReadOnlyPropertyPresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsReadOnlyPropertyPresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsReadOnlyPropertyPresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsReadOnlyPropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsReadOnlyPropertyPresent returned TRUE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsReadOnlyPropertyPresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsReadOnlyPropertyPresent failed, hr %#lx.\n", hr);
    }

    ret = TRUE;
    hr = IApiInformationStatics_IsReadOnlyPropertyPresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsReadOnlyPropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsReadOnlyPropertyPresent returned TRUE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsWriteablePropertyPresent() */
    hr = WindowsCreateString(L"Windows.Gaming.Input.ForceFeedback.IForceFeedbackEffect",
            wcslen(L"Windows.Gaming.Input.ForceFeedback.IForceFeedbackEffect"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"Gain", wcslen(L"Gain"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsWriteablePropertyPresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsWriteablePropertyPresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsWriteablePropertyPresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsWriteablePropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsWriteablePropertyPresent returned TRUE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsWriteablePropertyPresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsWriteablePropertyPresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsWriteablePropertyPresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsWriteablePropertyPresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE || broken(ret == FALSE) /* Win10 1507 */,
            "IsWriteablePropertyPresent returned FALSE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsEnumNamedValuePresent */
    hr = WindowsCreateString(L"Windows.Foundation.Metadata.GCPressureAmount",
            wcslen(L"Windows.Foundation.Metadata.GCPressureAmount"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
    hr = WindowsCreateString(L"Low", wcslen(L"Low"), &str2);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsEnumNamedValuePresent(statics, NULL, str2, &ret);
    ok(hr == E_INVALIDARG, "IsEnumNamedValuePresent failed, hr %#lx.\n", hr);

    ret = TRUE;
    hr = IApiInformationStatics_IsEnumNamedValuePresent(statics, str, NULL, &ret);
    todo_wine
    ok(hr == S_OK, "IsEnumNamedValuePresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsEnumNamedValuePresent returned TRUE.\n");

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsEnumNamedValuePresent(statics, str, str2, NULL);
    ok(hr == E_INVALIDARG, "IsEnumNamedValuePresent failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsEnumNamedValuePresent(statics, str, str2, &ret);
    todo_wine
    ok(hr == S_OK, "IsEnumNamedValuePresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsEnumNamedValuePresent returned FALSE.\n");

    ret = TRUE;
    hr = IApiInformationStatics_IsEnumNamedValuePresent(statics, str, str, &ret);
    todo_wine
    ok(hr == S_OK, "IsEnumNamedValuePresent failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsEnumNamedValuePresent returned TRUE.\n");

    WindowsDeleteString(str2);
    WindowsDeleteString(str);

    /* IsApiContractPresentByMajor */
    hr = WindowsCreateString(L"Windows.Foundation.FoundationContract",
            wcslen(L"Windows.Foundation.FoundationContract"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, NULL, 1, &ret);
    ok(hr == E_INVALIDARG, "IsApiContractPresentByMajor failed, hr %#lx.\n", hr);

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, str, 1, NULL);
    ok(hr == E_INVALIDARG, "IsApiContractPresentByMajor failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, str, 1, &ret);
    ok(hr == S_OK, "IsApiContractPresentByMajor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsApiContractPresentByMajor returned FALSE.\n");

    ret = FALSE;
    hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, str, 0, &ret);
    ok(hr == S_OK, "IsApiContractPresentByMajor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsApiContractPresentByMajor returned FALSE.\n");

    ret = TRUE;
    hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, str, 999, &ret);
    ok(hr == S_OK, "IsApiContractPresentByMajor failed, hr %#lx.\n", hr);
    ok(ret == FALSE, "IsApiContractPresentByMajor returned TRUE.\n");

    WindowsDeleteString(str);

    /* IsApiContractPresentByMajorAndMinor */
    hr = WindowsCreateString(L"Windows.Foundation.FoundationContract",
            wcslen(L"Windows.Foundation.FoundationContract"), &str);
    ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);

    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, NULL, 1, 0, &ret);
    ok(hr == E_INVALIDARG, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);

    if (0) /* Crash on Windows */
    {
    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, str, 1, 0, NULL);
    ok(hr == E_INVALIDARG, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);
    }

    ret = FALSE;
    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, str, 1, 0, &ret);
    todo_wine
    ok(hr == S_OK, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsApiContractPresentByMajorAndMinor returned FALSE.\n");

    ret = FALSE;
    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, str, 0, 999, &ret);
    todo_wine
    ok(hr == S_OK, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE, "IsApiContractPresentByMajorAndMinor returned FALSE.\n");

    ret = FALSE;
    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, str, 1, 999, &ret);
    todo_wine
    ok(hr == S_OK, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == TRUE || broken(ret == FALSE) /* Win10 1507 */,
            "IsApiContractPresentByMajorAndMinor returned FALSE.\n");

    ret = TRUE;
    hr = IApiInformationStatics_IsApiContractPresentByMajorAndMinor(statics, str, 999, 999, &ret);
    todo_wine
    ok(hr == S_OK, "IsApiContractPresentByMajorAndMinor failed, hr %#lx.\n", hr);
    todo_wine
    ok(ret == FALSE, "IsApiContractPresentByMajorAndMinor returned TRUE.\n");

    WindowsDeleteString(str);

    /* Test API contracts presence. */
    for (i = 0; i < ARRAY_SIZE(present_contracts); ++i)
    {
        hr = WindowsCreateString(present_contracts[i].name, wcslen(present_contracts[i].name), &str);
        ok(hr == S_OK, "WindowsCreateString failed, hr %#lx.\n", hr);
        for (j = 0; j <= present_contracts[i].max_major; ++j)
        {
            ret = FALSE;
            hr = IApiInformationStatics_IsApiContractPresentByMajor(statics, str, i, &ret);
            ok(hr == S_OK, "IsApiContractPresentByMajor failed, hr %#lx, i %u, major %u.\n", hr, i, j);
            ok(ret == TRUE, "IsApiContractPresentByMajor returned FALSE, i %u, major %u.\n", i, j);
        }
        WindowsDeleteString(str);
    }

    IApiInformationStatics_Release(statics);
    IAgileObject_Release(agile_object);
    IInspectable_Release(inspectable);
    IActivationFactory_Release(factory);
    RoUninitialize();
}

static void test_IPropertyValueStatics(void)
{
    static const WCHAR *class_name = L"Windows.Foundation.PropertyValue";
    static const BYTE byte_value = 0x12;
    static const INT16 int16_value = 0x1234;
    static const UINT16 uint16_value = 0x1234;
    static const INT32 int32_value= 0x1234abcd;
    static const UINT32 uint32_value = 0x1234abcd;
    static const INT64 int64_value = 0x12345678abcdef;
    static const UINT64 uint64_value = 0x12345678abcdef;
    static const FLOAT float_value = 1.5;
    static const DOUBLE double_value = 1.5;
    static const WCHAR wchar_value = 0x1234;
    static const boolean boolean_value = TRUE;
    static const struct DateTime datetime_value = {0x12345678abcdef};
    static const struct TimeSpan timespan_value = {0x12345678abcdef};
    static const struct Point point_value = {1, 2};
    static const struct Size size_value = {1, 2};
    static const struct Rect rect_value = {1, 2, 3, 4};
    IAgileObject *agile_object = NULL, *tmp_agile_object = NULL;
    IInspectable *inspectable = NULL, *tmp_inspectable = NULL;
    IPropertyValueStatics *statics = NULL;
    IActivationFactory *factory = NULL;
    IReference_boolean *iref_boolean;
    IReference_HSTRING *iref_hstring;
    IReference_DOUBLE *iref_double;
    IPropertyValue *value = NULL;
    enum PropertyType type;
    unsigned int i, count;
    BYTE byte, *ptr_byte;
    HSTRING str, ret_str;
    DOUBLE ret_double;
    boolean ret;
    HRESULT hr;

    hr = RoInitialize(RO_INIT_MULTITHREADED);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = WindowsCreateString(class_name, wcslen(class_name), &str);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    hr = RoGetActivationFactory(str, &IID_IActivationFactory, (void **)&factory);
    ok(hr == S_OK || broken(hr == REGDB_E_CLASSNOTREG), "RoGetActivationFactory failed, hr %#lx.\n", hr);
    if (hr == REGDB_E_CLASSNOTREG)
    {
        win_skip("%s runtimeclass not registered, skipping tests.\n", wine_dbgstr_w(class_name));
        WindowsDeleteString(str);
        RoUninitialize();
        return;
    }

    hr = IActivationFactory_QueryInterface(factory, &IID_IInspectable, (void **)&inspectable);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = IActivationFactory_QueryInterface(factory, &IID_IAgileObject, (void **)&agile_object);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = IActivationFactory_QueryInterface(factory, &IID_IPropertyValueStatics, (void **)&statics);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValueStatics_QueryInterface(statics, &IID_IInspectable, (void **)&tmp_inspectable);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    ok(tmp_inspectable == inspectable, "QueryInterface IID_IInspectable returned %p, expected %p.\n",
            tmp_inspectable, inspectable);
    IInspectable_Release(tmp_inspectable);
    IInspectable_Release(inspectable);

    hr = IPropertyValueStatics_QueryInterface(statics, &IID_IAgileObject, (void **)&tmp_agile_object);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    ok(tmp_agile_object == agile_object, "QueryInterface IID_IAgileObject returned %p, expected %p.\n",
            tmp_agile_object, agile_object);
    IAgileObject_Release(tmp_agile_object);
    IAgileObject_Release(agile_object);

    /* Parameter checks */
    hr = IPropertyValueStatics_CreateUInt8(statics, 0x12, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValueStatics_CreateUInt8(statics, 0x12, &inspectable);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = IInspectable_QueryInterface(inspectable, &IID_IPropertyValue, (void **)&value);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    ok(value == (IPropertyValue *)inspectable, "Expected the same pointer.\n");
    IInspectable_Release(inspectable);

    hr = IPropertyValue_get_Type(value, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetBoolean(value, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetBoolean(value, &ret);
    ok(hr == TYPE_E_TYPEMISMATCH, "Got unexpected hr %#lx.\n", hr);

    IPropertyValue_Release(value);

    /* Parameter checks for array types */
    hr = IPropertyValueStatics_CreateUInt8Array(statics, 1, NULL, &inspectable);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValueStatics_CreateUInt8Array(statics, 1, &byte, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValueStatics_CreateUInt8Array(statics, 1, &byte, &inspectable);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    hr = IInspectable_QueryInterface(inspectable, &IID_IPropertyValue, (void **)&value);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    ok(value == (IPropertyValue *)inspectable, "Expected the same pointer.\n");
    IInspectable_Release(inspectable);

    hr = IPropertyValue_get_Type(value, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetBoolean(value, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetBoolean(value, &ret);
    ok(hr == TYPE_E_TYPEMISMATCH, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetUInt8Array(value, NULL, &ptr_byte);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetUInt8Array(value, &count, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    hr = IPropertyValue_GetUInt8Array(value, &count, &ptr_byte);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);

    IPropertyValue_Release(value);

    /* PropertyType_Empty */
    hr = IPropertyValueStatics_CreateEmpty(statics, NULL);
    ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);

    inspectable = (IInspectable *)0xdeadbeef;
    hr = IPropertyValueStatics_CreateEmpty(statics, &inspectable);
    ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);
    ok(inspectable == NULL, "Got unexpected inspectable.\n");

    /* Test a single property value */
#define TEST_PROPERTY_VALUE(PROPERTY_TYPE, TYPE, VALUE)                                      \
    do                                                                                       \
    {                                                                                        \
        TYPE expected_value;                                                                 \
                                                                                             \
        inspectable = NULL;                                                                  \
        hr = IPropertyValueStatics_Create##PROPERTY_TYPE(statics, VALUE, &inspectable);      \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(inspectable != NULL, "Got unexpected inspectable.\n");                            \
                                                                                             \
        hr = IInspectable_QueryInterface(inspectable, &IID_IPropertyValue, (void **)&value); \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        IInspectable_Release(inspectable);                                                   \
                                                                                             \
        hr = IPropertyValue_get_Type(value, &type);                                          \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(type == PropertyType_##PROPERTY_TYPE, "Got unexpected type %d.\n",                \
           PropertyType_##PROPERTY_TYPE);                                                    \
                                                                                             \
        ret = TRUE;                                                                          \
        hr = IPropertyValue_get_IsNumericScalar(value, &ret);                                \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(ret == FALSE, "Expected not numeric scalar.\n");                                  \
                                                                                             \
        hr = IPropertyValue_Get##PROPERTY_TYPE(value, &expected_value);                      \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(!memcmp(&VALUE, &expected_value, sizeof(VALUE)), "Got unexpected value.\n");      \
                                                                                             \
        IPropertyValue_Release(value);                                                       \
    } while (0);

    TEST_PROPERTY_VALUE(UInt8, BYTE, byte_value)
    TEST_PROPERTY_VALUE(Int16, INT16, int16_value)
    TEST_PROPERTY_VALUE(UInt16, UINT16, uint16_value)
    TEST_PROPERTY_VALUE(Int32, INT32, int32_value)
    TEST_PROPERTY_VALUE(UInt32, UINT32, uint32_value)
    TEST_PROPERTY_VALUE(Int64, INT64, int64_value)
    TEST_PROPERTY_VALUE(UInt64, UINT64, uint64_value)
    TEST_PROPERTY_VALUE(Single, FLOAT, float_value)
    TEST_PROPERTY_VALUE(Double, DOUBLE, double_value)
    TEST_PROPERTY_VALUE(Char16, WCHAR, wchar_value)
    TEST_PROPERTY_VALUE(Boolean, boolean, boolean_value)
    TEST_PROPERTY_VALUE(String, HSTRING, str)
    TEST_PROPERTY_VALUE(DateTime, DateTime, datetime_value)
    TEST_PROPERTY_VALUE(TimeSpan, TimeSpan, timespan_value)
    TEST_PROPERTY_VALUE(Guid, GUID, IID_IPropertyValue)
    TEST_PROPERTY_VALUE(Point, Point, point_value)
    TEST_PROPERTY_VALUE(Size, Size, size_value)
    TEST_PROPERTY_VALUE(Rect, Rect, rect_value)

#undef TEST_PROPERTY_VALUE

    /* Test property value array */
#define TEST_PROPERTY_COUNT 2
#define TEST_PROPERTY_VALUE_ARRAY(PROPERTY_TYPE, TYPE, VALUE)                                   \
    do                                                                                          \
    {                                                                                           \
        TYPE values[TEST_PROPERTY_COUNT], *expected_values;                                     \
                                                                                                \
        for (i = 0; i < TEST_PROPERTY_COUNT; i++)                                               \
            memcpy(&values[i], &VALUE, sizeof(VALUE));                                          \
                                                                                                \
        hr = IPropertyValueStatics_Create##PROPERTY_TYPE(statics, TEST_PROPERTY_COUNT, values,  \
                                                         NULL);                                 \
        ok(hr == E_POINTER, "Got unexpected hr %#lx.\n", hr);                                   \
                                                                                                \
        inspectable = NULL;                                                                     \
        hr = IPropertyValueStatics_Create##PROPERTY_TYPE(statics, TEST_PROPERTY_COUNT, values,  \
                                                         &inspectable);                         \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                        \
        ok(inspectable != NULL, "Got unexpected inspectable.\n");                               \
                                                                                                \
        hr = IInspectable_QueryInterface(inspectable, &IID_IPropertyValue, (void **)&value);    \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                        \
        IInspectable_Release(inspectable);                                                      \
                                                                                                \
        hr = IPropertyValue_get_Type(value, &type);                                             \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                        \
        ok(type == PropertyType_##PROPERTY_TYPE, "Got unexpected type %d.\n",                   \
           PropertyType_##PROPERTY_TYPE);                                                       \
                                                                                                \
        ret = TRUE;                                                                             \
        hr = IPropertyValue_get_IsNumericScalar(value, &ret);                                   \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                        \
        ok(ret == FALSE, "Expected not numeric scalar.\n");                                     \
                                                                                                \
        count = 0;                                                                              \
        hr = IPropertyValue_Get##PROPERTY_TYPE(value, &count, &expected_values);                \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                        \
        ok(count == TEST_PROPERTY_COUNT, "Got unexpected count %u.\n", count);                  \
        ok(expected_values != values, "Got same pointer.\n");                                   \
        for (i = 0; i < TEST_PROPERTY_COUNT; i++)                                               \
            ok(!memcmp(&VALUE, &expected_values[i], sizeof(VALUE)), "Got unexpected value.\n"); \
                                                                                                \
        IPropertyValue_Release(value);                                                          \
    } while (0);

    TEST_PROPERTY_VALUE_ARRAY(UInt8Array, BYTE, byte_value)
    TEST_PROPERTY_VALUE_ARRAY(Int16Array, INT16, int16_value)
    TEST_PROPERTY_VALUE_ARRAY(UInt16Array, UINT16, uint16_value)
    TEST_PROPERTY_VALUE_ARRAY(Int32Array, INT32, int32_value)
    TEST_PROPERTY_VALUE_ARRAY(UInt32Array, UINT32, uint32_value)
    TEST_PROPERTY_VALUE_ARRAY(Int64Array, INT64, int64_value)
    TEST_PROPERTY_VALUE_ARRAY(UInt64Array, UINT64, uint64_value)
    TEST_PROPERTY_VALUE_ARRAY(SingleArray, FLOAT, float_value)
    TEST_PROPERTY_VALUE_ARRAY(DoubleArray, DOUBLE, double_value)
    TEST_PROPERTY_VALUE_ARRAY(Char16Array, WCHAR, wchar_value)
    TEST_PROPERTY_VALUE_ARRAY(BooleanArray, boolean, boolean_value)
    TEST_PROPERTY_VALUE_ARRAY(StringArray, HSTRING, str)
    TEST_PROPERTY_VALUE_ARRAY(DateTimeArray, DateTime, datetime_value)
    TEST_PROPERTY_VALUE_ARRAY(TimeSpanArray, TimeSpan, timespan_value)
    TEST_PROPERTY_VALUE_ARRAY(GuidArray, GUID, IID_IPropertyValue)
    TEST_PROPERTY_VALUE_ARRAY(PointArray, Point, point_value)
    TEST_PROPERTY_VALUE_ARRAY(SizeArray, Size, size_value)
    TEST_PROPERTY_VALUE_ARRAY(RectArray, Rect, rect_value)

#undef TEST_PROPERTY_VALUE_ARRAY
#undef TEST_PROPERTY_COUNT

    /* Test IReference<*> interface */
#define TEST_PROPERTY_VALUE_IREFERENCE(TYPE, IFACE_TYPE, VALUE, RET_OBJ, RET_VALUE)          \
    do                                                                                       \
    {                                                                                        \
        hr = IPropertyValueStatics_Create##TYPE(statics, VALUE, &inspectable);               \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
                                                                                             \
        hr = IInspectable_QueryInterface(inspectable, &IID_IPropertyValue, (void **)&value); \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(value == (IPropertyValue *)inspectable, "Expected the same pointer.\n");          \
                                                                                             \
        hr = IPropertyValue_QueryInterface(value, &IID_##IFACE_TYPE, (void **)&RET_OBJ);     \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
                                                                                             \
        hr = IFACE_TYPE##_get_Value(RET_OBJ, &RET_VALUE);                                    \
        ok(hr == S_OK, "Got unexpected hr %#lx.\n", hr);                                     \
        ok(RET_VALUE == VALUE, "Got unexpected value.\n");                                   \
                                                                                             \
        IFACE_TYPE##_Release(RET_OBJ);                                                       \
        IPropertyValue_Release(value);                                                       \
        IInspectable_Release(inspectable);                                                   \
    } while (0);

    TEST_PROPERTY_VALUE_IREFERENCE(Boolean, IReference_boolean, TRUE, iref_boolean, ret)
    TEST_PROPERTY_VALUE_IREFERENCE(String, IReference_HSTRING, str, iref_hstring, ret_str)
    TEST_PROPERTY_VALUE_IREFERENCE(Double, IReference_DOUBLE, 1.5, iref_double, ret_double)

#undef TEST_PROPERTY_VALUE_IREFERENCE

    IPropertyValueStatics_Release(statics);
    IActivationFactory_Release(factory);
    WindowsDeleteString(str);
    RoUninitialize();
}

static void test_RoResolveNamespace(void)
{
    static const WCHAR foundation[] = L"c:\\windows\\system32\\winmetadata\\windows.foundation.winmd";
    static const WCHAR foundation_wow64[] = L"c:\\windows\\sysnative\\winmetadata\\windows.foundation.winmd";
    static const WCHAR networking[] = L"c:\\windows\\system32\\winmetadata\\windows.networking.winmd";
    static const WCHAR networking_wow64[] = L"c:\\windows\\sysnative\\winmetadata\\windows.networking.winmd";
    HSTRING name, *paths;
    DWORD count, i;
    HRESULT hr;
    static const struct
    {
        const WCHAR *namespace;
        DWORD        len_namespace;
        const WCHAR *path;
        const WCHAR *path_wow64;
    }
    tests[] =
    {
        { L"Windows.Networking.Connectivity", ARRAY_SIZE(L"Windows.Networking.Connectivity") - 1,
          networking, networking_wow64 },
        { L"Windows.Foundation", ARRAY_SIZE(L"Windows.Foundation") - 1,
          foundation, foundation_wow64 },
    };

    hr = RoInitialize(RO_INIT_MULTITHREADED);
    ok(hr == S_OK, "got %#lx\n", hr);

    for (i = 0; i < ARRAY_SIZE(tests); i++)
    {
        winetest_push_context("%lu: ", i);
        hr = WindowsCreateString(tests[i].namespace, tests[i].len_namespace, &name);
        ok(hr == S_OK, "got %#lx\n", hr);

        count = 0;
        hr = RoResolveNamespace(name, NULL, 0, NULL, &count, &paths, 0, NULL);
        todo_wine ok(hr == S_OK, "got %#lx\n", hr);
        if (hr == S_OK)
        {
            const WCHAR *str = WindowsGetStringRawBuffer(paths[0], NULL);

            ok(count == 1, "got %lu\n", count);
            ok((!is_wow64 && !wcsicmp( str, tests[i].path )) ||
               (is_wow64 && !wcsicmp( str, tests[i].path_wow64 )) ||
               broken(is_wow64 && !wcsicmp( str, tests[i].path )) /* win8, win10 1507 */,
               "got %s\n", wine_dbgstr_w(str) );

            WindowsDeleteString(paths[0]);
            CoTaskMemFree(paths);
        }

        WindowsDeleteString(name);
        winetest_pop_context();
    }

    RoUninitialize();
}

START_TEST(wintypes)
{
    IsWow64Process(GetCurrentProcess(), &is_wow64);

    test_IApiInformationStatics();
    test_IPropertyValueStatics();
    test_RoResolveNamespace();
}