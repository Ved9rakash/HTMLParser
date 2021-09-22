
#Creating Parsing STATIC libraries.
add_library(PageGrabber STATIC PageGrabber.cpp ../include/PageGrabber.hpp)
add_library(Parse STATIC Parse.cpp ../include/Parse.hpp)

#main executable
add_executable(Parser HTMLParser.cpp)

#Linking the libraries
target_link_libraries(Parser PageGrabber Parse -lcurl)
