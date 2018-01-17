# Install script for directory: /Users/benjamin/orchestra/src/libs/DSPatch

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/benjamin/orchestra/src/libs/DSPatch/libDSPatch.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDSPatch.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDSPatch.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "libDSPatch.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDSPatch.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libDSPatch.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/benjamin/orchestra/src/libs/DSPatch/include/DSPatch.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dspatch" TYPE FILE FILES
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspCircuit.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspCircuitThread.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspComponent.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspComponentThread.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspParameter.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspPlugin.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspPluginLoader.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspRunType.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspSignal.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspSignalBus.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspThread.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspThreadNull.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspThreadUnix.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspThreadWin.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspWire.h"
    "/Users/benjamin/orchestra/src/libs/DSPatch/include/dspatch/DspWireBus.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/benjamin/orchestra/src/libs/DSPatch/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
