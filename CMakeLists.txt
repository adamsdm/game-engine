
# Project definitions
cmake_minimum_required(VERSION 3.0.0)
project(game_engine_test    VERSION 0.0.0)

set(CMAKE_BUILD_TYPE Debug)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    message(FATAL_ERROR "ERROR::In source build prohibited, please specify different build directory")
endif(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})



set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(GLM_DIR     ${EXT_DIR}/glm)
set(GLFW_DIR    ${EXT_DIR}/glfw)
set(GLAD_DIR    ${EXT_DIR}/glad)
set(STB_DIR     ${EXT_DIR}/stb)

### EXTERNALS
# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${GLFW_DIR})

# glad
add_subdirectory(${GLAD_DIR})

# glm
add_subdirectory(${GLM_DIR})
include_directories(${GLM_DIR})

#stb
include_directories(${STB_DIR})

### GAME ENGINE LIBRARY
set(GE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${GE_SRC_DIR})

# TODO Can these be picked using wildcards? I.e dir/*.cpp
# TODO Create several CMakelists?w
# Base sources
set(GE_CORE_BASE_SOURCES    ${GE_SRC_DIR}/base/app_window.cpp
                            ${GE_SRC_DIR}/base/mesh.cpp
                            ${GE_SRC_DIR}/base/renderer.cpp
                            ${GE_SRC_DIR}/base/scene.cpp
                            ${GE_SRC_DIR}/base/model.cpp)
# Camera sources
set(GE_CORE_CAMERA_SOURCES  ${GE_SRC_DIR}/camera/camera.cpp    
							${GE_SRC_DIR}/camera/perspective_camera.cpp)

# Geometry sources
set(GE_CORE_GEOMETRY_SOURCES    ${GE_SRC_DIR}/geometry/plane_geometry.cpp
								${GE_SRC_DIR}/geometry/box_geometry.cpp)

# Material sources
set(GE_CORE_MATERIAL_SOURCES    ${GE_SRC_DIR}/material/material.cpp
								${GE_SRC_DIR}/material/mesh_basic_material.cpp
								${GE_SRC_DIR}/material/mesh_phong_material.cpp)

# Utilities sources
set(GE_CORE_UTILITIES_SOURCES   ${GE_SRC_DIR}/utilities/utilities.cpp)

# Add sources to library 'game_engine'
add_library(game_engine     ${GE_CORE_BASE_SOURCES}
                            ${GE_CORE_CAMERA_SOURCES}
                            ${GE_CORE_GEOMETRY_SOURCES}
                            ${GE_CORE_MATERIAL_SOURCES}
                            ${GE_CORE_UTILITIES_SOURCES})

# Add include directory to library 'game_engine'
set(GE_INCLUDE_DIRECTORIES  src/base
                            src/camera
                            src/geometry
                            src/material
                            src/utilities/)

# copy resource folder on each 'make'
add_custom_target(copy_res_directory ALL
COMMAND ${CMAKE_COMMAND} -E copy_directory 
    "${CMAKE_SOURCE_DIR}/resources" "${CMAKE_BINARY_DIR}/resources"
COMMENT "Copy res directory to build tree"
VERBATIM)

add_dependencies(game_engine copy_res_directory)

target_include_directories(game_engine PUBLIC   ${GE_INCLUDE_DIRECTORIES})
# Link libraries to library 'game_engine'
target_link_libraries(game_engine   glfw 
                                    glad 
                                    glm_static)


### TEST EXECUTABLE
# This executable is intended to be used to test the framework
# Functionality is implemented in 'src/main.cpp'
add_executable(${PROJECT_NAME}  main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${GE_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME}   game_engine
                                        glfw 
                                        glad 
                                        glm_static)

