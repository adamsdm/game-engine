
#include "perspective_camera.h"

namespace GE {
namespace Camera {

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near,
                                     float far)
    : m_fov(fov),
      m_aspect(aspect),
      m_near(near),
      m_far(far),
      m_cam_pos(0.0f, 0.0f, 3.0f),
      m_cam_front(0.0f, 0.0f, -1.0f),
      m_cam_up(0.0f, 1.0f, 0.0f) {
  calculateProjectionMatrix();
  calculateViewMatrix();
}

PerspectiveCamera::~PerspectiveCamera() = default;

glm::mat4 PerspectiveCamera::getProjectionMatrix() const {
  return m_cam_projection_matrix;
}

glm::mat4 PerspectiveCamera::getViewMatrix() const {
  return m_cam_view_matrix;
}

glm::vec3 PerspectiveCamera::getPosition() const {
  return m_cam_pos;
}

void PerspectiveCamera::setPosition(const glm::vec3& newPos) {
  m_cam_pos.x = newPos.x;
  m_cam_pos.y = newPos.y;
  m_cam_pos.z = newPos.z;

  calculateViewMatrix();
}

void PerspectiveCamera::calculateViewMatrix() {
  m_cam_view_matrix = glm::lookAt(m_cam_pos, m_cam_pos + m_cam_front, m_cam_up);
}

void PerspectiveCamera::calculateProjectionMatrix() {
  m_cam_projection_matrix =
      glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
}

}  // namespace Camera
}  // namespace GE
