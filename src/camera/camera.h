
#ifndef GE_CAMERA_I_H
#define GE_CAMERA_I_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

namespace GE {
namespace Camera {

// TODO Rename interface
class Camera_I {
 public:
  virtual ~Camera_I() = default;
  virtual glm::mat4 Get_View_Matrix() const = 0;
  virtual glm::mat4 Get_Projection_Matrix() const = 0;
  virtual glm::vec3 Get_Position() const = 0;

  virtual void Set_Position(glm::vec3 New_Position) = 0;
};
}  // namespace Camera
}  // namespace GE

#endif /* GE_GEOMETRY_H */
