
#ifndef GE_MESH_BASIC_MATERIAL_H
#define GE_MESH_BASIC_MATERIAL_H

#include "interfaces/material_i.h"

namespace GE{
namespace Material {

class MeshBasicMaterial : public Material_I {
public:
    MeshBasicMaterial(float r, float g, float b);
    ~MeshBasicMaterial();

};

} 
}

#endif /* GE_MESH_BASIC_MATERIAL_H */