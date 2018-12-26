
#ifndef GE_PLANE_GEOMETRY_H
#define GE_PLANE_GEOMETRY_H

#include <glad/glad.h>
#include "interfaces/geometry_i.h"

namespace GE{
namespace Geometry {

class PlaneGeometry : public Geometry_I {
public:
    explicit PlaneGeometry(float width, float height);
    ~PlaneGeometry();
    void Render() const;

    int Get_VAO_ID();

private:

    unsigned int VBO; 
    unsigned int VAO;
    unsigned int EBO;

    unsigned int m_width;
    unsigned int m_height;
};

} 
}

#endif /* GE_BOX_GEOMETRY_H */