#ifndef GE_FIRST_PERSON_CAMERA_CONTROL
#define GE_FIRST_PERSON_CAMERA_CONTROL

#include "app_window.h"
#include "camera.h"

namespace GE {
namespace Camera {
namespace Controls {

class FirstPersonCameraControl {
 public:
  FirstPersonCameraControl(GE::Camera::CameraI& cam, GE::AppWindow& window,
                           float cameraSpeed = 5.0);
  ~FirstPersonCameraControl();

  void update(float deltaTime);

 private:
  GE::AppWindow& m_window;
  GE::Camera::CameraI& m_cam;
  float m_cameraSpeed;

  // For mouse control
  bool m_firstMouse;
  bool m_mouseDisabled;
  double m_lastX;
  double m_lastY;
  float m_yaw;
  float m_pitch;

  void onMouseMovement(float xpos, float ypos);
};

}  // namespace Controls
}  // namespace Camera
}  // namespace GE

#endif /* GE_FIRST_PERSON_CAMERA_CONTROL */
