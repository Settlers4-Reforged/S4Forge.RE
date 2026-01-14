#ifndef CAINORMALSECTORAI_H
#define CAINORMALSECTORAI_H

class CAINormalSectorAI : public CAISectorAI {
public:
    // address=[0x1323250]
     CAINormalSectorAI(class CAIPlayerAI &,int);

    // address=[0x13237a0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1323ab0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1323dc0]
    virtual void  PostAIEvent(int,int,int,int);

    // address=[0x1323e80]
    virtual void  Execute(void);

    // address=[0x1323f40]
    virtual bool  ProcessEvent(class CAIEvent const *);

    // address=[0x1324390]
    void  AttachAgentEx(class CAINormalSectorAgent &,unsigned int,unsigned int,unsigned int);

    // address=[0x13243d0]
    virtual void  DbgPrint(void);

    // address=[0x13244c0]
    void  OccupationCheck(int);

    // address=[0x1324670]
    int  FindTargetForSuicideMission(class CAITaskForce *);

    // address=[0x1324930]
    void  MoveSquadHome(class CAITaskForce *);

    // address=[0x1324cf0]
    void  EvaluateNextEnemyMilitaryBuilding(void);

    // address=[0x1324f20]
    bool  EvaluateNextOwnMilitaryBuilding(void);

    // address=[0x1325170]
    void  PostAIEventToAllEcoSectorAIs(int,int,int,int);

    // address=[0x1325d10]
    virtual  ~CAINormalSectorAI(void);

    // address=[0x13261a0]
    virtual bool  IsNormalPlayerSector(void)const;

protected:
    // address=[0x13249d0]
    int  GetEconomyAIIndex(int);

    // address=[0x1324a40]
    bool  IsEcoSectorAIActive(int);

    // address=[0x1324aa0]
    bool  IsEcoSectorAIMeaningful(int);

    // address=[0x1324b10]
    bool  DeleteEcoSectorAI(int);

    // address=[0x1324b50]
    void  DeleteInvalidEcoSectorAIs(void);

    // address=[0x1324bc0]
    void  CreateNewEcoSectorAIIfNecessaryAndMeaningful(int,int);

    // address=[0x1324c60]
    void  ScanForNewEcoSectors(void);

};


#endif // CAINORMALSECTORAI_H
