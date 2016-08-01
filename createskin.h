#ifndef CREATESKIN_H
#define CREATESKIN_H


#include "tpoint3d.h"
#include "curve.h"
#include <string>

//! calculates skin of of a point cloud and save it to a file
/*!
   \param refPoint - corner of the point cloud (the point with the smallest coordinates)
   \param nx,ny,nz - number of grid points in x,y and z directions
   \param sphereRad - radius of the sphere to cut
   \param func  -  function f(t) which determines trajectory of the sphere
   \param deltaT - step for movement function parameter t
   \param delta - spatial resolution (grid step for the point cloud). Same in all directions.
   \skinFileName - name of the file where the skin will be stored.
                    File format: one line per point, each line contain space-separated x,y and z coordinates of the points.

The function calculates the "skin" of the cloud array after cutting the spheres which move along the trajectory given by the parametric function func.
The "skin" contains all the points which are visible from the top.
*/
void CreateSkin( const point3d refPoint,
                const unsigned long nx, const unsigned long ny,
                const unsigned long nz, const double sphereRad,
                Curve &func, const double deltaT,
                const double delta, const std::string &skinFileName );


#endif // CREATESKIN_H
