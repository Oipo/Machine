:: Download and unpack MinGW
:: =========================
:: Had issues with spaces in paths,
:: so you'll see a lot of quotes around them:)

call path-fixer.bat
cd %tempdir%

wget -nc -c -H -i "%topdir%\mingw-urls.txt"

7za x -y *.gz 
7za x -y *.lzma
7za x -y -o"%tempdir%\MinGW" *.tar

copy MinGW\bin\mingw32-make.exe MinGW\bin\make.exe /y
set path=%path%;%tempdir%\MinGW\bin

cd %topdir%
