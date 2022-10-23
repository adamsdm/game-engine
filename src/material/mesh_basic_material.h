
#ifndef GE_MESH_BASIC_MATERIAL_H
#define GE_MESH_BASIC_MATERIAL_H

#include <glad/glad.h>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "utilities.h"

#include "material.h"

namespace GE {
namespace Material {
class MeshBasicMaterial : public MaterialI {
 public:
  MeshBasicMaterial(float r, float g, float b, float a);
  MeshBasicMaterial(std::string texture_path);
  ~MeshBasicMaterial();

  void prepareForRender(const Camera::CameraI& cam,
                        const glm::mat4& modelMatrix) override;
  void addSpecularMap(const std::string& specular_texture_path);

 private:
  // TODO Raw ptrs
  const char* m_vert_shader_source;
  const char* m_frag_shader_source;
  int m_program_id;

  unsigned int m_diffuse_texture{0};
  unsigned int m_specular_texture{0};

  glm::vec4 m_color;
};
}  // namespace Material
}  // namespace GE

#endif /* GE_MESH_BASIC_MATERIAL_H */
