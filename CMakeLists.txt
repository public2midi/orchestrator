cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

project(Orchestra VERSION 0.1 LANGUAGES CXX)

include_directories(DSPatch/include)
include_directories(mosquitto/lib)

set(WITH_SRV OFF)
set(WITH_TLS OFF)

add_subdirectory(OrchestraCore)
add_subdirectory(OrchestraComponents)
add_subdirectory(OrchestraGUI)
add_subdirectory(OrchestraSimulator)
add_subdirectory(DSPatch)
add_subdirectory(mosquitto)