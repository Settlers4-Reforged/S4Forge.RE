#ifndef CAIDEFENCEGOALS_H
#define CAIDEFENCEGOALS_H

class CAIDefenceGoals {
public:
    // address=[0x1309340]
     CAIDefenceGoals(void);

    // address=[0x13093e0]
    void  Clear(void);

    // address=[0x1309540]
    class CAIDefenceGoal &  Goal(int);

    // address=[0x13095c0]
    int  NumberOfGoals(void)const;

    // address=[0x1314a30]
    int  Search(int);

    // address=[0x1314a80]
    int  SetFlagBitsId(int,int);

    // address=[0x1314ad0]
    void  Insert(int,int,int,int);

    // address=[0x1314bb0]
    int  NextUnprotectedGoalIdx(int);

};


#endif // CAIDEFENCEGOALS_H
