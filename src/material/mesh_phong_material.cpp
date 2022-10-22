#include "mesh_phong_material.h"

namespace GE {
namespace Material {

MeshPhongMaterial::MeshPhongMaterial(float r, float g, float b, float a)
    : m_color(r, g, b, a) {

  std::string vStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_phong_material.vert");
  std::string fStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_phong_material.frag");

  // Convert string to char array
  m_vert_shader_source = vStringSrc.c_str();
  m_frag_shader_source = fStringSrc.c_str();

  m_program_id =
      MaterialI::createShaderProgram(m_vert_shader_source, m_frag_shader_source);
}

MeshPhongMaterial::MeshPhongMaterial(std::string texture_path) {
  MaterialI::loadAndBindTexture(m_texture, texture_path);

  std::string vStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_phong_material.vert");
  std::string fStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_phong_texture_material.frag");

  // Convert string to char array
  m_vert_shader_source = vStringSrc.c_str();
  m_frag_shader_source = fStringSrc.c_str();

  m_program_id =
      MaterialI::createShaderProgram(m_vert_shader_source, m_frag_shader_source);
}

MeshPhongMaterial::~MeshPhongMaterial() = default;

int MeshPhongMaterial::getProgramId() const {
  return m_program_id;
}

void MeshPhongMaterial::setViewMatrix(glm::mat4 view_matrix) {
  MaterialI::setUniformMat4(m_program_id, "View", view_matrix);
}

void MeshPhongMaterial::setViewPos(glm::vec3 view_pos) {
  MaterialI::setUniformVec3(m_program_id, "ViewPos", view_pos);
}

void MeshPhongMaterial::setProjectionMatrix(glm::mat4 projection_matrix) {
  MaterialI::setUniformMat4(m_program_id, "Projection", projection_matrix);
}
void MeshPhongMaterial::setModelMatrix(glm::mat4 model_matrix) {
  MaterialI::setUniformMat4(m_program_id, "Model", model_matrix);
}

void MeshPhongMaterial::updateUniforms() const {
  MaterialI::setUniformVec4(m_program_id, "Color", m_color);
}

void MeshPhongMaterial::bindTextures() const {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_texture);
}

}  // namespace Material
}  // namespace GE
