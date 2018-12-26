
#ifndef GE_BOX_GEOMETRY_H
#define GE_BOX_GEOMETRY_H

#include "interfaces/geometry_i.h"

namespace GE{
namespace Geometry {

class BoxGeometry : public Geometry_I {
public:
    explicit BoxGeometry(unsigned int width, unsigned int height, unsigned int depth);
    ~BoxGeometry();
    void render();

private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_depth;
};

} 
}

#endif /* GE_BOX_GEOMETRY_H */