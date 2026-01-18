#ifndef CWALKINGWORKER_H
#define CWALKINGWORKER_H

#include "defines.h"

class CWalkingWorker : public CWalkingBase {
public:
    // address=[0x15f90b0]
     CWalkingWorker(int a2);

    // address=[0x15fafd0]
    virtual  ~CWalkingWorker(void);

    // address=[0x15fb290]
    virtual enum T_WALKING_TYPE const  GetWalkingType(void);

protected:
    // address=[0x15f90f0]
    virtual bool  IsNotBlocked(int a2);

    // address=[0x15f9150]
    virtual int  SectorId(int a2);

    // address=[0x15f9170]
    virtual bool  FindPathAStar64(int a2, int a3, class CDirCache & a4);

};


#endif // CWALKINGWORKER_H
