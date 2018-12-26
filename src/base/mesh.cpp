

#include "mesh.h"

namespace GE{

    Mesh::Mesh(const Geometry::Geometry_I &geometry, const Material::Material_I &material) : 
    m_geometry(geometry),
    m_material(material)
    {
    }
    
    Mesh::~Mesh(){
    }
};
