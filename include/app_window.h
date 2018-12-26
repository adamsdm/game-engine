

#ifndef GE_WINDOW_H
#define GE_WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

namespace GE {
class AppWindow{
public: 
    AppWindow(const unsigned int Width, const unsigned int Height);
    ~AppWindow();

    bool Should_Close();
    GLFWwindow* Get_Ref();
    const unsigned int Get_Width() const;
    const unsigned int Get_Height() const;

private:
    GLFWwindow* m_window;
    bool m_isRunning;
    unsigned int m_width;
    unsigned int m_height;
    
    void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

}

#endif /* GE_WINDOW_H */