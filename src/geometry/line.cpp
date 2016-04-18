#include "geometry/line.h"
#include "math.h"

Line::Line(std::initializer_list<Vector3D *> line) : Geometry(line)
{
    if(count() != 2)
    {
        throw "IllegalArgumentException. Index out of bounds";
    }
}

bool Line::isIn(const Box &box) const
{
    Vector3D d = (box.getCorner(0) - box.getCorner(7)) * 0.5f;

    Vector3D e = (get(0) - get(1)) * 0.5f;

    Vector3D c = (box.getCorner(0) + d) - (*get(0) + *get(1)) * 0.5f;

    Vector3D ad = d.absolute();



    if (fabsf(c.getX()) > e.getX() + ad.getX())
    {
        return false;
    }
    if (fabsf(c.getY() > e.getY() + ad.getY()))
    {
        return false;
    }
    if (fabsf(c.getZ()) > e.getZ() + ad.getZ())
    {
        return false;
    }

    if (fabsf(d.getY() * c.getZ() - d.getZ() * c.getY()) > e.getY() * ad.getZ() + e.getZ() * ad.getY() + 0.001)
    {
        return false;
    }
    if (fabsf(d.getZ() * c.getX() - d.getX() * c.getZ()) > e.getZ() * ad.getX() + e.getX() * ad.getZ() + 0.001)
    {
        return false;
    }
    if (fabsf(d.getX() * c.getY() - d.getY() * c.getX()) > e.getX() * ad.getY() + e.getY() * ad.getX() + 0.001)
    {
        return false;
    }

    return true;
}

bool Line::isIn(Vector3D &center, double &radius) const
{
    return false;
}
