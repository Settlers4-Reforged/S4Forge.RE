#ifndef CAIMAIN_H
#define CAIMAIN_H

#include "defines.h"

class CAIMain : public IAIMain {
public:
    // address=[0x1311f30]
    virtual void  InitScripting(void);

    // address=[0x1311f50]
    virtual void  Init(void);

    // address=[0x1311fc0]
    virtual bool  IsInitialised(void);

    // address=[0x1311fe0]
    virtual void  Done(void);

    // address=[0x1312070]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x13121f0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1312330]
    virtual void  Execute(void);

    // address=[0x1312470]
    virtual void  ActivatePlayerAI(int a2);

    // address=[0x1312520]
    virtual void  DeactivatePlayerAI(int a2);

    // address=[0x13126c0]
    virtual void  DeactivateAllPlayerAIs(void);

    // address=[0x1312700]
    virtual bool  IsPlayerAIActive(int a2);

    // address=[0x1312780]
    virtual void  PostAIEvent(int a2, int a3, int a4, int a5);

    // address=[0x1313410]
    virtual void  DarkTribeIncreaseManaForNewManaSphere(int a2);

    // address=[0x13134b0]
    virtual class CStaticConfigVarInt const *  DarkTribeGetProductionCostConfigVar(int a2)const;

    // address=[0x1313570]
    virtual void  DbgPrint(int a2);

    // address=[0x1313630]
     CAIMain(void);

    // address=[0x13136e0]
    void  PrepareAI(void);

    // address=[0x1313700]
    void  CreatePlayerAI(int a2, class IS4Chunk * a3);

    // address=[0x1313f50]
     ~CAIMain(void);

    // address=[0x1314050]
    static bool __cdecl IsRealPlayerId(unsigned int a1);

};


#endif // CAIMAIN_H
