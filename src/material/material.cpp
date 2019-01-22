/*
 * material.cpp
 *
 *  Created on: 29 Dec 2018
 *      Author: adamsoderstrom
 */

#include "material.h"

namespace GE{
namespace Material {

	int Material_I::Create_Shader_Program(const char *vert_src, const char *frag_src){
      int vertexShader = Compile_Shader(vert_src, GL_VERTEX_SHADER);
      int fragmentShader = Compile_Shader(frag_src, GL_FRAGMENT_SHADER);
      int shaderProgram = Link_Shaders(vertexShader, fragmentShader);
      return shaderProgram;
    }

	int Material_I::Compile_Shader(const char *shader_src, GLenum shaderType){
	  int Shader = glCreateShader(shaderType);
	  glShaderSource(Shader, 1, &shader_src, 0);
	  glCompileShader(Shader);

	  // check for shader compile errors
	  int success;
	  char infoLog[512];
	  glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
	  if (!success)
	  {
		  glGetShaderInfoLog(Shader, 512, 0, infoLog);
		  std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	  }

	  return Shader;
	}
	int Material_I::Link_Shaders(int vertexShader, int fragmentShader){
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
		  std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	  }

	  glDeleteShader(vertexShader);
	  glDeleteShader(fragmentShader);

	  return shaderProgram;
	}

	void Material_I::Set_Uniform_Bool(int Program_ID, const std::string &name, bool value) const {
		glUniform1i(glGetUniformLocation(Program_ID, name.c_str()), (int)value);
	}
	void Material_I::Set_Uniform_Int(int Program_ID, const std::string &name, int value) const {
		glUniform1i(glGetUniformLocation(Program_ID, name.c_str()), value);
	}
	void Material_I::Set_Uniform_Float(int Program_ID, const std::string &name, float value) const {
		glUniform1f(glGetUniformLocation(Program_ID, name.c_str()), value);
	}
	void Material_I::Set_Uniform_Vec3(int Program_ID, const std::string &name, glm::vec3 value) const {
		glUniform3f(glGetUniformLocation(Program_ID, name.c_str()), value.x, value.y, value.z);
	}
	void Material_I::Set_Uniform_Vec4(int Program_ID, const std::string &name, glm::vec4 value) const {
		glUniform4f(glGetUniformLocation(Program_ID, name.c_str()), value.x, value.y, value.z, value.w);
	}
	void Material_I::Set_Uniform_Mat4(int Program_ID, const std::string &name, const glm::mat4 &mat) const{
		glUniformMatrix4fv(glGetUniformLocation(Program_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
}
}



