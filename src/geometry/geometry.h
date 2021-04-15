
#ifndef GE_GEOMETRY_H
#define GE_GEOMETRY_H

#include <vector>

#include "ge_types.h"

namespace GE{
    namespace Geometry {
        class Geometry_I{
        public:

            virtual ~Geometry_I() {};

            virtual void Render() const = 0;
            virtual std::vector<Vertex> Get_Vertices() const = 0;
            virtual std::vector<unsigned int> Get_Indices() const = 0;
        };
    } 
}

#endif /* GE_GEOMETRY_H */
