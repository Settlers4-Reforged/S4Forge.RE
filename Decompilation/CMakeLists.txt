cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(S4_Main CXX)

math(EXPR bits "8 * ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "Building ${bits}-bit Settlers 4")
if (NOT bits EQUAL 32)
    message(WARNING "Only 32-bit executables are supported at this time!")
endif ()

file(GLOB_RECURSE CUSTOM_SOURCES ./S4_Main/src/*.cpp)

set(SOURCE_LIST
        ${CUSTOM_SOURCES}
)

add_subdirectory(S4_Main/lib/sdl EXCLUDE_FROM_ALL)

add_executable(S4_Main ${SOURCE_LIST})


target_compile_features(S4_Main PRIVATE cxx_std_17)
target_compile_options(S4_Main PRIVATE /W4 /permissive-) # later add back /WX
set(CMAKE_C_FLAGS "-m32")
set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_EXE_LINKER_FLAGS "-m32")

#target_include_directories(S4_Main PRIVATE S4_Main/generated)
target_include_directories(S4_Main PRIVATE S4_Main/src)
target_include_directories(S4_Main PRIVATE S4_Main/lib)

target_link_libraries(S4_Main PRIVATE SDL3::SDL3)