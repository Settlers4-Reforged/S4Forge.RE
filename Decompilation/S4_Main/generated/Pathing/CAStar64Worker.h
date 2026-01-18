#ifndef CASTAR64WORKER_H
#define CASTAR64WORKER_H

#include "defines.h"

class CAStar64Worker : public CAStar64Normal {
public:
    // address=[0x15d3dc0]
    static bool __cdecl IsNotBlocked(int a1);

    // address=[0x15d3e20]
    static int __cdecl MoveCosts(int a1, int a2);

    // address=[0x15d5f50]
     CAStar64Worker(void);

private:
    // address=[0x15d3d60]
    virtual bool  InitFindPath(void);

    // address=[0x415c774]
    static int m_iEcoSectorId;

};


#endif // CASTAR64WORKER_H
