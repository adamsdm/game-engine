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
  GE::Material::MeshPhongMaterial containerMaterial(
      "resources/textures/container2.png");
  containerMaterial.addSpecularMap("resources/textures/container2_specular.png");
  auto containerBox{std::make_shared<GE::Mesh>(geometry, containerMaterial)};
  containerBox->setPosition(0.0, 0.0, 0.0);

  scene.add(containerBox);

  float time{0};
  float rotationSpeed{0.2};

  // Main loop
  while (!appWindow.shouldClose()) {
    time = glfwGetTime();
    containerBox->setRotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    renderer.render(scene, camera);
  }
}
