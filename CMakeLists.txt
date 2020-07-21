cmake_minimum_required(VERSION 3.10)

project(CnC_Remastered CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(mixtool)
add_subdirectory(REDALERT)
add_subdirectory(TIBERIANDAWN)
