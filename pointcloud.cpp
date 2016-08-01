#include "pointcloud.h"

PointCloud::PointCloud(int nx, int ny, int nz, double delta, const point3d &origin)
      : mNx(nx), mNy(ny), mNz(nz), mDelta(delta), mOrigin(origin) {

  // create a 3D array of points and initialize it with true's
  PointArray3D_iterator ix;
  PointArray2D_iterator iy;
  PointArray1D_iterator iz;

  mPoints.resize(nx);
  for(ix=mPoints.begin(); ix!=mPoints.end(); ix++) {
    (*ix).resize(ny);
    for(iy=(*ix).begin(); iy != (*ix).end(); iy++) {
      (*iy).assign(nz,true);
    }
  }

}

//! cut the shape from the array
/*!
Uses Shape::bounds() function to determine the region in which to look for the points
Uses the Shape::inside function to determine if the point is in the shape*/
void PointCloud::cut(const Shape & s) {

  const BoundingBox &b = s.bounds();

  int ilo,ihi, jlo, jhi, klo, khi;  // indeces which correspond to the lower and higher limits of the box

  xyz2idx(b.lo(), ilo, jlo, klo);
  xyz2idx(b.hi(), ihi, jhi, khi);

  // the loop over the points which can (potentially) cross the shape
  for(int i = std::max(0, ilo);  i<=std::min( nx()-1, ihi); i++) {
    for(int j = std::max(0, jlo); j<=std::min( ny()-1, jhi); j++) {
      for(int k = std::max(0, klo); k<=std::min( nz()-1, khi); k++) {

         // if the point is in the array, and if it is inside the shape - remove it from the array
         if(mPoints[i][j][k] && s.inside(gridPoint(i,j,k)) )
            mPoints[i][j][k] = false;
      } //k
    } // j
  } // i

} // cut


//! get skin of the cloud and store it in the skinStorage
/*!
  The skin contain all the points which are visible from the top (have the largest z value ) at each x,y positions
  \param skinStorage - the skinStorage class implementing ISkinStorage interface ( for example ListSkinStorage or MatrixSkinStorage )
*/
void PointCloud::getSkin( ISkinStorage & skinStorage ) const {

  skinStorage.init(nx(),ny(),nz());

  // loop over x and y
  for( int i=0; i < nx(); i++) {
    for( int j=0; j < ny(); j++) {

      //for each x and y find the highest z value
      int k;
      for( k=nz()-1; k>=0 && !mPoints[i][j][k]; k--) {}

      // if we did not cut everything at this x and y positions --> add the point to the skin
      if( k>0 )
         skinStorage.add( i, j, k,  gridPoint(i,j,k) );
    }//j
  }//i

}


