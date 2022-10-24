
#ifndef GE_MATERIAL_H
#define GE_MATERIAL_H

#include <glad/glad.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <string>

#include "camera.h"

namespace GE {
namespace Material {

class MaterialI {
 public:
  virtual ~MaterialI(){};

  virtual void prepareForRender(const Camera::CameraI& cam,
                                const glm::mat4& modelMatrix) const = 0;

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
