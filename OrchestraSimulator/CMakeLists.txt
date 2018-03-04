project(OrchestraSimulator)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB srcs src/*.cpp)

add_executable(simulator ${srcs})