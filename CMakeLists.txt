cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE DEBUG)

set(PROJECT_NAME wip_game)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.c
)
set(PROJECT_LIBRARIES_DIR libs)
set(PROJECT_LIBRARIES
    GOOM
)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

foreach(LIBRARY ${PROJECT_LIBRARIES})
    add_subdirectory("${PROJECT_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} SDL2)
