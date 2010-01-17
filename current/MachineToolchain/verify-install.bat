call path-fixer.bat

set instdir=%tempdir%\MinGW
if not exist "%instdir%\bin" (echo "MinGW not installed" >> error_log.txt ; exit)
    

set error="Box2d not installed."

if not exist "%instdir%\include\Box2d" (
    echo "Box2d not installed" >> error_log.txt)

if not exist "%instdir%\lib\libbox2d.a" (
    echo %error% >> error_log.txt


set error="Boost not installed."

