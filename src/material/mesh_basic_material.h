
#ifndef GE_MESH_BASIC_MATERIAL_H
#define GE_MESH_BASIC_MATERIAL_H

#include "interfaces/material_i.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace GE{
    namespace Material {
        class MeshBasicMaterial : public Material_I {
        public:
            MeshBasicMaterial(float r, float g, float b);
            ~MeshBasicMaterial();

            int Get_Program_ID() const;

        private:
            const char *vertexShaderSource;
            const char *fragmentShaderSource;
            int Program_ID;

            std::string Read_From_File(const char* path);

            int Create_Shader_Program(const char *vert_src, const char *frag_src);
            int Compile_Shader(const char  *shader_src, GLenum shaderType);
            int Link_Shaders(int vertexShader, int fragmentShader);
        };
    } 
}

#endif /* GE_MESH_BASIC_MATERIAL_H */
