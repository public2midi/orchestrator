cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COMPILE_FLAGS "-D__MACOSX_CORE__")

set(SOURCE_FILES main.cpp component/OrchAdderComponent.cpp component/OrchAdderComponent.h component/OrchSumComponent.cpp component/OrchSumComponent.h component/OrchStreamReaderComponent.cpp component/OrchStreamReaderComponent.h component/OrchStreamWriterComponent.cpp component/OrchStreamWriterComponent.h component/OrchMqttSourceComponent.cpp component/OrchMqttSourceComponent.h component/OrchMidiOutputComponent.cpp component/OrchMidiOutputComponent.h midi/midi.h component/OrchMidiKeyProducer.cpp component/OrchMidiKeyProducer.h midi/RtMidi.h midi/RtMidi.cpp component/OrchMidiTextToKeyComponent.cpp component/OrchMidiTextToKeyComponent.h)

find_library(CORE_MIDI CoreMIDI)
find_library(CORE_AUDIO CoreAudio)
find_library(CORE_FOUNDATION CoreFoundation)

add_definitions(${GCC_COMPILE_FLAGS})
add_executable(orchestra ${SOURCE_FILES})

target_link_libraries(orchestra ${CORE_MIDI})
target_link_libraries(orchestra ${CORE_AUDIO})
target_link_libraries(orchestra ${CORE_FOUNDATION})

target_link_libraries(orchestra DSPatch)
target_link_libraries(orchestra mosquittopp)