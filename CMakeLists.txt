#Cmake version
cmake_minimum_required(VERSION 3.21)

#Project name
project(Template)

#Bin name
set(NAME a.out)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Flags
set(CMAKE_CXX_FLAGS_RELEASE_INIT -Wall -Wextra)
set(CAKE_CXX_FLAGS_DEBUG_INIT ${CMAKE_CXX_FLAGS_RELEASE_INIT} -ggdb -g3)


if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message("Defining DEBUG Macro...")
    add_compile_definitions(DEBUG)
endif ()


# conan settings
include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Change output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/)

#includes
include_directories(Sources)

# Server Sources
include(Sources/Sources.cmake)
set(MAIN
        Sources/Main.cpp Sources/Main.cpp)
set(SRC ${SRC} )

# Build
add_executable(${NAME} ${MAIN} ${SRC})
conan_target_link_libraries(${NAME} ${CONAN_LIBS})

# Use external repository
#include(ExternalProject)
#
#ExternalProject_Add(
#        external
#        GIT_REPOSITORY https://github.com/
#        GIT_TAG ""
#        INSTALL_COMMAND ""
#        TEST_COMMAND ""
#)
#
#add_dependencies(${NAME} external)
#ExternalProject_Get_Property(ziapi external)
#include_directories(${SOURCE_DIR}/include)

# Unit tests
include(Tests/Tests.cmake)