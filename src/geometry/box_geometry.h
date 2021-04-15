/*
 * box_geometry.h
 *
 *  Created on: 30 Dec 2018
 *      Author: adamsoderstrom
 */

#ifndef SRC_GEOMETRY_BOX_GEOMETRY_H_
#define SRC_GEOMETRY_BOX_GEOMETRY_H_

#include <geometry.h>
#include <glad/glad.h>
#include <vector>
#include <ge_types.h>

namespace GE{
namespace Geometry {

class BoxGeometry: public Geometry_I {
public:
	BoxGeometry(float width, float height, float depth);
	virtual ~BoxGeometry();
	void Render() const override;

    std::vector<Vertex> Get_Vertices() const override;
    std::vector<unsigned int> Get_Indices() const override;

private:
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;

    float m_width;
    float m_height;
    float m_depth;
};
}
}

#endif /* SRC_GEOMETRY_BOX_GEOMETRY_H_ */
