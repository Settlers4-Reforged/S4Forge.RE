#ifndef CAIPLAYEREVALUATIONS_H
#define CAIPLAYEREVALUATIONS_H

#include "CAIPlayerEvaluation.h"
#include "defines.h"

class CAIPlayerEvaluations {
public:
    // address=[0x1303c50]
    void EvaluatePlayer(int a2);

    // address=[0x1311500]
    void Clear(void);

    // address=[0x1311540]
    void EvaluateAllPlayers(void);

    // address=[0x1311590]
    void DbgPrint(void);

    // Type information members
public:
    CAIPlayerEvaluation m_sPlayerEvaluations[9];
};


#endif // CAIPLAYEREVALUATIONS_H
