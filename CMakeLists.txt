cmake_minimum_required(VERSION 3.10)
project(CppApiScanner)

set(CMAKE_CXX_STANDARD 17)

# Wyszukiwanie libcurl
find_package(CURL REQUIRED)

include_directories(include)

add_executable(CppApiScanner src/main.cpp src/Scanner.cpp)
target_link_libraries(CppApiScanner ${CURL_LIBRARIES})
