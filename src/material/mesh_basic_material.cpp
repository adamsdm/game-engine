
#include "mesh_basic_material.h"

namespace GE{
  namespace Material {

    MeshBasicMaterial::MeshBasicMaterial(float r, float g, float b){
      
      // TODO: Replace this with read from file 
      vertexShaderSource = "#version 330 core\n"
          "layout (location = 0) in vec3 aPos;\n"
          "void main()\n"
          "{\n"
          "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
          "}\0";
      fragmentShaderSource = "#version 330 core\n"
          "out vec4 FragColor;\n"
          "void main()\n"
          "{\n"
          "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
          "}\n\0";

      Program_ID = Create_Shader_Program(vertexShaderSource, fragmentShaderSource);
    }

    MeshBasicMaterial::~MeshBasicMaterial(){
    }

    int MeshBasicMaterial::Get_Program_ID(){
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