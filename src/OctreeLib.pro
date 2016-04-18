#-------------------------------------------------
#
# Project created by QtCreator 2014-05-31T09:30:40
#
#-------------------------------------------------

TEMPLATE = lib

TARGET = OctreeLib

DEFINES += OCTREELIB_LIBRARY

QT       -= core gui

CONFIG   += c++11

CONFIG   -= app_bundle qt

SOURCES +=      \
                core/box.cpp \
                core/vector3d.cpp \
                core/octree.cpp \
                core/geometry.cpp \
                core/factory.cpp \
                geometry/triangle.cpp \
                geometry/point.cpp \
                geometry/line.cpp \
                io/filereader.cpp \
                core/filter.cpp

HEADERS +=      core/vector3d.h \
                core/box.h \
                core/reader.h \
                core/octree.h \
                core/geometry.h \
                core/factory.h \
                geometry/triangle.h \
                geometry/point.h \
                geometry/line.h \
                io/filereader.h \
                core/filter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
