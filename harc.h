#ifndef HARC_H
#define HARC_H


#include "curve.h"
#include <cmath>

//! Horizontal arc
//! defined by center, radius, start and end (0 - zero, 1. - full circle )
class HArc : public Curve
{
public:
    HArc() {}

    HArc(double t0, double t1 ,double R , const point3d &center)
       : Curve(t0,t1), mR(R), mC(center)
    {   }

    //! center of the arc
    const point3d &center() const {
        return mC;
    }

    //! radius of the arc
    const double &radius() const {
        return mR;
    }

    //! get point on arc for a given t
    virtual point3d operator()(double t) const {
      const double pi = 3.14159265;

      return point3d( mC.x() + radius()*cos(2*pi*t)
                    , mC.y() + radius()*sin(2*pi*t)
                    , mC.z() );
    }

private:
    double mR;
    point3d mC;
};

#endif // ARC_H
