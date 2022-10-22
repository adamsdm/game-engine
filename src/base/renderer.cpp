
#include "renderer.h"

namespace GE {

Renderer::Renderer(AppWindow window)
    : m_window(window.get()), m_clear_color(0.0f), m_width(0), m_height(0) {}

Renderer::~Renderer() {}

void Renderer::setClearColor(float red, float green, float blue, float alpha) {
  m_clear_color.r = red;
  m_clear_color.g = green;
  m_clear_color.b = blue;
  m_clear_color.a = alpha;
};

void Renderer::setSize(const unsigned int width, const unsigned int height) {
  m_width = width;
  m_height = width;
}

// TODO These should probably be const refs
void Renderer::render(Scene scene, Camera::CameraI& cam) {
  glClearColor(m_clear_color.r, m_clear_color.g, m_clear_color.b,
               m_clear_color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Change to for-each loop
  for (int i = 0; i < scene.getMeshes().size(); i++) {
    scene.getMeshes()[i]->render(cam);
  }

  glfwSwapBuffers(m_window);
  glfwPollEvents();
}

}  // namespace GE
