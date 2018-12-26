
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
    
  renderer.Set_Clear_Color(0.1f, 0.1f, 0.1f, 1.0f);
  renderer.Set_Size( appWindow.Get_Width(), appWindow.Get_Height());

  GE::Geometry::PlaneGeometry geometry1(1.5f, 0.2f);
  GE::Material::MeshBasicMaterial material1(1.0f, 0.0f, 0.0f);


  GE::Geometry::PlaneGeometry geometry2(0.2f, 1.5f);
  GE::Material::MeshBasicMaterial material2(1.0f, 0.0f, 0.0f);

  GE::Mesh cube1(geometry1, material1);
  GE::Mesh cube2(geometry2, material2);

  
  scene.add(cube1);
  scene.add(cube2);

  // Game loop
  while(!appWindow.Should_Close()){

    renderer.Render(scene, camera);
  }

  return 0;
}
