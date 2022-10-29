#ifndef GE_WINDOW_H
#define GE_WINDOW_H

#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <vector>
#include "GLFW/glfw3.h"

namespace GE {
namespace Events {
class KeyEventSubscriberI;
}

using KeyEventCallback = std::function<void(int, int, int, int)>;
using MousePosEventCallback = std::function<void(int, int)>;
using ResizeEventCallback = std::function<void(int, int)>;

class AppWindow {
 public:
  AppWindow(unsigned int width, unsigned int height);
  ~AppWindow();

  bool shouldClose();
  GLFWwindow* get();
  unsigned int getWidth() const;
  unsigned int getHeight() const;

  void close() const;

  void addKeyEventCallback(const KeyEventCallback& cb);
  void addMousePosEventCallback(const MousePosEventCallback& cb);
  void addResizeEventCallback(const ResizeEventCallback& cb);

  void notifyKeySubscribers(int key, int scancode, int action, int mods);
  void notifyMousePosSubscribers(int xpos, int ypos);
  void notifyWindowResizeSubscribers(int width, int height);

 private:
  GLFWwindow* m_window;
  unsigned int m_width;
  unsigned int m_height;

  std::vector<KeyEventCallback> m_keyEventCallbacks;
  std::vector<MousePosEventCallback> m_mouseEventCallbacks;
  std::vector<ResizeEventCallback> m_resizeEventCallbacks;
};

}  // namespace GE

#endif /* GE_WINDOW_H */
