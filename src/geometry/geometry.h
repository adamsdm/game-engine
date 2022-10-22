
#ifndef GE_GEOMETRY_H
#define GE_GEOMETRY_H

#include <vector>

#include "ge_types.h"

namespace GE {
namespace Geometry {
// TODO Rename interface
class GeometryI {
 public:
  virtual ~GeometryI() = default;
  virtual std::vector<Vertex> getVertices() const = 0;
  virtual std::vector<unsigned int> getIndices() const = 0;
};
}  // namespace Geometry
}  // namespace GE

#endif /* GE_GEOMETRY_H */
