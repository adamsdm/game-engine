
#ifndef GE_GEOMETRY_H
#define GE_GEOMETRY_H

#include <vector>

#include "ge_types.h"

namespace GE {
namespace Geometry {
// TODO Rename interface
class Geometry_I {
 public:
  virtual ~Geometry_I() = default;
  virtual std::vector<Vertex> Get_Vertices() const = 0;
  virtual std::vector<unsigned int> Get_Indices() const = 0;
};
}  // namespace Geometry
}  // namespace GE

#endif /* GE_GEOMETRY_H */
