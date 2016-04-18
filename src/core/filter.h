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

#ifndef FILTER_H
#define FILTER_H

#include "vector"
#include "deque"

#include "core/box.h"
#include "core/vector3d.h"
#include "core/octree.h"
#include "core/geometry.h"

/*
 * This class is intended to perform spatial search over octrees. It can perform
 * octogonal search and radial search. Other kind of search can be implemented
 * extending it's functionalities.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date Feb, 2015.
 */
class Filter
{
public:

    /*
     * Performs an octogonal search over the specified octree. Octogonal search
     * try to find all geometric object contained inside a box.
     * @params:
     *      const Box &box : the search volume represented by a box.
     *      Octree octree  : the octree that contains geometric objects.
     * @returns:
     *      std::vector    : a list of all geometric objetcs contained in the
     *                       specified search volume.
     */
    std::vector<Geometry *> octogonalFilter(const Box &box, Octree *octree);

    /*
     * Performs a radial search over the specified octree. Radial search
     * try to find all geometric object contained inside a sphere.
     * @params:
     *      const Vector3D &center : the center of the sphere.
     *      double radius          : the radius of the sphere.
     *      Octree octree          : the octree that contains geometric objects.
     * @returns:
     *      std::vector            : a list of all geometric objetcs contained in the
     *                               specified search volume.
     */
    std::vector<Geometry *> radialFilter(Vector3D &center, double radius, Octree *octree);

private:

    bool intersect(Vector3D &center, double &radius, Geometry &geometry);

};

#endif // FILTER_H
