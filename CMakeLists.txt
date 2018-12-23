
cmake_minimum_required(VERSION 3.0.0)

# Project definitions
project(game-eng    VERSION 0.0.0)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(GLM_DIR     ${EXT_DIR}/glm)
set(GLFW_DIR    ${EXT_DIR}/glfw)
set(GLAD_DIR    ${EXT_DIR}/glad)


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

### EXECUTABLE
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}   glfw 
                                        glad 
                                        glm_static)

