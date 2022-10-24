#ifndef SRC_GEOMETRY_BASIC_GEOMETRY_H_
#define SRC_GEOMETRY_BASIC_GEOMETRY_H_

#include <geometry.h>

namespace GE {
namespace Geometry {

class BasicGeometry : public GeometryI {
 public:
  BasicGeometry(const std::vector<Vertex>& vertices,
                const std::vector<unsigned int>& indices);
  virtual ~BasicGeometry();

  std::vector<Vertex> getVertices() const override;
  std::vector<unsigned int> getIndices() const override;

 private:
  std::vector<Vertex> m_vertices;
  std::vector<unsigned int> m_indices;
};
}  // namespace Geometry
}  // namespace GE

#endif /* SRC_GEOMETRY_BOX_GEOMETRY_H_ */
