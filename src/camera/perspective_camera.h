

#ifndef GE_CAMERA_H
#define GE_CAMERA_H

#include <camera.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GE {
namespace Camera {

class PerspectiveCamera : public Camera_I {
public: 
    PerspectiveCamera(float fov, float aspect, float near, float far);
    ~PerspectiveCamera();

    void Set_Position(glm::vec3 New_Position);
    glm::mat4 Get_View_Matrix() const;
    glm::mat4 Get_Projection_Matrix() const;

private:
    float m_fov;
    float m_aspect;
    float m_near;
    float m_far;

    glm::vec3 cam_Pos;
    glm::vec3 cam_Front;
    glm::vec3 cam_Up;

    glm::mat4 cam_View_Matrix;
    glm::mat4 cam_Projection_Matrix;
};

} /* PerspectiveCamera */
} /* GE */

#endif /* RENDERER */
