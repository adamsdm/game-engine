/*
 * material.cpp
 *
 *  Created on: 29 Dec 2018
 *      Author: adamsoderstrom
 */

#include "material.h"

namespace GE{
namespace Material {
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



