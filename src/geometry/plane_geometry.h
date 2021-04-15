
#ifndef GE_PLANE_GEOMETRY_H
#define GE_PLANE_GEOMETRY_H

#include <geometry.h>

namespace GE{
namespace Geometry {

class PlaneGeometry : public Geometry_I {
public:
    explicit PlaneGeometry(float width, float height);
    ~PlaneGeometry();

    std::vector<Vertex> Get_Vertices() const;
    std::vector<unsigned int> Get_Indices() const;

private:
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    unsigned int m_width;
    unsigned int m_height;
};

} 
}

#endif /* GE_BOX_GEOMETRY_H */