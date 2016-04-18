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

#ifndef OCTREE_H
#define OCTREE_H

#include "core/box.h"
#include "core/geometry.h"
#include "vector"

/*
 * This class represents an Octree which is a common tree data-structure with an 8th degree. Can perform
 * basic operations in a tree souch as adds and remove childs and determine if a node is a leaf or a brand,
 * the level of the node in the hierarchical structure, etc.
 *
 * This class make use of the factory contruction pattern so does not have any public contructor. Use Factory
 * class instead.
 *
 * @version 1.0.
 * @date Jan, 2014.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 *
 * Added functionalities for keep information about the geometric objects contained in the node restriction
 * volume.
 *
 * @version 1.1.
 * @date Oct, 2014.
 * @author Jairo Rojas Delgado <jrdelgado@estudiantes.uci.cu>.
 */
class Octree
{

friend class Factory;

public:

    ~Octree();

    /*
     * Returns the number of childs in the octree. This is O(1).
     * @returns unsigned int : The number of childs of the octree.
     */
    long getChildCount() const;

    /*
     * Returns the level of this octree node in it's asosiated hierarchy. This is O(1).
     * @returns unsigned int : The level of the octree.
     */
    int getLevel() const;

    /*
     * Returns the cube that represent the asosiated volume in a three dimensional space of this octree.
     * @returns Box : The asosiated cube.
     */
    Box getBox() const;

    /*
     * Returns a reference of the father node of this octree.
     * @returns *Octree: A reference to the node's father if exists; nullptr otherwise.
     */
    Octree *getFather() const;

    /*
     * Returns the i'th child of the octree.
     *
     * @returns *Octree : The octree's child.
     * @throws IllegalArgumentException : if (7 < index < 0) in souch case the given index does not
     * represent an octree child.
     */
    Octree *getChild(short index) const;

    /*
     * Returns the i'th geometry contained in the portion of space defined by this octree.
     * @params
     *          int index : the i'th index of the geometry.
     * @returns
     *          Geometry* : a reference to the specified Geometry.
     * @throws
     *          IllegalArgumentException : if the specified index is out of bounds.
     */
    Geometry* getGeometry(int index);

    /*
     * Returns the number of geometries contained in the portion of the space defined by this octree.
     * This is O(1).
     * @returns unsigned int : The number of geometries.
     */
    int getGeometryCount() const;

    /*
     * Determine if the current octree is a leaf in it's assosiated hierarchy.
     * @returns True, if the current octree is a leaf; False otherwise.
     */
    bool isLeaf();

    /*
     * Adds a new child to the octree in the specified index.
     * @params
     *      short index                 : The index in which the new child will be added.
     *      Octree *child               : A reference to the octree that will be added.
     * @throws IllegalArgumentException : if (7 < index < 0) in souch case the given index does not
     * represent an octree child.
     */
    void addChild(short index, Octree *child);

    /*
     * Remove a specified child octree from this octree. This will remove the entire octree child's hierarchy.
     * @params
     *          short index : The index of the i'th child.
     * @throws
     *          IllegalArgumentException : if (7 < index < 0) in souch case the given index does not
     *          represent an octree child.
     */
    void removeChild(short index);

    /*
     * Returns the amount of bytes loaded by this octree.
     *
     * @returns
     *      long : the amount of bytes loaded.
     */
    long size();

private:

    Octree(std::vector<Geometry *> *data);

    Octree(const Box &box, std::vector<Geometry *> *data);

    Octree*                             _childs[8];

    Octree*                             _father;

    Box                                 _box;

    unsigned long                       _childCount;

    unsigned int                        _level;

    std::vector<int>                    _dataIndex;

    std::vector<Geometry *>            *_data;

};

#endif // OCTREE_H
