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

#ifndef LINE_H
#define LINE_H

#include "core/geometry.h"

/*
 * This class represents a line in a three-dimensional space. This class implements the Geometry interface.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date May, 2014.
 */

class Line : public Geometry
{
public:

    /*
     * Creates a line class with the specified vectors coordinates from start to end.
     * @params
     *      std::initializer_list<Vector3D *>  line : a list of vectors conaining 2 elements
     *  @throws
     *      IllegalArgumentException, if the specified vector list contains more than 2 elements.
     */
    Line(std::initializer_list<Vector3D *> line);

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

#endif // LINE_H
