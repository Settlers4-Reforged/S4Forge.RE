#ifndef CCONDITIONSET_H
#define CCONDITIONSET_H

#include "defines.h"

class CConditionSet {
public:
    // address=[0x2f3ee40]
     CConditionSet(void);

    // address=[0x2f3eec0]
     ~CConditionSet(void);

    // address=[0x2f3ef00]
    int  size(void);

    // address=[0x2f3ef20]
    class CCondition *  elementAt(int a2);

    // address=[0x2f3ef40]
    void  NewMayProblem(int a2, class CParam * a3);

    // address=[0x2f3efe0]
    void  NewMayProblem(int a2, class CParam * a3, class COptimizeOptions * a4);

    // address=[0x2f3f010]
    void  NewProblem(int a2, class CParam * a3);

    // address=[0x2f3f0a0]
    void  NewProblem(int a2, class CParam * a3, class COptimizeOptions * a4);

    // address=[0x2f3f1e0]
    void  Ausgabe(void);

};


#endif // CCONDITIONSET_H
