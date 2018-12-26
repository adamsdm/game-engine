
#include "renderer.h"
#include <iostream>

namespace GE {

Renderer::Renderer(AppWindow window) :
    m_window(window.Get_Ref()),
    m_clear_color(0.0f),
    m_width(0),
    m_height(0)
{

}

Renderer::~Renderer(){
    
}

void Renderer::Set_Clear_Color(float red, float green, float blue, float alpha){
    m_clear_color.r = red;
    m_clear_color.g = green;
    m_clear_color.b = blue;
    m_clear_color.a = alpha;
};

void Renderer::Set_Size(const unsigned int width, const unsigned int height){
    m_width = width;
    m_height = width;
}

void Renderer::Render(){
    glClearColor(m_clear_color.r, m_clear_color.g, m_clear_color.b, m_clear_color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // TODO: Render logic 


    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

} /* GE */