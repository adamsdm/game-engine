

#ifndef GE_RENDERER_H
#define GE_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>

#include "app_window.h"

namespace GE {

class Renderer{
public:
    Renderer(AppWindow window);
    ~Renderer();

    void Set_Clear_Color(float red, float green, float blue, float alpha);
    void Set_Size(const unsigned int width, const unsigned int height);
    
    void Render();

private:
    GLFWwindow* m_window;
    glm::vec4 m_clear_color;
    unsigned int m_width;
    unsigned int m_height;
};

}

#endif /* RENDERER */