        ��  ��                  �      �� ��     0           <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity
      type="win32"
      name="wine.combase.test"
      version="1.0.0.0"
      processorArchitecture="*"
  />
<description>Wine combase test suite</description>
<file name="wine.combase.test.dll">
  <activatableClass name="Wine.Test.Missing" threadingModel="both" xmlns="urn:schemas-microsoft-com:winrt.v1"/>
  <activatableClass name="Wine.Test.Class" threadingModel="both" xmlns="urn:schemas-microsoft-com:winrt.v1"/>
  <activatableClass name="Wine.Test.Trusted" threadingModel="both" xmlns="urn:schemas-microsoft-com:winrt.v1"/>
</file>
</assembly>
  