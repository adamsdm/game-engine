
#include "perspective_camera.h"

namespace GE {
namespace Camera {

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far) :
    m_fov(fov),
    m_aspect(aspect),
    m_near(near),
    m_far(far),
    cam_Pos(0.0f, 0.0f, 3.0f),
	cam_Front(0.0f, 0.0f, -1.0f),
	cam_Up(0.0f, 1.0f,  0.0f)
{
	cam_View_Matrix = glm::lookAt(cam_Pos, cam_Pos + cam_Front, cam_Up);
	cam_Projection_Matrix = glm::perspective(glm::radians(fov), aspect, near, far);
}

PerspectiveCamera::~PerspectiveCamera(){

}

glm::mat4 PerspectiveCamera::Get_Projection_Matrix() const {
	return cam_Projection_Matrix;
}

glm::mat4 PerspectiveCamera::Get_View_Matrix() const {
	return cam_View_Matrix;
}

void PerspectiveCamera::Set_Position(glm::vec3 New_Position) {
    cam_Pos.x = New_Position.x;
    cam_Pos.y = New_Position.y;
    cam_Pos.z = New_Position.z;
}


} /* Camera */
} /* GE */
