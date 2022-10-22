/*
 * box_geometry.h
 *
 *  Created on: 30 Dec 2018
 *      Author: adamsoderstrom
 */

#ifndef SRC_GEOMETRY_BOX_GEOMETRY_H_
#define SRC_GEOMETRY_BOX_GEOMETRY_H_

#include <geometry.h>

namespace GE {
namespace Geometry {

class BoxGeometry : public GeometryI {
 public:
  // TODO Set default values of these
  BoxGeometry(float width, float height, float depth);
  virtual ~BoxGeometry();

  std::vector<Vertex> getVertices() const override;
  std::vector<unsigned int> getIndices() const override;

 private:
  std::vector<Vertex> m_vertices;
  std::vector<unsigned int> m_indices;

  // TODO These are currently unused
  float m_width;
  float m_height;
  float m_depth;
};
}  // namespace Geometry
}  // namespace GE

#endif /* SRC_GEOMETRY_BOX_GEOMETRY_H_ */
