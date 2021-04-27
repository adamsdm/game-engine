//TODO: Move to some root GE class
#define STB_IMAGE_IMPLEMENTATION

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
    
  renderer.Set_Clear_Color(0.1f, 0.1f, 0.1f, 1.0f);
  renderer.Set_Size( appWindow.Get_Width(), appWindow.Get_Height());

  GE::Geometry::BoxGeometry geometry(0.1f, 0.1f, 0.1f);
  GE::Material::MeshPhongMaterial adam_material("resources/textures/adam.jpg");
  GE::Material::MeshPhongMaterial container_material("resources/textures/container.jpg");
  GE::Material::MeshPhongMaterial awesomeface_material("resources/textures/grass.jpg");

  GE::Mesh* Box1 = new GE::Mesh(geometry, adam_material);
  GE::Mesh* Box2 = new GE::Mesh(geometry, container_material);
  GE::Mesh* Box3 = new GE::Mesh(geometry, awesomeface_material);


  Box1->Set_Position(-1.5, 0.0, 0.0);
  Box2->Set_Position( 0.0, 0.0, 0.0);
  Box3->Set_Position( 1.5, 0.0, 0.0);

  scene.add(Box1);
  scene.add(Box2);
  scene.add(Box3);

  float time = 0;
  float rotation_speed = 0.2;
  // Game loop
  while(!appWindow.Should_Close()){
    time = glfwGetTime();
    
    Box1->Set_Rotation(rotation_speed * time*3.14, 0.0f, 1.0f, 0.0f);
    Box2->Set_Rotation(rotation_speed * time*3.14, 0.0f, 1.0f, 0.0f);
    Box3->Set_Rotation(rotation_speed * time*3.14, 0.0f, 1.0f, 0.0f);

    renderer.Render(scene, camera);
  }

  delete Box1;
  delete Box2;
  delete Box3;

  return 0;
}
