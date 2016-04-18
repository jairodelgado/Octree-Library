#include "core/octree.h"
#include "math.h"

Octree::~Octree()
{
    for(Octree *o : _childs)
    {
        if(o != nullptr)
        {
            delete o;
        }
    }

    if(_father == nullptr)
    {
        delete _data;
    }
}

Octree::Octree(const Box &box, std::vector<Geometry *> *data)
{    
    _box        = box;
    _data       = data;
    _level      = 0;
    _childCount = 0;
    _father     = nullptr;

    _dataIndex.reserve(_data->size());

    for(unsigned int i = 0; i < _data->size(); i++)
    {
        _dataIndex.push_back(i);
    }

    for(int i= 0; i < 8; i++)
    {
        _childs[i] = nullptr;
    }
}

Octree::Octree(std::vector<Geometry *> *data)
{
    _data       = data;
    _childCount = 0;
    _father     = nullptr;

    for(int i= 0; i < 8; i++)
    {
        _childs[i] = nullptr;
    }
}

long Octree::getChildCount() const
{
    return _childCount;
}

int Octree::getGeometryCount() const
{
    return _dataIndex.size();
}

int Octree::getLevel() const
{
    return _level;
}

Box Octree::getBox() const
{
    return _box;
}

Octree* Octree::getFather() const
{
    return _father;
}

Octree *Octree::getChild(short index) const
{
    if(index < 0 || index > 7)
    {
        throw "IllegalArgumentException: Index out of bounds." ;
    }
    return _childs[index];
}

Geometry *Octree::getGeometry(int index)
{
    return _data->at(_dataIndex.at(index));
}

bool Octree::isLeaf()
{
    return _childCount == 0;
}

void Octree::addChild(short index, Octree *child)
{
    if(index < 0 || index > 7)
    {
        throw "IllegalArgumentException: Index out of bounds." ;
    }

    child->_box               = Box(_box.center(), _box.getCorner(index));
    child->_level             = _level + 1;
    child->_father            = this;

    child->_dataIndex.reserve(_dataIndex.size());

    for(const int &index : _dataIndex)
    {
        if(_data->at(index)->isIn(child->_box))
        {
            child->_dataIndex.push_back(index);
        }
    }

    child->_dataIndex.shrink_to_fit();

    if(_childs[index] == nullptr)
    {
        Octree *toActualiceFather = this;

        while(toActualiceFather != 0)
        {
            toActualiceFather->_childCount++;
            toActualiceFather = toActualiceFather->getFather();
        }
    }

    _childs[index]          = child;
}

void Octree::removeChild(short index)
{
    if(index < 0 || index > 7)
    {
        throw "IllegalArgumentException: Index out of bounds." ;
    }

    Octree *result              = _childs[index];
    _childs[index]              = 0;
    long childCount             = result->getChildCount() + 1;
    Octree *toActualiceFather   = this;

    while(toActualiceFather != 0)
    {
        toActualiceFather->_childCount -= childCount;
        toActualiceFather               = toActualiceFather->getFather();
    }

    delete result;
}

long Octree::size()
{
    long result = 0;

    for (int i = 0; i < 8; ++i) {

        result += _childs[i] == nullptr ? 0 : _childs[i] ->size();
    }

    return result + _dataIndex.size() * sizeof(int);
}
