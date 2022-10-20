
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
  float half_w = m_width / 2.0f;
  float half_h = m_height / 2.0f;

  float segmentWidth =
      static_cast<float>(m_width) / static_cast<float>(m_width_segments);
  float segmentHeight =
      static_cast<float>(m_height) / static_cast<float>(m_heigth_segments);

  // Setup vertices
  for (int i = 0; i < m_heigth_segments + 1; i++) {
    float y = segmentHeight * i - half_h;
    for (int j = 0; j < m_width_segments + 1; j++) {
      float x = j * segmentWidth - half_w;

      Vertex v;
      v.Position.x = x;
      v.Position.y = -y;
      v.Position.z = 0.0f;
      v.Normal.x = 0.0f;
      v.Normal.y = 0.0f;
      v.Normal.z = 1.0f;
      v.TexCoords.s = j / m_width_segments;
      v.TexCoords.t = i / m_heigth_segments;

      Vertices.push_back(v);
    }
  }

  // Setup indices
  for (int i = 0; i < m_heigth_segments; i++) {
    for (int j = 0; j < m_width_segments; j++) {
      unsigned int a = j + (m_width_segments + 1) * i;
      unsigned int b = j + (m_width_segments + 1) * (i + 1);
      unsigned int c = (j + 1) + (m_width_segments + 1) * (i + 1);
      unsigned int d = (j + 1) + (m_width_segments + 1) * i;

      Indices.push_back(a);
      Indices.push_back(b);
      Indices.push_back(d);

      Indices.push_back(b);
      Indices.push_back(c);
      Indices.push_back(d);
    }
  }
}

PlaneGeometry::~PlaneGeometry() = default;

std::vector<Vertex> PlaneGeometry::Get_Vertices() const {
  return Vertices;
}

std::vector<unsigned int> PlaneGeometry::Get_Indices() const {
  return Indices;
}
}  // namespace Geometry
}  // namespace GE
