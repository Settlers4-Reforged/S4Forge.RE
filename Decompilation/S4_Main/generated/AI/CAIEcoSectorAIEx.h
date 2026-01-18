#ifndef CAIECOSECTORAIEX_H
#define CAIECOSECTORAIEX_H

#include "defines.h"

class CAIEcoSectorAIEx : public IAIUnknown {
public:
    // address=[0x13098e0]
     CAIEcoSectorAIEx(class IAISectorAI * a2, int a3);

    // address=[0x1309a50]
     ~CAIEcoSectorAIEx(void);

    // address=[0x1309b30]
    static class CAIEcoSectorAIEx * __cdecl CreateEcoSectorAIEx(class IAISectorAI * a1, int a2);

    // address=[0x1309bc0]
    virtual void  Execute(void);

    // address=[0x1309cc0]
    virtual void  Release(void);

    // address=[0x1309ce0]
    bool  IsEcoSectorValid(void)const;

    // address=[0x13260f0]
    void  ClearEventQueue(void);

    // address=[0x1326110]
    unsigned int  CreationTime(void)const;

    // address=[0x1326150]
    int  EcoSectorId(void)const;

    // address=[0x13261b0]
    void  PostAIEvent(int a2, int a3, int a4, int a5);

};


#endif // CAIECOSECTORAIEX_H
