cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(MapAccess CXX)

set(MA_TEST_SOURCE_LIST
        lib/catch_amalgamated.cpp
        MapAccess/tests.cpp
)

add_executable(MA_tests ${MA_TEST_SOURCE_LIST})
add_subdirectory(../S4_Main/src/MapAccess "${CMAKE_BINARY_DIR}/MA-build")
target_link_libraries(MA_tests PRIVATE MapAccess)

target_compile_features(MA_tests PRIVATE cxx_std_17)
target_compile_options(MA_tests PRIVATE /W4 /permissive-) # later add back /WX
#set_target_properties(MA_tests PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")

target_include_directories(MA_tests PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../S4_Main/src")


set(MA_FIXTURE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/MapAccess/fixture")
set(MA_FIXTURE_DST_DIR "${CMAKE_CURRENT_BINARY_DIR}/MapAccess/fixture")

add_custom_target(copy_MA_fixtures ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "${MA_FIXTURE_DST_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${MA_FIXTURE_SRC_DIR}" "${MA_FIXTURE_DST_DIR}"
)

add_custom_command(TARGET MA_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MapAccess>
        $<TARGET_FILE_DIR:MA_tests>
        COMMAND_EXPAND_LISTS
)

add_dependencies(MA_tests copy_MA_fixtures)

target_compile_definitions(MA_tests PRIVATE
        MA_TEST_FIXTURE_DIR="${MA_FIXTURE_DST_DIR}"
)
