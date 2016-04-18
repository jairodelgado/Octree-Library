#include "geometry/point.h"

Point::Point(std::initializer_list<Vector3D *> point) : Geometry(point)
{
    if(count() != 1)
    {
        throw "IllegalArgumentException. Index out of bounds";
    }
}

bool Point::isIn(const Box &box) const
{
    for(const Vector3D * vector : _vectors)
    {
        if(box > *vector)
        {
            return true;
        }
    }
    return false;
}

bool Point::isIn(Vector3D &center, double &radius) const
{
    return center.distance(*get(0)) <= radius;
}
