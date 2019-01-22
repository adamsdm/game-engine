/*
 * mesh_phong_material.cpp
 *
 *  Created on: 31 Dec 2018
 *      Author: adamsoderstrom
 */

#include "mesh_phong_material.h"

namespace GE{
namespace Material {

	MeshPhongMaterial::MeshPhongMaterial(float r, float g, float b, float a) :
    		Color(r, g, b, a)
	{

    	std::string vStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_phong_material.vert");
    	std::string fStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_phong_material.frag");

    	// Convert string to char array
    	Vert_Shader_Source = vStringSrc.c_str();
    	Frag_Shader_Source = fStringSrc.c_str();

    	Program_ID = Material_I::Create_Shader_Program(Vert_Shader_Source, Frag_Shader_Source);
    }

	MeshPhongMaterial::~MeshPhongMaterial(){
	}

    int MeshPhongMaterial::Get_Program_ID() const {
      return Program_ID;
    }

    void MeshPhongMaterial::Set_View_Matrix(glm::mat4 view_matrix) {
    	Material_I::Set_Uniform_Mat4(Program_ID, "View", view_matrix);
    }

    void MeshPhongMaterial::Set_Projection_Matrix(glm::mat4 projection_matrix){
    	Material_I::Set_Uniform_Mat4(Program_ID, "Projection", projection_matrix);
    }
    void MeshPhongMaterial::Set_Model_Matrix(glm::mat4 model_matrix){
    	Material_I::Set_Uniform_Mat4(Program_ID, "Model", model_matrix);
    }

    void MeshPhongMaterial::Update_Uniforms() const {
    	Material_I::Set_Uniform_Vec4(Program_ID, "Color", Color);
	}


}
}


