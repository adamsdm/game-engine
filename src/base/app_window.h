

#ifndef GE_WINDOW_H
#define GE_WINDOW_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <stdlib.h>

namespace GE {
class AppWindow {
public:
  AppWindow(const unsigned int Width, const unsigned int Height);
  ~AppWindow();

  bool shouldClose();
  GLFWwindow* get(); 
  unsigned int getWidth() const;
  unsigned int getHeight() const;

 private:
 // TODO This should not be a raw ptr
  GLFWwindow* m_window;
  unsigned int m_width;
  unsigned int m_height;

  static void ErrorCallback(int error, const char* description);
  static void KeyCallback(GLFWwindow* window, int key, int scancode, int action,
                          int mods);
};

}  // namespace GE

#endif /* GE_WINDOW_H */
