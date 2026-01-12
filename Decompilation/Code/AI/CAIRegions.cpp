#include "CAIRegions.h"

// Definitions for class CAIRegions

// address=[0x1311690]
// Decompiled from void __thiscall CAIRegions::DefineRegion(CAIRegions *this, int a2, int a3, int a4, int a5)
void  CAIRegions::DefineRegion(int,int,int,int) {
  
  if ( a5 <= 0 )
  {
    CAIRegions::ClearRegion(this, a2);
  }
  else if ( CAIRegions::IsValidRegionId(a2) )
  {
    CAIRegion::DefineRegion((CAIRegions *)((char *)this + 12 * a2 + 4), a3, a4, a5);
    if ( a2 > *(_DWORD *)this )
      *(_DWORD *)this = a2;
  }
}


// address=[0x1311700]
// Decompiled from void __thiscall CAIRegions::ClearRegion(CAIRegions *this, int a2)
void  CAIRegions::ClearRegion(int) {
  
  if ( CAIRegions::IsValidRegionId(a2) )
  {
    if ( a2 > *(_DWORD *)this
      && CAIRegion::Used((CAIRegions *)((char *)this + 12 * a2 + 4))
      && BBSupportDbgReport(
           2,
           "AI\\AI_Global.cpp",
           555,
           "(_iRegionId <= m_iLastUsedRegionId ) || !m_cRegions[_iRegionId].Used()") == 1 )
    {
      __debugbreak();
    }
    CAIRegion::Clear((CAIRegions *)((char *)this + 12 * a2 + 4));
    if ( *(_DWORD *)this == a2 )
      CAIRegions::CalculateLastUsedRegionId(this);
  }
}


// address=[0x1311790]
// Decompiled from int __thiscall CAIRegions::ClearAllRegions(CAIRegions *this)
void  CAIRegions::ClearAllRegions(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  result = 0;
  *(_DWORD *)this = 0;
  for ( i = 0; i < 16; ++i )
  {
    CAIRegion::Clear((CAIRegions *)((char *)this + 12 * i + 4));
    result = i + 1;
  }
  return result;
}


// address=[0x13117e0]
// Decompiled from void *__thiscall CAIRegions::ClearAllPlayerRegionFlags(int this)
void  CAIRegions::ClearAllPlayerRegionFlags(void) {
  
  return j__memset((void *)(this + 196), 0, 0x240u);
}


// address=[0x1311810]
// Decompiled from void __thiscall CAIRegions::Load(CAIRegions *this, struct IS4Chunk *a2)
void  CAIRegions::Load(class IS4Chunk &) {
  
  int i; // [esp+8h] [ebp-4h]

  if ( (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 16, 16) != 16
    && BBSupportDbgReport(2, "AI\\AI_Global.cpp", 602, "iRegionsMax == AI_REGION_MAX") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < 16; ++i )
    CAIRegion::Load((CAIRegions *)((char *)this + 12 * i + 4), a2);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 196, 576);
  CAIRegions::CalculateLastUsedRegionId(this);
}


// address=[0x13118b0]
// Decompiled from int __thiscall CAIRegions::Save(CAIRegions *this, struct IS4Chunk *a2)
void  CAIRegions::Save(class IS4Chunk &) {
  
  int i; // [esp+4h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 16);
  for ( i = 0; i < 16; ++i )
    CAIRegion::Save((CAIRegions *)((char *)this + 12 * i + 4), a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 196, 576);
}


// address=[0x1311d90]
// Decompiled from bool __cdecl CAIRegions::IsValidRegionId(int a1)
static bool __cdecl CAIRegions::IsValidRegionId(int) {
  
  return (unsigned int)(a1 - 1) < 0xF;
}


// address=[0x131ee40]
// Decompiled from int __thiscall CAIRegions::SetPlayerRegionFlagBits(CAIRegions *this, unsigned int a2, unsigned int a3, int a4)
void  CAIRegions::SetPlayerRegionFlagBits(int,int,int) {
  
  int result; // eax

  if ( a2 >= 9
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Global.h",
         262,
         "static_cast<unsigned int>(_iPlayerId) < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 0x10
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Global.h",
         263,
         "static_cast<unsigned int>(_iRegionId) < AI_REGION_MAX") == 1 )
  {
    __debugbreak();
  }
  result = a4 | *((_DWORD *)this + 16 * a2 + a3 + 49);
  *((_DWORD *)this + 16 * a2 + a3 + 49) = result;
  return result;
}


// address=[0x1311920]
// Decompiled from char __thiscall CAIRegions::CalculateLastUsedRegionId(CAIRegions *this)
void  CAIRegions::CalculateLastUsedRegionId(void) {
  
  char result; // al
  int i; // [esp+4h] [ebp-4h]

  result = (char)this;
  *(_DWORD *)this = 0;
  for ( i = 15; i >= 1; --i )
  {
    result = CAIRegion::Used((CAIRegions *)((char *)this + 12 * i + 4));
    if ( result )
    {
      result = i;
      *(_DWORD *)this = i;
      return result;
    }
  }
  return result;
}


