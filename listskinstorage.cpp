#include "listskinstorage.h"

void ListSkinStorage::toStream( std::ostream &os) const {
    std::list<point3d>::const_iterator ipt;
    for(ipt=mList.begin(); ipt!=mList.end(); ipt++)
       os<<*ipt<<std::endl;
}
