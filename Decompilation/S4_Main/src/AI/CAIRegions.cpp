#include "CAIRegions.h"

#include "CBB/CBBSupport.h"
#include "Defines/AI.h"
#include "Defines/Players.h"
#include "LoadSave/IS4Chunk.h"

// Definitions for class CAIRegions

// address=[0x3e95500]
CAIRegions g_cAIRegions{};

// address=[0x1311690]
// Decompiled from void __thiscall CAIRegions::DefineRegion(CAIRegions *this, int _iRegionId, int a3, int a4, int a5)
void CAIRegions::DefineRegion(int _iRegionId, int a3, int a4, int a5) {
    if(a5 <= 0) {
        CAIRegions::ClearRegion(_iRegionId);
    } else if(CAIRegions::IsValidRegionId(_iRegionId)) {
        this->m_cRegions[_iRegionId].DefineRegion(a3, a4, a5);
        if(_iRegionId > this->m_iLastUsedRegionId)
            this->m_iLastUsedRegionId = _iRegionId;
    }
}

// address=[0x1311700]
// Decompiled from void __thiscall CAIRegions::ClearRegion(CAIRegions *this, int _iRegionId)
void CAIRegions::ClearRegion(int _iRegionId) {

    if(CAIRegions::IsValidRegionId(_iRegionId)) {
        BB_ASSERT((_iRegionId <= m_iLastUsedRegionId) || !m_cRegions[_iRegionId].Used())
        this->m_cRegions[_iRegionId].Clear();
        if(this->m_iLastUsedRegionId == _iRegionId)
            CAIRegions::CalculateLastUsedRegionId();
    }
}

// address=[0x1311790]
// Decompiled from void __thiscall CAIRegions::ClearAllRegions(CAIRegions *this)
void CAIRegions::ClearAllRegions(void) {

    int i; // [esp+4h] [ebp-4h]

    this->m_iLastUsedRegionId = 0;
    for(i = 0; i < AI_REGION_MAX; ++i)
        this->m_cRegions[i].Clear();
}

// address=[0x13117e0]
// Decompiled from void *__thiscall CAIRegions::ClearAllPlayerRegionFlags(CAIRegions *this)
void CAIRegions::ClearAllPlayerRegionFlags(void) {
    memset(this->m_vPlayerRegionFlags, 0, sizeof(this->m_vPlayerRegionFlags));
}

// address=[0x1311810]
// Decompiled from void __thiscall CAIRegions::Load(CAIRegions *this, struct IS4Chunk *a2)
void CAIRegions::Load(IS4Chunk &a2) {

    int i; // [esp+8h] [ebp-4h]

    int iRegionsMax = a2.LoadUnsigned32(AI_REGION_MAX, AI_REGION_MAX);
    BB_ASSERT(iRegionsMax == AI_REGION_MAX)
    for(i = 0; i < AI_REGION_MAX; ++i)
        this->m_cRegions[i].Load(a2);
    a2.Load(this->m_vPlayerRegionFlags, sizeof(576));
    static_assert(sizeof(this->m_vPlayerRegionFlags) == 576, "Size of m_vPlayerRegionFlags is not 576 bytes");

    CAIRegions::CalculateLastUsedRegionId();
}

// address=[0x13118b0]
// Decompiled from void __thiscall CAIRegions::Save(CAIRegions *this, struct IS4Chunk *a2)
void CAIRegions::Save(class IS4Chunk &a2) {

    int i; // [esp+4h] [ebp-4h]

    a2.SaveUnsigned32(AI_REGION_MAX);
    for(i = 0; i < AI_REGION_MAX; ++i)
        this->m_cRegions[i].Save(a2);
    a2.Save(this->m_vPlayerRegionFlags, 0x240u);
}

// address=[0x1311d90]
// Decompiled from bool __cdecl CAIRegions::IsValidRegionId(int a1)
bool __cdecl CAIRegions::IsValidRegionId(int a1) {

    return (unsigned int)(a1 - 1) < 0xF;
}

// address=[0x131ee40]
// Decompiled from void __thiscall CAIRegions::SetPlayerRegionFlagBits(  CAIRegions *this,  unsigned int _iPlayerId,  unsigned int _iRegionId,  int a4)
void CAIRegions::SetPlayerRegionFlagBits(int _iPlayerId, int _iRegionId, int a4) {

    BB_ASSERT(static_cast<unsigned int>(_iPlayerId) < PLAYER_MAX)
    BB_ASSERT(static_cast<unsigned int>(_iRegionId) < AI_REGION_MAX)

    this->m_vPlayerRegionFlags[_iPlayerId][_iRegionId] |= a4;
}

// address=[0x1311920]
// Decompiled from void __thiscall CAIRegions::CalculateLastUsedRegionId(CAIRegions *this)
void CAIRegions::CalculateLastUsedRegionId(void) {

    int i; // [esp+4h] [ebp-4h]

    this->m_iLastUsedRegionId = 0;
    for(i = AI_REGION_MAX - 1; i >= 1; --i) {
        if(this->m_cRegions[i].Used()) {
            this->m_iLastUsedRegionId = i;
            return;
        }
    }
}
