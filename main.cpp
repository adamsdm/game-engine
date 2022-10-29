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

  appWindow.addKeyEventCallback(
      [&appWindow](int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
          appWindow.close();
        }
      });

  float windowRatio{static_cast<float>(appWindow.getWidth()) /
                    static_cast<float>(appWindow.getHeight())};

  GE::Camera::PerspectiveCamera camera(75, windowRatio, 0.1, 1000);
  appWindow.addResizeEventCallback([&camera](int width, int height) {
    float windowRatio{static_cast<float>(width) / static_cast<float>(height)};
    camera.setAspectRatio(windowRatio);
  });

  renderer.setClearColor(0.1F, 0.1F, 0.1F, 1.0F);
  renderer.setSize(appWindow.getWidth(), appWindow.getHeight());

  GE::Geometry::BoxGeometry geometry(0.1F, 0.1F, 0.1F);
  GE::Material::MeshPhongMaterial containerMaterial(
      "resources/textures/container2.png");
  containerMaterial.addSpecularMap(
      "resources/textures/container2_specular.png");
  auto containerBox{std::make_shared<GE::Mesh>(geometry, containerMaterial)};
  containerBox->setPosition(1.5, 0.0, 0.0);

  auto model{std::make_shared<GE::Model>("resources/objects/f16/f16.obj",
                                         "resources/objects/f16/")};

  scene.add(containerBox);
  scene.add(model);

  float time{0};
  float rotationSpeed{0.2};

  // Main loop
  while (!appWindow.shouldClose()) {
    time = glfwGetTime();
    containerBox->setRotation(rotationSpeed * time * 3.14, 0.0F, 1.0F, 0.0F);
    model->setRotation(rotationSpeed * time * 3.14, 0.0, 1.0, 0.0);
    renderer.render(scene, camera);
  }
}
