

#ifndef GE_WINDOW_H
#define GE_WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

namespace GE {
class Window{
public: 
    Window(const unsigned int Width, const unsigned int Height);
    ~Window();
private:
    GLFWwindow* m_window;

    void error_callback(int error, const char* description);
};

}

#endif /* GE_WINDOW_H */