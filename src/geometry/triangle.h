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

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "core/geometry.h"
#include "core/vector3d.h"

/*
 * This class represents a triangle in a three-dimensional space. This class implements the Geometry interface.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date May, 2014.
 */

class Triangle : public Geometry
{
public:

    /*
     * Creates a Trignale class with the specified vectors coordinates.
     * @params
     *      Vector3D *triangle  :   a list of vectors conaining 3 elements.
     * @throws
     *      IllegalArgumentException, if the specified vector list contains more than 3 elements.
     */
    Triangle(std::initializer_list<Vector3D *> triangle);

    /*
     * Checks if this geometry is inside a specified Box.
     * @parameters:
     *      const Box &Box            :   The Box.
     * @returns:
     *      bool, true if this geometry is inside the specified Box, false otherwise.
     */
    bool isIn(const Box &box) const;

    bool isIn(Vector3D &center, double &radius) const;
};

#endif // TRIANGLE_H
