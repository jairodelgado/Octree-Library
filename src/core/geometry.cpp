#include "core/geometry.h"

Geometry::Geometry(std::initializer_list<Vector3D *> vectors)
{
    for(Vector3D *vector : vectors)
    {
        _vectors.push_back(vector);
    }
    _vectors.shrink_to_fit();
}

const Vector3D *Geometry::get(short index) const
{
    return _vectors.at(index);
}

void Geometry::set(short index, Vector3D *vector)
{
    _vectors.at(index) = vector;
}

short Geometry::count() const
{
    return _vectors.size();
}


