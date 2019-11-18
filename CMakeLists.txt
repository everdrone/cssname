cmake_minimum_required(VERSION 3.10)

# set the project name
project(cssname VERSION "1.1.0")

configure_file(config.h.in config.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(cssname src/main.cc)
target_include_directories(cssname PRIVATE include)
target_include_directories(cssname PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS cssname DESTINATION bin)

add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${PROJECT_SOURCE_DIR}/uninstall.cmake"
)
