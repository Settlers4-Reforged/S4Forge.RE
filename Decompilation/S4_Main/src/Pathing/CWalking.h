#ifndef CWALKING_H
#define CWALKING_H

#include "defines.h"

class CWalking {
  public:
    // address=[0x14d8690]
    bool IsFree(int a2);

    // address=[0x15f6110]
    static class CWalking *__cdecl Create(enum T_WALKING_TYPE a1, int a2);

    // address=[0x15f62c0]
    static class CWalking *__cdecl Create(std::istream &_rStream);

    // address=[0x15faec0]
    CWalking(void);

    // address=[0x15faf50]
    virtual ~CWalking(void);

    virtual void Store(std::ostream &a2) = 0;

    virtual void Init(int _iWalkState, int _iFlags) = 0;

    virtual void Init(class CWalking *a2, int a3) = 0;

    virtual void InitIfLeader(int a2, int a3) = 0;

    virtual int Walk(int a2) = 0;

    virtual int IdleWalk(int a2, int a3) = 0;

    virtual int DestinationXY(void) const = 0;

    virtual int State(int a2) const = 0;

    virtual bool IsNotBlocked(int a2) = 0;

    virtual bool IsNotOccupied(int a2) = 0;

    virtual int SectorId(int a2) = 0;

    virtual int TileId(int a2) = 0;

    virtual int GetNextWaypoint(void) = 0;

    virtual T_WALKING_TYPE const GetWalkingType(void) = 0;

  protected:
    virtual bool FindPathAStar64(int a2, int a3, class CDirCache &a4) = 0;

    virtual int FindNearest(int a2, int a3, int a4) = 0;

    virtual class CWalking *DetachWalking(void) = 0;
};

#endif // CWALKING_H
