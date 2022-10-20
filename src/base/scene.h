

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

  void add(Mesh* mesh);
  void add(Model* model);
  std::vector<Mesh*> const& Get_Meshes() const { return Meshes; }
  std::vector<Model*> const& Get_Models() const { return Models; }

 private:
  std::vector<Mesh*> Meshes;
  std::vector<Model*> Models;
};
}  // namespace GE

#endif /* GE_SCENE_H */
