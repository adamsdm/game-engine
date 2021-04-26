
#ifndef GE_MESH_BASIC_MATERIAL_H
#define GE_MESH_BASIC_MATERIAL_H

#include "utilities.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "material.h"

namespace GE{
    namespace Material {
        class MeshBasicMaterial : public Material_I {
        public:
            MeshBasicMaterial(float r, float g, float b, float a);
            MeshBasicMaterial(std::string texture_path);
            ~MeshBasicMaterial();

            int Get_Program_ID() const;
            void Update_Uniforms() const;
            void Bind_Textures() const;
            void Set_View_Matrix(glm::mat4 view_matrix);
            void Set_Projection_Matrix(glm::mat4 projection_matrix);
            void Set_Model_Matrix(glm::mat4 model_matrix);

        private:
            const char *Vert_Shader_Source;
            const char *Frag_Shader_Source;
            int Program_ID;
            
            unsigned int texture;

            glm::vec4 Color;
        };
    } 
}

#endif /* GE_MESH_BASIC_MATERIAL_H */
