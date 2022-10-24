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
  MeshPhongMaterial(const std::string& diffuse_texture_path);
  ~MeshPhongMaterial();
  
  void prepareForRender(const Camera::CameraI& cam,
                        const glm::mat4& modelMatrix) const override;
  void addSpecularMap(const std::string& specular_texture_path);

 private:
  const char* m_vert_shader_source;
  const char* m_frag_shader_source;
  int m_program_id;

  unsigned int m_diffuse_texture{0};
  unsigned int m_specular_texture{0};

  glm::vec4 m_color;
};
}  // namespace Material
}  // namespace GE

#endif /* SRC_MATERIAL_MESH_PHONG_MATERIAL_H_ */
