cmake_minimum_required(VERSION 3.11)
project(online_quiz LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/raylib)

add_executable(${PROJECT_NAME} src/main.c src/draw.c src/init.c src/update.c src/utils.c
src/button.c)


target_link_libraries(${PROJECT_NAME} raylib)
