#ifndef SRC_UTILITIES_UTILITIES_H_
#define SRC_UTILITIES_UTILITIES_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <glad/glad.h>

namespace GE {
namespace Utilities {

GLenum getTextureFormat(int nrChannels);

std::string readFromFile(const char* path);

}  // namespace Utilities
}  // namespace GE

#endif /* SRC_UTILITIES_UTILITIES_H_ */
