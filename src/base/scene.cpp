#include "scene.h"

namespace GE {

Scene::Scene() = default;

Scene::~Scene() = default;

// TODO If mesh and model have same parent we can get rid of one of these
void Scene::add(std::shared_ptr<Mesh> mesh) {
  m_meshes.push_back(mesh);
}

void Scene::add(std::shared_ptr<Model> model) {
  m_models.push_back(model);
}

}  // namespace GE
