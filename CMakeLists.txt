cmake_minimum_required(VERSION 3.15)

project(7zx LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SRC_FILES})

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})