#include "app_window.h"

#include <iostream>

namespace GE {

AppWindow::AppWindow(unsigned int width, unsigned int Height)
    : m_width(width), m_height(Height) {
  if (!glfwInit()) {
    std::cerr << "ERROR:: Failed to initialize GLFW" << std::endl;
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(
      GLFW_OPENGL_FORWARD_COMPAT,
      GL_TRUE);  // uncomment this statement to fix compilation on OS X
#endif

  m_window = glfwCreateWindow(m_width, m_height, "Simple example", nullptr, nullptr);
  if (!m_window) {
    glfwTerminate();
    std::cerr << "ERROR:: Failed to create GLFW window" << std::endl;
    exit(EXIT_FAILURE);
  }
  glfwSetKeyCallback(m_window, KeyCallback);
  glfwSetErrorCallback(ErrorCallback);
  glfwMakeContextCurrent(m_window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSwapInterval(1);

  // Configure global opengl state
  glEnable(GL_DEPTH_TEST);
}

AppWindow::~AppWindow() = default;

GLFWwindow* AppWindow::get() {
  return m_window;
}

unsigned int AppWindow::getWidth() const {
  return m_width;
}
unsigned int AppWindow::getHeight() const {
  return m_height;
}

bool AppWindow::shouldClose() {
  return glfwWindowShouldClose(m_window) != 0;
}

void AppWindow::ErrorCallback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

void AppWindow::KeyCallback(GLFWwindow* window, int key, int scancode,
                            int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  if (key == GLFW_KEY_E && action == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  } else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }
}

}  // namespace GE
