        ��  ��                  '� ,   ��( A P I . V B S       0           ' Copyright 2011 Jacek Caban for CodeWeavers
'
' This library is free software; you can redistribute it and/or
' modify it under the terms of the GNU Lesser General Public
' License as published by the Free Software Foundation; either
' version 2.1 of the License, or (at your option) any later version.
'
' This library is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
' Lesser General Public License for more details.
'
' You should have received a copy of the GNU Lesser General Public
' License along with this library; if not, write to the Free Software
' Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
'

Option Explicit

Dim x

Class EmptyClass
End Class

Call ok(vbSunday = 1, "vbSunday = " & vbSunday)
Call ok(getVT(vbSunday) = "VT_I2", "getVT(vbSunday) = " & getVT(vbSunday))
Call ok(vbMonday = 2, "vbMonday = " & vbMonday)
Call ok(getVT(vbMonday) = "VT_I2", "getVT(vbMonday) = " & getVT(vbMonday))
Call ok(vbTuesday = 3, "vbTuesday = " & vbTuesday)
Call ok(getVT(vbTuesday) = "VT_I2", "getVT(vbTuesday) = " & getVT(vbTuesday))
Call ok(vbWednesday = 4, "vbWednesday = " & vbWednesday)
Call ok(getVT(vbWednesday) = "VT_I2", "getVT(vbWednesday) = " & getVT(vbWednesday))
Call ok(vbThursday = 5, "vbThursday = " & vbThursday)
Call ok(getVT(vbThursday) = "VT_I2", "getVT(vbThursday) = " & getVT(vbThursday))
Call ok(vbFriday = 6, "vbFriday = " & vbFriday)
Call ok(getVT(vbFriday) = "VT_I2", "getVT(vbFriday) = " & getVT(vbFriday))
Call ok(vbSaturday = 7, "vbSaturday = " & vbSaturday)
Call ok(getVT(vbSaturday) = "VT_I2", "getVT(vbSaturday) = " & getVT(vbSaturday))

Sub TestConstant(name, val, exval)
    Call ok(val = exval, name & " =  " & val & " expected " & exval)
    Call ok(getVT(val) = "VT_I2*", "getVT(" & name & ") = " & getVT(val))
End Sub

Sub TestConstantI4(name, val, exval)
    Call ok(val = exval, name & " =  " & val & " expected " & exval)
    Call ok(getVT(val) = "VT_I4*", "getVT(" & name & ") = " & getVT(val))
End Sub

Sub TestConstantBSTR(name, val, exval)
    Call ok(val = exval, name & " =  " & val & " expected " & exval)
    Call ok(getVT(val) = "VT_BSTR*", "getVT(" & name & ") = " & getVT(val))
End Sub

TestConstant "vbEmpty", vbEmpty, 0
TestConstant "vbNull", vbNull, 1
TestConstant "vbLong", vbLong, 3
TestConstant "vbSingle", vbSingle, 4
TestConstant "vbDouble", vbDouble, 5
TestConstant "vbCurrency", vbCurrency, 6
TestConstant "vbDate", vbDate, 7
TestConstant "vbString", vbString, 8
TestConstant "vbObject", vbObject, 9
TestConstant "vbError", vbError, 10
TestConstant "vbBoolean", vbBoolean, 11
TestConstant "vbVariant", vbVariant, 12
TestConstant "vbDataObject", vbDataObject, 13
TestConstant "vbDecimal", vbDecimal, 14
TestConstant "vbByte", vbByte, 17
TestConstant "vbArray", vbArray, 8192
TestConstant "vbCritical", vbCritical, 16
TestConstant "vbQuestion", vbQuestion, 32
TestConstant "vbExclamation", vbExclamation, 48
TestConstant "vbInformation", vbInformation, 64
TestConstant "vbDefaultButton1", vbDefaultButton1, 0
TestConstant "vbDefaultButton2", vbDefaultButton2, 256
TestConstant "vbDefaultButton3", vbDefaultButton3, 512
TestConstant "vbDefaultButton4", vbDefaultButton4, 768
TestConstant "vbApplicationModal", vbApplicationModal, 0
TestConstant "vbSystemModal", vbSystemModal, 4096
TestConstant "vbUseSystem", vbUseSystem, 0
TestConstant "vbUseSystemDayOfWeek", vbUseSystemDayOfWeek, 0
TestConstant "vbFirstJan1", vbFirstJan1, 1
TestConstant "vbFirstFourDays", vbFirstFourDays, 2
TestConstant "vbFirstFullWeek", vbFirstFullWeek, 3
TestConstant "vbTrue", vbTrue, -1
TestConstant "vbFalse", vbFalse, 0
TestConstantI4 "vbMsgBoxHelpButton", vbMsgBoxHelpButton, 16384
TestConstantI4 "vbMsgBoxSetForeground", vbMsgBoxSetForeground, 65536
TestConstantI4 "vbMsgBoxRight", vbMsgBoxRight, 524288
TestConstantI4 "vbMsgBoxRtlReading", vbMsgBoxRtlReading, 1048576
TestConstant "vbUseDefault", vbUseDefault, -2
TestConstant "vbBinaryCompare", vbBinaryCompare, 0
TestConstant "vbTextCompare", vbTextCompare, 1
TestConstant "vbDatabaseCompare", vbDatabaseCompare, 2
TestConstant "vbGeneralDate", vbGeneralDate, 0
TestConstant "vbLongDate", vbLongDate, 1
TestConstant "vbShortDate", vbShortDate, 2
TestConstant "vbLongTime", vbLongTime, 3
TestConstant "vbShortTime", vbShortTime, 4
TestConstantI4 "vbObjectError", vbObjectError, &h80040000&
TestConstantI4 "vbBlack", vbBlack, 0
TestConstantI4 "vbBlue", vbBlue, &hff0000&
TestConstantI4 "vbCyan", vbCyan, &hffff00&
TestConstantI4 "vbGreen", vbGreen, &h00ff00&
TestConstantI4 "vbMagenta", vbMagenta, &hff00ff&
TestConstantI4 "vbRed", vbRed, &h0000ff&
TestConstantI4 "vbWhite", vbWhite, &hffffff&
TestConstantI4 "vbYellow", vbYellow, &h00ffff&
TestConstantBSTR "vbCr", vbCr, Chr(13)
TestConstantBSTR "vbCrLf", vbCrLf, Chr(13)&Chr(10)
TestConstantBSTR "vbNewLine", vbNewLine, Chr(13)&Chr(10)
TestConstantBSTR "vbFormFeed", vbFormFeed, Chr(12)
TestConstantBSTR "vbLf", vbLf, Chr(10)
TestConstantBSTR "vbNullChar", vbNullChar, Chr(0)
TestConstantBSTR "vbNullString", vbNullString, ""
TestConstantBSTR "vbTab", vbTab, chr(9)
TestConstantBSTR "vbVerticalTab", vbVerticalTab, chr(11)

Sub TestCStr(arg, exval)
    dim x
    x = CStr(arg)
    Call ok(getVT(x) = "VT_BSTR*", "getVT(x) = " & getVT(x))
    Call ok(x = exval, "CStr(" & arg & ") = " & x)
End Sub

TestCStr "test", "test"
TestCStr 3, "3"
if isEnglishLang then TestCStr 3.5, "3.5"
if isEnglishLang then TestCStr true, "True"

