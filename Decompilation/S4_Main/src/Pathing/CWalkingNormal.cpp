#include "CWalkingNormal.h"

#include "Defines/Walking.h"

// Definitions for class CWalkingNormal

// address=[0x15f9070]
// Decompiled from CWalkingNormal *__thiscall CWalkingNormal::CWalkingNormal(CWalkingNormal *this, int a2)
CWalkingNormal::CWalkingNormal(int a2) : CWalkingBase(WALKING_TYPE_NORMAL, a2) {
    this->m_sData.m_iEntityFlags = this->m_sData.m_iEntityFlags;
}


// address=[0x15faf90]
// Decompiled from CWalking *__thiscall CWalkingNormal::~CWalkingNormal(CWalkingNormal *this)
CWalkingNormal::~CWalkingNormal(void) = default;

// address=[0x15fb260]
// Decompiled from int CWalkingNormal::GetWalkingType()
enum T_WALKING_TYPE const CWalkingNormal::GetWalkingType(void) {
    return WALKING_TYPE_NORMAL;
}


