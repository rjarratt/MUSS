..\x64\debug\nmsl ..\..\muss\musl\ReferencePlatform.musl ReferencePlatform.bin -lib
if errorlevel 1 goto error
..\x64\debug\nmsl ..\..\muss\musl\ReferenceUtils.musl ReferenceUtils.bin -lib
if errorlevel 1 goto error
..\x64\debug\nmsl ..\..\muss\musl\ReferenceLibrary1.musl ReferenceLibrary1.bin -lib
if errorlevel 1 goto error
..\x64\debug\nmsl ..\..\muss\musl\ReferenceLibrary2.musl ReferenceLibrary2.bin -lib
if errorlevel 1 goto error
..\x64\debug\nmsl ..\..\muss\musl\ReferenceProgram1.musl ReferenceProgram1.bin -i ReferencePlatform.bin -i ReferenceUtils.bin -i ReferenceLibrary1.bin -i ReferenceLibrary2.bin
if errorlevel 1 goto error

echo Build succeeded
goto done
:error
echo Build failed

:done
