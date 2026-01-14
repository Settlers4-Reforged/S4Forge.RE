#ifndef CAIAGENTDARKTRIBEATTACK_H
#define CAIAGENTDARKTRIBEATTACK_H

class CAIAgentDarkTribeAttack : public CAIDarkTribeSectorAgent {
public:
    // address=[0x12f9ea0]
     CAIAgentDarkTribeAttack(void);

    // address=[0x12f9f10]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x12fa500]
    virtual void  Load(class IS4Chunk &);

    // address=[0x12fa610]
    virtual void  Save(class IS4Chunk &);

    // address=[0x12fa700]
    void  AttackWithShamans(int,int,bool);

    // address=[0x12fc9c0]
    virtual  ~CAIAgentDarkTribeAttack(void);

protected:
    // address=[0x12fa7e0]
    void  ResetAttackState(void);

    // address=[0x12fa890]
    bool  ShamanAttackTaskForceAvailable(void)const;

    // address=[0x12fa900]
    bool  ManakopterTaskForceAvailable(bool)const;

    // address=[0x12fa980]
    bool  CheckShamanAttackPosition(void);

    // address=[0x12fa9c0]
    void  OrderShamanTaskForcesHome(enum T_AI_TASK_FORCE_CMD);

    // address=[0x12faa30]
    int  OrderShamanTaskForcesToManakopter(bool,bool);

    // address=[0x12facf0]
    int  OrderShamanTaskForcesToSneakUpPosition(void);

    // address=[0x12fadb0]
    int  OrderShamanTaskForcesToAttackPosition(void);

    // address=[0x12fae60]
    int  OrderManakopterToPosition(bool);

    // address=[0x12fb1c0]
    int  OrderManakopterUnload(bool);

    // address=[0x12fb250]
    int  OrderShamansToImmediateAttack(void);

    // address=[0x12fb320]
    int  CheckIfPositionIsReached(void);

    // address=[0x12fb3a0]
    bool  CheckIfManakopterReachedPosition(void);

    // address=[0x12fb400]
    bool  CheckIfShamansAreOnBoard(void);

    // address=[0x12fb4e0]
    int  CheckShamanTaskForcesTargets(void);

    // address=[0x12fb990]
    bool  CheckIfReadyForReturn(void);

    // address=[0x12fba00]
    void  SetMissionBit(enum T_AI_TASK_FORCE_CMD);

    // address=[0x12fba70]
    void  RemoveMissionBit(void);

    // address=[0x3e8dd50]
    static class CAIConfigInt s_iMaxSoldiersPerTaskForce;

};


#endif // CAIAGENTDARKTRIBEATTACK_H
