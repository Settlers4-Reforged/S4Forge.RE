#ifndef CAISECTORAI_H
#define CAISECTORAI_H

#include "defines.h"

class CAISectorAI : public IAISectorAI {
public:
    // address=[0x12fce30]
    int  BasePackedXY(void)const;

    // address=[0x12fce60]
    int  BaseX(void)const;

    // address=[0x12fce80]
    int  BaseY(void)const;

    // address=[0x12fd4f0]
    class CAIPlayerAI &  PlayerAI(void)const;

    // address=[0x12fd5e0]
    int  SectorId(void)const;

    // address=[0x12fd750]
    class CAITaskForceGroup &  TaskForceGroup(void);

    // address=[0x1303950]
    int  HeadquarterId(void)const;

    // address=[0x1303990]
    class CAITaskForce *  Reservoir(enum T_AI_WARRIOR_TYPE a2)const;

    // address=[0x13195d0]
    static class CAISectorAI * __cdecl CreateNormalSectorAI(class CAIPlayerAI & a1, int a2, int a3);

    // address=[0x1320000]
    virtual  ~CAISectorAI(void);

    // address=[0x1320030]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1320160]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1320290]
    virtual void  Release(void);

    // address=[0x13202d0]
    virtual void  ExpansionCheck(int a2, int a3, int a4, struct SAIExpansionInfo & a5);

    // address=[0x13202f0]
    virtual enum T_AI_PRESENT_REQUEST_RESULT  RequestDivinePresent(int a1, enum T_AI_PRESENT_REQUEST_PRIORITY a2);

    // address=[0x1320300]
    static class CAISectorAI * __cdecl CreateNormalSectorAI(class CAIPlayerAI & a1, int a2);

    // address=[0x13203b0]
    static class CAISectorAI * __cdecl CreateDarkTribeSectorAI(class CAIPlayerAI & a1, int a2);

    // address=[0x1320460]
    void  CheckBasePosition(void);

    // address=[0x13205c0]
    bool  EvaluateEnemyMilitaryBuilding(int a2, struct SAIEvalResults & a3);

    // address=[0x1320740]
    void  EvaluateOwnMilitaryBuilding(int a2, struct SAIDefenceEvalResult & a3);

    // address=[0x1320890]
    void  MoveOneDefendingFighterToReservoir(int a2, enum T_AI_WARRIOR_TYPE a3, bool a4);

    // address=[0x13209e0]
    int  FindInnerPoint(int a2);

    // address=[0x1320c90]
    void  MoveFightersToReservoir(class CAITaskForce * a2);

    // address=[0x1320d20]
    int  RecruitNearestFighterForTaskForce(class CAITaskForce * a2, int a3, enum T_AI_WARRIOR_TYPE a4, int a5);

    // address=[0x1320e20]
    void  RecruitFightersForSquad(class CAITaskForce * a2, int a3, enum T_AI_WARRIOR_TYPE a4, int a5);

    // address=[0x1320f50]
    void  AutoRecruitFightersForSquad(class CAITaskForce * a2, int a3, int a4);

    // address=[0x1321110]
    void  SearchHeadquarter(void);

    // address=[0x13212e0]
    void  CalculateSectorIdAndEcoSectorIds(void);

    // address=[0x1321300]
    void  DeleteEmptyTaskForces(enum T_AI_TASK_FORCE_CLASS a2);

    // address=[0x13213c0]
    void  AddEntityToReservoir(int a2);

    // address=[0x1321410]
    void  AddEntityToReservoir(int a2, enum T_AI_WARRIOR_TYPE a3);

    // address=[0x1321b20]
    int  BaseWorldIdx(void)const;

    // address=[0x1321c50]
    void  SetBasePosition(int a2, int a3);

    // address=[0x1321d00]
    void  SetHeadquarterId(int a2);

    // address=[0x13260c0]
    static void __cdecl AwakeAgent(class CAIAgent & a1);

protected:
    // address=[0x131ff50]
     CAISectorAI(class CAIPlayerAI & a2);

    // address=[0x13214d0]
    void  ProcessEvents(void);

    // address=[0x1321520]
    virtual bool  ProcessEvent(class CAIEvent const * a2);

};


#endif // CAISECTORAI_H
