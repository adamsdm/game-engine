
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
  GE::Material::MeshBasicMaterial material1(1.0f, 0.0f, 0.0f, 1.0f);
  GE::Mesh* Plane1 = new GE::Mesh(geometry1, material1);

  GE::Geometry::PlaneGeometry geometry2(0.2f, 1.5f);
  GE::Material::MeshBasicMaterial material2(0.0f, 1.0f, 0.0f, 1.0f);
  GE::Mesh* Plane2 = new GE::Mesh(geometry2, material2);

  GE::Geometry::BoxGeometry geometry3(0.1f, 0.1f, 0.1f);
  GE::Material::MeshPhongMaterial material3(0.0f, 0.0f, 1.0f, 1.0f);

  GE::Mesh* Box = new GE::Mesh(geometry3, material3);

  Box->Set_Position(1.5f, 0.0f, 0.0f);

  scene.add(Plane1);
  scene.add(Plane2);
  scene.add(Box);

  // Game loop
  while(!appWindow.Should_Close()){

	Plane1->Set_Rotation((float) glm::radians(10.0f), 1.0f, 0.0f, 0.0f);
	Plane2->Set_Rotation((float) glm::radians(10.0f), 1.0f, 0.0f, 1.0f);
	Box->Set_Rotation((float) glm::radians(10.0f), 1.0f, 0.0f, 0.5f);

    renderer.Render(scene, camera);
  }

  delete Plane1;
  delete Plane2;

  return 0;
}
