/*
 * ge_types.h
 *
 *  Created on: 14 Apr 2021
 *      Author: adamsoderstrom
 */

#ifndef SRC_UTILITIES_GE_TYPES_H_
#define SRC_UTILITIES_GE_TYPES_H_

#include <glm/glm.hpp>
#include <string>

namespace GE {
struct Vertex {
  glm::vec3 Position;
  glm::vec3 Normal;
  glm::vec2 TexCoords;
};

struct Texture {
  unsigned int id;
  std::string type;
};
}  // namespace GE

#endif  //SRC_UTILITIES_GE_TYPES_H_