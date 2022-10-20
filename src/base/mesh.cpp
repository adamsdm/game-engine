

#include "mesh.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace GE {

Mesh::Mesh(const Geometry::Geometry_I& geometry, Material::Material_I& material)
    : m_geometry(geometry),
      m_material(material),
      Position(0.0f),
      Rotation(0.0f, 1.0f, 0.0f, 0.0f),
      Scale(1.0f) {
  Vertices = m_geometry.Get_Vertices();
  Indices = m_geometry.Get_Indices();

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int),
               &Indices[0], GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
  glEnableVertexAttribArray(0);

  // Normal attribute
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, Normal));
  glEnableVertexAttribArray(2);

  // TexCoord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                        (void*)offsetof(Vertex, TexCoords));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

Mesh::~Mesh() = default;

void Mesh::Set_Position(float x, float y, float z) {
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

void Mesh::Render(Camera::Camera_I& cam) const {
  glUseProgram(m_material.Get_Program_ID());

  glm::mat4 Model_Matrix(1.0f);
  Model_Matrix = glm::translate(Model_Matrix, Position);
  Model_Matrix = glm::rotate(Model_Matrix, Rotation.w,
                             glm::vec3(Rotation.x, Rotation.y, Rotation.z));
  Model_Matrix = glm::scale(Model_Matrix, Scale);

  m_material.Set_View_Matrix(cam.Get_View_Matrix());
  m_material.Set_View_Pos(cam.Get_Position());
  m_material.Set_Projection_Matrix(cam.Get_Projection_Matrix());
  m_material.Set_Model_Matrix(Model_Matrix);
  m_material.Bind_Textures();
  m_material.Update_Uniforms();

  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);
}

};  // namespace GE
