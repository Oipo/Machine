Background
========
There are a few use cases for the Machine Toolchain Installer. 

- You're hacking on the project and can't be bothered to set up your dev environment on a new comp or VM for the n-th time.
- You're a lurker trying to learn from the engine without investing the time to compile all the dependencies.
- You're coming from another language that doesn't have insane things like compilers, linkers, and makefiles, and you're too intimidated with setup to get to the code.


Using
========
Until the installer is more flexible, you'll have to modify 'install.bat' to choose which components you want installed.  Simply add a line like:
call install-somecomponent

If you want to install everything listed in install.bat, just double-click and away you go.  The process could take ten to fifteen minutes.  Have a cup of tea.  
After modifying install.bat, you can run 'package.bat' to produce your own,  personalized installer.

Running 'clean.bat' cleans up the temp directory.  It doesn't remove downloaded archives, so you can build again without redownloading.  

Some installers may depend on others: 
- box2d depends on cmake and svn
- boost.python (bjam, really) depends on mingw


Referece
=========
copy-to-top.bat -- Takes anything in temp\MinGW and puts it into machine-toolchain\Mingw
clean.bat -- remove any files generated during builds, but keep other stuff to speed up rebuilds. 
nuke.bat -- remove the temp directory for a clean slate


Hacking
========
The convention for these install scripts is to use the 'temp' directory for downloading and extracting.  At the top of an install script, use the command:
call path-fixer.bat
cd %tempdir%

'path-fixer.bat' ensures 'temp' exists, adds 'bin' to your path, and creates two helpful variables (%topdir% and %tempdir%).  For modularity, each script must end with the command:
cd %topdir%


*Roadmap* 
========
- Bootstrap python installation if one doesn't exist, start performing complicated scripting with that.
- Integrate buildit
- Integrate codeblocks
- Integrate github.com/rmag/machine
- Implement a script to check whether each dependency was successfully installed.
