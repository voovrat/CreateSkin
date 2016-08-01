#include "boundingbox.h"

#include <algorithm>

void BoundingBox::init( double x0, double x1, double y0, double y1, double z0, double z1 ) {
  mLo.x( std::min(x0,x1) );
  mLo.y( std::min(y0,y1) );
  mLo.z( std::min(z0,z1) );

  mHi.x( std::max(x0,x1) );
  mHi.y( std::max(y0,y1) );
  mHi.z( std::max(z0,z1) );
}

