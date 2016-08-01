#ifndef LISTSKINSTORAGE_H
#define LISTSKINSTORAGE_H

#include "iskinstorage.h"
#include <list>

//! iterator for the ListSkinStorage class
typedef std::list<point3d >::const_iterator ListSkinStorage_iterator;


//! save points to the list
class ListSkinStorage : public ISkinStorage {
public:

   //! initialize the list storage
   virtual void init(int nx,int ny,int nz) { mList.clear(); }

   //! add the point to the storage
   /*!
     \param i,j,k - indeces of the point in the cloud-array
     \param pt  - the point
   */
   virtual void add( int i, int j, int k, const point3d &pt) {
     mList.push_back(pt);
   }

   virtual void toStream(std::ostream &os) const;

   //! begin const iterator of the list of points
   ListSkinStorage_iterator begin() const { return mList.begin(); }

   //! end const iterator iterator of the list of points
   ListSkinStorage_iterator end() const { return mList.end(); }

   //! the list of points
   const std::list<point3d > & list() const {
     return mList;
   }

private:
   typedef std::list<point3d > TList;
   TList mList;
};

//! output the point list (skin) to the stream
/*! the format is: one point per line, each line has 3 numbers: space separated x,y and z coordinates */
inline std::ostream & operator<<(std::ostream & os, const ListSkinStorage &lss ) {
    lss.toStream(os);
    return os;
}


#endif // LINKSKINSTORAGE_H
