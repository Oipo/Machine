path=%PATH%;%CD%\bin
set name="MachineToolchain-%username%"
mkdir "%name%"

::utils
copy /y README.txt "%name%"
copy /y path-fixer.bat "%name%"
copy /y clean.bat "%name%"
xcopy /e /y /i bin "%name%\bin"

::installers
copy /y install.bat "%name%"
copy /y install-mingw.bat "%name%"
copy /y mingw-urls.txt "%name%"
copy /y install-sfml.bat "%name%"
copy /y install-boost.bat "%name%"
copy /y install-box2d.bat "%name%"
copy /y install-svn.bat "%name%"
copy /y install-cmake.bat "%name%"
copy /y install-python.bat "%name%"

7za a "%name%.7z" "%name%"  

rd /s /q "machine-toolchain-%username%"
