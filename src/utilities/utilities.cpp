#include "utilities.h"

namespace GE {
namespace Utilities {

// TODO Rename this file
std::string Read_From_File(const char* path) {
  std::string code;
  std::ifstream file;

  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  // TODO Refactor try catch
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
