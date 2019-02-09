cmake_minimum_required (VERSION 2.6)
project (OpenGL_tutor)

set(INCLUDE_DIR ./)
include_directories(${INCLUDE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
message ("cxx Flags: " ${CMAKE_CXX_FLAGS})

add_subdirectory(tutor)
