
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
      
      Vertices = {
          Vertex{ glm::vec3( half_w,  half_h, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},  
          Vertex{ glm::vec3( half_w, -half_h, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},  
          Vertex{ glm::vec3(-half_w, -half_h, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},  
          Vertex{ glm::vec3(-half_w,  half_h, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
      };
      Indices = {
          0, 1, 3,  // first Triangle
          1, 2, 3   // second Triangle
      };
      
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glGenBuffers(1, &EBO);
      // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);

      // position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0 );
      glEnableVertexAttribArray(0);

      // texture coord attribute
      glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, Normal) );
      glEnableVertexAttribArray(1);

      // normal attribute
      glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, TexCoords) );
      glEnableVertexAttribArray(2);

      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      glBindVertexArray(0); 

    }    
    
    PlaneGeometry::~PlaneGeometry(){

    }

    std::vector<Vertex> PlaneGeometry::Get_Vertices() const {
      return Vertices;
    }

    std::vector<unsigned int> PlaneGeometry::Get_Indices() const {
      return Indices;
    }

    void PlaneGeometry::Render() const {
      glBindVertexArray(VAO);
      glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);
    }
  } 
}
