

#ifndef GE_SCENE_H
#define GE_SCENE_H

#include "mesh.h"

#include <vector>

namespace GE {

class Scene{
    public:
        Scene();
        ~Scene();

        void add(Mesh mesh);
        std::vector<Mesh> const& Get_Meshes() const { 
            return Meshes; 
        }
        
    private:
        std::vector<Mesh> Meshes;
    };
}

#endif /* GE_SCENE_H */