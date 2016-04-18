#include "core/vector3d.h"
#include "math.h"

Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Vector3D::getX() const
{
    return _x;
}

double Vector3D::getY() const
{
    return _y;
}

double Vector3D::getZ() const
{
    return _z;
}

void Vector3D::setX(double x)
{
    _x = x;
}

void Vector3D::setY(double y)
{
    _y = y;
}

void Vector3D::setZ(double z)
{
    _z = z;
}

double Vector3D::distance(const Vector3D &vector) const
{
    return sqrt(pow(_x - vector._x, 2) + pow(_y - vector._y, 2) + pow(_z - vector._z, 2));
}
Vector3D Vector3D::absolute() const
{
    Vector3D result(fabs(_x), fabs(_y), fabs(_z));
    return result;
}

Vector3D Vector3D::operator+(const Vector3D &vector) const
{
    return Vector3D(_x + vector._x, _y + vector._y, _z + vector._z);
}

Vector3D Vector3D::operator-(const Vector3D &vector) const
{
    return Vector3D(_x - vector._x, _y - vector._y, _z - vector._z);
}

Vector3D Vector3D::operator*(double scalar) const
{
    return Vector3D(_x * scalar, _y * scalar, _z  * scalar);
}

Vector3D Vector3D::operator/(double scalar) const
{
    return Vector3D(_x / scalar, _y / scalar, _z / scalar);
}

Vector3D &Vector3D::operator+=(const Vector3D &vector)
{
    _x += vector.getX();
    _y += vector.getY();
    _z += vector.getZ();

    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &vector)
{
    _x -= vector.getX();
    _y -= vector.getY();
    _z -= vector.getZ();

    return *this;
}

Vector3D &Vector3D::operator*=(double scalar)
{
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;

    return *this;
}

Vector3D &Vector3D::operator/=(double scalar)
{
    if(scalar == 0)
    {
        throw "IllegalArgumentException. Division by zero";
    }
    _x /= scalar;
    _y /= scalar;
    _z /= scalar;

    return *this;
}

Vector3D &Vector3D::operator=(const Vector3D &vector)
{
    _x = vector.getX();
    _y = vector.getY();
    _z = vector.getZ();

    return *this;
}

bool Vector3D::operator==(const Vector3D &vector) const
{
    return _x == vector._x && _y == vector._y && _z == vector._z;
}

bool Vector3D::operator!=(const Vector3D &vector) const
{
    return !(_x == vector._x && _y == vector._y && _z == vector._z) ;
}

