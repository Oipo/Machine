:: Download and unpack Boost, build Boost.python
:: =============================================
call install-mingw.bat


cd "%tempdir%"

set filename=boost_1_41_0.7z
set boost=boost_1_41_0

wget -nc -c -H http://sourceforge.net/projects/boost/files/boost/1.41.0/%filename%/download
7za x -y %filename%

xcopy %boost%\boost MinGW\include\boost /e /y /i 

cd %boost%\libs\python\build
bjam toolset=gcc stage

cd "%tempdir%\%boost%\bin.v2\libs\python\build\gcc-mingw-4.4.0\debug"

xcopy /y /i *.dll "%tempdir%\MinGW\lib"
xcopy /y /i *.lib "%tempdir%\MinGW\lib"

cd %topdir%

