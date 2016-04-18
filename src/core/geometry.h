/*
 * Copyright (C) <2015> <Jairo Rojas Delgado>.
 *
 * This file is part of <OctreeLib>.
 *
 * The <OctreeLib> is free software: yo can redistribute it and/or modify
 * it under the terms of the GNU General Public Licence as published by
 * the Free Software Foundation, either versión 3 of the Licence, or
 * any later version.
 *
 * The <OctreeLib> is distributed in the hope tha it will be useful,
 * but WITHOUT ANY WARRANY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public Licence for more details.
 *
 * You should have redeived a copy of the GNU General Public Licence
 * along with the <OctreeLib>. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "core/box.h"
#include "core/vector3d.h"
#include "vector"

/*
 * This class represents a geometry in a three-dimensional space. This class is intended to act
 * as an interface to implement by any specific geometry.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date May, 2014.
 */
class Geometry
{
public:

    /*
     * Creates a geometric object with the specified vectors.
     * @params:
     *     std::initializer_list<Vector3D *> vectors : the vectors to requiered to generate
     *     the Geometry.
     */
    Geometry(std::initializer_list<Vector3D *> vectors);

    /*
     * Returns a specific vector of the geometry.
     * @params:
     *      short index   :   The vector number in the geometry.
     *
     * @returns: const *Vector3D, a reference to the requested vector.
     * @throws:
     *      IllegalArgumentException    :   if the specified index does not correspond to a vector.
     */
    const Vector3D *get(short index) const;

    /*
     * Changes a specific vector of the geometry.
     * @params:
     *      short index             :   The vector number in the geometry.
     *      const Vector3D *vector  :   A reference to the new vector.
     * @throws:
     *      IllegalArgumentException    :   if the specified index does not correspond to a vector.
     */
    void set(short index, Vector3D *vector);

    /*
     * Returns the amount of vectors in the geometry.
     * @returns : short, the amount of vectors.
     */
    short count() const;

    /*
     * Checks if this geometry is inside a specified Box.
     * @parameters:
     *      const Box &Box            :   The Box.
     * @returns:
     *      bool, true if this geometry is inside the specified Box, false otherwise.
     */
    virtual bool isIn(const Box &box) const = 0;

    /*
     * Checks if this geometry is inside a specified sphere.
     * @parameters:
     *      const Vector3D &center      : the center of the sphere.
     *      double radius               : the radius of the sphere.
     * @returns:
     *      bool, true if this geometry is inside the specified sphere, false otherwise.
     */
    virtual bool isIn(Vector3D &center, double &radius) const = 0;

protected:

    std::vector<Vector3D *>  _vectors;
};

#endif // GEOMETRY_H
