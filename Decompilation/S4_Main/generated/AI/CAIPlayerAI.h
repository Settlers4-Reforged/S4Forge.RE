#ifndef CAIPLAYERAI_H
#define CAIPLAYERAI_H

#include "defines.h"

class CAIPlayerAI : public IAIUnknown, public IS4ChunkObject {
public:
    // address=[0x12fd510]
    int  PlayerId(void)const;

    // address=[0x1306930]
    int  Race(void)const;

    // address=[0x13175a0]
    virtual void  Execute(void);

    // address=[0x1317660]
    virtual void  Release(void);

    // address=[0x1317680]
    void  PostAIEvent(int a2, int a3, int a4, int a5);

    // address=[0x13176b0]
     CAIPlayerAI(int a2, bool a3);

    // address=[0x1317870]
     ~CAIPlayerAI(void);

    // address=[0x1317920]
    virtual void  Init(void);

    // address=[0x1317930]
    static class CAIPlayerAI * __cdecl CreatePlayerAI(int a1, class IS4Chunk * a2);

    // address=[0x1317a90]
    void  DbgPrint(void);

    // address=[0x1317ae0]
    int  GetNumberOfOwnBuildings(int a2, int a3);

    // address=[0x1317b10]
    int  GetNumberOfOwnVehicles(int a2, int a3);

    // address=[0x1317b40]
    void  MoveEntitiesToSectorReservoirs(void);

    // address=[0x1317bd0]
    void  ScanForNewSectors(void);

    // address=[0x1317e10]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1317f40]
    virtual void  Save(class IS4Chunk & a2);

protected:
    // address=[0x1318070]
    void  ProcessEvents(void);

    // address=[0x1318660]
    void  CalculateSectorAndEcoSectorIds(void);

    // address=[0x13186e0]
    int  FillGeneralReservoir(void);

    // address=[0x1318820]
    void  AddEntityToSectorReservoir(int a2, enum T_AI_WARRIOR_TYPE a3, int a4);

    // address=[0x1318920]
    void  MoveNewWarShips(int a2, int a3, bool a4);

    // address=[0x13189b0]
    bool  ExistsSectorAI(int a2);

    // address=[0x1318a10]
    void  MoveToSuicideSquad(void);

};


#endif // CAIPLAYERAI_H
