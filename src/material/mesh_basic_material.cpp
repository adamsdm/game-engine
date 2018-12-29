
#include "mesh_basic_material.h"

namespace GE{
  namespace Material {

    MeshBasicMaterial::MeshBasicMaterial(float r, float g, float b){

    	std::string vStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_basic_material.vert");
    	std::string fStringSrc = ::GE::Utilities::Read_From_File("resources/shaders/mesh_basic_material.frag");

    	// Convert string to char array
    	Vert_Shader_Source = vStringSrc.c_str();
    	Frag_Shader_Source = fStringSrc.c_str();

    	Program_ID = Create_Shader_Program(Vert_Shader_Source, Frag_Shader_Source);
    }

    MeshBasicMaterial::~MeshBasicMaterial(){
	}

    int MeshBasicMaterial::Get_Program_ID() const {
      return Program_ID;
    }

    int MeshBasicMaterial::Create_Shader_Program(const char *vert_src, const char *frag_src){
  
      int vertexShader = Compile_Shader(vert_src, GL_VERTEX_SHADER);
      int fragmentShader = Compile_Shader(frag_src, GL_FRAGMENT_SHADER);
      int shaderProgram = Link_Shaders(vertexShader, fragmentShader);

      return shaderProgram;
    }

    int MeshBasicMaterial::Compile_Shader(const char *shader_src, GLenum shaderType){
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

    int MeshBasicMaterial::Link_Shaders(int vertexShader, int fragmentShader){
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

  } 
}
