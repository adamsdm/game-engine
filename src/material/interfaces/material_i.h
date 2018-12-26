
#ifndef GE_MATERIAL_H
#define GE_MATERIAL_H

#include <glad/glad.h>

namespace GE{
namespace Material {
    
    class Material_I{
    public:
        virtual int Get_Program_ID() const = 0;
    private:
        virtual int Create_Shader_Program(const char *vert_src, const char *frag_src) = 0;
        virtual int Compile_Shader(const char *shader_src, GLenum shaderType) = 0;
        virtual int Link_Shaders(int vertexShader, int fragmentShader) = 0;

    };
} 
}

#endif /* GE_GEOMETRY_H */