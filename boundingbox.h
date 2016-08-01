#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "tpoint3d.h"

//! This class represents the bounding box of the shape.
/*! We need it to restrict the number of points to cut
*/
class BoundingBox {

 public:

  //! default constructor
  BoundingBox() { init(0.,0.,0.,0.,0.,0.); }

  //! Construct a new bounding box
  /*!Sets the 3d point to the new position.
            \param x0, x1 - limits in x-direction (allowed x1<x0)
            \param y0, y1 - limits in y-direction
            \param z0, z1 - limits in z-direction
        */
  BoundingBox( double x0, double x1, double y0, double y1, double z0, double z1 ) {
    init(x0,x1,y0,y1,z0,z1);
  }

  //! Initialize a new bounding box
  /*!Sets the 3d point to the new position.
            \param x0, x1 - limits in x-direction (allowed x1<x0)
            \param y0, y1 - limits in y-direction
            \param z0, z1 - limits in z-direction
        */
  void init( double x0, double x1, double y0, double y1, double z0, double z1 );


  //! lower box limit
  /*! Comonents are lo.x(), lo.y(), lo.z() can be used to obtain the x,y,z coordinates of the lower limit */
  const point3d & lo() const {
    return mLo;
  }

  //! higher box limit
  /*! Comonents are hi.x(), hi.y(), hi.z() can be used to obtain the x,y,z coordinates of the higher limit */
  const point3d & hi() const {
    return mHi;
  }

private:
  point3d mLo, mHi;  // low and high limits of the box
};
#endif // BOUNDINGBOX_H
