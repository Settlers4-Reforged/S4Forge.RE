#ifndef CDEBITLEVELMANAGER_H
#define CDEBITLEVELMANAGER_H

#include "defines.h"

class CDebitLevelManager {
public:
    // address=[0x2f58b30]
     CDebitLevelManager(class CSchedule *);

    // address=[0x2f58b60]
     ~CDebitLevelManager(void);

    // address=[0x2f58b70]
    bool  AddDebitLevel(int a2, enum PILE_TYPES a3, bool a4, int a5, int a6, int a7, int a8, int a9, int a10);

    // address=[0x2f58d00]
    int  GetDebitValue(int a2, enum PILE_TYPES a3, bool a4, int a5);

    // address=[0x2f58df0]
    int  DebitPreCondition(int a2);

    // address=[0x2f59050]
    int  DebitException(int a2);

};


#endif // CDEBITLEVELMANAGER_H
