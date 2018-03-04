cmake_minimum_required(VERSION 3.8)

project(OrchestraCore)

include_directories(include)

include_directories(../OrchestraComponents)

file(GLOB srcs src/*.cpp)
file(GLOB hdrs include/*.h)

add_library(
        ${PROJECT_NAME} SHARED
        ${srcs}
        ${hdrs}
)

target_link_libraries(
        ${PROJECT_NAME}
        MqttSource
        StreamWriter
)