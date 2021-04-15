
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
    }    
    
    PlaneGeometry::~PlaneGeometry(){

    }

    std::vector<Vertex> PlaneGeometry::Get_Vertices() const {
      return Vertices;
    }

    std::vector<unsigned int> PlaneGeometry::Get_Indices() const {
      return Indices;
    }
  } 
}
