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

#ifndef POINT_H
#define POINT_H

#include "core/geometry.h"
#include "core/vector3d.h"

/*
 * This class represents a point in a three-dimensional space. This class implements the Geometry interface.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date May, 2014.
 */
class Point : public Geometry
{
public:

    /*
     * Creates a Point class with the specified vector coordinate.
     * @params
     *      std::initializer_list<Vector3D *>  point: a list of vectors conaining 1 element.
     * @throws
     *      IllegalArgumentException, if the specified vector list contains more than 1 element.
     */
    Point(std::initializer_list<Vector3D *>  point);

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

#endif // POINT_H
