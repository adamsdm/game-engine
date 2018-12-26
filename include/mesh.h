


#ifndef GE_MESH_H
#define GE_MESH_H

#include "geometry.h"
#include "material.h"

namespace GE{

class Mesh{
public:
    Mesh(Geometry::BoxGeometry geo, Material::MeshBasicMaterial mat);
    ~Mesh();
};

}

#endif /* GE_GEOMETRY_H */