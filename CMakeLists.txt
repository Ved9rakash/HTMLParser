cmake_minimum_required(VERSION 3.20)
project(HTMLParser)

set(CMAKE_CXX_STANDARD 17)

function(add_subdirectories)
#    Getting the name of directories which contains CMakeLists.txt file.
    file(GLOB cmake_lists_file_path "*/CMakeLists.txt")

#   Adding path to cmake_path() separately
    foreach(curr_cmakeList_file_path ${cmake_lists_file_path})
        cmake_path(GET curr_cmakeList_file_path PARENT_PATH curr_subdirectory_path)
        message(STATUS "Added subdirectory: ${curr_subdirectory_path}")
        add_subdirectory(${curr_subdirectory_path})
    endforeach()
endfunction()

add_subdirectories()
