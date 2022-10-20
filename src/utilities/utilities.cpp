/*
 * utilities.cpp
 *
 *  Created on: 29 Dec 2018
 *      Author: adamsoderstrom
 */

#include "utilities.h"

namespace GE {
namespace Utilities {

std::string Read_From_File(const char* path) {
  std::string code;
  std::ifstream file;

  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    // open files
    file.open(path);

    std::stringstream stream;
    // read file's buffer contents into streams
    stream << file.rdbuf();

    // close file handlers
    file.close();
    // convert stream into string
    code = stream.str();

  } catch (std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    exit(-1);
  }

  return code;
}

}  // namespace Utilities
}  // namespace GE
