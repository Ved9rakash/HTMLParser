cmake_minimum_required(VERSION 3.20)
project(HTMLParser)

set(CMAKE_CXX_STANDARD 17)

#find_package(curl REQUIRED)
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "cmake-conan Downloaded.")
endif()

#include(${CMAKE_BINARY_DIR}/conan.cmake)

#conan_cmake_run(REQUIRES Catch2/2.6.0@catchorg/stable BASIC_SETUP)

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
