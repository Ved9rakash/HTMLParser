cmake_minimum_required(VERSION 3.20)
project(HTMLParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        HTMLParser src/HTMLParser.cpp
        include/webPageGrabber.hpp
        src/webPageGrabber.cpp
        src/convert.cpp
)
