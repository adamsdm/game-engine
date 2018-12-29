
#ifndef GE_MESH_BASIC_MATERIAL_H
#define GE_MESH_BASIC_MATERIAL_H

#include "utilities.h"
#include <glad/glad.h>
#include <material.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

namespace GE{
    namespace Material {
        class MeshBasicMaterial : public Material_I {
        public:
            MeshBasicMaterial(float r, float g, float b, float a);
            ~MeshBasicMaterial();

            int Get_Program_ID() const;
            void Update_Uniforms() const;

        private:
            const char *Vert_Shader_Source;
            const char *Frag_Shader_Source;
            int Program_ID;
            glm::vec4 Color;

            int Create_Shader_Program(const char *vert_src, const char *frag_src);
            int Compile_Shader(const char  *shader_src, GLenum shaderType);
            int Link_Shaders(int vertexShader, int fragmentShader);
        };
    } 
}

#endif /* GE_MESH_BASIC_MATERIAL_H */
