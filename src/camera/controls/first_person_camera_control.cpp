#include "first_person_camera_control.h"

#include <iostream>

namespace GE {
namespace Camera {
namespace Controls {

FirstPersonCameraControl::FirstPersonCameraControl(GE::Camera::CameraI& cam,
                                                   GE::AppWindow& window,
                                                   float cameraSpeed)
    : m_cam(cam),
      m_window(window),
      m_cameraSpeed(cameraSpeed),
      m_firstMouse(true),
      m_yaw(-90.0f),
      m_pitch(0.0f) {
  m_window.addMousePosEventCallback(
      [this](int xpos, int ypos) { onMouseMovement(xpos, ypos); });

  glfwSetInputMode(m_window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  m_mouseDisabled = true;
}

FirstPersonCameraControl::~FirstPersonCameraControl() = default;

void FirstPersonCameraControl::update(float deltaTime) {
  auto cameraPos{m_cam.getPosition()};
  auto cameraFront{m_cam.getFrontDirection()};
  auto cameraUp{m_cam.getUpDirection()};

  float movementSpeed{m_cameraSpeed * deltaTime};

  if (glfwGetKey(m_window.get(), GLFW_KEY_A) == GLFW_PRESS) {
    cameraPos -=
        glm::normalize(glm::cross(cameraFront, cameraUp)) * movementSpeed;
  }
  if (glfwGetKey(m_window.get(), GLFW_KEY_D) == GLFW_PRESS) {
    cameraPos +=
        glm::normalize(glm::cross(cameraFront, cameraUp)) * movementSpeed;
  }
  if (glfwGetKey(m_window.get(), GLFW_KEY_W) == GLFW_PRESS) {
    cameraPos += cameraFront * movementSpeed;
  }
  if (glfwGetKey(m_window.get(), GLFW_KEY_S) == GLFW_PRESS) {
    cameraPos -= cameraFront * movementSpeed;
  }
  if (glfwGetKey(m_window.get(), GLFW_KEY_SPACE) == GLFW_PRESS) {
    cameraPos += cameraUp * movementSpeed;
  }
  if (glfwGetKey(m_window.get(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
    cameraPos -= cameraUp * movementSpeed;
  }
  m_cam.setPosition(cameraPos);
}

void FirstPersonCameraControl::onMouseMovement(float xpos, float ypos) {

  if (m_firstMouse) {
    m_lastX = xpos;
    m_lastY = ypos;
    m_firstMouse = false;
  }

  float xoffset = xpos - m_lastX;
  float yoffset = m_lastY - ypos;
  m_lastX = xpos;
  m_lastY = ypos;

  float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  m_yaw += xoffset;
  m_pitch += yoffset;

  if (m_pitch > 89.0f)
    m_pitch = 89.0f;
  if (m_pitch < -89.0f)
    m_pitch = -89.0f;

  glm::vec3 direction;
  direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
  direction.y = sin(glm::radians(m_pitch));
  direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

  m_cam.setFrontDirection(glm::normalize(direction));
}

}  // namespace Controls
}  // namespace Camera
}  // namespace GE