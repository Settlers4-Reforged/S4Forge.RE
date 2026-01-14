#ifndef CAIAGENTATTACK_H
#define CAIAGENTATTACK_H

class CAIAgentAttack : public CAINormalSectorAgent {
public:
    // address=[0x12ffa00]
     CAIAgentAttack(void);

    // address=[0x12ffa70]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x12ffd40]
    virtual void  Load(class IS4Chunk &);

    // address=[0x12ffe70]
    virtual void  Save(class IS4Chunk &);

    // address=[0x12fffa0]
    void  SetOwnFighterNumberAndValue(int,int);

    // address=[0x12fffc0]
    bool  AttackNow(int,int);

    // address=[0x1301020]
    virtual  ~CAIAgentAttack(void);

protected:
    // address=[0x1300070]
    void  ResetAttackState(void);

    // address=[0x13000d0]
    void  ResetAttackTarget(void);

    // address=[0x1300110]
    bool  SetAttackTarget(int);

    // address=[0x13001b0]
    bool  CheckAttackPosition(void);

    // address=[0x1300210]
    int  OrderSquadsToAttack(void);

    // address=[0x1300280]
    void  OrderSquadsHome(enum T_AI_TASK_FORCE_CMD);

    // address=[0x13002f0]
    bool  CheckSquadTarget(class CAITaskForce *);

    // address=[0x1300330]
    int  CheckIfSneakUpPositionIsReached(void);

    // address=[0x13003a0]
    bool  CheckCurrentTarget(bool);

    // address=[0x1300450]
    int  CheckSquadTargets(void);

    // address=[0x1300630]
    bool  FindNearTarget(class CAITaskForce *,int,int &);

    // address=[0x13006e0]
    bool  CheckStrengthAndFindAnyTarget(int,int);

    // address=[0x13008d0]
    bool  OrderSquadsToSneakUpPosition(int);

};


#endif // CAIAGENTATTACK_H
