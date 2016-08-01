#ifndef CYLINDER_H
#define CYLINDER_H


#include "shape.h"

//! Class that implements the cylindric shape
/*!
    The cylinder is represented by
      1) the line segment which conects the center of the cylinder with the
        center of the center of one of the bases ( half-axis of cylinder, CA)
      2) Radius R
*/
/*
      --- -------------
    /  |R \            \
    |  *--|----*       |
    \__A__/____O______/
*/
class Cylinder : public Shape {

public:

  //! Default constructor
  Cylinder() {}

  //! Constructs the cylinder
  /*!
    \param CA - vector center of cylinder to center of base
    \param R - Radius
 */
  Cylinder(const point3d &CA,double R) {
    init(CA,R);
  }

  //! Create cylinder and initialize the center by two centers of the bases and radius
  /*!
    \param A,B - centers of the bases of the cylinder
    \param R - Radius
 */
  Cylinder(const point3d &A, const point3d &B, double R) {
    init(A,B,R);
  }


  //! Initialized the cylinder
  /*!
    \param CA - vector center of cylinder to center of base
    \param R - Radius
 */
  void init(const point3d & CA, double R) {
    mCA = CA;
    mRadius = R;
    setInitialized();
  }

  //! Initialized the cylinder and center by two center of the bases and radius
  /*!
    \param A,B - centers of the bases of the cylinder
    \param R - Radius
 */
  void init(const point3d &A, const point3d &B,double R) {
    // center A - (A+B)/2  = A - A/2 - B/2 = (A - B)/2
    init( (A - B)/2., R );
    center( (A + B) / 2.);
  }

  //! center of cylinder to center of base
  const point3d &CA() const {
    return mCA;
  }

  //! center of one base
  const point3d A() const {
    return center() + mCA;
  }

  //! center of the opposite base
  const point3d B() const {
    return center() - mCA;
  }

  //! radius of the cylinder
  double radius() const {
    return mRadius;
  }

  //! calculate the bounding box for a given center (\param c)
  /*!  the bounding box is the bounding box the axis ( AB, where B is reflection of A w.r.t center )
       enlarged by the radius (R)
       the box is a little bit too large, but it is not critical
   */
  virtual void calculateBounds( const point3d &C ) {
      point3d A = this->A();
      point3d B = this->B();

      mBounds.init( std::min(A.x(),B.x()) - radius(), std::max(A.x(),B.x()) + radius()
                  , std::min(A.y(),B.y()) - radius(), std::max(A.y(),B.y()) + radius()
                  , std::min(A.z(),B.z()) - radius(), std::max(A.z(),B.z()) + radius() );
  }

  //! checks whether the point pt is inside the sphere
  /*!\param P - point to be checked
      To check whether the point P is inside the  cylinder we use two following criteria:
           1) distance from the point to the axis (AB) is <R
           2) the projection of the point to the axis lies between the centers of the bases
  */
  /*!  The algorithm: */
   //              P----D
   //             /|h  /
   //       B ---C-Q--A
   /*! Let  C = center of cylinder, A,B - centers of the bases,
                     P - point to check, Q - its projection to CA, h = |PQ|

       1)
       To calculate the distance to the axis we use the fact that the absolute value
       of vector product |[CP,CA]| is equal to the area of parallelogramme CPDA.
       From the other side S_CPDA = |CA|*h ==> h = |[CP,CA]|/|CA|. It should hold h<R

       2)
       To check whether the point lies between the bases of the cylinder,   we need to ensure
       that projection Q of the point P on the axis AB lines between A and B, i.e. -CA < CQ < CA,  |CQ| < |CA|

       To calculate the projection we divide the scolar product CP*CA by the length |CA| of CA:
           CQ = CP*CA / |CA|
    */
  virtual bool isInside( const point3d &P) const {

     point3d CP = P - center(); //vector to the point
     const point3d &CA = this->CA();
     double aCA = ~( CA ); // length of CA, "~" means norm, "%" - vector product, "*" - dot (scalar) product

     return ( ~( CP % CA ) / aCA < mRadius ) // 1) check that distnace to the axis h = |[CP,CA]]/|CA| < R
         && ( fabs( CP * CA ) / aCA < aCA );  // 2) check that  |CQ| < |CA|, where CQ = CP * CA / |CA| is a projection of CP
   }

private:
  point3d mCA;   // vector from center of cylinder to the center base of cylinder
  double mRadius; // radius

};


#endif // CYLINDER_H
