#ifndef CAITASKFORCE_H
#define CAITASKFORCE_H

#include <LoadSave/IS4ChunkObject.h>

#include "defines.h"

enum T_AI_TASK_FORCE_CMD {
    T_AI_TASK_FORCE_CMD_UNKNOWN_0,
    T_AI_TASK_FORCE_CMD_UNKNOWN_1,
    T_AI_TASK_FORCE_CMD_UNKNOWN_2,
    T_AI_TASK_FORCE_CMD_UNKNOWN_3,
    T_AI_TASK_FORCE_CMD_UNKNOWN_4,
};

enum T_AI_TASK_FORCE_STATUS {
    TASK_FORCE_STATUS_NONE = 0,
    TASK_FORCE_STATUS_UNKNOWN_1,
    TASK_FORCE_STATUS_UNKNOWN_2,
    TASK_FORCE_STATUS_UNKNOWN_3,
    TASK_FORCE_STATUS_UNKNOWN_4,
};

enum T_AI_TASK_FORCE_TYPE {
    TASK_FORCE_TYPE_NONE = 0,
    TASK_FORCE_TYPE_UNKNOWN_1,
    TASK_FORCE_TYPE_UNKNOWN_2,
    TASK_FORCE_TYPE_UNKNOWN_3,
    TASK_FORCE_TYPE_UNKNOWN_4,
    AI_TASK_FORCE_TYPE_PRIESTS        = 8,
    AI_TASK_FORCE_TYPE_DARK_GARDENERS = 11,
    AI_TASK_FORCE_TYPE_SHAMANS        = 12,
    AI_TASK_FORCE_TYPE_MANAKOPTERS    = 13
};

enum T_AI_WARRIOR_TYPE {
    AI_WARRIOR_TYPE_NONE           = 0,
    AI_WARRIOR_TYPE_PRIEST         = 6,
    AI_WARRIOR_TYPE_MISC_UNIT      = 7,
    AI_WARRIOR_TYPE_FIGHTER_UNIQUE = 4,
    AI_WARRIOR_TYPE_VEHICLE_MISC   = 9,
    AI_WARRIOR_TYPE_TOWER_BUILDING = 12,
    AI_WARRIOR_TYPE_LAST           = 13,
};

enum T_AI_TASK_FORCE_CLASS {
    AI_TASK_FORCE_CLASS_NONE      = 0,
    AI_TASK_FORCE_CLASS_RESERVOIR = 1,
    AI_TASK_FORCE_CLASS_SQUAD     = 2,
    AI_TASK_FORCE_CLASS_PRIESTS   = 3,

    AI_TASK_FORCE_CLASS_GROUP     = 6, // just a guess, but CTaskForceEx checks this in a Group call
    AI_TASK_FORCE_CLASS_MAX = 9,
};

enum T_RESULT {
    RESULT_INVALID   = 0,
    RESULT_FAILED    = 1,
    RESULT_UNKNOWN_2 = 2, //As in, I dont know what the name is
    RESULT_OK        = 3,
    RESULT_UNKNOWN_4 = 4, //As in, I dont know what the name is
};

class CAITaskForce : public IS4ChunkObject {
public:
    // address=[0x12fce10]
    class CAITaskForce *AssociatedTaskForce(void) const;

    // address=[0x12fcf20]
    void ClearFlagBit(unsigned int a2);

    // address=[0x12fcf50]
    int CmdGoal(void) const;

    // address=[0x12fcf70]
    unsigned int CmdTimeStamp(void) const;

    // address=[0x12fcf90]
    enum T_AI_TASK_FORCE_CMD Command(void) const;

    // address=[0x12fd0b0]
    class CAIEntityInfo *FirstEntity(void) const;

    // address=[0x12fd130]
    int Flags(void) const;

    // address=[0x12fd420]
    class CAITaskForce *NextTaskForceGroupMemberOfSameClass(void) const;

    // address=[0x12fd460]
    int NumberOfEntities(void) const;

    // address=[0x12fd660]
    void SetFlagBit(unsigned int a2);

    // address=[0x12fd710]
    enum T_AI_TASK_FORCE_STATUS Status(void) const;

    // address=[0x12fd7a0]
    enum T_AI_TASK_FORCE_TYPE Type(void) const;

    // address=[0x13014a0]
    int GoalEntityId(void) const;

    // address=[0x13014e0]
    int GoalUniqueId(void) const;

    // address=[0x13015e0]
    int OwnerId(void) const;

    // address=[0x13037f0]
    void ClearEntityAddedFlag(void);

    // address=[0x13039b0]
    void SetTimeStamp(unsigned int a2);

    // address=[0x13039f0]
    unsigned int TimeStamp(void) const;

    // address=[0x1306750]
    class CAIEntityInfo *LastEntity(void) const;

    // address=[0x1309690]
    unsigned int StatusTimeStamp(void) const;

    // address=[0x1319810]
    virtual bool NewCommand(int a2, int a3, int a4);

