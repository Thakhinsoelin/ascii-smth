cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions(-D_WIN32_WINNT=0x0A00)

find_package(fmt CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)

add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PRIVATE fmt::fmt Crow::Crow)