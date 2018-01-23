cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp component/OrchAdderComponent.cpp component/OrchAdderComponent.h component/OrchSumComponent.cpp component/OrchSumComponent.h component/OrchStreamReaderComponent.cpp component/OrchStreamReaderComponent.h component/OrchStreamWriterComponent.cpp component/OrchStreamWriterComponent.h component/OrchMqttSourceComponent.cpp component/OrchMqttSourceComponent.h)

add_executable(orchestra ${SOURCE_FILES})

target_link_libraries(orchestra DSPatch)
target_link_libraries(orchestra mosquittopp)