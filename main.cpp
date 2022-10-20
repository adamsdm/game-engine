//TODO: Move to some root GE class
#define STB_IMAGE_IMPLEMENTATION

#include <cmath>
#include <cstdio>
#include <glm/glm.hpp>
#include <iostream>

#include "base/core.h"

int main() {
  // TODO Refactor into an app class
  GE::AppWindow app_window(800, 600);
  GE::Scene scene;
  GE::Renderer renderer(app_window);

  float window_ratio = static_cast<float>(app_window.Get_Width()) /
                       static_cast<float>(app_window.Get_Height());
  GE::Camera::PerspectiveCamera camera(75, window_ratio, 0.1, 1000);

  renderer.Set_Clear_Color(0.1F, 0.1F, 0.1F, 1.0F);
  renderer.Set_Size(app_window.Get_Width(), app_window.Get_Height());

  GE::Geometry::BoxGeometry geometry(0.1F, 0.1F, 0.1F);
  GE::Material::MeshPhongMaterial adam_material("resources/textures/adam.jpg");
  GE::Material::MeshPhongMaterial container_material(
      "resources/textures/container.jpg");
  GE::Material::MeshPhongMaterial awesomeface_material(
      "resources/textures/grass.jpg");

  // TODO Raw ptrs
  // TODO Rename aswell
  auto* box1 = new GE::Mesh(geometry, adam_material);
  auto* box2 = new GE::Mesh(geometry, container_material);
  auto* box3 = new GE::Mesh(geometry, awesomeface_material);

  box1->Set_Position(-1.5, 0.0, 0.0);
  box2->Set_Position(0.0, 0.0, 0.0);
  box3->Set_Position(1.5, 0.0, 0.0);

  auto* model = new GE::Model("resources/objects/backpack/backpack.obj");

  scene.add(box1);
  scene.add(box2);
  scene.add(box3);
  scene.add(model);

  float time = 0;
  float rotation_speed = 0.2;
  // Game loop
  while (!app_window.Should_Close()) {
    time = glfwGetTime();

    box1->Set_Rotation(rotation_speed * time * 3.14, 0.0F, 1.0F, 0.0F);
    box2->Set_Rotation(rotation_speed * time * 3.14, 0.0F, 1.0F, 0.0F);
    box3->Set_Rotation(rotation_speed * time * 3.14, 0.0F, 1.0F, 0.0F);

    renderer.Render(scene, camera);
  }

  delete box1;
  delete box2;
  delete box3;
  delete model;

  return 0;
}
