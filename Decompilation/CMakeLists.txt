cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(S4_Main CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


math(EXPR bits "8 * ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "Building ${bits}-bit Settlers 4")
if (NOT bits EQUAL 32)
  message(WARNING "Only 32-bit executables are supported at this time.")
endif()

