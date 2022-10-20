//TODO: Move to some root GE class
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

#include "base/core.h"

int main(){

  GE::AppWindow appWindow(800, 600);  
  GE::Scene scene;
  GE::Renderer renderer(appWindow);

  float WindowRatio = (float)appWindow.Get_Width() / (float)appWindow.Get_Height();
  GE::Camera::PerspectiveCamera camera( 75, WindowRatio, 0.1, 1000);
    
  renderer.Set_Clear_Color(0.1f, 0.1f, 0.1f, 1.0f);
  renderer.Set_Size( appWindow.Get_Width(), appWindow.Get_Height());

  GE::Geometry::PlaneGeometry geometry1(15.0f, 15.0f, 1, 1);
  GE::Material::MeshPhongMaterial material1("resources/textures/grass.jpg");
  GE::Mesh* Plane1 = new GE::Mesh(geometry1, material1);
  Plane1->Set_Rotation(-3.14/2.0, 1.0f, 0.0f, 0.0f);
  Plane1->Set_Position(0.0f, -2.0f, 0.0f);


  GE::Geometry::BoxGeometry geometry3(0.1f, 0.1f, 0.1f);
  GE::Material::MeshPhongMaterial material3("resources/textures/adam.jpg");
  GE::Mesh* Box = new GE::Mesh(geometry3, material3);

  scene.add(Plane1);
  scene.add(Box);

  float time = 0;
  // Game loop
  while(!appWindow.Should_Close()){
    time = glfwGetTime();
    
    Box->Set_Position(2.0f * cos(time), 2.0f * sin(time), 0.0f);
    Box->Set_Rotation(time*3.14, 0.0f, 1.0f, 0.0f);

    renderer.Render(scene, camera);
  }

  delete Plane1;
  delete Box;

  return 0;
}
