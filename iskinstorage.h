#ifndef ISKINSTORAGE_H
#define ISKINSTORAGE_H

#include "tpoint3d.h"
#include <ostream>

//! saving function interface.
/*! Can be used in order to save the skin in different formats (e.g. coordinates, matrix of z-values, etc)*/
class ISkinStorage {
public:

   //! initialize storage.
   /*!
      \param nx,ny,nz - dimensions of the Cloud
  */
   virtual void init(int nx,int ny,int nz) = 0;

   //! add point to storage
   /*!
     \param i,j,k - indeces of the point in the cloud-array
     \param pt  - the point
   */
   virtual void add( int i, int j, int k, const point3d &pt) = 0;

   //! output to the stream
   virtual void toStream( std::ostream & os) const = 0;

};

#endif // ISKINSTORAGE_H
