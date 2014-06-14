Ramblings
-----------------------------------------
I forked this codebase from virtuald's apparently abandoned version, and re-did the Linux port because he didn't allow public access to
the dev version.  It has a shiny new cmake build system that should work on *nix, and the old Visual Studio project files are still
intact. See the README (no .md) file for the "old" Windows version doc.  I tried not to modify the codebase in such a way as to 
break Windows compatibility, so if someone out there has Visual Studio, I'd like to see if it will still work.

Build Instructions
-----------------------------------------
```# get the directory structure set up
$ cd ..
$ mkdir src
$ mv WPILibTestHarness src
$ mkdir WPILibTestHarness
$ mv src WPILibTestHarness
$ cd WPILibTestHarness
$ mkdir build
$ cd build

# build the code
$ cmake ../src
$ make
$ sudo make install

#if you want to run tests
$ make test

#if you are having a build error and want to see what commands cmake is running
$ make VERBOSE=1```

Use Instructions
-----------------------------------------
1. Create a different build configuration (or use a different setup entirely) that builds your robot code for x86(_64)

2. Add to include paths:
```/usr/include/wpiharness
/usr/include/wpiharness/WPILib```

3. Add to link libraries:
```WPILibTestHarness
wx_baseu-2.8
wx_gtk2u_xrc-2.8
wx_gtk2u_adv-2.8 
wx_gtk2u_core-2.8```
 (NOTE: the names of your wxwidgets libraries might be different, use wx-config to find them)

4. Run the resultant executable

