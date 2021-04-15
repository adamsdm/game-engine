/*
 * box_geometry.h
 *
 *  Created on: 30 Dec 2018
 *      Author: adamsoderstrom
 */

#ifndef SRC_GEOMETRY_BOX_GEOMETRY_H_
#define SRC_GEOMETRY_BOX_GEOMETRY_H_

#include <geometry.h>

namespace GE{
namespace Geometry {

class BoxGeometry: public Geometry_I {
public:
	BoxGeometry(float width, float height, float depth);
	virtual ~BoxGeometry();

    std::vector<Vertex> Get_Vertices() const override;
    std::vector<unsigned int> Get_Indices() const override;

private:
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;

    float m_width;
    float m_height;
    float m_depth;
};
}
}

#endif /* SRC_GEOMETRY_BOX_GEOMETRY_H_ */
