#ifndef CAIENTITYINFOTOWER_H
#define CAIENTITYINFOTOWER_H

#include "defines.h"

class CAIEntityInfoTower : public CAIEntityInfoEx {
public:
    // address=[0x130ad10]
    virtual  ~CAIEntityInfoTower(void);

protected:
    // address=[0x130aba0]
     CAIEntityInfoTower(void);

    // Type information members
public:
    _DWORD dword8;
    _DWORD dwordC;
    _DWORD dword10;

};


#endif // CAIENTITYINFOTOWER_H
