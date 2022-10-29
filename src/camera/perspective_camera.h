#ifndef GE_CAMERA_H
#define GE_CAMERA_H

#include <camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace GE {
namespace Camera {

class PerspectiveCamera : public CameraI {
 public:
  PerspectiveCamera(float fov, float aspect, float near, float far);
  ~PerspectiveCamera();

  void setPosition(const glm::vec3& newPos) override;
  glm::mat4 getViewMatrix() const override;
  glm::mat4 getProjectionMatrix() const override;

  glm::vec3 getPosition() const override;
  glm::vec3 getFrontDirection() const override;
  glm::vec3 getUpDirection() const override;

  void setFrontDirection(const glm::vec3& dir) override;
  void setAspectRatio(float aspect);

 private:
  void calculateViewMatrix();
  void calculateProjectionMatrix();

  float m_fov;
  float m_aspect;
  float m_near;
  float m_far;

  glm::vec3 m_cam_pos;
  glm::vec3 m_cam_front;
  glm::vec3 m_cam_up;

  glm::mat4 m_cam_view_matrix;
  glm::mat4 m_cam_projection_matrix;
};

}  // namespace Camera
}  // namespace GE

#endif /* GE_CAMERA_H */
