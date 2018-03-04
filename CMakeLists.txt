cmake_minimum_required(VERSION 3.8)
project(orchestra VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

macro(ADD_SUBLIB libname)
    file(GLOB sublib_sources "src/libs/${libname}/src/*.cpp")
    add_library(${libname} SHARED ${sublib_sources})
    include_directories("src/libs/${libname}/include")
endmacro(ADD_SUBLIB)

ADD_SUBLIB(DSPatch)

set(WITH_SRV OFF)
set(WITH_TLS OFF)

add_subdirectory(src/libs/mosquitto)
include_directories(src/libs/mosquitto/lib/cpp/)
include_directories(src/libs/mosquitto/lib)


add_subdirectory(src/orchestra)

add_subdirectory(src/mockDataSimulator)
