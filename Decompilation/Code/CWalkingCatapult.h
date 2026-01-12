#ifndef CWALKINGCATAPULT_H
#define CWALKINGCATAPULT_H

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
    virtual bool  IsNotBlocked(int);

    // address=[0x15f9220]
    virtual bool  IsNotOccupied(int);

    // address=[0x15f9300]
    virtual bool  FindPathAStar64(int,int,class CDirCache &);

    // address=[0x15f9420]
    virtual int  IdleWalk(int,int);

    // address=[0x15f9810]
    virtual int  SectorId(int);

    // address=[0x15f9830]
    virtual int  TileId(int);

};


#endif // CWALKINGCATAPULT_H
