#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "tpoint3d.h"
#include "shape.h"
#include "iskinstorage.h"
#include <vector>


//! 3d rectangular equidistant point cloud
/*!
   is represented by the 3d array of booleans, which reflect the correspondance of the given point to the array
 */
class PointCloud {
public:

  //! Construct a point array with a given dimensions, given delta and origin
  PointCloud(int nx, int ny, int nz, double delta, const point3d &origin);

  //! origin - the smallest coordinates stored in the array
  const point3d &origin() const {
    return mOrigin;
  }

  //! number of points in x direction
  int nx() const {
    return mNx;
  }

  //! number of points in y direction
  int ny() const {
    return mNy;
  }

  //! number of points in z direction
  int nz() const {
    return mNz;
  }

  //! grid step
  int delta() const {
    return mDelta;
  }

  //! check whether there is a point at a given indices
  bool hasPoint(int i,int j,int k) const {
    return ( i>=0) && (i<nx() ) && (j>=0) && (j<ny() ) && (k>=0) && (k<nz() ) && mPoints[i][j][k];
  }

  //! set point at a given index position
  void setPoint(int i,int j,int k) {
    if( (i>=0) && (i<nx() ) && (j>=0) && (j<ny() ) && (k>=0) && (k<nz() ) )
       mPoints[i][j][k] = true;
  }

  //! return a grid point coordinates at the position i,j,k
  point3d gridPoint( int i,int j, int k) const {
    return point3d( origin().x() + i*delta()
                  , origin().y() + j*delta()
                  , origin().z() + k*delta() );
  }

 //! cut the shape from the array
/*!
 Uses Shape::bounds() function to determine the region in which to look for the points
 Uses the Shape::inside function to determine if the point is in the shape*/
 void cut(const Shape & s);

 //! get skin of the cloud and store it in the skinStorage
 /*!
   The skin contain all the points which are visible from the top (have the largest z value ) at each x,y positions
   \param skinStorage - the skinStorage class implementing ISkinStorage interface ( for example ListSkinStorage or MatrixSkinStorage )
*/
 void getSkin( ISkinStorage & skinStorage ) const;

private:

  // definitions of the 1D,2D,3D array of booleans and corresponding array iterators
  typedef std::vector<bool> PointArray1D;
  typedef std::vector<bool>::iterator PointArray1D_iterator;

  typedef std::vector< PointArray1D > PointArray2D;
  typedef std::vector< PointArray1D >::iterator PointArray2D_iterator;

  typedef std::vector< PointArray2D > PointArray3D;
  typedef std::vector< PointArray2D >::iterator PointArray3D_iterator;


  PointArray3D  mPoints;  // 3d array of points, elements represent if they are in or out the array
  int mNx,mNy,mNz;    // array dimensions
  double mDelta;    // step size, same in all directions
  point3d mOrigin;  // origin of the array (the point with the smallest coordinates in the array)
                                    // the points has the coordinates origin.x() + i*delta, origin.y() + j*delta, origin.z() + k*delta

  // get index for a given x coordinate
  int xi( double x) const {
    return (int)( (x-mOrigin.x())/mDelta );
  }

  // get index for a given y coordinate
  int yi( double y) const {
    return (int)( (y-mOrigin.y())/mDelta );
  }

  // get index for a given z coordinate
  int zi( double z) const {
    return (int)( (z-mOrigin.z())/mDelta );
  }

  // convert the point coordinates to the corresponding indeces
  void xyz2idx( const point3d &pt, int &i, int &j, int &k) const {
     i = xi(pt.x());
     j = yi(pt.y());
     k = zi(pt.z());
  }

};



#endif // POINTCLOUD_H
