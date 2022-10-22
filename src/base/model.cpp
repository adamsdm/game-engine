#include "model.h"

namespace GE {

Model::Model(std::string path_to_model)
    : m_position(0.0f), m_rotation(0.0f, 1.0f, 0.0f, 0.0f), m_scale(1.0f) {
  loadModel(path_to_model);
}

Model::~Model() = default;

void Model::setPosition(float x, float y, float z) {
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
}
void Model::setRotation(float angle, float x, float y, float z) {
  m_rotation.x = x;
  m_rotation.y = y;
  m_rotation.z = z;
  m_rotation.w = angle;
}

glm::vec3 Model::getPosition() const {
  return m_position;
}

glm::vec4 Model::getRotation() const {
  return m_rotation;
}

void Model::render(Camera::CameraI& cam) const {
  // TODO Render each mesh
}

void Model::loadModel(std::string path) {
  // TODO Implement me
}

};  // namespace GE
