#ifndef GE_SCENE_H
#define GE_SCENE_H

#include "mesh.h"
#include "model.h"

#include <vector>

namespace GE {

class Scene {
 public:
  Scene();
  ~Scene();

  // TODO Raw ptrs....
  void add(Mesh* mesh);
  void add(Model* model);
  std::vector<Mesh*> const& getMeshes() const { return m_meshes; }
  std::vector<Model*> const& getModels() const { return m_models; }

 private:
  // TODO Naming convention, also raw ptrs
  std::vector<Mesh*> m_meshes;
  std::vector<Model*> m_models;
};
}  // namespace GE

#endif /* GE_SCENE_H */
