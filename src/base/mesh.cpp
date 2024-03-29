#include "mesh.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace GE {

Mesh::Mesh(const Geometry::GeometryI& geometry, const Material::MaterialI& material)
    : m_geometry(geometry),
      m_material(material),
      m_position(0.0f),
      m_rotation(0.0f, 1.0f, 0.0f, 0.0f),
      m_scale(1.0f) {

  m_vertices = m_geometry.getVertices();
  m_indices = m_geometry.getIndices();

  glGenVertexArrays(1, &m_VAO);
  glGenBuffers(1, &m_VBO);
  glGenBuffers(1, &m_EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(m_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex),
               &m_vertices[0], GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int),
               &m_indices[0], GL_STATIC_DRAW);

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

void Mesh::setPosition(float x, float y, float z) {
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
}
void Mesh::setRotation(float angle, float x, float y, float z) {
  m_rotation.x = x;
  m_rotation.y = y;
  m_rotation.z = z;
  m_rotation.w = angle;
}

glm::vec3 Mesh::getPosition() const {
  return m_position;
}

glm::vec4 Mesh::getRotation() const {
  return m_rotation;
}

void Mesh::render(const Camera::CameraI& cam) const {

  m_material.prepareForRender(cam, calculateModelMatrix());
  glBindVertexArray(m_VAO);
  glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}

glm::mat4 Mesh::calculateModelMatrix() const {
  glm::mat4 modelMatrix(1.0f);
  modelMatrix = glm::translate(modelMatrix, m_position);
  modelMatrix =
      glm::rotate(modelMatrix, m_rotation.w,
                  glm::vec3(m_rotation.x, m_rotation.y, m_rotation.z));
  modelMatrix = glm::scale(modelMatrix, m_scale);
  return modelMatrix;
}

};  // namespace GE
