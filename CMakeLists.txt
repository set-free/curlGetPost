cmake_minimum_required (VERSION 3.12.4) # Set min. cmake version
project (curlRequest) # Name of project 
add_executable(main main.cpp) # Compile file's

# Add libcurl
FIND_PACKAGE(CURL REQUIRED)
target_link_libraries(main PUBLIC ${CURL_LIBRARIES})
target_include_directories(main PRIVATE ${CURL_INCLUDE_DIRS})

include_directories(main "/usr/include/curlpp")
target_link_libraries(main PUBLIC "/usr/lib64/libcurlpp.so")

# Set compile options
set_target_properties(PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
