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

  float windowRatio{static_cast<float>(appWindow.getWidth()) /
                    static_cast<float>(appWindow.getHeight())};
  GE::Camera::PerspectiveCamera camera(75, windowRatio, 0.1, 1000);

  renderer.setClearColor(0.1F, 0.1F, 0.1F, 1.0F);
  renderer.setSize(appWindow.getWidth(), appWindow.getHeight());

  GE::Geometry::BoxGeometry geometry(0.1F, 0.1F, 0.1F);
  GE::Material::MeshPhongMaterial adamMaterial("resources/textures/adam.jpg");
  GE::Material::MeshPhongMaterial containerMaterial(
      "resources/textures/container.jpg");
  GE::Material::MeshPhongMaterial grassMaterial("resources/textures/grass.jpg");

  auto adamBox{std::make_shared<GE::Mesh>(geometry, adamMaterial)};
  auto containerBox{std::make_shared<GE::Mesh>(geometry, containerMaterial)};
  auto grassBox{std::make_shared<GE::Mesh>(geometry, grassMaterial)};

  adamBox->setPosition(-1.5, 0.0, 0.0);
  containerBox->setPosition(0.0, 0.0, 0.0);
  grassBox->setPosition(1.5, 0.0, 0.0);

  auto model{
      std::make_shared<GE::Model>("resources/objects/backpack/backpack.obj")};

  scene.add(adamBox);
  scene.add(containerBox);
  scene.add(grassBox);
  scene.add(model);

  float time{0};
  float rotationSpeed{0.2};

  // Main loop
  while (!appWindow.shouldClose()) {
    time = glfwGetTime();

    adamBox->setRotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    containerBox->setRotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    grassBox->setRotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);

    renderer.render(scene, camera);
  }
}
