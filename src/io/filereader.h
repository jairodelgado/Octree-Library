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

#ifndef FILEREADER_H
#define FILEREADER_H

#include "core/reader.h"
#include "core/geometry.h"

#include "geometry/point.h"
#include "geometry/line.h"
#include "geometry/triangle.h"

#include "fstream"
#include "string"
/*
 * A basic implementation of Reader interface. Can read a set of geometries from a specified
 * file.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date Nov, 2014.
 */
class FileReader : public Reader
{
public:

    /*
     * The basic constructor for FileReader class.
     * @params
     *      std::string fileName  : the file address in the file system of the geometry source.
     *      Readable geometryType : the geometry type contained in the source.
     * @throws
     *      IllegalArgumentException, if the file can't be opened.
     */
    FileReader(std::string fileName, Readable geometryType);

    ~FileReader();

    Geometry *next() const;

    bool hasNext() const;

    int size() const;

    void start();

private:
    Readable                _readable;

    std::ifstream          *_file;

    int                     _size;

    std::string             _fileName;
};

#endif // FILEREADER_H
