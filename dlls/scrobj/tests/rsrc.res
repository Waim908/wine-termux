        ��  ��                    4   ��( S C R O B J . W S C         0           <?xml version="1.0"?>
<component>
  <registration description="WineTest object" progid="WineTest" version="1.23" classid="{a8a83483-a6ac-474d-b22a-9a5f2d68cb7f}">
  </registration>
  <public>
    <method name="vbAddOne">
      <PARAMETER name="n">
        <?pi xxx="yyy"?>
      </PARAMETER>
    </method>
    <method name="jsAddTwo" />
    <method name="wtTest">
      <Parameter name="i"/>
    </method>
    <property name="gsProp">
      <get />
      <put> </put>
    </property>
  </public>
  <script language="VBScript">
  <![CDATA[
Option explicit
Function vbAddOne( n )
    vbAddOne = n + 1
End Function
]]>
  </script>
  <script language="JScript">
  function jsAddTwo(n) { return n + 2; }
  </script>
  <script language="WTScript">WTTest body</script>
</component>
 