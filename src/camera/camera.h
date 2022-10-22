
#ifndef GE_CAMERA_I_H
#define GE_CAMERA_I_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

namespace GE {
namespace Camera {

class CameraI {
 public:
  virtual ~CameraI() = default;
  virtual glm::mat4 getViewMatrix() const = 0;
  virtual glm::mat4 getProjectionMatrix() const = 0;
  virtual glm::vec3 getPosition() const = 0;

  virtual void setPosition(const glm::vec3& newPosition) = 0;
};
}  // namespace Camera
}  // namespace GE

#endif /* GE_GEOMETRY_H */
