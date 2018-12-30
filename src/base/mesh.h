


#ifndef GE_MESH_H
#define GE_MESH_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

#include "geometry.h"
#include "material.h"
#include "camera.h"


namespace GE{

class Mesh{
public:
    Mesh(const Geometry::Geometry_I &geometry, Material::Material_I &material);
    ~Mesh();

    void Set_Position(float x, float y, float z);
    void Set_Rotation(float angle, float x, float y, float z);

    void Render(Camera::Camera_I &cam) const;

private:
    glm::mat4 Model_Matrix;
    const Geometry::Geometry_I &m_geometry;
    Material::Material_I &m_material;
};

};

#endif /* GE_GEOMETRY_H */
