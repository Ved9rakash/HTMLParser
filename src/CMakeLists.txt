#include_directories(one PUBLIC ../include/)
add_library(PageGrabber STATIC PageGrabber.cpp ../include/PageGrabber.hpp)
add_executable(Parser HTMLParser.cpp)
target_link_libraries(Parser PageGrabber -lcurl)
