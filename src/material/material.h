
#ifndef GE_MATERIAL_H
#define GE_MATERIAL_H

#include <glad/glad.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <string>

namespace GE {
namespace Material {

class MaterialI {
 public:
  virtual ~MaterialI(){};
  virtual int getProgramId() const = 0;
  virtual void updateUniforms() const = 0;
  virtual void bindTextures() const = 0;
  virtual void setViewMatrix(glm::mat4 view_matrix) = 0;
  virtual void setViewPos(glm::vec3 view_pos) = 0;
  virtual void setProjectionMatrix(glm::mat4 projection_matrix) = 0;
  virtual void setModelMatrix(glm::mat4 model_matrix) = 0;

 protected:
  int createShaderProgram(const char* vert_src, const char* frag_src);
  int compileShader(const char* shader_src, GLenum shaderType);
  int linkShaders(int vertexShader, int fragmentShader);
  void loadAndBindTexture(unsigned int& texture_id, std::string texture_path);

  void setUniformBool(int Program_ID, const std::string& name,
                      bool value) const;
  void setUniformInt(int Program_ID, const std::string& name, int value) const;
  void setUniformFloat(int Program_ID, const std::string& name,
                       float value) const;
  void setUniformVec3(int Program_ID, const std::string& name,
                      glm::vec3 value) const;
  void setUniformVec4(int Program_ID, const std::string& name,
                      glm::vec4 value) const;
  void setUniformMat4(int Program_ID, const std::string& name,
                      const glm::mat4& mat) const;
};
}  // namespace Material
}  // namespace GE

#endif /* GE_GEOMETRY_H */
