cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)


project(Orchestra VERSION 0.1 LANGUAGES CXX)

include_directories(DSPatch/include)
include_directories(mosquitto/lib)

set(WITH_SRV OFF)
set(WITH_TLS OFF)

set(CMAKE_PREFIX_PATH ~/Qt/5.10.1/clang_64)

find_package(Qt5Widgets REQUIRED)

add_subdirectory(OrchestraCore)
add_subdirectory(OrchestraComponents)
add_subdirectory(OrchestraGUI)
add_subdirectory(OrchestraSimulator)
add_subdirectory(DSPatch)
add_subdirectory(mosquitto)
add_subdirectory(qtpatcher)