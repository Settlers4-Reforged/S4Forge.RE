#ifndef CWAYPOINTS_H
#define CWAYPOINTS_H

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
    void  PushBack(int);

    // address=[0x15d6ad0]
    void  PushGoal(int,int);

private:
    // address=[0x132e930]
    static int __cdecl DecWrap(int);

    // address=[0x15d6620]
    static int __cdecl IncWrap(int);

};


#endif // CWAYPOINTS_H
