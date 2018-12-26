
#include <stdio.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

#include "core.h"

int main(){

  GE::AppWindow appWindow(800, 600);  
  GE::Scene scene;
  GE::Renderer renderer(appWindow);
  
  float WindowRatio = (float)appWindow.Get_Width() / (float)appWindow.Get_Height();
  GE::Camera::PerspectiveCamera camera( 75, WindowRatio, 0.1, 1000);
  camera.Set_Position(glm::vec3(0.0f, 0.0f, 4.0f));
    
  renderer.Set_Clear_Color(1.0f, 0.0f, 0.0f, 1.0f);
  renderer.Set_Size( appWindow.Get_Width(), appWindow.Get_Height());

  /**
   *  TODO: Add interfaces for these classes which subclasses should inherit
   *    Geometry_I interface
   *    Material_I interface
   */
  GE::Geometry::BoxGeometry geometry( 1, 1, 1 );
  GE::Material::MeshBasicMaterial material(1.0f, 0.0f, 0.0f);

  
  //GE::Mesh cube = new GE::Mesh(geometry, material);

  // scene.add(cube);
  // Game loop

  float Time = glfwGetTime();

  while(!appWindow.Should_Close()){

    renderer.Render();
  }

  return 0;
}