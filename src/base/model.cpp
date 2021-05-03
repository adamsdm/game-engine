#include "model.h"

namespace GE{

    Model::Model(std::string path_to_model) :
        Position(0.0f),
        Rotation(0.0f, 1.0f, 0.0f, 0.0f),
        Scale(1.0f)
    {
        Load_Model(path_to_model);
    }
    
    Model::~Model(){
    }

    void Model::Set_Position(float x, float y, float z){
        Position.x = x;
        Position.y = y;
        Position.z = z;
    }
    void Model::Set_Rotation(float angle, float x, float y, float z) {
        Rotation.x = x;
        Rotation.y = y;
        Rotation.z = z;
        Rotation.w = angle;
    }

    glm::vec3 Model::Get_Position() const {
        return Position;
    }

    glm::vec4 Model::Get_Rotation() const {
        return Rotation;
    }

    void Model::Render(Camera::Camera_I &cam) const {
        // Render each mesh
    }

    void Model::Load_Model(std::string path) {
    }
    

};
