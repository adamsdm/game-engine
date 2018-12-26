
#ifndef GE_GEOMETRY_H
#define GE_GEOMETRY_H

namespace GE{
    namespace Geometry {
        class Geometry_I{
        public:
            virtual void Render() const = 0;
            virtual ~Geometry_I() {};
        };
    } 
}

#endif /* GE_GEOMETRY_H */
