

#include "mesh.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace GE{

    Mesh::Mesh(const Geometry::Geometry_I &geometry, Material::Material_I &material) :
        m_geometry(geometry),
        m_material(material),
    	Model_Matrix(1.0f)
    {
    }
    
    Mesh::~Mesh(){
    }

    void Mesh::Set_Position(float x, float y, float z){
    	Model_Matrix = glm::translate(Model_Matrix, glm::vec3(x,y,z));
    }
    void Mesh::Set_Rotation(float angle, float x, float y, float z){
    	Model_Matrix = glm::rotate(Model_Matrix, glm::radians(angle), glm::vec3(x, y, z));
    }

    void Mesh::Render(Camera::Camera_I &cam) const {
        glUseProgram(m_material.Get_Program_ID());

        m_material.Set_View_Matrix(cam.Get_View_Matrix());
        m_material.Set_Projection_Matrix(cam.Get_Projection_Matrix());
        m_material.Set_Model_Matrix(Model_Matrix);
        m_material.Update_Uniforms();

        m_geometry.Render();
    }

};
