
#include "mesh_basic_material.h"

namespace GE{
  namespace Material {

    MeshBasicMaterial::MeshBasicMaterial(float r, float g, float b, float a) :
    		Color(r, g, b, a)
	{

    	std::string vStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_basic_material.vert");
    	std::string fStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_basic_material.frag");

    	// Convert string to char array
    	Vert_Shader_Source = vStringSrc.c_str();
    	Frag_Shader_Source = fStringSrc.c_str();

    	Program_ID = Material_I::Create_Shader_Program(Vert_Shader_Source, Frag_Shader_Source);
    }

    MeshBasicMaterial::~MeshBasicMaterial(){
	}

    int MeshBasicMaterial::Get_Program_ID() const {
      return Program_ID;
    }

    void MeshBasicMaterial::Set_View_Matrix(glm::mat4 view_matrix) {
    	Material_I::Set_Uniform_Mat4(Program_ID, "View", view_matrix);
    }

    void MeshBasicMaterial::Set_Projection_Matrix(glm::mat4 projection_matrix){
    	Material_I::Set_Uniform_Mat4(Program_ID, "Projection", projection_matrix);
    }
    void MeshBasicMaterial::Set_Model_Matrix(glm::mat4 model_matrix){
    	Material_I::Set_Uniform_Mat4(Program_ID, "Model", model_matrix);
    }

    void MeshBasicMaterial::Update_Uniforms() const {
    	Material_I::Set_Uniform_Vec4(Program_ID, "Color", Color);
	}
  } 
}
