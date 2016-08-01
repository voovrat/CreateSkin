#ifndef SHAPE_H
#define SHAPE_H

#include "tpoint3d.h"
#include "uninitialized_exception.h"
#include "boundingbox.h"

//! Abstract Shape class
/*! The sphere is one kind of shapes, but there could be others
  the shape has
    - center (can be set)
    - bounding box
    - the function which tells if the point belongs to the shape or not
*/

class Shape {

public:
  //! Defaul constructor
  /*! Default constructior allows to put the shapes into collections
      Before use the shape should be initialized.
 */
  Shape() {
    mInitialized = false;
    mCenterIsSet = false;
  }

  //! virtual destructor
  virtual ~Shape() {}

  //! BoundingBox of the shape
  /*!  Calculates and returns the bounding box of the shape for a current position
       Throws an exception if shape was not initialized
  */
 const BoundingBox  & bounds() const {
   if(!mInitialized) throw UninitializedException("Shape");
   if(!mCenterIsSet) throw UninitializedException("Shape","center");
   return mBounds;
 }

 //! returns the initialization status of the class
 bool initialized() const {
  return mInitialized;
 }

 //! Check if the point is inside the shape
 /*!
    \param pt - point to check
     returns true if the point is inside the shape
     throws an exception if the shape is uninitialized
 */
 bool inside(const point3d &pt) const {
   if(!mInitialized) throw UninitializedException("Shape");
   return isInside(pt);
 }

  //! Get Center of the shape
  /*! Throws an exception if center was not set */
  const point3d &center() const {
    if(!mCenterIsSet) throw  UninitializedException("Shape","center");
    return mCenter;
  }

  //! Set center of the shape
  /*! The function recalculates the bounding box */
  void center( const point3d &c) {
    mCenter = c;
    mCenterIsSet = true;
    if( !mInitialized ) throw UninitializedException("Shape");
    calculateBounds( c );
  }


protected:

  //! Set initialized
  /*! called by derived class after initialization*/
  void setInitialized() {
    mInitialized = true;
  }

  //! calculate Bounding box for a given position
  /*! will be implemented in derived class.
      called from bounds() function */
  virtual void calculateBounds( const point3d &center ) = 0;

  BoundingBox mBounds; // recalculated when center is moved


 //! Checks whether the point is inside the shape
  /*! will be implemented in derived class.
      called from inside() (interface) function */
  virtual bool isInside(const point3d & pt) const = 0;

private:
  bool mInitialized;    // false before the shape is initialized (in either way defined by derived classes)
  bool mCenterIsSet;    // false before the center is set

  point3d mCenter;
};


#endif // SHAPE_H
