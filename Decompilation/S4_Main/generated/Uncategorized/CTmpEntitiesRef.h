#ifndef CTMPENTITIESREF_H
#define CTMPENTITIESREF_H

#include "defines.h"

class CTmpEntitiesRef {
public:
    // address=[0x132e5e0]
     CTmpEntitiesRef(void);

    // address=[0x132e6b0]
    class IEntity &  operator[](int a1)const;

};


#endif // CTMPENTITIESREF_H
