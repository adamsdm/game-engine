
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
  MaterialI::loadAndBindTexture(m_diffuse_texture, texture_path);

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

void MeshBasicMaterial::prepareForRender(const Camera::CameraI& cam,
                                         const glm::mat4& modelMatrix) {
  glUseProgram(m_program_id);
  MaterialI::setUniformMat4(m_program_id, "View", cam.getViewMatrix());
  MaterialI::setUniformVec3(m_program_id, "ViewPos", cam.getPosition());
  MaterialI::setUniformMat4(m_program_id, "Projection",
                            cam.getProjectionMatrix());
  MaterialI::setUniformMat4(m_program_id, "Model", modelMatrix);

  MaterialI::setUniformVec4(m_program_id, "Color", m_color);

  if (m_diffuse_texture) {
    MaterialI::setUniformBool(m_program_id, "UseTexture", true);
    MaterialI::setUniformInt(m_program_id, "Texture", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_diffuse_texture);
  }
  if (m_specular_texture) {
    MaterialI::setUniformBool(m_program_id, "UseSpecularMap", true);
    MaterialI::setUniformInt(m_program_id, "SpecularMap", 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_specular_texture);
  }
}

void MeshBasicMaterial::addSpecularMap(
    const std::string& specular_texture_path) {
  MaterialI::loadAndBindTexture(m_specular_texture, specular_texture_path);
}

}  // namespace Material
}  // namespace GE
