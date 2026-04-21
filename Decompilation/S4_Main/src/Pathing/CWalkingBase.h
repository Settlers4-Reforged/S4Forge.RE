#ifndef CWALKINGBASE_H
#define CWALKINGBASE_H

#include "defines.h"
#include "CDirCache.h"
#include "CWalking.h"
#include "CWaypoints.h"

class CWalkingBase : public CWalking {
public:
    // address=[0x15f6660]
    virtual ~CWalkingBase(void);

    // address=[0x15f66b0]
    virtual void Store(std::ostream &a2);

    // address=[0x15f6860]
    virtual void Init(int a2, int _iFlags);

    // address=[0x15f6950]
    virtual void Init(class CWalking *a2, int a3);

    // address=[0x15f6980]
    virtual void InitIfLeader(int a2, int a3);

    // address=[0x15f69f0]
    virtual int Walk(int _iCurrentXY);

    // address=[0x15f7bc0]
    virtual int IdleWalk(int a2, int a3);

    // address=[0x15f8420]
    virtual int DestinationXY(void) const;

    // address=[0x15f8440]
    virtual int State(int a2) const;

    // address=[0x15f8580]
    int OwnerId(void) const;

    // address=[0x15f85a0]
    virtual bool IsNotBlocked(int a2);

    // address=[0x15f85e0]
    virtual bool IsNotOccupied(int a2);

    // address=[0x15f8620]
    virtual int SectorId(int a2);

    // address=[0x15f8640]
    virtual int TileId(int a2);

    // address=[0x15f8660]
    virtual int GetNextWaypoint(void);

    // address=[0x15faee0]
    CWalkingBase(int a2, int a3);

    struct SData {
        int           m_iWalkingType;
        int           m_iWalkState;
        DWORD         field_8;
        int           m_iWalkToXY;
        int           m_iWalkTo2XY;
        int           m_iLeaderWalkToXY;
        int           m_iIdleWalkToXY;
        int           m_iWalkToIndex;
        int           field_20;
        int           m_iFineWaypointXY;
        int           m_iCoarseWaypointXY;
        int           m_uFlags;
        DWORD         m_iEntityFlags;
        int           field_34;
        int           field_38;
        int           field_3C;
        int           field_40;
        CWaypoints    m_cCoarseWaypoints;
        CDirCache     m_cFineWaypoints;
        CWalkingBase *m_pPrevWalking;
        CWalkingBase *m_pNextWalking;
        CWalkingBase *m_pLatestWalking;
    };

    // address=[0x15fb220]
    SData &CWalkingBase::GetData(void);

protected:
    // address=[0x15f86e0]
    virtual bool FindPathAStar64(int a2, int a3, class CDirCache &a4);

    // address=[0x15f8710]
    virtual int FindNearest(int a2, int a3, int a4);

    // address=[0x15f87f0]
    void GoalCheck(int a2);

    // address=[0x15f8a40]
    void DbgPrintElementInfo(char const *a2, int a3);

    // address=[0x15f8b70]
    void AttachWalking(class CWalkingBase *_pWalking);

    // address=[0x15f8c90]
    virtual class CWalking *DetachWalking(void);

    // address=[0x15f8e70]
    void GroupLeaderWalking(int a2, int a3);

    // address=[0x15fb200]
    int Flags(void);

    // address=[0x15fb2b0]
    bool IsNeighborTile(int _iTileA, int _iTileB);

    // address=[0x15fb300]
    bool NextCoarseWaypoint(int _iXY);

    // Type information members
public:
    SData m_sData;
};


#endif // CWALKINGBASE_H
