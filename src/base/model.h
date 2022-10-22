#ifndef GE_MODEL_H
#define GE_MODEL_H

#include <glm/glm.hpp>
#include <iostream>
#include <string>

#include "camera.h"
#include "ge_types.h"
#include "mesh.h"

namespace GE {

// TODO This class has a lot in common with mesh.h, should they implement the same interface?
class Model {
 public:
  Model(std::string path_to_model);
  ~Model();

  void setPosition(float x, float y, float z);
  void setRotation(float angle, float x, float y, float z);

  glm::vec3 getPosition() const;
  glm::vec4 getRotation() const;

  void render(Camera::CameraI& cam) const;

 private:
  glm::vec3 m_position;
  glm::vec4 m_rotation;
  glm::vec3 m_scale;
  std::vector<Mesh> m_meshes;
  std::vector<Texture> m_textures;

  void loadModel(std::string path);
};

};  // namespace GE

#endif /* GE_MODEL_H */
