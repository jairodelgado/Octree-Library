#include "filter.h"

std::vector<Geometry *> Filter::octogonalFilter(const Box &box, Octree *octree)
{
    std::vector<Geometry *> result;
    if((octree->getBox() ^ box))
    {
        if(octree->isLeaf())
        {
            for (int i = 0; i < octree->getGeometryCount(); ++i)
            {
                if(octree->getGeometry(i)->isIn(box))
                {
                    result.push_back(octree->getGeometry(i));
                }
            }
        } else
        {
            for (int i = 0; i < 8; ++i)
            {
                std::vector<Geometry *> aux = octogonalFilter(box, octree->getChild(i));
                result.insert(result.end(), aux.begin(), aux.end());
            }
        }
    }
    return result;
}

bool outsideRadius(Vector3D &center, double &radius, Box box)
{
    for (short i = 0; i < 8; ++i)
    {
       if(center.distance(box.getCorner(i)) <= radius)
       {
           return false;
       }
    }

    return true;
}

std::vector<Geometry *> Filter::radialFilter(Vector3D &center, double radius, Octree *octree)
{
    std::vector<Geometry *> result;

    if(!outsideRadius(center, radius, octree->getBox()))
    {
        if(octree->isLeaf())
        {
            for (int i = 0; i < octree->getGeometryCount(); ++i)
            {
                if(octree->getGeometry(i)->isIn(center, radius))
                    result.push_back(octree->getGeometry(i));
            }
        } else
        {
            for (int i = 0; i < 8; ++i)
            {
                std::vector<Geometry *> aux = radialFilter(center, radius, octree->getChild(i));
                result.insert(result.end(), aux.begin(), aux.end());
            }
        }
    }
    return result;
}
