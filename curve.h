#ifndef CURVE_H
#define CURVE_H

#include "tpoint3d.h"

//! the class implements a parametric curve
/*!
  the curve is defined by  start and end values (t0 and t1) of parameter t, and the function which evaluates the points
*/
class Curve {
public:

  //! default constructor
  Curve() { mt0=mt1=0.;  }

  //! constructor
  //! \param t0,t1 - start and end values of parameter
  Curve( double t0, double t1 ) {
    mt0 = t0;
    mt1 = t1;
  }

  //! virtual destructor
  virtual ~Curve() {}

  //! initial parameter value
  double t0() const {
    return mt0;
  }

  //! final parameter value
  double t1() const {
    return mt1;
  }

  //! get the point on curve corresponding to a given value of t
  virtual point3d operator()(  double t ) const = 0;

private:

  double mt0, mt1;

};

#endif // CURVE_H
