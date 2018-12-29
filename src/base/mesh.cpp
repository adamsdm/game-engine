

#include "mesh.h"

namespace GE{

    Mesh::Mesh(const Geometry::Geometry_I &geometry, const Material::Material_I &material) : 
        m_geometry(geometry),
        m_material(material)
    {
    }
    
    Mesh::~Mesh(){
    }

    void Mesh::Render() const {
        glUseProgram(m_material.Get_Program_ID());
        m_material.Update_Uniforms();
        m_geometry.Render();
    }

};
