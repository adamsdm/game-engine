#ifndef GE_SCENE_H
#define GE_SCENE_H

#include "mesh.h"
#include "model.h"

#include <memory>
#include <vector>

namespace GE {

class Scene {
 public:
  Scene();
  ~Scene();

  void add(std::shared_ptr<Mesh> mesh);
  void add(std::shared_ptr<Model> model);
  std::vector<std::shared_ptr<Mesh>> const& getMeshes() const {
    return m_meshes;
  }
  std::vector<std::shared_ptr<Model>> const& getModels() const {
    return m_models;
  }

 private:
  std::vector<std::shared_ptr<Mesh>> m_meshes;
  std::vector<std::shared_ptr<Model>> m_models;
};
}  // namespace GE

#endif /* GE_SCENE_H */
