        ��  ��                  C  8   D A T A   _ _ G D F _ X M L         0           <?xml version="1.0" encoding="utf-8"?>
<!--
     Example Game Definition File

     Copyright (C) 2010 Mariusz Pluciński

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
<GameDefinitionFile
xmlns:baseTypes="urn:schemas-microsoft-com:GamesExplorerBaseTypes.v1"
xmlns="urn:schemas-microsoft-com:GameDescription.v1">
    <GameDefinition gameID="{17A6558E-60BE-4078-B66F-9C3ADA2A32E6}">
        <Name>Example Game</Name>
        <Description>Game Description</Description>
        <Version>
            <VersionNumber versionNumber="1.0.0.0"/>
        </Version>
        <ExtendedProperties>
            <GameTasks>
                <Play>
                    <Primary>
                        <FileTask path="gameux_test.exe" arguments="" />
                    </Primary>
                </Play>
            </GameTasks>
        </ExtendedProperties>
    </GameDefinition>
</GameDefinitionFile>
 