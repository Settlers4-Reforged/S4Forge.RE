#ifndef CAIPLAYEREVALUATIONS_H
#define CAIPLAYEREVALUATIONS_H

#include "defines.h"

class CAIPlayerEvaluations {
public:
    // address=[0x1303c50]
    void  EvaluatePlayer(int a2);

    // address=[0x1311500]
    void  Clear(void);

    // address=[0x1311540]
    void  EvaluateAllPlayers(void);

    // address=[0x1311590]
    void  DbgPrint(void);

};


#endif // CAIPLAYEREVALUATIONS_H
