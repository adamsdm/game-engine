
#include "geometry.h"


namespace GE{
  namespace Geometry {
    BoxGeometry::BoxGeometry(unsigned int width, unsigned int height, unsigned int depth) :
      m_width(width),
      m_height(height),
      m_depth(depth)
    {
    }    
    
    BoxGeometry::~BoxGeometry(){

    }
  } 
}