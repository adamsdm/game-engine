#define STB_IMAGE_IMPLEMENTATION

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

  void Set_Position(float x, float y, float z);
  void Set_Rotation(float angle, float x, float y, float z);

  glm::vec3 Get_Position() const;
  glm::vec4 Get_Rotation() const;

  void Render(Camera::Camera_I& cam) const;

 private:
 // TODO Rename to follow convention m_variable_name
  glm::vec3 Position;
  glm::vec4 Rotation;
  glm::vec3 Scale;
  std::vector<Mesh> Meshes;
  std::vector<Texture> Textures;

  void Load_Model(std::string path);
};

};  // namespace GE

#endif /* GE_MODEL_H */
