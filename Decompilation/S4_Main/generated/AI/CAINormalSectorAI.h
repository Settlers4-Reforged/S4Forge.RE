#ifndef CAINORMALSECTORAI_H
#define CAINORMALSECTORAI_H

#include "defines.h"

class CAINormalSectorAI : public CAISectorAI {
public:
    // address=[0x1323250]
     CAINormalSectorAI(class CAIPlayerAI & a2, int a3);

    // address=[0x13237a0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1323ab0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1323dc0]
    virtual void  PostAIEvent(int a2, int a3, int a4, int a5);

    // address=[0x1323e80]
    virtual void  Execute(void);

    // address=[0x1323f40]
    virtual bool  ProcessEvent(class CAIEvent const * a2);

    // address=[0x1324390]
    void  AttachAgentEx(class CAINormalSectorAgent & a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x13243d0]
    virtual void  DbgPrint(void);

    // address=[0x13244c0]
    void  OccupationCheck(int a2);

    // address=[0x1324670]
    int  FindTargetForSuicideMission(class CAITaskForce * a2);

    // address=[0x1324930]
    void  MoveSquadHome(class CAITaskForce *);

    // address=[0x1324cf0]
    void  EvaluateNextEnemyMilitaryBuilding(void);

    // address=[0x1324f20]
    bool  EvaluateNextOwnMilitaryBuilding(void);

    // address=[0x1325170]
    void  PostAIEventToAllEcoSectorAIs(int a2, int a3, int a4, int a5);

    // address=[0x1325d10]
    virtual  ~CAINormalSectorAI(void);

    // address=[0x13261a0]
    virtual bool  IsNormalPlayerSector(void)const;

protected:
    // address=[0x13249d0]
    int  GetEconomyAIIndex(int a2);

    // address=[0x1324a40]
    bool  IsEcoSectorAIActive(int a2);

    // address=[0x1324aa0]
    bool  IsEcoSectorAIMeaningful(int a2);

    // address=[0x1324b10]
    bool  DeleteEcoSectorAI(int a2);

    // address=[0x1324b50]
    void  DeleteInvalidEcoSectorAIs(void);

    // address=[0x1324bc0]
    void  CreateNewEcoSectorAIIfNecessaryAndMeaningful(int a2, int a3);

    // address=[0x1324c60]
    void  ScanForNewEcoSectors(void);

};


#endif // CAINORMALSECTORAI_H
