#include "model.h"

#include <iostream>
#include <numeric>

#ifndef TINYOBJLOADER_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION
#endif
#include <tiny_obj_loader.h>

namespace GE {

Model::Model(const std::string& obj_path, const std::string& mtl_search_path)
    : m_position(0.0f), m_rotation(0.0f, 1.0f, 0.0f, 0.0f), m_scale(1.0f) {
  loadModel(obj_path, mtl_search_path);
}

Model::~Model() = default;

void Model::setPosition(float x, float y, float z) {
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
  for (auto& mesh : m_meshes) {
    mesh.setPosition(x, y, z);
  }
}
void Model::setRotation(float angle, float x, float y, float z) {
  m_rotation.x = x;
  m_rotation.y = y;
  m_rotation.z = z;
  m_rotation.w = angle;
  for (auto& mesh : m_meshes) {
    mesh.setRotation(angle, x, y, z);
  }
}

glm::vec3 Model::getPosition() const {
  return m_position;
}

glm::vec4 Model::getRotation() const {
  return m_rotation;
}

void Model::render(const Camera::CameraI& cam) const {
  for (auto& mesh : m_meshes) {
    mesh.render(cam);
  }
}

void Model::loadModel(const std::string& obj_path,
                      const std::string& mtl_search_path) {

  tinyobj::ObjReaderConfig readerConfig;

  readerConfig.mtl_search_path = mtl_search_path;
  readerConfig.triangulate = true;

  tinyobj::ObjReader reader;

  if (!reader.ParseFromFile(obj_path, readerConfig)) {
    if (!reader.Error().empty()) {
      std::cerr << "TinyObjReader: " << reader.Error();
    }
    exit(1);
  }

  if (!reader.Warning().empty()) {
    std::cout << "TinyObjReader: " << reader.Warning();
  }

  auto& attrib = reader.GetAttrib();
  auto& shapes = reader.GetShapes();
  auto& materials = reader.GetMaterials();

  // Loop over shapes
  for (const auto& shape : shapes) {

    auto indices{setupIndiceVec(shape)};
    auto vertices{setupVertices(shape, attrib)};

    auto geo{std::make_unique<GE::Geometry::BasicGeometry>(vertices, indices)};

    auto diff_tex_path{mtl_search_path + materials.at(0).diffuse_texname};
    auto mat{std::make_unique<GE::Material::MeshPhongMaterial>(diff_tex_path)};

    m_meshes.push_back(GE::Mesh(*geo, *mat));

    m_upGeometries.push_back(std::move(geo));
    m_upMaterials.push_back(std::move(mat));
  }
}

std::vector<unsigned int> Model::setupIndiceVec(const tinyobj::shape_t& shape) {
  // Fill indices vector with increasing values [0, 1,..,N]
  // where N=the number of indices
  const auto NUMBER_OF_INDICES{shape.mesh.indices.size()};
  std::vector<unsigned int> indices(NUMBER_OF_INDICES);
  std::iota(std::begin(indices), std::end(indices), 0);
  return indices;
}

std::vector<GE::Vertex> Model::setupVertices(const tinyobj::shape_t& shape,
                                             const tinyobj::attrib_t& attrib) {
  std::vector<GE::Vertex> vertices;

  // Each 'idx' contains indexes to the VertexPos, Normal and TexCoord
  for (auto const& idx : shape.mesh.indices) {
    GE::Vertex vertex{};

    vertex.Position.x = attrib.vertices[3 * size_t(idx.vertex_index) + 0];
    vertex.Position.y = attrib.vertices[3 * size_t(idx.vertex_index) + 1];
    vertex.Position.z = attrib.vertices[3 * size_t(idx.vertex_index) + 2];

    // Check if `normal_index` is zero or positive. negative = no normal data
    if (idx.normal_index >= 0) {
      vertex.Normal.x = attrib.normals[3 * size_t(idx.normal_index) + 0];
      vertex.Normal.y = attrib.normals[3 * size_t(idx.normal_index) + 1];
      vertex.Normal.z = attrib.normals[3 * size_t(idx.normal_index) + 2];
    }

    // Check if `texcoord_index` is zero or positive. negative = no texcoord data
    if (idx.texcoord_index >= 0) {
      vertex.TexCoords.s = attrib.texcoords[2 * size_t(idx.texcoord_index) + 0];
      vertex.TexCoords.t = attrib.texcoords[2 * size_t(idx.texcoord_index) + 1];
    }
    vertices.push_back(vertex);
  }

  return vertices;
}

};  // namespace GE