    // address=[0x1319830]
    virtual int NumberOfEntities(enum T_AI_WARRIOR_TYPE a1) const;

    // address=[0x1321b40]
    enum T_AI_TASK_FORCE_CLASS Class(void) const;

    // address=[0x13270c0]
    virtual ~CAITaskForce(void);

    // address=[0x1327140]
    virtual void Release(void);

    // address=[0x1327180]
    void ChangeType(enum T_AI_TASK_FORCE_TYPE a2);

    enum T_POSITION {
        POSITION_NONE  = 0,
        POSITION_FIRST = 1,
        POSITION_LAST  = 2,
    };

    // address=[0x1327260]
    virtual enum T_RESULT AddEntity(class CAIEntityInfo *_pEntityInfo, T_POSITION a3);

    // address=[0x13275f0]
    enum T_RESULT AddEntity(int _iEntityId, T_POSITION a3);

    // address=[0x1327690]
    virtual enum T_RESULT RemoveEntity(class CAIEntityInfo *_pEntityInfo);

    // address=[0x13279f0]
    enum T_RESULT RemoveEntity(int a2);

    // address=[0x1327a30]
    virtual void RemoveAllEntities(void);

    // address=[0x1327b40]
    void SetAssociatedTaskForce(class CAITaskForce *_pTaskForce);

    // address=[0x1327c70]
    void ClearAssociatedTaskForce(void);

    // address=[0x1327cd0]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x1327e60]
    virtual void Save(class IS4Chunk &a2);

    enum T_GOAL_TYPE {};

    // address=[0x1328020]
    bool IsGoalValid(T_GOAL_TYPE a2);

    // address=[0x13280c0]
    char const *ShortName(void) const;

    // address=[0x13280e0]
    bool GetPositionOfFirstEntity(int &_rX, int &_rY);

    // address=[0x132a520]
    class CAITaskForceGroup const *TaskForceGroup(void) const;

    // address=[0x132e9b0]
    bool GoalIsEntity(void) const;

    // address=[0x132e9f0]
    bool GoalIsPosition(void) const;

    // address=[0x132ec90]
    void SetWaitCounter(unsigned int _uNewCounter);

    // address=[0x132ece0]
    int State(void) const;

protected:
    // address=[0x13197f0]
    virtual bool IsAddEntityOk(int a2);

    // address=[0x1326f40]
    CAITaskForce(int _iOwnerId, T_AI_TASK_FORCE_CLASS _tClass, T_AI_TASK_FORCE_TYPE _tType, int _iFlags);

    // address=[0x13281a0]
    void SetCommand(int _iCommand, int a3, int _iFlags);

    // address=[0x1328240]
    void MarkGoalAsEntity(void);

    // address=[0x13282d0]
    void MarkGoalAsPosition(void);

    // address=[0x132a4a0]
    unsigned int DecWaitCounter(unsigned int a2);

    // address=[0x132e810]
    void ActivateNextState(void);

    // address=[0x132e870]
    void ClearInternalFlagBit(unsigned int a2);

    // address=[0x132e8d0]
    void ClearStateFlagBit(unsigned int a2);

    // address=[0x132ea30]
    bool IsTaskForceExState(int a2);

    // address=[0x132eb20]
    void SetNewStatusAndState(T_AI_TASK_FORCE_STATUS a2, int a3, int a4);

    // address=[0x132eb60]
    void SetState(int a2);

    // address=[0x132eb80]
    void SetStateEx(int a2, int _iNextState);

    // address=[0x132ebf0]
    void SetStateFlagBit(unsigned int _uMask);

    // address=[0x132ec50]
    void SetStatus(T_AI_TASK_FORCE_STATUS a2);

    // Type information members
public:
    enum T_AI_TASK_FORCE_CLASS  m_tClass;
    enum T_AI_TASK_FORCE_TYPE   m_tType;
    int                         m_iNumberOfEntities;
    struct CAIEntityInfo *      m_pFirstEntity;
    struct CAIEntityInfo *      m_pLastEntity;
    struct CAITaskForce *       m_pPrevTaskForce;
    struct CAITaskForce *       m_pFirstTaskForce;
    CAITaskForce *              m_pPrevTaskForceGroupMember;
    struct CAITaskForce *       m_pNextTaskForceGroupMember;
    struct CAITaskForceGroup *  m_pTaskForceGroup;
    struct CAITaskForce *       m_pAssociatedTaskForce;
    int                         m_iAssociatedId;
    unsigned __int8             m_uNewCounter;
    BYTE                        m_bState;
    BYTE                        m_iNextState;
    enum T_AI_TASK_FORCE_STATUS m_bStatus;
    DWORD                       m_uFlags;
    DWORD                       m_uCmdGoal;
    DWORD                       m_uCmdUniqueId;
    DWORD                       m_uCmdTimeStamp;
    DWORD                       m_uStatusTimeStamp;
    DWORD                       m_uTimeStamp;
};


#endif // CAITASKFORCE_H
