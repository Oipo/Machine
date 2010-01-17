call path-fixer.bat
cd %tempdir%

set filename=svn-win32-1.5.6
wget -nc -c -H "http://subversion.tigris.org/files/documents/15/45222/%filename%.zip"
7za x -y %filename%.zip
set path=%PATH%;%CD%\%filename%\bin

cd %topdir%
