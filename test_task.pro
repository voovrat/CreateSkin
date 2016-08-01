TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    cutSphereMove.cpp \
    mwException.cpp \
		mwArcFunction.cpp \
    curve.cpp \
    harc.cpp \
    exception.cpp \
    uninitialized_exception.cpp \
    boundingbox.cpp \
    shape.cpp \
    sphere.cpp \
    cylinder.cpp \
    iskinstorage.cpp \
    listskinstorage.cpp \
    matrixskinstorage.cpp \
    pointcloud.cpp \
    createskin.cpp


HEADERS += \
    mwTPoint3d.hpp \
    curve.h \
    tpoint3d.h \
    harc.h \
    exception.h \
    uninitialized_exception.h \
    boundingbox.h \
    shape.h \
    sphere.h \
    cylinder.h \
    iskinstorage.h \
    listskinstorage.h \
    matrixskinstorage.h \
    pointcloud.h \
    createskin.h

