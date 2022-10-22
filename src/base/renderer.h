#ifndef GE_RENDERER_H
#define GE_RENDERER_H

// clang-format off
// These includes have to be included in this order.
// Clang format will try to rearrange them
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <glm/glm.hpp>

#include "app_window.h"
#include "perspective_camera.h"
#include "scene.h"

namespace GE {

class Renderer {
 public:
  Renderer(AppWindow window);
  ~Renderer();

  void setClearColor(float red, float green, float blue, float alpha);
  void setSize(unsigned int width, unsigned int height);

  void render(const Scene& scene, const Camera::CameraI& cam);

 private:
  GLFWwindow* m_window;
  glm::vec4 m_clear_color;
  unsigned int m_width;
  unsigned int m_height;
};

}  // namespace GE

#endif /* RENDERER */
