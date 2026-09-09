cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(MapAccess CXX)

math(EXPR bits "8 * ${CMAKE_SIZEOF_VOID_P}")
message(STATUS "Building ${bits}-bit Settlers 4")
if (NOT bits EQUAL 32)
    message(WARNING "Only 32-bit executables are supported at this time!")
endif ()

file(GLOB_RECURSE COMPRESSION_SOURCES ../Compression/*.cpp)
#file(GLOB_RECURSE CBB_SOURCES ../CBB/*.cpp)

set(SOURCE_LIST
        MapAccess.cpp
        "${CMAKE_CURRENT_LIST_DIR}/../LoadSave/Cryptor.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../LoadSave/SMapChunk.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../Main/Players/CPlayerData.cpp"
        SEditorGlobalMapData.cpp
        ${COMPRESSION_SOURCES}
        #        ${CBB_SOURCES}
        "${CMAKE_CURRENT_LIST_DIR}/../CBB/CBBSupport.cpp"
)

add_library(MapAccess SHARED ${SOURCE_LIST})


target_compile_features(MapAccess PRIVATE cxx_std_17)
target_compile_options(MapAccess PRIVATE /W4 /permissive-) # later add back /WX
#set_target_properties(MapAccess PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")

target_compile_definitions(MapAccess PRIVATE EXPORT_MA)

target_link_libraries(MapAccess "comsuppw.lib")

target_include_directories(MapAccess PRIVATE "${CMAKE_CURRENT_LIST_DIR}/..")