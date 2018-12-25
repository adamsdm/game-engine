#include "window.h"

namespace GE {

    Window::Window(const unsigned int Width, const unsigned int Height){
        if (!glfwInit())
            exit(EXIT_FAILURE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        m_window = glfwCreateWindow(Width, Height, "Simple example", NULL, NULL);
        if (!m_window){
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        glfwSwapInterval(1);

        while (!glfwWindowShouldClose(m_window))
        {
        
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }

    }

    Window::~Window(){
        delete m_window;
    }

    void Window::error_callback(int error, const char* description){
        fprintf(stderr, "Error: %s\n", description);
    }

}