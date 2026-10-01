cmake_minimum_required(VERSION 3.15)

project(7zx LANGUAGES C)

# The LZMA SDK sources are unmodified and include "7zTypes.h" directly
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/7zx)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SRC_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE Z7_PPMD_SUPPORT Z7_EXTRACT_ONLY)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
