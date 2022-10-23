#include "material.h"

#include <iostream>

// stb_image.h HAS to be included in a cpp file, or you will get a compilation error
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "utilities/utilities.h"

namespace GE {
namespace Material {

int MaterialI::createShaderProgram(const char* vert_src, const char* frag_src) {
  int vertexShader = compileShader(vert_src, GL_VERTEX_SHADER);
  int fragmentShader = compileShader(frag_src, GL_FRAGMENT_SHADER);
  int shaderProgram = linkShaders(vertexShader, fragmentShader);
  return shaderProgram;
}

int MaterialI::compileShader(const char* shader_src, GLenum shaderType) {
  int shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &shader_src, 0);
  glCompileShader(shader);

  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, 0, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  return shader;
}
int MaterialI::linkShaders(int vertexShader, int fragmentShader) {
  int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // check for linking errors
  int success;
  char infoLog[512];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}

void MaterialI::loadAndBindTexture(unsigned int& texture_id,
                                   std::string texture_path) {
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  // set the texture wrapping/filtering options (on the currently bound texture object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load and generate the texture
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(
      true);  // tell stb_image.h to flip loaded texture's on the y-axis.

  unsigned char* data =
      stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);

  if (data) {
    GLenum format{::GE::Utilities::getTextureFormat(nrChannels)};
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "ERROR::Failed to load texture: " << texture_path << std::endl;
  }
  stbi_image_free(data);
}

void MaterialI::setUniformBool(int Program_ID, const std::string& name,
                               bool value) const {
  glUniform1i(glGetUniformLocation(Program_ID, name.c_str()), (int)value);
}
void MaterialI::setUniformInt(int Program_ID, const std::string& name,
                              int value) const {
  glUniform1i(glGetUniformLocation(Program_ID, name.c_str()), value);
}
void MaterialI::setUniformFloat(int Program_ID, const std::string& name,
                                float value) const {
  glUniform1f(glGetUniformLocation(Program_ID, name.c_str()), value);
}
void MaterialI::setUniformVec3(int Program_ID, const std::string& name,
                               glm::vec3 value) const {
  glUniform3f(glGetUniformLocation(Program_ID, name.c_str()), value.x, value.y,
              value.z);
}
void MaterialI::setUniformVec4(int Program_ID, const std::string& name,
                               glm::vec4 value) const {
  glUniform4f(glGetUniformLocation(Program_ID, name.c_str()), value.x, value.y,
              value.z, value.w);
}
void MaterialI::setUniformMat4(int Program_ID, const std::string& name,
                               const glm::mat4& mat) const {
  glUniformMatrix4fv(glGetUniformLocation(Program_ID, name.c_str()), 1,
                     GL_FALSE, &mat[0][0]);
}
}  // namespace Material
}  // namespace GE
