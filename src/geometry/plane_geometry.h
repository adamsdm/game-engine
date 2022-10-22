
#ifndef GE_PLANE_GEOMETRY_H
#define GE_PLANE_GEOMETRY_H

#include <geometry.h>

namespace GE {
namespace Geometry {

class PlaneGeometry : public GeometryI {
 public:
  explicit PlaneGeometry(float width, float height);
  explicit PlaneGeometry(float width, float height, unsigned int width_segments,
                         unsigned int heigth_segments);
  ~PlaneGeometry();

  std::vector<Vertex> getVertices() const;
  std::vector<unsigned int> getIndices() const;

 private:
  // TODO Rename
  std::vector<Vertex> m_vertices;
  std::vector<unsigned int> m_indices;

  unsigned int m_width;
  unsigned int m_height;
  unsigned int m_width_segments;
  unsigned int m_heigth_segments;
};

}  // namespace Geometry
}  // namespace GE

#endif /* GE_BOX_GEOMETRY_H */