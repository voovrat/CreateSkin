#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"

//! Sphere class
//! sphere is defined by center and radius
class Sphere : public Shape {

public:
   //! default constructor
   Sphere() {}

   //! Construct a sphere with a given radius
   Sphere( double r) {
     radius(r);
   }

   //! Construct a sphere with a given radius at a given position
   /*!
     \param  r - radius of the sphere
     \param  c - center of the sphere
   */
   Sphere( double r, const point3d & c ) {
     radius(r);
     center(c);
   }

   //! get radius of the sphere
   double radius() const {
     if(!initialized()) throw UninitializedException("Sphere");
     return mRadius;
   }

   //! set the radius of the sphere
   /*! function can be used as the initialization function for the Sphere object*/
   void radius(double r) {
      mRadius = r;
      setInitialized();
   }

protected:

   //! calculate the bounding box for a given center
   virtual void calculateBounds( const point3d &c ) {
      mBounds.init( c.x() - radius(), c.x() + radius()
                  , c.y() - radius(), c.y() + radius()
                  , c.z() - radius(), c.z() + radius()  );
   }

   //! checks whether the point pt is inside the sphere
   virtual bool isInside( const point3d &pt) const {
     return ~(pt - center()) < mRadius;  // operator~()  means the norm of the vector (pt-center())
   }

private:

 double mRadius; // radius

};

#endif // SPHERE_H
