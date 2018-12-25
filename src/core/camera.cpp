
#include "camera.h"

namespace GE {
namespace Camera {

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far) :
    m_fov(fov),
    m_aspect(aspect),
    m_near(near),
    m_far(far),
    m_pos(0.0f)
{
}

PerspectiveCamera::~PerspectiveCamera(){

}

void PerspectiveCamera::Set_Position(glm::vec3 New_Position){
    m_pos.x = New_Position.x;
    m_pos.y = New_Position.y;
    m_pos.z = New_Position.z;
}


} /* Camera */
} /* GE */