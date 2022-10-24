#include "basic_geometry.h"

namespace GE {
namespace Geometry {

BasicGeometry::BasicGeometry(const std::vector<Vertex>& vertices,
                             const std::vector<unsigned int>& indices)
    : m_vertices{vertices}, m_indices{indices} {}

BasicGeometry::~BasicGeometry() {
  ;
}

std::vector<Vertex> BasicGeometry::getVertices() const {
  return m_vertices;
}
std::vector<unsigned int> BasicGeometry::getIndices() const {
  return m_indices;
}

}  // namespace Geometry
}  // namespace GE
