cmake_minimum_required(VERSION 3.0)
project(pricing)

set(CMAKE_CXX_STANDARD 17)
set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)

include_directories(include)

add_library(lib_matching_market SHARED ${SRC_PATH}/matching_market.cpp)
add_executable(price ${SRC_PATH}/main.cpp)

target_link_libraries(price lib_matching_market)