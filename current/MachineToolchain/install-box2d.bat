call path-fixer.bat

call install-svn.bat
call install-cmake.bat
call install-mingw.bat

cd %tempdir%

svn checkout http://box2d.googlecode.com/svn/trunk/
cd trunk\Box2d

wget -H -c -nc http://aur.archlinux.org/packages/box2d-svn/box2d-svn/CMakeLists.txt
cmake -G "MinGW Makefiles"
make

xcopy /e /y /i Box2d "%tempdir%\MinGW\include\Box2d"
xcopy /y /i *.a "%tempdir%\MinGW\lib"
xcopy /y /i *.dll "%tempdir%\MinGW\lib"

cd %topdir%
