#ifndef CECOSECTORAI_H
#define CECOSECTORAI_H

#include "defines.h"

class CEcoSectorAI : public IAIEcoSectorAI {
public:
    // address=[0x2f34860]
     CEcoSectorAI(void);

    // address=[0x2f34890]
     CEcoSectorAI(class IAIEcoManager * a2, class IAISectorAI * a3, int a4, int a5);

    // address=[0x2f34a20]
     ~CEcoSectorAI(void);

    // address=[0x2f34af0]
    virtual void  Release(void);

    // address=[0x2f34b30]
    void  ReadConfigFile(void);

    // address=[0x2f34bb0]
    virtual void  Execute(void);

    // address=[0x2f34bd0]
    virtual enum T_AI_BUILD_RESULT  PutUpBuilding(int a2, int a3, int a4, int a5);

    // address=[0x2f34c90]
    virtual int  Flags(void);

    // address=[0x2f34cb0]
    virtual void  SetFlags(int a2);

};


#endif // CECOSECTORAI_H
