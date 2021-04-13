

#include "mesh.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace GE{

    Mesh::Mesh(const Geometry::Geometry_I &geometry, Material::Material_I &material) :
        m_geometry(geometry),
        m_material(material),
        Position(0.0f),
        Rotation(0.0f, 1.0f, 0.0f, 0.0f),
        Scale(1.0f)
    {
    }
    
    Mesh::~Mesh(){
    }

    void Mesh::Set_Position(float x, float y, float z){
        Position.x = x;
        Position.y = y;
        Position.z = z;
    }
    void Mesh::Set_Rotation(float angle, float x, float y, float z) {
        Rotation.x = x;
        Rotation.y = y;
        Rotation.z = z;
        Rotation.w = angle;
    }

    glm::vec3 Mesh::Get_Position() const {
        return Position;
    }

    glm::vec4 Mesh::Get_Rotation() const {
        return Rotation;
    }

    void Mesh::Render(Camera::Camera_I &cam) const {
        glUseProgram(m_material.Get_Program_ID());

        glm::mat4 Model_Matrix(1.0f);
        Model_Matrix = glm::translate(Model_Matrix, Position);
        Model_Matrix = glm::rotate(Model_Matrix, Rotation.w, glm::vec3(Rotation.x, Rotation.y, Rotation.z) );
        Model_Matrix = glm::scale(Model_Matrix, Scale);

        m_material.Set_View_Matrix(cam.Get_View_Matrix());
        m_material.Set_Projection_Matrix(cam.Get_Projection_Matrix());
        m_material.Set_Model_Matrix(Model_Matrix);
        m_material.Update_Uniforms();

        m_geometry.Render();
    }

};
