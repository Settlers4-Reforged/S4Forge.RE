#ifndef CTMPENTITIESREF_H
#define CTMPENTITIESREF_H

class CTmpEntitiesRef {
public:
    // address=[0x132e5e0]
     CTmpEntitiesRef(void);

    // address=[0x132e6b0]
    class IEntity &  operator[](int)const;

};


#endif // CTMPENTITIESREF_H
