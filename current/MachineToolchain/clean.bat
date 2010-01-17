call path-fixer.bat

cd %tempdir%

del /s /q *.tar
del /q ..\*.7z
del /q ..\error_log.txt

rd /s /q boost_1_41_0\bin.v2
::'trunk' refers to Box2d, pulled from SVN
rd /s /q trunk
if exist trunk ( call "%topdir%\clean.bat" )
rd /s /q Box2D_v2.0.1

cd %topdir%

