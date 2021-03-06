cmake_minimum_required (VERSION 3.12.4) # Set min. cmake version
project (main) # Name of project 

file (GLOB SOURCES_CPP "src/*.cpp")
file (GLOB HEADER_CPP "include/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES_CPP}) # Compile file's
message("${CMAKE_CURRENT_SOURCE_DIR}/include)")
message("${PROJECT_SOURCE_DIR}/include)")

# Add my libs
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add libcurl
FIND_PACKAGE(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CURL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})

# Add curlpp
include_directories(${PROJECT_NAME} "/usr/include/curlpp")
target_link_libraries(${PROJECT_NAME} PUBLIC "/usr/lib64/libcurlpp.so")

# Set compile options
set_target_properties(PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
