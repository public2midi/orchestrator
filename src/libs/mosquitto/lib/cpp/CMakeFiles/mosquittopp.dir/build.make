# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/benjamin/orchestra/src/libs/mosquitto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/benjamin/orchestra/src/libs/mosquitto

# Include any dependencies generated for this target.
include lib/cpp/CMakeFiles/mosquittopp.dir/depend.make

# Include the progress variables for this target.
include lib/cpp/CMakeFiles/mosquittopp.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cpp/CMakeFiles/mosquittopp.dir/flags.make

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o: lib/cpp/CMakeFiles/mosquittopp.dir/flags.make
lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o: lib/cpp/mosquittopp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/benjamin/orchestra/src/libs/mosquitto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o"
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o -c /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp/mosquittopp.cpp

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i"
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp/mosquittopp.cpp > CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s"
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp/mosquittopp.cpp -o CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires:

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires
	$(MAKE) -f lib/cpp/CMakeFiles/mosquittopp.dir/build.make lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides.build
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides.build: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o


# Object files for target mosquittopp
mosquittopp_OBJECTS = \
"CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o"

# External object files for target mosquittopp
mosquittopp_EXTERNAL_OBJECTS =

lib/cpp/libmosquittopp.1.4.14.dylib: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o
lib/cpp/libmosquittopp.1.4.14.dylib: lib/cpp/CMakeFiles/mosquittopp.dir/build.make
lib/cpp/libmosquittopp.1.4.14.dylib: lib/libmosquitto.1.4.14.dylib
lib/cpp/libmosquittopp.1.4.14.dylib: lib/cpp/CMakeFiles/mosquittopp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/benjamin/orchestra/src/libs/mosquitto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmosquittopp.dylib"
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mosquittopp.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && $(CMAKE_COMMAND) -E cmake_symlink_library libmosquittopp.1.4.14.dylib libmosquittopp.1.dylib libmosquittopp.dylib

lib/cpp/libmosquittopp.1.dylib: lib/cpp/libmosquittopp.1.4.14.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/cpp/libmosquittopp.1.dylib

lib/cpp/libmosquittopp.dylib: lib/cpp/libmosquittopp.1.4.14.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/cpp/libmosquittopp.dylib

# Rule to build all files generated by this target.
lib/cpp/CMakeFiles/mosquittopp.dir/build: lib/cpp/libmosquittopp.dylib

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/build

lib/cpp/CMakeFiles/mosquittopp.dir/requires: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/requires

lib/cpp/CMakeFiles/mosquittopp.dir/clean:
	cd /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp && $(CMAKE_COMMAND) -P CMakeFiles/mosquittopp.dir/cmake_clean.cmake
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/clean

lib/cpp/CMakeFiles/mosquittopp.dir/depend:
	cd /Users/benjamin/orchestra/src/libs/mosquitto && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/benjamin/orchestra/src/libs/mosquitto /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp /Users/benjamin/orchestra/src/libs/mosquitto /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp /Users/benjamin/orchestra/src/libs/mosquitto/lib/cpp/CMakeFiles/mosquittopp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/depend

