#include "scene.h"

namespace GE {

Scene::Scene() = default;

Scene::~Scene() = default;

// TODO If mesh and model have same parent we can get rid of one of these
void Scene::add(Mesh* mesh) {
  Meshes.push_back(mesh);
}

void Scene::add(Model* model) {
  Models.push_back(model);
}

}  // namespace GE
