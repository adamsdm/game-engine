

#ifndef GE_SCENE_H
#define GE_SCENE_H

#include "mesh.h"

namespace GE {

class Scene{
public:
    Scene();
    ~Scene();

    void add(Mesh &mesh);
};

}

#endif /* GE_SCENE_H */