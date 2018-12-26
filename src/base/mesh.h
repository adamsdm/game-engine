


#ifndef GE_MESH_H
#define GE_MESH_H

#include "geometry_i.h"
#include "material_i.h"

namespace GE{

class Mesh{
public:
    Mesh(const Geometry::Geometry_I &geometry, const Material::Material_I &material);
    ~Mesh();

    void Render() const;

private:
    const Geometry::Geometry_I &m_geometry;
    const Material::Material_I &m_material;
};

};

#endif /* GE_GEOMETRY_H */