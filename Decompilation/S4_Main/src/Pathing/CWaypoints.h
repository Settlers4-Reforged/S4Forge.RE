#ifndef CWAYPOINTS_H
#define CWAYPOINTS_H

#include "defines.h"

class CWaypoints {
public:
    // address=[0x130efd0]
    int  GoalDistance(void)const;

    // address=[0x132e830]
    int  Back(void)const;

    // address=[0x132e850]
    int  CachedWaypointsCount(void)const;

    // address=[0x132ea70]
    void  PopBack(void);

    // address=[0x159e920]
    int  Goal(void)const;

    // address=[0x15d65e0]
    bool  GoalCached(void)const;

    // address=[0x15d66b0]
    void  Init(void);

    // address=[0x15d6a20]
    void  PushBack(int _iXY);

    // address=[0x15d6ad0]
    void  PushGoal(int a2, int a3);

private:
    // address=[0x132e930]
    static int __cdecl DecWrap(int a1);

    // address=[0x15d6620]
    static int __cdecl IncWrap(int a1);

    // Type information members
public:
    int m_iGoal;
    int m_iGoalDistance;
    int m_iTotalWaypoints;
    int m_iCachedWaypointsCount;
    int m_iCurrentPointer;
    int m_iWaypoints[16];
    bool m_bFullyCached;

};


#endif // CWAYPOINTS_H
