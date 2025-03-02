cmake_minimum_required (VERSION 3.20)
project (tutor)

#set(INCLUDE_DIR ./)
#include_directories(${INCLUDE_DIR})
#include_directories (.)

include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

include_directories(${SDL2_INCLUDE_DIR})
link_libraries(${SDL2_LIBRARY})
link_libraries(${SDL2main_LIBRARY})

include_directories(${SDL2_IMG_INCLUDE_DIR})
link_libraries(${SDL2_IMG_LIBRARY})

add_executable(tutor main.cpp)

# Creates a folder "executables" and adds target 
# project (app.vcproj) under it
#set_property(TARGET tutor PROPERTY FOLDER "executables")

# Properties->General->Output Directory
#set_target_properties(tutor PROPERTIES
#                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
					  
#install (TARGETS tutor
#         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install)

include(../cmake/shaders_n_runtimelibs.cmake)