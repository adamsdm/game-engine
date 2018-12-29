# Game engine

## Project setup
 
The project depends on GLAD, GLFW and GLM, added as submodules. Thus a recursive git clone is needed: 
 ```
 > git clone --recursive <build folder>
 ```
### Install
* CMake (use out of source build, in source build is ugly af and prohibited)
    * Also make sure to uncheck `GLM_TEST_ENABLE` to avoid getting a lot of annoying glm test targets to your generated project

### Make targets
* Primary make targets:
    * `game_engine` - base game engine target
    * `game_engine_test`- executable which tests framework