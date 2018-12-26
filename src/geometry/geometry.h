
#ifndef GE_GEOMETRY_H
#define GE_GEOMETRY_H

namespace GE{
namespace Geometry {

class BoxGeometry{
public:
    BoxGeometry(unsigned int width, unsigned int height, unsigned int depth);
    ~BoxGeometry();

private:
    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_depth;
};

} 
}

#endif /* GE_GEOMETRY_H */