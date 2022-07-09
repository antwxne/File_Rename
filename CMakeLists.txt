#Cmake version
cmake_minimum_required(VERSION 3.21)

#Project name
project(Changer_les_noms_des_fichiers_par_date)

#Bin name
set(NAME Changer_les_noms_des_fichiers_par_date)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Flags
set(CMAKE_CXX_FLAGS_RELEASE_INIT -Wall -Wextra)
set(CAKE_CXX_FLAGS_DEBUG_INIT ${CMAKE_CXX_FLAGS_RELEASE_INIT} -ggdb -g3)


if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    message("Defining DEBUG Macro...")
    add_compile_definitions(DEBUG)
endif ()

add_compile_definitions(REPO_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# conan settings
include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS KEEP_RPATHS)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

#includes
include_directories(Sources)

# Server Sources
include(Sources/Sources.cmake)
set(MAIN
        Sources/Main.cpp)
set(SRC ${SRC} Sources/Button.cpp Sources/Button.hpp Sources/InputBox.cpp Sources/InputBox.hpp Sources/RenameClass.cpp Sources/RenameClass.hpp)

# Build
add_executable(${NAME} ${MAIN} ${SRC})
conan_target_link_libraries(${NAME} ${CONAN_LIBS})
