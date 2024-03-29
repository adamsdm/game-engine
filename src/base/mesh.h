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
  Mesh(const Geometry::GeometryI& geometry, const Material::MaterialI& material);
  ~Mesh();

  void setPosition(float x, float y, float z);
  void setRotation(float angle, float x, float y, float z);

  glm::vec3 getPosition() const;
  glm::vec4 getRotation() const;

  void render(const Camera::CameraI& cam) const;

 private:
  glm::vec3 m_position;
  glm::vec4 m_rotation;
  glm::vec3 m_scale;

  unsigned int m_VBO;
  unsigned int m_VAO;
  unsigned int m_EBO;
  std::vector<Vertex> m_vertices;
  std::vector<unsigned int> m_indices;
  std::vector<Texture> m_textures;

  const Geometry::GeometryI& m_geometry;
  const Material::MaterialI& m_material;

  glm::mat4 calculateModelMatrix() const;
};

};  // namespace GE

#endif /* GE_GEOMETRY_H */
