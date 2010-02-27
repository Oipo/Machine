call path-fixer.bat

:: Download and unpack SFML
:: ========================
cd %tempdir%
set filename=SFML-1.5-sdk-windows-mingw.zip

wget -nc -c -H http://downloads.sourceforge.net/sfml/%filename%
7za x -y %filename%

xcopy SFML-1.5\include MinGW\include /e /y /i
xcopy SFML-1.5\lib\mingw MinGW\lib /e /y /i

cd %topdir%

