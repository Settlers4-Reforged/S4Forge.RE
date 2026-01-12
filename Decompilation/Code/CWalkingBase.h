#ifndef CWALKINGBASE_H
#define CWALKINGBASE_H

class CWalkingBase : public CWalking {
public:
    // address=[0x15f6660]
    virtual  ~CWalkingBase(void);

    // address=[0x15f66b0]
    virtual void  Store(std::ostream &);

    // address=[0x15f6860]
    virtual void  Init(int,int);

    // address=[0x15f6950]
    virtual void  Init(class CWalking *,int);

    // address=[0x15f6980]
    virtual void  InitIfLeader(int,int);

    // address=[0x15f69f0]
    virtual int  Walk(int);

    // address=[0x15f7bc0]
    virtual int  IdleWalk(int,int);

    // address=[0x15f8420]
    virtual int  DestinationXY(void)const;

    // address=[0x15f8440]
    virtual int  State(int)const;

    // address=[0x15f8580]
    int  OwnerId(void)const;

    // address=[0x15f85a0]
    virtual bool  IsNotBlocked(int);

    // address=[0x15f85e0]
    virtual bool  IsNotOccupied(int);

    // address=[0x15f8620]
    virtual int  SectorId(int);

    // address=[0x15f8640]
    virtual int  TileId(int);

    // address=[0x15f8660]
    virtual int  GetNextWaypoint(void);

    // address=[0x15faee0]
     CWalkingBase(int,int);

    // address=[0x15fb220]
    struct SData &  CWalkingBase::GetData(void);

protected:
    // address=[0x15f86e0]
    virtual bool  FindPathAStar64(int,int,class CDirCache &);

    // address=[0x15f8710]
    virtual int  FindNearest(int,int,int);

    // address=[0x15f87f0]
    void  GoalCheck(int);

    // address=[0x15f8a40]
    void  DbgPrintElementInfo(char const *,int);

    // address=[0x15f8b70]
    void  AttachWalking(class CWalkingBase *);

    // address=[0x15f8c90]
    virtual class CWalking *  DetachWalking(void);

    // address=[0x15f8e70]
    void  GroupLeaderWalking(int,int);

    // address=[0x15fb200]
    int  Flags(void);

    // address=[0x15fb2b0]
    bool  IsNeighborTile(int,int);

    // address=[0x15fb300]
    bool  NextCoarseWaypoint(int);

};


#endif // CWALKINGBASE_H
