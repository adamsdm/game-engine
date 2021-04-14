


#ifndef GE_MESH_H
#define GE_MESH_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <vector>

#include "geometry.h"
#include "material.h"
#include "camera.h"
#include "ge_types.h"


namespace GE{

class Mesh{
public:
    Mesh(const Geometry::Geometry_I &geometry, Material::Material_I &material);
    ~Mesh();

    void Set_Position(float x, float y, float z);
    void Set_Rotation(float angle, float x, float y, float z);

    glm::vec3 Get_Position() const;
    glm::vec4 Get_Rotation() const;

    void Render(Camera::Camera_I &cam) const;

private:
    glm::vec3 Position;
    glm::vec4 Rotation;
    glm::vec3 Scale;

    //TODO: Currently unused
    std::vector<Vertex>       Vertices;
    std::vector<unsigned int> Indices;
    std::vector<Texture>      Textures;

    const Geometry::Geometry_I &m_geometry;
    Material::Material_I &m_material;
};

};

#endif /* GE_GEOMETRY_H */
