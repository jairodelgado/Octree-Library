#include "filereader.h"

FileReader::FileReader(std::string fileName, Readable geometryType)
{
    _readable   = geometryType;
    _file       = new std::ifstream(fileName);
    _fileName  = fileName;

    if(!_file)
    {
        throw "IllegalArgumentException. Unable to open the specified file.";
    }
    _size = 0;
    for(std::string line; std::getline(*_file, line); _size++);
}

FileReader::~FileReader()
{
    delete _file;
}

Geometry *FileReader::next() const
{   
    Geometry *result;
    double v_1_x , v_2_x, v_3_x;
    double v_1_y , v_2_y, v_3_y;
    double v_1_z , v_2_z, v_3_z;

    switch (_readable) {
    case POINT:
        *_file >> v_1_x >> v_1_y >> v_1_z;
        result = new Point{new Vector3D(v_1_x, v_1_y, v_1_z)};
        break;
    case LINE:
        *_file >> v_1_x >> v_1_y >> v_1_z >> v_2_x >> v_2_y >> v_2_z;
        result = new Line{new Vector3D(v_1_x, v_1_y, v_1_z), new Vector3D(v_2_x, v_2_y, v_2_z)};
        break;
    case TRIANGLE:
        *_file >> v_1_x >> v_1_y >> v_1_z >> v_2_x >> v_2_y >> v_2_z >> v_3_x >> v_3_y >> v_3_z;
        result = new Triangle{new Vector3D(v_1_x, v_1_y, v_1_z), new Vector3D(v_2_x, v_2_y, v_2_z), new Vector3D(v_3_x, v_3_y, v_3_z)};
        break;
    }

    return result;
}

bool FileReader::hasNext() const
{
    return !_file->eof();
}

int FileReader::size() const
{
    return _size;
}

void FileReader::start()
{
    delete _file;
    _file = new std::ifstream(_fileName);
}
