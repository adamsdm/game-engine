
#include "mesh_basic_material.h"

namespace GE{
  namespace Material {

    MeshBasicMaterial::MeshBasicMaterial(float r, float g, float b){

    	std::string vStringSrc = Read_From_File("resources/shaders/mesh_basic_material.vert");
    	std::string fStringSrc = Read_From_File("resources/shaders/mesh_basic_material.frag");

    	// Convert string to char array
    	vertexShaderSource = vStringSrc.c_str();
    	fragmentShaderSource = fStringSrc.c_str();

    	Program_ID = Create_Shader_Program(vertexShaderSource, fragmentShaderSource);
    }

    MeshBasicMaterial::~MeshBasicMaterial(){
	}

    std::string MeshBasicMaterial::Read_From_File(const char* path){

    	std::string code;

    	std::ifstream file;

    	file.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    	try
    	{
    		// open files
    		file.open(path);

    		std::stringstream stream;
    		// read file's buffer contents into streams
			stream << file.rdbuf();

    		// close file handlers
    		file.close();
    		// convert stream into string
    		code = stream.str();

    	}
    	catch(std::ifstream::failure e)
    	{
    		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
			exit(-1);
    	}

    	return code;
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
