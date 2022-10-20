
#ifndef GE_MATERIAL_H
#define GE_MATERIAL_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <string>
#include "stb_image.h"

/**
 * Abstract main material class, inherit from this class for future materials
 */

namespace GE {
namespace Material {

class Material_I {
 public:
  virtual ~Material_I(){};
  virtual int Get_Program_ID() const = 0;
  virtual void Update_Uniforms() const = 0;
  virtual void Bind_Textures() const = 0;
  virtual void Set_View_Matrix(glm::mat4 view_matrix) = 0;
  virtual void Set_View_Pos(glm::vec3 view_pos) = 0;
  virtual void Set_Projection_Matrix(glm::mat4 projection_matrix) = 0;
  virtual void Set_Model_Matrix(glm::mat4 model_matrix) = 0;

 protected:
  int Create_Shader_Program(const char* vert_src, const char* frag_src);
  int Compile_Shader(const char* shader_src, GLenum shaderType);
  int Link_Shaders(int vertexShader, int fragmentShader);
  void Load_And_Bind_Texture(unsigned int& texture_id,
                             std::string texture_path);

  void Set_Uniform_Bool(int Program_ID, const std::string& name,
                        bool value) const;
  void Set_Uniform_Int(int Program_ID, const std::string& name,
                       int value) const;
  void Set_Uniform_Float(int Program_ID, const std::string& name,
                         float value) const;
  void Set_Uniform_Vec3(int Program_ID, const std::string& name,
                        glm::vec3 value) const;
  void Set_Uniform_Vec4(int Program_ID, const std::string& name,
                        glm::vec4 value) const;
  void Set_Uniform_Mat4(int Program_ID, const std::string& name,
                        const glm::mat4& mat) const;
};
}  // namespace Material
}  // namespace GE

#endif /* GE_GEOMETRY_H */
