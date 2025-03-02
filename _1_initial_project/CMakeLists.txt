cmake_minimum_required (VERSION 3.20)
project (OpenGL_tutor)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

include(cmake/3rd_party.cmake)

add_subdirectory(tutor)
