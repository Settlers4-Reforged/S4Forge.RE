#ifndef CWALKINGSHIP_H
#define CWALKINGSHIP_H

#include "defines.h"

class CWalkingShip : public CWalkingBase {
public:
    // address=[0x15f9850]
     CWalkingShip(void);

    // address=[0x15fafb0]
    virtual  ~CWalkingShip(void);

    // address=[0x15fb270]
    virtual enum T_WALKING_TYPE const  GetWalkingType(void);

protected:
    // address=[0x15f9890]
    virtual bool  IsNotBlocked(int a2);

    // address=[0x15f98d0]
    virtual bool  IsNotOccupied(int a2);

    // address=[0x15f9910]
    virtual bool  FindPathAStar64(int a2, int a3, class CDirCache & a4);

    // address=[0x15f99b0]
    virtual int  IdleWalk(int a2, int a3);

};


#endif // CWALKINGSHIP_H
