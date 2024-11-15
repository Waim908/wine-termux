        ��  ��                  7	  4   �� W I N E T E S T . J S       0           /*
 * Copyright 2016 Jacek Caban for CodeWeavers
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

function guard(f) {
    return function() {
        try {
            f();
        }catch(e) {
            var msg = "Got exception ";
            if(e && typeof(e) == "object" && "message")
                msg += e.message;
            else
                msg += e;
            ok(false, msg);
            if("tests" in window) next_test();
        }
    };
}

function next_test() {
    var test = tests.shift();
    window.setTimeout(guard(test), 0);
}

function run_tests() {
    tests.push(reportSuccess);
    next_test();
}

function ok(b,m) {
    return external.ok(b, format_message(m));
}

function trace(m) {
    external.trace(format_message(m));
}

function win_skip(m) {
    external.win_skip(m);
}

function broken(e)
{
    return external.broken(e);
}

function reportSuccess() {
    external.reportSuccess();
}

var todo_wine = {
    ok: function(b,m) {
        return external.todo_wine_ok(b, format_message(m));
    }
};

function todo_wine_if(expr) {
    return expr ? todo_wine : { ok: ok };
}

var file_prefix = document.location.pathname;
if(document.location.search)
    file_prefix += document.location.search;
file_prefix += ":";

var test_name;

function format_message(msg) {
    var p = file_prefix;
    if(test_name) p += test_name + ":";
    return p + " " + msg;
}

function sync_test(name, f)
{
    tests.push(function() {
        test_name = name;
        f();
        test_name = undefined;
        next_test();
    });
}

function async_test(name, f)
{
    tests.push(function() {
        test_name = name;
        f();
    });
}
 �  8   �� E X E C T E S T . H T M L       0           <html>
<body>
Script execution test
<div id="b1"></div>
<div id="b2"></div>
<div id="b3"></div>
<script id="emptyscript"></script>
<script id="put_text_script">2+2</script>
<script>
function ok(b, msg) {
    return external.ok(b, msg);
}

var executed = false;
var extern_cnt = 0;
var exec_cnt;

function testWriteScript() {
    var len = document.getElementsByTagName('div').length;
    ok(len === 3, "init length = " + len);

    document.write("<script>"
        + "var len = document.getElementsByTagName('div').length;"
        + "ok(len === 3, 'unexpected length ' + len);"
        + "executed = true;"
        + "<" + "/script>");

    len = document.getElementsByTagName('script').length;
    ok(len === 4, "script col length = " + len);
    ok(executed, "written script not executed");
}

function testPutSrc() {
    var elem = document.getElementById("emptyscript");

    ok(extern_cnt === 0, "extern_cnt = " + extern_cnt + " expected 0");
    elem.src = "externscr.js";
    ok(extern_cnt === 0, "extern_cnt = " + extern_cnt + " expected 0");
}

function testPutText() {
    var elem = document.getElementById("put_text_script");

    exec_cnt = 0;
    elem.text = "exec_cnt++;";
    ok(exec_cnt === 1, "put_text_script exec_cnt " + exec_cnt);

    exec_cnt = 0;
    elem.text = "exec_cnt++;";
    ok(exec_cnt === 1, "put_text_script exec_cnt " + exec_cnt);
}

try {
    testWriteScript();
    testPutSrc();
    testPutText();
}catch(e) {
    ok(false, "Got an exception " + e.message);
}

function testPutSrc2() {
    var elem, elem2;

    elem = document.createElement("script");
    elem.src = "externscr.js";
    ok(extern_cnt === 1, "extern_cnt = " + extern_cnt + " expected 1");
    document.body.appendChild(elem);
    ok(extern_cnt === 2, "extern_cnt = " + extern_cnt + " expected 2");

    elem = document.createElement("script");
    document.body.appendChild(elem);
    ok(extern_cnt === 2, "extern_cnt = " + extern_cnt + " expected 2");
    elem.src = "externscr.js";
    ok(extern_cnt === 3, "extern_cnt = " + extern_cnt + " expected 3");

    elem2 = document.createElement("div");
    elem = document.createElement("script");
    elem.src = "externscr.js";
    ok(extern_cnt === 3, "extern_cnt = " + extern_cnt + " expected 3");
    elem2.appendChild(elem);
    document.body.appendChild(elem2);
    ok(extern_cnt === 4, "extern_cnt = " + extern_cnt + " expected 4");
}

function testPutText2() {
    var elem;

    elem = document.createElement("script");
    exec_cnt = 0;
    elem.text = "exec_cnt++;";
    ok(exec_cnt === 0, "script exec_cnt " + exec_cnt);

    document.body.appendChild(elem);
    ok(exec_cnt === 1, "script exec_cnt " + exec_cnt);
    exec_cnt = 0;
    elem.text = "exec_cnt++;";
    ok(exec_cnt === 1, "script exec_cnt " + exec_cnt);

    elem.src = "externscr.js";
    ok(extern_cnt === 5, "extern_cnt = " + extern_cnt + " expected 5");

    exec_cnt = 0;
    ok(extern_cnt === 5, "> extern_cnt = " + extern_cnt + " expected 5");
    elem.text = "exec_cnt++;"; /* forces evaluation, but src will be executed */
    ok(exec_cnt === 0, "script exec_cnt " + exec_cnt);
    ok(extern_cnt === 6, "< extern_cnt = " + extern_cnt + " expected 6");
    elem.text = "exec_cnt++;"; /* forces evaluation, but src will be executed */
    ok(exec_cnt === 0, "script exec_cnt " + exec_cnt);
    ok(extern_cnt === 7, "< extern_cnt = " + extern_cnt + " expected 6");

    elem = document.createElement("script");
    exec_cnt = 0;
    elem.text = "exec_cnt++;";
    ok(exec_cnt === 0, "script exec_cnt " + exec_cnt);
    elem.src = "externscr.js";
    ok(extern_cnt === 7, "extern_cnt = " + extern_cnt + " expected 7");

    document.body.appendChild(elem);
    ok(exec_cnt === 0, "script exec_cnt " + exec_cnt);
    ok(extern_cnt === 8, "extern_cnt = " + extern_cnt + " expected 8");
}

document.body.onload = function() {
    ok(extern_cnt === 1, "extern_cnt = " + extern_cnt);
    try {
        testPutSrc2();
        testPutText2();
    }catch(e) {
        ok(false, "got an exception " + e.message);
    }

    external.reportSuccess();
}
</script>
<script>
    ok(extern_cnt === 1, "extern_cnt = " + extern_cnt);
</script>
<div id="a1"></div>
<div id="a2"></div>
<div id="b3"></div>
</body>
</html>
  ~  D   �� A S Y N C S C R I P T L O A D . J S         0           /*
 * Copyright 2016 Jacek Caban for CodeWeavers
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

var tests = [];
var head = document.getElementsByTagName("head")[0];

/* Dynamically created script element is downloaded as soon as src property is set,
 * but it doesn't block document onload event. */
var detached_elem_executed = false;
var detached_elem = document.createElement("script");
detached_elem.src = "jsstream.php?detached_script";

async_test("detached_script_elem", function() {
    var oncomplete_called = false;
    detached_elem.onreadystatechange = guard(function() {
        if(detached_elem.readyState == "complete") {
            ok(detached_elem_executed, "detached element not executed before readyState complete");
            oncomplete_called = true;
            next_test();
            return;
        }

        ok(!detached_elem_executed, "detached element executed");
        if(detached_elem.readyState == "loaded") {
            head.appendChild(detached_elem);
            ok(detached_elem_executed, "detached element not yet executed");
            ok(detached_elem.readyState == "complete", "detached_elem.readyState = " + detached_elem.readyState + " expected complete");
            ok(!oncomplete_called, "oncomplete not called");
        }
    });

    external.writeStream("detached_script", 'detached_elem_executed = true;');
});

/* Dynamically created script elements are evaluated as soon as they are loaded, no matter
 * how they are ordered in the tree. */
var attached_elem1_executed = false;
var attached_elem1 = document.createElement("script");
attached_elem1.src = "jsstream.php?attached_script1";
head.appendChild(attached_elem1);

var attached_elem2_executed = false;
var attached_elem2 = document.createElement("script");
attached_elem2.src = "jsstream.php?attached_script2";
head.appendChild(attached_elem2);

async_test("attached_script_elem", function() {
    attached_elem1.onreadystatechange = guard(function() {
        ok(attached_elem1.readyState == "loaded", "attached_elem1.readyState = " + attached_elem2.readyState);
        ok(attached_elem1_executed, "attached element 1 not executed before readyState complete");
        next_test();
    });

    attached_elem2.onreadystatechange = guard(function() {
        ok(attached_elem2.readyState == "loaded", "attached_elem2.readyState = " + attached_elem2.readyState);
        ok(attached_elem2_executed, "attached element 2 not executed before readyState complete");

        external.writeStream("attached_script1", 'attached_elem1_executed = true;');
    });

    external.writeStream("attached_script2", 'attached_elem2_executed = true;');
});

async_test("append_script", function() {
    var elem = document.createElement("script");
    var ready_states = "";

    elem.onreadystatechange = guard(function() {
        ready_states += elem.readyState + ",";
        if(elem.readyState == "loaded")
            next_test();
    });

    document.body.appendChild(elem);
    elem.src = "jsstream.php?simple";
    external.writeStream("simple", " ");
});

function unexpected_load(e) {
    ok(false, "onload event before executing script");
}

guard(function() {
    var elem = document.createElement("script");
    document.head.appendChild(elem);
    elem.src = "jsstream.php?blockload";

    window.addEventListener("load", unexpected_load, true);

    setTimeout(guard(function() {
        external.writeStream("blockload", "window.removeEventListener('load', unexpected_load, true);");
    }), 100);
})();
  >;  4   �� J S T E S T . H T M L       0           <html>
<head>
<script src="winetest.js" type="text/javascript"></script>
</head>
<head>
<script>
function broken(expr) {
    return external.broken(expr);
}

function test_removeAttribute(e) {
    ok(e.removeAttribute('nonexisting') === false, "removeAttribute('nonexisting') didn't return false");

    e.title = "title";
    ok(e.removeAttribute('title') === true, "removeAttribute('title') didn't return true");
    ok(e.title === "", "e.title = " + e.title);
    ok(("title" in e) === true, "title is not in e");

    e["myattr"] = "test";
    ok(e.removeAttribute('myattr') === true, "removeAttribute('myattr') didn't return true");
    ok(e["myattr"] === undefined, "e['myattr'] = " + e['myattr']);
    ok(("myattr" in e) === false, "myattr is in e");

}

function test_select_index() {
    var s = document.getElementById("sel");

    ok("0" in s, "'0' is not in s");
    ok(s[0].text === "opt1", "s[0].text = " + s[0].text);
    ok("1" in s, "'1 is not in s");
    ok(s[1].text === "opt2", "s[1].text = " + s[1].text);
    ok("2" in s, "'2' is in s");
    ok(s[2] === null, "s[2] = " + s[2]);
}

function test_createDocumentFragment() {
    var fragment = document.createDocumentFragment();

    ok(typeof(fragment) === "object", "typeof(fragmend) = " + typeof(fragment));
    ok(fragment.nodeType === 11, "fragment.nodeType = " + fragment.nodeType);
    ok(fragment.nodeName === "#document-fragment", "fragment.nodeName = " + fragment.nodeName);

    var cloned = fragment.cloneNode(true);
    ok(cloned.nodeType === 11, "cloned.nodeType = " + cloned.nodeType);
    ok(cloned.nodeName === "#document-fragment", "cloned.nodeName = " + cloned.nodeName);
}

function test_document_name_as_index() {
    document.body.innerHTML = '<form name="formname"></form>';
    var e = document.getElementById("formname");
    ok(!!e, "e is null");

    ok(document.formname === e, "document.formname != getElementById('formname')");
    ok("formname" in document, "formname' is not in document");

    document.body.removeChild(e);

    ok(document.formname === undefined, "document.formname is not undefined");
    ok(!("formname" in document), "formname' is in document");

    document.body.innerHTML = '<form id="formid"></form>';
    var e = document.getElementById("formid");
    ok(!!e, "e is null");
    ok(!("formid" in document), "formid is in document");

    document.body.innerHTML = '<form name="formname"></form>';
    ok("formname" in window, "formname' is not in window");
    ok(typeof(window.formname) === "object", "typeof(window.formname) = " + typeof(window.formname));
    window.formname = 1;
    ok(window.formname === 1, "window.formname = " + window.formname);
    formname = 2;
    ok(window.formname === 2, "window.formname = " + window.formname);

    document.body.innerHTML = '<iframe id="iframeid"></iframe>';
    ok("iframeid" in window, "iframeid is not in window");
    e = document.getElementById("iframeid");
    ok(!!e, "e is null");
    ok(iframeid === e.contentWindow.self, "frameid != e.contentWindow.self");
    ok(iframeid.frameElement === e, "frameid.frameElement != e");
}

function test_remove_style_attribute() {
    var s = document.body.style, b;

    s.somevar = "test";
    b = s.removeAttribute("somevar", 1);
    ok(b, "removeAttribute returned " + b + " expected true");
    b = s.removeAttribute("somevar", 1);
    ok(b === false, "removeAttribute returned " + b + " expected false");
}

function test_clone_node() {
    var elem, cloned;

    elem = document.getElementById("divid");
    elem.style.filter = "alpha(opacity=50)";
    ok(elem.style.filter === "alpha(opacity=50)", "elem.style.filter = " + elem.style.filter);

    cloned = elem.cloneNode(true);
    ok(cloned.style.filter === "alpha(opacity=50)", "cloned.style.filter = " + cloned.style.filter);
}

function test_attrs() {
    var input, s, x, f, b;

    document.body.innerHTML = '<input id="inputid"></input>';
    input = document.getElementById("inputid");
    s = input.style;
    f = input.fireEvent;
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "test");
    ok(input.checked === true, "input.checked = " + input.checked);

    input.setAttribute("checked", 0);
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("Checked", 1, 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok(!("Checked" in input), "Checked added to input");

    input.setAttribute("checked", 0, 0);
    input.setAttribute("Checked", 1, 1);
    ok(input.checked === false, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 1, "input.Checked = " + input.Checked);

    input.removeAttribute("Checked", 1);
    ok(!("Checked" in input), "Checked is still in input");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", 1, 0);
    input.setAttribute("Checked", 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 0, "input.Checked = " + input.Checked);

    input.setAttribute("Checked", 2, 2);
    ok(input.Checked === 0, "input.Checked = " + input.Checked);
    input.setAttribute("Checked", 3, 3);
    ok(input.Checked === 3, "input.Checked = " + input.Checked);

    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", "display: none");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    ok(s.display === "", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    s.display = "none";
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    input.setAttribute("style", "");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", null);
    x = input.getAttribute("style");
    ok(input.style === s, "input.style = " + input.style);
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);

    x = input.getAttribute("fireEvent");
    ok(x === input.fireEvent, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "", "getAttribute('fireEvent') = " + x);

    input.setAttribute("fireEvent", 3);
    ok(input.fireEvent === 3, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "3", "getAttribute('fireEvent') = " + x);

    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");
    ok(input.style === s, "input.style = " + input.style);
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.display === "", "s.display = " + s.display);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);
    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");

    b = false;
    try {
        input.setAttribute("tagName", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(tagName)");

    b = false;
    try {
        input.setAttribute("parentElement", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(parentElement)");

    b = input.removeAttribute("fireEvent");
    ok(b === true, "removeAttribute(fireEvent) failed");
    ok(input.fireEvent === f, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === f, "input.getAttribute('fireEvent') = " + x);
    b = input.removeAttribute("fireEvent");
    ok(b === false || broken(b === true), "removeAttribute(fireEvent) returned " + b);

    input.fireEvent = 3;
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    ok(input.fireEvent === 3, "input.fireEvent' = " + input.fireEvent);
}

function test_attribute_collection() {
    var div, attr;

    document.body.innerHTML = '<div id="divid" class="test"></div>';
    div = document.getElementById("divid");

    attr = div.attributes["dir"];
    ok(attr === div.attributes["dir"], "attr !== div.attributes['dir']");
}

function test_getter_call() {
    document.body.innerHTML = '<div id="divid"></div>';

    var e = document.getElementById("divid");

    e.myfunc = function(x) { this.myfunc_called = x; };
    e.myfunc("test");
    ok(e.myfunc_called === "test", "e.myfunc_called = " + e.myfunc_called);

    e.onmousedown = function(x) { this.onmousedown_called = x; };
    e.onmousedown("test");
    ok(e.onmousedown_called === "test", "e.onmousedown_called = " + e.onmousedown_called);

    ok(document.all("divid").tagName === "DIV", "document.all('divid').tagName = " + document.all("divid").tagName);
}

function test_arg_conv() {
    /* this call would throw if the argument wasn't converted by JScript */
    window.clearInterval("");

    navigator.javaEnabled();
}

function test_override_functions() {
    function override_func() { return "test"; }

    ok(typeof(window.showModalDialog) === "object", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));
    window.showModalDialog = override_func;
    ok(window.showModalDialog === override_func, "window.showModalDialog != override_func");
    ok(typeof(window.showModalDialog) === "function", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));

    document.body.innerHTML = '<div id="divid"></div>';
    var div = document.getElementById("divid");
    ok(typeof(div.addBehavior) === "object", "typeof(div.addBehavior) = " + typeof(div.addBehavior));
    div.addBehavior = override_func;
    ok(div.addBehavior === override_func, "div.addBehavior != override_func");
    ok(typeof(div.addBehavior) === "function", "typeof(div.addBehavior) = " + typeof(div.addBehavior));

    var tmp = div.addBehavior();
    ok(tmp === "test", "div.addBehavior() = " + tmp);

    tmp = String(div.attachEvent);
    ok(tmp == "\nfunction attachEvent() {\n    [native code]\n}\n", "String(div.attachEvent) = " + tmp);
}

function test_forin() {
    var cnt=0;

    document.body.innerHTML = '<a id="aid"></a>';

    for(var x in document.getElementById("aid")) {
        cnt++;
    }

    ok(cnt > 100, "cnt = " + cnt);
}

function test_customtag() {
    document.body.innerHTML = 'test<unk><br>';

    var children = document.body.childNodes;

    ok(children.length === 3, "children.length = " + children.length);
    ok(children[0].data === "test", "children[0].data = " + children[0].data);
    ok(children[1].tagName === "UNK", "children[1].tagName = " + children[1].tagName);
    ok(children[2].tagName === "BR", "children[2].tagName = " + children[2].tagName);
}

function test_whitespace_nodes() {
    document.body.innerHTML = '<table id="tid"> <tr> \t<td>\n \t<div></div> </td>\n </tr> </table>';

    var t = document.getElementById("tid");
    ok(t.childNodes.length === 1, "t.childNodes.length = " + t.childNodes.length);
    ok(t.childNodes[0].tagName === "TBODY", "t.childNodes[0].tagName = " + t.childNodes[0].tagName);

    var row = t.rows[0];
    ok(row.childNodes.length === 1, "row.childNodes.length = " + row.childNodes.length);
    ok(row.childNodes[0].tagName === "TD", "row.childNodes[0].tagName = " + row.childNodes[0].tagName);

    var cell = row.cells[0];
    ok(cell.childNodes.length === 1, "cell.childNodes.length = " + cell.childNodes.length);


    document.body.innerHTML = '<table id="tid"> x<tr> \tx<td>\n \tx<div></div> </td>\n </tr> </table>';

    t = document.getElementById("tid");
    ok(t.rows[0].cells[0].childNodes.length === 2,
        "t.rows[0].cells[0].childNodes.length = " + t.rows[0].cells[0].childNodes.length);
}

function test_language_attribute() {
    document.body.innerHTML = '<div id="did" language="test"></div>';
    var elem = document.getElementById("did");
    ok(elem.language === "test", "elem.language = " + elem.language);
    elem.language = 1;
    ok(elem.language === "1", "elem.language = " + elem.language);
}

function test_text_node() {
    document.body.innerHTML = 'testing text';
    var text = document.body.childNodes[0], text2;
    ok(text.data == "testing text", "text.data = " + text.data);

    text2 = text.splitText(7);
    ok(text.data == "testing", "text.data = " + text.data);
    ok(text2.data == " text", "text2.data = " + text2.data);
    ok(text.nextSibling === text2, "text.nextSibling !== text2");

    text2 = text.splitText(0);
    ok(text.data == "", "text.data = " + text.data);
    ok(text2.data == "testing", "text2.data = " + text2.data);
}

function test_xhr() {
    ok("XMLHttpRequest" in window, "XMLHttpRequest not found in window object\n");

    if (typeof(XMLHttpRequest) != "object") {
        win_skip("XMLHTTPRequest is not available or disabled");
        return;
    }

    var xhr = new XMLHttpRequest();
    ok(typeof(xhr) === "object", "typeof(xhr) = " + typeof(xhr));
}

var globalVar = false;

function runTests() {
    obj = new Object();
    ok(obj === window.obj, "obj !== window.obj");

    ok(typeof(divid) === "object", "typeof(divid) = " + typeof(divid));

    test_removeAttribute(document.getElementById("divid"));
    test_removeAttribute(document.body);
    test_select_index();
    test_clone_node();
    test_createDocumentFragment();
    test_document_name_as_index();
    test_remove_style_attribute();
    test_getter_call();
    test_attrs();
    test_attribute_collection();
    test_arg_conv();
    test_override_functions();
    test_forin();
    test_customtag();
    test_whitespace_nodes();
    test_language_attribute();
    test_text_node();
    test_xhr();

    var r = window.execScript("globalVar = true;");
    ok(r === undefined, "execScript returned " + r);
    ok(globalVar === true, "globalVar = " + globalVar);

    /* Call setTimeout without specified time. */
    window.setTimeout(function() { external.reportSuccess(); });
}

function runTest() {
    try {
        runTests();
    }catch(e) {
        ok(false, "got exception " + e.message);
    }
}
</script>
<body onload="runTest();">
<div id="divid"></div>
<select id="sel">
<option>opt1</option>
<option>opt2</option>
</select>
</body>
</html>
  >;  D   ��>J S T E S T - R T F I L E . H T M L         0           <html>
<head>
<script src="winetest.js" type="text/javascript"></script>
</head>
<head>
<script>
function broken(expr) {
    return external.broken(expr);
}

function test_removeAttribute(e) {
    ok(e.removeAttribute('nonexisting') === false, "removeAttribute('nonexisting') didn't return false");

    e.title = "title";
    ok(e.removeAttribute('title') === true, "removeAttribute('title') didn't return true");
    ok(e.title === "", "e.title = " + e.title);
    ok(("title" in e) === true, "title is not in e");

    e["myattr"] = "test";
    ok(e.removeAttribute('myattr') === true, "removeAttribute('myattr') didn't return true");
    ok(e["myattr"] === undefined, "e['myattr'] = " + e['myattr']);
    ok(("myattr" in e) === false, "myattr is in e");

}

function test_select_index() {
    var s = document.getElementById("sel");

    ok("0" in s, "'0' is not in s");
    ok(s[0].text === "opt1", "s[0].text = " + s[0].text);
    ok("1" in s, "'1 is not in s");
    ok(s[1].text === "opt2", "s[1].text = " + s[1].text);
    ok("2" in s, "'2' is in s");
    ok(s[2] === null, "s[2] = " + s[2]);
}

function test_createDocumentFragment() {
    var fragment = document.createDocumentFragment();

    ok(typeof(fragment) === "object", "typeof(fragmend) = " + typeof(fragment));
    ok(fragment.nodeType === 11, "fragment.nodeType = " + fragment.nodeType);
    ok(fragment.nodeName === "#document-fragment", "fragment.nodeName = " + fragment.nodeName);

    var cloned = fragment.cloneNode(true);
    ok(cloned.nodeType === 11, "cloned.nodeType = " + cloned.nodeType);
    ok(cloned.nodeName === "#document-fragment", "cloned.nodeName = " + cloned.nodeName);
}

function test_document_name_as_index() {
    document.body.innerHTML = '<form name="formname"></form>';
    var e = document.getElementById("formname");
    ok(!!e, "e is null");

    ok(document.formname === e, "document.formname != getElementById('formname')");
    ok("formname" in document, "formname' is not in document");

    document.body.removeChild(e);

    ok(document.formname === undefined, "document.formname is not undefined");
    ok(!("formname" in document), "formname' is in document");

    document.body.innerHTML = '<form id="formid"></form>';
    var e = document.getElementById("formid");
    ok(!!e, "e is null");
    ok(!("formid" in document), "formid is in document");

    document.body.innerHTML = '<form name="formname"></form>';
    ok("formname" in window, "formname' is not in window");
    ok(typeof(window.formname) === "object", "typeof(window.formname) = " + typeof(window.formname));
    window.formname = 1;
    ok(window.formname === 1, "window.formname = " + window.formname);
    formname = 2;
    ok(window.formname === 2, "window.formname = " + window.formname);

    document.body.innerHTML = '<iframe id="iframeid"></iframe>';
    ok("iframeid" in window, "iframeid is not in window");
    e = document.getElementById("iframeid");
    ok(!!e, "e is null");
    ok(iframeid === e.contentWindow.self, "frameid != e.contentWindow.self");
    ok(iframeid.frameElement === e, "frameid.frameElement != e");
}

function test_remove_style_attribute() {
    var s = document.body.style, b;

    s.somevar = "test";
    b = s.removeAttribute("somevar", 1);
    ok(b, "removeAttribute returned " + b + " expected true");
    b = s.removeAttribute("somevar", 1);
    ok(b === false, "removeAttribute returned " + b + " expected false");
}

function test_clone_node() {
    var elem, cloned;

    elem = document.getElementById("divid");
    elem.style.filter = "alpha(opacity=50)";
    ok(elem.style.filter === "alpha(opacity=50)", "elem.style.filter = " + elem.style.filter);

    cloned = elem.cloneNode(true);
    ok(cloned.style.filter === "alpha(opacity=50)", "cloned.style.filter = " + cloned.style.filter);
}

function test_attrs() {
    var input, s, x, f, b;

    document.body.innerHTML = '<input id="inputid"></input>';
    input = document.getElementById("inputid");
    s = input.style;
    f = input.fireEvent;
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "test");
    ok(input.checked === true, "input.checked = " + input.checked);

    input.setAttribute("checked", 0);
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("Checked", 1, 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok(!("Checked" in input), "Checked added to input");

    input.setAttribute("checked", 0, 0);
    input.setAttribute("Checked", 1, 1);
    ok(input.checked === false, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 1, "input.Checked = " + input.Checked);

    input.removeAttribute("Checked", 1);
    ok(!("Checked" in input), "Checked is still in input");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", 1, 0);
    input.setAttribute("Checked", 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 0, "input.Checked = " + input.Checked);

    input.setAttribute("Checked", 2, 2);
    ok(input.Checked === 0, "input.Checked = " + input.Checked);
    input.setAttribute("Checked", 3, 3);
    ok(input.Checked === 3, "input.Checked = " + input.Checked);

    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", "display: none");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    ok(s.display === "", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    s.display = "none";
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    input.setAttribute("style", "");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", null);
    x = input.getAttribute("style");
    ok(input.style === s, "input.style = " + input.style);
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);

    x = input.getAttribute("fireEvent");
    ok(x === input.fireEvent, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "", "getAttribute('fireEvent') = " + x);

    input.setAttribute("fireEvent", 3);
    ok(input.fireEvent === 3, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "3", "getAttribute('fireEvent') = " + x);

    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");
    ok(input.style === s, "input.style = " + input.style);
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.display === "", "s.display = " + s.display);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);
    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");

    b = false;
    try {
        input.setAttribute("tagName", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(tagName)");

    b = false;
    try {
        input.setAttribute("parentElement", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(parentElement)");

    b = input.removeAttribute("fireEvent");
    ok(b === true, "removeAttribute(fireEvent) failed");
    ok(input.fireEvent === f, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === f, "input.getAttribute('fireEvent') = " + x);
    b = input.removeAttribute("fireEvent");
    ok(b === false || broken(b === true), "removeAttribute(fireEvent) returned " + b);

    input.fireEvent = 3;
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    ok(input.fireEvent === 3, "input.fireEvent' = " + input.fireEvent);
}

function test_attribute_collection() {
    var div, attr;

    document.body.innerHTML = '<div id="divid" class="test"></div>';
    div = document.getElementById("divid");

    attr = div.attributes["dir"];
    ok(attr === div.attributes["dir"], "attr !== div.attributes['dir']");
}

function test_getter_call() {
    document.body.innerHTML = '<div id="divid"></div>';

    var e = document.getElementById("divid");

    e.myfunc = function(x) { this.myfunc_called = x; };
    e.myfunc("test");
    ok(e.myfunc_called === "test", "e.myfunc_called = " + e.myfunc_called);

    e.onmousedown = function(x) { this.onmousedown_called = x; };
    e.onmousedown("test");
    ok(e.onmousedown_called === "test", "e.onmousedown_called = " + e.onmousedown_called);

    ok(document.all("divid").tagName === "DIV", "document.all('divid').tagName = " + document.all("divid").tagName);
}

function test_arg_conv() {
    /* this call would throw if the argument wasn't converted by JScript */
    window.clearInterval("");

    navigator.javaEnabled();
}

function test_override_functions() {
    function override_func() { return "test"; }

    ok(typeof(window.showModalDialog) === "object", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));
    window.showModalDialog = override_func;
    ok(window.showModalDialog === override_func, "window.showModalDialog != override_func");
    ok(typeof(window.showModalDialog) === "function", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));

    document.body.innerHTML = '<div id="divid"></div>';
    var div = document.getElementById("divid");
    ok(typeof(div.addBehavior) === "object", "typeof(div.addBehavior) = " + typeof(div.addBehavior));
    div.addBehavior = override_func;
    ok(div.addBehavior === override_func, "div.addBehavior != override_func");
    ok(typeof(div.addBehavior) === "function", "typeof(div.addBehavior) = " + typeof(div.addBehavior));

    var tmp = div.addBehavior();
    ok(tmp === "test", "div.addBehavior() = " + tmp);

    tmp = String(div.attachEvent);
    ok(tmp == "\nfunction attachEvent() {\n    [native code]\n}\n", "String(div.attachEvent) = " + tmp);
}

function test_forin() {
    var cnt=0;

    document.body.innerHTML = '<a id="aid"></a>';

    for(var x in document.getElementById("aid")) {
        cnt++;
    }

    ok(cnt > 100, "cnt = " + cnt);
}

function test_customtag() {
    document.body.innerHTML = 'test<unk><br>';

    var children = document.body.childNodes;

    ok(children.length === 3, "children.length = " + children.length);
    ok(children[0].data === "test", "children[0].data = " + children[0].data);
    ok(children[1].tagName === "UNK", "children[1].tagName = " + children[1].tagName);
    ok(children[2].tagName === "BR", "children[2].tagName = " + children[2].tagName);
}

function test_whitespace_nodes() {
    document.body.innerHTML = '<table id="tid"> <tr> \t<td>\n \t<div></div> </td>\n </tr> </table>';

    var t = document.getElementById("tid");
    ok(t.childNodes.length === 1, "t.childNodes.length = " + t.childNodes.length);
    ok(t.childNodes[0].tagName === "TBODY", "t.childNodes[0].tagName = " + t.childNodes[0].tagName);

    var row = t.rows[0];
    ok(row.childNodes.length === 1, "row.childNodes.length = " + row.childNodes.length);
    ok(row.childNodes[0].tagName === "TD", "row.childNodes[0].tagName = " + row.childNodes[0].tagName);

    var cell = row.cells[0];
    ok(cell.childNodes.length === 1, "cell.childNodes.length = " + cell.childNodes.length);


    document.body.innerHTML = '<table id="tid"> x<tr> \tx<td>\n \tx<div></div> </td>\n </tr> </table>';

    t = document.getElementById("tid");
    ok(t.rows[0].cells[0].childNodes.length === 2,
        "t.rows[0].cells[0].childNodes.length = " + t.rows[0].cells[0].childNodes.length);
}

function test_language_attribute() {
    document.body.innerHTML = '<div id="did" language="test"></div>';
    var elem = document.getElementById("did");
    ok(elem.language === "test", "elem.language = " + elem.language);
    elem.language = 1;
    ok(elem.language === "1", "elem.language = " + elem.language);
}

function test_text_node() {
    document.body.innerHTML = 'testing text';
    var text = document.body.childNodes[0], text2;
    ok(text.data == "testing text", "text.data = " + text.data);

    text2 = text.splitText(7);
    ok(text.data == "testing", "text.data = " + text.data);
    ok(text2.data == " text", "text2.data = " + text2.data);
    ok(text.nextSibling === text2, "text.nextSibling !== text2");

    text2 = text.splitText(0);
    ok(text.data == "", "text.data = " + text.data);
    ok(text2.data == "testing", "text2.data = " + text2.data);
}

function test_xhr() {
    ok("XMLHttpRequest" in window, "XMLHttpRequest not found in window object\n");

    if (typeof(XMLHttpRequest) != "object") {
        win_skip("XMLHTTPRequest is not available or disabled");
        return;
    }

    var xhr = new XMLHttpRequest();
    ok(typeof(xhr) === "object", "typeof(xhr) = " + typeof(xhr));
}

var globalVar = false;

function runTests() {
    obj = new Object();
    ok(obj === window.obj, "obj !== window.obj");

    ok(typeof(divid) === "object", "typeof(divid) = " + typeof(divid));

    test_removeAttribute(document.getElementById("divid"));
    test_removeAttribute(document.body);
    test_select_index();
    test_clone_node();
    test_createDocumentFragment();
    test_document_name_as_index();
    test_remove_style_attribute();
    test_getter_call();
    test_attrs();
    test_attribute_collection();
    test_arg_conv();
    test_override_functions();
    test_forin();
    test_customtag();
    test_whitespace_nodes();
    test_language_attribute();
    test_text_node();
    test_xhr();

    var r = window.execScript("globalVar = true;");
    ok(r === undefined, "execScript returned " + r);
    ok(globalVar === true, "globalVar = " + globalVar);

    /* Call setTimeout without specified time. */
    window.setTimeout(function() { external.reportSuccess(); });
}

function runTest() {
    try {
        runTests();
    }catch(e) {
        ok(false, "got exception " + e.message);
    }
}
</script>
<body onload="runTest();">
<div id="divid"></div>
<select id="sel">
<option>opt1</option>
<option>opt2</option>
</select>
</body>
</html>
  *  4   �� V B T E S T . H T M L       0           <html>
<head>
<script type="text/vbscript">
<!--
Dim counter

counter = 1

Sub ok(b,m)
    Call external.ok(b,m)
End Sub
-->
</script>
<script>
' Verifies that we're in VBScript although there is no type specified
If true then counter = counter+1
function inccounter(x)
    counter = counter+x
end function
</script>
<script type="text/javascript">
// We're in javascript
try {
    counter++;
    incCounter(2);
}catch(e) {
    ok(false, "got an exception " + e.message);
}
</script>
<script>
' And back to VBScript
If true then counter = counter+1

Sub runTest()
    Call ok(counter = 6, "counter = " & counter)
    Call ok(isNull(document.onkeyup), "document.onkeyup is not null")
    Call ok(document.formname.tagName = "FORM", "document.form.tagName = " & document.formname.tagName)
    Call ok(formname.tagName = "FORM", "form.tagName = " & formname.tagName)
    Call external.reportSuccess()
End Sub
</script>
<script type="text/javascript">
// We're in javascript
</script>
<body onload="If true then runTest()">
<form name="formname"></form>
</body>
</html>
  �6  4   �� E V E N T S . H T M L       0           <html>
<head>
<script src="winetest.js" type="text/javascript"></script>
</head>
<head>
<script>
var testevent_divid2_called = false, testevent_document_called = false, cnt=0;

function ondataavailable_test() {
    var evobj, div, b = false;

    div = document.getElementById("divid");

    function ondataavailableHandler() {
        b = true;
        ok(window.event === evobj, "window.event != evobj");

        ok(evobj.srcElement === div, "evobj.srcElement = " + evobj.srcElement);
        ok(evobj.fromElement === null, "evobj.srcElement = " + evobj.fromElement);
        ok(evobj.toElement === null, "evobj.srcElement = " + evobj.toElement);
        ok(evobj.type === "dataavailable", "evobj.type = " + evobj.type);
    }

    function ondataavailableDocHandler() {
        b = true;
        ok(window.event === evobj, "window.event != evobj");

        ok(evobj.srcElement === null, "evobj.srcElement = " + evobj.srcElement);
        ok(evobj.fromElement === null, "evobj.srcElement = " + evobj.fromElement);
        ok(evobj.toElement === null, "evobj.srcElement = " + evobj.toElement);
        ok(evobj.type === "dataavailable", "evobj.type = " + evobj.type);
    }

    div.attachEvent("ondataavailable", ondataavailableHandler);

    evobj = document.createEventObject();
    ok(evobj.srcElement === null, "evobj.srcElement = " + evobj.srcElement);
    ok(evobj.fromElement === null, "evobj.srcElement = " + evobj.fromElement);
    ok(evobj.toElement === null, "evobj.srcElement = " + evobj.toElement);
    ok(evobj.type === "", "evobj.type = " + evobj.type);

    div.fireEvent("ondataavailable", evobj);
    ok(b, "ondataavailable handler not called?");

    ok(evobj.srcElement === div, "evobj.srcElement = " + evobj.srcElement);
    ok(evobj.type === "dataavailable", "evobj.type = " + evobj.type);

    div.detachEvent("ondataavailable", ondataavailableHandler);

    b = false;
    div.fireEvent("ondataavailable", evobj);
    ok(!b, "ondataavailable handler called?");

    ok(evobj.srcElement === div, "evobj.srcElement = " + evobj.srcElement);
    ok(evobj.type === "dataavailable", "evobj.type = " + evobj.type);

    document.attachEvent("ondataavailable", ondataavailableDocHandler);

    evobj = document.createEventObject();

    document.fireEvent("ondataavailable", evobj);
    ok(b, "ondataavailable handler not called?");

    ok(evobj.srcElement === null, "evobj.srcElement = " + evobj.srcElement);
    ok(evobj.type === "dataavailable", "evobj.type = " + evobj.type);
}

function test_scriptfor() {
    var div = document.getElementById("divid2");
    ok("onclick" in div, "testevent not in div");
    ok(typeof(div.onclick) === "function", "typeof(div.onclick) = " + typeof(div.onclick));
    ok(testevent_divid2_called === false, "testevent_divid2_called = " + testevent_divid2_called);
    ok(typeof(document.onclick) === "function", "typeof(document.onclick) = " + typeof(document.onclick));
    ok(testevent_document_called === false, "testevent_document_called = " + testevent_document_called);
    div.click();
    ok(testevent_divid2_called === true, "testevent_divid2_called = " + testevent_divid2_called);
    ok(testevent_document_called === true, "testevent_document_called = " + testevent_document_called);

    ok(!("ontest" in div), "testevent in div");
    ok(typeof(div.ontest) === "undefined", "typeof(div.ontest) = " + typeof(div.ontest));
}

function test_handler_this() {
    document.body.innerHTML = '<div id="d1"><div id="d2"></div></div>';

    var div1 = document.getElementById("d1");
    var div2 = document.getElementById("d2");
    var calls = new Array();

    function createHandler(name, node) {
        return function() {
            ok(this === node, "this !== node");
            calls.push(name);
        }
    }

    function registerHandler(name, target) {
        var b = target.attachEvent("onclick", function(event_arg) {
            ok(this === window, "this !== window");
            calls.push(name+"*");
            with(todo_wine)
            ok(event_arg != window.event, "event_arg == window.event");
        });
        ok(b, "attachEvent failed");
    }

    registerHandler("div1", div1);
    registerHandler("div2", div2);
    registerHandler("body", document.body);
    div1.onclick = createHandler("div1", div1);
    div2.onclick = createHandler("div2", div2);
    document.body.onclick = createHandler("body", document.body);

    div2.click();
    ok(calls == "div2,div2*,div1,div1*,body,body*", "calls = " + calls);
}

function test_insert_script() {
    var e = document.createElement("script");

    extern_cnt = 0;
    e.src = "externscr.js";

    var readystatechange_log = "";
    e.onreadystatechange = function() {
        ok(window.event.srcElement === e, "srcElement != e");
        readystatechange_log += "," + e.readyState;
        ok(extern_cnt === 1, "extern_cnt = " + extern_cnt);
        if(e.readyState === "complete") {
            ok(readystatechange_log === "append,complete", "readystatechange_log = " + readystatechange_log);
            reportSuccess();
        }
    }

    document.body.appendChild(e);
    ok(extern_cnt === 1, "extern_cnt = " + extern_cnt);
    readystatechange_log = "append";
}

var string_handler_called = false;

function test_string_event_handler() {
    var e = document.createElement("div");
    var event_str = "string_handler_called = true;";

    document.body.appendChild(e);
    e.onclick = event_str;
    ok(e.onclick === event_str, "e.onclick = " + e.onclick);
    e.click();
    ok(string_handler_called === false, "string handler called");

    e.setAttribute("onclick", event_str);
    ok(e.onclick === event_str, "e.onclick = " + e.onclick);
    e.click();
    ok(string_handler_called === false, "string handler called");
}

function test_body_events() {
    var f = function() {}, g = function() {};

    document.body.onload = f;
    ok(document.body.onload === f, "body.onload != f");
    ok(window.onload === f, "window.onload != f");

    document.body.onfocus = f;
    ok(document.body.onfocus === f, "body.onfocus != f");
    ok(window.onfocus === f, "window.onfocus != f");
    window.onfocus = g;
    ok(document.body.onfocus === g, "body.onfocus != g");
    ok(window.onfocus === g, "window.onfocus != g");

    var onclick_called = false;
    var onclick_handler = function() { onclick_called = true; };
    document.body.attachEvent("onclick", onclick_handler);
    window.detachEvent("onclick", onclick_handler);
    document.body.click();
    ok(onclick_called, "onclick handler not invoked");
}

function test_event_target() {
    var div = document.createElement("div");
    document.body.appendChild(div);

    var last_event_arg;
    div.attachEvent("onclick", function(event_arg) {
        ok(event_arg.srcElement === div, "srcElement != div");
        last_event_arg = event_arg;
    });

    div.click();
    with(todo_wine)
    ok(last_event_arg.srcElement === null, "srcElement != null");

    document.body.removeChild(div);
}

function test_attach_event() {
    var calls;

    var div = document.createElement("div");
    document.body.appendChild(div);

    function listener() {
        calls += "listener,";
    }

    function listener2() {
        calls += "listener2,";
    }

    /* if the same listener is added twice, it will be called twice */
    div.attachEvent("onclick", listener);
    div.attachEvent("onclick", listener2);
    div.attachEvent("onclick", listener);

    calls = "";
    div.click();
    ok(calls === "listener,listener2,listener,", "calls = " + calls);

    /* remove listener once, it will be called once */
    div.detachEvent("onclick", listener);

    calls = "";
    div.click();
    ok(calls === "listener2,listener,", "calls = " + calls);

    div.detachEvent("onclick", listener);
    div.detachEvent("onclick", listener2);

    calls = "";
    div.click();
    ok(calls === "", "calls = " + calls);

    document.body.removeChild(div);
}

function test_listener_order() {
    if(!("documentMode" in document)) {
        win_skip("Skipping test_listener_order on too old IE");
        return;
    }

    var div = document.createElement("div");
    document.body.appendChild(div);

    var calls;
    function record_call(msg) {
        return function() { calls += msg + "," };
    }

    div.attachEvent("onclick", record_call("click1"));
    div.onclick = record_call("onclick");
    div.attachEvent("onclick", record_call("click2"));
    div.attachEvent("onclick", record_call("click3"));

    calls = "";
    div.click();
    ok(calls === "onclick,click3,click2,click1,", "calls = " + calls);

    document.body.removeChild(div);
}

function test_attach_in_attach() {
    var calls;

    var div = document.createElement("div");
    document.body.appendChild(div);

    /* listener attached inside onevent handler will be invoked in this propagation */
    div.onclick = function () {
        calls += "div.onclick,";
        div.attachEvent("onclick", function() {
            calls += "div.click,";
            /* listener attached inside another attached listener will not be invoked */
            div.attachEvent("onclick", function () { ok(false, "unexpected call"); });
        });
    }

    calls = "";
    div.click();
    ok(calls === "div.onclick,div.click,", "calls = " + calls);

    document.body.removeChild(div);
}

function test_event_obj_props(e) {
    var i, props = [
        "altKey", "button", "cancelBubble", "clientX", "clientY", "ctrlKey", "data", "fromElement", "keyCode", "offsetX", "offsetY",
        "origin", "qualifier", "reason", "returnValue", "screenX", "screenY", "shiftKey", "source", "srcElement", "srcFilter",
        "toElement", "type", "url", "x", "y" ];
    for(i = 0; i < props.length; i++)
        ok(props[i] in e, props[i] + " not in event obj");

    props = [ "imeCompositionChange", "imeNotifyCommand", "imeNotifyData", "imeRequest", "imeRequestData", "issession", "keyboardLayout" ];
    for(i = 0; i < props.length; i++)
        ok(!(props[i] in e), props[i] + " in event obj");
}

window.onload = function() {
    test_event_obj_props(window.event);
    try {
        ok(inlscr_complete_called, "onreadystatechange not fired");
        ok(extern_res_script_rs === "eval,complete1," || extern_res_script_rs == "loaded0,eval,complete1,",
            "extern_res_script_rs = " + extern_res_script_rs + " expected (loaded0)?,eval,complete1,");
        ok(extern_http_script_rs === "loading,loaded,complete," || extern_http_script_rs === "complete,",
            "extern_http_script_rs = " + extern_http_script_rs + " expected loading,loaded,complete, or complete,");

        ok(cnt == 1, "cnt=" + cnt + " exception during loading?");
        ok(this === window, "this !== window");

        ok(typeof(window.onload) === "function", "typeof(window.onload) = " + typeof(window.onload));
        ok(document.body.onload === window.onload, "document.body.onload !== window.onload");

        ok(img_onload_called, "img.onload not called before window.onload");

        test_scriptfor();
        ondataavailable_test();
        test_handler_this();
        test_insert_script();
        test_string_event_handler();
        test_body_events();
        test_event_target();
        test_attach_event();
        test_listener_order();
        test_attach_in_attach();
    }catch(e) {
        ok(false, "Got an exception: " + e.message);
    }
}
</script>
<script>
var img = document.createElement("img");
img.src = "http://test.winehq.org/tests/winehq_snapshot/index_files/winehq_logo_glass.png";

var img_onload_called = false;
img.onload = function() {
    trace("img.onload");
    img_onload_called = true;
}
img.onerror = function() {
    trace("img.onerror");
    img_onload_called = true;
}
</script>
</head>
<body>
<div id="divid"></div>
<div id="divid2"></div>
<script event="onclick" for="divid2">
    testevent_divid2_called = true;
</script>
<script event="onclick" for="document">
    testevent_document_called = true;
</script>
<script event="ontest" for="divid2">
    ok(false, "unexpected ontest");
</script>
<script>
(function() {
    var div = document.getElementById("divid2");
    ok(div.onclick === null, "div.onclick = null");
    cnt++;
})();
</script>
<script>
var inlscr_complete_called = false, extern_res_script_rs = "", extern_http_script_rs = "";
var extern_cnt = 0;

function expect_inlscr_complete() {
    var elem = document.getElementById("inlscr");
    ok(elem.readyState === "complete" || broken(elem.readyState === "loading"), "expect_inlscr_complete: elem.readyState = " + elem.readyState);
    if(elem.readyState === "complete")
        inlscr_complete_called = true;
}

function extern_res_script_readystatechange() {
    var elem = document.getElementById("extscr");
    if(elem.readyState != "loading")
        extern_res_script_rs += elem.readyState + extern_cnt + ",";
    else
        trace("Got loading readyState from external res script.");
}

function http_script_readystatechange() {
    var elem = document.getElementById("httpscr");
    extern_http_script_rs += elem.readyState + ",";
}

function on_externscr() {
    var elem = document.getElementById("extscr");
    ok(elem.readyState === "interactive" || broken(elem.readyState === "loading"),
        "on_externscr: elem.readyState = " + elem.readyState);
    extern_res_script_rs += "eval,";
}

</script>
<script id="inlscr" onreadystatechange="expect_inlscr_complete();">
(function() {
    ok(inlscr_complete_called === false || broken(inlscr_complete_called), "onreadystatechange fired too early");

    var elem = document.getElementById("inlscr");
    ok(elem.readyState === "interactive", "inlscr: elem.readyState = " + elem.readyState);
})();
</script>
<script id="extscr" onreadystatechange="extern_res_script_readystatechange()" src="externscr.js"></script>
<script id="httpscr" onreadystatechange="http_script_readystatechange()" src="https://test.winehq.org/tests/empty.js?123456"></script>
<script>
document.body.appendChild(img);
</script>
</body>
</html>
  �   <   �� R U N S C R I P T . H T M L         0           <!DOCTYPE html>
<html>
  <head>
  </head>
  <script>
    var q = document.location.search.replace("?", "");
    if(q) document.write('<s'+'cript src="' + q + '"></s'+'cript>');
  </script>
  <body>
  </body>
</html>
�  0   �� F R A M E . J S         0           /*
 * Copyright 2017 Jacek Caban for CodeWeavers
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

var global_value = "global value";

var global_object = {
    get_global_value: function() {
        return global_value;
    }
};
?   8   �� E X T E R N S C R . J S         0           extern_cnt++;
if("on_externscr" in window)
    on_externscr();
 �  8   �� N A V I G A T I O N . J S       0           /*
 * Copyright 2016 Jacek Caban for CodeWeavers
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

function nav_parent_test() {
    external.trace("Running _parent navigation tests...");

    var iframe = document.getElementById("testframe");
    var subframe = iframe.contentWindow.document.createElement("iframe");

    subframe.onload = function() {
        var doc = subframe.contentWindow.document;
        doc.body.innerHTML = '<a href="blank2.html" id="aid" target="_parent">test</a>';
        doc.getElementById("aid").click();
    }

    iframe.onload = function() {
        iframe.onload = null;
        var href = iframe.contentWindow.location.href;
	ok(/.*blank2.html/.test(href), "Unexpected href " + href);
	next_test();
    }

    iframe.contentWindow.document.body.appendChild(subframe);
    subframe.src = "blank.html";
}

function window_navigate_test() {
    external.trace("Running window.navigate() tests...");

    var iframe = document.getElementById("testframe");

    iframe.onload = function() {
        iframe.onload = null;
        var href = iframe.contentWindow.location.href;
	ok(href === "about:blank", "Unexpected href " + href);
	next_test();
    }

    iframe.contentWindow.navigate("about:blank");
}

function window_open_self_test() {
    external.trace("Running window.open(_self) tests...");

    var iframe = document.getElementById("testframe");
    var iframe_window = iframe.contentWindow;

    iframe.onload = function() {
        iframe.onload = null;
        var href = iframe.contentWindow.location.href;
        ok(/.*blank.html\?window_open_self/.test(href), "Unexpected href " + href);
        ok(iframe.contentWindow === iframe_window, "iframe.contentWindow !== iframe_window");
	next_test();
    }

    iframe_window.open("blank.html?window_open_self", "_self");
}

function detached_src_test() {
    var iframe = document.createElement("iframe");
    var onload_called = false;

    iframe.onload = function() {
        onload_called = true;
        next_test();
    }

    iframe.src = "blank.html";
    document.body.appendChild(iframe);
    ok(onload_called === false, "called onload too early?");
}

function detached_iframe_doc() {
    document.body.innerHTML = "";

    var iframe = document.createElement("iframe");
    var origDoc;

    function expect_exception(f, is_todo) {
        try {
            f();
            todo_wine_if(is_todo).ok(false, "expected exception");
        } catch(e) {}
    }

    iframe.onload = guard(function() {
        origDoc = iframe.contentWindow.document;
        iframe.onload = guard(function () {
            var doc = iframe.contentWindow.document;

            ok(/.*blank2.html/.test(doc.URL), "Unexpected iframe doc URL " + doc.URL);

            if (doc.documentMode >= 9) {
                try {
                    origDoc != null; // it's not allowed to even compare detached document
                    todo_wine.
                    ok(false, "expected exception");
                } catch(e) {}
            } else {
                todo_wine.
                ok(doc === origDoc, "doc != origDoc");
            }

            expect_exception(function() { origDoc.onclick; }, true);
            expect_exception(function() { origDoc.toString; }, true);
            expect_exception(function() { origDoc.toString(); }, true);
            expect_exception(function() { origDoc.cookie; });
            expect_exception(function() { origDoc.cookie = "test=val"; });
            expect_exception(function() { origDoc.documentElement; });
            expect_exception(function() { origDoc.domain; });
            expect_exception(function() { origDoc.frames; });
            expect_exception(function() { origDoc.location = "blank.html"; });
            expect_exception(function() { origDoc.readyState; }, true);
            expect_exception(function() { origDoc.URL; });
            expect_exception(function() { origDoc.URL = "blank.html"; });
            expect_exception(function() { origDoc.open("blank.html", "_self"); });

            next_test();
        });
        iframe.src = "blank2.html";
    });

    iframe.src = "blank.html";
    document.body.appendChild(iframe);
}

function init_test_iframe() {
    var iframe = document.createElement("iframe");

    iframe.onload = next_test;
    iframe.id = "testframe";
    iframe.src = "about:blank";
    document.body.appendChild(iframe);
}

var tests = [
    init_test_iframe,
    nav_parent_test,
    window_navigate_test,
    window_open_self_test,
    detached_src_test,
    detached_iframe_doc
];
   �D  ,   �� X H R . J S         0           /*
 * Copyright 2016 Jacek Caban for CodeWeavers
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

var tests = [];
var xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<a name=\"test\">wine</a>";

async_test("async_xhr", function() {
    var xhr = new XMLHttpRequest();
    var complete_cnt = 0, loadstart = false;

    xhr.onreadystatechange = function() {
        if(xhr.readyState != 4)
            return;

        ok(xhr.responseText === xml, "unexpected responseText " + xhr.responseText);
        ok(xhr.responseXML !== null, "unexpected null responseXML");

        if(complete_cnt++ && !("onloadend" in xhr))
            next_test();
    }
    xhr.ontimeout = function() { ok(false, "ontimeout called"); }
    var onload_func = xhr.onload = function() {
        ok(xhr.statusText === "OK", "statusText = " + xhr.statusText);
        if("onloadstart" in xhr)
            ok(loadstart, "onloadstart not fired");
        if(complete_cnt++ && !("onloadend" in xhr))
            next_test();
    };
    ok(xhr.onload === onload_func, "xhr.onload != onload_func");
    if("onloadstart" in xhr) {
        xhr.onloadstart = function(e) {
            ok(complete_cnt == 0, "onloadstart fired after onload");
            var props = [ "initProgressEvent", "lengthComputable", "loaded", "total" ];
            for(var i = 0; i < props.length; i++)
                ok(props[i] in e, props[i] + " not available in loadstart");
            ok(e.lengthComputable === false, "lengthComputable in loadstart = " + e.lengthComputable);
            ok(e.loaded === 0, "loaded in loadstart = " + e.loaded);
            ok(e.total === 18446744073709552000, "total in loadstart = " + e.total);
            loadstart = true;
        };
        xhr.onloadend = function(e) {
            ok(complete_cnt == 2, "onloadend not fired after onload and onreadystatechange");
            ok(loadstart, "onloadstart not fired before onloadend");
            var props = [ "initProgressEvent", "lengthComputable", "loaded", "total" ];
            for(var i = 0; i < props.length; i++)
                ok(props[i] in e, props[i] + " not available in loadend");
            ok(e.lengthComputable === true, "lengthComputable in loadend = " + e.lengthComputable);
            ok(e.loaded === xml.length, "loaded in loadend = " + e.loaded);
            ok(e.total === xml.length, "total in loadend = " + e.total);
            next_test();
        };
    }

    xhr.open("POST", "echo.php", true);
    xhr.setRequestHeader("X-Test", "True");
    if("withCredentials" in xhr) {
        ok(xhr.withCredentials === false, "default withCredentials = " + xhr.withCredentials);
        xhr.withCredentials = true;
        ok(xhr.withCredentials === true, "withCredentials = " + xhr.withCredentials);
        xhr.withCredentials = false;
    }
    xhr.send(xml);
});

async_test("sync_xhr", function() {
    var async_xhr, async_xhr2, sync_xhr, sync_xhr_in_async, sync_xhr_nested, a = [ 0 ];
    var async_xhr_clicked = false, doc_dblclicked = false;
    function onmsg(e) { a.push("msg" + e.data); }
    document.ondblclick = function() { doc_dblclicked = true; };
    window.addEventListener("message", onmsg);
    window.postMessage("1", "*");
    window.setTimeout(function() { a.push("timeout"); }, 0);
    window.postMessage("2", "*");
    a.push(1);

    async_xhr = new XMLHttpRequest();
    async_xhr.open("POST", "echo.php", true);
    async_xhr.onreadystatechange = function() {
        if(async_xhr.readyState < 3)
            return;
        a.push("async_xhr(" + async_xhr.readyState + ")");
        ok(async_xhr2.readyState === 1, "async_xhr2.readyState = " + async_xhr2.readyState);
        if(async_xhr.readyState == 4) {
            window.postMessage("_async", "*");

            sync_xhr_in_async = new XMLHttpRequest();
            sync_xhr_in_async.open("POST", "echo.php", false);
            sync_xhr_in_async.onreadystatechange = function() { if(sync_xhr_in_async.readyState == 4) a.push("sync_xhr_in_async"); };
            sync_xhr_in_async.setRequestHeader("X-Test", "True");
            sync_xhr_in_async.send("sync_in_async");
        }
    };
    async_xhr.addEventListener("click", function() { async_xhr_clicked = true; });
    async_xhr.setRequestHeader("X-Test", "True");
    async_xhr.send("1234");
    a.push(2);

    async_xhr2 = new XMLHttpRequest();
    async_xhr2.open("POST", "echo.php?delay_with_signal", true);
    async_xhr2.onreadystatechange = function() {
        if(async_xhr2.readyState < 3)
            return;
        a.push("async_xhr2(" + async_xhr2.readyState + ")");
        ok(async_xhr.readyState === 4, "async_xhr.readyState = " + async_xhr.readyState);
    };
    async_xhr2.setRequestHeader("X-Test", "True");
    async_xhr2.send("foobar");
    a.push(3);

    sync_xhr = new XMLHttpRequest();
    sync_xhr.open("POST", "echo.php?delay_with_signal", false);
    sync_xhr.onreadystatechange = function() {
        a.push("sync_xhr(" + sync_xhr.readyState + ")");
        ok(async_xhr.readyState === 1, "async_xhr.readyState in sync_xhr handler = " + async_xhr.readyState);
        ok(async_xhr2.readyState === 1, "async_xhr2.readyState in sync_xhr handler = " + async_xhr2.readyState);
        if(sync_xhr.readyState < 4)
            return;
        window.setTimeout(function() { a.push("timeout_sync"); }, 0);
        window.postMessage("_sync", "*");

        sync_xhr_nested = new XMLHttpRequest();
        sync_xhr_nested.open("POST", "echo.php", false);
        sync_xhr_nested.onreadystatechange = function() {
            a.push("nested(" + sync_xhr_nested.readyState + ")");
            if(sync_xhr_nested.readyState == 4) {
                window.setTimeout(function() { a.push("timeout_nested"); }, 0);
                window.postMessage("_nested", "*");

                var e = document.createEvent("Event");
                e.initEvent("click", true, false);
                ok(async_xhr_clicked === false, "async_xhr click fired before dispatch");
                async_xhr.dispatchEvent(e);
                ok(async_xhr_clicked === true, "async_xhr click not fired immediately");
                if(document.fireEvent) {
                    ok(doc_dblclicked === false, "document dblclick fired before dispatch");
                    document.fireEvent("ondblclick", document.createEventObject());
                    ok(doc_dblclicked === true, "document dblclick not fired immediately");
                }
            }
        };
        sync_xhr_nested.setRequestHeader("X-Test", "True");
        sync_xhr_nested.send("nested");
    };
    sync_xhr.setRequestHeader("X-Test", "True");
    sync_xhr.send("abcd");
    a.push(4);

    window.setTimeout(function() {
        var r = a.join(",");
        ok(r === "0,1,2,3," + (document.documentMode < 10 ? "sync_xhr(1),sync_xhr(2),sync_xhr(3)," : "") +
                 "sync_xhr(4)," + (document.documentMode < 10 ? "nested(1),nested(2),nested(3)," : "") +
                 "nested(4),4,async_xhr(3),async_xhr(4),sync_xhr_in_async,async_xhr2(3),async_xhr2(4)," +
                 "msg1,msg2,msg_sync,msg_nested,msg_async,timeout,timeout_sync,timeout_nested",
           "unexpected order: " + r);
        window.removeEventListener("message", onmsg);
        document.ondblclick = null;
        a = [ 0 ];

        // Events dispatched to other iframes are not blocked by a send() in another context,
        // except for async XHR events (which are a special case again), messages, and timeouts.
        var iframe = document.createElement("iframe"), iframe2 = document.createElement("iframe");
        iframe.onload = function() {
            iframe2.onload = function() {
                function onmsg(e) {
                    a.push(e.data);
                    if(e.data === "echo")
                        iframe2.contentWindow.postMessage("sync_xhr", "*");
                };

                window.setTimeout(function() {
                    var r = a.join(",");
                    ok(r === "0,1,async_xhr,echo,sync_xhr(pre-send),sync_xhr(DONE),sync_xhr,async_xhr(DONE)",
                       "[iframes 1] unexpected order: " + r);
                    a = [ 0 ];

                    window.setTimeout(function() {
                        var r = a.join(",");
                        ok(r === "0,1,echo,blank(DONE),sync_xhr(pre-send),sync_xhr(DONE),sync_xhr",
                           "[iframes 2] unexpected order: " + r);
                        window.removeEventListener("message", onmsg);
                        next_test();
                    }, 0);

                    iframe.onload = function() { a.push("blank(DONE)"); };
                    iframe.src = "blank.html?delay_with_signal";
                    iframe2.contentWindow.postMessage("echo", "*");
                    a.push(1);
                }, 0);

                window.addEventListener("message", onmsg);
                iframe.contentWindow.postMessage("async_xhr", "*");
                iframe2.contentWindow.postMessage("echo", "*");
                a.push(1);
            };
            iframe2.src = "xhr_iframe.html";
            document.body.appendChild(iframe2);
        };
        iframe.src = "xhr_iframe.html";
        document.body.appendChild(iframe);
    }, 0);
});

async_test("content_types", function() {
    var xhr = new XMLHttpRequest(), types, i = 0, override = false;
    var v = document.documentMode;

    var types = [
        "",
        "text/plain",
        "text/html",
        "wine/xml",
        "xml"
    ];
    var xml_types = [
        "text/xmL",
        "apPliCation/xml",
        "image/SvG+xml",
        "Wine/Test+xml",
        "++Xml",
        "+xMl"
    ];

    function onload() {
        ok(xhr.responseText === xml, "unexpected responseText " + xhr.responseText);
        if(v < 10 || types === xml_types)
            ok(xhr.responseXML !== null, "unexpected null responseXML for " + types[i]);
        else
            ok(xhr.responseXML === null, "unexpected non-null responseXML for " + (override ? "overridden " : "") + types[i]);

        if(("overrideMimeType" in xhr) && !override) {
            override = true;
            xhr = new XMLHttpRequest();
            xhr.onload = onload;
            xhr.open("POST", "echo.php", true);
            xhr.setRequestHeader("X-Test", "True");
            xhr.overrideMimeType(types[i]);
            xhr.send(xml);
            return;
        }
        override = false;

        if(++i >= types.length) {
            if(types === xml_types) {
                next_test();
                return;
            }
            types = xml_types;
            i = 0;
        }
        xhr = new XMLHttpRequest();
        xhr.onload = onload;
        xhr.open("POST", "echo.php?content-type=" + types[i], true);
        xhr.setRequestHeader("X-Test", "True");
        xhr.send(xml);
    }

    xhr.onload = onload;
    xhr.open("POST", "echo.php?content-type=" + types[i], true);
    xhr.setRequestHeader("X-Test", "True");
    xhr.send(xml);
});

async_test("abort", function() {
    var xhr = new XMLHttpRequest();
    if(!("onabort" in xhr)) { next_test(); return; }

    xhr.onreadystatechange = function() {
        if(xhr.readyState != 4)
            return;
        todo_wine_if(v < 10).
        ok(v >= 10, "onreadystatechange called");
    }
    xhr.onload = function() { ok(false, "onload called"); }
    xhr.onabort = function(e) { next_test(); }

    xhr.open("POST", "echo.php?delay", true);
    xhr.setRequestHeader("X-Test", "True");
    xhr.send("Abort Test");
    xhr.abort();
});

async_test("timeout", function() {
    var xhr = new XMLHttpRequest();
    var v = document.documentMode;

    xhr.onreadystatechange = function() {
        if(xhr.readyState != 4)
            return;
        todo_wine_if(v < 10).
        ok(v >= 10, "onreadystatechange called");
    }
    xhr.onload = function() { ok(false, "onload called"); }
    xhr.ontimeout = function(e) {
        var r = Object.prototype.toString.call(e);
        ok(r === ("[object " + (v < 10 ? "Event" : "ProgressEvent") + "]"), "Object.toString = " + r);
        var props = [ "initProgressEvent", "lengthComputable", "loaded", "total" ];
        for(r = 0; r < props.length; r++) {
            if(v < 10)
                ok(!(props[r] in e), props[r] + " is available");
            else
                ok(props[r] in e, props[r] + " not available");
        }
        if(v >= 10) {
            ok(e.lengthComputable === false, "lengthComputable = " + e.lengthComputable);
            ok(e.loaded === 0, "loaded = " + e.loaded);
            ok(e.total === 18446744073709552000, "total = " + e.total);

            e.initProgressEvent("timeout", false, false, true, 13, 42);
            ok(e.lengthComputable === false, "lengthComputable after initProgressEvent = " + e.lengthComputable);
            ok(e.loaded === 0, "loaded after initProgressEvent = " + e.loaded);
            ok(e.total === 18446744073709552000, "total after initProgressEvent = " + e.total);
        }
        next_test();
    }

    xhr.open("POST", "echo.php?delay", true);
    xhr.setRequestHeader("X-Test", "True");
    xhr.timeout = 10;
    xhr.send("Timeout Test");
});

async_test("responseType", function() {
    var i, xhr = new XMLHttpRequest();
    if(!("responseType" in xhr)) { next_test(); return; }

    ok(xhr.responseType === "", "default responseType = " + xhr.responseType);
    try {
        xhr.responseType = "";
        ok(false, "setting responseType before open() did not throw exception");
    }catch(ex) {
        todo_wine.
        ok(ex.name === "InvalidStateError", "setting responseType before open() threw " + ex.name);
    }
    try {
        xhr.responseType = "invalid response type";
        ok(false, "setting invalid responseType before open() did not throw exception");
    }catch(ex) {
        todo_wine.
        ok(ex.name === "InvalidStateError", "setting invalid responseType before open() threw " + ex.name);
    }

    xhr.open("POST", "echo.php", true);
    xhr.setRequestHeader("X-Test", "True");
    ok(xhr.responseType === "", "default responseType after open() = " + xhr.responseType);

    var types = [ "text", "", "document", "arraybuffer", "blob", "ms-stream" ];
    for(i = 0; i < types.length; i++) {
        xhr.responseType = types[i];
        ok(xhr.responseType === types[i], "responseType = " + xhr.responseType + ", expected " + types[i]);
    }

    types = [ "json", "teXt", "Document", "moz-chunked-text", "moz-blob", null ];
    for(i = 0; i < types.length; i++) {
        xhr.responseType = types[i];
        ok(xhr.responseType === "ms-stream", "responseType (after set to " + types[i] + ") = " + xhr.responseType);
    }

    xhr.responseType = "";
    xhr.onreadystatechange = function() {
        if(xhr.readyState < 3) {
            xhr.responseType = "";
            return;
        }
        try {
            xhr.responseType = "";
            ok(false, "setting responseType with state " + xhr.readyState + " did not throw exception");
        }catch(ex) {
            todo_wine.
            ok(ex.name === "InvalidStateError", "setting responseType with state " + xhr.readyState + " threw " + ex.name);
        }
    }
    xhr.onloadend = function() { next_test(); }
    xhr.send("responseType test");
});

async_test("response", function() {
    var xhr = new XMLHttpRequest(), i = 0;
    if(!("response" in xhr)) { next_test(); return; }

    var types = [
        [ "text", "application/octet-stream", function() {
            if(xhr.readyState < 3)
                ok(xhr.response === "", "response for text with state " + state + " = " + xhr.response);
            else if(xhr.readyState === 4)
                ok(xhr.response === xml, "response for text = " + xhr.response);
        }],
        [ "arraybuffer", "image/png", function() {
            if(xhr.readyState < 4)
                ok(xhr.response === undefined, "response for arraybuffer with state " + state + " = " + xhr.response);
        }],
        [ "blob", "wine/test", function() {
            if(xhr.readyState < 4)
                ok(xhr.response === undefined, "response for blob with state " + state + " = " + xhr.response);
        }]
    ];

    function onreadystatechange() {
        types[i][2]();
        if(xhr.readyState < 4)
            return;
        if(++i >= types.length) {
            next_test();
            return;
        }
        xhr = new XMLHttpRequest();
        xhr.open("POST", "echo.php?content-type=" + types[i][1], true);
        xhr.onreadystatechange = onreadystatechange;
        xhr.setRequestHeader("X-Test", "True");
        xhr.responseType = types[i][0];
        xhr.send(xml);
    }

    xhr.open("POST", "echo.php?content-type=" + types[i][1], true);
    xhr.onreadystatechange = onreadystatechange;
    xhr.setRequestHeader("X-Test", "True");
    xhr.responseType = types[i][0];
    xhr.send(xml);
});
j�  ,   �� D O M . J S         0           /*
 * Copyright 2017 Jacek Caban for CodeWeavers
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

var tests = [];

sync_test("url", function() {
    ok(document.URL === "http://winetest.example.org/index.html?dom.js", "document.URL = " + document.URL);
    ok(!("documentURI" in document), "documentURI in document");
});

sync_test("input_selection", function() {
    var input = document.createElement("input");
    input.type = "text";
    input.value = "test";
    document.body.appendChild(input);

    function test_range(start, end) {
        ok(input.selectionStart === start, "input.selectionStart = " + input.selectionStart + " expected " + start);
        ok(input.selectionEnd === end, "input.selectionEnd = " + input.selectionEnd + " expected " + end);
    }

    test_range(0, 0);

    input.selectionStart = 2;
    test_range(2, 2);

    input.selectionStart = -1;
    test_range(0, 2);

    input.selectionStart = 10;
    test_range(4, 4);

    input.selectionEnd = 2;
    test_range(2, 2);

    input.selectionEnd = -1;
    test_range(0, 0);

    input.selectionEnd = 10;
    test_range(0, 4);

    input.setSelectionRange(2, 3);
    test_range(2, 3);

    input.setSelectionRange(-1, 10);
    test_range(0, 4);

    input.setSelectionRange(3, 3);
    test_range(3, 3);
});

sync_test("textContent", function() {
    var text = document.createTextNode("test");
    ok(text.textContent === "test", "text.textContent = " + text.textContent);

    var div = document.createElement("div");
    document.body.appendChild(div);
    div.innerHTML = "abc<script>/* */</script><div>text</div>";
    ok(div.textContent === "abc/* */text", "div.textContent = " + div.textContent);

    div.textContent = "test";
    ok(div.textContent === "test", "div.textContent = " + div.textContent);
    ok(div.childNodes.length === 1, "div.childNodes.length = " + div.childNodes.length);
    ok(div.firstChild.textContent === "test", "div.firstChild.textContent = " + div.firstChild.textContent);

    div.textContent = "";
    ok(div.textContent === "", "div.textContent = " + div.textContent);
    ok(div.childNodes.length === 0, "div.childNodes.length = " + div.childNodes.length);

    div.textContent = null;
    ok(div.textContent === "", "div.textContent = " + div.textContent);
    div.textContent = 11;
    ok(div.textContent === "11", "div.textContent = " + div.textContent);
    div.textContent = 10.5;
    ok(div.textContent === "10.5", "div.textContent = " + div.textContent);

    ok(document.textContent === null, "document.textContent = " + document.textContent);
});

sync_test("ElementTraversal", function() {
    var div = document.createElement("div");
    div.innerHTML = "abc<b>bold</b><script>/* */</script><div>text</div>def";
    ok(div.childElementCount === 3, "div.childElementCount = " + div.childElementCount);
    ok(div.firstElementChild.outerHTML === "<b>bold</b>",
            "div.firstElementChild.outerHTML = " + div.firstElementChild.outerHTML);
    ok(div.lastElementChild.outerHTML === "<div>text</div>",
            "div.lastElementChild.outerHTML = " + div.lastElementChild.outerHTML);
    ok(div.firstElementChild.nextElementSibling.outerHTML === "<script>/* */</script>",
            "div.firstElementChild.nextElementSibling.outerHTML = " + div.firstElementChild.nextElementSibling.outerHTML);
    ok(div.lastElementChild.nextElementSibling === null,
            "div.lastElementChild.nextElementSibling = " + div.lastElementChild.nextElementSibling);
    ok(div.lastElementChild.previousElementSibling.outerHTML === "<script>/* */</script>",
            "div.lastElementChild.previousElementSibling.outerHTML = " + div.lastElementChild.previousElementSibling.outerHTML);
    ok(div.firstElementChild.previousElementSibling === null,
            "div.firstElementChild.previousElementSibling = " + div.firstElementChild.previousElementSibling);

    div.innerHTML = "abc";
    ok(div.childElementCount === 0, "div.childElementCount = " + div.childElementCount);
    ok(div.firstElementChild === null, "div.firstElementChild = " + div.firstElementChild);
    ok(div.lastElementChild === null, "div.lastElementChild = " + div.lastElementChild);

    ok(!("childElementCount" in document), "childElementCount found in document");
    ok(!("firstElementChild" in document), "firstElementChild found in document");
    ok(!("nextElementSibling" in document), "nextElementSibling found in document");
});

sync_test("head", function() {
    var h = document.head;
    ok(h.tagName === "HEAD", "h.tagName = " + h.tagName);
    ok(h === document.getElementsByTagName("head")[0], "unexpected head element");
});

async_test("iframe", function() {
    document.body.innerHTML = '<iframe src="runscript.html?frame.js"></iframe>'
    var iframe = document.body.firstChild;

    iframe.onload = guard(function() {
        var r = iframe.contentWindow.global_object.get_global_value();
        ok(r === "global value", "get_global_value() returned " + r);

        var f = iframe.contentWindow.global_object.get_global_value;
        ok(f() === "global value", "f() returned " + f());

        next_test();
    });
});

async_test("iframe_location", function() {
    document.body.innerHTML = '<iframe src="emptyfile"></iframe>'
    var iframe = document.body.firstChild;

    iframe.onload = function() {
        ok(iframe.contentWindow.location.pathname === "/emptyfile",
           "path = " + iframe.contentWindow.location.pathname);
        iframe.onload = function () {
            ok(iframe.contentWindow.location.pathname === "/empty/file",
               "path = " + iframe.contentWindow.location.pathname);
            next_test();
        }
        iframe.src = "empty/file";
    }
});

sync_test("anchor", function() {
    var anchor_tests = [
        { href: "http://www.winehq.org:123/about",
          protocol: "http:", host: "www.winehq.org:123", path: "/about" },
        { href: "https://www.winehq.org:123/about",
          protocol: "https:", host: "www.winehq.org:123", path: "/about" },
        { href: "about:blank",
          protocol: "about:", host: "", path: "/blank", todo_pathname: 1 },
        { href: "unknown:path",
          protocol: "unknown:", host: "", path: "path" },
        { href: "ftp:path",
          protocol: "ftp:", host: "", path: "path" },
        { href: "mailto:path",
          protocol: "mailto:", host: "", path: "path" },
        { href: "ws:path",
          protocol: "ws:", host: "", path: "path" },
        { href: "file:path",
          protocol: "file:", host: "", path: "/path", todo_pathname: 1 },
        { href: "file:///c:/dir/file.html",
          protocol: "file:", host: "", path: "/c:/dir/file.html" },
        { href: "http://www.winehq.org/about",
          protocol: "http:", host: "www.winehq.org", path: "/about" },
        { href: "https://www.winehq.org/about",
          protocol: "https:", host: "www.winehq.org", path: "/about" },
    ];

    for(var i in anchor_tests) {
        var t = anchor_tests[i];
        document.body.innerHTML = '<a href="' + t.href + '">';
        var anchor = document.body.firstChild;
        ok(anchor.protocol === t.protocol, "anchor(" + t.href + ").protocol = " + anchor.protocol);
        ok(anchor.host === t.host, "anchor(" + t.href + ").host = " + anchor.host);
        todo_wine_if("todo_pathname" in t).
        ok(anchor.pathname === t.path, "anchor(" + t.href + ").pathname = " + anchor.pathname);
    }
});

sync_test("getElementsByClassName", function() {
    var elems;

    document.body.innerHTML = '<div class="class1">'
        + '<div class="class1"></div>'
        + '<a id="class1" class="class2"></a>'
        + '</div>'
        + '<script class="class1"></script>';

    elems = document.getElementsByClassName("class1");
    ok(elems.length === 3, "elems.length = " + elems.length);
    ok(elems[0].tagName === "DIV", "elems[0].tagName = " + elems[0].tagName);
    ok(elems[1].tagName === "DIV", "elems[1].tagName = " + elems[1].tagName);
    ok(elems[2].tagName === "SCRIPT", "elems[2].tagName = " + elems[2].tagName);

    elems = document.getElementsByClassName("class2");
    ok(elems.length === 1, "elems.length = " + elems.length);
    ok(elems[0].tagName === "A", "elems[0].tagName = " + elems[0].tagName);

    elems = document.getElementsByClassName("classnotfound");
    ok(elems.length == 0, "elems.length = " + elems.length);
});

sync_test("createElementNS", function() {
    var svg_ns = "http://www.w3.org/2000/svg";
    var elem;

    elem = document.createElementNS(null, "test");
    ok(elem.tagName === "test", "elem.tagName = " + elem.tagName);
    ok(elem.namespaceURI === null, "elem.namespaceURI = " + elem.namespaceURI);

    elem = document.createElementNS(svg_ns, "test");
    ok(elem.tagName === "test", "elem.tagName = " + elem.tagName);
    ok(elem.namespaceURI === svg_ns, "elem.namespaceURI = " + elem.namespaceURI);

    elem = document.createElementNS(svg_ns, "svg");
    ok(elem.tagName === "svg", "elem.tagName = " + elem.tagName);
    ok(elem.namespaceURI === svg_ns, "elem.namespaceURI = " + elem.namespaceURI);

    elem = document.createElementNS("test", "svg");
    ok(elem.tagName === "svg", "elem.tagName = " + elem.tagName);
    ok(elem.namespaceURI === "test", "elem.namespaceURI = " + elem.namespaceURI);
});

sync_test("query_selector", function() {
    document.body.innerHTML = '<div class="class1">'
        + '<div class="class1"></div>'
        + '<a id="class1" class="class2"></a>'
        + '</div>'
        + '<script class="class1"></script>';

    var frag = document.createDocumentFragment()
    var e = document.createElement("div");
    e.innerHTML = '<div class="class3"></div><a id="class3" class="class4"></a></div>';
    frag.appendChild(e);
    var e = document.createElement("script");
    e.className = "class3";
    frag.appendChild(e);

    e = document.querySelector("nomatch");
    ok(e === null, "e = " + e);
    e = document.body.querySelector("nomatch");
    ok(e === null, "e = " + e);
    e = frag.querySelector("nomatch");
    ok(e === null, "e = " + e);

    e = document.querySelector(".class1");
    ok(e.tagName === "DIV", "e.tagName = " + e.tagName);
    e = document.body.querySelector(".class1");
    ok(e.tagName === "DIV", "e.tagName = " + e.tagName);
    ok(e.msMatchesSelector(".class1") === true, "msMatchesSelector returned " + e.msMatchesSelector(".class1"));
    ok(e.msMatchesSelector(".class2") === false, "msMatchesSelector returned " + e.msMatchesSelector(".class2"));
    e = document.querySelector(".class3");
    ok(e === null, "e = " + e);
    e = document.body.querySelector(".class3");
    ok(e === null, "e = " + e);

    e = frag.querySelector(".class3");
    ok(e.tagName === "DIV", "e.tagName = " + e.tagName);
    e = frag.querySelector(".class4");
    ok(e.tagName === "A", "e.tagName = " + e.tagName);
    e = frag.querySelector(".class1");
    ok(e === null, "e = " + e);
    e = frag.querySelector(".class2");
    ok(e === null, "e = " + e);

    e = document.querySelector("a");
    ok(e.tagName === "A", "e.tagName = " + e.tagName);
    e = document.body.querySelector("a");
    ok(e.tagName === "A", "e.tagName = " + e.tagName);
    e = frag.querySelector("a");
    ok(e.tagName === "A", "e.tagName = " + e.tagName);

    e = document.querySelectorAll(".class1");
    ok(e.length === 3, "e.length = " + e.length);
    e = document.body.querySelectorAll(".class1");
    ok(e.length === 3, "e.length = " + e.length);
    e = document.querySelectorAll(".class2");
    ok(e.length === 1, "e.length = " + e.length);
    e = document.body.querySelectorAll(".class2");
    ok(e.length === 1, "e.length = " + e.length);
    e = frag.querySelectorAll(".class3");
    ok(e.length === 2, "e.length = " + e.length);
    e = frag.querySelectorAll(".class4");
    ok(e.length === 1, "e.length = " + e.length);
});

sync_test("compare_position", function() {
    document.body.innerHTML = '<div><div></div><div></div></div>';

    var parent = document.body.firstChild;
    var child1 = parent.firstChild;
    var child2 = child1.nextSibling;
    var elem = document.createElement("div");

    function compare_position(node1, node2, expected_result, ignore_mask) {
        var cmp = node1.compareDocumentPosition(node2);
        ok((cmp & ~ignore_mask) == expected_result,
           "compareDocumentPosition returned " + cmp + " expected " + expected_result);
    }

    compare_position(child1, child2, 4);
    compare_position(child2, child1, 2);
    compare_position(parent, child1, 0x14);
    compare_position(parent, child2, 0x14);
    compare_position(parent, elem, 0x21, 6);
    compare_position(elem, parent, 0x21, 6);
});

sync_test("rects", function() {
    document.body.innerHTML = '<div>test</div>';
    var elem = document.body.firstChild;
    var rects = elem.getClientRects();
    var rect = elem.getBoundingClientRect();

    ok(rects.length === 1, "rect.length = " + rects.length);
    ok(rects[0].top === rect.top, "rects[0].top = " + rects[0].top + " rect.top = " + rect.top);
    ok(rects[0].bottom === rect.bottom, "rects[0].bottom = " + rects[0].bottom + " rect.bottom = " + rect.bottom);

    ok("" + rects[0] === "[object ClientRect]", "rects[0] = " + rects[0]);
    ok(rects.hasOwnProperty("0"), 'rects.hasOwnProperty("0") = ' + rects.hasOwnProperty("0"));
    todo_wine.
    ok(rects.hasOwnProperty("1"), 'rects.hasOwnProperty("1") = ' + rects.hasOwnProperty("1"));
    var desc = Object.getOwnPropertyDescriptor(rects, "0");
    ok(desc.writable === true, "writable = " + desc.writable);
    todo_wine.
    ok(desc.enumerable === true, "enumerable = " + desc.enumerable);
    ok(desc.configurable === true, "configurable = " + desc.configurable);
    ok("" + desc.value === "[object ClientRect]", "desc.value = " + desc.value);

    ok(rect.height === rect.bottom - rect.top, "rect.height = " + rect.height + " rect.bottom = " + rect.bottom + " rect.top = " + rect.top);
    ok(rect.width === rect.right - rect.left, "rect.width = " + rect.width + " rect.right = " + rect.right + " rect.left = " + rect.left);

    elem = document.createElement("style");
    rects = elem.getClientRects();
    ok(rects.length === 0, "rect.length = " + rects.length);
});

sync_test("document_lastModified", function() {
    // actually it seems to be rounded up from about ~250ms above a sec, but be more conservative with the check
    var diff = Date.parse(document.lastModified) - performance.timing.navigationStart;
    ok(diff > -1000 && diff < 1000, "lastModified too far from navigationStart: " + diff);
});

sync_test("document_owner", function() {
    var node;

    ok(document.ownerDocument === null, "ownerDocument = " + document.ownerDocument);
    ok(document.body.ownerDocument === document,
       "body.ownerDocument = " + document.body.ownerDocument);
    ok(document.documentElement.ownerDocument === document,
       "documentElement.ownerDocument = " + document.documentElement.ownerDocument);

    node = document.createElement("test");
    ok(node.ownerDocument === document, "element.ownerDocument = " + node.ownerDocument);

    node = document.createDocumentFragment();
    ok(node.ownerDocument === document, "fragment.ownerDocument = " + node.ownerDocument);

    node = document.createTextNode("test");
    ok(node.ownerDocument === document, "text.ownerDocument = " + node.ownerDocument);
});

sync_test("style_properties", function() {
    document.body.innerHTML = '<div>test</div><svg></svg>';
    var elem = document.body.firstChild;
    var style = elem.style;
    var current_style = elem.currentStyle;
    var computed_style = window.getComputedStyle(elem);
    var val;

    style.cssFloat = "left";
    ok(style.cssFloat === "left", "cssFloat = " + style.cssFloat);
    ok(style.getPropertyValue("float") === "left",
       'style.getPropertyValue("float") = ' + style.getPropertyValue("float"));
    ok(style.getPropertyValue("cssFloat") === "",
       'style.getPropertyValue("cssFloat") = ' + style.getPropertyValue("cssFloat"));

    val = style.removeProperty("float");
    ok(val === "left", "removeProperty() returned " + val);
    ok(style.cssFloat === "", "cssFloat = " + style.cssFloat);

    style.cssFloat = "left";
    val = style.removeProperty("FloaT");
    ok(val === "left", "removeProperty() returned " + val);
    ok(style.cssFloat === "", "cssFloat = " + style.cssFloat);

    style.cssFloat = "left";
    val = style.removeProperty("cssFloat");
    ok(val === "", "removeProperty() returned " + val);
    ok(style.cssFloat === "left", "cssFloat = " + style.cssFloat);
    ok(style["float"] === "left", "float = " + style["float"]);

    style.testVal = "test";
    val = style.removeProperty("testVal");
    ok(val === "", "removeProperty() returned " + val);
    ok(style.testVal === "test", "testVal = " + style.testVal);

    val = style.getPropertyValue("testVal");
    ok(val === "", 'style.getPropertyValue("testVal") = ' + val);
    ok(style.testVal === "test", "testVal = " + style.testVal);

    style.setProperty("testVal", "1px");
    val = style.getPropertyValue("testVal");
    ok(val === "", 'style.getPropertyValue("testVal") = ' + val);
    ok(style.testVal === "test", "testVal = " + style.testVal);

    style.setProperty("test", "1px");
    val = style.getPropertyValue("test");
    ok(val === "", 'style.getPropertyValue("test") = ' + val);
    ok(!("test" in style), "test in style");

    style["z-index"] = 1;
    ok(style.zIndex === 1, "zIndex = " + style.zIndex);
    ok(style["z-index"] === 1, "z-index = " + style["z-index"]);
    ok(style.getPropertyValue("z-index") === "1",
       'style.getPropertyValue("x-index") = ' + style.getPropertyValue("z-index"));
    ok(style.getPropertyValue("zIndex") === "",
       'style.getPropertyValue("xIndex") = ' + style.getPropertyValue("zIndex"));

    style.setProperty("border-width", "5px");
    ok(style.borderWidth === "5px", "style.borderWidth = " + style.borderWidth);

    try {
        style.setProperty("border-width", 6);
        ok(style.borderWidth === "5px", "style.borderWidth = " + style.borderWidth);
    }catch(e) {
        win_skip("skipping setProperty tests on too old IE version");
        return;
    }

    style.setProperty("border-width", "7px", "test");
    ok(style.borderWidth === "5px", "style.borderWidth = " + style.borderWidth);

    style.setProperty("border-width", "6px", "");
    ok(style.borderWidth === "6px", "style.borderWidth = " + style.borderWidth);

    style.setProperty("border-width", "7px", "important");
    ok(style.borderWidth === "7px", "style.borderWidth = " + style.borderWidth);

    style.setProperty("border-width", "8px", undefined);
    ok(style.borderWidth === "7px", "style.borderWidth = " + style.borderWidth);

    style.clip = "rect(1px 1px 10px 10px)";
    ok(style.clip === "rect(1px, 1px, 10px, 10px)", "style.clip = " + style.clip);
    ok(current_style.clip === "rect(1px, 1px, 10px, 10px)",
       "current_style.clip = " + current_style.clip);
    ok(computed_style.clip === "rect(1px, 1px, 10px, 10px)",
       "computed_style.clip = " + current_style.clip);

    style.zIndex = 2;
    ok(current_style.zIndex === 2, "current_style.zIndex = " + current_style.zIndex);
    ok(computed_style.zIndex === 2, "computed_style.zIndex = " + computed_style.zIndex);

    try {
        current_style.zIndex = 1;
        ok(false, "expected exception");
    }catch(e) {}

    try {
        computed_style.zIndex = 1;
        ok(false, "expected exception");
    }catch(e) {}

    elem = elem.nextSibling;
    computed_style = window.getComputedStyle(elem);

    elem.style.zIndex = 4;
    ok(computed_style.zIndex === 4, "computed_style.zIndex = " + computed_style.zIndex);

    window.getComputedStyle(elem, null);

    /* ms* prefixed styles alias */
    var list = [
        [ "transform", "translate(5px, 5px)" ],
        [ "transition", "background-color 0.5s linear 0.1s" ]
    ];
    for(var i = 0; i < list.length; i++) {
        var s = list[i][0], v = list[i][1], ms = "ms" + s[0].toUpperCase() + s.substring(1);
        style[s] = v;
        ok(style[s] === v, "style." + s + " = " + style[s] + ", expected " + v);
        ok(style[ms] === v, "style." + ms + " = " + style[ms] + ", expected " + v);
        elem.style[ms] = v;
        ok(elem.style[s] === v, "elem.style." + s + " = " + elem.style[s] + ", expected " + v);
        ok(elem.style[ms] === v, "elem.style." + ms + " = " + elem.style[ms] + ", expected " + v);
    }
});

sync_test("stylesheets", function() {
    document.body.innerHTML = '<style>.div { margin-right: 1px; }</style>';
    var elem = document.body.firstChild;

    ok(document.styleSheets.length === 1, "document.styleSheets.length = " + document.styleSheets.length);

    var stylesheet = document.styleSheets.item(0);
    ok(stylesheet.rules.length === 1, "stylesheet.rules.length = " + stylesheet.rules.length);
    ok(typeof(stylesheet.rules.item(0)) === "object",
       "typeof(stylesheet.rules.item(0)) = " + typeof(stylesheet.rules.item(0)));

    stylesheet = document.styleSheets[0];
    ok(stylesheet.rules.length === 1, "document.styleSheets[0].rules.length = " + stylesheet.rules.length);

    try {
        stylesheet.rules.item(1);
        ok(false, "expected exception");
    }catch(e) {}

    ok(stylesheet.href === null, "stylesheet.href = " + stylesheet.href);

    var id = stylesheet.insertRule(".input { margin-left: 1px; }", 0);
    ok(id === 0, "id = " + id);
    ok(document.styleSheets.length === 1, "document.styleSheets.length = " + document.styleSheets.length);

    try {
        stylesheet.insertRule(".input { margin-left: 1px; }", 3);
        ok(false, "expected exception");
    }catch(e) {}

    id = stylesheet.addRule(".p", "margin-top: 2px");
    ok(id === 2, "id = " + id);
    ok(document.styleSheets.length === 1, "document.styleSheets.length = " + document.styleSheets.length);
    ok(stylesheet.rules.length === 3, "stylesheet.rules.length = " + stylesheet.rules.length);

    id = stylesheet.addRule(".pre", "border: none", -1);
    ok(id === 3, "id = " + id);
    ok(stylesheet.rules.length === 4, "stylesheet.rules.length = " + stylesheet.rules.length);

    id = stylesheet.addRule(".h1", " ", 0);
    ok(id === 0, "id = " + id);
    ok(stylesheet.rules.length === 5, "stylesheet.rules.length = " + stylesheet.rules.length);

    id = stylesheet.addRule(".h2", "color: black", 8);
    ok(id === 5, "id = " + id);
    ok(stylesheet.rules.length === 6, "stylesheet.rules.length = " + stylesheet.rules.length);

    try {
        stylesheet.addRule("", "border: none", 0);
        ok(false, "expected exception");
    }catch(e) {}
    try {
        stylesheet.addRule(".img", "", 0);
        ok(false, "expected exception");
    }catch(e) {}
});

sync_test("storage", function() {
    ok(typeof(window.sessionStorage) === "object",
       "typeof(window.sessionStorage) = " + typeof(window.sessionStorage));
    ok(typeof(window.localStorage) === "object" || typeof(window.localStorage) === "unknown",
       "typeof(window.localStorage) = " + typeof(window.localStorage));

    var item = sessionStorage.getItem("nonexisting");
    ok(item === null, "'nonexisting' item = " + item);
    item = sessionStorage["nonexisting"];
    ok(item === undefined, "[nonexisting] item = " + item);
    ok(!("nonexisting" in sessionStorage), "nonexisting in sessionStorage");

    sessionStorage.setItem("foobar", 42);
    ok("foobar" in sessionStorage, "foobar not in sessionStorage");
    ok(sessionStorage.hasOwnProperty("foobar"), "foobar not prop of sessionStorage");
    item = sessionStorage.getItem("foobar");
    ok(item === "42", "'foobar' item = " + item);
    item = sessionStorage["foobar"];
    ok(item === "42", "[foobar] item = " + item);
    sessionStorage.removeItem("foobar");
    item = sessionStorage["foobar"];
    ok(item === undefined, "[foobar] item after removal = " + item);

    sessionStorage["barfoo"] = true;
    ok("barfoo" in sessionStorage, "barfoo not in sessionStorage");
    ok(sessionStorage.hasOwnProperty("barfoo"), "barfoo not prop of sessionStorage");
    item = sessionStorage["barfoo"];
    ok(item === "true", "[barfoo] item = " + item);
    item = sessionStorage.getItem("barfoo");
    ok(item === "true", "'barfoo' item = " + item);
});

async_test("animation", function() {
    document.body.innerHTML =
        "<style>" +
        "  @keyframes testAnimation {0% { opacity: 0; } 100% { opacity: 1; }}" +
        "  .testAnimation { animation-name: testAnimation; animation-duration: 0.01s; }" +
        "</style>";
    var div = document.createElement("div");
    div.addEventListener("animationstart", function() {
        div.addEventListener("animationend", next_test);
    });
    document.body.appendChild(div);
    div.className = "testAnimation";
});

sync_test("navigator", function() {
    ok(typeof(window.navigator) === "object",
       "typeof(window.navigator) = " + typeof(window.navigator));

    var v = window.navigator;
    ok(v === window.navigator, "v != window.navigator");
    v.testProp = true;
    ok(window.navigator.testProp, "window.navigator.testProp = " + window.navigator.testProp);
});

sync_test("elem_props", function() {
    var elem = document.body;

    ok(elem.accessKey === "", "accessKey = " + elem.accessKey);
    elem.accessKey = "q";
    ok(elem.accessKey === "q", "accessKey = " + elem.accessKey + " expected q");
});

async_test("animation_frame", function() {
    var id = requestAnimationFrame(function(x) { ok(false, "request was supposed to be cancelled"); });
    id = cancelAnimationFrame(id);
    ok(id === undefined, "cancelAnimationFrame returned " + id);

    id = requestAnimationFrame(function(x) {
        ok(this === window, "this != window");
        ok(typeof(x) === "number", "x = " + x);
        ok(arguments.length === 1, "arguments.length = " + arguments.length);
        next_test();
    });
    cancelAnimationFrame(0);
    clearInterval(id);
    clearTimeout(id);
    ok(typeof(id) === "number", "id = " + id);
    ok(id !== 0, "id = 0");
});

sync_test("title", function() {
    var elem = document.createElement("div");
    ok(elem.title === "", "div.title = " + elem.title);
    ok(elem.getAttribute("title") === null, "title attribute = " + elem.getAttribute("title"));
    elem.title = "test";
    ok(elem.title === "test", "div.title = " + elem.title);
    ok(elem.getAttribute("title") === "test", "title attribute = " + elem.getAttribute("title"));

    var orig = document.title;
    document.title = "w i n e test";
    var title = document.getElementsByTagName("title")[0];
    ok(title.text === "w i n e test", "<title> element text = " + title.text);
    title.text = "winetest";
    ok(title.text === "winetest", "<title> element text after change = " + title.text);
    ok(document.title === "winetest", "document.title after <title> change = " + document.title);

    elem = document.createElement("title");
    ok(elem.text === "", "detached <title> element text = " + elem.text);
    elem.text = "foobar";
    ok(elem.text === "foobar", "detached <title> element text after change = " + elem.text);
    ok(document.title === "winetest", "document.title after detached <title> change = " + document.title);

    title.parentNode.replaceChild(elem, title);
    ok(document.title === "foobar", "document.title after <title> replaced = " + document.title);
    document.title = orig;
});

sync_test("disabled", function() {
    var elem = document.createElement("div");
    document.body.appendChild(elem);
    ok(elem.disabled === false, "div.disabled = " + elem.disabled);
    ok(elem.getAttribute("disabled") === null, "disabled attribute = " + elem.getAttribute("disabled") + " expected null");

    elem.disabled = true;
    ok(elem.disabled === true, "div.disabled = " + elem.disabled);
    ok(elem.getAttribute("disabled") === "", "disabled attribute = " + elem.getAttribute("disabled") + " expected \"\"");

    elem.disabled = false;
    ok(elem.disabled === false, "div.disabled = " + elem.disabled);
    ok(elem.getAttribute("disabled") === null, "disabled attribute = " + elem.getAttribute("disabled") + " expected null");

    elem.setAttribute("disabled", "false");
    ok(elem.disabled === true, "div.disabled = " + elem.disabled);
    ok(elem.getAttribute("disabled") === "false", "disabled attribute = " + elem.getAttribute("disabled"));

    elem.removeAttribute("disabled");
    ok(elem.disabled === false, "div.disabled = " + elem.disabled);
    ok(elem.getAttribute("disabled") === null, "disabled attribute = " + elem.getAttribute("disabled") + " expected null");
});

sync_test("hasAttribute", function() {
    document.body.innerHTML = '<div attr="test"></div>';
    var elem = document.body.firstChild, r;

    r = elem.hasAttribute("attr");
    ok(r === true, "hasAttribute(attr) returned " + r);
    r = elem.hasAttribute("attr2");
    ok(r === false, "hasAttribute(attr2) returned " + r);

    elem.setAttribute("attr2", "abc");
    r = elem.hasAttribute("attr2");
    ok(r === true, "hasAttribute(attr2) returned " + r);

    elem.removeAttribute("attr");
    r = elem.hasAttribute("attr");
    ok(r === false, "hasAttribute(attr) returned " + r);
});

sync_test("classList", function() {
    var elem = document.createElement("div");
    var classList = elem.classList, i, r;

    var props = [ "add", "contains", "item", "length", "remove", "toggle" ];
    for(i = 0; i < props.length; i++)
        ok(props[i] in classList, props[i] + " not found in classList.");

    props = [ "entries", "forEach", "keys", "replace", "supports", "value", "values"];
    for(i = 0; i < props.length; i++)
        ok(!(props[i] in classList), props[i] + " found in classList.");

    classList.add("a");
    ok(elem.className === "a", "Expected className 'a', got " + elem.className);
    ok(classList.length === 1, "Expected length 1 for className 'a', got " + classList.length);

    classList.add("b");
    ok(elem.className === "a b", "Expected className 'a b', got " + elem.className);
    ok(classList.length === 2, "Expected length 2 for className 'a b', got " + classList.length);

    classList.add("c");
    ok(elem.className === "a b c", "Expected className 'a b c', got " + elem.className);
    ok(classList.length === 3, "Expected length 3 for className 'a b c', got " + classList.length);

    classList.add(4);
    ok(elem.className === "a b c 4", "Expected className 'a b c 4', got " + elem.className);
    ok(classList.length === 4, "Expected length 4 for className 'a b c 4', got " + classList.length);

    classList.add("c");
    ok(elem.className === "a b c 4", "(2) Expected className 'a b c 4', got " + elem.className);
    ok(("" + classList) === "a b c 4", "Expected classList value 'a b c 4', got " + classList);
    ok(classList.toString() === "a b c 4", "Expected classList toString 'a b c 4', got " + classList.toString());

    var exception = false

    try
    {
        classList.add();
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception && elem.className === "a b c 4", "Expected exception, className 'a b c 4', got exception "
            + exception + ", className" + elem.className);

    exception = false
    try
    {
        classList.add("");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.add(\"\")");

    exception = false
    try
    {
        classList.add("e f");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.add(\"e f\")");

    exception = false;
    try
    {
        classList.contains();
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.contains()");

    exception = false;
    try
    {
        classList.contains("");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.contains(\"\")");

    exception = false;
    try
    {
        classList.contains("a b");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.contains(\"a b\")");

    ok(classList.contains("4") === true, "contains: expected '4' to return true");
    ok(classList.contains("b") === true, "contains: expected 'b' to return true");
    ok(classList.contains("d") === false, "contains: expected 'd' to return false");

    r = classList.item(-1);
    ok(r === null, "item(-1) = " + r);
    r = classList.item(0);
    ok(r === "a", "item(0) = " + r);
    r = classList.item(1);
    ok(r === "b", "item(1) = " + r);
    r = classList.item(2);
    ok(r === "c", "item(2) = " + r);
    r = classList.item(3);
    ok(r === "4", "item(3) = " + r);
    r = classList.item(4);
    ok(r === null, "item(4) = " + r);

    classList.remove("e");
    ok(elem.className === "a b c 4", "remove: expected className 'a b c 4', got " + elem.className);

    exception = false
    try
    {
        classList.remove("e f");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "remove: expected exception for classList.remove(\"e f\")");

    exception = false
    try
    {
        classList.remove("");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "remove: expected exception for classList.remove(\"\")");

    classList.remove("d");
    ok(elem.className === "a b c 4", "remove: expected className 'a b c 4', got " + elem.className);

    classList.remove("c");
    ok(elem.className === "a b 4", "remove: expected className 'a b 4', got " + elem.className);

    classList.remove(4);
    ok(elem.className === "a b", "remove: expected className 'a b', got " + elem.className);

    classList.remove('a');
    ok(elem.className === "b", "remove: expected className 'b', got " + elem.className);

    classList.remove("a");
    ok(elem.className === "b", "remove (2): expected className 'b', got " + elem.className);

    classList.remove("b");
    ok(elem.className === "", "remove: expected className '', got " + elem.className);

    exception = false;
    try
    {
        classList.toggle();
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.toggle()");

    exception = false;
    try
    {
        classList.toggle("");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.toggle(\"\")");

    exception = false;
    try
    {
        classList.toggle("a b");
    }
    catch(e)
    {
        exception = true;
    }
    ok(exception, "Expected exception for classList.toggle(\"a b\")");

    // toggle's second arg is not implemented by IE, and ignored
    r = classList.toggle("abc");
    ok(r === true, "toggle('abc') returned " + r);
    ok(elem.className === "abc", "toggle('abc'): got className " + elem.className);

    r = classList.toggle("def", false);
    ok(r === true, "toggle('def', false) returned " + r);
    ok(elem.className === "abc def", "toggle('def', false): got className " + elem.className);

    r = classList.toggle("123", 1234);
    ok(r === true, "toggle('123', 1234) returned " + r);
    ok(elem.className === "abc def 123", "toggle('123', 1234): got className " + elem.className);

    r = classList.toggle("def", true);
    ok(r === false, "toggle('def', true) returned " + r);
    ok(elem.className === "abc 123", "toggle('def', true): got className " + elem.className);

    r = classList.toggle("123", null);
    ok(r === false, "toggle('123', null) returned " + r);
    ok(elem.className === "abc", "toggle('123', null): got className " + elem.className);

    elem.className = "  testclass    foobar  ";
    ok(classList.length === 2, "Expected length 2 for className '  testclass    foobar  ', got " + classList.length);
    ok(("" + classList) === "  testclass    foobar  ", "Expected classList value '  testclass    foobar  ', got " + classList);
    ok(classList.toString() === "  testclass    foobar  ", "Expected classList toString '  testclass    foobar  ', got " + classList.toString());

    r = classList[-1];
    ok(r === null, "classList[-1] = " + r);
    r = classList[0];
    ok(r === "testclass", "classList[0] = " + r);
    r = classList[1];
    ok(r === "foobar", "classList[1] = " + r);
    r = classList[2];
    ok(r === null, "classList[2] = " + r);

    classList[0] = "barfoo";
    classList[2] = "added";
    ok(classList.toString() === "  testclass    foobar  ", "Expected classList toString to not be changed after setting indexed props, got " + classList.toString());

    try
    {
        classList[0]();
        ok(false, "Expected exception calling classList[0]");
    }
    catch(e)
    {
        ok(e.number === 0xa138a - 0x80000000, "Calling classList[0] threw " + e.number);
    }

    try
    {
        new classList[0]();
        ok(false, "Expected exception calling classList[0] as constructor");
    }
    catch(e)
    {
        ok(e.number === 0xa01bd - 0x80000000, "Calling classList[0] as constructor threw " + e.number);
    }
});

sync_test("importNode", function() {
    var node, node2, orig_node, doc = document.implementation.createHTMLDocument("TestDoc");
    doc.body.innerHTML = '<div id="test"><span/></div>';
    orig_node = doc.getElementById("test");

    node = document.importNode(orig_node, false);
    ok(node !== orig_node, "node = orig_node");
    ok(orig_node.hasChildNodes() === true, "orig_node does not have child nodes");
    ok(orig_node.parentNode === doc.body, "orig_node.parentNode = " + orig_node.parentNode);
    ok(node.hasChildNodes() === false, "node has child nodes with shallow import");
    ok(node.parentNode === null, "node.parentNode = " + node.parentNode);

    node = document.importNode(orig_node, true);
    ok(node !== orig_node, "node = orig_node");
    ok(orig_node.hasChildNodes() === true, "orig_node does not have child nodes");
    ok(orig_node.parentNode === doc.body, "orig_node.parentNode = " + orig_node.parentNode);
    ok(node.hasChildNodes() === true, "node does not have child nodes with deep import");
    ok(node.parentNode === null, "node.parentNode = " + node.parentNode);

    node2 = document.importNode(node, false);
    ok(node !== node2, "node = node2");
    ok(node.hasChildNodes() === true, "node does not have child nodes");
    ok(node.parentNode === null, "node.parentNode = " + node.parentNode);
    ok(node2.hasChildNodes() === false, "node2 has child nodes");
    ok(node2.parentNode === null, "node2.parentNode = " + node2.parentNode);
});
  �� ,   �� E S 5 . J S         0           /*
 * Copyright 2018 Jacek Caban for CodeWeavers
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

var E_INVALIDARG = 0x80070057;
var JS_E_PROP_DESC_MISMATCH = 0x800a01bd;
var JS_E_INVALID_ACTION = 0x800a01bd;
var JS_E_NUMBER_EXPECTED = 0x800a1389;
var JS_E_FUNCTION_EXPECTED = 0x800a138a;
var JS_E_DATE_EXPECTED = 0x800a138e;
var JS_E_OBJECT_EXPECTED = 0x800a138f;
var JS_E_BOOLEAN_EXPECTED = 0x800a1392;
var JS_E_VBARRAY_EXPECTED = 0x800a1395;
var JS_E_ENUMERATOR_EXPECTED = 0x800a1397;
var JS_E_REGEXP_EXPECTED = 0x800a1398;
var JS_E_UNEXPECTED_QUANTIFIER = 0x800a139a;
var JS_E_INVALID_LENGTH = 0x800a13a5;
var JS_E_INVALID_WRITABLE_PROP_DESC = 0x800a13ac;
var JS_E_NONCONFIGURABLE_REDEFINED = 0x800a13d6;
var JS_E_NONWRITABLE_MODIFIED = 0x800a13d7;
var JS_E_NOT_DATAVIEW = 0x800a13df;
var JS_E_DATAVIEW_NO_ARGUMENT = 0x800a13e0;
var JS_E_DATAVIEW_INVALID_ACCESS = 0x800a13e1;
var JS_E_DATAVIEW_INVALID_OFFSET = 0x800a13e2;
var JS_E_WRONG_THIS = 0x800a13fc;
var JS_E_ARRAYBUFFER_EXPECTED = 0x800a15e4;

var tests = [];

function check_enum(o, name) {
    var ret = 0;
    for(var iter in o) {
        if(iter == name) ret++;
    }
    ok(ret < 2, name + " enumerated " + ret + " times");
    return ret != 0;
}

sync_test("script vars", function() {
    function foo() { }
    foo.prototype.foo = 13;
    var obj = new foo();
    obj.Foo = 42;
    obj.aBc = 1;
    obj.abC = 2;
    obj.Bar = 3;
    document.body.foobar = 42;
    external.testVars(document.body, obj);
});

sync_test("date_now", function() {
    var now = Date.now();
    var time = (new Date()).getTime();

    ok(time >= now && time - now < 500, "unexpected Date.now() result " + now + " expected " + time);

    Date.now(1, 2, 3);
});

sync_test("toISOString", function() {
    function expect(date, expected) {
        var s = date.toISOString();
        ok(s === expected, "toISOString returned " + s + " expected " + expected);
    }

    function expect_exception(func) {
        try {
            func();
        }catch(e) {
            return;
        }
        ok(false, "expected exception");
    }

    expect(new Date(0), "1970-01-01T00:00:00.000Z");
    expect(new Date(0xdeadbeef), "1970-02-13T05:45:28.559Z");
    expect(new Date(10928309128301), "2316-04-22T01:25:28.301Z");
    expect(new Date(-1), "1969-12-31T23:59:59.999Z");
    expect(new Date(-62167219200000), "0000-01-01T00:00:00.000Z");
    expect(new Date(-62167219200001), "-000001-12-31T23:59:59.999Z");
    expect(new Date(-6216721920000100), "-195031-12-03T23:59:59.900Z");
    expect(new Date(1092830912830100), "+036600-06-07T22:27:10.100Z");

    expect_exception(function() { new Date(NaN).toISOString(); });
    expect_exception(function() { new Date(31494784780800001).toISOString(); });
});

sync_test("Array toLocaleString", function() {
    var r = Array.prototype.toLocaleString.length, old = Number.prototype.toLocaleString;
    var s = external.listSeparator + ' ';
    ok(r === 0, "length = " + r);

    r = [5];
    r.toLocaleString = function(a, b, c) { return a + " " + b + " " + c; };
    Number.prototype.toLocaleString = function() { return "aBc"; };

    r = [new Number(3), r, new Number(12)].toLocaleString("foo", "bar", "baz");
    ok(r === "aBc"+s+"undefined undefined undefined"+s+"aBc", "toLocaleString returned " + r);

    r = [3].toLocaleString();  /* primitive number value not affected */
    if(external.isEnglish)
        ok(r === "3.00", "[3].toLocaleString returned " + r);
    else
        ok(r !== "aBc", "[3].toLocaleString returned " + r);
    Number.prototype.toLocaleString = old;

    r = Object.create(null);
    r.toString = function() { return "foo"; }
    try {
        Array.prototype.toLocaleString.call([r]);
        ok(false, "expected exception calling it on array with object without toLocaleString");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_FUNCTION_EXPECTED, "called on array with object without toLocaleString threw " + n);
    }

    r = { length: 2 };
    r[0] = { toLocaleString: function() { return "foo"; } }
    r[1] = { toLocaleString: function() { return "bar"; } }
    r = Array.prototype.toLocaleString.call(r);
    ok(r === "foo"+s+"bar", "toLocaleString on array-like object returned " + r);

    r = Array.prototype.toLocaleString.call({});
    ok(r === "", "toLocaleString on {} returned " + r);

    r = Array.prototype.toLocaleString.call("ab");
    ok(r === "a"+s+"b", "toLocaleString on 'ab' returned " + r);

    try {
        Array.prototype.toLocaleString.call(undefined);
        ok(false, "expected exception calling it on undefined");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "called on undefined threw " + n);
    }
    try {
        Array.prototype.toLocaleString.call(null);
        ok(false, "expected exception calling it on null");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "called on null threw " + n);
    }
    try {
        Array.prototype.toLocaleString.call(external.nullDisp);
        ok(false, "expected exception calling it on nullDisp");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "called on nullDisp threw " + n);
    }
});

sync_test("Number toLocaleString", function() {
    var r = Number.prototype.toLocaleString.length;
    ok(r === 0, "length = " + r);
    var tests = [
        [ 0.0,          "0" ],
        [ 1234.5,       "1,234.5" ],
        [ -1337.7331,   "-1,337.733" ],
        [ -0.0123,      "-0.012" ],
        [-0.0198,       "-0.02" ],
        [ 0.004,        "0.004" ],
        [ 99.004,       "99.004" ],
        [ 99.0004,      "99" ],
        [ 65536.5,      "65,536.5" ],
        [ NaN,          "NaN" ]
    ];

    if(external.isEnglish) {
        /* Some recent Win8.1 updates have old jscript behavior */
        if(Number.prototype.toLocaleString.call(0.0) === "0.00")
            win_skip("skipping tests due to old behavior");
        else
            for(var i = 0; i < tests.length; i++) {
                r = Number.prototype.toLocaleString.call(tests[i][0]);
                ok(r === tests[i][1], "[" + i + "] got " + r);
            }
    }

    try {
        Number.prototype.toLocaleString.call("50");
        ok(false, "expected exception calling it on string");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_WRONG_THIS || broken(n === JS_E_NUMBER_EXPECTED) /* newer Win8.1 */,
           "called on string threw " + n);
    }
    try {
        Number.prototype.toLocaleString.call(undefined);
        ok(false, "expected exception calling it on undefined");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_WRONG_THIS || broken(n === JS_E_NUMBER_EXPECTED) /* newer Win8.1 */,
           "called on undefined threw " + n);
    }
    try {
        Number.prototype.toLocaleString.call(external.nullDisp);
        ok(false, "expected exception calling it on nullDisp");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_WRONG_THIS || broken(n === JS_E_NUMBER_EXPECTED) /* newer Win8.1 */,
           "called on nullDisp threw " + n);
    }
});

sync_test("indexOf", function() {
    function expect(array, args, exr) {
        var r = Array.prototype.indexOf.apply(array, args);
        ok(r == exr, "indexOf returned " + r + " expected " + exr);
    }

    ok(Array.prototype.indexOf.length == 1, "indexOf.length = " + Array.prototype.indexOf.length);

    expect([1,2,3], [2], 1);
    expect([1,undefined,3], [undefined], 1);
    expect([1,undefined,3], [], 1);
    expect([1,,3], [undefined], -1);
    expect([1,2,3,4,5,6], [2, 2], -1);
    expect([1,2,3,4,5,6], [5, -1], -1);
    expect([1,2,3,4,5,6], [5, -2], 4);
    expect([1,2,3,4,5,6], [5, -20], 4);
    expect([1,2,3,4,5,6], [5, 20], -1);
    expect("abc", ["b"], 1);
    expect(true, [true], -1);
    expect({"4": 4, length: 5}, [4], 4);
    expect({"4": 4, length: 5}, [undefined], -1);
    expect({"4": 4, length: 3}, [4], -1);
    expect({"test": true}, [true], -1);
    expect([1,2,3], [2, 1.9], 1);
});

sync_test("lastIndexOf", function() {
    function expect(array, args, exr) {
        var r = Array.prototype.lastIndexOf.apply(array, args);
        ok(r == exr, "lastIndexOf returned " + r + " expected " + exr);
    }

    ok(Array.prototype.lastIndexOf.length == 1, "lastIndexOf.length = " + Array.prototype.lastIndexOf.length);

    expect([1,2,3], [2], 1);
    expect([1,undefined,3], [undefined], 1);
    expect([1,undefined,3], [], 1);
    expect([1,,3], [undefined], -1);
    expect([1,undefined,undefined], [undefined], 2);
    expect([1,2,3,2,5,6], [2, 2], 1);
    expect([1,2,3,2,5,6], [2], 3);
    expect([1,2,3,2,5,6], [2, -3], 3);
    expect([1,2,3,2,5,6], [2, -4], 1);
    expect([1,2,3,2,5,6], [1, -100], -1);
    expect([1,2,3,2,5,6], [2, 100], 3);
    expect("abcba", ["b"], 3);
    expect(true, [true], -1);
    expect({"4": 4, length: 5}, [4], 4);
    expect({"4": 4, length: 5}, [undefined], -1);
    expect({"4": 4, length: 3}, [4], -1);
    expect({"test": true}, [true], -1);
    expect([1,2,3], [2, 1.9], 1);
    expect([1,2,3], [2, 0.9], -1);
});

sync_test("filter", function() {
    ok(Array.prototype.filter.length === 1, "filter.length = " + Array.prototype.filter.length);

    var arr = ["a","foobar",true,"b",42,0,Math,null,undefined,[1,2,3,"4"]];
    delete arr[1];

    function test(expect, fn, expect_this) {
        var mismatch = false, r = function(v, i, a) {
            ok(a === arr, "unexpected array " + arr);
            ok(v === arr[i], "value = " + v + ", expected " + arr[i]);
            ok(this === (expect_this ? expect_this : window), "this = " + this + ", expected " + expect_this);
            return fn(v);
        };
        r = expect_this ? Array.prototype.filter.call(arr, r, expect_this) : Array.prototype.filter.call(arr, r);
        ok(r.length === expect.length, "filtered array length = " + r.length + ", expected " + expect.length);
        for(var i = 0; i < r.length; i++)
            if(r[i] !== expect[i])
                mismatch = true;
        ok(!mismatch, "filtered array = " + r + ", expected " + expect);
    }

    test([], function(v) { return false; });
    test(["a",true,"b",42,0,Math,null,undefined,arr[9]], function(v) { if(arr[1] === "foobar") delete arr[1]; return true; });
    test(["a","b"], function(v) { if(v === "b") delete arr[0]; return typeof v === "string"; });
    test(["b"], function(v) { if(arr[arr.length - 1] !== "c") arr.push("c"); return typeof v === "string"; });
    test([true,"b",42,Math,arr[9],"c"], function(v) { return v; }, Object);

    [0].filter(function() { ok(this.valueOf() === "wine", "this.valueOf() = " + this.valueOf()); return true; }, "wine");
});

sync_test("every & some", function() {
    ok(Array.prototype.every.length === 1, "every.length = " + Array.prototype.every.length);
    ok(Array.prototype.some.length === 1, "some.length = " + Array.prototype.some.length);
    var arr = ["foobar"];

    function test(expect_every, expect_some, fn, expect_this) {
        var cb = function(v, i, a) {
            ok(a === arr, "unexpected array " + arr);
            ok(v === arr[i], "value = " + v + ", expected " + arr[i]);
            ok(this === (expect_this ? expect_this : window), "this = " + this + ", expected " + expect_this);
            return fn(v);
        };
        r = expect_this ? Array.prototype.every.call(arr, cb, expect_this) : Array.prototype.every.call(arr, cb);
        ok(r === expect_every, "'every' = " + r);
        r = expect_this ? Array.prototype.some.call(arr, cb, expect_this) : Array.prototype.some.call(arr, cb);
        ok(r === expect_some, "'some' = " + r);
    }

    delete arr[0];
    test(true, false, function(v) { return false; });
    test(true, false, function(v) { return true; });

    arr = [1,"2",3];
    test(true, true, function(v) { return true; });
    test(true, true, function(v) { if(arr[1] === "2") delete arr[1]; return typeof v === "number"; });
    test(true, true, function(v) { if(arr[arr.length - 1] !== "a") arr.push("a"); return typeof v === "number"; }, Object);
    test(false, true, function(v) { return typeof v === "number"; }, Object);

    arr = [0,null,undefined,false];
    test(false, false, function(v) { return v; });
    arr.push(1);
    test(false, true, function(v) { return v; });

    [0].every(function() { ok(this.valueOf() === 42, "this.valueOf() = " + this.valueOf()); return true; }, 42);
    [0].some(function() { ok(this.valueOf() === 137, "this.valueOf() = " + this.valueOf()); return false; }, 137);
});

sync_test("forEach", function() {
    ok(Array.prototype.forEach.length === 1, "forEach.length = " + Array.prototype.forEach.length);

    function test(array, expect) {
        var r = Array.prototype.forEach.call(array, function(value, index, arr) {
            ok(arr === array, "unexpected array " + arr);
            ok(index === expect[0][0], "index = " + index + " expected " + expect[0][0]);
            ok(value === expect[0][1], "value = " + value + " expected " + expect[0][1]);
            expect.shift();
        });
        ok(r === undefined, "forEach returned " + r);
        ok(expect.length === 0, "too few forEach() calls, expected " + expect.length + " more");
    }

    test(["a",2,"c"], [[0,"a"],[1,2],[2,"c"]]);
    test({length: 1000, 500: false, c: 30, 3: "x", 999: 1}, [[3,"x"],[500,false],[999,1]]);
    test(new String("abc"), [[0,"a"],[1,"b"],[2,"c"]]);
    test([], []);

    [1,2].forEach(function() {
        ok(this === window, "this != window");
    });
    [1,2].forEach(function() {
        ok(this === window, "this != window");
    }, undefined);

    var o = new Object(), a = [1,2];
    a.forEach(function(value, index, array) {
        ok(array === a, "array != a");
        ok(this === o, "this != o");
    }, o);

    a.forEach(function() { ok(this.valueOf() === "foobar", "this.valueOf() = " + this.valueOf()); }, "foobar");
});

sync_test("isArray", function() {
    function expect_array(a, exr) {
        var r = Array.isArray(a);
        ok(r === exr, "isArray returned " + r + " expected " + exr);
    }

    expect_array([1], true);
    expect_array(Array, false);
    expect_array(new Array(), true);
    expect_array({"1": 1, "2": 2, length: 2}, false);

    function C() {}
    C.prototype = Array.prototype;
    expect_array(new C(), false);
});

sync_test("array_splice", function() {
    var arr = [1,2,3,4,5]
    var tmp = arr.splice(2);
    ok(arr.toString() === "1,2", "arr = " + arr);
    ok(tmp.toString() === "3,4,5", "tmp = " + tmp);
});

sync_test("array_map", function() {
    var calls, m, arr, ctx;

    /* basic map call with context */
    calls = "";
    arr = [1,2,3];
    ctx = {};
    m = arr.map(function(x, i, a) {
        ok(this === ctx, "this != ctx");
        ok(i === x - 1, "i = " + i);
        ok(a === arr, "a != arr");
        calls += x + ",";
        return x * 2;
    }, ctx);
    ok(calls === "1,2,3,", "calls = " + calls);
    ok(m.join() === "2,4,6", "m = " + m);

    /* non-array object as this argument */
    calls = "";
    arr = { 1: "one", 2: "two", 3: "three", length: 3 };
    m = Array.prototype.map.call(arr, function(x, i) {
        calls += i + ":" + x + ",";
        return x + "!";
    });
    ok(calls === "1:one,2:two,", "calls = " + calls);
    ok(m.join() === ",one!,two!", "m = " + m);
    ok(!("0" in m), "0 is in m");

    /* mutate array in callback */
    calls = "";
    arr = [1,2,3];
    m = Array.prototype.map.call(arr, function(x, i) {
        calls += i + ":" + x + ",";
        for(var j = i; j < arr.length; j++)
            arr[j]++;
        arr.push(i * i);
        return x - 1;
    });
    ok(calls === "0:1,1:3,2:5,", "calls = " + calls);
    ok(m.join() === "0,2,4", "m = " + m);

    [1,2].map(function() {
        ok(this === window, "this != window");
    });
    [1,2].map(function() {
        ok(this === window, "this != window");
    }, undefined);
    [1,2].map(function() {
        ok(this.valueOf() === 137, "this.valueOf() = " + this.valueOf());
    }, 137);

    r = [1,,2,].map(function(x) { return "" + x; });
    ok(r.length === 3, "[1,,2,].map length = " + r.length);
    ok(r[0] === "1", "[1,,2,].map[0] = " + r[0]);
    ok(r[2] === "2", "[1,,2,].map[2] = " + r[2]);
    ok(!("1" in r), "[1,,2,].map[1] exists");
    ok(!("3" in r), "[1,,2,].map[3] exists");
});

sync_test("array_sort", function() {
    var r;

    r = [3,1,2].sort(function(x,y) { return y-x; }, 1, 2, 3, true, undefined ).join();
    ok(r === "3,2,1", "reverse sorted [3,1,2] = " + r);

    r = [3,1,2].sort(undefined).join();
    ok(r === "1,2,3", "null sorted [3,1,2] = " + r);

    try {
        r = [3,1,2].sort(null);
        ok(false, "expected sort(null) exception");
    }catch(e) {
        ok(e.name === "TypeError", "got exception " + e.name);
    }
});

sync_test("identifier_keywords", function() {
    function get(let, set) { { get instanceof (Object); } return let + set; }
    { get /* asdf */: 10 }
    let /* block label */ : {
        break let;
        ok(false, "did not break out of 'let' labelled block statement");
    }
    set: var let = get(1, 2);
    var set = 1234;
    var o = {
        get: get,
        set: set,
        let /* comment */  :  let,
        if: 1,
        default: 2,
        function: 3,
        break: true,
        case: true,
        catch: true,
        continue: true,
        delete: true,
        do: true,
        else: true,
        finally: true,
        for: true,
        set in(x) { },
        get instanceof() { return 3; },
        new: true,
        return: true,
        switch: true,
        throw: true,
        try: true,
        typeof: true,
        var: true,
        void: true,
        while: true,
        with: true,
        true: true,
        false: true,
        null: true,
        this: true
    };
    function ro() { return o; };

    ok(o.if === 1, "o.if = " + o.if);
    ok(ro().default === 2, "ro().default = " + ro().default);
    ok(o.false === true, "o.false = " + o.false);
    ok(o.get === get, "o.get = " + o.get);
    ok(o.set === set, "o.set = " + o.set);
    ok(o.let === let, "o.let = " + o.let);
    ok(o.instanceof === 3, "o.instanceof = " + o.instanceof);
    ok(let === 3, "let = " + let);
    ok(set === 1234, "set = " + set);

    var tmp = false;
    try {
        eval('function var() { }');
    }
    catch(set) {
        tmp = true;
    }
    ok(tmp === true, "Expected exception for 'function var() { }'");
});

function test_own_data_prop_desc(obj, prop, expected_writable, expected_enumerable,
                                 expected_configurable) {
    var desc = Object.getOwnPropertyDescriptor(obj, prop);
    ok("value" in desc, "value is not in desc");
    ok(desc.value === obj[prop], "desc.value = " + desc.value + " expected " + obj[prop]);
    ok(desc.writable === expected_writable, "desc(" + prop + ").writable = " + desc.writable
       + " expected " + expected_writable);
    ok(desc.enumerable === expected_enumerable, "desc.enumerable = " + desc.enumerable
       + " expected " + expected_enumerable);
    ok(desc.configurable === expected_configurable, "desc.configurable = " + desc.configurable
       + " expected " + expected_configurable);
}

sync_test("getOwnPropertyDescriptor", function() {
    var obj;

    obj = { test: 1 };
    test_own_data_prop_desc(obj, "test", true, true, true);

    test_own_data_prop_desc(Object, "getOwnPropertyDescriptor", true, false, true);
    test_own_data_prop_desc(Math, "PI", false, false, false);

    var obj = new String();
    test_own_data_prop_desc(obj, "length", false, false, false);
    ok(Object.getOwnPropertyDescriptor(obj, "slice") === undefined,
       "getOwnPropertyDescriptor(slice) did not return undefined");
    test_own_data_prop_desc(String.prototype, "slice", true, false, true);

    obj = new Array();
    test_own_data_prop_desc(obj, "length", true, false, false);

    obj = new Function();
    test_own_data_prop_desc(obj, "length", false, false, false);
    test_own_data_prop_desc(obj, "arguments", false, false, false);

    obj = /test/;
    test_own_data_prop_desc(obj, "global", false, false, false);
    test_own_data_prop_desc(obj, "ignoreCase", false, false, false);
    test_own_data_prop_desc(obj, "lastIndex", true, false, false);
    test_own_data_prop_desc(obj, "multiline", false, false, false);
    test_own_data_prop_desc(obj, "source", false, false, false);

    (function() {
        test_own_data_prop_desc(arguments, "length", true, false, true);
        test_own_data_prop_desc(arguments, "callee", true, false, true);
        ok(!("caller" in arguments), "caller in arguments");
    })();

    test_own_data_prop_desc(String, "prototype", false, false, false);
    test_own_data_prop_desc(function(){}, "prototype", true, false, false);
    test_own_data_prop_desc(function(){}, "caller", false, false, false);
    test_own_data_prop_desc(function(){}, "arguments", false, false, false);
    test_own_data_prop_desc(Function, "prototype", false, false, false);
    test_own_data_prop_desc(Function.prototype, "caller", false, false, false);
    test_own_data_prop_desc(Function.prototype, "arguments", false, false, false);
    test_own_data_prop_desc(String.prototype, "constructor", true, false, true);

    try {
        Object.getOwnPropertyDescriptor(null, "prototype");
        ok(false, "expected exception with null");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "with null context threw " + n);
    }
    try {
        Object.getOwnPropertyDescriptor(external.nullDisp, "prototype");
        ok(false, "expected exception calling getOwnPropertyDescriptor(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "getOwnPropertyDescriptor(nullDisp) threw " + n);
    }
});

sync_test("defineProperty", function() {
    var nullDisp = external.nullDisp;
    function test_accessor_prop_desc(obj, prop, orig_desc) {
        var expected_enumerable = "enumerable" in orig_desc && !!orig_desc.enumerable;
        var expected_configurable = "configurable" in orig_desc && !!orig_desc.configurable;

        var desc = Object.getOwnPropertyDescriptor(obj, prop);
        ok(desc.enumerable === expected_enumerable, "desc.enumerable = " + desc.enumerable
           + " expected " + expected_enumerable);
        ok(desc.configurable === expected_configurable, "desc.configurable = " + desc.configurable
           + " expected " + expected_configurable);
        ok(desc.get === orig_desc.get, "desc.get = " + desc.get);
        ok(desc.set === orig_desc.set, "desc.set = " + desc.set);
    }

    function expect_exception(func, expected_number) {
        try {
            func();
        }catch(e) {
            var n = e.number + 0x100000000; /* make it unsigned like HRESULT */
            todo_wine_if(expected_number == JS_E_PROP_DESC_MISMATCH).
            ok(n === expected_number, "got exception " + n.toString(16)
               + " expected " + expected_number.toString(16));
            ok(e.name === "TypeError", "e.name = " + e.name);
            return;
        }
        ok(false, "expected exception");
    }

    var obj = new Object(), defined;
    defined = Object.defineProperty(obj, "test", {});
    ok(defined === obj, "defined != obj");
    ok("test" in obj, "test is not in obj");
    test_own_data_prop_desc(obj, "test", false, false, false);
    ok(obj.test === undefined, "obj.test = " + obj.test);

    Object.defineProperty(obj, "all", {writable: true, enumerable: true, configurable: true, value: 1});
    test_own_data_prop_desc(obj, "all", true, true, true);
    ok(obj.all === 1, "obj.test = " + obj.test);

    Object.defineProperty(obj, "all", {writable: false});
    test_own_data_prop_desc(obj, "all", false, true, true);
    ok(obj.all === 1, "obj.test = " + obj.test);

    var getsetprop_value = 1;
    var desc = {
        get: function() {
            return getsetprop_value;
        },
        set: function(v) {
            getsetprop_value = v;
        },
        configurable: true
    };
    Object.defineProperty(obj, "getsetprop", desc);
    test_accessor_prop_desc(obj, "getsetprop", desc);

    ok(obj.getsetprop === 1, "getsetprop = " + obj.getsetprop);
    obj.getsetprop = 2;
    ok(getsetprop_value === 2, "getsetprop_value = " + getsetprop_value);
    test_accessor_prop_desc(obj, "getsetprop", desc);
    ok(obj.getsetprop === 2, "getsetprop = " + obj.getsetprop);

    ok((delete obj.getsetprop) === true, "delete getsetprop returned false");
    ok(!("getsetprop" in obj), "getsetprop still in obj after delete");

    Object.defineProperty(obj, "notConf", {writable: true, enumerable: true, configurable: false, value: 1});
    test_own_data_prop_desc(obj, "notConf", true, true, false);

    expect_exception(function() {
        Object.defineProperty(obj, "notConf",
                              {writable: true, enumerable: true, configurable: true, value: 1});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConf",
                              {writable: true, enumerable: false, configurable: false, value: 1});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    Object.defineProperty(obj, "notConf",
                          {writable: true, enumerable: true, configurable: false, value: 2});
    test_own_data_prop_desc(obj, "notConf", true, true, false);

    Object.defineProperty(obj, "notConf", {writable: true, value: 2});
    test_own_data_prop_desc(obj, "notConf", true, true, false);

    Object.defineProperty(obj, "notConf2",
                          {writable: false, enumerable: false, configurable: false, value: 1});
    test_own_data_prop_desc(obj, "notConf2", false, false, false);
    obj.notConf2 = 2;
    ok(obj.notConf2 === 1, "obj.notConf2 = " + obj.notConf2)

    expect_exception(function() {
        Object.defineProperty(obj, "notConf2",
                              {writable: false, enumerable: false, configurable: true, value: 1});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConf2",
                              {writable: false, enumerable: true, configurable: false, value: 1});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConf2", {writable: true, value: 1});
    }, JS_E_NONWRITABLE_MODIFIED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConf2", {value: 2});
    }, JS_E_NONWRITABLE_MODIFIED);

    Object.defineProperty(obj, "notConf2",
                          {writable: false, enumerable: false, configurable: false, value: 1});
    test_own_data_prop_desc(obj, "notConf2", false, false, false);

    Object.defineProperty(obj, "notConf2", {writable: false, value: 1});
    test_own_data_prop_desc(obj, "notConf2", false, false, false);

    desc = {
        get: function() {
            return getsetprop_value;
        },
        set: function(v) {
            getsetprop_value = v;
        },
        configurable: false
    };
    Object.defineProperty(obj, "notConfAcc", desc);
    test_accessor_prop_desc(obj, "notConfAcc", desc);

    expect_exception(function() {
        Object.defineProperty(obj, "notConfAcc", {value: 1});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConfAcc", {get: desc.get, set: function () {}});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConfAcc", {get: undefined, set: desc.set});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    expect_exception(function() {
        Object.defineProperty(obj, "notConfAcc", {writable: true});
    }, JS_E_NONCONFIGURABLE_REDEFINED);

    Object.defineProperty(obj, "notConfAcc", {get: desc.get});
    test_accessor_prop_desc(obj, "notConfAcc", desc);

    Object.defineProperty(obj, "notConfAcc", {set: desc.set});
    test_accessor_prop_desc(obj, "notConfAcc", desc);

    Object.defineProperty(obj, "notConfAcc", {configurable: false});
    test_accessor_prop_desc(obj, "notConfAcc", desc);

    desc = {
        get: function() {
            return getsetprop_value;
        },
        set: function(v) {
            getsetprop_value = v;
        },
        configurable: true
    };
    Object.defineProperty(obj, "confAcc", desc);
    test_accessor_prop_desc(obj, "confAcc", desc);

    Object.defineProperty(obj, "confAcc", {writable: 1});
    test_own_data_prop_desc(obj, "confAcc", true, false, true);

    Object.defineProperty(obj, "confAcc", desc);
    test_accessor_prop_desc(obj, "confAcc", desc);

    desc.get = function() {};
    desc.set = undefined;
    Object.defineProperty(obj, "confAcc", desc);
    test_accessor_prop_desc(obj, "confAcc", desc);

    expect_exception(function() {
        Object.defineProperty(obj, "invaliddesc", {get: undefined, value: 1});
    }, JS_E_PROP_DESC_MISMATCH);

    expect_exception(function() {
        Object.defineProperty(obj, "invaliddesc", {set: undefined, writable: true});
    }, JS_E_INVALID_WRITABLE_PROP_DESC);

    function child() {}
    desc = {
        get: function() {
            ok(this === obj, "this != obj");
            return getsetprop_value;
        },
        set: function(v) {
            ok(this === obj, "this != obj");
            getsetprop_value = v;
        },
        configurable: true
    };
    Object.defineProperty(child.prototype, "parent_accessor", desc);

    obj = new child();
    getsetprop_value = 6;
    ok(obj.parent_accessor === 6, "parent_accessor = " + obj.parent_accessor);
    obj.parent_accessor = 1;
    ok(getsetprop_value === 1, "getsetprop_value = " + getsetprop_value);
    ok(obj.parent_accessor === 1, "parent_accessor = " + obj.parent_accessor);

    ok(Object.getOwnPropertyDescriptor(obj, "parent_accessor") === undefined,
       "getOwnPropertyDescriptor(parent_accessor) did not return undefined");
    test_accessor_prop_desc(child.prototype, "parent_accessor", desc);

    desc.get = undefined;
    Object.defineProperty(child.prototype, "parent_accessor", desc);
    ok(obj.parent_accessor === undefined, "parent_accessor = " + obj.parent_accessor);

    /* no setter */
    desc = {
        get: function() {
            ok(this === obj, "this != obj");
            return true;
        },
        configurable: true
    };
    Object.defineProperty(obj, "no_setter", desc);
    test_accessor_prop_desc(obj, "no_setter", desc);
    obj.no_setter = false;
    ok(obj.no_setter === true, "no_setter = " + obj.no_setter);

    ok((delete obj.no_setter) === true, "delete no_setter returned false");
    ok(!("no_setter" in obj), "no_setter still in obj after delete");

    Object.defineProperty(child.prototype, "no_setter", desc);
    test_accessor_prop_desc(child.prototype, "no_setter", desc);
    ok(!obj.hasOwnProperty("no_setter"), "no_setter is a property of obj");
    obj.no_setter = false;
    ok(obj.no_setter === true, "no_setter = " + obj.no_setter);
    ok(!obj.hasOwnProperty("no_setter"), "no_setter is a property of obj");

    /* call prop with getter */
    desc = {
        get: function() {
            ok(this === obj, "this != obj");
            return function(x) {
                ok(x === 100, "x = " + x);
                return 10;
            };
        }
    };
    Object.defineProperty(obj, "funcprop", desc);
    test_accessor_prop_desc(obj, "funcprop", desc);
    ok(obj.funcprop(100) === 10, "obj.funcprop() = " + obj.funcprop(100));

    Object.defineProperty(child.prototype, "funcprop_prot", desc);
    test_accessor_prop_desc(child.prototype, "funcprop_prot", desc);
    ok(obj.funcprop_prot(100) === 10, "obj.funcprop_prot() = " + obj.funcprop_prot(100));

    expect_exception(function() {
        Object.defineProperty(null, "funcprop", desc);
    }, JS_E_OBJECT_EXPECTED);
    expect_exception(function() {
        Object.defineProperty(nullDisp, "funcprop", desc);
    }, JS_E_OBJECT_EXPECTED);
    expect_exception(function() {
        Object.defineProperty(obj, "funcprop", nullDisp);
    }, JS_E_OBJECT_EXPECTED);
    expect_exception(function() {
        var o = {};
        Object.defineProperty(o, "f", { get: function() { return 0; } });
        o.f();
    }, JS_E_FUNCTION_EXPECTED);
});

sync_test("defineProperties", function() {
    var o, defined, descs;

    descs = {
        acc_prop: { get: function() { return 1; } },
        prop: { value: 2 },
        e: { enumerable: true }
    };

    o = new Object();
    defined = Object.defineProperties(o, descs);
    ok(defined === o, "defined != o");
    ok(o.acc_prop === 1, "o.acc_prop = " + o.acc_prop);
    ok(o.prop === 2, "o.prop = " + o.prop);
    ok(o.e === undefined, "o.e = " + o.e);
    ok("e" in o, "e is not in o");
    test_own_data_prop_desc(o, "prop", false, false, false);
    test_own_data_prop_desc(o, "e", false, true, false);
    for(var p in o) ok(p === "e", "p = " + p);

    o = new Object();
    Object.defineProperties(o, 1);
    for(var p in o) ok(false, "o has property " + p);

    o = Object.create(null, descs);
    ok(o.acc_prop === 1, "o.acc_prop = " + o.acc_prop);
    ok(o.prop === 2, "o.prop = " + o.prop);
    ok(o.e === undefined, "o.e = " + o.e);
    ok("e" in o, "e is not in o");
    test_own_data_prop_desc(o, "prop", false, false, false);
    test_own_data_prop_desc(o, "e", false, true, false);
    for(var p in o) ok(p === "e", "p = " + p);

    var desc_proto = new Object();
    desc_proto.proto_prop = { value: true, enumerable: true };
    descs = Object.create(desc_proto);
    o = Object.create(null, descs);
    ok(!("proto_prop" in o), "proto_prop is in o");
});

sync_test("property_definitions", function() {
    var obj, val, i, arr;

    function test_accessor_prop_desc(obj, prop, have_getter, have_setter) {
        var desc = Object.getOwnPropertyDescriptor(obj, prop);
        ok(desc.enumerable === true, "desc.enumerable = " + desc.enumerable);
        ok(desc.configurable === true, "desc.configurable = " + desc.configurable);

        if(have_getter) {
            ok(typeof(desc.get) === "function", "desc.get = " + desc.get);
            ok(typeof(desc.get.prototype) === "object", "desc.get.prototype = " + desc.get.prototype);
        }else {
            ok(!("get" in obj), "desc.get = " + desc.get);
        }

        if(have_setter) {
            ok(typeof(desc.set) === "function", "desc.set = " + desc.set);
            ok(typeof(desc.set.prototype) === "object", "desc.set.prototype = " + desc.set.prototype);
        }else {
            ok(!("set" in obj), "desc.get = " + desc.get);
        }
    }

    obj = {
        get prop()  { return val + 1; },
        set prop(v) { val = v; }
    };
    test_accessor_prop_desc(obj, "prop", true, true);
    val = 0;
    ok(obj.prop === 1, "obj.prop = " + obj.prop);
    obj.prop = 3;
    ok(val === 3, "val = " + val);
    ok(obj.prop === 4, "obj.prop = " + obj.prop);

    arr = [];
    for(i in obj)
        arr.push(i);
    ok(arr.join() === "prop", "prop of obj = " + arr.join());

    obj = {
        set prop(v) { val = v; }
    };
    test_accessor_prop_desc(obj, "prop", false, true);
    val = 1;
    ok(obj.prop === undefined, "obj.prop = " + obj.prop);
    obj.prop = 2;
    ok(val === 2, "val = " + val);
    ok(obj.prop === undefined, "obj.prop = " + obj.prop);

    obj = {
        get prop()  { return val + 1; },
        get 0()     { return val + 2; }
    };
    test_accessor_prop_desc(obj, "prop", true, false);
    val = 5;
    ok(obj.prop === 6, "obj.prop = " + obj.prop);
    obj.prop = 10;
    ok(val === 5, "val = " + val);
    ok(obj.prop === 6, "obj.prop = " + obj.prop);
    test_accessor_prop_desc(obj, "0", true, false);
    ok(obj[0] === 7, "obj.prop = " + obj[0]);
});

sync_test("string_idx", function() {
    var i, s = "foobar";
    ok(s[0] === "f", "s[0] = " + s[0]);
    ok(s[5] === "r", "s[5] = " + s[5]);
    ok(s[6] === undefined, "s[6] = " + s[6]);
    ok((delete s[0]) === false, "delete s[0] returned true");
    ok((delete s[6]) === true, "delete s[6] returned false");
    s[6] = "X";
    ok(s[6] === undefined, "s[6] = " + s[6]);

    s = new String(s);
    test_own_data_prop_desc(s, "0", false, true, false);
    test_own_data_prop_desc(s, "1", false, true, false);
    ok(!s.hasOwnProperty("6"), "'6' is a property");

    s[7] = "X";
    ok(s[7] === "X", "s[7] = " + s[7]);
    // s.hasOwnProperty("7") returns false on Win8 likely due to a bug in its js engine

    Object.defineProperty(s, "8", {writable: false, enumerable: true, configurable: true, value: "Y"});
    ok(s[8] === "Y", "s[8] = " + s[8]);
    ok(s.hasOwnProperty("8"), "'8' not a property");

    String.prototype[9] = "Z";
    ok(s[9] === "Z", "s[9] = " + s[9]);
    delete String.prototype[9];

    i = 0;
    for(var idx in s) {
        ok(s[idx] === "foobar XY"[idx], "enum s[" + idx + "] = " + s[idx]);
        i++;
    }
    ok(i === 8, "enum did " + i + " iterations");
});

sync_test("string_trim", function() {
    function test_trim(value, expected) {
        var r = String.prototype.trim.call(value);
        ok(r === expected, "trim(" + value + ") = " + r);
    }

    test_trim("test", "test");
    test_trim(false, "false");
    test_trim("\n \t\rte st\t\t\n", "te st");
    test_trim({ toString: function() { return " test "; } }, "test");
    test_trim("", "");
    test_trim(" \t\n", "");
});

sync_test("global_properties", function() {
    var o;

    /* Make sure that global properties are not writable. */
    o = NaN;
    NaN = 1;
    ok(isNaN(NaN), "NaN = " + NaN);
    o = undefined;
    undefined = 1;
    ok(undefined === o, "NaN = " + NaN);
    o = Infinity;
    Infinity = 1;
    ok(Infinity === o, "Infinity = " + NaN);
});

sync_test("string_split", function() {
    var r;

    /* IE9 got this wrong*/
    if("1undefined2".split(undefined).length != 1) {
        win_skip("detected broken String.prototype.split implementation");
        return;
    }

    function test(string, separator, result) {
        var r = string.split(separator);
        ok(r == result, "\"" + string + "\".split(" + separator + ") returned " + r + " expected " + result);
    }

    test("test", /^|\s+/, "test");
    test("test", /$|\s+/, "test");
    test("test", /^|./, "t,,,");
    test("test", /.*/, ",");
    test("test", /x*/, "t,e,s,t");
    test("test", /$|x*/, "t,e,s,t");
    test("test", /^|x*/, "t,e,s,t");
    test("test", /t*/, ",e,s,");
    test("xaabaax", /a*|b*/, "x,b,x");
    test("xaabaax", /a+|b+/, "x,,,x");
    test("xaabaax", /a+|b*/, "x,,,x");
    test("xaaxbaax", /b+|a+/, "x,x,,x");
    test("test", /^|t/, "tes,");
    test("test", /^|t/, "tes,");
    test("a,,b", /,/, "a,,b");
    test("ab", /a*/, ",b");
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

    r = "1,2,3".split(undefined);
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 1, "r.length = " + r.length);
    ok(r[0] === "1,2,3", "r[0] = " + r[0]);

    r = "1,undefined2undefined,3".split(undefined);
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 1, "r.length = " + r.length);
    ok(r[0] === "1,undefined2undefined,3", "r[0] = " + r[0]);

    r = "1,undefined2undefined,3".split();
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 1, "r.length = " + r.length);
    ok(r[0] === "1,undefined2undefined,3", "r[0] = " + r[0]);

    /* note: spec violation, limit is ignored */
    r = "1,undefined2undefined,3".split(undefined, 0);
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 1, "r.length = " + r.length);
    ok(r[0] === "1,undefined2undefined,3", "r[0] = " + r[0]);

    r = "1,undefined2null,3".split(null);
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 2, "r.length = " + r.length);
    ok(r[0] === "1,undefined2", "r[0] = " + r[0]);
    ok(r[1] === ",3", "r[1] = " + r[1]);

    r = "".split();
    ok(typeof(r) === "object", "typeof(r) = " + typeof(r));
    ok(r.length === 1, "r.length = " + r.length);
    ok(r[0] === "", "r[0] = " + r[0]);
});

sync_test("getPrototypeOf", function() {
    ok(Object.create.length === 2, "Object.create.length = " + Object.create.length);
    ok(Object.getPrototypeOf.length === 1, "Object.getPrototypeOf.length = " + Object.getPrototypeOf.length);

    ok(Object.getPrototypeOf(new Object()) === Object.prototype,
       "Object.getPrototypeOf(new Object()) !== Object.prototype");

    function Constr() {}
    var obj = new Constr();
    ok(Object.getPrototypeOf(Constr.prototype) === Object.prototype,
       "Object.getPrototypeOf(Constr.prototype) !== Object.prototype");
    ok(Object.getPrototypeOf(obj) === Constr.prototype,
       "Object.getPrototypeOf(obj) !== Constr.prototype");

    var proto = new Object();
    Constr.prototype = proto;
    ok(Object.getPrototypeOf(obj) != proto,
       "Object.getPrototypeOf(obj) == proto");
    obj = new Constr();
    ok(Object.getPrototypeOf(obj) === proto,
       "Object.getPrototypeOf(obj) !== proto");
    ok(Object.getPrototypeOf(obj, 2, 3, 4) === proto,
       "Object.getPrototypeOf(obj) !== proto");

    ok(Object.getPrototypeOf(Object.prototype) === null,
       "Object.getPrototypeOf(Object.prototype) !== null");

    obj = Object.create(proto = { test: 1 });
    ok(Object.getPrototypeOf(obj) === proto,
       "Object.getPrototypeOf(obj) !== proto");
    ok(obj.test === 1, "obj.test = " + obj.test);

    obj = Object.create(null);
    ok(!("toString" in obj), "toString is in obj");
    ok(Object.getPrototypeOf(obj) === null, "Object.getPrototypeOf(obj) = " + Object.getPrototypeOf(obj));

    ok(Object.getPrototypeOf(external) === null, "Object.getPrototypeOf(non-JS obj) = " + Object.getPrototypeOf(external));
    try {
        Object.getOwnPropertyDescriptor(external.nullDisp);
        ok(false, "expected exception calling getOwnPropertyDescriptor(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "getOwnPropertyDescriptor(nullDisp) threw " + n);
    }
});

sync_test("toString", function() {
    var tmp, obj;

    (function () { tmp = Object.prototype.toString.call(arguments); })();
    todo_wine.
    ok(tmp === "[object Arguments]", "toString.call(arguments) = " + tmp);
    tmp = Object.prototype.toString.call(this);
    ok(tmp === "[object Window]", "toString.call(null) = " + tmp);
    tmp = Object.prototype.toString.call(null);
    ok(tmp === "[object Null]", "toString.call(null) = " + tmp);
    tmp = Object.prototype.toString.call(undefined);
    ok(tmp === "[object Undefined]", "toString.call(undefined) = " + tmp);
    tmp = Object.prototype.toString.call();
    ok(tmp === "[object Undefined]", "toString.call() = " + tmp);

    obj = Object.create(null);
    tmp = Object.prototype.toString.call(obj);
    ok(tmp === "[object Object]", "toString.call(Object.create(null)) = " + tmp);
    obj = Object.create(Number.prototype);
    tmp = Object.prototype.toString.call(obj);
    ok(tmp === "[object Object]", "toString.call(Object.create(Number.prototype)) = " + tmp);

    tmp = (new Number(303)).toString(undefined);
    ok(tmp === "303", "Number 303 toString(undefined) = " + tmp);
});

sync_test("bind", function() {
    var f, r;
    var o = new Object(), o2 = new Object();

    f = (function() {
        ok(this === o, "this != o");
        ok(arguments.length === 0, "arguments.length = " + arguments.length);
        return 1;
    }).bind(o);
    ok(f.length === 0, "f.length = " + f.length);
    r = f.call(o2);
    ok(r === 1, "r = " + r);

    try {
        f.arguments;
        ok(false, "expected exception getting f.arguments");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_INVALID_ACTION, "f.arguments threw " + n);
    }
    try {
        f.caller;
        ok(false, "expected exception getting f.caller");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_INVALID_ACTION, "f.caller threw " + n);
    }

    f = (function() {
        ok(this === o, "this != o");
        ok(arguments.length === 1, "arguments.length = " + arguments.length);
        ok(arguments[0] === 1, "arguments[0] = " + arguments[0]);
        return 1;
    }).bind(o, 1);
    ok(f.length === 0, "f.length = " + f.length);
    r = f.call(o2);
    ok(r === 1, "r = " + r);

    f = (function() {
        ok(this === o, "this != o");
        ok(arguments.length === 2, "arguments.length = " + arguments.length);
        ok(arguments[0] === 1, "arguments[0] = " + arguments[0]);
        ok(arguments[1] === 2, "arguments[1] = " + arguments[0]);
        return 1;
    }).bind(o, 1);
    r = f.call(o2, 2);
    ok(r === 1, "r = " + r);

    o2.f = f;
    r = o2.f(2);
    ok(r === 1, "r = " + r);

    f = (function test(x, y, z) {
        ok(this === o, "this != o");
        ok(arguments.length === 2, "arguments.length = " + arguments.length);
        ok(x === 1, "x = " + x);
        ok(y === 2, "y = " + y);
        ok(z === undefined, "z = " + z);
        return 1;
    }).bind(o, 1);
    ok(f.length === 2, "f.length = " + f.length);
    r = f.call(o2, 2);
    ok(r === 1, "r = " + r);
    ok(f.toString() === "\nfunction() {\n    [native code]\n}\n", "f.toString() = " + f.toString());
    ok(!("prototype" in f), "bound function has prototype");

    var a = [];
    f = Array.prototype.push.bind(a, 1);
    f();
    ok(a.length === 1, "a.length = " + a.length);
    f(2);
    ok(a.length === 3, "a.length = " + a.length);
    ok(f.length === 0, "f.length = " + f.length);
    ok(f.toString() === "\nfunction() {\n    [native code]\n}\n", "f.toString() = " + f.toString());
    ok(a.toString() === "1,1,2", "a = " + a);
    f.call([], 3);
    ok(a.toString() === "1,1,2,1,3", "a = " + a);

    f = (function() { return this; }).bind(a);
    ok(f() === a, "f() != a");

    f = (function() { return this; }).bind(null);
    ok(f() === window, "f() = " + f());

    var t;
    f = (function() { return t = this; }).bind(a);
    ok(new f() === t, "new f() != a");
    ok(typeof(t) === "object", "typeof(t) = " + typeof(t));
    ok(t != a, "t == a");

    ok(Function.prototype.bind.length === 1, "Function.prototype.bind.length = " + Function.prototype.bind.length);

    ((function() { ok(this === window, "bind() this = " + this); }).bind())();
    ((function() { ok(this === window, "bind(undefined) = " + this); }).bind(undefined))();
    ((function() { ok(this === window, "bind(nullDisp) = " + this); }).bind(external.nullDisp))();
    ((function() {
        ok(typeof(this) === "object", "bind(42) typeof(this) = " + typeof(this));
        ok(this.valueOf() === 42, "bind(42) this = " + this);
    }).bind(42))();

    r = (Object.prototype.toString.bind())();
    ok(r === "[object Undefined]", "toString.bind() returned " + r);
    r = (Object.prototype.toString.bind(undefined))();
    ok(r === "[object Undefined]", "toString.bind(undefined) returned " + r);
    r = (Object.prototype.toString.bind(null))();
    ok(r === "[object Null]", "toString.bind(null) returned " + r);
    r = (Object.prototype.toString.bind(external.nullDisp))();
    ok(r === "[object Null]", "toString.bind(nullDisp) returned " + r);
});

sync_test("keys", function() {
    var o = { a: 1, b: 2, c: 3 };
    var keys = Object.keys(o).sort().join();
    ok(keys === "a,b,c", "keys = " + keys);

    o = Object.create(o);
    keys = Object.keys(o).sort().join();
    ok(keys === "", "keys = " + keys);

    o.test = 1;
    keys = Object.keys(o).sort().join();
    ok(keys === "test", "keys = " + keys);

    Object.defineProperty(o, "defined", { value: 3, enumerable: false });
    keys = Object.keys(o).sort().join();
    ok(keys === "test", "keys = " + keys);

    keys = Object.keys([]).sort().join();
    ok(keys === "", "keys([]) = " + keys);

    ok(Object.keys.length === 1, "Object.keys.length = " + Object.keys.length);

    try {
        Object.keys(external.nullDisp);
        ok(false, "expected exception calling keys(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "keys(nullDisp) threw " + n);
    }
});

sync_test("getOwnPropertyNames", function() {
    var o = { a: 1, b: 2, c: 3 };
    var names = Object.getOwnPropertyNames(o).sort().join();
    ok(names === "a,b,c", "names = " + names);

    o = Object.create(o);
    names = Object.getOwnPropertyNames(o).sort().join();
    ok(names === "", "names = " + names);

    o.test = 1;
    names = Object.getOwnPropertyNames(o).sort().join();
    ok(names === "test", "names = " + names);

    Object.defineProperty(o, "defined", { value: 3, enumerable: false });
    names = Object.getOwnPropertyNames(o).sort().join();
    ok(names === "defined,test", "names = " + names);

    names = Object.getOwnPropertyNames([]).sort().join();
    todo_wine.
    ok(names === "length", "names = " + names);

    ok(Object.getOwnPropertyNames.length === 1, "Object.getOwnPropertyNames.length = " + Object.getOwnPropertyNames.length);

    try {
        Object.getOwnPropertyNames(external.nullDisp);
        ok(false, "expected exception calling getOwnPropertyNames(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "getOwnPropertyNames(nullDisp) threw " + n);
    }
});

sync_test("reduce", function() {
    var r, array;

    r = [1,2,3].reduce(function(a, value) { return a + value + 10; });
    ok(r === 26, "reduce() returned " + r);

    r = [1,2,3].reduce(function(a, value) { return a + value + 10; }, 1);
    ok(r === 37, "reduce() returned " + r);

    r = [1,2,3].reduce(function(a, value) { return a + value; }, "str");
    ok(r === "str123", "reduce() returned " + r);

    r = [1,2,].reduce(function(a, value) { return a + value; }, "str");
    ok(r === "str12", "reduce() returned " + r);

    array = [1,2,3];
    r = array.reduce(function(a, value, index, src) {
        ok(src === array, "src != array");
        return a + "(" + index + "," + value + ")";
    }, "str");
    ok(r === "str(0,1)(1,2)(2,3)", "reduce() returned " + r);

    r = [1,2,3].reduce(function(a, value, index, src) {
        src[0] = false;
        delete src[1];
        src[2] = "test";
        return a + value;
    }, "");
    ok(r === "1test", "reduce() returned " + r);

    r = [1].reduce(function(a) { return 0; });
    ok(r === 1, "[1].reduce() returned " + r);

    r = [1].reduce(function(a) { return 0; }, 2);
    ok(r === 0, "[1].reduce(2) returned " + r);

    r = [].reduce(function(a) { return 0; }, 2);
    ok(r === 2, "[].reduce(2) returned " + r);

    r = [].reduce(function(a) { return 0; }, undefined);
    ok(r === undefined, "[].reduce(undefined) returned " + r);

    try {
        [].reduce(function(a) { return 0; });
        ok(false, "expected exception");
    }catch(e) {}

    ok(Array.prototype.reduce.length === 1, "Array.prototype.reduce.length = " + Array.prototype.reduce.length);
});

sync_test("preventExtensions", function() {
    var o = {};
    var r = Object.preventExtensions(o);
    ok(r === o, "r != o");
    o.x = 1;
    ok(!("x" in o), "x property added to o");
    try {
        Object.defineProperty(o, "y", { value: true });
        ok(false, "expected exception");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }

    r = Object.preventExtensions(o);
    ok(r === o, "r != o");
    r = Object.isExtensible(o);
    ok(r === false, "isExtensible(o) returned " + r);

    function Constr() {}
    o = Object.preventExtensions(new Constr());
    Constr.prototype.prop = 1;
    ok(o.prop === 1, "o.prop = " + o.prop);
    o.prop = 2;
    ok(o.prop === 1, "o.prop = " + o.prop);
    r = Object.isExtensible(o);
    ok(r === false, "isExtensible(o) returned " + r);
    try {
        Object.defineProperty(o, "prop", { value: true });
        ok(false, "expected exception");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }

    r = Object.isExtensible({});
    ok(r === true, "isExtensible(o) returned " + r);

    try {
        Object.isExtensible(1);
        ok(false, "exception expected");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }

    o = [];
    Object.preventExtensions(o);
    try {
        o.push(1);
        ok(false, "exception expected on o.push");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }
    ok(!("0" in o), "0 is in o");
    ok(o.length === 0, "o.length = " + o.length);

    o = [1];
    Object.preventExtensions(o);
    o.pop();
    ok(!("0" in o), "0 is in o");
    ok(o.length === 0, "o.length = " + o.length);

    ok(Object.preventExtensions.length === 1, "Object.preventExtensions.length = " + Object.preventExtensions.length);
    ok(Object.isExtensible.length === 1, "Object.isExtensible.length = " + Object.isExtensible.length);

    try {
        Object.preventExtensions(external.nullDisp);
        ok(false, "expected exception calling preventExtensions(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "preventExtensions(nullDisp) threw " + n);
    }
});

sync_test("freeze", function() {
    ok(Object.freeze.length === 1, "Object.freeze.length = " + Object.freeze.length);
    try {
        Object.freeze(1);
        ok(false, "exception expected");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }

    function f() {}

    var o = {}, r;
    o.prop = 1;
    o.func = f;
    Object.defineProperty(o, "accprop", {
        get: function() {
            return r;
        },
        set: function(v) {
            r = v;
        }
    });

    test_own_data_prop_desc(o, "prop", true, true, true);
    r = Object.freeze(o);
    ok(r === o, "r != o");
    test_own_data_prop_desc(o, "prop", false, true, false);
    test_own_data_prop_desc(o, "func", false, true, false);
    ok(!Object.isExtensible(o), "o is still extensible");
    o.prop = false;
    o.func = false;
    ok(o.prop === 1, "o.prop = " + o.prop);
    ok(o.func === f, "o.func = " + o.func);

    r = 1;
    o.accprop = 2;
    ok(r === 2, "r = " + r);
    r = 3;
    ok(o.accprop === 3, "o.accprop = " + o.accprop);

    o = [1];
    Object.freeze(o);
    try {
        o.pop();
        ok(false, "exception expected on o.pop");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }
    ok(o[0] === 1, "o[0] = " + o[0]);
    ok(o.length === 1, "o.length = " + o.length);

    try {
        Object.freeze(external.nullDisp);
        ok(false, "expected exception freeze(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "freeze(nullDisp) threw " + n);
    }
});

sync_test("seal", function() {
    ok(Object.seal.length === 1, "Object.seal.length = " + Object.seal.length);
    try {
        Object.seal(1);
        ok(false, "exception expected");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }

    function f() {}

    var o = {}, r;
    o.prop = 1;
    o.func = f;
    Object.defineProperty(o, "accprop", {
        get: function() {
            return r;
        },
        set: function(v) {
            r = v;
        }
    });

    test_own_data_prop_desc(o, "prop", true, true, true);
    r = Object.seal(o);
    ok(r === o, "r != o");
    test_own_data_prop_desc(o, "prop", true, true, false);
    test_own_data_prop_desc(o, "func", true, true, false);
    ok(!Object.isExtensible(o), "o is still extensible");
    o.prop = false;
    o.func = false;
    ok(o.prop === false, "o.prop = " + o.prop);
    ok(o.func === false, "o.func = " + o.func);

    r = 1;
    o.accprop = 2;
    ok(r === 2, "r = " + r);
    r = 3;
    ok(o.accprop === 3, "o.accprop = " + o.accprop);

    o = [1];
    Object.seal(o);
    try {
        o.pop();
       ok(false, "exception expected on o.pop");
    }catch(e) {
        ok(e.name === "TypeError", "got " + e.name + " exception");
    }
    ok(o[0] === 1, "o[0] = " + o[0]);
    ok(o.length === 1, "o.length = " + o.length);

    try {
        Object.seal(external.nullDisp);
        ok(false, "expected exception calling seal(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "seal(nullDisp) threw " + n);
    }
});

sync_test("isFrozen", function() {
    var nullDisp = external.nullDisp;
    ok(Object.isFrozen.length === 1, "Object.isFrozen.length = " + Object.isFrozen.length);
    ok(Object.isSealed.length === 1, "Object.isSealed.length = " + Object.isSealed.length);

    var o = Object.freeze({});
    ok(Object.isFrozen(o) === true, "o is not frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    ok(Object.isFrozen({}) === false, "{} is frozen");
    ok(Object.isSealed({}) === false, "{} is sealed");

    o = Object.preventExtensions({});
    ok(Object.isFrozen(o) === true, "o is not frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = Object.preventExtensions({ prop: 1 });
    ok(Object.isFrozen(o) === false, "o is frozen");
    ok(Object.isSealed(o) === false, "o is sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = Object.freeze({ prop: 1 });
    ok(Object.isFrozen(o) === true, "o is not frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = Object.seal({ prop: 1 });
    ok(Object.isFrozen(o) === false, "o is frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = {};
    Object.defineProperty(o, "prop", { value: 1 });
    Object.preventExtensions(o);
    ok(Object.isFrozen(o) === true, "o is not frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = {};
    Object.defineProperty(o, "prop", { value: 1, writable: true });
    Object.preventExtensions(o);
    ok(Object.isFrozen(o) === false, "o is frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = {};
    Object.defineProperty(o, "prop", { value: 1, writable: true, configurable: true });
    Object.preventExtensions(o);
    ok(Object.isFrozen(o) === false, "o is frozen");
    ok(Object.isSealed(o) === false, "o is sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = {};
    Object.defineProperty(o, "prop", { value: 1, configurable: true });
    Object.preventExtensions(o);
    ok(Object.isFrozen(o) === false, "o is frozen");
    ok(Object.isSealed(o) === false, "o is sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    o = {};
    Object.defineProperty(o, "prop", { get: function() {}, set: function() {} });
    Object.preventExtensions(o);
    ok(Object.isFrozen(o) === true, "o is not frozen");
    ok(Object.isSealed(o) === true, "o is not sealed");
    ok(Object.isExtensible(o) === false, "o is extensible");

    try {
        Object.isFrozen(nullDisp);
        ok(false, "expected exception calling isFrozen(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "isFrozen(nullDisp) threw " + n);
    }
    try {
        Object.isSealed(nullDisp);
        ok(false, "expected exception calling isSealed(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "isSealed(nullDisp) threw " + n);
    }
    try {
        Object.isExtensible(nullDisp);
        ok(false, "expected exception calling isExtensible(nullDisp)");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_OBJECT_EXPECTED, "isExtensible(nullDisp) threw " + n);
    }
});

sync_test("JSON.parse escapes", function() {
    var i, valid = [ "b", "t", "n", "f", "r", "u1111", '"', "/" ];

    for(i = 0; i < valid.length; i++) {
        var a = JSON.parse('"\\' + valid[i] + '"'), b = eval('"\\' + valid[i] + '"');
        ok(a === b, "JSON.parse with \\" + valid[i] + " returned " + a);
    }

    var invalid = [ "0", "00", "05", "x20", "i", "'" ];

    for(i = 0; i < invalid.length; i++) {
        try {
            JSON.parse('"\\' + invalid[i] + '"');
            ok(false, "expected exception calling JSON.parse with \\" + invalid[i]);
        } catch(e) {
            ok(e.number === 0xa03f6 - 0x80000000, "calling JSON.parse with \\" + invalid[i] + " threw " + e.number);
        }
    }
});

sync_test("RegExp", function() {
    var r;

    r = /()/.exec("")[1];
    ok(r === "", "/()/ captured: " + r);
    r = /()?/.exec("")[1];
    ok(r === undefined, "/()?/ captured: " + r);
    r = /()??/.exec("")[1];
    ok(r === undefined, "/()??/ captured: " + r);
    r = /()*/.exec("")[1];
    ok(r === undefined, "/()*/ captured: " + r);
    r = /()??()/.exec("");
    ok(r[1] === undefined, "/()??()/ [1] captured: " + r);
    ok(r[2] === "", "/()??()/ [2] captured: " + r);

    try {
        r = new RegExp("(?<a>b)", "g");
        ok(false, "expected exception with /(?<a>b)/ regex");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_UNEXPECTED_QUANTIFIER, "/(?<a>b)/ regex threw " + n);
    }
});

sync_test("ArrayBuffers & Views", function() {
    var i, r, buf, buf2, view, view2, arr;

    var types = [
        [ "Int8",    1 ],
        [ "Uint8",   1 ],
        [ "Int16",   2 ],
        [ "Uint16",  2 ],
        [ "Int32",   4 ],
        [ "Uint32",  4 ],
        [ "Float32", 4 ],
        [ "Float64", 8 ]
    ];

    function test_own_props(obj_name, props) {
        var obj = eval(obj_name);
        for(var i = 0; i < props.length; i++)
            ok(Object.prototype.hasOwnProperty.call(obj, props[i]), props[i] + " not a property of " + obj_name);
    }

    function test_not_own_props(obj_name, props) {
        var obj = eval(obj_name);
        for(var i = 0; i < props.length; i++)
            ok(!Object.prototype.hasOwnProperty.call(obj, props[i]), props[i] + " is a property of " + obj_name);
    }

    function test_readonly(obj, prop, val) {
        var name = Object.getPrototypeOf(obj).constructor.toString();
        name = name.substring(9, name.indexOf("(", 9)) + ".prototype." + prop;
        obj[prop] = val + 42;
        ok(obj[prop] === val, name + " not read-only");
    }

    test_own_props("ArrayBuffer", [ "isView" ]);
    test_own_props("ArrayBuffer.prototype", [ "byteLength", "slice" ]);
    test_own_data_prop_desc(ArrayBuffer.prototype, "byteLength", false, false, false);

    r = Object.prototype.toString.call(new ArrayBuffer());
    ok(r === "[object ArrayBuffer]", "Object toString(new ArrayBuffer()) = " + r);
    r = ArrayBuffer.length;
    ok(r === 1, "ArrayBuffer.length = " + r);
    r = ArrayBuffer.isView.length;
    ok(r === 1, "ArrayBuffer.isView.length = " + r);
    r = ArrayBuffer.prototype.slice.length;
    ok(r === 2, "ArrayBuffer.prototype.slice.length = " + r);

    try {
        ArrayBuffer.prototype.slice.call(null);
        ok(false, "ArrayBuffer: calling slice with null context did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_ARRAYBUFFER_EXPECTED, "ArrayBuffer: calling slice with null context threw " + n);
    }
    try {
        ArrayBuffer.prototype.slice.call({});
        ok(false, "ArrayBuffer: calling slice with an object context did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_ARRAYBUFFER_EXPECTED, "ArrayBuffer: calling slice with an object context threw " + n);
    }
    try {
        new ArrayBuffer(-1);
        ok(false, "new ArrayBuffer(-1) did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_INVALID_LENGTH, "new ArrayBuffer(-1) threw " + n);
    }

    buf = new ArrayBuffer();
    ok(buf.byteLength === 0, "ArrayBuffer().byteLength = " + buf.byteLength);
    buf = new ArrayBuffer(13.1);
    ok(buf.byteLength === 13, "ArrayBuffer(13).byteLength = " + buf.byteLength);
    buf = ArrayBuffer("10");
    ok(buf.byteLength === 10, "ArrayBuffer(10).byteLength = " + buf.byteLength);
    test_readonly(buf, "byteLength", 10);
    test_own_data_prop_desc(buf, "byteLength", false, false, false);

    test_own_props("DataView.prototype", [
        "buffer", "byteLength", "byteOffset",
        "getInt8",  "setInt8",  "getUint8",  "setUint8",
        "getInt16", "setInt16", "getUint16", "setUint16",
        "getInt32", "setInt32", "getUint32", "setUint32",
        "getFloat32", "setFloat32", "getFloat64", "setFloat64"
    ]);

    r = Object.prototype.toString.call(new DataView(buf));
    ok(r === "[object Object]", "Object toString(new DataView(buf)) = " + r);
    r = DataView.length;
    ok(r === 1, "DataView.length = " + r);

    /* DataView.prototype has actual accessors, but others don't */
    arr = [ "buffer", "byteLength", "byteOffset" ];
    for(i = 0; i < arr.length; i++) {
        var prop = arr[i], desc = Object.getOwnPropertyDescriptor(DataView.prototype, prop);
        ok(!("value" in desc), "DataView: value is in desc");
        ok(!("writable" in desc), "DataView: writable is in desc");
        ok(desc.enumerable === false, "DataView: desc.enumerable = " + desc.enumerable);
        ok(desc.configurable === true, "DataView: desc.configurable = " + desc.configurable);
        ok(Object.getPrototypeOf(desc.get) === Function.prototype, "DataView: desc.get not a function: " + desc.get);
        ok("set" in desc, "DataView: set is not in desc");
        ok(desc.set === undefined, "DataView: desc.set not undefined: " + desc.set);
        try {
            desc.get.call(null);
            ok(false, "DataView: calling " + prop + " getter with null did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "DataView: calling " + prop + " getter with null threw " + n);
        }
        try {
            desc.get.call({});
            ok(false, "DataView: calling " + prop + " getter with an object did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "DataView: calling " + prop + " getter with an object threw " + n);
        }
        try {
            desc.get.call(DataView);
            ok(false, "DataView: calling " + prop + " getter with DataView constructor did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "DataView: calling " + prop + " getter with DataView constructor threw " + n);
        }
        try {
            desc.get.call(new ArrayBuffer());
            ok(false, "DataView: calling " + prop + " getter with ArrayBuffer did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "DataView: calling " + prop + " getter with ArrayBuffer threw " + n);
        }
        r = desc.get.call(DataView.prototype);
        if(prop === "buffer")
            ok(Object.getPrototypeOf(r) === ArrayBuffer.prototype, "DataView: calling " + prop + " getter with DataView.prototype returned " + r);
        else
            ok(r === 0, "DataView: calling " + prop + " getter with DataView.prototype returned " + r);
    }

    try {
        new DataView();
        ok(false, "new DataView() did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_DATAVIEW_NO_ARGUMENT, "new DataView() threw " + n);
    }
    try {
        new DataView(ArrayBuffer);
        ok(false, "new DataView(ArrayBuffer) did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_DATAVIEW_NO_ARGUMENT, "new DataView(ArrayBuffer) threw " + n);
    }
    try {
        new DataView(buf, -1);
        ok(false, "new DataView(buf, -1) did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_DATAVIEW_INVALID_OFFSET, "new DataView(buf, -1) threw " + n);
    }
    try {
        new DataView(buf, 11);
        ok(false, "new DataView(buf, 11) did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_DATAVIEW_INVALID_OFFSET, "new DataView(buf, 11) threw " + n);
    }
    try {
        new DataView(buf, 9, 2);
        ok(false, "new DataView(buf, 9, 2) did not throw exception");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_DATAVIEW_INVALID_OFFSET, "new DataView(buf, 9, 2) threw " + n);
    }

    view = new DataView(buf, 9, 1);
    ok(view.buffer === buf,  "DataView(buf, 9, 1).buffer = " + view.buffer);
    ok(view.byteLength === 1, "DataView(buf, 9, 1).byteLength = " + view.byteLength);
    ok(view.byteOffset === 9, "DataView(buf, 9, 1).byteOffset = " + view.byteOffset);
    test_readonly(view, "byteLength", 1);
    test_readonly(view, "byteOffset", 9);
    test_not_own_props("view", [ "buffer", "byteLength", "byteOffset" ]);

    view = new DataView(buf, 10);
    ok(view.buffer === buf,  "DataView(buf, 10).buffer = " + view.buffer);
    ok(view.byteLength === 0, "DataView(buf, 10).byteLength = " + view.byteLength);
    ok(view.byteOffset === 10, "DataView(buf, 10).byteOffset = " + view.byteOffset);
    view = new DataView(buf, 1, 7);
    ok(view.buffer === buf,  "DataView(buf, 1, 7).buffer = " + view.buffer);
    ok(view.byteLength === 7, "DataView(buf, 1, 7).byteLength = " + view.byteLength);
    ok(view.byteOffset === 1, "DataView(buf, 1, 7).byteOffset = " + view.byteOffset);
    view2 = new DataView(buf, 6);
    ok(view2.buffer === buf,  "DataView(buf, 6).buffer = " + view2.buffer);
    ok(view2.byteLength === 4, "DataView(buf, 6).byteLength = " + view2.byteLength);
    ok(view2.byteOffset === 6, "DataView(buf, 6).byteOffset = " + view2.byteOffset);
    view = DataView(buf);
    ok(view.buffer === buf,  "DataView(buf).buffer = " + view.buffer);
    ok(view.byteLength === 10, "DataView(buf).byteLength = " + view.byteLength);
    ok(view.byteOffset === 0,  "DataView(buf).byteOffset = " + view.byteOffset);

    for(i = 0; i < 10; i++) {
        r = view.getInt8(i);
        ok(r === 0, "view byte " + i + " = " + r);
    }

    for(i = 0; i < types.length; i++) {
        var method = "get" + types[i][0], offs = 11 - types[i][1];
        r = DataView.prototype[method].length;
        ok(r === 1, "DataView.prototype." + method + ".length = " + r);
        try {
            view[method]();
            ok(false, "view." + method + "() did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_NO_ARGUMENT, "view." + method + "() threw " + n);
        }
        try {
            view[method](-1);
            ok(false, "view." + method + "(-1) did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_INVALID_ACCESS, "view." + method + "(-1) threw " + n);
        }
        try {
            view[method](offs);
            ok(false, "view." + method + "(" + offs + ") did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_INVALID_ACCESS, "view." + method + "(" + offs + ") threw " + n);
        }
        try {
            view[method].call(null, 0);
            ok(false, "view." + method + "(0) with null context did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "view." + method + "(0) with null context threw " + n);
        }
        try {
            view[method].call({}, 0);
            ok(false, "view." + method + "(0) with an object context did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "view." + method + "(0) with an object context threw " + n);
        }
        method = "set" + types[i][0];
        r = DataView.prototype[method].length;
        ok(r === 1, "DataView.prototype." + method + ".length = " + r);
        try {
            view[method]();
            ok(false, "view." + method + "() did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_NO_ARGUMENT, "view." + method + "() threw " + n);
        }
        try {
            view[method](0);
            ok(false, "view." + method + "(0) did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_NO_ARGUMENT, "view." + method + "(0) threw " + n);
        }
        try {
            view[method](-1, 0);
            ok(false, "view." + method + "(-1, 0) did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_INVALID_ACCESS, "view." + method + "(-1, 0) threw " + n);
        }
        try {
            view[method](offs, 0);
            ok(false, "view." + method + "(" + offs + ", 0) did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_DATAVIEW_INVALID_ACCESS, "view." + method + "(" + offs + ", 0) threw " + n);
        }
        try {
            view[method].call(null, 0, 0);
            ok(false, "view." + method + "(0, 0) with null context did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "view." + method + "(0, 0) with null context threw " + n);
        }
        try {
            view[method].call({}, 0, 0);
            ok(false, "view." + method + "(0, 0) with an object context did not throw exception");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === JS_E_NOT_DATAVIEW, "view." + method + "(0, 0) with an object context threw " + n);
        }
    }

    r = view.setInt8(1, -257);
    ok(r === undefined, "view.setInt8(1, -1) returned " + r);
    r = view.getUint16(0);
    ok(r === 255, "view.getUint16(0) returned " + r);
    r = view.getUint16(0, true);
    ok(r === 65280, "view.getUint16(0, true) returned " + r);
    r = view.setUint32(2, "12345678", true);
    ok(r === undefined, "view.setUint32(2, '12345678', true) returned " + r);
    r = view.getInt32(1);
    ok(r === -11640388, "view.getInt32(1) returned " + r);
    r = view.setInt16(3, 65535, true);
    ok(r === undefined, "view.setInt16(3, 65535) returned " + r);
    r = view.getUint16(3);
    ok(r === 65535, "view.getUint16(3) returned " + r);
    r = view.setUint32(0, -2, true);
    ok(r === undefined, "view.setUint32(0, -2) returned " + r);
    r = view.getInt32(0, true);
    ok(r === -2, "view.getInt32(0) returned " + r);
    r = view.setFloat32(6, 1234.5, true);
    ok(r === undefined, "view.setFloat32(6, 1234.5) returned " + r);
    r = view2.getFloat32(0, true);
    ok(r === 1234.5, "view2.getFloat32(0) returned " + r);

    r = buf.slice(-9, 1);
    ok(r instanceof ArrayBuffer, "buf.slice did not return an ArrayBuffer");
    ok(r.byteLength === 0, "buf.slice(-9, 1).byteLength = " + r.byteLength);
    r = buf.slice();
    ok(r.byteLength === 10, "buf.slice().byteLength = " + r.byteLength);
    r = buf.slice(9, 16);
    ok(r.byteLength === 1, "buf.slice(9, 16).byteLength = " + r.byteLength);
    r = buf.slice(-9, -1);
    ok(r.byteLength === 8, "buf.slice(-9, -1).byteLength = " + r.byteLength);

    /* setters differing only in signedness have identical behavior, but they're not the same methods */
    ok(view.setInt8 !== view.setUint8, "setInt8 and setUint8 are the same method");
    ok(view.setInt16 !== view.setUint16, "setInt16 and setUint16 are the same method");
    ok(view.setInt32 !== view.setUint32, "setInt32 and setUint32 are the same method");

    /* slice makes a copy */
    buf2 = buf.slice(-9);
    ok(buf2.byteLength === 9, "buf.slice(-9).byteLength = " + buf2.byteLength);
    view2 = DataView(buf2, 1);
    ok(view2.byteLength === 8, "buf.slice(-9) view(1).byteLength = " + view2.byteLength);

    r = view2.getUint32(0);
    ok(r === 4294967040, "buf.slice(-9) view(1).getUint32(0) returned " + r);
    view2.setInt16(0, -5);
    r = view2.getUint16(1);
    ok(r === 64511, "buf.slice(-9) view(1).getUint16(1) returned " + r);
    r = view.getInt32(1);
    ok(r === -1, "view.getInt32(1) after slice changed returned " + r);

    r = view2.setFloat64(0, 11.875);
    ok(r === undefined, "buf.slice(-9) view(1).setFloat64(0, 11.875) returned " + r);
    r = view2.getFloat64(0);
    ok(r === 11.875, "buf.slice(-9) view(1).getFloat64(0) returned " + r);
});

sync_test("builtin_context", function() {
    var nullDisp = external.nullDisp;
    var tests = [
        [ "Array.map",              JS_E_OBJECT_EXPECTED,       function(ctx) { Array.prototype.map.call(ctx, function(a, b) {}); } ],
        [ "Array.sort",             JS_E_OBJECT_EXPECTED,       function(ctx) { Array.prototype.sort.call(ctx); } ],
        [ "Boolean.toString",       JS_E_BOOLEAN_EXPECTED,      function(ctx) { Boolean.prototype.toString.call(ctx); } ],
        [ "Date.getTime",           JS_E_DATE_EXPECTED,         function(ctx) { Date.prototype.getTime.call(ctx); } ],
        [ "Date.toGMTString",       JS_E_DATE_EXPECTED,         function(ctx) { Date.prototype.toGMTString.call(ctx); } ],
        [ "Enumerator.item",        JS_E_ENUMERATOR_EXPECTED,   function(ctx) { Enumerator.prototype.item.call(ctx); } ],
        [ "Error.toString",         JS_E_OBJECT_EXPECTED,       function(ctx) { Error.prototype.toString.call(ctx); } ],
        [ "Function.call",          JS_E_FUNCTION_EXPECTED,     function(ctx) { Function.prototype.call.call(ctx, function() {}); } ],
        [ "Map.clear",              JS_E_OBJECT_EXPECTED,       function(ctx) { Map.prototype.clear.call(ctx); } ],
        [ "Number.toFixed",         JS_E_NUMBER_EXPECTED,       function(ctx) { Number.prototype.toFixed.call(ctx); } ],
        [ "Object.isPrototypeOf",   JS_E_OBJECT_EXPECTED,       function(ctx) { Object.prototype.isPrototypeOf.call(ctx, Object); } ],
        [ "RegExp.exec",            JS_E_REGEXP_EXPECTED,       function(ctx) { RegExp.prototype.exec.call(ctx, "foobar"); } ],
        [ "Set.add",                JS_E_OBJECT_EXPECTED,       function(ctx) { Set.prototype.add.call(ctx, 5); } ],
        [ "String.search",          JS_E_OBJECT_EXPECTED,       function(ctx) { String.prototype.search.call(ctx, /foobar/g); } ],
        [ "String.trim",            JS_E_OBJECT_EXPECTED,       function(ctx) { String.prototype.trim.call(ctx); } ],
        [ "VBArray.dimensions",     JS_E_VBARRAY_EXPECTED,      function(ctx) { VBArray.prototype.dimensions.call(ctx); } ]
    ];

    /* make global object suitable for some calls */
    window[0] = "foo";
    window[1] = "bar";
    window.length = 2;

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
        try {
            tests[i][2](nullDisp);
            ok(false, "expected exception calling " + tests[i][0] + " with nullDisp context");
        }catch(ex) {
            var n = ex.number >>> 0;
            ok(n === tests[i][1], tests[i][0] + " with nullDisp context exception code = " + n);
        }
    }

    var obj = (function() { return this; }).call(null);
    ok(obj === window, "obj = " + obj);
    var obj = (function() { return this; }).call(undefined);
    ok(obj === window, "obj = " + obj);
    obj = (function() { return this; }).call(42);
    ok(obj.valueOf() === 42, "obj = " + obj);

    obj = Object.create([100]);
    ok(obj.length === 1, "obj.length = " + obj.length);
});

sync_test("host this", function() {
    var tests = [ undefined, null, external.nullDisp, function() {}, [0], "foobar", true, 42, new Number(42), external.testHostContext(true), window, document ];
    var i, obj = Object.create(Function.prototype);

    // only pure js objects are passed as 'this' (regardless of prototype)
    [137].forEach(external.testHostContext(true), obj);
    Function.prototype.apply.call(external.testHostContext(true), obj, [137, 0, {}]);

    for(i = 0; i < tests.length; i++) {
        [137].forEach(external.testHostContext(false), tests[i]);
        Function.prototype.apply.call(external.testHostContext(false), tests[i], [137, 0, {}]);
    }
});

sync_test("head_setter", function() {
    document.head = "";
    ok(typeof(document.head) === "object", "typeof(document.head) = " + typeof(document.head));
});


sync_test("declaration_let", function() {
    ok(typeof(func) === "undefined", "typeof(func)  = " + typeof(func));
    with(new Object()) {
        var x = false && function func() {};
    }
    ok(typeof(func) === "undefined", "typeof(func)  = " + typeof(func));

    function expect_exception(func, todo) {
        try {
            func();
        }catch(e) {
            return;
        }
        if (typeof todo === 'undefined' || !todo)
            ok(false, "expected exception");
        else
            todo_wine.ok(false, "expected exception");
    }

    function call_func(f, expected_a)
    {
        f(2, expected_a);
    }

    ok(a === undefined, "a is not undefined");
    var a = 3;

    {
        let a = 2;
        let b

        ok(typeof b === 'undefined', "b is defined");
        ok(b === undefined, "b !== undefined");

        ok(a == 2, "a != 2");

        a = 4;
        ok(a == 4, "a != 4");

        eval('ok(a == 4, "eval: a != 4"); b = a; a = 5;')
        ok(b == 4, "b != 4");
        ok(a == 5, "a != 5");

        function func1()
        {
            ok(typeof b === 'undefined', "func1: b is defined");
            ok(b === undefined, "func1: should produce exception");
            let b = 1;
        }
        expect_exception(func1, true);

        function func2()
        {
            let b = 1;
            ok(b == 1, "func2: b != 1");
        }
        func2();

        var w = 8;
        with({w: 9})
        {
            {
                let c = 5

                function func3(b, expected)
                {
                    var b = 2

                    ok(typeof d === 'undefined', "d is defined");

                    ok(c == expected, "func3: c != expected");
                    ok(w == 9, "w != 9")
                    ok(b == 2, "func3: b != 2");
                    b = 3;
                    ok(b == 3, "func3: b != 3");
                    ok(a == expected, "func3: a != expected");
                    a = 6;
                    c = 6;
                }

                let f3 = func3
                let f4 = function()
                    {
                        ok(a == 6, "f4: a != 6");
                    }

                ok(a == 5, "tmp 2 a != 5");
                ok(c == 5, "c != 5");
                func3(1, 5)
                ok(c == 6, "c != 6");
                call_func(func3, 6);
                f3(1, 6)
                ok(a == 6, "a != 6");
                ok(b == 4, "b != 4");
                ok(c == 6, "c != 6");

                call_func(f4);
                f4();
            }
        }
        {
            let c = 4;
            let d = 1;

            func3(1, 6);
        }
    }

    ok(a == 3, "a != 3");

    var except = false

    try
    {
        eval('if (true) let a = 3');
    }
    catch (e)
    {
        except = true;
    }
    ok(except, "with({w:9}) let a = 3: expected exception.");

    let for_count = 0;
    for (let for_i1 = 0, for_i2 = 1; for_i1 < 3; ++for_i1, ++for_i2, ++for_count)
    {
        let for_i2 = 10;

        ok(for_i2 == 10, "for_i2 != 10");
    }

    ok(typeof for_i1 == 'undefined', "for_i1 is defined");
    ok(typeof for_i2 == 'undefined', "for_i2 is defined");
    ok(for_count == 3, "for_count != 3");
});

sync_test("let scope instances", function() {
    var a = [], i;
    for(i = 0; i < 3; i++) {
        a[i] = function() { return v; };
        let v = i;
    }
    for(i = 0; i < 3; i++)
        ok(a[i]() == i, "a[" + i + "]() = " + a[i]());

    ok(typeof f == 'undefined', "f is defined");

    for(i = 0; i < 3; i++) {
        function f() { return v; }
        a[i] = f;
        let v = i;
    }
    for(i = 0; i < 3; i++)
        ok(a[i]() == i, "a[" + i + "]() = " + a[i]());

    ok(f() == 2, "f() = " + f());
});

sync_test("substituted this", function() {
    try {
        ((function() { var f = Number.prototype.toString; return (function() { return f(); }); })())();
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === JS_E_NUMBER_EXPECTED, "Number.toString threw " + n);
    }

    var r = ((function() { var f = Object.prototype.toString; return (function() { return f(); }); })())();
    ok(r === "[object Undefined]", "detached scope Object.toString returned " + r);

    var r = (function() { this.f = Object.prototype.toString; return this.f(); })();
    ok(r === "[object Window]", "Object.toString returned " + r);

    var r = (function() { var f = Object.prototype.toString; return f(); })();
    ok(r === "[object Undefined]", "Object.toString returned " + r);

    var r = ((function() { return (function() { return this; }); })())();
    ok(r === window, "detached scope this = " + r);
});

sync_test("functions scope", function() {
    function f(){ return 1; }
    function f(){ return 2; }

    var f0 = f, f1, f2, f3, i, o, a = [];
    ok(f0() === 2, "f0() = " + f0());

    {
        f1 = f;
        function f() { return 3; }
        ok(f1 === f, "f1 != f");
        ok(f0 != f1, "f0 == f1");
    }
    ok(f === f1, "f != f1");

    for(i = 0; i < 3; i++) {
        a[i] = f;
        function f() {}
        ok(f === a[i], "f != a[i]");
    }
    ok(a[0] != a[1], "a[0] == a[1]");
    ok(a[1] != a[2], "a[1] == a[2]");
    ok(f === a[2], "f != a[2]");

    {
        f2 = f;
        ok(f() === 4, "f() = " + f());
        function f() { return 4; }

        {
            f3 = f;
            ok(f() === 5, "f() = " + f());
            function f() { return 5;}
        }
        ok(f() === 4, "f() = " + f());
        ok(f === f2, "f != f2");
    }
    ok(f === f3, "f != f3");

    with(o = {f: 1}) {
        ok(f === 1, "f != 1");
        {
            ok(f() === 6, "f() = " + f());
            function f() { return 6; }
        }
        ok(f === 1, "f != 1");
        delete o.f;
        ok(f() === 6, "f() = " + f());
    }

    if(false) {
        function f() { throw "unexpected call"; }
    }
    ok(f() === 6, "f() = " + f());

    /* 'with' has no effect for function defined in a single statement context. */
    let w = 8;
    with({w:10, value:11})
        function with_function()
        {
            var except

            ok(w == 8, "w != 8");
            except = false;
            try
            {
                ok(value === undefined, "value is defined");
            }
            catch(e)
            {
                except = true;
            }
            ok(except, "with_function: expected exception");

            let ret = w;
            w = 9;
            return ret;
        }
    val = with_function();
    ok(val == 8, "val != 8");
    ok(w == 9, "w != 9");

    var func, func_outer, ret;
    var o = new Object();

    func_outer = function e()
    {
        function func_inner()
        {
            ok(typeof e == "function", "typeof e == " + typeof e);
            ret = e
        }
        func = func_inner
    }
    func_outer();
    func();
    ok(ret === func_outer, "ret != func_outer");

    func_outer = function f(f)
    {
        function func_inner()
        {
            ok(typeof f == "object", "typeof f == " + typeof f);
            ret = f
        }
        func = func_inner
    }
    func_outer(o);
    func();
    ok(ret === o, "ret != o");

    func_outer = function g() {
        var g2 = g;
        g = 10;
        ok(g !== 10, "g was redefined to 10");
        g = function() {};
        ok(g === g2, "g !== g2: " + g);
    }
    func_outer();

    function h() {
        h = 1;
        ok(h === 1, "h was not redefined: " + h);
    }
    h();
    ok(h === 1, "h = " + h);

    function h2() { return function() { h2 = 2; }; }
    h2()();
    ok(h2 === 2, "h2 = " + h2);

    (function e() {
        var f = e;
        ok(typeof(f) === "function", "f = " + f);
        (function () { e = 1; })();
        e = 2;
        ok(f === e, "f != e");
    })();
});

sync_test("console", function() {
    var except

    window.console.log('1', '2');
    console.info('1', '2', '3');
    console.info();
    console.log();
    console.trace();
    console.warn();
    console.debug();
    console.error();

    console.assert(false, '1');
    console.assert(true, '1');
    console.assert('1');

    console.clear();
    console.count('1');
    console.count(1);


    except = false;
    try
    {
        console.countReset('1');
    }
    catch(e)
    {
        except = true;
    }
    ok(except, "console.countReset: expected exception");
    console.dir(document);
    console.dir();
    console.dirxml(document);
    console.group('1');
    console.groupCollapsed('1');
    console.groupEnd();

    except = false;
    try
    {
        console.table(['1', '2']);
    }
    catch(e)
    {
        except = true;
    }
    ok(except, "console.table: expected exception");

    console.time('1');
    console.timeEnd('1');

    except = false;
    try
    {
        console.timeLog('1');
    }
    catch(e)
    {
        except = true;
    }
    ok(except, "console.timeLog: expected exception");
});

async_test("matchMedia", function() {
    var i, r, mql, expect, event_fired, event2_fired;

    try {
        mql = window.matchMedia("");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === E_INVALIDARG, "matchMedia('') threw " + n);
    }
    r = [
        [ undefined, "unknown" ],
        [ null,      "unknown" ],
        [ 42,        "not all" ],
        [{ toString: function() { return "(max-width: 0px)"; }}, "all and (max-width:0px)" ]
    ];
    for(i = 0; i < r.length; i++) {
        mql = window.matchMedia(r[i][0]);
        todo_wine_if(r[i][0] !== 42).
        ok(mql.media === r[i][1], r[i][0] + " media = " + mql.media);
        ok(mql.matches === false, r[i][0] + " matches");
    }
    mql = window.matchMedia("(max-width: 1000px)");
    ok(mql.matches === true, "(max-width: 1000px) does not match");
    mql = window.matchMedia("(max-width: 50px)");
    ok(mql.matches === false, "(max-width: 50px) matches");

    ok(!("addEventListener" in mql), "addEventListener in MediaQueryList");
    ok(!("removeEventListener" in mql), "removeEventListener in MediaQueryList");
    r = mql.addListener(null);
    ok(r === undefined, "addListener with null returned " + r);
    r = mql.removeListener(null);
    ok(r === undefined, "removeListener with null returned " + r);
    r = mql.addListener("function() { ok(false, 'string handler called'); }");
    ok(r === undefined, "addListener with string returned " + r);

    var handler = function(e) {
        ok(this === window, "handler this = " + this);
        ok(e === mql, "handler argument = " + e);
        event_fired = true;
        ok(event2_fired !== true, "second handler fired before first");
    }
    var handler2 = function(e) {
        ok(this === window, "handler2 this = " + this);
        ok(e === mql, "handler2 argument = " + e);
        event2_fired = true;
    }
    var tests = [
        [ 20, 20, function() {
            var r = mql.removeListener("function() { ok(false, 'string handler called'); }");
            ok(r === undefined, "removeListener with string returned " + r);
            r = mql.addListener(handler);
            ok(r === undefined, "addListener with function returned " + r);
        }],
        [ 120, 120, function() {
            ok(event_fired === true, "event not fired after changing from 20x20 to 120x120 view");
            mql.addListener(null);
            mql.addListener("function() { ok(false, 'second string handler called'); }");
            mql.addListener(handler2);
        }],
        [ 30, 30, function() {
            ok(event_fired === true, "event not fired after changing from 120x120 to 30x30 view");
            ok(event2_fired === true, "event not fired from second handler after changing from 120x120 to 30x30 view");
            var r = mql.removeListener(handler);
            ok(r === undefined, "removeListener with function returned " + r);
        }],
        [ 300, 300, function() {
            ok(event_fired === false, "removed event handler fired after changing from 30x30 to 300x300 view");
            ok(event2_fired === true, "event not fired from second handler after changing from 30x30 to 300x300 view");
        }]
    ];

    function test() {
        tests[i][2]();
        if(++i >= tests.length) {
            next_test();
            return;
        }
        expect = !expect;
        event_fired = event2_fired = false;
        external.setViewSize(tests[i][0], tests[i][1]);
        window.setTimeout(check);
    }

    // async dispatch once even after change confirmed, to ensure that any possible listeners are dispatched first (or not)
    function check() { window.setTimeout(mql.matches === expect ? test : check); }

    i = 0;
    expect = !mql.matches;
    external.setViewSize(tests[i][0], tests[i][1]);
    window.setTimeout(check);
});

sync_test("initProgressEvent", function() {
    var e = document.createEvent("ProgressEvent");
    e.initProgressEvent("loadend", false, false, true, 13, 42);
    ok(e.lengthComputable === true, "lengthComputable = " + e.lengthComputable);
    ok(e.loaded === 13, "loaded = " + e.loaded);
    ok(e.total === 42, "total = " + e.total);

    e.initProgressEvent("loadstart", false, false, false, 99, 50);
    ok(e.lengthComputable === false, "lengthComputable after re-init = " + e.lengthComputable);
    ok(e.loaded === 99, "loaded after re-init = " + e.loaded);
    ok(e.total === 50, "total after re-init = " + e.total);
});

sync_test("screen", function() {
    var o = screen;

    ok(typeof(o) == "object", "typeof(o) = " + typeof(o));
    ok(o instanceof Object, "o is not an instance of Object");

    o.prop = 1;
    ok(o.prop === 1, "o.prop = " + o.prop);
    ok(o.hasOwnProperty("prop"), 'o.hasOwnProperty("prop") = ' + o.hasOwnProperty("prop"));
    test_own_data_prop_desc(o, "prop", true, true, true);

    Object.defineProperty(o, "defprop", {writable: false, enumerable: false, configurable: true, value: 2});
    ok(o.defprop === 2, "o.prop = " + o.prop);
    test_own_data_prop_desc(o, "defprop", false, false, true);

    ok(typeof(Object.keys(o)) === "object", "Object.keys(o) = " + Object.keys(o));
    ok(Object.isExtensible(o) === true, "Object.isExtensible(o) = " + Object.isExtensible(o));
    ok(Object.isFrozen(o) === false, "Object.isFrozen(o) = " + Object.isFrozen(o));
    ok(Object.isSealed(o) === false, "Object.isSealed(o) = " + Object.isSealed(o));

    Object.seal(o);
    test_own_data_prop_desc(o, "prop", true, true, false);
    test_own_data_prop_desc(o, "defprop", false, false, false);
    ok(Object.isExtensible(o) === false, "Object.isExtensible(o) = " + Object.isExtensible(o));
    ok(Object.isFrozen(o) === false, "Object.isFrozen(o) = " + Object.isFrozen(o));
    ok(Object.isSealed(o) === true, "Object.isSealed(o) = " + Object.isSealed(o));

    ok(!o.hasOwnProperty("width"), 'o.hasOwnProperty("width") = ' + o.hasOwnProperty("width"));
    ok(Screen.prototype.hasOwnProperty("width"),
       'Screen.prototype.hasOwnProperty("width") = ' + Screen.prototype.hasOwnProperty("width"));

    var desc = Object.getOwnPropertyDescriptor(Screen.prototype, "width");
    ok(!("value" in desc), "width prop: value is in desc");
    ok(!("writable" in desc), "width prop: writable is in desc");
    ok(desc.enumerable === true, "width prop: enumerable = " + desc.enumerable);
    ok(desc.configurable === true, "width prop: configurable = " + desc.configurable);
    ok(Object.getPrototypeOf(desc.get) === Function.prototype, "width prop: get not a function: " + desc.get);
    ok("set" in desc, "width prop: set is not in desc");
    ok(desc.set === undefined, "width prop: set not undefined: " + desc.set);
    ok(desc.get.call(o) === o.width, "width prop: get.call() not same as o.width: " + desc.get.call(o) + ", expected " + o.width);

    o.prop2 = 3;
    ok(!("prop2" in o), "o.prop2 = " + o.prop2);

    ok(check_enum(o, "width"), "width not enumerated");
    ok(check_enum(o, "height"), "height not enumerated");
    ok(check_enum(o, "prop"), "prop not enumerated");
    ok(!check_enum(o, "defprop"), "defprop enumerated");
    ok(!check_enum(o, "prop2"), "prop2 enumerated");
});

sync_test("builtin_func", function() {
    var o = document.implementation, r;
    var f = o.hasFeature;

    ok(f instanceof Function, "f is not an instance of Function");
    ok(Object.getPrototypeOf(f) === Function.prototype, "Object.getPrototypeOf(f) = " + Object.getPrototypeOf(f));
    ok(!f.hasOwnProperty("length"), "f has own length property");
    ok(f.length === 0, "f.length = " + f.length);
    ok(f.call(o, "test", 1) === false, 'f.call(o, "test", 1) = ' + f.call(o, "test", 1));
    ok("" + f === "\nfunction hasFeature() {\n    [native code]\n}\n", "f = " + f);

    o = document.body;
    var desc = Object.getOwnPropertyDescriptor(Object.getPrototypeOf(Object.getPrototypeOf(o)), "innerHTML");
    ok(!("value" in desc), "innerHTML prop: value is in desc");
    ok(!("writable" in desc), "innerHTML prop: writable is in desc");
    ok(desc.enumerable === true, "innerHTML prop: enumerable = " + desc.enumerable);
    ok(desc.configurable === true, "innerHTML prop: configurable = " + desc.configurable);
    ok(Object.getPrototypeOf(desc.get) === Function.prototype, "innerHTML prop: get not a function: " + desc.get);
    ok(Object.getPrototypeOf(desc.set) === Function.prototype, "innerHTML prop: set not a function: " + desc.set);
    r = desc.set.call(o, '<div id="winetest"></div>');
    ok(r === undefined, "innerHTML prop: setter returned " + r);
    r = desc.get.call(o);
    ok(r === '<div id="winetest"></div>', "innerHTML prop: getter returned " + r);
    ok(r === o.innerHTML, "innerHTML prop: getter not same as o.innerHTML: " + r + ", expected " + o.innerHTML);
});

async_test("script_global", function() {
    // Created documents share script global, so their objects are instances of Object from
    // the current script context.
    var doc = document.implementation.createHTMLDocument("test");
    todo_wine.
    ok(doc instanceof Object, "created doc is not an instance of Object");
    ok(doc.implementation instanceof Object, "created doc.implementation is not an instance of Object");

    document.body.innerHTML = "";
    var iframe = document.createElement("iframe");

    // Documents created in iframe use iframe's script global, so their objects are not instances of
    // current script context Object.
    iframe.onload = guard(function() {
        var doc = iframe.contentWindow.document;
        ok(!(doc instanceof Object), "doc is an instance of Object");
        ok(!(doc.implementation instanceof Object), "doc.implementation is an instance of Object");

        doc = doc.implementation.createHTMLDocument("test");
        ok(!(doc instanceof Object), "created iframe doc is an instance of Object");
        ok(!(doc.implementation instanceof Object), "created iframe doc.implementation is an instance of Object");

        next_test();
    });

    iframe.src = "about:blank";
    document.body.appendChild(iframe);
});

sync_test("form_as_prop", function() {
    document.body.innerHTML = '<form id="testid" name="testname"></form>';
    var form = document.body.firstChild;
    var o = Object.create(document);

    ok(document.testid === form, "document.testid = " + document.testid);
    ok(o.testid === form, "o.testid = " + o.testid);
    ok(document.hasOwnProperty("testid"), 'document.hasOwnProperty("testid") = ' + document.hasOwnProperty("testid"));
    ok(!o.hasOwnProperty("testid"), 'o.hasOwnProperty("testid") = ' + o.hasOwnProperty("testid"));
    test_own_data_prop_desc(document, "testid", true, true, true);

    ok(document.testname === form, "document.testname = " + document.testname);
    ok(o.testname === form, "o.testname = " + o.testname);
    ok(document.hasOwnProperty("testname"), 'document.hasOwnProperty("testname") = ' + document.hasOwnProperty("testname"));
    ok(!o.hasOwnProperty("testname"), 'o.hasOwnProperty("testname") = ' + o.hasOwnProperty("testname"));
    test_own_data_prop_desc(document, "testname", true, true, true);
    todo_wine.
    ok(!check_enum(document, "testid"), "testid enumerated in document");
    ok(check_enum(document, "testname"), "testid not enumerated in document");
    todo_wine.
    ok(!check_enum(o, "testid"), "testid enumerated in o");
    ok(check_enum(o, "testname"), "testid not enumerated in o");

    document.body.innerHTML = '';
    ok(!("testid" in o), "testid is in o");
    ok(!("testname" in o), "testname is in o");
    ok(!("testid" in document), "testid is in document");
    ok(!("testname" in document), "testname is in document");
    ok(!document.hasOwnProperty("testid"), 'document.hasOwnProperty("testid") = ' + document.hasOwnProperty("testid"));
    ok(!document.hasOwnProperty("testname"), 'document.hasOwnProperty("testname") = ' + document.hasOwnProperty("testname"));
});

sync_test("prototypes", function() {
    var constr = DOMImplementation;
    test_own_data_prop_desc(window, "DOMImplementation", true, false, true);
    ok(Object.getPrototypeOf(DOMImplementation) === Object.prototype,
       "Object.getPrototypeOf(DOMImplementation) = " + Object.getPrototypeOf(DOMImplementation));
    todo_wine.
    ok(DOMImplementation == "[object DOMImplementation]", "DOMImplementation = " + DOMImplementation);

    var proto = constr.prototype;
    ok(proto == "[object DOMImplementationPrototype]", "DOMImplementation.prototype = " + proto);
    ok(Object.getPrototypeOf(document.implementation) === proto,
       "Object.getPrototypeOf(document.implementation) = " + Object.getPrototypeOf(document.implementation));
    ok(Object.getPrototypeOf(proto) === Object.prototype, "Object.getPrototypeOf(proto) = " + Object.getPrototypeOf(proto));

    test_own_data_prop_desc(constr, "prototype", false, false, false);
    test_own_data_prop_desc(proto, "constructor", true, false, true);
    ok(proto.hasOwnProperty("createHTMLDocument"), "prototype has no own createHTMLDocument property");
    ok(!document.implementation.hasOwnProperty("createHTMLDocument"),
       "prototype has own createHTMLDocument property");

    ok(proto.constructor === constr, "proto.constructor = " + proto.constructor);
    proto.constructor = 1;
    ok(proto.constructor === 1, "proto.constructor = " + proto.constructor + " expected 1");
    proto.constructor = constr;

    DOMImplementation = 1;
    ok(DOMImplementation === 1, "DOMImplementation = " + DOMImplementation + " expected 1");
    DOMImplementation = constr;

    ok(!HTMLBodyElement.prototype.hasOwnProperty("click"), "HTMLBodyElement prototype has own click property");
    ok(HTMLElement.prototype.hasOwnProperty("click"), "HTMLElement prototype does not have own click property");

    ok(!HTMLBodyElement.prototype.hasOwnProperty("removeChild"), "HTMLBodyElement prototype has own removeChild property");
    ok(!HTMLElement.prototype.hasOwnProperty("removeChild"), "HTMLElement prototype has own removeChild property");
    ok(!Element.prototype.hasOwnProperty("removeChild"), "Element prototype has own removeChild property");
    ok(Node.prototype.hasOwnProperty("removeChild"), "Node prototype does not have own removeChild property");

    test_own_data_prop_desc(window, "XMLHttpRequest", true, false, true);
    ok(typeof(XMLHttpRequest) === "function", "typeof(XMLHttpRequest) = " + typeof(XMLHttpRequest));
    ok(XMLHttpRequest.hasOwnProperty("create"), "XMLHttpRequest does not have create property");
    ok(Object.getPrototypeOf(XMLHttpRequest) === Function.prototype,
       "Object.getPrototypeOf(XMLHttpRequest) = " + Object.getPrototypeOf(XMLHttpRequest));
    ok(XMLHttpRequest.prototype.constructor === XMLHttpRequest,
       "XMLHttpRequest.prototype.constructor !== XMLHttpRequest");
    var xhr = new XMLHttpRequest();
    ok(Object.getPrototypeOf(xhr) === XMLHttpRequest.prototype,
       "Object.getPrototypeOf(xhr) = " + Object.getPrototypeOf(xhr));
    constr = XMLHttpRequest;
    XMLHttpRequest = 1;
    ok(XMLHttpRequest === 1, "XMLHttpRequest = " + XMLHttpRequest);
    XMLHttpRequest = constr;

    ok(Image != HTMLImageElement, "Image == HTMLImageElement");
    ok(typeof(HTMLImageElement) === "object", "typeof(HTMLImageElement) = " + typeof(HTMLImageElement));
    ok(typeof(Image) === "function", "typeof(Image) = " + typeof(Image));
    ok(Image.prototype === HTMLImageElement.prototype, "Image.prototype != HTMLImageElement.prototype");

    ok(Option != HTMLOptionElement, "Option == HTMLOptionElement");
    ok(typeof(HTMLOptionElement) === "object", "typeof(HTMLOptionElement) = " + typeof(HTMLOptionElement));
    ok(typeof(Option) === "function", "typeof(Option) = " + typeof(Option));
    ok(Option.prototype === HTMLOptionElement.prototype, "Option.prototype != HTMLOptionElement.prototype");

    ok(document.implementation instanceof DOMImplementation, "document.implementation is not an instance of DOMImplementation");
    ok(navigator instanceof Navigator, "navigator is not an instance of Navigator");
    ok(!(navigator instanceof DOMImplementation), "navigator is an instance of DOMImplementation");
    ok(document.body instanceof HTMLBodyElement, "body is not an instance of HTMLBodyElement");
    ok(document.body instanceof HTMLElement, "body is not an instance of HTMLElement");
    ok(document.body instanceof Element, "body is not an instance of Element");
    ok(document.body instanceof Node, "body is not an instance of Node");
});
  ِ  0   �� E V E N T S . J S       0           /*
 * Copyright 2017 Jacek Caban for CodeWeavers
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

var tests = [];

var test_content_loaded = (function() {
    var calls = "";

    function unexpected_call() {
        ok(false, "unexpected call");
    }

    function record_call(msg) {
        return function() { calls += msg + ","; };
    }

    window.addEventListener("DOMContentLoaded", record_call("window.capture"), true);
    window.addEventListener("DOMContentLoaded", record_call("window.bubble"), false);
    document.addEventListener("DOMContentLoaded", record_call("document.capture"), true);
    document.addEventListener("DOMContentLoaded", record_call("document.bubble"), false);

    document.attachEvent("onDOMContentLoaded", unexpected_call);
    document.attachEvent("DOMContentLoaded", unexpected_call);

    return function() {
        ok(calls === "window.capture,document.capture,document.bubble,window.bubble,",
           "calls = " + calls);
        next_test();
    };
})();

async_test("content_loaded", test_content_loaded);

sync_test("listener_order", function() {
    document.body.innerHTML = '<div></div>';
    var div = document.body.firstChild;

    var calls;
    function record_call(msg) {
        return function() { calls += msg + ","; };
    }

    window.addEventListener("click", record_call("window.click(capture)"), true);
    window.addEventListener("click", record_call("window.click(bubble)"), false);

    document.attachEvent("onclick", record_call("document.click(attached)"));
    document.addEventListener("click", record_call("document.click(capture)"), true);
    document.addEventListener("click", record_call("document.click(bubble)"), false);
    document.onclick = record_call("document.onclick");

    document.body.onclick = record_call("body.onclick");
    document.body.addEventListener("click", record_call("body.click(capture)"), true);
    document.body.addEventListener("click", record_call("body.click(bubble)"), false);
    document.body.addEventListener("click", record_call("body.click(bubble2)"));
    document.body.attachEvent("onclick", record_call("body.click(attached)"));

    div.attachEvent("onclick", record_call("div.click(attached)"));
    div.addEventListener("click", record_call("div.click(bubble)"), false);
    div.onclick = record_call("div.onclick");
    div.addEventListener("click", record_call("div.click(capture1)"), true);
    div.addEventListener("click", record_call("div.click(capture2)"), true);

    calls = "";
    div.click();
    ok(calls === "window.click(capture),document.click(capture),body.click(capture),"
       + "div.click(attached),div.click(bubble),div.onclick,div.click(capture1),"
       + "div.click(capture2),body.onclick,body.click(bubble),body.click(bubble2),"
       + "body.click(attached),document.click(attached),document.click(bubble),"
       + "document.onclick,window.click(bubble),", "calls = " + calls);

    div.onclick = record_call("new div.onclick");

    calls = "";
    div.click();
    ok(calls === "window.click(capture),document.click(capture),body.click(capture),"
       + "div.click(attached),div.click(bubble),new div.onclick,div.click(capture1),"
       + "div.click(capture2),body.onclick,body.click(bubble),body.click(bubble2),"
       + "body.click(attached),document.click(attached),document.click(bubble),"
       + "document.onclick,window.click(bubble),", "calls = " + calls);

    var e = document.createEvent("Event");
    e.initEvent("click", true, true);

    calls = "";
    div.dispatchEvent(e);
    ok(calls === "window.click(capture),document.click(capture),body.click(capture),"
       + "div.click(bubble),new div.onclick,div.click(capture1),div.click(capture2),"
       + "body.onclick,body.click(bubble),body.click(bubble2),document.click(bubble),"
       + "document.onclick,window.click(bubble),", "calls = " + calls);
});

sync_test("add_listener_in_listener", function() {
    var calls;

    document.body.innerHTML = '<div><div></div></div>';
    var div1 = document.body.firstChild;
    var div2 = div1.firstChild;

    function record_call(msg) {
        return function() { calls += msg + ","; };
    }

    div1.addEventListener("click", function() {
        div2.addEventListener("click", function() {
            calls += "div2.click";
            /* if we add more listeners here, whey won't be invoked */
            div2.onclick = function() { calls += "click2,"; };
            div2.addEventListener("click", function() { calls += "click3,"; }, false);
            div2.attachEvent("onclick", function() { calls += "click4,"; });
        }, true);
    }, true);

    calls = "";
    div2.click();
    ok(calls === "div2.click", "calls = " + calls);
});

sync_test("remove_listener_in_listener", function() {
    var calls;

    document.body.innerHTML = '<div></div>';
    var div = document.body.firstChild;

    function record_call(msg) {
        return function() { calls += msg + ","; };
    }

    var capture = record_call("capture"), bubble = record_call("bubble");

    div.addEventListener("click", function() {
        div.removeEventListener("click", capture, true);
        div.removeEventListener("click", bubble, false);
        calls += "remove,";
    }, true);

    div.addEventListener("click", capture, true);
    div.addEventListener("click", bubble, false);
    div.onclick = record_call("onclick");

    calls = "";
    div.click();
    ok(calls === "remove,capture,bubble,onclick,", "calls = " + calls);
});

sync_test("add_remove_listener", function() {
    var calls;

    document.body.innerHTML = '<div></div>';
    var div = document.body.firstChild;

    function listener() {
        calls += "listener,";
    }

    /* if the same listener is added twice, second one won't be called */
    div.addEventListener("click", listener, false);
    div.addEventListener("click", listener, false);

    calls = "";
    div.click();
    ok(calls === "listener,", "calls = " + calls);

    /* remove capture listener, it won't do anything */
    div.removeEventListener("click", listener, true);

    calls = "";
    div.click();
    ok(calls === "listener,", "calls = " + calls);

    /* remove listener once, it won't called anymore */
    div.removeEventListener("click", listener, false);

    calls = "";
    div.click();
    ok(calls === "", "calls = " + calls);

    div.removeEventListener("click", listener, false);

    /* test implicit capture removeEventListener argument */
    div.addEventListener("click", listener, false);
    div.removeEventListener("click", listener);

    calls = "";
    div.click();
    ok(calls === "", "calls = " + calls);

    /* test undefined function argument */
    div.addEventListener("click", undefined, false);

    calls = "";
    div.click();
    ok(calls === "", "calls = " + calls);

    div.addEventListener("click", listener, false);
    div.removeEventListener("click", undefined);

    calls = "";
    div.click();
    ok(calls === "listener,", "calls = " + calls);
    div.removeEventListener("click", listener);
});

sync_test("event_phase", function() {
    document.body.innerHTML = '<div><div></div></div>';
    var div1 = document.body.firstChild;
    var div2 = div1.firstChild;
    var last_event;

    function check_phase(expected_phase) {
        return function(e) {
            if(last_event)
                ok(last_event === e, "last_event != e");
            else
                last_event = e;
            ok(e.eventPhase === expected_phase,
               "eventPhase = " + e.eventPhase + " expedted " + expected_phase);
        };
    }

    div1.addEventListener("click", check_phase(1), true);
    div1.addEventListener("click", check_phase(3), false);
    div1.onclick = check_phase(3);
    div2.addEventListener("click", check_phase(2), true);
    div2.addEventListener("click", check_phase(2), false);
    div2.onclick = check_phase(2);

    div2.click();
    ok(last_event.eventPhase === 3, "last_event.eventPhase = " + last_event.eventPhase);
});

sync_test("stop_propagation", function() {
    document.body.innerHTML = '<div><div></div></div>';
    var div1 = document.body.firstChild;
    var div2 = div1.firstChild;

    var calls;
    function record_call(msg) {
        return function() { calls += msg + ","; };
    }

    function stop_propagation(e) {
        calls += "stop,";
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble before stopPropagation = " + e.cancelBubble);
        e.stopPropagation();
        e.cancelBubble_winetest = true;
        ok(e.cancelBubble === true, "cancelBubble after stopPropagation = " + e.cancelBubble);
        ok(e.bubbles === true, "bubbles = " + e.bubbles);
        ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
    }

    function stop_immediate_propagation(e) {
        calls += "immediateStop,";
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble before stopImmediatePropagation = " + e.cancelBubble);
        e.stopImmediatePropagation();
        e.cancelBubble_winetest = true;
        ok(e.cancelBubble === true, "cancelBubble after stopImmediatePropagation = " + e.cancelBubble);
        ok(e.bubbles === true, "bubbles = " + e.bubbles);
        ok(e.cancelable === true, "cancelable = " + e.cancelable);
        ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
    }

    function stop_immediate_propagation_cancel_bubble_false(e) {
        calls += "immediateStop and cancelBubble(false),";
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble before stopImmediatePropagation = " + e.cancelBubble);
        e.stopImmediatePropagation();
        e.cancelBubble = false;
        e.cancelBubble_winetest = e.eventPhase < 2 ? true : false;
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble after stopImmediatePropagation and setting cancelBubble to false = " + e.cancelBubble);
        ok(e.bubbles === true, "bubbles = " + e.bubbles);
        ok(e.cancelable === true, "cancelable = " + e.cancelable);
        ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
    }

    function cancel_bubble_impl(i) {
        return function(e) {
            calls += "cancelBubble["+i+"],";
            ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble before setting cancelBubble = " + e.cancelBubble);
            e.cancelBubble = true;
            if(e.eventPhase < 2)
                ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble after setting cancelBubble during capture phase = " + e.cancelBubble);
            else
                ok(e.cancelBubble === true, "cancelBubble after setting cancelBubble during bubble phase = " + e.cancelBubble);
            e.cancelBubble_winetest = e.cancelBubble;
            ok(e.bubbles === true, "bubbles = " + e.bubbles);
            ok(e.cancelable === true, "cancelable = " + e.cancelable);
            ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
        }
    }

    var cancel_bubble = [];
    for(var i = 0; i < 4; i++)
        cancel_bubble.push(cancel_bubble_impl(i));

    function cancel_bubble_false(e) {
        calls += "cancelBubble(false),";
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble before setting cancelBubble to false = " + e.cancelBubble);
        e.cancelBubble = false;
        if(e.cancelBubble_winetest && e.eventPhase !== 1)
            delete e.cancelBubble_winetest;
        ok(e.cancelBubble === (e.cancelBubble_winetest ? true : false), "cancelBubble after setting cancelBubble to false = " + e.cancelBubble);
        ok(e.bubbles === true, "bubbles = " + e.bubbles);
        ok(e.cancelable === true, "cancelable = " + e.cancelable);
        ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
    }

    div1.addEventListener("click", stop_immediate_propagation_cancel_bubble_false, true);
    div1.addEventListener("click", stop_propagation, true);
    div1.addEventListener("click", cancel_bubble[0], true);
    div1.addEventListener("click", cancel_bubble_false, true);
    div1.addEventListener("click", record_call("div1.click(capture)"), true);

    div2.addEventListener("click", stop_immediate_propagation, true);
    div2.addEventListener("click", cancel_bubble[1], true);
    div2.addEventListener("click", stop_propagation, true);
    div2.addEventListener("click", record_call("div2.click(capture)"), true);

    div1.addEventListener("click", cancel_bubble[2], false);
    div1.addEventListener("click", cancel_bubble_false, false);
    div1.addEventListener("click", stop_propagation, false);
    div1.addEventListener("click", record_call("div1.click(bubble)"), false);

    div2.addEventListener("click", stop_immediate_propagation_cancel_bubble_false, false);
    div2.addEventListener("click", stop_propagation, false);
    div2.addEventListener("click", cancel_bubble[3], false);
    div2.addEventListener("click", cancel_bubble_false, false);
    div2.addEventListener("click", record_call("div2.click(bubble)"), false);

    calls = "";
    div2.click();
    ok(calls === "immediateStop and cancelBubble(false),", "calls = " + calls);

    div1.removeEventListener("click", stop_immediate_propagation_cancel_bubble_false, true);
    calls = "";
    div2.click();
    ok(calls === "stop,cancelBubble[0],cancelBubble(false),div1.click(capture),", "calls = " + calls);

    div1.removeEventListener("click", stop_propagation, true);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble[0],cancelBubble(false),div1.click(capture),immediateStop,", "calls = " + calls);

    div1.removeEventListener("click", cancel_bubble[0], true);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),immediateStop,", "calls = " + calls);

    div2.removeEventListener("click", stop_immediate_propagation, true);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),cancelBubble[1],stop,div2.click(capture),immediateStop and cancelBubble(false),cancelBubble[2],",  // weird native behavior
       "calls = " + calls);

    div2.removeEventListener("click", stop_immediate_propagation_cancel_bubble_false, false);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),cancelBubble[1],stop,div2.click(capture),stop,cancelBubble[3],cancelBubble(false),div2.click(bubble),cancelBubble[2],cancelBubble(false),stop,div1.click(bubble),",
       "calls = " + calls);

    div2.removeEventListener("click", cancel_bubble_false, false);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),cancelBubble[1],stop,div2.click(capture),stop,cancelBubble[3],div2.click(bubble),",
       "calls = " + calls);

    div2.removeEventListener("click", cancel_bubble[1], true);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),stop,div2.click(capture),stop,cancelBubble[3],div2.click(bubble),",
       "calls = " + calls);

    div2.removeEventListener("click", stop_propagation, true);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),div2.click(capture),stop,cancelBubble[3],div2.click(bubble),",
       "calls = " + calls);

    div2.removeEventListener("click", stop_propagation, false);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),div2.click(capture),cancelBubble[3],div2.click(bubble),",
       "calls = " + calls);

    div2.removeEventListener("click", cancel_bubble[3], false);
    calls = "";
    div2.click();
    ok(calls === "cancelBubble(false),div1.click(capture),div2.click(capture),div2.click(bubble),cancelBubble[2],cancelBubble(false),stop,div1.click(bubble),",
       "calls = " + calls);
});

sync_test("prevent_default", function() {
    document.body.innerHTML = '<div><a href="about:blank"></a></div>';
    var div = document.body.firstChild;
    var a = div.firstChild;
    var calls;

    div.addEventListener("click", function(e) {
        ok(e.defaultPrevented === false, "e.defaultPrevented = " + e.defaultPrevented);
        e.preventDefault();
        ok(e.defaultPrevented === e.cancelable, "e.defaultPrevented = " + e.defaultPrevented);
        calls += "div,";
    }, true);

    a.addEventListener("click", function(e) {
        calls += "a,";
        ok(e.defaultPrevented === true, "e.defaultPrevented = " + e.defaultPrevented);
        ok(e.isTrusted === true, "isTrusted = " + e.isTrusted);
    }, true);

    calls = "";
    a.click();
    ok(calls === "div,a,", "calls = " + calls);

    var e = document.createEvent("Event");
    e.initEvent("click", true, false);

    calls = "";
    div.dispatchEvent(e);
    ok(calls === "div,", "calls = " + calls);

    e = document.createEvent("Event");
    e.initEvent("click", false, true);

    calls = "";
    div.dispatchEvent(e);
    ok(calls === "div,", "calls = " + calls);

    document.body.innerHTML = '<div></div>';
    var elem = document.body.firstChild;
    var e, r;

    elem.onclick = function(event) {
        event.preventDefault();
    }
    e = document.createEvent("Event");
    e.initEvent("click", true, true);
    r = elem.dispatchEvent(e);
    ok(r === false, "dispatchEvent returned " + r);

    elem.onclick = function(event) {
        event.preventDefault();
        ok(event.defaultPrevented === false, "defaultPrevented");
    }
    e = document.createEvent("Event");
    e.initEvent("click", true, false);
    r = elem.dispatchEvent(e);
    ok(r === true, "dispatchEvent returned " + r);

    elem.onclick = function(event) {
        event.stopPropagation();
    }
    e = document.createEvent("Event");
    e.initEvent("click", true, true);
    r = elem.dispatchEvent(e);
    ok(r === true, "dispatchEvent returned " + r);

    e = document.createEvent("Event");
    e.initEvent("click", false, true);
    e.preventDefault();
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);

    e = document.createEvent("Event");
    e.initEvent("click", false, true);
    elem.onclick = null;
    r = elem.dispatchEvent(e);
    ok(r === true, "dispatchEvent returned " + r);
    e.preventDefault();
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
});

sync_test("init_event", function() {
    var e = document.createEvent("Event");
    var calls;

    ok(e.type === "", "type = " + e.type);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.isTrusted === false, "isTrusted = " + e.isTrusted);

    e.initEvent("test", true, false);
    ok(e.type === "test", "type = " + e.type);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);
    ok(e.isTrusted === false, "isTrusted = " + e.isTrusted);

    e.preventDefault();
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);

    e.initEvent("NewTest", false, true);
    ok(e.type === "NewTest", "type = " + e.type);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);

    document.body.innerHTML = '<div></div>';
    var elem = document.body.firstChild;

    elem.addEventListener("NewTest", function(event) {
        ok(e === event, "e != event");
        ok(e.isTrusted === false, "isTrusted = " + e.isTrusted);

        e.preventDefault();
        ok(e.defaultPrevented === true, "defaultPrevented = " + e.defaultPrevented);

        /* initEvent no longer has effect */
        event.initEvent("test", true, false);
        ok(event.type === "NewTest", "event.type = " + event.type);
        ok(event.bubbles === false, "bubbles = " + event.bubbles);
        ok(event.cancelable === true, "cancelable = " + event.cancelable);
        ok(e.defaultPrevented === true, "defaultPrevented = " + e.defaultPrevented);

        calls++;
    }, true);

    calls = 0;
    elem.dispatchEvent(e);
    ok(calls === 1, "calls = " + calls);
    ok(e.type === "NewTest", "event.type = " + e.type);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.target === elem, "target != elem");
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);

    /* initEvent no longer has any effect except resetting defaultPrevented */
    e.initEvent("test", true, false);
    ok(e.type === "NewTest", "type = " + e.type);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.target === elem, "target != elem");
    ok(e.defaultPrevented === false, "defaultPrevented = " + e.defaultPrevented);

    calls = 0;
    elem.dispatchEvent(e);
    ok(calls === 1, "calls = " + calls);
    ok(e.type === "NewTest", "event.type = " + e.type);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.target === elem, "target != elem");

    document.body.dispatchEvent(e);
    ok(e.target === document.body, "target != body");
});

sync_test("current_target", function() {
    document.body.innerHTML = '<div><div></div></div>';
    var parent = document.body.firstChild;
    var child = parent.firstChild;
    var calls;
    var e;

    function expect_current_target(expected_target) {
        return function(event) {
            ok(event.currentTarget === expected_target, "unexpected currentTarget");
            calls++;
        }
    }

    parent.addEventListener("test", expect_current_target(parent), true);
    parent.addEventListener("test", expect_current_target(parent), false);
    child.addEventListener("test", expect_current_target(child), true);
    child.addEventListener("test", expect_current_target(child), false);

    e = document.createEvent("Event");
    e.initEvent("test", true, true);
    ok(e.currentTarget === null, "currentTarget != null");

    calls = 0;
    child.dispatchEvent(e);
    ok(calls === 4, "calls = " + calls + " expected 4");
    ok(e.currentTarget === null, "currentTarget != null");
});

sync_test("dispatch_event", function() {
    document.body.innerHTML = '<div><div></div></div>';
    var parent = document.body.firstChild;
    var child = parent.firstChild;
    var calls;
    var e;

    function record_call(msg) {
        return function(event) {
            ok(event === e, "event != e");
            ok(event.target === child, "target != child");
            ok(event.srcElement === child, "srcElement != child");
            calls += msg + ",";
        };
    }

    parent.addEventListener("click", record_call("parent.click(capture)"), true);
    parent.addEventListener("click", record_call("parent.click(bubble)"), false);
    child.addEventListener("click", record_call("child.click(capture)"), true);
    child.addEventListener("click", record_call("child.click(bubble)"), false);
    parent.addEventListener("testing", record_call("parent.testing(capture)"), true);
    parent.addEventListener("testing", record_call("parent.testing(bubble)"), false);
    child.addEventListener("testing", record_call("child.testing(capture)"), true);
    child.addEventListener("testing", record_call("child.testing(bubble)"), false);

    e = document.createEvent("Event");
    e.initEvent("click", true, true);
    ok(e.target === null, "e.target != null");
    ok(e.srcElement === null, "e.srcElement != null");

    calls = "";
    child.dispatchEvent(e);
    ok(calls === "parent.click(capture),child.click(capture),child.click(bubble),"
       + "parent.click(bubble),", "calls = " + calls);
    ok(e.target === child, "e.target != child");
    ok(e.srcElement === child, "e.srcElement != child");
    ok(e.currentTarget === null, "e.currentTarget != null");

    e = document.createEvent("Event");
    e.initEvent("click", false, true);

    calls = "";
    child.dispatchEvent(e);
    ok(calls === "parent.click(capture),child.click(capture),child.click(bubble),",
       "calls = " + calls);

    /* again, without reinitialization */
    calls = "";
    child.dispatchEvent(e);
    ok(calls === "parent.click(capture),child.click(capture),child.click(bubble),",
       "calls = " + calls);

    e = document.createEvent("Event");
    e.initEvent("testing", true, true);

    calls = "";
    child.dispatchEvent(e);
    ok(calls === "parent.testing(capture),child.testing(capture),"
       + "child.testing(bubble),parent.testing(bubble),", "calls = " + calls);

    var xhr = new XMLHttpRequest();
    xhr.addEventListener("testing", function(event) {
        ok(event === e, "event != e");
        ok(event.target === xhr, "target != child");
        ok(event.srcElement === null, "srcElement != child");
        calls += "xhr.testing";
    }, true);

    calls = "";
    xhr.dispatchEvent(e);
    ok(calls === "xhr.testing", "calls = " + calls);
});

sync_test("recursive_dispatch", function() {
    document.body.innerHTML = '<div></div><div></div>';
    var elem1 = document.body.firstChild;
    var elem2 = elem1.nextSibling;
    var calls;

    var e = document.createEvent("Event");
    ok(e.eventPhase === 0, "eventPhase = " + e.eventPhase);

    e.initEvent("test", true, true);
    ok(e.eventPhase === 0, "eventPhase = " + e.eventPhase);

    elem1.addEventListener("test", function(event_arg) {
        calls += "elem1.test,";
        ok(event_arg === e, "event_arg != e");
        try {
            elem2.dispatchEvent(e);
            ok(false, "expected exception");
        }catch(exception) {}
    }, true);

    elem2.addEventListener("test", function() {
        ok(false, "unexpected recursive event call");
    }, true);

    calls = "";
    elem1.dispatchEvent(e);
    ok(calls === "elem1.test,", "calls = " + calls);
    ok(e.eventPhase === 3, "eventPhase = " + e.eventPhase);
});

sync_test("time_stamp", function() {
    document.body.innerHTML = '<div></div>';
    var elem = document.body.firstChild;
    var calls, last_time_stamp;

    elem.onclick = function(event) {
        ok(event.timeStamp === last_time_stamp, "timeStamp = " + event.timeStamp);
        calls++;
    }

    var e = document.createEvent("Event");
    ok(typeof(e.timeStamp) === "number", "typeof(timeStamp) = " + typeof(e.timeStamp));
    ok(e.timeStamp > 0, "timeStamp = " + e.timeStamp);

    var now = (new Date()).getTime();
    last_time_stamp = e.timeStamp;
    ok(Math.abs(now - last_time_stamp) < 3, "timeStamp " + last_time_stamp + " != now " + now);

    e.initEvent("click", true, true);
    ok(e.timeStamp === last_time_stamp, "timeStamp = " + e.timeStamp);
    calls = 0;
    elem.dispatchEvent(e);
    ok(calls === 1, "calls = " + calls);
    ok(e.timeStamp === last_time_stamp, "timeStamp = " + e.timeStamp);

    elem.onclick = function(event) {
        ok(event.timeStamp > 0, "timeStamp = " + event.timeStamp);
        trace("timestamp " + event.timeStamp);
        calls++;
    }

    calls = 0;
    elem.click();
    ok(calls === 1, "calls = " + calls);
});

sync_test("mouse_event", function() {
    var e;

    e = document.createEvent("MouseEvent");
    ok(e.screenX === 0, "screenX = " + e.screenX);
    ok(e.screenY === 0, "screenY = " + e.screenY);
    ok(e.clientX === 0, "clientX = " + e.clientX);
    ok(e.clientY === 0, "clientY = " + e.clientY);
    ok(e.offsetX === 0, "offsetX = " + e.offsetX);
    ok(e.offsetY === 0, "offsetY = " + e.offsetY);
    ok(e.ctrlKey === false, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === false, "altKey = " + e.altKey);
    ok(e.shiftKey === false, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === false, "metaKey = " + e.metaKey);
    ok(e.button === 0, "button = " + e.button);
    ok(e.buttons === 0, "buttons = " + e.buttons);
    ok(e.pageX === 0, "pageX = " + e.pageX);
    ok(e.pageY === 0, "pageY = " + e.pageY);
    ok(e.which === 1, "which = " + e.which);
    ok(e.relatedTarget === null, "relatedTarget = " + e.relatedTarget);
    ok(e.toElement === null, "toElement = " + e.toElement);
    ok(e.fromElement === null, "fromElement = " + e.fromElement);

    e.initMouseEvent("test", true, true, window, 1, 2, 3, 4, 5, false, false, false, false, 1, document);
    ok(e.type === "test", "type = " + e.type);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.detail === 1, "detail = " + e.detail);
    todo_wine.
    ok(e.view === window, "view != window");
    ok(e.screenX === 2, "screenX = " + e.screenX);
    ok(e.screenY === 3, "screenY = " + e.screenY);
    ok(e.clientX === 4, "clientX = " + e.clientX);
    ok(e.clientY === 5, "clientY = " + e.clientY);
    ok(e.ctrlKey === false, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === false, "altKey = " + e.altKey);
    ok(e.shiftKey === false, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === false, "metaKey = " + e.metaKey);
    ok(e.button === 1, "button = " + e.button);
    ok(e.buttons === 0, "buttons = " + e.buttons);
    ok(e.which === 2, "which = " + e.which);
    ok(e.relatedTarget === document, "relatedTarget = " + e.relatedTarget);

    e.initMouseEvent("test", false, false, window, 9, 8, 7, 6, 5, true, true, true, true, 127, document.body);
    ok(e.type === "test", "type = " + e.type);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.detail === 9, "detail = " + e.detail);
    ok(e.screenX === 8, "screenX = " + e.screenX);
    ok(e.screenY === 7, "screenY = " + e.screenY);
    ok(e.clientX === 6, "clientX = " + e.clientX);
    ok(e.clientY === 5, "clientY = " + e.clientY);
    ok(e.ctrlKey === true, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === true, "altKey = " + e.altKey);
    ok(e.shiftKey === true, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === true, "metaKey = " + e.metaKey);
    ok(e.button === 127, "button = " + e.button);
    ok(e.which === 128, "which = " + e.which);
    ok(e.relatedTarget === document.body, "relatedTarget = " + e.relatedTarget);

    e.initEvent("testevent", true, true);
    ok(e.type === "testevent", "type = " + e.type);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.detail === 9, "detail = " + e.detail);
    ok(e.screenX === 8, "screenX = " + e.screenX);
    ok(e.screenY === 7, "screenY = " + e.screenY);
    ok(e.clientX === 6, "clientX = " + e.clientX);
    ok(e.clientY === 5, "clientY = " + e.clientY);
    ok(e.ctrlKey === true, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === true, "altKey = " + e.altKey);
    ok(e.shiftKey === true, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === true, "metaKey = " + e.metaKey);
    ok(e.button === 127, "button = " + e.button);

    e.initUIEvent("testevent", true, true, window, 6);
    ok(e.type === "testevent", "type = " + e.type);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.detail === 6, "detail = " + e.detail);
    ok(e.screenX === 8, "screenX = " + e.screenX);
    ok(e.screenY === 7, "screenY = " + e.screenY);
    ok(e.clientX === 6, "clientX = " + e.clientX);
    ok(e.clientY === 5, "clientY = " + e.clientY);
    ok(e.ctrlKey === true, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === true, "altKey = " + e.altKey);
    ok(e.shiftKey === true, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === true, "metaKey = " + e.metaKey);
    ok(e.button === 127, "button = " + e.button);
});

sync_test("ui_event", function() {
    var e;

    e = document.createEvent("UIEvent");
    ok(e.detail === 0, "detail = " + e.detail);

    e.initUIEvent("test", true, true, window, 3);
    ok(e.type === "test", "type = " + e.type);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.detail === 3, "detail = " + e.detail);
    todo_wine.
    ok(e.view === window, "view != window");
});

sync_test("keyboard_event", function() {
    var e;

    e = document.createEvent("KeyboardEvent");

    e.initEvent("test", true, true);
    ok(e.key === "", "key = " + e.key);
    ok(e.keyCode === 0, "keyCode = " + e.keyCode);
    ok(e.charCode === 0, "charCode = " + e.charCode);
    ok(e.repeat === false, "repeat = " + e.repeat);
    ok(e.ctrlKey === false, "ctrlKey = " + e.ctrlKey);
    ok(e.altKey === false, "altKey = " + e.altKey);
    ok(e.shiftKey === false, "shiftKey = " + e.shiftKey);
    ok(e.metaKey === false, "metaKey = " + e.metaKey);
    ok(e.location === 0, "location = " + e.location);
    ok(e.detail === 0, "detail = " + e.detail);
    ok(e.which === 0, "which = " + e.which);
    ok(e.locale === "", "locale = " + e.locale);
});

sync_test("custom_event", function() {
    var e = document.createEvent("CustomEvent");

    ok(e.detail === undefined, "detail = " + e.detail);

    e.initCustomEvent("test", true, false, 123);
    ok(e.type === "test", "type = " + e.type);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.detail === 123, "detail = " + e.detail);
});

async_test("error_event", function() {
    document.body.innerHTML = '<div><img></img></div>';
    var div = document.body.firstChild;
    var img = div.firstChild;
    var calls = "";

    function record_call(msg) {
        return function() { calls += msg + ","; };
    }
    var win_onerror = record_call("window.onerror");
    var doc_onerror = record_call("doc.onerror");
    var body_onerror = record_call("body.onerror");

    window.addEventListener("error", win_onerror, true);
    document.addEventListener("error", doc_onerror, true);
    document.body.addEventListener("error", body_onerror, true);
    div.addEventListener("error", record_call("div.onerror"), true);

    div.addEventListener("error", function() {
        ok(calls === "window.onerror,doc.onerror,body.onerror,div.onerror,", "calls = " + calls);

        window.removeEventListener("error", win_onerror, true);
        document.removeEventListener("error", doc_onerror, true);
        document.body.removeEventListener("error", body_onerror, true);
        next_test();
    }, true);

    img.src = "about:blank";
});

async_test("detached_img_error_event", function() {
    var img = new Image();
    img.onerror = function() {
        next_test();
    }
    img.src = "about:blank";
});

async_test("img_wrong_content_type", function() {
    var img = new Image();
    img.onload = function() {
        ok(img.width === 2, "width = " + img.width);
        ok(img.height === 2, "height = " + img.height);
        next_test();
    }
    img.src = "img.png?content-type=image/jpeg";
});

async_test("message event", function() {
    var listener_called = false, iframe = document.createElement("iframe");

    window.addEventListener("message", function(e) {
        if(listener_called) {
            ok(e.data === "echo", "e.data (diff origin) = " + e.data);
            ok(e.source === iframe.contentWindow, "e.source (diff origin) not iframe.contentWindow");
            ok(e.origin === "http://winetest.different.org:1234", "e.origin (diff origin) = " + e.origin);
            next_test();
            return;
        }
        listener_called = true;
        e.initMessageEvent("blah", true, true, "barfoo", "wine", 1234, window);
        ok(e.data === "test", "e.data = " + e.data);
        ok(e.bubbles === false, "bubbles = " + e.bubbles);
        ok(e.cancelable === false, "cancelable = " + e.cancelable);
        ok(e.source === window, "e.source = " + e.source);
        ok(e.origin === "http://winetest.example.org", "e.origin = " + e.origin);

        iframe.onload = function() { iframe.contentWindow.postMessage("echo", "hTtP://WinEtesT.difFerent.ORG:1234"); }
        iframe.src = "http://winetest.different.org:1234/xhr_iframe.html";
        document.body.appendChild(iframe);
    });

    window.postMessage("test", "httP://wineTest.example.org");
    ok(listener_called == false, "listener already called");
});
   �, <   �� D O C U M E N T M O D E . J S       0           /*
 * Copyright 2016 Jacek Caban for CodeWeavers
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

var compat_version;
var tests = [];

var svg_ns = "http://www.w3.org/2000/svg";

ok(performance.timing.navigationStart > 0, "navigationStart <= 0");
ok(performance.timing.fetchStart == performance.timing.navigationStart, "fetchStart != navigationStart");
ok(performance.timing.domainLookupStart >= performance.timing.fetchStart, "domainLookupStart < fetchStart");
ok(performance.timing.domainLookupEnd >= performance.timing.domainLookupStart, "domainLookupEnd < domainLookupStart");
ok(performance.timing.connectStart >= performance.timing.domainLookupEnd, "connectStart < domainLookupEnd");
ok(performance.timing.connectEnd >= performance.timing.connectStart, "connectEnd < connectStart");
ok(performance.timing.requestStart >= performance.timing.connectEnd, "requestStart < connectEnd");
ok(performance.timing.responseStart >= performance.timing.requestStart, "responseStart < requestStart");
ok(performance.timing.responseEnd >= performance.timing.responseStart, "responseEnd < responseStart");
ok(performance.timing.domLoading >= performance.timing.responseEnd, "domLoading < responseEnd");
ok(performance.timing.domInteractive === 0, "domInteractive != 0");
ok(performance.timing.domComplete === 0, "domComplete != 0");
ok(performance.timing.domContentLoadedEventStart === 0, "domContentLoadedEventStart != 0");
ok(performance.timing.domContentLoadedEventEnd === 0, "domContentLoadedEventEnd != 0");
ok(performance.timing.loadEventStart === 0, "loadEventStart != 0");
ok(performance.timing.loadEventEnd === 0, "loadEventEnd != 0");
ok(performance.timing.unloadEventStart === 0, "unloadEventStart != 0");
ok(performance.timing.unloadEventEnd === 0, "unloadEventEnd != 0");
ok(performance.timing.redirectStart === 0, "redirectStart != 0");
ok(performance.timing.redirectEnd === 0, "redirectEnd != 0");
ok(performance.timing.msFirstPaint === 0, "msFirstPaint != 0");

var pageshow_fired = false, pagehide_fired = false;
document.doc_unload_events_called = false;
window.onbeforeunload = function() { ok(false, "beforeunload fired"); };
window.onunload = function() {
    document.doc_unload_events_called = true;
    ok(document.readyState === "complete", "unload readyState = " + document.readyState);
    if(document.documentMode < 11)
        ok(pagehide_fired === false, "pagehide fired before unload");
    else
        ok(pagehide_fired === true, "pagehide not fired before unload");
};

if(window.addEventListener) {
    window.addEventListener("pageshow", function(e) {
        pageshow_fired = true;

        var r = Object.prototype.toString.call(e);
        ok(r === "[object PageTransitionEvent]", "pageshow toString = " + r);
        ok("persisted" in e, "'persisted' not in pageshow event");
        ok(document.readyState === "complete", "pageshow readyState = " + document.readyState);
        ok(performance.timing.loadEventEnd > 0, "loadEventEnd <= 0 in pageshow handler");
    }, true);

    window.addEventListener("pagehide", function(e) {
        pagehide_fired = true;
        ok(document.documentMode >= 11, "pagehide fired");

        var r = Object.prototype.toString.call(e);
        ok(r === "[object PageTransitionEvent]", "pagehide toString = " + r);
        ok("persisted" in e, "'persisted' not in pagehide event");
    }, true);

    document.addEventListener("visibilitychange", function() { ok(false, "visibilitychange fired"); });
    document.addEventListener("beforeunload", function() { ok(false, "beforeunload fired on document"); });
    document.addEventListener("unload", function() { ok(false, "unload fired on document"); });
}else {
    document.attachEvent("onbeforeunload", function() { ok(false, "beforeunload fired on document"); });
    document.attachEvent("onunload", function() { ok(false, "unload fired on document"); });
}

sync_test("performance timing", function() {
    ok(performance.timing.domInteractive >= performance.timing.domLoading, "domInteractive < domLoading");
    ok(performance.timing.domContentLoadedEventStart >= performance.timing.domInteractive, "domContentLoadedEventStart < domInteractive");
    ok(performance.timing.domContentLoadedEventEnd >= performance.timing.domContentLoadedEventStart, "domContentLoadedEventEnd < domContentLoadedEventStart");
    ok(performance.timing.domComplete >= performance.timing.domContentLoadedEventEnd, "domComplete < domContentLoadedEventEnd");
    ok(performance.timing.loadEventStart >= performance.timing.domComplete, "loadEventStart < domComplete");
    ok(performance.timing.loadEventEnd >= performance.timing.loadEventStart, "loadEventEnd < loadEventStart");
    ok(performance.navigation.type === 0, "navigation type = " + performance.navigation.type);
    ok(performance.navigation.redirectCount === 0, "redirectCount = " + performance.navigation.redirectCount);
});

sync_test("page transition events", function() {
    if(document.documentMode < 11)
        ok(pageshow_fired === false, "pageshow fired");
    else
        ok(pageshow_fired === true, "pageshow not fired");
    ok(pagehide_fired === false, "pagehide fired");

    if(document.body.addEventListener)
        document.body.addEventListener("unload", function() { ok(false, "unload fired on document.body"); });
    else
        document.body.attachEvent("onunload", function() { ok(false, "unload fired on document.body"); });
});

sync_test("builtin_toString", function() {
    var tags = [
        [ "abbr",            "Phrase", -1 ],
        [ "acronym",         "Phrase", -1 ],
        [ "address",         "Block", -1 ],
     // [ "applet",          "Applet" ],  // makes Windows pop up a dialog box
        [ "article",         "" ],
        [ "aside",           "" ],
        [ "audio",           "Audio", -1 ],
        [ "b",               "Phrase", -1 ],
        [ "base",            "Base", -1 ],
        [ "basefont",        "BaseFont", -1 ],
        [ "bdi",             "Unknown" ],
        [ "bdo",             "Phrase", -1 ],
        [ "big",             "Phrase", -1 ],
        [ "blockquote",      "Block", -1 ],
        [ "body",            "Body" ],
        [ "br",              "BR", -1 ],
        [ "button",          "Button" ],
        [ "canvas",          "Canvas", -1 ],
        [ "caption",         "TableCaption", -1 ],
        [ "center",          "Block", -1 ],
        [ "cite",            "Phrase", -1 ],
        [ "code",            "Phrase", -1 ],
        [ "col",             "TableCol", -1 ],
        [ "colgroup",        "TableCol", -1 ],
        [ "data",            "Unknown" ],
        [ "datalist",        "DataList", 10 ],
        [ "dd",              "DD", -1 ],
        [ "del",             "Mod", -1 ],
        [ "details",         "Unknown" ],
        [ "dfn",             "Phrase", -1 ],
        [ "dialog",          "Unknown" ],
        [ "dir",             "Directory", -1 ],
        [ "div",             "Div", -1 ],
        [ "dl",              "DList", -1 ],
        [ "dt",              "DT", -1 ],
        [ "em",              "Phrase", -1 ],
        [ "embed",           "Embed" ],
        [ "fieldset",        "FieldSet", -1 ],
        [ "figcaption",      "" ],
        [ "figure",          "" ],
        [ "font",            "Font", -1 ],
        [ "footer",          "" ],
        [ "form",            "Form" ],
        [ "frame",           "Frame" ],
        [ "frameset",        "FrameSet", -1 ],
        [ "h1",              "Heading", -1 ],
        [ "h2",              "Heading", -1 ],
        [ "h3",              "Heading", -1 ],
        [ "h4",              "Heading", -1 ],
        [ "h5",              "Heading", -1 ],
        [ "h6",              "Heading", -1 ],
        [ "h7",              "Unknown" ],
        [ "head",            "Head" ],
        [ "header",          "" ],
        [ "hr",              "HR", -1 ],
        [ "html",            "Html" ],
        [ "i",               "Phrase", -1 ],
        [ "iframe",          "IFrame" ],
        [ "img",             "Image" ],
        [ "input",           "Input" ],
        [ "ins",             "Mod", -1 ],
        [ "kbd",             "Phrase", -1 ],
        [ "label",           "Label" ],
        [ "legend",          "Legend", -1 ],
        [ "li",              "LI", -1 ],
        [ "link",            "Link" ],
        [ "main",            "Unknown" ],
        [ "map",             "Map", -1 ],
        [ "mark",            "" ],
        [ "meta",            "Meta" ],
        [ "meter",           "Unknown" ],
        [ "nav",             "" ],
        [ "noframes",        "" ],
        [ "noscript",        "" ],
        [ "object",          "Object" ],
        [ "ol",              "OList", -1 ],
        [ "optgroup",        "OptGroup", -1 ],
        [ "option",          "Option" ],
        [ "output",          "Unknown" ],
        [ "p",               "Paragraph", -1 ],
        [ "param",           "Param", -1 ],
        [ "picture",         "Unknown" ],
        [ "pre",             "Pre", -1 ],
        [ "progress",        "Progress", 10 ],
        [ "q",               "Quote", -1 ],
        [ "rp",              "Phrase", -1 ],
        [ "rt",              "Phrase", -1 ],
        [ "ruby",            "Phrase", -1 ],
        [ "s",               "Phrase", -1 ],
        [ "samp",            "Phrase", -1 ],
        [ "script",          "Script" ],
        [ "section",         "" ],
        [ "select",          "Select" ],
        [ "small",           "Phrase", -1 ],
        [ "source",          "Source", -1 ],
        [ "span",            "Span", -1 ],
        [ "strike",          "Phrase", -1 ],
        [ "strong",          "Phrase", -1 ],
        [ "style",           "Style" ],
        [ "sub",             "Phrase", -1 ],
        [ "summary",         "Unknown" ],
        [ "sup",             "Phrase", -1 ],
        [ "svg",             "Unknown" ],
        [ "table",           "Table" ],
        [ "tbody",           "TableSection", -1 ],
        [ "td",              "TableDataCell" ],
        [ "template",        "Unknown" ],
        [ "textarea",        "TextArea" ],
        [ "tfoot",           "TableSection", -1 ],
        [ "th",              "TableHeaderCell", -1 ],
        [ "thead",           "TableSection", -1 ],
        [ "time",            "Unknown" ],
        [ "title",           "Title" ],
        [ "tr",              "TableRow" ],
        [ "track",           "Track", 10 ],
        [ "tt",              "Phrase", -1 ],
        [ "u",               "Phrase", -1 ],
        [ "ul",              "UList", -1 ],
        [ "var",             "Phrase", -1 ],
        [ "video",           "Video", -1 ],
        [ "wbr",             "" ],
        [ "winetest",        "Unknown" ]
    ];
    var v = document.documentMode, e;

    function test(msg, obj, name, tostr, is_todo) {
        var s;
        if(obj.toString) {
            s = obj.toString();
            todo_wine_if(name !== "HTMLElement" && s === "[object HTMLElement]").
            ok(s === (tostr ? tostr : (v < 9 ? "[object]" : "[object " + name + "]")), msg + " toString returned " + s);
        }
        s = Object.prototype.toString.call(obj);
        todo_wine_if(v >= 9 && is_todo).
        ok(s === (v < 9 ? "[object Object]" : "[object " + name + "]"), msg + " Object.toString returned " + s);
    }

    for(var i = 0; i < tags.length; i++)
        if(tags[i].length < 3 || v >= tags[i][2])
            test("tag '" + tags[i][0] + "'", document.createElement(tags[i][0]), "HTML" + tags[i][1] + "Element", null, tags[i].length > 2);

    e = document.createElement("a");
    ok(e.toString() === "", "tag 'a' (without href) toString returned " + e.toString());
    e.href = "https://www.winehq.org/";
    test("tag 'a'", e, "HTMLAnchorElement", "https://www.winehq.org/");

    e = document.createElement("area");
    ok(e.toString() === "", "tag 'area' (without href) toString returned " + e.toString());
    e.href = "https://www.winehq.org/";
    test("tag 'area'", e, "HTMLAreaElement", "https://www.winehq.org/");

    e = document.createElement("style");
    document.body.appendChild(e);
    var sheet = v >= 9 ? e.sheet : e.styleSheet;
    if(v >= 9)
        sheet.insertRule("div { border: none }", 0);
    else
        sheet.addRule("div", "border: none", 0);

    e = document.createElement("p");
    e.className = "testclass    another ";
    e.textContent = "Test content";
    e.style.border = "1px solid black";
    document.body.appendChild(e);

    var txtRange = document.body.createTextRange();
    txtRange.moveToElementText(e);

    var clientRects = e.getClientRects();
    if(!clientRects) win_skip("getClientRects() is buggy and not available, skipping");

    var currentStyle = e.currentStyle;
    if(!currentStyle) win_skip("currentStyle is buggy and not available, skipping");

    // w10pro64 testbot VM throws WININET_E_INTERNAL_ERROR for some reason
    var localStorage;
    try {
        localStorage = window.localStorage;
    }catch(e) {
        ok(e.number === 0x72ee4 - 0x80000000, "localStorage threw " + e.number + ": " + e);
    }
    if(!localStorage) win_skip("localStorage is buggy and not available, skipping");

    test("attribute", document.createAttribute("class"), "Attr");
    if(false /* todo_wine */) test("attributes", e.attributes, "NamedNodeMap");
    test("childNodes", document.body.childNodes, "NodeList");
    if(clientRects) test("clientRect", clientRects[0], "ClientRect");
    if(clientRects) test("clientRects", clientRects, "ClientRectList");
    if(currentStyle) test("currentStyle", currentStyle, "MSCurrentStyleCSSProperties");
    if(v >= 11 /* todo_wine */) test("document", document, v < 11 ? "Document" : "HTMLDocument");
    test("elements", document.getElementsByTagName("body"), "HTMLCollection");
    test("history", window.history, "History");
    test("implementation", document.implementation, "DOMImplementation");
    if(localStorage) test("localStorage", localStorage, "Storage");
    test("location", window.location, "Object", window.location.href, null, true);
    if(v >= 11 /* todo_wine */) test("mimeTypes", window.navigator.mimeTypes, v < 11 ? "MSMimeTypesCollection" : "MimeTypeArray");
    test("navigator", window.navigator, "Navigator");
    test("performance", window.performance, "Performance");
    test("performanceNavigation", window.performance.navigation, "PerformanceNavigation");
    test("performanceTiming", window.performance.timing, "PerformanceTiming");
    if(v >= 11 /* todo_wine */) test("plugins", window.navigator.plugins, v < 11 ? "MSPluginsCollection" : "PluginArray");
    test("screen", window.screen, "Screen");
    test("sessionStorage", window.sessionStorage, "Storage");
    test("style", document.body.style, "MSStyleCSSProperties");
    test("styleSheet", sheet, "CSSStyleSheet");
    test("styleSheetRule", sheet.rules[0], "CSSStyleRule");
    test("styleSheetRules", sheet.rules, "MSCSSRuleList");
    test("styleSheets", document.styleSheets, "StyleSheetList");
    test("textNode", document.createTextNode("testNode"), "Text", v < 9 ? "testNode" : null);
    test("textRange", txtRange, "TextRange");
    test("window", window, "Window", "[object Window]");
    test("xmlHttpRequest", new XMLHttpRequest(), "XMLHttpRequest");
    if(v < 10) {
        test("namespaces", document.namespaces, "MSNamespaceInfoCollection");
    }
    if(v < 11) {
        test("eventObject", document.createEventObject(), "MSEventObj");
        test("selection", document.selection, "MSSelection");
    }
    if(v >= 9) {
        test("computedStyle", window.getComputedStyle(e), "CSSStyleDeclaration");
        test("doctype", document.doctype, "DocumentType");

        test("Event", document.createEvent("Event"), "Event");
        test("CustomEvent", document.createEvent("CustomEvent"), "CustomEvent");
        test("KeyboardEvent", document.createEvent("KeyboardEvent"), "KeyboardEvent");
        test("MouseEvent", document.createEvent("MouseEvent"), "MouseEvent");
        test("UIEvent", document.createEvent("UIEvent"), "UIEvent");
    }
    if(v >= 10) {
        test("classList", e.classList, "DOMTokenList", "testclass    another ");
        test("console", window.console, "Console");
        test("mediaQueryList", window.matchMedia("(hover:hover)"), "MediaQueryList");
    }
    if(v >= 11) {
        test("MutationObserver", new window.MutationObserver(function() {}), "MutationObserver");
    }
    if(v >= 9) {
        document.body.innerHTML = "<!--...-->";
        test("comment", document.body.firstChild, "Comment");

        test("SVGSVGElement", document.createElementNS(svg_ns, "svg"), "SVGSVGElement");
        test("SVGCircleElement", document.createElementNS(svg_ns, "circle"), "SVGCircleElement");
        test("SVGCircleElement", document.createElementNS(svg_ns, "tspan"), "SVGTSpanElement");
    }
});

sync_test("builtin_obj", function() {
    var v = document.documentMode;
    var f = document.createElement;
    var e;

    if(v < 9) {
        ok(!(window instanceof Object), "window instance of Object");
        ok(!(document instanceof Object), "document instance of Object");
        ok(!(f.apply instanceof Function), "f.apply instance of Function");
        ok(!(f.call instanceof Function), "f.call instance of Function");
        ok(!("arguments" in f), "arguments in f");
        ok(!("length" in f), "length in f");
        e = 0;
        try {
            f.toString();
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0xa01b6 - 0x80000000, "[f.toString] e = " + e);
        try {
            window.toString.call(null);
            ok(false, "expected exception calling window.toString with null context");
        }catch(ex) {}
    }else {
        ok(Object.getPrototypeOf(f) === Function.prototype, "unexpected document.createElement prototype");
        e = window.toString.call(null);
        ok(e === "[object Window]", "window.toString with null context = " + e);
        e = window.toString.call(external.nullDisp);
        ok(e === "[object Window]", "window.toString with nullDisp context = " + e);
    }

    e = 0;
    try {
        f.call(Object, "div");
    }catch(ex) {
        e = ex.number;
    }
    ok(e === (v < 9 ? 0xa0005 : 0x0ffff) - 0x80000000, "[f.call(Object, 'div')] e = " + e);

    e = 0;
    try {
        f.call(null, "div");
    }catch(ex) {
        e = ex.number;
    }
    ok(e === (v < 9 ? 0xa0005 : 0x0ffff) - 0x80000000, "[f.call(null, 'div')] e = " + e);

    var elem1 = f.call(document, "div");
    var elem2 = f.call(document, "br");
    document.body.appendChild(elem1);
    document.body.appendChild(elem2);
    elem1.onclick = function() { ok(false, "unexpected elem1.onclick"); };
    var clicked = false;
    elem2.onclick = function() { clicked = true; };
    elem1.click.call(elem2);
    ok(clicked === true, "elem2.onclick not called");

    elem1 = f.apply(document, ["div"]);
    elem2 = f.apply(document, ["br"]);
    document.body.appendChild(elem1);
    document.body.appendChild(elem2);
    elem1.onclick = function() { ok(false, "unexpected elem1.onclick"); };
    clicked = false;
    elem2.onclick = function() { clicked = true; };
    elem1.click.apply(elem2);
    ok(clicked === true, "elem2.onclick not called");

    try {
        elem1.click.apply(elem2, { length: -1 });
        ok(false, "exception expected");
    }catch(ex) {}

    e = 0;
    try {
        new f();
    }catch(ex) {
        e = ex.number;
    }
    ok(e === (v < 9 ? 0xa01b6 : 0x0ffff) - 0x80000000, "[new f()] e = " + e);

    if(v < 9) {
        ok(!("call" in f.call), "call in f.call");
        ok(!("apply" in f.call), "apply in f.call");
        ok(!("call" in f.apply), "call in f.apply");
        ok(!("apply" in f.apply), "apply in f.apply");
        ok(f.call+"" === "\nfunction call() {\n    [native code]\n}\n", "f.call = " + f.call);
        ok(f.apply+"" === "\nfunction apply() {\n    [native code]\n}\n", "f.apply = " + f.apply);
        ok(external.getVT(f.call) === "VT_DISPATCH", "f.call not VT_DISPATCH");
        ok(external.getVT(f.apply) === "VT_DISPATCH", "f.apply not VT_DISPATCH");

        ok(f.apply !== f.apply, "f.apply == f.apply");
        f = f.apply;
        ok(!("arguments" in f), "arguments in f.apply");
        ok(!("length" in f), "length in f.apply");
        ok(!("call" in f), "call in f.apply");
        ok(!("apply" in f), "apply in f.apply");
        e = 0;
        try {
            f.toString();
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0xa01b6 - 0x80000000, "[f.apply.toString] e = " + e);
        e = 0;
        try {
            f(document, ["style"]);
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0xa01b6 - 0x80000000, "[f.apply() indirect] e = " + e);

        var enumerator = new Enumerator(document.getElementsByTagName("br"));
        enumerator.moveNext();
        var enum_elem = enumerator.item();
        ok(enum_elem === elem2, "enum_elem = " + enum_elem);
        enumerator.moveNext();
        ok(enumerator.atEnd(), "enumerator not at end");
    }else {
        elem = f.call.call(f, document, "div");
        f = f.bind(document);
        elem = f.apply(null, ["style"]);
        document.body.appendChild(elem);

        try {
            var enumerator = new Enumerator(document.getElementsByTagName("style"));
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0xa01c3 - 0x80000000, "[style Enumerator] e = " + e);

        f.apply = 0;
        f.call = function() { };
        ok(f.apply === 0, "changed f.apply = ", f.apply);
        ok(f.call instanceof Function, "changed f.call not instance of Function");
    }
});

sync_test("elem_props", function() {
    var elem = document.documentElement;

    function test_exposed(prop, expect, is_todo) {
        var ok_ = is_todo ? todo_wine.ok : ok;
        if(expect)
            ok_(prop in elem, prop + " not found in element.");
        else
            ok_(!(prop in elem), prop + " found in element.");
    }

    var v = document.documentMode;

    test_exposed("attachEvent", v < 11);
    test_exposed("detachEvent", v < 11);
    test_exposed("doScroll", v < 11);
    test_exposed("readyState", v < 11);
    test_exposed("clientTop", true);
    test_exposed("title", true);
    test_exposed("querySelectorAll", v >= 8);
    test_exposed("textContent", v >= 9);
    test_exposed("prefix", v >= 9);
    test_exposed("firstElementChild", v >= 9);
    test_exposed("onsubmit", v >= 9);
    test_exposed("getElementsByClassName", v >= 9);
    test_exposed("removeAttributeNS", v >= 9);
    test_exposed("addEventListener", v >= 9);
    test_exposed("hasAttribute", v >= 8, v === 8);
    test_exposed("removeEventListener", v >= 9);
    test_exposed("dispatchEvent", v >= 9);
    test_exposed("msSetPointerCapture", v >= 10);
    if (v >= 9) test_exposed("spellcheck", v >= 10);

    elem = document.createElement("style");
    test_exposed("media", true);
    test_exposed("type", true);
    test_exposed("disabled", true);
    test_exposed("media", true);
    test_exposed("sheet", v >= 9);
    test_exposed("readyState", v < 11);
    test_exposed("styleSheet", v < 11);
    test_exposed("classList", v >= 10);

    elem = document.createElement("img");
    test_exposed("fileSize", v < 11);
});

sync_test("doc_props", function() {
    function test_exposed(prop, expect, is_todo) {
        var ok_ = is_todo ? todo_wine.ok : ok;
        if(expect)
            ok_(prop in document, prop + " not found in document.");
        else
            ok_(!(prop in document), prop + " found in document.");
    }

    var v = document.documentMode;
    ok(document.mimeType === external.getExpectedMimeType("text/html"), "mimeType = " + document.mimeType);

    test_exposed("attachEvent", v < 11);
    test_exposed("detachEvent", v < 11);
    test_exposed("createStyleSheet",v < 11);
    test_exposed("fileSize", v < 11);
    test_exposed("selection", v < 11);
    test_exposed("onstorage", v < 9);
    test_exposed("textContent", v >= 9);
    test_exposed("prefix", v >= 9);
    test_exposed("defaultView", v >= 9);
    test_exposed("head", v >= 9);
    test_exposed("addEventListener", v >= 9);
    test_exposed("removeEventListener", v >= 9);
    test_exposed("dispatchEvent", v >= 9);
    test_exposed("createEvent", v >= 9);

    test_exposed("parentWindow", true);
    if(v >= 9) ok(document.defaultView === document.parentWindow, "defaultView != parentWindow");
});

sync_test("docfrag_props", function() {
    var docfrag = document.createDocumentFragment();

    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in docfrag, prop + " not found in document fragent.");
        else
            ok(!(prop in docfrag), prop + " found in document fragent.");
    }

    var v = document.documentMode;

    test_exposed("compareDocumentPosition", v >= 9);
});

sync_test("window_props", function() {
    function test_exposed(prop, expect, is_todo) {
        var ok_ = is_todo ? todo_wine.ok : ok;
        if(expect)
            ok_(prop in window, prop + " not found in window.");
        else
            ok_(!(prop in window), prop + " found in window.");
    }

    var v = document.documentMode;

    test_exposed("attachEvent", v < 11);
    test_exposed("detachEvent", v < 11);
    test_exposed("execScript", v < 11);
    test_exposed("createPopup", v < 11);
    test_exposed("postMessage", true);
    test_exposed("sessionStorage", true);
    test_exposed("localStorage", true);
    test_exposed("addEventListener", v >= 9);
    test_exposed("removeEventListener", v >= 9);
    test_exposed("dispatchEvent", v >= 9);
    test_exposed("getSelection", v >= 9);
    test_exposed("onfocusout", v >= 9);
    test_exposed("getComputedStyle", v >= 9);
    test_exposed("cancelAnimationFrame", v >= 10);
    test_exposed("requestAnimationFrame", v >= 10);
    test_exposed("Map", v >= 11);
    test_exposed("Set", v >= 11);
    test_exposed("WeakMap", v >= 11);
    test_exposed("WeakSet", false);
    test_exposed("performance", true);
    test_exposed("console", v >= 10);
    test_exposed("matchMedia", v >= 10);
    test_exposed("MutationObserver", v >= 11);
});

sync_test("domimpl_props", function() {
    var domimpl = document.implementation;
    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in domimpl, prop + " not found in DOMImplementation.");
        else
            ok(!(prop in domimpl), prop + " found in DOMImplementation.");
    }

    var v = document.documentMode;

    test_exposed("hasFeature", true);
    test_exposed("createDocument", v >= 9);
    test_exposed("createDocumentType", v >= 9);
    test_exposed("createHTMLDocument", v >= 9);
});

sync_test("xhr_props", function() {
    var xhr = new XMLHttpRequest();

    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in xhr, prop + " not found in XMLHttpRequest.");
        else
            ok(!(prop in xhr), prop + " found in XMLHttpRequest.");
    }

    var v = document.documentMode;

    test_exposed("addEventListener", v >= 9);
    test_exposed("removeEventListener", v >= 9);
    test_exposed("dispatchEvent", v >= 9);
    test_exposed("onabort", v >= 10);
    test_exposed("onerror", v >= 10);
    test_exposed("onloadend", v >= 10);
    test_exposed("onloadstart", v >= 10);
    test_exposed("onprogress", v >= 10);
    test_exposed("ontimeout", true);
    test_exposed("overrideMimeType", v >= 11);
    test_exposed("response", v >= 10);
    test_exposed("responseType", v >= 10);
    test_exposed("timeout", true);
    test_exposed("upload", v >= 10);
    test_exposed("withCredentials", v >= 10);
});

sync_test("stylesheet_props", function() {
    var v = document.documentMode;
    var elem = document.createElement("style");
    document.body.appendChild(elem);
    var sheet = v >= 9 ? elem.sheet : elem.styleSheet;

    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in sheet, prop + " not found in style sheet.");
        else
            ok(!(prop in sheet), prop + " found in style sheet.");
    }

    test_exposed("href", true);
    test_exposed("title", true);
    test_exposed("type", true);
    test_exposed("media", true);
    test_exposed("ownerNode", v >= 9);
    test_exposed("ownerRule", v >= 9);
    test_exposed("cssRules", v >= 9);
    test_exposed("insertRule", v >= 9);
    test_exposed("deleteRule", v >= 9);
    test_exposed("disabled", true);
    test_exposed("parentStyleSheet", true);
    test_exposed("owningElement", true);
    test_exposed("readOnly", true);
    test_exposed("imports", true);
    test_exposed("id", true);
    test_exposed("addImport", true);
    test_exposed("addRule", true);
    test_exposed("removeImport", true);
    test_exposed("removeRule", true);
    test_exposed("cssText", true);
    test_exposed("rules", true);
});

sync_test("rect_props", function() {
    document.body.innerHTML = '<div>test</div>';
    var elem = document.body.firstChild;
    var rect = elem.getBoundingClientRect();
    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in rect, prop + " not found in rect object.");
        else
            ok(!(prop in rect), prop + " found in rect object.");
    }

    var v = document.documentMode;

    test_exposed("width", v >= 9);
    test_exposed("height", v >= 9);
});

sync_test("xhr open", function() {
    var e = false;
    try {
        (new XMLHttpRequest()).open("GET", "https://www.winehq.org/");
    }catch(ex) {
        e = true;
    }

    if(document.documentMode < 10)
        ok(e, "expected exception");
    else
        ok(!e, "unexpected exception");
});

sync_test("style_props", function() {
    var style = document.body.style, currentStyle = document.body.currentStyle, computedStyle = window.getComputedStyle ? window.getComputedStyle(document.body) : undefined;

    function test_exposed(prop, expect_style, expect_currentStyle, expect_computedStyle) {
        if(expect_style)
            ok(prop in style, prop + " not found in style object.");
        else
            ok(!(prop in style), prop + " found in style object.");
        if(expect_currentStyle)
            ok(prop in currentStyle, prop + " not found in currentStyle object.");
        else
            ok(!(prop in currentStyle), prop + " found in currentStyle object.");
        if(computedStyle) {
            if(expect_computedStyle)
                ok(prop in computedStyle, prop + " not found in computedStyle object.");
            else
                ok(!(prop in computedStyle), prop + " found in computedStyle object.");
        }
    }

    var v = document.documentMode;

    test_exposed("removeAttribute", true, broken(true) ? v >= 9 : false /* todo_wine */, false);
    test_exposed("zIndex", true, true, true);
    test_exposed("z-index", true, true, true);
    test_exposed("filter", true, true, broken(true) ? v >= 10 : v >= 9 /* todo_wine */);
    test_exposed("pixelTop", true, false, false);
    test_exposed("float", true, true, true);
    test_exposed("css-float", false, false, false);
    test_exposed("style-float", false, false, false);
    test_exposed("setProperty", v >= 9, v >= 9, v >= 9);
    test_exposed("removeProperty", v >= 9, v >= 9, v >= 9);
    test_exposed("background-clip", v >= 9, v >= 9, v >= 9);
    test_exposed("msTransform", v >= 9, v >= 9, v >= 9);
    test_exposed("msTransition", v >= 10, v >= 10, v >= 10);
    test_exposed("transform", v >= 10, v >= 10, v >= 10);
    test_exposed("transition", v >= 10, v >= 10, v >= 10);
});

sync_test("createElement_inline_attr", function() {
    var v = document.documentMode, e, s;

    if(v < 9) {
        s = document.createElement("<div>").tagName;
        ok(s === "DIV", "<div>.tagName returned " + s);
        s = document.createElement("<div >").tagName;
        ok(s === "DIV", "<div >.tagName returned " + s);
        s = document.createElement("<div/>").tagName;
        ok(s === "DIV", "<div/>.tagName returned " + s);
        e = 0;
        try {
            document.createElement("<div");
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0x4005 - 0x80000000, "<div e = " + e);
        e = 0;
        try {
            document.createElement("<div test=1");
        }catch(ex) {
            e = ex.number;
        }
        ok(e === 0x4005 - 0x80000000, "<div test=1 e = " + e);

        var tags = [ "div", "head", "body", "title", "html" ];

        for(var i = 0; i < tags.length; i++) {
            e = document.createElement("<" + tags[i] + " test='a\"' abcd=\"&quot;b&#34;\">");
            ok(e.tagName === tags[i].toUpperCase(), "<" + tags[i] + " test=\"a\" abcd=\"b\">.tagName returned " + e.tagName);
            ok(e.test === "a\"", "<" + tags[i] + " test='a\"' abcd=\"&quot;b&#34;\">.test returned " + e.test);
            ok(e.abcd === "\"b\"", "<" + tags[i] + " test='a\"' abcd=\"&quot;b&#34;\">.abcd returned " + e.abcd);
        }
    }else {
        s = "";
        e = 0;
        try {
            document.createElement("<div>");
        }catch(ex) {
            s = ex.toString();
            e = ex.number;
        }
        todo_wine.
        ok(e === undefined, "<div> e = " + e);
        todo_wine.
        ok(s === "InvalidCharacterError", "<div> s = " + s);
        s = "";
        e = 0;
        try {
            document.createElement("<div test=\"a\">");
        }catch(ex) {
            s = ex.toString();
            e = ex.number;
        }
        todo_wine.
        ok(e === undefined, "<div test=\"a\"> e = " + e);
        todo_wine.
        ok(s === "InvalidCharacterError", "<div test=\"a\"> s = " + s);
    }
});

sync_test("JS objs", function() {
    var g = window;

    function test_exposed(func, obj, expect, is_todo) {
        var ok_ = is_todo ? todo_wine.ok : ok;
        if(expect)
            ok_(func in obj, func + " not found in " + obj);
        else
            ok_(!(func in obj), func + " found in " + obj);
    }

    function test_parses(code, expect) {
        var success;
        try {
            eval(code);
            success = true;
        }catch(e) {
            success = false;
        }
        if(expect)
            ok(success === true, code + " did not parse");
        else
            ok(success === false, code + " parsed");
    }

    var v = document.documentMode;

    test_exposed("ScriptEngineMajorVersion", g, true);

    test_exposed("JSON", g, v >= 8);
    test_exposed("now", Date, true);
    test_exposed("toISOString", Date.prototype, v >= 9);
    test_exposed("isArray", Array, v >= 9);
    test_exposed("forEach", Array.prototype, v >= 9);
    test_exposed("indexOf", Array.prototype, v >= 9);
    test_exposed("trim", String.prototype, v >= 9);
    test_exposed("map", Array.prototype, v >= 9);

    /* FIXME: IE8 implements weird semi-functional property descriptors. */
    test_exposed("getOwnPropertyDescriptor", Object, v >= 8, v === 8);
    test_exposed("defineProperty", Object, v >= 8, v === 8);
    test_exposed("defineProperties", Object, v >= 9);

    test_exposed("getPrototypeOf", Object, v >= 9);

    test_parses("if(false) { o.default; }", v >= 9);
    test_parses("if(false) { o.with; }", v >= 9);
    test_parses("if(false) { o.if; }", v >= 9);
});

sync_test("eval", function() {
    var i, context, code = "this.foobar = 1234", v = document.documentMode;

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
        function() { window.eval(code); },
        function() { window["eval"](code); },
        function() { eval("eval")(code); }
    ];

    for(i = 0; i < indirect.length; i++) {
        context = {};
        ok(!("foobar" in window), "indirect[" + i + "] has global foobar before call");
        indirect[i].call(context);
        if(v < 9) {
            ok(context.foobar === 1234, "indirect[" + i + "] context foobar = " + context.foobar);
            ok(!("foobar" in window), "indirect[" + i + "] has global foobar");
        }else {
            ok(!("foobar" in context), "indirect[" + i + "] has foobar");
            ok(window.foobar === 1234, "indirect[" + i + "] global foobar = " + context.foobar);
            delete window.foobar;
        }
    }

    context = {};
    (function(eval) { eval(code); })(function() { context.barfoo = 4321; });
    ok(context.barfoo === 4321, "context.barfoo = " + context.barfoo);

    (0,eval)("var foobar = 'wine';");
    if(v < 9) {
        ok(!("foobar" in window), "foobar in window");
        ok(foobar === "wine", "foobar = " + foobar);
    }else {
        ok("foobar" in window, "foobar not in window");
        ok(window.foobar === "wine", "foobar = " + window.foobar);
    }
    delete foobar;
});

sync_test("for..in", function() {
    var v = document.documentMode, found = 0, r;

    function ctor() {}
    ctor.prototype.test2 = true;

    var arr = new Array(), obj = new ctor(), i, r;
    obj.test1 = true;

    i = 0;
    for(r in obj) {
        ctor.prototype.test3 = true;
        arr[r] = true;
        i++;
    }

    ok(i === 3, "enum did " + i + " iterations");
    ok(arr["test1"] === true, "arr[test1] !== true");
    ok(arr["test2"] === true, "arr[test2] !== true");
    ok(arr["test3"] === true, "arr[test3] !== true");

    for(r in document)
        if(r === "ondragstart")
            found++;
    ok(found === 1, "ondragstart enumerated " + found + " times in document");
    document.ondragstart = "";
    found = 0;
    for(r in document)
        if(r === "ondragstart")
            found++;
    ok(found === 1, "ondragstart enumerated " + found + " times in document after set to empty string");
});

sync_test("function caller", function() {
    var v = document.documentMode;

    ok(Function.prototype.hasOwnProperty("caller"), "caller not prop of Function.prototype");
    if(v < 9)
        ok(arguments.hasOwnProperty("caller"), "caller not prop of arguments");
    else
        ok(!("caller" in arguments), "caller in arguments");

    function test_caller(expected_caller, stop) {
        ok(test_caller.caller === expected_caller, "caller = " + test_caller.caller);
        if(v < 9)
            ok(arguments.caller === expected_caller.arguments, "arguments.caller = " + arguments.caller);

        if(stop) return;
        function nested() {
            ok(nested.caller === test_caller, "nested caller = " + nested.caller);
            if(v < 9)
                ok(arguments.caller === test_caller.arguments, "nested arguments.caller = " + arguments.caller);
            test_caller(nested, true);
            ok(test_caller.caller === expected_caller, "caller within nested = " + test_caller.caller);
            if(v < 9)
                ok(test_caller.arguments.caller === expected_caller.arguments, "arguments.caller within nested = " + test_caller.arguments.caller);
        }
        nested();
        ok(test_caller.caller === expected_caller, "caller after nested = " + test_caller.caller);
        if(v < 9)
            ok(arguments.caller === expected_caller.arguments, "arguments.caller after nested = " + arguments.caller);
    }
    ok(test_caller.hasOwnProperty("caller"), "caller not prop of test_caller");
    ok(test_caller.caller === null, "test_caller.caller = " + test_caller.caller);

    function f1() { test_caller(f1); } f1();
    function f2() { test_caller(f2); } f2();
});

sync_test("elem_by_id", function() {
    document.body.innerHTML = '<form id="testid" name="testname"></form>';
    var v = document.documentMode, found, i;

    var id_elem = document.getElementById("testid");
    ok(id_elem.tagName === "FORM", "id_elem.tagName = " + id_elem.tagName);

    var name_elem = document.getElementById("testname");
    if(v < 8)
        ok(id_elem === name_elem, "id_elem != id_elem");
    else
        ok(name_elem === null, "name_elem != null");

    id_elem = window.testid;
    ok(id_elem.tagName === "FORM", "window.testid = " + id_elem);

    name_elem = document.testname;
    ok(name_elem.tagName === "FORM", "document.testname = " + name_elem);

    for(id_elem in window)
        ok(id_elem !== "testid" && id_elem != "testname", id_elem + " was enumerated in window");
    window.testid = 137;
    found = false;
    for(id_elem in window) {
        ok(id_elem != "testname", id_elem + " was enumerated in window after set to 137");
        if(id_elem === "testid")
            found = true;
    }
    ok(found, "testid was not enumerated in window after set to 137");

    found = false;
    for(id_elem in document) {
        ok(id_elem !== "testid", "testid was enumerated in document");
        if(id_elem === "testname")
            found = true;
    }
    ok(found, "testname was not enumerated in document");

    try {
        document.testname();
        ok(false, "document.testname() did not throw exception");
    }catch(e) {
        ok(e.number === 0xa01b6 - 0x80000000, "document.testname() threw = " + e.number);
    }

    try {
        document.testname = "foo";
        ok(v >= 9, "Setting document.testname did not throw exception");

        id_elem = document.testid;
        ok(id_elem.tagName === "FORM", "document.testid after set = " + id_elem);
        name_elem = document.testname;
        ok(name_elem === "foo", "document.testname after set = " + name_elem);
    }catch(e) {
        todo_wine_if(v >= 9).
        ok(v < 9 && e.number === 0xa01b6 - 0x80000000, "Setting document.testname threw = " + e.number);
    }

    try {
        document.testid = "bar";
        ok(v >= 9, "Setting document.testid did not throw exception");

        id_elem = document.testid;
        ok(id_elem === "bar", "document.testid after both set = " + id_elem);
        name_elem = document.testname;
        ok(name_elem === "foo", "document.testname after both set = " + name_elem);

        found = false, name_elem = false;
        for(id_elem in document) {
            if(id_elem === "testid")
                found = true;
            if(id_elem === "testname")
                name_elem = true;
        }
        ok(found, "testid was not enumerated in document after both set");
        ok(name_elem, "testname was not enumerated in document after both set");
        delete document.testid;
        delete document.testname;
    }catch(e) {
        todo_wine_if(v >= 9).
        ok(v < 9 && e.number === 0xa01b6 - 0x80000000, "Setting document.testid threw = " + e.number);
    }

    window.testid2 = 1;
    document.testid2 = 2;
    document.body.innerHTML = '<form id="testid2" name="testname"></form>';
    ok(window.testid2 == 1, "window.testid2 = " + window.testid2);
    id_elem = document.body.firstChild;
    ok(document.testid2 == (v < 9 ? id_elem : 2), "document.testid2 = " + document.testid2);
    document.body.innerHTML = '';
    ok(window.testid2 == 1, "window.testid2 = " + window.testid2);
    ok(document.testid2 == 2, "document.testid2 = " + document.testid2 + " expected 2");

    ok(document.title === "", "document.title = " + document.title);
    document.body.innerHTML = '<form id="title" name="testname"></form>';
    id_elem = document.body.firstChild;
    todo_wine_if(v < 9).
    ok(document.title === (v < 9 ? id_elem : ""), "document.title = " + document.title);
    document.body.innerHTML = '';
    ok(document.title === "", "document.title = " + document.title);

    ok(window.closed === false, "window.closed = " + window.closed);
    document.body.innerHTML = '<form id="closed" name="testname"></form>';
    id_elem = document.body.firstChild;
    ok(window.closed === false, "window.closed = " + window.closed);

    // these tags expose name as props, and id only if they have a name
    var tags = [ "embed", "form", "iframe", "img" ];
    for(i in tags) {
        var tag = tags[i];
        document.body.innerHTML = '<' + tag + ' id="testid" name="testname"></' + tag + '><' + tag + ' id="foobar"></' + tag + '>';
        ok("testname" in document, tag + " did not expose testname");
        ok("testid" in document, tag + " did not expose testid");
        ok(!("foobar" in document), tag + " exposed foobar");
    }

    // these tags always expose their id as well as name (we don't test applet because it makes Windows pop up a dialog box)
    tags = [ "object" ];
    for(i in tags) {
        var tag = tags[i];
        document.body.innerHTML = '<' + tag + ' id="testid" name="testname"></' + tag + '><' + tag + ' id="foobar"></' + tag + '>';
        ok("testname" in document, tag + " did not expose testname");
        ok("testid" in document, tag + " did not expose testid");
        ok("foobar" in document, tag + " did not expose foobar");
    }

    // all other tags don't expose props for either id or name, test a few of them here
    tags = [ "a", "b", "body", "center", "div", "frame", "h2", "head", "html", "input", "meta", "p", "span", "style", "table", "winetest" ];
    for(i in tags) {
        var tag = tags[i];
        document.body.innerHTML = '<' + tag + ' id="testid" name="testname"></' + tag + '><' + tag + ' id="foobar"></' + tag + '>';
        ok(!("testname" in document), tag + " exposed testname");
        ok(!("testid" in document), tag + " exposed testid");
        ok(!("foobar" in document), tag + " exposed foobar");
    }
});

sync_test("doc_mode", function() {
    compat_version = parseInt(document.location.search.substring(1));

    trace("Testing compatibility mode " + compat_version);

    if(compat_version > 6 && compat_version > document.documentMode) {
        win_skip("Document mode not supported (expected " + compat_version + " got " + document.documentMode + ")");
        reportSuccess();
        return;
    }

    ok(Math.max(compat_version, 5) === document.documentMode, "documentMode = " + document.documentMode);

    if(document.documentMode > 5)
        ok(document.compatMode === "CSS1Compat", "document.compatMode = " + document.compatMode);
    else
        ok(document.compatMode === "BackCompat", "document.compatMode = " + document.compatMode);
});

sync_test("doctype", function() {
    var doctype = document.doctype;

    if(document.documentMode < 9) {
        ok(doctype === null, "doctype = " + document.doctype);
        return;
    }

    ok(doctype.name === "html", "doctype.name = " + doctype.name);
});

async_test("iframe_doc_mode", function() {
    var iframe = document.createElement("iframe");

    iframe.onload = function() {
        var iframe_mode = iframe.contentWindow.document.documentMode;
        if(document.documentMode < 9)
            ok(iframe_mode === 5, "iframe_mode = " + iframe_mode);
        else
            ok(iframe_mode === document.documentMode, "iframe_mode = " + iframe_mode);
        next_test();
    }

    iframe.src = "about:blank";
    document.body.appendChild(iframe);
});

sync_test("conditional_comments", function() {
    var div = document.createElement("div");
    document.body.appendChild(div);

    function test_version(v) {
        var version = compat_version ? compat_version : 7;

        div.innerHTML = "<!--[if lte IE " + v + "]>true<![endif]-->";
        ok(div.innerText === (version <= v ? "true" : ""),
           "div.innerText = " + div.innerText + " for version (<=) " + v);

        div.innerHTML = "<!--[if lt IE " + v + "]>true<![endif]-->";
        ok(div.innerText === (version < v ? "true" : ""),
           "div.innerText = " + div.innerText + " for version (<) " + v);

        div.innerHTML = "<!--[if gte IE " + v + "]>true<![endif]-->";
        ok(div.innerText === (version >= v && version < 10 ? "true" : ""),
           "div.innerText = " + div.innerText + " for version (>=) " + v);

        div.innerHTML = "<!--[if gt IE " + v + "]>true<![endif]-->";
        ok(div.innerText === (version > v && version < 10 ? "true" : ""),
           "div.innerText = " + div.innerText + " for version (>) " + v);
    }

    test_version(5);
    test_version(6);
    test_version(7);
    test_version(8);
});

var ready_states;

async_test("script_load", function() {
    var v = document.documentMode;
    if(v < 9) {
        next_test();
        return;
    }

    var elem = document.createElement("script");
    ready_states = "";

    elem.onreadystatechange = guard(function() {
        ok(v < 11, "unexpected onreadystatechange call");
        ready_states += elem.readyState + ",";
    });

    elem.onload = guard(function() {
        switch(v) {
        case 9:
            ok(ready_states === "loading,exec,loaded,", "ready_states = " + ready_states);
            break;
        case 10:
            ok(ready_states === "loading,exec,", "ready_states = " + ready_states);
            break;
        case 11:
            ok(ready_states === "exec,", "ready_states = " + ready_states);
            break;
        }
        next_test();
    });

    document.body.appendChild(elem);
    elem.src = "jsstream.php?simple";
    external.writeStream("simple", "ready_states += 'exec,';");
});

sync_test("location", function() {
    var v = document.documentMode;
    document.body.innerHTML = '<a name="testanchor">test</a>';

    ok(location.host === "winetest.example.org" + (v < 10 ? ":80" : ""), "location.host = " + location.host);

    ok(location.hash === "", "initial location.hash = " + location.hash);
    location.hash = "TestAnchor";
    ok(location.hash === "#TestAnchor", "location.hash after set to TestAnchor = " + location.hash);
    location.hash = "##foo";
    ok(location.hash === "##foo", "location.hash after set to ##foo = " + location.hash);
    location.hash = "#testanchor";
    ok(location.hash === "#testanchor", "location.hash after set to #testanchor = " + location.hash);
});

sync_test("navigator", function() {
    var v = document.documentMode, re;
    var app = navigator.appVersion;
    ok(navigator.userAgent === "Mozilla/" + app,
       "userAgent = " + navigator.userAgent + " appVersion = " + app);

    re = v < 11
        ? "^" + (v < 9 ? "4" : "5") + "\\.0 \\(compatible; MSIE " + (v < 7 ? 7 : v) +
          "\\.0; Windows NT [0-9].[0-9]; .*Trident/[678]\\.0.*\\)$"
        : "^5.0 \\(Windows NT [0-9].[0-9]; .*Trident/[678]\\.0.*rv:11.0\\) like Gecko$";
    ok(new RegExp(re).test(app), "appVersion = " + app);

    ok(navigator.appCodeName === "Mozilla", "appCodeName = " + navigator.appCodeName);
    ok(navigator.appName === (v < 11 ? "Microsoft Internet Explorer" : "Netscape"),
       "appName = " + navigator.appName);
    ok(navigator.toString() === (v < 9 ? "[object]" : "[object Navigator]"),
       "navigator.toString() = " + navigator.toString());
});

sync_test("delete_prop", function() {
    var v = document.documentMode;
    var obj = document.createElement("div"), r, obj2;

    obj.prop1 = true;
    r = false;
    try {
        delete obj.prop1;
    }catch(ex) {
        r = true;
    }
    if(v < 8) {
        ok(r, "did not get an expected exception");
        return;
    }
    ok(!r, "got an unexpected exception");
    ok(!("prop1" in obj), "prop1 is still in obj");

    /* again, this time prop1 does not exist */
    r = false;
    try {
        delete obj.prop1;
    }catch(ex) {
        r = true;
    }
    if(v < 9) {
        ok(r, "did not get an expected exception");
        return;
    }else {
        ok(!r, "got an unexpected exception");
        ok(!("prop1" in obj), "prop1 is still in obj");
    }

    r = (delete obj.className);
    ok(r, "delete returned " + r);
    ok("className" in obj, "className deleted from obj");
    ok(obj.className === "", "className = " + obj.className);

    /* builtin propertiles don't throw any exception, but are not really deleted */
    r = (delete obj.tagName);
    ok(r, "delete returned " + r);
    ok("tagName" in obj, "tagName deleted from obj");
    ok(obj.tagName === "DIV", "tagName = " + obj.tagName);

    obj = document.querySelectorAll("*");
    ok("0" in obj, "0 is not in obj");
    obj2 = obj[0];
    r = (delete obj[0]);
    ok("0" in obj, "0 is not in obj");
    ok(obj[0] === obj2, "obj[0] != obj2");

    /* test window object and its global scope handling */
    obj = window;

    obj.globalprop1 = true;
    ok(globalprop1, "globalprop1 = " + globalprop1);
    r = false;
    try {
        delete obj.globalprop1;
    }catch(ex) {
        r = true;
    }
    if(v < 9) {
        ok(r, "did not get an expected exception");
    }else {
        ok(!r, "got an unexpected globalprop1 exception");
        ok(!("globalprop1" in obj), "globalprop1 is still in obj");
    }

    globalprop2 = true;
    ok(obj.globalprop2, "globalprop2 = " + globalprop2);
    r = false;
    try {
        delete obj.globalprop2;
    }catch(ex) {
        r = true;
    }
    if(v < 9) {
        ok(r, "did not get an expected globalprop2 exception");
    }else {
        ok(!r, "got an unexpected exception");
        todo_wine.
        ok(!("globalprop2" in obj), "globalprop2 is still in obj");
    }

    obj.globalprop3 = true;
    ok(globalprop3, "globalprop3 = " + globalprop3);
    r = false;
    try {
        delete globalprop3;
    }catch(ex) {
        r = true;
    }
    if(v < 9) {
        ok(r, "did not get an expected exception");
        ok("globalprop3" in obj, "globalprop3 is not in obj");
    }else {
        ok(!r, "got an unexpected globalprop3 exception");
        ok(!("globalprop3" in obj), "globalprop3 is still in obj");
    }

    globalprop4 = true;
    ok(obj.globalprop4, "globalprop4 = " + globalprop4);
    r = (delete globalprop4);
    ok(r, "delete returned " + r);
    todo_wine.
    ok(!("globalprop4" in obj), "globalprop4 is still in obj");
});

sync_test("detached arguments", function() {
    var args, get_a, set_a, get_x, set_x;

    function test_args() {
        ok(args[0] === 1, "args[0] = " + args[0]);
        set_x(2);
        ok(args[0] === 2, "args[0] = " + args[0]);
        args[0] = 3;
        ok(get_x() === 3, "get_x() = " + get_x());
        ok(args[0] === 3, "args[0] = " + args[0]);
    }

    (function(x) {
        args = arguments;
        get_x = function() { return x; };
        set_x = function(v) { x = v; };

        test_args();
        x = 1;
    })(1);
    test_args();

    (function(a, a, b, c) {
        get_a = function() { return a; }
        set_a = function(v) { a = v; }
        ok(get_a() === 2, "get_a() = " + get_a());
        ok(a === 2, "a = " + a);
        ok(b === 3, "b = " + b);
        ok(c === 4, "c = " + c);
        a = 42;
        ok(arguments[0] === 1, "arguments[0] = " + arguments[0]);
        ok(arguments[1] === 42, "arguments[1] = " + arguments[1]);
        ok(get_a() === 42, "get_a() after assign = " + get_a());
        args = arguments;
    })(1, 2, 3, 4);

    ok(get_a() === 42, "get_a() after detach = " + get_a());
    set_a(100);
    ok(get_a() === 100, "get_a() after set_a() = " + get_a());
    ok(args[0] === 1, "detached args[0] = " + args[0]);
    ok(args[1] === 100, "detached args[1] = " + args[1]);

    (function(a, a) {
        eval("var a = 7;");
        ok(a === 7, "function(a, a) a = " + a);
        ok(arguments[0] === 5, "function(a, a) arguments[0] = " + arguments[0]);
        ok(arguments[1] === 7, "function(a, a) arguments[1] = " + arguments[1]);
    })(5, 6);
});

var func_scope_val = 1;
var func_scope_val2 = 2;

sync_test("func_scope", function() {
    var func_scope_val = 2;

    var f = function func_scope_val() {
        return func_scope_val;
    };

    func_scope_val = 3;
    if(document.documentMode < 9) {
        ok(f() === 3, "f() = " + f());
        return;
    }
    ok(f === f(), "f() = " + f());

    f = function func_scope_val(a) {
        func_scope_val = 4;
        return func_scope_val;
    };

    func_scope_val = 3;
    ok(f === f(), "f() = " + f());
    ok(func_scope_val === 3, "func_scope_val = " + func_scope_val);
    ok(window.func_scope_val === 1, "window.func_scope_val = " + window.func_scope_val);

    f = function func_scope_val(a) {
        return (function() { return a ? func_scope_val(false) : func_scope_val; })();
    };

    ok(f === f(true), "f(true) = " + f(true));

    window = 1;
    ok(window === window.self, "window = " + window);

    ! function func_scope_val2() {};
    ok(window.func_scope_val2 === 2, "window.func_scope_val2 = " + window.func_scope_val2);

    var o = {};
    (function(x) {
        ok(x === o, "x = " + x);
        ! function x() {};
        ok(x === o, "x != o");
    })(o);

    (function(x) {
        ok(x === o, "x = " + x);
        1, function x() {};
        ok(x === o, "x != o");
    })(o);

    (function() {
        ! function x() {};
        try {
            x();
            ok(false, "expected exception");
        }catch(e) {}
    })(o);
});

sync_test("set_obj", function() {
    if(!("Set" in window)) return;

    try {
        var s = Set();
        ok(false, "expected exception calling constructor as method");
    }catch(e) {
        ok(e.number === 0xa13fc - 0x80000000, "calling constructor as method threw " + e.number);
    }

    var s = new Set, r;
    ok(Object.getPrototypeOf(s) === Set.prototype, "unexpected Set prototype");

    function test_length(name, len) {
        ok(Set.prototype[name].length === len, "Set.prototype." + name + " = " + Set.prototype[name].length);
        try {
            Set.prototype[name].call({}, 0);
            ok(false, "expected exception calling Set.prototype." + name + "(object)");
        }catch(e) {
            ok(e.number === 0xa13fc - 0x80000000, "Set.prototype." + name + "(object) threw " + e.number);
        }
    }
    test_length("add", 1);
    test_length("clear", 0);
    test_length("delete", 1);
    test_length("forEach", 1);
    test_length("has", 1);
    ok(!("entries" in s), "entries are in Set");
    ok(!("keys" in s), "keys are in Set");
    ok(!("values" in s), "values are in Set");

    r = Object.prototype.toString.call(s);
    ok(r === "[object Object]", "toString returned " + r);

    r = s.has(-0);
    ok(r === false, "has(-0) returned " + r);
    ok(s.size === 0, "size = " + s.size);

    r = s.add(42);
    ok(r === undefined, "add(42) returned " + r);
    r = s.add(42);
    ok(r === undefined, "add(42) returned " + r);
    r = s.add(0);
    ok(r === undefined, "add(0) returned " + r);
    r = s.has(-0);
    ok(r === false, "has(-0) returned " + r);
    r = s.add(-0);
    ok(r === undefined, "add(-0) returned " + r);
    r = s.has(-0);
    ok(r === true, "has(-0) after add returned " + r);
    r = s.add("test");
    ok(r === undefined, "add(test) returned " + r);
    r = s.add(13);
    ok(r === undefined, "add(13) returned " + r);
    r = s.add(s);
    ok(r === undefined, "add(s) returned " + r);

    r = s["delete"]("test"); /* using s.delete() would break parsing in quirks mode */
    ok(r === true, "delete(test) returned " + r);
    r = s["delete"]("test");
    ok(r === false, "delete(test) returned " + r);

    ok(s.size === 5, "size = " + s.size);
    s.size = 100;
    ok(s.size === 5, "size (after set) = " + s.size);

    var a = [];
    r = s.forEach(function(value, key, obj) {
        var t = s["delete"](key);
        ok(t === true, "delete(" + key + ") returned " + r);
        ok(value === key, "value = " + value + ", key = " + key);
        ok(obj === s, "set = " + obj);
        ok(this === a, "this = " + this);
        a.push(value);
    }, a);
    ok(r === undefined, "forEach returned " + r);
    ok(a.length === 5, "a.length = " + a.length);
    for(var i = 0; i < a.length; i++)
        ok(a[i] === [42, 0, -0, 13, s][i], "a[" + i + "] = " + a[i]);
    ok(s.size === 0, "size = " + s.size);

    s = new Set();
    ok(s.size === 0, "size = " + s.size);
    s.add(1);
    s.add(2);
    ok(s.size === 2, "size = " + s.size);
    r = s.clear();
    ok(r === undefined, "clear returned " + r);
    ok(s.size === 0, "size = " + s.size);

    s = new Set([1, 2, 3]);
    ok(s.size === 0, "size = " + s.size);

    s = new Set();
    s.add(1);
    s.add(2);
    s.add(3);
    r = 0;
    s.forEach(function(value, key, obj) {
        r++;
        s.clear();
        ok(s.size === 0, "size = " + s.size);
        ok(this.valueOf() === 42, "this.valueOf() = " + this.valueOf());
    }, 42);
    ok(r === 1, "r = " + r);
});

sync_test("map_obj", function() {
    if(!("Map" in window)) return;

    try {
        var s = Map();
        ok(false, "expected exception calling constructor as method");
    }catch(e) {
        ok(e.number === 0xa13fc - 0x80000000, "calling constructor as method threw " + e.number);
    }

    var s = new Map, r, i;
    ok(Object.getPrototypeOf(s) === Map.prototype, "unexpected Map prototype");

    function test_length(name, len) {
        ok(Map.prototype[name].length === len, "Map.prototype." + name + " = " + Map.prototype[name].length);
    }
    test_length("clear", 0);
    test_length("delete", 1);
    test_length("forEach", 1);
    test_length("get", 1);
    test_length("has", 1);
    test_length("set", 2);
    ok(!("entries" in s), "entries are in Map");
    ok(!("keys" in s), "keys are in Map");
    ok(!("values" in s), "values are in Map");
    todo_wine.
    ok("size" in Map.prototype, "size is not in Map.prototype");

    r = Object.prototype.toString.call(s);
    ok(r === "[object Object]", "toString returned " + r);

    r = s.get("test");
    ok(r === undefined, "get(test) returned " + r);
    r = s.has("test");
    ok(r === false, "has(test) returned " + r);
    ok(s.size === 0, "size = " + s.size + " expected 0");

    r = s.set("test", 1);
    ok(r === undefined, "set returned " + r);
    ok(s.size === 1, "size = " + s.size + " expected 1");
    r = s.get("test");
    ok(r === 1, "get(test) returned " + r);
    r = s.has("test");
    ok(r === true, "has(test) returned " + r);

    s.size = 100;
    ok(s.size === 1, "size = " + s.size + " expected 1");

    s.set("test", 2);
    r = s.get("test");
    ok(r === 2, "get(test) returned " + r);
    r = s.has("test");
    ok(r === true, "has(test) returned " + r);

    r = s["delete"]("test"); /* using s.delete() would break parsing in quirks mode */
    ok(r === true, "delete(test) returned " + r);
    ok(s.size === 0, "size = " + s.size + " expected 0");
    r = s["delete"]("test");
    ok(r === false, "delete(test) returned " + r);

    var test_keys = [undefined, null, NaN, 3, "str", false, true, {}];
    for(i in test_keys) {
        r = s.set(test_keys[i], test_keys[i] + 1);
        ok(r === undefined, "set(test) returned " + r);
    }
    ok(s.size === test_keys.length, "size = " + s.size + " expected " + test_keys.length);
    for(i in test_keys) {
        r = s.get(test_keys[i]);
        if(isNaN(test_keys[i]))
            ok(isNaN(r), "get(" + test_keys[i] + ") returned " + r);
        else
            ok(r === test_keys[i] + 1, "get(" + test_keys[i] + ") returned " + r);
    }

    var calls = [];
    i = 0;
    r = s.forEach(function(value, key, map) {
        if(isNaN(test_keys[i])) {
            ok(isNaN(key), "key = " + key + " expected NaN");
            ok(isNaN(value), "value = " + value + " expected NaN");
        }else {
            ok(key === test_keys[i], "key = " + key + " expected " + test_keys[i]);
            ok(value === key + 1, "value = " + value);
        }
        ok(map === s, "map = " + map);
        ok(this === test_keys, "this = " + this);
        i++;
    }, test_keys);
    ok(i === test_keys.length, "i = " + i);
    ok(r === undefined, "forEach returned " + r);

    s.set(3, "test2")
    calls = [];
    i = 0;
    s.forEach(function(value, key) {
        if(isNaN(test_keys[i]))
            ok(isNaN(key), "key = " + key + " expected " + test_keys[i]);
        else
            ok(key === test_keys[i], "key = " + key + " expected " + test_keys[i]);
        i++;
    });
    ok(i === test_keys.length, "i = " + i);

    r = s.clear();
    ok(r === undefined, "clear returned " + r);
    ok(s.size === 0, "size = " + s.size + " expected 0");
    r = s.get(test_keys[0]);
    ok(r === undefined, "get returned " + r);

    s = new Map();
    s.set(1, 10);
    s.set(2, 20);
    s.set(3, 30);
    i = true;
    s.forEach(function() {
        ok(i, "unexpected call");
        s.clear();
        i = false;
    });

    s = new Map();
    s.set(1, 10);
    s.set(2, 20);
    s.set(3, 30);
    i = 0;
    s.forEach(function(value, key) {
        i += key + value;
        r = s["delete"](key);
        ok(r === true, "delete returned " + r);
    });
    ok(i === 66, "i = " + i);

    s = new Map();
    s.set(0,  10);
    s.set(-0, 20);
    ok(s.size === 2, "size = " + s.size + " expected 2");
    r = s.get(-0);
    ok(r === 20, "get(-0) returned " + r);
    r = s.get(0);
    ok(r === 10, "get(0) returned " + r);

    try {
        Map.prototype.set.call({}, 1, 2);
        ok(false, "expected exception");
    }catch(e) {
        ok(e.number === 0xa13fc - 0x80000000, "e.number = " + e.number);
    }

    s = new Map();
    s.set(1, 10);
    s.set(2, 20);
    s.set(3, 30);
    r = 0;
    s.forEach(function(value, key) {
        r++;
        s.clear();
        ok(s.size === 0, "size = " + s.size);
        ok(this.valueOf() === 42, "this.valueOf() = " + this.valueOf());
    }, 42);
    ok(r === 1, "r = " + r);
});

async_test("weakmap_obj", function() {
    if(!("WeakMap" in window)) { next_test(); return; }

    try {
        var s = WeakMap();
        ok(false, "expected exception calling constructor as method");
    }catch(e) {
        ok(e.number === 0xa13fc - 0x80000000, "calling constructor as method threw " + e.number);
    }

    var s = new WeakMap, r, o, o2;
    ok(Object.getPrototypeOf(s) === WeakMap.prototype, "unexpected WeakMap prototype");

    function test_length(name, len) {
        ok(WeakMap.prototype[name].length === len, "WeakMap.prototype." + name + " = " + WeakMap.prototype[name].length);
    }
    test_length("clear", 0);
    test_length("delete", 1);
    test_length("get", 1);
    test_length("has", 1);
    test_length("set", 2);
    ok(!("entries" in s), "entries is in WeakMap");
    ok(!("forEach" in s), "forEach is in WeakMap");
    ok(!("keys" in s), "keys is in WeakMap");
    ok(!("size" in s), "size is in WeakMap");
    ok(!("values" in s), "values is in WeakMap");

    r = Object.prototype.toString.call(s);
    ok(r === "[object Object]", "toString returned " + r);

    r = s.get("test");
    ok(r === undefined, "get('test') returned " + r);
    r = s.has("test");
    ok(r === false, "has('test') returned " + r);

    try {
        r = s.set("test", 1);
        ok(false, "set('test') did not throw");
    }catch(e) {
        ok(e.number === 0xa13fd - 0x80000000, "set('test') threw " + e.number);
    }
    try {
        r = s.set(external.testHostContext(true), 1);
        ok(false, "set(host_obj) did not throw");
    }catch(e) {
        ok(e.number === 0xa13fd - 0x80000000, "set(host_obj) threw " + e.number);
    }

    r = s.set({}, 1);
    ok(r === undefined, "set({}, 1) returned " + r);

    o = {}, o2 = {};
    r = s.get({});
    ok(r === undefined, "get({}) returned " + r);
    r = s.has({});
    ok(r === false, "has({}) returned " + r);

    r = s.set(o, 2);
    ok(r === undefined, "set(o, 2) returned " + r);
    r = s.get(o);
    ok(r === 2, "get(o) returned " + r);
    r = s.has(o);
    ok(r === true, "has(o) returned " + r);
    r = s.get(o2);
    ok(r === undefined, "get(o2) before set returned " + r);
    r = s.has(o2);
    ok(r === false, "has(o2) before set returned " + r);
    r = s.set(o2, "test");
    ok(r === undefined, "set(o2, 'test') returned " + r);
    r = s.get(o2);
    ok(r === "test", "get(o2) returned " + r);
    r = s.has(o2);
    ok(r === true, "has(o2) returned " + r);

    r = s["delete"]("test"); /* using s.delete() would break parsing in quirks mode */
    ok(r === false, "delete('test') returned " + r);
    r = s["delete"]({});
    ok(r === false, "delete({}) returned " + r);
    r = s["delete"](o);
    ok(r === true, "delete(o) returned " + r);

    r = s.get(o);
    ok(r === undefined, "get(o) after delete returned " + r);
    r = s.has(o);
    ok(r === false, "has(o) after delete returned " + r);
    r = s.get(o2);
    ok(r === "test", "get(o2) after delete returned " + r);
    r = s.has(o2);
    ok(r === true, "has(o2) after delete returned " + r);

    r = s.set(o, undefined);
    ok(r === undefined, "set(o, undefined) returned " + r);
    r = s.get(o);
    ok(r === undefined, "get(o) after re-set returned " + r);
    r = s.has(o);
    ok(r === true, "has(o) after re-set returned " + r);

    r = s.clear();
    ok(r === undefined, "clear() returned " + r);
    r = s.get(o);
    ok(r === undefined, "get(o) after clear returned " + r);
    r = s.has(o);
    ok(r === false, "has(o) after clear returned " + r);
    r = s.get(o2);
    ok(r === undefined, "get(o2) after clear returned " + r);
    r = s.has(o2);
    ok(r === false, "has(o2) after clear returned " + r);

    r = external.newRefTest();
    ok(r.ref === 1, "wrong ref after newRefTest: " + r.ref);
    o = { val: r.get(), map: s };
    s.set(o, o);
    ok(r.ref > 1, "map entry released");

    o = Date.now();
    CollectGarbage();
    function retry() {
        if(r.ref > 1 && Date.now() - o < 5000) {
            CollectGarbage();
            window.setTimeout(retry);
            return;
        }
        ok(r.ref === 1, "map entry not released");
        next_test();
    }
    window.setTimeout(retry);
});

sync_test("storage", function() {
    var v = document.documentMode, i, r, list;

    sessionStorage["add-at-end"] = 0;
    sessionStorage.removeItem("add-at-end");

    sessionStorage.setItem("foobar", "1234");
    ok("foobar" in sessionStorage, "foobar not in sessionStorage");
    r = sessionStorage.foobar;
    ok(r === "1234", "sessionStorage.foobar = " + r);
    sessionStorage.barfoo = 4321;
    r = sessionStorage.getItem("barfoo");
    ok(r === "4321", "sessionStorage.barfoo = " + r);
    sessionStorage.setItem("abcd", "blah");
    sessionStorage.dcba = "test";

    // Order isn't consistent, but changes are reflected during the enumeration.
    // Elements that were already traversed in DISPID (even if removed before
    // the enumeration) are not enumerated, even if re-added during the enum.
    i = 0; list = [ "foobar", "barfoo", "abcd", "dcba" ];
    for(r in sessionStorage) {
        for(var j = 0; j < list.length; j++)
            if(r === list[j])
                break;
        ok(j < list.length, "got '" + r + "' enumerating");
        list.splice(j, 1);
        if(i === 1) {
            sessionStorage.removeItem(list[0]);
            sessionStorage.setItem("new", "new");
            list.splice(0, 1, "new");
        }
        if(!list.length)
            sessionStorage.setItem("add-at-end", "0");
        i++;
    }
    ok(i === 4, "enum did " + i + " iterations");

    try {
        delete sessionStorage.foobar;
        ok(v >= 8, "expected exception deleting sessionStorage.foobar");
        ok(!("foobar" in sessionStorage), "foobar in sessionStorage after deletion");
        r = sessionStorage.getItem("foobar");
        ok(r === null, "sessionStorage.foobar after deletion = " + r);
    }catch(e) {
        ok(v < 8, "did not expect exception deleting sessionStorage.foobar");
        ok(e.number === 0xa01bd - 0x80000000, "deleting sessionStorage.foobar threw = " + e.number);
    }

    sessionStorage.clear();
});

async_test("storage events", function() {
    var iframe = document.createElement("iframe"), iframe2 = document.createElement("iframe");
    var local = false, storage, storage2, v = document.documentMode, i = 0;

    var tests = [
        function() {
            expect();
            storage.removeItem("foobar");
        },
        function() {
            expect(0, "foobar", "", "test");
            storage.setItem("foobar", "test");
        },
        function() {
            expect(1, "foobar", "test", "TEST", true);
            storage2.setItem("foobar", "TEST");
        },
        function() {
            expect(0, "foobar", "TEST", "");
            storage.removeItem("foobar");
        },
        function() {
            expect(1, "winetest", "", "WineTest");
            storage2.setItem("winetest", "WineTest");
        },
        function() {
            expect(0, "", "", "");
            storage.clear();
        }
    ];

    function next() {
        if(++i < tests.length)
            tests[i]();
        else if(local)
            next_test();
        else {
            // w10pro64 testbot VM throws WININET_E_INTERNAL_ERROR for some reason
            storage = null, storage2 = null;
            try {
                storage = window.localStorage, storage2 = iframe.contentWindow.localStorage;
            }catch(e) {
                ok(e.number === 0x72ee4 - 0x80000000, "localStorage threw " + e.number + ": " + e);
            }
            if(!storage || !storage2) {
                win_skip("localStorage is buggy and not available, skipping");
                next_test();
                return;
            }
            i = 0, local = true;

            if(!storage.length)
                setTimeout(function() { tests[0](); });
            else {
                // Get rid of any entries first, since native doesn't update immediately
                var w = [ window, iframe.contentWindow ];
                for(var j = 0; j < w.length; j++)
                    w[j].onstorage = w[j].document.onstorage = w[j].document.onstoragecommit = null;
                document.onstoragecommit = function() {
                    if(!storage.length)
                        setTimeout(function() { tests[0](); });
                    else
                        storage.clear();
                };
                storage.clear();
            }
        }
    }

    function test_event(e, idx, key, oldValue, newValue) {
        if(v < 9) {
            ok(e === undefined, "event not undefined in legacy mode: " + e);
            return;
        }
        var s = Object.prototype.toString.call(e);
        todo_wine_if(e.target != window && e.target != document).
        ok(s === "[object StorageEvent]", "Object.toString = " + s);
        ok(e.key === key, "key = " + e.key + ", expected " + key);
        ok(e.oldValue === oldValue, "oldValue = " + e.oldValue + ", expected " + oldValue);
        ok(e.newValue === newValue, "newValue = " + e.newValue + ", expected " + newValue);
        s = (idx ? iframe.contentWindow : window)["location"]["href"].split('#', 1)[0];
        ok(e.url === s, "url = " + e.url + ", expected " + s);
    }

    function expect(idx, key, oldValue, newValue, quirk) {
        var window2 = iframe.contentWindow, document2 = window2.document;
        window.onstorage = function() { ok(false, "window.onstorage called"); };
        document.onstorage = function() { ok(false, "doc.onstorage called"); };
        document.onstoragecommit = function() { ok(false, "doc.onstoragecommit called"); };
        window2.onstorage = function() { ok(false, "iframe window.onstorage called"); };
        document2.onstorage = function() { ok(false, "iframe doc.onstorage called"); };
        document2.onstoragecommit = function() { ok(false, "iframe doc.onstoragecommit called"); };

        if(idx === undefined) {
            setTimeout(function() { next(); });
        }else {
            // Native sometimes calls this for some reason
            if(local && quirk) document.onstoragecommit = null;

            (v < 9 ? document2 : window2)["onstorage"] = function(e) {
                (local && idx ? document2 : (local || v < 9 ? document : window))[local ? "onstoragecommit" : "onstorage"] = function(e) {
                    test_event(e, idx, local ? "" : key, local ? "" : oldValue, local ? "" : newValue);
                    next();
                }
                test_event(e, idx, key, oldValue, newValue);
            }
        }
    }

    iframe.onload = function() {
        iframe2.onload = function() {
            var w = iframe2.contentWindow;
            w.onstorage = function() { ok(false, "about:blank window.onstorage called"); };
            w.document.onstorage = function() { ok(false, "about:blank document.onstorage called"); };
            w.document.onstoragecommit = function() { ok(false, "about:blank document.onstoragecommit called"); };

            storage = window.sessionStorage, storage2 = iframe.contentWindow.sessionStorage;
            tests[0]();
        };
        iframe2.src = "about:blank";
        document.body.appendChild(iframe2);
    };
    iframe.src = "blank.html";
    document.body.appendChild(iframe);
});

sync_test("elem_attr", function() {
    var v = document.documentMode;
    var elem = document.createElement("div"), r;

    function test_exposed(prop, expect) {
        if(expect)
            ok(prop in elem, prop + " is not exposed from elem");
        else
            ok(!(prop in elem), prop + " is exposed from elem");
    }

    r = elem.getAttribute("class");
    ok(r === null, "class attr = " + r);
    r = elem.getAttribute("className");
    ok(r === (v < 8 ? "" : null), "className attr = " + r);

    elem.className = "cls";
    r = elem.getAttribute("class");
    ok(r === (v < 8 ? null : "cls"), "class attr = " + r);
    r = elem.getAttribute("className");
    ok(r === (v < 8 ? "cls" : null), "className attr = " + r);

    elem.setAttribute("class", "cls2");
    ok(elem.className === (v < 8 ? "cls" : "cls2"), "elem.className = " + elem.className);
    r = elem.getAttribute("class");
    ok(r === "cls2", "class attr = " + r);
    r = elem.getAttribute("className");
    ok(r === (v < 8 ? "cls" : null), "className attr = " + r);

    elem.setAttribute("className", "cls3");
    ok(elem.className === (v < 8 ? "cls3" : "cls2"), "elem.className = " + elem.className);
    r = elem.getAttribute("class");
    ok(r === "cls2", "class attr = " + r);
    r = elem.getAttribute("className");
    ok(r === "cls3", "className attr = " + r);

    elem.htmlFor = "for";
    r = elem.getAttribute("for");
    ok(r === null, "for attr = " + r);
    r = elem.getAttribute("htmlFor");
    ok(r === (v < 9 ? "for" : null), "htmlFor attr = " + r);

    elem.setAttribute("for", "for2");
    ok(elem.htmlFor === "for", "elem.htmlFor = " + elem.htmlFor);
    r = elem.getAttribute("for");
    ok(r === "for2", "for attr = " + r);
    r = elem.getAttribute("htmlFor");
    ok(r === (v < 9 ? "for" : null), "htmlFor attr = " + r);

    elem.setAttribute("htmlFor", "for3");
    ok(elem.htmlFor === (v < 9 ? "for3" : "for"), "elem.htmlFor = " + elem.htmlFor);
    r = elem.getAttribute("for");
    ok(r === "for2", "for attr = " + r);
    r = elem.getAttribute("htmlFor");
    ok(r === "for3", "htmlFor attr = " + r);

    elem.setAttribute("testattr", "test", 0, "extra arg", 0xdeadbeef);
    test_exposed("class", v < 8);
    test_exposed("className", true);
    test_exposed("for", v < 9);
    test_exposed("htmlFor", true);
    test_exposed("testattr", v < 9);

    var arr = [3];
    elem.setAttribute("testattr", arr);
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : "3"), "testattr = " + r);
    ok(elem.testattr === (v < 9 ? arr : undefined), "elem.testattr = " + elem.testattr);
    r = elem.removeAttribute("testattr");
    ok(r === (v < 9 ? true : undefined), "testattr removeAttribute returned " + r);
    ok(elem.testattr === undefined, "removed testattr = " + elem.testattr);

    arr[0] = 9;
    elem.setAttribute("testattr", "string");
    elem.testattr = arr;
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 9 ? "9" : "string")), "testattr = " + r);
    ok(elem.testattr === arr, "elem.testattr = " + elem.testattr);
    arr[0] = 3;
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 9 ? "3" : "string")), "testattr = " + r);
    ok(elem.testattr === arr, "elem.testattr = " + elem.testattr);
    r = elem.removeAttribute("testattr");
    ok(r === (v < 9 ? true : undefined), "testattr removeAttribute returned " + r);
    ok(elem.testattr === (v < 9 ? undefined : arr), "removed testattr = " + elem.testattr);

    arr.toString = function() { return 42; }
    elem.testattr = arr;
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 9 ? "42" : null)), "testattr with custom toString = " + r);
    elem.setAttribute("testattr", arr);
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : "42"), "testattr after setAttribute with custom toString = " + r);
    ok(elem.testattr === arr, "elem.testattr after setAttribute with custom toString = " + elem.testattr);
    r = elem.removeAttribute("testattr");
    ok(r === (v < 9 ? true : undefined), "testattr removeAttribute with custom toString returned " + r);
    ok(elem.testattr === (v < 9 ? undefined : arr), "removed testattr with custom toString = " + elem.testattr);

    arr.valueOf = function() { return "arrval"; }
    elem.testattr = arr;
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 9 ? "arrval" : null)), "testattr with custom valueOf = " + r);
    elem.setAttribute("testattr", arr);
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 10 ? "arrval" : "42")), "testattr after setAttribute with custom valueOf = " + r);
    ok(elem.testattr === arr, "elem.testattr after setAttribute with custom valueOf = " + elem.testattr);
    r = elem.removeAttribute("testattr");
    ok(r === (v < 9 ? true : undefined), "testattr removeAttribute with custom valueOf returned " + r);
    ok(elem.testattr === (v < 9 ? undefined : arr), "removed testattr with custom valueOf = " + elem.testattr);

    var func = elem.setAttribute;
    try {
        func("testattr", arr);
        ok(v < 9, "expected exception setting testattr via func");
    }catch(ex) {
        ok(v >= 9, "did not expect exception setting testattr via func");
        func.call(elem, "testattr", arr);
    }
    r = elem.getAttribute("testattr");
    ok(r === (v < 8 ? arr : (v < 10 ? "arrval" : "42")), "testattr after setAttribute (as func) = " + r);
    delete arr.valueOf;
    delete arr.toString;

    elem.setAttribute("id", arr);
    r = elem.getAttribute("id");
    todo_wine_if(v >= 8 && v < 10).
    ok(r === (v < 8 || v >= 10 ? "3" : "[object]"), "id = " + r);
    r = elem.removeAttribute("id");
    ok(r === (v < 9 ? true : undefined), "id removeAttribute returned " + r);
    ok(elem.id === "", "removed id = " + elem.id);

    func = function() { };
    elem.onclick = func;
    ok(elem.onclick === func, "onclick = " + elem.onclick);
    r = elem.getAttribute("onclick");
    todo_wine_if(v === 8).
    ok(r === (v < 8 ? func : null), "onclick attr = " + r);
    r = elem.removeAttribute("onclick");
    ok(r === (v < 9 ? false : undefined), "removeAttribute returned " + r);
    todo_wine_if(v === 8).
    ok(elem.onclick === (v != 8 ? func : null), "removed onclick = " + elem.onclick);

    elem.onclick_test = func;
    ok(elem.onclick_test === func, "onclick_test = " + elem.onclick_test);
    r = elem.getAttribute("onclick_test");
    ok(r === (v < 8 ? func : (v < 9 ? func.toString() : null)), "onclick_test attr = " + r);

    elem.setAttribute("onclick", "test");
    r = elem.getAttribute("onclick");
    ok(r === "test", "onclick attr after setAttribute = " + r);
    r = elem.removeAttribute("onclick");
    ok(r === (v < 9 ? true : undefined), "removeAttribute after setAttribute returned " + r);

    /* IE11 returns an empty function, which we can't check directly */
    todo_wine_if(v >= 9).
    ok((v < 11) ? (elem.onclick === null) : (elem.onclick !== func), "removed onclick after setAttribute = " + elem.onclick);

    r = Object.prototype.toString.call(elem.onclick);
    todo_wine_if(v >= 9 && v < 11).
    ok(r === (v < 9 ? "[object Object]" : (v < 11 ? "[object Null]" : "[object Function]")),
        "removed onclick after setAttribute Object.toString returned " + r);

    elem.setAttribute("onclick", "string");
    r = elem.getAttribute("onclick");
    ok(r === "string", "onclick attr after setAttribute = " + r);
    elem.onclick = func;
    ok(elem.onclick === func, "onclick = " + elem.onclick);
    r = elem.getAttribute("onclick");
    todo_wine_if(v === 8).
    ok(r === (v < 8 ? func : (v < 9 ? null : "string")), "onclick attr = " + r);
    elem.onclick = "test";
    r = elem.getAttribute("onclick");
    ok(r === (v < 9 ? "test" : "string"), "onclick attr = " + r);
    r = elem.removeAttribute("onclick");
    ok(r === (v < 9 ? true : undefined), "removeAttribute returned " + r);
    todo_wine_if(v >= 9).
    ok(elem.onclick === null, "removed onclick = " + elem.onclick);

    elem.setAttribute("ondblclick", arr);
    r = elem.getAttribute("ondblclick");
    todo_wine_if(v >= 8 && v < 10).
    ok(r === (v < 8 ? arr : (v < 10 ? "[object]" : "3")), "ondblclick = " + r);
    r = elem.removeAttribute("ondblclick");
    ok(r === (v < 8 ? false : (v < 9 ? true : undefined)), "ondblclick removeAttribute returned " + r);
    r = Object.prototype.toString.call(elem.ondblclick);
    todo_wine_if(v >= 11).
    ok(r === (v < 8 ? "[object Array]" : (v < 9 ? "[object Object]" : (v < 11 ? "[object Null]" : "[object Function]"))),
        "removed ondblclick Object.toString returned " + r);

    elem.setAttribute("ondblclick", "string");
    r = elem.getAttribute("ondblclick");
    ok(r === "string", "ondblclick string = " + r);
    r = elem.removeAttribute("ondblclick");
    ok(r === (v < 9 ? true : undefined), "ondblclick string removeAttribute returned " + r);
    ok(elem.ondblclick === null, "removed ondblclick string = " + elem.ondblclick);

    if(v < 9) {
        /* style is a special case */
        try {
            elem.style = "opacity: 1.0";
            ok(false, "expected exception setting elem.style");
        }catch(ex) { }

        var style = elem.style;
        r = elem.getAttribute("style");
        ok(r === (v < 8 ? style : null), "style attr = " + r);
        r = elem.removeAttribute("style");
        ok(r === true, "removeAttribute('style') returned " + r);
        r = elem.style;
        ok(r === style, "removed elem.style = " + r);
        r = elem.getAttribute("style");
        ok(r === (v < 8 ? style : null), "style attr after removal = " + r);
        elem.setAttribute("style", "opacity: 1.0");
        r = elem.getAttribute("style");
        ok(r === (v < 8 ? style : "opacity: 1.0"), "style attr after setAttribute = " + r);
        r = elem.style;
        ok(r === style, "elem.style after setAttribute = " + r);
    }
});

sync_test("elem_attrNS", function() {
    var v = document.documentMode;
    if(v < 9) return;  /* not available */

    var specialspace_ns = "http://www.mozilla.org/ns/specialspace";

    var elem = document.createElement("div"), r;

    elem.setAttributeNS(specialspace_ns, "spec:align", "left");
    r = elem.hasAttribute("spec:align");
    ok(r === true, "spec:align does not exist");
    r = elem.getAttribute("spec:align");
    ok(r === "left", "spec:align = " + r);
    r = elem.hasAttribute("align");
    ok(r === false, "align exists");
    r = elem.getAttribute("align");
    ok(r === null, "align = " + r);
    r = elem.hasAttributeNS(null, "spec:align");
    ok(r === false, "null spec:align exists");
    r = elem.getAttributeNS(null, "spec:align");
    ok(r === "", "null spec:align = " + r);
    r = elem.hasAttributeNS(null, "spec:align");
    ok(r === false, "null align exists");
    r = elem.getAttributeNS(null, "align");
    ok(r === "", "null align = " + r);
    r = elem.hasAttributeNS(svg_ns, "spec:align");
    ok(r === false, "svg spec:align exists");
    r = elem.getAttributeNS(svg_ns, "spec:align");
    ok(r === "", "svg spec:align = " + r);
    r = elem.hasAttributeNS(svg_ns, "align");
    ok(r === false, "svg align exists");
    r = elem.getAttributeNS(svg_ns, "align");
    ok(r === "", "svg align = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "spec:align");
    ok(r === false, "specialspace spec:align exists");
    r = elem.getAttributeNS(specialspace_ns, "spec:align");
    ok(r === "", "specialspace spec:align = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "align");
    ok(r === true, "specialspace align does not exist");
    r = elem.getAttributeNS(specialspace_ns, "align");
    ok(r === "left", "specialspace align = " + r);

    try {
        elem.setAttributeNS(null, "spec:align", "right");
        ok(false, "expected exception setting qualified attr with null ns");
    }catch(ex) {
        todo_wine.
        ok(ex.message === "NamespaceError", "setAttributeNS(null, 'spec:align', 'right') threw " + ex.message);
    }
    try {
        elem.setAttributeNS("", "spec:align", "right");
        ok(false, "expected exception setting qualified attr with empty ns");
    }catch(ex) {
        todo_wine.
        ok(ex.message === "NamespaceError", "setAttributeNS('', 'spec:align', 'right') threw " + ex.message);
    }
    elem.setAttributeNS(null, "align", "right");
    r = elem.getAttribute("spec:align");
    ok(r === "left", "spec:align (null) = " + r);
    r = elem.hasAttribute("align");
    ok(r === true, "align (null) does not exist");
    r = elem.getAttribute("align");
    ok(r === "right", "align (null) = " + r);
    r = elem.hasAttributeNS(null, "spec:align");
    ok(r === false, "null spec:align exists");
    r = elem.getAttributeNS(null, "spec:align");
    ok(r === "", "null spec:align (null) = " + r);
    r = elem.hasAttributeNS(null, "align");
    ok(r === true, "null align does not exist");
    r = elem.getAttributeNS(null, "align");
    ok(r === "right", "null align (null) = " + r);
    r = elem.hasAttributeNS(svg_ns, "spec:align");
    ok(r === false, "svg spec:align (null) exists");
    r = elem.getAttributeNS(svg_ns, "spec:align");
    ok(r === "", "svg spec:align (null) = " + r);
    r = elem.hasAttributeNS(svg_ns, "align");
    ok(r === false, "svg align (null) exists");
    r = elem.getAttributeNS(svg_ns, "align");
    ok(r === "", "svg align (null) = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "spec:align");
    ok(r === false, "specialspace_ns spec:align (null) exists");
    r = elem.getAttributeNS(specialspace_ns, "spec:align");
    ok(r === "", "specialspace spec:align (null) = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "align");
    ok(r === true, "specialspace align (null) does not exist");
    r = elem.getAttributeNS(specialspace_ns, "align");
    ok(r === "left", "specialspace align (null) = " + r);

    elem.setAttribute("align", "center");
    r = elem.hasAttributeNS(null, "spec:align");
    ok(r === false, "null spec:align (non-NS) exists");
    r = elem.getAttributeNS(null, "spec:align");
    ok(r === "", "null spec:align (non-NS) = " + r);
    r = elem.hasAttributeNS(null, "align");
    ok(r === true, "null align (non-NS) does not exist");
    r = elem.getAttributeNS(null, "align");
    ok(r === "center", "null align (non-NS) = " + r);
    r = elem.hasAttributeNS(svg_ns, "spec:align");
    ok(r === false, "svg spec:align (non-NS) exists");
    r = elem.getAttributeNS(svg_ns, "spec:align");
    ok(r === "", "svg spec:align (non-NS) = " + r);
    r = elem.hasAttributeNS(svg_ns, "align");
    ok(r === false, "svg align (non-NS) exists");
    r = elem.getAttributeNS(svg_ns, "align");
    ok(r === "", "svg align (non-NS) = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "spec:align");
    ok(r === false, "specialspace spec:align (non-NS) exists");
    r = elem.getAttributeNS(specialspace_ns, "spec:align");
    ok(r === "", "specialspace spec:align (non-NS) = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "align");
    ok(r === true, "specialspace align (non-NS) does not exist");
    r = elem.getAttributeNS(specialspace_ns, "align");
    ok(r === "left", "specialspace align (non-NS) = " + r);
    elem.removeAttributeNS(null, "spec:align");

    elem.setAttribute("emptynsattr", "none");
    elem.setAttributeNS("", "emptynsattr", "test");
    r = elem.hasAttribute("emptynsattr");
    ok(r === true, "emptynsattr without NS does not exist");
    r = elem.getAttribute("emptynsattr");
    ok(r === "test", "emptynsattr without NS = " + r);
    elem.setAttributeNS(null, "emptynsattr", "wine");
    r = elem.hasAttribute("emptynsattr");
    ok(r === true, "emptynsattr without NS does not exist");
    r = elem.getAttribute("emptynsattr");
    ok(r === "wine", "emptynsattr without NS = " + r);
    elem.setAttributeNS(specialspace_ns, "emptynsattr", "ns");
    r = elem.hasAttribute("emptynsattr");
    ok(r === true, "emptynsattr without NS does not exist");
    r = elem.getAttribute("emptynsattr");
    ok(r === "wine", "emptynsattr without NS = " + r);
    r = elem.hasAttributeNS("", "emptynsattr");
    ok(r === true, "emptynsattr empty ns does not exist");
    r = elem.getAttributeNS("", "emptynsattr");
    ok(r === "wine", "emptynsattr empty ns = " + r);
    r = elem.hasAttributeNS(null, "emptynsattr");
    ok(r === true, "emptynsattr null ns does not exist");
    r = elem.getAttributeNS(null, "emptynsattr");
    ok(r === "wine", "emptynsattr null ns = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === true, "emptynsattr specialspace ns does not exist");
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "ns", "emptynsattr specialspace ns = " + r);

    elem.removeAttributeNS("", "emptynsattr");
    r = elem.hasAttribute("emptynsattr");
    ok(r === true, "emptynsattr without NS after remove does not exist");
    r = elem.getAttribute("emptynsattr");
    ok(r === "ns", "emptynsattr without NS after remove = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === true, "emptynsattr specialspace ns after empty remove does not exist");
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "ns", "emptynsattr specialspace ns after empty remove = " + r);
    elem.setAttribute("emptynsattr", "test");
    r = elem.getAttribute("emptynsattr");
    ok(r === "test", "emptynsattr without NS after re-set = " + r);
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "test", "emptynsattr specialspace ns after empty re-set = " + r);

    elem.removeAttribute("emptynsattr");
    r = elem.hasAttribute("emptynsattr");
    ok(r === false, "emptynsattr without NS after non-NS remove exists");
    r = elem.getAttribute("emptynsattr");
    ok(r === null, "emptynsattr without NS after non-NS remove = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === false, "emptynsattr specialspace ns after non-NS remove exists");
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "", "emptynsattr specialspace ns after non-NS remove = " + r);

    elem.setAttributeNS(specialspace_ns, "emptynsattr", "ns");
    elem.removeAttributeNS(svg_ns, "emptynsattr");
    r = elem.hasAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === true, "emptynsattr specialspace ns after wrong NS remove does not exist");
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "ns", "emptynsattr specialspace ns after wrong NS remove = " + r);
    r = elem.hasAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === true, "emptynsattr specialspace ns after remove does not exist");
    r = elem.getAttributeNS(specialspace_ns, "emptynsattr");
    ok(r === "ns", "emptynsattr specialspace ns after remove = " + r);

    var ns = {};
    ns.toString = function() { return "toString namespace"; }
    ns.valueOf = function() { return "valueOf namespace"; }
    elem.setAttributeNS(ns, "foobar", "test");
    r = elem.hasAttribute("foobar");
    ok(r === true, "foobar without NS does not exist");
    r = elem.getAttribute("foobar");
    ok(r === "test", "foobar without NS = " + r);
    r = elem.hasAttributeNS(ns, "foobar");
    ok(r === true, "foobar does not exist");
    r = elem.getAttributeNS(ns, "foobar");
    ok(r === "test", "foobar = " + r);
    r = elem.hasAttributeNS("toString namespace", "foobar");
    ok(r === (v < 10 ? false : true), "foobar (toString namespace) " + (v < 10 ? "exists" : "does not exist"));
    r = elem.getAttributeNS("toString namespace", "foobar");
    ok(r === (v < 10 ? "" : "test"), "foobar (toString namespace) = " + r);
    r = elem.hasAttributeNS("valueOf namespace", "foobar");
    ok(r === (v < 10 ? true : false), "foobar (valueOf namespace) = " + (v < 10 ? "does not exist" : "exists"));
    r = elem.getAttributeNS("valueOf namespace", "foobar");
    ok(r === (v < 10 ? "test" : ""), "foobar (valueOf namespace) = " + r);

    var arr = [3];
    elem.setAttributeNS(svg_ns, "testattr", arr);
    r = elem.getAttributeNS(svg_ns, "testattr");
    ok(r === "3", "testattr = " + r);
    ok(elem.testattr === undefined, "elem.testattr = " + elem.testattr);
    elem.removeAttributeNS(svg_ns, "testattr");
    r = elem.getAttributeNS(svg_ns, "testattr");
    ok(r === "", "testattr after remove = " + r);

    arr.toString = function() { return 42; }
    elem.setAttributeNS(svg_ns, "testattr", arr);
    r = elem.getAttributeNS(svg_ns, "testattr");
    ok(r === "42", "testattr with custom toString = " + r);
    elem.removeAttributeNS(svg_ns, "testattr");
    r = elem.getAttributeNS(svg_ns, "testattr");
    ok(r === "", "testattr with custom toString after remove = " + r);

    arr.valueOf = function() { return "arrval"; }
    elem.setAttributeNS(svg_ns, "testattr", arr);
    r = elem.getAttributeNS(svg_ns, "testattr");
    ok(r === "42", "testattr with custom valueOf = " + r);
    elem.removeAttributeNS(svg_ns, "testattr");

    elem.setAttributeNS(svg_ns, "boolattr", true);
    r = elem.getAttributeNS(svg_ns, "boolattr");
    ok(r === "true", "boolattr = " + r);

    elem.setAttributeNS(svg_ns, "numattr", 13);
    r = elem.getAttributeNS(svg_ns, "numattr");
    ok(r === "13", "numattr = " + r);
});

sync_test("builtins_diffs", function() {
    var v = document.documentMode;

    /* despite what spec says for ES6, IE still throws */
    var props = [
        "freeze",
        "getPrototypeOf",
        "isExtensible",
        "isFrozen",
        "isSealed",
        "keys",
        "preventExtensions",
        "seal"
    ];
    for(var i = 0; i < props.length; i++) {
        try {
            Object[props[i]]("test");
            ok(false, "Object." + props[i] + " with non-object: expected exception");
        }catch(e) {
            ok(e.number === (v < 9 ? 0xa01b6 : 0xa138f) - 0x80000000, "Object." + props[i] + " with non-object: exception = " + e.number);
        }
    }

    try {
        RegExp.prototype.toString.call({source: "foo", flags: "g"});
        ok(false, "RegExp.toString with non-regexp: expected exception");
    }catch(e) {
        ok(e.number === 0xa1398 - 0x80000000, "RegExp.toString with non-regexp: exception = " + e.number);
    }
    try {
        RegExp.prototype.toString.call({source: "abc", global: true, ignoreCase: true, multiline: true});
        ok(false, "RegExp.toString with non-regexp 2: expected exception");
    }catch(e) {
        ok(e.number === 0xa1398 - 0x80000000, "RegExp.toString with non-regexp 2: exception = " + e.number);
    }

    try {
        /a/.lastIndex();
        ok(false, "/a/.lastIndex(): expected exception");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "/a/.lastIndex(): exception = " + e.number);
    }
    try {
        "a".length();
        ok(false, "\"a\".length(): expected exception");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "\"a\".length(): exception = " + e.number);
    }
});

sync_test("style attribute", function() {
    var r, v = document.documentMode, s = document.createElement("div").style;

    s.setAttribute("background-color", "black");
    s.foobar = "white";

    r = s.getAttribute("background-color");
    ok(r === "black", "background-color = " + r);
    r = s.foobar;
    ok(r === "white", "foobar prop = " + r);

    r = s.removeAttribute("background-color");
    ok(r === true, "removeAttribute(background-color) returned " + r);
    r = s.removeAttribute("border");
    ok(r === false, "removeAttribute(border) returned " + r);
    r = s.removeAttribute("foobar");
    ok(r === (v < 9 ? true : false), "removeAttribute(foobar) returned " + r);
    r = s.removeAttribute("barfoo");
    ok(r === false, "removeAttribute(barfoo) returned " + r);

    r = s.getAttribute("background-color");
    ok(r === "", "background-color after remove = " + r);
    if(v < 9)
        ok(!("foobar" in s), "foobar in style after remove");
    else {
        r = s.foobar;
        ok(r === "white", "foobar prop after remove = " + r);
    }
});

sync_test("nullDisp", function() {
    var v = document.documentMode, nullDisp = external.nullDisp, r;

    ok(external.getVT(nullDisp) === "VT_NULL", "getVT(nullDisp) is not VT_NULL");
    ok(typeof(nullDisp) === "object", "typeof(nullDisp) = " + typeof(nullDisp));
    ok(nullDisp === nullDisp, "nullDisp !== nullDisp");
    ok(nullDisp === null, "nullDisp === null");
    ok(nullDisp == null, "nullDisp == null");
    ok(!nullDisp === true, "!nullDisp = " + !nullDisp);
    ok(String(nullDisp) === "null", "String(nullDisp) = " + String(nullDisp));
    ok(+nullDisp === 0, "+nullDisp !== 0");
    ok(''+nullDisp === "null", "''+nullDisp !== null");
    ok(nullDisp != new Object(), "nullDisp == new Object()");
    ok(new Object() != nullDisp, "new Object() == nullDisp");
    ok((typeof Object(nullDisp)) === "object", "typeof Object(nullDisp) !== 'object'");
    r = Object(nullDisp).toString();
    ok(r === "[object Object]", "Object(nullDisp).toString() = " + r);
    ok(Object(nullDisp) != nullDisp, "Object(nullDisp) == nullDisp");
    ok(new Object(nullDisp) != nullDisp, "new Object(nullDisp) == nullDisp");
    r = (nullDisp instanceof Object);
    ok(r === false, "nullDisp instance of Object");

    if(v >= 8) {
        r = JSON.stringify.call(null, nullDisp);
        ok(r === "null", "JSON.stringify(nullDisp) returned " + r);
    }

    try {
        (new Object()) instanceof nullDisp;
        ok(false, "expected exception on (new Object()) instanceof nullDisp");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "(new Object()) instanceof nullDisp threw " + e.number);
    }

    try {
        Function.prototype.apply.call(nullDisp, Object, []);
        ok(false, "expected exception calling Function.apply on nullDisp");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "Function.apply on nullDisp threw " + e.number);
    }
    try {
        Function.prototype.call.call(nullDisp, Object);
        ok(false, "expected exception calling Function.call on nullDisp");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "Function.call on nullDisp threw " + e.number);
    }

    try {
        new nullDisp;
        ok(false, "expected exception for new nullDisp");
    }catch(e) {
        ok(e.number === 0xa138f - 0x80000000, "new nullDisp threw " + e.number);
    }
});

sync_test("invalid selectors", function() {
    var v = document.documentMode, body = document.body, i;
    if(v < 8)
        return;

    var selectors = [
        "[s!='']",
        "*,:x",
        "*,##",
        ":x",
        "##",
        "*,",
        ","
    ];

    for(i = 0; i < selectors.length; i++) {
        try {
            body.querySelector(selectors[i]);
            ok(false, "body.querySelector(\"" + selectors[i] + "\" did not throw exception");
        }catch(e) {
            if(v < 9)
                ok(e.number === 0x70057 - 0x80000000, "body.querySelector(\"" + selectors[i] + "\" threw " + e.number);
            else {
                todo_wine.
                ok(e.name === (v < 10 ? undefined : "SyntaxError"), "body.querySelector(\"" + selectors[i] + "\" threw " + e.name);
            }
        }
        try {
            body.querySelectorAll(selectors[i]);
            ok(false, "body.querySelectorAll(\"" + selectors[i] + "\" did not throw exception");
        }catch(e) {
            if(v < 9)
                ok(e.number === 0x70057 - 0x80000000, "body.querySelectorAll(\"" + selectors[i] + "\" threw " + e.number);
            else {
                todo_wine.
                ok(e.name === (v < 10 ? undefined : "SyntaxError"), "body.querySelectorAll(\"" + selectors[i] + "\" threw " + e.name);
            }
        }
    }

    if(!body.msMatchesSelector)
        return;

    for(i = 0; i < selectors.length; i++) {
        try {
            body.msMatchesSelector(selectors[i]);
            ok(false, "body.msMatchesSelector(\"" + selectors[i] + "\" did not throw exception");
        }catch(e) {
            if(v < 9)
                ok(e.number === 0x70057 - 0x80000000, "body.msMatchesSelector(\"" + selectors[i] + "\" threw " + e.number);
            else {
                todo_wine.
                ok(e.name === (v < 10 ? undefined : "SyntaxError"), "body.msMatchesSelector(\"" + selectors[i] + "\" threw " + e.name);
            }
        }
    }
});

sync_test("__proto__", function() {
    var v = document.documentMode;
    var r, x = 42;

    if(v < 11) {
        ok(x.__proto__ === undefined, "x.__proto__ = " + x.__proto__);
        ok(!("__proto__" in Object), "Object.__proto__ = " + Object.__proto__);
        return;
    }

    ok(x.__proto__ === Number.prototype, "x.__proto__ = " + x.__proto__);
    ok(Object.__proto__ === Function.prototype, "Object.__proto__ = " + Object.__proto__);
    ok(Object.prototype.__proto__ === null, "Object.prototype.__proto__ = " + Object.prototype.__proto__);
    ok(Object.prototype.hasOwnProperty("__proto__"), "__proto__ is not a property of Object.prototype");
    ok(!Object.prototype.hasOwnProperty.call(x, "__proto__"), "__proto__ is a property of x");

    x.__proto__ = Object.prototype;
    ok(x.__proto__ === Number.prototype, "x.__proto__ set to Object.prototype = " + x.__proto__);
    ok(!Object.prototype.hasOwnProperty.call(x, "__proto__"), "__proto__ is a property of x after set to Object.prototype");
    x = {};
    x.__proto__ = null;
    r = Object.getPrototypeOf(x);
    ok(x.__proto__ === undefined, "x.__proto__ after set to null = " + x.__proto__);
    ok(r === null, "getPrototypeOf(x) after set to null = " + r);

    function check(expect, msg) {
        var r = Object.getPrototypeOf(x);
        ok(x.__proto__ === expect, "x.__proto__ " + msg + " = " + x.__proto__);
        ok(r === expect, "getPrototypeOf(x) " + msg + " = " + r);
        ok(!Object.prototype.hasOwnProperty.call(x, "__proto__"), "__proto__ is a property of x " + msg);
    }

    x = {};
    check(Object.prototype, "after x set to {}");
    x.__proto__ = Number.prototype;
    check(Number.prototype, "after set to Number.prototype");
    x.__proto__ = Object.prototype;
    check(Object.prototype, "after re-set to Object.prototype");

    function ctor() { }
    var obj = new ctor();
    x.__proto__ = obj;
    check(obj, "after set to obj");
    x.__proto__ = ctor.prototype;
    check(obj.__proto__, "after set to ctor.prototype");
    ok(obj.__proto__ === ctor.prototype, "obj.__proto__ !== ctor.prototype");

    r = (delete x.__proto__);
    ok(r, "delete x.__proto__ returned " + r);
    ok(Object.prototype.hasOwnProperty("__proto__"), "__proto__ is not a property of Object.prototype after delete");
    r = Object.getPrototypeOf(x);
    ok(r === ctor.prototype, "x.__proto__ after delete = " + r);

    var desc = Object.getOwnPropertyDescriptor(Object.prototype, "__proto__");
    ok(desc.value === undefined, "__proto__ value = " + desc.value);
    ok(Object.getPrototypeOf(desc.get) === Function.prototype, "__proto__ getter not a function");
    ok(Object.getPrototypeOf(desc.set) === Function.prototype, "__proto__ setter not a function");
    ok(desc.get.length === 0, "__proto__ getter length = " + desc.get.length);
    ok(desc.set.length === 1, "__proto__ setter length = " + desc.set.length);

    r = desc.get.call(x, 1, 2, 3, 4);
    ok(r === x.__proto__, "calling __proto__ getter on x returned " + r);

    r = desc.set.call(x, obj);
    ok(r === obj, "calling __proto__ setter(obj) on x returned " + r);
    check(obj, "after set to obj via calling setter");
    r = desc.set.call(x, 42);
    ok(r === 42, "calling __proto__ setter(42) on x returned " + r);
    check(obj, "after set to obj via calling setter(42)");
    r = desc.set.call(x, "foo");
    ok(r === "foo", "calling __proto__ setter('foo') on x returned " + r);
    check(obj, "after set to obj via calling setter('foo')");
    r = desc.set.call(x);
    ok(r === undefined, "calling __proto__ setter() on x returned " + r);
    r = desc.set.call(true, obj);
    ok(r === obj, "calling __proto__ setter(obj) on true value returned " + r);
    x = true;
    r = desc.set.call(x, obj);
    ok(r === obj, "calling __proto__ setter(obj) on x set to true returned " + r);
    ok(x.__proto__ === Boolean.prototype, "true value __proto__ after set to obj = " + x.__proto__);
    x = new Boolean(true);
    r = desc.set.call(x, obj);
    ok(r === obj, "calling __proto__ setter(obj) on x set to Boolean(true) returned " + r);
    ok(x.__proto__ === obj, "Boolean(true) __proto__ after set to obj = " + x.__proto__);

    r = desc.get.call(13);
    ok(r === Number.prototype, "calling __proto__ getter on 13 returned " + r);
    try {
        r = desc.get.call(undefined);
        ok(false, "expected exception calling __proto__ getter on undefined");
    }catch(e) {
        ok(e.number === 0xa138f - 0x80000000, "calling __proto__ getter on undefined threw exception " + e.number);
    }
    try {
        r = desc.get.call(null);
        ok(false, "expected exception calling __proto__ getter on null");
    }catch(e) {
        ok(e.number === 0xa138f - 0x80000000, "calling __proto__ getter on null threw exception " + e.number);
    }

    try {
        r = desc.set.call(undefined, obj);
        ok(false, "expected exception calling __proto__ setter on undefined");
    }catch(e) {
        ok(e.number === 0xa138f - 0x80000000, "calling __proto__ setter on undefined threw exception " + e.number);
    }
    try {
        r = desc.set.call(null, obj);
        ok(false, "expected exception calling __proto__ setter on null");
    }catch(e) {
        ok(e.number === 0xa138f - 0x80000000, "calling __proto__ setter on null threw exception " + e.number);
    }

    x = {};
    r = Object.create(x);
    ok(r.__proto__ === x, "r.__proto__ = " + r.__proto__);
    r = Object.create(r);
    ok(r.__proto__.__proto__ === x, "r.__proto__.__proto__ = " + r.__proto__.__proto__);
    try {
        x.__proto__ = r;
        ok(false, "expected exception setting circular proto chain");
    }catch(e) {
        ok(e.number === 0xa13b0 - 0x80000000 && e.name === "TypeError",
            "setting circular proto chain threw exception " + e.number + " (" + e.name + ")");
    }

    Object.preventExtensions(x);
    x.__proto__ = Object.prototype;  /* same prototype */
    try {
        x.__proto__ = Number.prototype;
        ok(false, "expected exception changing __proto__ on non-extensible object");
    }catch(e) {
        ok(e.number === 0xa13b6 - 0x80000000 && e.name === "TypeError",
            "changing __proto__ on non-extensible object threw exception " + e.number + " (" + e.name + ")");
    }
});

sync_test("__defineGetter__", function() {
    var v = document.documentMode;
    var r, x = 42;

    if(v < 11) {
        ok(x.__defineGetter__ === undefined, "x.__defineGetter__ = " + x.__defineGetter__);
        ok(!("__defineGetter__" in Object), "Object.__defineGetter__ = " + Object.__defineGetter__);
        return;
    }
    ok(Object.prototype.hasOwnProperty("__defineGetter__"), "__defineGetter__ is not a property of Object.prototype");
    ok(Object.prototype.__defineGetter__.length === 2, "__defineGetter__.length = " + Object.prototype.__defineGetter__.length);

    function getter() { return "wine"; }
    function setter(val) { }

    r = x.__defineGetter__("foo", getter);
    ok(r === undefined, "__defineGetter__ on 42 returned " + r);
    ok(x.foo === undefined, "42.foo = " + x.foo);

    x = {};
    r = x.__defineGetter__("foo", getter);
    ok(r === undefined, "__defineGetter__ returned " + r);
    ok(x.foo === "wine", "x.foo = " + x.foo);
    r = Object.getOwnPropertyDescriptor(x, "foo");
    ok(r.value === undefined, "x.foo value = " + r.value);
    ok(r.get === getter, "x.foo get = " + r.get);
    ok(r.set === undefined, "x.foo set = " + r.set);
    ok(r.writable === undefined, "x.foo writable = " + r.writable);
    ok(r.enumerable === true, "x.foo enumerable = " + r.enumerable);
    ok(r.configurable === true, "x.foo configurable = " + r.configurable);

    Object.defineProperty(x, "foo", { get: undefined, set: setter, configurable: false });
    r = Object.getOwnPropertyDescriptor(x, "foo");
    ok(r.value === undefined, "x.foo setter value = " + r.value);
    ok(r.get === undefined, "x.foo setter get = " + r.get);
    ok(r.set === setter, "x.foo setter set = " + r.set);
    ok(r.writable === undefined, "x.foo setter writable = " + r.writable);
    ok(r.enumerable === true, "x.foo setter enumerable = " + r.enumerable);
    ok(r.configurable === false, "x.foo setter configurable = " + r.configurable);
    try {
        x.__defineGetter__("foo", getter);
        ok(false, "expected exception calling __defineGetter__ on non-configurable property");
    }catch(e) {
        ok(e.number === 0xa13d6 - 0x80000000, "__defineGetter__ on non-configurable property threw exception " + e.number);
    }

    r = Object.prototype.__defineGetter__.call(undefined, "bar", getter);
    ok(r === undefined, "__defineGetter__ on undefined returned " + r);
    r = Object.prototype.__defineGetter__.call(null, "bar", getter);
    ok(r === undefined, "__defineGetter__ on null returned " + r);
    r = x.__defineGetter__(undefined, getter);
    ok(r === undefined, "__defineGetter__ undefined prop returned " + r);
    ok(x["undefined"] === "wine", "x.undefined = " + x["undefined"]);
    r = x.__defineGetter__(false, getter);
    ok(r === undefined, "__defineGetter__ undefined prop returned " + r);
    ok(x["false"] === "wine", "x.false = " + x["false"]);

    try {
        x.__defineGetter__("bar", "string");
        ok(false, "expected exception calling __defineGetter__ with string");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineGetter__ with string threw exception " + e.number);
    }
    try {
        x.__defineGetter__("bar", undefined);
        ok(false, "expected exception calling __defineGetter__ with undefined");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineGetter__ with undefined threw exception " + e.number);
    }
    try {
        x.__defineGetter__("bar", null);
        ok(false, "expected exception calling __defineGetter__ with null");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineGetter__ with null threw exception " + e.number);
    }
    try {
        Object.prototype.__defineGetter__.call(x, "bar");
        ok(false, "expected exception calling __defineGetter__ with only one arg");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineGetter__ with only one arg threw exception " + e.number);
    }

    x.bar = "test";
    ok(x.bar === "test", "x.bar = " + x.bar);
    x.__defineGetter__("bar", getter);
    ok(x.bar === "wine", "x.bar with getter = " + x.bar);
});

sync_test("__defineSetter__", function() {
    var v = document.documentMode;
    var r, x = 42;

    if(v < 11) {
        ok(x.__defineSetter__ === undefined, "x.__defineSetter__ = " + x.__defineSetter__);
        ok(!("__defineSetter__" in Object), "Object.__defineSetter__ = " + Object.__defineSetter__);
        return;
    }
    ok(Object.prototype.hasOwnProperty("__defineSetter__"), "__defineSetter__ is not a property of Object.prototype");
    ok(Object.prototype.__defineSetter__.length === 2, "__defineSetter__.length = " + Object.prototype.__defineSetter__.length);

    function getter() { return "wine"; }
    function setter(val) { this.setterVal = val - 1; }

    r = x.__defineSetter__("foo", setter);
    ok(r === undefined, "__defineSetter__ on 42 returned " + r);
    ok(x.foo === undefined, "42.foo = " + x.foo);

    x = {};
    r = x.__defineSetter__("foo", setter);
    ok(r === undefined, "__defineSetter__ returned " + r);
    ok(x.setterVal === undefined, "x.setterVal = " + x.setterVal);
    x.foo = 13;
    ok(x.setterVal === 12, "x.setterVal = " + x.setterVal);
    r = Object.getOwnPropertyDescriptor(x, "foo");
    ok(r.value === undefined, "x.foo value = " + r.value);
    ok(r.get === undefined, "x.foo get = " + r.get);
    ok(r.set === setter, "x.foo set = " + r.set);
    ok(r.writable === undefined, "x.foo writable = " + r.writable);
    ok(r.enumerable === true, "x.foo enumerable = " + r.enumerable);
    ok(r.configurable === true, "x.foo configurable = " + r.configurable);

    Object.defineProperty(x, "foo", { get: getter, set: undefined, configurable: false });
    r = Object.getOwnPropertyDescriptor(x, "foo");
    ok(r.value === undefined, "x.foo getter value = " + r.value);
    ok(r.get === getter, "x.foo getter get = " + r.get);
    ok(r.set === undefined, "x.foo getter set = " + r.set);
    ok(r.writable === undefined, "x.foo getter writable = " + r.writable);
    ok(r.enumerable === true, "x.foo getter enumerable = " + r.enumerable);
    ok(r.configurable === false, "x.foo getter configurable = " + r.configurable);
    try {
        x.__defineSetter__("foo", setter);
        ok(false, "expected exception calling __defineSetter__ on non-configurable property");
    }catch(e) {
        ok(e.number === 0xa13d6 - 0x80000000, "__defineSetter__ on non-configurable property threw exception " + e.number);
    }

    r = Object.prototype.__defineSetter__.call(undefined, "bar", setter);
    ok(r === undefined, "__defineSetter__ on undefined returned " + r);
    r = Object.prototype.__defineSetter__.call(null, "bar", setter);
    ok(r === undefined, "__defineSetter__ on null returned " + r);
    r = x.__defineSetter__(null, setter);
    ok(r === undefined, "__defineSetter__ null prop returned " + r);
    x["null"] = 100;
    ok(x.setterVal === 99, "x.setterVal after setting x.null = " + x.setterVal);
    r = x.__defineSetter__(50, setter);
    ok(r === undefined, "__defineSetter__ 50 prop returned " + r);
    x["50"] = 33;
    ok(x.setterVal === 32, "x.setterVal after setting x.50 = " + x.setterVal);

    try {
        x.__defineSetter__("bar", true);
        ok(false, "expected exception calling __defineSetter__ with bool");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineSetter__ with bool threw exception " + e.number);
    }
    try {
        x.__defineSetter__("bar", undefined);
        ok(false, "expected exception calling __defineSetter__ with undefined");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineSetter__ with undefined threw exception " + e.number);
    }
    try {
        x.__defineSetter__("bar", null);
        ok(false, "expected exception calling __defineSetter__ with null");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineSetter__ with null threw exception " + e.number);
    }
    try {
        Object.prototype.__defineSetter__.call(x, "bar");
        ok(false, "expected exception calling __defineSetter__ with only one arg");
    }catch(e) {
        ok(e.number === 0xa138a - 0x80000000, "__defineSetter__ with only one arg threw exception " + e.number);
    }

    x.bar = "test";
    ok(x.bar === "test", "x.bar = " + x.bar);
    x.__defineSetter__("bar", setter);
    ok(x.bar === undefined, "x.bar with setter = " + x.bar);
    x.bar = 10;
    ok(x.bar === undefined, "x.bar with setter = " + x.bar);
    ok(x.setterVal === 9, "x.setterVal after setting bar = " + x.setterVal);
});

sync_test("MutationObserver", function() {
    if (!window.MutationObserver) {
        return;
    }

    try {
        window.MutationObserver();
        ok(false, "MutationObserver without args should fail");
    } catch(e) {
        ok(e.number == 0xffff - 0x80000000, "MutationObserver without new threw exception " + e.number);
    }

    try {
        window.MutationObserver(42);
        ok(false, "MutationObserver with non-function should fail");
    } catch(e) {
        todo_wine.
        ok(e.name == "TypeMismatchError", "MutationObserver with non-function arg threw exception " + e.name);
    }

    try {
        window.MutationObserver(function() {});
    } catch(e) {
        ok(false, "MutationObserver without new threw exception " + e.number);
    }

    try {
        new window.MutationObserver();
        ok(false, "MutationObserver with no args should fail");
    } catch(e) {
        ok(e.number == 0xffff - 0x80000000, "MutationObserver with no args threw exception " + e.number);
    }

    try {
        new window.MutationObserver(1);
        ok(false, "MutationObserver with non-function arg should fail");
    } catch(e) {
        todo_wine.
        ok(e.name == "TypeMismatchError", "MutationObserver with non-function arg threw exception " + e.name);
    }

    try {
        new window.MutationObserver(function() {});
    } catch(e) {
        ok(false, "MutationObserver threw exception " + e.number);
    }

    try {
        new window.MutationObserver(function() {}, 1);
    } catch(e) {
        ok(false, "MutationObserver with extra args threw exception " + e.number);
    }

    var mutation_observer = new MutationObserver(function() {});
    function test_exposed(prop) {
        ok(prop in mutation_observer, prop + " not found in MutationObserver.");
    }
    test_exposed("observe");
    test_exposed("disconnect");
    test_exposed("takeRecords");
});

sync_test("initMessageEvent", function() {
    var e, v = document.documentMode;
    if(!document.createEvent)
        return;
    e = document.createEvent("MessageEvent");
    ok(e.data === (v < 10 ? "" : undefined), "e.data = " + e.data);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.source === null, "e.source = " + e.source);
    ok(e.origin === "", "e.origin = " + e.origin);

    e.initMessageEvent("blah", true, true, 137, "wine", 1234, window);
    ok(e.data === "137", "e.data = " + e.data);
    ok(e.bubbles === true, "bubbles = " + e.bubbles);
    ok(e.cancelable === true, "cancelable = " + e.cancelable);
    ok(e.source === window, "e.source = " + e.source);
    ok(e.origin === "wine", "e.origin = " + e.origin);

    e.initMessageEvent("abcd", false, false, "testdata", "origin", 42, null);
    ok(e.data === "testdata", "e.data = " + e.data);
    ok(e.bubbles === false, "bubbles = " + e.bubbles);
    ok(e.cancelable === false, "cancelable = " + e.cancelable);
    ok(e.source === null, "e.source = " + e.source);
    ok(e.origin === "origin", "e.origin = " + e.origin);
});

async_test("postMessage", function() {
    var v = document.documentMode;
    var onmessage_called = false;
    window.onmessage = function(e) {
        onmessage_called = true;
        if(v < 9)
            ok(e === undefined, "e = " + e);
        else {
            ok(e.data === (v < 10 ? "10" : 10), "e.data = " + e.data);
            ok(e.source === window, "e.source = " + e.source);
            ok(e.origin === "http://winetest.example.org", "e.origin = " + e.origin);

            e = document.createEvent("MessageEvent");
            ok(e.data === (v < 10 ? "" : undefined), "created e.data = " + e.data);
            next_test();
        }
    }

    var invalid = [
        v < 10 ? { toString: function() { return "http://winetest.example.org"; } } : null,
        (function() { return "http://winetest.example.org"; }),
        "winetest.example.org",
        "example.org",
        undefined
    ];
    for(var i = 0; i < invalid.length; i++) {
        try {
            window.postMessage("invalid " + i, invalid[i]);
            ok(false, "expected exception with targetOrigin " + invalid[i]);
        }catch(ex) {
            var n = ex.number >>> 0;
            todo_wine_if(v >= 10).
            ok(n === (v < 10 ? 0x80070057 : 0), "postMessage with targetOrigin " + invalid[i] + " threw " + n);
            if(v >= 10)
                todo_wine.
                ok(ex.name === "SyntaxError", "postMessage with targetOrigin " + invalid[i] + " threw " + ex.name);
        }
    }
    try {
        window.postMessage("invalid empty", "");
        ok(false, "expected exception with empty targetOrigin");
    }catch(ex) {
        var n = ex.number >>> 0;
        ok(n === 0x80070057, "postMessage with empty targetOrigin threw " + n);
    }

    window.postMessage("wrong port", "http://winetest.example.org:1234");
    ok(onmessage_called == (v < 9 ? true : false), "onmessage not called with wrong port");
    onmessage_called = false;

    var not_sent = [
        "http://winetest.example.com",
        "ftp://winetest.example.org",
        "http://wine.example.org",
        "http://example.org"
    ];
    for(var i = 0; i < not_sent.length; i++) {
        window.postMessage("not_sent " + i, not_sent[i]);
        ok(onmessage_called == false, "onmessage called with targetOrigin " + not_sent[i]);
        onmessage_called = false;
    }

    window.postMessage(10, (v < 10 ? "*" : { toString: function() { return "*"; } }));
    ok(onmessage_called == (v < 9 ? true : false), "onmessage not called");
    if(v < 9) next_test();
});

sync_test("form", function() {
    document.body.innerHTML = "";
    var form = document.createElement("form");
    document.body.appendChild(form);

    form[0] = "test";
    form.innerHTML = "<input type=\"text\" id = \"i1\" /><input type=\"text\" id = \"i2\" />";
    ok(form.length === 2, "form.length = " + form.length);
    ok(typeof(form[0]) === "object", "form[0] = " + form[0]);
    ok(typeof(form[1]) === "object", "form[1] = " + form[1]);
    form.innerHTML = "";
    ok(form[0] === "test", "form[0] = " + form[0]);
});

sync_test("prototypes", function() {
    var v = document.documentMode;
    if(v < 9)
        return;

    function check(obj, proto, name) {
        var p = Object.getPrototypeOf(obj);
        ok(p === proto, "unexpected " + name + " prototype object " + Object.prototype.toString.call(p));
    }

    check(document.implementation, DOMImplementation.prototype, "implementation");
    check(DOMImplementation.prototype, Object.prototype, "implementation prototype");
    check(window.navigator, Navigator.prototype, "navigator");
    check(Navigator.prototype, Object.prototype, "navigator prototype");
    check(document.body, HTMLBodyElement.prototype, "body element");
    check(HTMLBodyElement.prototype, HTMLElement.prototype, "body prototype");
    check(HTMLElement.prototype, Element.prototype, "html element prototype");
    check(Element.prototype, Node.prototype, "element prototype");
    check(Node.prototype, Object.prototype, "node prototype");
    check(sessionStorage, Storage.prototype, "storage");
    check(Storage.prototype, Object.prototype, "storage prototype");
    if(v >= 11) {
        check(document, HTMLDocument.prototype, "html document");
        check(HTMLDocument.prototype, Document.prototype, "html document prototype");
        check(Document.prototype, Node.prototype, "document prototype");
    }
    check(window, Window.prototype, "window");
    check(Window.prototype, Object.prototype, "window prototype");
    check(new XMLHttpRequest(), XMLHttpRequest.prototype, "xhr");
    check(XMLHttpRequest.prototype, Object.prototype, "xhr prototype");
    check(XMLHttpRequest, Function.prototype, "xhr constructor");
    check(document.createElement("img"), HTMLImageElement.prototype, "img elem");
    check(HTMLImageElement.prototype, HTMLElement.prototype, "img elem prototype");
    check(Image, Function.prototype, "Image constructor");
    check(document.createElement("option"), HTMLOptionElement.prototype, "option elem");
    check(HTMLOptionElement.prototype, HTMLElement.prototype, "option elem prototype");
    check(Option, Function.prototype, "Option constructor");
    if(v >= 11) {
        check(new MutationObserver(function() {}), MutationObserver.prototype, "mutation observer");
        check(MutationObserver.prototype, Object.prototype, "mutation observer prototype");
        check(MutationObserver, Function.prototype, "mutation observer constructor");
    }
    check(document.createElement("a"), HTMLAnchorElement.prototype, "anchor element");
    check(HTMLAnchorElement.prototype, HTMLElement.prototype, "anchor element prototype");
    check(document.createElement("area"), HTMLAreaElement.prototype, "area element");
    check(HTMLAreaElement.prototype, HTMLElement.prototype, "area element prototype");
    check(document.createElement("form"), HTMLFormElement.prototype, "form element");
    check(HTMLFormElement.prototype, HTMLElement.prototype, "form element prototype");
    check(document.createElement("frame"), HTMLFrameElement.prototype, "frame element");
    check(HTMLFrameElement.prototype, HTMLElement.prototype, "frame element prototype");
    check(document.createElement("iframe"), HTMLIFrameElement.prototype, "iframe element");
    check(HTMLIFrameElement.prototype, HTMLElement.prototype, "iframe element prototype");
    check(document.createElement("title"), HTMLTitleElement.prototype, "title element");
    check(HTMLTitleElement.prototype, HTMLElement.prototype, "title element prototype");
    check(document.documentElement, HTMLHtmlElement.prototype, "html element");
    check(HTMLHtmlElement.prototype, HTMLElement.prototype, "html element prototype");
    check(document.head, HTMLHeadElement.prototype, "head element");
    check(HTMLHeadElement.prototype, HTMLElement.prototype, "head element prototype");
    check(document.createElement("meta"), HTMLMetaElement.prototype, "meta element");
    check(HTMLMetaElement.prototype, HTMLElement.prototype, "meta element prototype");
    check(document.createElement("input"), HTMLInputElement.prototype, "input element");
    check(HTMLInputElement.prototype, HTMLElement.prototype, "input element prototype");
    check(document.createElement("label"), HTMLLabelElement.prototype, "label element");
    check(HTMLLabelElement.prototype, HTMLElement.prototype, "label element prototype");
    check(document.createElement("button"), HTMLButtonElement.prototype, "button element");
    check(HTMLButtonElement.prototype, HTMLElement.prototype, "button element prototype");
    check(document.createElement("link"), HTMLLinkElement.prototype, "link element");
    check(HTMLLinkElement.prototype, HTMLElement.prototype, "link element prototype");
    check(document.createElement("object"), HTMLObjectElement.prototype, "object element");
    check(HTMLObjectElement.prototype, HTMLElement.prototype, "object element prototype");
    check(document.createElement("embed"), HTMLEmbedElement.prototype, "embed element");
    check(HTMLEmbedElement.prototype, HTMLElement.prototype, "embed element prototype");
    check(document.createElement("script"), HTMLScriptElement.prototype, "script element");
    check(HTMLScriptElement.prototype, HTMLElement.prototype, "script element prototype");
    check(document.createElement("select"), HTMLSelectElement.prototype, "select element");
    check(HTMLSelectElement.prototype, HTMLElement.prototype, "select element prototype");
    check(document.createElement("style"), HTMLStyleElement.prototype, "style element");
    check(HTMLStyleElement.prototype, HTMLElement.prototype, "style element prototype");
    check(document.createElement("table"), HTMLTableElement.prototype, "table element");
    check(HTMLTableElement.prototype, HTMLElement.prototype, "table element prototype");
    check(document.createElement("tr"), HTMLTableRowElement.prototype, "tr element");
    check(HTMLTableRowElement.prototype, HTMLElement.prototype, "tr element prototype");
    check(document.createElement("td"), HTMLTableDataCellElement.prototype, "td element");
    check(HTMLTableDataCellElement.prototype, HTMLTableCellElement.prototype, "td element prototype");
    check(HTMLTableCellElement.prototype, HTMLElement.prototype, "table cell prototype");
    check(document.createElement("textarea"), HTMLTextAreaElement.prototype, "textarea element");
    check(HTMLTextAreaElement.prototype, HTMLElement.prototype, "textarea element prototype");
    check(document.createElement("test"), HTMLUnknownElement.prototype, "unknown element");
    check(HTMLUnknownElement.prototype, HTMLElement.prototype, "unknown element prototype");
    check(document.createElementNS(svg_ns, "svg"), SVGSVGElement.prototype, "svg:svg element");
    check(SVGSVGElement.prototype, SVGElement.prototype, "svg:svg element prototype");
    check(SVGElement.prototype, Element.prototype, "svg element prototype");
    check(document.createElementNS(svg_ns, "circle"), SVGCircleElement.prototype, "svg:circle element");
    check(SVGCircleElement.prototype, SVGElement.prototype, "svg:circle element prototype");
    check(document.createElementNS(svg_ns, "tspan"), SVGTSpanElement.prototype, "svg:tspan element");
    check(SVGTSpanElement.prototype, SVGTextPositioningElement.prototype, "svg:tspan element prototype");
    check(SVGTextPositioningElement.prototype, SVGTextContentElement.prototype, "SVGTextPositioningElement prototype");
    check(SVGTextContentElement.prototype, SVGElement.prototype, "SVGTextPositioningElement prototype");
    check(document.doctype, DocumentType.prototype, "doctype");
    check(DocumentType.prototype, Node.prototype, "doctype prototype");
    check(document.createTextNode(""), Text.prototype, "text");
    check(Text.prototype, CharacterData.prototype, "text prototype");
    check(CharacterData.prototype, Node.prototype, "character data prototype");
    check(window.getComputedStyle(document.body), CSSStyleDeclaration.prototype, "computed style");
    check(CSSStyleDeclaration.prototype, Object.prototype, "CSSStyleDeclaration");
    check(document.body.style, MSStyleCSSProperties.prototype, "style");
    check(MSStyleCSSProperties.prototype, MSCSSProperties.prototype, "MSStyleCSSProperties");
    check(MSCSSProperties.prototype, CSSStyleDeclaration.prototype, "MSCSSProperties");
    check(CSSStyleDeclaration.prototype, Object.prototype, "CSSStyleDeclaration");
    check(document.body.currentStyle, MSCurrentStyleCSSProperties.prototype, "current style");
    check(MSCurrentStyleCSSProperties.prototype, MSCSSProperties.prototype, "MSCurrentStyleCSSProperties");
    var e = document.createElement("style");
    document.body.appendChild(e);
    check(e.sheet, CSSStyleSheet.prototype, "stylesheet");
    check(CSSStyleSheet.prototype, StyleSheet.prototype, "css stylesheet prototype");
    check(StyleSheet.prototype, Object.prototype, "stylesheet prototype");
    check(document.styleSheets, StyleSheetList.prototype, "stylesheets list");
    check(StyleSheetList.prototype, Object.prototype, "stylesheets list prototype");
    check(e.sheet.rules, MSCSSRuleList.prototype, "css rule list");
    check(MSCSSRuleList.prototype, Object.prototype, "css rule list prototype");
    e.sheet.insertRule("div { border: none }", 0);
    check(e.sheet.rules[0], CSSStyleRule.prototype, "css rule");
    check(CSSStyleRule.prototype, CSSRule.prototype, "css rule prototype");
    check(CSSRule.prototype, Object.prototype, "css rule prototype");
    check(document.body.getBoundingClientRect(), ClientRect.prototype, "rect");
    check(ClientRect.prototype, Object.prototype, "rect prototype");
    check(document.body.getClientRects(), ClientRectList.prototype, "rect list");
    check(ClientRectList.prototype, Object.prototype, "rect list prototype");
    if(v < 11) {
        check(document.createEventObject(), MSEventObj.prototype, "event obj");
        check(MSEventObj.prototype, Object.prototype, "event obj prototype");
    }
    check(document.createEvent("Event"), Event.prototype, "event");
    check(Event.prototype, Object.prototype, "event prototype");
    check(document.createEvent("UIEvent"), UIEvent.prototype, "UI event");
    check(UIEvent.prototype, Event.prototype, "UI event prototype");
    check(document.createEvent("MouseEvent"), MouseEvent.prototype, "mouse event");
    check(MouseEvent.prototype, UIEvent.prototype, "mouse event prototype");
    check(document.createEvent("KeyboardEvent"), KeyboardEvent.prototype, "keyboard event");
    check(KeyboardEvent.prototype, UIEvent.prototype, "keyboard event prototype");
    if(v >= 11) {
        check(document.createEvent("PageTransitionEvent"), PageTransitionEvent.prototype, "page transition event");
        check(PageTransitionEvent.prototype, Event.prototype, "page transition event prototype");
    }
    check(document.createEvent("CustomEvent"), CustomEvent.prototype, "custom event");
    check(CustomEvent.prototype, Event.prototype, "custom event prototype");
    check(document.createEvent("MessageEvent"), MessageEvent.prototype, "message event");
    check(MessageEvent.prototype, Event.prototype, "message event prototype");
    if(v >= 10) {
        check(document.createEvent("ProgressEvent"), ProgressEvent.prototype, "progress event");
        check(ProgressEvent.prototype, Event.prototype, "progress event prototype");
    }
    check(document.createEvent("StorageEvent"), StorageEvent.prototype, "storage event");
    check(StorageEvent.prototype, Event.prototype, "storage event prototype");
    check(screen, Screen.prototype, "screen");
    check(Screen.prototype, Object.prototype, "screen prototype");
    check(history, History.prototype, "history");
    check(History.prototype, Object.prototype, "history prototype");
    if(v >= 11 /* todo_wine */) {
        check(navigator.plugins, PluginArray.prototype, "plugins");
        check(PluginArray.prototype, Object.prototype, "plugins prototype");
        check(navigator.mimeTypes, MimeTypeArray.prototype, "mimeTypes");
        check(MimeTypeArray.prototype, Object.prototype, "mimeTypes prototype");
    }
    check(performance.timing, PerformanceTiming.prototype, "timing");
    check(PerformanceTiming.prototype, Object.prototype, "timing prototype");
    check(performance.navigation, PerformanceNavigation.prototype, "navigation");
    check(PerformanceNavigation.prototype, Object.prototype, "navigation prototype");
    check(performance, Performance.prototype, "performance");
    check(Performance.prototype, Object.prototype, "performance prototype");
    if(v < 10) {
        check(document.namespaces, MSNamespaceInfoCollection.prototype, "namespaces");
        check(MSNamespaceInfoCollection.prototype, Object.prototype, "namespaces prototype");
    }else {
        ok(!("MSNamespaceInfoCollection" in window), "MSNamespaceInfoCollection found in window");
    }
    if(v >= 10) {
        check(console, Console.prototype, "console");
        check(Console.prototype, Object.prototype, "console prototype");
    }else {
        ok(!("Console" in window), "Console found in window");
    }
    if(v >= 10) {
        check(window.matchMedia("(hover:hover)"), MediaQueryList.prototype, "media query");
        check(MediaQueryList.prototype, Object.prototype, "media query prototype");
    }else {
        ok(!("MediaQueryList" in window), "MediaQueryList found in window");
    }
    if(v >= 10) {
        check(document.body.classList, DOMTokenList.prototype, "token list");
        check(DOMTokenList.prototype, Object.prototype, "token list prototype");
    }else {
        ok(!("DOMTokenList" in window), "DOMTokenList found in window");
    }
    check(document.body.attributes, NamedNodeMap.prototype, "node map");
    check(NamedNodeMap.prototype, Object.prototype, "node map prototype");
    check(document.getElementsByTagName("body"), HTMLCollection.prototype, "elem collection");
    check(HTMLCollection.prototype, Object.prototype, "elem collection prototype");
    check(document.body.childNodes, NodeList.prototype, "node list");
    check(NodeList.prototype, Object.prototype, "node list prototype");
    check(document.body.createTextRange(), TextRange.prototype, "text range");
    check(TextRange.prototype, Object.prototype, "text range prototype");
    check(Range.prototype, Object.prototype, "range prototype");
    if(v < 11) {
        check(document.selection, MSSelection.prototype, "selection");
        check(MSSelection.prototype, Object.prototype, "selection prototype");
    }else {
        ok(!("MSSelection" in window), "MSSelection found in window");
    }
    check(document.createComment(""), Comment.prototype, "comment");
    check(Comment.prototype, CharacterData.prototype, "comment prototype");
    check(document.createAttribute("test"), Attr.prototype, "attr");
    check(Attr.prototype, Node.prototype, "attr prototype");
    check(document.createDocumentFragment(), DocumentFragment.prototype, "fragment");
    check(DocumentFragment.prototype, Node.prototype, "fragment prototype");
});
      0   �� R E L O A D . J S       0           /*
 * Copyright 2022 Gabriel Ivăncescu for CodeWeavers
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

var tests = [];

async_test("reload", function() {
    if(sessionStorage.getItem("skip reload test")) {
        ok(performance.navigation.type === 1, "navigation type = " + performance.navigation.type);
        next_test();
        return;
    }

    var script = document.createElement("script");
    script.src ="http://winetest.different.org/jsstream.php?reload";
    document.getElementsByTagName("head")[0].appendChild(script);

    external.writeStream("reload",
    '   try {' +
    '       window.location.reload();' +
    '       sessionStorage.setItem("skip reload test", true);' +
    '   }catch(e) {' +
    '       ok(false, "reload with different origin threw " + e.number);' +
    '   }' +
    '   next_test()'
    );
});
   4   �� B L A N K . H T M L         0           <html></html>
     4   �� B L A N K 2 . H T M L       0           <html></html>
         �� ��{     0           <html></html>
  R   <   �� B L A N K _ I E 1 0 . H T M L       0           <html>
<head><meta http-equiv="x-ua-compatible" content="IE=10" /></head>
</html>
  L   D   �� D O C _ W I T H _ P R O P . H T M L         0           <html>
<script type="text/javascript">document.prop = 137;</script>
</html>
�   L   �� D O C _ W I T H _ P R O P _ I E 9 . H T M L         0           <html><head>
<meta http-equiv="x-ua-compatible" content="IE=9" />
<script type="text/javascript">document.prop = 137;</script>
</head></html>
  �   4   �� I F R A M E . H T M L       0           <html>
<head><meta http-equiv="x-ua-compatible" content="IE=11" /></head>
<body><iframe src="about:blank" id="ifr"></iframe></body>
</html>
"  <   �� X H R _ I F R A M E . H T M L       0           <html><head><script type="text/javascript">window.onmessage = function(e)
{
    if(e.data === "echo")
        parent.postMessage("echo", "*");
    else if(e.data === "async_xhr") {
        var async_xhr = new XMLHttpRequest();
        async_xhr.open("POST", "echo.php?delay_with_signal", true);
        async_xhr.onreadystatechange = function() { if(async_xhr.readyState == 4) parent.postMessage("async_xhr(DONE)", "*"); };
        async_xhr.setRequestHeader("X-Test", "True");
        async_xhr.send("foo");
        parent.postMessage("async_xhr", "*");
    }
    else if(e.data === "sync_xhr") {
        var sync_xhr = new XMLHttpRequest();
        sync_xhr.open("POST", "echo.php?delay_with_signal", false);
        sync_xhr.onreadystatechange = function() { if(sync_xhr.readyState == 4) parent.postMessage("sync_xhr(DONE)", "*"); };
        sync_xhr.setRequestHeader("X-Test", "True");
        parent.postMessage("sync_xhr(pre-send)", "*");
        sync_xhr.send("bar");
        parent.postMessage("sync_xhr", "*");
    }
}
</script><body></body></html>
  >;  4   T E S T   R E S . H T M L       0           <html>
<head>
<script src="winetest.js" type="text/javascript"></script>
</head>
<head>
<script>
function broken(expr) {
    return external.broken(expr);
}

function test_removeAttribute(e) {
    ok(e.removeAttribute('nonexisting') === false, "removeAttribute('nonexisting') didn't return false");

    e.title = "title";
    ok(e.removeAttribute('title') === true, "removeAttribute('title') didn't return true");
    ok(e.title === "", "e.title = " + e.title);
    ok(("title" in e) === true, "title is not in e");

    e["myattr"] = "test";
    ok(e.removeAttribute('myattr') === true, "removeAttribute('myattr') didn't return true");
    ok(e["myattr"] === undefined, "e['myattr'] = " + e['myattr']);
    ok(("myattr" in e) === false, "myattr is in e");

}

function test_select_index() {
    var s = document.getElementById("sel");

    ok("0" in s, "'0' is not in s");
    ok(s[0].text === "opt1", "s[0].text = " + s[0].text);
    ok("1" in s, "'1 is not in s");
    ok(s[1].text === "opt2", "s[1].text = " + s[1].text);
    ok("2" in s, "'2' is in s");
    ok(s[2] === null, "s[2] = " + s[2]);
}

function test_createDocumentFragment() {
    var fragment = document.createDocumentFragment();

    ok(typeof(fragment) === "object", "typeof(fragmend) = " + typeof(fragment));
    ok(fragment.nodeType === 11, "fragment.nodeType = " + fragment.nodeType);
    ok(fragment.nodeName === "#document-fragment", "fragment.nodeName = " + fragment.nodeName);

    var cloned = fragment.cloneNode(true);
    ok(cloned.nodeType === 11, "cloned.nodeType = " + cloned.nodeType);
    ok(cloned.nodeName === "#document-fragment", "cloned.nodeName = " + cloned.nodeName);
}

function test_document_name_as_index() {
    document.body.innerHTML = '<form name="formname"></form>';
    var e = document.getElementById("formname");
    ok(!!e, "e is null");

    ok(document.formname === e, "document.formname != getElementById('formname')");
    ok("formname" in document, "formname' is not in document");

    document.body.removeChild(e);

    ok(document.formname === undefined, "document.formname is not undefined");
    ok(!("formname" in document), "formname' is in document");

    document.body.innerHTML = '<form id="formid"></form>';
    var e = document.getElementById("formid");
    ok(!!e, "e is null");
    ok(!("formid" in document), "formid is in document");

    document.body.innerHTML = '<form name="formname"></form>';
    ok("formname" in window, "formname' is not in window");
    ok(typeof(window.formname) === "object", "typeof(window.formname) = " + typeof(window.formname));
    window.formname = 1;
    ok(window.formname === 1, "window.formname = " + window.formname);
    formname = 2;
    ok(window.formname === 2, "window.formname = " + window.formname);

    document.body.innerHTML = '<iframe id="iframeid"></iframe>';
    ok("iframeid" in window, "iframeid is not in window");
    e = document.getElementById("iframeid");
    ok(!!e, "e is null");
    ok(iframeid === e.contentWindow.self, "frameid != e.contentWindow.self");
    ok(iframeid.frameElement === e, "frameid.frameElement != e");
}

function test_remove_style_attribute() {
    var s = document.body.style, b;

    s.somevar = "test";
    b = s.removeAttribute("somevar", 1);
    ok(b, "removeAttribute returned " + b + " expected true");
    b = s.removeAttribute("somevar", 1);
    ok(b === false, "removeAttribute returned " + b + " expected false");
}

function test_clone_node() {
    var elem, cloned;

    elem = document.getElementById("divid");
    elem.style.filter = "alpha(opacity=50)";
    ok(elem.style.filter === "alpha(opacity=50)", "elem.style.filter = " + elem.style.filter);

    cloned = elem.cloneNode(true);
    ok(cloned.style.filter === "alpha(opacity=50)", "cloned.style.filter = " + cloned.style.filter);
}

function test_attrs() {
    var input, s, x, f, b;

    document.body.innerHTML = '<input id="inputid"></input>';
    input = document.getElementById("inputid");
    s = input.style;
    f = input.fireEvent;
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "test");
    ok(input.checked === true, "input.checked = " + input.checked);

    input.setAttribute("checked", 0);
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("Checked", 1, 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok(!("Checked" in input), "Checked added to input");

    input.setAttribute("checked", 0, 0);
    input.setAttribute("Checked", 1, 1);
    ok(input.checked === false, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 1, "input.Checked = " + input.Checked);

    input.removeAttribute("Checked", 1);
    ok(!("Checked" in input), "Checked is still in input");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", 1, 0);
    input.setAttribute("Checked", 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 0, "input.Checked = " + input.Checked);

    input.setAttribute("Checked", 2, 2);
    ok(input.Checked === 0, "input.Checked = " + input.Checked);
    input.setAttribute("Checked", 3, 3);
    ok(input.Checked === 3, "input.Checked = " + input.Checked);

    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", "display: none");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    ok(s.display === "", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    s.display = "none";
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    input.setAttribute("style", "");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", null);
    x = input.getAttribute("style");
    ok(input.style === s, "input.style = " + input.style);
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);

    x = input.getAttribute("fireEvent");
    ok(x === input.fireEvent, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "", "getAttribute('fireEvent') = " + x);

    input.setAttribute("fireEvent", 3);
    ok(input.fireEvent === 3, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "3", "getAttribute('fireEvent') = " + x);

    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");
    ok(input.style === s, "input.style = " + input.style);
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.display === "", "s.display = " + s.display);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);
    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");

    b = false;
    try {
        input.setAttribute("tagName", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(tagName)");

    b = false;
    try {
        input.setAttribute("parentElement", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(parentElement)");

    b = input.removeAttribute("fireEvent");
    ok(b === true, "removeAttribute(fireEvent) failed");
    ok(input.fireEvent === f, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === f, "input.getAttribute('fireEvent') = " + x);
    b = input.removeAttribute("fireEvent");
    ok(b === false || broken(b === true), "removeAttribute(fireEvent) returned " + b);

    input.fireEvent = 3;
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    ok(input.fireEvent === 3, "input.fireEvent' = " + input.fireEvent);
}

function test_attribute_collection() {
    var div, attr;

    document.body.innerHTML = '<div id="divid" class="test"></div>';
    div = document.getElementById("divid");

    attr = div.attributes["dir"];
    ok(attr === div.attributes["dir"], "attr !== div.attributes['dir']");
}

function test_getter_call() {
    document.body.innerHTML = '<div id="divid"></div>';

    var e = document.getElementById("divid");

    e.myfunc = function(x) { this.myfunc_called = x; };
    e.myfunc("test");
    ok(e.myfunc_called === "test", "e.myfunc_called = " + e.myfunc_called);

    e.onmousedown = function(x) { this.onmousedown_called = x; };
    e.onmousedown("test");
    ok(e.onmousedown_called === "test", "e.onmousedown_called = " + e.onmousedown_called);

    ok(document.all("divid").tagName === "DIV", "document.all('divid').tagName = " + document.all("divid").tagName);
}

function test_arg_conv() {
    /* this call would throw if the argument wasn't converted by JScript */
    window.clearInterval("");

    navigator.javaEnabled();
}

function test_override_functions() {
    function override_func() { return "test"; }

    ok(typeof(window.showModalDialog) === "object", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));
    window.showModalDialog = override_func;
    ok(window.showModalDialog === override_func, "window.showModalDialog != override_func");
    ok(typeof(window.showModalDialog) === "function", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));

    document.body.innerHTML = '<div id="divid"></div>';
    var div = document.getElementById("divid");
    ok(typeof(div.addBehavior) === "object", "typeof(div.addBehavior) = " + typeof(div.addBehavior));
    div.addBehavior = override_func;
    ok(div.addBehavior === override_func, "div.addBehavior != override_func");
    ok(typeof(div.addBehavior) === "function", "typeof(div.addBehavior) = " + typeof(div.addBehavior));

    var tmp = div.addBehavior();
    ok(tmp === "test", "div.addBehavior() = " + tmp);

    tmp = String(div.attachEvent);
    ok(tmp == "\nfunction attachEvent() {\n    [native code]\n}\n", "String(div.attachEvent) = " + tmp);
}

function test_forin() {
    var cnt=0;

    document.body.innerHTML = '<a id="aid"></a>';

    for(var x in document.getElementById("aid")) {
        cnt++;
    }

    ok(cnt > 100, "cnt = " + cnt);
}

function test_customtag() {
    document.body.innerHTML = 'test<unk><br>';

    var children = document.body.childNodes;

    ok(children.length === 3, "children.length = " + children.length);
    ok(children[0].data === "test", "children[0].data = " + children[0].data);
    ok(children[1].tagName === "UNK", "children[1].tagName = " + children[1].tagName);
    ok(children[2].tagName === "BR", "children[2].tagName = " + children[2].tagName);
}

function test_whitespace_nodes() {
    document.body.innerHTML = '<table id="tid"> <tr> \t<td>\n \t<div></div> </td>\n </tr> </table>';

    var t = document.getElementById("tid");
    ok(t.childNodes.length === 1, "t.childNodes.length = " + t.childNodes.length);
    ok(t.childNodes[0].tagName === "TBODY", "t.childNodes[0].tagName = " + t.childNodes[0].tagName);

    var row = t.rows[0];
    ok(row.childNodes.length === 1, "row.childNodes.length = " + row.childNodes.length);
    ok(row.childNodes[0].tagName === "TD", "row.childNodes[0].tagName = " + row.childNodes[0].tagName);

    var cell = row.cells[0];
    ok(cell.childNodes.length === 1, "cell.childNodes.length = " + cell.childNodes.length);


    document.body.innerHTML = '<table id="tid"> x<tr> \tx<td>\n \tx<div></div> </td>\n </tr> </table>';

    t = document.getElementById("tid");
    ok(t.rows[0].cells[0].childNodes.length === 2,
        "t.rows[0].cells[0].childNodes.length = " + t.rows[0].cells[0].childNodes.length);
}

function test_language_attribute() {
    document.body.innerHTML = '<div id="did" language="test"></div>';
    var elem = document.getElementById("did");
    ok(elem.language === "test", "elem.language = " + elem.language);
    elem.language = 1;
    ok(elem.language === "1", "elem.language = " + elem.language);
}

function test_text_node() {
    document.body.innerHTML = 'testing text';
    var text = document.body.childNodes[0], text2;
    ok(text.data == "testing text", "text.data = " + text.data);

    text2 = text.splitText(7);
    ok(text.data == "testing", "text.data = " + text.data);
    ok(text2.data == " text", "text2.data = " + text2.data);
    ok(text.nextSibling === text2, "text.nextSibling !== text2");

    text2 = text.splitText(0);
    ok(text.data == "", "text.data = " + text.data);
    ok(text2.data == "testing", "text2.data = " + text2.data);
}

function test_xhr() {
    ok("XMLHttpRequest" in window, "XMLHttpRequest not found in window object\n");

    if (typeof(XMLHttpRequest) != "object") {
        win_skip("XMLHTTPRequest is not available or disabled");
        return;
    }

    var xhr = new XMLHttpRequest();
    ok(typeof(xhr) === "object", "typeof(xhr) = " + typeof(xhr));
}

var globalVar = false;

function runTests() {
    obj = new Object();
    ok(obj === window.obj, "obj !== window.obj");

    ok(typeof(divid) === "object", "typeof(divid) = " + typeof(divid));

    test_removeAttribute(document.getElementById("divid"));
    test_removeAttribute(document.body);
    test_select_index();
    test_clone_node();
    test_createDocumentFragment();
    test_document_name_as_index();
    test_remove_style_attribute();
    test_getter_call();
    test_attrs();
    test_attribute_collection();
    test_arg_conv();
    test_override_functions();
    test_forin();
    test_customtag();
    test_whitespace_nodes();
    test_language_attribute();
    test_text_node();
    test_xhr();

    var r = window.execScript("globalVar = true;");
    ok(r === undefined, "execScript returned " + r);
    ok(globalVar === true, "globalVar = " + globalVar);

    /* Call setTimeout without specified time. */
    window.setTimeout(function() { external.reportSuccess(); });
}

function runTest() {
    try {
        runTests();
    }catch(e) {
        ok(false, "got exception " + e.message);
    }
}
</script>
<body onload="runTest();">
<div id="divid"></div>
<select id="sel">
<option>opt1</option>
<option>opt2</option>
</select>
</body>
</html>
  >;  H   T E S T   D I R / D I R 2 / R E S . H T M L         0           <html>
<head>
<script src="winetest.js" type="text/javascript"></script>
</head>
<head>
<script>
function broken(expr) {
    return external.broken(expr);
}

function test_removeAttribute(e) {
    ok(e.removeAttribute('nonexisting') === false, "removeAttribute('nonexisting') didn't return false");

    e.title = "title";
    ok(e.removeAttribute('title') === true, "removeAttribute('title') didn't return true");
    ok(e.title === "", "e.title = " + e.title);
    ok(("title" in e) === true, "title is not in e");

    e["myattr"] = "test";
    ok(e.removeAttribute('myattr') === true, "removeAttribute('myattr') didn't return true");
    ok(e["myattr"] === undefined, "e['myattr'] = " + e['myattr']);
    ok(("myattr" in e) === false, "myattr is in e");

}

function test_select_index() {
    var s = document.getElementById("sel");

    ok("0" in s, "'0' is not in s");
    ok(s[0].text === "opt1", "s[0].text = " + s[0].text);
    ok("1" in s, "'1 is not in s");
    ok(s[1].text === "opt2", "s[1].text = " + s[1].text);
    ok("2" in s, "'2' is in s");
    ok(s[2] === null, "s[2] = " + s[2]);
}

function test_createDocumentFragment() {
    var fragment = document.createDocumentFragment();

    ok(typeof(fragment) === "object", "typeof(fragmend) = " + typeof(fragment));
    ok(fragment.nodeType === 11, "fragment.nodeType = " + fragment.nodeType);
    ok(fragment.nodeName === "#document-fragment", "fragment.nodeName = " + fragment.nodeName);

    var cloned = fragment.cloneNode(true);
    ok(cloned.nodeType === 11, "cloned.nodeType = " + cloned.nodeType);
    ok(cloned.nodeName === "#document-fragment", "cloned.nodeName = " + cloned.nodeName);
}

function test_document_name_as_index() {
    document.body.innerHTML = '<form name="formname"></form>';
    var e = document.getElementById("formname");
    ok(!!e, "e is null");

    ok(document.formname === e, "document.formname != getElementById('formname')");
    ok("formname" in document, "formname' is not in document");

    document.body.removeChild(e);

    ok(document.formname === undefined, "document.formname is not undefined");
    ok(!("formname" in document), "formname' is in document");

    document.body.innerHTML = '<form id="formid"></form>';
    var e = document.getElementById("formid");
    ok(!!e, "e is null");
    ok(!("formid" in document), "formid is in document");

    document.body.innerHTML = '<form name="formname"></form>';
    ok("formname" in window, "formname' is not in window");
    ok(typeof(window.formname) === "object", "typeof(window.formname) = " + typeof(window.formname));
    window.formname = 1;
    ok(window.formname === 1, "window.formname = " + window.formname);
    formname = 2;
    ok(window.formname === 2, "window.formname = " + window.formname);

    document.body.innerHTML = '<iframe id="iframeid"></iframe>';
    ok("iframeid" in window, "iframeid is not in window");
    e = document.getElementById("iframeid");
    ok(!!e, "e is null");
    ok(iframeid === e.contentWindow.self, "frameid != e.contentWindow.self");
    ok(iframeid.frameElement === e, "frameid.frameElement != e");
}

function test_remove_style_attribute() {
    var s = document.body.style, b;

    s.somevar = "test";
    b = s.removeAttribute("somevar", 1);
    ok(b, "removeAttribute returned " + b + " expected true");
    b = s.removeAttribute("somevar", 1);
    ok(b === false, "removeAttribute returned " + b + " expected false");
}

function test_clone_node() {
    var elem, cloned;

    elem = document.getElementById("divid");
    elem.style.filter = "alpha(opacity=50)";
    ok(elem.style.filter === "alpha(opacity=50)", "elem.style.filter = " + elem.style.filter);

    cloned = elem.cloneNode(true);
    ok(cloned.style.filter === "alpha(opacity=50)", "cloned.style.filter = " + cloned.style.filter);
}

function test_attrs() {
    var input, s, x, f, b;

    document.body.innerHTML = '<input id="inputid"></input>';
    input = document.getElementById("inputid");
    s = input.style;
    f = input.fireEvent;
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "test");
    ok(input.checked === true, "input.checked = " + input.checked);

    input.setAttribute("checked", 0);
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", "");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("Checked", 1, 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok(!("Checked" in input), "Checked added to input");

    input.setAttribute("checked", 0, 0);
    input.setAttribute("Checked", 1, 1);
    ok(input.checked === false, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 1, "input.Checked = " + input.Checked);

    input.removeAttribute("Checked", 1);
    ok(!("Checked" in input), "Checked is still in input");
    ok(input.checked === false, "input.checked = " + input.checked);

    input.setAttribute("checked", 1, 0);
    input.setAttribute("Checked", 0);
    ok(input.checked === true, "input.checked = " + input.checked);
    ok("Checked" in input, "checked not added to input");
    ok(input.Checked === 0, "input.Checked = " + input.Checked);

    input.setAttribute("Checked", 2, 2);
    ok(input.Checked === 0, "input.Checked = " + input.Checked);
    input.setAttribute("Checked", 3, 3);
    ok(input.Checked === 3, "input.Checked = " + input.Checked);

    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", "display: none");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    ok(s.display === "", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    s.display = "none";
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    input.setAttribute("style", "");
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);

    input.setAttribute("style", null);
    x = input.getAttribute("style");
    ok(input.style === s, "input.style = " + input.style);
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.cssText != "", "s.cssText = " + s.cssText);
    ok(s.display === "none", "s.display = " + s.display);

    x = input.getAttribute("fireEvent");
    ok(x === input.fireEvent, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "", "getAttribute('fireEvent') = " + x);

    input.setAttribute("fireEvent", 3);
    ok(input.fireEvent === 3, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    x = input.getAttribute("fireEvent", 2);
    ok(x === "3", "getAttribute('fireEvent') = " + x);

    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");
    ok(input.style === s, "input.style = " + input.style);
    x = input.getAttribute("style");
    ok(x === s, "getAttribute('style') = " + x);
    ok(s.display === "", "s.display = " + s.display);
    ok(s.cssText === "", "s.cssText = " + s.cssText);
    x = input.getAttribute("style", 2);
    ok(x === "", "getAttribute('style') = " + x);
    b = input.removeAttribute("style");
    ok(b === true, "removeAttribute('style') failed");

    b = false;
    try {
        input.setAttribute("tagName", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(tagName)");

    b = false;
    try {
        input.setAttribute("parentElement", "xxx");
    }catch(e) {
        b = true;
    }
    ok(b, "Expected exception on setAttribute(parentElement)");

    b = input.removeAttribute("fireEvent");
    ok(b === true, "removeAttribute(fireEvent) failed");
    ok(input.fireEvent === f, "input.fireEvent = " + input.fireEvent);
    x = input.getAttribute("fireEvent");
    ok(x === f, "input.getAttribute('fireEvent') = " + x);
    b = input.removeAttribute("fireEvent");
    ok(b === false || broken(b === true), "removeAttribute(fireEvent) returned " + b);

    input.fireEvent = 3;
    x = input.getAttribute("fireEvent");
    ok(x === 3, "input.getAttribute('fireEvent') = " + x);
    ok(input.fireEvent === 3, "input.fireEvent' = " + input.fireEvent);
}

function test_attribute_collection() {
    var div, attr;

    document.body.innerHTML = '<div id="divid" class="test"></div>';
    div = document.getElementById("divid");

    attr = div.attributes["dir"];
    ok(attr === div.attributes["dir"], "attr !== div.attributes['dir']");
}

function test_getter_call() {
    document.body.innerHTML = '<div id="divid"></div>';

    var e = document.getElementById("divid");

    e.myfunc = function(x) { this.myfunc_called = x; };
    e.myfunc("test");
    ok(e.myfunc_called === "test", "e.myfunc_called = " + e.myfunc_called);

    e.onmousedown = function(x) { this.onmousedown_called = x; };
    e.onmousedown("test");
    ok(e.onmousedown_called === "test", "e.onmousedown_called = " + e.onmousedown_called);

    ok(document.all("divid").tagName === "DIV", "document.all('divid').tagName = " + document.all("divid").tagName);
}

function test_arg_conv() {
    /* this call would throw if the argument wasn't converted by JScript */
    window.clearInterval("");

    navigator.javaEnabled();
}

function test_override_functions() {
    function override_func() { return "test"; }

    ok(typeof(window.showModalDialog) === "object", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));
    window.showModalDialog = override_func;
    ok(window.showModalDialog === override_func, "window.showModalDialog != override_func");
    ok(typeof(window.showModalDialog) === "function", "typeof(window.showModalDialog) = " + typeof(window.showModalDialog));

    document.body.innerHTML = '<div id="divid"></div>';
    var div = document.getElementById("divid");
    ok(typeof(div.addBehavior) === "object", "typeof(div.addBehavior) = " + typeof(div.addBehavior));
    div.addBehavior = override_func;
    ok(div.addBehavior === override_func, "div.addBehavior != override_func");
    ok(typeof(div.addBehavior) === "function", "typeof(div.addBehavior) = " + typeof(div.addBehavior));

    var tmp = div.addBehavior();
    ok(tmp === "test", "div.addBehavior() = " + tmp);

    tmp = String(div.attachEvent);
    ok(tmp == "\nfunction attachEvent() {\n    [native code]\n}\n", "String(div.attachEvent) = " + tmp);
}

function test_forin() {
    var cnt=0;

    document.body.innerHTML = '<a id="aid"></a>';

    for(var x in document.getElementById("aid")) {
        cnt++;
    }

    ok(cnt > 100, "cnt = " + cnt);
}

function test_customtag() {
    document.body.innerHTML = 'test<unk><br>';

    var children = document.body.childNodes;

    ok(children.length === 3, "children.length = " + children.length);
    ok(children[0].data === "test", "children[0].data = " + children[0].data);
    ok(children[1].tagName === "UNK", "children[1].tagName = " + children[1].tagName);
    ok(children[2].tagName === "BR", "children[2].tagName = " + children[2].tagName);
}

function test_whitespace_nodes() {
    document.body.innerHTML = '<table id="tid"> <tr> \t<td>\n \t<div></div> </td>\n </tr> </table>';

    var t = document.getElementById("tid");
    ok(t.childNodes.length === 1, "t.childNodes.length = " + t.childNodes.length);
    ok(t.childNodes[0].tagName === "TBODY", "t.childNodes[0].tagName = " + t.childNodes[0].tagName);

    var row = t.rows[0];
    ok(row.childNodes.length === 1, "row.childNodes.length = " + row.childNodes.length);
    ok(row.childNodes[0].tagName === "TD", "row.childNodes[0].tagName = " + row.childNodes[0].tagName);

    var cell = row.cells[0];
    ok(cell.childNodes.length === 1, "cell.childNodes.length = " + cell.childNodes.length);


    document.body.innerHTML = '<table id="tid"> x<tr> \tx<td>\n \tx<div></div> </td>\n </tr> </table>';

    t = document.getElementById("tid");
    ok(t.rows[0].cells[0].childNodes.length === 2,
        "t.rows[0].cells[0].childNodes.length = " + t.rows[0].cells[0].childNodes.length);
}

function test_language_attribute() {
    document.body.innerHTML = '<div id="did" language="test"></div>';
    var elem = document.getElementById("did");
    ok(elem.language === "test", "elem.language = " + elem.language);
    elem.language = 1;
    ok(elem.language === "1", "elem.language = " + elem.language);
}

function test_text_node() {
    document.body.innerHTML = 'testing text';
    var text = document.body.childNodes[0], text2;
    ok(text.data == "testing text", "text.data = " + text.data);

    text2 = text.splitText(7);
    ok(text.data == "testing", "text.data = " + text.data);
    ok(text2.data == " text", "text2.data = " + text2.data);
    ok(text.nextSibling === text2, "text.nextSibling !== text2");

    text2 = text.splitText(0);
    ok(text.data == "", "text.data = " + text.data);
    ok(text2.data == "testing", "text2.data = " + text2.data);
}

function test_xhr() {
    ok("XMLHttpRequest" in window, "XMLHttpRequest not found in window object\n");

    if (typeof(XMLHttpRequest) != "object") {
        win_skip("XMLHTTPRequest is not available or disabled");
        return;
    }

    var xhr = new XMLHttpRequest();
    ok(typeof(xhr) === "object", "typeof(xhr) = " + typeof(xhr));
}

var globalVar = false;

function runTests() {
    obj = new Object();
    ok(obj === window.obj, "obj !== window.obj");

    ok(typeof(divid) === "object", "typeof(divid) = " + typeof(divid));

    test_removeAttribute(document.getElementById("divid"));
    test_removeAttribute(document.body);
    test_select_index();
    test_clone_node();
    test_createDocumentFragment();
    test_document_name_as_index();
    test_remove_style_attribute();
    test_getter_call();
    test_attrs();
    test_attribute_collection();
    test_arg_conv();
    test_override_functions();
    test_forin();
    test_customtag();
    test_whitespace_nodes();
    test_language_attribute();
    test_text_node();
    test_xhr();

    var r = window.execScript("globalVar = true;");
    ok(r === undefined, "execScript returned " + r);
    ok(globalVar === true, "globalVar = " + globalVar);

    /* Call setTimeout without specified time. */
    window.setTimeout(function() { external.reportSuccess(); });
}

function runTest() {
    try {
        runTests();
    }catch(e) {
        ok(false, "got exception " + e.message);
    }
}
</script>
<body onload="runTest();">
<div id="divid"></div>
<select id="sel">
<option>opt1</option>
<option>opt2</option>
</select>
</body>
</html>
  J   0   P N G   I M G . P N G       0           �PNG

   IHDR         �Ԛs   IDATx�c�@ "� 3��ɸ�    IEND�B`�  