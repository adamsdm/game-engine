

#ifndef GE_MESH_H
#define GE_MESH_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <vector>

#include "camera.h"
#include "ge_types.h"
#include "geometry.h"
#include "material.h"

namespace GE {

class Mesh {
 public:
  Mesh(const Geometry::Geometry_I& geometry, Material::Material_I& material);
  ~Mesh();

  void Set_Position(float x, float y, float z);
  void Set_Rotation(float angle, float x, float y, float z);

  glm::vec3 Get_Position() const;
  glm::vec4 Get_Rotation() const;

  void Render(Camera::Camera_I& cam) const;

 private:
  // TODO Rename to follow convention m_variable name
  glm::vec3 Position;
  glm::vec4 Rotation;
  glm::vec3 Scale;

  unsigned int VBO;
  unsigned int VAO;
  unsigned int EBO;
  std::vector<Vertex> Vertices;
  std::vector<unsigned int> Indices;
  std::vector<Texture> Textures;

  const Geometry::Geometry_I& m_geometry;
  Material::Material_I& m_material;
};

};  // namespace GE

#endif /* GE_GEOMETRY_H */
