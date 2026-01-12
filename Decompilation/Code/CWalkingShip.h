#ifndef CWALKINGSHIP_H
#define CWALKINGSHIP_H

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
    virtual bool  IsNotBlocked(int);

    // address=[0x15f98d0]
    virtual bool  IsNotOccupied(int);

    // address=[0x15f9910]
    virtual bool  FindPathAStar64(int,int,class CDirCache &);

    // address=[0x15f99b0]
    virtual int  IdleWalk(int,int);

};


#endif // CWALKINGSHIP_H
