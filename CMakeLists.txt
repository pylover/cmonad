cmake_minimum_required(VERSION 3.7)
project(cmonad 
    VERSION 0.1.0
    LANGUAGES C
)


set(CMAKE_VERBOSE_MAKEFILE OFF)
set(PRJ ${CMAKE_PROJECT_NAME})


# cpack config
set (CPACK_PACKAGE_CONTACT "Vahid Mardani <vahid.mardani@gmail.com>")
set (CPACK_DEBIAN_PACKAGE_DEPENDS "clog")


# cmake libs
include(cmake/build.cmake)
include(cmake/menu.cmake)
include(cmake/lint.cmake)
include(cmake/valgrind.cmake)
include(cmake/cpack.cmake)
include(cmake/install.cmake)


# cc flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE=1")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_POSIX_C_SOURCE=199309L")


include_directories(
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_BINARY_DIR}/src
)


add_subdirectory(src)


# test
enable_testing()
add_subdirectory(tests)
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
