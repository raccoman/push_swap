cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_CXX_STANDARD 89)

include_directories(headers)
include_directories(libraries/libft)

set(LINK_LIBRARIES ${CMAKE_SOURCE_DIR}/libraries)

set(SRC
		sources/operations.c
		sources/sorting.c
		sources/utils.c
		sources/utils_2.c
		sources/sorting_utils.c
		sources/sort_n_utils.c
		sources/bonus.c
)

add_executable(checker checker.c ${SRC})
add_executable(push_swap push_swap.c ${SRC})

target_link_libraries(checker ${LINK_LIBRARIES}/libft/libft.a)
target_link_libraries(push_swap ${LINK_LIBRARIES}/libft/libft.a)