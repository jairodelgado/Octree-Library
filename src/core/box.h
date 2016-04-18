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

#ifndef Box_H
#define Box_H

#include "core/vector3d.h"

/*
 * This class represents a cube object in a three dimensional space. Is defined by two vectors
 * that fix the diagonal of the cube. Can retreive information about area, volume and the centroid
 * of the object. Can perform basic operations souch as translations.
 *
 * @version 1.0.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date January, 2014.
 */
class Box
{
public:
    /*
     * The basic constructor of a Box object. Create a cube given two points in a three dimensional space
     * that represents the diagonal of the cube object. A cube can be represented by two points which are
     * the min and max corners of any cube.
     *
     * @params
     *      Vector3D v1 : The first corner of the cube object.
     *      Vector3D v2 : The second corner of the cube object.
     */
    Box(const Vector3D &v1 = Vector3D(-0.5,-0.5,-0.5), const Vector3D &v2 = Vector3D(0.5,0.5,0.5));

    /*
     * Changes the first corner of the cube object.
     *
     * @params
     *      Vector3D corner : The new vertex of the first corner.
     */
    void setMinCorner(const Vector3D &corner);

    /*
     * Changes the second corner of the cube.
     * @params
     *      Vector3D corner : The new vertex of the second corner.
     */
    void setMaxCorner(const Vector3D &corner);

    /*
     * Calculates the coord of one corner of the cube object. The corners can be enumerated starting
     * in the front left bottom corner from left to right, then up and finally to the back repeating
     * the same enumerating proccess up to 8 corners. The minCorner is the index 0 and the max corner
     * the index 7.
     *
     * @params
     *      short index  : The index of the requested corner.
     *
     * @returns
     *      Vector3D : The first corner of the cube object.
     *
     * @throws IllegalArgumentExpetion : If (7 < index < 0) in souch case the given index does not
     * represent a cube corner.
     */
    const Vector3D getCorner(short index) const;

    /*
     * Calculates the lenght of the cube side.
     * @returns double : The lenght of the cube's side.
     */
    double side() const;

    /*
     * Calculates the volume of the cube object.
     * @returns double : The volume of the cube object.
     */
    double volume() const;

    /*
     * Calculates the area of the cube.
     * @returns double : The area of the cube object.
     */
    double area() const;

    /*
     * Calculates the center of the cube.
     * @returns Vertex3D : The vertex that represents the center of the cube object.
     */
    Vector3D center() const;

    /*
     * Traslates the cube by x, y, and z coordinates given the specified traslation vector.
     * Traslates de cube by x given the traslationVector.getX(), by y given the traslationVector.getY()
     * and by z given the traslationVector.getZ().
     * @params
     *      Vector3D traslationVector : The traslation values.
     */
    void traslate(const Vector3D &traslationVector);

    /*
     * Compare if this cube and a given cube are equals. Two cubes are equals if the i-vertex of the
     * first cube is equal to the i-vertex of the second cube.
     *
     * @operators
     *      Box Box : The second Box.
     * @returns bool : True if the Boxs are equals; False otherwise.
     */
    bool operator ==(const Box &box) const;

    /*
     * Compare if this cube and a given cube are not equals. Two cubes are not equals if at least
     * the i-vertex of the first cube is not equal to the i-vertex of the second cube.
     *
     * @operators
     *      Box Box : The second Box to compare.
     * @returns bool : True if the Boxs are not equals; False otherwise.
     */
    bool operator !=(const Box &box) const;

    /*
     * Determine if a given Vector3D out of this Box.
     *
     * @operators
     *      Box vector : The vector that represents the coordinates of the Vector3D.
     * @returns bool : True if the vector is out of the cube; False otherwise.
     */
    bool operator <(const Vector3D &vector) const;

    /*
     * Determine if a given point is in this Box.
     * @operators
     *      Box vector : The vector that represents the coordinates of the point.
     *
     * @returns bool : True if the vector is in the cube; False otherwise.
     */
    bool operator >(const Vector3D &vector) const;

    /*
     * Determine if this Box is inside the given Box.
     * @operators
     *      Box Box : A cube.
     * @returns bool: true if this Box is inside the given one; false otherwise.
     */
    bool operator <(const Box &box) const;

    /*
     * Determine if a given Box is inside this Box.
     *
     * @operators
     *      Box Box : A box to check with.
     *
     * @returns bool : true if the given cube is inside this cube; false otherwise.
     */
    bool operator >(const Box &box) const;

    /*
     * Determine if a given Box intersects this Box.
     *
     * @operators
     *      Box Box : A box to check with.
     *
     * @returns bool : true if the given cube is inside this cube; false otherwise.
     */
    bool operator ^(const Box &box) const;

    /*
     * Copy the values of the specified box.
     * @operators
     *      Box Box : A box.
     * @returns &Box : the box with the new values.
     */
    Box &operator=(const Box &box);

private:

    Vector3D        _minCorner;

    Vector3D        _maxCorner;
};

#endif // Box_H
