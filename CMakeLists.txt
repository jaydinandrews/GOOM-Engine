cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE DEBUG)

set(PROJECT_NAME wip_game)

# Settings
set(PROJECT_DATA_DIR data)
set(PROJECT_DATA
  ${PROJECT_DATA_DIR}/settings.h
)

# Sources
set(PROJECT_SOURCE_DIR src)
set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.c
)

# Libraries
set(PROJECT_LIBRARIES_DIR lib)
set(PROJECT_LIBRARIES
  GOOM
)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCES}
  ${PROJECT_DATA}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_DATA_DIR})

foreach(LIBRARY ${PROJECT_LIBRARIES})
    add_subdirectory("${PROJECT_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} SDL2)