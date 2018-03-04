project(OrchestraGUI)

include_directories(../OrchestraCore/include)

file(GLOB srcs src/*.cpp)
file(GLOB hdrs include/*.h)

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
)