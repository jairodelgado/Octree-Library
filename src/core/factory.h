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

#ifndef FACTORY_H
#define FACTORY_H

#include "core/octree.h"
#include "core/reader.h"
#include "core/geometry.h"
#include "core/box.h"

#include "vector"
#include "deque"

/*
 * This is intended to create Octree objects based on several indexing criterias.
 *
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date Nov, 2014.
 */
class Factory
{

public:

    /*
     * The basic contructor of a Factory object.
     * @params
     *      Reader *reader : A reference to a source of geometries from which create the Octree.
     */
    Factory(Reader *reader);

    /*
     * Generate an octree with a geometry limit as stoping criteria. This mean that Factory will
     * continue partitioning the space until any partition contain no more geometries than the
     * specified.
     * @params
     *      unsigned int limit : the limit of geometries.
     * @returns
     *      Octree*, a reference to the generated Octree.
     */
    Octree* buildUntilGeometryLimit(int limit) const;


    /*
     * Generate an octree with a geometry limit as stoping criteria. This mean that Factory will
     * continue partitioning the space until any partition contain no more geometries than the
     * specified using a recursive aproach.
     * @params
     *      unsigned int limit : the limit of geometries.
     * @returns
     *      Octree*, a reference to the generated Octree.
     */
    Octree* buildUntilGeometryLimitR(int limit) const;

    /*
     * Generate an octree with a volume limit as stoping criteria. This mean that Factory will
     * continue partitioning the space until any partition contain no more volume than the
     * specified.
     * @params
     *      double limit : the limit of volume.
     * @returns
     *      Octree*, a reference to the generated Octree.
     */
    Octree* buildUntilVolumLimit(double limit) const;

    /*
     * Generate an octree with a volume limit as stoping criteria. This mean that Factory will
     * continue partitioning the space until any partition contain no more volume than the
     * specified using a recursive aproach.
     * @params
     *      double limit : the limit of volume.
     * @returns
     *      Octree*, a reference to the generated Octree.
     */
    Octree* buildUntilVolumLimitR(double limit) const;

private:

    Box         *getBoundingBox() const;

    Octree* buildUntilGeometryLimitRR(Octree *octree, int limit) const;

    Octree* buildUntilVolumLimitRR(Octree *octree, double limit) const;


    std::vector<Geometry *>  *_data;

};

#endif // FACTORY_H
