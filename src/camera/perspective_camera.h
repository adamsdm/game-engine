

#ifndef GE_CAMERA_H
#define GE_CAMERA_H

#include <glm/glm.hpp>
#include "interfaces/camera_i.h"

namespace GE {
namespace Camera {

class PerspectiveCamera : public Camera_I {
public: 
    PerspectiveCamera(float fov, float aspect, float near, float far);
    ~PerspectiveCamera();

    void Set_Position(glm::vec3 New_Position);

private:
    float m_fov;
    float m_aspect;
    float m_near;
    float m_far;
    glm::vec3 m_pos;
};

} /* PerspectiveCamera */
} /* GE */

#endif /* RENDERER */
