#include "core/box.h"
#include "math.h"
#include "algorithm"

Box::Box(const Vector3D &v1, const Vector3D &v2)
{
    double dx = std::fabs(v1.getX() - v2.getX());
    double dy = std::fabs(v1.getY() - v2.getY());
    double dz = std::fabs(v1.getZ() - v2.getZ());

    if(v1 == v2 || std::fabs(dx - dy) > 0.0001 || std::fabs(dx - dz) > 0.0001)
    {
        throw "IllegalArgumentException. Vectors does not represent a Box. ";
    }
    _minCorner = Vector3D(std::min(v1.getX(), v2.getX()), std::min(v1.getY(), v2.getY()),  std::min(v1.getZ(), v2.getZ()));
    _maxCorner = Vector3D(std::max(v1.getX(), v2.getX()), std::max(v1.getY(), v2.getY()),  std::max(v1.getZ(), v2.getZ()));
}

void Box::setMinCorner(const Vector3D &corner)
{
    _minCorner = corner;
}

void Box::setMaxCorner(const Vector3D &corner)
{
    _maxCorner = corner;
}

const Vector3D Box::getCorner(short index) const
{
    switch(index)
    {
    case 0:
        return _minCorner;
    case 1:
        return Vector3D(_minCorner.getX(), _minCorner.getY(), _maxCorner.getZ());
    case 2:
        return Vector3D(_minCorner.getX(), _maxCorner.getY(), _minCorner.getZ());
    case 3:
        return Vector3D(_minCorner.getX(), _maxCorner.getY(), _maxCorner.getZ());
    case 4:
        return Vector3D(_maxCorner.getX(), _minCorner.getY(), _minCorner.getZ());
    case 5:
        return Vector3D(_maxCorner.getX(), _minCorner.getY(), _maxCorner.getZ());
    case 6:
        return Vector3D(_maxCorner.getX(), _maxCorner.getY(), _minCorner.getZ());
    case 7:
        return _maxCorner;
    default:
        throw "IllegalArgumentException";
    }
}

double Box::side() const
{
    return _minCorner.distance(getCorner(1));
}

double Box::volume() const
{
    return std::pow(side(), 3);
}

double Box::area() const
{
    return std::pow(side(), 2) * 6;
}

Vector3D Box::center() const
{
    return (_minCorner + _maxCorner) / 2;
}

void Box::traslate(const Vector3D &traslationVector)
{
    _minCorner  += traslationVector;
    _maxCorner  += traslationVector;
}

bool Box::operator ==(const Box &box) const
{
    return _minCorner == box._minCorner &&_maxCorner == box._maxCorner;
}

bool Box::operator !=(const Box &box) const
{
    return _minCorner != box._minCorner || _maxCorner != box._maxCorner;
}

bool Box::operator <(const Vector3D &vector) const
{
    return !(vector.getX() >= _minCorner.getX() && vector.getX() <= _maxCorner.getX() &&
             vector.getY() >= _minCorner.getY() && vector.getY() <= _maxCorner.getY() &&
             vector.getZ() >= _minCorner.getZ() && vector.getZ() <= _maxCorner.getZ());
}

bool Box::operator >(const Vector3D &vector) const
{
    return  (vector.getX() >= _minCorner.getX() && vector.getX() <= _maxCorner.getX() &&
             vector.getY() >= _minCorner.getY() && vector.getY() <= _maxCorner.getY() &&
             vector.getZ() >= _minCorner.getZ() && vector.getZ() <= _maxCorner.getZ());
}

bool Box::operator <(const Box &box) const
{
    for(short i = 0; i < 8; i++)
    {
        if(box < getCorner(i))
        {
            return false;
        }
    }

    return true;
}

bool Box::operator >(const Box &box) const
{
    for(short i = 0; i < 8; i++)
    {
        if(*this < box.getCorner(i))
        {
            return false;
        }
    }

    return true;
}

bool Box::operator ^(const Box &box) const
{
    for(short i = 0; i < 8; i++)
    {
        if(box > this->getCorner(i))
        {
            return true;
        }

        if(*this > box.getCorner(i))
        {
            return true;
        }
    }

    return false;
}

Box &Box::operator=(const Box &box)
{
    _minCorner = box._minCorner;
    _maxCorner = box._maxCorner;

    return *this;
}
