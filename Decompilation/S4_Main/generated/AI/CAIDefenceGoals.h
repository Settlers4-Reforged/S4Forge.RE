#ifndef CAIDEFENCEGOALS_H
#define CAIDEFENCEGOALS_H

#include "defines.h"

class CAIDefenceGoals {
public:
    // address=[0x1309340]
     CAIDefenceGoals(void);

    // address=[0x13093e0]
    void  Clear(void);

    // address=[0x1309540]
    class CAIDefenceGoal &  Goal(int a2);

    // address=[0x13095c0]
    int  NumberOfGoals(void)const;

    // address=[0x1314a30]
    int  Search(int a2);

    // address=[0x1314a80]
    int  SetFlagBitsId(int a2, int a3);

    // address=[0x1314ad0]
    void  Insert(int a2, int a3, int a4, int a5);

    // address=[0x1314bb0]
    int  NextUnprotectedGoalIdx(int a2);

};


#endif // CAIDEFENCEGOALS_H
