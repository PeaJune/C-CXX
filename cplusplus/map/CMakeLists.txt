cmake_minimum_required(VERSION 2.8)

project(test)

set(Map_version_major 1)
set(Map_version_minor 9.1)

message("build start...")
message("binary: ${PROJECT_BINARY_DIR}")

configure_file(
	"${PROJECT_SOURCE_DIR}/src/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(map  ./src/map.cpp)
