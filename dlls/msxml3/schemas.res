        ��  ��                  �;  4   X M L   D A T A T Y P E S       0           <?xml version="1.0" encoding="UTF-8"?>
<!--
    XDR (XML-Data Reduced) datatypes implementation

    Copyright 2010 Adam Martinson for CodeWeavers

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
-->
<xsd:schema xmlns="urn:schemas-microsoft-com:datatypes"
            xmlns:dt="urn:schemas-microsoft-com:datatypes"
            xmlns:xsd="http://www.w3.org/2001/XMLSchema"
            targetNamespace="urn:schemas-microsoft-com:datatypes"
            elementFormDefault="qualified"
            attributeFormDefault="unqualified">

    <xsd:simpleType name="bin.base64">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:base64Binary

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:base64Binary"/>
    </xsd:simpleType>

    <xsd:element name="bin.base64" type="dt:bin.base64"/>

    <xsd:simpleType name="bin.hex">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:hexBinary

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:hexBinary"/>
    </xsd:simpleType>

    <xsd:element name="bin.hex" type="dt:bin.hex"/>

    <xsd:simpleType name="boolean">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:boolean

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:boolean"/>
    </xsd:simpleType>

    <xsd:element name="boolean" type="dt:boolean"/>

    <xsd:simpleType name="char">
        <xsd:annotation>
            <xsd:documentation>

                Single unicode char

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:string">
            <xsd:length value="1"/>
        </xsd:restriction>
    </xsd:simpleType>

    <xsd:element name="char" type="dt:char"/>

    <xsd:simpleType name="date">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:date with no timezone

                TODO: restrict -> force no timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:date"/>
    </xsd:simpleType>

    <xsd:element name="date" type="dt:date"/>

    <xsd:simpleType name="date.tz">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:date with timezone

                TODO: restrict -> force timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:date"/>
    </xsd:simpleType>

    <xsd:element name="date.tz" type="dt:date.tz"/>

    <xsd:simpleType name="dateTime">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:dateTime with no timezone

                TODO: restrict -> force no timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:dateTime"/>
    </xsd:simpleType>

    <xsd:element name="dateTime" type="dt:dateTime"/>

    <xsd:simpleType name="dateTime.tz">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:dateTime with timezone

                TODO: restrict -> force timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:dateTime"/>
    </xsd:simpleType>

    <xsd:element name="dateTime.tz" type="dt:dateTime.tz"/>

    <xsd:simpleType name="entity">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:ENTITY

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:ENTITY"/>
    </xsd:simpleType>

    <xsd:element name="entity" type="dt:entity"/>

    <xsd:simpleType name="entities">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:ENTITIES

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:ENTITIES"/>
    </xsd:simpleType>

    <xsd:element name="entities" type="dt:entities"/>

    <xsd:simpleType name="enumeration">
        <xsd:annotation>
            <xsd:documentation>

                Valid for attributes only
                dt:values is equivalent to xsd:list

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:string"/>
    </xsd:simpleType>

    <xsd:simpleType name="fixed.14.4">
        <xsd:annotation>
            <xsd:documentation>

                Fixed-length decimal floating-point value
                Up to 14 digits before the decimal point
                Up to 4 digits after the decimal point

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:decimal">
            <xsd:pattern value="([0-9]{0,14})([.][0-9]{0,4})?"/>
        </xsd:restriction>
    </xsd:simpleType>

    <xsd:element name="fixed.14.4" type="dt:fixed.14.4"/>

    <xsd:simpleType name="float">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:decimal

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:decimal"/>
    </xsd:simpleType>

    <xsd:element name="float" type="dt:float"/>

    <xsd:simpleType name="i1">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:byte

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:byte"/>
    </xsd:simpleType>

    <xsd:element name="i1" type="dt:i1"/>

    <xsd:simpleType name="i2">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:short

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:short"/>
    </xsd:simpleType>

    <xsd:element name="i2" type="dt:i2"/>

    <xsd:simpleType name="i4">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:int

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:int"/>
    </xsd:simpleType>

    <xsd:element name="i4" type="dt:i4"/>

    <xsd:simpleType name="i8">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:long

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:long"/>
    </xsd:simpleType>

    <xsd:element name="i8" type="dt:i8"/>

    <xsd:simpleType name="id">
        <xsd:annotation>
            <xsd:documentation>

                Valid for attributes only
                Equivalent to xsd:ID

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:ID"/>
    </xsd:simpleType>

    <xsd:simpleType name="idref">
        <xsd:annotation>
            <xsd:documentation>

                Valid for attributes only
                Equivalent to xsd:IDREF

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:IDREF"/>
    </xsd:simpleType>

    <xsd:simpleType name="idrefs">
        <xsd:annotation>
            <xsd:documentation>

                Valid for attributes only
                Equivalent to xsd:IDREFS

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:IDREFS"/>
    </xsd:simpleType>

    <xsd:simpleType name="int">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:integer

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:integer"/>
    </xsd:simpleType>

    <xsd:element name="int" type="dt:int"/>

    <xsd:simpleType name="nmtoken">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:NMTOKEN

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:NMTOKEN"/>
    </xsd:simpleType>

    <xsd:element name="nmtoken" type="dt:nmtoken"/>

    <xsd:simpleType name="nmtokens">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:NMTOKENS

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:NMTOKENS"/>
    </xsd:simpleType>

    <xsd:element name="nmtokens" type="dt:nmtokens"/>

    <xsd:simpleType name="notation">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:NOTATION

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:NOTATION"/>
    </xsd:simpleType>

    <xsd:element name="notation" type="dt:notation"/>

    <xsd:simpleType name="number">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:decimal

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:decimal"/>
    </xsd:simpleType>

    <xsd:element name="number" type="dt:number"/>

    <xsd:simpleType name="r4">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:float

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:float"/>
    </xsd:simpleType>

    <xsd:element name="r4" type="dt:r4"/>

    <xsd:simpleType name="r8">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:double

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:double"/>
    </xsd:simpleType>

    <xsd:element name="r8" type="dt:r8"/>

    <xsd:simpleType name="string">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:string

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:string"/>
    </xsd:simpleType>

    <xsd:element name="string" type="dt:string"/>

    <xsd:simpleType name="time">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:time with no timezone

                TODO: restrict -> force no timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:time"/>
    </xsd:simpleType>

    <xsd:element name="time" type="dt:time"/>

    <xsd:simpleType name="time.tz">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:time with timezone

                TODO: restrict -> force timezone

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:time"/>
    </xsd:simpleType>

    <xsd:element name="time.tz" type="dt:time.tz"/>

    <xsd:simpleType name="ui1">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:unsignedByte

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:unsignedByte"/>
    </xsd:simpleType>

    <xsd:element name="ui1" type="dt:ui1"/>

    <xsd:simpleType name="ui2">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:unsignedShort

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:unsignedShort"/>
    </xsd:simpleType>

    <xsd:element name="ui2" type="dt:ui2"/>

    <xsd:simpleType name="ui4">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:unsignedInt

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:unsignedInt"/>
    </xsd:simpleType>

    <xsd:element name="ui4" type="dt:ui4"/>

    <xsd:simpleType name="ui8">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:unsignedLong

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:unsignedLong"/>
    </xsd:simpleType>

    <xsd:element name="ui8" type="dt:ui8"/>

    <xsd:simpleType name="uri">
        <xsd:annotation>
            <xsd:documentation>

                Equivalent to xsd:anyURI

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:anyURI"/>
    </xsd:simpleType>

    <xsd:element name="uri" type="dt:uri"/>

    <xsd:simpleType name="uuid">
        <xsd:annotation>
            <xsd:documentation>

                Hex octet string with optional hyphens

            </xsd:documentation>
        </xsd:annotation>

        <xsd:restriction base="xsd:string">
            <xsd:pattern value="([0-9A-Fa-f]{4})([-]{0,1}[0-9A-Fa-f]{4})*"/>
        </xsd:restriction>
    </xsd:simpleType>

    <xsd:element name="uuid" type="dt:uuid"/>

    <xsd:attribute name="dt" default="string">
        <xsd:simpleType>
            <xsd:restriction base="string">
                <xsd:enumeration value="bin.base64"/>
                <xsd:enumeration value="bin.hex"/>
                <xsd:enumeration value="boolean"/>
                <xsd:enumeration value="char"/>
                <xsd:enumeration value="date"/>
                <xsd:enumeration value="date.tz"/>
                <xsd:enumeration value="dateTime"/>
                <xsd:enumeration value="dateTime.tz"/>
                <xsd:enumeration value="entity"/>
                <xsd:enumeration value="entities"/>
                <xsd:enumeration value="enumeration"/>
                <xsd:enumeration value="fixed.14.4"/>
                <xsd:enumeration value="float"/>
                <xsd:enumeration value="i1"/>
                <xsd:enumeration value="i2"/>
                <xsd:enumeration value="i4"/>
                <xsd:enumeration value="i8"/>
                <xsd:enumeration value="id"/>
                <xsd:enumeration value="idref"/>
                <xsd:enumeration value="idrefs"/>
                <xsd:enumeration value="int"/>
                <xsd:enumeration value="nmtoken"/>
                <xsd:enumeration value="nmtokens"/>
                <xsd:enumeration value="notation"/>
                <xsd:enumeration value="number"/>
                <xsd:enumeration value="r4"/>
                <xsd:enumeration value="r8"/>
                <xsd:enumeration value="string"/>
                <xsd:enumeration value="time"/>
                <xsd:enumeration value="time.tz"/>
                <xsd:enumeration value="ui1"/>
                <xsd:enumeration value="ui2"/>
                <xsd:enumeration value="ui4"/>
                <xsd:enumeration value="ui8"/>
                <xsd:enumeration value="uri"/>
                <xsd:enumeration value="uuid"/>
            </xsd:restriction>
        </xsd:simpleType>
    </xsd:attribute>

</xsd:schema>
  