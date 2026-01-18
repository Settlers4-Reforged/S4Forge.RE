#ifndef CAIDARKTRIBESECTORAI_H
#define CAIDARKTRIBESECTORAI_H

#include "defines.h"

class CAIDarkTribeSectorAI : public CAISectorAI {
public:
    // address=[0x1303820]
    class IAIDarkTribeEcoAI *  EconomyAI(void)const;

    // address=[0x1322250]
    virtual  ~CAIDarkTribeSectorAI(void);

    // address=[0x1322390]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x13224d0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1322610]
    virtual void  PostAIEvent(int a2, int a3, int a4, int a5);

    // address=[0x1322660]
    virtual void  Execute(void);

    // address=[0x1322690]
    bool  FindMushroomFarm(int & a2, int & a3, int a4, int a5);

    // address=[0x1323210]
    virtual void  DbgPrint(void);

    // address=[0x1323240]
    virtual bool  IsNormalPlayerSector(void)const;

protected:
    // address=[0x1321d50]
     CAIDarkTribeSectorAI(class CAIPlayerAI & a2, int a3);

    // address=[0x13228d0]
    virtual bool  ProcessEvent(class CAIEvent const * a2);

    // address=[0x1322a00]
    void  AttachAgentEx(class CAIDarkTribeSectorAgent & a2, unsigned int a3, unsigned int a4, unsigned int a5);

};


#endif // CAIDARKTRIBESECTORAI_H
