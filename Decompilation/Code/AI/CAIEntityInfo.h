#ifndef CAIENTITYINFO_H
#define CAIENTITYINFO_H

class CAIEntityInfo {
public:
    // address=[0x12fd010]
    int  EntityId(void)const;

    // address=[0x12fd380]
    class CAIEntityInfo *  Next(void)const;

    // address=[0x12fd730]
    class CAITaskForce *  TaskForce(void)const;

    // address=[0x1306910]
    class CAIEntityInfo *  Prev(void)const;

    // address=[0x13069a0]
    void  SetTargetId(int);

    // address=[0x13069c0]
    void  SetTimeStamp(unsigned int);

    // address=[0x13069e0]
    int  TargetId(void)const;

    // address=[0x1306a00]
    unsigned int  TimeStamp(void)const;

    // address=[0x130a880]
     CAIEntityInfo(int);

    // address=[0x130a8e0]
     ~CAIEntityInfo(void);

    // address=[0x130aa00]
    class CAIEntityInfoEx *  ExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS);

};


#endif // CAIENTITYINFO_H
