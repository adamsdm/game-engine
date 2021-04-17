#include "app_window.h"

#include <iostream>

namespace GE {

    AppWindow::AppWindow(const unsigned int Width, const unsigned int Height) : 
        m_width(Width),
        m_height(Height)
    {
        if (!glfwInit()){
        	std::cerr << "ERROR:: Failed to initialize GLFW" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

        m_window = glfwCreateWindow(Width, Height, "Simple example", NULL, NULL);
        if (!m_window){
            glfwTerminate();
            std::cerr << "ERROR:: Failed to create GLFW window" << std::endl;
            exit(EXIT_FAILURE);
        }
        glfwSetKeyCallback(m_window, key_callback);
        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        glfwSwapInterval(1);

        // Configure global opengl state
        glEnable(GL_DEPTH_TEST);
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
        if (key == GLFW_KEY_E && action == GLFW_PRESS){
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        } else if(key == GLFW_KEY_R && action == GLFW_PRESS){
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        }
    }

}
