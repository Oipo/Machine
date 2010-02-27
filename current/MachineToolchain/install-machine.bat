call path-fixer.bat

cd %tempdir%

wget -nc -c -H http://github.com/rmag/machine/zipball/master

7za x -y  rmag*.zip

cd %topdir%
