#if FALSE
#include "CAIRegions.h"

// Definitions for class CAIRegions

// address=[0x1311690]
// Decompiled from void __thiscall CAIRegions::DefineRegion(CAIRegions *this, int _iRegionId, int a3, int a4, int a5)
void  CAIRegions::DefineRegion(int _iRegionId, int a3, int a4, int a5) {
  
  if ( a5 <= 0 )
  {
    CAIRegions::ClearRegion(this, _iRegionId);
  }
  else if ( CAIRegions::IsValidRegionId(_iRegionId) )
  {
    CAIRegion::DefineRegion(&this->m_cRegions[_iRegionId], a3, a4, a5);
    if ( _iRegionId > this->m_iLastUsedRegionId )
      this->m_iLastUsedRegionId = _iRegionId;
  }
}


// address=[0x1311700]
// Decompiled from void __thiscall CAIRegions::ClearRegion(CAIRegions *this, int _iRegionId)
void  CAIRegions::ClearRegion(int _iRegionId) {
  
  if ( CAIRegions::IsValidRegionId(_iRegionId) )
  {
    if ( _iRegionId > this->m_iLastUsedRegionId
      && CAIRegion::Used(&this->m_cRegions[_iRegionId])
      && BBSupportDbgReport(
           2,
           "AI\\AI_Global.cpp",
           555,
           "(_iRegionId <= m_iLastUsedRegionId ) || !m_cRegions[_iRegionId].Used()") == 1 )
    {
      __debugbreak();
    }
    CAIRegion::Clear(&this->m_cRegions[_iRegionId]);
    if ( this->m_iLastUsedRegionId == _iRegionId )
      CAIRegions::CalculateLastUsedRegionId(this);
  }
}


// address=[0x1311790]
// Decompiled from void __thiscall CAIRegions::ClearAllRegions(CAIRegions *this)
void  CAIRegions::ClearAllRegions(void) {
  
  int i; // [esp+4h] [ebp-4h]

  this->m_iLastUsedRegionId = 0;
  for ( i = 0; i < 16; ++i )
    CAIRegion::Clear(&this->m_cRegions[i]);
}


// address=[0x13117e0]
// Decompiled from void *__thiscall CAIRegions::ClearAllPlayerRegionFlags(CAIRegions *this)
void  CAIRegions::ClearAllPlayerRegionFlags(void) {
  
  return memset(this->m_vPlayerRegionFlags, 0, sizeof(this->m_vPlayerRegionFlags));
}


// address=[0x1311810]
// Decompiled from void __thiscall CAIRegions::Load(CAIRegions *this, struct IS4Chunk *a2)
void  CAIRegions::Load(class IS4Chunk & a2) {
  
  int i; // [esp+8h] [ebp-4h]

  if ( a2->LoadUnsigned32(16, 16) != 16
    && BBSupportDbgReport(2, "AI\\AI_Global.cpp", 602, "iRegionsMax == AI_REGION_MAX") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < 16; ++i )
    CAIRegion::Load(&this->m_cRegions[i], a2);
  a2->Load(this->m_vPlayerRegionFlags, 576);
  CAIRegions::CalculateLastUsedRegionId(this);
}


// address=[0x13118b0]
// Decompiled from void __thiscall CAIRegions::Save(CAIRegions *this, struct IS4Chunk *a2)
void  CAIRegions::Save(class IS4Chunk & a2) {
  
  int i; // [esp+4h] [ebp-4h]

  a2->SaveUnsigned32(16);
  for ( i = 0; i < 16; ++i )
    CAIRegion::Save(&this->m_cRegions[i], a2);
  a2->Save(this->m_vPlayerRegionFlags, 0x240u);
}


// address=[0x1311d90]
// Decompiled from bool __cdecl CAIRegions::IsValidRegionId(int a1)
bool __cdecl CAIRegions::IsValidRegionId(int a1) {
  
  return (unsigned int)(a1 - 1) < 0xF;
}


// address=[0x131ee40]
// Decompiled from void __thiscall CAIRegions::SetPlayerRegionFlagBits(  CAIRegions *this,  unsigned int _iPlayerId,  unsigned int _iRegionId,  int a4)
void  CAIRegions::SetPlayerRegionFlagBits(int _iPlayerId, int _iRegionId, int a4) {
  
  if ( _iPlayerId >= 9
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Global.h",
         262,
         "static_cast<unsigned int>(_iPlayerId) < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iRegionId >= 0x10
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Global.h",
         263,
         "static_cast<unsigned int>(_iRegionId) < AI_REGION_MAX") == 1 )
  {
    __debugbreak();
  }
  this->m_vPlayerRegionFlags[_iPlayerId][_iRegionId] |= a4;
}


// address=[0x1311920]
// Decompiled from void __thiscall CAIRegions::CalculateLastUsedRegionId(CAIRegions *this)
void  CAIRegions::CalculateLastUsedRegionId(void) {
  
  int i; // [esp+4h] [ebp-4h]

  this->m_iLastUsedRegionId = 0;
  for ( i = 15; i >= 1; --i )
  {
    if ( CAIRegion::Used(&this->m_cRegions[i]) )
    {
      this->m_iLastUsedRegionId = i;
      return;
    }
  }
}


#endif // Already implemented
