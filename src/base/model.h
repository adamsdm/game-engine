#ifndef GE_MODEL_H
#define GE_MODEL_H

#include <glm/glm.hpp>
#include <iostream>
#include <memory>
#include <string>

#include "basic_geometry.h"
#include "camera.h"
#include "ge_types.h"
#include "mesh.h"
#include "mesh_phong_material.h"

namespace tinyobj {
struct shape_t;
struct attrib_t;
}

namespace GE {

// TODO This class has a lot in common with mesh.h, should they implement the same interface?
class Model {
 public:
  Model(const std::string& obj_path, const std::string& mtl_search_path);
  ~Model();

  void setPosition(float x, float y, float z);
  void setRotation(float angle, float x, float y, float z);

  glm::vec3 getPosition() const;
  glm::vec4 getRotation() const;

  void render(const Camera::CameraI& cam) const;

 private:
  glm::vec3 m_position;
  glm::vec4 m_rotation;
  glm::vec3 m_scale;

  std::vector<std::unique_ptr<GE::Geometry::BasicGeometry>> m_upGeometries;
  std::vector<std::unique_ptr<GE::Material::MeshPhongMaterial>> m_upMaterials;
  std::vector<Mesh> m_meshes;

  void loadModel(const std::string& obj_path,
                 const std::string& mtl_search_path);
  std::vector<unsigned int> setupIndiceVec(const tinyobj::shape_t& shape);
  std::vector<GE::Vertex> setupVertices(const tinyobj::shape_t& shape, const tinyobj::attrib_t& attrib);
};

};  // namespace GE

#endif /* GE_MODEL_H */
