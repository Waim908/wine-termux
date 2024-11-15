        ��  ��                  W� ,   ��( A P I . J S         0           /*
 * Copyright 2008 Jacek Caban for CodeWeavers
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

var JS_E_NUMBER_EXPECTED = 0x800a1389;
var JS_E_FUNCTION_EXPECTED = 0x800a138a;
var JS_E_DATE_EXPECTED = 0x800a138e;
var JS_E_OBJECT_EXPECTED = 0x800a138f;
var JS_E_BOOLEAN_EXPECTED = 0x800a1392;
var JS_E_VBARRAY_EXPECTED = 0x800a1395;
var JS_E_ENUMERATOR_EXPECTED = 0x800a1397;
var JS_E_REGEXP_EXPECTED = 0x800a1398;

var tmp, i;

var bigInt = Math.pow(2,40);

ok(ScriptEngine() === "JScript", "ScriptEngine() = " + ScriptEngine());
ok(ScriptEngine(3) === "JScript", "ScriptEngine(3) = " + ScriptEngine(3));
ok(ScriptEngineMajorVersion() === ScriptEngineMajorVersion(2), "ScriptEngineMajorVersion() !== ScriptEngineMajorVersion(2)");
ok(ScriptEngineMinorVersion() === ScriptEngineMinorVersion(2), "ScriptEngineMinorVersion() !== ScriptEngineMinorVersion(2)");
ok(ScriptEngineBuildVersion() === ScriptEngineBuildVersion(2), "ScriptEngineBuildVersion() !== ScriptEngineBuildVersion(2)");

function testNoEnumerables(expr) {
    for(var iter in obj)
        ok(false, expr + " has property " + iter);
}

testNoEnumerables("Object");
testNoEnumerables("Object.prototype");
testNoEnumerables("new Object()");
testNoEnumerables("Math");
testNoEnumerables("String");
testNoEnumerables("String.prototype");
testNoEnumerables("new String()");
testNoEnumerables("Number");
testNoEnumerables("Number.prototype");
testNoEnumerables("new Number(1)");
testNoEnumerables("ActiveXObject");
testNoEnumerables("Array");
testNoEnumerables("Array.prototype");
testNoEnumerables("new Array()");
testNoEnumerables("Boolean");
testNoEnumerables("Boolean.prototype");
testNoEnumerables("new Boolean()");
testNoEnumerables("Date");
testNoEnumerables("Date.prototype");
testNoEnumerables("new Date()");
testNoEnumerables("TypeError");
testNoEnumerables("TypeError.prototype");
testNoEnumerables("new TypeError()");
testNoEnumerables("Function");
testNoEnumerables("Function.prototype");
testNoEnumerables("testNoEnumerates");
testNoEnumerables("VBArray");
testNoEnumerables("new Enumerator()");
testNoEnumerables("Enumerator()");

ok(Object.propertyIsEnumerable("prototype") === false, "Object.prototype is enumerable");
ok(Math.propertyIsEnumerable("E") === false, "Math.E is enumerable");
ok(Math.propertyIsEnumerable("SQRT2") === false, "Math.SQRT2 is enumerable");
ok(Math.propertyIsEnumerable("PI") === false, "Math.PI is enumerable");
ok("test".propertyIsEnumerable("length") === false, "'test'.length is enumerable");
ok([1].propertyIsEnumerable("length") === false, "[1].length is enumerable");
ok((new TypeError()).propertyIsEnumerable("message") === true, "(new TypeError()).message is not enumerable");
ok((new TypeError()).propertyIsEnumerable("description") === false, "(new TypeError()).description is enumerable");
ok((new TypeError()).propertyIsEnumerable("name") === false, "(new TypeError()).name is enumerable");
ok((new TypeError()).propertyIsEnumerable("number") === false, "(new TypeError()).number is enumerable");
ok(Object.propertyIsEnumerable.propertyIsEnumerable("length") === false, "Object.propertyIsEnumerable.length is enumerable");

tmp = new Object();
tmp.test = "1";
ok(tmp.propertyIsEnumerable("test"), "tmp.test is not enumerable");

tmp = { test: 1 };
ok(tmp.propertyIsEnumerable("test"), "tmp.test is not enumerable");

ok([1].concat([2]).propertyIsEnumerable("1"), "[1].concat([2]).1 is not enumerable");
ok("t.e.s.t".split(".").propertyIsEnumerable("0"), "'test'.split().0 is not enumerable");

(function() {
    ok(arguments.propertyIsEnumerable("0") === false, "arguments.0 is enumerable");
    ok(arguments.propertyIsEnumerable("length") === false, "arguments.length is enumerable");
    ok(arguments.propertyIsEnumerable("calee") === false, "arguments.calee is enumerable");
})();

tmp = [1];
tmp.push("");
ok(tmp.propertyIsEnumerable("1"), "[1].push() ... 1 is not enumerable");

ok([1,2].reverse().propertyIsEnumerable("1"), "[1,2].rverse().1 is not enumerable");
ok([1,2].propertyIsEnumerable("0"), "[1,2].0 is not enumerable");

i = parseInt("0");
ok(i === 0, "parseInt('0') = " + i);
i = parseInt("123");
ok(i === 123, "parseInt('123') = " + i);
i = parseInt("-123");
ok(i === -123, "parseInt('-123') = " + i);
i = parseInt("0xff");
ok(i === 0xff, "parseInt('0xff') = " + i);
i = parseInt("11", 8);
ok(i === 9, "parseInt('11', 8) = " + i);
i = parseInt("1j", 22);
ok(i === 41, "parseInt('1j', 32) = " + i);
i = parseInt("123", 0);
ok(i === 123, "parseInt('123', 0) = " + i);
i = parseInt("123", 10, "test");
ok(i === 123, "parseInt('123', 10, 'test') = " + i);
i = parseInt("11", "8");
ok(i === 9, "parseInt('11', '8') = " + i);
i = parseInt("010");
ok(i === 8, "parseInt('010') = " + i);
i = parseInt("");
ok(isNaN(i), "parseInt('') = " + i);
i = parseInt("0x");
ok(isNaN(i), "parseInt('0x') = " + i);
i = parseInt("+");
ok(isNaN(i), "parseInt('+') = " + i);
i = parseInt("-");
ok(isNaN(i), "parseInt('-') = " + i);
i = parseInt("0x10", 11);
ok(i === 0, "parseInt('0x10', 11) = " + i);
i = parseInt("010", 7);
ok(i === 7, "parseInt('010', 7) = " + i);
i = parseInt("123abc");
ok(i === 123, "parseInt('123abc') = " + i);
i = parseInt("   \t123abc");
ok(i === 123, "parseInt('   \\t123abc') = " + i);
i = parseInt("abc");
ok(isNaN(i), "parseInt('123abc') = " + i);
i = parseInt("-12", 11);
ok(i === -13, "parseInt('-12') = " + i);
i = parseInt("-0x10");
ok(i === -16, "parseInt('-0x10') = " + i);
i = parseInt("-010");
ok(i === -8, "parseInt('-010') = " + i);
i = parseInt("123", 0);
ok(i === 123, "parseInt('123', 0) = " + i);
i = parseInt("0x10", 0);
ok(i === 16, "parseInt('123', 0) = " + i);
i = parseInt("0x10", 10);
ok(i === 0, "parseInt('0x10', 10) = " + i);
i = parseInt("0xz");
ok(isNaN(i), "parseInt('0xz') = " + i);
i = parseInt("1", 1);
ok(isNaN(i), "parseInt('1', 1) = " + i);
i = parseInt("1", -1);
ok(isNaN(i), "parseInt('1', -1) = " + i);
i = parseInt("1", 37);
ok(isNaN(i), "parseInt('1', 37) = " + i);
i = parseInt("1", 36);
ok(i === 1, "parseInt('1', 36) = " + i);
i = parseInt("0x1f", 16);
ok(i === 31, "parseInt('0xf', 16) = " + i);
i = parseInt("0x", 16);
ok(isNaN(i), "parseInt('0x', 16) = " + i);
i = parseInt("0x1f", 17);
ok(i === 0, "parseInt('0xf', 16) = " + i);

tmp = encodeURI("abc");
ok(tmp === "abc", "encodeURI('abc') = " + tmp);
tmp = encodeURI("{abc}");
ok(tmp === "%7Babc%7D", "encodeURI('{abc}') = " + tmp);
tmp = encodeURI("");
ok(tmp === "", "encodeURI('') = " + tmp);
tmp = encodeURI("\01\02\03\04");
ok(tmp === "%01%02%03%04", "encodeURI('\\01\\02\\03\\04') = " + tmp);
tmp = encodeURI("{#@}");
ok(tmp === "%7B#@%7D", "encodeURI('{#@}') = " + tmp);
tmp = encodeURI("\xa1 ");
ok(tmp === "%C2%A1%20", "encodeURI(\\xa1 ) = " + tmp);
tmp = encodeURI("\xffff");
ok(tmp.length === 8, "encodeURI('\\xffff').length = " + tmp.length);
tmp = encodeURI("abcABC123;/?:@&=+$,-_.!~*'()");
ok(tmp === "abcABC123;/?:@&=+$,-_.!~*'()", "encodeURI('abcABC123;/?:@&=+$,-_.!~*'()') = " + tmp);
tmp = encodeURI("%");
ok(tmp === "%25", "encodeURI('%') = " + tmp);
tmp = encodeURI();
ok(tmp === "undefined", "encodeURI() = " + tmp);
tmp = encodeURI("abc", "test");
ok(tmp === "abc", "encodeURI('abc') = " + tmp);

tmp = decodeURI("abc");
ok(tmp === "abc", "decodeURI('abc') = " + tmp);
tmp = decodeURI("{abc}");
ok(tmp === "{abc}", "decodeURI('{abc}') = " + tmp);
tmp = decodeURI("");
ok(tmp === "", "decodeURI('') = " + tmp);
tmp = decodeURI("\01\02\03\04");
ok(tmp === "\01\02\03\04", "decodeURI('\\01\\02\\03\\04') = " + tmp);
tmp = decodeURI();
ok(tmp === "undefined", "decodeURI() = " + tmp);
tmp = decodeURI("abc", "test");
ok(tmp === "abc", "decodeURI('abc') = " + tmp);
tmp = decodeURI("%7babc%7d");
ok(tmp === "{abc}", "decodeURI('%7Babc%7D') = " + tmp);
tmp = decodeURI("%01%02%03%04");
ok(tmp === "\01\02\03\04", "decodeURI('%01%02%03%04') = " + tmp);
tmp = decodeURI("%C2%A1%20");
ok(tmp === "\xa1 ", "decodeURI('%C2%A1%20') = " + tmp);
tmp = decodeURI("%C3%BFff");
ok(tmp.length === 3, "decodeURI('%C3%BFff').length = " + tmp.length);

tmp = encodeURIComponent("abc");
ok(tmp === "abc", "encodeURIComponent('abc') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "abc", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("{abc}");
ok(tmp === "%7Babc%7D", "encodeURIComponent('{abc}') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "{abc}", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("");
ok(tmp === "", "encodeURIComponent('') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("\01\02\03\04");
ok(tmp === "%01%02%03%04", "encodeURIComponent('\\01\\02\\03\\04') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "\01\02\03\04", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("{#@}");
ok(tmp === "%7B%23%40%7D", "encodeURIComponent('{#@}') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "{#@}", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("\xa1 ");
ok(tmp === "%C2%A1%20", "encodeURIComponent(\\xa1 ) = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "\xa1 ", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("\xffff");
ok(tmp.length === 8, "encodeURIComponent('\\xffff').length = " + tmp.length);
dec = decodeURIComponent(tmp);
ok(dec === "\xffff", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent("abcABC123;/?:@&=+$,-_.!~*'()");
ok(tmp === "abcABC123%3B%2F%3F%3A%40%26%3D%2B%24%2C-_.!~*'()", "encodeURIComponent('abcABC123;/?:@&=+$,-_.!~*'()') = " + tmp);
dec = decodeURIComponent(tmp);
ok(dec === "abcABC123;/?:@&=+$,-_.!~*'()", "decodeURIComponent('" + tmp + "') = " + dec);
tmp = encodeURIComponent();
ok(tmp === "undefined", "encodeURIComponent() = " + tmp);
tmp = encodeURIComponent("abc", "test");
ok(tmp === "abc", "encodeURIComponent('abc') = " + tmp);
dec = decodeURIComponent();
ok(dec === "undefined", "decodeURIComponent() = " + dec);
dec = decodeURIComponent("abc", "test");
ok(dec === "abc", "decodeURIComponent('abc') = " + dec);

tmp = escape("abc");
ok(tmp === "abc", "escape('abc') = " + tmp);
tmp = escape("");
ok(tmp === "", "escape('') = " + tmp);
tmp = escape("a1b c!d+e@*-_+./,");
ok(tmp === "a1b%20c%21d+e@*-_+./%2C", "escape('a1b c!d+e@*-_+./,') = " + tmp);
tmp = escape();
ok(tmp === "undefined", "escape() = " + tmp);
tmp = escape('\u1234\123\xf3');
ok(tmp == "%u1234S%F3", "escape('\u1234\123\xf3') = " + tmp);

tmp = unescape("abc");
ok(tmp === "abc", "unescape('abc') = " + tmp);
tmp = unescape("");
ok(tmp === "", "unescape('') = " + tmp);
tmp = unescape("%%%");
ok(tmp === "%%%", "unescape('%%%') = " + tmp);
tmp = unescape();
ok(tmp === "undefined", "unescape() = " + tmp);
tmp = unescape("%54%65s%u0074");
ok(tmp === "Test", "unescape('%54%65s%u0074') = " + tmp);

tmp = "aA1~`!@#$%^&*()_+=-][{}';:/.,<>?\|";
ok(escape(tmp) === "aA1%7E%60%21@%23%24%25%5E%26*%28%29_+%3D-%5D%5B%7B%7D%27%3B%3A/.%2C%3C%3E%3F%7C", "escape('" + tmp + "') = " + escape(tmp));
ok(unescape(escape(tmp)) === tmp, "unescape(escape('" + tmp + "')) = " + unescape(escape(tmp)));

ok(Object.prototype.hasOwnProperty('toString'), "Object.prototype.hasOwnProperty('toString') is false");
ok(Object.prototype.hasOwnProperty('isPrototypeOf'), "Object.prototype.hasOwnProperty('isPrototypeOf') is false");
ok(Function.prototype.hasOwnProperty('call'), "Function.prototype.hasOwnProperty('call') is false");
ok(!Function.prototype.hasOwnProperty('caller'), "Function.prototype.hasOwnProperty('caller') is true");
ok(!Function.prototype.hasOwnProperty('arguments'), "Function.prototype.hasOwnProperty('arguments') is true");

Object();
new Object();
obj = new Object();

ok(!obj.hasOwnProperty('toString'), "obj.hasOwnProperty('toString') is true");
ok(!obj.hasOwnProperty('isPrototypeOf'), "obj.hasOwnProperty('isPrototypeOf') is true");
ok(!Object.hasOwnProperty('toString'), "Object.hasOwnProperty('toString') is true");
ok(!Object.hasOwnProperty('isPrototypeOf'), "Object.hasOwnProperty('isPrototypeOf') is true");
ok(!parseFloat.hasOwnProperty('call'), "parseFloat.hasOwnProperty('call') is true");
ok(!Function.hasOwnProperty('call'), "Function.hasOwnProperty('call') is true");

Array();
new Array();
obj = new Array();
ok(Array.prototype.hasOwnProperty('sort'), "Array.prototype.hasOwnProperty('sort') is false");
ok(Array.prototype.hasOwnProperty('length'), "Array.prototype.hasOwnProperty('length') is false");
ok(!obj.hasOwnProperty('sort'), "obj.hasOwnProperty('sort') is true");
ok(obj.hasOwnProperty('length'), "obj.hasOwnProperty('length') is true");

Boolean();
new Boolean();
obj = new Boolean(false);
ok(!obj.hasOwnProperty('toString'), "obj.hasOwnProperty('toString') is true");
ok(!Boolean.hasOwnProperty('toString'), "Boolean.hasOwnProperty('toString') is true");
ok(Boolean.prototype.hasOwnProperty('toString'), "Boolean.prototype.hasOwnProperty('toString') is false");

Date();
new Date();
obj = new Date();
ok(!obj.hasOwnProperty('getTime'), "obj.hasOwnProperty('getTime') is true");
ok(!Date.hasOwnProperty('getTime'), "Date.hasOwnProperty('getTime') is true");
ok(Date.prototype.hasOwnProperty('getTime'), "Date.prototype.hasOwnProperty('getTime') is false");
ok(!("now" in Date), "now found in Date");

Number();
new Number();
obj = new Number();
ok(!obj.hasOwnProperty('toFixed'), "obj.hasOwnProperty('toFixed') is true");
ok(!Number.hasOwnProperty('toFixed'), "Number.hasOwnProperty('toFixed') is true");
ok(Number.prototype.hasOwnProperty('toFixed'), "Number.prototype.hasOwnProperty('toFixed') is false");

/x/;
obj = /x/;
ok(!obj.hasOwnProperty('exec'), "obj.hasOwnProperty('exec') is true");
ok(obj.hasOwnProperty('source'), "obj.hasOwnProperty('source') is false");
ok(!RegExp.hasOwnProperty('exec'), "RegExp.hasOwnProperty('exec') is true");
ok(!RegExp.hasOwnProperty('source'), "RegExp.hasOwnProperty('source') is true");
ok(RegExp.prototype.hasOwnProperty('source'), "RegExp.prototype.hasOwnProperty('source') is false");
ok(RegExp.prototype.source === "", "RegExp.prototype.source = " + RegExp.prototype.source);
ok(RegExp.prototype.lastIndex === 0, "RegExp.prototype.lastIndex = " + RegExp.prototype.lastIndex);

String();
new String();
obj = new String();
ok(!obj.hasOwnProperty('charAt'), "obj.hasOwnProperty('charAt') is true");
ok(obj.hasOwnProperty('length'), "obj.hasOwnProperty('length') is false");
ok(!String.hasOwnProperty('charAt'), "String.hasOwnProperty('charAt') is true");
ok(String.prototype.hasOwnProperty('charAt'), "String.prototype.hasOwnProperty('charAt') is false");
ok(String.prototype.hasOwnProperty('length'), "String.prototype.hasOwnProperty('length') is false");

tmp = "" + new Object();
ok(tmp === "[object Object]", "'' + new Object() = " + tmp);
(tmp = new Array).f = Object.prototype.toString;
ok(tmp.f() === "[object Array]", "tmp.f() = " + tmp.f());
(tmp = new Boolean).f = Object.prototype.toString;
ok(tmp.f() === "[object Boolean]", "tmp.f() = " + tmp.f());
(tmp = new Date).f = Object.prototype.toString;
ok(tmp.f() === "[object Date]", "tmp.f() = " + tmp.f());
(tmp = function() {}).f = Object.prototype.toString;
ok(tmp.f() === "[object Function]", "tmp.f() = " + tmp.f());
Math.f = Object.prototype.toString;
ok(Math.f() === "[object Math]", "tmp.f() = " + tmp.f());
(tmp = new Number).f = Object.prototype.toString;
ok(tmp.f() === "[object Number]", "tmp.f() = " + tmp.f());
(tmp = new RegExp("")).f = Object.prototype.toString;
ok(tmp.f() === "[object RegExp]", "tmp.f() = " + tmp.f());
(tmp = new String).f = Object.prototype.toString;
ok(tmp.f() === "[object String]", "tmp.f() = " + tmp.f());
tmp = Object.prototype.toString.call(testObj);
ok(tmp === "[object Object]", "toString.call(testObj) = " + tmp);
tmp = Object.prototype.toString.call(this);
ok(tmp === "[object Object]", "toString.call(this) = " + tmp);
(function () { tmp = Object.prototype.toString.call(arguments); })();
ok(tmp === "[object Object]", "toString.call(arguments) = " + tmp);
tmp = Object.prototype.toString.call(new VBArray(createArray()));
ok(tmp === "[object Object]", "toString.call(new VBArray()) = " + tmp);
(tmp = new Enumerator()).f = Object.prototype.toString;
ok(tmp.f() === "[object Object]", "tmp.f() = " + tmp.f());
tmp = Object.prototype.toString.call(null);
ok(tmp === "[object Object]", "toString.call(null) = " + tmp);
tmp = Object.prototype.toString.call(undefined);
ok(tmp === "[object Object]", "toString.call(undefined) = " + tmp);
tmp = Object.prototype.toString.call();
ok(tmp === "[object Object]", "toString.call() = " + tmp);

function TSTestConstr() {}
TSTestConstr.prototype = { toString: function() { return "test"; } };
obj = new TSTestConstr();
ok(obj.toString() === "test", "obj.toString() = " + obj.toString());

ok(Object(1) instanceof Number, "Object(1) is not instance of Number");
ok(Object("") instanceof String, "Object('') is not instance of String");
ok(Object(false) instanceof Boolean, "Object(false) is not instance of Boolean");

ok(new Object(1) instanceof Number, "Object(1) is not instance of Number");
ok(new Object("") instanceof String, "Object('') is not instance of String");
ok(new Object(false) instanceof Boolean, "Object(false) is not instance of Boolean");

obj = new Object();
ok(Object(obj) === obj, "Object(obj) !== obj");

ok(typeof(Object()) === "object", "typeof(Object()) !== 'object'");
ok(typeof(Object(undefined)) === "object", "typeof(Object(undefined)) !== 'object'");
ok(typeof(Object(null)) === "object", "typeof(Object(null)) !== 'object'");
ok(typeof(Object(nullDisp)) === "object", "typeof(Object(nullDisp)) !== 'object'");

ok(Object(nullDisp) != nullDisp, "Object(nullDisp) == nullDisp");
ok(new Object(nullDisp) != nullDisp, "new Object(nullDisp) == nullDisp");

ok(Object(testObj) === testObj, "Object(testObj) != testObj\n");
ok(new Object(testObj) === testObj, "new Object(testObj) != testObj\n");

tmp = new Object();
ok(Object(tmp) === tmp, "Object(tmp) != tmp");
ok(new Object(tmp) === tmp, "new Object(tmp) != tmp");

var obj = new Object();
obj.toString = function (x) {
    ok(arguments.length === 0, "arguments.length = " + arguments.length);
    return "test";
};
ok((tmp = obj.toLocaleString()) === "test", "obj.toLocaleString() = " + tmp);
ok((tmp = obj.toLocaleString(1)) === "test", "obj.toLocaleString(1) = " + tmp);
ok(obj === obj.valueOf(), "obj !== obj.valueOf");

ok("".length === 0, "\"\".length = " + "".length);
ok(getVT("".length) == "VT_I4", "\"\".length = " + "".length);
ok("abc".length === 3, "\"abc\".length = " + "abc".length);
ok(String.prototype.length === 0, "String.prototype.length = " + String.prototype.length);

tmp = "".toString();
ok(tmp === "", "''.toString() = " + tmp);
tmp = "test".toString();
ok(tmp === "test", "''.toString() = " + tmp);
tmp = "test".toString(3);
ok(tmp === "test", "''.toString(3) = " + tmp);

tmp = "".valueOf();
ok(tmp === "", "''.valueOf() = " + tmp);
tmp = "test".valueOf();
ok(tmp === "test", "''.valueOf() = " + tmp);
tmp = "test".valueOf(3);
ok(tmp === "test", "''.valueOf(3) = " + tmp);

var str = new String("test");
ok(str.toString() === "test", "str.toString() = " + str.toString());
var str = new String();
ok(str.toString() === "", "str.toString() = " + str.toString());
var str = new String("test", "abc");
ok(str.toString() === "test", "str.toString() = " + str.toString());

str = new String("test");
ok(str.length === 4, "str.length = " + str.length);
str.length = 3;
str.length = 5;
ok(str.length === 4, "str.length = " + str.length);

var strObj = new Object();
strObj.toString = function() { return "abcd" };
strObj.substr = String.prototype.substr;
strObj.lastIndexOf = String.prototype.lastIndexOf;

tmp = "value " + str;
ok(tmp === "value test", "'value ' + str = " + tmp);

tmp = String();
ok(tmp === "", "String() = " + tmp);
tmp = String(false);
ok(tmp === "false", "String(false) = " + tmp);
tmp = String(null);
ok(tmp === "null", "String(null) = " + tmp);
tmp = String("test");
ok(tmp === "test", "String('test') = " + tmp);
tmp = String("test", "abc");
ok(tmp === "test", "String('test','abc') = " + tmp);

tmp = "abc".charAt(0);
ok(tmp === "a", "'abc',charAt(0) = " + tmp);
tmp = "abc".charAt(1);
ok(tmp === "b", "'abc',charAt(1) = " + tmp);
tmp = "abc".charAt(2);
ok(tmp === "c", "'abc',charAt(2) = " + tmp);
tmp = "abc".charAt(3);
ok(tmp === "", "'abc',charAt(3) = " + tmp);
tmp = "abc".charAt(4);
ok(tmp === "", "'abc',charAt(4) = " + tmp);
tmp = "abc".charAt();
ok(tmp === "a", "'abc',charAt() = " + tmp);
tmp = "abc".charAt(-1);
ok(tmp === "", "'abc',charAt(-1) = " + tmp);
tmp = "abc".charAt(0,2);
ok(tmp === "a", "'abc',charAt(0.2) = " + tmp);
tmp = "abc".charAt(NaN);
ok(tmp === "a", "'abc',charAt(NaN) = " + tmp);
tmp = "abc".charAt(bigInt);
ok(tmp === "", "'abc',charAt(bigInt) = " + tmp);

tmp = "abc".charCodeAt(0);
ok(tmp === 0x61, "'abc'.charCodeAt(0) = " + tmp);
tmp = "abc".charCodeAt(1);
ok(tmp === 0x62, "'abc'.charCodeAt(1) = " + tmp);
tmp = "abc".charCodeAt(2);
ok(tmp === 0x63, "'abc'.charCodeAt(2) = " + tmp);
tmp = "abc".charCodeAt();
ok(tmp === 0x61, "'abc'.charCodeAt() = " + tmp);
tmp = "abc".charCodeAt(true);
ok(tmp === 0x62, "'abc'.charCodeAt(true) = " + tmp);
tmp = "abc".charCodeAt(0,2);
ok(tmp === 0x61, "'abc'.charCodeAt(0,2) = " + tmp);
tmp = "\u49F4".charCodeAt(0);
ok(tmp === 0x49F4, "'\u49F4'.charCodeAt(0) = " + tmp);
tmp = "\052".charCodeAt(0);
ok(tmp === 0x2A, "'\052'.charCodeAt(0) = " + tmp);
tmp = "\xa2".charCodeAt(0);
ok(tmp === 0xA2, "'\xa2'.charCodeAt(0) = " + tmp);
tmp = "abc".charCodeAt(bigInt);
ok(isNaN(tmp), "'abc'.charCodeAt(bigInt) = " + tmp);

tmp = "abcd".substring(1,3);
ok(tmp === "bc", "'abcd'.substring(1,3) = " + tmp);
tmp = "abcd".substring(-1,3);
ok(tmp === "abc", "'abcd'.substring(-1,3) = " + tmp);
tmp = "abcd".substring(1,6);
ok(tmp === "bcd", "'abcd'.substring(1,6) = " + tmp);
tmp = "abcd".substring(3,1);
ok(tmp === "bc", "'abcd'.substring(3,1) = " + tmp);
tmp = "abcd".substring(2,2);
ok(tmp === "", "'abcd'.substring(2,2) = " + tmp);
tmp = "abcd".substring(true,"3");
ok(tmp === "bc", "'abcd'.substring(true,'3') = " + tmp);
tmp = "abcd".substring(1,3,2);
ok(tmp === "bc", "'abcd'.substring(1,3,2) = " + tmp);
tmp = "abcd".substring();
ok(tmp === "abcd", "'abcd'.substring() = " + tmp);

tmp = "abcd".substr(1,3);
ok(tmp === "bcd", "'abcd'.substr(1,3) = " + tmp);
tmp = "abcd".substr(-1,3);
ok(tmp === "abc", "'abcd'.substr(-1,3) = " + tmp);
tmp = "abcd".substr(1,6);
ok(tmp === "bcd", "'abcd'.substr(1,6) = " + tmp);
tmp = "abcd".substr(2,-1);
ok(tmp === "", "'abcd'.substr(3,1) = " + tmp);
tmp = "abcd".substr(2,0);
ok(tmp === "", "'abcd'.substr(2,2) = " + tmp);
tmp = "abcd".substr(true,"3");
ok(tmp === "bcd", "'abcd'.substr(true,'3') = " + tmp);
tmp = "abcd".substr(1,3,2);
ok(tmp === "bcd", "'abcd'.substr(1,3,2) = " + tmp);
tmp = "abcd".substr();
ok(tmp === "abcd", "'abcd'.substr() = " + tmp);
tmp = strObj.substr(1,1);
ok(tmp === "b", "'abcd'.substr(1,3) = " + tmp);

tmp = "abcd".slice(1,3);
ok(tmp === "bc", "'abcd'.slice(1,3) = " + tmp);
tmp = "abcd".slice(1,-1);
ok(tmp === "bc", "'abcd'.slice(1,-1) = " + tmp);
tmp = "abcd".slice(-3,3);
ok(tmp === "bc", "'abcd'.slice(-3,3) = " + tmp);
tmp = "abcd".slice(-6,3);
ok(tmp === "abc", "'abcd'.slice(-6,3) = " + tmp);
tmp = "abcd".slice(3,1);
ok(tmp === "", "'abcd'.slice(3,1) = " + tmp);
tmp = "abcd".slice(true,3);
ok(tmp === "bc", "'abcd'.slice(true,3) = " + tmp);
tmp = "abcd".slice();
ok(tmp === "abcd", "'abcd'.slice() = " + tmp);
tmp = "abcd".slice(1);
ok(tmp === "bcd", "'abcd'.slice(1) = " + tmp);

tmp = "abc".concat(["d",1],2,false);
ok(tmp === "abcd,12false", "concat returned " + tmp);
var arr = new Array(2,"a");
arr.concat = String.prototype.concat;
tmp = arr.concat("d");
ok(tmp === "2,ad", "arr.concat = " + tmp);

m = "a+bcabc".match("a+");
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 1, "m.length is not 1");
ok(m["0"] === "a", "m[0] is not \"a\"");

r = "- [test] -".replace("[test]", "success");
ok(r === "- success -", "r = " + r + " expected '- success -'");

r = "- [test] -".replace("[test]", "success", "test");
ok(r === "- success -", "r = " + r + " expected '- success -'");

r = "test".replace();
ok(r === "test", "r = " + r + " expected 'test'");

function replaceFunc3(m, off, str) {
    ok(arguments.length === 3, "arguments.length = " + arguments.length);
    ok(m === "[test]", "m = " + m + " expected [test]");
    ok(off === 1, "off = " + off + " expected 0");
    ok(str === "-[test]-", "str = " + arguments[3]);
    return "ret";
}

r = "-[test]-".replace("[test]", replaceFunc3);
ok(r === "-ret-", "r = " + r + " expected '-ret-'");

r = "-[test]-".replace("[test]", replaceFunc3, "test");
ok(r === "-ret-", "r = " + r + " expected '-ret-'");

r = "x,x,x".replace("x", "y");
ok(r === "y,x,x", "r = " + r + " expected 'y,x,x'");

r = "x,x,x".replace("", "y");
ok(r === "yx,x,x", "r = " + r + " expected 'yx,x,x'");

r = "x,x,x".replace("", "");
ok(r === "x,x,x", "r = " + r + " expected 'x,x,x'");

r = "1,2,3".split(",");
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[2] = " + r[2]);

r = "1,2,3".split(",*");
ok(r.length === 1, "r.length = " + r.length);
ok(r[0] === "1,2,3", "r[0] = " + r[0]);

r = "123".split("");
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[2] = " + r[2]);

r = "123".split(2);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "3", "r[1] = " + r[1]);

r = "1,2,".split(",");
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "", "r[2] = " + r[2]);

r = "1,2,3".split(",", 2);
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);

r = "1,2,3".split(",", 0);
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 0, "r.length = " + r.length);

r = "1,2,3".split(",", -1);
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[1] = " + r[1]);

r = "1,2,3".split(undefined);
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 1, "r.length = " + r.length);
ok(r[0] === "1,2,3", "r[0] = " + r[0]);

r = "1,undefined2undefined,3".split(undefined);
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1,", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === ",3", "r[2] = " + r[2]);

r = "1,undefined2undefined,3".split();
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 1, "r.length = " + r.length);
ok(r[0] === "1,undefined2undefined,3", "r[0] = " + r[0]);

r = "".split();
ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
ok(r.length === 1, "r.length = " + r.length);
ok(r[0] === "", "r[0] = " + r[0]);

(function() {
    function test(string, separator, result) {
        var r = string.split(separator);
        ok(r == result, "\"" + string + "\".split(" + separator + ") returned " + r + " expected " + result);
    }

    test("test", /^|\s+/, "test");
    test("test", /$|\s+/, "test");
    test("test", /^|./, "t");
    test("test", /.*/, "");
    test("test", /x*/, "t,e,s,t");
    test("test", /$|x*/, "t,e,s,t");
    test("test", /^|x*/, "t,e,s,t");
    test("test", /t*/, "e,s");
    test("xaabaax", /a*|b*/, "x,b,x");
    test("xaabaax", /a+|b+/, "x,x");
    test("xaabaax", /a+|b*/, "x,x");
    test("xaaxbaax", /b+|a+/, "x,x,x");
    test("test", /^|t/, "tes");
    test("test", /^|t/, "tes");
    test("a,,b", /,/, "a,b");
    test("ab", /a*/, "b");
    test("aab", "a", ",,b");
    test("a", "a", ",");

    function test_length(string, separator, len) {
        var r = string.split(separator);
        ok(r.length === len, "\"" + string + "\".split(" + separator + ").length = "
           + r.length + " expected " + len);
    }

    test_length("", /a*/, 0);
    test_length("", /a+/, 1);
    test_length("", "", 0);
    test_length("", "x", 1);
})();

tmp = "abcd".indexOf("bc",0);
ok(tmp === 1, "indexOf = " + tmp);
tmp = "abcd".indexOf("bc",1);
ok(tmp === 1, "indexOf = " + tmp);
tmp = "abcd".indexOf("bc");
ok(tmp === 1, "indexOf = " + tmp);
tmp = "abcd".indexOf("ac");
ok(tmp === -1, "indexOf = " + tmp);
tmp = "abcd".indexOf("bc",2);
ok(tmp === -1, "indexOf = " + tmp);
tmp = "abcd".indexOf("a",0);
ok(tmp === 0, "indexOf = " + tmp);
tmp = "abcd".indexOf("bc",0,"test");
ok(tmp === 1, "indexOf = " + tmp);
tmp = "abcd".indexOf();
ok(tmp == -1, "indexOf = " + tmp);
tmp = "abcd".indexOf("b", bigInt);
ok(tmp == -1, "indexOf = " + tmp);
tmp = "abcd".indexOf("abcd",0);
ok(tmp === 0, "indexOf = " + tmp);
tmp = "abcd".indexOf("abcd",1);
ok(tmp === -1, "indexOf = " + tmp);
tmp = ("ab" + String.fromCharCode(0) + "cd").indexOf(String.fromCharCode(0));
ok(tmp === 2, "indexOf = " + tmp);

tmp = "abcd".lastIndexOf("bc",1);
ok(tmp === 1, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("bc",2);
ok(tmp === 1, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("bc");
ok(tmp === 1, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("ac");
ok(tmp === -1, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("d",10);
ok(tmp === 3, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("bc",0,"test");
ok(tmp === -1, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf();
ok(tmp === -1, "lastIndexOf = " + tmp);
tmp = "aaaa".lastIndexOf("a",2);
ok(tmp == 2, "lastIndexOf = " + tmp);
tmp = strObj.lastIndexOf("b");
ok(tmp === 1, "lastIndexOf = " + tmp);
tmp = "bbb".lastIndexOf("b", bigInt);
ok(tmp === 2, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("abcd",4);
ok(tmp === 0, "lastIndexOf = " + tmp);
tmp = "abcd".lastIndexOf("abcd",0);
ok(tmp === 0, "lastIndexOf = " + tmp);
tmp = ("ab" + String.fromCharCode(0) + "cd").lastIndexOf(String.fromCharCode(0));
ok(tmp === 2, "lastIndexOf = " + tmp);

tmp = "".toLowerCase();
ok(tmp === "", "''.toLowerCase() = " + tmp);
tmp = "test".toLowerCase();
ok(tmp === "test", "''.toLowerCase() = " + tmp);
tmp = "test".toLowerCase(3);
ok(tmp === "test", "''.toLowerCase(3) = " + tmp);
tmp = "tEsT".toLowerCase();
ok(tmp === "test", "''.toLowerCase() = " + tmp);
tmp = "tEsT".toLocaleLowerCase();
ok(tmp === "test", "''.toLocaleLowerCase() = " + tmp);
tmp = "tEsT".toLowerCase(3);
ok(tmp === "test", "''.toLowerCase(3) = " + tmp);
tmp = ("tE" + String.fromCharCode(0) + "sT").toLowerCase();
ok(tmp === "te" + String.fromCharCode(0) + "st", "''.toLowerCase() = " + tmp);
ok(String.prototype.toLocaleLowerCase != String.prototype.toLowerCase,
   "String.prototype.toLocaleLowerCase == String.prototype.toLowerCase");

tmp = "".toUpperCase();
ok(tmp === "", "''.toUpperCase() = " + tmp);
tmp = "TEST".toUpperCase();
ok(tmp === "TEST", "''.toUpperCase() = " + tmp);
tmp = "TEST".toUpperCase(3);
ok(tmp === "TEST", "''.toUpperCase(3) = " + tmp);
tmp = "tEsT".toUpperCase();
ok(tmp === "TEST", "''.toUpperCase() = " + tmp);
tmp = "tEsT".toUpperCase(3);
ok(tmp === "TEST", "''.toUpperCase(3) = " + tmp);
tmp = "tEsT".toLocaleUpperCase(3);
ok(tmp === "TEST", "''.toLocaleUpperCase(3) = " + tmp);
tmp = ("tE" + String.fromCharCode(0) + "sT").toUpperCase();
ok(tmp === "TE" + String.fromCharCode(0) + "ST", "''.toUpperCase() = " + tmp);
ok(String.prototype.toLocaleUpperCase != String.prototype.toUpperCase,
   "String.prototype.toLocaleUpperCase == String.prototype.toUpperCase");

tmp = "".anchor();
ok(tmp === "<A NAME=\"undefined\"></A>", "''.anchor() = " + tmp);
tmp = "".anchor(3);
ok(tmp === "<A NAME=\"3\"></A>", "''.anchor(3) = " + tmp);
tmp = "".anchor("red");
ok(tmp === "<A NAME=\"red\"></A>", "''.anchor('red') = " + tmp);
tmp = "test".anchor();
ok(tmp === "<A NAME=\"undefined\">test</A>", "'test'.anchor() = " + tmp);
tmp = "test".anchor(3);
ok(tmp === "<A NAME=\"3\">test</A>", "'test'.anchor(3) = " + tmp);
tmp = "test".anchor("green");
ok(tmp === "<A NAME=\"green\">test</A>", "'test'.anchor('green') = " + tmp);

tmp = "".big();
ok(tmp === "<BIG></BIG>", "''.big() = " + tmp);
tmp = "".big(3);
ok(tmp === "<BIG></BIG>", "''.big(3) = " + tmp);
tmp = "test".big();
ok(tmp === "<BIG>test</BIG>", "'test'.big() = " + tmp);
tmp = "test".big(3);
ok(tmp === "<BIG>test</BIG>", "'test'.big(3) = " + tmp);

tmp = "".blink();
ok(tmp === "<BLINK></BLINK>", "''.blink() = " + tmp);
tmp = "".blink(3);
ok(tmp === "<BLINK></BLINK>", "''.blink(3) = " + tmp);
tmp = "test".blink();
ok(tmp === "<BLINK>test</BLINK>", "'test'.blink() = " + tmp);
tmp = "test".blink(3);
ok(tmp === "<BLINK>test</BLINK>", "'test'.blink(3) = " + tmp);

tmp = "".bold();
ok(tmp === "<B></B>", "''.bold() = " + tmp);
tmp = "".bold(3);
ok(tmp === "<B></B>", "''.bold(3) = " + tmp);
tmp = "test".bold();
ok(tmp === "<B>test</B>", "'test'.bold() = " + tmp);
tmp = "test".bold(3);
ok(tmp === "<B>test</B>", "'test'.bold(3) = " + tmp);

tmp = "".fixed();
ok(tmp === "<TT></TT>", "''.fixed() = " + tmp);
tmp = "".fixed(3);
ok(tmp === "<TT></TT>", "''.fixed(3) = " + tmp);
tmp = "test".fixed();
ok(tmp === "<TT>test</TT>", "'test'.fixed() = " + tmp);
tmp = "test".fixed(3);
ok(tmp === "<TT>test</TT>", "'test'.fixed(3) = " + tmp);

tmp = "".fontcolor();
ok(tmp === "<FONT COLOR=\"undefined\"></FONT>", "''.fontcolor() = " + tmp);
tmp = "".fontcolor(3);
ok(tmp === "<FONT COLOR=\"3\"></FONT>", "''.fontcolor(3) = " + tmp);
tmp = "".fontcolor("red");
ok(tmp === "<FONT COLOR=\"red\"></FONT>", "''.fontcolor('red') = " + tmp);
tmp = "test".fontcolor();
ok(tmp === "<FONT COLOR=\"undefined\">test</FONT>", "'test'.fontcolor() = " + tmp);
tmp = "test".fontcolor(3);
ok(tmp === "<FONT COLOR=\"3\">test</FONT>", "'test'.fontcolor(3) = " + tmp);
tmp = "test".fontcolor("green");
ok(tmp === "<FONT COLOR=\"green\">test</FONT>", "'test'.fontcolor('green') = " + tmp);

tmp = "".fontsize();
ok(tmp === "<FONT SIZE=\"undefined\"></FONT>", "''.fontsize() = " + tmp);
tmp = "".fontsize(3);
ok(tmp === "<FONT SIZE=\"3\"></FONT>", "''.fontsize(3) = " + tmp);
tmp = "".fontsize("red");
ok(tmp === "<FONT SIZE=\"red\"></FONT>", "''.fontsize('red') = " + tmp);
tmp = "test".fontsize();
ok(tmp === "<FONT SIZE=\"undefined\">test</FONT>", "'test'.fontsize() = " + tmp);
tmp = "test".fontsize(3);
ok(tmp === "<FONT SIZE=\"3\">test</FONT>", "'test'.fontsize(3) = " + tmp);
tmp = "test".fontsize("green");
ok(tmp === "<FONT SIZE=\"green\">test</FONT>", "'test'.fontsize('green') = " + tmp);

tmp = ("".fontcolor()).fontsize();
ok(tmp === "<FONT SIZE=\"undefined\"><FONT COLOR=\"undefined\"></FONT></FONT>", "(''.fontcolor()).fontsize() = " + tmp);

tmp = "".italics();
ok(tmp === "<I></I>", "''.italics() = " + tmp);
tmp = "".italics(3);
ok(tmp === "<I></I>", "''.italics(3) = " + tmp);
tmp = "test".italics();
ok(tmp === "<I>test</I>", "'test'.italics() = " + tmp);
tmp = "test".italics(3);
ok(tmp === "<I>test</I>", "'test'.italics(3) = " + tmp);

tmp = "".link();
ok(tmp === "<A HREF=\"undefined\"></A>", "''.link() = " + tmp);
tmp = "".link(3);
ok(tmp === "<A HREF=\"3\"></A>", "''.link(3) = " + tmp);
tmp = "".link("red");
ok(tmp === "<A HREF=\"red\"></A>", "''.link('red') = " + tmp);
tmp = "test".link();
ok(tmp === "<A HREF=\"undefined\">test</A>", "'test'.link() = " + tmp);
tmp = "test".link(3);
ok(tmp === "<A HREF=\"3\">test</A>", "'test'.link(3) = " + tmp);
tmp = "test".link("green");
ok(tmp === "<A HREF=\"green\">test</A>", "'test'.link('green') = " + tmp);

tmp = "".small();
ok(tmp === "<SMALL></SMALL>", "''.small() = " + tmp);
tmp = "".small(3);
ok(tmp === "<SMALL></SMALL>", "''.small(3) = " + tmp);
tmp = "test".small();
ok(tmp === "<SMALL>test</SMALL>", "'test'.small() = " + tmp);
tmp = "test".small(3);
ok(tmp === "<SMALL>test</SMALL>", "'test'.small(3) = " + tmp);

tmp = "".strike();
ok(tmp === "<STRIKE></STRIKE>", "''.strike() = " + tmp);
tmp = "".strike(3);
ok(tmp === "<STRIKE></STRIKE>", "''.strike(3) = " + tmp);
tmp = "test".strike();
ok(tmp === "<STRIKE>test</STRIKE>", "'test'.strike() = " + tmp);
tmp = "test".strike(3);
ok(tmp === "<STRIKE>test</STRIKE>", "'test'.strike(3) = " + tmp);

tmp = "".sub();
ok(tmp === "<SUB></SUB>", "''.sub() = " + tmp);
tmp = "".sub(3);
ok(tmp === "<SUB></SUB>", "''.sub(3) = " + tmp);
tmp = "test".sub();
ok(tmp === "<SUB>test</SUB>", "'test'.sub() = " + tmp);
tmp = "test".sub(3);
ok(tmp === "<SUB>test</SUB>", "'test'.sub(3) = " + tmp);

tmp = "".sup();
ok(tmp === "<SUP></SUP>", "''.sup() = " + tmp);
tmp = "".sup(3);
ok(tmp === "<SUP></SUP>", "''.sup(3) = " + tmp);
tmp = "test".sup();
ok(tmp === "<SUP>test</SUP>", "'test'.sup() = " + tmp);
tmp = "test".sup(3);
ok(tmp === "<SUP>test</SUP>", "'test'.sup(3) = " + tmp);

ok(String.fromCharCode() === "", "String.fromCharCode() = " + String.fromCharCode());
ok(String.fromCharCode(65,"66",67) === "ABC", "String.fromCharCode(65,'66',67) = " + String.fromCharCode(65,"66",67));
ok(String.fromCharCode(1024*64+65, -1024*64+65) === "AA",
        "String.fromCharCode(1024*64+65, -1024*64+65) = " + String.fromCharCode(1024*64+65, -1024*64+65));
ok(String.fromCharCode(65, NaN, undefined).length === 3,
        "String.fromCharCode(65, NaN, undefined).length = " + String.fromCharCode(65, NaN, undefined).length);

var arr = new Array();
ok(typeof(arr) === "object", "arr () is not object");
ok((arr.length === 0), "arr.length is not 0");
ok(arr["0"] === undefined, "arr[0] is not undefined");

var arr = new Array(1, 2, "test");
ok(typeof(arr) === "object", "arr (1,2,test) is not object");
ok((arr.length === 3), "arr.length is not 3");
ok(arr["0"] === 1, "arr[0] is not 1");
ok(arr["1"] === 2, "arr[1] is not 2");
ok(arr["2"] === "test", "arr[2] is not \"test\"");

arr["7"] = true;
ok((arr.length === 8), "arr.length is not 8");

tmp = "" + [];
ok(tmp === "", "'' + [] = " + tmp);
tmp = "" + [1,true];
ok(tmp === "1,true", "'' + [1,true] = " + tmp);

var arr = new Array(6);
ok(typeof(arr) === "object", "arr (6) is not object");
ok((arr.length === 6), "arr.length is not 6");
ok(arr["0"] === undefined, "arr[0] is not undefined");

ok(arr.push() === 6, "arr.push() !== 6");
ok(arr.push(1) === 7, "arr.push(1) !== 7");
ok(arr[6] === 1, "arr[6] != 1");
ok(arr.length === 7, "arr.length != 10");
ok(arr.push(true, 'b', false) === 10, "arr.push(true, 'b', false) !== 10");
ok(arr[8] === "b", "arr[8] != 'b'");
ok(arr.length === 10, "arr.length != 10");

var arr = new Object();
arr.push = Array.prototype.push;

arr.length = 6;

ok(arr.push() === 6, "arr.push() !== 6");
ok(arr.push(1) === 7, "arr.push(1) !== 7");
ok(arr[6] === 1, "arr[6] != 1");
ok(arr.length === 7, "arr.length != 10");
ok(arr.push(true, 'b', false) === 10, "arr.push(true, 'b', false) !== 10");
ok(arr[8] === "b", "arr[8] != 'b'");
ok(arr.length === 10, "arr.length != 10");

arr.pop = Array.prototype.pop;
ok(arr.pop() === false, "arr.pop() !== false");
ok(arr[8] === "b", "arr[8] !== 'b'");
ok(arr.pop() === 'b', "arr.pop() !== 'b'");
ok(arr[8] === undefined, "arr[8] !== undefined");

arr = [3,4,5];
tmp = arr.pop();
ok(arr.length === 2, "arr.length = " + arr.length);
ok(tmp === 5, "pop() = " + tmp);
tmp = arr.pop(2);
ok(arr.length === 1, "arr.length = " + arr.length);
ok(tmp === 4, "pop() = " + tmp);
tmp = arr.pop();
ok(arr.length === 0, "arr.length = " + arr.length);
ok(tmp === 3, "pop() = " + tmp);
for(tmp in arr)
    ok(false, "not deleted " + tmp);
tmp = arr.pop();
ok(arr.length === 0, "arr.length = " + arr.length);
ok(tmp === undefined, "tmp = " + tmp);
arr = new Object();
arr.pop = Array.prototype.pop;
tmp = arr.pop();
ok(arr.length === 0, "arr.length = " + arr.length);
ok(tmp === undefined, "tmp = " + tmp);
arr = [,,,,,];
tmp = arr.pop();
ok(arr.length === 5, "arr.length = " + arr.length);
ok(tmp === undefined, "tmp = " + tmp);
tmp = [1,2,,,].pop();
ok(tmp === undefined, "tmp = " + tmp);

function PseudoArray() {
    this[0] = 0;
}
PseudoArray.prototype = {length: 1};
arr = new PseudoArray();
Array.prototype.push.call(arr, 2);
ok(arr.propertyIsEnumerable("length"), "arr.length is not enumerable");

arr = [1,2,null,false,undefined,,"a"];

tmp = arr.join();
ok(tmp === "1,2,,false,,,a", "arr.join() = " + tmp);
tmp = arr.join(";");
ok(tmp === "1;2;;false;;;a", "arr.join(';') = " + tmp);
tmp = arr.join(";","test");
ok(tmp === "1;2;;false;;;a", "arr.join(';') = " + tmp);
tmp = arr.join("");
ok(tmp === "12falsea", "arr.join('') = " + tmp);

tmp = arr.toString();
ok(tmp === "1,2,,false,,,a", "arr.toString() = " + tmp);
tmp = arr.toString("test");
ok(tmp === "1,2,,false,,,a", "arr.toString() = " + tmp);

arr = ["a", "b"];

tmp = arr.join(String.fromCharCode(0));
ok(tmp === "a" + String.fromCharCode(0) + "b", "arr.join(String.fromCharCode(0)) = " + tmp);

arr = new Object();
arr.length = 3;
arr[0] = "aa";
arr[2] = 2;
arr[7] = 3;
arr.join = Array.prototype.join;
tmp = arr.join(",");
ok(arr.length === 3, "arr.length = " + arr.length);
ok(tmp === "aa,,2", "tmp = " + tmp);

arr = [5,true,2,-1,3,false,"2.5"];
tmp = arr.sort(function(x,y) { return y-x; });
ok(tmp === arr, "tmp !== arr");
tmp = [5,3,"2.5",2,true,false,-1];
for(var i=0; i < arr.length; i++)
    ok(arr[i] === tmp[i], "arr[" + i + "] = " + arr[i] + " expected " + tmp[i]);

tmp = [3,1,2].sort(function(x,y) { return y-x; }).join();
ok(tmp === "3,2,1", "reverse sorted [3,1,2] = " + tmp);

tmp = [3,1,2].sort(null).join();
ok(tmp === "1,2,3", "null sorted [3,1,2] = " + tmp);

try {
    tmp = [3,1,2].sort(function(x,y) { return y-x; }, 1, 2, 3);
    ok(false, "expected sort(undefined) exception");
} catch(e) {
    ok(e.name === "TypeError", "got exception " + e.name);
}

arr = [5,false,2,0,"abc",3,"a",-1];
tmp = arr.sort();
ok(tmp === arr, "tmp !== arr");
tmp = [-1,0,2,3,5,"a","abc",false];
for(var i=0; i < arr.length; i++)
    ok(arr[i] === tmp[i], "arr[" + i + "] = " + arr[i] + " expected " + tmp[i]);

arr = ["a", "b", "ab"];
tmp = ["a", "ab", "b"];
ok(arr.sort() === arr, "arr.sort() !== arr");
for(var i=0; i < arr.length; i++)
    ok(arr[i] === tmp[i], "arr[" + i + "] = " + arr[i] + " expected " + tmp[i]);

arr = new Object();
arr.length = 3;
arr[0] = 1;
arr[2] = "aa";
arr.sort = Array.prototype.sort;
tmp = arr.sort();
ok(arr === tmp, "tmp !== arr");
ok(arr[0]===1 && arr[1]==="aa" && arr[2]===undefined, "arr is sorted incorrectly");

tmp = [["bb","aa"],["ab","aa"]].sort().toString();
ok(tmp === "ab,aa,bb,aa", "sort() = " + tmp);

tmp = [["bb","aa"],"ab"].sort().toString();
ok(tmp === "ab,bb,aa", "sort() = " + tmp);

tmp = [["bb","aa"],"cc"].sort().toString();
ok(tmp === "bb,aa,cc", "sort() = " + tmp);

tmp = [2,"1"].sort().toString();
ok(tmp === "1,2", "sort() = " + tmp);

tmp = ["2",1].sort().toString();
ok(tmp === "1,2", "sort() = " + tmp);

tmp = [,,0,"z"].sort().toString();
ok(tmp === "0,z,,", "sort() = " + tmp);

tmp = ["a,b",["a","a"],["a","c"]].sort().toString();
ok(tmp === "a,a,a,b,a,c", "sort() = " + tmp);

arr = ["1", "2", "3"];
arr.length = 1;
ok(arr.length === 1, "arr.length = " + arr.length);
arr.length = 3;
ok(arr.length === 3, "arr.length = " + arr.length);
ok(arr.toString() === "1,,", "arr.toString() = " + arr.toString());

arr = Array("a","b","c");
ok(arr.toString() === "a,b,c", "arr.toString() = " + arr.toString());

ok(arr.valueOf === Object.prototype.valueOf, "arr.valueOf !== Object.prototype.valueOf");
ok(arr === arr.valueOf(), "arr !== arr.valueOf");

arr = [1,2,3];
tmp = arr.reverse();
ok(tmp === arr, "tmp !== arr");
ok(arr.length === 3, "arr.length = " + arr.length);
ok(arr.toString() === "3,2,1", "arr.toString() = " + arr.toString());

arr = [];
arr[3] = 5;
arr[5] = 1;
tmp = arr.reverse();
ok(tmp === arr, "tmp !== arr");
ok(arr.length === 6, "arr.length = " + arr.length);
ok(arr.toString() === "1,,5,,,", "arr.toString() = " + arr.toString());

arr = new Object();
arr.length = 3;
arr[0] = "aa";
arr[2] = 2;
arr[7] = 3;
arr.reverse = Array.prototype.reverse;
tmp = arr.reverse();
ok(tmp === arr, "tmp !== arr");
ok(arr.length === 3, "arr.length = " + arr.length);
ok(arr[0] === 2 && arr[1] === undefined && arr[2] === "aa", "unexpected array");

arr = [1,2,3];
tmp = arr.unshift(0);
ok(tmp === (invokeVersion < 2 ? undefined : 4), "[1,2,3].unshift(0) returned " +tmp);
ok(arr.length === 4, "arr.length = " + arr.length);
ok(arr.toString() === "0,1,2,3", "arr.toString() = " + arr.toString());

arr = new Array(3);
arr[0] = 1;
arr[2] = 3;
tmp = arr.unshift(-1,0);
ok(tmp === (invokeVersion < 2 ? undefined : 5), "unshift returned " +tmp);
ok(arr.length === 5, "arr.length = " + arr.length);
ok(arr.toString() === "-1,0,1,,3", "arr.toString() = " + arr.toString());

arr = [1,2,3];
tmp = arr.unshift();
ok(tmp === (invokeVersion < 2 ? undefined : 3), "unshift returned " +tmp);
ok(arr.length === 3, "arr.length = " + arr.length);
ok(arr.toString() === "1,2,3", "arr.toString() = " + arr.toString());

arr = new Object();
arr.length = 2;
arr[0] = 1;
arr[1] = 2;
tmp = Array.prototype.unshift.call(arr, 0);
ok(tmp === (invokeVersion < 2 ? undefined : 3), "unshift returned " +tmp);
ok(arr.length === 3, "arr.length = " + arr.length);
ok(arr[0] === 0 && arr[1] === 1 && arr[2] === 2, "unexpected array");

arr = [1,2,,4];
tmp = arr.shift();
ok(tmp === 1, "[1,2,,4].shift() = " + tmp);
ok(arr.toString() === "2,,4", "arr = " + arr.toString());

arr = [];
tmp = arr.shift();
ok(tmp === undefined, "[].shift() = " + tmp);
ok(arr.toString() === "", "arr = " + arr.toString());

arr = [1,2,,4];
tmp = arr.shift(2);
ok(tmp === 1, "[1,2,,4].shift(2) = " + tmp);
ok(arr.toString() === "2,,4", "arr = " + arr.toString());

arr = [1,];
tmp = arr.shift();
ok(tmp === 1, "[1,].shift() = " + tmp);
ok(arr.toString() === "", "arr = " + arr.toString());

obj = new Object();
obj[0] = "test";
obj[2] = 3;
obj.length = 3;
tmp = Array.prototype.shift.call(obj);
ok(tmp === "test", "obj.shift() = " + tmp);
ok(obj.length == 2, "obj.length = " + obj.length);
ok(obj[1] === 3, "obj[1] = " + obj[1]);

var num = new Number(6);
arr = [0,1,2];
tmp = arr.concat(3, [4,5], num);
ok(tmp !== arr, "tmp === arr");
for(var i=0; i<6; i++)
    ok(tmp[i] === i, "tmp[" + i + "] = " + tmp[i]);
ok(tmp[6] === num, "tmp[6] !== num");
ok(tmp.length === 7, "tmp.length = " + tmp.length);

arr = [].concat();
ok(arr.length === 0, "arr.length = " + arr.length);

arr = [1,];
tmp = arr.concat([2]);
ok(tmp.length === 3, "tmp.length = " + tmp.length);
ok(tmp[1] === undefined, "tmp[1] = " + tmp[1]);

arr = [1,false,'a',null,undefined,'a'];
ok(arr.slice(0,6).toString() === "1,false,a,,,a", "arr.slice(0,6).toString() = " + arr.slice(0,6));
ok(arr.slice(0,6).length === 6, "arr.slice(0,6).length = " + arr.slice(0,6).length);
ok(arr.slice().toString() === "1,false,a,,,a", "arr.slice().toString() = " + arr.slice());
ok(arr.slice("abc").toString() === "1,false,a,,,a", "arr.slice(\"abc\").toString() = " + arr.slice("abc"));
ok(arr.slice(3,8).toString() === ",,a", "arr.slice(3,8).toString() = " + arr.slice(3,8));
ok(arr.slice(3,8).length === 3, "arr.slice(3,8).length = " + arr.slice(3,8).length);
ok(arr.slice(1).toString() === "false,a,,,a", "arr.slice(1).toString() = " + arr.slice(1));
ok(arr.slice(-2).toString() === ",a", "arr.slice(-2).toString() = " + arr.slice(-2));
ok(arr.slice(3,1).toString() === "", "arr.slice(3,1).toString() = " + arr.slice(3,1));
tmp = arr.slice(0,6);
for(var i=0; i < arr.length; i++)
    ok(arr[i] === tmp[i], "arr[" + i + "] = " + arr[i] + " expected " + tmp[i]);
arr[12] = 2;
ok(arr.slice(5).toString() === "a,,,,,,,2", "arr.slice(5).toString() = " + arr.slice(5).toString());
ok(arr.slice(5).length === 8, "arr.slice(5).length = " + arr.slice(5).length);

arr = [1,2,3,4,5];
tmp = arr.splice(2,2);
ok(tmp.toString() == "3,4", "arr.splice(2,2) returned " + tmp.toString());
ok(arr.toString() == "1,2,5", "arr.splice(2,2) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(2,2,"a");
ok(tmp.toString() == "3,4", "arr.splice(2,2,'a') returned " + tmp.toString());
ok(arr.toString() == "1,2,a,5", "arr.splice(2,2,'a') is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(2,2,'a','b','c');
ok(tmp.toString() == "3,4", "arr.splice(2,2,'a','b','c') returned " + tmp.toString());
ok(arr.toString() == "1,2,a,b,c,5", "arr.splice(2,2,'a','b','c') is " + arr.toString());

arr = [1,2,3,4,];
tmp = arr.splice(2,2,'a','b','c');
ok(tmp.toString() == "3,4", "arr.splice(2,2,'a','b','c') returned " + tmp.toString());
ok(arr.toString() == "1,2,a,b,c,", "arr.splice(2,2,'a','b','c') is " + arr.toString());

arr = [1,2,3,4,];
arr.splice(2,2,'a','b','c');
ok(arr.toString() == "1,2,a,b,c,", "arr.splice(2,2,'a','b','c') is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(2,2,'a','b');
ok(tmp.toString() == "3,4", "arr.splice(2,2,'a','b') returned " + tmp.toString());
ok(arr.toString() == "1,2,a,b,5", "arr.splice(2,2,'a','b') is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(-1,2);
ok(tmp.toString() == "5", "arr.splice(-1,2) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4", "arr.splice(-1,2) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(-10,3);
ok(tmp.toString() == "1,2,3", "arr.splice(-10,3) returned " + tmp.toString());
ok(arr.toString() == "4,5", "arr.splice(-10,3) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(-10,100);
ok(tmp.toString() == "1,2,3,4,5", "arr.splice(-10,100) returned " + tmp.toString());
ok(arr.toString() == "", "arr.splice(-10,100) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(2,-1);
ok(tmp.toString() == "", "arr.splice(2,-1) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(2,-1) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(2);
ok(tmp.toString() == "", "arr.splice(2) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(2) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice();
ok(tmp.toString() == "", "arr.splice(2,-1) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(2,-1) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(bigInt);
ok(tmp.toString() == "", "arr.splice(bigInt) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(bigInt) is " + arr.toString());

arr = [1,2,3,4,5];
tmp = arr.splice(-bigInt);
ok(tmp.toString() == "", "arr.splice(-bigInt) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(-bigInt) is " + arr.toString());

if(invokeVersion >= 2) {
    arr = [1,2,3,4,5];
    tmp = arr.splice(2, bigInt);
    ok(tmp.toString() == "3,4,5", "arr.splice(2, bigInt) returned " + tmp.toString());
    ok(arr.toString() == "1,2", "arr.splice(2, bigInt) is " + arr.toString());
}

arr = [1,2,3,4,5];
tmp = arr.splice(2, -bigInt);
ok(tmp.toString() == "", "arr.splice(2, -bigInt) returned " + tmp.toString());
ok(arr.toString() == "1,2,3,4,5", "arr.splice(2, -bigInt) is " + arr.toString());

obj = new Object();
obj.length = 3;
obj[0] = 1;
obj[1] = 2;
obj[2] = 3;
tmp = Array.prototype.splice.call(obj, 1, 1, 'a', 'b');
ok(tmp.toString() === "2", "obj.splice returned " + tmp);
ok(obj.length === 4, "obj.length = " + obj.length);
ok(obj[0] === 1, "obj[0] = " + obj[0]);
ok(obj[1] === 'a', "obj[1] = " + obj[1]);
ok(obj[2] === 'b', "obj[2] = " + obj[2]);
ok(obj[3] === 3, "obj[3] = " + obj[3]);

obj = new Object();
obj.length = 3;
obj[0] = 1;
obj[1] = 2;
obj[2] = 3;
tmp = Array.prototype.slice.call(obj, 1, 2);
ok(tmp.length === 1, "tmp.length = " + tmp.length);
ok(tmp[0] === 2, "tmp[0] = " + tmp[0]);

tmp = (new Number(2)).toString();
ok(tmp === "2", "num(2).toString = " + tmp);
tmp = (new Number()).toString();
ok(tmp === "0", "num().toString = " + tmp);
tmp = (new Number(5.5)).toString(2);
ok(tmp === "101.1", "num(5.5).toString(2) = " + tmp);

tmp = (new Number(12)).toLocaleString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = Number.prototype.toLocaleString.call(NaN);
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");

tmp = (new Number(3)).toFixed(3);
ok(tmp === "3.000", "num(3).toFixed(3) = " + tmp);
tmp = (new Number(3)).toFixed();
ok(tmp === "3", "Number(3).toFixed() = " + tmp);
tmp = (new Number(0)).toFixed();
ok(tmp === "0", "Number(0).toFixed() = " + tmp);
tmp = (new Number(0)).toFixed(1);
ok(tmp === "0.0", "Number(0).toFixed(1) = " + tmp);
tmp = (new Number(0)).toFixed(2);
ok(tmp === "0.00", "Number(0).toFixed(2) = " + tmp);
tmp = (new Number(1.76)).toFixed(1);
ok(tmp === "1.8", "num(1.76).toFixed(1) = " + tmp);
tmp = (new Number(7.92)).toFixed(5);
ok(tmp === "7.92000", "num(7.92).toFixed(5) = " + tmp);
tmp = (new Number(2.88)).toFixed();
ok(tmp === "3", "num(2.88).toFixed = " + tmp);
tmp = (new Number(-2.5)).toFixed();
ok(tmp === "-3", "num(-2.5).toFixed = " + tmp);
tmp = (new Number(1000000000000000128)).toFixed(0);
//todo_wine ok(tmp === "1000000000000000100", "num(1000000000000000128) = " + tmp);
tmp = (new Number(3.14).toFixed(NaN));
ok(tmp === "3", "num(3.14).toFixed = " + tmp);
tmp = (new Number(0.95).toFixed(1));
ok(tmp === "1.0", "num(0.95).toFixed(1) = " + tmp);
tmp = (new Number(1e900)).toFixed(0);
ok(tmp === "Infinity", "num(1000000000000000128) = " + tmp);
tmp = (new Number(0.12345678901234567890123)).toFixed(20);
ok(tmp === "0.12345678901234568000", "num(0.12345678901234567890123) = " + tmp);

tmp = (new Number(2)).toExponential(3);
ok(tmp === "2.000e+0", "num(2).toExponential(3) = " + tmp);
tmp = (new Number(1.17e-32)).toExponential(20);
ok(tmp === "1.17000000000000000000e-32", "num(1.17e-32).toExponential(20) = " + tmp);
tmp = (new Number(0)).toExponential(7);
ok(tmp === "0.0000000e+0", "num(0).toExponential(7) = " + tmp);
tmp = (new Number(0)).toExponential(0);
ok(tmp === "0e+0", "num(0).toExponential() = " + tmp);
tmp = (new Number(-13.7567)).toExponential();
ok(tmp === "-1.37567e+1", "num(-13.7567).toExponential() = " + tmp);
tmp = (new Number(-32.1)).toExponential();
ok(tmp === "-3.21e+1", "num(-32.1).toExponential() = " + tmp);
tmp = (new Number(4723.4235)).toExponential();
ok(tmp === "4.7234235e+3", "num(4723.4235).toExponential() = " + tmp);

tmp = (new Number(5)).toPrecision(12);
ok(tmp == "5.00000000000", "num(5).toPrecision(12) = " + tmp);
tmp = (new Number(7.73)).toPrecision(7);
ok(tmp == "7.730000", "num(7.73).toPrecision(7) = " + tmp);
tmp = (new Number(-127547.47472)).toPrecision(17);
ok(tmp == "-127547.47472000000", "num(-127547.47472).toPrecision(17) = " + tmp);
tmp = (new Number(0)).toPrecision(3);
ok(tmp == "0.00", "num(0).toPrecision(3) = " + tmp);
tmp = (new Number(42345.52342465464562334)).toPrecision(15);
ok(tmp == "42345.5234246546", "num(42345.52342465464562334).toPrecision(15) = " + tmp);
tmp = (new Number(1.182e30)).toPrecision(5);
ok(tmp == "1.1820e+30", "num(1.182e30)).toPrecision(5) = " + tmp);
tmp = (new Number(1.123)).toPrecision();
ok(tmp == "1.123", "num(1.123).toPrecision() = " + tmp);
if(invokeVersion >= 2) {
    tmp = (new Number(1.123)).toPrecision(undefined);
    ok(tmp == "1.123", "num(1.123).toPrecision(undefined) = " + tmp);
}

ok(Number() === 0, "Number() = " + Number());
ok(Number(false) === 0, "Number(false) = " + Number(false));
ok(Number("43") === 43, "Number('43') = " + Number("43"));

tmp = (new Number(1)).valueOf();
ok(tmp === 1, "(new Number(1)).valueOf = " + tmp);
tmp = (new Number(1,2)).valueOf();
ok(tmp === 1, "(new Number(1,2)).valueOf = " + tmp);
tmp = (new Number()).valueOf();
ok(tmp === 0, "(new Number()).valueOf = " + tmp);
tmp = Number.prototype.valueOf();
ok(tmp === 0, "Number.prototype.valueOf = " + tmp);

function equals(val, base) {
    var i;
    var num = 0;
    var str = val.toString(base);

    for(i=0; i<str.length; i++) {
        if(str.substring(i, i+1) == '(') break;
        if(str.substring(i, i+1) == '.') break;
        num = num*base + parseInt(str.substring(i, i+1));
    }

    if(str.substring(i, i+1) == '.') {
        var mult = base;
        for(i++; i<str.length; i++) {
            if(str.substring(i, i+1) == '(') break;
            num += parseInt(str.substring(i, i+1))/mult;
            mult *= base;
        }
    }

    if(str.substring(i, i+1) == '(') {
        exp = parseInt(str.substring(i+2));
        num *= Math.pow(base, exp);
    }

    ok(num>val-val/1000 && num<val+val/1000, "equals: num = " + num);
}

ok((10).toString(11) === "a", "(10).toString(11) = " + (10).toString(11));
ok((213213433).toString(17) === "8e2ddcb", "(213213433).toString(17) = " + (213213433).toString(17));
ok((-3254343).toString(33) === "-2oicf", "(-3254343).toString(33) = " + (-3254343).toString(33));
ok((NaN).toString(12) === "NaN", "(NaN).toString(11) = " + (NaN).toString(11));
ok((Infinity).toString(13) === "Infinity", "(Infinity).toString(11) = " + (Infinity).toString(11));
for(i=2; i<10; i++) {
    equals(1.123, i);
    equals(2305843009200000000, i);
    equals(5.123, i);
    equals(21711, i);
    equals(1024*1024*1024*1024*1024*1024*1.9999, i);
    equals(748382, i);
    equals(0.6, i);
    equals(4.65661287308e-10, i);
    ok((0).toString(i) === "0", "(0).toString("+i+") = " + (0).toString(i));
}

ok(parseFloat('123') === 123, "parseFloat('123') = " + parseFloat('123'));
ok(parseFloat('-13.7') === -13.7, "parseFloat('-13.7') = " + parseFloat('-13.7'));
ok(parseFloat('-0.01e-2') === -0.01e-2, "parseFloat('-0.01e-2') = " + parseFloat('-0.01e-2'));
ok(parseFloat('-12e+5') === -12e+5, "parseFloat('-12e+5') = " + parseFloat('-12e+5'));
ok(parseFloat('1E5 not parsed') === 1E5, "parseFloat('1E5 not parsed') = " + parseFloat('1E5 not parsed'));
ok(isNaN(parseFloat('not a number')), "parseFloat('not a number') is not NaN");
ok(parseFloat('+13.2e-3') === 13.2e-3, "parseFloat('+13.2e-3') = " + parseFloat('+13.2e-3'));
ok(parseFloat('.12') === 0.12, "parseFloat('.12') = " + parseFloat('.12'));
ok(parseFloat('1e') === 1, "parseFloat('1e') = " + parseFloat('1e'));
ok(isNaN(parseFloat('\uff16')), "parseFloat('\\uD835') is not NaN");

tmp = Math.min(1);
ok(tmp === 1, "Math.min(1) = " + tmp);

tmp = Math.min(1, false);
ok(tmp === 0, "Math.min(1, false) = " + tmp);

tmp = Math.min();
ok(tmp === Infinity, "Math.min() = " + tmp);

tmp = Math.min(1, NaN, -Infinity, false);
ok(isNaN(tmp), "Math.min(1, NaN, -Infinity, false) is not NaN");

tmp = Math.min(1, false, true, null, -3);
ok(tmp === -3, "Math.min(1, false, true, null, -3) = " + tmp);

tmp = Math.max(1);
ok(tmp === 1, "Math.max(1) = " + tmp);

tmp = Math.max(true, 0);
ok(tmp === 1, "Math.max(true, 0) = " + tmp);

tmp = Math.max(-2, false, true, null, 1);
ok(tmp === 1, "Math.max(-2, false, true, null, 1) = " + tmp);

tmp = Math.max();
ok(tmp === -Infinity, "Math.max() = " + tmp);

tmp = Math.max(true, NaN, 0);
ok(isNaN(tmp), "Math.max(true, NaN, 0) is not NaN");

tmp = Math.round(0.5);
ok(tmp === 1, "Math.round(0.5) = " + tmp);

tmp = Math.round(-0.5);
ok(tmp === 0, "Math.round(-0.5) = " + tmp);

tmp = Math.round(1.1);
ok(tmp === 1, "Math.round(1.1) = " + tmp);

tmp = Math.round(true);
ok(tmp === 1, "Math.round(true) = " + tmp);

tmp = Math.round(1.1, 3, 4);
ok(tmp === 1, "Math.round(1.1, 3, 4) = " + tmp);

tmp = Math.round();
ok(isNaN(tmp), "Math.round() is not NaN");

tmp = Math.ceil(0.5);
ok(tmp === 1, "Math.ceil(0.5) = " + tmp);

tmp = Math.ceil(-0.5);
ok(tmp === 0, "Math.ceil(-0.5) = " + tmp);

tmp = Math.ceil(1.1);
ok(tmp === 2, "Math.round(1.1) = " + tmp);

tmp = Math.ceil(true);
ok(tmp === 1, "Math.ceil(true) = " + tmp);

tmp = Math.ceil(1.1, 3, 4);
ok(tmp === 2, "Math.ceil(1.1, 3, 4) = " + tmp);

tmp = Math.ceil();
ok(isNaN(tmp), "ceil() is not NaN");

tmp = Math.floor(0.5);
ok(tmp === 0, "Math.floor(0.5) = " + tmp);

tmp = Math.floor(-0.5);
ok(tmp === -1, "Math.floor(-0.5) = " + tmp);

tmp = Math.floor(1.1);
ok(tmp === 1, "Math.floor(1.1) = " + tmp);

tmp = Math.floor(true);
ok(tmp === 1, "Math.floor(true) = " + tmp);

tmp = Math.floor(1.1, 3, 4);
ok(tmp === 1, "Math.floor(1.1, 3, 4) = " + tmp);

tmp = Math.floor();
ok(isNaN(tmp), "floor is not NaN");

tmp = Math.abs(3);
ok(tmp === 3, "Math.abs(3) = " + tmp);

tmp = Math.abs(-3);
ok(tmp === 3, "Math.abs(-3) = " + tmp);

tmp = Math.abs(true);
ok(tmp === 1, "Math.abs(true) = " + tmp);

tmp = Math.abs();
ok(isNaN(tmp), "Math.abs() is not NaN");

tmp = Math.abs(NaN);
ok(isNaN(tmp), "Math.abs() is not NaN");

tmp = Math.abs(-Infinity);
ok(tmp === Infinity, "Math.abs(-Infinite) = " + tmp);

tmp = Math.abs(-3, 2);
ok(tmp === 3, "Math.abs(-3, 2) = " + tmp);

tmp = Math.cos(0);
ok(tmp === 1, "Math.cos(0) = " + tmp);

tmp = Math.cos(Math.PI/2);
ok(Math.floor(tmp*100) === 0, "Math.cos(Math.PI/2) = " + tmp);

tmp = Math.cos(-Math.PI/2);
ok(Math.floor(tmp*100) === 0, "Math.cos(-Math.PI/2) = " + tmp);

tmp = Math.cos(Math.PI/3, 2);
ok(Math.floor(tmp*100) === 50, "Math.cos(Math.PI/3, 2) = " + tmp);

tmp = Math.cos(true);
ok(Math.floor(tmp*100) === 54, "Math.cos(true) = " + tmp);

tmp = Math.cos(false);
ok(tmp === 1, "Math.cos(false) = " + tmp);

tmp = Math.cos();
ok(isNaN(tmp), "Math.cos() is not NaN");

tmp = Math.cos(NaN);
ok(isNaN(tmp), "Math.cos(NaN) is not NaN");

tmp = Math.cos(Infinity);
ok(isNaN(tmp), "Math.cos(Infinity) is not NaN");

tmp = Math.cos(-Infinity);
ok(isNaN(tmp), "Math.cos(-Infinity) is not NaN");

tmp = Math.pow(2, 2);
ok(tmp === 4, "Math.pow(2, 2) = " + tmp);

tmp = Math.pow(4, 0.5);
ok(tmp === 2, "Math.pow(2, 2) = " + tmp);

tmp = Math.pow(2, 2, 3);
ok(tmp === 4, "Math.pow(2, 2, 3) = " + tmp);

tmp = Math.pow(2);
ok(isNaN(tmp), "Math.pow(2) is not NaN");

tmp = Math.pow();
ok(isNaN(tmp), "Math.pow() is not NaN");

tmp = Math.random();
ok(typeof(tmp) == "number", "typeof(tmp) = " + typeof(tmp));
ok(0 <= tmp && tmp <= 1, "Math.random() = " + tmp);

tmp = Math.random(100);
ok(typeof(tmp) == "number", "typeof(tmp) = " + typeof(tmp));
ok(0 <= tmp && tmp <= 1, "Math.random(100) = " + tmp);

tmp = Math.acos(0);
ok(Math.floor(tmp*100) === 157, "Math.acos(0) = " + tmp);

tmp = Math.acos(1);
ok(Math.floor(tmp*100) === 0, "Math.acos(1) = " + tmp);

tmp = Math.acos(-1);
ok(Math.floor(tmp*100) === 314, "Math.acos(-1) = " + tmp);

tmp = Math.acos(Math.PI/4, 2);
ok(Math.floor(tmp*100) === 66, "Math.acos(Math.PI/4, 2) = " + tmp);

tmp = Math.acos(true);
ok(Math.floor(tmp*100) === 0, "Math.acos(true) = " + tmp);

tmp = Math.acos(false);
ok(Math.floor(tmp*100) === 157, "Math.acos(false) = " + tmp);

tmp = Math.acos(1.1);
ok(isNaN(tmp), "Math.acos(1.1) is not NaN");

tmp = Math.acos();
ok(isNaN(tmp), "Math.acos() is not NaN");

tmp = Math.acos(NaN);
ok(isNaN(tmp), "Math.acos(NaN) is not NaN");

tmp = Math.acos(Infinity);
ok(isNaN(tmp), "Math.acos(Infinity) is not NaN");

tmp = Math.acos(-Infinity);
ok(isNaN(tmp), "Math.acos(-Infinity) is not NaN");

tmp = Math.asin(0);
ok(Math.floor(tmp*100) === 0, "Math.asin(0) = " + tmp);

tmp = Math.asin(1);
ok(Math.floor(tmp*100) === 157, "Math.asin(1) = " + tmp);

tmp = Math.asin(-1);
ok(Math.floor(tmp*100) === -158, "Math.asin(-1) = " + tmp);

tmp = Math.asin(Math.PI/4, 2);
ok(Math.floor(tmp*100) === 90, "Math.asin(Math.PI/4, 2) = " + tmp);

tmp = Math.asin(true);
ok(Math.floor(tmp*100) === 157, "Math.asin(true) = " + tmp);

tmp = Math.asin(false);
ok(Math.floor(tmp*100) === 0, "Math.asin(false) = " + tmp);

tmp = Math.asin(1.1);
ok(isNaN(tmp), "Math.asin(1.1) is not NaN");

tmp = Math.asin();
ok(isNaN(tmp), "Math.asin() is not NaN");

tmp = Math.asin(NaN);
ok(isNaN(tmp), "Math.asin(NaN) is not NaN");

tmp = Math.asin(Infinity);
ok(isNaN(tmp), "Math.asin(Infinity) is not NaN");

tmp = Math.asin(-Infinity);
ok(isNaN(tmp), "Math.asin(-Infinity) is not NaN");

tmp = Math.atan(0);
ok(Math.floor(tmp*100) === 0, "Math.atan(0) = " + tmp);

tmp = Math.atan(1);
ok(Math.floor(tmp*100) === 78, "Math.atan(1) = " + tmp);

tmp = Math.atan(-1);
ok(Math.floor(tmp*100) === -79, "Math.atan(-1) = " + tmp);

tmp = Math.atan(true);
ok(Math.floor(tmp*100) === 78, "Math.atan(true) = " + tmp);

tmp = Math.atan(false);
ok(Math.floor(tmp*100) === 0, "Math.atan(false) = " + tmp);

tmp = Math.atan();
ok(isNaN(tmp), "Math.atan() is not NaN");

tmp = Math.atan(NaN);
ok(isNaN(tmp), "Math.atan(NaN) is not NaN");

tmp = Math.atan(Infinity);
ok(Math.floor(tmp*100) === 157, "Math.atan(Infinity) = " + tmp);

tmp = Math.atan(-Infinity);
ok(Math.floor(tmp*100) === -158, "Math.atan(Infinity) = " + tmp);

tmp = Math.atan2(0, 0);
ok(Math.floor(tmp*100) === 0, "Math.atan2(0, 0) = " + tmp);

tmp = Math.atan2(0, 1);
ok(Math.floor(tmp*100) === 0, "Math.atan2(0, 1) = " + tmp);

tmp = Math.atan2(0, Infinity);
ok(Math.floor(tmp*100) === 0, "Math.atan2(0, Infinity) = " + tmp);

tmp = Math.atan2(0, -1);
ok(Math.floor(tmp*100) === 314, "Math.atan2(0, -1) = " + tmp);

tmp = Math.atan2(0, -Infinity);
ok(Math.floor(tmp*100) === 314, "Math.atan2(0, -Infinity) = " + tmp);

tmp = Math.atan2(1, 0);
ok(Math.floor(tmp*100) === 157, "Math.atan2(1, 0) = " + tmp);

tmp = Math.atan2(Infinity, 0);
ok(Math.floor(tmp*100) === 157, "Math.atan2(Infinity, 0) = " + tmp);

tmp = Math.atan2(-1, 0);
ok(Math.floor(tmp*100) === -158, "Math.atan2(-1, 0) = " + tmp);

tmp = Math.atan2(-Infinity, 0);
ok(Math.floor(tmp*100) === -158, "Math.atan2(-Infinity, 0) = " + tmp);

tmp = Math.atan2(1, 1);
ok(Math.floor(tmp*100) === 78, "Math.atan2(1, 1) = " + tmp);

tmp = Math.atan2(-1, -1);
ok(Math.floor(tmp*100) === -236, "Math.atan2(-1, -1) = " + tmp);

tmp = Math.atan2(-1, 1);
ok(Math.floor(tmp*100) === -79, "Math.atan2(-1, 1) = " + tmp);

tmp = Math.atan2(Infinity, Infinity);
ok(Math.floor(tmp*100) === 78, "Math.atan2(Infinity, Infinity) = " + tmp);

tmp = Math.atan2(Infinity, -Infinity, 1);
ok(Math.floor(tmp*100) === 235, "Math.atan2(Infinity, -Infinity, 1) = " + tmp);

tmp = Math.atan2();
ok(isNaN(tmp), "Math.atan2() is not NaN");

tmp = Math.atan2(1);
ok(isNaN(tmp), "Math.atan2(1) is not NaN");

tmp = Math.exp(0);
ok(tmp === 1, "Math.exp(0) = " + tmp);

tmp = Math.exp(1);
ok(Math.floor(tmp*100) === 271, "Math.exp(1) = " + tmp);

tmp = Math.exp(-1);
ok(Math.floor(tmp*100) === 36, "Math.exp(-1) = " + tmp);

tmp = Math.exp(true);
ok(Math.floor(tmp*100) === 271, "Math.exp(true) = " + tmp);

tmp = Math.exp(1, 1);
ok(Math.floor(tmp*100) === 271, "Math.exp(1, 1) = " + tmp);

tmp = Math.exp();
ok(isNaN(tmp), "Math.exp() is not NaN");

tmp = Math.exp(NaN);
ok(isNaN(tmp), "Math.exp(NaN) is not NaN");

tmp = Math.exp(Infinity);
ok(tmp === Infinity, "Math.exp(Infinity) = " + tmp);

tmp = Math.exp(-Infinity);
ok(tmp === 0, "Math.exp(-Infinity) = " + tmp);

tmp = Math.log(1);
ok(Math.floor(tmp*100) === 0, "Math.log(1) = " + tmp);

tmp = Math.log(-1);
ok(isNaN(tmp), "Math.log(-1) is not NaN");

tmp = Math.log(true);
ok(Math.floor(tmp*100) === 0, "Math.log(true) = " + tmp);

tmp = Math.log(1, 1);
ok(Math.floor(tmp*100) === 0, "Math.log(1, 1) = " + tmp);

tmp = Math.log();
ok(isNaN(tmp), "Math.log() is not NaN");

tmp = Math.log(NaN);
ok(isNaN(tmp), "Math.log(NaN) is not NaN");

tmp = Math.log(Infinity);
ok(tmp === Infinity, "Math.log(Infinity) = " + tmp);

tmp = Math.log(-Infinity);
ok(isNaN(tmp), "Math.log(-Infinity) is not NaN");

tmp = Math.sin(0);
ok(tmp === 0, "Math.sin(0) = " + tmp);

tmp = Math.sin(Math.PI/2);
ok(tmp === 1, "Math.sin(Math.PI/2) = " + tmp);

tmp = Math.sin(-Math.PI/2);
ok(tmp === -1, "Math.sin(-Math.PI/2) = " + tmp);

tmp = Math.sin(Math.PI/3, 2);
ok(Math.floor(tmp*100) === 86, "Math.sin(Math.PI/3, 2) = " + tmp);

tmp = Math.sin(true);
ok(Math.floor(tmp*100) === 84, "Math.sin(true) = " + tmp);

tmp = Math.sin(false);
ok(tmp === 0, "Math.sin(false) = " + tmp);

tmp = Math.sin();
ok(isNaN(tmp), "Math.sin() is not NaN");

tmp = Math.sin(NaN);
ok(isNaN(tmp), "Math.sin(NaN) is not NaN");

tmp = Math.sin(Infinity);
ok(isNaN(tmp), "Math.sin(Infinity) is not NaN");

tmp = Math.sin(-Infinity);
ok(isNaN(tmp), "Math.sin(-Infinity) is not NaN");

tmp = Math.sqrt(0);
ok(tmp === 0, "Math.sqrt(0) = " + tmp);

tmp = Math.sqrt(4);
ok(tmp === 2, "Math.sqrt(4) = " + tmp);

tmp = Math.sqrt(-1);
ok(isNaN(tmp), "Math.sqrt(-1) is not NaN");

tmp = Math.sqrt(2, 2);
ok(Math.floor(tmp*100) === 141, "Math.sqrt(2, 2) = " + tmp);

tmp = Math.sqrt(true);
ok(tmp === 1, "Math.sqrt(true) = " + tmp);

tmp = Math.sqrt(false);
ok(tmp === 0, "Math.sqrt(false) = " + tmp);

tmp = Math.sqrt();
ok(isNaN(tmp), "Math.sqrt() is not NaN");

tmp = Math.sqrt(NaN);
ok(isNaN(tmp), "Math.sqrt(NaN) is not NaN");

tmp = Math.sqrt(Infinity);
ok(tmp === Infinity, "Math.sqrt(Infinity) = " + tmp);

tmp = Math.sqrt(-Infinity);
ok(isNaN(tmp), "Math.sqrt(-Infinity) is not NaN");

tmp = Math.tan(0);
ok(tmp === 0, "Math.tan(0) = " + tmp);

tmp = Math.tan(Math.PI);
ok(Math.floor(tmp*100) === -1, "Math.tan(Math.PI) = " + tmp);

tmp = Math.tan(2, 2);
ok(Math.floor(tmp*100) === -219, "Math.tan(2, 2) = " + tmp);

tmp = Math.tan(true);
ok(Math.floor(tmp*100) === 155, "Math.tan(true) = " + tmp);

tmp = Math.tan(false);
ok(tmp === 0, "Math.tan(false) = " + tmp);

tmp = Math.tan();
ok(isNaN(tmp), "Math.tan() is not NaN");

tmp = Math.tan(NaN);
ok(isNaN(tmp), "Math.tan(NaN) is not NaN");

tmp = Math.tan(Infinity);
ok(isNaN(tmp), "Math.tan(Infinity) is not NaN");

tmp = Math.tan(-Infinity);
ok(isNaN(tmp), "Math.tan(-Infinity) is not NaN");

(function() {
    if(invokeVersion < 2)
        return;

    var stringify_tests = [
        [[], undefined],
        [[true], "true"],
        [[false], "false"],
        [[null], "null"],
        [[nullDisp], undefined],
        [[1], "1"],
        [["test"], "\"test\""],
        [["test\"\\\b\f\n\r\t\u0002 !"], "\"test\\\"\\\\\\b\\f\\n\\r\\t\\u0002 !\""],
        [[NaN], "null"],
        [[Infinity], "null"],
        [[-Infinity], "null"],
        [[{prop1: true, prop2: "string", func1: function() {}}], "{\"prop1\":true,\"prop2\":\"string\"}"],
        [[{prop1: true, prop2: testObj, prop3: undefined}], "{\"prop1\":true}"],
        [[{prop1: true, prop2: {prop: "string"}},undefined,"  "],
                "{\n  \"prop1\": true,\n  \"prop2\": {\n    \"prop\": \"string\"\n  }\n}"],
        [[{ },undefined," "], "{}"],
        [[[,2,undefined,3,{ },]],"[null,2,null,3,{},null]"],
        [[[,2,undefined,3,{prop:0},],undefined,"  "],"[\n  null,\n  2,\n  null,\n  3,\n  {\n    \"prop\": 0\n  },\n  null\n]"]
    ];

    var i, s, v, t;

    for(i=0; i < stringify_tests.length; i++) {
        s = JSON.stringify.apply(null, stringify_tests[i][0]);
        ok(s === stringify_tests[i][1],
           "["+i+"] stringify(" + stringify_tests[i][0] + ") returned " + s + " expected " + stringify_tests[i][1]);
    }

    s = JSON.stringify();
    ok(s === undefined, "stringify() returned " + s + " expected undefined");

    s = JSON.stringify(testObj);
    ok(s === undefined || s === "undefined" /* broken on some old versions */,
       "stringify(testObj) returned " + s + " expected undefined");

    s = JSON.stringify(undefined);
    ok(s === undefined || s === "undefined" /* broken on some old versions */,
       "stringify(undefined) returned " + s + " expected undefined");

    s = JSON.stringify(1, function(name, value) {
        ok(name === "", "name = " + name);
        ok(value === 1, "value = " + value);
        ok(this[name] === value, "this[" + name + "] = " + this[name] + " expected " + value);
        return 2;
    });
    ok(s == "2", "s = " + s);

    var o = { prop: 1 };
        s = JSON.stringify(1, function(name, value) {
        ok(name === "" || name === "prop", "name = " + name);
        ok(value === 1 || value === true, "value = " + value);
        ok(this[name] === value, "this[" + name + "] = " + this[name] + " expected " + value);
        if(name === "") return o;
        ok(this === o, "this != o");
        return value;
    });
    ok(s == "{\"prop\":1}", "s = " + s);

    var parse_tests = [
        ["true", true],
        ["   \nnull  ", null],
        ["{}", {}],
        ["\"\\r\\n test\\u1111\\/\\x20\\45\\'\"", "\r\n test\u1111/ %'"],
        ["{\"x\" :\n true}", {x:true}],
        ["{\"x y\": {}, \"z\": {\"x\":null}}", {"x y":{}, z:{x:null}}],
        ["[]", []],
        ["[false,{},{\"x\": []}]", [false,{},{x:[]}]],
        ["0", 0],
        ["- 1", -1],
        ["1e2147483648", Infinity],
        ["0.5", 0.5],
        ["0e5", 0],
        [".5", 0.5]
    ];

    function json_cmp(x, y) {
        if(x === y)
            return true;

        if(!(x instanceof Object) || !(y instanceof Object))
            return false;

        for(var prop in x) {
            if(!x.hasOwnProperty(prop))
                continue;
            if(!y.hasOwnProperty(prop))
                return false;
            if(!json_cmp(x[prop], y[prop]))
                return false;
        }

        for(var prop in y) {
            if(!x.hasOwnProperty(prop) && y.hasOwnProperty(prop))
                return false;
        }

        return true;
    }

    for(i=0; i < parse_tests.length; i++) {
        v = JSON.parse(parse_tests[i][0]);
        ok(json_cmp(v, parse_tests[i][1]), "parse[" + i + "] returned " + v + ", expected " + parse_tests[i][1]);
    }

    v = [ [-1, "b"], {"length": -2, "0": -4, "1": -5}, [{}], [{"x": [null]}] ];
    s =
    '{' +
        '"foo": true,' +
        '"bar": [],' +
        '"baz": "remove_me",' +
        '"obj": {' +
        '    "arr": [ [1, "b"], {"length": 2, "0": 4, "1": 5}, [{}], [{"x": [null]}] ],' +
        '    "": "empty"' +
        '},' +
        '"last": false' +
    '}';
    o = JSON.parse(s), t = JSON.parse(s), i = new Object();
    i[""] = t;
    delete t.baz;   /* baz gets removed */
    t.obj.arr = v;  /* has negative values */

    var walk_expect = [
        [ o, "foo", true ],
        [ o, "bar", [] ],
        [ o, "baz", "remove_me" ],
        [ [1, "b"], "0", 1 ],
        [ [-1, "b"], "1", "b" ],
        [ [ [-1, "b"], {"length": 2, "0": 4, "1": 5}, [{}], [{"x": [null]}] ], "0", [-1, "b"] ],
        [ {"length": 2, "0": 4, "1": 5}, "length", 2 ],
        [ {"length": -2, "0": 4, "1": 5}, "0", 4 ],
        [ {"length": -2, "0": -4, "1": 5}, "1", 5 ],
        [ v, "1", {"length": -2, "0": -4, "1": -5} ],
        [ [{}], "0", {} ],
        [ v, "2", [{}] ],
        [ [null], "0", null ],
        [ {"x": [null]}, "x", [null] ],
        [ [{"x": [null]}], "0", {"x": [null]} ],
        [ v, "3", [{"x": [null]}] ],
        [ { "arr": v, "": "empty" }, "arr", v ],
        [ { "arr": v, "": "empty" }, "", "empty" ],
        [ t, "obj", { "arr": v, "": "empty" } ],
        [ t, "last", false ],
        [ i, "", t ]
    ];
    i = 0;
    v = JSON.parse(s, function(prop, value) {
        var a = [this, prop, value];
        ok(json_cmp(a, walk_expect[i]), "[walk step " + i + "] got [" + a + "], expected [" + walk_expect[i] + "]");
        i++;
        return (typeof value === 'number') ? -value : (value === "remove_me" ? undefined : value);
    });
    ok(i === walk_expect.length, "parse with reviver walked " + i + " steps, expected " + walk_expect.length);
    ok(json_cmp(v, t), "parse with reviver returned wrong object");

    v = JSON.parse('true', function(prop, value) { return prop === "" ? undefined : value; });
    ok(v === undefined, "parse with reviver removing last prop returned " + v);
    v = JSON.parse('true', function(prop, value) { return prop === "" ? false : value; });
    ok(v === false, "parse with reviver setting last prop to false returned " + v);
})();

var func = function  (a) {
        var a = 1;
        if(a) return;
    };
ok(func.toString() === "function  (a) {\n        var a = 1;\n        if(a) return;\n    }",
   "func.toString() = " + func.toString());
ok("" + func === "function  (a) {\n        var a = 1;\n        if(a) return;\n    }",
   "'' + func.toString() = " + func);

ok(func.valueOf === Object.prototype.valueOf, "func.valueOf !== Object.prototype.valueOf");
ok(func === func.valueOf(), "func !== func.valueOf()");

function testFuncToString(x,y) {
    return x+y;
}
ok(testFuncToString.toString() === "function testFuncToString(x,y) {\n    return x+y;\n}",
   "testFuncToString.toString() = " + testFuncToString.toString());
ok("" + testFuncToString === "function testFuncToString(x,y) {\n    return x+y;\n}",
   "'' + testFuncToString = " + testFuncToString);

tmp = new Object();

function callTest(argc) {
    ok(this === tmp, "this !== tmp\n");
    ok(arguments.length === argc+1, "arguments.length = " + arguments.length + " expected " + (argc+1));
    for(var i=1; i <= argc; i++)
        ok(arguments[i] === i, "arguments[i] = " + arguments[i]);
    var a = arguments;
    for(var i=1; i <= argc; i++)
        ok(a[i] === i, "a[i] = " + a[i]);
}

callTest.call(tmp, 1, 1);
callTest.call(tmp, 2, 1, 2);
callTest.call(tmp, 3, 1, 2, 3);

callTest.apply(tmp, [1, 1]);
callTest.apply(tmp, [2, 1, 2]);
callTest.apply(tmp, [3, 1, 2, 3]);
(function () { callTest.apply(tmp, arguments); })(2,1,2);

function callTest2() {
    ok(this === tmp, "this !== tmp\n");
    ok(arguments.length === 0, "callTest2: arguments.length = " + arguments.length + " expected 0");
}

callTest2.call(tmp);
callTest2.apply(tmp, []);
callTest2.apply(tmp);
(function () { callTest2.apply(tmp, arguments); })();

function callTest3() {
    testThis(this);
    ok(arguments.length === 0, "arguments.length = " + arguments.length + " expected 0");
}

callTest3.call();
callTest3.call(undefined);
callTest3.call(null);
callTest3.apply();
callTest3.apply(undefined);
callTest3.apply(null);

tmp = Number.prototype.toString.call(3);
ok(tmp === "3", "Number.prototype.toString.call(3) = " + tmp);

var func = new Function("return 3;");

tmp = func();
ok(tmp === 3, "func() = " + tmp);
ok(func.call() === 3, "func.call() = " + tmp);
ok(func.length === 0, "func.length = " + func.length);
tmp = func.toString();
ok(tmp === "function anonymous() {\nreturn 3;\n}", "func.toString() = " + tmp);

func = new Function("x", "return x+2;");
tmp = func(1);
ok(tmp === 3, "func(1) = " + tmp);
tmp = func.toString();
ok(tmp === "function anonymous(x) {\nreturn x+2;\n}", "func.toString() = " + tmp);

tmp = (new Function("x ", "return x+2;")).toString();
ok(tmp === "function anonymous(x ) {\nreturn x+2;\n}", "func.toString() = " + tmp);

func = new Function("x", "y", "return x+y");
tmp = func(1,3);
ok(tmp === 4, "func(1,3) = " + tmp);
tmp = func.toString();
ok(tmp === "function anonymous(x, y) {\nreturn x+y\n}", "func.toString() = " + tmp);

func = new Function(" x, \ty", "\tz", "return x+y+z;");
tmp = func(1,3,2);
ok(tmp === 6, "func(1,3,2) = " + tmp);
ok(func.length === 3, "func.length = " + func.length);
tmp = func.toString();
ok(tmp === "function anonymous( x, \ty, \tz) {\nreturn x+y+z;\n}", "func.toString() = " + tmp);

func = new Function();
tmp = func();
ok(tmp === undefined, "func() = " + tmp);
tmp = func.toString();
ok(tmp == "function anonymous() {\n\n}", "func.toString() = " + tmp);

// Function constructor called as function
func = Function("return 3;");

tmp = func();
ok(tmp === 3, "func() = " + tmp);
ok(func.call() === 3, "func.call() = " + tmp);
ok(func.length === 0, "func.length = " + func.length);
tmp = func.toString();
ok(tmp === "function anonymous() {\nreturn 3;\n}", "func.toString() = " + tmp);

func = (function() {
        var tmp = 3;
        return new Function("return tmp;");
    })();
tmp = 2;
tmp = func();
ok(tmp === 2, "func() = " + tmp);

var date = new Date();

date = new Date(100);
ok(date.getTime() === 100, "date.getTime() = " + date.getTime());
ok(Date.prototype.getTime() === 0, "date.prototype.getTime() = " + Date.prototype.getTime());
date = new Date(8.64e15);
ok(date.getTime() === 8.64e15, "date.getTime() = " + date.getTime());
date = new Date(8.64e15+1);
ok(isNaN(0+date.getTime()), "date.getTime() is not NaN");
date = new Date(Infinity);
ok(isNaN(0+date.getTime()), "date.getTime() is not NaN");
date = new Date("3 July 2009 22:28:00 UTC+0100");
ok(date.getTime() === 1246656480000, "date.getTime() = " + date.getTime());
date = new Date(1984, 11, 29, 13, 51, 24, 120);
ok(date.getFullYear() === 1984, "date.getFullYear() = " + date.getFullYear());
ok(date.getMonth() === 11, "date.getMonth() = " + date.getMonth());
ok(date.getDate() === 29, "date.getDate() = " + date.getDate());
ok(date.getHours() === 13, "date.getHours() = " + date.getHours());
ok(date.getMinutes() === 51, "date.getMinutes() = " + date.getMinutes());
ok(date.getSeconds() === 24, "date.getSeconds() = " + date.getSeconds());
ok(date.getMilliseconds() === 120, "date.getMilliseconds() = " + date.getMilliseconds());
date = new Date(731, -32, 40, -1, 70, 65, -13);
ok(date.getFullYear() === 728, "date.getFullYear() = " + date.getFullYear());
ok(date.getMonth() === 5, "date.getMonth() = " + date.getMonth());
ok(date.getDate() === 9, "date.getDate() = " + date.getDate());
ok(date.getHours() === 0, "date.getHours() = " + date.getHours());
ok(date.getMinutes() === 11, "date.getMinutes() = " + date.getMinutes());
ok(date.getSeconds() === 4, "date.getSeconds() = " + date.getSeconds());
ok(date.getMilliseconds() === 987, "date.getMilliseconds() = " + date.getMilliseconds());

ok(date.setTime(123) === 123, "date.setTime(123) !== 123");
ok(date.setTime("123", NaN) === 123, "date.setTime(\"123\") !== 123");
ok(isNaN(date.setTime(NaN)), "date.setTime(NaN) is not NaN");

ok(date.setTime(0) === date.getTime(), "date.setTime(0) !== date.getTime()");
ok(date.getUTCFullYear() === 1970, "date.getUTCFullYear() = " + date.getUTCFullYear());
ok(date.getUTCMonth() === 0, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCDate() === 1, "date.getUTCDate() = " + date.getUTCDate());
ok(date.getUTCDay() === 4, "date.getUTCDay() = " + date.getUTCDay());
ok(date.getUTCHours() === 0, "date.getUTCHours() = " + date.getUTCHours());
ok(date.getUTCMinutes() === 0, "date.getUTCMinutes() = " + date.getUTCMinutes());
ok(date.getUTCSeconds() === 0, "date.getUTCSeconds() = " + date.getUTCSeconds());
ok(date.getUTCMilliseconds() === 0, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());

date.setTime(60*24*60*60*1000);
ok(date.getUTCFullYear() === 1970, "date.getUTCFullYear() = " + date.getUTCFullYear());
ok(date.getUTCMonth() === 2, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCDate() === 2, "date.getUTCDate() = " + date.getUTCDate());
ok(date.getUTCDay() === 1, "date.getUTCDay() = " + date.getUTCDay());
ok(date.getUTCHours() === 0, "date.getUTCHours() = " + date.getUTCHours());
ok(date.getUTCMinutes() === 0, "date.getUTCMinutes() = " + date.getUTCMinutes());
ok(date.getUTCSeconds() === 0, "date.getUTCSeconds() = " + date.getUTCSeconds());
ok(date.getUTCMilliseconds() === 0, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());

date.setTime(59*24*60*60*1000 + 4*365*24*60*60*1000 + 60*60*1000 + 2*60*1000 + 2*1000 + 640);
ok(date.getUTCFullYear() === 1974, "date.getUTCFullYear() = " + date.getUTCFullYear());
ok(date.getUTCMonth() === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCMonth(123) === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCDate() === 28, "date.getUTCDate() = " + date.getUTCDate());
ok(date.getUTCDay() === 4, "date.getUTCDay() = " + date.getUTCDay());
ok(date.getUTCHours() === 1, "date.getUTCHours() = " + date.getUTCHours());
ok(date.getUTCMinutes() === 2, "date.getUTCMinutes() = " + date.getUTCMinutes());
ok(date.getUTCSeconds() === 2, "date.getUTCSeconds() = " + date.getUTCSeconds());
ok(date.getUTCMilliseconds() === 640, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());

tmp = date.setYear(96);
ok(date.getYear() === 96, "date.getYear() = " + date.getYear());
ok(date.getFullYear() === 1996, "date.getFullYear() = " + date.getYear());
ok(date.getUTCMonth() === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCMonth(123) === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCMilliseconds() === 640, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());

tmp = date.setYear(2010);
ok(tmp === date.getTime(), "date.setYear(2010) = " + tmp);
ok(date.getYear() === 2010, "date.getYear() = " + date.getYear());
ok(date.getFullYear() === 2010, "date.getFullYear() = " + date.getYear());
ok(date.getUTCMonth() === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCMonth(123) === 1, "date.getUTCMonth() = " + date.getUTCMonth());
ok(date.getUTCMilliseconds() === 640, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());

date.setTime(Infinity);
ok(isNaN(date.getUTCFullYear()), "date.getUTCFullYear() is not NaN");
ok(isNaN(date.getUTCMonth()), "date.getUTCMonth() is not NaN");
ok(isNaN(date.getUTCDate()), "date.getUTCDate() is not NaN");
ok(isNaN(date.getUTCDay()), "date.getUTCDay() is not NaN");
ok(isNaN(date.getUTCHours()), "date.getUTCHours() is not NaN");
ok(isNaN(date.getUTCMinutes()), "date.getUTCMinutes() is not NaN");
ok(isNaN(date.getUTCSeconds()), "date.getUTCSeconds() is not NaN");
ok(isNaN(date.getUTCMilliseconds()), "date.getUTCMilliseconds() is not NaN");
ok(isNaN(date.setMilliseconds(0)), "date.setMilliseconds() is not NaN");

date.setTime(0);
tmp = date.setYear(NaN);
ok(isNaN(tmp), "date.setYear(NaN) = " + tmp);
ok(isNaN(date.getUTCFullYear()), "date.getUTCFullYear() is not NaN");
ok(isNaN(date.getUTCMonth()), "date.getUTCMonth() is not NaN");

date.setTime(0);
date.setUTCMilliseconds(-10, 2);
ok(date.getUTCMilliseconds() === 990, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());
date.setUTCMilliseconds(10);
ok(date.getUTCMilliseconds() === 10, "date.getUTCMilliseconds() = " + date.getUTCMilliseconds());
date.setUTCSeconds(-10);
ok(date.getUTCSeconds() === 50, "date.getUTCSeconds() = " + date.getUTCSeconds());
date.setUTCMinutes(-10);
ok(date.getUTCMinutes() === 50, "date.getUTCMinutes() = " + date.getUTCMinutes());
date.setUTCHours(-10);
ok(date.getUTCHours() === 14, "date.getUTCHours() = " + date.getUTCHours());
date.setUTCHours(-123);
ok(date.getTime() === -612549990, "date.getTime() = " + date.getTime());
date.setUTCHours(20);
ok(date.getUTCHours() === 20, "date.getUTCHours() = " + date.getUTCHours());
date.setUTCDate(32);
ok(date.getUTCDate() === 1, "date.getUTCDate() = " + date.getUTCDate());
date.setUTCMonth(22, 37);
ok(date.getTime() === 60987050010, "date.getTime() = " + date.getTime());
date.setUTCFullYear(83, 21, 321);
ok(date.getTime() === -59464984149990, "date.getTime() = " + date.getTime());
ok(Math.abs(date) === 59464984149990, "Math.abs(date) = " + Math.abs(date));
ok(getVT(date+1) === "VT_BSTR", "getVT(date+1) = " + getVT(date+1));

ok(isNaN(Date.parse()), "Date.parse() is not NaN");
ok(isNaN(Date.parse("")), "Date.parse(\"\") is not NaN");
ok(isNaN(Date.parse("Jan Jan 20 2009")), "Date.parse(\"Jan Jan 20 2009\") is not NaN");
ok(Date.parse("Jan 20 2009 UTC") === 1232409600000, "Date.parse(\"Jan 20 2009 UTC\") = " + Date.parse("Jan 20 2009 UTC"));
ok(Date.parse("Jan 20 2009 GMT") === 1232409600000, "Date.parse(\"Jan 20 2009 GMT\") = " + Date.parse("Jan 20 2009 GMT"));
ok(Date.parse("Jan 20 2009 UTC-0") === 1232409600000, "Date.parse(\"Jan 20 2009 UTC-0\") = " + Date.parse("Jan 20 2009 UTC-0"));
ok(Date.parse("Jan 20 2009 UTC+0000") === 1232409600000, "Date.parse(\"Jan 20 2009 UTC+0000\") = " + Date.parse("Jan 20 2009 UTC+0000"));
ok(Date.parse("Jan 20 2009 UTC-1") === 1232413200000, "Date.parse(\"Jan 20 2009 UTC-1\") = " + Date.parse("Jan 20 2009 UTC-1"));
ok(Date.parse("Jan 20 2009 UTC+1") === 1232406000000, "Date.parse(\"Jan 20 2009 UTC+1\") = " + Date.parse("Jan 20 2009 UTC+1"));
ok(Date.parse("Ju 13 79 UTC") === 300672000000, "Date.parse(\"Ju 13 79 UTC\") = " + Date.parse("Ju 13 79 UTC"));
ok(Date.parse("12Au91 UTC") === 681955200000, "Date.parse(\"12Au91 UTC\") = " + Date.parse("12Au91 UTC"));
ok(Date.parse("7/02/17 UTC") === -1656806400000, "Date.parse(\"7/02/17 UTC\") = " + Date.parse("7/02/17 UTC"));
ok(Date.parse("Se001   70 12:31:17 UTC") === 21040277000, "Date.parse(\"Se001   70 12:31:17 UTC\") = " + Date.parse("Se001   70 12:31:17 UTC"));
ok(Date.parse("February 31   UTC, 2000 12:31:17 PM") === 952000277000,
        "Date.parse(\"February 31   UTC, 2000 12:31:17 PM\") = " + Date.parse("February 31   UTC, 2000 12:31:17 PM"));
ok(Date.parse("71 11:32AM Dec 12 UTC BC ") === -64346358480000, "Date.parse(\"71 11:32AM Dec 12 UTC BC \") = " + Date.parse("71 11:32AM Dec 12 UTC BC "));
ok(Date.parse("23/71/2000 11::32::UTC") === 1010662320000, "Date.parse(\"23/71/2000 11::32::UTC\") = " + Date.parse("23/71/2000 11::32::UTC"));
ok(Date.parse("1970/01/01") === Date.parse("01/01/1970"), "Date.parse(\"1970/01/01\") = " + Date.parse("1970/01/01"));
ok(Date.parse("71/12/14") === Date.parse("12/14/1971"), "Date.parse(\"71/12/14\") = " + Date.parse("71/12/14"));
ok(Date.parse("Tue, 22 Mar 2016 09:57:55 -0300") === Date.parse("Tue, 22 Mar 2016 09:57:55 GMT-0300"),
        "Date.parse(\"Tue, 22 Mar 2016 09:57:55 -0300\") = " + Date.parse("Tue, 22 Mar 2016 09:57:55 -0300"));
ok(Date.parse("Tue, 22 Mar 2016 09:57:55 +0400") === Date.parse("Tue, 22 Mar 2016 09:57:55 UTC+0400"),
        "Date.parse(\"Tue, 22 Mar 2016 09:57:55 +0400\") = " + Date.parse("Tue, 22 Mar 2016 09:57:55 +0400"));

tmp = (new Date()).toGMTString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date()).toLocaleDateString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date(1600, 1, 1, 0, 0, 0, 0)).toLocaleDateString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date(1600, 1, 1, 0, 0, 0, 0)).toLocaleString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date()).toLocaleTimeString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date()).toString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date()).toTimeString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");
tmp = (new Date()).toUTCString();
ok(tmp.indexOf(String.fromCharCode(0)) == -1, "invalid null byte");

ok(typeof(Math.PI) === "number", "typeof(Math.PI) = " + typeof(Math.PI));
ok(Math.floor(Math.PI*100) === 314, "Math.PI = " + Math.PI);
Math.PI = "test";
ok(Math.floor(Math.PI*100) === 314, "modified Math.PI = " + Math.PI);

ok(typeof(Math.E) === "number", "typeof(Math.E) = " + typeof(Math.E));
ok(Math.floor(Math.E*100) === 271, "Math.E = " + Math.E);
Math.E = "test";
ok(Math.floor(Math.E*100) === 271, "modified Math.E = " + Math.E);

ok(typeof(Math.LOG2E) === "number", "typeof(Math.LOG2E) = " + typeof(Math.LOG2E));
ok(Math.floor(Math.LOG2E*100) === 144, "Math.LOG2E = " + Math.LOG2E);
Math.LOG2E = "test";
ok(Math.floor(Math.LOG2E*100) === 144, "modified Math.LOG2E = " + Math.LOG2E);

ok(typeof(Math.LOG10E) === "number", "typeof(Math.LOG10E) = " + typeof(Math.LOG10E));
ok(Math.floor(Math.LOG10E*100) === 43, "Math.LOG10E = " + Math.LOG10E);
Math.LOG10E = "test";
ok(Math.floor(Math.LOG10E*100) === 43, "modified Math.LOG10E = " + Math.LOG10E);

ok(typeof(Math.LN2) === "number", "typeof(Math.LN2) = " + typeof(Math.LN2));
ok(Math.floor(Math.LN2*100) === 69, "Math.LN2 = " + Math.LN2);
Math.LN2 = "test";
ok(Math.floor(Math.LN2*100) === 69, "modified Math.LN2 = " + Math.LN2);

ok(typeof(Math.LN10) === "number", "typeof(Math.LN10) = " + typeof(Math.LN10));
ok(Math.floor(Math.LN10*100) === 230, "Math.LN10 = " + Math.LN10);
Math.LN10 = "test";
ok(Math.floor(Math.LN10*100) === 230, "modified Math.LN10 = " + Math.LN10);

ok(typeof(Math.SQRT2) === "number", "typeof(Math.SQRT2) = " + typeof(Math.SQRT2));
ok(Math.floor(Math.SQRT2*100) === 141, "Math.SQRT2 = " + Math.SQRT2);
Math.SQRT2 = "test";
ok(Math.floor(Math.SQRT2*100) === 141, "modified Math.SQRT2 = " + Math.SQRT2);

ok(typeof(Math.SQRT1_2) === "number", "typeof(Math.SQRT1_2) = " + typeof(Math.SQRT1_2));
ok(Math.floor(Math.SQRT1_2*100) === 70, "Math.SQRT1_2 = " + Math.SQRT1_2);
Math.SQRT1_2 = "test";
ok(Math.floor(Math.SQRT1_2*100) === 70, "modified Math.SQRT1_2 = " + Math.SQRT1_2);

ok(isNaN.toString() === "\nfunction isNaN() {\n    [native code]\n}\n",
   "isNaN.toString = '" + isNaN.toString() + "'");
ok(Array.toString() === "\nfunction Array() {\n    [native code]\n}\n",
   "Array.toString = '" + Array.toString() + "'");
ok(Function.toString() === "\nfunction Function() {\n    [native code]\n}\n",
   "Function.toString = '" + Function.toString() + "'");
ok(Function.prototype.toString() === "\nfunction prototype() {\n    [native code]\n}\n",
   "Function.prototype.toString = '" + Function.prototype.toString() + "'");
ok("".substr.toString() === "\nfunction substr() {\n    [native code]\n}\n",
   "''.substr.toString = '" + "".substr.toString() + "'");

var bool = new Boolean();
ok(bool.toString() === "false", "bool.toString() = " + bool.toString());
var bool = new Boolean("false");
ok(bool.toString() === "true", "bool.toString() = " + bool.toString());
ok(bool.valueOf() === Boolean(1), "bool.valueOf() = " + bool.valueOf());
ok(bool.toLocaleString() === bool.toString(), "bool.toLocaleString() = " + bool.toLocaleString());

tmp = Object.prototype.valueOf.call(nullDisp);
ok(tmp === nullDisp, "nullDisp.valueOf != nullDisp");

(function(global) {
    var i, context, code = "this.foobar = 1234";

    var direct = [
        function() { eval(code); },
        function() { (eval)(code); },
        function() { (function(eval) { eval(code); }).call(this, eval); },
        function() { eval("eval(" + code + ")"); }
    ];

    for(i = 0; i < direct.length; i++) {
        context = {};
        direct[i].call(context);
        ok(context.foobar === 1234, "direct[" + i + "] context foobar = " + context.foobar);
    }

    var indirect = [
        function() { (true, eval)(code); },
        function() { (eval, eval)(code); },
        function() { (true ? eval : false)(code); },
        function() { [eval][0](code); },
        function() { eval.call(this, code); },
        function() { var f; (f = eval)(code); },
        function() { var f = eval; f(code); },
        function() { (function(f) { f(code); }).call(this, eval); },
        function() { (function(f) { return f; }).call(this, eval)(code); },
        function() { (function() { arguments[0](code) }).call(this, eval); },
        function() { eval("eval")(code); }
    ];

    for(i = 0; i < indirect.length; i++) {
        context = {};
        ok(!("foobar" in global), "indirect[" + i + "] has global foobar before call");
        indirect[i].call(context);
        ok(context.foobar === 1234, "indirect[" + i + "] context foobar = " + context.foobar);
        ok(!("foobar" in global), "indirect[" + i + "] has global foobar");
    }

    context = {};
    (function(eval) { eval(code); })(function() { context.barfoo = 4321; });
    ok(context.barfoo === 4321, "context.barfoo = " + context.barfoo);
})(this);

ok(ActiveXObject instanceof Function, "ActiveXObject is not instance of Function");
ok(ActiveXObject.prototype instanceof Object, "ActiveXObject.prototype is not instance of Object");

ok(Error.prototype !== TypeError.prototype, "Error.prototype === TypeError.prototype");
ok(RangeError.prototype !== TypeError.prototype, "RangeError.prototype === TypeError.prototype");
ok(Error.prototype.toLocaleString === Object.prototype.toLocaleString,
        "Error.prototype.toLocaleString !== Object.prototype.toLocaleString");
err = new Error();
ok(err.valueOf === Object.prototype.valueOf, "err.valueOf !== Object.prototype.valueOf");
ok(Error.prototype.name === "Error", "Error.prototype.name = " + Error.prototype.name);
ok(err.name === "Error", "err.name = " + err.name);
EvalError.prototype.message = "test";
ok(EvalError.prototype.message === "test", "EvalError.prototype.message = " + EvalError.prototype.message);
ok(err.toString !== Object.prototype.toString, "err.toString === Object.prototype.toString");
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "Error"), "err.toString() = " + err.toString());
err = new EvalError();
ok(EvalError.prototype.name === "EvalError", "EvalError.prototype.name = " + EvalError.prototype.name);
ok(err.name === "EvalError", "err.name = " + err.name);
ok(err.toString === Error.prototype.toString, "err.toString !== Error.prototype.toString");
ok(err.message === "", "err.message != ''");
err.message = date;
ok(err.message === date, "err.message != date");
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "EvalError: "+err.message),
   "err.toString() = " + err.toString());
ok(err.toString !== Object.prototype.toString, "err.toString === Object.prototype.toString");
err = new RangeError();
ok(RangeError.prototype.name === "RangeError", "RangeError.prototype.name = " + RangeError.prototype.name);
ok(err.name === "RangeError", "err.name = " + err.name);
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "RangeError"), "err.toString() = " + err.toString());
err = new ReferenceError();
ok(ReferenceError.prototype.name === "ReferenceError", "ReferenceError.prototype.name = " + ReferenceError.prototype.name);
ok(err.name === "ReferenceError", "err.name = " + err.name);
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "ReferenceError"), "err.toString() = " + err.toString());
err = new SyntaxError();
ok(SyntaxError.prototype.name === "SyntaxError", "SyntaxError.prototype.name = " + SyntaxError.prototype.name);
ok(err.name === "SyntaxError", "err.name = " + err.name);
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "SyntaxError"), "err.toString() = " + err.toString());
err = new TypeError();
ok(TypeError.prototype.name === "TypeError", "TypeError.prototype.name = " + TypeError.prototype.name);
ok(err.name === "TypeError", "err.name = " + err.name);
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "TypeError"), "err.toString() = " + err.toString());
err = new URIError();
ok(URIError.prototype.name === "URIError", "URIError.prototype.name = " + URIError.prototype.name);
ok(err.name === "URIError", "err.name = " + err.name);
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "URIError"), "err.toString() = " + err.toString());
err = new Error("message");
ok(err.message === "message", "err.message !== 'message'");
ok(err.toString() === (invokeVersion < 2 ? "[object Error]" : "Error: message"), "err.toString() = " + err.toString());
err = new Error(123);
ok(err.number === 123, "err.number = " + err.number);
err.number = 254;
ok(err.number === 254, "err.number = " + err.number);
err = new Error(0, "message");
ok(err.number === 0, "err.number = " + err.number);
ok(err.message === "message", "err.message = " + err.message);
ok(err.description === "message", "err.description = " + err.description);
err = new Error();
ok(err.number === 0, "err.number = " + err.number);
ok(err.description === "", "err.description = " + err.description);
err.description = 5;
ok(err.description === 5, "err.description = " + err.description);
ok(err.message === "", "err.message = " + err.message);
err.message = 4;
ok(err.message === 4, "err.message = " + err.message);

ok(!("number" in Error), "number is in Error");

tmp = new Object();
ok(tmp.hasOwnProperty("toString") === false, "toString property should be inherited");
tmp.toString = function() { return "test"; };
ok(tmp.hasOwnProperty("toString") === true, "toString own property should exist");
ok(tmp.hasOwnProperty("nonExisting") === false, "nonExisting property should not exist");

tmp = Error.prototype.toString.call(tmp);
ok(tmp === "[object Error]", "Error.prototype.toString.call(tmp) = " + tmp);

tmp = function() { return 0; };
tmp[0] = true;
ok(tmp.hasOwnProperty("toString") === false, "toString property should be inherited");
ok(tmp.hasOwnProperty("0") === true, "hasOwnProperty(0) returned false");
ok(tmp.hasOwnProperty() === false, "hasOwnProperty() returned true");

ok(Object.prototype.hasOwnProperty.call(testObj) === false, "hasOwnProperty without name returned true");

if(invokeVersion >= 2) {
    obj = new Object();
    obj.name = "test";
    tmp = Error.prototype.toString.call(obj);
    ok(tmp === "test", "Error.prototype.toString.call(obj) = " + tmp);

    obj = new Object();
    obj.name = 6;
    obj.message = false;
    tmp = Error.prototype.toString.call(obj);
    ok(tmp === "6: false", "Error.prototype.toString.call(obj) = " + tmp);

    obj = new Object();
    obj.message = "test";
    tmp = Error.prototype.toString.call(obj);
    ok(tmp === "test", "Error.prototype.toString.call(obj) = " + tmp);

    obj = new Object();
    obj.name = "";
    obj.message = "test";
    tmp = Error.prototype.toString.call(obj);
    ok(tmp === "test", "Error.prototype.toString.call(obj) = " + tmp);
}

tmp = Error.prototype.toString.call(testObj);
ok(tmp === "[object Error]", "Error.prototype.toString.call(testObj) = " + tmp);

err = new Error();
err.name = null;
ok(err.name === null, "err.name = " + err.name + " expected null");
if(invokeVersion >= 2)
    ok(err.toString() === "null", "err.toString() = " + err.toString());

err = new Error();
err.message = false;
ok(err.message === false, "err.message = " + err.message + " expected false");
if(invokeVersion >= 2)
    ok(err.toString() === "Error: false", "err.toString() = " + err.toString());

err = new Error();
err.message = new Object();
err.message.toString = function() { return ""; };
if(invokeVersion >= 2)
    ok(err.toString() === "Error", "err.toString() = " + err.toString());

err = new Error();
err.message = undefined;
if(invokeVersion >= 2)
    ok(err.toString() === "Error", "err.toString() = " + err.toString());

var exception_array = {
    E_INVALID_LENGTH:  { type: "RangeError",  number: -2146823259 },

    E_NOT_DATE:            { type: "TypeError",   number: -2146823282 },
    E_NOT_BOOL:            { type: "TypeError",   number: -2146823278 },
    E_ARG_NOT_OPT:         { type: "TypeError",   number: -2146827839 },
    E_NO_PROPERTY:         { type: "TypeError",   number: -2146827850 },
    E_NOT_NUM:             { type: "TypeError",   number: -2146823287 },
    E_INVALID_CALL_ARG:    { type: "TypeError",   number: -2146828283 },
    E_NOT_FUNC:            { type: "TypeError",   number: -2146823286 },
    E_OBJECT_EXPECTED:     { type: "TypeError", number: -2146823281 },
    E_OBJECT_REQUIRED:     { type: "TypeError", number: -2146827864 },
    E_UNSUPPORTED_ACTION:  { type: "TypeError", number: -2146827843 },
    E_REGEXP_EXPECTED:     { type: "TypeError", number: -2146823272 },
    E_NOT_ENUMERATOR:      { type: "TypeError", number: -2146823273 },
    E_NOT_VBARRAY:         { type: "TypeError", number: -2146823275 },
    E_INVALID_DELETE:      { type: "TypeError", number: -2146823276 },
    E_UNDEFINED:           { type: "TypeError", number: -2146823279 },
    E_JSCRIPT_EXPECTED:    { type: "TypeError", number: -2146823274 },
    E_NOT_ARRAY:           { type: "TypeError", number: -2146823257 },

    E_SYNTAX_ERROR:      { type: "SyntaxError",  number: -2146827286 },
    E_LBRACKET:          { type: "SyntaxError",  number: -2146827283 },
    E_RBRACKET:          { type: "SyntaxError",  number: -2146827282 },
    E_SEMICOLON:         { type: "SyntaxError",  number: -2146827284 },
    E_UNTERMINATED_STR:  { type: "SyntaxError",  number: -2146827273 },
    E_DISABLED_CC:       { type: "SyntaxError",  number: -2146827258 },
    E_INVALID_BREAK:     { type: "SyntaxError",  number: -2146827269 },
    E_INVALID_CONTINUE:  { type: "SyntaxError",  number: -2146827268 },
    E_LABEL_NOT_FOUND:   { type: "SyntaxError",  number: -2146827262 },
    E_LABEL_REDEFINED:   { type: "SyntaxError",  number: -2146827263 },
    E_MISPLACED_RETURN:  { type: "SyntaxError",  number: -2146827270 },

    E_ILLEGAL_ASSIGN:  { type: "ReferenceError", number: -2146823280 },

    E_PRECISION_OUT_OF_RANGE:        {type: "RangeError", number: -2146823261 },
    E_FRACTION_DIGITS_OUT_OF_RANGE:  {type: "RangeError", number: -2146823262 },
    E_SUBSCRIPT_OUT_OF_RANGE:        {type: "RangeError", number: -2146828279 },

    E_REGEXP_SYNTAX_ERROR:  { type: "RegExpError", number: -2146823271 },

    E_URI_INVALID_CHAR:     { type: "URIError", number: -2146823264 },
    E_URI_INVALID_CODING:   { type: "URIError", number: -2146823263 },

    E_STACK_OVERFLOW:       { type: "Error", number: -2146828260 }
};

function testException(func, id) {
    var ex = exception_array[id];
    var ret = "", num = "";

    try {
        func();
    } catch(e) {
        ret = e.name;
        num = e.number;
    }

    ok(ret === ex.type, "Exception test, ret = " + ret + ", expected " + ex.type +". Executed function: " + func.toString());
    ok(num === ex.number, "Exception test, num = " + num + " (" + (num + 0x80000000).toString(16) + "), expected " + ex.number
       + ". Executed function: " + func.toString());
}

// RangeError tests
testException(function() {Array(-3);}, "E_INVALID_LENGTH");
testException(function() {createArray().lbound("aaa");}, "E_SUBSCRIPT_OUT_OF_RANGE");
testException(function() {createArray().lbound(3);}, "E_SUBSCRIPT_OUT_OF_RANGE");
testException(function() {createArray().getItem(3);}, "E_SUBSCRIPT_OUT_OF_RANGE");

// TypeError tests
testException(function() {date.setTime();}, "E_ARG_NOT_OPT");
testException(function() {date.setYear();}, "E_ARG_NOT_OPT");
testException(function() {arr.test();}, "E_NO_PROPERTY");
testException(function() {[1,2,3].sort(nullDisp);}, "E_JSCRIPT_EXPECTED");
testException(function() {var o = new Object(); o.length = 1; o[0] = "a"; Array.prototype.toLocaleString.call(o);}, "E_NOT_ARRAY");
testException(function() {Number.prototype.toString.call(arr);}, "E_NOT_NUM");
testException(function() {Number.prototype.toFixed.call(arr);}, "E_NOT_NUM");
testException(function() {Number.prototype.toLocaleString.call(arr);}, "E_NOT_NUM");
testException(function() {Number.prototype.toLocaleString.call(null);}, "E_NOT_NUM");
testException(function() {(new Number(3)).toString(1);}, "E_INVALID_CALL_ARG");
testException(function() {(new Number(3)).toString(undefined);}, "E_INVALID_CALL_ARG");
testException(function() {(new Number(3)).toFixed(21);}, "E_FRACTION_DIGITS_OUT_OF_RANGE");
testException(function() {(new Number(1)).toPrecision(0);}, "E_PRECISION_OUT_OF_RANGE");
if(invokeVersion < 2)
    testException(function() {(new Number(1)).toPrecision(undefined);}, "E_PRECISION_OUT_OF_RANGE");
testException(function() {not_existing_variable.something();}, "E_UNDEFINED");
testException(function() {date();}, "E_NOT_FUNC");
testException(function() {arr();}, "E_NOT_FUNC");
testException(function() {(new Object) instanceof (new Object);}, "E_NOT_FUNC");
testException(function() {eval("nonexistingfunc()")}, "E_OBJECT_EXPECTED");
testException(function() {(new Object()) instanceof 3;}, "E_NOT_FUNC");
testException(function() {(new Object()) instanceof null;}, "E_NOT_FUNC");
testException(function() {(new Object()) instanceof nullDisp;}, "E_NOT_FUNC");
testException(function() {nullDisp instanceof Object;}, "E_OBJECT_EXPECTED");
testException(function() {Function.prototype.apply.call(nullDisp, Object, []);}, "E_OBJECT_REQUIRED");
testException(function() {Function.prototype.call.call(nullDisp, Object);}, "E_OBJECT_REQUIRED");
testException(function() {"test" in 3;}, "E_OBJECT_EXPECTED");
testException(function() {"test" in null;}, "E_OBJECT_EXPECTED");
testException(function() {"test" in nullDisp;}, "E_OBJECT_EXPECTED");
testException(function() {new 3;}, "E_UNSUPPORTED_ACTION");
testException(function() {new null;}, "E_OBJECT_EXPECTED");
testException(function() {new nullDisp;}, "E_NO_PROPERTY");
testException(function() {new Math.max(5);}, "E_UNSUPPORTED_ACTION");
testException(function() {new VBArray();}, "E_NOT_VBARRAY");
testException(function() {new VBArray(new VBArray(createArray()));}, "E_NOT_VBARRAY");
testException(function() {VBArray.prototype.lbound.call(new Object());}, "E_NOT_VBARRAY");
testException(function() {+nullDisp.prop;}, "E_OBJECT_REQUIRED");
testException(function() {+nullDisp["prop"];}, "E_OBJECT_REQUIRED");
testException(function() {delete (new Object());}, "E_INVALID_DELETE");
testException(function() {delete false;}, "E_INVALID_DELETE");
testException(function() {undefined.toString();}, "E_OBJECT_EXPECTED");
testException(function() {null.toString();}, "E_OBJECT_EXPECTED");
testException(function() {RegExp.prototype.toString.call(new Object());}, "E_REGEXP_EXPECTED");
testException(function() {/a/.lastIndex();}, "E_NOT_FUNC");
testException(function() {"a".length();}, "E_NOT_FUNC");
testException(function() {var o = {f: {}}; o.f();}, "E_NOT_FUNC");
testException(function() {((function() { var f = Number.prototype.toString; return (function() { return f(); }); })())();}, "E_NOT_NUM");
testException(function() {((function() { var f = Object.prototype.hasOwnProperty; return (function() { return f("f"); }); })())();}, "E_OBJECT_EXPECTED");

testException(function() { return arguments.callee(); }, "E_STACK_OVERFLOW");

obj = new Object();
obj.prop = 1;
tmp = false;
testException(function() {delete ((tmp = true) ? obj.prop : obj.prop);}, "E_INVALID_DELETE");
ok(tmp, "delete (..) expression not evaluated");

//FIXME: testException(function() {nonexistent++;}, "E_OBJECT_EXPECTED");
//FIXME: testException(function() {undefined.nonexistent++;}, "E_OBJECT_EXPECTED");


// SyntaxError tests
function testSyntaxError(code, id) {
    var ex = exception_array[id];
    var ret = "", num = "";

    try {
        eval(code);
    } catch(e) {
        ret = e.name;
        num = e.number;
    }

    ok(ret === ex.type, "Syntax exception test, ret = " + ret + ", expected " + ex.type +". Executed code: " + code);
    ok(num === ex.number, "Syntax exception test, num = " + num + ", expected " + ex.number + ". Executed code: " + code);
}

testSyntaxError("for(i=0;) {}", "E_SYNTAX_ERROR");
testSyntaxError("function {};", "E_LBRACKET");
testSyntaxError("if", "E_LBRACKET");
testSyntaxError("do i=0; while", "E_LBRACKET");
testSyntaxError("while", "E_LBRACKET");
testSyntaxError("for", "E_LBRACKET");
testSyntaxError("with", "E_LBRACKET");
testSyntaxError("switch", "E_LBRACKET");
testSyntaxError("if(false", "E_RBRACKET");
testSyntaxError("for(i=0; i<10; i++", "E_RBRACKET");
testSyntaxError("while(true", "E_RBRACKET");
testSyntaxError("for(i=0", "E_SEMICOLON");
testSyntaxError("for(i=0;i<10", "E_SEMICOLON");
testSyntaxError("while(", "E_SYNTAX_ERROR");
testSyntaxError("if(", "E_SYNTAX_ERROR");
testSyntaxError("'unterminated", "E_UNTERMINATED_STR");
testSyntaxError("*", "E_SYNTAX_ERROR");
testSyntaxError("@_jscript_version", "E_DISABLED_CC");
testSyntaxError("@a", "E_DISABLED_CC");
testSyntaxError("/* @cc_on @*/ @_jscript_version", "E_DISABLED_CC");
testSyntaxError("ok(false, 'unexpected execution'); break;", "E_INVALID_BREAK");
testSyntaxError("ok(false, 'unexpected execution'); continue;", "E_INVALID_CONTINUE");
testSyntaxError("ok(false, 'unexpected execution'); while(true) break unknown_label;", "E_LABEL_NOT_FOUND");
testSyntaxError("ok(false, 'unexpected execution'); some_label: continue some_label;", "E_INVALID_CONTINUE");
testSyntaxError("ok(false, 'unexpected execution'); while(true) continue some_label;", "E_LABEL_NOT_FOUND");
testSyntaxError("ok(false, 'unexpected execution'); some_label: { while(true) continue some_label; }", "E_INVALID_CONTINUE");
testSyntaxError("ok(false, 'unexpected execution'); some_label: { some_label: while(true); }", "E_LABEL_REDEFINED");
testSyntaxError("return;", "E_MISPLACED_RETURN");
testSyntaxError("001.5;", "E_SEMICOLON");
testSyntaxError("001.5", "E_SEMICOLON");
testSyntaxError("0a", "E_SEMICOLON");
testSyntaxError("01a", "E_SEMICOLON");
testSyntaxError("0x1r", "E_SEMICOLON");
testSyntaxError("1a", "E_SEMICOLON");
testSyntaxError("1_", "E_SEMICOLON");

// ReferenceError tests
testException(function() {test = function() {}}, "E_ILLEGAL_ASSIGN");

tmp = false;
testException(function() {test = (tmp = true);}, "E_ILLEGAL_ASSIGN");
ok(tmp, "expr value on invalid assign not evaluated");

tmp = false;
testException(function() {(tmp = true) = false;}, "E_ILLEGAL_ASSIGN");
ok(tmp, "expr assign not evaluated");

tmp = false;
testException(function() {true = (tmp = true);}, "E_ILLEGAL_ASSIGN");
ok(tmp, "expr value assign not evaluated");

tmp = "";
testException(function() {(tmp = tmp+"1") = (tmp = tmp+"2");}, "E_ILLEGAL_ASSIGN");
ok(tmp === "12", "assign evaluated in unexpected order");

tmp = false;
testException(function() { ((tmp = true) && false)++; }, "E_ILLEGAL_ASSIGN")
ok(tmp, "incremented expression not evaluated");

// RegExpError tests
testException(function() {RegExp(/a/, "g");}, "E_REGEXP_SYNTAX_ERROR");

// URIError tests
testException(function() {encodeURI('\udcaa');}, "E_URI_INVALID_CHAR");
testException(function() {encodeURIComponent('\udcaa');}, "E_URI_INVALID_CHAR");
testException(function() {decodeURI('%');}, "E_URI_INVALID_CODING");
testException(function() {decodeURI('%aaaa');}, "E_URI_INVALID_CODING");

function testThisExcept(func, e) {
    testException(function() {func.call(new Object())}, e);
}

function testBoolThis(func) {
    testThisExcept(Boolean.prototype[func], "E_NOT_BOOL");
}

testBoolThis("toString");
testBoolThis("valueOf");

function testDateThis(func) {
    testThisExcept(Date.prototype[func], "E_NOT_DATE");
}

testDateThis("getDate");
testDateThis("getDay");
testDateThis("getFullYear");
testDateThis("getHours");
testDateThis("getMilliseconds");
testDateThis("getMinutes");
testDateThis("getMonth");
testDateThis("getSeconds");
testDateThis("getTime");
testDateThis("getTimezoneOffset");
testDateThis("getUTCDate");
testDateThis("getUTCDay");
testDateThis("getUTCFullYear");
testDateThis("getUTCHours");
testDateThis("getUTCMilliseconds");
testDateThis("getUTCMinutes");
testDateThis("getUTCMonth");
testDateThis("getUTCSeconds");
testDateThis("getYear");
testDateThis("setDate");
testDateThis("setFullYear");
testDateThis("setHours");
testDateThis("setMilliseconds");
testDateThis("setMinutes");
testDateThis("setMonth");
testDateThis("setSeconds");
testDateThis("setTime");
testDateThis("setUTCDate");
testDateThis("setUTCFullYear");
testDateThis("setUTCHours");
testDateThis("setUTCMilliseconds");
testDateThis("setUTCMinutes");
testDateThis("setUTCMonth");
testDateThis("setUTCSeconds");
testDateThis("setYear");
testDateThis("toDateString");
testDateThis("toLocaleDateString");
testDateThis("toLocaleString");
testDateThis("toLocaleTimeString");
testDateThis("toString");
testDateThis("toTimeString");
testDateThis("toUTCString");
testDateThis("valueOf");

function testArrayThis(func) {
    testThisExcept(Array.prototype[func], "E_NOT_ARRAY");
}

testArrayThis("toString");

function testFunctionThis(func) {
    testThisExcept(Function.prototype[func], "E_NOT_FUNC");
}

testFunctionThis("toString");
testFunctionThis("call");
testFunctionThis("apply");

function testArrayHostThis(func) {
    testException(function() { Array.prototype[func].call(testObj); }, "E_JSCRIPT_EXPECTED");
}

testArrayHostThis("push");
testArrayHostThis("shift");
testArrayHostThis("slice");
testArrayHostThis("splice");
testArrayHostThis("unshift");
testArrayHostThis("reverse");
testArrayHostThis("join");
testArrayHostThis("pop");
testArrayHostThis("sort");

function testEnumeratorThis(func) {
    testThisExcept(Enumerator.prototype[func], "E_NOT_ENUMERATOR");
}

testEnumeratorThis("atEnd");
testEnumeratorThis("item");
testEnumeratorThis("moveFirst");
testEnumeratorThis("moveNext");

function testObjectInherit(obj, constr, ts, tls, vo) {
    ok(obj instanceof Object, "obj is not instance of Object");
    ok(obj instanceof constr, "obj is not instance of its constructor");

    ok(obj.hasOwnProperty === Object.prototype.hasOwnProperty,
       "obj.hasOwnProperty !== Object.prototype.hasOwnProprty");
    ok(obj.isPrototypeOf === Object.prototype.isPrototypeOf,
       "obj.isPrototypeOf !== Object.prototype.isPrototypeOf");
    ok(obj.propertyIsEnumerable === Object.prototype.propertyIsEnumerable,
       "obj.propertyIsEnumerable !== Object.prototype.propertyIsEnumerable");

    if(ts)
        ok(obj.toString === Object.prototype.toString,
           "obj.toString !== Object.prototype.toString");
    else
        ok(obj.toString != Object.prototype.toString,
           "obj.toString == Object.prototype.toString");

    if(tls)
        ok(obj.toLocaleString === Object.prototype.toLocaleString,
           "obj.toLocaleString !== Object.prototype.toLocaleString");
    else
        ok(obj.toLocaleString != Object.prototype.toLocaleString,
           "obj.toLocaleString == Object.prototype.toLocaleString");

    if(vo)
        ok(obj.valueOf === Object.prototype.valueOf,
           "obj.valueOf !== Object.prototype.valueOf");
    else
        ok(obj.valueOf != Object.prototype.valueOf,
           "obj.valueOf == Object.prototype.valueOf");

    ok(obj._test === "test", "obj.test = " + obj._test);
}

Object.prototype._test = "test";
testObjectInherit(new String("test"), String, false, true, false);
testObjectInherit(/test/g, RegExp, false, true, true);
testObjectInherit(new Number(1), Number, false, false, false);
testObjectInherit(new Date(), Date, false, false, false);
testObjectInherit(new Boolean(true), Boolean, false, true, false);
testObjectInherit(new Array(), Array, false, false, true);
testObjectInherit(new Error(), Error, false, true, true);
testObjectInherit(testObjectInherit, Function, false, true, true);
testObjectInherit(Math, Object, true, true, true);

(function() { testObjectInherit(arguments, Object, true, true, true); })();

function testFunctions(obj, arr) {
    var l;

    for(var i=0; i<arr.length; i++) {
        l = obj[arr[i][0]].length;
        ok(l === arr[i][1], arr[i][0] + ".length = " + l);

        ok(obj.propertyIsEnumerable(arr[i][0]) === false, arr[i][0] + " is enumerable");
    }
}

testFunctions(Boolean.prototype, [
        ["valueOf", 0],
        ["toString", 0]
    ]);

testFunctions(Number.prototype, [
        ["valueOf", 0],
        ["toString", 1],
        ["toExponential", 1],
        ["toLocaleString", 0],
        ["toPrecision", 1]
    ]);

testFunctions(String.prototype, [
        ["valueOf", 0],
        ["toString", 0],
        ["anchor", 1],
        ["big", 0],
        ["blink", 0],
        ["bold", 0],
        ["charAt", 1],
        ["charCodeAt", 1],
        ["concat", 1],
        ["fixed", 0],
        ["fontcolor", 1],
        ["fontsize", 1],
        ["indexOf", 2],
        ["italics", 0],
        ["lastIndexOf", 2],
        ["link", 1],
        ["localeCompare", 1],
        ["match", 1],
        ["replace", 1],
        ["search", 0],
        ["slice", 0],
        ["small", 0],
        ["split", 2],
        ["strike", 0],
        ["sub", 0],
        ["substr", 2],
        ["substring", 2],
        ["sup", 0],
        ["toLocaleLowerCase", 0],
        ["toLocaleUpperCase", 0],
        ["toLowerCase", 0],
        ["toUpperCase", 0]
    ]);

testFunctions(RegExp.prototype, [
        ["toString", 0],
        ["exec", 1],
        ["test", 1]
    ]);

testFunctions(Date.prototype, [
        ["getDate", 0],
        ["getDay", 0],
        ["getFullYear", 0],
        ["getHours", 0],
        ["getMilliseconds", 0],
        ["getMinutes", 0],
        ["getMonth", 0],
        ["getSeconds", 0],
        ["getTime", 0],
        ["getTimezoneOffset", 0],
        ["getUTCDate", 0],
        ["getUTCDay", 0],
        ["getUTCFullYear", 0],
        ["getUTCHours", 0],
        ["getUTCMilliseconds", 0],
        ["getUTCMinutes", 0],
        ["getUTCMonth", 0],
        ["getUTCSeconds", 0],
        ["getYear", 0],
        ["setDate", 1],
        ["setFullYear", 3],
        ["setHours", 4],
        ["setMilliseconds", 1],
        ["setMinutes", 3],
        ["setMonth", 2],
        ["setSeconds", 2],
        ["setTime", 1],
        ["setUTCDate", 1],
        ["setUTCFullYear", 3],
        ["setUTCHours", 4],
        ["setUTCMilliseconds", 1],
        ["setUTCMinutes", 3],
        ["setUTCMonth", 2],
        ["setUTCSeconds", 2],
        ["setYear", 1],
        ["toDateString", 0],
        ["toLocaleDateString", 0],
        ["toLocaleString", 0],
        ["toLocaleTimeString", 0],
        ["toString", 0],
        ["toTimeString", 0],
        ["toUTCString", 0],
        ["toGMTString", 0],
        ["valueOf", 0]
    ]);

testFunctions(Array.prototype, [
        ["concat", 1],
        ["join", 1],
        ["push", 1],
        ["pop", 0],
        ["reverse", 0],
        ["shift", 0],
        ["slice", 2],
        ["sort", 1],
        ["splice", 2],
        ["toLocaleString", 0],
        ["toString", 0],
        ["unshift", 1]
    ]);

testFunctions(Error.prototype, [
        ["toString", 0]
    ]);

testFunctions(Math, [
        ["abs", 1],
        ["acos", 1],
        ["asin", 1],
        ["atan", 1],
        ["atan2", 2],
        ["ceil", 1],
        ["cos", 1],
        ["exp", 1],
        ["floor", 1],
        ["log", 1],
        ["max", 2],
        ["min", 2],
        ["pow", 2],
        ["random", 0],
        ["round", 1],
        ["sin", 1],
        ["sqrt", 1],
        ["tan", 1]
    ]);

testFunctions(Object.prototype, [
        ["hasOwnProperty", 1],
        ["isPrototypeOf", 1],
        ["propertyIsEnumerable", 1],
        ["toLocaleString", 0],
        ["toString", 0],
        ["valueOf", 0]
    ]);

testFunctions(Function.prototype, [
        ["apply", 2],
        ["call", 1],
        ["toString", 0]
    ]);

testFunctions(VBArray.prototype, [
        ["dimensions", 0],
        ["getItem", 1],
        ["lbound", 0],
        ["toArray", 0],
        ["ubound", 0]
]);

if(invokeVersion < 2)
    ok(typeof(JSON) === "undefined", "JSON is not undefined");
else
    testFunctions(JSON, [
        ["parse", 2],
        ["stringify", 3]
    ]);

ok(ActiveXObject.length == 1, "ActiveXObject.length = " + ActiveXObject.length);
ok(Array.length == 1, "Array.length = " + Array.length);
ok(Boolean.length == 1, "Boolean.length = " + Boolean.length);
ok(CollectGarbage.length == 0, "CollectGarbage.length = " + CollectGarbage.length);
ok(Date.length == 7, "Date.length = " + Date.length);
ok(Enumerator.length == 7, "Enumerator.length = " + Enumerator.length);
ok(Error.length == 1, "Error.length = " + Error.length);
ok(EvalError.length == 1, "EvalError.length = " + EvalError.length);
ok(RegExpError.length == 1, "RegExpError.length = " + RegExpError.length);
ok(Function.length == 1, "Function.length = " + Function.length);
ok(GetObject.length == 2, "GetObject.length = " + GetObject.length);
ok(Number.length == 1, "Number.length = " + Number.length);
ok(Object.length == 0, "Object.length = " + Object.length);
ok(RangeError.length == 1, "RangeError.length = " + RangeError.length);
ok(ReferenceError.length == 1, "ReferenceError.length = " + ReferenceError.length);
ok(RegExp.length == 2, "RegExp.length = " + RegExp.length);
ok(ScriptEngine.length == 0, "ScriptEngine.length = " + ScriptEngine.length);
ok(ScriptEngineBuildVersion.length == 0,
    "ScriptEngineBuildVersion.length = " + ScriptEngineBuildVersion.length);
ok(ScriptEngineMajorVersion.length == 0,
    "ScriptEngineMajorVersion.length = " + ScriptEngineMajorVersion.length);
ok(ScriptEngineMinorVersion.length == 0,
    "ScriptEngineMinorVersion.length = " + ScriptEngineMinorVersion.length);
ok(String.length == 1, "String.length = " + String.length);
ok(SyntaxError.length == 1, "SyntaxError.length = " + SyntaxError.length);
ok(TypeError.length == 1, "TypeError.length = " + TypeError.length);
ok(URIError.length == 1, "URIError.length = " + URIError.length);
ok(VBArray.length == 1, "VBArray.length = " + VBArray.length);
ok(decodeURI.length == 1, "decodeURI.length = " + decodeURI.length);
ok(decodeURIComponent.length == 1, "decodeURIComponent.length = " + decodeURIComponent.length);
ok(encodeURI.length == 1, "encodeURI.length = " + encodeURI.length);
ok(encodeURIComponent.length == 1, "encodeURIComponent.length = " + encodeURIComponent.length);
ok(escape.length == 1, "escape.length = " + escape.length);
ok(eval.length == 1, "eval.length = " + eval.length);
ok(isFinite.length == 1, "isFinite.length = " + isFinite.length);
ok(isNaN.length == 1, "isNaN.length = " + isNaN.length);
ok(parseFloat.length == 1, "parseFloat.length = " + parseFloat.length);
ok(parseInt.length == 2, "parseInt.length = " + parseInt.length);
ok(unescape.length == 1, "unescape.length = " + unescape.length);

String.length = 3;
ok(String.length == 1, "String.length = " + String.length);

(function() {
    var tests = [
        [ "Array.sort",             JS_E_OBJECT_EXPECTED,        function(ctx) { Array.prototype.sort.call(ctx); } ],
        [ "Boolean.valueOf",        JS_E_BOOLEAN_EXPECTED,       function(ctx) { Boolean.prototype.valueOf.call(ctx); } ],
        [ "Date.getYear",           JS_E_DATE_EXPECTED,          function(ctx) { Date.prototype.getYear.call(ctx); } ],
        [ "Enumerator.atEnd",       JS_E_ENUMERATOR_EXPECTED,    function(ctx) { Enumerator.prototype.atEnd.call(ctx); } ],
        [ "Function.apply",         JS_E_FUNCTION_EXPECTED,      function(ctx) { Function.prototype.apply.call(ctx, [ function() {} ]); } ],
        [ "Number.toExponential",   JS_E_NUMBER_EXPECTED,        function(ctx) { Number.prototype.toExponential.call(ctx); } ],
        [ "Object.hasOwnProperty",  JS_E_OBJECT_EXPECTED,        function(ctx) { Object.prototype.hasOwnProperty.call(ctx, "toString"); } ],
        [ "RegExp.test",            JS_E_REGEXP_EXPECTED,        function(ctx) { RegExp.prototype.test.call(ctx, "foobar"); } ],
        [ "VBArray.lbound",         JS_E_VBARRAY_EXPECTED,       function(ctx) { VBArray.prototype.lbound.call(ctx); } ]
    ];

    for(var i = 0; i < tests.length; i++) {
        try {
            tests[i][2](null);
            ok(false, "expected exception calling " + tests[i][0] + " with null context");
        }catch(ex) {
            var n = ex.number >>> 0; /* make it unsigned like HRESULT */
            ok(n === tests[i][1], tests[i][0] + " with null context exception code = " + n);
        }
        try {
            tests[i][2](undefined);
            ok(false, "expected exception calling " + tests[i][0] + " with undefined context");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === tests[i][1], tests[i][0] + " with undefined context exception code = " + n);
        }
    }

    var r = Error.prototype.toString.call(undefined);
    ok(r === "[object Error]", "Error.toString with undefined context returned " + r);
    r = String.prototype.slice.call(null, 1, 3);
    ok(r === "ul", "String.slice with null context returned " + r);
    r = String.prototype.slice.call(undefined, 2, 5);
    ok(r === "def", "String.slice with undefined context returned " + r);
    r = (function() { return this; }).call(null);
    ok(r === test, "wrong 'this' of function with null context");
    r = (function() { return this; }).call(undefined);
    ok(r === test, "wrong 'this' of function with undefined context");
    r = (function() { return this; }).call(42);
    ok(r.valueOf() === 42, "'this' of function with 42 context = " + r);
})();

var tmp = createArray();
ok(getVT(tmp) == "VT_ARRAY|VT_VARIANT", "getVT(createArray()) = " + getVT(tmp));
ok(getVT(VBArray(tmp)) == "VT_ARRAY|VT_VARIANT", "getVT(VBArray(tmp)) = " + getVT(VBArray(tmp)));
VBArray(tmp);
new VBArray(tmp);
tmp = new VBArray(tmp);
tmp = new VBArray(VBArray(createArray()));
ok(tmp.dimensions() == 2, "tmp.dimensions() = " + tmp.dimensions());
ok(tmp.lbound() == 0, "tmp.lbound() = " + tmp.lbound());
ok(tmp.lbound(1) == 0, "tmp.lbound(1) = " + tmp.lbound(1));
ok(tmp.lbound(2, 1) == 2, "tmp.lbound(2, 1) = " + tmp.lbound(2, 1));
ok(tmp.ubound() == 4, "tmp.ubound() = " + tmp.ubound());
ok(tmp.ubound("2") == 3, "tmp.ubound(\"2\") = " + tmp.ubound("2"));
ok(tmp.getItem(1, 2) == 3, "tmp.getItem(1, 2) = " + tmp.getItem(1, 2));
ok(tmp.getItem(2, 3) == 33, "tmp.getItem(2, 3) = " + tmp.getItem(2, 3));
ok(tmp.getItem(3, 2) == 13, "tmp.getItem(3, 2) = " + tmp.getItem(3, 2));
ok(tmp.toArray() == "2,3,12,13,22,23,32,33,42,43", "tmp.toArray() = " + tmp.toArray());
ok(createArray().toArray() == "2,3,12,13,22,23,32,33,42,43",
        "createArray.toArray()=" + createArray().toArray());

obj = new Enumerator();
ok(obj.atEnd(), "atEnd() = " + obj.atEnd());
obj.moveFirst();
ok(obj.atEnd(), "atEnd() = " + obj.atEnd());

reportSuccess();
 �  (   ��( C C . J S       0           /*
 * Copyright 2010 Jacek Caban for CodeWeavers
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

eval("@_jscript_version");

var tmp;

/*@ */
//@cc_on @*/

@_jscript_version;

@cc_on
@*/

// Standard predefined variabled
if(isWin64) {
    ok(@_win64 === true, "@_win64 = " + @_win64);
    ok(@_amd64 === true, "@_amd64 = " + @_amd64);
    ok(isNaN(@_win32), "@_win32 = " + @_win32);
    ok(isNaN(@_x86), "@_x86 = " + @_x86);
}else {
    ok(@_win32 === true, "@_win32 = " + @_win32);
    ok(@_x86 === true, "@_x86 = " + @_x86);
    ok(isNaN(@_win64), "@_win64 = " + @_win64);
    ok(isNaN(@_amd64), "@_amd64 = " + @_amd64);
}

ok(@_jscript === true, "@_jscript = " + @_jscript);
ok(@_jscript_build === ScriptEngineBuildVersion(),
   "@_jscript_build = " + @_jscript_build + " expected " + ScriptEngineBuildVersion());
tmp = ScriptEngineMajorVersion() + ScriptEngineMinorVersion()/10;
ok(@_jscript_version === tmp, "@_jscript_version = " + @_jscript_version + " expected " + tmp);
ok(isNaN(@_win16), "@_win16 = " + @_win16);
ok(isNaN(@_mac), "@_mac = " + @_mac);
ok(isNaN(@_alpha), "@_alpha = " + @_alpha);
ok(isNaN(@_mc680x0), "@_mc680x0 = " + @_mc680x0);
ok(isNaN(@_PowerPC), "@_PowerPC = " + @_PowerPC);

// Undefined variable
ok(isNaN(@xxx), "@xxx = " + @xxx);
ok(isNaN(@x$_xx), "@x$_xx = " + @x$_xx);

tmp = false;
try {
    eval("/*@cc_on */");
}catch(e) {
    tmp = true;
}
ok(tmp, "expected syntax exception");

tmp = false;
try {
    eval("/*@_jscript_version */");
}catch(e) {
    tmp = true;
}
ok(tmp, "expected syntax exception");

ok(isNaN(@test), "@test = " + @test);

@set @test = 1
ok(@test === 1, "@test = " + @test);

@set @test = 0
ok(@test === 0, "@test = " + @test);

tmp = false
@set @test = @test tmp=true
ok(@test === 0, "@test = " + @test);
ok(tmp, "expr after @set not evaluated");

@set @test = !@test
ok(@test === true, "@test = " + @test);

@set @test = (@test+1+true)
ok(@test === 3, "@test = " + @test);

@set
 @test
 =
 2
ok(@test === 2, "@test = " + @test);

@set
 @test
 =
 (
 2
 +
 2
 )
ok(@test === 4, "@test = " + @test);

@set @test = 2.5
ok(@test === 2.5, "@test = " + @test);

@set @test = 0x4
ok(@test === 4, "@test = " + @test);

@set @test = (2 + 2/2)
ok(@test === 3, "@test = " + @test);

@set @test = (false+false)
ok(@test === 0, "@test = " + @test);

@set @test = ((1+1)*((3)+1))
ok(@test === 8, "@test = " + @test);

@set @_test = true
ok(@_test === true, "@_test = " + @_test);

@set @$test = true
ok(@$test === true, "@$test = " + @$test);

@set @newtest = (@newtest != @newtest)
ok(@newtest === true, "@newtest = " + @newtest);

@set @test = (false != 0)
ok(@test === false, "@test = " + @test);

@set @test = (1 != true)
ok(@test === false, "@test = " + @test);

@set @test = (0 != true)
ok(@test === true, "@test = " + @test);

@set @test = (true-2)
ok(@test === -1, "@test = " + @test);

@set @test = (true-@_jscript)
ok(@test === 0, "@test = " + @test);

@set @test = (true==1)
ok(@test === true, "@test = " + @test);

@set @test = (1==false+1)
ok(@test === true, "@test = " + @test);

function expect(val, exval) {
    ok(val === exval, "got " + val + " expected " + exval);
}

@set @test = (false < 0.5)
expect(@test, true);

@set @test = (true == 0 < 0.5)
expect(@test, true);

@set @test = (false < 0)
expect(@test, false);

@set @test = (false > 0.5)
expect(@test, false);

@set @test = (1 < true)
expect(@test, false);

@set @test = (1 <= true)
expect(@test, true);

@set @test = (1 >= true)
expect(@test, true);

@set @test = (1 >= true-1)
expect(@test, true);

@set @test = (true && true)
expect(@test, true);

@set @test = (false && true)
expect(@test, false);

@set @test = (true && false)
expect(@test, false);

@set @test = (false && false)
expect(@test, false);

if(!isWin64) {
@set @test = (@_win32&&@_jscript_version>=5)
expect(@test, true);
}

@if (false)
    this wouldn not parse
"@end

@if (false) "@end

tmp = "@if (false) @end";
ok(tmp.length === 16, "tmp.length = " + tmp.length);

@if(true)
tmp = true
@end
ok(tmp === true, "tmp = " + tmp);

@if(false)
@if this would not CC parse
this will not parse
@elif(true)
this will also not parse
@else
this also will not parse
@if let me complicate things a bit
@end enough
@end
@end

@if(false)
this will not parse
@else
tmp = 2
@else
this will not be parsed
@else
also this
@end
ok(tmp === 2, "tmp = " + tmp);

@if(true)
tmp = 3;
@else
just skip this
@end
ok(tmp === 3, "tmp = " + tmp);

@if(true)
tmp = 4;
@elif(true)
this will not parse
@elif nor this
@else
just skip this
@end
ok(tmp === 4, "tmp = " + tmp);

@if(false)
this will not parse
@elif(false)
nor this would
@elif(true)
tmp = 5;
@elif nor this
@else
just skip this
@end
ok(tmp === 5, "tmp = " + tmp);

@if (!@_jscript)
this would not parse
@if(true)
@else
@if(false)
@end
@end
@elif (@_jscript)
tmp = 6;
@elif (true)
@if xxx
@else
@if @elif @elif @else @end
@end
@else
this would not parse
@end
ok(tmp === 6, "tmp = " + tmp);

@if(true)
@if(false)
@else
tmp = 7;
@end
@else
this would not parse
@end
ok(tmp === 7, "tmp = " + tmp);

var exception_map = {
    JS_E_SYNTAX:               {type: "SyntaxError", number: -2146827286},
    JS_E_MISSING_LBRACKET:     {type: "SyntaxError", number: -2146827283},
    JS_E_EXPECTED_IDENTIFIER:  {type: "SyntaxError", number: -2146827278},
    JS_E_EXPECTED_ASSIGN:      {type: "SyntaxError", number: -2146827277},
    JS_E_EXPECTED_CCEND:       {type: "SyntaxError", number: -2146827259},
    JS_E_EXPECTED_AT:          {type: "SyntaxError", number: -2146827256}
};

function testException(src, id) {
    var ex = exception_map[id];
    var ret = "", num = "";

    try {
        eval(src);
    } catch(e) {
        ret = e.name;
        num = e.number;
    }

    ok(ret === ex.type, "Exception test, ret = " + ret + ", expected " + ex.type +". Executed code: " + src);
    ok(num === ex.number, "Exception test, num = " + num + ", expected " + ex.number + ". Executed function: " + src);
}

testException("@set test=true", "JS_E_EXPECTED_AT");
testException("@set @1=true", "JS_E_EXPECTED_IDENTIFIER");
testException("@set @test x=true", "JS_E_EXPECTED_ASSIGN");
testException("@if false\n@end", "JS_E_MISSING_LBRACKET");
testException("@if (false)\n", "JS_E_EXPECTED_CCEND");
testException("@end\n", "JS_E_SYNTAX");
testException("@elif\n", "JS_E_SYNTAX");
testException("@else\n", "JS_E_SYNTAX");
testException("@if false\n@elif true\n@end", "JS_E_MISSING_LBRACKET");

reportSuccess();
   C�  ,   ��( L A N G . J S       0           /*
 * Copyright 2008 Jacek Caban for CodeWeavers
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

var tmp;

ok(true, "true is not true?");
ok(!false, "!false is not true");
ok(!undefined, "!undefined is not true");
ok(!null, "!null is not true");
ok(!0, "!0 is not true");
ok(!0.0, "!0.0 is not true");

ok(1 === 1, "1 === 1 is false");
ok(!(1 === 2), "!(1 === 2) is false");
ok(1.0 === 1, "1.0 === 1 is false");
ok("abc" === "abc", "\"abc\" === \"abc\" is false");
ok(true === true, "true === true is false");
ok(null === null, "null === null is false");
ok(undefined === undefined, "undefined === undefined is false");
ok(!(undefined === null), "!(undefined === null) is false");
ok(1E0 === 1, "1E0 === 1 is false");
ok(1000000*1000000 === 1000000000000, "1000000*1000000 === 1000000000000 is false");
ok(8.64e15 === 8640000000000000, "8.64e15 !== 8640000000000000");
ok(1e2147483648 === Infinity, "1e2147483648 !== Infinity");

ok(00 === 0, "00 != 0");
ok(010 === 8, "010 != 8");
ok(077 === 63, "077 != 63");
ok(080 === 80, "080 != 80");
ok(090 === 90, "090 != 90");
ok(018 === 18, "018 != 18");
tmp = 07777777777777777777777;
ok(typeof(tmp) === "number" && tmp > 0xffffffff, "tmp = " + tmp);
tmp = 07777777779777777777777;
ok(typeof(tmp) === "number" && tmp > 0xffffffff, "tmp = " + tmp);
ok(0xffffffff === 4294967295, "0xffffffff = " + 0xffffffff);
tmp = 0x10000000000000000000000000000000000000000000000000000000000000000;
ok(tmp === Math.pow(2, 256), "0x1000...00 != 2^256");

ok(1 !== 2, "1 !== 2 is false");
ok(null !== undefined, "null !== undefined is false");

ok(1 == 1, "1 == 1 is false");
ok(!(1 == 2), "!(1 == 2) is false");
ok(1.0 == 1, "1.0 == 1 is false");
ok("abc" == "abc", "\"abc\" == \"abc\" is false");
ok(true == true, "true == true is false");
ok(null == null, "null == null is false");
ok(undefined == undefined, "undefined == undefined is false");
ok(undefined == null, "undefined == null is false");
ok(true == 1, "true == 1 is false");
ok(!(true == 2), "true == 2");
ok(0 == false, "0 == false is false");

ok(1 != 2, "1 != 2 is false");
ok(false != 1, "false != 1 is false");

ok(this === test, "this !== test");
eval('ok(this === test, "this !== test");');

var trueVar = true;
ok(trueVar, "trueVar is not true");

ok(ScriptEngine.length === 0, "ScriptEngine.length is not 0");

function testFunc1(x, y) {
    ok(this !== undefined, "this is undefined");
    ok(x === true, "x is not true");
    ok(y === "test", "y is not \"test\"");
    ok(arguments.length === 2, "arguments.length is not 2");
    ok(arguments["0"] === true, "arguments[0] is not true");
    ok(arguments["1"] === "test", "arguments[1] is not \"test\"");
    ok(arguments.callee === testFunc1, "arguments.calee !== testFunc1");
    ok(testFunc1.arguments === arguments, "testFunc1.arguments = " + testFunc1.arguments);

    x = false;
    ok(arguments[0] === false, "arguments[0] is not false");
    arguments[1] = "x";
    ok(y === "x", "y = " + y);
    ok(arguments[1] === "x", "arguments[1] = " + arguments[1]);

    ok(arguments["0x0"] === undefined, "arguments['0x0'] = " + arguments["0x0"]);
    ok(arguments["x"] === undefined, "arguments['x'] = " + arguments["x"]);

    ok(this === test, "this !== test");
    eval('ok(this === test, "this !== test");');

    tmp = delete arguments;
    ok(tmp === false, "arguments deleted");
    ok(typeof(arguments) === "object", "typeof(arguments) = " + typeof(arguments));

    x = 2;
    ok(x === 2, "x = " + x);
    ok(arguments[0] === 2, "arguments[0] = " + arguments[0]);

    return true;
}

ok(testFunc1.length === 2, "testFunc1.length is not 2");
ok(testFunc1.arguments === null, "testFunc1.arguments = " + testFunc1.arguments);

ok(Object.prototype !== undefined, "Object.prototype is undefined");
ok(Object.prototype.prototype === undefined, "Object.prototype is not undefined");
ok(String.prototype !== undefined, "String.prototype is undefined");
ok(Array.prototype !== undefined, "Array.prototype is undefined");
ok(Boolean.prototype !== undefined, "Boolean.prototype is undefined");
ok(Number.prototype !== undefined, "Number.prototype is undefined");
ok(RegExp.prototype !== undefined, "RegExp.prototype is undefined");
ok(Math !== undefined, "Math is undefined");
ok(Math.prototype === undefined, "Math.prototype is not undefined");
ok(Function.prototype !== undefined, "Function.prototype is undefined");
ok(Function.prototype.prototype === undefined, "Function.prototype.prototype is not undefined");
ok(Date.prototype !== undefined, "Date.prototype is undefined");
ok(Date.prototype.prototype === undefined, "Date.prototype is not undefined");

function testConstructor(constr, name, inst) {
    ok(constr.prototype.constructor === constr, name + ".prototype.constructor !== " + name);
    ok(constr.prototype.hasOwnProperty("constructor"), name + ".prototype.hasOwnProperty('constructor')");

    if(!inst)
        inst = new constr();

    ok(inst.constructor === constr, "(new " + name + "()).constructor !== " + name);
    ok(!inst.hasOwnProperty("constructor"), "(new " + name + "()).hasOwnProperty('constructor')");
}

testConstructor(Object, "Object");
testConstructor(String, "String");
testConstructor(Array, "Array");
testConstructor(Boolean, "Boolean");
testConstructor(Number, "Number");
testConstructor(RegExp, "RegExp", /x/);
testConstructor(Function, "Function");
testConstructor(Date, "Date");
testConstructor(VBArray, "VBArray", new VBArray(createArray()));
testConstructor(Error, "Error");
testConstructor(EvalError, "EvalError");
testConstructor(RangeError, "RangeError");
testConstructor(ReferenceError, "ReferenceError");
testConstructor(RegExpError, "RegExpError");
testConstructor(SyntaxError, "SyntaxError");
testConstructor(TypeError, "TypeError");
testConstructor(URIError, "URIError");

Function.prototype.test = true;
ok(testFunc1.test === true, "testFunc1.test !== true");
ok(Function.test === true, "Function.test !== true");

ok(typeof(0) === "number", "typeof(0) is not number");
ok(typeof(1.5) === "number", "typeof(1.5) is not number");
ok(typeof("abc") === "string", "typeof(\"abc\") is not string");
ok(typeof("") === "string", "typeof(\"\") is not string");
ok(typeof(true) === "boolean", "typeof(true) is not boolean");
ok(typeof(null) === "object", "typeof(null) is not object");
ok(typeof(undefined) === "undefined", "typeof(undefined) is not undefined");
ok(typeof(Math) === "object", "typeof(Math) is not object");
ok(typeof(String.prototype) === "object", "typeof(String.prototype) is not object");
ok(typeof(testFunc1) === "function", "typeof(testFunc1) is not function");
ok(typeof(String) === "function", "typeof(String) is not function");
ok(typeof(ScriptEngine) === "function", "typeof(ScriptEngine) is not function");
ok(typeof(this) === "object", "typeof(this) is not object");
ok(typeof(doesnotexist) === "undefined", "typeof(doesnotexist) = " + typeof(doesnotexist));
tmp = typeof((new Object()).doesnotexist);
ok(tmp === "undefined", "typeof((new Object).doesnotexist = " + tmp);
tmp = typeof(testObj.onlyDispID);
ok(tmp === "unknown", "typeof(testObj.onlyDispID) = " + tmp);

ok("\0\0x\0\0".length === 5, "\"\\0\\0x\\0\\0\".length = " + "\0\0x\0\0".length);
ok("\0\0x\0\0" === String.fromCharCode(0) + "\0x\0" + String.fromCharCode(0), "\"\\0\\0x\\0\\0\" unexpected");

ok(testFunc1(true, "test") === true, "testFunc1 not returned true");

ok(testFunc1.arguments === null, "testFunc1.arguments = " + testFunc1.arguments);

(tmp) = 3;
ok(tmp === 3, "tmp = " + tmp);

(function() {
    /* VT_DATE handling */
    var d, e;
    ok(getVT(v_date(0)) === "VT_DATE", "vt v_date(0) = " + getVT(v_date(0)));
    d = v_date(0);
    e = Date.parse("Sat Dec 30 00:00:00 1899");
    ok(getVT(d) === "VT_DATE", "vt v_date(0) = " + getVT(d));
    ok(getVT(+d) === "VT_R8", "vt +v_date(0) = " + getVT(d));
    ok(getVT(d / d) === "VT_I4", "vt v_date(0) / v_date(0) = " + getVT(d / d));
    ok((+d) === e, "+v_date(0) = " + (+d) + " expected " + e);
    ok(("" + d).match(/^Sat Dec 30 00:00:00 .* 1899$/) != null, "+v_date(0) = " + d);
    ok(d != d, "date d == d");

    d = v_date(2.5);
    e = Date.parse("Mon Jan 1 12:00:00 1900");
    ok((+d) === e, "+v_date(2.5) = " + (+d));
    ok(("" + d).match(/^Mon Jan 1 12:00:00 .* 1900$/) != null, "+v_date(2.5) = " + d);

    d = v_date(42091);
    e = Date.parse("Sat Mar 28 00:00:00 2015");
    ok((+d) === e, "+v_date(2015y) = " + (+d) + " expected " + e);
    ok(("" + d).match(/^Sat Mar 28 00:00:00 .* 2015$/) != null, "+v_date(2015y) = " + d);
    ok(d != d, "date d == d");
})();

(function() {
    /* VT_CY handling */
    var d;
    todo_wine_ok(getVT(v_cy(0)) === "VT_R8", "vt v_cy(0) = " + getVT(v_cy(0)));
    todo_wine_ok(getVT(v_cy(10000)) === "VT_R8", "vt v_cy(10000) = " + getVT(v_cy(0)));
    d = v_cy(0);
    todo_wine_ok(getVT(d) === "VT_R8", "vt v_cy(0) = " + getVT(d));
    todo_wine_ok(getVT(+d) === "VT_R8", "vt +v_cy(0) = " + getVT(d));
    ok(d == 0, "v_cy(0) != 0\n");
    ok(d === 0, "v_cy(0) !== 0\n");
    ok("" + d === "0", "str(v_cy(0)) = " + d);
    ok(d === d, "date d !== d");

    d = v_cy(1000);
    ok(getVT(d) === "VT_R8", "vt v_cy(1000) = " + getVT(d));
    ok(getVT(+d) === "VT_R8", "vt +v_cy(1000) = " + getVT(d));
    ok(d == 0.1, "v_cy(1000) != 0, d = " + d);
    ok(d === 0.1, "v_cy(1000) !== 0.1\n");
    ok("" + d === "0.1", "str(v_cy(1000)) = " + d);
    ok(d === d, "date d !== d");

    d = v_cy(25000);
    ok(getVT(d) === "VT_R8", "vt v_cy(25000) = " + getVT(d));
    ok(getVT(+d) === "VT_R8", "vt +v_cy(25000) = " + getVT(d));
    ok(d === 2.5, "v_cy(25000) !== 2.5\n");
    ok("" + d === "2.5", "str(v_cy(25000)) = " + d);
})();

function testRecFunc(x) {
    ok(testRecFunc.arguments === arguments, "testRecFunc.arguments = " + testRecFunc.arguments);
    if(x) {
        testRecFunc(false);
        ok(testRecFunc.arguments === arguments, "testRecFunc.arguments = " + testRecFunc.arguments);
        ok(testRecFunc.arguments[0] === true, "testRecFunc.arguments.x = " + testRecFunc.arguments[0]);
    }
}

testRecFunc.arguments = 5;
ok(testRecFunc.arguments === null, "testRecFunc.arguments = " + testRecFunc.arguments);
testRecFunc(true);
ok(testRecFunc.arguments === null, "testRecFunc.arguments = " + testRecFunc.arguments);

function argumentsTest() {
    var save = arguments;
    with({arguments: 1}) {
        ok(arguments === 1, "arguments = " + arguments);
        (function() {
            ok(argumentsTest.arguments === save, "unexpected argumentsTest.arguments");
        })();
    }
    eval('ok(arguments === save, "unexpected arguments");');
    [1,2].sort(function() {
        ok(argumentsTest.arguments === save, "unexpected argumentsTest.arguments");
        return 1;
    });
}

argumentsTest();

// arguments object detached from its execution context
(function() {
    var args, get_x, set_x;

    function test_args(detached) {
        ok(args[0] === 1, "args[0] = " + args[0]);
        set_x(2);
        ok(args[0] === (detached ? 1 : 2), "args[0] = " + args[0] + " expected " + (detached ? 1 : 2));
        args[0] = 3;
        ok(get_x() === (detached ? 2 : 3), "get_x() = " + get_x());
        ok(args[0] === 3, "args[0] = " + args[0]);
    }

    (function(x) {
        args = arguments;
        get_x = function() { return x; };
        set_x = function(v) { x = v; };

        test_args(false);
        x = 1;
    })(1);

    test_args(true);
})();

// arguments is a regular variable, it may be overwritten
(function() {
    ok(typeof(arguments) === "object", "typeof(arguments) = " + typeof(arguments));
    arguments = 1;
    ok(arguments === 1, "arguments = " + arguments);
})();

// duplicated argument names are shadowed by the last argument with the same name
(function() {
    var args, get_a, set_a;

    (function(a, a, b, c) {
        get_a = function() { return a; }
        set_a = function(v) { a = v; }
        ok(get_a() === 2, "function(a, a, b, c) get_a() = " + get_a());
        ok(a === 2, "function(a, a, b, c) a = " + a);
        ok(b === 3, "function(a, a, b, c) b = " + b);
        ok(c === 4, "function(a, a, b, c) c = " + c);
        a = 42;
        ok(arguments[0] === 1, "function(a, a, b, c) arguments[0] = " + arguments[0]);
        ok(arguments[1] === 42, "function(a, a, b, c) arguments[1] = " + arguments[1]);
        ok(get_a() === 42, "function(a, a, b, c) get_a() = " + get_a() + " expected 42");
        args = arguments;
    })(1, 2, 3, 4);

    ok(get_a() === 42, "function(a, a, b, c) get_a() after detach = " + get_a());
    set_a(100);
    ok(get_a() === 100, "function(a, a, b, c) get_a() = " + get_a() + " expected 100");
    ok(args[0] === 1, "function(a, a, b, c) detached args[0] = " + args[0]);
    ok(args[1] === 42, "function(a, a, b, c) detached args[1] = " + args[1]);

    (function(a, a) {
        eval("var a = 7;");
        ok(a === 7, "function(a, a) a = " + a);
        ok(arguments[0] === 5, "function(a, a) arguments[0] = " + arguments[0]);
        ok(arguments[1] === 7, "function(a, a) arguments[1] = " + arguments[1]);
    })(5, 6);
})();

(function callAsExprTest() {
    ok(callAsExprTest.arguments === null, "callAsExprTest.arguments = " + callAsExprTest.arguments);
})(1,2);

tmp = ((function() { var f = function() {return this}; return (function() { return f(); }); })())();
ok(tmp === this, "detached scope function call this != global this");

tmp = (function() {1;})();
ok(tmp === undefined, "tmp = " + tmp);
tmp = eval("1;");
ok(tmp === 1, "tmp = " + tmp);
tmp = eval("1,2;");
ok(tmp === 2, "tmp = " + tmp);
tmp = eval("testNoRes(),2;");
ok(tmp === 2, "tmp = " + tmp);
tmp = eval("if(true) {3}");
ok(tmp === 3, "tmp = " + tmp);
eval("testRes(); testRes()");
tmp = eval("3; if(false) {4;} else {};;;")
ok(tmp === 3, "tmp = " + tmp);
tmp = eval("try { 1; } finally { 2; }")
ok(tmp === 2, "tmp = " + tmp);

testNoRes();
testRes() && testRes();
testNoRes(), testNoRes();

(function() {
    eval("var x=1;");
    ok(x === 1, "x = " + x);
})();

(function() {
    var e = eval;
    var r = e(1);
    ok(r === 1, "r = " + r);
    (function(x, a) { x(a); })(eval, "2");
})();

(function(r) {
    r = eval("1");
    ok(r === 1, "r = " + r);
    (function(x, a) { x(a); })(eval, "2");
})();

tmp = (function(){ return testNoRes(), testRes();})();

var f1, f2;

ok(funcexpr() == 2, "funcexpr() = " + funcexpr());

f1 = function funcexpr() { return 1; }
ok(f1 != funcexpr, "f1 == funcexpr");
ok(f1() === 1, "f1() = " + f1());

f2 = function funcexpr() { return 2; }
ok(f2 != funcexpr, "f2 != funcexpr");
ok(f2() === 2, "f2() = " + f2());

f1 = null;
for(i = 0; i < 3; i++) {
    f2 = function funcexpr2() {};
    ok(f1 != f2, "f1 == f2");
    f1 = f2;
}

f1 = null;
for(i = 0; i < 3; i++) {
    f2 = function() {};
    ok(f1 != f2, "f1 == f2");
    f1 = f2;
}

(function() {
    ok(infuncexpr() == 2, "infuncexpr() = " + infuncexpr());

    f1 = function infuncexpr() { return 1; }
    ok(f1 != funcexpr, "f1 == funcexpr");
    ok(f1() === 1, "f1() = " + f1());

    f2 = function infuncexpr() { return 2; }
    ok(f2 != funcexpr, "f2 != funcexpr");
    ok(f2() === 2, "f2() = " + f2());

    f1 = null;
    for(i = 0; i < 3; i++) {
        f2 = function infuncexpr2() {};
        ok(f1 != f2, "f1 == f2");
        f1 = f2;
    }

    f1 = null;
    for(i = 0; i < 3; i++) {
        f2 = function() {};
        ok(f1 != f2, "f1 == f2");
        f1 = f2;
    }
})();

var obj1 = new Object();
ok(typeof(obj1) === "object", "typeof(obj1) is not object");
ok(obj1.constructor === Object, "unexpected obj1.constructor");
obj1.test = true;
obj1.func = function () {
    ok(this === obj1, "this is not obj1");
    ok(this.test === true, "this.test is not true");
    ok(arguments.length === 1, "arguments.length is not 1");
    ok(arguments["0"] === true, "arguments[0] is not true");
    ok(typeof(arguments.callee) === "function", "typeof(arguments.calee) = " + typeof(arguments.calee));
    ok(arguments.caller === null, "arguments.caller = " + arguments.caller);
    function test_caller() { ok(arguments.caller === foobar.arguments, "nested arguments.caller = " + arguments.caller); }
    function foobar() { test_caller(); } foobar();

    return "test";
};

ok(obj1.func(true) === "test", "obj1.func(true) is not \"test\"");

function testConstr1() {
    this.var1 = 1;

    ok(this !== undefined, "this is undefined");
    ok(arguments.length === 1, "arguments.length is not 1");
    ok(arguments["0"] === true, "arguments[0] is not 1");
    ok(arguments.callee === testConstr1, "arguments.calee !== testConstr1");

    return false;
}

testConstr1.prototype.pvar = 1;
ok(testConstr1.prototype.constructor === testConstr1, "testConstr1.prototype.constructor !== testConstr1");

var obj2 = new testConstr1(true);
ok(typeof(obj2) === "object", "typeof(obj2) is not object");
ok(obj2.constructor === testConstr1, "unexpected obj2.constructor");
ok(obj2.pvar === 1, "obj2.pvar is not 1");
ok(!obj2.hasOwnProperty('constructor'), "obj2.hasOwnProperty('constructor')");

testConstr1.prototype.pvar = 2;
ok(obj2.pvar === 2, "obj2.pvar is not 2");

obj2.pvar = 3;
testConstr1.prototype.pvar = 1;
ok(obj2.pvar === 3, "obj2.pvar is not 3");

obj1 = new Object();
function testConstr3() {
    return obj1;
}

obj2 = new testConstr3();
ok(obj1 === obj2, "obj1 != obj2");

function testConstr4() {
    return 2;
}

obj2 = new testConstr3();
ok(typeof(obj2) === "object", "typeof(obj2) = " + typeof(obj2));

var obj3 = new Object;
ok(typeof(obj3) === "object", "typeof(obj3) is not object");

(function() {
    ok(typeof(func) === "function", "typeof(func) = " + typeof(func));
    function func() {}
    ok(typeof(func) === "function", "typeof(func) = " + typeof(func));
    func = 0;
    ok(typeof(func) === "number", "typeof(func) = " + typeof(func));
})();

(function(f) {
    ok(typeof(f) === "function", "typeof(f) = " + typeof(f));
    function f() {};
    ok(typeof(f) === "function", "typeof(f) = " + typeof(f));
})(1);

for(var iter in "test")
    ok(false, "unexpected forin call, test = " + iter);

for(var iter in null)
    ok(false, "unexpected forin call, test = " + iter);

for(var iter in false)
    ok(false, "unexpected forin call, test = " + iter);

for(var iter in pureDisp)
    ok(false, "unexpected forin call in pureDisp object");

tmp = new Object();
ok(!tmp.nonexistent, "!tmp.nonexistent = " + !tmp.nonexistent);
ok(!("nonexistent" in tmp), "nonexistent is in tmp after '!' expression")

tmp = new Object();
ok((~tmp.nonexistent) === -1, "!tmp.nonexistent = " + ~tmp.nonexistent);
ok(!("nonexistent" in tmp), "nonexistent is in tmp after '~' expression")

tmp = new Object();
ok(isNaN(+tmp.nonexistent), "!tmp.nonexistent = " + (+tmp.nonexistent));
ok(!("nonexistent" in tmp), "nonexistent is in tmp after '+' expression")

tmp = new Object();
tmp[tmp.nonexistent];
ok(!("nonexistent" in tmp), "nonexistent is in tmp after array expression")

tmp = 0;
if(true)
    tmp = 1;
else
    ok(false, "else evaluated");
ok(tmp === 1, "tmp !== 1, if not evaluated?");

tmp = 0;
if(1 === 0)
    ok(false, "if evaluated");
else
    tmp = 1;
ok(tmp === 1, "tmp !== 1, if not evaluated?");

if(false)
    ok(false, "if(false) evaluated");

tmp = 0;
if(true)
    tmp = 1;
ok(tmp === 1, "tmp !== 1, if(true) not evaluated?");

if(false) {
}else {
}

var obj3 = { prop1: 1,  prop2: typeof(false) };
ok(obj3.prop1 === 1, "obj3.prop1 is not 1");
ok(obj3.prop2 === "boolean", "obj3.prop2 is not \"boolean\"");
ok(obj3.constructor === Object, "unexpected obj3.constructor");

if(invokeVersion >= 2) {
    eval("tmp = {prop: 'value',}");
    ok(tmp.prop === "value", "tmp.prop = " + tmp.prop);
    eval("tmp = {prop: 'value',second:2,}");
    ok(tmp.prop === "value", "tmp.prop = " + tmp.prop);
}else {
    try {
        eval("tmp = {prop: 'value',}");
    }catch(e) {
        tmp = true;
    }
    ok(tmp === true, "exception not fired");
}

{
    var blockVar = 1;
    blockVar = 2;
}
ok(blockVar === 2, "blockVar !== 2");

ok((true ? 1 : 2) === 1, "conditional expression true is not 1");
ok((0 === 2 ? 1 : 2) === 2, "conditional expression true is not 2");

ok(getVT(undefined) === "VT_EMPTY", "getVT(undefined) is not VT_EMPTY");
ok(getVT(null) === "VT_NULL", "getVT(null) is not VT_NULL");
ok(getVT(0) === "VT_I4", "getVT(0) is not VT_I4");
ok(getVT(0.5) === "VT_R8", "getVT(0.5) is not VT_R8");
ok(getVT("test") === "VT_BSTR", "getVT(\"test\") is not VT_BSTR");
ok(getVT(Math) === "VT_DISPATCH", "getVT(Math) is not VT_DISPATCH");
ok(getVT(false) === "VT_BOOL", "getVT(false) is not VT_BOOL");

tmp = 2+2;
ok(tmp === 4, "2+2 !== 4");
ok(getVT(tmp) === "VT_I4", "getVT(2+2) !== VT_I4");

tmp = 2+2.5;
ok(tmp === 4.5, "2+2.5 !== 4.5");
ok(getVT(tmp) === "VT_R8", "getVT(2+2.5) !== VT_R8");

tmp = 1.5+2.5;
ok(tmp === 4, "1.4+2.5 !== 4");
ok(getVT(tmp) === "VT_I4", "getVT(1.5+2.5) !== VT_I4");

tmp = 4-2;
ok(tmp === 2, "4-2 !== 2");
ok(getVT(tmp) === "VT_I4", "getVT(4-2) !== VT_I4");

tmp = 4.5-2;
ok(tmp === 2.5, "4.5-2 !== 2.5");
ok(getVT(tmp) === "VT_R8", "getVT(4.5-2) !== VT_R8");

tmp = -2;
ok(tmp === 0-2, "-2 !== 0-2");
ok(getVT(tmp) === "VT_I4", "getVT(-2) !== VT_I4");

tmp = 2*3;
ok(tmp === 6, "2*3 !== 6");
ok(getVT(tmp) === "VT_I4", "getVT(2*3) !== VT_I4");

tmp = 2*3.5;
ok(tmp === 7, "2*3.5 !== 7");
ok(getVT(tmp) === "VT_I4", "getVT(2*3.5) !== VT_I4");

tmp = 2.5*3.5;
/* FIXME: the parser loses precision */
/* ok(tmp === 8.75, "2.5*3.5 !== 8.75"); */
ok(tmp > 8.749999 && tmp < 8.750001, "2.5*3.5 !== 8.75");
ok(getVT(tmp) === "VT_R8", "getVT(2.5*3.5) !== VT_R8");

tmp = 2*.5;
ok(tmp === 1, "2*.5 !== 1");
ok(getVT(tmp) == "VT_I4", "getVT(2*.5) !== VT_I4");

tmp = 4/2;
ok(tmp === 2, "4/2 !== 2");
ok(getVT(tmp) === "VT_I4", "getVT(4/2) !== VT_I4");

tmp = 4.5/1.5;
ok(tmp === 3, "4.5/1.5 !== 3");
ok(getVT(tmp) === "VT_I4", "getVT(4.5/1.5) !== VT_I4");

tmp = 3/2;
ok(tmp === 1.5, "3/2 !== 1.5");
ok(getVT(tmp) === "VT_R8", "getVT(3/2) !== VT_R8");

tmp = 3%2;
ok(tmp === 1, "3%2 = " + tmp);

tmp = 4%2;
ok(tmp ===0, "4%2 = " + tmp);

tmp = 3.5%1.5;
ok(tmp === 0.5, "3.5%1.5 = " + tmp);

tmp = 3%true;
ok(tmp === 0, "3%true = " + tmp);

tmp = "ab" + "cd";
ok(tmp === "abcd", "\"ab\" + \"cd\" !== \"abcd\"");

tmp = 1;
ok((tmp += 1) === 2, "tmp += 1 !== 2");
ok(tmp === 2, "tmp !== 2");

tmp = 2;
ok((tmp -= 1) === 1, "tmp -= 1 !== 1");
ok(tmp === 1, "tmp !=== 1");

tmp = 2;
ok((tmp *= 1.5) === 3, "tmp *= 1.5 !== 3");
ok(tmp === 3, "tmp !=== 3");

tmp = 5;
ok((tmp /= 2) === 2.5, "tmp /= 2 !== 2.5");
ok(tmp === 2.5, "tmp !=== 2.5");

tmp = 3;
ok((tmp %= 2) === 1, "tmp %= 2 !== 1");
ok(tmp === 1, "tmp !== 1");

tmp = 8;
ok((tmp <<= 1) === 16, "tmp <<= 1 !== 16");

tmp = 8;
ok((tmp >>= 1) === 4, "tmp >>= 1 !== 4");

tmp = 8;
ok((tmp >>>= 1) === 4, "tmp >>>= 1 !== 4");

tmp = 3 || ok(false, "second or expression called");
ok(tmp === 3, "3 || (...) is not 3");

tmp = false || 2;
ok(tmp === 2, "false || 2 is not 2");

tmp = 0 && ok(false, "second and expression called");
ok(tmp === 0, "0 && (...) is not 0");

tmp = true && "test";
ok(tmp === "test", "true && \"test\" is not \"test\"");

tmp = true && 0;
ok(tmp === 0, "true && 0 is not 0");

tmp = 3 | 4;
ok(tmp === 7, "3 | 4 !== 7");
ok(getVT(tmp) === "VT_I4", "getVT(3|4) = " + getVT(tmp));

tmp = 3.5 | 0;
ok(tmp === 3, "3.5 | 0 !== 3");
ok(getVT(tmp) === "VT_I4", "getVT(3.5|0) = " + getVT(tmp));

tmp = -3.5 | 0;
ok(tmp === -3, "-3.5 | 0 !== -3");
ok(getVT(tmp) === "VT_I4", "getVT(3.5|0) = " + getVT(tmp));

tmp = 0 | NaN;
ok(tmp === 0, "0 | NaN = " + tmp);

tmp = 0 | Infinity;
ok(tmp === 0, "0 | NaN = " + tmp);

tmp = 0 | (-Infinity);
ok(tmp === 0, "0 | NaN = " + tmp);

tmp = 10;
ok((tmp |= 0x10) === 26, "tmp(10) |= 0x10 !== 26");
ok(getVT(tmp) === "VT_I4", "getVT(tmp |= 10) = " + getVT(tmp));

tmp = (123 * Math.pow(2,32) + 2) | 0;
ok(tmp === 2, "123*2^32+2 | 0 = " + tmp);

tmp = (-123 * Math.pow(2,32) + 2) | 0;
ok(tmp === 2, "123*2^32+2 | 0 = " + tmp);

tmp = 3 & 5;
ok(tmp === 1, "3 & 5 !== 1");
ok(getVT(tmp) === "VT_I4", "getVT(3|5) = " + getVT(tmp));

tmp = 3.5 & 0xffff;
ok(tmp === 3, "3.5 & 0xffff !== 3 ");
ok(getVT(tmp) === "VT_I4", "getVT(3.5&0xffff) = " + getVT(tmp));

tmp = (-3.5) & 0xffffffff;
ok(tmp === -3, "-3.5 & 0xffff !== -3");
ok(getVT(tmp) === "VT_I4", "getVT(3.5&0xffff) = " + getVT(tmp));

tmp = 2 << 3;
ok(tmp === 16, "2 << 3 = " + tmp);

tmp = 2 << 35;
ok(tmp === 16, "2 << 35 = " + tmp);

tmp = 8 >> 2;
ok(tmp === 2, "8 >> 2 = " + tmp);

tmp = -64 >> 4;
ok(tmp === -4, "-64 >> 4 = " + tmp);

tmp = 8 >>> 2;
ok(tmp === 2, "8 >> 2 = " + tmp);

tmp = -64 >>> 4;
ok(tmp === 0x0ffffffc, "-64 >>> 4 = " + tmp);

tmp = 4 >>> NaN;
ok(tmp === 4, "4 >>> NaN = " + tmp);

tmp = 10;
ok((tmp &= 8) === 8, "tmp(10) &= 8 !== 8");
ok(getVT(tmp) === "VT_I4", "getVT(tmp &= 8) = " + getVT(tmp));

tmp = 0xf0f0^0xff00;
ok(tmp === 0x0ff0, "0xf0f0^0xff00 !== 0x0ff0");
ok(getVT(tmp) === "VT_I4", "getVT(0xf0f0^0xff00) = " + getVT(tmp));

tmp = 5;
ok((tmp ^= 3) === 6, "tmp(5) ^= 3 !== 6");
ok(getVT(tmp) === "VT_I4", "getVT(tmp ^= 3) = " + getVT(tmp));

tmp = ~1;
ok(tmp === -2, "~1 !== -2");
ok(getVT(tmp) === "VT_I4", "getVT(~1) = " + getVT(tmp));

ok((3,4) === 4, "(3,4) !== 4");

ok(+3 === 3, "+3 !== 3");
ok(+true === 1, "+true !== 1");
ok(+false === 0, "+false !== 0");
ok(+null === 0, "+null !== 0");
ok(+"0" === 0, "+'0' !== 0");
ok(+"3" === 3, "+'3' !== 3");
ok(+"-3" === -3, "+'-3' !== -3");
ok(+"0xff" === 255, "+'0xff' !== 255");
ok(+"3e3" === 3000, "+'3e3' !== 3000");

tmp = new Number(1);
ok(+tmp === 1, "+(new Number(1)) = " + (+tmp));
ok(tmp.constructor === Number, "unexpected tmp.constructor");
tmp = new String("1");
ok(+tmp === 1, "+(new String('1')) = " + (+tmp));
ok(tmp.constructor === String, "unexpected tmp.constructor");

ok("" + 0 === "0", "\"\" + 0 !== \"0\"");
ok("" + 123 === "123", "\"\" + 123 !== \"123\"");
ok("" + (-5) === "-5", "\"\" + (-5) !== \"-5\"");
ok("" + null === "null", "\"\" + null !== \"null\"");
ok("" + undefined === "undefined", "\"\" + undefined !== \"undefined\"");
ok("" + true === "true", "\"\" + true !== \"true\"");
ok("" + false === "false", "\"\" + false !== \"false\"");
ok("" + 0.5 === "0.5", "'' + 0.5 = " + 0.5);
ok("" + (-0.5432) === "-0.5432", "'' + (-0.5432) = " + (-0.5432));

ok(1 < 3.4, "1 < 3.4 failed");
ok(!(3.4 < 1), "3.4 < 1");
ok("abc" < "abcd", "abc < abcd failed");
ok("abcd" < "abce", "abce < abce failed");
ok("" < "x", "\"\" < \"x\" failed");
ok(!(0 < 0), "0 < 0");

ok(1 <= 3.4, "1 <= 3.4 failed");
ok(!(3.4 <= 1), "3.4 <= 1");
ok("abc" <= "abcd", "abc <= abcd failed");
ok("abcd" <= "abce", "abce <= abce failed");
ok("" <= "x", "\"\" <= \"x\" failed");
ok(0 <= 0, "0 <= 0 failed");

ok(3.4 > 1, "3.4 > 1 failed");
ok(!(1 > 3.4), "1 > 3.4");
ok("abcd" > "abc", "abc > abcd failed");
ok("abce" > "abcd", "abce > abce failed");
ok("x" > "", "\"x\" > \"\" failed");
ok(!(0 > 0), "0 > 0");

ok(3.4 >= 1, "3.4 >= 1 failed");
ok(!(1 >= 3.4), "1 >= 3.4");
ok("abcd" >= "abc", "abc >= abcd failed");
ok("abce" >= "abcd", "abce >= abce failed");
ok("x" >= "", "\"x\" >= \"\" failed");
ok(0 >= 0, "0 >= 0");

tmp = 1;
ok(++tmp === 2, "++tmp (1) is not 2");
ok(tmp === 2, "incremented tmp is not 2");
ok(--tmp === 1, "--tmp (2) is not 1");
ok(tmp === 1, "decremented tmp is not 1");
ok(tmp++ === 1, "tmp++ (1) is not 1");
ok(tmp === 2, "incremented tmp(1) is not 2");
ok(tmp-- === 2, "tmp-- (2) is not 2");
ok(tmp === 1, "decremented tmp is not 1");

tmp = new Object();
tmp.iii++;
ok(isNaN(tmp.iii), "tmp.iii = " + tmp.iii);

String.prototype.test = true;
ok("".test === true, "\"\".test is not true");

Boolean.prototype.test = true;
ok(true.test === true, "true.test is not true");

Number.prototype.test = true;
ok((0).test === true, "(0).test is not true");
ok((0.5).test === true, "(0.5).test is not true");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
}catch(ex) {
    ok(false, "unexpected catch");
}
ok(state === "try", "state = " + state + " expected try");

state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
}finally {
    ok(state === "try", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

state = "";
try {
    try {
        throw 0;
    }finally {
        state = "finally";
    }
}catch(e) {
    ok(state === "finally", "state = " + state + " expected finally");
    state = "catch";
}
ok(state === "catch", "state = " + state + " expected catch");

try {
    try {
        throw 0;
    }finally {
        throw 1;
    }
}catch(e) {
    ok(e === 1, "e = " + e);
}

state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
}catch(ex) {
    ok(false, "unexpected catch");
}finally {
    ok(state === "try", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    throw "except";
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === "except", "ex is not \"except\"");
    state = "catch";
}
ok(state === "catch", "state = " + state + " expected catch");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    throw true;
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === true, "ex is not true");
    state = "catch";
}finally {
    ok(state === "catch", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    try { throw true; } finally {}
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === true, "ex is not true");
    state = "catch";
}finally {
    ok(state === "catch", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    try { throw "except"; } catch(ex) { throw true; }
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === true, "ex is not true");
    state = "catch";
}finally {
    ok(state === "catch", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

function throwFunc(x) {
    throw x;
}

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    throwFunc(true);
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === true, "ex is not true");
    state = "catch";
}finally {
    ok(state === "catch", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

state = "";
switch(1) {
case "1":
    ok(false, "unexpected case \"1\"");
case 1:
    ok(state === "", "case 1: state = " + state);
    state = "1";
default:
    ok(state === "1", "default: state = " + state);
    state = "default";
case false:
    ok(state === "default", "case false: state = " + state);
    state = "false";
}
ok(state === "false", "state = " + state);

state = "";
switch("") {
case "1":
case 1:
    ok(false, "unexpected case 1");
default:
    ok(state === "", "default: state = " + state);
    state = "default";
case false:
    ok(state === "default", "case false: state = " + state);
    state = "false";
}
ok(state === "false", "state = " + state);

state = "";
switch(1) {
case "1":
    ok(false, "unexpected case \"1\"");
case 1:
    ok(state === "", "case 1: state = " + state);
    state = "1";
default:
    ok(state === "1", "default: state = " + state);
    state = "default";
    break;
case false:
    ok(false, "unexpected case false");
}
ok(state === "default", "state = " + state);

switch(1) {
case 2:
    ok(false, "unexpected case 2");
case 3:
    ok(false, "unexpected case 3");
}

switch(1) {
case 2:
    ok(false, "unexpected case 2");
    break;
default:
    /* empty default */
}

switch(2) {
default:
    ok(false, "unexpected default");
    break;
case 2:
    /* empty case */
};

switch(2) {
default:
    ok(false, "unexpected default");
    break;
case 1:
case 2:
case 3:
    /* empty case */
};

(function() {
    var i=0;

    switch(1) {
    case 1:
        i++;
    }
    return i;
})();

(function() {
    var ret, x;

    function unreachable() {
        ok(false, "unreachable");
    }

    function expect(value, expect_value) {
        ok(value === expect_value, "got " + value + " expected " + expect_value);
    }

    ret = (function() {
        try {
            return "try";
            unreachable();
        }catch(e) {
            unreachable();
        }finally {
            return "finally";
            unreachable();
        }
        unreachable();
    })();
    expect(ret, "finally");

    x = "";
    ret = (function() {
        try {
            x += "try,";
            return x;
            unreachable();
        }catch(e) {
            unreachable();
        }finally {
            x += "finally,";
        }
        unreachable();
    })();
    expect(ret, "try,");
    expect(x, "try,finally,");

    x = "";
    ret = (function() {
        try {
            x += "try,"
            throw 1;
            unreachable();
        }catch(e) {
            x += "catch,";
            return "catch";
            unreachable();
        }finally {
            x += "finally,";
            return "finally";
            unreachable();
        }
        unreachable();
    })();
    expect(ret, "finally");
    expect(x, "try,catch,finally,");

    x = "";
    ret = (function() {
        try {
            x += "try,"
            throw 1;
            unreachable();
        }catch(e) {
            x += "catch,";
            return "catch";
            unreachable();
        }finally {
            x += "finally,";
        }
        unreachable();
    })();
    expect(ret, "catch");
    expect(x, "try,catch,finally,");

    x = "";
    ret = (function() {
        try {
            x += "try,"
            try {
                x += "try2,";
                return "try2";
            }catch(e) {
                unreachable();
            }finally {
                x += "finally2,";
            }
            unreachable();
        }catch(e) {
            unreachable();
        }finally {
            x += "finally,";
        }
        unreachable();
    })();
    expect(ret, "try2");
    expect(x, "try,try2,finally2,finally,");

    x = "";
    ret = (function() {
        while(true) {
            try {
                x += "try,"
                try {
                    x += "try2,";
                    break;
                }catch(e) {
                    unreachable();
                }finally {
                    x += "finally2,";
                }
                unreachable();
            }catch(e) {
                unreachable();
            }finally {
                x += "finally,";
            }
            unreachable();
        }
        x += "ret";
        return "ret";
    })();
    expect(ret, "ret");
    expect(x, "try,try2,finally2,finally,ret");

    x = "";
    ret = (function() {
        while(true) {
            try {
                x += "try,"
                try {
                    x += "try2,";
                    continue;
                }catch(e) {
                    unreachable();
                }finally {
                    x += "finally2,";
                }
                unreachable();
            }catch(e) {
                unreachable();
            }finally {
                x += "finally,";
                break;
            }
            unreachable();
        }
        x += "ret";
        return "ret";
    })();
    expect(ret, "ret");
    expect(x, "try,try2,finally2,finally,ret");

    ret = (function() {
        try {
            return "try";
            unreachable();
        }catch(e) {
            unreachable();
        }finally {
            new Object();
            var tmp = (function() {
                var s = new String();
                try {
                    s.length;
                }finally {
                    return 1;
                }
            })();
        }
        unreachable();
    })();
    expect(ret, "try");
})();

(function() {
    var e;
    var E_FAIL = -2147467259;
    var JS_E_SUBSCRIPT_OUT_OF_RANGE = -2146828279;

    try {
        throwInt(E_FAIL);
    }catch(ex) {
        e = ex;
    }
    ok(e.name === "Error", "e.name = " + e.name);
    ok(e.message === "", "e.message = " + e.message);
    ok(e.number === E_FAIL, "e.number = " + e.number);

    try {
        throwInt(JS_E_SUBSCRIPT_OUT_OF_RANGE);
    }catch(ex) {
        e = ex;
    }
    ok(e.name === "RangeError", "e.name = " + e.name);
    ok(e.number === JS_E_SUBSCRIPT_OUT_OF_RANGE, "e.number = " + e.number);

    try {
        throwEI(JS_E_SUBSCRIPT_OUT_OF_RANGE);
    }catch(ex) {
        e = ex;
    }
    ok(e.name === "RangeError", "e.name = " + e.name);
    ok(e.number === JS_E_SUBSCRIPT_OUT_OF_RANGE, "e.number = " + e.number);
})();

tmp = eval("1");
ok(tmp === 1, "eval(\"1\") !== 1");
eval("{ ok(tmp === 1, 'eval: tmp !== 1'); } tmp = 2;");
ok(tmp === 2, "tmp !== 2");

ok(eval(false) === false, "eval(false) !== false");
ok(eval() === undefined, "eval() !== undefined");

tmp = eval("1", "2");
ok(tmp === 1, "eval(\"1\", \"2\") !== 1");

var state = "";
try {
    ok(state === "", "try: state = " + state);
    state = "try";
    eval("throwFunc(true);");
}catch(ex) {
    ok(state === "try", "catch: state = " + state);
    ok(ex === true, "ex is not true");
    state = "catch";
}finally {
    ok(state === "catch", "finally: state = " + state);
    state = "finally";
}
ok(state === "finally", "state = " + state + " expected finally");

tmp = [,,1,2,,,true];
ok(tmp.length === 7, "tmp.length !== 7");
ok(tmp["0"] === undefined, "tmp[0] is not undefined");
ok(tmp["3"] === 2, "tmp[3] !== 2");
ok(tmp["6"] === true, "tmp[6] !== true");
ok(tmp[2] === 1, "tmp[2] !== 1");
ok(!("0" in tmp), "0 found in array");
ok(!("1" in tmp), "1 found in array");
ok("2" in tmp, "2 not found in array");
ok(!("2" in [1,,,,]), "2 found in [1,,,,]");

ok([1,].length === 2, "[1,].length !== 2");
ok([,,].length === 3, "[,,].length !== 3");
ok([,].length === 2, "[].length != 2");
ok([].length === 0, "[].length != 0");

tmp = 0;
while(tmp < 4) {
    ok(tmp < 4, "tmp >= 4");
    tmp++;
}
ok(tmp === 4, "tmp !== 4");

tmp = 0;
while(true) {
    ok(tmp < 4, "tmp >= 4");
    tmp++;
    if(tmp === 4) {
        break;
        ok(false, "break did not break");
    }
}
ok(tmp === 4, "tmp !== 4");

tmp = 0;
do {
    ok(tmp < 4, "tmp >= 4");
    tmp++;
} while(tmp < 4);
ok(tmp === 4, "tmp !== 4");

tmp = 0;
do {
    ok(tmp === 0, "tmp !=== 0");
    tmp++;
} while(false);
ok(tmp === 1, "tmp !== 1");

tmp = 0;
do {
    ok(tmp < 4, "tmp >= 4");
    tmp++;
} while(tmp < 4)
ok(tmp === 4, "tmp !== 4")

tmp = 0;
while(tmp < 4) {
    tmp++;
    if(tmp === 2) {
        continue;
        ok(false, "break did not break");
    }
    ok(tmp <= 4 && tmp != 2, "tmp = " + tmp);
}
ok(tmp === 4, "tmp !== 4");

for(tmp=0; tmp < 4; tmp++)
    ok(tmp < 4, "tmp = " + tmp);
ok(tmp === 4, "tmp !== 4");

for(tmp=0; tmp < 4; tmp++) {
    if(tmp === 2)
        break;
    ok(tmp < 2, "tmp = " + tmp);
}
ok(tmp === 2, "tmp !== 2");

for(tmp=0; tmp < 4; tmp++) {
    if(tmp === 2)
        continue;
    ok(tmp < 4 && tmp != 2, "tmp = " + tmp);
}
ok(tmp === 4, "tmp !== 4");

for(var fi=0; fi < 4; fi++)
    ok(fi < 4, "fi = " + fi);
ok(fi === 4, "fi !== 4");

tmp = true;
obj1 = new Object();
for(obj1.nonexistent; tmp; tmp = false)
    ok(!("nonexistent" in obj1), "nonexistent added to obj1");

obj1 = new Object();
for(tmp in obj1.nonexistent)
    ok(false, "for(tmp in obj1.nonexistent) called with tmp = " + tmp);
ok(!("nonexistent" in obj1), "nonexistent added to obj1 by for..in loop");


var i, j;

/* Previous versions have broken finally block implementation */
if(ScriptEngineMinorVersion() >= 8) {
    tmp = "";
    i = 0;
    while(true) {
        tmp += "1";
        for(i = 1; i < 3; i++) {
            switch(i) {
            case 1:
                tmp += "2";
                continue;
            case 2:
                tmp += "3";
                try {
                    throw null;
                }finally {
                    tmp += "4";
                    break;
                }
            default:
                ok(false, "unexpected state");
            }
            tmp += "5";
        }
        with({prop: "6"}) {
            tmp += prop;
            break;
        }
    }
    ok(tmp === "123456", "tmp = " + tmp);
}

tmp = "";
i = 0;
for(j in [1,2,3]) {
    tmp += "1";
    for(;;) {
        with({prop: "2"}) {
            tmp += prop;
            try {
                throw "3";
            }catch(e) {
                tmp += e;
                with([0])
                    break;
            }
        }
        ok(false, "unexpected state");
    }
    while(true) {
        tmp += "4";
        break;
    }
    break;
}
ok(tmp === "1234", "tmp = " + tmp);

tmp = 0;
for(var iter in [1,2,3]) {
    tmp += +iter;
    continue;
}
ok(tmp === 3, "tmp = " + tmp);

tmp = false;
for(var iter in [1,2,3]) {
    switch(+iter) {
    case 1:
        tmp = true;
        try {
            continue;
        }finally {}
    default:
        continue;
    }
}
ok(tmp, "tmp = " + tmp);

loop_label:
while(true) {
    while(true)
        break loop_label;
}

loop_label: {
    tmp = 0;
    while(true) {
        while(true)
            break loop_label;
    }
    ok(false, "unexpected evaluation 1");
}

while(true) {
    some_label: break;
    ok(false, "unexpected evaluation 2");
}

just_label: tmp = 1;
ok(tmp === 1, "tmp != 1");

some_label: break some_label;

other_label: {
    break other_label;
    ok(false, "unexpected evaluation 3");
}

loop_label:
do {
    while(true)
        continue loop_label;
}while(false);

loop_label:
for(i = 0; i < 3; i++) {
    while(true)
        continue loop_label;
}

loop_label:
other_label:
for(i = 0; i < 3; i++) {
    while(true)
        continue loop_label;
}

loop_label:
for(tmp in {prop: false}) {
    while(true)
        continue loop_label;
}

ok((void 1) === undefined, "(void 1) !== undefined");

var inobj = new Object();

for(var iter in inobj)
    ok(false, "unexpected iter = " + iter);

inobj.test = true;
tmp = 0;
for(iter in inobj) {
    ok(iter == "test", "unexpected iter = " + iter);
    tmp++;
}
ok(tmp === 1, "for..in tmp = " + tmp);

function forinTestObj() {}

forinTestObj.prototype.test3 = true;

var arr = new Array();
inobj = new forinTestObj();
inobj.test1 = true;
inobj.test2 = true;

tmp = 0;
for(iter in inobj) {
    forinTestObj.prototype.test4 = true;
    arr[iter] = true;
    tmp++;
}

ok(tmp === 3, "for..in tmp = " + tmp);
ok(arr["test1"] === true, "arr[test1] !== true");
ok(arr["test2"] === true, "arr[test2] !== true");
ok(arr["test3"] === true, "arr[test3] !== true");
ok(arr["test4"] !== true, "arr[test4] === true");

ok((delete inobj.test1) === true, "delete inobj.test1 returned false");
ok(!("test1" in inobj), "test1 is still in inobj after delete");
ok((delete inobj.test3) === true, "delete inobj.test3 returned false");
ok("test3" in inobj, "test3 is not in inobj after delete");
ok((delete forinTestObj.prototype.test3) === true, "delete forinTestObj.prototype.test3 returned false");
ok(!("test3" in inobj), "test3 is still in inobj after delete on prototype");

tmp = new Object();
tmp.test = false;
ok((delete tmp.test) === true, "delete returned false");
ok(typeof(tmp.test) === "undefined", "tmp.test type = " + typeof(tmp.test));
ok(!("test" in tmp), "test is still in tmp after delete?");
for(iter in tmp)
    ok(false, "tmp has prop " + iter);
ok((delete tmp.test) === true, "deleting test didn't return true");
ok((delete tmp.nonexistent) === true, "deleting nonexistent didn't return true");
ok((delete nonexistent) === true, "deleting nonexistent didn't return true");

tmp = new Object();
tmp.test = false;
ok((delete tmp["test"]) === true, "delete returned false");
ok(typeof(tmp.test) === "undefined", "tmp.test type = " + typeof(tmp.test));
ok(!("test" in tmp), "test is still in tmp after delete?");

arr = [1, 2, 3];
ok(arr.length === 3, "arr.length = " + arr.length);
ok((delete arr.length) === false, "delete arr.length returned true");
ok("reverse" in arr, "reverse not in arr");
ok((delete Array.prototype.reverse) === true, "delete Array.prototype.reverse returned false");
ok(!("reverse" in arr), "reverse is still in arr after delete from prototype");

tmp.testWith = true;
with(tmp)
    ok(testWith === true, "testWith !== true");

function withScopeTest()
{
    var a = 3;
    with({a : 2})
    {
        ok(a == 2, "withScopeTest: a != 2");
        function func()
        {
            ok(a == 3, "withScopeTest: func: a != 3");
        }
        func();
        eval('ok(a == 2, "withScopeTest: eval: a != 2");');
    }
}
withScopeTest();

if(false) {
    var varTest1 = true;
}

ok(varTest1 === undefined, "varTest1 = " + varTest1);
ok(varTest2 === undefined, "varTest2 = " + varTest1);

var varTest2;

function varTestFunc(varTest3) {
    var varTest3;

    ok(varTest3 === 3, "varTest3 = " + varTest3);
    ok(varTest4 === undefined, "varTest4 = " + varTest4);

    var varTest4;
}

varTestFunc(3);

deleteTest = 1;
delete deleteTest;
try {
    tmp = deleteTest;
    ok(false, "deleteTest did not throw an exception?");
}catch(ex) {}

(function() {
    var to_delete = 2;
    var r = delete to_delete;
    ok(r === false, "delete 1 returned " + r);
    if(r)
        return;
    ok(to_delete === 2, "to_delete = " + to_delete);

    to_delete = new Object();
    r = delete to_delete;
    ok(r === false, "delete 2 returned " + r);
    ok(typeof(to_delete) === "object", "typeof(to_delete) = " + typeof(to_delete));
})();

(function(to_delete) {
    var r = delete to_delete;
    ok(r === false, "delete 3 returned " + r);
    ok(to_delete === 2, "to_delete = " + to_delete);

    to_delete = new Object();
    r = delete to_delete;
    ok(r === false, "delete 4 returned " + r);
    ok(typeof(to_delete) === "object", "typeof(to_delete) = " + typeof(to_delete));
})(2);

(function() {
    with({to_delete: new Object()}) {
        var r = delete to_delete;
        ok(r === true, "delete returned " + r);
    }
})();

(function() {
    function constr() {}
    constr.prototype = { prop: 1 };
    var o = new constr(), r;
    ok(o.prop === 1, "o.prop = " + o.prop);
    r = delete constr.prototype.prop;
    ok(r === true, "delete returned " + r);
    ok(o.prop === undefined, "o.prop = " + o.prop);
    r = delete o["prop"];
    ok(r === true, "delete returned " + r);
})();

if (false)
    if (true)
        ok(false, "if evaluated");
    else
        ok(false, "else should be associated with nearest if statement");

if (true)
    if (false)
        ok(false, "if evaluated");
    else
        ok(true, "else should be associated with nearest if statement");

function instanceOfTest() {}
tmp = new instanceOfTest();

ok((tmp instanceof instanceOfTest) === true, "tmp is not instance of instanceOfTest");
ok((tmp instanceof Object) === true, "tmp is not instance of Object");
ok((tmp instanceof String) === false, "tmp is instance of String");
ok(instanceOfTest.isPrototypeOf(tmp) === false, "instanceOfTest is prototype of tmp");
ok(instanceOfTest.prototype.isPrototypeOf(tmp) === true, "instanceOfTest.prototype is not prototype of tmp");
ok(Object.prototype.isPrototypeOf(tmp) === true, "Object.prototype is not prototype of tmp");

instanceOfTest.prototype = new Object();
ok((tmp instanceof instanceOfTest) === false, "tmp is instance of instanceOfTest");
ok((tmp instanceof Object) === true, "tmp is not instance of Object");
ok(instanceOfTest.prototype.isPrototypeOf(tmp) === false, "instanceOfTest.prototype is prototype of tmp");

ok((1 instanceof Object) === false, "1 is instance of Object");
ok((false instanceof Boolean) === false, "false is instance of Boolean");
ok(("" instanceof Object) === false, "'' is instance of Object");
ok(Number.prototype.isPrototypeOf(1) === false, "Number.prototype is prototype of 1");
ok(String.prototype.isPrototypeOf("") === false, "String.prototype is prototype of ''");

ok(tmp.isPrototypeOf(null) === false, "tmp is prototype of null");
ok(tmp.isPrototypeOf(undefined) === false, "tmp is prototype of undefined");
ok(Object.prototype.isPrototypeOf.call(tmp) === false, "tmp is prototype of no argument");
ok(Object.prototype.isPrototypeOf.call(test, Object) === false, "test is prototype of Object");
ok(Object.prototype.isPrototypeOf.call(testObj, Object) === false, "testObj is prototype of Object");
ok(Object.prototype.isPrototypeOf(test) === false, "Object.prototype is prototype of test");
ok(Object.prototype.isPrototypeOf(testObj) === false, "Object.prototype is prototype of testObj");

(function () {
    ok((arguments instanceof Object) === true, "argument is not instance of Object");
    ok((arguments instanceof Array) === false, "argument is not instance of Array");
    ok(arguments.toString() === "[object Object]", "arguments.toString() = " + arguments.toString());
})(1,2);

obj = new String();
ok(("length" in obj) === true, "length is not in obj");
ok(("isPrototypeOf" in obj) === true, "isPrototypeOf is not in obj");
ok(("abc" in obj) === false, "test is in obj");
obj.abc = 1;
ok(("abc" in obj) === true, "test is not in obj");
ok(("1" in obj) === false, "1 is in obj");

obj = [1,2,3];
ok((1 in obj) === true, "1 is not in obj");

obj = new Object();
try {
    obj.prop["test"];
    ok(false, "expected exception");
}catch(e) {}
ok(!("prop" in obj), "prop in obj");

if(invokeVersion >= 2) {
    ok("test"[0] === "t", '"test"[0] = ' + test[0]);
    ok("test"[5] === undefined, '"test"[0] = ' + test[0]);

    tmp = "test";
    ok(tmp[1] === "e", "tmp[1] = " + tmp[1]);
    tmp[1] = "x";
    ok(tmp[1] === "e", "tmp[1] = " + tmp[1]);
    ok(tmp["1"] === "e", "tmp['1'] = " + tmp["1"]);
    ok(tmp["0x1"] === undefined, "tmp['0x1'] = " + tmp["0x1"]);
}else {
    ok("test"[0] === undefined, '"test"[0] = ' + test[0]);
}

ok(isNaN(NaN) === true, "isNaN(NaN) !== true");
ok(isNaN(0.5) === false, "isNaN(0.5) !== false");
ok(isNaN(Infinity) === false, "isNaN(Infinity) !== false");
ok(isNaN() === true, "isNaN() !== true");
ok(isNaN(NaN, 0) === true, "isNaN(NaN, 0) !== true");
ok(isNaN(0.5, NaN) === false, "isNaN(0.5, NaN) !== false");
ok(isNaN(+undefined) === true, "isNaN(+undefined) !== true");

ok(isFinite(0.5) === true, "isFinite(0.5) !== true");
ok(isFinite(Infinity) === false, "isFinite(Infinity) !== false");
ok(isFinite(-Infinity) === false, "isFinite(Infinity) !== false");
ok(isFinite(NaN) === false, "isFinite(NaN) !== false");
ok(isFinite(0.5, NaN) === true, "isFinite(0.5, NaN) !== true");
ok(isFinite(NaN, 0.5) === false, "isFinite(NaN, 0.5) !== false");
ok(isFinite() === false, "isFinite() !== false");

ok((1 < NaN) === false, "(1 < NaN) !== false");
ok((1 > NaN) === false, "(1 > NaN) !== false");
ok((1 <= NaN) === false, "(1 <= NaN) !== false");
ok((1 >= NaN) === false, "(1 >= NaN) !== false");
ok((NaN < 1) === false, "(NaN < 1) !== false");
ok((NaN > 1) === false, "(NaN > 1) !== false");
ok((NaN <= 1) === false, "(NaN <= 1) !== false");
ok((NaN >= 1) === false, "(NaN >= 1) !== false");
ok((Infinity < 2) === false, "(Infinity < 2) !== false");
ok((Infinity > 2) === true, "(Infinity > 2) !== true");
ok((-Infinity < 2) === true, "(-Infinity < 2) !== true");

ok(isNaN(+"test") === true, "isNaN(+'test') !== true");
ok(isNaN(+"123t") === true, "isNaN(+'123t') !== true");
ok(isNaN(+"Infinity x") === true, "isNaN(+'Infinity x') !== true");
ok(+"Infinity" === Infinity, "+'Infinity' !== Infinity");
ok(+" Infinity " === Infinity, "+' Infinity ' !== Infinity");
ok(+"-Infinity" === -Infinity, "+'-Infinity' !== -Infinity");

ok((NaN !== NaN) === true, "(NaN !== NaN) !== true");
ok((NaN === NaN) === false, "(NaN === NaN) !== false");
ok((Infinity !== NaN) === true, "(Infinity !== NaN) !== true");
ok((Infinity !== NaN) === true, "(Infinity !== NaN) !== true");
ok((0 === NaN) === false, "(0 === NaN) !== false");

ok((NaN != NaN) === true, "(NaN !== NaN) != true");
ok((NaN == NaN) === false, "(NaN === NaN) != false");
ok((Infinity != NaN) === true, "(Infinity != NaN) !== true");
ok((Infinity != NaN) === true, "(Infinity != NaN) !== true");
ok((0 == NaN) === false, "(0 === NaN) != false");

// escape tests
var escapeTests = [
    ["\'", "\\'", 39],
    ["\"", "\\\"", 34],
    ["\\", "\\\\", 92],
    ["\b", "\\b", 8],
    ["\t", "\\t", 9],
    ["\n", "\\n", 10],
    ["\v", "\\v", 118],
    ["\f", "\\f", 12],
    ["\r", "\\r", 13],
    ["\xf3", "\\xf3", 0xf3],
    ["\u1234", "\\u1234", 0x1234],
    ["\a", "\\a", 97],
    ["\?", "\\?", 63]
];

for(i=0; i<escapeTests.length; i++) {
    tmp = escapeTests[i][0].charCodeAt(0);
    ok(tmp === escapeTests[i][2], "escaped '" + escapeTests[i][1] + "' = " + tmp + " expected " + escapeTests[i][2]);
}

tmp = !+"\v1";
ok(tmp === true, '!+"\v1" = ' + tmp);

ok(typeof(testFunc2) === "function", "typeof(testFunc2) = " + typeof(testFunc2));
tmp = testFunc2(1);
ok(tmp === 2, "testFunc2(1) = " + tmp);
function testFunc2(x) { return x+1; }

ok(typeof(testFunc3) === "function", "typeof(testFunc3) = " + typeof(testFunc3));
tmp = testFunc3(1);
ok(tmp === 3, "testFunc3(1) = " + tmp);
tmp = function testFunc3(x) { return x+2; };

tmp = testFunc4(1);
ok(tmp === 5, "testFunc4(1) = " + tmp);
tmp = function testFunc4(x) { return x+3; };
tmp = testFunc4(1);
testFunc4 = 1;
ok(testFunc4 === 1, "testFunc4 = " + testFunc4);
ok(tmp === 5, "testFunc4(1) = " + tmp);
tmp = function testFunc4(x) { return x+4; };
ok(testFunc4 === 1, "testFunc4 = " + testFunc4);

function testEmbeddedFunctions() {
    ok(typeof(testFunc5) === "function", "typeof(testFunc5) = " + typeof(testFunc5));
    tmp = testFunc5(1);
    ok(tmp === 3, "testFunc5(1) = " + tmp);
    tmp = function testFunc5(x) { return x+2; };

    tmp = testFunc6(1);
    ok(tmp === 5, "testFunc6(1) = " + tmp);
    tmp = function testFunc6(x) { return x+3; };
    tmp = testFunc6(1);
    ok(tmp === 5, "testFunc6(1) = " + tmp);
    tmp = function testFunc6(x) { return x+4; };
    testFunc6 = 1;
    ok(testFunc6 === 1, "testFunc4 = " + testFunc6);
}

testEmbeddedFunctions();

date = new Date();
date.toString = function() { return "toString"; }
ok(""+date === "toString", "''+date = " + date);
date.toString = function() { return this; }
ok(""+date === ""+date.valueOf(), "''+date = " + date);

str = new String("test");
str.valueOf = function() { return "valueOf"; }
ok(""+str === "valueOf", "''+str = " + str);
str.valueOf = function() { return new Date(); }
ok(""+str === "test", "''+str = " + str);

ok((function (){return 1;})() === 1, "(function (){return 1;})() = " + (function (){return 1;})());

(function() {
    var order = "", o = {};
    o[order += "1,", { toString: function() { order += "2,"; } }] = (order += "3");
    ok(order === "1,2,3", "array expression order = " + order);
})();

var re = /=(\?|%3F)/g;
ok(re.source === "=(\\?|%3F)", "re.source = " + re.source);

tmp = new Array();
for(var i=0; i<2; i++)
    tmp[i] = /b/;
ok(tmp[0] != tmp[1], "tmp[0] == tmp [1]");

ok(isNullBSTR(getNullBSTR()), "isNullBSTR(getNullBSTR()) failed\n");
ok(getNullBSTR() === '', "getNullBSTR() !== ''");
ok(+getNullBSTR() === 0 , "+getNullBTR() !=== 0");

ok(getVT(nullDisp) === "VT_DISPATCH", "getVT(nullDisp) = " + getVT(nullDisp));
ok(typeof(nullDisp) === "object", "typeof(nullDisp) = " + typeof(nullDisp));
ok(nullDisp === nullDisp, "nullDisp !== nullDisp");
ok(nullDisp !== re, "nullDisp === re");
ok(nullDisp === null, "nullDisp === null");
ok(nullDisp == null, "nullDisp == null");
ok(getVT(true && nullDisp) === "VT_DISPATCH",
   "getVT(0 && nullDisp) = " + getVT(true && nullDisp));
ok(!nullDisp === true, "!nullDisp = " + !nullDisp);
ok(String(nullDisp) === "null", "String(nullDisp) = " + String(nullDisp));
ok(+nullDisp === 0, "+nullDisp !== 0");
ok(''+nullDisp === "null", "''+nullDisp !== null");
ok(nullDisp != new Object(), "nullDisp == new Object()");
ok(new Object() != nullDisp, "new Object() == nullDisp");
ok((typeof Object(nullDisp)) === "object", "typeof Object(nullDisp) !== 'object'");
tmp = getVT(Object(nullDisp));
ok(tmp === "VT_DISPATCH", "getVT(Object(nullDisp) = " + tmp);
tmp = Object(nullDisp).toString();
ok(tmp === "[object Object]", "Object(nullDisp).toString() = " + tmp);

function testNullPrototype() {
    this.x = 13;
}
tmp = new testNullPrototype();
ok(tmp.x === 13, "tmp.x !== 13");
ok(!("y" in tmp), "tmp has 'y' property");
testNullPrototype.prototype.y = 10;
ok("y" in tmp, "tmp does not have 'y' property");
tmp = new testNullPrototype();
ok(tmp.y === 10, "tmp.y !== 10");
testNullPrototype.prototype = nullDisp;
tmp = new testNullPrototype();
ok(tmp.x === 13, "tmp.x !== 13");
ok(!("y" in tmp), "tmp has 'y' property");
ok(!tmp.hasOwnProperty("y"), "tmp has 'y' property");
ok(!tmp.propertyIsEnumerable("y"), "tmp has 'y' property enumerable");
ok(tmp.toString() == "[object Object]", "tmp.toString returned " + tmp.toString());
testNullPrototype.prototype = null;
tmp = new testNullPrototype();
ok(!tmp.hasOwnProperty("y"), "tmp has 'y' property");
ok(!tmp.propertyIsEnumerable("y"), "tmp has 'y' property enumerable");
ok(tmp.toString() == "[object Object]", "tmp.toString returned " + tmp.toString());

testNullPrototype.prototype = 42;
tmp = new testNullPrototype();
ok(tmp.hasOwnProperty("x"), "tmp does not have 'x' property");
ok(!tmp.hasOwnProperty("y"), "tmp has 'y' property");
ok(tmp.toString() == "[object Object]", "tmp.toString returned " + tmp.toString());

testNullPrototype.prototype = true;
tmp = new testNullPrototype();
ok(tmp.hasOwnProperty("x"), "tmp does not have 'x' property");
ok(!tmp.hasOwnProperty("y"), "tmp has 'y' property");
ok(tmp.toString() == "[object Object]", "tmp.toString returned " + tmp.toString());

testNullPrototype.prototype = "foobar";
tmp = new testNullPrototype();
ok(tmp.hasOwnProperty("x"), "tmp does not have 'x' property");
ok(!tmp.hasOwnProperty("y"), "tmp has 'y' property");
ok(tmp.toString() == "[object Object]", "tmp.toString returned " + tmp.toString());

function do_test() {}
function nosemicolon() {} nosemicolon();
function () {} nosemicolon();

if(false) {
    function in_if_false() { return true; } ok(false, "!?");
}

ok(in_if_false(), "in_if_false failed");

(function() { newValue = 1; })();
ok(newValue === 1, "newValue = " + newValue);

obj = {undefined: 3};

ok(typeof(name_override_func) === "function", "typeof(name_override_func) = " + typeof(name_override_func));
name_override_func = 3;
ok(name_override_func === 3, "name_override_func = " + name_override_func);
function name_override_func() {};
ok(name_override_func === 3, "name_override_func = " + name_override_func);

tmp = (function() {
    var ret = false;
    with({ret: true})
        return ret;
})();
ok(tmp, "tmp = " + tmp);

tmp = (function() {
    for(var iter in [1,2,3,4]) {
        var ret = false;
        with({ret: true})
            return ret;
    }
})();
ok(tmp, "tmp = " + tmp);

(function() {
    ok(typeof(func) === "function", "typeof(func)  = " + typeof(func));
    with(new Object()) {
        var x = false && function func() {};
    }
    ok(typeof(func) === "function", "typeof(func)  = " + typeof(func));
})();

(function() {
    ok(x === undefined, "x = " + x); // x is declared, but never initialized
    with({x: 1}) {
        ok(x === 1, "x = " + x);
        var x = 2;
        ok(x === 2, "x = " + x);
    }
    ok(x === undefined, "x = " + x);
})();

var get, set;

/* NoNewline rule parser tests */
while(true) {
    if(true) break
    tmp = false
}

while(true) {
    if(true) break /*
                    * no semicolon, but comment present */
    tmp = false
}

while(true) {
    if(true) break // no semicolon, but comment present
    tmp = false
}

while(true) {
    break
    continue
    tmp = false
}

function returnTest() {
    return
    true;
}

ok(returnTest() === undefined, "returnTest = " + returnTest());

ActiveXObject = 1;
ok(ActiveXObject === 1, "ActiveXObject = " + ActiveXObject);

Boolean = 1;
ok(Boolean === 1, "Boolean = " + Boolean);

Object = 1;
ok(Object === 1, "Object = " + Object);

Array = 1;
ok(Array === 1, "Array = " + Array);

Date = 1;
ok(Date === 1, "Date = " + Date);

Error = 1;
ok(Error === 1, "Error = " + Error);

/* Keep this test in the end of file */
undefined = 6;
ok(undefined === 6, "undefined = " + undefined);

NaN = 6;
ok(NaN === 6, "NaN !== 6");

Infinity = 6;
ok(Infinity === 6, "Infinity !== 6");

Math = 6;
ok(Math === 6, "NaN !== 6");

reportSuccess();

function test_es5_keywords() {
    var let = 1
    var tmp
    ok(let == 1, "let != 1");

    tmp = false
    try {
        eval('var var = 1;');
    }
    catch(e) {
        tmp = true
    }
    ok(tmp === true, "Expected exception for 'var var = 1;'");

    tmp = false
    try {
        eval('var const = 1;');
    }
    catch(e) {
        tmp = true
    }
    ok(tmp === true, "Expected exception for 'var const = 1;'");

    tmp = false
    try {
        eval('const c1 = 1;');
    }
    catch(e) {
        tmp = true
    }
    ok(tmp === true, "Expected exception for 'const c1 = 1;'");
}
test_es5_keywords();
 Sp  0   ��( R E G E X P . J S       0           /*
 * Copyright 2008 Jacek Caban for CodeWeavers
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


var m, re, b, i, obj;

ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
RegExp.leftContext = "abc";
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);

re = /a+/;
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);

m = re.exec(" aabaaa");
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(m.index === 1, "m.index = " + m.index);
ok(m.input === " aabaaa", "m.input = " + m.input);
ok(m.length === 1, "m.length = " + m.length);
ok(m[0] === "aa", "m[0] = " + m[0]);
ok(RegExp.leftContext === " ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "baaa", "RegExp.rightContext = " + RegExp.rightContext);

m = re.exec(" aabaaa");
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(m.index === 1, "m.index = " + m.index);
ok(m.input === " aabaaa", "m.input = " + m.input);
ok(m.length === 1, "m.length = " + m.length);
ok(m[0] === "aa", "m[0] = " + m[0]);
ok(m.propertyIsEnumerable("0"), "m.0 is not enumerable");
ok(m.propertyIsEnumerable("input"), "m.input is not enumerable");
ok(m.propertyIsEnumerable("index"), "m.index is not enumerable");
ok(m.propertyIsEnumerable("lastIndex"), "m.lastIndex is not enumerable");
ok(m.propertyIsEnumerable("length") === false, "m.length is not enumerable");
ok(RegExp.leftContext === " ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "baaa", "RegExp.rightContext = " + RegExp.rightContext);

m = /^[^<]*(<(.|\s)+>)[^>]*$|^#(\w+)$/.exec(
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
ok(m === null, "m is not null");

re = /a+/g;
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);

m = re.exec(" aabaaa");
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(m.index === 1, "m.index = " + m.index);
ok(m.lastIndex == 3, "m.lastIndex = " + m.lastIndex);
ok(m.input === " aabaaa", "m.input = " + m.input);
ok(m.length === 1, "m.length = " + m.length);
ok(m[0] === "aa", "m[0] = " + m[0]);

m = re.exec(" aabaaa");
ok(re.lastIndex === 7, "re.lastIndex = " + re.lastIndex);
ok(m.index === 4, "m.index = " + m.index);
ok(m.input === " aabaaa", "m.input = " + m.input);
ok(m.length === 1, "m.length = " + m.length);
ok(m[0] === "aaa", "m[0] = " + m[0]);

m = re.exec(" aabaaa");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);
ok(m === null, "m is not null");

re.exec("               a");
ok(re.lastIndex === 16, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "               ",
   "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "", "RegExp.rightContext = " + RegExp.rightContext);

m = re.exec(" a");
ok(m === null, "m is not null");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);

m = re.exec(" a");
ok(re.lastIndex === 2, "re.lastIndex = " + re.lastIndex);

m = re.exec();
ok(m === null, "m is not null");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);

m = /(a|b)+|(c)/.exec("aa");
ok(m[0] === "aa", "m[0] = " + m[0]);
ok(m[1] === "a", "m[1] = " + m[1]);
ok(m[2] === "", "m[2] = " + m[2]);

b = re.test("  a ");
ok(b === true, "re.test('  a ') returned " + b);
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "  ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " ", "RegExp.rightContext = " + RegExp.rightContext);

b = re.test(" a ");
ok(b === false, "re.test(' a ') returned " + b);
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "  ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " ", "RegExp.rightContext = " + RegExp.rightContext);

re = /\[([^\[]+)\]/g;
m = re.exec(" [test]  ");
ok(re.lastIndex === 7, "re.lastIndex = " + re.lastIndex);
ok(m.index === 1, "m.index = " + m.index);
ok(m.input === " [test]  ", "m.input = " + m.input);
ok(m.length === 2, "m.length = " + m.length);
ok(m[0] === "[test]", "m[0] = " + m[0]);
ok(m[1] === "test", "m[1] = " + m[1]);

b = /a*/.test();
ok(b === true, "/a*/.test() returned " + b);
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "undefined", "RegExp.rightContext = " + RegExp.rightContext);

b = /f/.test();
ok(b === true, "/f/.test() returned " + b);
ok(RegExp.leftContext === "unde", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "ined", "RegExp.rightContext = " + RegExp.rightContext);

b = /abc/.test();
ok(b === false, "/abc/.test() returned " + b);
ok(RegExp.leftContext === "unde", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "ined", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match(re = /ca/);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 1, "m.length is not 1");
ok(m["0"] === "ca", "m[0] is not \"ca\"");
ok(m.constructor === Array, "unexpected m.constructor");
ok(re.lastIndex === 4, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "ab", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "bc", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match(/ab/);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 1, "m.length is not 1");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cabc", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match(/ab/g);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");
/* ok(m.input === "abcabc", "m.input = " + m.input); */

m = "abcabc".match(/Ab/g);
ok(typeof(m) === "object", "typeof m is not object");
ok(m === null, "m is not null");

m = "abcabc".match(/Ab/gi);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");
ok(RegExp.leftContext === "abc", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "c", "RegExp.rightContext = " + RegExp.rightContext);

m = "aaabcabc".match(/a+b/g);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "aaab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");

m = "aaa\\\\cabc".match(/\\/g);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "\\", "m[0] is not \"\\\"");
ok(m["1"] === "\\", "m[1] is not \"\\\"");

m = "abcabc".match(new RegExp("ab"));
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 1, "m.length is not 1");
ok(m["0"] === "ab", "m[0] is not \"ab\"");

m = "abcabc".match(new RegExp("ab","g"));
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");
ok(RegExp.leftContext === "abc", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "c", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match(new RegExp(/ab/g));
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");

m = "abcabc".match(new RegExp("ab","g", "test"));
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length is not 2");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(m["1"] === "ab", "m[1] is not \"ab\"");
ok(m.index === 3, "m.index = " + m.index);
ok(m.input === "abcabc", "m.input = " + m.input);
ok(m.lastIndex === 5, "m.lastIndex = " + m.lastIndex);

m = "abcabcg".match("ab", "g");
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 1, "m.length is not 1");
ok(m["0"] === "ab", "m[0] is not \"ab\"");
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cabcg", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match();
ok(m === null, "m is not null");
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cabcg", "RegExp.rightContext = " + RegExp.rightContext);

m = "abcabc".match(/(a)(b)cabc/);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 3, "m.length is not 3");
ok(m[0] === "abcabc", "m[0] is not \"abc\"");
ok(m[1] === "a", "m[1] is not \"a\"");
ok(m[2] === "b", "m[2] is not \"b\"");

re = /(a)bcabc/;
re.lastIndex = -3;
m = "abcabc".match(re);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length = " + m.length + "expected 3");
ok(m[0] === "abcabc", "m[0] is not \"abc\"");
ok(m[1] === "a", "m[1] is not \"a\"");
ok(re.lastIndex === 6, "re.lastIndex = " + re.lastIndex);

re = /(a)bcabc/;
re.lastIndex = 2;
m = "abcabcxxx".match(re);
ok(typeof(m) === "object", "typeof m is not object");
ok(m.length === 2, "m.length = " + m.length + "expected 3");
ok(m[0] === "abcabc", "m[0] is not \"abc\"");
ok(m[1] === "a", "m[1] is not \"a\"");
ok(m.input === "abcabcxxx", "m.input = " + m.input);
ok(re.lastIndex === 6, "re.lastIndex = " + re.lastIndex);

r = "- [test] -".replace(re = /\[([^\[]+)\]/g, "success");
ok(r === "- success -", "r = " + r + " expected '- success -'");
ok(re.lastIndex === 8, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "- ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " -", "RegExp.rightContext = " + RegExp.rightContext);

r = "[test] [test]".replace(/\[([^\[]+)\]/g, "aa");
ok(r === "aa aa", "r = " + r + "aa aa");
ok(RegExp.leftContext === "[test] ",
   "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "",
   "RegExp.rightContext = " + RegExp.rightContext);

r = "[test] [test]".replace(/\[([^\[]+)\]/, "aa");
ok(r === "aa [test]", "r = " + r + " expected 'aa [test]'");

r = "- [test] -".replace(/\[([^\[]+)\]/g);
ok(r === "- undefined -", "r = " + r + " expected '- undefined -'");

r = "- [test] -".replace(/\[([^\[]+)\]/g, true);
ok(r === "- true -", "r = " + r + " expected '- true -'");

r = "- [test] -".replace(/\[([^\[]+)\]/g, true, "test");
ok(r === "- true -", "r = " + r + " expected '- true -'");
ok(RegExp.leftContext === "- ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " -", "RegExp.rightContext = " + RegExp.rightContext);

var tmp = 0;

function replaceFunc1(m, off, str) {
    ok(arguments.length === 3, "arguments.length = " + arguments.length);

    switch(tmp) {
    case 0:
        ok(m === "[test1]", "m = " + m + " expected [test1]");
        ok(off === 0, "off = " + off + " expected 0");
        ok(RegExp.leftContext === "- ",
           "RegExp.leftContext = " + RegExp.leftContext);
        ok(RegExp.rightContext === " -",
           "RegExp.rightContext = " + RegExp.rightContext);
        break;
    case 1:
        ok(m === "[test2]", "m = " + m + " expected [test2]");
        ok(off === 8, "off = " + off + " expected 8");
        ok(RegExp.leftContext === "- ",
           "RegExp.leftContext = " + RegExp.leftContext);
        ok(RegExp.rightContext === " -",
           "RegExp.rightContext = " + RegExp.rightContext);
        break;
    default:
        ok(false, "unexpected call");
    }

    ok(str === "[test1] [test2]", "str = " + arguments[3]);
    return "r" + tmp++;
}

r = "[test1] [test2]".replace(/\[[^\[]+\]/g, replaceFunc1);
ok(r === "r0 r1", "r = " + r + " expected 'r0 r1'");
ok(RegExp.leftContext === "[test1] ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "", "RegExp.rightContext = " + RegExp.rightContext);

tmp = 0;

function replaceFunc2(m, subm, off, str) {
    ok(arguments.length === 4, "arguments.length = " + arguments.length);

    switch(tmp) {
    case 0:
        ok(subm === "test1", "subm = " + subm);
        ok(m === "[test1]", "m = " + m + " expected [test1]");
        ok(off === 0, "off = " + off + " expected 0");
        break;
    case 1:
        ok(subm === "test2", "subm = " + subm);
        ok(m === "[test2]", "m = " + m + " expected [test2]");
        ok(off === 8, "off = " + off + " expected 8");
        break;
    default:
        ok(false, "unexpected call");
    }

    ok(str === "[test1] [test2]", "str = " + arguments[3]);
    return "r" + tmp++;
}

r = "[test1] [test2]".replace(/\[([^\[]+)\]/g, replaceFunc2);
ok(r === "r0 r1", "r = '" + r + "' expected 'r0 r1'");

r = "$1,$2".replace(/(\$(\d))/g, "$$1-$1$2");
ok(r === "$1-$11,$1-$22", "r = '" + r + "' expected '$1-$11,$1-$22'");
ok(RegExp.leftContext === "$1,", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "", "RegExp.rightContext = " + RegExp.rightContext);

r = "abc &1 123".replace(/(\&(\d))/g, "$&");
ok(r === "abc &1 123", "r = '" + r + "' expected 'abc &1 123'");
ok(RegExp.leftContext === "abc ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " 123", "RegExp.rightContext = " + RegExp.rightContext);

r = "abc &1 123".replace(/(\&(\d))/g, "$'");
ok(r === "abc  123 123", "r = '" + r + "' expected 'abc  123 123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$`");
ok(r === "abc abc  123", "r = '" + r + "' expected 'abc abc  123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$3");
ok(r === "abc $3 123", "r = '" + r + "' expected 'abc $3 123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$");
ok(r === "abc $ 123", "r = '" + r + "' expected 'abc $ 123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$a");
ok(r === "abc $a 123", "r = '" + r + "' expected 'abc $a 123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$11");
ok(r === "abc &11 123", "r = '" + r + "' expected 'abc &11 123'");

r = "abc &1 123".replace(/(\&(\d))/g, "$0");
ok(r === "abc $0 123", "r = '" + r + "' expected 'abc $0 123'");

/a/.test("a");
r = "1 2 3".replace("2", "$&");
ok(r === "1 $& 3", "r = '" + r + "' expected '1 $& 3'");
ok(RegExp.leftContext === "", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "", "RegExp.rightContext = " + RegExp.rightContext);

r = "1 2 3".replace("2", "$'");
ok(r === "1 $' 3", "r = '" + r + "' expected '1 $' 3'");

r = "1,,2,3".split(/,+/g);
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[2] = " + r[2]);
ok(RegExp.leftContext === "1,,2", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "3", "RegExp.rightContext = " + RegExp.rightContext);

r = "1,,2,3".split(/,+/g, 2);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(RegExp.leftContext === "1,,2", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "3", "RegExp.rightContext = " + RegExp.rightContext);

r = "1,,2,3".split(/,+/g, 1);
ok(r.length === 1, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(RegExp.leftContext === "1", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "2,3", "RegExp.rightContext = " + RegExp.rightContext);

r = "1,,2,3".split(/,+/);
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[2] = " + r[2]);

r = "1,,2,".split(/,+/);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);

re = /,+/;
r = "1,,2,".split(re);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(re.lastIndex === 5, "re.lastIndex = " + re.lastIndex);

re = /,+/g;
r = "1,,2,".split(re);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(re.lastIndex === 5, "re.lastIndex = " + re.lastIndex);

r = "1 12 \t3".split(re = /\s+/).join(";");
ok(r === "1;12;3", "r = " + r);
ok(re.lastIndex === 6, "re.lastIndex = " + re.lastIndex);

r = "123".split(re = /\s+/).join(";");
ok(r === "123", "r = " + r);
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);

r = "1ab2aab3".split(/(a+)b/);
ok(r.length === 3, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(r[2] === "3", "r[2] = " + r[2]);

r = "A<B>bold</B>and<CODE>coded</CODE>".split(/<(\/)?([^<>]+)>/) ;
ok(r.length === 4, "r.length = " + r.length);

/* another standard violation */
r = "1 12 \t3".split(re = /(\s)+/g).join(";");
ok(r === "1;12;3", "r = " + r);
ok(re.lastIndex === 6, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "1 12", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "3", "RegExp.rightContext = " + RegExp.rightContext);

re = /,+/;
re.lastIndex = 4;
r = "1,,2,".split(re);
ok(r.length === 2, "r.length = " + r.length);
ok(r[0] === "1", "r[0] = " + r[0]);
ok(r[1] === "2", "r[1] = " + r[1]);
ok(re.lastIndex === 5, "re.lastIndex = " + re.lastIndex);

re = /abc[^d]/g;
ok(re.source === "abc[^d]", "re.source = '" + re.source + "', expected 'abc[^d]'");

re = /a\bc[^d]/g;
ok(re.source === "a\\bc[^d]", "re.source = '" + re.source + "', expected 'a\\bc[^d]'");

re = /abc/;
ok(re === RegExp(re), "re !== RegExp(re)");

re = RegExp("abc[^d]", "g");
ok(re.source === "abc[^d]", "re.source = '" + re.source + "', expected 'abc[^d]'");

re = /abc/;
ok(re === RegExp(re, undefined), "re !== RegExp(re, undefined)");

re = /abc/;
ok(re === RegExp(re, undefined, 1), "re !== RegExp(re, undefined, 1)");

re = /a/g;
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 0");

m = re.exec(" a   ");
ok(re.lastIndex === 2, "re.lastIndex = " + re.lastIndex + " expected 2");
ok(m.index === 1, "m.index = " + m.index + " expected 1");
ok(RegExp.leftContext === " ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "   ", "RegExp.rightContext = " + RegExp.rightContext);

m = re.exec(" a   ");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 0");
ok(m === null, "m = " + m + " expected null");

re.lastIndex = 2;
m = re.exec(" a a ");
ok(re.lastIndex === 4, "re.lastIndex = " + re.lastIndex + " expected 4");
ok(m.index === 3, "m.index = " + m.index + " expected 3");

re.lastIndex = "2";
ok(re.lastIndex === "2", "re.lastIndex = " + re.lastIndex + " expected '2'");
m = re.exec(" a a ");
ok(re.lastIndex === 4, "re.lastIndex = " + re.lastIndex + " expected 4");
ok(m.index === 3, "m.index = " + m.index + " expected 3");

var li = 0;
var obj = new Object();
obj.valueOf = function() { return li; };

re.lastIndex = obj;
ok(re.lastIndex === obj, "re.lastIndex = " + re.lastIndex + " expected obj");
li = 2;
m = re.exec(" a a ");
ok(re.lastIndex === 2, "re.lastIndex = " + re.lastIndex + " expected 2");
ok(m.index === 1, "m.index = " + m.index + " expected 1");

re.lastIndex = 3;
re.lastIndex = "test";
ok(re.lastIndex === "test", "re.lastIndex = " + re.lastIndex + " expected 'test'");
m = re.exec(" a a ");
ok(re.lastIndex === 2 || re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 2 or 0");
if(re.lastIndex != 0)
    ok(m.index === 1, "m.index = " + m.index + " expected 1");
else
    ok(m === null, "m = " + m + " expected null");

re.lastIndex = 0;
re.lastIndex = 3.9;
ok(re.lastIndex === 3.9, "re.lastIndex = " + re.lastIndex + " expected 3.9");
m = re.exec(" a a ");
ok(re.lastIndex === 4, "re.lastIndex = " + re.lastIndex + " expected 4");
ok(m.index === 3, "m.index = " + m.index + " expected 3");

obj.valueOf = function() { throw 0; }
re.lastIndex = obj;
ok(re.lastIndex === obj, "unexpected re.lastIndex");
m = re.exec(" a a ");
ok(re.lastIndex === 2, "re.lastIndex = " + re.lastIndex + " expected 2");
ok(m.index === 1, "m.index = " + m.index + " expected 1");

re.lastIndex = -3;
ok(re.lastIndex === -3, "re.lastIndex = " + re.lastIndex + " expected -3");
m = re.exec(" a a ");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 0");
ok(m === null, "m = " + m + " expected null");

re.lastIndex = -1;
ok(re.lastIndex === -1, "re.lastIndex = " + re.lastIndex + " expected -1");
m = re.exec("  ");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 0");
ok(m === null, "m = " + m + " expected null");

re = /a/;
re.lastIndex = -3;
ok(re.lastIndex === -3, "re.lastIndex = " + re.lastIndex + " expected -3");
m = re.exec(" a a ");
ok(re.lastIndex === 2, "re.lastIndex = " + re.lastIndex + " expected 0");
ok(m.index === 1, "m = " + m + " expected 1");
ok(RegExp.leftContext === " ", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === " a ", "RegExp.rightContext = " + RegExp.rightContext);

re.lastIndex = -1;
ok(re.lastIndex === -1, "re.lastIndex = " + re.lastIndex + " expected -1");
m = re.exec("  ");
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex + " expected 0");
ok(m === null, "m = " + m + " expected null");

re = /aa/g;
i = 'baacd'.search(re);
ok(i === 1, "'baacd'.search(re) = " + i);
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "b", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cd", "RegExp.rightContext = " + RegExp.rightContext);

re.lastIndex = 2;
i = 'baacdaa'.search(re);
ok(i === 1, "'baacd'.search(re) = " + i);
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);

re = /aa/;
i = 'baacd'.search(re);
ok(i === 1, "'baacd'.search(re) = " + i);
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);

re.lastIndex = 2;
i = 'baacdaa'.search(re);
ok(i === 1, "'baacd'.search(re) = " + i);
ok(re.lastIndex === 3, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "b", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cdaa", "RegExp.rightContext = " + RegExp.rightContext);

re = /d/g;
re.lastIndex = 1;
i = 'abc'.search(re);
ok(i === -1, "'abc'.search(/d/g) = " + i);
ok(re.lastIndex === 0, "re.lastIndex = " + re.lastIndex);
ok(RegExp.leftContext === "b", "RegExp.leftContext = " + RegExp.leftContext);
ok(RegExp.rightContext === "cdaa", "RegExp.rightContext = " + RegExp.rightContext);

i = 'abcdde'.search(/[df]/);
ok(i === 3, "'abc'.search(/[df]/) = " + i);

i = 'abcdde'.search(/[df]/, "a");
ok(i === 3, "'abc'.search(/[df]/) = " + i);

i = 'abcdde'.search("[df]");
ok(i === 3, "'abc'.search(/d*/) = " + i);

obj = {
    toString: function() { return "abc"; }
};
i = String.prototype.search.call(obj, "b");
ok(i === 1, "String.prototype.seatch.apply(obj, 'b') = " + i);

i = " undefined ".search();
ok(i === null, "' undefined '.search() = " + i);

tmp = "=)".replace(/=/, "?");
ok(tmp === "?)", "'=)'.replace(/=/, '?') = " + tmp);

tmp = "   ".replace(/^\s*|\s*$/g, "y");
ok(tmp === "yy", '"   ".replace(/^\s*|\s*$/g, "y") = ' + tmp);

tmp = "xxx".replace(/^\s*|\s*$/g, "");
ok(tmp === "xxx", '"xxx".replace(/^\s*|\s*$/g, "y") = ' + tmp);

tmp = "xxx".replace(/^\s*|\s*$/g, "y");
ok(tmp === "yxxxy", '"xxx".replace(/^\s*|\s*$/g, "y") = ' + tmp);

tmp = "x/y".replace(/[/]/, "*");
ok(tmp === "x*y", '"x/y".replace(/[/]/, "*") = ' + tmp);

tmp = "x/y".replace(/[xy/]/g, "*");
ok(tmp === "***", '"x/y".replace(/[xy/]/, "*") = ' + tmp);

tmp = /()/.exec("")[1];
ok(tmp === "", "/()/ captured: " + tmp);
tmp = /()?/.exec("")[1];
ok(tmp === "", "/()?/ captured: " + tmp);
tmp = /()??/.exec("")[1];
ok(tmp === "", "/()??/ captured: " + tmp);
tmp = /()*/.exec("")[1];
ok(tmp === "", "/()*/ captured: " + tmp);
tmp = /()??()/.exec("");
ok(tmp[1] === "", "/()??()/ [1] captured: " + tmp);
ok(tmp[2] === "", "/()??()/ [2] captured: " + tmp);

try {
    tmp = new RegExp("(?<a>b)", "g");
    ok(false, "expected exception with /(?<a>b)/ regex");
}catch(e) {
    ok(e.number === 0xa1399 - 0x80000000, "/(?<a>b)/ regex threw " + e.number);
}

/(b)/.exec("abc");
ok(RegExp.$1 === "b", "RegExp.$1 = " + RegExp.$1);
ok("$2" in RegExp, "RegExp.$2 doesn't exist");
ok(RegExp.$2 === "", "RegExp.$2 = " + RegExp.$2);
ok(RegExp.$9 === "", "RegExp.$9 = " + RegExp.$9);
ok(!("$10" in RegExp), "RegExp.$10 exists");

/(b)(b)(b)(b)(b)(b)(b)(b)(b)(b)(b)/.exec("abbbbbbbbbbbc");
ok(RegExp.$1 === "b", "RegExp.$1 = " + RegExp.$1);
ok(RegExp.$2 === "b", "[2] RegExp.$2 = " + RegExp.$2);
ok(RegExp.$9 === "b", "RegExp.$9 = " + RegExp.$9);
ok(!("$10" in RegExp), "RegExp.$10 exists");

/(b)/.exec("abc");
ok(RegExp.$1 === "b", "RegExp.$1 = " + RegExp.$1);
ok("$2" in RegExp, "RegExp.$2 doesn't exist");
ok(RegExp.$2 === "", "RegExp.$2 = " + RegExp.$2);
ok(RegExp.$9 === "", "RegExp.$9 = " + RegExp.$9);
ok(!("$10" in RegExp), "RegExp.$10 exists");

RegExp.$1 = "a";
ok(RegExp.$1 === "b", "RegExp.$1 = " + RegExp.$1);

ok(/abc/.toString() === "/abc/", "/abc/.toString() = " + /abc/.toString());
ok(/\//.toString() === "/\\//", "/\//.toString() = " + /\//.toString());
tmp = new RegExp("abc/");
ok(tmp.toString() === "/abc//", "(new RegExp(\"abc/\")).toString() = " + tmp.toString());
ok(/abc/g.toString() === "/abc/g", "/abc/g.toString() = " + /abc/g.toString());
ok(/abc/i.toString() === "/abc/i", "/abc/i.toString() = " + /abc/i.toString());
ok(/abc/ig.toString() === "/abc/ig", "/abc/ig.toString() = " + /abc/ig.toString());
ok(/abc/mgi.toString() === "/abc/igm", "/abc/mgi.toString() = " + /abc/mgi.toString());
tmp = new RegExp("abc/", "mgi");
ok(tmp.toString() === "/abc//igm", "(new RegExp(\"abc/\")).toString() = " + tmp.toString());
ok(/abc/.toString(1, false, "3") === "/abc/", "/abc/.toString(1, false, \"3\") = " + /abc/.toString());

re = /x/;
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);
re = /x/i;
ok(re.ignoreCase === true, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);
re = new RegExp("xxx", "gi");
ok(re.ignoreCase === true, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === true, "re.global = " + re.global);
re = /x/mg;
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === true, "re.multiline = " + re.multiline);
ok(re.global === true, "re.global = " + re.global);

re = new RegExp(undefined);
ok(re.source === "", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);

re = new RegExp();
ok(re.source === "", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);

re = new RegExp(true);
ok(re.source === "true", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);

re = new RegExp({ toString: function() { return "test"; } });
ok(re.source === "test", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);

re = new RegExp("test", undefined);
ok(re.source === "test", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === false, "re.multiline = " + re.multiline);
ok(re.global === false, "re.global = " + re.global);

re = new RegExp("test", { toString: function() { return "mg"; } });
ok(re.source === "test", "re.source = " + re.source);
ok(re.ignoreCase === false, "re.ignoreCase = " + re.ignoreCase);
ok(re.multiline === true, "re.multiline = " + re.multiline);
ok(re.global === true, "re.global = " + re.global);

reportSuccess();
 ƥ ,   ��( D N A . J S         0           // The Computer Language Shootout
// http://shootout.alioth.debian.org/
//
// contributed by Jesse Millikan
// Base on the Ruby version by jose fco. gonzalez

var l;
var dnaInput = ">ONE Homo sapiens alu\n\
GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGA\n\
TCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACT\n\
AAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAG\n\
GCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCG\n\
CCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGT\n\
GGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCA\n\
GGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAA\n\
TTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAG\n\
AATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCA\n\
GCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGT\n\
AATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACC\n\
AGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTG\n\
GTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACC\n\
CGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAG\n\
AGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTT\n\
TGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACA\n\
TGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCT\n\
GTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGG\n\
TTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGT\n\
CTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGG\n\
CGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCG\n\
TCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTA\n\
CTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCG\n\
AGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCG\n\
GGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACC\n\
TGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAA\n\
TACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGA\n\
GGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACT\n\
GCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTC\n\
ACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGT\n\
TCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGC\n\
CGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCG\n\
CTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTG\n\
GGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCC\n\
CAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCT\n\
GGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGC\n\
GCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGA\n\
GGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGA\n\
GACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGA\n\
GGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTG\n\
AAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAAT\n\
CCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCA\n\
GTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAA\n\
AAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGC\n\
GGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCT\n\
ACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGG\n\
GAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATC\n\
GCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGC\n\
GGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGG\n\
TCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAA\n\
AAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAG\n\
GAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACT\n\
CCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCC\n\
TGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAG\n\
ACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGC\n\
GTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGA\n\
ACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGA\n\
CAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCA\n\
CTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCA\n\
ACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCG\n\
CCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGG\n\
AGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTC\n\
CGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCG\n\
AGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACC\n\
CCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAG\n\
CTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAG\n\
CCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGG\n\
CCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATC\n\
ACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAA\n\
AAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGC\n\
TGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCC\n\
ACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGG\n\
CTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGG\n\
AGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATT\n\
AGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAA\n\
TCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGC\n\
CTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAA\n\
TCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAG\n\
CCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGT\n\
GGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCG\n\
GGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAG\n\
CGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTG\n\
GGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATG\n\
GTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGT\n\
AATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTT\n\
GCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCT\n\
CAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCG\n\
GGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTC\n\
TCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACT\n\
CGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAG\n\
ATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGG\n\
CGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTG\n\
AGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATA\n\
CAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGG\n\
CAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGC\n\
ACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCAC\n\
GCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTC\n\
GAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCG\n\
GGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCT\n\
TGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGG\n\
CGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCA\n\
GCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGG\n\
CCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGC\n\
GCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGG\n\
CGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGA\n\
CTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGG\n\
CCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAA\n\
ACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCC\n\
CAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGT\n\
GAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAA\n\
AGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGG\n\
ATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTAC\n\
TAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGA\n\
GGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGC\n\
GCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGG\n\
TGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTC\n\
AGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAA\n\
ATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGA\n\
GAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC\n\
AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTG\n\
TAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGAC\n\
CAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGT\n\
GGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAAC\n\
CCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACA\n\
GAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACT\n\
TTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAAC\n\
ATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCC\n\
TGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAG\n\
GTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCG\n\
TCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAG\n\
GCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCC\n\
GTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCT\n\
ACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCC\n\
GAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCC\n\
GGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCAC\n\
CTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAA\n\
ATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTG\n\
AGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCAC\n\
TGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCT\n\
CACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAG\n\
TTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAG\n\
CCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATC\n\
GCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCT\n\
GGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATC\n\
CCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCC\n\
TGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGG\n\
CGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG\n\
AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCG\n\
AGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGG\n\
AGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGT\n\
GAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAA\n\
TCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGC\n\
AGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCA\n\
AAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGG\n\
CGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTC\n\
TACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCG\n\
GGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGAT\n\
CGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCG\n\
CGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAG\n\
GTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACA\n\
AAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCA\n\
GGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCAC\n\
TCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGC\n\
CTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGA\n\
GACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGG\n\
CGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTG\n\
AACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCG\n\
ACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGC\n\
ACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCC\n\
AACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGC\n\
GCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCG\n\
GAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACT\n\
CCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCC\n\
GAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAAC\n\
CCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA\n\
GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGA\n\
GCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAG\n\
GCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGAT\n\
CACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTA\n\
AAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGG\n\
CTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGC\n\
CACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTG\n\
GCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAG\n\
GAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAAT\n\
TAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGA\n\
ATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAG\n\
CCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTA\n\
ATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCA\n\
GCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGG\n\
TGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCC\n\
GGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGA\n\
GCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTT\n\
GGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACAT\n\
GGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTG\n\
TAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGT\n\
TGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTC\n\
TCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGC\n\
GGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGT\n\
CTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTAC\n\
TCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGA\n\
GATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGG\n\
GCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCT\n\
GAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT\n\
ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAG\n\
GCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTG\n\
CACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCA\n\
CGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTT\n\
CGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCC\n\
GGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGC\n\
TTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGG\n\
GCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCC\n\
AGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTG\n\
GCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCG\n\
CGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAG\n\
GCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAG\n\
ACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAG\n\
GCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGA\n\
AACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATC\n\
CCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAG\n\
TGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAA\n\
AAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCG\n\
GATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTA\n\
CTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGG\n\
AGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCG\n\
CGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCG\n\
GTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGT\n\
CAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAA\n\
AATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGG\n\
AGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTC\n\
CAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCT\n\
GTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA\n\
CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCG\n\
TGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAA\n\
CCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGAC\n\
AGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCAC\n\
TTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAA\n\
CATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGC\n\
CTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGA\n\
GGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCC\n\
GTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGA\n\
GGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCC\n\
CGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGC\n\
TACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGC\n\
CGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGC\n\
CGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCA\n\
CCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAA\n\
AATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCT\n\
GAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCA\n\
CTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGC\n\
TCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGA\n\
GTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTA\n\
GCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAAT\n\
CGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCC\n\
TGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAAT\n\
CCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGC\n\
CTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTG\n\
GCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGG\n\
GAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGC\n\
GAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG\n\
GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGG\n\
TGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTA\n\
ATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTG\n\
CAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTC\n\
AAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGG\n\
GCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCT\n\
CTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTC\n\
GGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGA\n\
TCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGC\n\
GCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGA\n\
GGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATAC\n\
AAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGC\n\
AGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCA\n\
CTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACG\n\
CCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCG\n\
AGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGG\n\
GCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTT\n\
GAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGC\n\
GACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAG\n\
CACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGC\n\
CAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCG\n\
CGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGC\n\
GGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGAC\n\
TCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGC\n\
CGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAA\n\
CCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCC\n\
AGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTG\n\
AGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA\n\
GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGA\n\
TCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACT\n\
AAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAG\n\
GCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCG\n\
CCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGT\n\
GGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCA\n\
GGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAA\n\
TTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAG\n\
AATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCA\n\
GCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGT\n\
AATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACC\n\
AGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTG\n\
GTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACC\n\
CGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAG\n\
AGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTT\n\
TGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACA\n\
TGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCT\n\
GTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGG\n\
TTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGT\n\
CTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGG\n\
CGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCG\n\
TCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTA\n\
CTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCG\n\
AGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCG\n\
GGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACC\n\
TGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAA\n\
TACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGA\n\
GGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACT\n\
GCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTC\n\
ACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGT\n\
TCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGC\n\
CGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCG\n\
CTTGAACCCGGGAGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTG\n\
GGCGACAGAGCGAGACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCC\n\
CAGCACTTTGGGAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCT\n\
GGCCAACATGGTGAAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGC\n\
GCGCGCCTGTAATCCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGA\n\
GGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGA\n\
GACTCCGTCTCAAAAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGA\n\
GGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTG\n\
AAACCCCGTCTCTACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAAT\n\
CCCAGCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGGAGGCGGAGGTTGCA\n\
GTGAGCCGAGATCGCGCCACTGCACTCCAGCCTGGGCGACAGAGCGAGACTCCGTCTCAA\n\
AAAGGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGGGAGGCCGAGGCGGGC\n\
GGATCACCTGAGGTCAGGAGTTCGAGACCAGCCTGGCCAACATGGTGAAACCCCGTCTCT\n\
ACTAAAAATACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCAGCTACTCGG\n\
GAGGCTGAGGCAGGAGAATC\n\
>TWO IUB ambiguity codes\n\
cttBtatcatatgctaKggNcataaaSatgtaaaDcDRtBggDtctttataattcBgtcg\n\
tactDtDagcctatttSVHtHttKtgtHMaSattgWaHKHttttagacatWatgtRgaaa\n\
NtactMcSMtYtcMgRtacttctWBacgaaatatagScDtttgaagacacatagtVgYgt\n\
cattHWtMMWcStgttaggKtSgaYaaccWStcgBttgcgaMttBYatcWtgacaYcaga\n\
gtaBDtRacttttcWatMttDBcatWtatcttactaBgaYtcttgttttttttYaaScYa\n\
HgtgttNtSatcMtcVaaaStccRcctDaataataStcYtRDSaMtDttgttSagtRRca\n\
tttHatSttMtWgtcgtatSSagactYaaattcaMtWatttaSgYttaRgKaRtccactt\n\
tattRggaMcDaWaWagttttgacatgttctacaaaRaatataataaMttcgDacgaSSt\n\
acaStYRctVaNMtMgtaggcKatcttttattaaaaagVWaHKYagtttttatttaacct\n\
tacgtVtcVaattVMBcttaMtttaStgacttagattWWacVtgWYagWVRctDattBYt\n\
gtttaagaagattattgacVatMaacattVctgtBSgaVtgWWggaKHaatKWcBScSWa\n\
accRVacacaaactaccScattRatatKVtactatatttHttaagtttSKtRtacaaagt\n\
RDttcaaaaWgcacatWaDgtDKacgaacaattacaRNWaatHtttStgttattaaMtgt\n\
tgDcgtMgcatBtgcttcgcgaDWgagctgcgaggggVtaaScNatttacttaatgacag\n\
cccccacatYScaMgtaggtYaNgttctgaMaacNaMRaacaaacaKctacatagYWctg\n\
ttWaaataaaataRattagHacacaagcgKatacBttRttaagtatttccgatctHSaat\n\
actcNttMaagtattMtgRtgaMgcataatHcMtaBSaRattagttgatHtMttaaKagg\n\
YtaaBataSaVatactWtataVWgKgttaaaacagtgcgRatatacatVtHRtVYataSa\n\
KtWaStVcNKHKttactatccctcatgWHatWaRcttactaggatctataDtDHBttata\n\
aaaHgtacVtagaYttYaKcctattcttcttaataNDaaggaaaDYgcggctaaWSctBa\n\
aNtgctggMBaKctaMVKagBaactaWaDaMaccYVtNtaHtVWtKgRtcaaNtYaNacg\n\
gtttNattgVtttctgtBaWgtaattcaagtcaVWtactNggattctttaYtaaagccgc\n\
tcttagHVggaYtgtNcDaVagctctctKgacgtatagYcctRYHDtgBattDaaDgccK\n\
tcHaaStttMcctagtattgcRgWBaVatHaaaataYtgtttagMDMRtaataaggatMt\n\
ttctWgtNtgtgaaaaMaatatRtttMtDgHHtgtcattttcWattRSHcVagaagtacg\n\
ggtaKVattKYagactNaatgtttgKMMgYNtcccgSKttctaStatatNVataYHgtNa\n\
BKRgNacaactgatttcctttaNcgatttctctataScaHtataRagtcRVttacDSDtt\n\
aRtSatacHgtSKacYagttMHtWataggatgactNtatSaNctataVtttRNKtgRacc\n\
tttYtatgttactttttcctttaaacatacaHactMacacggtWataMtBVacRaSaatc\n\
cgtaBVttccagccBcttaRKtgtgcctttttRtgtcagcRttKtaaacKtaaatctcac\n\
aattgcaNtSBaaccgggttattaaBcKatDagttactcttcattVtttHaaggctKKga\n\
tacatcBggScagtVcacattttgaHaDSgHatRMaHWggtatatRgccDttcgtatcga\n\
aacaHtaagttaRatgaVacttagattVKtaaYttaaatcaNatccRttRRaMScNaaaD\n\
gttVHWgtcHaaHgacVaWtgttScactaagSgttatcttagggDtaccagWattWtRtg\n\
ttHWHacgattBtgVcaYatcggttgagKcWtKKcaVtgaYgWctgYggVctgtHgaNcV\n\
taBtWaaYatcDRaaRtSctgaHaYRttagatMatgcatttNattaDttaattgttctaa\n\
ccctcccctagaWBtttHtBccttagaVaatMcBHagaVcWcagBVttcBtaYMccagat\n\
gaaaaHctctaacgttagNWRtcggattNatcRaNHttcagtKttttgWatWttcSaNgg\n\
gaWtactKKMaacatKatacNattgctWtatctaVgagctatgtRaHtYcWcttagccaa\n\
tYttWttaWSSttaHcaaaaagVacVgtaVaRMgattaVcDactttcHHggHRtgNcctt\n\
tYatcatKgctcctctatVcaaaaKaaaagtatatctgMtWtaaaacaStttMtcgactt\n\
taSatcgDataaactaaacaagtaaVctaggaSccaatMVtaaSKNVattttgHccatca\n\
cBVctgcaVatVttRtactgtVcaattHgtaaattaaattttYtatattaaRSgYtgBag\n\
aHSBDgtagcacRHtYcBgtcacttacactaYcgctWtattgSHtSatcataaatataHt\n\
cgtYaaMNgBaatttaRgaMaatatttBtttaaaHHKaatctgatWatYaacttMctctt\n\
ttVctagctDaaagtaVaKaKRtaacBgtatccaaccactHHaagaagaaggaNaaatBW\n\
attccgStaMSaMatBttgcatgRSacgttVVtaaDMtcSgVatWcaSatcttttVatag\n\
ttactttacgatcaccNtaDVgSRcgVcgtgaacgaNtaNatatagtHtMgtHcMtagaa\n\
attBgtataRaaaacaYKgtRccYtatgaagtaataKgtaaMttgaaRVatgcagaKStc\n\
tHNaaatctBBtcttaYaBWHgtVtgacagcaRcataWctcaBcYacYgatDgtDHccta\n\
aagacYRcaggattHaYgtKtaatgcVcaataMYacccatatcacgWDBtgaatcBaata\n\
cKcttRaRtgatgaBDacggtaattaaYtataStgVHDtDctgactcaaatKtacaatgc\n\
gYatBtRaDatHaactgtttatatDttttaaaKVccYcaaccNcBcgHaaVcattHctcg\n\
attaaatBtatgcaaaaatYMctSactHatacgaWacattacMBgHttcgaatVaaaaca\n\
BatatVtctgaaaaWtctRacgBMaatSgRgtgtcgactatcRtattaScctaStagKga\n\
DcWgtYtDDWKRgRtHatRtggtcgaHgggcgtattaMgtcagccaBggWVcWctVaaat\n\
tcgNaatcKWagcNaHtgaaaSaaagctcYctttRVtaaaatNtataaccKtaRgtttaM\n\
tgtKaBtRtNaggaSattHatatWactcagtgtactaKctatttgRYYatKatgtccgtR\n\
tttttatttaatatVgKtttgtatgtNtataRatWYNgtRtHggtaaKaYtKSDcatcKg\n\
taaYatcSRctaVtSMWtVtRWHatttagataDtVggacagVcgKWagBgatBtaaagNc\n\
aRtagcataBggactaacacRctKgttaatcctHgDgttKHHagttgttaatgHBtatHc\n\
DaagtVaBaRccctVgtgDtacRHSctaagagcggWYaBtSaKtHBtaaactYacgNKBa\n\
VYgtaacttagtVttcttaatgtBtatMtMtttaattaatBWccatRtttcatagVgMMt\n\
agctStKctaMactacDNYgKYHgaWcgaHgagattacVgtttgtRaSttaWaVgataat\n\
gtgtYtaStattattMtNgWtgttKaccaatagNYttattcgtatHcWtctaaaNVYKKt\n\
tWtggcDtcgaagtNcagatacgcattaagaccWctgcagcttggNSgaNcHggatgtVt\n\
catNtRaaBNcHVagagaaBtaaSggDaatWaatRccaVgggStctDaacataKttKatt\n\
tggacYtattcSatcttagcaatgaVBMcttDattctYaaRgatgcattttNgVHtKcYR\n\
aatRKctgtaaacRatVSagctgtWacBtKVatctgttttKcgtctaaDcaagtatcSat\n\
aWVgcKKataWaYttcccSaatgaaaacccWgcRctWatNcWtBRttYaattataaNgac\n\
acaatagtttVNtataNaYtaatRaVWKtBatKagtaatataDaNaaaaataMtaagaaS\n\
tccBcaatNgaataWtHaNactgtcDtRcYaaVaaaaaDgtttRatctatgHtgttKtga\n\
aNSgatactttcgagWaaatctKaaDaRttgtggKKagcDgataaattgSaacWaVtaNM\n\
acKtcaDaaatttctRaaVcagNacaScRBatatctRatcctaNatWgRtcDcSaWSgtt\n\
RtKaRtMtKaatgttBHcYaaBtgatSgaSWaScMgatNtctcctatttctYtatMatMt\n\
RRtSaattaMtagaaaaStcgVgRttSVaScagtgDtttatcatcatacRcatatDctta\n\
tcatVRtttataaHtattcYtcaaaatactttgVctagtaaYttagatagtSYacKaaac\n\
gaaKtaaatagataatSatatgaaatSgKtaatVtttatcctgKHaatHattagaaccgt\n\
YaaHactRcggSBNgtgctaaBagBttgtRttaaattYtVRaaaattgtaatVatttctc\n\
ttcatgBcVgtgKgaHaaatattYatagWacNctgaaMcgaattStagWaSgtaaKagtt\n\
ttaagaDgatKcctgtaHtcatggKttVDatcaaggtYcgccagNgtgcVttttagagat\n\
gctaccacggggtNttttaSHaNtatNcctcatSaaVgtactgBHtagcaYggYVKNgta\n\
KBcRttgaWatgaatVtagtcgattYgatgtaatttacDacSctgctaaaStttaWMagD\n\
aaatcaVYctccgggcgaVtaaWtStaKMgDtttcaaMtVgBaatccagNaaatcYRMBg\n\
gttWtaaScKttMWtYataRaDBMaDataatHBcacDaaKDactaMgagttDattaHatH\n\
taYatDtattDcRNStgaatattSDttggtattaaNSYacttcDMgYgBatWtaMagact\n\
VWttctttgYMaYaacRgHWaattgRtaagcattctMKVStatactacHVtatgatcBtV\n\
NataaBttYtSttacKgggWgYDtgaVtYgatDaacattYgatggtRDaVDttNactaSa\n\
MtgNttaacaaSaBStcDctaccacagacgcaHatMataWKYtaYattMcaMtgSttDag\n\
cHacgatcaHttYaKHggagttccgatYcaatgatRaVRcaagatcagtatggScctata\n\
ttaNtagcgacgtgKaaWaactSgagtMYtcttccaKtStaacggMtaagNttattatcg\n\
tctaRcactctctDtaacWYtgaYaSaagaWtNtatttRacatgNaatgttattgWDDcN\n\
aHcctgaaHacSgaataaRaataMHttatMtgaSDSKatatHHaNtacagtccaYatWtc\n\
actaactatKDacSaStcggataHgYatagKtaatKagStaNgtatactatggRHacttg\n\
tattatgtDVagDVaRctacMYattDgtttYgtctatggtKaRSttRccRtaaccttaga\n\
gRatagSaaMaacgcaNtatgaaatcaRaagataatagatactcHaaYKBctccaagaRa\n\
BaStNagataggcgaatgaMtagaatgtcaKttaaatgtaWcaBttaatRcggtgNcaca\n\
aKtttScRtWtgcatagtttWYaagBttDKgcctttatMggNttattBtctagVtacata\n\
aaYttacacaaRttcYtWttgHcaYYtaMgBaBatctNgcDtNttacgacDcgataaSat\n\
YaSttWtcctatKaatgcagHaVaacgctgcatDtgttaSataaaaYSNttatagtaNYt\n\
aDaaaNtggggacttaBggcHgcgtNtaaMcctggtVtaKcgNacNtatVaSWctWtgaW\n\
cggNaBagctctgaYataMgaagatBSttctatacttgtgtKtaattttRagtDtacata\n\
tatatgatNHVgBMtKtaKaNttDHaagatactHaccHtcatttaaagttVaMcNgHata\n\
tKtaNtgYMccttatcaaNagctggacStttcNtggcaVtattactHaSttatgNMVatt\n\
MMDtMactattattgWMSgtHBttStStgatatRaDaagattttctatMtaaaaaggtac\n\
taaVttaSacNaatactgMttgacHaHRttgMacaaaatagttaatatWKRgacDgaRta\n\
tatttattatcYttaWtgtBRtWatgHaaattHataagtVaDtWaVaWtgStcgtMSgaS\n\
RgMKtaaataVacataatgtaSaatttagtcgaaHtaKaatgcacatcggRaggSKctDc\n\
agtcSttcccStYtccRtctctYtcaaKcgagtaMttttcRaYDttgttatctaatcata\n\
NctctgctatcaMatactataggDaHaaSttMtaDtcNatataattctMcStaaBYtaNa\n\
gatgtaatHagagSttgWHVcttatKaYgDctcttggtgttMcRaVgSgggtagacaata\n\
aDtaattSaDaNaHaBctattgNtaccaaRgaVtKNtaaYggHtaKKgHcatctWtctDt\n\
ttctttggSDtNtaStagttataaacaattgcaBaBWggHgcaaaBtYgctaatgaaatW\n\
cDcttHtcMtWWattBHatcatcaaatctKMagtDNatttWaBtHaaaNgMttaaStagt\n\
tctctaatDtcRVaYttgttMtRtgtcaSaaYVgSWDRtaatagctcagDgcWWaaaBaa\n\
RaBctgVgggNgDWStNaNBKcBctaaKtttDcttBaaggBttgaccatgaaaNgttttt\n\
tttatctatgttataccaaDRaaSagtaVtDtcaWatBtacattaWacttaSgtattggD\n\
gKaaatScaattacgWcagKHaaccaYcRcaRttaDttRtttHgaHVggcttBaRgtccc\n\
tDatKaVtKtcRgYtaKttacgtatBtStaagcaattaagaRgBagSaattccSWYttta\n\
ttVaataNctgHgttaaNBgcVYgtRtcccagWNaaaacaDNaBcaaaaRVtcWMgBagM\n\
tttattacgDacttBtactatcattggaaatVccggttRttcatagttVYcatYaSHaHc\n\
ttaaagcNWaHataaaRWtctVtRYtagHtaaaYMataHYtNBctNtKaatattStgaMc\n\
BtRgctaKtgcScSttDgYatcVtggaaKtaagatWccHccgKYctaNNctacaWctttt\n\
gcRtgtVcgaKttcMRHgctaHtVaataaDtatgKDcttatBtDttggNtacttttMtga\n\
acRattaaNagaactcaaaBBVtcDtcgaStaDctgaaaSgttMaDtcgttcaccaaaag\n\
gWtcKcgSMtcDtatgtttStaaBtatagDcatYatWtaaaBacaKgcaDatgRggaaYc\n\
taRtccagattDaWtttggacBaVcHtHtaacDacYgtaatataMagaatgHMatcttat\n\
acgtatttttatattacHactgttataMgStYaattYaccaattgagtcaaattaYtgta\n\
tcatgMcaDcgggtcttDtKgcatgWRtataatatRacacNRBttcHtBgcRttgtgcgt\n\
catacMtttBctatctBaatcattMttMYgattaaVYatgDaatVagtattDacaacDMa\n\
tcMtHcccataagatgBggaccattVWtRtSacatgctcaaggggYtttDtaaNgNtaaB\n\
atggaatgtctRtaBgBtcNYatatNRtagaacMgagSaSDDSaDcctRagtVWSHtVSR\n\
ggaacaBVaccgtttaStagaacaMtactccagtttVctaaRaaHttNcttagcaattta\n\
ttaatRtaaaatctaacDaBttggSagagctacHtaaRWgattcaaBtctRtSHaNtgta\n\
cattVcaHaNaagtataccacaWtaRtaaVKgMYaWgttaKggKMtKcgWatcaDatYtK\n\
SttgtacgaccNctSaattcDcatcttcaaaDKttacHtggttHggRRaRcaWacaMtBW\n\
VHSHgaaMcKattgtaRWttScNattBBatYtaNRgcggaagacHSaattRtttcYgacc\n\
BRccMacccKgatgaacttcgDgHcaaaaaRtatatDtatYVtttttHgSHaSaatagct\n\
NYtaHYaVYttattNtttgaaaYtaKttWtctaNtgagaaaNctNDctaaHgttagDcRt\n\
tatagccBaacgcaRBtRctRtggtaMYYttWtgataatcgaataattattataVaaaaa\n\
ttacNRVYcaaMacNatRttcKatMctgaagactaattataaYgcKcaSYaatMNctcaa\n\
cgtgatttttBacNtgatDccaattattKWWcattttatatatgatBcDtaaaagttgaa\n\
VtaHtaHHtBtataRBgtgDtaataMttRtDgDcttattNtggtctatctaaBcatctaR\n\
atgNacWtaatgaagtcMNaacNgHttatactaWgcNtaStaRgttaaHacccgaYStac\n\
aaaatWggaYaWgaattattcMaactcBKaaaRVNcaNRDcYcgaBctKaacaaaaaSgc\n\
tccYBBHYaVagaatagaaaacagYtctVccaMtcgtttVatcaatttDRtgWctagtac\n\
RttMctgtDctttcKtWttttataaatgVttgBKtgtKWDaWagMtaaagaaattDVtag\n\
gttacatcatttatgtcgMHaVcttaBtVRtcgtaYgBRHatttHgaBcKaYWaatcNSc\n\
tagtaaaaatttacaatcactSWacgtaatgKttWattagttttNaggtctcaagtcact\n\
attcttctaagKggaataMgtttcataagataaaaatagattatDgcBVHWgaBKttDgc\n\
atRHaagcaYcRaattattatgtMatatattgHDtcaDtcaaaHctStattaatHaccga\n\
cNattgatatattttgtgtDtRatagSacaMtcRtcattcccgacacSattgttKaWatt\n\
NHcaacttccgtttSRtgtctgDcgctcaaMagVtBctBMcMcWtgtaacgactctcttR\n\
ggRKSttgYtYatDccagttDgaKccacgVatWcataVaaagaataMgtgataaKYaaat\n\
cHDaacgataYctRtcYatcgcaMgtNttaBttttgatttaRtStgcaacaaaataccVg\n\
aaDgtVgDcStctatatttattaaaaRKDatagaaagaKaaYYcaYSgKStctccSttac\n\
agtcNactttDVttagaaagMHttRaNcSaRaMgBttattggtttaRMggatggcKDgWR\n\
tNaataataWKKacttcKWaaagNaBttaBatMHtccattaacttccccYtcBcYRtaga\n\
ttaagctaaYBDttaNtgaaaccHcaRMtKtaaHMcNBttaNaNcVcgVttWNtDaBatg\n\
ataaVtcWKcttRggWatcattgaRagHgaattNtatttctctattaattaatgaDaaMa\n\
tacgttgggcHaYVaaNaDDttHtcaaHtcVVDgBVagcMacgtgttaaBRNtatRtcag\n\
taagaggtttaagacaVaaggttaWatctccgtVtaDtcDatttccVatgtacNtttccg\n\
tHttatKgScBatgtVgHtYcWagcaKtaMYaaHgtaattaSaHcgcagtWNaatNccNN\n\
YcacgVaagaRacttctcattcccRtgtgtaattagcSttaaStWaMtctNNcSMacatt\n\
ataaactaDgtatWgtagtttaagaaaattgtagtNagtcaataaatttgatMMYactaa\n\
tatcggBWDtVcYttcDHtVttatacYaRgaMaacaStaatcRttttVtagaDtcacWat\n\
ttWtgaaaagaaagNRacDtttStVatBaDNtaactatatcBSMcccaSttccggaMatg\n\
attaaWatKMaBaBatttgataNctgttKtVaagtcagScgaaaDggaWgtgttttKtWt\n\
atttHaatgtagttcactaaKMagttSYBtKtaYgaactcagagRtatagtVtatcaaaW\n\
YagcgNtaDagtacNSaaYDgatBgtcgataacYDtaaactacagWDcYKaagtttatta\n\
gcatcgagttKcatDaattgattatDtcagRtWSKtcgNtMaaaaacaMttKcaWcaaSV\n\
MaaaccagMVtaMaDtMaHaBgaacataBBVtaatVYaNSWcSgNtDNaaKacacBttta\n\
tKtgtttcaaHaMctcagtaacgtcgYtactDcgcctaNgagagcYgatattttaaattt\n\
ccattttacatttDaaRctattttWctttacgtDatYtttcagacgcaaVttagtaaKaa\n\
aRtgVtccataBggacttatttgtttaWNtgttVWtaWNVDaattgtatttBaagcBtaa\n\
BttaaVatcHcaVgacattccNggtcgacKttaaaRtagRtctWagaYggtgMtataatM\n\
tgaaRttattttgWcttNtDRRgMDKacagaaaaggaaaRStcccagtYccVattaNaaK\n\
StNWtgacaVtagaagcttSaaDtcacaacgDYacWDYtgtttKatcVtgcMaDaSKStV\n\
cgtagaaWaKaagtttcHaHgMgMtctataagBtKaaaKKcactggagRRttaagaBaaN\n\
atVVcgRcKSttDaactagtSttSattgttgaaRYatggttVttaataaHttccaagDtg\n\
atNWtaagHtgcYtaactRgcaatgMgtgtRaatRaNaacHKtagactactggaatttcg\n\
ccataacgMctRgatgttaccctaHgtgWaYcactcacYaattcttaBtgacttaaacct\n\
gYgaWatgBttcttVttcgttWttMcNYgtaaaatctYgMgaaattacNgaHgaacDVVM\n\
tttggtHtctaaRgtacagacgHtVtaBMNBgattagcttaRcttacaHcRctgttcaaD\n\
BggttKaacatgKtttYataVaNattccgMcgcgtagtRaVVaattaKaatggttRgaMc\n\
agtatcWBttNtHagctaatctagaaNaaacaYBctatcgcVctBtgcaaagDgttVtga\n\
HtactSNYtaaNccatgtgDacgaVtDcgKaRtacDcttgctaagggcagMDagggtBWR\n\
tttSgccttttttaacgtcHctaVtVDtagatcaNMaVtcVacatHctDWNaataRgcgt\n\
aVHaggtaaaaSgtttMtattDgBtctgatSgtRagagYtctSaKWaataMgattRKtaa\n\
catttYcgtaacacattRWtBtcggtaaatMtaaacBatttctKagtcDtttgcBtKYYB\n\
aKttctVttgttaDtgattttcttccacttgSaaacggaaaNDaattcYNNaWcgaaYat\n\
tttMgcBtcatRtgtaaagatgaWtgaccaYBHgaatagataVVtHtttVgYBtMctaMt\n\
cctgaDcYttgtccaaaRNtacagcMctKaaaggatttacatgtttaaWSaYaKttBtag\n\
DacactagctMtttNaKtctttcNcSattNacttggaacaatDagtattRtgSHaataat\n\
gccVgacccgatactatccctgtRctttgagaSgatcatatcgDcagWaaHSgctYYWta\n\
tHttggttctttatVattatcgactaagtgtagcatVgtgHMtttgtttcgttaKattcM\n\
atttgtttWcaaStNatgtHcaaaDtaagBaKBtRgaBgDtSagtatMtaacYaatYtVc\n\
KatgtgcaacVaaaatactKcRgtaYtgtNgBBNcKtcttaccttKgaRaYcaNKtactt\n\
tgagSBtgtRagaNgcaaaNcacagtVtttHWatgttaNatBgtttaatNgVtctgaata\n\
tcaRtattcttttttttRaaKcRStctcggDgKagattaMaaaKtcaHacttaataataK\n\
taRgDtKVBttttcgtKaggHHcatgttagHggttNctcgtatKKagVagRaaaggaaBt\n\
NatttVKcRttaHctaHtcaaatgtaggHccaBataNaNaggttgcWaatctgatYcaaa\n\
HaatWtaVgaaBttagtaagaKKtaaaKtRHatMaDBtBctagcatWtatttgWttVaaa\n\
ScMNattRactttgtYtttaaaagtaagtMtaMaSttMBtatgaBtttaKtgaatgagYg\n\
tNNacMtcNRacMMHcttWtgtRtctttaacaacattattcYaMagBaacYttMatcttK\n\
cRMtgMNccattaRttNatHaHNaSaaHMacacaVaatacaKaSttHatattMtVatWga\n\
ttttttaYctttKttHgScWaacgHtttcaVaaMgaacagNatcgttaacaaaaagtaca\n\
HBNaattgttKtcttVttaaBtctgctacgBgcWtttcaggacacatMgacatcccagcg\n\
gMgaVKaBattgacttaatgacacacaaaaaatRKaaBctacgtRaDcgtagcVBaacDS\n\
BHaaaaSacatatacagacRNatcttNaaVtaaaataHattagtaaaaSWccgtatWatg\n\
gDttaactattgcccatcttHaSgYataBttBaactattBtcHtgatcaataSttaBtat\n\
KSHYttWggtcYtttBttaataccRgVatStaHaKagaatNtagRMNgtcttYaaSaact\n\
cagDSgagaaYtMttDtMRVgWKWtgMaKtKaDttttgactatacataatcNtatNaHat\n\
tVagacgYgatatatttttgtStWaaatctWaMgagaRttRatacgStgattcttaagaD\n\
taWccaaatRcagcagaaNKagtaaDggcgccBtYtagSBMtactaaataMataBSacRM\n\
gDgattMMgtcHtcaYDtRaDaacggttDaggcMtttatgttaNctaattaVacgaaMMt\n\
aatDccSgtattgaRtWWaccaccgagtactMcgVNgctDctaMScatagcgtcaactat\n\
acRacgHRttgctatttaatgaattataYKttgtaagWgtYttgcHgMtaMattWaWVta\n\
RgcttgYgttBHtYataSccStBtgtagMgtDtggcVaaSBaatagDttgBgtctttctc\n\
attttaNagtHKtaMWcYactVcgcgtatMVtttRacVagDaatcttgctBBcRDgcaac\n\
KttgatSKtYtagBMagaRtcgBattHcBWcaactgatttaatttWDccatttatcgagS\n\
KaWttataHactaHMttaatHtggaHtHagaatgtKtaaRactgtttMatacgatcaagD\n\
gatKaDctataMggtHDtggHacctttRtatcttYattttgacttgaaSaataaatYcgB\n\
aaaaccgNatVBttMacHaKaataagtatKgtcaagactcttaHttcggaattgttDtct\n\
aaccHttttWaaatgaaatataaaWattccYDtKtaaaacggtgaggWVtctattagtga\n\
ctattaagtMgtttaagcatttgSgaaatatccHaaggMaaaattttcWtatKctagDtY\n\
tMcctagagHcactttactatacaaacattaacttaHatcVMYattYgVgtMttaaRtga\n\
aataaDatcaHgtHHatKcDYaatcttMtNcgatYatgSaMaNtcttKcWataScKggta\n\
tcttacgcttWaaagNatgMgHtctttNtaacVtgttcMaaRatccggggactcMtttaY\n\
MtcWRgNctgNccKatcttgYDcMgattNYaRagatHaaHgKctcataRDttacatBatc\n\
cattgDWttatttaWgtcggagaaaaatacaatacSNtgggtttccttacSMaagBatta\n\
caMaNcactMttatgaRBacYcYtcaaaWtagctSaacttWgDMHgaggatgBVgcHaDt\n\
ggaactttggtcNatNgtaKaBcccaNtaagttBaacagtatacDYttcctNgWgcgSMc\n\
acatStctHatgRcNcgtacacaatRttMggaNKKggataaaSaYcMVcMgtaMaHtgat\n\
tYMatYcggtcttcctHtcDccgtgRatcattgcgccgatatMaaYaataaYSggatagc\n\
gcBtNtaaaScaKgttBgagVagttaKagagtatVaactaSacWactSaKatWccaKaaa\n\
atBKgaaKtDMattttgtaaatcRctMatcaaMagMttDgVatggMaaWgttcgaWatga\n\
aatttgRtYtattaWHKcRgctacatKttctaccaaHttRatctaYattaaWatVNccat\n\
NgagtcKttKataStRaatatattcctRWatDctVagttYDgSBaatYgttttgtVaatt\n\
taatagcagMatRaacttBctattgtMagagattaaactaMatVtHtaaatctRgaaaaa\n\
aaatttWacaacaYccYDSaattMatgaccKtaBKWBattgtcaagcHKaagttMMtaat\n\
ttcKcMagNaaKagattggMagaggtaatttYacatcWaaDgatMgKHacMacgcVaaca\n\
DtaDatatYggttBcgtatgWgaSatttgtagaHYRVacaRtctHaaRtatgaactaata\n\
tctSSBgggaaHMWtcaagatKgagtDaSatagttgattVRatNtctMtcSaagaSHaat\n\
aNataataRaaRgattctttaataaagWaRHcYgcatgtWRcttgaaggaMcaataBRaa\n\
ccagStaaacNtttcaatataYtaatatgHaDgcStcWttaacctaRgtYaRtataKtgM\n\
ttttatgactaaaatttacYatcccRWtttHRtattaaatgtttatatttgttYaatMca\n\
RcSVaaDatcgtaYMcatgtagacatgaaattgRtcaaYaaYtRBatKacttataccaNa\n\
aattVaBtctggacaagKaaYaaatatWtMtatcYaaVNtcgHaactBaagKcHgtctac\n\
aatWtaDtSgtaHcataHtactgataNctRgttMtDcDttatHtcgtacatcccaggStt\n\
aBgtcacacWtccNMcNatMVaVgtccDYStatMaccDatggYaRKaaagataRatttHK\n\
tSaaatDgataaacttaHgttgVBtcttVttHgDacgaKatgtatatNYataactctSat\n\
atatattgcHRRYttStggaactHgttttYtttaWtatMcttttctatctDtagVHYgMR\n\
BgtHttcctaatYRttKtaagatggaVRataKDctaMtKBNtMtHNtWtttYcVtattMc\n\
gRaacMcctNSctcatttaaagDcaHtYccSgatgcaatYaaaaDcttcgtaWtaattct\n\
cgttttScttggtaatctttYgtctaactKataHacctMctcttacHtKataacacagcN\n\
RatgKatttttSaaatRYcgDttaMRcgaaattactMtgcgtaagcgttatBtttttaat\n\
taagtNacatHgttcRgacKcBBtVgatKttcgaBaatactDRgtRtgaNacWtcacYtt\n\
aaKcgttctHaKttaNaMgWgWaggtctRgaKgWttSttBtDcNtgtttacaaatYcDRt\n\
gVtgcctattcNtctaaaDMNttttNtggctgagaVctDaacVtWccaagtaacacaNct\n\
gaScattccDHcVBatcgatgtMtaatBgHaatDctMYgagaatgYWKcctaatNaStHa\n\
aaKccgHgcgtYaaYtattgtStgtgcaaRtattaKatattagaWVtcaMtBagttatta\n\
gNaWHcVgcaattttDcMtgtaRHVYtHtctgtaaaaHVtMKacatcgNaatttMatatg\n\
ttgttactagWYtaRacgataKagYNKcattataNaRtgaacKaYgcaaYYacaNccHat\n\
MatDcNgtHttRaWttagaaDcaaaaaatagggtKDtStaDaRtaVtHWKNtgtattVct\n\
SVgRgataDaRaWataBgaagaaKtaataaYgDcaStaNgtaDaaggtattHaRaWMYaY\n\
aWtggttHYgagVtgtgcttttcaaDKcagVcgttagacNaaWtagtaataDttctggtt\n\
VcatcataaagtgKaaaNaMtaBBaattaatWaattgctHaVKaSgDaaVKaHtatatat\n\
HatcatSBagNgHtatcHYMHgttDgtaHtBttWatcgtttaRaattgStKgSKNWKatc\n\
agDtctcagatttctRtYtBatBgHHtKaWtgYBgacVVWaKtacKcDttKMaKaVcggt\n\
gttataagaataaHaatattagtataatMHgttYgaRttagtaRtcaaVatacggtcMcg\n\
agtaaRttacWgactKRYataaaagSattYaWgagatYagKagatgSaagKgttaatMgg\n\
tataatgttWYttatgagaaacctNVataatHcccKtDctcctaatactggctHggaSag\n\
gRtKHaWaattcgSatMatttagaggcYtctaMcgctcataSatatgRagacNaaDagga\n\
VBagaYttKtacNaKgtSYtagttggaWcatcWttaatctatgaVtcgtgtMtatcaYcg\n\
tRccaaYgDctgcMgtgtWgacWtgataacacgcgctBtgttaKtYDtatDcatcagKaV\n\
MctaatcttgVcaaRgcRMtDcgattaHttcaNatgaatMtactacVgtRgatggaWttt\n\
actaaKatgagSaaKggtaNtactVaYtaaKRagaacccacaMtaaMtKtatBcttgtaa\n\
WBtMctaataaVcDaaYtcRHBtcgttNtaaHatttBNgRStVDattBatVtaagttaYa\n\
tVattaagaBcacggtSgtVtatttaRattgatgtaHDKgcaatattKtggcctatgaWD\n\
KRYcggattgRctatNgatacaatMNttctgtcRBYRaaaHctNYattcHtaWcaattct\n\
BtMKtVgYataatMgYtcagcttMDataVtggRtKtgaatgccNcRttcaMtRgattaac\n\
attRcagcctHtWMtgtDRagaKaBtgDttYaaaaKatKgatctVaaYaacWcgcatagB\n\
VtaNtRtYRaggBaaBtgKgttacataagagcatgtRattccacttaccatRaaatgWgD\n\
aMHaYVgVtaSctatcgKaatatattaDgacccYagtgtaYNaaatKcagtBRgagtcca\n\
tgKgaaaccBgaagBtgSttWtacgatWHaYatcgatttRaaNRgcaNaKVacaNtDgat\n\
tgHVaatcDaagcgtatgcNttaDataatcSataaKcaataaHWataBtttatBtcaKtK\n\
tatagttaDgSaYctacaRatNtaWctSaatatttYaKaKtaccWtatcRagacttaYtt\n\
VcKgSDcgagaagatccHtaattctSttatggtKYgtMaHagVaBRatttctgtRgtcta\n\
tgggtaHKgtHacHtSYacgtacacHatacKaaBaVaccaDtatcSaataaHaagagaat\n\
ScagactataaRttagcaaVcaHataKgDacatWccccaagcaBgagWatctaYttgaaa\n\
tctVNcYtttWagHcgcgcDcVaaatgttKcHtNtcaatagtgtNRaactttttcaatgg\n\
WgBcgDtgVgtttctacMtaaataaaRggaaacWaHttaRtNtgctaaRRtVBctYtVta\n\
tDcattDtgaccYatagatYRKatNYKttNgcctagtaWtgaactaMVaacctgaStttc\n\
tgaKVtaaVaRKDttVtVctaDNtataaaDtccccaagtWtcgatcactDgYaBcatcct\n\
MtVtacDaaBtYtMaKNatNtcaNacgDatYcatcgcaRatWBgaacWttKttagYtaat\n\
tcggttgSWttttDWctttacYtatatWtcatDtMgtBttgRtVDggttaacYtacgtac\n\
atgaattgaaWcttMStaDgtatattgaDtcRBcattSgaaVBRgagccaaKtttcDgcg\n\
aSMtatgWattaKttWtgDBMaggBBttBaatWttRtgcNtHcgttttHtKtcWtagHSt\n\
aacagttgatatBtaWSaWggtaataaMttaKacDaatactcBttcaatatHttcBaaSa\n\
aatYggtaRtatNtHcaatcaHtagVtgtattataNggaMtcttHtNagctaaaggtaga\n\
YctMattNaMVNtcKtactBKcaHHcBttaSagaKacataYgctaKaYgttYcgacWVtt\n\
WtSagcaacatcccHaccKtcttaacgaKttcacKtNtacHtatatRtaaatacactaBt\n\
ttgaHaRttggttWtatYagcatYDatcggagagcWBataagRtacctataRKgtBgatg\n\
aDatataSttagBaHtaatNtaDWcWtgtaattacagKttcNtMagtattaNgtctcgtc\n\
ctcttBaHaKcKccgtRcaaYagSattaagtKataDatatatagtcDtaacaWHcaKttD\n\
gaaRcgtgYttgtcatatNtatttttatggccHtgDtYHtWgttatYaacaattcaWtat\n\
NgctcaaaSttRgctaatcaaatNatcgtttaBtNNVtgttataagcaaagattBacgtD\n\
atttNatttaaaDcBgtaSKgacgtagataatttcHMVNttgttBtDtgtaWKaaRMcKM\n\
tHtaVtagataWctccNNaSWtVaHatctcMgggDgtNHtDaDttatatVWttgttattt\n\
aacctttcacaaggaSaDcggttttttatatVtctgVtaacaStDVaKactaMtttaSNa\n\
gtgaaattaNacttSKctattcctctaSagKcaVttaagNaVcttaVaaRNaHaaHttat\n\
gtHttgtgatMccaggtaDcgaccgtWgtWMtttaHcRtattgScctatttKtaaccaag\n\
tYagaHgtWcHaatgccKNRtttagtMYSgaDatctgtgaWDtccMNcgHgcaaacNDaa\n\
aRaStDWtcaaaaHKtaNBctagBtgtattaactaattttVctagaatggcWSatMaccc\n\
ttHttaSgSgtgMRcatRVKtatctgaaaccDNatYgaaVHNgatMgHRtacttaaaRta\n\
tStRtDtatDttYatattHggaBcttHgcgattgaKcKtttcRataMtcgaVttWacatN\n\
catacctRataDDatVaWNcggttgaHtgtMacVtttaBHtgagVttMaataattatgtt\n\
cttagtttgtgcDtSatttgBtcaacHattaaBagVWcgcaSYttMgcttacYKtVtatc\n\
aYaKctgBatgcgggcYcaaaaacgNtctagKBtattatctttKtaVttatagtaYtRag\n\
NtaYataaVtgaatatcHgcaaRataHtacacatgtaNtgtcgYatWMatttgaactacR\n\
ctaWtWtatacaatctBatatgYtaagtatgtgtatSttactVatcttYtaBcKgRaSgg\n\
RaaaaatgcagtaaaWgtaRgcgataatcBaataccgtatttttccatcNHtatWYgatH\n\
SaaaDHttgctgtccHtggggcctaataatttttctatattYWtcattBtgBRcVttaVM\n\
RSgctaatMagtYtttaaaaatBRtcBttcaaVtaacagctccSaaSttKNtHtKYcagc\n\
agaaaccccRtttttaaDcDtaStatccaagcgctHtatcttaDRYgatDHtWcaaaBcW\n\
gKWHttHataagHacgMNKttMKHccaYcatMVaacgttaKgYcaVaaBtacgcaacttt\n\
MctaaHaatgtBatgagaSatgtatgSRgHgWaVWgataaatatttccKagVgataattW\n\
aHNcYggaaatgctHtKtaDtctaaagtMaatVDVactWtSaaWaaMtaHtaSKtcBRaN\n\
cttStggtBttacNagcatagRgtKtgcgaacaacBcgKaatgataagatgaaaattgta\n\
ctgcgggtccHHWHaaNacaBttNKtKtcaaBatatgctaHNgtKcDWgtttatNgVDHg\n\
accaacWctKaaggHttgaRgYaatHcaBacaatgagcaaattactgtaVaaYaDtagat\n\
tgagNKggtggtgKtWKaatacagDRtatRaMRtgattDggtcaaYRtatttNtagaDtc\n\
acaaSDctDtataatcgtactaHttatacaatYaacaaHttHatHtgcgatRRttNgcat\n\
SVtacWWgaaggagtatVMaVaaattScDDKNcaYBYaDatHgtctatBagcaacaagaa\n\
tgagaaRcataaKNaRtBDatcaaacgcattttttaaBtcSgtacaRggatgtMNaattg\n\
gatatWtgagtattaaaVctgcaYMtatgatttttYgaHtgtcttaagWBttHttgtctt\n\
attDtcgtatWtataataSgctaHagcDVcNtaatcaagtaBDaWaDgtttagYctaNcc\n\
DtaKtaHcttaataacccaRKtacaVaatNgcWRaMgaattatgaBaaagattVYaHMDc\n\
aDHtcRcgYtcttaaaWaaaVKgatacRtttRRKYgaatacaWVacVcRtatMacaBtac\n\
tggMataaattttHggNagSctacHgtBagcgtcgtgattNtttgatSaaggMttctttc\n\
ttNtYNagBtaaacaaatttMgaccttacataattgYtcgacBtVMctgStgMDtagtaR\n\
ctHtatgttcatatVRNWataDKatWcgaaaaagttaaaagcacgHNacgtaatctttMR\n\
tgacttttDacctataaacgaaatatgattagaactccSYtaBctttaataacWgaaaYa\n\
tagatgWttcatKtNgatttttcaagHtaYgaaRaDaagtaggagcttatVtagtctttc\n\
attaaaatcgKtattaRttacagVaDatgcatVgattgggtctttHVtagKaaRBtaHta\n\
aggccccaaaaKatggtttaMWgtBtaaacttcactttKHtcgatctccctaYaBacMgt\n\
cttBaBaNgcgaaacaatctagtHccHtKttcRtRVttccVctttcatacYagMVtMcag\n\
aMaaacaataBctgYtaatRaaagattaaccatVRatHtaRagcgcaBcgDttStttttc\n\
VtttaDtKgcaaWaaaaatSccMcVatgtKgtaKgcgatatgtagtSaaaDttatacaaa\n\
catYaRRcVRHctKtcgacKttaaVctaDaatgttMggRcWaacttttHaDaKaDaBctg\n\
taggcgtttaHBccatccattcNHtDaYtaataMttacggctNVaacDattgatatttta\n\
cVttSaattacaaRtataNDgacVtgaacataVRttttaDtcaaacataYDBtttaatBa\n\
DtttYDaDaMccMttNBttatatgagaaMgaNtattHccNataattcaHagtgaaggDga\n\
tgtatatatgYatgaStcataaBStWacgtcccataRMaaDattggttaaattcMKtctM\n\
acaBSactcggaatDDgatDgcWctaacaccgggaVcacWKVacggtaNatatacctMta\n\
tgatagtgcaKagggVaDtgtaacttggagtcKatatcgMcttRaMagcattaBRaStct\n\
YSggaHYtacaactMBaagDcaBDRaaacMYacaHaattagcattaaaHgcgctaaggSc\n\
cKtgaaKtNaBtatDDcKBSaVtgatVYaagVtctSgMctacgttaacWaaattctSgtD\n\
actaaStaaattgcagBBRVctaatatacctNttMcRggctttMttagacRaHcaBaacV\n\
KgaataHttttMgYgattcYaNRgttMgcVaaacaVVcDHaatttgKtMYgtatBtVVct\n\
WgVtatHtacaaHttcacgatagcagtaaNattBatatatttcVgaDagcggttMaagtc\n\
ScHagaaatgcYNggcgtttttMtStggtRatctacttaaatVVtBacttHNttttaRca\n\
aatcacagHgagagtMgatcSWaNRacagDtatactaaDKaSRtgattctccatSaaRtt\n\
aaYctacacNtaRtaactggatgaccYtacactttaattaattgattYgttcagDtNKtt\n\
agDttaaaaaaaBtttaaNaYWKMBaaaacVcBMtatWtgBatatgaacVtattMtYatM\n\
NYDKNcKgDttDaVtaaaatgggatttctgtaaatWtctcWgtVVagtcgRgacttcccc\n\
taDcacagcRcagagtgtWSatgtacatgttaaSttgtaaHcgatgggMagtgaacttat\n\
RtttaVcaccaWaMgtactaatSSaHtcMgaaYtatcgaaggYgggcgtgaNDtgttMNg\n\
aNDMtaattcgVttttaacatgVatgtWVMatatcaKgaaattcaBcctccWcttgaaWH\n\
tWgHtcgNWgaRgctcBgSgaattgcaaHtgattgtgNagtDttHHgBttaaWcaaWagc\n\
aSaHHtaaaVctRaaMagtaDaatHtDMtcVaWMtagSagcttHSattaacaaagtRacM\n\
tRtctgttagcMtcaBatVKtKtKacgagaSNatSactgtatatcBctgagVtYactgta\n\
aattaaaggcYgDHgtaacatSRDatMMccHatKgttaacgactKtgKagtcttcaaHRV\n\
tccttKgtSataatttacaactggatDNgaacttcaRtVaagDcaWatcBctctHYatHa\n\
DaaatttagYatSatccaWtttagaaatVaacBatHcatcgtacaatatcgcNYRcaata\n\
YaRaYtgattVttgaatgaVaactcRcaNStgtgtattMtgaggtNttBaDRcgaaaagc\n\
tNgBcWaWgtSaDcVtgVaatMKBtttcgtttctaaHctaaagYactgMtatBDtcStga\n\
ccgtSDattYaataHctgggaYYttcggttaWaatctggtRagWMaDagtaacBccacta\n\
cgHWMKaatgatWatcctgHcaBaSctVtcMtgtDttacctaVgatYcWaDRaaaaRtag\n\
atcgaMagtggaRaWctctgMgcWttaagKBRtaaDaaWtctgtaagYMttactaHtaat\n\
cttcataacggcacBtSgcgttNHtgtHccatgttttaaagtatcgaKtMttVcataYBB\n\
aKtaMVaVgtattNDSataHcagtWMtaggtaSaaKgttgBtVtttgttatcatKcgHac\n\
acRtctHatNVagSBgatgHtgaRaSgttRcctaacaaattDNttgacctaaYtBgaaaa\n\
tagttattactcttttgatgtNNtVtgtatMgtcttRttcatttgatgacacttcHSaaa\n\
ccaWWDtWagtaRDDVNacVaRatgttBccttaatHtgtaaacStcVNtcacaSRttcYa\n\
gacagaMMttttgMcNttBcgWBtactgVtaRttctccaaYHBtaaagaBattaYacgat\n\
ttacatctgtaaMKaRYtttttactaaVatWgctBtttDVttctggcDaHaggDaagtcg\n\
aWcaagtagtWttHtgKtVataStccaMcWcaagataagatcactctHatgtcYgaKcat\n\
cagatactaagNSStHcctRRNtattgtccttagttagMVgtatagactaactctVcaat\n\
MctgtttgtgttgccttatWgtaBVtttctggMcaaKgDWtcgtaaYStgSactatttHg\n\
atctgKagtagBtVacRaagRtMctatgggcaaaKaaaatacttcHctaRtgtDcttDat\n\
taggaaatttcYHaRaaBttaatggcacKtgctHVcaDcaaaVDaaaVcgMttgtNagcg\n\
taDWgtcgttaatDgKgagcSatatcSHtagtagttggtgtHaWtaHKtatagctgtVga\n\
ttaBVaatgaataagtaatVatSttaHctttKtttgtagttaccttaatcgtagtcctgB\n\
cgactatttVcMacHaaaggaatgDatggKtaHtgStatattaaSagctWcctccRtata\n\
BaDYcgttgcNaagaggatRaaaYtaWgNtSMcaatttactaacatttaaWttHtatBat\n\
tgtcgacaatNgattgcNgtMaaaKaBDattHacttggtRtttaYaacgVactBtaBaKt\n\
gBttatgVttgtVttcaatcWcNctDBaaBgaDHacBttattNtgtDtatttVSaaacag\n\
gatgcRatSgtaSaNtgBatagttcHBgcBBaaattaHgtDattatDaKaatBaaYaaMa\n\
ataaataKtttYtagtBgMatNcatgtttgaNagtgttgtgKaNaSagtttgaSMaYBca\n\
aaacDStagttVacaaaaactaaWttBaagtctgtgcgtMgtaattctcctacctcaNtt\n\
taaccaaaaVtBcacataacaccccBcWMtatVtggaatgaWtcaaWaaaaaaaaWtDta\n\
atatRcctDWtcctaccMtVVatKttaWaaKaaatataaagScHBagaggBaSMtaWaVt\n\
atattactSaaaKNaactatNatccttgaYctattcaaaVgatttYHcRagattttaSat\n\
aggttattcVtaaagaKgtattattKtRttNcggcRgtgtgtWYtaacHgKatKgatYta\n\
cYagDtWcHBDctctgRaYKaYagcactKcacSaRtBttttBHKcMtNtcBatttatttt\n\
tgSatVgaaagaWtcDtagDatatgMacaacRgatatatgtttgtKtNRaatatNatgYc\n\
aHtgHataacKtgagtagtaacYttaNccaaatHcacaacaVDtagtaYtccagcattNt\n\
acKtBtactaaagaBatVtKaaHBctgStgtBgtatgaSNtgDataaccctgtagcaBgt\n\
gatcttaDataStgaMaccaSBBgWagtacKcgattgaDgNNaaaacacagtSatBacKD\n\
gcgtataBKcatacactaSaatYtYcDaactHttcatRtttaatcaattataRtttgtaa\n\
gMcgNttcatcBtYBagtNWNMtSHcattcRctttttRWgaKacKttgggagBcgttcgc\n\
MaWHtaatactgtctctatttataVgtttaBScttttaBMaNaatMacactYtBMggtHa\n\
cMagtaRtctgcatttaHtcaaaatttgagKtgNtactBacaHtcgtatttctMaSRagc\n\
agttaatgtNtaaattgagagWcKtaNttagVtacgatttgaatttcgRtgtWcVatcgt\n\
taaDVctgtttBWgaccagaaagtcSgtVtatagaBccttttcctaaattgHtatcggRa\n\
ttttcaaggcYSKaagWaWtRactaaaacccBatMtttBaatYtaagaactSttcgaaSc\n\
aatagtattgaccaagtgttttctaacatgtttNVaatcaaagagaaaNattaaRtttta\n\
VaaaccgcaggNMtatattVctcaagaggaacgBgtttaacaagttcKcYaatatactaa\n\
ccBaaaSggttcNtattctagttRtBacgScVctcaatttaatYtaaaaaaatgSaatga\n\
tagaMBRatgRcMcgttgaWHtcaVYgaatYtaatctttYttatRaWtctgBtDcgatNa\n\
tcKaBaDgatgtaNatWKctccgatattaacattNaaacDatgBgttctgtDtaaaMggt\n\
gaBaSHataacgccSctaBtttaRBtcNHcDatcDcctagagtcRtaBgWttDRVHagat\n\
tYatgtatcWtaHtttYcattWtaaagtctNgtStggRNcgcggagSSaaagaaaatYcH\n\
DtcgctttaatgYcKBVSgtattRaYBaDaaatBgtatgaHtaaRaRgcaSWNtagatHa\n\
acttNctBtcaccatctMcatattccaSatttgcgaDagDgtatYtaaaVDtaagtttWV\n\
aagtagYatRttaagDcNgacKBcScagHtattatcDaDactaaaaaYgHttBcgaDttg\n\
gataaaKSRcBMaBcgaBSttcWtgNBatRaccgattcatttataacggHVtaattcaca\n\
agagVttaaRaatVVRKcgWtVgacctgDgYaaHaWtctttcacMagggatVgactagMa\n\
aataKaaNWagKatagNaaWtaaaatttgaattttatttgctaaVgaHatBatcaaBWcB\n\
gttcMatcgBaaNgttcgSNaggSaRtttgHtRtattaNttcDcatSaVttttcgaaaaa\n\
ttgHatctaRaggSaNatMDaaatDcacgattttagaHgHaWtYgattaatHNSttatMS\n\
gggNtcKtYatRggtttgtMWVtttaYtagcagBagHaYagttatatggtBacYcattaR\n\
SataBatMtttaaatctHcaaaSaaaagttNSaaWcWRccRtKaagtBWtcaaattSttM\n\
tattggaaaccttaacgttBtWatttatatWcDaatagattcctScacctaagggRaaYt\n\
aNaatgVtBcttaaBaacaMVaaattatStYgRcctgtactatcMcVKatttcgSgatRH\n\
MaaaHtagtaaHtVgcaaataatatcgKKtgccaatBNgaaWcVttgagttaKatagttc\n\
aggKDatDtattgaKaVcaKtaataDataataHSaHcattagttaatRVYcNaHtaRcaa\n\
ggtNHcgtcaaccaBaaagYtHWaaaRcKgaYaaDttgcWYtataRgaatatgtYtgcKt\n\
aNttWacatYHctRaDtYtattcBttttatcSataYaYgttWaRagcacHMgtttHtYtt\n\
YaatcggtatStttcgtRSattaaDaKMaatatactaNBaWgctacacYtgaYVgtgHta\n\
aaRaaRgHtagtWattataaaSDaaWtgMattatcgaaaagtaYRSaWtSgNtBgagcRY\n\
aMDtactaacttaWgtatctagacaagNtattHggataatYttYatcataDcgHgttBtt\n\
ctttVttgccgaaWtaaaacgKgtatctaaaaaNtccDtaDatBMaMggaatNKtatBaa\n\
atVtccRaHtaSacataHattgtttKVYattcataVaattWtcgtgMttcttKtgtctaa\n\
cVtatctatatBRataactcgKatStatattcatHHRttKtccaacgtgggtgRgtgaMt\n\
attattggctatcgtgacMtRcBDtcttgtactaatRHttttaagatcgVMDStattatY\n\
BtttDttgtBtNttgRcMtYtgBacHaWaBaatDKctaagtgaaactaatgRaaKgatcc\n\
aagNaaaatattaggWNtaagtatacttttKcgtcggSYtcttgRctataYcttatataa\n\
agtatattaatttataVaacacaDHatctatttttKYVatHRactttaBHccaWagtact\n\
BtcacgaVgcgttRtttttttSVgtSagtBaaattctgaHgactcttgMcattttagVta\n\
agaattHctHtcaDaaNtaacRggWatagttcgtSttgaDatcNgNagctagDgatcNtt\n\
KgttgtaDtctttRaaYStRatDtgMggactSttaDtagSaVtBDttgtDgccatcacaM\n\
attaaaMtNacaVcgSWcVaaDatcaHaatgaattaMtatccVtctBtaattgtWattat\n\
BRcWcaatgNNtactWYtDaKttaaatcactcagtRaaRgatggtKgcgccaaHgaggat\n\
StattYcaNMtcaBttacttatgagDaNtaMgaaWtgtttcttctaHtMNgttatctaWW\n\
atMtBtaaatagDVatgtBYtatcggcttaagacMRtaHScgatatYgRDtcattatSDa\n\
HggaaataNgaWSRRaaaBaatagBattaDctttgHWNttacaataaaaaaatacggttt\n\
gHgVtaHtWMttNtBtctagtMcgKMgHgYtataHaNagWtcaacYattaataYRgtaWK\n\
gaBctataaccgatttaHaNBRaRaMtccggtNgacMtctcatttgcaattcWgMactta\n\
caaDaaNtactWatVtttagccttMaatcagVaagtctVaaDaBtattaattaYtNaYtg\n\
gattaKtaKctYaMtattYgatattataatKtVgDcttatatNBtcgttgtStttttMag\n\
aggttaHYSttcKgtcKtDNtataagttataagSgttatDtRttattgttttSNggRtca\n\
aKMNatgaatattgtBWtaMacctgggYgaSgaagYataagattacgagaatBtggtRcV\n\
HtgYggaDgaYaKagWagctatagacgaaHgtWaNgacttHRatVaWacKYtgRVNgVcS\n\
gRWctacatcKSactctgWYtBggtataagcttNRttVtgRcaWaaatDMatYattaact\n\
ttcgaagRatSctgccttgcRKaccHtttSNVagtagHagBagttagaccaRtataBcca\n\
taatSHatRtcHagacBWatagcaMtacaRtgtgaaBatctKRtScttccaNaatcNgta\n\
atatWtcaMgactctBtWtaaNactHaaaaRctcgcatggctMcaaNtcagaaaaacaca\n\
gtggggWttRttagtaagaVctVMtcgaatcttcMaaaHcaHBttcgattatgtcaDagc\n\
YRtBtYcgacMgtDcagcgaNgttaataatagcagKYYtcgtaBtYctMaRtaRtDagaa\n\
aacacatgYaBttgattattcgaaNttBctSataaMataWRgaHtttccgtDgaYtatgg\n\
tDgHKgMtatttVtMtVagttaRatMattRagataaccctKctMtSttgaHagtcStcta\n\
tttccSagatgttccacgaggYNttHRacgattcDatatDcataaaatBBttatcgaHtN\n\
HaaatatDNaggctgaNcaaggagttBttMgRagVatBcRtaWgatgBtSgaKtcgHttt\n\
gaatcaaDaHttcSBgHcagtVaaSttDcagccgttNBtgttHagYtattctttRWaaVt\n\
SttcatatKaaRaaaNacaVtVctMtSDtDtRHRcgtaatgctcttaaatSacacaatcg\n\
HattcaWcttaaaatHaaatcNctWttaNMcMtaKctVtcctaagYgatgatcYaaaRac\n\
tctaRDaYagtaacgtDgaggaaatctcaaacatcaScttcKttNtaccatNtaNataca\n\
tttHaaDHgcaDatMWaaBttcRggctMaagctVYcacgatcaDttatYtaatcKatWat\n\
caatVYtNagatttgattgaYttttYgacttVtcKaRagaaaHVgDtaMatKYagagttN\n\
atWttaccNtYtcDWgSatgaRgtMatgKtcgacaagWtacttaagtcgKtgatccttNc\n\
ttatagMatHVggtagcgHctatagccctYttggtaattKNaacgaaYatatVctaataM\n\
aaaYtgVtcKaYtaataacagaatHcacVagatYWHttagaaSMaatWtYtgtaaagNaa\n\
acaVgaWtcacNWgataNttcaSagctMDaRttgNactaccgataMaaatgtttattDtc\n\
aagacgctDHYYatggttcaagccNctccttcMctttagacBtaaWtaWVHggaaaaNat\n\
ttaDtDtgctaaHHtMtatNtMtagtcatttgcaaaRatacagRHtatDNtgtDgaatVg\n\
tVNtcaaatYBMaaaagcaKgtgatgatMgWWMaHttttMgMagatDtataaattaacca\n\
actMtacataaattgRataatacgBtKtaataattRgtatDagDtcRDacctatRcagag\n\
cSHatNtcaScNtttggacNtaaggaccgtgKNttgttNcttgaaRgYgRtNtcagttBc\n\
ttttcHtKtgcttYaaNgYagtaaatgaatggWaMattBHtatctatSgtcYtgcHtaat\n\
tHgaaMtHcagaaSatggtatgccaHBtYtcNattWtgtNgctttaggtttgtWatNtgH\n\
tgcDttactttttttgcNtactKtWRaVcttcatagtgSNKaNccgaataaBttataata\n\
YtSagctttaaatSttggctaaKSaatRccgWHgagDttaaatcatgagMtcgagtVtaD\n\
ggaBtatttgDacataaacgtagYRagBWtgDStKDgatgaagttcattatttaKWcata\n\
aatWRgatataRgttRacaaNKttNtKagaaYaStaactScattattaacgatttaaatg\n\
DtaattagatHgaYataaactatggggatVHtgccgtNgatNYcaStRtagaccacWcaM\n\
tatRagHgVactYtWHtcttcatgatWgagaKggagtatgaWtDtVtNaNtcgYYgtaaa\n\
ctttaDtBactagtaDctatagtaatatttatatataacgHaaaRagKattSagttYtSt\n\
>THREE Homo sapiens frequency\n\
agagagacgatgaaaattaatcgtcaatacgctggcgaacactgagggggacccaatgct\n\
cttctcggtctaaaaaggaatgtgtcagaaattggtcagttcaaaagtagaccggatctt\n\
tgcggagaacaattcacggaacgtagcgttgggaaatatcctttctaccacacatcggat\n\
tttcgccctctcccattatttattgtgttctcacatagaattattgtttagacatccctc\n\
gttgtatggagagttgcccgagcgtaaaggcataatccatataccgccgggtgagtgacc\n\
tgaaattgtttttagttgggatttcgctatggattagcttacacgaagagattctaatgg\n\
tactataggataattataatgctgcgtggcgcagtacaccgttacaaacgtcgttcgcat\n\
atgtggctaacacggtgaaaatacctacatcgtatttgcaatttcggtcgtttcatagag\n\
cgcattgaattactcaaaaattatatatgttgattatttgattagactgcgtggaaagaa\n\
ggggtactcaagccatttgtaaaagctgcatctcgcttaagtttgagagcttacattagt\n\
ctatttcagtcttctaggaaatgtctgtgtgagtggttgtcgtccataggtcactggcat\n\
atgcgattcatgacatgctaaactaagaaagtagattactattaccggcatgcctaatgc\n\
gattgcactgctatgaaggtgcggacgtcgcgcccatgtagccctgataataccaatact\n\
tacatttggtcagcaattctgacattatacctagcacccataaatttactcagacttgag\n\
gacaggctcttggagtcgatcttctgtttgtatgcatgtgatcatatagatgaataagcg\n\
atgcgactagttagggcatagtatagatctgtgtatacagttcagctgaacgtccgcgag\n\
tggaagtacagctgagatctatcctaaaatgcaaccatatcgttcacacatgatatgaac\n\
ccagggggaaacattgagttcagttaaattggcagcgaatcccccaagaagaaggcggag\n\
tgacgttgaacgggcttatggtttttcagtacttcctccgtataagttgagcgaaatgta\n\
aacagaataatcgttgtgttaacaacattaaaatcgcggaatatgatgagaatacacagt\n\
gtgagcatttcacttgtaaaatatctttggtagaacttactttgctttaaatatgttaaa\n\
ccgatctaataatctacaaaacggtagattttgcctagcacattgcgtccttctctattc\n\
agatagaggcaatactcagaaggttttatccaaagcactgtgttgactaacctaagtttt\n\
agtctaataatcatgattgattataggtgccgtggactacatgactcgtccacaaataat\n\
acttagcagatcagcaattggccaagcacccgacttttatttaatggttgtgcaatagtc\n\
cagattcgtattcgggactctttcaaataatagtttcctggcatctaagtaagaaaagct\n\
cataaggaagcgatattatgacacgctcttccgccgctgttttgaaacttgagtattgct\n\
cgtccgaaattgagggtcacttcaaaatttactgagaagacgaagatcgactaaagttaa\n\
aatgctagtccacagttggtcaagttgaattcatccacgagttatatagctattttaatt\n\
tatagtcgagtgtacaaaaaacatccacaataagatttatcttagaataacaacccccgt\n\
atcatcgaaatcctccgttatggcctgactcctcgagcttatagcatttgtgctggcgct\n\
cttgccaggaacttgctcgcgaggtggtgacgagtgagatgatcagtttcattatgatga\n\
tacgattttatcgcgactagttaatcatcatagcaagtaaaatttgaattatgtcattat\n\
catgctccattaacaggttatttaattgatactgacgaaattttttcacaatgggttttc\n\
tagaatttaatatcagtaattgaagccttcataggggtcctactagtatcctacacgacg\n\
caggtccgcagtatcctggagggacgtgttactgattaaaagggtcaaaggaatgaaggc\n\
tcacaatgttacctgcttcaccatagtgagccgatgagttttacattagtactaaatccc\n\
aaatcatactttacgatgaggcttgctagcgctaaagagaatacatacaccaccacatag\n\
aattgttagcgatgatatcaaatagactcctggaagtgtcagggggaaactgttcaatat\n\
ttcgtccacaggactgaccaggcatggaaaagactgacgttggaaactataccatctcac\n\
gcccgacgcttcactaattgatgatccaaaaaatatagcccggattcctgattagcaaag\n\
ggttcacagagaaagatattatcgacgtatatcccaaaaaacagacgtaatgtgcatctt\n\
cgaatcgggatgaatacttgtatcataaaaatgtgacctctagtatacaggttaatgtta\n\
gtgatacacaatactcgtgggccatgggttctcaaataaaatgtaatattgcgtcgatca\n\
ctcacccacgtatttggtctaattatgttttatttagtgacaatccaatagataaccggt\n\
cctattaagggctatatttttagcgaccacgcgtttaaacaaaggattgtatgtagatgg\n\
taccagtttaattgccagtgggcaatcctaagcaaaatgagattctatcctaaagtttgg\n\
gcttgatataagatttcggatgtatgggttttataatcgttggagagctcaatcatgagc\n\
taatacatggatttcgctacctcaccgagagaccttgcatgaagaattctaaccaaaagt\n\
ttaataggccggattggattgagttaattaagaccttgttcagtcatagtaaaaaccctt\n\
aaattttaccgattgacaaagtgagcagtcgcaataccctatgcgaaacgcctcgatagt\n\
gactaggtatacaaggtttttgagttcctttgaaatagttaactaatttaaaattaatta\n\
acgacatggaaatcacagaacctaatgctttgtaggagttatttatgctgtttactgcct\n\
ctacaaccctaataaagcagtcctaagaatgaaacgcatcttttagttcagaaagtggta\n\
tccagggtggtcaatttaataaattcaacatcgggtctcaggatattcggtcatataatt\n\
tattaagggctcttcgagtcttactctgagtgaaattggaaacagtcatccttttcgttg\n\
tgaggcatcttacaccgctatcgatatacaatgcattccaccgcggtgtcccgtacacaa\n\
ggaaacttgttaccttggggatataagaaaactcacacgtctcattattaaactgagtac\n\
aatttttgcacgagaaagtaatgcaatacaatatgatgaaagccagctaatgaaaaggga\n\
tggaacgcacctcggatctgttgcactggattaaaatccgattatttttaaaaatattca\n\
gtgctagagcatatcaggtctacttttttatctggtatgtaaagcccacggagcgatagt\n\
gagatccttacgactcaacgaaaagttataacataactcccgttagccaaagcccaatcc\n\
cgattactgccctaccctaacgtctgccatctaaatatcgaacttgttatgatcaatgtg\n\
actacctcccaccctttccccttcatttgttccactggggataagctagcgttttcagaa\n\
tcaatgcaataagaatagccaattgtctcacttcatcagagctcttggcaattccaggcg\n\
ctacgtggttctggaatatattcatttttcaaatagtaatacgtttagtgttgctattgt\n\
ctacacgtttggatattacgttatgtgagcggacatcaatagttgtctaactctttagta\n\
agccagagatagcactcttagcgaatggataccatcttccataagtttagttaatagtcc\n\
gaaacaactgcttcgagcatatttgaacctccttgtaggcaaatagcctcttcaaagcaa\n\
tcttactaatagatagagtttgttttaagggactactagaaatgggacaatcttaatagt\n\
atgacctaaactgacatttaaagatatatccaggtggcaagcataaagatcattgcgcca\n\
cctccaccgtgggattacttatcagtcgatatcctatatgctaagtttgcgacggcagaa\n\
tacaaactaagctgagttgatgctaaccttacctatgataccccattggaccggttaaca\n\
gccctacttattccaaataaaagaacttttatgctgtagaagctattatagtgatgcctg\n\
gtaacttcagtatattaaaatgacacacatacgccatatagagctcctggaactttgaat\n\
aatgagcgaacttcgaagttgaagagcaagaaaccatatgtcacggttgcctaaagcccg\n\
gtaaccagacatgtgctatcattgatcattatcgaggttttcataaccttgacccattat\n\
cggctgtgcgcggacaagtacttaaatcactagtttcttcacctgcttatcggtaagaaa\n\
taaggttggcaaagaatcgcataagacggacgtagagccgcagcgttgtgcgagtccagg\n\
tgcatgcgcagcaataggattttaaattttgttccatttttaatttagccgtaaggatgt\n\
ccgtaaatgattgaaaattggattcaatctttgggcctatgctactggaacctgatcgac\n\
aaaatttcaaacatacgttaactccgaaagaccgtatttttgcggctagaatagtcagtc\n\
gcttggagccatataccttaccacttaaacgacgtgctcctgtagttgaaatataaacag\n\
aacacaaagactaccgatcatatcaactgaagatctttgtaactttgaggcgaagcaccc\n\
tcttcgagacaactaagagtaaagtaccgggcgccgcaaggagtcgattgggaccctaaa\n\
tcttgacgaattgctaagaggctcagagctaccactgtaatttctctagagcccataata\n\
aatgaacgatacatccgtaggtagcacctaagggattataatggaagccaaatgcagtta\n\
ataatattatatactggcgtacacgattcgacggatctctcacatagtgattcacgaccc\n\
ccccctttgattgacacagcgtcagcattttgcaagaacgatcttctgcatagggtgcgc\n\
caccgtaaggatgacgtcgaagctacaactgggtataatttaccatgcttccctgatgct\n\
gagtgcaatacactaagaatgagtttttaccccatatcaccagtatttgttctgttattg\n\
cgaagaaatggctatgctgagttggcgactaaagtcacccatcctttttattaggtaacc\n\
ccctcccttaaactaactgatttgctggagctgccctgcatacatatactttatcattta\n\
tggacgtccgtgacgcttattatccaccatagtcgatatgctacacggattcattaatgg\n\
atcgtaggagtttaagttatatttactaagatcggtctcggctactatcccgccttaccc\n\
ggcgctatttacggccatttttaatatattgacggtaattattcctatggtttcgaccgc\n\
acgtccttggacaagaaagaatggcaaaaaaaatgtaaaagaaaaaaaatattgagtccc\n\
taccatcatataaaaaatatgtgatgagtaacttgacgaaatgttagtggttattaaaga\n\
ctatctattacaccttttgttttctgtcgtagtatattaaagtctagaagccttacagga\n\
aaatcagggttatacagccgatactccgcagcatgaatcatcgaggaggtgtcctaccat\n\
cgcgccttgtaatcttgtctgtgtatactgtatttagaccttttatacaaagtaaatatc\n\
tcggctttatgtgattgggaggggcctactcaaacatgatgacttgacctaataatcact\n\
gtgcgggcgtcttatgactagctattccttgaaatccaccaccaaatggttaatatgtaa\n\
aaactttgacgatgaaacaaggtgaatgtgtagttactttgtgtaattagctgcgtcgag\n\
cattgcttgtaaaaccgtcaatcgcacacgttacttccataaaatttctacgaatacacc\n\
cttcttaaaaaaaacgtaggaattcacgagtttaacaaacgataactgtataaagtggaa\n\
gtccgaagaaagcagatgcccgaactactcgaagatgtttcgttttcttaaccatagggg\n\
cttcttaatggcccactacgcacattttgttcaagcccgagagggacatccccattacgg\n\
gagtattactaaaactgttccgtaatacgttcagcaagggatgaaaaaggccactgctca\n\
agttattgacgtgggagtattacatcggaagcctgaatcccacactatgatggtctgtac\n\
aggcctagggactgcgtctagacggtattaccggcttctaatcatacgatcgtgagtctt\n\
aacgggaagtaaggctcacacctaccccaaaccatttatctatgtaagtataaaattgtg\n\
cgtaagtgttcaaagtggacaataaagacgtggcaaaaacccccgcacataagccgcttt\n\
agatttcacaaataccaatgcggttaaaaacatccttgagtcgtacatacaccatactcg\n\
cgttaaacggatataacagaagataataaatccggatgtggagtcggtgtaactatagaa\n\
agccaagtgaaataatgcttaccagtcatttagctatacggctttcatttcatgtcaaga\n\
gggtggagtttgacctgtacagttgatatatcaccgatacttagaactcacctaaagcta\n\
aaattgctcgcagcgtgtaatccgcatattacaaacaatagatgggattcattatacata\n\
agacacgatgatctgctttttcaggttgcgagatgttgcctatcgtcaatcgagtcctgc\n\
cttacaccacttaaacaaaagtattgacagggaacctattttcgaggtattatatagtcc\n\
agcttgaatatcaatttgacagttaacctagtgaaaatcagtaagaggaaatacgccaca\n\
ttctccagtgaaattctacgggttatcgtctagtccaactatcaattataactcacgaga\n\
tataagtaaattctcgtacttggcctgatttttattatactttggatccttagtaaacag\n\
gaagggagaaaccttcaacgaaaaacactggattttgttttactctcaaagctcttatat\n\
gacggaaataccctgtcaagtcttaactttattactagactaatgaaatgggcttggggt\n\
ggccagaatcatagtacaatttagcggatacactattcggactttcctatcggctgtctg\n\
gttggataagtatggggactaataggctagacatacctatacttaaactatacaggcgtc\n\
atctatctctgcaactttggagttccctgatgttctcccgccctttgggttcacatcttc\n\
tataccgacacccctaataacgattagtttgtgggttagagtaaattaatacggttaata\n\
ttaatgtatcgttgaaaagctggtgtcgccaataaggtaaccggctaggcagagtatatg\n\
tcacgaagtataactaccctaatgataagctgtaggaataaaattaatgctgtctctaag\n\
cgaagagatatttccgactctgttttaatgacgaatctcattacttctgacttgcaaatg\n\
ttcaatatggcacggtttcacggcacctttgtgacgcatataatgaacttagaagattat\n\
aacgacggaactttatatgataatccgttacgattaaagaatctgttaaatatcataatg\n\
gcattcagttctagaccgtgcatcatggtaaacttactttctctgcatggcgacatacat\n\
ttcgctattcaaattcgcgtgtggttacacccactcgcacctttggaatattaagagaag\n\
atgatcagaaaatccattcgctcaatttttctgacgtacgtctaatttatcctaggagac\n\
aaatcgttttatgtctctcacatttttgaagaaaggttcgagagacaatactcaggtcct\n\
gaactgctagaagatactcggtggagcgtggcaacaatgaaaaactcgtgacataaatga\n\
atgatacttttccaagttcagttaagtgaatatgtttaacatacccggcttttcgatctt\n\
aagctgacgctggacgtgcgagtaatgtcagtctcttacatacactagtgactccaagtt\n\
tcgtcaaaaacgccccctcccttctcgagcccactcacgctatgtattgacgcgaacttg\n\
ttcgggatcagacttttcaggagttcggtcgcgtgtccctatgtgctaatatataagtta\n\
gatcgcattagatgctaatctgaatacttatagacgaccttcaacgagaacgggtaccac\n\
cttgaggctagagttaggtgtgaaacgacaggtagggacatataaaatttgagtgcggct\n\
ttagttaagggtttaattacctactcaaacatcacgctcgcgcccttcgtacgtaatcga\n\
ccatctagaggctaaggggactgtactaggtagtgattaatgatatcctagacgcacgtg\n\
ccttagatcttcagactctgatggtccgcgatcaccgtaattgtagtcctccaactcgat\n\
cactttgttggcgtcaaagaaattacgatatctaaatacttataatacaataaccaagga\n\
tgagaatgactcatcgcgttggagttatattgcttgaagttctatggaatgaaagcacgt\n\
tatctgccgtcccaatatctccagtgagctaattcattggacggtccactttgatcaatc\n\
cccgaggagatgttcggacactttagtctgtaacacttagcgttgagaccacgaacaatt\n\
gattactcagtcttgaaggtgttttccaaagttcattttaaataagactacgataggcct\n\
ttcctattgatataaactacccggctctgttgttcgtgtgagtcgtacttctctgtgttt\n\
ttctgattatagcaagattcgattcttagtgtaaacagcgatttttatttgacccgtcaa\n\
tgagaagcgcataggatctaagcaaaattatcaagttgtgccacaaggtaagatctttcc\n\
agttattgcaggtaggatgtatcccacgttgatagtatgaggtctgacgtcaactgtcta\n\
ggagagttgaccgcgtgcgggtacaccggatttgcatcgatgttgagaacgcagaactcc\n\
cactgtcgtggcggcgttcctgatatttagcaagaggcgttgataaagccctcatcatct\n\
agatctcgacctcatctgccctcttgctccatcattttctacacagactactttcctatc\n\
tacgttagtataattgctttctatcttagtatcatttagagcttctccgtcaacaggttc\n\
gtgctattaaagttagtacgaaagggacaacttgtagcaacgcatttaatcggttttcga\n\
ctacttcgcacaaaatcagataaagaagtttgtcattctattagacattgaattgcgcaa\n\
ttgacttgtaccacttatgatcgaacactgaatcaagactgtgattaactaaaatagaca\n\
agccactatatcaactaataaaaacgcccctggtggtcgaacatagttgactacaggata\n\
attaattggactggagccattacattctctacaatcgtatcacttcccaagtagacaact\n\
ttgaccttgtagtttcatgtacaaaaaaatgctttcgcaggagcacattggtagttcaat\n\
agtttcatgggaacctcttgagccgtcttctgtgggtgtgttcggatagtaggtactgat\n\
aaagtcgtgtcgctttcgatgagagggaattcaccggaaaacaccttggttaacaggata\n\
gtctatgtaaacttcgagacatgtttaagagttaccagcttaatccacggtgctctacta\n\
gtatcatcagctgtcttgcctcgcctagaaatatgcattctatcgttatcctatcaacgg\n\
ttgccgtactgagcagccttattgtggaagagtaatatataaatgtagtcttgtctttac\n\
gaagcagacgtaagtaataatgacttggaataccaaaactaaacatagtggattatcata\n\
ctcaagaactctccagataaataacagtttttacgatacgtcaccaatgagcttaaagat\n\
taggatcctcaaaactgatacaaacgctaattcatttgttattggatccagtatcagtta\n\
aactgaatggagtgaagattgtagaatgttgttctggcctcgcatggggtctaggtgata\n\
tacaatttctcatacttacacggtagtggaaatctgattctagcttcgtagctgactata\n\
ctcaaggaaccactgctcaaggtaggagactagttccgaccctacagtcaaagtggccga\n\
agcttaaactatagactagttgttaaatgctgatttcaagatatcatctatatacagttt\n\
ggacaattatgtgtgcgaaactaaaattcatgctattcagatggatttcacttatgcctt\n\
agaaacagatattgcccgagctcaatcaacagttttagccggaaacaatcgaagcatagg\n\
gacaatgtatcttttcctaaattgccatgtgcagatttctgagtgtcacgaagcgcataa\n\
tagaatcttgtgttgcctcaactcgttgaaaagtttaaaacaatcgcagcagtctttttg\n\
gggtctactgtgtgtttgcaaaataactgaaagaaacgcttgaacaactctgaagtagct\n\
cgagtactcattaaagtgtaacacattagtgaatatcggccaatgaaccaaacgcttccc\n\
ggtacgctatctctctcatcgggaggcgatgtgcaggttatctacgaaagcatcccttta\n\
cgttgagagtgtcgatgcatgaacctcattgtaacaatagcccagcaaattctcatacgt\n\
gcctcagggtccgggcgtactcctccatggaagggcgcgcatctagtgttataccaactc\n\
gctttttaactactatgctgtagttctacaggcatagtggccagtattttctaacttctc\n\
tggatagatgctctcactcctcatccatcacggcttcagtttacgtcttacttgcttgtt\n\
cagcaacggatggaggcattaagtatcttcactgttccctaaaattgctgttcaatatca\n\
aagtaaggacgatacagggaaagctcaagcacactcattgaatactgccccagttgcaac\n\
ctcacttaatctgacaaaaataatgactactctaagtgttgcggaagcagtctcttccac\n\
gagcttgtctgtatcacttcgtataggcatgtaactcgatagacacgaacaccgagtgag\n\
aaactatattcttgcttccgtgtgtgtgacaccaggtaattgatgcggatataagctgga\n\
gatcactcacgcccacacaaggcgctgctacctctttattccaatgtgtaagaatttgct\n\
aacttcatttctagaccgcagctttgcggtcataatttcacggtacggacccttgggtta\n\
gagacttgataacacacttcgcagtttccaccgcgcacatgttttagtggcttctaacat\n\
agaatttttgttgtgacataaagagtgcgtgggagacttgcccgaccgttaagccataat\n\
caattgaaagccccgtgagtcacatctaattggttgtactgcgcatttagctatccttta\n\
gctgactcgaagagattcgattcctaatataggttaattagatggctgccgcgcgaagta\n\
aaacgtgaaaaacgtagtgcgcagatctgcataactcgcgcttaattacttatgagtagt\n\
tccaagttcgctacgttatgagagagattggaattaagcaaatatgttttatggtgattt\n\
tgggatgagaaggactgctaagtacggctactaaacaaatttctaaaaccgccatctacc\n\
ttatcttggagacatttaagttgtatatgtcactagtctagcttttgtctgtgggacgcg\n\
ttctcggaatgagggaaatgcaagagccgattcatcaaatgcttatctaagaaagtagtg\n\
gactattacaccaagcacgaatgccagggaactgctttcttgctcaggacctcgcgacaa\n\
ggtaccccgcataagtcctagaattacatttggtcagcaatgctgacatttgaccgtgaa\n\
aacataattttaatcagaaggcagctcacccgcttgctctagatcttatctttgtatgaa\n\
tgtcagaatttactgcaatatccgttccgaatagtgagggcttagtatagttctctgtat\n\
acaggtcacatcaaactccccctgtcctagtacagctctgagctttaattaattgcatac\n\
atttccttcaatcatcagatgaaaacaccgcgaatcatgctcttctcgtatagggcaaga\n\
gaagcaacaaacaactagcccgactcacgttcatccgccgtatccttgttcagttcttac\n\
tccgtattaggtcagcgaaatctaatcagaataatcggtcgcgtatcaaaattaaaatcc\n\
cgcttgaggttgacaattaaaacgctgagcagttatcggctattagatagtggggtgaaa\n\
gtaattggctggaattatgttaaaacgtgatattaagctaaaatacgctacttgttgccg\n\
acctaattcagtcattcgatattcagttagagccaagaataacaagcttgtataaattga\n\
acggggtgcactaaacgatgtgttactctaatattcagcttggagtatacctgaaggcga\n\
attcatgtatcggccaataataagacgttgaagatcacaatttggactagcaaaagaagg\n\
tgatttatgcgtggggattgagtccactgtacgagtacggtctctggaaaattataggtt\n\
cagggaatataaggaagtaaagataattaccaagagatttttggtatcgctatgacccag\n\
aggtgttctaacgtctgttttgatccgcagaatttctgcctcaatgcatatttgacggac\n\
ttgaactagagcctctaaagttaaatggcgacgcaactgttcctaaacttcaattattac\n\
tactctttttttcctagggtattgtagaggccagtggacaaaataaatcaaatttaagat\n\
gtttcggacattaacatcccccgtagcatagaaatcatcagttatccaatctctcatcga\n\
gcttttacaatttctgctggcgctatggacagcatatgccgcgagacctccgcaagactc\n\
acttgatcactgtaagtatcttcattagaggttagagcctatagttaagctgctgaccta\n\
gtaaaattggtattttctaattttattgctcaagttaaaggttagtgaagggataatgac\n\
gttatttttgaacaatgggttgtattcaattttatatcacgaatggaacccttcattccc\n\
ggcataatactagacgacacgaacaagctccgatctatcagccaggcacgtgttaaggtt\n\
taattccggcaaaccaatgaagcatcaaaaggtgacctgatgcaacttagggtcacgatg\n\
agtttttcaggactacttattacctattaataagttaacatgagccttcataccccgtaa\n\
gacaatacatactccaccaattagaattctgagccatcttatctttttgtatcatcgaag\n\
ggtatggccgaataggttaattagttactcctaacgtctctacaggcatgcatttgacgc\n\
accttcgaaaatagtcaatctctcgccacacgcgtctagtatgcagcatcaaaaatatag\n\
tccacggtttccggattaccaaacgcggcaaagagaaacattgtatcgacggagataact\n\
taatacagaaggaaggggcatcttcgaatacggatgaataattctatctgtttattctga\n\
catcttgttttcaggttaatcttacgcattcaaatgacgcctgccccatgcgtgcgcaat\n\
tattttctaatattgacgagagcaatctcactccttttgggtctatttatgttttattga\n\
ggcacaagcctatacagaacaggtactattaaggccgtgagtgtgagactcaaaccgtgg\n\
aaacaaaggatgggttgttcttggtacaagttttagtgcatgtgggcaatccttaccaaa\n\
atcagatgctatccttaactttgggctgcatttaagatggcggttggaggcctgtgagaa\n\
tcctgcgtgtcatctttaatgaccgaattcatccatgtagattcagatcacacactcatt\n\
ccttgatgttgtctaaacaaaagttgttgtggacgcattggagggagttaagtaacaact\n\
tgggatcgcatacttataaaaattatatgttaaactttcacaaacgctgaagtccaaagt\n\
aactagcccaaacgcctcgagagtcactaggtattaatggtgtttgagttcctgtgaaat\n\
agtgttcgaaggtaaaatttatgtaccaaatcgaaagaacacttaataaggcttgcttgc\n\
acggaggtatgatgtttactgactctacaaccctaattttccagtacgtacattcattcc\n\
aataggttagttctcaaagtgctatacaggctcctcaattgatgatatgcttcagccgct\n\
ctatggatattagctcattttatttaggaagcccgcttagaggcttactatgagggaaat\n\
gccaaaatgtcatacttttcggtgtgtcccatatgacaccgctttacatagaatttgaat\n\
taaaacgcgctctcccgttcactaccatacttggtaccgtgcgcatattacatatagata\n\
taggatcattttttaaagctgtactaggtttgatcgacaatcttatgctatactatatga\n\
tgtaaccctcataatcaataccgatcgtacgatcctagcataggtggcaagcgattttat\n\
gccgattattgtgttaaatagtctgtgagtgtgattatcagggctacgttggtagagggg\n\
ttgtatagacctcgcacacattgtgacatacttaacaatatacgaaaactgatataataa\n\
atccccttacccaaacaccaatcccgttgaatcaactaccataacgtctcccatataaat\n\
tgcctacttgtttgcataaatctgaatacataacaccattgcaccttcttgtgttccaat\n\
cccgttaagattgccttgtcagatgatatgcaagaacaatagcatttgctagcaattatt\n\
aacagctcttcgaattgcctccacataacgcgggagggtatattttaatttggcaaatac\n\
taagtactgttggcgtcatatgctattaacggttggatattaagttatgtcagccgtaag\n\
caagagtgggcgaaatattttgttacccagtgagagcactcttagagtttggatacaata\n\
ggccatatgttgacttaagaggacgtaactacgccgtacaccattgttcaaccgacttct\n\
tggcaaatagaatcgtattagcaatcttaagaatagagacacgttcgtgttagggtatac\n\
tacaaatccgaaaatcttaagaggatcacctaaactgaaatttatacatatttcaacgtg\n\
gatagatttaacataattcagccacctccaacctgggagtaattttcagtagatttacta\n\
gatgattagtggcccaacgcacttgactatataagatctggggatcctaacctgacctat\n\
gagacaaaattggaaacgttaacagcccttatgtgtacaaagaaaagtaagttgttgctg\n\
ttcaacagatgatagtcatgacgcgtaacttcactatagtaaattgaaacaaatacgcaa\n\
tttagacagaatggtacggtcatgaatgacagtaattcgaagtgctagaccaacttaaaa\n\
taggtaaacgtgcccgaaaccccccttaacagaaagctgctatcatggtgcagtatcgac\n\
gtgttcagaaacttgtaacttttgagcaggtccgagcacatggaagtatatcacgtgttt\n\
ctgaaccggcttatccctaagatatatccgtcgcaaactttcgatttagtcccacgtaga\n\
gcccaagcgttgtgcgactccacgtgcatgcccagaaatacgagtttaaatttggttaca\n\
tggttaattttgaccgaagcatcgcactttatgattgataattggattcaatatgtcgcc\n\
ctatgcgaatgcaacatgatccacaatttggctataagacgtttaatccgtatcacactt\n\
tgtttgcggctagtatagtaacgcccgtgcaccaagagtcagtaacaattataagtactc\n\
cgcaggtacttcaaatataaaaactaatcaaacacgacccatatgatcatctgaagatat\n\
ttggaactttctcgacaaccaccctcgtactcaatacttacactaatcgacaggcacacg\n\
caacgtgtacagtcgcaccatattgagtcaagatttgcttagtggcgatgagcgtacacg\n\
cttatttctctagtcacaattagttatctacgagacatcacgagggagcaaataagcgat\n\
gttatggctacacataggcacgtatgaatatgatataagccagttaaacagtcgaaccat\n\
cgagcaaattctcatgcaccaacccacacgttgaggcacaaagagtaagctgtttgaatg\n\
taacttcttctgctgagcgggccccaacgtaaggatcaactagaagagaaaactcggtat\n\
tagtttaaatgcgtcacggagcatgagtgcatttcactaagaatgtctgtgtaaccaata\n\
taacatctatttgttatctgattgcctacttatggctttgcggtcgtggcgactaatgtc\n\
tccaatccttttgaggtcggtaccaactccctttaaattacgctgtgcaggctcatgcac\n\
tgcatacatatacggtagcaggtagggacctcacgcacccttattataatcaatagtagt\n\
tatcagtcaacgaggcaggaatgctgaggtcgaggtgttggtatattttctatgtgccgt\n\
ctaggcgactatcacgcattaccaggcgagatttaagccaattttgaatatagtcaacgt\n\
aatttttactatgggttccaccgaaacgccttgcacaactaagaatcccataaaatatcg\n\
atatcaaataaaagattgtgtcaataccttcatatatattttttcggttgactaacgtga\n\
actaaggttaggggttttgtatgtctatataggaaacagtttcttttctgtcctacttta\n\
gtaaagtcttcaagccttactccaaaatcacggtgattaagccgttactcagcagcatga\n\
ttctgcctgctcgggtcctaaaatccagccttgtaagagtcgctgtgtattagctaggga\n\
gacctttgttaaaaaggatatatcgcggcgggatgtgagtgcgtggcgcatactcaatct\n\
tcagctcgtgtcattataatatctctcccccacgcttttcactagatatgccgtgtaagc\n\
aaacaccttatgcttaatttcgaaaatattggtacttgaaaaaagctgtaggggtactta\n\
atgtctggtaggagatcaggagagaattgagtgtaaaaccgtaaagccctcacctgactt\n\
catgtaaatggcttagaagactccatgatttaataaatactacgaaggaaagactggatc\n\
taaagataactctagtaaggccaactcccttcaatgctgttgccagttataatccaagag\n\
ctgtccttttctgaaccatagcggcttctgaagcgaactagaagcaaagttggttctagc\n\
cagacagccacataccctgtacgggtgtattactaaaactggtccggtattagttcacca\n\
agggaggaattaggcaaaggatctaggtatgcaagtcggagtattacatccctaccctga\n\
atccatcaataggttcctctgtactggccttcgcaatgagtattcaaggttgtacagccg\n\
tataataataagatagtgactatgaacgggaagtaacccgctcaccttccccaaaacatt\n\
gttatatctaagtattaaagtctgccgtagtgttaatactcgaaaataaacaactggcaa\n\
attacaccgcacttaagccgcttttgatttatatttttccaatgcgcttttaaaaataat\n\
tcagtcctacatactaattaagacccttaaacggagatatcacaagttaagttttaacca\n\
tctcgactaggtggaactatagatacccaactcaatttatcattacctgtaatgttccta\n\
gaaggattgcatttcatgtcaagacggtggagtttcacagcgaaacttcagtgtgaacag\n\
attctgagaaatcacctaaacctattagtcagagcacccggttagaaccagttgtcaaaa\n\
aatagagcggttgcatgagacagaagtaacgatgagatccgttgtaacgttgagacatct\n\
ggcctatcgtcaatacagtcctcccttaaaaatatttttaaatactaggcaaacccaaca\n\
taggttagtcctatgtgatacgccacatggtatatcattttgtaacgttacctagggata\n\
atcaggaagtggaattacgcaaaagtagacagtgaaatgcttagggttatagtctagtcc\n\
aaagataaaggataaagcacgtcagagaactatattagccgaatgggaatcattgttagg\n\
agactgtggatcatgtctaaaaagcaacgcagaaacagtcatcgaaaaaatctcgttttt\n\
gtttgaatctaaaagagctttgatgaccgatagtacctgtatactagttactgtattacg\n\
tgtctaatgatttcggattggggtccccagaatcagacgtcattgtagacgattcaagtt\n\
taccaatttaatttcccagctctccttggagaactatcgccaataattgcagtcactttc\n\
cttttctgaaacgataaagccgtcagagttctctgcaacgttggacttacctgaggttct\n\
aacccactttcggttctaatagtagttaacgacacaacgaataacctttactgtggggct\n\
ttcacgatattttttcgcttattattaatggttacgtcataagctggtgtccaaattaag\n\
gttaccggcttcgcagagtagttgtatccaagtataacttccctaatcataagatcgagg\n\
tagaaaattaatgctgtctctaaccgaacagatatgtcccactatgtggtatggacgttg\n\
ctaattacttctgaagggaaattggtcattatggatacgtgtctaccatcaggtcggacg\n\
cagatatggttctgtcttcagttgatccaccgttctttataggataataactgacgatta\n\
aagattatggtaaatagattaagccaattctcttcttgtcagtgaagcatccttaactga\n\
cttgctctgcagcccctcatacatttagctattcaaagtaccggctcgtttcaaactctc\n\
ccacctttggaagaggttgtcaacttgataagtatatcatttacagcattttttcggacg\n\
tacctctaatgtttcattgcagaaaattagttttttctatcgcacattttgcaagtaacg\n\
ttagagacacaattatctgcgaatgaactgctagatctgacgaccgggagcctcgcaaat\n\
atcaaaaaagactgacatatatcaaggagtcgttgacaagtgctggtaagtcaattggtt\n\
tatctgtcccggcgtttcgatcttaagctgaccatgcacggcagagtaatgtcactctcg\n\
ttcttacaagtctgtctccaagggtcggcaaaaaagacccctccattctcgagcccactc\n\
acgatatgtagggacgacaacttgtgcggcttatgaattgtctggactgcgggcgagggt\n\
ccatatctccgaagttagaagggacatacctttagatgataagatcaattcttattgacg\n\
aaattcatccacaacggggaacaacttcaccctagacttacgtctgaaaagacacctagc\n\
gtcttataaaaggtcagtgccccgtttcgtaaggctggaattacctacgcaaacttaaac\n\
ctcgcgcccttccttacgtatcgacaagatagaggctatcgcgaatgtactacggaggca\n\
tgaatcatatactagaaccaagtgcctgtgatattaacaagatgatccgacgcgagcacc\n\
gtaattctaggcataaaactccagcaatttgggggccgaaaacaaatgacgttagctaat\n\
taattatatgacatgatcaaaggaggtcaatcacgcatcgagttcgacgtatattcattg\n\
aacttcgtgcgtttgaaagaaacttttatgaaggcaaaattgatcctgtctcctatttca\n\
tgcgtacctcctagttgataattccccgagcagtggttaggacacttttgtcggtatcaa\n\
gttccggtctcaaaacgtaaaattctgtaatctgtatggatggtctgtgaattagttaat\n\
ttttatgaagtcgtcgagacgcagttcctattgatttattctaaacggagatgtgcttcg\n\
tgggactcggaagtagatctgtgtttatgattattgctactttagatgctgactgttaac\n\
tccgtgttgtttttcaaccgtatatcacaaccgaattggatagaacctatagtttcaagt\n\
tctgccacaaggtatcatatttacagttagtgctggttgcttctttcaaacgtggtgagt\n\
ttgtgctatcacgtcaacggtagagctcagtggaccgagtgcgcgttcaaccctgttcca\n\
gagagggtgtgatagcacatataccacgctcgtcgaggcgttcatgatagtttgcaagag\n\
ccggtgttaaacacatattattattgttatccaactaatcggacctatgcataaagcatt\n\
gtctaaacagaataattgcctatatacggtagttttagtgatttatatcttagtatcagt\n\
tagagcttcgaactcttcaggttcctcatatttaacgttcttcgaaagcgaaaacttcta\n\
caaacgaatgtaagcggttttccaagtagtacctataaatcacagaaagatctgtctcag\n\
tatagttgaaatggtattcagctagtgacgtgtaccaattatcatagttcactcaagcaa\n\
gacgctcattaacgaatatagacaagacactatatcatataataaaaaagaacatggtgc\n\
tcgaacatagttgaattcaccatattgaaggggaatgctgacatgtaattcgctactaga\n\
cgatcaattccctacttgtcaaagttgaactggtacgttcttggaattaaatatgattgc\n\
gctggaccaaattgcgacttcttgagtttcagggcaaacgattgagccggaggatgtccg\n\
tctcttacctttcttgcttatgataaacgacggtccctgtacatcactgggaattctcag\n\
caaaaataattgggtaaatcgagactcgatgtattcggccacaaaggtgttagacgttaa\n\
agattattcaacggggcgataataggatcataaccggtatgcaagcgcattgaaagagcc\n\
atgagatccttatccgataaacgctgcacggtatgtgcagccttattgtcgatcacgaat\n\
ttataaatgtagtctgggctgtaagttgaagacctaagttataatgaagtgcaataccaa\n\
atcgattcatagtggattatcagactcaagatatctcctgataaattacagttgttaaga\n\
tacggataaaatgagatttaagattagcagcctctaatctgtttcaatcccgttggaatg\n\
tggtatgcgatcaaggttaagttaaaatcaagcctgtcttcagtcttgattcttgttctg\n\
ccatcgcatgcggtctacgtgagttaatatgtagcttacgttctagcttgtgctaatctg\n\
agtatagattcgtagaggaatattatcaagcttccacgcctcaacgtacgtgtattggtc\n\
acacaagacactaaaagtggaagtagcgtaaactatagtctagttgttaaatgctcagtt\n\
cttgttatattcgatatactcttggctaatttatgtctgagtatataaaattaatgatat\n\
taacttgcatttcacggatcccttagaaaaagattttgaccgagcgcattataaacggtt\n\
acaccgaatcaatagaagcatacccaatagctttctttgaatttattgcctgcgcaactt\n\
ggctgactctctagatccgaataattctatatggtcgtgacgaaactagttcattactgt\n\
ttaaaatgccaacatgtcttttgggccgataatggctctttgcaaaattactcaatgata\n\
cgattgatcaaagcggtagttgctagtggtagcatgtaagtctatcaaatgtctgattat\n\
ccgaaaatcttccaaaagagtccacgtaccatatctatctcatagcgacgcgaggggaac\n\
cttatctaactatcattccatttaccgggtgactctcgatgcaggatccgattgggataa\n\
attgcccagaaatggctcattcctgactaagggtaaggccgttctcagcaagggaacccc\n\
gcgaatctaggcttataccatctagattgttaactacttgcctgtagttctacagccata\n\
ctggacagttgtttctaaatgatcgggattcatgctagcactcctctgaatgcaccgcgt\n\
aagtttaactattacgtccgtgggcagataaggatggaggctgtatgtatcttaactgtt\n\
acctaatatggctggtaattatcaaagtaaggaccttaatgccatagcgctagcaatcgc\n\
tttgtatactgaccatgtgccaacctctcttaatctgtaaaatataatgtcttagctaac\n\
tgtggacgatcatgtctctgcctagagcttcgctgtatcaattcctatagccagcgtact\n\
agtgacacaacaacaccgtgtgagaaaagatattagtccttacgtctgtctctctacagc\n\
ttattgatgaggattgaacatggacatatagctccccctcaaaagcagatgctacctctt\n\
tattccattctcgaacatttgccgaacttaatttcgacaaacctgaggtcacgtcttaat\n\
ttatcggtaacgtcacgtccctttgagactggataaatatattaccaggggccaacgagc\n\
aattgttggaggcgcttctataatacaaggtgtcttgtcaaagaaagacggcgtgcgtct\n\
cgtgcaactcacttaaccaatattaatgtgaaacccccctctctcacatcttatgcggtg\n\
tactgccctggtacatttcctgtacaggactccaacagtgtagattcctaagatagctgt\n\
tggagttgcctcacgccagatcgaaaaactgaataaactagtgagctgagctgcagaaat\n\
accgcttaattacttatgactagttcaaagggacctacgtgatgtcagacattgcaagga\n\
agaaattaggtttgtgcgtcattttggctggactagcactccttacttcccctactattc\n\
aaatgtcgtaaacagcatgagacaggatcgtgctgacatttaaggtctattgggaacgag\n\
gctacctttggtcgcgcgctcgcgttctccgaatgaccgaaatgcatgagcacagtatgc\n\
aattgcttatagatctaaggtctggtcgttgaaaccaagcacgtaggcctgggaaatcag\n\
ttcttcctcagcaactacacaaaagcgtccaagcattagtacttgtagtaaatgtccgaa\n\
cctatgcgctcatttgaaagtcaaaaaatatttttaagcagtaggcacctaacccgattc\n\
ctctacttagtagctttctttgattctcagaattgactgcaatatcactgcacaattctg\n\
tgccattactagacttctctgtattaacgtctcatcttactaacactcgcctaggacaca\n\
tctgagagtgaagtatttcaatacatttactgaaatcttcagttctaaaatccccgaata\n\
aggctcttatcggtttggccaacacaagaaaaaaacttcttgcaccactcaccttcatac\n\
gcaggagcctggggaacttagtaataactatttcggcagacaaagcttataacaagttgc\n\
cggcgcgtataatatttaaaagaccccttgagctgctcaattaaaacgctcacctggtat\n\
aggctattagatagtgccgtcttagtaaggggcgggaattatcggataaactgatatttt\n\
gataaaataaccgacttgttcacgacataagtcactaaggagattttatctttctccaaa\n\
gtatatcttccttggataatttcaaagcgctgcaatttaagttctgttactagtttatgc\n\
tgctgggaggtgaccggaaggcgtagtaatctagaggcaaattataagaagttcatcata\n\
tcattttcgactacaaaaacaaggtgttgtatgccggcgcattgtgtaaactggacgagt\n\
accctagatggaaaattatacgttaagccaagatttcgatgtaatgataattacctacac\n\
atttttgctatccataggaacaagagctgttctataggctcgtggcatacgaacatttgc\n\
tgccgctatgaatattggaagctcttcaactacagactctattcttaattgccgtcgaaa\n\
atgggccgaatcggctattattaatactcggtttttccgaggggattgttgtcgacagtc\n\
gtaattattattaatattgatgttggtgaggtcatttaaatacaaccttgcagacaatga\n\
ataagggatccaatctctcatactccttttacaattgctcatgcccctatgcaaacctta\n\
tgccgccacacctccgcaactctctcttctgaactgtaagtagcttcattactggtttga\n\
gactatactgaagctgatgacattctaaaatggctattttcgaatgtgattcataatgtt\n\
tatcgtttgggatggcagaatcacgttatttttgatatagcccgggtattctattgtata\n\
gaacgtatgctacaagtcattccccgaagaagactagaagtaaacaacatgcgaccatcg\n\
ttaagccacgcaaggctgtagctttatttcccgataacctatcttccataaatagcggac\n\
agcaggatactgacgctcaacatcagtggttatggtctaatttttaacttttaataaggt\n\
aacttcagcaggcatacacagtaactctttaatttataatcaaattagaagtctgacact\n\
tcttatatttttctatcatccaacgcgatcgcccattagcttattgtgttactaataacg\n\
tatctaaaccaatccttttcaagctactgcctatattgtcaatatatacaaacaacagga\n\
tagtaggctgcttaaaaaatattgtcaaccgtgtacgctttacaatacccggaaatcaca\n\
aactttgtagacaacgagtgaaatttatacactacgaagggccagcgtacaagacccatg\n\
aattaggcgatatgtttattctgacatattggtttatccttaatctgtcgctgtaaaatg\n\
aagccgcccccatccctgcgaattttttttcgaagattcacgactgaaatataaatacgt\n\
ttggctatatttatgttggagggaggcaatagcctttactgttaaccgaagatttagcca\n\
gtgagtgtgacactaaaacactggaataaatgcaggcgttcttctgggtaaaaggtttag\n\
tcaatctcgcctataagttcatatagctctggatataattatctggcccatgcatttatc\n\
atggcgcttggtgccctgtgtgaagccggcctctcatattgaaggtccgaagtattccat\n\
gtacattaagatcactctctcattcatgcatcttggcttaacaaatctggttgtccaagc\n\
tttccaggcacgtatggtacaaattcggatcgaatacttataaaaatgatatgttaaact\n\
gtctaaaacgctcatctacaaagtaaagtgcactaaccaatagagtctcaagaccgtgta\n\
atgctggtgcactgaatgtgtaatacggttagaagggattagttatgttacaaatccatt\n\
gaaaacttaagaagcattgcgtgctcggagggtgcatcttttatcaagagactaacatta\n\
ttttcaacgacgtacatgctttacaatagggtacttatcaaacgccgagaaacgcgccta\n\
tagtgatgttatgattatgacccgatatccattggaccgaattttatgtaggttcccagc\n\
gtactcgcgtaatatctcggtattgccataatgtaatacttgtcggtctctcccagatga\n\
aaaagcgttacagagtatttcaatgaaaaacagcgcgcaacgtcaatacctttaggggta\n\
acggccgctgatttcatatagatatacgataagttggtatagctctactaggtggcatcc\n\
acaatcgttgcatttactatagctggttacaatcataatctataccgttccttacatact\n\
accatagcgggatagcgtttttttgccgttgattgggtttaagaggatgtcagtctcatt\n\
atatccgattcggtgggagagccgttgttttcaaatcgcacactttgtgacataatgtac\n\
aagataacaaaactgatataagatataaactgtcaatatcaccttgacacttgaatcaaa\n\
gtaaattaactcgcaaatataatttgactaattgggtgcagatttctcaattaataaaaa\n\
aatggcaccggatgggcttacaagccccttatcattcacttgtatcatgatttccaagaa\n\
caatagaatttgctagcaagtatgaacagagattcgaattgcatccacagtacgccggag\n\
cgtttattttaatgtggatatgacgatgtactgttggcggcatttgctagtaaccggtcc\n\
ttatttacgtagcgcacacgtaagcatgtctgggagaaatatggtggtacaatctcagag\n\
aaagattacagtttggtttaaataggacttatcgggtcggaagtggaacttaataagcag\n\
tacacaattgggcaacagacgtcttgcctattacaataggattacaatgcgttagatttc\n\
agacacgttcgtgtttggctattcgtcaattccctaaatagttagacgatcaactattat\n\
caaagtgattctttgttcatcctccattcatgtaacagatggcacactacgcataacgcc\n\
gaggaattttaacgagatttaagagagcagttcgggcacaacccacttgactttataaca\n\
gctcggcagcataaacggtaatatgtgacaaatttccaaacgttataagaacgtatgtgt\n\
acttagaaaactaagtggttcatgttcaacagatgtgacgcagcaagcctaacttatcta\n\
ttggttttgctataaaagaacaaagttacacagaatcctaagggcttgtttcacacttat\n\
gcctagtgcttcaccatcttaaaatagcgaaaccggcacgaatcaaaccttaaaacaatg\n\
cgcagatattggtgatggtgactccgggtatgataatggtaactgttgaccagcgcccac\n\
ctcatcgaagtatagaaagtggttaggataaggatgagaccgaacttatttccggccata\n\
actttagattttctacctagtacacaacatcagggcggacacgaaaccgccatcacatca\n\
tataccaggtttaatttgcttaatgggggaagtgtcaacgaaccttcgaactttagcagg\n\
catatggccattatatatggccccagagcagaatgctacagcagacaaaatttggattta\n\
tgtagtttaatacctatcaaacttggtgtgaccatacttgtctaacgacagtgcacaaag\n\
tgtaagttacaattattactactcagcagcttctgcaatgataaaatcttatcatacacg\n\
tcacatatgataatatctacttagggggaacgggctccacaacctacatagtactcaata\n\
cttacactattcgacaggcacaccaaacctgtacagtcccaaaagattgagtcaactttg\n\
cagtactgcagatcacagtaatagcttagttagcgagtcaaaattagttttctacgagac\n\
tgcacgaccgtgcaaatttccgatgtgttggctacaaatagcaacgtatgaatttgtttg\n\
aagccacgtaaactgtacaaccttagagataagtctcaggctactaaaaacacgttgtgg\n\
cactaacaggatcatggttgattcttacttattcggctgaccggcccaataagtaacctt\n\
caactagaacagaataatcgggagtagtttaattcagtcaaggtgcaggtctcattgtaa\n\
ctaacaagctctgtgtaaccaagttaaaatcgttttcttagcggattccctacttatgga\n\
tttgagctcgtccacaatattcgatacaagaagtttgtggtccgtaacaacgaaatttta\n\
attacgctgtgcagcctcatccaaggaattaatagaaggttgatggtaggctccgaacgc\n\
tccatgattataatcaagtggactgtgcagtaaacgaggaaggtatcctgacgtcgtggt\n\
gttcgtttttgttatttgtgccctatacgagtagataaaccatgaacagcacagtgtgaa\n\
cccatggttgattttaggctaccttatttttaatttccgttacacagaaacgaattccac\n\
aactaacatgccattaatttttcgatatcttataaaagatggtcgaaattcattcattta\n\
ttttttttcggttctcgaaagtcaactaagctgtcgcgttttgtttctctttagaggtaa\n\
aagtggctttgatctcctacgtttggatactagtcaaccattactccatttgatccgtga\n\
gtatcacctgtctaacatccagcattatgactcctcggcgaagaaaagacacacttctta\n\
gagtcgatgtgtattagctagggacacagttgtttaatacgatagtgagcccagggaggg\n\
cagtgcgtcccccagtagatttattcagctagtgtaagtataagatatctcacccacgag\n\
gttcaagtgatatgcagtcttagaataatacttatcctgaatttcgatattatgggtact\n\
tcaataatccgctagcgctactttatgtctcgttggacagcaggacacatggcagtctta\n\
aacactaaagacatcacctgaatgaatgtaatgggattacaagaatcaatgaggtattat\n\
atacgacgtaggaaactctggatatatacagtaatctagttacgccatcgcacttcattc\n\
ctctggaaacttagaagacatcagctgtacgtggaggaaccagacccccgtatgtagcca\n\
aatagaaccaaagttgcttatacaaacacacccaatgacaatggaccgctggagttcgta\n\
aactcggaacgtagtactgcacaaacccagcatttagcaataggagctacgtatgcaact\n\
cccacgtggtaataccttcaagctatcaatatataggtgcctagctaatcgcattcgcaa\n\
gcagtattcaagcttgtaaaccagtataataattacagaggctctatgaaacccaacttt\n\
ccagctaaaagtcccaattaaatggttatttcgtacttttaaagtcgcccgttctgttat\n\
tacgcgaattgattctactccaaaattaaacacaaattatcaaccgtttcatttatattt\n\
gtcaatgcagctgtttaaaataaggctctactaaattataattaagacacttattaccag\n\
atttctctagttaagtttgaaccagctcgactaccgcgaaagatacattcccttctctat\n\
ttttcagttcatctatgggtcagagaagcattgaatttattctattcaccctcgtcgttc\n\
acagcgaatcgtcagtgtgatcagtgtatgagaaatatcctaaaccgtttagtcagacca\n\
cacgcttagaacaagtggtctaaaaagactgccctggaaggagtaagaagtatacagctg\n\
atccggtgtatccttcagtcatctgccctatactaattacacgacgcaaggaaaaatagg\n\
tttattttctaggcaaacccttcataggtgactccgatgtgttacgaatcatgcttgaga\n\
atgtgctatcgttaccgacggataataacgatctccaatgaaccaaatgtagaatgtcta\n\
ttgattacccttttactattcgacttagagataggagatagaacctcagtgtactttttt\n\
agccgaatgggaatctttgggaggtgaatggccataaggtcgtaaatccaaccctcttaa\n\
agtcttccatattatatcgttgttcgtggaatcgataacagatttgttgacccatagtaa\n\
atgtatactagtttatgttgtaagtgtagattgttttccgattgccgtccaaactttatg\n\
tcgtaattgtagaccagtaaagttgaccaaggtaagtgcccagcgatcctgcgagatcga\n\
tcgccaatttttccagtcactgtaagtgtaggtttagataaagccgtatgagttatatca\n\
taagggcctcggaaagcagcttcgaaccaaagttcccttataatagtagtttaactataa\n\
aagtatatactggtctgtcgccctttcacgatttgttttaccggtttatgaagcgttacg\n\
tcattagagcggctccaatttaaggttaacggcttccatgtgtagttgtatacaaggata\n\
acttaaagtatctgttcagcgagctagttaagttatcctcgatagaacacaactcagagg\n\
tcccaagatcgggtttgcaacttgctaatttattctcaaggcaaattgggaattatcgat\n\
acctgtataccataaggtcgctcgatgtgatgcttatgtcttctggtgatcctaccttag\n\
ttagtgctgattaacggaacattaatgtttatcgttttgagatttagccaattctctgat\n\
tctaactcaagatgccttatctgacgtgctatgcagcccctaagtattttacattgtaat\n\
aggacacgctcctttaaaactcgccaaaaggtcgttgtggttctctactggttaactata\n\
taatttacagctttgttgagctagttcctctttggtttaagtcctcaatattagttggtt\n\
cgagcgataagttggctagttaccttagtcactatattagatccgaatgttatgcttcat\n\
ctgaagaccgccaccctccaaaatttcttttaagactcacttattgcaaggtgtaggtga\n\
attcggctcgtttctcaagtggtgtatctgtacacgagtttccatattttcatcaacagc\n\
caccgcacacttatgtcactctaggtattaaaagtcgctctacaaggggacgcaattaag\n\
aaacagacatgctagtcaaaaataaacatagcgaggcaccactaattcggccgcttatca\n\
atgggatgctctgcgcgagacgcgccagagctcagtagttagttcggacatacatttact\n\
tcagatgatcaattagttttctacaaatgcttactctaccccgaaaaaagtcaccagact\n\
cttacgtctctttagtatccttccgtcttatataaggtcagtcccccgtttcggtaccct\n\
ggaatttactaagaataatgaaacagcccccaaggacgtacgtttacaaatgatagacca\n\
gatcgcctagcttattccgacgcatgttgcatagaattgaaccaacggaatgtgagagta\n\
actagatgagccgaccacagcacccgtttgcgtcgcagaatacgcctgatagttcggcca\n\
cgaaatcatatgtcctttgagtattaagtatttgtaatgatcaatcgagctcaagcaagc\n\
ttacacttcctcggatattcagggaacttagtgcctttgaaagatacgttgatcaacgaa\n\
aaattgataatggctcatatggaatgcctacctcatagtgctgaattaacacagcactgc\n\
ggacctaacttttcgaggtttcaagttcacgtctcaaaacctaataggctggaatatgta\n\
gggatcctcggtgaatttgtgattgggtttgttgtagtactgaccaagtgaatattcttt\n\
ttttctaaaagcagatctgctgccgggcactacgaaggagatctctgtgtatcattattg\n\
cttcttgacatgatgactcttaaatcactgtgggtgtgcaaaacgatagcacaacccaat\n\
tcgatagtacatattgttgatacttcgcactaaaccgttcatatttaaaggttgtgctcc\n\
ttccttcgttaaatactggtgacttggtcctatctactattagctagacctctggggaac\n\
cacgcccccgtaaaacctgtgcaagagagggggtcatacatcttagacatcgcgcctcca\n\
ccagggaagcattgggtgattgaccaggtgtgtaacaaatatgattattcttatactaat\n\
attagcaaagatgcataatgatttgtattaaatgtataattgaattgataagggtctttt\n\
agtcagtgatagagtagtataaggtagacattagaactcttaaccggacgcagatttttc\n\
ggtcttagtaagccaattagtcgacaaaacaaggtaagagcggttactagtagtacctat\n\
aatgcactgaatcttcggtcgaagtatagttctaatgctatgcagattgtgacggcgaca\n\
aatgttcagacttatatcatgaaacaagctcttgtaagtattgacaaatgaaaagattga\n\
atatttttaaatacaaaatgcgcctacttattaggggaattaaccagattgaaggccaat\n\
cctcacatgtaatgagataatagacgataaatgaaattcttgtaatagttgaactgctac\n\
gtgatgggtattatatatgattgagatcctccaattgccgacgtcttgtcttgatgccca\n\
aaagattgtcaacgaggagctccctcgcgtacctgtcgtccgtatcataaacgacgcgac\n\
atgtacagcactccgaagtataagcaataataatgcgggtaatccagactagatcttttc\n\
ggactcaatgcggtttcacggtaaacatgattaataccggagagtagtcgagcttatcag\n\
cgatgcaagcgaattcattgtgccaggagatacgttgcagataaaaccggcaacgtatgt\n\
caacaagttttggcgatctcgttgtttgtattcgacgaggcgcgggaacttcaagaacta\n\
tcgtatattcaagtccattaccttttagtttcagactggtggagctgactaaagttatat\n\
catcattttgtacactggtttagttaacgataatttcagatttaacatgaccagacgata\n\
atcgctgtatatccagttggaatgtggtttgccagaaaggttaacttataatcaagcctc\n\
tcttcagtcttgattcgtcgtatcccatccattgcgctatacctcagtgtatttggagct\n\
gtagttataccgtgtgctaagatcagtagacatgacgagagcaatattatctaccttaca\n\
agcatcaacggacgtctagtcggaacaaaagactctaaaactcgaacttcaggttaatat\n\
actatagttctgtattcagcagttattcttatattcgatattatcttgcctattggatgt\n\
ctgactttagtatattaatcatagtatctgccatgtaaaggtgccagtactaaatctgtt\n\
tcacagtgcgaattataaacggttacaaccattaaagacaacaagaccctatagctttat\n\
ttgaattttgtcaatgcgcaacttggagctcgcgatacatcccaattagtctatagggtc\n\
gggacgattctacggcatttctggttataatgacaacatggattgtggcccgagaatcgc\n\
tctttcattaattaagcaatcattacagtcttataagcgctacttccgagtggtagcagg\n\
taactcgatataaggtcgcatgagccgaatagcttaaaaaacaggccaccgaacattgat\n\
agagaataccgaccacagcgcaacctttgattactttcattaaattgtacggctcactcg\n\
acatcaagcttaagattgcgataatgtgaactcaaatggatcagtactgaagaaccgtaa\n\
cccacttcgcagaaagcgtacccagagaagatacgctgttacaatatacagggtgaaatt\n\
attgcctgttcttcgtaaccatttcgccaaacttggttagaaatgatagccattcatgat\n\
agaaataagctgaatgataccagtatctttaactatgtagtcagggggaagataacgatg\n\
gtccatgtatgtttctgatatgtgacagtattggccgcgtaatttgctaacgaagctact\n\
taatgcctttgagcttcatatagatttctttaatcaaaatcggcaaaaagatagtatgag\n\
ctataatatatgctagtagagaactctggaccatcatctatatgaatactgattcgagcg\n\
tgcaattactttagcctgcgtactactgactctacaaaacactctgagataagtttgtag\n\
tcagtaagtcgctctctataaaccttttggatgaccattgtacagccacttatagatccc\n\
aataaatagcacaggagacagagtttttcaatgctcgatcatttgccgatagtattttcg\n\
tctaacctcagggcacctattatttgatacctaacctaacggccctttcacaatggagaa\n\
atatatgacatcgggacaaacacaaatggtgggtggccaggagatatgacatggtggcgt\n\
ctctaagaaacacggactccctctaggcaaactcacgtaaccaattttaatgtcaaacaa\n\
aacgctcgaaaagattttgccgtgtaatgacctggtacattgactggtcaggaatacatc\n\
actgtagttgccgtagtgtcctgttggtgttccatcaagacacatcgtataacgcaattt\n\
acgacggacatcagatcaagttatacagattatttaagtatcacgtgtgcattgggacat\n\
aagggatctcacacatgccttggaacatttttgctttgtgccgctttttcgctgcactac\n\
caatccttacttaccagtatattcaaaggtcgttaacagaatgagaaaggttagggctct\n\
aagttatcgtcgattgggatagacgagacatttgcgagcgccctccacggatacgaatct\n\
cccatatcaatgtgaactggatgctatgcagtttagttcttacgtctcctagtggtaaaa\n\
atcaaagtagcactcgcatagcagttattcagaacctaatacacaaaaccgtcaaacatt\n\
ttctaattctaggtatgggccgatcataggagctaaggtgaaactcataaatgttttgtt\n\
agatctagcatcctaaaaagatgcatatactgagtagctggcgtgcattctctcaattgt\n\
atcctttttaactgaactagtcggtcccatttcgtgactgagatctattaaccgataaga\n\
ttaataacactcgcattcgtatcagctcagagtgaagtttttcaataatttgactgatat\n\
attaacttctaaaataaccctttaagcctcggatccgtttcccaatcacatcaaaaattc\n\
ttattccaactatctacggattaacaacgtgcatggggatcgtagtaagaacttgttccg\n\
atcactttgagtatatcaagttgacggcccggttattattgaatagaaacattcacctgc\n\
taaattaaataccgcacatcggatacccgatttcagagggccgtcttactaagggcaggc\n\
tttgttcggtttaactgagatgttcattattttacagtatgcttcaactaatatgtaacg\n\
aaggacagtggatctgtctccatagtagatcttcagtcgtgaatttcataccgctcctat\n\
ttaagttcgcgttcgagttgttgatcatggcacgtgaaagcaacccctagtattctagac\n\
gaaaattttttctagttcatctgataatttgccaattcaaaaacaaccgctggtttcccg\n\
gcgcattctctaaaatggaagtcgaacctagagccattatttgtcggtaacccatgagtt\n\
ccttcttttcagaagttaatacactgtggtcctatacagaggaaaaacagcggttatata\n\
cgatcgtggcataacaacattggatcaagatagcaatttggctacctattctaattctca\n\
ctagattcggtattccactacaatatcggcagattaggattggatgaataatcggtgttt\n\
aagtccggttgcgtctccaatctcctaatttttattaatattgatcttggtgacctattg\n\
taaataaaaacttcaagactttgaataacggtgaaaagatagaagactcatttgaaaatg\n\
gatcatccacagatccaaacattagcaagacactaatccccaactagctattctgatcgc\n\
gatcgtgctgcagtactcctgtcacaatagtctgttcatgatctaattctttttgggctt\n\
tgttcgatggtgattcagaatctttatccggtcgcttccctgtagctactttgtggggat\n\
attgcccggggattatagggttgagatcgtttcctaaaagtatttaaaccaagtagactt\n\
caactaaactacatcagaacatcgtgaagacaccatacgcggtacctttatttaccgata\n\
acatttcttcaagaaataccggtaagcagcataatgaccctaaacagctcggggtatcgt\n\
cgtagttttaaattttatttaggttactgctcaaggaataaaaactaactatttaattta\n\
taataatattacaaggctcacactgattagatttgtctataagacttcgcgatcccccat\n\
taccggattgtcttaagaataaactagataaaccatgcattttctagataaggcctttag\n\
tctaattagatacaaaaaacacgatagttgcatccttaatttattgtgtcaaacctggaa\n\
ccttttaattacccgcaaatcactttatgtcgagactacctctgaaatttattatctacc\n\
taccgcatgaggacttgaaccatcttgtaggagttatgtttattagctaagattcgttta\n\
tcctgtagcggtccatgtatattcaacaagcaaaaagcactcagaattgtttttagttga\n\
gtcaagactgatatataaataagtttccctagttttttcgtggtgggacgatattgaatt\n\
gaatcttaaccgaagagtttcccactctgtcgcacaataatacacgccaatatttccagc\n\
cctgcttatgccttaatcggttactcaatctcccattgaagttcattttgatctgcatag\n\
aagtttcgggcccagccttttttctgccaccttcctccaagctctgtagacgcactctaa\n\
gattgatgctcacatgtattaattctacattaacataaatatataagtcatgcatcttcg\n\
agtaaaatatctggttctccaacatgtcctggcacgtatcgttataatgcccatacatgt\n\
agtattaaaatgattgggttaactggatattaagatcatcgaaattgtaaagtcaaatta\n\
acaatactgtctcaagaccgtgtattcctcgtgctcggaagggctattacgcttacttcc\n\
gttttggtatcttaatatgactttcaaaaattaagttgcagtgagtcctacctgcgtgca\n\
tcggttagcaagagtataaaagttgtttaaacgaactacttgctttacaataccggtcgt\n\
atatatcgccgtgaatccagaagattgtcttctttggattatcaaccgagatcctgtgga\n\
ccgatgttttgggaccttcacagaggactccaggtagagctcgcttttgcattaatctaa\n\
gaattgtacctctctaaaagatctaaaacagtgaatgtgtatttcatggaaaaacacaga\n\
gaaacgtaaattactttaggccgaaaggcacatgagttattatacatatacgagatggtg\n\
gtatacatcgaattcggggcatacactatagttgcattgtatttagctgctttaaataat\n\
atgatattaccttccttacataagacattaccggcataccctggttttcaacttgtgggg\n\
ctttttgacgatcgcactctcatttgatccgagtagggcggtgacccctgcttttcaaat\n\
acaaaaatttcgctatgaaggtaatagattacttttcgctgttatgatagaaacggtaaa\n\
tttaaaattgaaacttctagaaaagtaaagtaacgagaaatgattttgtgaataatgcgg\n\
tcatgattgcgcaagtaagaaaaaaaggcaaaaggatgcgcggaatagaaacttatcagt\n\
cacgggtatcttgatttcattcttcttgtcaattgccgacataggatgaaatcagattcc\n\
aatgcaatacacagtaacccccacccttgattgtaatgtcgatttgaagttgtacgcgtc\n\
gacgaagtggatagtatacgggccttttgtacggtgcgatcaactatgaatctcggcgag\n\
ttagatggtcgtacaatctcacacatagaggtcacttgcctgtaatgacgaattttcggc\n\
taggtactcgaactttattagaagtaaaaatgtgggcaaaagaaggattccattttacaa\n\
gacgattacaatgagttacatgtctctcaacgtagtctttccctagtagtctttgaacta\n\
tttaggtactccagaaaattttagcaaagggtttctgtgtgaatccgccattcatgttta\n\
tgatggaacaataagaataacgccctcgtatgttatcgacagtgaagtcagcagttcggc\n\
caaaaacatattcaatttagtacagatccccagaagttaagctaagtgctctaaaatggc\n\
ctaaacggttatcaaagtaggtctaattactatactaacgggtgcatcgtaataactgct\n\
gtcgatgcaacactatatgatagtgtcgttttgctatatatgtacaatgtgacaaagaag\n\
ccttagcgattcttgcaaacttaggacttcggattctcaatcttaaatgtccgaaaacgc\n\
aaagattcaaaaatttaatctatgagcagatatgcctgatggtgactacgcgtatgttaa\n\
ggctaaatgttgacaaccgcacacataatcgaactattgatagtcgggagcataaccagg\n\
tgaacgtactttgttcacgacatttattgacatgttctaaatacgtctcaaaatcacggc\n\
gcactagaaaacgcaatcaaatcattgtcctggtttaagggccgtaatgccggtagtgtc\n\
aaacttcatgagaactttagctggcttttggccagtatttagggaccaagagcactagcc\n\
ttaagctgaatattttgccatttatctactgttataactttaaaacttggtggcaccaga\n\
cttgtcgatacacacgcatcaatctgtaacgtaaaaggtttactaagaacaagcgtagga\n\
attgagtttatattatatttaaactaaaagatgatattagcttctgagggcgatagggct\n\
ccaaatcataaagaggaatatattattacacgattagaaacccacaacatacctcgaatc\n\
gcccaaaagtttgacgaaacttggcagtactccacatctcagtaatacagttgggagagt\n\
ctcaaatgttgttttattactcaatgaaccaccctcataatttcactgctgttccattaa\n\
atttgcaaacgatcatttgctttgaagaaacgtaaaatcgacaaaattacagataagtag\n\
atgcataataaaaaaaactgctcgctataacacgatcatcgtgcattcttacttaggagc\n\
atcacccgcacaataacgtaccttaaactacaacactattagaccgagtactgtaattca\n\
cgaaagctcaagctcgcattgtaaagaacttgctctctcgtaaaatgtgataatagtttg\n\
cggagaggattcaattattttccattgcacctactccactagattcgataaaagaaggtg\n\
gtcctcccttaaaaagaaatgttaagtaacatcggaaccataagcaaagcatgtaagtga\n\
accgtcatccttccctaagaaacataaaggtttttaataatgtcgactgtgaactataac\n\
tgcatcctttcctgacctactccggttccttgttgttatttctgaacgagaccagtagat\n\
aaacaatgtaaaccacagtgggtaccaatggtgcatgtgacgctaccgttgttttaagtg\n\
cccgtacaaacataagaagtcataatcttacttgaaattaattttgccttttattttttt\n\
tcaggctcgaaattaatgatttgttttttttgaccttctagttacgctaatatgcggtcg\n\
cctgtggtttctattgagtcctataacgggatgggatctaatacgtttggttactagtaa\n\
acaaggtataaatttgataccggagtatcaactgtataacatcaagctttatgactcata\n\
cgcgaagtaatgacacaaggctttcaggagatcgcgagtacagagccactaaggggtgta\n\
ttacgatagtgacaccaccgagcgcactcactccccaagtagatttatgatcctacgcta\n\
agtattagatatataaccaaagaggttctagtcagtgcaactcttagaataataattagc\n\
cggttttgcctttttaggcctaatgcaatattcagctagcccttatgtatctcgcgttcc\n\
acagcaccactcatggcacgcgtttaaactaatcaaatataatctatgaatgttatgcca\n\
gtacttgaataaatcaggttttttataagtccttgcatactctcgttatatactgttaga\n\
gtcttaccccatagaaattctttcatctgcaaacttagaagaattctcagctacggggag\n\
cataaagtccccaggatgttgacaaatacaacaaatgtggcttatacaaacactccatat\n\
gaaaatcgaaccctcgtggtagttttagccgaaccttgtacggataaatccctccatttt\n\
ccaatagcagatacctatcctactacctcgtggtattaaattaaagcttgaaatatagag\n\
ctgcatagcttatccaattcccaagcacgagtctaccgtcgtaaccacgatttgatttac\n\
agacgctagagcaaacccatctttaaacatataagtaaaaattaaagggtgagtgcgtac\n\
gtgtttactagcaacttcgcttattaagacaattgtttataagccataattaaaaacata\n\
tgttcaacaggttcattgatatttgtaattgcacaggtttttaataaggatctacgtaag\n\
tataatgaacaaactttttaccagagttatattctgtactttgaaaatgctcctctaccg\n\
ccttagagactttcaattagattttttgcagttaatctatgcgtaagtgaaccatgcaag\n\
ggatgcgattcaaccgcctcgtgctaaccctatcgtctgtctcataactgtaggtctaat\n\
ataattttcagttttcgaacacataaccctttgaaaatctgctatttaatgtctcacctg\n\
catgcactatcttctatactgctcagaacggctatacgtcactatgctccaagtgacgat\n\
ttaaacgaagcaaggaataataggtttattttagtgcaaaacaattaagtgcggactacg\n\
tgctctttacaataagccttgtgattgggctataggttaagtcccatattaacgatctcc\n\
aatgtacaaaatcgacaatcgctttgcattacccggttactagtcgaattacagatagct\n\
gttagatactcactctaattttggacaacaatcccaatcttggggtcgtctatcgcctga\n\
agctcgtaaatccttccatcttaaacgattacatattatagacttgttcggggtagagat\n\
atcacagttgtgcaaacattgtaaatcgatactagtttatgttggtagtctagttgcttt\n\
taccattccccgaaaaacttgatctactatttcgacaacagtaaacttgaactaggtaag\n\
tgaaaacagagaatgcctcatagtgccactatttgtccactatatgtaagtgtagcttta\n\
cataatccactatgactgagatcattacggcctaggaaagcagcgtagaaaaaaagggcc\n\
cggatattacgactgtaactataaaactagttactggtagcgcgccatgtatagatttgt\n\
tttaccggttgtggttgcgttaacgaatttcagccgcgaaaattgatccgttaaccagtc\n\
catctcgacttctataaaacgataaagtaaagttgatgttcagcctccttcttatggttg\n\
catcgagagtacactactcagtgggaaatagatcggggttcctacttcagattgtattat\n\
ctaggcaattgccgattgtgccatacctggataaaataagctacctacatgtgatgctta\n\
tctattatcgtcatactaccttagggtgtcctgttgaacgctacattaatctttagccgt\n\
ttgagatgttccaatggataggagtctaacgcatgatgaagtttaggaaggcagagcatc\n\
ccactaagtatgtgacagtgtatttcgaaacgagacgttataaatagaaaaaaggtcctt\n\
ctggttctattctgctgaactattgaatggaaagattggttgacctacgtactatttgct\n\
tgaagtcatcaatttgacggggtgagagacatatggtgcatactttacggactctatatt\n\
ttagatcagaagcttagcagtcttctctacaccccctcacgacataattgcttttaagaa\n\
tctatgtttgattcctctacgggaattcggatccgttcgcatgtgcggtttatctaaacc\n\
aggggacatatgttcagctaaagcatacgaacactttgctaactagacgtatgtatagta\n\
gctataaatcccgacgatatttacaaaaagaaatgagactcaaatatatacatagcgacc\n\
ctacacttattcgcaccctgatctaggcgatcctagcacccacacccgaaagtgagcact\n\
agtgtcttccgtattaaatttactgcagttgagattttagttgtctactaaggattactc\n\
taacccgtaataaggatcaagactcggtactagctttactatcattccctatgtgttttc\n\
ctaactcacaagggtacgtaccagcctatgtaattacaataatgataaagacacaaagga\n\
agtaactttacaaatgagtctccagttacactagcttagtccctcccatcttgctttgaa\n\
gtctaaatacgcaatctctgaggatatacagcagaagaacactcataacgttggagtcca\n\
agaattagactcatagggcccccaacatttaatatgtactgtgagtttgaaggtgttcta\n\
ttgttaattcctgctcttgatacatgacacgtactccgtgtttaaggcttcggactgact\n\
ttctttcataagttgagcaacgaaaatttcagaatcgataagttggattcactaactaat\n\
acggctgattgaaaactccactccggacctatatggtcgacctttatacgtaaccgatat\n\
aaaacttataggctggtatatcgagccttcctagcgcaatttcggatggggtttcttcta\n\
ctactcaacaacggaatagtctttgtttagtaaaccagagctcaggacgcccaatacgta\n\
ggagagcgctgtggagcatgtgtcattatggactggagcactcttaaatcactctgcgtg\n\
tgctaaacgatagatcataacatgtcctgagtaaattttcttgatacgtcgcaatatacc\n\
gttattagttaaacgttctcatccgtcatgcgtgaaatacggctgtcgtgctcagatata\n\
ctattagcgactcatctcgcctaacacgcacacgtataaactcggaatgactgccgctct\n\
tacatattagaaatacagactacaccacggaagcattgggtcattctcaaccgctgtata\n\
aaagatgattagtcttataataagattaccaaagaggcagaatcatgggtagtaaatcta\n\
ttattcaagtgattaccgtcgtgtaggcagggagtgaggacgagatggtactcaggacaa\n\
atattaaccggacgaagtggtttacgtcgtactttcactattagtagtaaatacaaggta\n\
acaccggggaatagtactaaatataatgatatctatcttcgggagaacgagtcgtctatt\n\
gctttgaacattctcaaggcgtaaaatgtgctgacttatagcatgatacaaccgattgtt\n\
acttttgtctattcaaaagattgaatagttttttatacaaaagccgcatacttatgacgg\n\
ctagtatacagtttcatcccctagcatcaatgctatggacagtattgaacttataggaaa\n\
ttcttctaatagggcaaatccgtcgtgatgcctattttttttcagtcacatcctcaaatg\n\
gcactagtattgtcgggatcccattaacaggctcaaccacgagctcacgcgaggacatgt\n\
agtccgtatctttaacgaagcgacagcgacagaactcccatggataaccaattataaggc\n\
ccgtaatcctctagacatcgtttaccaataaatccgctttctccgtaatcatgttgaata\n\
ccccagagtagtccagatgataaccgatgaaacacaagtctttctcaatgcacttacggt\n\
gaacttattaccgccaacgtagctcatcaaggttgcgacatctagttgtgtgtttgcgac\n\
gagcccagcgaacttcatcaactttcgtatattcaacgccttgtaattttactttaagac\n\
gcctggtgatgtagattcttagataatcagtttgttatcggctgtactttaccataattt\n\
cacaggtttcaggtcaagaagattatagctgtatatacagttccatgctcggtgcacaga\n\
aacgtgatcggataataatcaatcgcttatgtcgtctttaggcgtatccaatacatgccc\n\
cgataccgcagtgtatttcgacatgtaggtataccgtcgcatttgagctcgagtcaggac\n\
gtcagctagattagattccttaatagaatataccgacctctagtccgaactaaactatag\n\
ataacgccaacttcaggttaattgtctagtcgtctgtttgcagatgggattcttagatga\n\
gtgagtatcggccatattggttcgagcactttagtttttgatgcataggatatgcaatgt\n\
atagctgaaagtactttatctgtttcaaactcacattgattaaaccggtaaacctttaaa\n\
gactacaagaaaatattcagtgagggcaattttgtcaatcacaatcttccagctagagat\n\
acttcacaatttgtcttgaggctacgcaacattagacggattttcgcgttttattgaaat\n\
aatcgaggggcccaagagtatccatagttcattttgtaagatttctttacaggcttatta\n\
cagcttcttcagactcctacatgcttacgagttatatgctagcatgtgaacaatagatta\n\
atatacaggaaaacgtacattgagagagatgaccctacacagcgcaaccgttgagtactt\n\
tcattaaagggtaacgctctcgagacagcatccttaagatggccttattgtcaaatcatt\n\
tgcagaagtacgcaagatccctaaccaacgtagaagaatccctacaaacacatgagacgc\n\
ggtgaaaatagacagggtgttagtattcaatcttcggagtatcaatttcgccaatcttgg\n\
tgagaaagcataccctttcttcagagaaagaagatcaatcataacactatctttaacgag\n\
gtacgcacgcgcatcattacctgcctccatggatctttaggatagcggaaagtattggca\n\
gcgtattgtgatttcgttcctactttatcaatttcacattcatatacatgtcttttatca\n\
aaatcgccaataagataggatgagctatattagatgctagtagagttcgcgccaacatca\n\
tcgataggaatactcaggacagcgtgataggacttttcaatccctaatactctctataat\n\
tataactctctcttaagtttggaggcagtaacgcgctctatataatcagtttgctgcacc\n\
attcttcagcctctgatacatacaaataaattccacagcagtaagagggtttaattgaga\n\
catcttgggaacttaggattttactctaacatcaccgaaacgattattggataccgtacc\n\
taaacgaactttctcaaggcagtaatataggacatccgcaataacacaaatgctgcctcc\n\
ccaggagttatgtcttcctggaggctatatcttacacccactcactataggcaaactaaa\n\
gtttaaatgttgattgtctaaaaaaaagatagataagagttggccggcgtagcacatgcg\n\
aaagtgaatcgtaagctataattctctggacttgaagttctgtcctgttcctctgcaaga\n\
aacaaacttcctttaaagctatttacgacgcacatctcagcaagttataaacatgttgga\n\
agtttctagtcggaattcccaaagaacggatctatctaatgcattcctacatttttcctg\n\
tctgccgatggtgccatcctattcaaagaatttcttaaaagtagattaaatgggactttt\n\
aacaatgagtaaccttacgcctctaagggttcctcgagtgccatacaccagtcaggtccg\n\
agccacatacacggagaacattctaacatagcattctcaactcgatcatttgcaggttac\n\
ttctttcctatcctagtgctaaaaatcatacttgcaatcccatagcacggattaagaacc\n\
taagaaacaattcagtaaaacatgttcgaattcttggtatgggaacatcattgcagctat\n\
ggtctaacgcattaatgtttgggtacatcttccatcatataaacaggaagagtctgacga\n\
cagggagtgcttgcgatcatgtctatcattgtgaaatcaaattgtagctcacatgtcgtc\n\
tatgagagcgtgtatccgataagatttagaaaaatagaagtcgtataagatctcactgaa\n\
cttttgaatgaatgtgaagcatatatgatctgctttaataaaactttatccataggatac\n\
gtttccaaatcaattcaataattattagtcaaaatagataaggatgaacaacctgaaggc\n\
cgatcggacgtagaaagtggtcccatcactttgagttgatattgttgaaccacacgttat\n\
tatggttttcaaacagtctcaggatattgtatatacagataatccgataccagttgtctg\n\
acgcccctcttacgtaccccaccctttgtgacgtttaaagcagttgttcagtattttaaa\n\
ctaggcggcaactaatttggaaagaagcacagtggatatgtctaaattcttgttattcag\n\
gcctgaatttaatacaccgcatagttaacttcgcggtagagttgttcatcatgcctcctc\n\
taagctaccacttctatgatacaccaatagttgttctacggaatctgataattggccaag\n\
tcataaacttccgctgcgttcaacccccttgctcgaatatccaactcgaaaagacagcct\n\
tttggtgtccggaacaaatcagttacttcttttctgatgttaattctctgtggtcagata\n\
cagaccaaaaactccgcggatttaccatcctccaagaacaaatttgcatcaacatagcat\n\
tttggctacatattctaagtctcaatagtttaggttttcaactacattatcccaacatta\n\
ggattggaggaataatagctgggtaagtccccttgcgtctacaatcgactattttttatg\n\
aatatgcttctgccgcacctatggttattaaaaaagtcatgactttgaagaaccctgaaa\n\
agatagatgaatcaggtgtaatggcagcagccaaagagcatataattagcaacactctaa\n\
gaacattatagatatgatgatagcgatcgtcatgatgttatccggtcacaatagtagctt\n\
catcagctaattcgttttgccagtggtgacttgcgctggaagaatcgttatacggtccct\n\
tccctcttgatacggtgggggcttattcaaccgcgtggattgggttgtcatacttgcatt\n\
aaacgatgtaaaccatctagtagtcaactatactaaatcacaaaatagtgatcaatacat\n\
acccgcttcatggttttaaccatttaattgattaaagatattccgctaagaaccattatc\n\
tacctaaactgatcgccgtatcctagtagtttgaaatttgatgtaccgtaatgatcaacg\n\
aagtaaaacgttatattgtatgtagaataataggtcttggagctaaatgatgtgattggt\n\
agtgaagacttacccttacaactttaccggtttctcggaagaatatactagagaatcaat\n\
gcatgggctacataagcactttagtctaatgagataaaaaatacacgagtcttccatcat\n\
gaattttttgtcgaaaaactcgaacctggtaatttaaaccatatatctttatgtcgtcaa\n\
taactctcatatgttttatataacttcccaatcacgacttgtaactgcttgttcgactga\n\
gctgtttgagctatgaggccgggatccggttgagctacatctatttgctacaagaaaaat\n\
gaaagcacatttgttgggagttctggctacactcatagagaaataagtggcccgagtggg\n\
tgcggcctgcctccatattcaagtgtatcttaaaccaagtggttccaacgctcgcgctaa\n\
agaattaaagcctttatttcctccacggagtagcccgtaatccggttcgaaagagaccat\n\
tgaagttaattttcatatccagtgaagtttaggcacaagcatgtgttctgccacatgcct\n\
caaagcgctcttcaaccaagatatgattcatcctaacttcgatgaatgcgtctgtaacat\n\
aaatatagaaggaatgattcggcgagttaattttcgccttctccaacatggcatccctac\n\
gttcgttataaggaccatacatgtaggttttaaaggtttgcggttaatcgatatttacat\n\
catagaaattctatagtcaaatttacaagactctagatactcactcgttgcagccggcta\n\
ggaagcgctttgtaccttacttcccttttcgttgcgtaatatgaatttcatatagtaagt\n\
tcaaggcactcatacctccgtgaagagggtagatagactattaaagttgtttaatagtac\n\
gtattgatggaaatgacccgtaggagatttaccactcaatccacaagattcgctgctgtg\n\
cattatcaaaacagtgcatgtcgaaacatgggttgggtccttcaaacacgaatccaggta\n\
gagatacctttgcaattttt\n";

dnaInput = dnaInput + dnaInput + dnaInput;

var ilen, clen,
 seqs = [
  /agggtaaa|tttaccct/ig,
  /[cgt]gggtaaa|tttaccc[acg]/ig,
  /a[act]ggtaaa|tttacc[agt]t/ig,
  /ag[act]gtaaa|tttac[agt]ct/ig,
  /agg[act]taaa|ttta[agt]cct/ig,
  /aggg[acg]aaa|ttt[cgt]ccct/ig,
  /agggt[cgt]aa|tt[acg]accct/ig,
  /agggta[cgt]a|t[acg]taccct/ig,
  /agggtaa[cgt]|[acg]ttaccct/ig],
 subs = {
  B: '(c|g|t)', D: '(a|g|t)', H: '(a|c|t)', K: '(g|t)',
  M: '(a|c)', N: '(a|c|g|t)', R: '(a|g)', S: '(c|t)',
  V: '(a|c|g)', W: '(a|t)', Y: '(c|t)' }

ilen = dnaInput.length;

// There is no in-place substitution
dnaInput = dnaInput.replace(/>.*\n|\n/g,"")
clen = dnaInput.length

var dnaOutputString;

for(i in seqs)
    dnaOutputString += seqs[i].source + " " + (dnaInput.match(seqs[i]) || []).length + "\n";
 // match returns null if no matches, so replace with empty

for(k in subs)
 dnaInput = dnaInput.replace(k, subs[k]) // FIXME: Would like this to be a global substitution in a future version of SunSpider.
 // search string, replacement string, flags
  �  0   ��( B A S E 6 4 . J S       0           /* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla XML-RPC Client component.
 *
 * The Initial Developer of the Original Code is
 * Digital Creations 2, Inc.
 * Portions created by the Initial Developer are Copyright (C) 2000
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Martijn Pieters <mj@digicool.com> (original author)
 *   Samuel Sieb <samuel@sieb.net>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

// From: http://lxr.mozilla.org/mozilla/source/extensions/xml-rpc/src/nsXmlRpcClient.js#956

/* Convert data (an array of integers) to a Base64 string. */
var toBase64Table = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
var base64Pad = '=';

function toBase64(data) {
    var result = '';
    var length = data.length;
    var i;
    // Convert every three bytes to 4 ascii characters.
    for (i = 0; i < (length - 2); i += 3) {
        result += toBase64Table[data.charCodeAt(i) >> 2];
        result += toBase64Table[((data.charCodeAt(i) & 0x03) << 4) + (data.charCodeAt(i+1) >> 4)];
        result += toBase64Table[((data.charCodeAt(i+1) & 0x0f) << 2) + (data.charCodeAt(i+2) >> 6)];
        result += toBase64Table[data.charCodeAt(i+2) & 0x3f];
    }

    // Convert the remaining 1 or 2 bytes, pad out to 4 characters.
    if (length%3) {
        i = length - (length%3);
        result += toBase64Table[data.charCodeAt(i) >> 2];
        if ((length%3) == 2) {
            result += toBase64Table[((data.charCodeAt(i) & 0x03) << 4) + (data.charCodeAt(i+1) >> 4)];
            result += toBase64Table[(data.charCodeAt(i+1) & 0x0f) << 2];
            result += base64Pad;
        } else {
            result += toBase64Table[(data.charCodeAt(i) & 0x03) << 4];
            result += base64Pad + base64Pad;
        }
    }

    return result;
}

/* Convert Base64 data to a string */
var toBinaryTable = [
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,62, -1,-1,-1,63,
    52,53,54,55, 56,57,58,59, 60,61,-1,-1, -1, 0,-1,-1,
    -1, 0, 1, 2,  3, 4, 5, 6,  7, 8, 9,10, 11,12,13,14,
    15,16,17,18, 19,20,21,22, 23,24,25,-1, -1,-1,-1,-1,
    -1,26,27,28, 29,30,31,32, 33,34,35,36, 37,38,39,40,
    41,42,43,44, 45,46,47,48, 49,50,51,-1, -1,-1,-1,-1
];

function base64ToString(data) {
    var result = '';
    var leftbits = 0; // number of bits decoded, but yet to be appended
    var leftdata = 0; // bits decoded, but yet to be appended

    // Convert one by one.
    for (var i = 0; i < data.length; i++) {
        var c = toBinaryTable[data.charCodeAt(i) & 0x7f];
        var padding = (data.charCodeAt(i) == base64Pad.charCodeAt(0));
        // Skip illegal characters and whitespace
        if (c == -1) continue;

        // Collect data into leftdata, update bitcount
        leftdata = (leftdata << 6) | c;
        leftbits += 6;

        // If we have 8 or more bits, append 8 bits to the result
        if (leftbits >= 8) {
            leftbits -= 8;
            // Append if not padding.
            if (!padding)
                result += String.fromCharCode((leftdata >> leftbits) & 0xff);
            leftdata &= (1 << leftbits) - 1;
        }
    }

    // If there are any bits left, the base64 string was corrupted
    if (leftbits)
        throw Components.Exception('Corrupted base64 string');

    return result;
}

var str = "";

for ( var i = 0; i < 8192; i++ )
        str += String.fromCharCode( (25 * Math.random()) + 97 );

for ( var i = 8192; i <= 16384; i *= 2 ) {

    var base64;

    base64 = toBase64(str);
    base64ToString(base64);

    // Double the string
    str += str;
}

toBinaryTable = null;
 �  @   ��( V A L I D A T E I N P U T . J S         0           letters = new Array("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z");
numbers = new Array(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26);
colors  = new Array("FF","CC","99","66","33","00");

var endResult;

function doTest()
{
   endResult = "";

   // make up email address
   for (var k=0;k<4000;k++)
   {
      username = makeName(6);
      (k%2)?email=username+"@mac.com":email=username+"(at)mac.com";

      // validate the email address
      var pattern = /^[a-zA-Z0-9\-\._]+@[a-zA-Z0-9\-_]+(\.?[a-zA-Z0-9\-_]*)\.[a-zA-Z]{2,3}$/;

      if(pattern.test(email))
      {
         var r = email + " appears to be a valid email address.";
         addResult(r);
      }
      else
      {
         r = email + " does NOT appear to be a valid email address.";
         addResult(r);
      }
   }

   // make up ZIP codes
   for (var s=0;s<4000;s++)
   {
      var zipGood = true;
      var zip = makeNumber(4);
      (s%2)?zip=zip+"xyz":zip=zip.concat("7");

      // validate the zip code
      for (var i = 0; i < zip.length; i++) {
          var ch = zip.charAt(i);
          if (ch < "0" || ch > "9") {
              zipGood = false;
              r = zip + " contains letters.";
              addResult(r);
          }
      }
      if (zipGood && zip.length>5)
      {
         zipGood = false;
         r = zip + " is longer than five characters.";
         addResult(r);
      }
      if (zipGood)
      {
         r = zip + " appears to be a valid ZIP code.";
         addResult(r);
      }
   }
}

function makeName(n)
{
   var tmp = "";
   for (var i=0;i<n;i++)
   {
      var l = Math.floor(26*Math.random());
      tmp += letters[l];
   }
   return tmp;
}

function makeNumber(n)
{
   var tmp = "";
   for (var i=0;i<n;i++)
   {
      var l = Math.floor(9*Math.random());
      tmp = tmp.concat(l);
   }
   return tmp;
}

function addResult(r)
{
   endResult += "\n" + r;
}

doTest();
 