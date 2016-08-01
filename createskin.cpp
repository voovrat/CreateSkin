/*! \file createskin.cpp
 * The file contains the implementation of CreateSkin test project
 *
 * The main interface function is CreateSkin, other classes and functions are hidden from the end-user
 *The function calculates the "skin" of the cloud array after cutting the spheres which move along the trajectory   given by the parametric function func.
 *
 * The "skin" contains all the points which are visible from the top.

*/



#include "tpoint3d.h"
#include <fstream>
#include "sphere.h"
#include "pointcloud.h"
#include "cylinder.h"
#include "curve.h"
#include <string>

#include "matrixskinstorage.h"
#include "listskinstorage.h"

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
				const double delta, const std::string &skinFileName )
{


  // create the cloud of points
  PointCloud cloud(nx,ny,nz,delta,refPoint);


  //create the sphere of radius r
  Sphere sph(sphereRad);


  //the point of the previous center
  point3d prevCenter;
  
  // the first-step flag
  bool firstStep = true;

  // move the sphere and cut the points
  for( double t=func.t0(); t<=func.t1(); t+=deltaT) {

    //move the sphere
    sph.center( func(t) );

    //cut the sphere from the cloud
    cloud.cut( sph );
    
    // at all steps except of first - cut additionally the cylinder connectiog sphere centers of this and previous steps
    if(!firstStep) {
      // create cylinder which connects the current and the previous sphere centers 
      Cylinder cyl(sph.center(), prevCenter, sphereRad );   

     //cut the cylinder from the cloud
      cloud.cut(cyl);             
    } else { // on the first step we do not do any additional cuts
      firstStep = false;
    }

    prevCenter = sph.center();
  }
 
  //get the skin

// one can use either ListSkinStorage or MatrixSkinStorage representations. 
// Please uncomment a proper line below 
//  (NOTE: in principle, it would be possible to give a ISkinStorage & reference as a parameter to Createskin.
//         But for a time being I will not change a given interface )
//  ListSkinStorage skin;
  MatrixSkinStorage skin;
  cloud.getSkin( skin );

  //output the skin to the file
  std::fstream fs(skinFileName.c_str(),std::ios_base::out);
  fs<<skin;
  fs.close();

}
