project(RtMidi)

file(GLOB srcs src/*.cpp)
file(GLOB hdrs include/*.h)

set(GCC_COMPILE_FLAGS "-D__MACOSX_CORE__")

find_library(CORE_MIDI CoreMIDI)
find_library(CORE_AUDIO CoreAudio)
find_library(CORE_FOUNDATION CoreFoundation)

add_definitions(${GCC_COMPILE_FLAGS})

add_library(
        ${PROJECT_NAME} SHARED
        ${srcs}
        ${hdrs}
)

target_link_libraries(${PROJECT_NAME} ${CORE_MIDI})
target_link_libraries(${PROJECT_NAME} ${CORE_AUDIO})
target_link_libraries(${PROJECT_NAME} ${CORE_FOUNDATION})