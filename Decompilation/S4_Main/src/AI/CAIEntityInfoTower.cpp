#include "CAIEntityInfoTower.h"

// Definitions for class CAIEntityInfoTower

// address=[0x130ad10]
// Decompiled from CAIEntityInfoEx *__thiscall CAIEntityInfoTower::~CAIEntityInfoTower(CAIEntityInfoTower *this)
CAIEntityInfoTower::~CAIEntityInfoTower(void) = default;

// address=[0x130aba0]
// Decompiled from CAIEntityInfoTower *__thiscall CAIEntityInfoTower::CAIEntityInfoTower(CAIEntityInfoTower *this)
CAIEntityInfoTower::CAIEntityInfoTower(void) : CAIEntityInfoEx(AI_ENTITY_INFO_EX_CLASS_TOWER) {
    this->m_iOwnValue = 0;
    this->m_iAllyValue = 0;
    this->m_iEnemyValue = 0;
}


