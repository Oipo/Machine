call path-fixer.bat

cd %tempdir%

set pylocation=%SystemDrive%\Python26

if not exist "%pylocation%\python.exe" (
wget -nc -c -H http://www.python.org/ftp/python/2.6.4/python-2.6.4.msi
msiexec /i python-2.6.4.msi /passive
) else (
echo "Found python, sweeeeeeeeet..."
)

set path=%PATH%;"%pylocation%"

cd %topdir%
