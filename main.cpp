//TODO: Move to some root GE class
#define STB_IMAGE_IMPLEMENTATION

#include <cmath>
#include <cstdio>
#include <glm/glm.hpp>
#include <iostream>

#include "base/core.h"

int main() {
  // TODO Refactor into an app class
  GE::AppWindow appWindow(800, 600);
  GE::Scene scene;
  GE::Renderer renderer(appWindow);

  float windowRatio = static_cast<float>(appWindow.Get_Width()) /
                      static_cast<float>(appWindow.Get_Height());
  GE::Camera::PerspectiveCamera camera(75, windowRatio, 0.1, 1000);

  renderer.Set_Clear_Color(0.1F, 0.1F, 0.1F, 1.0F);
  renderer.Set_Size(appWindow.Get_Width(), appWindow.Get_Height());

  GE::Geometry::BoxGeometry geometry(0.1F, 0.1F, 0.1F);
  GE::Material::MeshPhongMaterial adamMaterial("resources/textures/adam.jpg");
  GE::Material::MeshPhongMaterial containerMaterial(
      "resources/textures/container.jpg");
  GE::Material::MeshPhongMaterial awesomefaceMaterial(
      "resources/textures/grass.jpg");

  // TODO Raw ptrs
  // TODO Rename aswell
  auto* box1 = new GE::Mesh(geometry, adamMaterial);
  auto* box2 = new GE::Mesh(geometry, containerMaterial);
  auto* box3 = new GE::Mesh(geometry, awesomefaceMaterial);

  box1->Set_Position(-1.5, 0.0, 0.0);
  box2->Set_Position(0.0, 0.0, 0.0);
  box3->Set_Position(1.5, 0.0, 0.0);

  auto* model = new GE::Model("resources/objects/backpack/backpack.obj");

  scene.add(box1);
  scene.add(box2);
  scene.add(box3);
  scene.add(model);

  float time = 0;
  float rotationSpeed = 0.2;
  // Game loop
  while (!appWindow.Should_Close()) {
    time = glfwGetTime();

    box1->Set_Rotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    box2->Set_Rotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    box3->Set_Rotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);

    renderer.Render(scene, camera);
  }

  delete box1;
  delete box2;
  delete box3;
  delete model;

  return 0;
}
