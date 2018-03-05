project(OrchestraGUI)

include_directories(../OrchestraCore/include)
include_directories(../qtpatcher/include)

file(GLOB srcs src/*.cpp)
file(GLOB hdrs include/*.h)

add_definitions(-DPLUGIN_DIR="${CMAKE_CURRENT_SOURCE_DIR}/components")

add_executable(
        ${PROJECT_NAME}
        ${srcs}
        ${hdrs}
)

target_link_libraries(
        ${PROJECT_NAME}
        OrchestraCore
        mosquittopp
        DSPatch
        QtPatcher
)