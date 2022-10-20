
#ifndef GE_PLANE_GEOMETRY_H
#define GE_PLANE_GEOMETRY_H

#include <geometry.h>

namespace GE {
namespace Geometry {

class PlaneGeometry : public Geometry_I {
 public:
  explicit PlaneGeometry(float width, float height);
  explicit PlaneGeometry(float width, float height, unsigned int width_segments,
                         unsigned int heigth_segments);
  ~PlaneGeometry();

  std::vector<Vertex> Get_Vertices() const;
  std::vector<unsigned int> Get_Indices() const;

 private:
  // TODO Rename
  std::vector<Vertex> Vertices;
  std::vector<unsigned int> Indices;

  unsigned int m_width;
  unsigned int m_height;
  unsigned int m_width_segments;
  unsigned int m_heigth_segments;
};

}  // namespace Geometry
}  // namespace GE

#endif /* GE_BOX_GEOMETRY_H */