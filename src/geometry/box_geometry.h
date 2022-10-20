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

class BoxGeometry : public Geometry_I {
 public:
  // TODO Set default values of these
  BoxGeometry(float width, float height, float depth);
  virtual ~BoxGeometry();

  std::vector<Vertex> Get_Vertices() const override;
  std::vector<unsigned int> Get_Indices() const override;

 private:
  // TODO Rename to follow convention
  std::vector<Vertex> Vertices;
  std::vector<unsigned int> Indices;

  // TODO These are currently unused
  float m_width;
  float m_height;
  float m_depth;
};
}  // namespace Geometry
}  // namespace GE

#endif /* SRC_GEOMETRY_BOX_GEOMETRY_H_ */
