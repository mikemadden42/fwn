cmake_minimum_required(VERSION 2.8)

project(fwn C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

add_library(utils STATIC
  interfaces.c
)

add_executable(fwn
  main.c
)

target_link_libraries(fwn
  utils
)
