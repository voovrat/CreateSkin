#ifndef tpoint3d_h
#define tpoint3d_h

#include <cmath>
#include <ostream>

template<class T> 
class tpoint3d {

public:

  //! default constructor
  tpoint3d() {
     mx = my = mz = 0.;
  }

  //! construct point with a given coordinates
  /*! \param x,y,z  - coordinates */
  tpoint3d(T x,T y,T z) {
    move(x,y,z);
  }


  //! copy constructor  
  tpoint3d( const tpoint3d<T> &pt) {
    move(pt);
  }

  void move(const T &x,const T &y,const T &z) {
    mx = x; my = y; mz = z;
  }

  void move( const tpoint3d<T> &pt) {
    move(pt.x(), pt.y(), pt.z() );
  }

  const T & x() const {
    return mx;
  }

  void x( const T & _x ) {
    mx = _x;
  }  
 
  const T & y() const {
    return my;
  }

  void y( const T & _y ) {
    my = _y;
  }

  const T & z() const {
    return mz;
  }

  void z( const T & _z ) {
    mz = _z;
  }

  const tpoint3d<T> & operator=( const tpoint3d<T> &pt ) {
    move(pt);
    return *this;   
  }

  const tpoint3d<T> operator-() const {
    return tpoint3d<T>(-mx,-my,-mz);
  }

  const T operator~() const {
    return sqrt( mx*mx + my*my + mz*mz );
  }


protected:

  double mx,my,mz;
};

template<class T>
inline bool operator==( const tpoint3d<T> &a, const tpoint3d<T> &b ) {
  return (a.x() == b.x()) 
      && (a.y() == b.y())
      && (a.z() == b.z());   
}

template<class T>
inline bool operator!=( const tpoint3d<T> &a, const tpoint3d<T> &b) {
  return !(a==b);
}


template<class T>
inline const tpoint3d<T>  operator+(const tpoint3d<T> &a, const tpoint3d<T> &b ){
  return tpoint3d<T>( a.x() + b.x(), a.y() + b.y(), a.z() + b.z() );
}

template<class T>
inline const tpoint3d<T>  operator-(const tpoint3d<T> &a, const tpoint3d<T> &b ){
  return tpoint3d<T>( a.x() - b.x(), a.y() - b.y(), a.z() - b.z() );
}

template<class T>
inline const tpoint3d<T> operator*(const T & q, const tpoint3d<T> &a) {
  return tpoint3d<T>( q*a.x(), q*a.y(), q*a.z() );
}

template<class T>
inline const tpoint3d<T> operator*(const tpoint3d<T> &a, const T &q) {
  return q*a;
}

template<class T>
inline const tpoint3d<T> operator/(const tpoint3d<T> &a, const T &q) {
  return 1/q * a;
}

//! scalar (dot) product
template<class T>
inline const T operator*(const tpoint3d<T> &a, const tpoint3d<T> &b) {
  return  a.x()*b.x() + a.y()*b.y() + a.z()*b.z();
}

//! cross product
template<class T>
inline const tpoint3d<T> operator%( const tpoint3d<T> &a, const tpoint3d<T> &b) {
  return tpoint3d<T> ( a.y()*b.z() - a.z()*b.y()
                     ,-a.x()*b.z() + a.z()*b.x()
                     , a.x()*b.y() - a.y()*b.x() );
}

typedef tpoint3d<double> point3d;


//! output the point to the ostream
/*! the format is space separated x,y and z coordinates */
template<class T>
inline std::ostream & operator<<( std::ostream & os, const tpoint3d<T> &pt ) {
   os<<pt.x() << " "<<pt.y() << " "<<pt.z();
   return os;
}


#endif
