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
class MeshPhongMaterial : public Material_I {
 public:
  MeshPhongMaterial(float r, float g, float b, float a);
  MeshPhongMaterial(std::string texture_path);
  ~MeshPhongMaterial();

  // TODO These are common for all materials, move to base class?
  int Get_Program_ID() const;
  void Update_Uniforms() const;
  void Bind_Textures() const;
  void Set_View_Matrix(glm::mat4 view_matrix);
  void Set_View_Pos(glm::vec3 view_pos);
  void Set_Projection_Matrix(glm::mat4 projection_matrix);
  void Set_Model_Matrix(glm::mat4 model_matrix);

 private:
  const char* Vert_Shader_Source;
  const char* Frag_Shader_Source;
  int Program_ID;

  unsigned int texture;

  glm::vec4 Color;
};
}  // namespace Material
}  // namespace GE

#endif /* SRC_MATERIAL_MESH_PHONG_MATERIAL_H_ */
