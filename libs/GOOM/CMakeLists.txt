cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME GOOM_Engine)
set(LIBRARY_NAME GOOM)
set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)
set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/I_Application.h
    ${LIBRARY_HEADERS_DIR}/R_Renderer.h
)
set(LIBRARY_SOURCE_DIR src)
set(LIBRARY_SOURCES
    ${LIBRARY_SOURCE_DIR}/I_Application.c
    ${LIBRARY_SOURCE_DIR}/R_Renderer.c
)
project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)