#ifndef MATRIXSKINSTORAGE_H
#define MATRIXSKINSTORAGE_H

#include "iskinstorage.h"
#include <vector>

//! Class to store the skin in a matrix form (z-values arranged in a 2D array)
class MatrixSkinStorage : public ISkinStorage {
public:

  //! initialize the matrix storage (allocate the matrix)
  virtual void init(int nx,int ny, int nz);

  //! add a point to the matrix storage
   /*!
     \param i,j,k - indeces of the point in the cloud-array
     \param pt  - the point
   */
  virtual void add( int i, int j, int k, const point3d &pt ) {
    mMatrix[i][j] = pt.z();
  }

  //! save matrix to stream
    /*!
      The output format is a space-separated matrix with nx lines and ny columns of floating point values
     */
   virtual void toStream( std::ostream &os) const;

  //! get z-value at a given position
  /*!
       \param ix,iy - indices of x and y positions.
                       0<=ix<nx(),  0<=iy<ny()
  */
  double operator()(int ix,int iy) const {
    return mMatrix[ix][iy];
  }

  //! get the matrix of z-values
  const std::vector< std::vector<double> > & matrix() const {
    return mMatrix;
  }

  //! number of points in x direction
  int nx() const {
    return mNx;
  }

  //! number of points in y direction
  int ny() const {
    return mNy;
  }

private:
  std::vector< std::vector<double> > mMatrix;
  int mNx, mNy;
};

//! output the matrix of z-values to the stream
/*!
  The output format is a space-separated matrix with nx lines and ny columns of floating point values
 */
inline std::ostream & operator<<( std::ostream & os, const MatrixSkinStorage & mss ) {
    mss.toStream(os);
    return os;
}


#endif // MATRIXSKINSTORAGE_H
