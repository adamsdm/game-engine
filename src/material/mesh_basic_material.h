
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

  // TODO These are common for all materials, move too base class?
  int getProgramId() const override;
  void updateUniforms() const override;
  void bindTextures() const override;
  void setViewMatrix(glm::mat4 view_matrix) override;
  void setViewPos(glm::vec3 view_pos) override;
  void setProjectionMatrix(glm::mat4 projection_matrix) override;
  void setModelMatrix(glm::mat4 model_matrix) override;

 private:
 // TODO Raw ptrs
  const char* m_vert_shader_source;
  const char* m_frag_shader_source;
  int m_program_id;

  unsigned int m_texture;

  glm::vec4 m_color;
};
}  // namespace Material
}  // namespace GE

#endif /* GE_MESH_BASIC_MATERIAL_H */
