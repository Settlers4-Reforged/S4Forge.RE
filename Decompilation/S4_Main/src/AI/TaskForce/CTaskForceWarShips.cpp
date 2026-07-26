#include "CTaskForceWarShips.h"

#include "AI/IAIEnvironment.h"

// Definitions for class CTaskForceWarShips

// address=[0x132a240]
// Decompiled from CTaskForceWarShips *__thiscall CTaskForceWarShips::CTaskForceWarShips(CTaskForceWarShips *this, int a2, int a3, int a4)
CTaskForceWarShips::CTaskForceWarShips(int a2, T_AI_TASK_FORCE_TYPE a3, int a4) : CAITaskForceEx(a2, AI_TASK_FORCE_CLASS_WARSHIP, a3, a4) {}

// address=[0x132a300]
// Decompiled from struct CAITaskForce *__thiscall CTaskForceWarShips::~CTaskForceWarShips(CAITaskForce **this)
CTaskForceWarShips::~CTaskForceWarShips(void) = default;

// address=[0x132ce30]
// Decompiled from char __thiscall CTaskForceWarShips::IsAddEntityOk(CTaskForceWarShips *this, int a2)
bool CTaskForceWarShips::IsAddEntityOk(int a2) {
    if(IAIEnvironment::EntityWarriorType(a2) == AI_WARRIOR_TYPE_SHIP_WAR)
        return 1;
    IAIEnvironment::DbgTracePrintF("CTaskForceWarShips::IsAddEntityOk(): Entity %i is not a war ship!", a2);
    return 0;
}
