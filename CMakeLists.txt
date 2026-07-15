cmake_minimum_required(VERSION 3.11)
project(online_quiz LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/raylib)
add_subdirectory(vendor/libuv)

add_executable(${PROJECT_NAME} src/main.c src/draw.c src/init.c src/update.c src/utils.c
src/button.c src/cleanup.c src/scene.c src/networking.c)

# default compile options
target_compile_options(online_quiz PRIVATE -Wall -Wextra -Wpedantic)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
# extra compile and link options added for the Debug mode
target_compile_options(online_quiz PRIVATE -fsanitize=address)
target_link_options(online_quiz PRIVATE -fsanitize=address)
endif()

target_link_libraries(${PROJECT_NAME} raylib uv_a)
