#include "factory.h"

Factory::Factory(Reader *reader)
{
    _data = new std::vector<Geometry *>();

    _data->reserve(reader->size());

    reader->start();
    while(reader->hasNext())
    {
        _data->push_back(reader->next());
    }
}

Octree* Factory::buildUntilGeometryLimit(int limit) const
{
    Octree *result = new Octree(*getBoundingBox(), _data);

    std::deque<Octree *> build_path{result};

    while(!build_path.empty())
    {
        Octree *node = build_path.front();

        if(node->getGeometryCount() > limit)
        {
            for(short i = 0; i < 8; i++)
            {
                node->addChild(i, new Octree(_data));
                build_path.push_back(node->getChild(i));
            }
        }
        build_path.pop_front();
    }
    return result;
}

Octree* Factory::buildUntilGeometryLimitR(int limit) const
{
    Octree *result = new Octree(*getBoundingBox(), _data);

    result = buildUntilGeometryLimitRR(result, limit);

    return result;
}

Octree* Factory::buildUntilVolumLimit(double limit) const
{
    Octree *result;

    result = new Octree(*getBoundingBox(), _data);

    std::deque<Octree *> build_path{result};

    while(!build_path.empty())
    {
        Octree *node = build_path.front();

        if(node->getBox().volume() > limit && node->getGeometryCount() > 0)
        {
            for(short i = 0; i < 8; i++)
            {
                node->addChild(i, new Octree(_data));
                build_path.push_back(node->getChild(i));
            }
        }
        build_path.pop_front();
    }

    return result;
}

Octree* Factory::buildUntilVolumLimitR(double limit) const
{
    Octree *result = new Octree(*getBoundingBox(), _data);

    result = buildUntilVolumLimitRR(result, limit);

    return result;
}

Box* Factory::getBoundingBox() const
{
    Vector3D    centroid(0, 0, 0);

    Box        *result;

    int         point_counter = 0;

    double      max_distance  = 0;

    for(const Geometry *geometry : *_data)
    {
        for(int i = 0; i < geometry->count(); i++)
        {
            point_counter++;
            const Vector3D &auxiliar = *geometry->get(i);
            centroid += auxiliar;
        }
    }

    centroid /= point_counter;

    for(const Geometry *geometry : *_data)
    {
        for(int i = 0; i < geometry->count(); i++)
        {
            const Vector3D &auxiliar = *geometry->get(i);

            if(centroid.distance(auxiliar) > max_distance)
            {
                max_distance = centroid.distance(auxiliar);
            }
        }
    }

    result = new Box(Vector3D(centroid.getX() - max_distance, centroid.getY() - max_distance, centroid.getZ() - max_distance), Vector3D(centroid.getX() + max_distance, centroid.getY() + max_distance, centroid.getZ() + max_distance));

    return result;
}

Octree* Factory::buildUntilGeometryLimitRR(Octree *octree, int limit) const
{
    if(octree->getGeometryCount() > limit)
    {
        for(short i = 0; i < 8; i++)
        {
            octree->addChild(i, new Octree(_data));

            buildUntilGeometryLimitRR(octree->getChild(i), limit);
        }
    }

    return octree;
}

Octree* Factory::buildUntilVolumLimitRR(Octree *octree, double limit) const
{
    if(octree->getBox().volume() > limit)
    {
        for(short i = 0; i < 8; i++)
        {
            octree->addChild(i, new Octree(_data));

            buildUntilGeometryLimitRR(octree->getChild(i), limit);
        }
    }

    return octree;
}

