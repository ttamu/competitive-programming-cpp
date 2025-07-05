cmake_minimum_required(VERSION 3.28.3)
project(cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
    add_executable(main src/main.cpp)
    set_target_properties(main PROPERTIES FOLDER "Main")
endif ()

file(GLOB_RECURSE ALL_SOURCES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
)

foreach (source_file ${ALL_SOURCES})
    if ("${source_file}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
        continue()
    endif()
    get_filename_component(problem_name ${source_file} NAME_WE)
    get_filename_component(problem_dir ${source_file} DIRECTORY)
    get_filename_component(contest_name ${problem_dir} NAME)
    set(target_name "${contest_name}_${problem_name}")

    add_executable(${target_name} "${source_file}")

    get_filename_component(contest_group_dir ${problem_dir} DIRECTORY)
    get_filename_component(contest_group_name ${contest_group_dir} NAME)
    set_target_properties(${target_name} PROPERTIES
            FOLDER "Contests/${contest_group_name}/${contest_name}"
    )
endforeach ()