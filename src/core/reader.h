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

#ifndef READER_H
#define READER_H

#include "core/geometry.h"

/*
 * This class is an abstract superclass to read a set of Geometries from a source.
 * This source could be a file, a data base, or a resource at internet. Specific
 * implementations should be provided in derived classes.
 *
 * @version: 1.0.
 * @date: May, 20014.
 * @author: Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>
 *
 * Added functionalities for load lines and triangles from files.
 *
 * @version: 1.1.
 * @date: Oct, 20014.
 * @author: Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>
 */
class Reader
{
public:

    /*
     * This enum defines the types of geometries that the reader should be able
     * to load. This is an integer enum where the corresponding integer number
     * represents the number of vectors that has to be loaded in order to create
     * the specified geometry.
     */
    enum Readable {POINT = 1, LINE = 2, TRIANGLE = 3};

    /*
     * Load the next geometry from the geometry's source.
     * @returns Geometry* : A pointer to the created Geometry.
     */
    virtual Geometry *next() const = 0;

    /*
     * Specifies if there is another geometry in the source to be loaded.
     * @returns bool : true if there is another Geometry to be loaded, false otherwise.
     */
    virtual bool hasNext() const = 0;

    /*
     * Specifies the number of geometries int the source.
     * @returns int : the number of geometries in the source.
     */
    virtual int size() const = 0;

    /*
     * Prepares the reader to start from the first Geometry again.
     */
    virtual void start() = 0;

};

#endif // READER_H
