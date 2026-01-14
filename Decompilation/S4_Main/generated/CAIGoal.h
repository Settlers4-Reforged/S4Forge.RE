#ifndef CAIGOAL_H
#define CAIGOAL_H

class CAIGoal {
public:
    // address=[0x1301370]
    int  EntityId(void)const;

    // address=[0x1301850]
    int  UniqueId(void)const;

    // address=[0x13096f0]
    int  Value(void)const;

    // address=[0x1314ec0]
    void  Maximum(void);

    // address=[0x1314f00]
    void  Set(int,int,int);

};


#endif // CAIGOAL_H
