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

#ifndef VECTOR3D_H
#define VECTOR3D_H

/*
 * This class represents a three dimensional vector in a three dimensional space.
 * Permorfs basic operations souch as sume and sustraction of two vectors and
 * multiplication and division with a scalar number.
 *
 * @version 1.0
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 * @date January, 2014.
 */
class Vector3D
{
public:
    /*
     * The basic contructor of Vector3D class. Construct a basic vector with the
     * provided space components.
     *
     * @params
     *      double x :  The X component of the vector.
     *      double y :  The Y component of the vector.
     *      double z :  The Z component of the vector.
     */
    Vector3D(double x = 0, double y = 0, double z = 0);

    /*
     * Returns the X component of the vector.
     * @returns double : The X component of the vector.
     */
    double getX() const;

    /*
     * Returns the Y component of the vector.
     * @returns double : The Y component of the vector.
     */
    double getY() const;

    /*
     * Returns the Z component of the vector.
     * @returns double : The Z component of the vector.
     */
    double getZ() const;

    /*
     * Changes the X component of the vector.
     * @params
     *      double x : The new X component of the vector to be set.
     */
    void setX(double x);

    /*
     * Changes the Y component of the vector.
     * @params
     *      double y : The new Y component of the vector to be set.
     */
    void setY(double y);

    /*
     * Changes the Z component of the vector.
     * @params
     *      double z : The new Z component of the vector to be set.
     */
    void setZ(double z);

    /*
     * Calculates the euclidean distance betwen this vector and another vector.
     * @params
     *      Vector3D vector : The vector to calculate distance.
     * @returns double: The calculated distance between this vector and the given one.
     */
    double distance(const Vector3D &vector) const;

    /*
     * Returns the same vector but with all components turned into it's absoulte values.
     *
     * @returns:
     *      Vector3D: a vector with all it's components positives.
     */
    Vector3D absolute() const;

    /*
     * Calculates the sume of two three-dimensional vectors. The sume of two vectors is
     * calculated as the sume of the i-component of the first vector and de i-component
     * of the second vector.
     * @operators
     *      Vector3D vector: The second vector.     * 
     * @returns Vector3D : The resulting calculation.
     */
    Vector3D operator+(const Vector3D &vector) const;

    /*
     * Calculates the rest of two three-dimensional vectors. The rest of two vectors is
     * calculated as the rest of the i-component of the first vector and de i-component
     * of the second vector.     *
     * @operators
     *      Vector3D vector : The second vector.
     * @returns Vector3D : The resulting calculation.
     */
    Vector3D operator-(const Vector3D &vector2) const;

    /*
     * Calculates the multiplication of a three-dimensional vector and a scalar number.
     * The  multiplication of a three-dimensional vector and a scalar number is calculated
     * as the multiplication of the i th-component of the vector and the scalar number.
     *
     * @operators
     *      double scalar : The scalar number.
     *
     * @returns Vector3D : The resulting calculation.
     */
    Vector3D operator*( double scalar) const;

    /*
     * Calculates the division of a three-dimensional vector and a scalar number. The
     * division of a three-dimensional vector and a scalar number is calculated as the
     * division of the i-component of the vector and the scalar number.
     *
     * @operators
     *      double scalar : The scalar number.
     *
     * @returns Vector3D : The resulting calculation.
     *
     * @throws IllegalArgumentException : If scalar = 0 in souch case division by cero is undefined.
     */
    Vector3D operator/(const double scalar) const;

    /*
     * Calculates the sume of this three-dimensional vector and the given one. The sume
     * of two vectors is calculated as the sume of the i-component of fisrt vector and
     * de i-component of the second vector.
     *
     * @operators
     *      Vector3D vector: The vector.
     *
     * @returns Vector3D : This vector after the resulting calculation.
     */
    Vector3D &operator+=(const Vector3D &vector);

    /*
     * Calculates the rest of this three-dimensional vector and the given one. The rest
     * of two vectors is calculated as the rest of the i-component of the fisrt vector
     * and de i-component of the second vector.
     *
     * @operators
     *      Vector3D vector: The vector.
     *
     * @returns Vector3D : This vector after the resulting calculation.
     */
    Vector3D &operator-=(const Vector3D &vector);

    /*
     * Calculates the multiplication of this three-dimensional vector and a scalar number.
     * The  multiplication of a three-dimensional vector and a scalar number is calculated
     * as the multiplication of the i-component of the vector and the scalar number.
     * @operators
     *
     *      double scalar : The scalar number.
     *
     * @returns Vector3D  : This vector after the resulting calculation.
     */
    Vector3D &operator*=(double scalar);

    /*
     * Calculates the division of this three-dimensional vector and a scalar number. The
     * division of a three-dimensional vector and a scalar number is calculated as the
     * division of the i-component of the vector and the scalar number.
     *
     * @operators
     *      double scalar : The scalar number.
     *
     * @returns Vector3D  : This vector after the resulting calculation.
     *
     * @throws IllegalArgumentException : If scalar = 0 in souch case division by cero is undefined.
     */
    Vector3D &operator/=(double scalar);

    /*
     * Compares two vectors to check if they are equals. Two vectors are equals if
     * the i th-component of the first vector is equal to the i-component of the second vector.
     *
     * @operators
     *      Vector3D vector : The second vector.
     *
     * @returns bool : True, if the vectors are equals. False, otherwise.
     */
    bool operator==(const Vector3D &vector) const;

    /*
     * Compares two vectors to check if they are not equals. Two vectors are not equals if
     * at least one component of the first vector is not equal to the corresponding
     * i th-component of the second vector.
     *
     * @operators
     *      Vector3D vector : The second vector.
     *
     * @returns bool : True, if the vectors are not equals. False, otherwise.
     */
    bool operator!=(const Vector3D &vector) const;

    /*
     * Copies the components of the given vector in this vector component
     *
     * @operators
     *      Vector3D vector : The vector.
     *
     * @returns This vector with it's components changed.
     */
    Vector3D &operator=(const Vector3D &vector);
private:

    double _x;

    double _y;

    double _z;
};

#endif // VECTOR3D_H
