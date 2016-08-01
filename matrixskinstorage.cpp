#include "matrixskinstorage.h"

void MatrixSkinStorage::init(int nx,int ny, int nz) {
  mMatrix.resize( nx );
  for(int i=0;i<nx;i++) {
    mMatrix[i].assign(ny,0.);
  }
  mNx = nx;
  mNy = ny;
}

void MatrixSkinStorage::toStream(std::ostream & os) const {
  int i,j;
  for(i=0; i<nx(); i++) {
    for(j=0; j<ny(); j++ ) {
       os<<(*this)(i,j)<<"  ";
    }
    os<<"\n";
  }
}


