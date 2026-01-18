#ifndef CTASKFORCEWARSHIPS_H
#define CTASKFORCEWARSHIPS_H

#include "defines.h"

class CTaskForceWarShips : public CAITaskForceEx {
public:
    // address=[0x132a240]
     CTaskForceWarShips(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132a300]
    virtual  ~CTaskForceWarShips(void);

    // address=[0x132ce30]
    virtual bool  IsAddEntityOk(int a2);

};


#endif // CTASKFORCEWARSHIPS_H
