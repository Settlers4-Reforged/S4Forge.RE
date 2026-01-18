#ifndef CSTATELOADGAME_H
#define CSTATELOADGAME_H

#include "defines.h"

class CStateLoadGame : public CGuiGameState {
public:
    // address=[0x148fe10]
    static void __cdecl InitSaveList(void);

    // address=[0x14b52b0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14b5680]
     CStateLoadGame(void * a2);

    // address=[0x14b57c0]
    virtual  ~CStateLoadGame(void);

    // address=[0x14b5840]
    virtual bool  Perform(void);

    // address=[0x14b58e0]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14b5a30]
    static void __cdecl BuildSaveList(enum TGAME_TYPE a1, enum CAMPAIGN_TYPE a2);

    // address=[0x14b5dd0]
    static void __cdecl DestroySaveList(void);

    // address=[0x402f3d0]
    static struct SSaveEntry * * m_stempSavePtr;

private:
    // address=[0x14b5330]
    static bool __cdecl FileMatch(wchar_t const * String, enum TGAME_TYPE a2, enum CAMPAIGN_TYPE a3, std::string & a4);

};


#endif // CSTATELOADGAME_H
