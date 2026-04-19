#ifndef CAIENTITYINFOTOWER_H
#define CAIENTITYINFOTOWER_H

#include "defines.h"
#include "CAIEntityInfoEx.h"

class CAIEntityInfoTower : public CAIEntityInfoEx {
public:
    // address=[0x130ad10]
    virtual ~CAIEntityInfoTower(void);

protected:
    friend class CAIEntityInfoEx;

    // address=[0x130aba0]
    CAIEntityInfoTower(void);

    // Type information members
public:
    int m_iOwnValue;
    int m_iAllyValue;
    int m_iEnemyValue;
};


#endif // CAIENTITYINFOTOWER_H
