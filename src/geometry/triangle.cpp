#include "geometry/triangle.h"

Triangle::Triangle(std::initializer_list<Vector3D *> triangle) : Geometry(triangle)
{
    if(count() != 3)
    {
        throw "IllegalArgumentException. Index out of bounds";
    }
}


bool Triangle::isIn(const Box &box) const
{
    return false;
}


bool Triangle::isIn(Vector3D &center, double &radius) const
{
    return false;
}
