
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

void Initialize_GLFW(){
  
  std::cout << "Initializing GLFW... ";

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    exit(-1);
  }
  // Create a GLFWwindow object that we can use for GLFW's functions
  GLFWwindow* window = glfwCreateWindow(100,100, "LearnOpenGL", NULL, NULL);

  glfwMakeContextCurrent(window);
  if (window == NULL)
  {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      exit(-1);
  }
  std::cout << "Sucess!" << std::endl;
}

void Initialize_GLAD(){
  std::cout << "Initializing GLAD... ";
  if (!gladLoadGL())
  {
    printf("Something went wrong!\n");
    exit(-1);
  }
  std::cout << "Sucess!" << std::endl;
}

void Initialize_GLM(){
  std::cout << "Testing GLM vec3: ";

  glm::vec3 Temp = glm::vec3(1.0f);

  printf("Vector: {%f, %f, %f}\n", Temp.x, Temp.y, Temp.z);
}

int main(){
  Initialize_GLFW();
  Initialize_GLAD();
  Initialize_GLM();

  return 0;
}