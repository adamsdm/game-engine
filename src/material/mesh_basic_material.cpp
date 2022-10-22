
#include "mesh_basic_material.h"

namespace GE {
namespace Material {

MeshBasicMaterial::MeshBasicMaterial(float r, float g, float b, float a)
    : m_color(r, g, b, a) {

  std::string vStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_basic_material.vert");
  std::string fStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_basic_material.frag");

  // Convert string to char array
  m_vert_shader_source = vStringSrc.c_str();
  m_frag_shader_source = fStringSrc.c_str();

  m_program_id = MaterialI::createShaderProgram(m_vert_shader_source,
                                                m_frag_shader_source);
}

MeshBasicMaterial::MeshBasicMaterial(std::string texture_path) {
  MaterialI::loadAndBindTexture(m_texture, texture_path);

  std::string vStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_basic_material.vert");
  std::string fStringSrc = ::GE::Utilities::readFromFile(
      "resources/shaders/mesh_basic_texture_material.frag");

  // Convert string to char array
  m_vert_shader_source = vStringSrc.c_str();
  m_frag_shader_source = fStringSrc.c_str();

  m_program_id = MaterialI::createShaderProgram(m_vert_shader_source,
                                                m_frag_shader_source);
}

MeshBasicMaterial::~MeshBasicMaterial() = default;

int MeshBasicMaterial::getProgramId() const {
  return m_program_id;
}

void MeshBasicMaterial::setViewMatrix(glm::mat4 view_matrix) {
  MaterialI::setUniformMat4(m_program_id, "View", view_matrix);
}

void MeshBasicMaterial::setViewPos(glm::vec3 view_pos) {
  MaterialI::setUniformVec3(m_program_id, "ViewPos", view_pos);
}

void MeshBasicMaterial::setProjectionMatrix(glm::mat4 projection_matrix) {
  MaterialI::setUniformMat4(m_program_id, "Projection", projection_matrix);
}
void MeshBasicMaterial::setModelMatrix(glm::mat4 model_matrix) {
  MaterialI::setUniformMat4(m_program_id, "Model", model_matrix);
}

void MeshBasicMaterial::updateUniforms() const {
  glBindTexture(GL_TEXTURE_2D, m_texture);
  MaterialI::setUniformVec4(m_program_id, "Color", m_color);
}

void MeshBasicMaterial::bindTextures() const {
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_texture);
}
}  // namespace Material
}  // namespace GE
