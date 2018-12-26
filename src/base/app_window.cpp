#include "app_window.h"

namespace GE {

    AppWindow::AppWindow(const unsigned int Width, const unsigned int Height) : 
        m_width(Width),
        m_height(Height)
    {
        if (!glfwInit())
            exit(EXIT_FAILURE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        m_window = glfwCreateWindow(Width, Height, "Simple example", NULL, NULL);
        if (!m_window){
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetKeyCallback(m_window, key_callback);

        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        glfwSwapInterval(1);
    }
    
    AppWindow::~AppWindow(){
    }
    
    GLFWwindow* AppWindow::Get_Ref(){
        return m_window;
    }

    const unsigned int AppWindow::Get_Width() const {
        return m_width;
    }
    const unsigned int AppWindow::Get_Height() const {
        return m_height;
    }

    bool AppWindow::Should_Close(){
        return glfwWindowShouldClose(m_window);
    }

    void AppWindow::error_callback(int error, const char* description){
        fprintf(stderr, "Error: %s\n", description);
    }

    void AppWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

}