#include "plane_geometry.h"

#include <iostream>

namespace GE {
namespace Geometry {

PlaneGeometry::PlaneGeometry(float width, float height)
    : PlaneGeometry(width, height, 1, 1) {
  ;
}

PlaneGeometry::PlaneGeometry(float width, float height,
                             unsigned int width_segments,
                             unsigned int heigth_segments)
    : m_width(width),
      m_height(height),
      m_heigth_segments(heigth_segments),
      m_width_segments(width_segments) {
  float halfW = m_width / 2.0f;
  float halfH = m_height / 2.0f;

  // TODO Rename to follow convention
  float segmentWidth =
      static_cast<float>(m_width) / static_cast<float>(m_width_segments);
  float segmentHeight =
      static_cast<float>(m_height) / static_cast<float>(m_heigth_segments);

  // Setup vertices
  for (int i = 0; i < m_heigth_segments + 1; i++) {
    float y = segmentHeight * i - halfH;
    for (int j = 0; j < m_width_segments + 1; j++) {
      float x = j * segmentWidth - halfW;

      Vertex v;
      v.Position.x = x;
      v.Position.y = -y;
      v.Position.z = 0.0f;
      v.Normal.x = 0.0f;
      v.Normal.y = 0.0f;
      v.Normal.z = 1.0f;
      v.TexCoords.s = j / m_width_segments;
      v.TexCoords.t = i / m_heigth_segments;

      m:m_vertices.push_back(v);
    }
  }

  // Setup indices
  for (int i = 0; i < m_heigth_segments; i++) {
    for (int j = 0; j < m_width_segments; j++) {
      // TODO This could use an explanatory comment
      unsigned int a = j + (m_width_segments + 1) * i;
      unsigned int b = j + (m_width_segments + 1) * (i + 1);
      unsigned int c = (j + 1) + (m_width_segments + 1) * (i + 1);
      unsigned int d = (j + 1) + (m_width_segments + 1) * i;

      m_indices.push_back(a);
      m_indices.push_back(b);
      m_indices.push_back(d);

      m_indices.push_back(b);
      m_indices.push_back(c);
      m_indices.push_back(d);
    }
  }
}

PlaneGeometry::~PlaneGeometry() = default;

std::vector<Vertex> PlaneGeometry::getVertices() const {
  return m_vertices;
}

std::vector<unsigned int> PlaneGeometry::getIndices() const {
  return m_indices;
}
}  // namespace Geometry
}  // namespace GE