sub testCStrError()
    on error resume next
    Err.clear()
    CStr(null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    if isEnglishLang then call ok(Err.source = "Microsoft VBScript runtime error", "Err.source = " & Err.source)
    if isEnglishLang then call ok(Err.description = "Invalid use of Null", "Err.description = " & Err.description)
end sub
call testCStrError()

Call ok(getVT(Chr(120)) = "VT_BSTR", "getVT(Chr(120)) = " & getVT(Chr(120)))
Call ok(getVT(Chr(255)) = "VT_BSTR", "getVT(Chr(255)) = " & getVT(Chr(255)))
Call ok(Chr(120) = "x", "Chr(120) = " & Chr(120))
Call ok(Chr(0) <> "", "Chr(0) = """"")
Call ok(Chr(120.5) = "x", "Chr(120.5) = " & Chr(120.5))
Call ok(Chr(119.5) = "x", "Chr(119.5) = " & Chr(119.5))
Call ok(Chr("120") = "x", "Chr(""120"") = " & Chr("120"))

sub testChrError
    on error resume next

    if MaxCharSize = 1 then
        call Err.clear()
        call Chr(-1)
        call ok(Err.number = 5, "Err.number = " & Err.number)
        if isEnglishLang then call ok(Err.description = "Invalid procedure call or argument", "Err.description = " & Err.description)

        call Err.clear()
        call Chr(256)
        call ok(Err.number = 5, "Err.number = " & Err.number)
    else
        call Err.clear()
        call Chr(-1)
        call ok(Err.number = 0, "Err.number = " & Err.number)
        call Err.clear()
        call Chr(256)
        call ok(Err.number = 0, "Err.number = " & Err.number)
    end if

    call Err.clear()
    call Chr(65536)
    call ok(Err.number = 5, "Err.number = " & Err.number)

    call Err.clear()
    call Chr(-32769)
    call ok(Err.number = 5, "Err.number = " & Err.number)
end sub

call testChrError

Call ok(isObject(new EmptyClass), "isObject(new EmptyClass) is not true?")
Set x = new EmptyClass
Call ok(isObject(x), "isObject(x) is not true?")
Call ok(isObject(Nothing), "isObject(Nothing) is not true?")
Call ok(not isObject(true), "isObject(true) is true?")
Call ok(not isObject(4), "isObject(4) is true?")
Call ok(not isObject("x"), "isObject(""x"") is true?")
Call ok(not isObject(Null), "isObject(Null) is true?")

Call ok(not isDate(new EmptyClass), "isDate(new EmptyClass) is true?")
Set x = new EmptyClass
Call ok(not isDate(x), "isDate(x) is true?")
x = CDate(1)
Call ok(isDate(x), "isDate(x) is not true?")
Call ok(isDate(#1/1/2000#), "isDate(#1/1/2000#) is not true?")
Call ok(not isDate(empty), "isDate(empty) is true?")
Call ok(not isDate(Nothing), "isDate(Nothing) is true?")
Call ok(not isDate(true), "isDate(true) is true?")
Call ok(not isDate(4), "isDate(4) is true?")
Call ok(not isDate("4"), "isDate(""4"") is true?")
Call ok(not isDate("x"), "isDate(""x"") is true?")
Call ok(not isDate(Null), "isDate(Null) is true?")

Call ok(not isEmpty(new EmptyClass), "isEmpty(new EmptyClass) is true?")
Set x = new EmptyClass
Call ok(not isEmpty(x), "isEmpty(x) is true?")
x = empty
Call ok(isEmpty(x), "isEmpty(x) is not true?")
Call ok(isEmpty(empty), "isEmpty(empty) is not true?")
Call ok(not isEmpty(Nothing), "isEmpty(Nothing) is not true?")
Call ok(not isEmpty(true), "isEmpty(true) is true?")
Call ok(not isEmpty(4), "isEmpty(4) is true?")
Call ok(not isEmpty("x"), "isEmpty(""x"") is true?")
Call ok(not isEmpty(Null), "isEmpty(Null) is true?")

Call ok(not isNull(new EmptyClass), "isNull(new EmptyClass) is true?")
Set x = new EmptyClass
Call ok(not isNull(x), "isNull(x) is true?")
x = null
Call ok(isNull(x), "isNull(x) is not true?")
Call ok(not isNull(empty), "isNull(empty) is true?")
Call ok(not isNull(Nothing), "isNull(Nothing) is true?")
Call ok(not isNull(true), "isNull(true) is true?")
Call ok(not isNull(4), "isNull(4) is true?")
Call ok(not isNull("x"), "isNull(""x"") is true?")
Call ok(isNull(Null), "isNull(Null) is not true?")

Call ok(isNumeric(Empty), "isNumeric(empty) is not true?")
Call ok(not isNumeric(Null), "isNumeric(Null) is not true?")
Call ok(isNumeric(32767), "isNumeric(32767) is true?")
Call ok(isNumeric(32768), "isNumeric(32768) is true?")
Call ok(isNumeric(CSng(3242.4)), "isNumeric(CSng(3242.4)) is true?")
Call ok(isNumeric(32768.4), "isNumeric(32768.4) is true?")
Call ok(isNumeric(CCur(32768.4)), "isNumeric(CCur(32768.4)) is true?")
Call ok(isNumeric("44"), "isNumeric(""44"") is true?")
Call ok(not isNumeric("rwrf"), "isNumeric(""rwrf"") is not true?")
Call ok(not isNumeric(Nothing), "isNumeric(Nothing) is not true?")
Call ok(not isNumeric(New EmptyClass), "isNumeric(New EmptyClass) is not true?")
Call ok(isNumeric(true), "isNumeric(true) is true?")
Call ok(isNumeric(CByte(32)), "isNumeric(CByte(32)) is true?")
Dim arr(2)
arr(0) = 2
arr(1) = 3
Call ok(not isNumeric(arr), "isNumeric(arr) is not true?")

Call ok(isArray(arr), "isArray(arr) is not true?")
x = Array()
Call ok(isArray(arr), "isArray(Array()) is not true?")
Call ok(not isArray(Empty), "isArray(empty) is true?")
Call ok(not isArray(Null), "isArray(Null) is true?")
Call ok(not isArray(42), "isArray(42) is true?")
Call ok(not isArray(CSng(3242.4)), "isArray(CSng(3242.4)) is true?")
Call ok(not isArray(CCur(32768.4)), "isArray(CCur(32768.4)) is true?")
Call ok(not isArray("44"), "isArray(""44"") is true?")
Call ok(not isArray("rwrf"), "isArray(""rwrf"") is true?")
Call ok(not isArray(Nothing), "isArray(Nothing) is true?")
Call ok(not isArray(New EmptyClass), "isArray(New EmptyClass) is true?")
Call ok(not isArray(true), "isArray(true) is true?")
Call ok(not isArray(CByte(32)), "isArray(CByte(32)) is true?")

Call ok(getVT(Array()) = "VT_ARRAY|VT_VARIANT", "getVT(Array()) = " & getVT(Array()))
x = Array("a1", 2, "a3")
Call ok(getVT(x) = "VT_ARRAY|VT_VARIANT*", "getVT(array) = " & getVT(x))
Call ok(getVT(x(0)) = "VT_BSTR*", "getVT(array(0)) = " & getVT(x(0)))
Call ok(x(0) = "a1", "array(0) = " & x(0))
Call ok(getVT(x(1)) = "VT_I2*", "getVT(array(1)) = " & getVT(x(1)))
Call ok(x(1) = 2, "array(1) = " & x(1))
Call ok(getVT(x(2)) = "VT_BSTR*", "getVT(array(2)) = " & getVT(x(2)))
Call ok(x(2) = "a3", "array(2) = " & x(2))

Dim new_array
new_array = x
x(0) = "new value"
Call ok(new_array(0) = "a1", "new_array(0) = " & new_array(0))

Call ok(getVT(UBound(x)) = "VT_I4", "getVT(UBound(x)) = " & getVT(UBound(x)))
Call ok(UBound(x) = 2, "UBound(x) = " & UBound(x))
Call ok(getVT(UBound(x, 1)) = "VT_I4", "getVT(UBound(x, 1)) = " & getVT(UBound(x, 1)))
Call ok(UBound(x, 1) = 2, "UBound(x) = " & UBound(x, 1))

x = Array(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33)
ok x(1) = 2, "x(1) = " & x(1)
ok x(32) = 33, "x(32) = " & x(32)
ok ubound(x) = 32, "ubound(x) = " & ubound(x)

Dim arr2(2, 4)
Call ok(UBound(arr2) = 2, "UBound(x) = " & UBound(x))
Call ok(UBound(arr2, 1) = 2, "UBound(x) = " & UBound(x))
Call ok(UBound(arr2, 2) = 4, "UBound(x) = " & UBound(x))
Call ok(Lbound(arr2) = 0, "Lbound(x) = " & Lbound(x))
Call ok(Lbound(arr2, 1) = 0, "Lbound(x) = " & Lbound(x))
Call ok(Lbound(arr2, 2) = 0, "Lbound(x) = " & Lbound(x))

sub testLBoundError()
    on error resume next
    call Err.clear()
    call LBound()
    call ok(Err.number = 450, "Err.number = " & Err.number)
    call Err.clear()
    call LBound(Empty)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call LBound(Null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call LBound(arr, 1, 2)
    call ok(Err.number = 450, "Err.number = " & Err.number)
    if isEnglishLang then call ok(Err.description = "Wrong number of arguments or invalid property assignment", _
                                  "Err.description = " & Err.description)
end sub

sub testUBoundError()
    on error resume next
    call Err.clear()
    call UBound()
    call ok(Err.number = 450, "Err.number = " & Err.number)
    call Err.clear()
    call UBound(Empty)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call UBound(Null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call UBound(arr, 1, 2)
    call ok(Err.number = 450, "Err.number = " & Err.number)
    if isEnglishLang then call ok(Err.description = "Wrong number of arguments or invalid property assignment", _
                                  "Err.description = " & Err.description)
end sub

call testLBoundError()
call testUBoundError()

Dim newObject
Set newObject = New ValClass
newObject.myval = 1
Call ok(isNumeric(newObject), "isNumeric(newObject) is true?")
newObject.myval = "test"
Call ok(not isNumeric(newObject), "isNumeric(newObject) is not true?")

Call ok(getVT(err) = "VT_DISPATCH", "getVT(err) = " & getVT(err))

Sub TestHex(x, ex)
    Call ok(hex(x) = ex, "hex(" & x & ") = " & hex(x) & " expected " & ex)
End Sub

TestHex 0, "0"
TestHex 6, "6"
TestHex 16, "10"
TestHex &hdeadbeef&, "DEADBEEF"
TestHex -1, "FFFF"
TestHex -16, "FFF0"
TestHex -934859845, "C8472BBB"
TestHex empty, "0"
TestHex "17", "11"
TestHex 228.5, "E4"
TestHex -32767, "8001"
TestHex -32768, "FFFF8000"
TestHex 2147483647.49, "7FFFFFFF"
TestHex -2147483647.5, "80000000"
newObject.myval = 30.5
TestHex newObject, "1E"
newObject.myval = "27"
TestHex newObject, "1B"


Call ok(getVT(hex(null)) = "VT_NULL", "getVT(hex(null)) = " & getVT(hex(null)))
Call ok(getVT(hex(empty)) = "VT_BSTR", "getVT(hex(empty)) = " & getVT(hex(empty)))

Sub TestHexError(num, err_num)
    On Error Resume Next
    Call Hex(num)
    Call ok(Err.number = err_num, "Hex(" & num & ") returns error number " & Err.number & " expected " & err_num)
End Sub

TestHexError 2147483647.5, 6
TestHexError 2147483648.51, 6
TestHexError "test", 13

Sub TestOct(x, ex, res_type)
    Call ok(Oct(x) = ex, "Oct(" & x & ") = " & Oct(x) & " expected " & ex)
    Call ok(getVT(Oct(x)) = res_type, "getVT(Oct(" &x & ")) = " & getVT(Oct(x)) & "expected " & res_type)
End Sub

Sub TestOctError(num, err_num)
    On error resume next
    Call Oct(num)
    Call ok(Err.number = err_num, "Oct(" & num & ") error number is " & Err.number & " expected " & err_num)
End Sub

TestOct empty, "0", "VT_BSTR"
TestOct 0, "0", "VT_BSTR"
TestOct 9, "11", "VT_BSTR"
TestOct "9", "11", "VT_BSTR"
TestOct 8.5, "10", "VT_BSTR"
TestOct 9.5, "12", "VT_BSTR"
TestOct -1, "177777", "VT_BSTR"
TestOct -32767, "100001", "VT_BSTR"
TestOct -32768, "37777700000", "VT_BSTR"
TestOct 2147483647.49, "17777777777", "VT_BSTR"
TestOct -2147483648.5, "20000000000", "VT_BSTR"
Call ok(getVT(Oct(null)) = "VT_NULL", "getVT(Oct(null)) = " & getVT(Oct(null)))
newObject.myval = 5
TestOct newObject, "5", "VT_BSTR"

TestOctError 2147483647.5, 6
TestOctError -2147483648.51, 6
TestOctError "test", 13

x = InStr(1, "abcd", "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr("abcd", "bc")
Call ok(x = 2, "InStr returned " & x)
Call ok(getVT(x) = "VT_I4*", "getVT(InStr) returned " & getVT(x))

x = InStr("abc", "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr("abcbc", "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr("bcabc", "bc")
Call ok(x = 1, "InStr returned " & x)

x = InStr(3, "abcd", "bc")
Call ok(x = 0, "InStr returned " & x)

x = InStr("abcd", "bcx")
Call ok(x = 0, "InStr returned " & x)

x = InStr(5, "abcd", "bc")
Call ok(x = 0, "InStr returned " & x)

x = "abcd"
x = InStr(x, "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr("abcd", null)
Call ok(isNull(x), "InStr returned " & x)
x = InStr(null, "abcd")
Call ok(isNull(x), "InStr returned " & x)
x = InStr(2, null, "abcd")
Call ok(isNull(x), "InStr returned " & x)

x = InStr(1.3, "abcd", "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr(2.3, "abcd", "bc")
Call ok(x = 2, "InStr returned " & x)

x = InStr(2.6, "abcd", "bc")
Call ok(x = 0, "InStr returned " & x)

x = InStr(3, "abcdefgh", "fg", 0)
Call ok(x = 6, "InStr returned " & x)

x = InStr(3, "abcdefgh", "FG", 0)
Call ok(x = 0, "InStr returned " & x)

x = InStr(3, "abcdefgh", "FG", 1)
Call ok(x = 6, "InStr returned " & x)

x = InStr(3, "abcdefgh", "FG", 1.4)
Call ok(x = 6, "InStr returned " & x)

x = InStr(3, "abcdefgh", "FG", -0.3)
Call ok(x = 0, "InStr returned " & x)

x = InStr(1, "abcABC", "aB", 0)
Call ok(x = 0, "InStr returned " & x)

x = InStr(1, "abcABC", "aB", 1)
Call ok(x = 1, "InStr returned " & x)

x = InStr(2, "abcABC", "aB", 1)
Call ok(x = 4, "InStr returned " & x)

x = InStr(5, "abcABC", "aB", 1)
Call ok(x = 0, "InStr returned " & x)

x = InStr(2, "abcABC", "ab", 1)
Call ok(x = 4, "InStr returned " & x)

x = InStr(6, "abcABC", "c", 1)
Call ok(x = 6, "InStr returned " & x)

x = InStr(2, "abc" & Chr(0) & "A" & Chr(0) & "BC", "C", 0)
Call ok(x = 8, "InStr returned " & x)

x = InStr(1, "abc" & Chr(0) & "ABC", Chr(0) & "a", 1)
Call ok(x = 4, "InStr returned " & x)

x = InStr(1, 23456, 45, 0)
Call ok(x = 3, "InStr returned " & x)

x = InStr(1, "23456", 34, 1)
Call ok(x = 2, "InStr returned " & x)

x = InStr(2, "", "abcd", 0)
Call ok(x = 0, "InStr returned " & x)

x = InStr(4, "abcdef", "", 0)
Call ok(x = 4, "InStr returned " & x)

x = InStr(20, "abcdef", "", 0)
Call ok(x = 0, "InStr returned " & x)

x = InStr(4, "", "", 0)
Call ok(x = 0, "InStr returned " & x)

Sub testInStrError(arg1, arg2, arg3, arg4, error_num)
    on error resume next
    Dim x

    Call Err.clear()
    x = InStr(arg1, arg2, arg3, arg4)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

call testInStrError(2, "abcd", null, 0, 0)
call testInStrError(2, Null, "abcd", 0, 0)
call testInStrError(Null, "abcd", "abcd", 0, 94)
call testInStrError(2, "abcd", "abcd", null, 94)
call testInStrError(-20, "abcd", "abcd", 1, 5)
Call testInStrError(2, "abcd", "abcd", 10, 5)


x = InStrRev("bcabcd", "bc")
Call ok(x = 4, "InStrRev returned " & x)
Call ok(getVT(x) = "VT_I4*", "getVT(InStrRev) returned " & getVT(x))

x = InStrRev("bcabcd", "bc", 6)
Call ok(x = 4, "InStrRev returned " & x)

x = InStrRev("abcd", "bcx")
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 3)
Call ok(x = 2, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 2)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "b", 2)
Call ok(x = 2, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 5)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 15)
Call ok(x = 0, "InStrRev returned " & x)

x = "abcd"
x = InStrRev(x, "bc")
Call ok(x = 2, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 1.3)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 2.3)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "bc", 2.6)
Call ok(x = 2, "InStrRev returned " & x)

x = InStrRev("1234", 34)
Call ok(x = 3, "InStrRev returned " & x)

x = InStrRev(1234, 34)
Call ok(x = 3, "InStrRev returned " & x)

x = InStrRev("abcd", "A", 1, 0)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "A", 1, 1)
Call ok(x = 1, "InStrRev returned " & x)

x = InStrRev("abcd", "Ab", 1, 1)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "Ab", -1, 1)
Call ok(x = 1, "InStrRev returned " & x)

x = InStrRev("abcd", "cd", 3, 1)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "cd", 4, 1)
Call ok(x = 3, "InStrRev returned " & x)

x = InStrRev("abcd", "cd", 5, 1)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abc" & Chr(0) & "A" & Chr(0) & "BC", "c", 8, 0)
Call ok(x = 3, "InStrRev returned " & x)

x = InStrRev("abc" & Chr(0) & "ABC", Chr(0) & "a", 6, 1)
Call ok(x = 4, "InStrRev returned " & x)

x = InStrRev("", "hi", 1, 0)
Call ok(x = 0, "InStrRev returned " & x)

x = InStrRev("abcd", "", 3, 1)
Call ok(x = 3, "InStrRev returned " & x)

x = InStrRev("", "", 3, 0)
Call ok(x = 0, "InStrRev returned " & x)

Sub testInStrRevError(arg1, arg2, arg3, arg4, error_num)
    on error resume next
    Dim x

    Call Err.clear()
    x = InStrRev(arg1, arg2, arg3, arg4)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

call testInStrRevError("abcd", null, 2, 0, 94)
call testInStrRevError(null, "abcd", 2, 0, 94)
call testInStrRevError("abcd", "abcd", null, 0, 94)
call testInStrRevError("abcd", "abcd", 2, null, 94)
call testInStrRevError("abcd", "abcd", -20, 1, 5)
Call testInStrRevError("abcd", "abcd", 2, 10, 5)

Sub TestMid(str, start, len, ex)
    x = Mid(str, start, len)
    Call ok(x = ex, "Mid(" & str & ", " & start & ", " & len & ") = " & x & " expected " & ex)
End Sub

Sub TestMid2(str, start, ex)
    x = Mid(str, start)
    Call ok(x = ex, "Mid(" & str & ", " & start & ") = " & x & " expected " & ex)
End Sub

TestMid "test", 2, 2, "es"
TestMid "test", 2, 4, "est"
TestMid "test", 1, 2, "te"
TestMid "test", 1, 0, ""
TestMid "test", 1, 0, ""
TestMid "test", 5, 2, ""
TestMid 1234, 1, 2, "12"
TestMid 1234, 5, 2, ""
TestMid2 "test", 1, "test"
TestMid2 "test", 2, "est"
TestMid2 "test", 4, "t"
TestMid2 "test", 5, ""
TestMid2 1234, 5, ""

sub TestMidError()
    on error resume next
    call Err.clear()
    call Mid("test", "a", 1)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", "a", null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", "a", empty)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Mid("test", 0, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", -1, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid(null, -1, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", 0, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", -1, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", null, 2)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", null, -1)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Mid(null, -1, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", empty, 1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid("test", 0, empty)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Mid(empty, 0, 0)
    call ok(Err.number = 5, "Err.number = " & Err.number)
end sub
call TestMidError()

Sub TestUCase(str, ex)
    x = UCase(str)
    Call ok(x = ex, "UCase(" & str & ") = " & x & " expected " & ex)
End Sub

TestUCase "test", "TEST"
TestUCase "123aBC?", "123ABC?"
TestUCase "", ""
TestUCase 1, "1"
if isEnglishLang then TestUCase true, "TRUE"
TestUCase 0.123, doubleAsString(0.123)
TestUCase Empty, ""
Call ok(getVT(UCase(Null)) = "VT_NULL", "getVT(UCase(Null)) = " & getVT(UCase(Null)))

Sub TestLCase(str, ex)
    x = LCase(str)
    Call ok(x = ex, "LCase(" & str & ") = " & x & " expected " & ex)
End Sub

TestLCase "test", "test"
TestLCase "123aBC?", "123abc?"
TestLCase "", ""
TestLCase 1, "1"
if isEnglishLang then TestLCase true, "true"
TestLCase 0.123, doubleAsString(0.123)
TestLCase Empty, ""
Call ok(getVT(LCase(Null)) = "VT_NULL", "getVT(LCase(Null)) = " & getVT(LCase(Null)))

x=Split("abc")
Call ok(x(0) = "abc", "Split(""abc"")(0)=" & x(0))
x = Split("abc def")
Call ok(x(0) = "abc", "Split(""abc def"")(0)=" & x(0))
Call ok(x(1) = "def", "Split(""abc def"")(1)=" & x(1))
x = Split("abc def ghi")
Call ok(x(0) = "abc", "Split(""abc def ghi"")(0)=" & x(0))
Call ok(x(1) = "def", "Split(""abc def ghi"")(1)=" & x(1))
Call ok(x(2) = "ghi", "Split(""abc def ghi"")(2)=" & x(2))
x = Split("abc def","")
Call ok(x(0) = "abc def", "Split(""abc def"","""")(0)=" & x(0))
x = Split("abc-def","-")
Call ok(x(0) = "abc", "Split(""abc-def"",""-"")(0)=" & x(0))
Call ok(x(1) = "def", "Split(""abc-def"",""-"")(1)=" & x(1))
x = Split("abc--def","-")
Call ok(x(0) = "abc", "Split(""abc--def"",""-"")(0)=" & x(0))
Call ok(x(1) = "",    "Split(""abc--def"",""-"")(1)=" & x(1))
Call ok(x(2) = "def", "Split(""abc--def"",""-"")(2)=" & x(2))
x = Split("abcdefghi","def")
Call ok(x(0) = "abc", "Split(""abcdefghi"",""def"")(0)=" & x(0))
Call ok(x(1) = "ghi", "Split(""abcdefghi"",""def"")(1)=" & x(1))
x = Split("12345",3)
Call ok(x(0) = "12", "Split(""12345"",3)(0)=" & x(0))
Call ok(x(1) = "45", "Split(""12345"",3)(1)=" & x(1))
x = Split("12345",5)
Call ok(x(0) = "1234", "Split(""12345"",5)(0)=" & x(0))
Call ok(x(1) = "",     "Split(""12345"",5)(1)=" & x(1))
x = Split("12345",12)
Call ok(x(0) = "", "Split(""12345"",12)(0)=" & x(0))
Call ok(x(1) = "345", "Split(""12345"",12)(1)=" & x(1))
x = Split("abc-def-ghi","-")
Call ok(UBound(x) = 2, "UBound(Split(""abc-def-ghi"",""-""))=" & UBound(x))
x = Split("a b c d e f g h i j k l m n o p q")
Call ok(UBound(x) = 16, "UBound(Split(""a b c d e f g h i j k l m n o p q""))=" & UBound(x))
x = Split("abc-def-ghi","-",2)
Call ok(UBound(x) = 1, "UBound(Split(""abc-def-ghi"",""-"",2))=" & UBound(x))
x = Split("abc-def-ghi","-",4)
Call ok(UBound(x) = 2, "UBound(Split(""abc-def-ghi"",""-"",4))="  & UBound(x))
x = Split("abc-def-ghi","-",-1)
Call ok(UBound(x) = 2, "UBound(Split(""abc-def-ghi"",""-"",-1))="  & UBound(x))
x = Split("abc-def-ghi","-",-1)
Call ok(UBound(x) = 2, "UBound(Split(""abc-def-ghi"",""-"",-42))="  & UBound(x))
x = Split("abcZdefZghi","Z",3,0)
Call ok(UBound(x) = 2, "UBound(Split(""abcZdefZghi"",""Z"",3,0))="  & UBound(x))
x = Split("abcZdefZghi","z",3,0)
Call ok(UBound(x) = 0, "UBound(Split(""abcZdefZghi"",""z"",3,0))=" & UBound(x))
x = Split("abcZdefZghi","z",3,1)
Call ok(UBound(x) = 2, "UBound(Split(""abcZdefZghi"",""z"",3,1))=" & UBound(x))

Sub testSplitError(arg1, arg2, arg3, arg4, error_num)
    on error resume next
    Dim x

    Call Err.clear()
    x = Split(arg1, arg2, arg3, arg4)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

call testSplitError("abc-def-ghi", "-", -1, 2, 5)
call testSplitError("abc-def-ghi", "-", -42, 0, 5)
call testSplitError(null, "-", -1, 0, 94)
call testSplitError("abc-def-ghi", null, -1, 0, 94)
call testSplitError("abc-def-ghi", "-", null, 0, 94)
call testSplitError("abc-def-ghi", "-", -1, null, 94)

Sub TestStrComp(str_left, str_right, mode, ex)
    x = StrComp(str_left, str_right, mode)
    Call ok(x = ex, "StrComp(" & str_left & ", " & str_right & ", " & mode & ") = " & x & " expected " & ex)
End Sub

TestStrComp "ABC",  "abc",  0, -1
TestStrComp "abc",  "ABC",  0,  1
TestStrComp "ABC",  "ABC",  0,  0
TestStrComp "ABC",  "abc",  0, -1
TestStrComp "abc",  "ABC",  0,  1
TestStrComp "ABC",  "ABC",  0,  0
TestStrComp "ABCD", "ABC",  0,  1
TestStrComp "ABC",  "ABCD", 0, -1
TestStrComp "ABC",  "abc",  1,  0
TestStrComp "ABC",  "ABC",  1,  0
TestStrComp "ABCD", "ABC",  1,  1
TestStrComp "ABC",  "ABCD", 1, -1
TestStrComp "ABC",  "ABCD", "0", -1
TestStrComp "ABC",  "ABCD", "1", -1
TestStrComp 1,      1,      1,  0
TestStrComp "1",    1,      1,  0
TestStrComp "1",    1.0,    1,  0
TestStrComp Empty,  Empty,  1,  0
TestStrComp Empty,  "",     1,  0
TestStrComp Empty,  "ABC",  1,  -1
TestStrComp "ABC",  Empty,  1,  1
TestStrComp vbNull, vbNull, 1,  0
TestStrComp "",     vbNull, 1,  -1

sub testStrCompError()
    on error resume next
    call Err.clear()
    call StrComp()
    call ok(Err.number = 450, "Err.number = " & Err.number)
    call Err.clear()
    call StrComp("a", "a", 0, 1)
    call ok(Err.number = 450, "Err.number = " & Err.number)
end sub
call testStrCompError()

Call ok(Len("abc") = 3, "Len(abc) = " & Len("abc"))
Call ok(Len("") = 0, "Len() = " & Len(""))
Call ok(Len(1) = 1, "Len(1) = " & Len(1))
Call ok(isNull(Len(null)), "Len(null) = " & Len(null))
Call ok(Len(empty) = 0, "Len(empty) = " & Len(empty))
Call ok(getVT(Len("abc")) = "VT_I4", "getVT(Len(abc)) = " & getVT(Len("abc")))

Call ok(Space(1) = " ", "Space(1) = " & Space(1) & """")
Call ok(Space(0) = "", "Space(0) = " & Space(0) & """")
Call ok(Space(false) = "", "Space(false) = " & Space(false) & """")
Call ok(Space(5) = "     ", "Space(5) = " & Space(5) & """")
Call ok(Space(5.2) = "     ", "Space(5.2) = " & Space(5.2) & """")
Call ok(Space(5.8) = "      ", "Space(5.8) = " & Space(5.8) & """")
Call ok(Space(5.5) = "      ", "Space(5.5) = " & Space(5.5) & """")
Call ok(Space(4.5) = "    ", "Space(4.5) = " & Space(4.5) & """")
Call ok(Space(0.5) = "", "Space(0.5) = " & Space(0.5) & """")
Call ok(Space(1.5) = "  ", "Space(1.5) = " & Space(1.5) & """")
Call ok(Space("1") = " ", "Space(""1"") = " & Space("1") & """")
Call ok(Space(Empty) = "", "Space(Empty) = " & Space(Empty) & """")

sub testSpaceError()
    on error resume next
    call Err.clear()
    call Space(-1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Space("-1")
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Space(Null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
end sub
call testSpaceError()

function strlength(s1, s2, s3, s4, s5)
   strlength = Len(s1 & s2 & s3 & s4 & s5)
end function
Call ok(strlength(String(500, "a"), String(500, "b"), String(500, "c"), String(500, "d"), String(500, "e")) = 500*5, "strlength(...) = 500*5")

sub test_string(cnt, char, exp)
    call ok(String(cnt, char) = exp, "String(" & cnt & ", """ & char & """ = """ & _
                                     String(cnt, char) & """ expected """ & exp & """")
end sub

test_string 3, "x", "xxx"
test_string 3, "xy", "xxx"
test_string 1, "z", "z"
test_string 0, "z", ""
test_string "3", "xy", "xxx"
test_string 3, Chr(3), Chr(3)&Chr(3)&Chr(3)

call ok(getVT(String(0, "z")) = "VT_BSTR", "getVT(String(0,z)) = " & getVT(String(0, "z")))

sub test_string_error()
    on error resume next
    dim x
    x = String(-2, "x")
    call ok(err.number = 5, "err.number = " & err.number)
    err.clear
    x = String(3, "")
    call ok(err.number = 5, "err.number = " & err.number)
    err.clear
    x = String(0, "")
    call ok(err.number = 5, "err.number = " & err.number)
end sub
call test_string_error

Sub TestStrReverse(str, ex)
    Call ok(StrReverse(str) = ex, "StrReverse(" & str & ") = " & StrReverse(str))
End Sub

TestStrReverse "test", "tset"
TestStrReverse "", ""
TestStrReverse 123, "321"
if isEnglishLang then TestStrReverse true, "eurT"

Sub TestLeft(str, len, ex)
    Call ok(Left(str, len) = ex, "Left(" & str & ", " & len & ") = " & Left(str, len))
End Sub

TestLeft "test", 2, "te"
TestLeft "test", 5, "test"
TestLeft "test", 0, ""
TestLeft 123, 2, "12"
TestLeft "123456", 1.5, "12"
TestLeft "123456", 2.5, "12"
TestLeft "test", "2", "te"
if isEnglishLang then TestLeft true, 2, "Tr"

Sub TestRight(str, len, ex)
    Call ok(Right(str, len) = ex, "Right(" & str & ", " & len & ") = " & Right(str, len))
End Sub

TestRight "test", 2, "st"
TestRight "test", 5, "test"
TestRight "test", 0, ""
TestRight 123, 2, "23"
TestRight "test", "3", "est"
TestRight 123, "2", "23"
TestRight empty, 0, ""
TestRight empty, 1, ""
TestRight "test", empty, ""
TestRight "test", empty, ""
if isEnglishLang then TestRight true, 2, "ue"
call Right(null, 0)
call ok(getVT(Right(null, 0)) = "VT_NULL", "getVT(Right(null, 0)) = " & getVT(Right(null, 0)))
call ok(getVT(Right(null, 1)) = "VT_NULL", "getVT(Right(null, 1)) = " & getVT(Right(null, 1)))

sub TestRightError()
    on error resume next
    call Err.clear()
    call Right("test", -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Right(null, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Right("test", null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
end sub
call TestRightError()

Sub TestTrim(str, exstr)
    Call ok(Trim(str) = exstr, "Trim(" & str & ") = " & Trim(str))
End Sub

TestTrim "   test    ", "test"
TestTrim "test    ", "test"
TestTrim "   test", "test"
TestTrim "test", "test"
TestTrim "", ""
TestTrim 123, "123"
if isEnglishLang then TestTrim true, "True"

Sub TestLTrim(str, exstr)
    Call ok(LTrim(str) = exstr, "LTrim(" & str & ") = " & LTrim(str))
End Sub

TestLTrim "   test    ", "test    "
TestLTrim "test    ", "test    "
TestLTrim "   test", "test"
TestLTrim "test", "test"
TestLTrim "", ""
TestLTrim 123, "123"
if isEnglishLang then TestLTrim true, "True"

Sub TestRTrim(str, exstr)
    Call ok(RTrim(str) = exstr, "RTrim(" & str & ") = " & RTrim(str))
End Sub

TestRTrim "   test    ", "   test"
TestRTrim "test    ", "test"
TestRTrim "   test", "   test"
TestRTrim "test", "test"
TestRTrim "", ""
TestRTrim 123, "123"
if isEnglishLang then TestRTrim true, "True"


sub test_replace(str, find, rep, exp)
    dim r
    r = Replace(str, find, rep)
    ok r = exp, "Replace(""" & str & """, """ & find & """, """ & rep & """) = """ & _
       r & """ expected """ & exp & """"
end sub

sub test_replace_from(str, find, rep, from, exp)
    dim r
    r = Replace(str, find, rep, from)
    ok r = exp, "Replace(""" & str & """, """ & find & """, """ & rep & """, " & from & ") = """ & _
       r & """ expected """ & exp & """"
end sub

sub test_replace_cnt(str, find, rep, from, cnt, exp)
    dim r
    r = Replace(str, find, rep, from, cnt)
    ok r = exp, "Replace(""" & str & """, """ & find & """, """ & rep & """, " & from & ", " & cnt & ") = """ & _
       r & """ expected """ & exp & """"
end sub

sub test_replace_mode(str, find, rep, from, cnt, mode, exp)
    dim r
    r = Replace(str, find, rep, from, cnt, mode)
    ok r = exp, "Replace(""" & str & """, """ & find & """, """ & rep & """, " & from & ", " & cnt & ", " & mode _
       & ") = """ & r & """ expected """ & exp & """"
end sub

test_replace "xx testxx(xx)", "xx", "!", "! test!(!)"
test_replace "", "x", "y", ""
test_replace "xxx", "", "y", "xxx"
test_replace "yxxy", "x", "", "yy"
test_replace "xxxxx", "xx", "y", "yyx"
test_replace 123, 2, 6, "163"
test_replace "xyz" & Chr(0) & "xyz", "y", "Y", "xYz" & Chr(0) & "xYz"
test_replace "xyz" & Chr(0) & "xyz", Chr(0) & "x", "Y" & Chr(0) & Chr(0), "xyzY" & Chr(0) & Chr(0) & "yz"

test_replace_from "xx testxx(xx)", "xx", "!", 1, "! test!(!)"
test_replace_from "xx testxx(xx)", "xx", "!", 1, "! test!(!)"
test_replace_from "xx testxx(xx)", "xx", "!", 2, "x test!(!)"
test_replace_from "xx testxx(xx)", "xx", "!", 2000, ""
test_replace_from "xxx", "", "y", 2, "xx"

test_replace_cnt "xx testxx(xx)", "xx", "!", 1, 2, "! test!(xx)"
test_replace_cnt "xx testxx(xx)", "xx", "!", 1, 1, "! testxx(xx)"
test_replace_cnt "xx testxx(xx)", "xx", "!", 2, 1, "x test!(xx)"
test_replace_cnt "xx testxx(xx)", "xx", "!", 1, -1, "! test!(!)"
test_replace_cnt "xx testxx(xx)", "xx", "!", 1, 0, "xx testxx(xx)"

test_replace_mode "Aa testAAa(aa)", "aa", "!", 1, 2, 1, "! test!a(aa)"
test_replace_mode "aA testaa(aa)", "AA", "!", 1, 1, 1, "! testaa(aa)"
test_replace_mode "aa testAa(aa)", "aa", "!", 2, 2, 0, "a testAa(!)"
test_replace_mode "aa testAA(aA)", "Aa", "!", 1, -1, 1, "! test!(!)"
test_replace_mode "aa testaa(aa)", "A", "!", 1, -1, 1, "!! test!!(!!)"

on error resume next
Replace "xx", "x", "y", -1
x = err.number
on error goto 0
ok x = 5, "err = " & x

on error resume next
Replace "xx", "x", "y", 0
x = err.number
on error goto 0
ok x = 5, "err = " & x

on error resume next
Replace "xx", "x", "y", 1, -2
x = err.number
on error goto 0
ok x = 5, "err = " & x

Sub testReplaceError(arg1, arg2, arg3, arg4, arg5, arg6, error_num)
    on error resume next
    Dim x

    Call Err.clear()
    x = Replace(arg1, arg2, arg3, arg4, arg5, arg6)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

Call testReplaceError(Null, "x", "y", 1, 1, 0, 94)
Call testReplaceError("xx", null, "y", 1, 1, 0, 94)
Call testReplaceError("xx", "x", null, 1, 1, 0, 94)
Call testReplaceError("xx", "x", "y", null, 1, 0, 94)
Call testReplaceError("xx", "x", "y", 1, null, 0, 94)
Call testReplaceError("xx", "x", "y", 1, 1, null, 94)
Call testReplaceError("xx", "x", "y", 1, 1, 8, 5)


Sub TestRound(val, exval, vt)
    Call ok(Round(val) = exval, "Round(" & val & ") = " & Round(val))
    Call ok(getVT(Round(val)) = vt, "getVT(Round(" & val & ")) = " & getVT(Round(val)))
End Sub

TestRound 3, 3, "VT_I2"
TestRound 3.3, 3, "VT_R8"
TestRound 3.8, 4, "VT_R8"
TestRound 3.5, 4, "VT_R8"
TestRound -3.3, -3, "VT_R8"
TestRound -3.5, -4, "VT_R8"
TestRound "2", 2, "VT_R8"
TestRound true, true, "VT_BOOL"
TestRound false, false, "VT_BOOL"

Sub TestRound2(val, decnum, exval, vt)
    Call ok(Round(val, decnum) = exval, "Round(" & val & " , " & decnum & ") = " & Round(val, decnum))
    Call ok(getVT(Round(val, decnum)) = vt, "getVT(Round(" & val & " , " & decnum & ")) = " & getVT(Round(val, decnum)))
End Sub

TestRound2 3, 0, 3, "VT_I2"
TestRound2 3, 1, 3, "VT_I2"
TestRound2 3.3, 0, 3, "VT_R8"
TestRound2 3.8, 0, 4, "VT_R8"
TestRound2 3.5, 0, 4, "VT_R8"
TestRound2 -3.3, 0, -3, "VT_R8"
TestRound2 -3.5, 0, -4, "VT_R8"
TestRound2 3.3, 1, 3.3, "VT_R8"
TestRound2 3.8, 1, 3.8, "VT_R8"
TestRound2 3.5, 1, 3.5, "VT_R8"
TestRound2 -3.3, 1, -3.3, "VT_R8"
TestRound2 -3.5, 1, -3.5, "VT_R8"
TestRound2 "2", 1, 2, "VT_R8"
TestRound2 true, 0, true, "VT_BOOL"
TestRound2 false, 0, false, "VT_BOOL"
TestRound2 true, 1, true, "VT_BOOL"
TestRound2 false, 1, false, "VT_BOOL"

if isEnglishLang then
    Call ok(WeekDayName(1) = "Sunday", "WeekDayName(1) = " & WeekDayName(1))
    Call ok(WeekDayName(3) = "Tuesday", "WeekDayName(3) = " & WeekDayName(3))
    Call ok(WeekDayName(7) = "Saturday", "WeekDayName(7) = " & WeekDayName(7))
    Call ok(WeekDayName(1.1) = "Sunday", "WeekDayName(1.1) = " & WeekDayName(1.1))
    Call ok(WeekDayName(1, false) = "Sunday", "WeekDayName(1, false) = " & WeekDayName(1, false))
    Call ok(WeekDayName(1, true) = "Sun", "WeekDayName(1, true) = " & WeekDayName(1, true))
    Call ok(WeekDayName(1, 10) = "Sun", "WeekDayName(1, 10) = " & WeekDayName(1, 10))
    Call ok(WeekDayName(1, true, 2) = "Mon", "WeekDayName(1, true, 2) = " & WeekDayName(1, true, 2))
    Call ok(WeekDayName(1, true, 2.5) = "Mon", "WeekDayName(1, true, 2.5) = " & WeekDayName(1, true, 2.5))
    Call ok(WeekDayName(1, true, 1.5) = "Mon", "WeekDayName(1, true, 1.5) = " & WeekDayName(1, true, 1.5))
    Call ok(WeekDayName(1, true, 7) = "Sat", "WeekDayName(1, true, 7) = " & WeekDayName(1, true, 7))
    Call ok(WeekDayName(1, true, 7.1) = "Sat", "WeekDayName(1, true, 7.1) = " & WeekDayName(1, true, 7.1))

    Call ok(MonthName(1) = "January", "MonthName(1) = " & MonthName(1))
    Call ok(MonthName(12) = "December", "MonthName(12) = " & MonthName(12))
    Call ok(MonthName(1, 0) = "January", "MonthName(1, 0) = " & MonthName(1, 0))
    Call ok(MonthName(12, false) = "December", "MonthName(12, false) = " & MonthName(12, false))
    Call ok(MonthName(1, 10) = "Jan", "MonthName(1, 10) = " & MonthName(1, 10))
    Call ok(MonthName(12, true) = "Dec", "MonthName(12, true) = " & MonthName(12, true))
end if

Call ok(WeekDayName(1, true, 0) = WeekDayName(1, true, firstDayOfWeek), _
        "WeekDayName(1, true, 0) = " & WeekDayName(1, true, 0))

Call ok(getVT(Now()) = "VT_DATE", "getVT(Now()) = " & getVT(Now()))

Call ok(vbOKOnly = 0, "vbOKOnly = " & vbOKOnly)
Call ok(getVT(vbOKOnly) = "VT_I2", "getVT(vbOKOnly) = " & getVT(vbOKOnly))
Call ok(vbOKCancel = 1, "vbOKCancel = " & vbOKCancel)
Call ok(getVT(vbOKCancel) = "VT_I2", "getVT(vbOKCancel) = " & getVT(vbOKCancel))
Call ok(vbAbortRetryIgnore = 2, "vbAbortRetryIgnore = " & vbAbortRetryIgnore)
Call ok(getVT(vbAbortRetryIgnore) = "VT_I2", "getVT(vbAbortRetryIgnore) = " & getVT(vbAbortRetryIgnore))
Call ok(vbYesNoCancel = 3, "vbYesNoCancel = " & vbYesNoCancel)
Call ok(getVT(vbYesNoCancel) = "VT_I2", "getVT(vbYesNoCancel) = " & getVT(vbYesNoCancel))
Call ok(vbYesNo = 4, "vbYesNo = " & vbYesNo)
Call ok(getVT(vbYesNo) = "VT_I2", "getVT(vbYesNo) = " & getVT(vbYesNo))
Call ok(vbRetryCancel = 5, "vbRetryCancel = " & vbRetryCancel)
Call ok(getVT(vbRetryCancel) = "VT_I2", "getVT(vbRetryCancel) = " & getVT(vbRetryCancel))

Call ok(vbOK = 1, "vbOK = " & vbOK)
Call ok(getVT(vbOK) = "VT_I2", "getVT(vbOK) = " & getVT(vbOK))
Call ok(vbCancel = 2, "vbCancel = " & vbCancel)
Call ok(getVT(vbCancel) = "VT_I2", "getVT(vbCancel) = " & getVT(vbCancel))
Call ok(vbAbort = 3, "vbAbort = " & vbAbort)
Call ok(getVT(vbAbort) = "VT_I2", "getVT(vbAbort) = " & getVT(vbAbort))
Call ok(vbRetry = 4, "vbRetry = " & vbRetry)
Call ok(getVT(vbRetry) = "VT_I2", "getVT(vbRetry) = " & getVT(vbRetry))
Call ok(vbIgnore = 5, "vbIgnore = " & vbIgnore)
Call ok(getVT(vbIgnore) = "VT_I2", "getVT(vbIgnore) = " & getVT(vbIgnore))
Call ok(vbYes = 6, "vbYes = " & vbYes)
Call ok(getVT(vbYes) = "VT_I2", "getVT(vbYes) = " & getVT(vbYes))
Call ok(vbNo = 7, "vbNo = " & vbNo)
Call ok(getVT(vbNo) = "VT_I2", "getVT(vbNo) = " & getVT(vbNo))

Call ok(CInt(-36.75) = -37, "CInt(-36.75) = " & CInt(-36.75))
Call ok(getVT(CInt(-36.75)) = "VT_I2", "getVT(CInt(-36.75)) = " & getVT(CInt(-36.75)))
Call ok(CInt(-36.50) = -36, "CInt(-36.50) = " & CInt(-36.50))
Call ok(getVT(CInt(-36.50)) = "VT_I2", "getVT(CInt(-36.50)) = " & getVT(CInt(-36.50)))
Call ok(CInt(-36.25) = -36, "CInt(-36.25) = " & CInt(-36.25))
Call ok(getVT(CInt(-36.25)) = "VT_I2", "getVT(CInt(-36.25)) = " & getVT(CInt(-36.25)))
Call ok(CInt(-36) = -36, "CInt(-36) = " & CInt(-36))
Call ok(getVT(CInt(-36)) = "VT_I2", "getVT(CInt(-36)) = " & getVT(CInt(-36)))
Call ok(CInt(0) = 0, "CInt(0) = " & CInt(0))
Call ok(getVT(CInt(0)) = "VT_I2", "getVT(CInt(0)) = " & getVT(CInt(0)))
Call ok(CInt(0.0) = 0, "CInt(0.0) = " & CInt(0))
Call ok(getVT(CInt(0.0)) = "VT_I2", "getVT(CInt(0.0)) = " & getVT(CInt(0.0)))
Call ok(CInt(0.5) = 0, "CInt(0.5) = " & CInt(0))
Call ok(getVT(CInt(0.5)) = "VT_I2", "getVT(CInt(0.5)) = " & getVT(CInt(0.5)))
Call ok(CInt(36) = 36, "CInt(36) = " & CInt(36))
Call ok(getVT(CInt(36)) = "VT_I2", "getVT(CInt(36)) = " & getVT(CInt(36)))
Call ok(CInt(36.25) = 36, "CInt(36.25) = " & CInt(36.25))
Call ok(getVT(CInt(36.25)) = "VT_I2", "getVT(CInt(36.25)) = " & getVT(CInt(36.25)))
Call ok(CInt(36.50) = 36, "CInt(36.50) = " & CInt(36.50))
Call ok(getVT(CInt(36.50)) = "VT_I2", "getVT(CInt(36.50)) = " & getVT(CInt(36.50)))
Call ok(CInt(36.75) = 37, "CInt(36.75) = " & CInt(36.75))
Call ok(getVT(CInt(36.75)) = "VT_I2", "getVT(CInt(36.75)) = " & getVT(CInt(36.75)))


Call ok(CBool(5) = true, "CBool(5) = " & CBool(5))
Call ok(getVT(CBool(5)) = "VT_BOOL", "getVT(CBool(5)) = " & getVT(CBool(5)))
Call ok(CBool(0) = false, "CBool(0) = " & CBool(0))
Call ok(getVT(CBool(0)) = "VT_BOOL", "getVT(CBool(0)) = " & getVT(CBool(0)))
Call ok(CBool(-5) = true, "CBool(-5) = " & CBool(-5))
Call ok(getVT(CBool(-5)) = "VT_BOOL", "getVT(CBool(-5)) = " & getVT(CBool(-5)))

Sub testCBoolError(strings, error_num)
    on error resume next

    Call Err.clear()
    Call CBool(strings)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

Class ValClass
    Public myval

    Public default Property Get defprop
        defprop = myval
    End Property
End Class

Dim MyObject
Set MyObject = New ValClass

Call ok(CBool(Empty) = False, "CBool(Empty) = " & CBool(Empty))
Call ok(getVT(CBool(Empty)) = "VT_BOOL", "getVT(CBool(Empty)) = " & getVT(CBool(Empty)))
Call ok(CBool(1) = True, "CBool(1) = " & CBool(1))
Call ok(getVT(CBool(1)) = "VT_BOOL", "getVT(CBool(1)) = " & getVT(CBool(1)))
Call ok(CBool(0) = False, "CBool(0) = " & CBool(0))
Call ok(getVT(CBool(0)) = "VT_BOOL", "getVT(CBool(0)) = " & getVT(CBool(0)))
Call ok(CBool(-0.56) = True, "CBool(-0.56) = " & CBool(-0.56))
Call ok(getVT(CBool(-0.56)) = "VT_BOOL", "getVT(CBool(-0.56)) = " & getVT(CBool(-0.56)))
Call testCBoolError("", 13)
Call ok(CBool("0") = False, "CBool(""0"") = " & CBool("0"))
Call ok(getVT(CBool("0")) = "VT_BOOL", "getVT(CBool(""0"")) = " & getVT(CBool("0")))
If isEnglishLang Then
    Call ok(CBool("0.1") = True, "CBool(""0.1"") = " & CBool("0.1"))
    Call ok(getVT(CBool("0.1")) = "VT_BOOL", "getVT(CBool(""0.1"")) = " & getVT(CBool("0.1")))
End If
    Call ok(CBool("true") = True, "CBool(""true"") = " & CBool("true"))
Call ok(getVT(CBool("true")) = "VT_BOOL", "getVT(CBool(""true"")) = " & getVT(CBool("true")))
Call ok(CBool("false") = False, "CBool(""false"") = " & CBool("false"))
Call ok(getVT(CBool("false")) = "VT_BOOL", "getVT(CBool(""false"")) = " & getVT(CBool("false")))
Call ok(CBool("TRUE") = True, "CBool(""TRUE"") = " & CBool("TRUE"))
Call ok(getVT(CBool("TRUE")) = "VT_BOOL", "getVT(CBool(""TRUE"")) = " & getVT(CBool("TRUE")))
Call ok(CBool("FALSE") = False, "CBool(""FALSE"") = " & CBool("FALSE"))
Call ok(getVT(CBool("FALSE")) = "VT_BOOL", "getVT(CBool(""FALSE"")) = " & getVT(CBool("FALSE")))
Call ok(CBool("#TRUE#") = True, "CBool(""#TRUE#"") = " & CBool("#TRUE#"))
Call ok(getVT(CBool("#TRUE#")) = "VT_BOOL", "getVT(CBool(""#TRUE#"")) = " & getVT(CBool("#TRUE#")))
Call ok(CBool("#FALSE#") = False, "CBool(""#FALSE#"") = " & CBool("#FALSE#"))
Call ok(getVT(CBool("#FALSE#")) = "VT_BOOL", "getVT(CBool(""#FALSE#"")) = " & getVT(CBool("#FALSE#")))
Call ok(CBool(MyObject) = False, "CBool(MyObject) = " & CBool(MyObject))
Call ok(getVT(CBool(MyObject)) = "VT_BOOL", "getVT(CBool(MyObject)) = " & getVT(CBool(MyObject)))
MyObject.myval = 1
Call ok(CBool(MyObject) = True, "CBool(MyObject) = " & CBool(MyObject))
Call ok(getVT(CBool(MyObject)) = "VT_BOOL", "getVT(CBool(MyObject)) = " & getVT(CBool(MyObject)))
MyObject.myval = 0
Call ok(CBool(MyObject) = False, "CBool(MyObject) = " & CBool(MyObject))
Call ok(getVT(CBool(MyObject)) = "VT_BOOL", "getVT(CBool(MyObject)) = " & getVT(CBool(MyObject)))

Sub testCByteError(strings, error_num1,error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CByte(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CByte(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CByte(Empty) = 0, "CByte(Empty) = " & CByte(Empty))
Call ok(getVT(CByte(Empty)) = "VT_UI1", "getVT(CByte(Empty)) = " & getVT(CByte(Empty)))
Call ok(CByte(255) = 255, "CByte(255) = " & CByte(255))
Call ok(getVT(CByte(255)) = "VT_UI1", "getVT(CByte(255)) = " & getVT(CByte(255)))
Call ok(CByte(255.49) = 255, "CByte(255.49) = " & CByte(255.49))
Call ok(getVT(CByte(255.49)) = "VT_UI1", "getVT(CByte(255.49)) = " & getVT(CByte(255.49)))
Call testCByteError(1, 0, 458)
Call testCByteError("", 13, 13)
Call testCByteError("-1", 6, 6)
Call testCByteError("258", 6, 6)
Call testCByteError("TRUE", 13, 13)
Call testCByteError("FALSE", 13, 13)
Call testCByteError("#TRue#", 13, 13)
Call testCByteError("#fAlSE#", 13, 13)
If isEnglishLang Then
    Call ok(CByte("-0.5") = 0, "CByte(""-0.5"") = " & CByte("-0.5"))
    Call ok(getVT(CByte("-0.5")) = "VT_UI1", "getVT(CByte(""-0.5"")) = " & getVT(CByte("-0.5")))
End If
Call ok(CByte(True) = 255, "CByte(True) = " & CByte(True))
Call ok(getVT(CByte(True)) = "VT_UI1", "getVT(CByte(True)) = " & getVT(CByte(True)))
Call ok(CByte(False) = 0, "CByte(False) = " & CByte(False))
Call ok(getVT(CByte(False)) = "VT_UI1", "getVT(CByte(False)) = " & getVT(CByte(False)))
Call ok(CByte(MyObject) = 0, "CByte(MyObject) = " & CByte(MyObject))
Call ok(getVT(CByte(MyObject)) = "VT_UI1", "getVT(CByte(MyObject)) = " & getVT(CByte(MyObject)))
MyObject.myval = 1
Call ok(CByte(MyObject) = 1, "CByte(MyObject) = " & CByte(MyObject))
Call ok(getVT(CByte(MyObject)) = "VT_UI1", "getVT(CByte(MyObject)) = " & getVT(CByte(MyObject)))
MyObject.myval = 0
Call ok(CByte(MyObject) = 0, "CByte(MyObject) = " & CByte(MyObject))
Call ok(getVT(CByte(MyObject)) = "VT_UI1", "getVT(CByte(MyObject)) = " & getVT(CByte(MyObject)))

Sub testCCurError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CCur(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CCur(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CCur(Empty) = 0, "CCur(Empty) = " & CCur(Empty))
Call ok(getVT(CCur(Empty)) = "VT_CY", "getVT(CCur(Empty)) = " & getVT(CCur(Empty)))
Call ok(CCur(-32768) = -32768, "CCur(-32768) = " & CCur(-32768))
Call ok(getVT(CCur(-32768)) = "VT_CY", "getVT(CCur(-32768)) = " & getVT(CCur(-32768)))
Call ok(CCur(32768) = 32768, "CCur(32768) = " & CCur(32768))
Call ok(getVT(CCur(32768)) = "VT_CY", "getVT(CCur(32768)) = " & getVT(CCur(32768)))
Call ok(CCur(0.000149) = 0.0001, "CCur(0.000149) = " & CCur(0.000149))
Call ok(getVT(CCur(0.000149)) = "VT_CY", "getVT(CCur(0.000149)) = " & getVT(CCur(0.000149)))
Call ok(CCur(2147483647.99) = 2147483647.99, "CCur(2147483647.99) = " & CCur(2147483647.99))
Call ok(getVT(CCur(2147483647.99)) = "VT_CY", "getVT(CCur(2147483647.99)) = " & getVT(CCur(2147483647.99)))
Call ok(CCur("-1") = -1, "CCur(""-1"") = " & CCur("-1"))
Call ok(getVT(CCur("-1")) = "VT_CY", "getVT(CCur(""-1"")) = " & getVT(CCur("-1")))
If isEnglishLang Then
    Call ok(CCur("-0.5") = -0.5, "CCur(""-0.5"") = " & CCur("-0.5"))
    Call ok(getVT(CCur("-0.5")) = "VT_CY", "getVT(CCur(""-0.5"")) = " & getVT(CCur("-0.5")))
End If
Call testCCurError("", 13, 13)
Call testCCurError("-1", 0, 458)
Call testCCurError("TRUE", 13, 13)
Call testCCurError("FALSE", 13, 13)
Call testCCurError("#TRue#", 13, 13)
Call testCCurError("#fAlSE#", 13, 13)
Call testCCurError(1, 0, 458)
Call ok(CCur(True) = -1, "CCur(True) = " & CCur(True))
Call ok(getVT(CCur(True)) = "VT_CY", "getVT(CCur(True)) = " & getVT(CCur(True)))
Call ok(CCur(False) = 0, "CCur(False) = " & CCur(False))
Call ok(getVT(CCur(False)) = "VT_CY", "getVT(CCur(False)) = " & getVT(CCur(False)))
MyObject.myval = 0.1
Call ok(CCur(MyObject) = 0.1, "CCur(MyObject) = " & CCur(MyObject))
Call ok(getVT(CCur(MyObject)) = "VT_CY", "getVT(CCur(MyObject)) = " & getVT(CCur(MyObject)))
MyObject.myval = 0
Call ok(CCur(MyObject) = 0, "CCur(MyObject) = " & CCur(MyObject))
Call ok(getVT(CCur(MyObject)) = "VT_CY", "getVT(CCur(MyObject)) = " & getVT(CCur(MyObject)))

Sub testCDateError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CDate(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CDate(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CDate(Empty) = 0, "CDate(Empty) = " & CDate(Empty))
Call ok(getVT(CDate(Empty)) = "VT_DATE", "getVT(CDate(Empty)) = " & getVT(CDate(Empty)))
Call ok(CDate(0) = 0, "CDate(0) = " & CDate(0))
Call ok(getVT(CDate(0)) = "VT_DATE", "getVT(CDate(0)) = " & getVT(CDate(0)))
Call ok(CDate(1) = #1899-12-31#, "CDate(1) = " & CDate(1))
Call ok(getVT(CDate(1)) = "VT_DATE", "getVT(CDate(1)) = " & getVT(CDate(1)))
Call ok(CDate("1") = #1899-12-31#, "CDate(""1"") = " & CDate("1"))
Call ok(getVT(CDate("1")) = "VT_DATE", "getVT(CDate(""1"")) = " & getVT(CDate("1")))
If isEnglishLang Then
    Call ok(CDate("1/1/2000") = #2000-1-1#, "CDate(""1/1/2000"") = " & CDate("1/1/2000"))
    Call ok(getVT(CDate("1/1/2000")) = "VT_DATE", "getVT(CDate(""1/1/2000"")) = " & getVT(CDate("1/1/2000")))
End If
Call ok(CDate(-1) = #1899-12-29#, "CDate(-1) = " & CDate(-1))
Call ok(getVT(CDate(-1)) = "VT_DATE", "getVT(CDate(-1)) = " & getVT(CDate(-1)))
Call ok(CDate(100000) = #2173-10-14#, "CDate(100000) = " & CDate(100000))
Call ok(getVT(CDate(100000)) = "VT_DATE", "getVT(CDate(100000)) = " & getVT(CDate(100000)))
Call testCDateError("", 13, 13)
Call testCDateError(null, 94, 94)
Call testCDateError(1, 0, 458)

Sub testCDblError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CDbl(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CDbl(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CDbl(Empty) = 0, "CDbl(Empty) = " & CDbl(Empty))
Call ok(getVT(CDbl(Empty)) = "VT_R8", "getVT(CDbl(Empty)) = " & getVT(CDbl(Empty)))
Call ok(CDbl(CByte(0)) = 0, "CDbl(CByte(0)) = " & CDbl(CByte(0)))
Call ok(getVT(CDbl(CCur(0))) = "VT_R8", "getVT(CDbl(CCur(0))) = " & getVT(CDbl(CCur(0))))
Call ok(CDbl(CCur(0)) = 0, "CDbl(CCur(0)) = " & CDbl(CCur(0)))
Call ok(getVT(CDbl(CCur(0))) = "VT_R8", "getVT(CDbl(CCur(0))) = " & getVT(CDbl(CCur(0))))
Call ok(CDbl(0) = 0, "CDbl(0) = " & CDbl(0))
Call ok(getVT(CDbl(0)) = "VT_R8", "getVT(CDbl(0)) = " & getVT(CDbl(0)))
Call ok(CDbl(32768) = 32768, "CDbl(32768) = " & CDbl(32768))
Call ok(getVT(CDbl(32768)) = "VT_R8", "getVT(CDbl(32768)) = " & getVT(CDbl(32768)))
Call ok(CDbl(0.001 * 0.001) = 0.000001, "CDbl(0.001 * 0.001) = " & CDbl(0.001 * 0.001))
Call ok(getVT(CDbl(0.001 * 0.001)) = "VT_R8", "getVT(CDbl(0.001 * 0.001)) = " & getVT(CDbl(0.001 * 0.001)))
Call ok(CDbl("-1") = -1, "CDbl(""-1"") = " & CDbl("-1"))
Call ok(getVT(CDbl("-1")) = "VT_R8", "getVT(CDbl(""-1"")) = " & getVT(CDbl("-1")))
If isEnglishLang Then
    Call ok(CDbl("-0.5") = -0.5, "CDbl(""-0.5"") = " & CDbl("-0.5"))
    Call ok(getVT(CDbl("-0.5")) = "VT_R8", "getVT(CDbl(""-0.5"")) = " & getVT(CDbl("-0.5")))
End If
Call testCDblError("", 13, 13)
Call testCDblError("TRUE", 13, 13)
Call testCDblError("FALSE", 13, 13)
Call testCDblError("#TRue#", 13, 13)
Call testCDblError("#fAlSE#", 13, 13)
Call testCDblError(1, 0, 458)
Call ok(CDbl(True) = -1, "CDbl(True) = " & CDbl(True))
Call ok(getVT(CDbl(True)) = "VT_R8", "getVT(CDbl(True)) = " & getVT(CDbl(True)))
Call ok(CDbl(False) = 0, "CDbl(False) = " & CDbl(False))
Call ok(getVT(CDbl(False)) = "VT_R8", "getVT(CDbl(False)) = " & getVT(CDbl(False)))
MyObject.myval = 0.1
Call ok(CDbl(MyObject) = 0.1, "CDbl(MyObject) = " & CDbl(MyObject))
Call ok(getVT(CDbl(MyObject)) = "VT_R8", "getVT(CDbl(MyObject)) = " & getVT(CDbl(MyObject)))
MyObject.myval = 0
Call ok(CDbl(MyObject) = 0, "CDbl(MyObject) = " & CDbl(MyObject))
Call ok(getVT(CDbl(MyObject)) = "VT_R8", "getVT(CDbl(MyObject)) = " & getVT(CDbl(MyObject)))

Sub testCLngError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CLng(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CLng(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CLng(Empty) = 0, "CLng(Empty) = " & CLng(Empty))
Call ok(getVT(CLng(Empty)) = "VT_I4", "getVT(CLng(Empty)) = " & getVT(CLng(Empty)))
Call ok(CLng(CByte(0)) = 0, "CLng(CByte(0)) = " & CLng(CByte(0)))
Call ok(getVT(CLng(CCur(0))) = "VT_I4", "getVT(CLng(CCur(0))) = " & getVT(CLng(CCur(0))))
Call ok(CLng(CCur(0)) = 0, "CLng(CCur(0)) = " & CLng(CCur(0)))
Call ok(getVT(CLng(CCur(0))) = "VT_I4", "getVT(CLng(CCur(0))) = " & getVT(CLng(CCur(0))))
Call ok(CLng(0) = 0, "CLng(0) = " & CLng(0))
Call ok(getVT(CLng(0)) = "VT_I4", "getVT(CLng(0)) = " & getVT(CLng(0)))
Call ok(CLng(0.49) = 0, "CLng(0.49) = " & CLng(0.49))
Call ok(getVT(CLng(0.49)) = "VT_I4", "getVT(CLng(0.49)) = " & getVT(CLng(0.49)))
Call ok(CLng(0.5) = 0, "CLng(0.5) = " & CLng(0.5))
Call ok(getVT(CLng(0.5)) = "VT_I4", "getVT(CLng(0.5)) = " & getVT(CLng(0.5)))
Call ok(CLng(0.51) = 1, "CLng(0.51) = " & CLng(0.51))
Call ok(getVT(CLng(0.51)) = "VT_I4", "getVT(CLng(0.51)) = " & getVT(CLng(0.51)))
Call ok(CLng(1.49) = 1, "CLng(1.49) = " & CLng(1.49))
Call ok(getVT(CLng(1.49)) = "VT_I4", "getVT(CLng(1.49)) = " & getVT(CLng(1.49)))
Call ok(CLng(1.5) = 2, "CLng(1.5) = " & CLng(1.5))
Call ok(getVT(CLng(1.5)) = "VT_I4", "getVT(CLng(1.5)) = " & getVT(CLng(1.5)))
Call ok(CLng(1.51) = 2, "CLng(1.51) = " & CLng(1.51))
Call ok(getVT(CLng(1.51)) = "VT_I4", "getVT(CLng(1.51)) = " & getVT(CLng(1.51)))
Call ok(CLng("-1") = -1, "CLng(""-1"") = " & CLng("-1"))
Call ok(getVT(CLng("-1")) = "VT_I4", "getVT(CLng(""-1"")) = " & getVT(CLng("-1")))
If isEnglishLang Then
    Call ok(CLng("-0.5") = 0, "CLng(""-0.5"") = " & CLng("-0.5"))
    Call ok(getVT(CLng("-0.5")) = "VT_I4", "getVT(CLng(""-0.5"")) = " & getVT(CLng("-0.5")))
End If
Call testCLngError("", 13, 13)
Call testCLngError("TRUE", 13, 13)
Call testCLngError("FALSE", 13, 13)
Call testCLngError("#TRue#", 13, 13)
Call testCLngError("#fAlSE#", 13, 13)
Call testCLngError(1, 0, 458)
Call ok(CLng(True) = -1, "CLng(True) = " & CLng(True))
Call ok(getVT(CLng(True)) = "VT_I4", "getVT(CLng(True)) = " & getVT(CLng(True)))
Call ok(CLng(False) = 0, "CLng(False) = " & CLng(False))
Call ok(getVT(CLng(False)) = "VT_I4", "getVT(CLng(False)) = " & getVT(CLng(False)))
MyObject.myval = 1
Call ok(CLng(MyObject) = 1, "CLng(MyObject) = " & CLng(MyObject))
Call ok(getVT(CLng(MyObject)) = "VT_I4", "getVT(CLng(MyObject)) = " & getVT(CLng(MyObject)))
MyObject.myval = 0
Call ok(CLng(MyObject) = 0, "CLng(MyObject) = " & CLng(MyObject))
Call ok(getVT(CLng(MyObject)) = "VT_I4", "getVT(CLng(MyObject)) = " & getVT(CLng(MyObject)))

Sub testCIntError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CInt(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CInt(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CInt(Empty) = 0, "CInt(Empty) = " & CInt(Empty))
Call ok(getVT(CInt(Empty)) = "VT_I2", "getVT(CInt(Empty)) = " & getVT(CInt(Empty)))
Call ok(CInt(CByte(0)) = 0, "CInt(CByte(0)) = " & CInt(CByte(0)))
Call ok(getVT(CInt(CByte(0))) = "VT_I2", "getVT(CInt(CByte(0))) = " & getVT(CInt(CByte(0))))
Call ok(CInt(CCur(0)) = 0, "CInt(CCur(0)) = " & CInt(CCur(0)))
Call ok(getVT(CInt(CCur(0))) = "VT_I2", "getVT(CInt(CCur(0))) = " & getVT(CInt(CCur(0))))
Call ok(CInt(0.49) = 0, "CInt(0.49) = " & CInt(0.49))
Call ok(getVT(CInt(0.49)) = "VT_I2", "getVT(CInt(0.49)) = " & getVT(CInt(0.49)))
Call ok(CInt(0.5) = 0, "CInt(0.5) = " & CInt(0.5))
Call ok(getVT(CInt(0.5)) = "VT_I2", "getVT(CInt(0.5)) = " & getVT(CInt(0.5)))
Call ok(CInt(0.51) = 1, "CInt(0.51) = " & CInt(0.51))
Call ok(getVT(CInt(0.51)) = "VT_I2", "getVT(CInt(0.51)) = " & getVT(CInt(0.51)))
Call ok(CInt(1.49) = 1, "CInt(0.49) = " & CInt(0.49))
Call ok(getVT(CInt(0.49)) = "VT_I2", "getVT(CInt(0.49)) = " & getVT(CInt(0.49)))
Call ok(CInt(1.5) = 2, "CInt(1.5) = " & CInt(1.5))
Call ok(getVT(CInt(1.5)) = "VT_I2", "getVT(CInt(1.5)) = " & getVT(CInt(1.5)))
Call ok(CInt(1.51) = 2, "CInt(1.51) = " & CInt(1.51))
Call ok(getVT(CInt(1.51)) = "VT_I2", "getVT(CInt(1.51)) = " & getVT(CInt(1.51)))
Call ok(CInt("-1") = -1, "CInt(""-1"") = " & CInt("-1"))
Call ok(getVT(CInt("-1")) = "VT_I2", "getVT(CInt(""-1"")) = " & getVT(CInt("-1")))
If isEnglishLang Then
    Call ok(CInt("-0.5") = 0, "CInt(""-0.5"") = " & CInt("-0.5"))
    Call ok(getVT(CInt("-0.5")) = "VT_I2", "getVT(CInt(""-0.5"")) = " & getVT(CInt("-0.5")))
End If
Call testCIntError("", 13, 13)
Call testCIntError("-1", 0, 458)
Call testCIntError("TRUE", 13, 13)
Call testCIntError("FALSE", 13, 13)
Call testCIntError("#TRue#", 13, 13)
Call testCIntError("#fAlSE#", 13, 13)
Call testCIntError(1, 0, 458)
Call testCIntError(32767.49, 0, 458)
Call testCIntError(32767.5, 6, 6)
Call testCIntError(-32768.5, 0, 458)
Call testCIntError(-32768.51, 6, 6)
Call ok(CInt(True) = -1, "CInt(True) = " & CInt(True))
Call ok(getVT(CInt(True)) = "VT_I2", "getVT(CInt(True)) = " & getVT(CInt(True)))
Call ok(CInt(False) = 0, "CInt(False) = " & CInt(False))
Call ok(getVT(CInt(False)) = "VT_I2", "getVT(CInt(False)) = " & getVT(CInt(False)))
MyObject.myval = 2.5
Call ok(CInt(MyObject) = 2, "CInt(MyObject) = " & CInt(MyObject))
Call ok(getVT(CInt(MyObject)) = "VT_I2", "getVT(CInt(MyObject)) = " & getVT(CInt(MyObject)))
MyObject.myval = 1.5
Call ok(CInt(MyObject) = 2, "CInt(MyObject) = " & CInt(MyObject))
Call ok(getVT(CInt(MyObject)) = "VT_I2", "getVT(CInt(MyObject)) = " & getVT(CInt(MyObject)))

Sub testCSngError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = CSng(strings)
    Call ok(Err.number = error_num1, "Err.number = " & Err.number)

    Call Err.clear()
    Call CSng(strings)
    Call ok(Err.number = error_num2, "Err.number = " & Err.number)
End Sub

Call ok(CSng(Empty) = 0, "CSng(Empty) = " & CSng(Empty))
Call ok(getVT(CSng(Empty)) = "VT_R4", "getVT(CSng(Empty)) = " & getVT(CSng(Empty)))
Call ok(CSng(CByte(0)) = 0, "CSng(CByte(0)) = " & CSng(CByte(0)))
Call ok(getVT(CSng(CCur(0))) = "VT_R4", "getVT(CSng(CCur(0))) = " & getVT(CSng(CCur(0))))
Call ok(CSng(CCur(0)) = 0, "CSng(CCur(0)) = " & CSng(CCur(0)))
Call ok(getVT(CSng(CCur(0))) = "VT_R4", "getVT(CSng(CCur(0))) = " & getVT(CSng(CCur(0))))
Call ok(CSng(0) = 0, "CSng(0) = " & CSng(0))
Call ok(getVT(CSng(0)) = "VT_R4", "getVT(CSng(0)) = " & getVT(CSng(0)))
Call ok(CSng(32768) = 32768, "CSng(32768) = " & CSng(32768))
Call ok(getVT(CSng(32768)) = "VT_R4", "getVT(CSng(32768)) = " & getVT(CSng(32768)))
Call ok(CSng(0.001 * 0.001) = 0.000001, "CSng(0.001 * 0.001) = " & CSng(0.001 * 0.001))
Call ok(getVT(CSng(0.001 * 0.001)) = "VT_R4", "getVT(CSng(0.001 * 0.001)) = " & getVT(CSng(0.001 * 0.001)))
Call ok(CSng("-1") = -1, "CSng(""-1"") = " & CSng("-1"))
Call ok(getVT(CSng("-1")) = "VT_R4", "getVT(CSng(""-1"")) = " & getVT(CSng("-1")))
If isEnglishLang Then
    Call ok(CSng("-0.5") = -0.5, "CSng(""-0.5"") = " & CSng("-0.5"))
    Call ok(getVT(CSng("-0.5")) = "VT_R4", "getVT(CSng(""-0.5"")) = " & getVT(CSng("-0.5")))
End If
Call testCSngError("", 13, 13)
Call testCSngError("TRUE", 13, 13)
Call testCSngError("FALSE", 13, 13)
Call testCSngError("#TRue#", 13, 13)
Call testCSngError("#fAlSE#", 13, 13)
Call testCSngError(1, 0, 458)
Call ok(CSng(True) = -1, "CSng(True) = " & CSng(True))
Call ok(getVT(CSng(True)) = "VT_R4", "getVT(CSng(True)) = " & getVT(CSng(True)))
Call ok(CSng(False) = 0, "CSng(False) = " & CSng(False))
Call ok(getVT(CSng(False)) = "VT_R4", "getVT(CSng(False)) = " & getVT(CSng(False)))
MyObject.myval = 0.1
Call ok(CSng(MyObject) = 0.1, "CSng(MyObject) = " & CSng(MyObject))
Call ok(getVT(CSng(MyObject)) = "VT_R4", "getVT(CSng(MyObject)) = " & getVT(CSng(MyObject)))
MyObject.myval = 0
Call ok(CSng(MyObject) = 0, "CSng(MyObject) = " & CSng(MyObject))
Call ok(getVT(CSng(MyObject)) = "VT_R4", "getVT(CSng(MyObject)) = " & getVT(CSng(MyObject)))

Call ok(TypeName(Nothing) = "Nothing", "TypeName(Nothing) = " & TypeName(Nothing))
Call ok(getVT(TypeName(Nothing)) = "VT_BSTR", "getVT(TypeName(Nothing)) = " & getVT(TypeName(Nothing)))
Call ok(TypeName(Empty) = "Empty", "TypeName(Empty) = " & TypeName(Empty))
Call ok(getVT(TypeName(Empty)) = "VT_BSTR", "getVT(TypeName(Empty)) = " & getVT(TypeName(Empty)))
Call ok(TypeName(Null) = "Null", "TypeName(Null) = " & TypeName(Null))
Call ok(getVT(TypeName(Null)) = "VT_BSTR", "getVT(TypeName(Null)) = " & getVT(TypeName(Null)))
Call ok(TypeName(CByte(255)) = "Byte", "TypeName(CByte(255)) = " & TypeName(CByte(255)))
Call ok(getVT(TypeName(CByte(255))) = "VT_BSTR", "getVT(TypeName(CByte(255))) = " & getVT(TypeName(CByte(255))))
Call ok(TypeName(255) = "Integer", "TypeName(255) = " & TypeName(255))
Call ok(getVT(TypeName(255)) = "VT_BSTR", "getVT(TypeName(255)) = " & getVT(TypeName(255)))
Call ok(TypeName(32768) = "Long", "TypeName(32768) = " & TypeName(32768))
Call ok(getVT(TypeName(32768)) = "VT_BSTR", "getVT(TypeName(32768)) = " & getVT(TypeName(32768)))
Call ok(TypeName(CSng(0.5)) = "Single", "TypeName(CSng(0.5)) = " & TypeName(CSng(0.5)))
Call ok(getVT(TypeName(CSng(0.5))) = "VT_BSTR", "getVT(TypeName(CSng(0.5))) = " & getVT(TypeName(CSng(0.5))))
Call ok(TypeName(-0.5) = "Double", "TypeName(-0.5) = " & TypeName(-0.5))
Call ok(getVT(TypeName(-0.5)) = "VT_BSTR", "getVT(TypeName(-0.5)) = " & getVT(TypeName(-0.5)))
Call ok(TypeName(CCur(0.5)) = "Currency", "TypeName(CCur(0.5)) = " & TypeName(CCur(0.5)))
Call ok(getVT(TypeName(CCur(0.5))) = "VT_BSTR", "getVT(TypeName(CCur(0.5))) = " & getVT(TypeName(CCur(0.5))))
Call ok(TypeName(CStr(0.5)) = "String", "TypeName(CStr(0.5)) = " & TypeName(CStr(0.5)))
Call ok(getVT(TypeName(CStr(0.5))) = "VT_BSTR", "getVT(TypeName(CStr(0.5))) = " & getVT(TypeName(CStr(0.5))))
Call ok(TypeName(True) = "Boolean", "TypeName(True) = " & TypeName(True))
Call ok(getVT(TypeName(True)) = "VT_BSTR", "getVT(TypeName(True)) = " & getVT(TypeName(True)))
Call ok(TypeName(arr) = "Variant()", "TypeName(arr) = " & TypeName(arr))
Call ok(getVT(TypeName(arr)) = "VT_BSTR", "getVT(TypeName(arr)) = " & getVT(TypeName(arr)))
Call ok(TypeName(collectionObj) = "Object", "TypeName(collectionObj) = " & TypeName(collectionObj))
Dim regex
set regex = new RegExp
Call ok(TypeName(regex) = "IRegExp2", "TypeName(regex) = " & TypeName(regex))

Call ok(VarType(Empty) = vbEmpty, "VarType(Empty) = " & VarType(Empty))
Call ok(getVT(VarType(Empty)) = "VT_I2", "getVT(VarType(Empty)) = " & getVT(VarType(Empty)))
Call ok(VarType(Null) = vbNull, "VarType(Null) = " & VarType(Null))
Call ok(getVT(VarType(Null)) = "VT_I2", "getVT(VarType(Null)) = " & getVT(VarType(Null)))
Call ok(VarType(255) = vbInteger, "VarType(255) = " & VarType(255))
Call ok(getVT(VarType(255)) = "VT_I2", "getVT(VarType(255)) = " & getVT(VarType(255)))
set x = new EmptyClass
Call ok(VarType(x) = vbObject, "VarType(x) = " & VarType(x))
Call ok(getVT(VarType(x)) = "VT_I2", "getVT(VarType(x)) = " & getVT(VarType(x)))
Call ok(VarType(32768) = vbLong, "VarType(32768) = " & VarType(32768))
Call ok(getVT(VarType(32768)) = "VT_I2", "getVT(VarType(32768)) = " & getVT(VarType(32768)))
Call ok(VarType(CSng(0.5)) = vbSingle, "VarType(CSng(0.5)) = " & VarType(CSng(0.5)))
Call ok(getVT(VarType(CSng(0.5))) = "VT_I2", "getVT(VarType(CSng(0.5))) = " & getVT(VarType(CSng(0.5))))
Call ok(VarType(-0.5) = vbDouble, "VarType(-0.5) = " & VarType(-0.5))
Call ok(getVT(VarType(-0.5)) = "VT_I2", "getVT(VarType(-0.5)) = " & getVT(VarType(-0.5)))
Call ok(VarType(CCur(0.5)) = vbCurrency, "VarType(CCur(0.5)) = " & VarType(CCur(0.5)))
Call ok(getVT(VarType(CCur(0.5))) = "VT_I2", "getVT(VarType(CCur(0.5))) = " & getVT(VarType(CCur(0.5))))
Call ok(VarType(CStr(0.5)) = vbString, "VarType(CStr(0.5)) = " & VarType(CStr(0.5)))
Call ok(getVT(VarType(CStr(0.5))) = "VT_I2", "getVT(VarType(CStr(0.5))) = " & getVT(VarType(CStr(0.5))))
Call ok(VarType(CBool(0.5)) = vbBoolean, "VarType(CBool(0.5)) = " & VarType(CBool(0.5)))
Call ok(getVT(VarType(CBool(0.5))) = "VT_I2", "getVT(VarType(CBool(0.5))) = " & getVT(VarType(CBool(0.5))))
Call ok(VarType(CByte(255)) = vbByte, "VarType(CByte(255)) = " & VarType(CByte(255)))
Call ok(getVT(VarType(CByte(255))) = "VT_I2", "getVT(VarType(CByte(255))) = " & getVT(VarType(CByte(255))))
Call ok(VarType(arr) = (vbArray or vbVariant), "VarType(arr) = " & VarType(arr))
Call ok(getVT(VarType(arr)) = "VT_I2", "getVT(VarType(arr)) = " & getVT(VarType(arr)))

Call ok(Sgn(Empty) = 0, "Sgn(MyEmpty) = " & Sgn(Empty))
Call ok(getVT(Sgn(Empty)) = "VT_I2", "getVT(Sgn(MyEmpty)) = " & getVT(Sgn(Empty)))
Call ok(Sgn(0) = 0, "Sgn(0) = " & Sgn(0))
Call ok(getVT(Sgn(0)) = "VT_I2", "getVT(Sgn(0)) = " & getVT(Sgn(0)))
Call ok(Sgn(-32769) = -1, "Sgn(-32769) = " & Sgn(-32769))
Call ok(getVT(Sgn(-32769)) = "VT_I2", "getVT(Sgn(-32769)) = " & getVT(Sgn(-32769)))
Call ok(Sgn(CSng(-0.5)) = -1, "Sgn(CSng(-0.5)) = " & Sgn(CSng(-0.5)))
Call ok(getVT(Sgn(CSng(-0.5))) = "VT_I2", "getVT(Sgn(CSng(-0.5))) = " & getVT(Sgn(CSng(-0.5))))
Call ok(Sgn(0.5) = 1, "Sgn(0.5) = " & Sgn(0.5))
Call ok(getVT(Sgn(0.5)) = "VT_I2", "getVT(Sgn(0.5)) = " & getVT(Sgn(0.5)))
Call ok(Sgn(CCur(-1)) = -1, "Sgn(CCur(-1)) = " & Sgn(CCur(-1)))
Call ok(getVT(Sgn(CCur(-1))) = "VT_I2", "getVT(Sgn(CCur(-1))) = " & getVT(Sgn(CCur(-1))))
Call ok(Sgn(CStr(-1)) = -1, "Sgn(CStr(-1)) = " & Sgn(CStr(-1)))
Call ok(getVT(Sgn(CStr(-1))) = "VT_I2", "getVT(Sgn(CStr(-1))) = " & getVT(Sgn(CStr(-1))))
Call ok(Sgn(False) = 0, "Sgn(False) = " & Sgn(False))
Call ok(getVT(Sgn(False)) = "VT_I2", "getVT(Sgn(False)) = " & getVT(Sgn(False)))
Call ok(Sgn(True) = -1, "Sgn(True) = " & Sgn(True))
Call ok(getVT(Sgn(True)) = "VT_I2", "getVT(Sgn(True)) = " & getVT(Sgn(True)))
Call ok(Sgn(CByte(1)) = 1, "Sgn(CByte(1)) = " & Sgn(CByte(1)))
Call ok(getVT(Sgn(CByte(1))) ="VT_I2", "getVT(Sgn(CByte(1))) = " & getVT(Sgn(CByte(1))))

Sub testSgnError(strings, error_num)
    on error resume next

    Call Err.clear()
    Call Sgn(strings)
    Call ok(Err.number = error_num, "Err.number = " & Err.number)
End Sub

Call testSgnError(Null, 94)

Call ok(Abs(Empty) = 0, "Abs(Empty) = " & Abs(Empty))
Call ok(getVT(Abs(Empty)) = "VT_I2", "getVT(Abs(Empty)) = " & getVT(Abs(Empty)))
Call ok(IsNull(Abs(Null)), "Is Abs(Null) not Null?")
Call ok(getVT(Abs(Null)) = "VT_NULL", "getVT(Abs(Null)) = " & getVT(Abs(Null)))
Call ok(Abs(0) = 0, "Abs(0) = " & Abs(0))
Call ok(getVT(Abs(0)) = "VT_I2", "getVT(Abs(0)) = " & getVT(Abs(0)))
Call ok(Abs(-32769) = 32769, "Abs(-32769) = " & Abs(-32769))
Call ok(getVT(Abs(-32769)) = "VT_I4", "getVT(Abs(-32769)) = " & getVT(Abs(-32769)))
Call ok(Abs(CSng(-0.5)) = 0.5, "Abs(CSng(-0.5)) = " & Abs(CSng(-0.5)))
Call ok(getVT(Abs(CSng(-0.5))) = "VT_R4", "getVT(Abs(CSng(-0.5))) = " & getVT(Abs(CSng(-0.5))))
Call ok(Abs(0.5) = 0.5, "Abs(0.5) = " & Abs(0.5))
Call ok(getVT(Abs(0.5)) = "VT_R8", "getVT(Abs(0.5)) = " & getVT(Abs(0.5)))
Call ok(Abs(CCur(-1)) = 1, "Abs(CCur(-1)) = " & Abs(CCur(-1)))
Call ok(getVT(Abs(CCur(-1))) = "VT_CY", "getVT(Abs(CCur(-1))) = " & getVT(Abs(CCur(-1))))
Call ok(Abs("-1") = 1, "Abs(""-1"") = " & Abs("-1"))
Call ok(getVT(Abs("-1")) = "VT_R8", "getVT(Abs(""-1"")) = " & getVT(Abs("-1")))
Call ok(Abs(False) = 0, "Abs(False) = " & Abs(False))
Call ok(getVT(Abs(False)) = "VT_I2", "getVT(Abs(False)) = " & getVT(Abs(False)))
Call ok(Abs(True) = 1, "Abs(True) = " & Abs(True))
Call ok(getVT(Abs(True)) = "VT_I2", "getVT(Abs(True)) = " & getVT(Abs(True)))
Call ok(Abs(CByte(1)) = 1, "Abs(CByte(1)) = " & Abs(CByte(1)))
Call ok(getVT(Abs(CByte(1))) = "VT_UI1", "getVT(Abs(CByte(1))) = " & getVT(Abs(CByte(1))))
Call ok(Abs("30000") = 30000, "Abs(""30000"") = " & Abs("30000"))

Sub testAbsError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = Abs(strings)
    Call ok(Err.number = error_num1, "Err.number1 = " & Err.number)

    Call Err.clear()
    Call Abs(strings)
    Call ok(Err.number = error_num2, "Err.number2 = " & Err.number)
End Sub

Call testAbsError("strings", 13, 13)
Call testAbsError(-4, 0, 0)

Call ok(ScriptEngine = "VBScript", "Is scriptengine not VBScript?")
Call ok(getVT(ScriptEngine) = "VT_BSTR", "getVT(ScriptEngine) = " & getVT(ScriptEngine))

Call ok(getVT(ScriptEngineBuildVersion) = "VT_I4", "getVT(ScriptEngineBuildVersion) = " & getVT(ScriptEngineBuildVersion))

Call ok(getVT(ScriptEngineMajorVersion) = "VT_I4", "getVT(ScriptEngineMajorVersion) = " & getVT(ScriptEngineMajorVersion))

Call ok(getVT(ScriptEngineMinorVersion) = "VT_I4", "getVT(ScriptEngineMinorVersion) = " & getVT(ScriptEngineMinorVersion))

Call ok(Fix(Empty) = 0, "Fix(Empty) = " & Fix(Empty))
Call ok(getVT(Fix(Empty)) = "VT_I2", "getVT(Fix(Empty)) = " & getVT(Fix(Empty)))
Call ok(Fix(CCur(-0.99)) = 0, "Fix(CCur(-0.99)) = " & Fix(CCur(-0.99)))
Call ok(getVT(Fix(CCur(-0.99))) = "VT_CY", "getVT(Fix(CCur(-0.99))) = " & getVT(Fix(CCur(-0.99))))
Call ok(Fix(1.99) = 1, "Fix(1.99) = " & Fix(1.99))
Call ok(getVT(Fix(1.99)) = "VT_R8", "getVT(Fix(1.99)) = " & getVT(Fix(1.99)))
Call ok(Fix(-1.99) = -1, "Fix(-1.99) = " & Fix(-1.99))
Call ok(getVT(Fix(-1.99)) = "VT_R8", "getVT(Fix(-1.99)) = " & getVT(Fix(-1.99)))
If isEnglishLang Then
    Call ok(Fix("1.99") = 1, "Fix(""1.99"") = " & Fix("1.99"))
    Call ok(getVT(Fix("1.99")) = "VT_R8", "getVT(Fix(""1.99"")) = " & getVT(Fix("1.99")))
    Call ok(Fix("-1.99") = -1, "Fix(""-1.99"") = " & Fix("-1.99"))
    Call ok(getVT(Fix("-1.99")) = "VT_R8", "getVT(Fix(""-1.99"")) = " & getVT(Fix("-1.99")))
End If
Call ok(Fix(True) = -1, "Fix(True) = " & Fix(True))
Call ok(getVT(Fix(True)) = "VT_I2", "getVT(Fix(True)) = " & getVT(Fix(True)))
Call ok(Fix(False) = 0, "Fix(False) = " & Fix(False))
Call ok(getVT(Fix(False)) = "VT_I2", "getVT(Fix(False)) = " & getVT(Fix(False)))
MyObject.myval = 2.5
Call ok(Fix(MyObject) = 2, "Fix(MyObject) = " & Fix(MyObject))
Call ok(getVT(Fix(MyObject)) = "VT_R8", "getVT(Fix(MyObject)) = " & getVT(Fix(MyObject)))
MyObject.myval = -2.5
Call ok(Fix(MyObject) = -2, "Fix(MyObject) = " & Fix(MyObject))
Call ok(getVT(Fix(MyObject)) = "VT_R8", "getVT(Fix(MyObject)) = " & getVT(Fix(MyObject)))

Call ok(Int(Empty) = 0, "Int(Empty) = " & Int(Empty))
Call ok(getVT(Int(Empty)) = "VT_I2", "getVT(Int(Empty)) = " & getVT(Int(Empty)))
Call ok(Int(CCur(-0.99)) = -1, "Int(CCur(-0.99)) = " & Int(CCur(-0.99)))
Call ok(getVT(Int(CCur(-0.99))) = "VT_CY", "getVT(Int(CCur(-0.99))) = " & getVT(Int(CCur(-0.99))))
Call ok(Int(1.99) = 1, "Int(1.99) = " & Int(1.99))
Call ok(getVT(Int(1.99)) = "VT_R8", "getVT(Int(1.99)) = " & getVT(Int(1.99)))
Call ok(Int(-1.99) = -2, "Int(-1.99) = " & Int(-1.99))
Call ok(getVT(Int(-1.99)) = "VT_R8", "getVT(Int(-1.99)) = " & getVT(Int(-1.99)))
If isEnglishLang Then
    Call ok(Int("1.99") = 1, "Int(""1.99"") = " & Int("1.99"))
    Call ok(getVT(Int("1.99")) = "VT_R8", "getVT(Int(""1.99"")) = " & getVT(Int("1.99")))
    Call ok(Int("-1.99") = -2, "Int(""-1.99"") = " & Int("-1.99"))
    Call ok(getVT(Int("-1.99")) = "VT_R8", "getVT(Int(""-1.99"")) = " & getVT(Int("-1.99")))
End If
Call ok(Int(True) = -1, "Int(True) = " & Int(True))
Call ok(getVT(Int(True)) = "VT_I2", "getVT(Int(True)) = " & getVT(Int(True)))
Call ok(Int(False) = 0, "Int(False) = " & Int(False))
Call ok(getVT(Int(False)) = "VT_I2", "getVT(Int(False)) = " & getVT(Int(False)))
MyObject.myval = 2.5
Call ok(Int(MyObject) = 2, "Int(MyObject) = " & Int(MyObject))
Call ok(getVT(Int(MyObject)) = "VT_R8", "getVT(Int(MyObject)) = " & getVT(Int(MyObject)))
MyObject.myval = -2.5
Call ok(Int(MyObject) = -3, "Int(MyObject) = " & Int(MyObject))
Call ok(getVT(Int(MyObject)) = "VT_R8", "getVT(Int(MyObject)) = " & getVT(Int(MyObject)))

Sub testSqrError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = Sqr(strings)
    Call ok(Err.number = error_num1, "Err.number1 = " & Err.number)

    Call Err.clear()
    Call Sqr(strings)
    Call ok(Err.number = error_num2, "Err.number2 = " & Err.number)
End Sub

Call testSqrError(-2, 5, 5)
Call testSqrError(True, 5, 5)

Call ok(Sqr(Empty) = 0, "Sqr(Empty) = " & Sqr(Empty))
Call ok(getVT(Sqr(Empty)) = "VT_R8", "getVT(Sqr(Empty)) = " & getVT(Sqr(Empty)))
Call ok(Sqr(0) = 0, "Sqr(0) = " & Sqr(0))
Call ok(getVT(Sqr(0)) = "VT_R8", "getVT(Sqr(0)) = " & getVT(Sqr(0)))
Call ok(Sqr(1) = 1, "Sqr(1) = " & Sqr(1))
Call ok(getVT(Sqr(1)) = "VT_R8", "getVT(Sqr(1)) = " & getVT(Sqr(1)))
Call ok(Sqr(CSng(121)) = 11, "Sqr(CSng(121)) = " & Sqr(CSng(121)))
Call ok(getVT(Sqr(CSng(121))) = "VT_R8", "getVT(Sqr(CSng(121))) = " & getVT(Sqr(CSng(121))))
Call ok(Sqr(36100) = 190, "Sqr(36100) = " & Sqr(36100))
Call ok(getVT(Sqr(36100)) = "VT_R8", "getVT(Sqr(36100)) = " & getVT(Sqr(36100)))
Call ok(Sqr(CCur(0.0625)) = 0.25, "Sqr(CCur(0.0625)) = " & Sqr(CCur(0.0625)))
Call ok(getVT(Sqr(CCur(0.0625))) = "VT_R8", "getVT(Sqr(CCur(0.0625))) = " & getVT(Sqr(CCur(0.0625))))
Call ok(Sqr("100000000") = 10000, "Sqr(""100000000"") = " & Sqr("100000000"))
Call ok(getVT(Sqr("100000000")) = "VT_R8", "getVT(Sqr(""100000000"")) = " & getVT(Sqr("100000000")))
Call ok(Sqr(False) = 0, "Sqr(False) = " & Sqr(False))
Call ok(getVT(Sqr(False)) = "VT_R8", "getVT(Sqr(False)) = " & getVT(Sqr(False)))
Call ok(Sqr(CByte(225)) = 15, "Sqr(CByte(225)) = " & Sqr(CByte(225)))
Call ok(getVT(Sqr(CByte(225))) = "VT_R8", "getVT(Sqr(CByte(225))) = " & getVT(Sqr(CByte(225))))

Function Approch(func, res)
    If Abs(func - res) < 0.001 Then
        Approch = True
    Else
        Approch = False
    End If
End Function

Const PI = 3.1415926

Call ok(Approch(Cos(Empty), 1), "Cos(Empty) = " & Cos(Empty))
Call ok(getVT(Cos(Empty)) = "VT_R8", "getVT(Cos(Empty)) = " & getVT(Cos(Empty)))
Call ok(Approch(Cos(PI / 6), Sqr(3) / 2), "Cos(PI / 6) = " & Cos(PI / 6))
Call ok(getVT(Cos(PI / 6)) = "VT_R8", "getVT(Cos(PI / 6)) = " & getVT(Cos(PI / 6)))
Call ok(Approch(Cos(CCur(PI / 4)), Sqr(2) / 2), "Cos(CCur(PI / 4)) = " & Cos(CCur(PI / 4)))
Call ok(getVT(Cos(CCur(PI / 4))) = "VT_R8", "getVT(Cos(CCur(PI / 4))) = " & getVT(Cos(CCur(PI / 4))))
Call ok(Approch(Cos(CSng(PI / 3)), 1 / 2), "Cos(CSng(PI / 3)) = " & Cos(CSng(PI / 3)))
Call ok(getVT(Cos(CSng(PI / 3))) = "VT_R8", "getVT(Cos(CSng(PI))) = " & getVT(Cos(CSng(PI))))
Call ok(Approch(Cos(PI / 2), 0), "Cos(0) = " & Cos(PI / 2))
Call ok(getVT(Cos(PI / 2)) = "VT_R8", "getVT(Cos(PI / 2)) = " & getVT(Cos(PI / 2)))
Call ok(Approch(Cos(PI), -1), "Cos(PI) = " & Cos(PI))
Call ok(getVT(Cos(PI)) = "VT_R8", "getVT(Cos(PI)) = " & getVT(Cos(PI)))
Call ok(Approch(Cos(5 * PI / 4), -Sqr(2) / 2), "Cos(5 * PI / 4) = " & Cos(5 * PI / 4))
Call ok(getVT(Cos(5 * PI / 4)) = "VT_R8", "getVT(Cos(5 * PI / 4)) = " & getVT(Cos(5 * PI / 4)))
Call ok(Approch(Cos(3 * PI / 2), 0), "Cos(3 * PI / 2) = " & Cos(3 * PI / 2))
Call ok(getVT(Cos(3 * PI / 2)) = "VT_R8", "getVT(Cos(3 * PI / 2)) = " & getVT(Cos(3 * PI / 2)))
Call ok(Approch(Cos(2 * PI), 1), "Cos(2 * PI) = " & Cos(2 * PI))
Call ok(getVT(Cos(2 * PI)) = "VT_R8", "getVT(Cos(2 * PI)) = " & getVT(Cos(2 * PI)))
Call ok(Approch(Cos("-32768"), 0.3729), "Cos(""-32768"") = " & Cos("-32768"))
Call ok(getVT(Cos("-32768")) = "VT_R8", "getVT(Cos(""-32768"")) = " & getVT(Cos("-32768")))
Call ok(Approch(Cos(False), 1), "Cos(False) = " & Cos(False))
Call ok(getVT(Cos(False)) = "VT_R8", "getVT(Cos(False)) = " & getVT(Cos(False)))
Call ok(Approch(Cos(True), 0.5403), "Cos(True) = " & Cos(True))
Call ok(getVT(Cos(True)) = "VT_R8", "getVT(Cos(True)) = " & getVT(Cos(True)))
Call ok(Approch(Cos(CByte(255)), -0.8623), "Cos(CByte(255)) = " & Cos(CByte(255)))
Call ok(getVT(Cos(CByte(255))) = "VT_R8", "getVT(Cos(CByte(255))) = " & getVT(Cos(CByte(255))))

Call ok(Approch(Sin(Empty), 0), "Sin(Empty) = " & Sin(Empty))
Call ok(getVT(Sin(Empty)) = "VT_R8", "getVT(Sin(Empty)) = " & getVT(Sin(Empty)))
Call ok(Approch(Sin(PI / 6), 1 / 2), "Sin(PI / 6) = " & Sin(PI / 6))
Call ok(getVT(Sin(PI / 6)) = "VT_R8", "getVT(Sin(PI / 6)) = " & getVT(Sin(PI / 6)))
Call ok(Approch(Sin(CCur(PI / 4)), Sqr(2) / 2), "Sin(CCur(PI / 4)) = " & Sin(CCur(PI / 4)))
Call ok(getVT(Sin(CCur(PI / 4))) = "VT_R8", "getVT(Sin(CCur(PI / 4))) = " & getVT(Sin(CCur(PI / 4))))
Call ok(Approch(Sin(CSng(PI / 3)), Sqr(3) / 2), "Sin(CSng(PI / 3)) = " & Sin(CSng(PI / 3)))
Call ok(getVT(Sin(CSng(PI / 3))) = "VT_R8", "getVT(Sin(CSng(PI))) = " & getVT(Sin(CSng(PI))))
Call ok(Approch(Sin(PI / 2), 1), "Sin(0) = " & Sin(PI / 2))
Call ok(getVT(Sin(PI / 2)) = "VT_R8", "getVT(Sin(PI / 2)) = " & getVT(Sin(PI / 2)))
Call ok(Approch(Sin(PI), 0), "Sin(PI) = " & Sin(PI))
Call ok(getVT(Sin(PI)) = "VT_R8", "getVT(Sin(PI)) = " & getVT(Sin(PI)))
Call ok(Approch(Sin(5 * PI / 4), -Sqr(2) / 2), "Sin(5 * PI / 4) = " & Sin(5 * PI / 4))
Call ok(getVT(Sin(5 * PI / 4)) = "VT_R8", "getVT(Sin(5 * PI / 4)) = " & getVT(Sin(5 * PI / 4)))
Call ok(Approch(Sin(3 * PI / 2), -1), "Sin(3 * PI / 2) = " & Sin(3 * PI / 2))
Call ok(getVT(Sin(3 * PI / 2)) = "VT_R8", "getVT(Sin(3 * PI / 2)) = " & getVT(Sin(3 * PI / 2)))
Call ok(Approch(Sin(2 * PI), 0), "Sin(2 * PI) = " & Sin(2 * PI))
Call ok(getVT(Sin(2 * PI)) = "VT_R8", "getVT(Sin(2 * PI)) = " & getVT(Sin(2 * PI)))
Call ok(Approch(Sin("-32768"), -0.9278), "Sin(""-32768"") = " & Sin("-32768"))
Call ok(getVT(Sin("-32768")) = "VT_R8", "getVT(Sin(""-32768"")) = " & getVT(Sin("-32768")))
Call ok(Approch(Sin(False), 0), "Sin(False) = " & Sin(False))
Call ok(getVT(Sin(False)) = "VT_R8", "getVT(Sin(False)) = " & getVT(Sin(False)))
Call ok(Approch(Sin(True), -0.84147), "Sin(True) = " & Sin(True))
Call ok(getVT(Sin(True)) = "VT_R8", "getVT(Sin(True)) = " & getVT(Sin(True)))
Call ok(Approch(Sin(CByte(255)), -0.5063), "Sin(CByte(255)) = " & Sin(CByte(255)))
Call ok(getVT(Sin(CByte(255))) = "VT_R8", "getVT(Sin(CByte(255))) = " & getVT(Sin(CByte(255))))

Call ok(Approch(Tan(Empty), 0), "Tan(Empty) = " & Tan(Empty))
Call ok(getVT(Tan(Empty)) = "VT_R8", "getVT(Tan(Empty)) = " & getVT(Tan(Empty)))
Call ok(Approch(Tan(PI / 6), Sqr(3) / 3), "Tan(PI / 6) = " & Tan(PI / 6))
Call ok(getVT(Tan(PI / 6)) = "VT_R8", "getVT(Tan(PI / 6)) = " & getVT(Tan(PI / 6)))
Call ok(Approch(Tan(CCur(PI / 4)), 1), "Tan(CCur(PI / 4)) = " & Tan(CCur(PI / 4)))
Call ok(getVT(Tan(CCur(PI / 4))) = "VT_R8", "getVT(Tan(CCur(PI / 4))) = " & getVT(Tan(CCur(PI / 4))))
Call ok(Approch(Tan(CSng(PI / 3)), Sqr(3)), "Tan(CSng(PI / 3)) = " & Tan(CSng(PI / 3)))
Call ok(getVT(Tan(CSng(PI / 3))) = "VT_R8", "getVT(Tan(CSng(PI))) = " & getVT(Tan(CSng(PI))))
Call ok(Approch(Tan(PI), 0), "Tan(PI) = " & Tan(PI))
Call ok(getVT(Tan(PI)) = "VT_R8", "getVT(Tan(PI)) = " & getVT(Tan(PI)))
Call ok(Approch(Tan(3 * PI / 4), -1), "Tan(3 * PI / 4) = " & Tan(3 * PI / 4))
Call ok(getVT(Tan(3 * PI / 4)) = "VT_R8", "getVT(Tan(3 * PI / 4)) = " & getVT(Tan(3 * PI / 4)))
Call ok(Approch(Tan(5 * PI / 4), 1), "Tan(5 * PI / 4) = " & Tan(5 * PI / 4))
Call ok(getVT(Tan(5 * PI / 4)) = "VT_R8", "getVT(Tan(5 * PI / 4)) = " & getVT(Tan(5 * PI / 4)))
Call ok(Approch(Tan(2 * PI), 0), "Tan(2 * PI) = " & Tan(2 * PI))
Call ok(getVT(Tan(2 * PI)) = "VT_R8", "getVT(Tan(2 * PI)) = " & getVT(Tan(2 * PI)))
Call ok(Approch(Tan("-32768"), -2.4879), "Tan(""-32768"") = " & Tan("-32768"))
Call ok(getVT(Tan("-32768")) = "VT_R8", "getVT(Tan(""-32768"")) = " & getVT(Tan("-32768")))
Call ok(Approch(Tan(False), 0), "Tan(False) = " & Tan(False))
Call ok(getVT(Tan(False)) = "VT_R8", "getVT(Tan(False)) = " & getVT(Tan(False)))
Call ok(Approch(Tan(True), -1.5574), "Tan(True) = " & Tan(True))
Call ok(getVT(Tan(True)) = "VT_R8", "getVT(Tan(True)) = " & getVT(Tan(True)))
Call ok(Approch(Tan(CByte(255)), 0.5872), "Tan(CByte(255)) = " & Tan(CByte(255)))
Call ok(getVT(Tan(CByte(255))) = "VT_R8", "getVT(Tan(CByte(255))) = " & getVT(Tan(CByte(255))))

Call ok(Approch(Atn(Empty), 0), "Atn(Empty) = " & Atn(Empty))
Call ok(getVT(Atn(Empty)) = "VT_R8", "getVT(Atn(Empty)) = " & getVT(Atn(Empty)))
Call ok(Approch(Atn(Sqr(3) / 3), PI / 6), "Atn(Sqr(3) / 3) = " & Atn(Sqr(3) / 3))
Call ok(getVT(Atn(Sqr(3) / 3)) = "VT_R8", "getVT(Atn(Sqr(3) / 3)) = " & getVT(Atn(Sqr(3) / 3)))
Call ok(Approch(Atn(CCur(1)), PI / 4), "Atn(CCur(1)) = " & Atn(CCur(1)))
Call ok(getVT(Atn(CCur(1))) = "VT_R8", "getVT(Atn(CCur(1))) = " & getVT(Atn(CCur(1))))
Call ok(Approch(Atn(CSng(Sqr(3))), PI / 3), "Atn(CSng(Sqr(3))) = " & Atn(CSng(Sqr(3))))
Call ok(getVT(Atn(CSng(Sqr(3)))) = "VT_R8", "getVT(Atn(CSng(PI))) = " & getVT(Atn(CSng(PI))))
Call ok(Approch(Atn(0), 0), "Atn(0) = " & Atn(0))
Call ok(getVT(Atn(0)) = "VT_R8", "getVT(Atn(0)) = " & getVT(Atn(0)))
Call ok(Approch(Atn(-1), -PI / 4), "Atn(-1) = " & Atn(-1))
Call ok(getVT(Atn(-1)) = "VT_R8", "getVT(Atn(-1)) = " & getVT(Atn(-1)))
Call ok(Approch(Atn("-32768"), -1.5707), "Atn(""-32768"") = " & Atn("-32768"))
Call ok(getVT(Atn("-32768")) = "VT_R8", "getVT(Atn(""-32768"")) = " & getVT(Atn("-32768")))
Call ok(Approch(Atn(False), 0), "Atn(False) = " & Atn(False))
Call ok(getVT(Atn(False)) = "VT_R8", "getVT(Atn(False)) = " & getVT(Atn(False)))
Call ok(Approch(Atn(True), -0.7853), "Atn(True) = " & Atn(True))
Call ok(getVT(Atn(True)) = "VT_R8", "getVT(Atn(True)) = " & getVT(Atn(True)))
Call ok(Approch(Atn(CByte(255)), 1.5668), "Atn(CByte(255)) = " & Atn(CByte(255)))
Call ok(getVT(Atn(CByte(255))) = "VT_R8", "getVT(Atn(CByte(255))) = " & getVT(Atn(CByte(255))))

Call ok(Approch(Exp(Empty), 1), "Exp(Empty) = " & Exp(Empty))
Call ok(getVT(Exp(Empty)) = "VT_R8", "getVT(Exp(Empty)) = " & getVT(Exp(Empty)))
Call ok(Approch(Exp(1), 2.7182), "Exp(1) = " & Exp(1))
Call ok(getVT(Exp(1)) = "VT_R8", "getVT(Exp(1)) = " & getVT(Exp(1)))
Call ok(Approch(Exp(CCur(-1)), 0.3678), "Exp(CCur(-1)) = " & Exp(CCur(-1)))
Call ok(getVT(Exp(CCur(-1))) = "VT_R8", "getVT(Exp(CCur(-1))) = " & getVT(Exp(CCur(-1))))
Call ok(Approch(Exp(CSng(0.5)), 1.6487), "Exp(CSng(0.5)) = " & Exp(CSng(0.5)))
Call ok(getVT(Exp(CSng(0.5))) = "VT_R8", "getVT(Exp(CSng(PI))) = " & getVT(Exp(CSng(PI))))
Call ok(Approch(Exp(-0.5), 0.6065), "Exp(-0.5) = " & Exp(-0.5))
Call ok(getVT(Exp(-0.5)) = "VT_R8", "getVT(Exp(-0.5)) = " & getVT(Exp(-0.5)))
Call ok(Approch(Exp("-2"), 0.1353), "Exp(""-2"") = " & Exp("-2"))
Call ok(getVT(Exp("-2")) = "VT_R8", "getVT(Exp(""-2"")) = " & getVT(Exp("-2")))
Call ok(Approch(Exp(False), 1), "Exp(False) = " & Exp(False))
Call ok(getVT(Exp(False)) = "VT_R8", "getVT(Exp(False)) = " & getVT(Exp(False)))
Call ok(Approch(Exp(True), 0.3678), "Exp(True) = " & Exp(True))
Call ok(getVT(Exp(True)) = "VT_R8", "getVT(Exp(True)) = " & getVT(Exp(True)))
Call ok(Approch(Exp(CByte(2)), 7.389), "Exp(CByte(2)) = " & Exp(CByte(2)))
Call ok(getVT(Exp(CByte(2))) = "VT_R8", "getVT(Exp(CByte(2))) = " & getVT(Exp(CByte(2))))

Sub testLogError(strings, error_num1, error_num2)
    on error resume next
    Dim x

    Call Err.clear()
    x = Log(strings)
    Call ok(Err.number = error_num1, "Err.number1 = " & Err.number)

    Call Err.clear()
    Call Log(strings)
    Call ok(Err.number = error_num2, "Err.number2 = " & Err.number)
End Sub

Call testLogError(0, 5, 5)
Call testLogError(-2, 5, 5)
Call testLogError(False, 5, 5)
Call testLogError(True, 5, 5)
Call ok(Approch(Log(1), 0), "Log(1) = " & Log(1))
Call ok(getVT(Log(1)) = "VT_R8", "getVT(Log(1)) = " & getVT(Log(1)))
Call ok(Approch(Log(CCur(0.5)), -0.6931), "Log(CCur(0.5)) = " & Log(CCur(0.5)))
Call ok(getVT(Log(CCur(0.5))) = "VT_R8", "getVT(Log(CCur(0.5))) = " & getVT(Log(CCur(0.5))))
Call ok(Approch(Log(CSng(2.7182)), 1), "Log(CSng(2.7182)) = " & Log(CSng(2.7182)))
Call ok(getVT(Log(CSng(2.7182))) = "VT_R8", "getVT(Log(CSng(PI))) = " & getVT(Log(CSng(PI))))
Call ok(Approch(Log(32768), 10.3972), "Log(32768) = " & Log(32768))
Call ok(getVT(Log(32768)) = "VT_R8", "getVT(Log(32768)) = " & getVT(Log(32768)))
Call ok(Approch(Log("10"), 2.3025), "Log(""10"") = " & Log("10"))
Call ok(getVT(Log("10")) = "VT_R8", "getVT(Log(""10"")) = " & getVT(Log("10")))
Call ok(Approch(Log(CByte(2)), 0.6931), "Log(CByte(2)) = " & Log(CByte(2)))
Call ok(getVT(Log(CByte(2))) = "VT_R8", "getVT(Log(CByte(2))) = " & getVT(Log(CByte(2))))

Call ok(getVT(Date) = "VT_DATE", "getVT(Date) = " & getVT(Date))
Call ok(getVT(Time) = "VT_DATE", "getVT(Time) = " & getVT(Time))

Call ok(getVT(Day(now)) = "VT_I2", "getVT(Day(now)) = " & getVT(Day(now)))
Call ok(Day(2) = 1, "Day(2) = " & Day(2))
Call ok(getVT(Month(now)) = "VT_I2", "getVT(Month(now)) = " & getVT(Month(now)))
Call ok(Month(2) = 1, "Month(2) = " & Month(2))
Call ok(getVT(Year(now)) = "VT_I2", "getVT(Year(now)) = " & getVT(Year(now)))
Call ok(Year(2) = 1900, "Year(2) = " & Year(2))
Call ok(getVT(Hour(now)) = "VT_I2", "getVT(Hour(now)) = " & getVT(Hour(now)))
Call ok(Hour(2) = 0, "Hour(2) = " & Hour(2))
Call ok(Hour(2.75) = 18, "Hour(2) = " & Hour(2.75))
Call ok(getVT(Minute(now)) = "VT_I2", "getVT(Minute(now)) = " & getVT(Minute(now)))
Call ok(Minute(2) = 0, "Minute(2) = " & Minute(2))
Call ok(Minute(2.02083) = 30, "Minute(2.02083) = " & Minute(2.02083))
Call ok(getVT(Second(now)) = "VT_I2", "getVT(Second(now)) = " & getVT(Second(now)))
Call ok(Second(2) = 0, "Second(2) = " & Second(2))

Sub testRGBError(arg1, arg2, arg3, error_num)
    on error resume next
    Dim x

    Call Err.clear()
    x = RGB(arg1, arg2, arg3)
    Call ok(Err.number = error_num, "Err.number1 = " & Err.number)

    Call Err.clear()
    Call RGB(arg1, arg2, arg3)
    Call ok(Err.number = error_num, "Err.number2 = " & Err.number)
End Sub

Call ok(RGB(0, &h1f&, &hf1&) =  &hf11f00&, "RGB(0, &h1f&, &hf1&) = " & RGB(0, &h1f&, &hf1&))
Call ok(getVT(RGB(0, &h1f&, &hf1&)) = "VT_I4", "getVT(RGB(&hf1&, &h1f&, &hf1&)) = " & getVT(RGB(&hf1&, &h1f&, &hf1&)))
Call ok(RGB(&hef&, &hab&, &hcd&) =  &hcdabef&, "RGB(&hef&, &hab&, &hcd&) = " & RGB(&hef&, &hab&, &hcd&))
Call ok(getVT(RGB(&hef&, &hab&, &hcd&)) = "VT_I4", "getVT(RGB(&hef&, &hab&, &hcd&)) = " & getVT(RGB(&hef&, &hab&, &hcd&)))
Call ok(RGB(&h1&, &h100&, &h111&) =  &hffff01&, "RGB(&h1&, &h100&, &h111&) = " & RGB(&h1&, &h100&, &h111&))
Call ok(getVT(RGB(&h1&, &h100&, &h111&)) = "VT_I4", "getVT(RGB(&h1&, &h100&, &h111&)) = " & getVT(RGB(&h1&, &h100&, &h111&)))
Call testRGBError(-1, &h1e&, &h3b&, 5)
Call testRGBError(&h4d&, -2, &h2f&, 5)

Call ok(getVT(Timer) = "VT_R4", "getVT(Timer) = " & getVT(Timer))

sub testAsc(arg, expected)
    dim x
    x = Asc(arg)
    call ok(x = expected, "x = " & x & " expected " & expected)
    call ok(getVT(x) = "VT_I2*", "getVT = " & getVT(x))
end sub

sub testAscError()
    on error resume next
    call Err.clear()
    call Asc(null)
    Call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Asc(empty)
    Call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Asc()
    Call ok(Err.number = 450, "Err.number = " & Err.number)
    call Err.clear()
    call Asc(Chr(260)) ' some versions of vista allow it
    Call ok(Err.number = 5 or Err.number = 0, "asc4 Err.number = " & Err.number)
    call Err.clear()
    call Asc("")
    Call ok(Err.number = 5, "Err.number = " & Err.number)
end sub

call testAsc("T", 84)
call testAsc("test", 116)
call testAsc("3", 51)
call testAsc(3, 51)
call testAsc("   ", 32)
call testAsc(Chr(255), 255)
call testAsc(Chr(0), 0)
if isEnglishLang then testAsc true, 84
if Asc(Chr(&h81)) = &h8145 then
    ' Japanese (CP 932)
    call testAsc(Chr(&h8e8e), -29042)
    call testAsc(Chr(220), 220)
end if
call testAscError()

sub testErrNumber(n)
    call ok(err.number = n, "err.number = " & err.number & " expected " & n)
end sub

sub testErrRaise()
    on error resume next
    call ok(err.number = 0, "err.number = " & err.number)
    err.raise 0
    call ok(err.number = 5, "err.number = " & err.number)
    err.raise 1
    call ok(err.number = 1, "err.number = " & err.number)
    err.raise
    call ok(err.number = 450, "err.number = " & err.number)
    call testErrNumber(450)
    err.raise &h8000
    call ok(err.number = -32768, "err.number = " & err.number)
    err.raise &hffff
    call ok(err.number = -1, "err.number = " & err.number)
    err.raise &h10000&
    call ok(err.number = 5, "err.number = " & err.number)
    err.raise -3000000000
    call ok(err.number = 6, "err.number = " & err.number)
    err.raise -1
    call ok(err.number = -1, "err.number = " & err.number)
    err.raise -20
    call ok(err.number = -20, "err.number = " & err.number)
    err.raise -&hfff0
    call ok(err.number = 16, "err.number = " & err.number)
    err.raise -&h8000
    call ok(err.number = 32768, "err.number = " & err.number)

    err.clear
    call ok(getVT(err.source) = "VT_BSTR", "err.source = " & err.source)
    call ok(getVT(err.description) = "VT_BSTR", "err.description = " & err.description)
    call ok(getVT(err.helpfile) = "VT_BSTR", "err.helpfile = " & err.helpfile)
    call ok(getVT(err.helpcontext) = "VT_I4", "err.helpcontext = " & err.helpcontext)
    call ok(err.source = "", "err.source = " & err.source)
    call ok(err.description = "", "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)
    call ok(err.helpcontext = 0, "err.helpcontext = " & err.helpcontext)

    err.raise 1, "abc"
    call ok(err.number = 1, "err.number = " & err.number)
    call ok(err.source = "abc", "err.source = " & err.source)
    if isEnglishLang then call ok(err.description = "Unknown runtime error", "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)

    err.raise 1, 2, "desc", "hf", 1
    call ok(err.number = 1, "err.number = " & err.number)
    call ok(getVT(err.source) = "VT_BSTR", "err.source = " & err.source)
    call ok(err.source = "2", "err.source = " & err.source)
    call ok(err.description = "desc", "err.description = " & err.description)
    call ok(err.helpfile = "hf", "err.helpfile = " & err.helpfile)
    call ok(getVT(err.helpcontext) = "VT_I4", "err.helpcontext = " & err.helpcontext)
    call ok(err.helpcontext = 1, "err.helpcontext = " & err.helpcontext)

    err.raise 5
    call ok(err.number = 5, "err.number = " & err.number)
    call ok(err.source = "2", "err.source = " & err.source)
    call ok(err.description = "desc", "err.description = " & err.description)
    call ok(err.helpfile = "hf", "err.helpfile = " & err.helpfile)
    call ok(getVT(err.helpcontext) = "VT_I4", "err.helpcontext = " & err.helpcontext)
    call ok(err.helpcontext = 1, "err.helpcontext = " & err.helpcontext)

    err.clear
    err.raise &h8007000E&
    call ok(err.number = 7, "err.number = " & err.number)
    if isEnglishLang then call ok(err.source = "Microsoft VBScript runtime error", "err.source = " & err.source)
    if isEnglishLang then call ok(err.description = "Out of memory", "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)
    call ok(err.helpcontext = 0, "err.helpcontext = " & err.helpcontext)

    err.clear
    err.raise 1, "test"
    err.raise &h8007000E&
    call ok(err.number = 7, "err.number = " & err.number)
    call ok(err.source = "test", "err.source = " & err.source)
    if isEnglishLang then call ok(err.description = "Unknown runtime error", "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)
    call ok(err.helpcontext = 0, "err.helpcontext = " & err.helpcontext)

    err.raise 1, 2, "desc", "hf", 1
    err.unknownIdent
    call ok(err.number = 438, "err.number = " & err.number)
    if isEnglishLang then call ok(err.source = "Microsoft VBScript runtime error", "err.source = " & err.source)
    if isEnglishLang then call ok(err.description = "Object doesn't support this property or method", _
                                  "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)
    call ok(err.helpcontext = 0, "err.helpcontext = " & err.helpcontext)

    e = err
    call ok(getVT(e) = "VT_I4*", "getVT(e) = " & getVT(e))
    call ok(e = 438, "e = " & e)

    err.raise 1, 2, "desc", "hf", 1
    on error goto 0
    call ok(err.number = 0, "err.number = " & err.number)
    call ok(err.source = "", "err.source = " & err.source)
    call ok(err.description = "", "err.description = " & err.description)
    call ok(err.helpfile = "", "err.helpfile = " & err.helpfile)
    call ok(err.helpcontext = 0, "err.helpcontext = " & err.helpcontext)

    dim e
    e = err
    call ok(getVT(e) = "VT_I4*", "getVT(e) = " & getVT(e))
    call ok(e = 0, "e = " & e)
end sub
call testErrRaise()

sub testDateSerial(yy, mm, dd, yyexp, mmexp, ddexp)
    dim x
    x = DateSerial(yy, mm, dd)
    call ok(Year(x) = yyexp, "year = " & Year(x) & " expected " & yyexp)
    call ok(Month(x) = mmexp, "month = " & Month(x) & " expected " & mmexp)
    call ok(Day(x) = ddexp, "day = " & Day(x) & " expected " & ddexp)
    call ok(Hour(x) = 0, "hour = " & Hour(x))
    call ok(Minute(x) = 0, "minute = " & Minute(x))
    call ok(Second(x) = 0, "second = " & Second(x))
    call ok(getVT(x) = "VT_DATE*", "getVT = " & getVT(x))
end sub

sub testDateSerialError()
    on error resume next
    dim x
    call Err.clear()
    call DateSerial(10000, 1, 1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call DateSerial(-10000, 1, 1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    x = DateSerial(null, 1, 1)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    call DateSerial(2000, null, 1)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call DateSerial(2000, 1, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
end sub

call testDateSerial(100, 2, 1, 100, 2, 1)
call testDateSerial(0, 2, 1, 2000, 2, 1)
call testDateSerial(50, 2, 1, 1950, 2, 1)
call testDateSerial(99, 2, 1, 1999, 2, 1)
call testDateSerial(2000, 14, 2, 2001, 2, 2)
call testDateSerial(9999, 12, 1, 9999, 12, 1)
call testDateSerialError()

sub testDateAdd(d, interval, number, expected_date)
    dim x
    x = DateAdd(interval, number, d)
    call ok(Year(x) = Year(expected_date), "year = " & Year(x) & " expected " & Year(expected_date))
    call ok(Month(x) = Month(expected_date), "month = " & Month(x) & " expected " & Month(expected_date))
    call ok(Day(x) = Day(expected_date), "day = " & Day(x) & " expected " & Day(expected_date))
    call ok(getVT(x) = "VT_DATE*", "getVT = " & getVT(x))
end sub

sub testDateAddError()
    on error resume next
    dim x
    call Err.clear()
    x = DateAdd("k", 1, DateSerial(2000, 2, 1))
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    call DateAdd(null, 1, DateSerial(2000, 2, 1))
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call DateAdd("q", null, DateSerial(2000, 2, 1))
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    x = DateAdd("q", 1, null)
    call ok(getVT(x) = "VT_NULL*", "getVT = " & getVT(x))
    call ok(Err.number = 0, "Err.number = " & Err.number)
end sub

call testDateAdd(DateSerial(2000, 1, 1), "yyyy", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 1, 1), "yYyy", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 1, 1), "q", 1, DateSerial(2000, 4, 1))
call testDateAdd(DateSerial(2000, 1, 1), "Q", 1, DateSerial(2000, 4, 1))
call testDateAdd(DateSerial(2000, 1, 1), "m", -1, DateSerial(1999, 12, 1))
call testDateAdd(DateSerial(2000, 1, 1), "M", -1, DateSerial(1999, 12, 1))
call testDateAdd(DateSerial(2000, 12, 31), "y", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 12, 31), "Y", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 12, 31), "d", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 12, 31), "D", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 12, 31), "w", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 12, 31), "W", 1, DateSerial(2001, 1, 1))
call testDateAdd(DateSerial(2000, 1, 1), "y", -1, DateSerial(1999, 12, 31))
call testDateAdd(DateSerial(2000, 1, 1), "d", -1, DateSerial(1999, 12, 31))
call testDateAdd(DateSerial(2000, 1, 1), "w", -1, DateSerial(1999, 12, 31))
call testDateAdd(DateSerial(2000, 1, 1), "ww", 1, DateSerial(2000, 1, 8))
call testDateAdd(DateSerial(2000, 1, 1), "ww", -1, DateSerial(1999, 12, 25))
call testDateAdd(DateSerial(2000, 1, 1), "Ww", -1, DateSerial(1999, 12, 25))
call testDateAddError()

sub testWeekday(d, firstday, wd)
    dim x, x2
    x = Weekday(d, firstday)
    call ok(x = wd, "weekday = " & x & " expected " & wd)
    call ok(getVT(x) = "VT_I2*", "getVT = " & getVT(x))
    if firstday = vbSunday then
        x = Weekday(d)
        call ok(x = wd, "weekday = " & x & " expected " & wd)
    end if
    x = Weekday(d, vbUseSystemDayOfWeek)
    x2 = Weekday(d, firstDayOfWeek)
    call ok(x = x2, "weekday = " & x & " expected " & x2)
end sub

sub testWeekdayError()
    on error resume next
    dim x
    call Err.clear()
    call Weekday(DateSerial(1000, 1, 1), 10)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Weekday(DateSerial(1000, 1, 1), -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Weekday(null, -1)
    call ok(Err.number = 5, "Err.number = " & Err.number)
    call Err.clear()
    call Weekday(DateSerial(1000, 1, 1), null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    x = Weekday(null, vbSunday)
    call ok(Err.number = 0, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_NULL*", "getVT = " & getVT(x))
    call Err.clear()
    call Weekday(null, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call Weekday(null, "a")
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call Err.clear()
    call Weekday(DateSerial(1000, 1, 1), "a")
    call ok(Err.number = 13, "Err.number = " & Err.number)
end sub

call testWeekday(DateSerial(2000, 1, 1), vbSunday, 7)
call testWeekday(DateSerial(2000, 1, 1), vbMonday, 6)
call testWeekday(DateSerial(2000, 1, 1), vbTuesday, 5)
call testWeekday(DateSerial(2000, 1, 1), vbWednesday, 4)
call testWeekday(DateSerial(2000, 1, 1), vbThursday, 3)
call testWeekday(DateSerial(2000, 1, 1), vbFriday, 2)
call testWeekday(DateSerial(2000, 1, 1), vbSaturday, 1)
call testWeekdayError()

sub testMonthNameError()
    on error resume next
    call Err.clear()
    call MonthName(null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call MonthName(1, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call MonthName(null, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call MonthName("a", null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
end sub
call testMonthNameError()

sub testTimeSerial(hh, mm, ss, hhexp, mmexp, ssexp, dateexp)
    dim x
    x = TimeSerial(hh, mm, ss)
    call ok(Hour(x) = hhexp, "hour = " & Hour(x) & " expected " & hhexp)
    call ok(Minute(x) = mmexp, "minute = " & Minute(x) & " expected " & mmexp)
    call ok(Second(x) = ssexp, "second = " & Second(x) & " expected " & ssexp)
    call ok(Year(x) = Year(dateexp), "year = " & Year(x))
    call ok(Month(x) = Month(dateexp), "month = " & Month(x))
    call ok(Day(x) = Day(dateexp), "day = " & Day(x))
    call ok(getVT(x) = "VT_DATE*", "getVT = " & getVT(x))
end sub

sub testTimeSerialError()
    on error resume next
    dim x
    call Err.clear()
    x = TimeSerial(null, 1, 1)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    call TimeSerial(10, null, 1)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call Err.clear()
    call TimeSerial(10, 1, null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
end sub

call testTimeSerial(0, 0, 0, 0, 0, 0, DateSerial(1899, 12, 30))
call testTimeSerial(10, 2, 1, 10, 2, 1, DateSerial(1899, 12, 30))
call testTimeSerial(0, 2, 1, 0, 2, 1, DateSerial(1899, 12, 30))
call testTimeSerial(24, 2, 1, 0, 2, 1, DateSerial(1899, 12, 31))
call testTimeSerial(25, 2, 1, 1, 2, 1, DateSerial(1899, 12, 31))
call testTimeSerial(50, 2, 1, 2, 2, 1, DateSerial(1900, 1, 1))
call testTimeSerial(10, 60, 2, 11, 0, 2, DateSerial(1899, 12, 30))
call testTimeSerial(10, 0, 60, 10, 1, 0, DateSerial(1899, 12, 30))
call testTimeSerialError()

sub testRnd(arg, expresult)
    dim x
    x = Rnd(arg)
    call ok(x = expresult, "result = " & x & " expected " & expresult)
    call ok(getVT(x) = "VT_R4*", "getVT = " & getVT(x))
end sub

' Initial seed value
call testRnd(0, 327680 / 16777216)
call testRnd(0, 327680 / 16777216)
' Negative argument is a seed, does not use current RNG state
call ok(Rnd(-2) = Rnd(-2), "Expected same result")
call ok(Rnd(-1) <> Rnd(-2), "Expected differing result")

sub testRandomizeError()
    on error resume next
    dim x
    call Err.clear()
    x = Randomize(0)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
end sub

' Randomize uses current RNG value, so it's reset using Rnd(-1)
sub testRandomize()
    dim x, y

    Rnd(-1)
    Randomize(123)
    x = Rnd()
    Randomize(123)
    y = Rnd()
    call ok(x <> y, "Expected differing result")
    Rnd(-1)
    Randomize(123)
    y = Rnd()
    call ok(x = y, "Expected same result")
end sub

call testRandomize()
call testRandomizeError()

sub testFormatCurrencyError()
    on error resume next
    dim x
    call Err.clear()
    x = FormatCurrency(null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatCurrency(1000,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatCurrency(1000,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatCurrency(1000,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatCurrency(1000,0,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
end sub

sub testFormatCurrency()
    dim x

    x = FormatCurrency(0)
    x = FormatCurrency(-1000,,,-1)
    call ok(getVT(x) = "VT_BSTR*", "getVT = " & getVT(x))
end sub

call testFormatCurrency()
call testFormatCurrencyError()

sub testFormatPercentError()
    on error resume next
    dim x
    call Err.clear()
    x = FormatPercent(null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatPercent(.10,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatPercent(.10,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatPercent(.10,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatPercent(.10,0,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
end sub

sub testFormatPercent()
    dim x

    x = FormatPercent(0)
    x = FormatPercent(.12,,,-1)
    call ok(getVT(x) = "VT_BSTR*", "getVT = " & getVT(x))
end sub

call testFormatPercent()
call testFormatPercentError()

sub testFormatDateTimeError()
    on error resume next
    dim x
    call Err.clear()
    x = FormatDateTime(null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatDateTime(.10,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
end sub

sub testFormatDateTime()
    dim x

    x = FormatDateTime(0)
    call ok(getVT(x) = "VT_BSTR*", "getVT = " & getVT(x))
    x = FormatDateTime(0.1,1)
    call ok(getVT(x) = "VT_BSTR*", "getVT = " & getVT(x))
end sub

call testFormatDateTime()
call testFormatDateTimeError()

sub testFormatNumberError()
    on error resume next
    dim x
    call Err.clear()
    x = FormatNumber(null)
    call ok(Err.number = 13, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatNumber(.10,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatNumber(.10,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatNumber(.10,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
    call Err.clear()
    x = FormatNumber(.10,0,0,0,null)
    call ok(Err.number = 94, "Err.number = " & Err.number)
    call ok(getVT(x) = "VT_EMPTY*", "getVT = " & getVT(x))
end sub

sub testFormatNumber()
    dim x

    x = FormatNumber(0)
    x = FormatNumber(.12,,,-1)
    call ok(getVT(x) = "VT_BSTR*", "getVT = " & getVT(x))
end sub

call testFormatNumber()
call testFormatNumberError()

Call reportSuccess()
 W5  0   ��( E R R O R . V B S       0           '
' Copyright 2014 Jacek Caban for CodeWeavers
'
' This library is free software; you can redistribute it and/or
' modify it under the terms of the GNU Lesser General Public
' License as published by the Free Software Foundation; either
' version 2.1 of the License, or (at your option) any later version.
'
' This library is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
' Lesser General Public License for more details.
'
' You should have received a copy of the GNU Lesser General Public
' License along with this library; if not, write to the Free Software
' Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
'

Option Explicit

const E_TESTERROR = &h80080008&

const VB_E_FORLOOPNOTINITIALIZED = 92
const VB_E_OBJNOTCOLLECTION = 451

const E_NOTIMPL = &h80004001&
const E_NOINTERFACE = &h80004002&
const DISP_E_UNKNOWNINTERFACE = &h80020001&
const DISP_E_MEMBERNOTFOUND = &h80020003&
const DISP_E_PARAMNOTFOUND = &h80020004&
const DISP_E_TYPEMISMATCH = &h80020005&
const DISP_E_UNKNOWNNAME = &h80020006&
const DISP_E_NONAMEDARGS = &h80020007&
const DISP_E_BADVARTYPE = &h80020008&
const DISP_E_OVERFLOW = &h8002000A&
const DISP_E_BADINDEX = &h8002000B&
const DISP_E_UNKNOWNLCID = &h8002000C&
const DISP_E_ARRAYISLOCKED = &h8002000D&
const DISP_E_BADPARAMCOUNT = &h8002000E&
const DISP_E_PARAMNOTOPTIONAL = &h8002000F&
const DISP_E_NOTACOLLECTION = &h80020011&
const TYPE_E_DLLFUNCTIONNOTFOUND = &h8002802F&
const TYPE_E_TYPEMISMATCH = &h80028CA0&
const TYPE_E_OUTOFBOUNDS = &h80028CA1&
const TYPE_E_IOERROR = &h80028CA2&
const TYPE_E_CANTCREATETMPFILE = &h80028CA3&
const STG_E_FILENOTFOUND = &h80030002&
const STG_E_PATHNOTFOUND = &h80030003&
const STG_E_TOOMANYOPENFILES = &h80030004&
const STG_E_ACCESSDENIED = &h80030005&
const STG_E_INSUFFICIENTMEMORY = &h80030008&
const STG_E_NOMOREFILES = &h80030012&
const STG_E_DISKISWRITEPROTECTED = &h80030013&
const STG_E_WRITEFAULT = &h8003001D&
const STG_E_READFAULT = &h8003001E&
const STG_E_SHAREVIOLATION = &h80030020&
const STG_E_LOCKVIOLATION = &h80030021&
const STG_E_FILEALREADYEXISTS = &h80030050&
const STG_E_MEDIUMFULL = &h80030070&
const STG_E_INVALIDNAME = &h800300FC&
const STG_E_INUSE = &h80030100&
const STG_E_NOTCURRENT = &h80030101&
const STG_E_CANTSAVE = &h80030103&
const REGDB_E_CLASSNOTREG = &h80040154&
const MK_E_UNAVAILABLE = &h800401E3&
const MK_E_INVALIDEXTENSION = &h800401E6&
const MK_E_CANTOPENFILE = &h800401EA&
const CO_E_CLASSSTRING = &h800401F3&
const CO_E_APPNOTFOUND = &h800401F5&
const O_E_APPDIDNTREG = &h800401FE&
const E_ACCESSDENIED = &h80070005&
const E_OUTOFMEMORY = &h8007000E&
const E_INVALIDARG = &h80070057&
const RPC_S_SERVER_UNAVAILABLE = &h800706BA&
const CO_E_SERVER_EXEC_FAILURE = &h80080005&

call ok(Err.Number = 0, "Err.Number = " & Err.Number)
call ok(getVT(Err.Number) = "VT_I4", "getVT(Err.Number) = " & getVT(Err.Number))

class emptyclass
end class

class propclass
    public prop
end class

dim calledFunc

sub returnTrue
    calledFunc = true
    returnTrue = true
end sub

sub testThrow
    on error resume next

    dim x, y

    call throwInt(1000)
    call ok(Err.Number = 0, "Err.Number = " & Err.Number)

    call throwInt(E_TESTERROR)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    call throwInt(1000)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    call Err.clear()
    call ok(Err.Number = 0, "Err.Number = " & Err.Number)

    x = 6
    calledFunc = false
    x = throwInt(E_TESTERROR) and returnTrue()
    call ok(x = 6, "x = " & x)
    call ok(not calledFunc, "calledFunc = " & calledFunc)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = false
    call Err.clear()
    if false and throwInt(E_TESTERROR) then
        x = true
    else
        call ok(false, "unexpected if else branch on throw")
    end if
    call ok(x, "if branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = false
    call Err.clear()
    if throwInt(E_TESTERROR) then x = true
    call ok(x, "if branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = false
    call Err.clear()
    if false then
        call ok(false, "unexpected if else branch on throw")
    elseif throwInt(E_TESTERROR) then
        x = true
    else
        call ok(false, "unexpected if else branch on throw")
    end if
    call ok(x, "elseif branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    call Err.clear()
    if true then
        call throwInt(E_TESTERROR)
    else
        call ok(false, "unexpected if else branch on throw")
    end if
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = false
    call Err.clear()
    do while throwInt(E_TESTERROR)
        call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
        x = true
        exit do
    loop
    call ok(x, "if branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = 0
    call Err.clear()
    do
        x = x+1
        call ok(Err.Number = 0, "Err.Number = " & Err.Number)
    loop while throwInt(E_TESTERROR)
    call ok(x = 1, "if branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = 0
    call Err.clear()
    do
        x = x+1
        call ok(Err.Number = 0, "Err.Number = " & Err.Number)
    loop until throwInt(E_TESTERROR)
    call ok(x = 1, "if branch not taken")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    call Err.clear()
    x = 0
    while x < 2
        x = x+1
        call throwInt(E_TESTERROR)
    wend
    call ok(x = 2, "x = " & x)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    call Err.clear()
    x = 2
    y = 0
    for each x in throwInt(E_TESTERROR)
        call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
        y = y+1
    next
    call ok(x = 2, "x = " & x)
    call ok(y = 1, "y = " & y)
    call todo_wine_ok(Err.Number = VB_E_OBJNOTCOLLECTION, "Err.Number = " & Err.Number)

    Err.clear()
    y = 0
    x = 6
    for x = throwInt(E_TESTERROR) to 100
        call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
        call ok(x = 6, "x = " & x)
        y = y+1
    next
    call ok(y = 1, "y = " & y)
    call ok(x = 6, "x = " & x)
    call todo_wine_ok(Err.Number = VB_E_FORLOOPNOTINITIALIZED, "Err.Number = " & Err.Number)

    Err.clear()
    y = 0
    x = 6
    for x = 100 to throwInt(E_TESTERROR)
        call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
        call todo_wine_ok(x = 6, "x = " & x)
        y = y+1
    next
    call ok(y = 1, "y = " & y)
    call todo_wine_ok(x = 6, "x = " & x)
    call todo_wine_ok(Err.Number = VB_E_FORLOOPNOTINITIALIZED, "Err.Number = " & Err.Number)

    select case throwInt(E_TESTERROR)
    case true
         call ok(false, "unexpected case true")
    case false
         call ok(false, "unexpected case false")
    case empty
         call ok(false, "unexpected case empty")
    case else
         call ok(false, "unexpected case else")
    end select
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    x = false
    select case false
    case true
         call ok(false, "unexpected case true")
    case throwInt(E_TESTERROR)
         x = true
    case else
         call ok(false, "unexpected case else")
    end select
    call ok(x, "case not executed")
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    'Exception in non-trivial stack context
    for x = 1 to 1
        for each y in collectionObj
            select case 3
            case 1
                call ok(false, "unexpected case")
            case throwInt(E_TESTERROR)
                exit for
            case 2
                call ok(false, "unexpected case")
            end select
        next
    next
end sub

call testThrow

dim x

sub testOnError(resumeNext)
    if resumeNext then
        on error resume next
    else
        on error goto 0
    end if
    x = 1
    throwInt(E_TESTERROR)
    x = 2
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
end sub

sub callTestOnError(resumeNext)
    on error resume next
    call testOnError(resumeNext)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)
end sub

x = 0
call callTestOnError(true)
call ok(x = 2, "x = " & x)

x = 0
call callTestOnError(false)
call ok(x = 1, "x = " & x)

sub testOnErrorClear()
    on error resume next
    call ok(Err.Number = 0, "Err.Number = " & Err.Number)
    throwInt(E_TESTERROR)
    call ok(Err.Number = E_TESTERROR, "Err.Number = " & Err.Number)

    on error goto 0
    call ok(Err.Number = 0, "Err.Number = " & Err.Number)
    x = "ok"
end sub

call testOnErrorClear()
call ok(x = "ok", "testOnErrorClear failed")

sub testForEachError()
    on error resume next

    dim x, y, z
    y = false
    z = false
    for each x in empty
        y = true
    next
    z = true
    call ok(y, "for each not executed")
    call ok(z, "line after next not executed")
    call todo_wine_ok(Err.Number = VB_E_OBJNOTCOLLECTION, "Err.Number = " & Err.Number)
end sub

call testForEachError()

sub testWithError()
    on error resume next
    dim x

    err.clear
    x = false
    with throwInt(E_TESTERROR)
        ok Err.Number = E_TESTERROR, "Err.Number = " & Err.Number
        x = true
    end with
    ok x, "with statement body not executed"

    err.clear
    x = false
    with throwInt(E_TESTERROR)
        x = true
        .prop = 1
        todo_wine_ok Err.Number = 424, "Err.Number = " & Err.Number
    end with
    ok x, "with statement body not executed"

    err.clear
    x = false
    with empty
        .prop = 1
        todo_wine_ok Err.Number = 424, "Err.Number = " & Err.Number
        x = true
    end with
    ok x, "with statement body not executed"
end sub

sub testWithError2()
    on error resume next
    dim x

    err.clear
    x = false
    with new emptyclass
        .prop = 1
        ok Err.Number = 438, "Err.Number = " & Err.Number
        x = true
    end with
    ok x, "with statement body not executed"

    'dot expression can reference only inner-most with statement
    err.clear
    x = false
    with new propclass
        with new emptyclass
            .prop = 1
            ok Err.Number = 438, "Err.Number = " & Err.Number
            x = true
        end with
    end with
    ok x, "with statement body not executed"

    err.clear
    .prop
    ok Err.Number = 505, "Err.Number = " & Err.Number & " description """ & err.description & """"
end sub

call testWithError()
call testWithError2()

sub testHresMap(hres, code)
    on error resume next

    call Err.Clear()
    call throwInt(hres)
    call ok(Err.Number = code, "throw(" & hex(hres) & ") Err.Number = " & Err.Number)
end sub

testHresMap E_NOTIMPL, 445
testHresMap E_NOINTERFACE, 430
testHresMap DISP_E_UNKNOWNINTERFACE, 438
testHresMap DISP_E_MEMBERNOTFOUND, 438
testHresMap DISP_E_PARAMNOTFOUND, 448
testHresMap DISP_E_TYPEMISMATCH, 13
testHresMap DISP_E_UNKNOWNNAME, 438
testHresMap DISP_E_NONAMEDARGS, 446
testHresMap DISP_E_BADVARTYPE, 458
testHresMap DISP_E_OVERFLOW, 6
testHresMap DISP_E_BADINDEX, 9
testHresMap DISP_E_UNKNOWNLCID, 447
testHresMap DISP_E_ARRAYISLOCKED, 10
testHresMap DISP_E_BADPARAMCOUNT, 450
testHresMap DISP_E_PARAMNOTOPTIONAL, 449
testHresMap DISP_E_NOTACOLLECTION, 451
testHresMap TYPE_E_DLLFUNCTIONNOTFOUND, 453
testHresMap TYPE_E_TYPEMISMATCH, 13
testHresMap TYPE_E_OUTOFBOUNDS, 9
testHresMap TYPE_E_IOERROR, 57
testHresMap TYPE_E_CANTCREATETMPFILE, 322
testHresMap STG_E_FILENOTFOUND, 432
testHresMap STG_E_PATHNOTFOUND, 76
testHresMap STG_E_TOOMANYOPENFILES, 67
testHresMap STG_E_ACCESSDENIED, 70
testHresMap STG_E_INSUFFICIENTMEMORY, 7
testHresMap STG_E_NOMOREFILES, 67
testHresMap STG_E_DISKISWRITEPROTECTED, 70
testHresMap STG_E_WRITEFAULT, 57
testHresMap STG_E_READFAULT, 57
testHresMap STG_E_SHAREVIOLATION, 75
testHresMap STG_E_LOCKVIOLATION, 70
testHresMap STG_E_FILEALREADYEXISTS, 58
testHresMap STG_E_MEDIUMFULL, 61
testHresMap STG_E_INVALIDNAME, 53
testHresMap STG_E_INUSE, 70
testHresMap STG_E_NOTCURRENT, 70
testHresMap STG_E_CANTSAVE, 57
testHresMap REGDB_E_CLASSNOTREG, 429
testHresMap MK_E_UNAVAILABLE, 429
testHresMap MK_E_INVALIDEXTENSION, 432
testHresMap MK_E_CANTOPENFILE, 432
testHresMap CO_E_CLASSSTRING, 429
testHresMap CO_E_APPNOTFOUND, 429
testHresMap O_E_APPDIDNTREG, 429
testHresMap E_ACCESSDENIED, 70
testHresMap E_OUTOFMEMORY, 7
testHresMap E_INVALIDARG, 5
testHresMap RPC_S_SERVER_UNAVAILABLE, 462
testHresMap CO_E_SERVER_EXEC_FAILURE, 429

sub testVBErrorCodes()
    on error resume next

    Err.clear()
    throwInt(&h800a00aa&)
    call ok(Err.number = 170, "Err.number = " & Err.number)

    Err.clear()
    throwInt(&h800a10aa&)
    call ok(Err.number = 4266, "Err.number = " & Err.number)
end sub

call testVBErrorCodes

on error resume next

throwWithDesc
ok err.number = &hdeadbeef&, "err.number = " & hex(err.number)
ok err.description = "test", "err.description = " & err.description
ok err.helpcontext = 10, "err.helpcontext = " & err.helpcontext
ok err.helpfile = "test.chm", "err.helpfile = " & err.helpfile

throwWithDesc = 1
ok err.number = &hdeadbeef&, "err.number = " & hex(err.number)
ok err.description = "test", "err.description = " & err.description
ok err.helpcontext = 10, "err.helpcontext = " & err.helpcontext
ok err.helpfile = "test.chm", "err.helpfile = " & err.helpfile

on error goto 0

call reportSuccess()
 ��  0   ��( L A N G . V B S         0           '
' Copyright 2011 Jacek Caban for CodeWeavers
'
' This library is free software; you can redistribute it and/or
' modify it under the terms of the GNU Lesser General Public
' License as published by the Free Software Foundation; either
' version 2.1 of the License, or (at your option) any later version.
'
' This library is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
' Lesser General Public License for more details.
'
' You should have received a copy of the GNU Lesser General Public
' License along with this library; if not, write to the Free Software
' Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
'

OPTION EXPLICIT  : : DIM W

dim x, y, z, e, hi
Dim obj

call ok(true, "true is not true?")
ok true, "true is not true?"
call ok((true), "true is not true?")

ok not false, "not false but not true?"
ok not not true, "not not true but not true?"

Call ok(true = true, "true = true is false")
Call ok(false = false, "false = false is false")
Call ok(not (true = false), "true = false is true")
Call ok("x" = "x", """x"" = ""x"" is false")
Call ok(empty = empty, "empty = empty is false")
Call ok(empty = "", "empty = """" is false")
Call ok(0 = 0.0, "0 <> 0.0")
Call ok(16 = &h10&, "16 <> &h10&")
Call ok(010 = 10, "010 <> 10")
Call ok(10. = 10, "10. <> 10")
Call ok(&hffFFffFF& = -1, "&hffFFffFF& <> -1")
Call ok(&hffFFffFF& = -1, "&hffFFffFF& <> -1")
Call ok(34e5 = 3400000, "34e5 <> 3400000")
Call ok(34e+5 = 3400000, "34e+5 <> 3400000")
Call ok(56.789e5 = 5678900, "56.789e5 = 5678900")
Call ok(56.789e-2 = 0.56789, "56.789e-2 <> 0.56789")
Call ok(1e-94938484 = 0, "1e-... <> 0")
Call ok(34e0 = 34, "34e0 <> 34")
Call ok(34E1 = 340, "34E0 <> 340")
Call ok(.5 = 0.5, ".5 <> 0.5")
Call ok(.5e1 = 5, ".5e1 <> 5")
Call ok(--1 = 1, "--1 = " & --1)
Call ok(-empty = 0, "-empty = " & (-empty))
Call ok(true = -1, "! true = -1")
Call ok(false = 0, "false <> 0")
Call ok(&hff = 255, "&hff <> 255")
Call ok(&Hff = 255, "&Hff <> 255")
Call ok(&hffff = -1, "&hffff <> -1")
Call ok(&hfffe = -2, "&hfffe <> -2")
Call ok(&hffff& = 65535, "&hffff& <> -1")
Call ok(&hfffe& = 65534, "&hfffe& <> -2")
Call ok(&hffffffff& = -1, "&hffffffff& <> -1")
Call ok((&h01or&h02)=3,"&h01or&h02 <> 3")

' Test concat when no space and var begins with h
hi = "y"
x = "x" &hi
Call ok(x = "xy", "x = " & x & " expected ""xy""")

W = 5
Call ok(W = 5, "W = " & W & " expected " & 5)

x = "xx"
Call ok(x = "xx", "x = " & x & " expected ""xx""")

Dim public1 : public1 = 42
Call ok(public1 = 42, "public1=" & public1 & " expected & " & 42)
Private priv1 : priv1 = 43
Call ok(priv1 = 43, "priv1=" & priv1 & " expected & " & 43)
Public pub1 : pub1 = 44
Call ok(pub1 = 44, "pub1=" & pub1 & " expected & " & 44)

Call ok(true <> false, "true <> false is false")
Call ok(not (true <> true), "true <> true is true")
Call ok(not ("x" <> "x"), """x"" <> ""x"" is true")
Call ok(not (empty <> empty), "empty <> empty is true")
Call ok(x <> "x", "x = ""x""")
Call ok("true" <> true, """true"" = true is true")

Call ok("" = true = false, """"" = true = false is false")
Call ok(not(false = true = ""), "false = true = """" is true")
Call ok(not (false = false <> false = false), "false = false <> false = false is true")
Call ok(not ("" <> false = false), """"" <> false = false is true")

Call ok(getVT(false) = "VT_BOOL", "getVT(false) is not VT_BOOL")
Call ok(getVT(true) = "VT_BOOL", "getVT(true) is not VT_BOOL")
Call ok(getVT("") = "VT_BSTR", "getVT("""") is not VT_BSTR")
Call ok(getVT("test") = "VT_BSTR", "getVT(""test"") is not VT_BSTR")
Call ok(getVT(Empty) = "VT_EMPTY", "getVT(Empty) is not VT_EMPTY")
Call ok(getVT(null) = "VT_NULL", "getVT(null) is not VT_NULL")
Call ok(getVT(0) = "VT_I2", "getVT(0) is not VT_I2")
Call ok(getVT(1) = "VT_I2", "getVT(1) is not VT_I2")
Call ok(getVT(0.5) = "VT_R8", "getVT(0.5) is not VT_R8")
Call ok(getVT(.5) = "VT_R8", "getVT(.5) is not VT_R8")
Call ok(getVT(0.0) = "VT_R8", "getVT(0.0) is not VT_R8")
Call ok(getVT(2147483647) = "VT_I4", "getVT(2147483647) is not VT_I4")
Call ok(getVT(2147483648) = "VT_R8", "getVT(2147483648) is not VT_R8")
Call ok(getVT(&h10&) = "VT_I2", "getVT(&h10&) is not VT_I2")
Call ok(getVT(&h10000&) = "VT_I4", "getVT(&h10000&) is not VT_I4")
Call ok(getVT(&H10000&) = "VT_I4", "getVT(&H10000&) is not VT_I4")
Call ok(getVT(&hffFFffFF&) = "VT_I2", "getVT(&hffFFffFF&) is not VT_I2")
Call ok(getVT(&hffFFffFE&) = "VT_I2", "getVT(&hffFFffFE &) is not VT_I2")
Call ok(getVT(&hffF&) = "VT_I2", "getVT(&hffFF&) is not VT_I2")
Call ok(getVT(&hffFF&) = "VT_I4", "getVT(&hffFF&) is not VT_I4")
Call ok(getVT(# 1/1/2011 #) = "VT_DATE", "getVT(# 1/1/2011 #) is not VT_DATE")
Call ok(getVT(1e2) = "VT_R8", "getVT(1e2) is not VT_R8")
Call ok(getVT(1e0) = "VT_R8", "getVT(1e0) is not VT_R8")
Call ok(getVT(0.1e2) = "VT_R8", "getVT(0.1e2) is not VT_R8")
Call ok(getVT(1 & 100000) = "VT_BSTR", "getVT(1 & 100000) is not VT_BSTR")
Call ok(getVT(-empty) = "VT_I2", "getVT(-empty) = " & getVT(-empty))
Call ok(getVT(-null) = "VT_NULL", "getVT(-null) = " & getVT(-null))
Call ok(getVT(y) = "VT_EMPTY*", "getVT(y) = " & getVT(y))
Call ok(getVT(nothing) = "VT_DISPATCH", "getVT(nothing) = " & getVT(nothing))
set x = nothing
Call ok(getVT(x) = "VT_DISPATCH*", "getVT(x=nothing) = " & getVT(x))
x = true
Call ok(getVT(x) = "VT_BOOL*", "getVT(x) = " & getVT(x))
Call ok(getVT(false or true) = "VT_BOOL", "getVT(false) is not VT_BOOL")
x = "x"
Call ok(getVT(x) = "VT_BSTR*", "getVT(x) is not VT_BSTR*")
x = 0.0
Call ok(getVT(x) = "VT_R8*", "getVT(x) = " & getVT(x))

Call ok(isNullDisp(nothing), "nothing is not nulldisp?")

x = "xx"
Call ok("ab" & "cd" = "abcd", """ab"" & ""cd"" <> ""abcd""")
Call ok("ab " & null = "ab ", """ab"" & null = " & ("ab " & null))
Call ok("ab " & empty = "ab ", """ab"" & empty = " & ("ab " & empty))
Call ok(1 & 100000 = "1100000", "1 & 100000 = " & (1 & 100000))
Call ok("ab" & x = "abxx", """ab"" & x = " & ("ab"&x))

if(isEnglishLang) then
    Call ok("" & true = "True", """"" & true = " & true)
    Call ok(true & false = "TrueFalse", "true & false = " & (true & false))
end if

call ok(true and true, "true and true is not true")
call ok(true and not false, "true and not false is not true")
call ok(not (false and true), "not (false and true) is not true")
call ok(getVT(null and true) = "VT_NULL", "getVT(null and true) = " & getVT(null and true))

call ok(false or true, "false or uie is false?")
call ok(not (false or false), "false or false is not false?")
call ok(false and false or true, "false and false or true is false?")
call ok(true or false and false, "true or false and false is false?")
call ok(null or true, "null or true is false")

call ok(true xor false, "true xor false is false?")
call ok(not (false xor false), "false xor false is true?")
call ok(not (true or false xor true), "true or false xor true is true?")
call ok(not (true xor false or true), "true xor false or true is true?")

call ok(false eqv false, "false does not equal false?")
call ok(not (false eqv true), "false equals true?")
call ok(getVT(false eqv null) = "VT_NULL", "getVT(false eqv null) = " & getVT(false eqv null))

call ok(true imp true, "true does not imp true?")
call ok(false imp false, "false does not imp false?")
call ok(not (true imp false), "true imp false?")
call ok(false imp null, "false imp null is false?")

Call ok(2 >= 1, "! 2 >= 1")
Call ok(2 >= 2, "! 2 >= 2")
Call ok(2 => 1, "! 2 => 1")
Call ok(2 => 2, "! 2 => 2")
Call ok(not(true >= 2), "true >= 2 ?")
Call ok(2 > 1, "! 2 > 1")
Call ok(false > true, "! false < true")
Call ok(0 > true, "! 0 > true")
Call ok(not (true > 0), "true > 0")
Call ok(not (0 > 1 = 1), "0 > 1 = 1")
Call ok(1 < 2, "! 1 < 2")
Call ok(1 = 1 < 0, "! 1 = 1 < 0")
Call ok(1 <= 2, "! 1 <= 2")
Call ok(2 <= 2, "! 2 <= 2")
Call ok(1 =< 2, "! 1 =< 2")
Call ok(2 =< 2, "! 2 =< 2")
Call ok(not (2 >< 2), "2 >< 2")
Call ok(2 >< 1, "! 2 >< 1")
Call ok(not (2 <> 2), "2 <> 2")
Call ok(2 <> 1, "! 2 <> 1")

Call ok(isNull(0 = null), "'(0 = null)' is not null")
Call ok(isNull(null = 1), "'(null = 1)' is not null")
Call ok(isNull(0 > null), "'(0 > null)' is not null")
Call ok(isNull(null > 1), "'(null > 1)' is not null")
Call ok(isNull(0 < null), "'(0 < null)' is not null")
Call ok(isNull(null < 1), "'(null < 1)' is not null")
Call ok(isNull(0 <> null), "'(0 <> null)' is not null")
Call ok(isNull(null <> 1), "'(null <> 1)' is not null")
Call ok(isNull(0 >= null), "'(0 >= null)' is not null")
Call ok(isNull(null >= 1), "'(null >= 1)' is not null")
Call ok(isNull(0 <= null), "'(0 <= null)' is not null")
Call ok(isNull(null <= 1), "'(null <= 1)' is not null")

x = 3
Call ok(2+2 = 4, "2+2 = " & (2+2))
Call ok(false + 6 + true = 5, "false + 6 + true <> 5")
Call ok(getVT(2+null) = "VT_NULL", "getVT(2+null) = " & getVT(2+null))
Call ok(2+empty = 2, "2+empty = " & (2+empty))
Call ok(x+x = 6, "x+x = " & (x+x))

Call ok(5-1 = 4, "5-1 = " & (5-1))
Call ok(3+5-true = 9, "3+5-true <> 9")
Call ok(getVT(2-null) = "VT_NULL", "getVT(2-null) = " & getVT(2-null))
Call ok(2-empty = 2, "2-empty = " & (2-empty))
Call ok(2-x = -1, "2-x = " & (2-x))

Call ok(9 Mod 6 = 3, "9 Mod 6 = " & (9 Mod 6))
Call ok(11.6 Mod 5.5 = False, "11.6 Mod 5.5 = " & (11.6 Mod 5.5 = 0.6))
Call ok(7 Mod 4+2 = 5, "7 Mod 4+2 <> 5")
Call ok(getVT(2 mod null) = "VT_NULL", "getVT(2 mod null) = " & getVT(2 mod null))
Call ok(getVT(null mod 2) = "VT_NULL", "getVT(null mod 2) = " & getVT(null mod 2))
'FIXME: Call ok(empty mod 2 = 0, "empty mod 2 = " & (empty mod 2))

Call ok(5 \ 2 = 2, "5 \ 2 = " & (5\2))
Call ok(4.6 \ 1.5 = 2, "4.6 \ 1.5 = " & (4.6\1.5))
Call ok(4.6 \ 1.49 = 5, "4.6 \ 1.49 = " & (4.6\1.49))
Call ok(2+3\4 = 2, "2+3\4 = " & (2+3\4))

Call ok(2*3 = 6, "2*3 = " & (2*3))
Call ok(3/2 = 1.5, "3/2 = " & (3/2))
Call ok(5\4/2 = 2, "5\4/2 = " & (5\2/1))
Call ok(12/3\2 = 2, "12/3\2 = " & (12/3\2))
Call ok(5/1000000 = 0.000005, "5/1000000 = " & (5/1000000))

Call ok(2^3 = 8, "2^3 = " & (2^3))
Call ok(2^3^2 = 64, "2^3^2 = " & (2^3^2))
Call ok(-3^2 = 9, "-3^2 = " & (-3^2))
Call ok(2*3^2 = 18, "2*3^2 = " & (2*3^2))

x =_
    3
x _
    = 3

x = 3

if true then y = true : x = y
ok x, "x is false"

x = true : if false then x = false
ok x, "x is false, if false called?"

if not false then x = true
ok x, "x is false, if not false not called?"

if not false then x = "test" : x = true
ok x, "x is false, if not false not called?"

if false then x = y : call ok(false, "if false .. : called")

if false then x = y : call ok(false, "if false .. : called") else x = "else"
Call ok(x = "else", "else not called?")

if true then x = y else y = x : Call ok(false, "in else?")

if false then :

if false then x = y : if true then call ok(false, "embedded if called")

if false then x=1 else x=2 end if
if true then x=1 end if

x = false
if false then x = true : x = true
Call ok(x = false, "x <> false")

if false then
    ok false, "if false called"
end if

x = true
if x then
    x = false
end if
Call ok(not x, "x is false, if not evaluated?")

x = false
If false Then
   Call ok(false, "inside if false")
Else
   x = true
End If
Call ok(x, "else not called?")

' Else without following newline
x = false
If false Then
   Call ok(false, "inside if false")
Else x = true
End If
Call ok(x, "else not called?")

' Else with colon before statement following newline
x = false
If false Then
   Call ok(false, "inside if false")
Else
: x = true
End If
Call ok(x, "else not called?")

x = false
If false Then
   Call ok(false, "inside if false")
ElseIf not True Then
   Call ok(false, "inside elseif not true")
Else
   x = true
End If
Call ok(x, "else not called?")

x = false
If false Then
   Call ok(false, "inside if false")
   x = 1
   y = 10+x
ElseIf not False Then
   x = true
Else
   Call ok(false, "inside else not true")
End If
Call ok(x, "elseif not called?")

x = false
If false Then
   Call ok(false, "inside if false")
ElseIf not False Then
   x = true
End If
Call ok(x, "elseif not called?")

' ElseIf with statement on same line
x = false
If false Then
   Call ok(false, "inside if false")
ElseIf not False Then x = true
End If
Call ok(x, "elseif not called?")

' ElseIf with statement following statement separator
x = false
If false Then
   Call ok(false, "inside if false")
ElseIf not False Then
: x = true
End If
Call ok(x, "elseif not called?")

x = false
if 1 then x = true
Call ok(x, "if 1 not run?")

x = false
if &h10000& then x = true
Call ok(x, "if &h10000& not run?")

x = false
y = false
while not (x and y)
    if x then
        y = true
    end if
    x = true
wend
call ok((x and y), "x or y is false after while")

if false then
' empty body
end if

if false then
    x = false
elseif true then
' empty body
end if

if false then
    x = false
else
' empty body
end if

while false
wend

if empty then
   ok false, "if empty executed"
end if

while empty
   ok false, "while empty executed"
wend

x = 0
if "0" then
   ok false, "if ""0"" executed"
else
   x = 1
end if
Call ok(x = 1, "if ""0"" else not executed")

x = 0
if "-1" then
   x = 1
else
   ok false, "if ""-1"" else executed"
end if
Call ok(x = 1, "if ""-1"" not executed")

x = 0
if 0.1 then
   x = 1
else
   ok false, "if ""0.1"" else executed"
end if
Call ok(x = 1, "if ""0.1"" not executed")

x = 0
if "TRUE" then
   x = 1
else
   ok false, "if ""TRUE"" else executed"
end if
Call ok(x = 1, "if ""TRUE"" not executed")

x = 0
if "#TRUE#" then
   x = 1
else
   ok false, "if ""#TRUE#"" else executed"
end if
Call ok(x = 1, "if ""#TRUE#"" not executed")

x = 0
if (not "#FALSE#") then
   x = 1
else
   ok false, "if ""not #FALSE#"" else executed"
end if
Call ok(x = 1, "if ""not #FALSE#"" not executed")

Class ValClass
    Public myval

    Public default Property Get defprop
        defprop = myval
    End Property
End Class

Dim MyObject
Set MyObject = New ValClass

MyObject.myval = 1
Call ok(CBool(MyObject) = True, "CBool(MyObject) = " & CBool(MyObject))
x = 0
if MyObject then
   x = 1
else
   ok false, "if ""MyObject(1)"" else executed"
end if
Call ok(x = 1, "if ""MyObject(1)"" not executed")

MyObject.myval = 0
Call ok(CBool(MyObject) = False, "CBool(MyObject) = " & CBool(MyObject))
x = 0
if not MyObject then
   x = 1
else
   ok false, "if ""MyObject(0)"" else executed"
end if
Call ok(x = 1, "if ""MyObject(0)"" not executed")

x = 0
WHILE x < 3 : x = x + 1 : Wend
Call ok(x = 3, "x not equal to 3")

x = 0
WHILE x < 3 : x = x + 1
Wend
Call ok(x = 3, "x not equal to 3")

z = 2
while z > -4 :


z = z -2
wend

x = false
y = false
do while not (x and y)
    if x then
        y = true
    end if
    x = true
loop
call ok((x and y), "x or y is false after while")

do while false
loop

do while false : loop

do while true
    exit do
    ok false, "exit do didn't work"
loop

x = 0
Do While x < 2 : x = x + 1
Loop
Call ok(x = 2, "x not equal to 2")

x = 0
Do While x < 2 : x = x + 1: Loop
Call ok(x = 2, "x not equal to 2")

x = 0
Do While x >= -2 :
x = x - 1
Loop
Call ok(x = -3, "x not equal to -3")

x = false
y = false
do until x and y
    if x then
        y = true
    end if
    x = true
loop
call ok((x and y), "x or y is false after do until")

do until true
loop

do until false
    exit do
    ok false, "exit do didn't work"
loop

x = 0
Do: :: x = x + 2
Loop Until x = 4
Call ok(x = 4, "x not equal to 4")

x = 0
Do: :: x = x + 2 :::  : Loop Until x = 4
Call ok(x = 4, "x not equal to 4")

x = 5
Do: :

: x = x * 2
Loop Until x = 40
Call ok(x = 40, "x not equal to 40")


x = false
do
    if x then exit do
    x = true
loop
call ok(x, "x is false after do..loop?")

x = 0
Do :If x = 6 Then
        Exit Do
    End If
    x = x + 3
Loop
Call ok(x = 6, "x not equal to 6")

x = false
y = false
do
    if x then
        y = true
    end if
    x = true
loop until x and y
call ok((x and y), "x or y is false after while")

do
loop until true

do
    exit do
    ok false, "exit do didn't work"
loop until false

x = false
y = false
do
    if x then
        y = true
    end if
    x = true
loop while not (x and y)
call ok((x and y), "x or y is false after while")

do
loop while false

do
    exit do
    ok false, "exit do didn't work"
loop while true

y = "for1:"
for x = 5 to 8
    y = y & " " & x
next
Call ok(y = "for1: 5 6 7 8", "y = " & y)

y = "for2:"
for x = 5 to 8 step 2
    y = y & " " & x
next
Call ok(y = "for2: 5 7", "y = " & y)

y = "for3:"
x = 2
for x = x+3 to 8
    y = y & " " & x
next
Call ok(y = "for3: 5 6 7 8", "y = " & y)

y = "for4:"
for x = 5 to 4
    y = y & " " & x
next
Call ok(y = "for4:", "y = " & y)

y = "for5:"
for x = 5 to 3 step true
    y = y & " " & x
next
Call ok(y = "for5: 5 4 3", "y = " & y)

y = "for6:"
z = 4
for x = 5 to z step 3-4
    y = y & " " & x
    z = 0
next
Call ok(y = "for6: 5 4", "y = " & y)

y = "for7:"
z = 1
for x = 5 to 8 step z
    y = y & " " & x
    z = 2
next
Call ok(y = "for7: 5 6 7 8", "y = " & y)

z = 0
For x = 10 To 18 Step 2 : : z = z + 1
Next
Call ok(z = 5, "z not equal to 5")

y = "for8:"
for x = 5 to 8
    y = y & " " & x
    x = x+1
next
Call ok(y = "for8: 5 7", "y = " & y)

function testfor( startvalue, endvalue, stepvalue, steps)
    Dim s
    s=0
    for x=startvalue to endvalue step stepvalue
        s = s + 1
    Next
    Call ok( s = steps, "counted " & s & " steps in for loop, expected " & steps)
end function

Call testfor (1, 2, 1, 2)
Call testfor ("1", 2, 1, 2)
Call testfor (1, "2", 1, 2)
Call testfor (1, 2, "1", 2)
Call testfor ("1", "2", "1", 2)
if (isEnglishLang) then
    Call testfor (1, 2, 0.5, 3)
    Call testfor (1, 2.5, 0.5, 4)
    Call testfor ("1", 2,  0.5, 3)
    Call testfor ("1", 2.5, 0.5, 4)
    Call testfor (1, "2",  0.5, 3)
    Call testfor (1, "2.5", 0.5, 4)
    Call testfor (1, 2, "0.5", 3)
    Call testfor (1, 2.5, "0.5", 4)
    Call testfor ("1", "2", "0.5", 3)
    Call testfor ("1", "2.5", "0.5", 4)
end if

for x = 1.5 to 1
    Call ok(false, "for..to called when unexpected")
next

for x = 1 to 100
    exit for
    Call ok(false, "exit for not escaped the loop?")
next

for x = 1 to 5 :
:
:   :exit for
    Call ok(false, "exit for not escaped the loop?")
next

dim a1(8)
a1(6)=8
for x=1 to 8:a1(x)=x-1:next
Call ok(a1(6) = 5, "colon used in for loop")

a1(6)=8
for x=1 to 8:y=1
a1(x)=x-2:next
Call ok(a1(6) = 4, "colon used in for loop")

do while true
    for x = 1 to 100
        exit do
    next
loop

if null then call ok(false, "if null evaluated")

while null
    call ok(false, "while null evaluated")
wend

Call collectionObj.reset()
y = 0
for each x in collectionObj :

   :y = y + 3
next
Call ok(y = 9, "y = " & y)

Call collectionObj.reset()
y = 0
x = 10
z = 0
for each x in collectionObj : z = z + 2
    y = y+1
    Call ok(x = y, "x <> y")
next
Call ok(y = 3, "y = " & y)
Call ok(z = 6, "z = " & z)
Call ok(getVT(x) = "VT_EMPTY*", "getVT(x) = " & getVT(x))

Call collectionObj.reset()
y = 0
x = 10
z = 0
for each x in collectionObj : z = z + 2 : y = y+1 ::
Call ok(x = y, "x <> y") : next
Call ok(y = 3, "y = " & y)
Call ok(z = 6, "z = " & z)

Call collectionObj.reset()
y = false
for each x in collectionObj
    if x = 2 then exit for
    y = 1
next
Call ok(y = 1, "y = " & y)
Call ok(x = 2, "x = " & x)

Set obj = collectionObj
Call obj.reset()
y = 0
x = 10
for each x in obj
    y = y+1
    Call ok(x = y, "x <> y")
next
Call ok(y = 3, "y = " & y)
Call ok(getVT(x) = "VT_EMPTY*", "getVT(x) = " & getVT(x))

x = false
select case 3
    case 2
        Call ok(false, "unexpected case")
    case 2
        Call ok(false, "unexpected case")
    case 4
        Call ok(false, "unexpected case")
    case "test"
    case "another case"
        Call ok(false, "unexpected case")
    case 0, false, 2+1, 10
        x = true
    case ok(false, "unexpected case")
        Call ok(false, "unexpected case")
    case else
        Call ok(false, "unexpected case")
end select
Call ok(x, "wrong case")

x = false
select case 3
    case 3
        x = true
end select
Call ok(x, "wrong case")

x = false
select case 2+2
    case 3
        Call ok(false, "unexpected case")
    case else
        x = true
end select
Call ok(x, "wrong case")

y = "3"
x = false
select case y
    case "3"
        x = true
    case 3
        Call ok(false, "unexpected case")
end select
Call ok(x, "wrong case")

select case 0
    case 1
        Call ok(false, "unexpected case")
    case "2"
        Call ok(false, "unexpected case")
end select

select case 0
end select

x = false
select case 2
    case 3,1,2,4: x = true
    case 5,6,7
        Call ok(false, "unexpected case")
end select
Call ok(x, "wrong case")

x = false
select case 2: case 5,6,7: Call ok(false, "unexpected case")
    case 2,1,2,4
        x = true
    case else: Call ok(false, "unexpected case else")
end select
Call ok(x, "wrong case")

x = False
select case 1  :

    :case 3, 4 :


    case 5
:
        Call ok(false, "unexpected case") :
    Case Else:

        x = True
end select
Call ok(x, "wrong case")

select case 0
    case 1
    case else
       'empty else with comment test
end select

select case 0 : case 1 : case else : end select

' Case without separator
function SelectCaseTest(x)
    select case x
        case 0: SelectCaseTest = 100
        case 1  SelectCaseTest = 200
        case 2
                SelectCaseTest = 300
        case 3
        case 4  SelectCaseTest = 400
        case else SelectCaseTest = 500
    end select
end function

call ok(SelectCaseTest(0) = 100, "Unexpected case " & SelectCaseTest(0))
call ok(SelectCaseTest(1) = 200, "Unexpected case " & SelectCaseTest(1))
call ok(SelectCaseTest(2) = 300, "Unexpected case " & SelectCaseTest(2))
call ok(SelectCaseTest(3) = vbEmpty, "Unexpected case " & SelectCaseTest(3))
call ok(SelectCaseTest(4) = 400, "Unexpected case " & SelectCaseTest(4))
call ok(SelectCaseTest(5) = 500, "Unexpected case " & SelectCaseTest(5))

if false then
Sub testsub
    x = true
End Sub
end if

x = false
Call testsub
Call ok(x, "x is false, testsub not called?")

if false then
Sub testsub_one_line() x = true End Sub
end if

x = false
Call testsub_one_line
Call ok(x, "x is false, testsub_one_line not called?")

Sub SubSetTrue(v)
    Call ok(not v, "v is not true")
    v = true
End Sub

x = false
SubSetTrue x
Call ok(x, "x was not set by SubSetTrue")

SubSetTrue false
Call ok(not false, "false is no longer false?")

Sub SubSetTrue2(ByRef v)
    Call ok(not v, "v is not true")
    v = true
End Sub

x = false
SubSetTrue2 x
Call ok(x, "x was not set by SubSetTrue")

Sub TestSubArgVal(ByVal v)
    Call ok(not v, "v is not false")
    v = true
    Call ok(v, "v is not true?")
End Sub

x = false
Call TestSubArgVal(x)
Call ok(not x, "x is true after TestSubArgVal call?")

Sub TestSubMultiArgs(a,b,c,d,e)
    Call ok(a=1, "a = " & a)
    Call ok(b=2, "b = " & b)
    Call ok(c=3, "c = " & c)
    Call ok(d=4, "d = " & d)
    Call ok(e=5, "e = " & e)
End Sub

Sub TestSubExit(ByRef a)
    If a Then
        Exit Sub
    End If
    Call ok(false, "Exit Sub not called?")
End Sub

Call TestSubExit(true)

Sub TestSubExit2
    for x = 1 to 100
        Exit Sub
    next
End Sub
Call TestSubExit2

TestSubMultiArgs 1, 2, 3, 4, 5
Call TestSubMultiArgs(1, 2, 3, 4, 5)

Sub TestSubLocalVal
    x = false
    Call ok(not x, "local x is not false?")
    Dim x
    Dim a,b, c
End Sub

x = true
y = true
Call TestSubLocalVal
Call ok(x, "global x is not true?")

Public Sub TestPublicSub
End Sub
Call TestPublicSub

Private Sub TestPrivateSub
End Sub
Call TestPrivateSub

Public Sub TestSeparatorSub : :
:
End Sub
Call TestSeparatorSub

if false then
Function testfunc
    x = true
End Function
end if

x = false
Call TestFunc
Call ok(x, "x is false, testfunc not called?")

if false then
Function testfunc_one_line() x = true End Function
end if

x = false
Call testfunc_one_line
Call ok(x, "x is false, testfunc_one_line not called?")

Function FuncSetTrue(v)
    Call ok(not v, "v is not true")
    v = true
End Function

x = false
FuncSetTrue x
Call ok(x, "x was not set by FuncSetTrue")

FuncSetTrue false
Call ok(not false, "false is no longer false?")

Function FuncSetTrue2(ByRef v)
    Call ok(not v, "v is not true")
    v = true
End Function

x = false
FuncSetTrue2 x
Call ok(x, "x was not set by FuncSetTrue")

Function TestFuncArgVal(ByVal v)
    Call ok(not v, "v is not false")
    v = true
    Call ok(v, "v is not true?")
End Function

x = false
Call TestFuncArgVal(x)
Call ok(not x, "x is true after TestFuncArgVal call?")

const c10 = 10
Sub TestParamvsConst(c10)
    Call ok( c10 = 42, "precedence between const and parameter wrong!")
End Sub
Call TestParamvsConst(42)

Sub TestDimVsConst
    dim c10
    c10 = 42
    Call ok( c10 = 42, "precedence between const and dim is wrong")
End Sub
Call TestDimVsConst

Function TestFuncMultiArgs(a,b,c,d,e)
    Call ok(a=1, "a = " & a)
    Call ok(b=2, "b = " & b)
    Call ok(c=3, "c = " & c)
    Call ok(d=4, "d = " & d)
    Call ok(e=5, "e = " & e)
End Function

TestFuncMultiArgs 1, 2, 3, 4, 5
Call TestFuncMultiArgs(1, 2, 3, 4, 5)

Function TestFuncLocalVal
    x = false
    Call ok(not x, "local x is not false?")
    Dim x
End Function

x = true
y = true
Call TestFuncLocalVal
Call ok(x, "global x is not true?")

Function TestFuncExit(ByRef a)
    If a Then
        Exit Function
    End If
    Call ok(false, "Exit Function not called?")
End Function

Call TestFuncExit(true)

Function TestFuncExit2(ByRef a)
    For x = 1 to 100
        For y = 1 to 100
            Exit Function
        Next
    Next
    Call ok(false, "Exit Function not called?")
End Function

Call TestFuncExit2(true)

Sub SubParseTest
End Sub : x = false
Call SubParseTest

Function FuncParseTest
End Function : x = false

Function ReturnTrue
     ReturnTrue = false
     ReturnTrue = true
End Function

Call ok(ReturnTrue(), "ReturnTrue returned false?")

Function SetVal(ByRef x, ByVal v)
    x = v
    SetVal = x
    Exit Function
End Function

x = false
ok SetVal(x, true), "SetVal returned false?"
Call ok(x, "x is not set to true by SetVal?")

Public Function TestPublicFunc
End Function
Call TestPublicFunc

Private Function TestPrivateFunc
End Function
Call TestPrivateFunc

Public Function TestSepFunc(ByVal a) : :
: TestSepFunc = a
End Function
Call ok(TestSepFunc(1) = 1, "Function did not return 1")

ok duplicatedfunc() = 2, "duplicatedfunc = " & duplicatedfunc()

function duplicatedfunc
    ok false, "duplicatedfunc called"
end function

sub duplicatedfunc
    ok false, "duplicatedfunc called"
end sub

function duplicatedfunc
    duplicatedfunc = 2
end function

ok duplicatedfunc() = 2, "duplicatedfunc = " & duplicatedfunc()

' Stop has an effect only in debugging mode
Stop

set x = testObj
Call ok(getVT(x) = "VT_DISPATCH*", "getVT(x=testObj) = " & getVT(x))

Set obj = New EmptyClass
Call ok(getVT(obj) = "VT_DISPATCH*", "getVT(obj) = " & getVT(obj))

Class EmptyClass
End Class

Set x = obj
Call ok(getVT(x) = "VT_DISPATCH*", "getVT(x) = " & getVT(x))

Class TestClass
    Public publicProp
    Public publicArrayProp

    Private privateProp

    Public Function publicFunction()
        privateSub()
        publicFunction = 4
    End Function

    Public Property Get gsProp()
        gsProp = privateProp
        funcCalled = "gsProp get"
        exit property
        Call ok(false, "exit property not returned?")
    End Property

    Public Default Property Get DefValGet
        DefValGet = privateProp
        funcCalled = "GetDefVal"
    End Property

    Public Property Let DefValGet(x)
    End Property

    Public publicProp2

    Public Sub publicSub
    End Sub

    Public Property Let gsProp(val)
        privateProp = val
        funcCalled = "gsProp let"
        exit property
        Call ok(false, "exit property not returned?")
    End Property

    Public Property Set gsProp(val)
        funcCalled = "gsProp set"
        exit property
        Call ok(false, "exit property not returned?")
    End Property

    Public Sub setPrivateProp(x)
        privateProp = x
    End Sub

    Function getPrivateProp
        getPrivateProp = privateProp
    End Function

    Private Sub privateSub
    End Sub

    Public Sub Class_Initialize
        publicProp2 = 2
        ReDim publicArrayProp(2)

        publicArrayProp(0) = 1
        publicArrayProp(1) = 2

        privateProp = true
        Call ok(getVT(privateProp) = "VT_BOOL*", "getVT(privateProp) = " & getVT(privateProp))
        Call ok(getVT(publicProp2) = "VT_I2*", "getVT(publicProp2) = " & getVT(publicProp2))
        Call ok(getVT(Me.publicProp2) = "VT_I2", "getVT(Me.publicProp2) = " & getVT(Me.publicProp2))
    End Sub

    Property Get gsGetProp(x)
        gsGetProp = x
    End Property
End Class

Call testDisp(new testClass)

Set obj = New TestClass

Call ok(obj.publicFunction = 4, "obj.publicFunction = " & obj.publicFunction)
Call ok(obj.publicFunction() = 4, "obj.publicFunction() = " & obj.publicFunction())

obj.publicSub()
Call obj.publicSub
Call obj.publicFunction()

Call ok(getVT(obj.publicProp) = "VT_EMPTY", "getVT(obj.publicProp) = " & getVT(obj.publicProp))
obj.publicProp = 3
Call ok(getVT(obj.publicProp) = "VT_I2", "getVT(obj.publicProp) = " & getVT(obj.publicProp))
Call ok(obj.publicProp = 3, "obj.publicProp = " & obj.publicProp)
obj.publicProp() = 3

Call ok(obj.getPrivateProp() = true, "obj.getPrivateProp() = " & obj.getPrivateProp())
Call obj.setPrivateProp(6)
Call ok(obj.getPrivateProp = 6, "obj.getPrivateProp = " & obj.getPrivateProp)

Dim funcCalled
funcCalled = ""
Call ok(obj.gsProp = 6, "obj.gsProp = " & obj.gsProp)
Call ok(funcCalled = "gsProp get", "funcCalled = " & funcCalled)
obj.gsProp = 3
Call ok(funcCalled = "gsProp let", "funcCalled = " & funcCalled)
Call ok(obj.getPrivateProp = 3, "obj.getPrivateProp = " & obj.getPrivateProp)
Set obj.gsProp = New testclass
Call ok(funcCalled = "gsProp set", "funcCalled = " & funcCalled)

x = obj
Call ok(x = 3, "(x = obj) = " & x)
Call ok(funcCalled = "GetDefVal", "funcCalled = " & funcCalled)
funcCalled = ""
Call ok(obj = 3, "(x = obj) = " & obj)
Call ok(funcCalled = "GetDefVal", "funcCalled = " & funcCalled)

Call obj.Class_Initialize
Call ok(obj.getPrivateProp() = true, "obj.getPrivateProp() = " & obj.getPrivateProp())

'Accessing array property by index
Call ok(obj.publicArrayProp(0) = 1, "obj.publicArrayProp(0) = " & obj.publicArrayProp(0))
Call ok(obj.publicArrayProp(1) = 2, "obj.publicArrayProp(1) = " & obj.publicArrayProp(1))
x = obj.publicArrayProp(2)
Call ok(getVT(x) = "VT_EMPTY*", "getVT(x) = " & getVT(x))
Call ok(obj.publicArrayProp("0") = 1, "obj.publicArrayProp(0) = " & obj.publicArrayProp("0"))

x = (New testclass).publicProp

Class TermTest
    Public Sub Class_Terminate()
        funcCalled = "terminate"
    End Sub
End Class

Set obj = New TermTest
funcCalled = ""
Set obj = Nothing
Call ok(funcCalled = "terminate", "funcCalled = " & funcCalled)

Set obj = New TermTest
funcCalled = ""
Call obj.Class_Terminate
Call ok(funcCalled = "terminate", "funcCalled = " & funcCalled)
funcCalled = ""
Set obj = Nothing
Call ok(funcCalled = "terminate", "funcCalled = " & funcCalled)

Call (New testclass).publicSub()
Call (New testclass).publicSub

class PropTest
    property get prop0()
        prop0 = 1
    end property

    property get prop1(x)
        prop1 = x+1
    end property

    property get prop2(x, y)
        prop2 = x+y
    end property
end class

set obj = new PropTest

call ok(obj.prop0 = 1, "obj.prop0 = " & obj.prop0)
call ok(obj.prop1(3) = 4, "obj.prop1(3) = " & obj.prop1(3))
call ok(obj.prop2(3,4) = 7, "obj.prop2(3,4) = " & obj.prop2(3,4))
call obj.prop0()
call obj.prop1(2)
call obj.prop2(3,4)

x = "following ':' is correct syntax" :
x = "following ':' is correct syntax" :: :
:: x = "also correct syntax"
rem another ugly way for comments
x = "rem as simplestatement" : rem rem comment
:

Set obj = new EmptyClass
Set x = obj
Set y = new EmptyClass

Call ok(obj is x, "obj is not x")
Call ok(x is obj, "x is not obj")
Call ok(not (obj is y), "obj is not y")
Call ok(not obj is y, "obj is not y")
Call ok(not (x is Nothing), "x is 1")
Call ok(Nothing is Nothing, "Nothing is not Nothing")
Call ok(x is obj and true, "x is obj and true is false")

Class TestMe
    Public Sub Test(MyMe)
        Call ok(Me is MyMe, "Me is not MyMe")
    End Sub
End Class

Set obj = New TestMe
Call obj.test(obj)

Call ok(getVT(test) = "VT_DISPATCH", "getVT(test) = " & getVT(test))
Call ok(Me is Test, "Me is not Test")

Const c1 = 1, c2 = 2, c3 = -3
Private Const c4 = 4
Public Const c5 = 5
Call ok(c1 = 1, "c1 = " & c1)
Call ok(getVT(c1) = "VT_I2", "getVT(c1) = " & getVT(c1))
Call ok(c3 = -3, "c3 = " & c3)
Call ok(getVT(c3) = "VT_I2", "getVT(c3) = " & getVT(c3))
Call ok(c4 = 4, "c4 = " & c4)
Call ok(getVT(c4) = "VT_I2", "getVT(c4) = " & getVT(c4))
Call ok(c5 = 5, "c5 = " & c5)
Call ok(getVT(c5) = "VT_I2", "getVT(c5) = " & getVT(c5))

Const cb = True, cs = "test", cnull = null
Call ok(cb, "cb = " & cb)
Call ok(getVT(cb) = "VT_BOOL", "getVT(cb) = " & getVT(cb))
Call ok(cs = "test", "cs = " & cs)
Call ok(getVT(cs) = "VT_BSTR", "getVT(cs) = " & getVT(cs))
Call ok(isNull(cnull), "cnull = " & cnull)
Call ok(getVT(cnull) = "VT_NULL", "getVT(cnull) = " & getVT(cnull))

Call ok(+1 = 1, "+1 != 1")
Call ok(+true = true, "+1 != 1")
Call ok(getVT(+true) = "VT_BOOL", "getVT(+true) = " & getVT(+true))
Call ok(+"true" = "true", """+true"" != true")
Call ok(getVT(+"true") = "VT_BSTR", "getVT(+""true"") = " & getVT(+"true"))
Call ok(+obj is obj, "+obj != obj")
Call ok(+--+-+1 = -1, "+--+-+1 != -1")

if false then Const conststr = "str"
Call ok(conststr = "str", "conststr = " & conststr)
Call ok(getVT(conststr) = "VT_BSTR", "getVT(conststr) = " & getVT(conststr))
Call ok(conststr = "str", "conststr = " & conststr)

Sub ConstTestSub
    Const funcconst = 1
    Call ok(c1 = 1, "c1 = " & c1)
    Call ok(funcconst = 1, "funcconst = " & funcconst)
End Sub

Call ConstTestSub
Dim funcconst

' Property may be used as an identifier (although it's a keyword)
Sub TestProperty
    Dim Property
    PROPERTY = true
    Call ok(property, "property = " & property)

    for property = 1 to 2
    next
End Sub

Call TestProperty

Class Property
    Public Sub Property()
    End Sub

    Sub Test(byref property)
    End Sub
End Class

Class Property2
    Function Property()
    End Function

    Sub Test(property)
    End Sub

    Sub Test2(byval property)
    End Sub
End Class

Class SeparatorTest : : Dim varTest1
:
    Private Sub Class_Initialize : varTest1 = 1
    End Sub ::

    Property Get Test1() :
        Test1 = varTest1
    End Property ::
: :
    Property Let Test1(a) :
        varTest1 = a
    End Property :

    Public Function AddToTest1(ByVal a)  :: :
        varTest1 = varTest1 + a
        AddToTest1 = varTest1
    End Function :    End Class : ::   Set obj = New SeparatorTest

Call ok(obj.Test1 = 1, "obj.Test1 is not 1")
obj.Test1 = 6
Call ok(obj.Test1 = 6, "obj.Test1 is not 6")
obj.AddToTest1(5)
Call ok(obj.Test1 = 11, "obj.Test1 is not 11")

set obj = unkObj
set x = obj
call ok(getVT(obj) = "VT_UNKNOWN*", "getVT(obj) = " & getVT(obj))
call ok(getVT(x) = "VT_UNKNOWN*", "getVT(x) = " & getVT(x))
call ok(getVT(unkObj) = "VT_UNKNOWN", "getVT(unkObj) = " & getVT(unkObj))
call ok(obj is unkObj, "obj is not unkObj")

' Array tests

Call ok(getVT(arr) = "VT_EMPTY*", "getVT(arr) = " & getVT(arr))

Dim arr(3)
Dim arr2(4,3), arr3(5,4,3), arr0(0), noarr()

Call ok(getVT(arr) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(arr) = " & getVT(arr))
Call ok(getVT(arr2) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(arr2) = " & getVT(arr2))
Call ok(getVT(arr0) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(arr0) = " & getVT(arr0))
Call ok(getVT(noarr) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(noarr) = " & getVT(noarr))

Call testArray(1, arr)
Call testArray(2, arr2)
Call testArray(3, arr3)
Call testArray(0, arr0)
Call testArray(-1, noarr)

Call ok(getVT(arr(1)) = "VT_EMPTY*", "getVT(arr(1)) = " & getVT(arr(1)))
Call ok(getVT(arr2(1,2)) = "VT_EMPTY*", "getVT(arr2(1,2)) = " & getVT(arr2(1,2)))
Call ok(getVT(arr3(1,2,2)) = "VT_EMPTY*", "getVT(arr3(1,2,3)) = " & getVT(arr3(1,2,2)))
Call ok(getVT(arr(0)) = "VT_EMPTY*", "getVT(arr(0)) = " & getVT(arr(0)))
Call ok(getVT(arr(3)) = "VT_EMPTY*", "getVT(arr(3)) = " & getVT(arr(3)))
Call ok(getVT(arr0(0)) = "VT_EMPTY*", "getVT(arr0(0)) = " & getVT(arr0(0)))

arr(2) = 3
Call ok(arr(2) = 3, "arr(2) = " & arr(2))
Call ok(getVT(arr(2)) = "VT_I2*", "getVT(arr(2)) = " & getVT(arr(2)))

arr3(3,2,1) = 1
arr3(1,2,3) = 2
Call ok(arr3(3,2,1) = 1, "arr3(3,2,1) = " & arr3(3,2,1))
Call ok(arr3(1,2,3) = 2, "arr3(1,2,3) = " & arr3(1,2,3))
arr2(4,3) = 1
Call ok(arr2(4,3) = 1, "arr2(4,3) = " & arr2(4,3))

x = arr3
Call ok(x(3,2,1) = 1, "x(3,2,1) = " & x(3,2,1))

Function getarr()
    Dim arr(3)
    arr(2) = 2
    getarr = arr
    arr(3) = 3
End Function

x = getarr()
Call ok(getVT(x) = "VT_ARRAY|VT_VARIANT*", "getVT(x) = " & getVT(x))
Call ok(x(2) = 2, "x(2) = " & x(2))
Call ok(getVT(x(3)) = "VT_EMPTY*", "getVT(x(3)) = " & getVT(x(3)))

x(1) = 1
Call ok(x(1) = 1, "x(1) = " & x(1))
x = getarr()
Call ok(getVT(x(1)) = "VT_EMPTY*", "getVT(x(1)) = " & getVT(x(1)))
Call ok(x(2) = 2, "x(2) = " & x(2))

x(1) = 1
y = x
x(1) = 2
Call ok(y(1) = 1, "y(1) = " & y(1))

for x=1 to 1
    Dim forarr(3)
    if x=1 then
        Call ok(getVT(forarr(1)) = "VT_EMPTY*", "getVT(forarr(1)) = " & getVT(forarr(1)))
    else
        Call ok(forarr(1) = x, "forarr(1) = " & forarr(1))
    end if
    forarr(1) = x+1
next

x=1
Call ok(forarr(x) = 2, "forarr(x) = " & forarr(x))

sub accessArr()
    ok arr(1) = 1, "arr(1) = " & arr(1)
    arr(1) = 2
end sub
arr(1) = 1
call accessArr
ok arr(1) = 2, "arr(1) = " & arr(1)

sub accessArr2(x,y)
    ok arr2(x,y) = 1, "arr2(x,y) = " & arr2(x,y)
    x = arr2(x,y)
    arr2(x,y) = 2
end sub
arr2(1,2) = 1
call accessArr2(1, 2)
ok arr2(1,2) = 2, "arr2(1,2) = " & arr2(1,2)

x = Array(Array(3))
call ok(x(0)(0) = 3, "x(0)(0) = " & x(0)(0))

function seta0(arr)
    arr(0) = 2
    seta0 = 1
end function

x = Array(1)
seta0 x
ok x(0) = 2, "x(0) = " & x(0)

x = Array(1)
seta0 (x)
ok x(0) = 1, "x(0) = " & x(0)

x = Array(1)
call (((seta0))) ((x))
ok x(0) = 1, "x(0) = " & x(0)

x = Array(1)
call (((seta0))) (x)
ok x(0) = 2, "x(0) = " & x(0)

x = Array(Array(3))
seta0 x(0)
call ok(x(0)(0) = 2, "x(0)(0) = " & x(0)(0))

x = Array(Array(3))
seta0 (x(0))
call ok(x(0)(0) = 3, "x(0)(0) = " & x(0)(0))

y = (seta0)(x)
ok y = 1, "y = " & y

y = ((x))(0)
ok y = 2, "y = " & y

sub changearg(x)
    x = 2
end sub

x = Array(1)
changearg x(0)
ok x(0) = 2, "x(0) = " & x(0)
ok getVT(x) = "VT_ARRAY|VT_VARIANT*", "getVT(x) after redim = " & getVT(x)

x = Array(1)
changearg (x(0))
ok x(0) = 1, "x(0) = " & x(0)

x = Array(1)
redim x(4)
ok ubound(x) = 4, "ubound(x) = " & ubound(x)
ok x(0) = empty, "x(0) = " & x(0)

x = 1
redim x(3)
ok ubound(x) = 3, "ubound(x) = " & ubound(x)

x(0) = 1
x(1) = 2
x(2) = 3
x(2) = 4

redim preserve x(1)
ok ubound(x) = 1, "ubound(x) = " & ubound(x)
ok x(0) = 1, "x(0) = " & x(1)
ok x(1) = 2, "x(1) = " & x(1)

redim preserve x(2)
ok ubound(x) = 2, "ubound(x) = " & ubound(x)
ok x(0) = 1, "x(0) = " & x(0)
ok x(1) = 2, "x(1) = " & x(1)
ok x(2) = vbEmpty, "x(2) = " & x(2)

on error resume next
redim preserve x(2,2)
e = err.number
on error goto 0
ok e = 9, "e = " & e ' VBSE_OUT_OF_BOUNDS, cannot change cDims

x = Array(1, 2)
redim x(-1)
ok lbound(x) = 0, "lbound(x) = " & lbound(x)
ok ubound(x) = -1, "ubound(x) = " & ubound(x)

redim x(3, 2)
ok ubound(x) = 3, "ubound(x) = " & ubound(x)
ok ubound(x, 1) = 3, "ubound(x, 1) = " & ubound(x, 1)
ok ubound(x, 2) = 2, "ubound(x, 2) = " & ubound(x, 2) & " expected 2"

redim x(1, 3)
x(0,0) = 1.1
x(0,1) = 1.2
x(0,2) = 1.3
x(0,3) = 1.4
x(1,0) = 2.1
x(1,1) = 2.2
x(1,2) = 2.3
x(1,3) = 2.4

redim preserve x(1,1)
ok ubound(x, 1) = 1, "ubound(x, 1) = " & ubound(x, 1)
ok ubound(x, 2) = 1, "ubound(x, 2) = " & ubound(x, 2)
ok x(0,0) = 1.1, "x(0,0) = " & x(0,0)
ok x(0,1) = 1.2, "x(0,1) = " & x(0,1)
ok x(1,0) = 2.1, "x(1,0) = " & x(1,0)
ok x(1,1) = 2.2, "x(1,1) = " & x(1,1)

redim preserve x(1,2)
ok ubound(x, 1) = 1, "ubound(x, 1) = " & ubound(x, 1)
ok ubound(x, 2) = 2, "ubound(x, 2) = " & ubound(x, 2)
ok x(0,0) = 1.1, "x(0,0) = " & x(0,0)
ok x(0,1) = 1.2, "x(0,1) = " & x(0,1)
ok x(1,0) = 2.1, "x(1,0) = " & x(1,0)
ok x(1,1) = 2.2, "x(1,1) = " & x(1,1)
ok x(0,2) = vbEmpty, "x(0,2) = " & x(0,2)
ok x(1,2) = vbEmpty, "x(1,2) = " & x(1,1)

on error resume next
redim preserve x(2,2)
e = err.number
on error goto 0
ok e = 9, "e = " & e ' VBSE_OUT_OF_BOUNDS, can only change rightmost dimension

sub TestReDimFixed
    on error resume next

    dim staticarray(4)
    err.clear
    redim staticarray(3)
    call ok(err.number = 10, "err.number = " & err.number)
    call ok(isArrayFixed(staticarray), "Expected fixed size array")

    err.clear
    redim staticarray("abc")
    call ok(err.number = 10, "err.number = " & err.number)

    dim staticarray2(4)
    err.clear
    redim preserve staticarray2(5)
    call ok(err.number = 10, "err.number = " & err.number)
    call ok(isArrayFixed(staticarray2), "Expected fixed size array")

    err.clear
    redim preserve staticarray2("abc")
    ' Win10+ builds return INVALID_CALL (5)
    call ok(err.number = 5 or err.number = 13, "err.number = " & err.number)
end sub
Call TestRedimFixed

sub TestRedimInputArg
    on error resume next

    dim x

    x = Array(1)
    err.clear
    redim x("abc")
    call ok(err.number = 13, "err.number = " & err.number)

    err.clear
    redim preserve x("abc")
    ' Win10+ builds return INVALID_CALL (5)
    call ok(err.number = 5 or err.number = 13, "err.number = " & err.number)
end sub
Call TestRedimInputArg

sub TestReDimList
    dim x, y

    x = Array(1)
    y = Array(1)
    redim x(1, 3), y(2)
    ok ubound(x, 1) = 1, "ubound(x, 1) = " & ubound(x, 1)
    ok ubound(x, 2) = 3, "ubound(x, 2) = " & ubound(x, 2)
    ok ubound(y, 1) = 2, "ubound(y, 1) = " & ubound(y, 1)

    x(0,0) = 1.1
    x(0,1) = 1.2
    x(0,2) = 1.3
    x(0,3) = 1.4
    x(1,0) = 2.1
    x(1,1) = 2.2
    x(1,2) = 2.3
    x(1,3) = 2.4

    y(0) = 2.1
    y(1) = 2.2
    y(2) = 2.3

    redim preserve x(1,1), y(3)
    ok ubound(x, 1) = 1, "ubound(x, 1) = " & ubound(x, 1)
    ok ubound(x, 2) = 1, "ubound(x, 2) = " & ubound(x, 2)
    ok x(0,0) = 1.1, "x(0,0) = " & x(0,0)
    ok x(0,1) = 1.2, "x(0,1) = " & x(0,1)
    ok x(1,0) = 2.1, "x(1,0) = " & x(1,0)
    ok x(1,1) = 2.2, "x(1,1) = " & x(1,1)
    ok ubound(y, 1) = 3, "ubound(y, 1) = " & ubound(y, 1)
    ok y(0) = 2.1, "y(0) = " & y(0)
    ok y(1) = 2.2, "y(1) = " & y(1)
    ok y(2) = 2.3, "y(2) = " & y(2)
    ok y(3) = vbEmpty, "y(3) = " & y(3)
end sub
call TestReDimList

dim rx
redim rx(4)
sub TestReDimByRef(byref x)
   ok ubound(x) = 4, "ubound(x) = " & ubound(x)
   redim x(6)
   ok ubound(x) = 6, "ubound(x) = " & ubound(x)
end sub
call TestReDimByRef(rx)
ok ubound(rx) = 6, "ubound(rx) = " & ubound(rx)

redim rx(5)
rx(3)=2
sub TestReDimPreserveByRef(byref x)
   ok ubound(x) = 5, "ubound(x) = " & ubound(x)
   ok x(3) = 2, "x(3) = " & x(3)
   redim preserve x(7)
   ok ubound(x) = 7, "ubound(x) = " & ubound(x)
   ok x(3) = 2, "x(3) = " & x(3)
end sub
call TestReDimPreserveByRef(rx)
ok ubound(rx) = 7, "ubound(rx) = " & ubound(rx)
ok rx(3) = 2, "rx(3) = " & rx(3)

Class ArrClass
    Dim classarr(3)
    Dim classnoarr()
    Dim var

    Private Sub Class_Initialize
        Call ok(getVT(classarr) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(classarr) = " & getVT(classarr))
        Call testArray(-1, classnoarr)
        classarr(0) = 1
        classarr(1) = 2
        classarr(2) = 3
        classarr(3) = 4
    End Sub

    Public Sub testVarVT
        Call ok(getVT(var) = "VT_ARRAY|VT_VARIANT*", "getVT(var) = " & getVT(var))
    End Sub
End Class

Set obj = new ArrClass
Call ok(getVT(obj.classarr) = "VT_ARRAY|VT_VARIANT", "getVT(obj.classarr) = " & getVT(obj.classarr))
'todo_wine Call ok(obj.classarr(1) = 2, "obj.classarr(1) = " & obj.classarr(1))

obj.var = arr
Call ok(getVT(obj.var) = "VT_ARRAY|VT_VARIANT", "getVT(obj.var) = " & getVT(obj.var))
Call obj.testVarVT

Sub arrarg(byref refarr, byval valarr, byref refarr2, byval valarr2)
    Call ok(getVT(refarr) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(refarr) = " & getVT(refarr))
    Call ok(getVT(valarr) = "VT_ARRAY|VT_VARIANT*", "getVT(valarr) = " & getVT(valarr))
    Call ok(getVT(refarr2) = "VT_ARRAY|VT_VARIANT*", "getVT(refarr2) = " & getVT(refarr2))
    Call ok(getVT(valarr2) = "VT_ARRAY|VT_VARIANT*", "getVT(valarr2) = " & getVT(valarr2))
End Sub

Call arrarg(arr, arr, obj.classarr, obj.classarr)

Sub arrarg2(byref refarr(), byval valarr(), byref refarr2(), byval valarr2())
    Call ok(getVT(refarr) = "VT_ARRAY|VT_BYREF|VT_VARIANT*", "getVT(refarr) = " & getVT(refarr))
    Call ok(getVT(valarr) = "VT_ARRAY|VT_VARIANT*", "getVT(valarr) = " & getVT(valarr))
    Call ok(getVT(refarr2) = "VT_ARRAY|VT_VARIANT*", "getVT(refarr2) = " & getVT(refarr2))
    Call ok(getVT(valarr2) = "VT_ARRAY|VT_VARIANT*", "getVT(valarr2) = " & getVT(valarr2))
End Sub

Call arrarg2(arr, arr, obj.classarr, obj.classarr)

Sub testarrarg(arg(), vt)
    Call ok(getVT(arg) = vt, "getVT() = " & getVT(arg) & " expected " & vt)
End Sub

Call testarrarg(1, "VT_I2*")
Call testarrarg(false, "VT_BOOL*")
Call testarrarg(Empty, "VT_EMPTY*")

Sub modifyarr(arr)
    Call ok(arr(0) = "not modified", "arr(0) = " & arr(0))
    arr(0) = "modified"
End Sub

arr(0) = "not modified"
Call modifyarr(arr)
Call ok(arr(0) = "modified", "arr(0) = " & arr(0))

arr(0) = "not modified"
modifyarr(arr)
Call ok(arr(0) = "not modified", "arr(0) = " & arr(0))

for x = 0 to UBound(arr)
    arr(x) = x
next
y = 0
for each x in arr
    Call ok(x = y, "x = " & x & ", expected " & y)
    Call ok(arr(y) = y, "arr(" & y & ") = " & arr(y))
    arr(y) = 1
    x = 1
    y = y+1
next
Call ok(y = 4, "y = " & y & " after array enumeration")

for x=0 to UBound(arr2, 1)
    for y=0 to UBound(arr2, 2)
        arr2(x, y) = x + y*(UBound(arr2, 1)+1)
    next
next
y = 0
for each x in arr2
    Call ok(x = y, "x = " & x & ", expected " & y)
    y = y+1
next
Call ok(y = 20, "y = " & y & " after array enumeration")

for each x in noarr
    Call ok(false, "Empty array contains: " & x)
next

' It's allowed to declare non-builtin RegExp class...
class RegExp
     public property get Global()
         Call ok(false, "Global called")
         Global = "fail"
     end property
end class

' ...but there is no way to use it because builtin instance is always created
set x = new RegExp
Call ok(x.Global = false, "x.Global = " & x.Global)

sub test_nothing_errors
    dim x
    on error resume next

    x = 1
    err.clear
    x = nothing
    call ok(err.number = 91, "err.number = " & err.number)
    call ok(x = 1, "x = " & x)

    err.clear
    x = not nothing
    call ok(err.number = 91, "err.number = " & err.number)
    call ok(x = 1, "x = " & x)

    err.clear
    x = "" & nothing
    call ok(err.number = 91, "err.number = " & err.number)
    call ok(x = 1, "x = " & x)
end sub
call test_nothing_errors()

sub test_identifiers
    ' test keywords that can also be a declared identifier
    Dim default
    default = "xx"
    Call ok(default = "xx", "default = " & default & " expected ""xx""")

    Dim error
    error = "xx"
    Call ok(error = "xx", "error = " & error & " expected ""xx""")

    Dim explicit
    explicit = "xx"
    Call ok(explicit = "xx", "explicit = " & explicit & " expected ""xx""")

    Dim step
    step = "xx"
    Call ok(step = "xx", "step = " & step & " expected ""xx""")

    Dim property
    property = "xx"
    Call ok(property = "xx", "property = " & property & " expected ""xx""")
end sub
call test_identifiers()

Class class_test_identifiers_as_function_name
    Sub Property ( par )
    End Sub

    Function Error( par )
    End Function

    Sub Default ()
    End Sub

    Function Explicit (par)
        Explicit = par
    End Function

    Sub Step ( default )
    End Sub
End Class

Class class_test_identifiers_as_property_name
    Public Property Get Property()
    End Property

    Public Property Let Error(par)
        Error = par
    End Property

    Public Property Set Default(par)
        Set Default = par
    End Property
End Class

sub test_dotIdentifiers
    ' test keywords that can also be an identifier after a dot
    Call ok(testObj.rem = 10, "testObj.rem = " & testObj.rem & " expected 10")
    Call ok(testObj.true = 10, "testObj.true = " & testObj.true & " expected 10")
    Call ok(testObj.false = 10, "testObj.false = " & testObj.false & " expected 10")
    Call ok(testObj.not = 10, "testObj.not = " & testObj.not & " expected 10")
    Call ok(testObj.and = 10, "testObj.and = " & testObj.and & " expected 10")
    Call ok(testObj.or = 10, "testObj.or = " & testObj.or & " expected 10")
    Call ok(testObj.xor = 10, "testObj.xor = " & testObj.xor & " expected 10")
    Call ok(testObj.eqv = 10, "testObj.eqv = " & testObj.eqv & " expected 10")
    Call ok(testObj.imp = 10, "testObj.imp = " & testObj.imp & " expected 10")
    Call ok(testObj.is = 10, "testObj.is = " & testObj.is & " expected 10")
    Call ok(testObj.mod = 10, "testObj.mod = " & testObj.mod & " expected 10")
    Call ok(testObj.call = 10, "testObj.call = " & testObj.call & " expected 10")
    Call ok(testObj.dim = 10, "testObj.dim = " & testObj.dim & " expected 10")
    Call ok(testObj.sub = 10, "testObj.sub = " & testObj.sub & " expected 10")
    Call ok(testObj.function = 10, "testObj.function = " & testObj.function & " expected 10")
    Call ok(testObj.get = 10, "testObj.get = " & testObj.get & " expected 10")
    Call ok(testObj.let = 10, "testObj.let = " & testObj.let & " expected 10")
    Call ok(testObj.const = 10, "testObj.const = " & testObj.const & " expected 10")
    Call ok(testObj.if = 10, "testObj.if = " & testObj.if & " expected 10")
    Call ok(testObj.else = 10, "testObj.else = " & testObj.else & " expected 10")
    Call ok(testObj.elseif = 10, "testObj.elseif = " & testObj.elseif & " expected 10")
    Call ok(testObj.end = 10, "testObj.end = " & testObj.end & " expected 10")
    Call ok(testObj.then = 10, "testObj.then = " & testObj.then & " expected 10")
    Call ok(testObj.exit = 10, "testObj.exit = " & testObj.exit & " expected 10")
    Call ok(testObj.while = 10, "testObj.while = " & testObj.while & " expected 10")
    Call ok(testObj.wend = 10, "testObj.wend = " & testObj.wend & " expected 10")
    Call ok(testObj.do = 10, "testObj.do = " & testObj.do & " expected 10")
    Call ok(testObj.loop = 10, "testObj.loop = " & testObj.loop & " expected 10")
    Call ok(testObj.until = 10, "testObj.until = " & testObj.until & " expected 10")
    Call ok(testObj.for = 10, "testObj.for = " & testObj.for & " expected 10")
    Call ok(testObj.to = 10, "testObj.to = " & testObj.to & " expected 10")
    Call ok(testObj.each = 10, "testObj.each = " & testObj.each & " expected 10")
    Call ok(testObj.in = 10, "testObj.in = " & testObj.in & " expected 10")
    Call ok(testObj.select = 10, "testObj.select = " & testObj.select & " expected 10")
    Call ok(testObj.case = 10, "testObj.case = " & testObj.case & " expected 10")
    Call ok(testObj.byref = 10, "testObj.byref = " & testObj.byref & " expected 10")
    Call ok(testObj.byval = 10, "testObj.byval = " & testObj.byval & " expected 10")
    Call ok(testObj.option = 10, "testObj.option = " & testObj.option & " expected 10")
    Call ok(testObj.nothing = 10, "testObj.nothing = " & testObj.nothing & " expected 10")
    Call ok(testObj.empty = 10, "testObj.empty = " & testObj.empty & " expected 10")
    Call ok(testObj.null = 10, "testObj.null = " & testObj.null & " expected 10")
    Call ok(testObj.class = 10, "testObj.class = " & testObj.class & " expected 10")
    Call ok(testObj.set = 10, "testObj.set = " & testObj.set & " expected 10")
    Call ok(testObj.new = 10, "testObj.new = " & testObj.new & " expected 10")
    Call ok(testObj.public = 10, "testObj.public = " & testObj.public & " expected 10")
    Call ok(testObj.private = 10, "testObj.private = " & testObj.private & " expected 10")
    Call ok(testObj.next = 10, "testObj.next = " & testObj.next & " expected 10")
    Call ok(testObj.on = 10, "testObj.on = " & testObj.on & " expected 10")
    Call ok(testObj.resume = 10, "testObj.resume = " & testObj.resume & " expected 10")
    Call ok(testObj.goto = 10, "testObj.goto = " & testObj.goto & " expected 10")
    Call ok(testObj.with = 10, "testObj.with = " & testObj.with & " expected 10")
    Call ok(testObj.redim = 10, "testObj.redim = " & testObj.redim & " expected 10")
    Call ok(testObj.preserve = 10, "testObj.preserve = " & testObj.preserve & " expected 10")
    Call ok(testObj.property = 10, "testObj.property = " & testObj.property & " expected 10")
    Call ok(testObj.me = 10, "testObj.me = " & testObj.me & " expected 10")
    Call ok(testObj.stop = 10, "testObj.stop = " & testObj.stop & " expected 10")
end sub
call test_dotIdentifiers

' Test End statements not required to be preceded by a newline or separator
Sub EndTestSub
    x = 1 End Sub

Sub EndTestSubWithCall
    x = 1
    Call ok(x = 1, "x = " & x)End Sub
Call EndTestSubWithCall()

Function EndTestFunc(x)
    Call ok(x > 0, "x = " & x)End Function
EndTestFunc(1)

Class EndTestClassWithStorageId
    Public x End Class

Class EndTestClassWithDim
    Dim x End Class

Class EndTestClassWithFunc
    Function test(ByVal x)
        x = 0 End Function End Class

Class EndTestClassWithProperty
    Public x
    Public default Property Get defprop
        defprop = x End Property End Class

class TestPropSyntax
    public prop

    function getProp()
        set getProp = prop
    end function

    public default property get def()
        def = ""
    end property
end class

Class TestPropParam
    Public oDict
    Public gotNothing
    Public m_obj

    Public Property Set bar(obj)
        Set m_obj = obj
    End Property
    Public Property Set foo(par,obj)
        Set m_obj = obj
        if obj is Nothing Then gotNothing = True
        oDict = par
    End Property
    Public Property Let Key(oldKey,newKey)
        oDict = oldKey & newKey
    End Property
    Public Property Let three(uno,due,tre)
        oDict = uno & due & tre
    End Property
    Public Property Let ten(a,b,c,d,e,f,g,h,i,j)
        oDict = a & b & c & d & e & f & g & h & i & j
    End Property
End Class

Set x = new TestPropParam
x.key("old") = "new"
call ok(x.oDict = "oldnew","x.oDict = " & x.oDict & " expected oldnew")
x.three(1,2) = 3
call ok(x.oDict = "123","x.oDict = " & x.oDict & " expected 123")
x.ten(1,2,3,4,5,6,7,8,9) = 0
call ok(x.oDict = "1234567890","x.oDict = " & x.oDict & " expected 1234567890")
Set x.bar = Nothing
call ok(x.gotNothing=Empty,"x.gotNothing = " & x.gotNothing  & " expected Empty")
Set x.foo("123") = Nothing
call ok(x.oDict = "123","x.oDict = " & x.oDict & " expected 123")
call ok(x.gotNothing=True,"x.gotNothing = " & x.gotNothing  & " expected true")

set x = new TestPropSyntax
set x.prop = new TestPropSyntax
set x.prop.prop = new TestPropSyntax
x.prop.prop.prop = 2
call ok(x.getProp().getProp.prop = 2, "x.getProp().getProp.prop = " & x.getProp().getProp.prop)
x.getprop.getprop().prop = 3
call ok(x.getProp.prop.prop = 3, "x.getProp.prop.prop = " & x.getProp.prop.prop)
set x.getprop.getprop().prop = new emptyclass
set obj = new emptyclass
set x.getprop.getprop().prop = obj
call ok(x.getprop.getprop().prop is obj, "x.getprop.getprop().prop is not obj (emptyclass)")

ok getVT(x) = "VT_DISPATCH*", "getVT(x) = " & getVT(x)
todo_wine_ok getVT(x()) = "VT_BSTR", "getVT(x()) = " & getVT(x())

funcCalled = ""
class DefaultSubTest1
 Public  default Sub init(a)
    funcCalled = "init" & a
 end sub
end class

Set obj = New DefaultSubTest1
obj.init(1)
call ok(funcCalled = "init1","funcCalled=" & funcCalled)
funcCalled = ""
obj(2)
call ok(funcCalled = "init2","funcCalled=" & funcCalled)

class DefaultSubTest2
 Public Default Function init
    funcCalled = "init"
 end function
end class

Set obj = New DefaultSubTest2
funcCalled = ""
obj.init()
call ok(funcCalled = "init","funcCalled=" & funcCalled)
funcCalled = ""
' todo this is not yet supported
'funcCalled = ""
'obj()
'call ok(funcCalled = "init","funcCalled=" & funcCalled)

with nothing
end with

set x = new TestPropSyntax
with x
     .prop = 1
     ok .prop = 1, ".prop = "&.prop
end with
ok x.prop = 1, "x.prop = " & x.prop

with new TestPropSyntax
     .prop = 1
     ok .prop = 1, ".prop = "&.prop
end with

function testsetresult(x, y)
    set testsetresult = new TestPropSyntax
    testsetresult.prop = x
    y = testsetresult.prop + 1
end function

set x = testsetresult(1, 2)
ok x.prop = 1, "x.prop = " & x.prop

set arr(0) = new TestPropSyntax
arr(0).prop = 1
ok arr(0).prop = 1, "arr(0) = " & arr(0).prop

function recursingfunction(x)
    if (x) then exit function
    recursingfunction = 2
    dim y
    y = recursingfunction
    call ok(y = 2, "y = " & y)
    recursingfunction = 1
    call recursingfunction(True)
end function
call ok(recursingfunction(False) = 1, "unexpected return value " & recursingfunction(False))

x = false
function recursingfunction2
    if (x) then exit function
    recursingfunction2 = 2
    dim y
    y = recursingfunction2
    call ok(y = 2, "y = " & y)
    recursingfunction2 = 1
    x = true
    recursingfunction2()
end function
call ok(recursingfunction2() = 1, "unexpected return value " & recursingfunction2())

function f2(x,y)
end function

f2 1 = 1, 2

function f1(x)
    ok x = true, "x = " & x
end function

f1 1 = 1
f1 1 = (1)
f1 not 1 = 0

arr (0) = 2 xor -2

reportSuccess()
 +'  4   ��( R E G E X P . V B S         0           '
' Copyright 2013 Piotr Caban for CodeWeavers
'
' This library is free software; you can redistribute it and/or
' modify it under the terms of the GNU Lesser General Public
' License as published by the Free Software Foundation; either
' version 2.1 of the License, or (at your option) any later version.
'
' This library is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
' Lesser General Public License for more details.
'
' You should have received a copy of the GNU Lesser General Public
' License along with this library; if not, write to the Free Software
' Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
'

Option Explicit

Dim x, matches, match, submatch, r

Set x = CreateObject("vbscript.regexp")
Call ok(getVT(x.Pattern) = "VT_BSTR", "getVT(RegExp.Pattern) = " & getVT(x.Pattern))
Call ok(x.Pattern = "", "RegExp.Pattern = " & x.Pattern)
Call ok(getVT(x.IgnoreCase) = "VT_BOOL", "getVT(RegExp.IgnoreCase) = " & getVT(x.IgnoreCase))
Call ok(x.IgnoreCase = false, "RegExp.IgnoreCase = " & x.IgnoreCase)
Call ok(getVT(x.Global) = "VT_BOOL", "getVT(RegExp.Global) = " & getVT(x.Global))
Call ok(x.Global = false, "RegExp.Global = " & x.Global)
Call ok(getVT(x.Multiline) = "VT_BOOL", "getVT(RegExp.Multiline) = " & getVT(x.Multiline))
Call ok(x.Multiline = false, "RegExp.Multiline = " & x.Multiline)

x.Pattern = "a+"
matches = x.Test(" aabaaa")
Call ok(matches = true, "RegExp.Test returned: " & matches)
Set matches = x.Execute(" aabaaa")
Call ok(getVT(matches.Count) = "VT_I4", "getVT(matches.Count) = " & getVT(matches.Count))
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "aa", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 1, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Global = true
Set matches = x.Execute(" aabaaa")
Call ok(matches.Count = 2, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "aa", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 1, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)
Set match = matches.Item(1)
Call ok(match.Value = "aaa", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 4, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 3, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

Set matches = x.Execute(" aabaaa")
Call ok(matches.Count = 2, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "aa", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 1, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Pattern = "^[^<]*(<(.|\s)+>)[^>]*$|^#(\w+)$"
x.Global = false
Set matches = x.Execute("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
Call ok(matches.Count = 0, "matches.Count = " & matches.Count)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Pattern = "(a|b)+|(c)"
Set matches = x.Execute("aa")
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "aa", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 0, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 2, "submatch.Count = " & submatch.Count)
Call ok(getVT(submatch.Item(0)) = "VT_BSTR", "getVT(submatch.Item(0)) = " & getVT(submatch.Item(0)))
Call ok(submatch.Item(0) = "a", "submatch.Item(0) = " & submatch.Item(0))
Call ok(getVT(submatch.Item(1)) = "VT_EMPTY", "getVT(submatch.Item(1)) = " & getVT(submatch.Item(1)))
Call ok(submatch.Item(1) = "", "submatch.Item(0) = " & submatch.Item(1))

matches = x.Test("  a ")
Call ok(matches = true, "RegExp.Test returned: " & matches)
matches = x.Test("  a ")
Call ok(matches = true, "RegExp.Test returned: " & matches)

x.Pattern = "\[([^\[]+)\]"
x.Global = true
Set matches = x.Execute(" [test]  ")
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "[test]", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 1, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 6, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 1, "submatch.Count = " & submatch.Count)
Call ok(submatch.Item(0) = "test", "submatch.Item(0) = " & submatch.Item(0))

x.Pattern = "Ab"
x.IgnoreCase = true
Set matches = x.Execute("abcaBc")
Call ok(matches.Count = 2, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "ab", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 0, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)
Set match = matches.Item(1)
Call ok(match.Value = "aB", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 3, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Pattern = "a+b"
x.IgnoreCase = false
Set matches = x.Execute("aaabcabc")
Call ok(matches.Count = 2, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "aaab", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 0, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 4, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)
Set match = matches.Item(1)
Call ok(match.Value = "ab", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 5, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 2, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Pattern = "\\"
Set matches = x.Execute("aaa\\cabc")
Call ok(matches.Count = 2, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "\", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 3, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 1, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)
Set match = matches.Item(1)
Call ok(match.Value = "\", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 4, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 1, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 0, "submatch.Count = " & submatch.Count)

x.Pattern = "(a)(b)cabc"
Set matches = x.Execute("abcabc")
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
Set match = matches.Item(0)
Call ok(match.Value = "abcabc", "match.Value = " & match.Value)
Call ok(match.FirstIndex = 0, "match.FirstIndex = " & match.FirstIndex)
Call ok(match.Length = 6, "match.Length = " & match.Length)
Set submatch = match.SubMatches
Call ok(submatch.Count = 2, "submatch.Count = " & submatch.Count)
Call ok(submatch.Item(0) = "a", "submatch.Item(0) = " & submatch.Item(0))
Call ok(submatch.Item(1) = "b", "submatch.Item(0) = " & submatch.Item(1))

Set x = new regexp
Call ok(x.Pattern = "", "RegExp.Pattern = " & x.Pattern)
Call ok(x.IgnoreCase = false, "RegExp.IgnoreCase = " & x.IgnoreCase)
Call ok(x.Global = false, "RegExp.Global = " & x.Global)
Call ok(x.Multiline = false, "RegExp.Multiline = " & x.Multiline)

set matches = x.execute("test")
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
x.pattern = ""
set matches = x.execute("test")
Call ok(matches.Count = 1, "matches.Count = " & matches.Count)
set match = matches.item(0)
Call ok(match.Value = "", "match.Value = " & match.Value)
x.global = true
set matches = x.execute("test")
Call ok(matches.Count = 5, "matches.Count = " & matches.Count)
set match = matches.item(0)
Call ok(match.Value = "", "match.Value = " & match.Value)
set match = matches.item(4)
Call ok(match.Value = "", "match.Value = " & match.Value)
matches = x.test("test")
Call ok(matches = true, "matches = " & matches)

dim test_global

sub test_replace(pattern, string, rep, exp)
    dim x, re
    set re = new regexp
    re.pattern = pattern
    re.global = test_global
    x = re.replace(string, rep)
    call ok(x = exp, "replace returned " & x & " expected " & exp)
end sub

test_global = true
test_replace "xxx", "xxxx", "y", "yx"
test_replace "\[([^\[]+)\]", "- [test] -", "success", "- success -"
test_replace "\[([^\[]+)\]", "[test] [test]", "aa", "aa aa"
test_replace "(\&(\d))", "abc &1 123", "$'", "abc  123 123"
test_replace "(\&(\d))", "abc &1 123", "$`", "abc abc  123"
test_replace "(\&(\d))", "abc &1 123", "$3", "abc $3 123"
test_replace "\[([^\[]+)\]", "- [test] -", true, "- -1 -"
test_replace "\[([^\[]+)\]", "- [test] -", 6, "- 6 -"
test_replace "(\$(\d))", "$1,$2", "$$1-$1$2", "$1-$11,$1-$22"
test_replace "b", "abc", "x$&z", "axbzc"

test_global = false
test_replace "\[([^\[]+)\]", "[test] [test]", "aa", "aa [test]"

set r = new regexp
x = r.replace("xxx", "y")
call ok(x = "yxxx", "x = " & x)
r.global = true
x = r.replace("xxx", "y")
call ok(x = "yxyxyxy", "x = " & x)

Call reportSuccess()
 