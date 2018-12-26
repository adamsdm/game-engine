
#include "plane_geometry.h"


namespace GE{
  namespace Geometry {
    PlaneGeometry::PlaneGeometry(float width, float height) :
      m_width(width),
      m_height(height)
    {
      // TODO: Abstract this into functions
      float half_w = width/2.0f;
      float half_h = height/2.0f;
      
      float vertices[] = {
           half_w,  half_h, 0.0f,  // top right
           half_w, -half_h, 0.0f,  // bottom right
          -half_w, -half_h, 0.0f,  // bottom left
          -half_w,  half_h, 0.0f   // top left 
      };
      unsigned int indices[] = {
          0, 1, 3,  // first Triangle
          1, 2, 3   // second Triangle
      };
      
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glGenBuffers(1, &EBO);
      // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);

      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      glBindVertexArray(0); 

    }    
    
    PlaneGeometry::~PlaneGeometry(){

    }

    void PlaneGeometry::Render() const {
      glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    int PlaneGeometry::Get_VAO_ID(){
      return VAO;
    }
  } 
}