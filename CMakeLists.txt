cmake_minimum_required(VERSION 3.28.3)
project(cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lib")

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
    add_executable(main src/main.cpp)
    target_include_directories(main PRIVATE ${INCLUDE_DIRS})
endif ()

file(GLOB ALL_SOURCES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/bin/*.cpp"
)

foreach (source_file ${ALL_SOURCES})
    get_filename_component(target_name ${source_file} NAME_WE)

    add_executable(${target_name} "${source_file}")
    target_include_directories(${target_name} PRIVATE ${INCLUDE_DIRS})
endforeach ()
