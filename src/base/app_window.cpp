#include "app_window.h"

#include <iostream>

namespace GE {

namespace {
void errorCallback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action,
                 int mods) {
  // Notify the user of this window of the keyEvent
  auto* appWindow = static_cast<AppWindow*>(glfwGetWindowUserPointer(window));
  if (appWindow) {
    appWindow->notifyKeySubscribers(key, scancode, action, mods);
  }
}

void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
  // Notify the user of this window of the keyEvent
  auto* appWindow = static_cast<AppWindow*>(glfwGetWindowUserPointer(window));
  if (appWindow) {
    appWindow->notifyMousePosSubscribers(xpos, ypos);
  }
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
  // TODO What if theres multiple windows?
  glViewport(0, 0, width, height);

  // Notify the user of this window of the resize event
  auto* appWindow = static_cast<AppWindow*>(glfwGetWindowUserPointer(window));
  if (appWindow) {
    appWindow->notifyWindowResizeSubscribers(width, height);
  }
}

}  // namespace

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

  m_window =
      glfwCreateWindow(m_width, m_height, "Simple example", nullptr, nullptr);
  if (!m_window) {
    glfwTerminate();
    std::cerr << "ERROR:: Failed to create GLFW window" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Tell opengl that 'this' is the user of the window instance
  // glfwGetWindowUserPointer can then be used to retrieve 'this'
  glfwSetWindowUserPointer(m_window, this);

  // Setup callbacks
  glfwSetErrorCallback(errorCallback);
  glfwSetKeyCallback(m_window, keyCallback);
  glfwSetCursorPosCallback(m_window, mousePosCallback);
  glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);

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

void AppWindow::close() const {
  glfwSetWindowShouldClose(m_window, true);
}

void AppWindow::addKeyEventCallback(const KeyEventCallback& cb) {
  m_keyEventCallbacks.push_back(cb);
}

void AppWindow::addMousePosEventCallback(const MousePosEventCallback& cb) {
  m_mouseEventCallbacks.push_back(cb);
}

void AppWindow::addResizeEventCallback(const ResizeEventCallback& cb) {
  m_resizeEventCallbacks.push_back(cb);
}

void AppWindow::notifyKeySubscribers(int key, int scancode, int action,
                                     int mods) {
  for (auto cb : m_keyEventCallbacks) {
    cb(key, scancode, action, mods);
  }
}

void AppWindow::notifyMousePosSubscribers(int xpos, int ypos) {
  for (auto cb : m_mouseEventCallbacks) {
    cb(xpos, ypos);
  }
}

void AppWindow::notifyWindowResizeSubscribers(int width, int height) {
  for (auto cb : m_resizeEventCallbacks) {
    cb(width, height);
  }
}

bool AppWindow::shouldClose() {
  return glfwWindowShouldClose(m_window) != 0;
}

}  // namespace GE
