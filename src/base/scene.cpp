
#include "scene.h"

namespace GE {
    
    Scene::Scene(){
    }

    Scene::~Scene(){
    }

    void Scene::add(Mesh mesh){
        Meshes.push_back(mesh);
    }

}


