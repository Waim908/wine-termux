        ��  ��                  h  H   ��
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
g  H   ��
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
    <clrSurrogate
        clsid="{2e106e50-e7a4-4489-8538-83643f100fdd}"
        name="Surrogate.Test"
        runtimeVersion="v4.0.0.1">
    </clrSurrogate>
    <file name="comtest.dll">
    </file>
</assembly>
 