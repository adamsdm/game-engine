
#ifndef GE_MATERIAL_H
#define GE_MATERIAL_H

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace GE{
namespace Material {
    
    class Material_I{
    public:
        virtual int Get_Program_ID() const = 0;
        virtual void Update_Uniforms() const = 0;
        virtual ~Material_I(){};
    private:
        virtual int Create_Shader_Program(const char *vert_src, const char *frag_src) = 0;
        virtual int Compile_Shader(const char *shader_src, GLenum shaderType) = 0;
        virtual int Link_Shaders(int vertexShader, int fragmentShader) = 0;
    protected:
        void Set_Uniform_Bool(int Program_ID, const std::string &name, bool value) const;
        void Set_Uniform_Int(int Program_ID, const std::string &name, int value) const;
        void Set_Uniform_Float(int Program_ID, const std::string &name, float value) const;
        void Set_Uniform_Vec3(int Program_ID, const std::string &name, glm::vec3 value) const;
        void Set_Uniform_Vec4(int Program_ID, const std::string &name, glm::vec4 value) const;
    };
} 
}

#endif /* GE_GEOMETRY_H */
