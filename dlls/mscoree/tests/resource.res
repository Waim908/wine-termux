        ��  ��                    4   ��
 C O M T E S T . C S         0           /*
 * Copyright 2018 Fabian Maurer
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

/* Compile with
    csc /target:library /out:dll.dll comtest.cs
*/

using System.Runtime.InteropServices;

namespace DLL
{
    [Guid("1dbc4491-080d-45c5-a15d-1e3c4610bdd9"), ComVisible(true), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface ITest
    {
        void Func(ref int i);
    }

    [ComVisible(true), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface ITest2
    {
        void Func2(ref int i);
    }

    [Guid("2e106e50-e7a4-4489-8538-83643f100fdc"), ComVisible(true), ClassInterface(ClassInterfaceType.None)]
    public class Test : ITest, ITest2
    {
        public void Func(ref int i)
        {
            i = 42;
        }
        public void Func2(ref int i)
        {
            i = 43;
        }
    }
}
   h  H   ��
 C O M T E S T _ E X E . M A N I F E S T         0           <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
    <dependency>
        <dependentAssembly>
            <assemblyIdentity
                name="comtest"
                version="1.0.0.0"
                type="win32"/>
        </dependentAssembly>
    </dependency>
</assembly>
�  H   ��
 C O M T E S T _ D L L . M A N I F E S T         0           <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
    <assemblyIdentity
        name="comtest"
        version="1.0.0.0"
        type="win32"
    />
    <clrClass
        clsid="{2e106e50-e7a4-4489-8538-83643f100fdc}"
        threadingModel="Both"
        name="DLL.Test"
        runtimeVersion="v4.0.0.0">
    </clrClass>
    <file name="comtest.dll">
    </file>
</assembly>
   �  @   ��
 L O A D P A T H S . E X E . C S         0           /*
 * Copyright 2021 Rémi Bernon for CodeWeavers
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

using System;

namespace LoadPaths
{
    public static class Test
    {
        public static int RunExternal()
        {
            return new Test2().Foo();
        }
    }

    public static class MainClass
    {
        static int Main(string[] args)
        {
            try {
                return Test.RunExternal();
            }
            catch {
                return 1;
            }
        }
    }
}
   �  @   ��
 L O A D P A T H S . D L L . C S         0           /*
 * Copyright 2021 Rémi Bernon for CodeWeavers
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

using System.Reflection;

#if NEUTRAL
[assembly: AssemblyCulture("")]
#else
[assembly: AssemblyCulture("en")]
#endif

namespace LoadPaths
{
    public class Test2
    {
        public int Foo() { return 0; }
    }
}
  �   H   ��
 L O A D P A T H S . E X E . C O N F I G         0           <?xml version="1.0" encoding="utf-8"?>
<configuration>
  <runtime>
    <assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1">
      <probing privatePath="private"/>
    </assemblyBinding>
  </runtime>
</configuration>
  