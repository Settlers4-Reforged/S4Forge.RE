cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(S4_Main CXX)


math(EXPR bits "8 * ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "Building ${bits}-bit Settlers 4")
if (NOT bits EQUAL 32)
  message(WARNING "Only 32-bit executables are supported at this time!")
endif()

file(GLOB_RECURSE GENERATED_SOURCES S4_Main/generated/*.cpp)

set(SOURCE_LIST
    S4_Main/main.cpp
    ${GENERATED_SOURCES}
)

add_executable(S4_Main ${SOURCE_LIST})


target_compile_features(S4_Main PRIVATE cxx_std_17)
target_compile_options(S4_Main PRIVATE /W4 /WX /permissive-)

target_include_directories(S4_Main PRIVATE S4_Main/generated)
target_include_directories(S4_Main PRIVATE S4_Main/src)
