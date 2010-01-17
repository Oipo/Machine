call path-fixer.bat
cd %tempdir%

set filename="cmake-2.8.0-win32-x86"
wget -nc -c -H "http://www.cmake.org/files/v2.8/%filename%.zip"
7za x -y cmake-*.zip
set path=%PATH%;%CD%\%filename%\bin

cd %topdir%
