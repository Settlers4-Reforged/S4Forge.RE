#ifndef CAITASKFORCE_H
#define CAITASKFORCE_H

class CAITaskForce : public IS4ChunkObject {
public:
    // address=[0x12fce10]
    class CAITaskForce *  AssociatedTaskForce(void)const;

    // address=[0x12fcf20]
    void  ClearFlagBit(unsigned int);

    // address=[0x12fcf50]
    int  CmdGoal(void)const;

    // address=[0x12fcf70]
    unsigned int  CmdTimeStamp(void)const;

    // address=[0x12fcf90]
    enum T_AI_TASK_FORCE_CMD  Command(void)const;

    // address=[0x12fd0b0]
    class CAIEntityInfo *  FirstEntity(void)const;

    // address=[0x12fd130]
    int  Flags(void)const;

    // address=[0x12fd420]
    class CAITaskForce *  NextTaskForceGroupMemberOfSameClass(void)const;

    // address=[0x12fd460]
    int  NumberOfEntities(void)const;

    // address=[0x12fd660]
    void  SetFlagBit(unsigned int);

    // address=[0x12fd710]
    enum T_AI_TASK_FORCE_STATUS  Status(void)const;

    // address=[0x12fd7a0]
    enum T_AI_TASK_FORCE_TYPE  Type(void)const;

    // address=[0x13014a0]
    int  GoalEntityId(void)const;

    // address=[0x13014e0]
    int  GoalUniqueId(void)const;

    // address=[0x13015e0]
    int  OwnerId(void)const;

    // address=[0x13037f0]
    void  ClearEntityAddedFlag(void);

    // address=[0x13039b0]
    void  SetTimeStamp(unsigned int);

    // address=[0x13039f0]
    unsigned int  TimeStamp(void)const;

    // address=[0x1306750]
    class CAIEntityInfo *  LastEntity(void)const;

    // address=[0x1309690]
    unsigned int  StatusTimeStamp(void)const;

    // address=[0x1319810]
    virtual bool  NewCommand(int,int,int);

    // address=[0x1319830]
    virtual int  NumberOfEntities(enum T_AI_WARRIOR_TYPE)const;

    // address=[0x1321b40]
    enum T_AI_TASK_FORCE_CLASS  Class(void)const;

    // address=[0x13270c0]
    virtual  ~CAITaskForce(void);

    // address=[0x1327140]
    virtual void  Release(void);

    // address=[0x1327180]
    void  ChangeType(enum T_AI_TASK_FORCE_TYPE);

    // address=[0x1327260]
    virtual enum T_RESULT  CAITaskForce::AddEntity(class CAIEntityInfo *,enum CAITaskForce::T_POSITION);

    // address=[0x13275f0]
    enum T_RESULT  CAITaskForce::AddEntity(int,enum CAITaskForce::T_POSITION);

    // address=[0x1327690]
    virtual enum T_RESULT  CAITaskForce::RemoveEntity(class CAIEntityInfo *);

    // address=[0x13279f0]
    enum T_RESULT  CAITaskForce::RemoveEntity(int);

    // address=[0x1327a30]
    virtual void  RemoveAllEntities(void);

    // address=[0x1327b40]
    void  SetAssociatedTaskForce(class CAITaskForce *);

    // address=[0x1327c70]
    void  ClearAssociatedTaskForce(void);

    // address=[0x1327cd0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1327e60]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1328020]
    bool  IsGoalValid(enum CAITaskForce::T_GOAL_TYPE);

    // address=[0x13280c0]
    char const *  ShortName(void)const;

    // address=[0x13280e0]
    bool  GetPositionOfFirstEntity(int &,int &);

    // address=[0x132a520]
    class CAITaskForceGroup const *  TaskForceGroup(void)const;

    // address=[0x132e9b0]
    bool  GoalIsEntity(void)const;

    // address=[0x132e9f0]
    bool  GoalIsPosition(void)const;

    // address=[0x132ec90]
    void  SetWaitCounter(unsigned int);

    // address=[0x132ece0]
    int  State(void)const;

protected:
    // address=[0x13197f0]
    virtual bool  IsAddEntityOk(int);

    // address=[0x1326f40]
     CAITaskForce(int,enum T_AI_TASK_FORCE_CLASS,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x13281a0]
    void  SetCommand(int,int,int);

    // address=[0x1328240]
    void  MarkGoalAsEntity(void);

    // address=[0x13282d0]
    void  MarkGoalAsPosition(void);

    // address=[0x132a4a0]
    unsigned int  DecWaitCounter(unsigned int);

    // address=[0x132e810]
    void  ActivateNextState(void);

    // address=[0x132e870]
    void  ClearInternalFlagBit(unsigned int);

    // address=[0x132e8d0]
    void  ClearStateFlagBit(unsigned int);

    // address=[0x132ea30]
    bool  IsTaskForceExState(int);

    // address=[0x132eb20]
    void  SetNewStatusAndState(enum T_AI_TASK_FORCE_STATUS,int,int);

    // address=[0x132eb60]
    void  SetState(int);

    // address=[0x132eb80]
    void  SetStateEx(int,int);

    // address=[0x132ebf0]
    void  SetStateFlagBit(unsigned int);

    // address=[0x132ec50]
    void  SetStatus(enum T_AI_TASK_FORCE_STATUS);

};


#endif // CAITASKFORCE_H
