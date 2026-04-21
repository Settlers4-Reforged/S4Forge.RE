#ifndef CWALKINGCATAPULT_H
#define CWALKINGCATAPULT_H

#include "defines.h"

class CWalkingCatapult : public CWalkingBase {
public:
    // address=[0x15f91a0]
     CWalkingCatapult(void);

    // address=[0x15faf70]
    virtual  ~CWalkingCatapult(void);

    // address=[0x15fb240]
    virtual enum T_WALKING_TYPE const  GetWalkingType(void);

protected:
    // address=[0x15f91e0]
    virtual bool  IsNotBlocked(int a2);

    // address=[0x15f9220]
    virtual bool  IsNotOccupied(int a2);

    // address=[0x15f9300]
    virtual bool  FindPathAStar64(int a2, int a3, class CDirCache & a4);

    // address=[0x15f9420]
    virtual int  IdleWalk(int a2, int a3);

    // address=[0x15f9810]
    virtual int  SectorId(int a2);

    // address=[0x15f9830]
    virtual int  TileId(int a2);

};


#endif // CWALKINGCATAPULT_H
