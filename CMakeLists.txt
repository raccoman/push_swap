cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_CXX_STANDARD 89)

include_directories(headers)

set(LINK_LIBRARIES ${CMAKE_SOURCE_DIR}/libraries)
set(SRCS
        )

add_executable(${PROJECT_NAME} main.c ${SRCS})