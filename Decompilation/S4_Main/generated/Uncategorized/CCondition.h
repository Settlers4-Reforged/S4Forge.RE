#ifndef CCONDITION_H
#define CCONDITION_H

#include "defines.h"

class CCondition : public CDynListEntry {
public:
    // address=[0x2f3ed60]
     CCondition(void);

    // address=[0x2f3ed80]
    virtual  ~CCondition(void);

    // address=[0x2f3ee00]
     CCondition(int a2, class CParam * a3, class COptimizeOptions * a4);

};


#endif // CCONDITION_H
