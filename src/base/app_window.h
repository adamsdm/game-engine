

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

  bool Should_Close();
  GLFWwindow* Get_Ref();
  const unsigned int Get_Width() const;
  const unsigned int Get_Height() const;

 private:
  GLFWwindow* m_window;
  unsigned int m_width;
  unsigned int m_height;

  static void error_callback(int error, const char* description);
  static void key_callback(GLFWwindow* window, int key, int scancode,
                           int action, int mods);
};

}  // namespace GE

#endif /* GE_WINDOW_H */
