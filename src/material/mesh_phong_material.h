/*
 * mesh_phone_material.h
 *
 *  Created on: 31 Dec 2018
 *      Author: adamsoderstrom
 */

#ifndef SRC_MATERIAL_MESH_PHONG_MATERIAL_H_
#define SRC_MATERIAL_MESH_PHONG_MATERIAL_H_

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
class MeshPhongMaterial : public MaterialI {
 public:
  MeshPhongMaterial(float r, float g, float b, float a);
  MeshPhongMaterial(std::string texture_path);
  ~MeshPhongMaterial();

  // TODO These are common for all materials, move to base class?
  int getProgramId() const override;
  void updateUniforms() const override;
  void bindTextures() const override;
  void setViewMatrix(glm::mat4 view_matrix) override;
  void setViewPos(glm::vec3 view_pos) override;
  void setProjectionMatrix(glm::mat4 projection_matrix) override;
  void setModelMatrix(glm::mat4 model_matrix) override;

 private:
  const char* m_vert_shader_source;
  const char* m_frag_shader_source;
  int m_program_id;

  unsigned int m_texture;

  glm::vec4 m_color;
};
}  // namespace Material
}  // namespace GE

#endif /* SRC_MATERIAL_MESH_PHONG_MATERIAL_H_ */
