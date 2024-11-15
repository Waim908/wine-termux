        ��  ��                    8   X M L   X M L V I E W . X M L       0           <?xml version="1.0" encoding="ISO-8859-1"?>
<?xml-stylesheet type="text/xsl" href="xmlview.xsl"?>
<test>
    <field>
        <title>title1</title>
        <value>value1</value>
    </field>
    <field>
        <title>title2</title>
        <value>value2</value>
    </field>
</test>
    8   X M L   X M L V I E W . X S L       0           <?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
    <html>
    <body>
    <h2>Generated HTML</h2>
    <table>
    <tr bgcolor="green">
    <th>Title</th>
    <th>Value</th>
    </tr>
    <xsl:for-each select="test/field">
        <tr>
        <td><xsl:value-of select="title"/></td>
        <td><xsl:value-of select="value"/></td>
        </tr>
    </xsl:for-each>
    </table>
    </body>
    </html>
</xsl:template>

</xsl:stylesheet>
