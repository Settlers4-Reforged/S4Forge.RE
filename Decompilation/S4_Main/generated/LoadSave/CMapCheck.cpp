#include "CMapCheck.h"

// Definitions for class CMapCheck

// address=[0x1496ac0]
// Decompiled from int __thiscall CMapCheck::CalculateMapCRC2(CMapCheck *this, int a2, int a3, int a4, int a5, int a6)
unsigned int  CMapCheck::CalculateMapCRC2(int,int,int,int,int) {
  
  return sub_1496A50(a2, a3, a4, a5, a6);
}


// address=[0x1496af0]
// Decompiled from int __stdcall CMapCheck::GetPatchMap(wchar_t *Source, int a2, int a3)
enum IMapCheck::PATCHMAPS  CMapCheck::GetPatchMap(wchar_t const *,unsigned int,unsigned int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; dword_3D89BB8[4 * i]; ++i )
  {
    if ( a2 == dword_3D89BB0[4 * i]
      && a3 == dword_3D89BB4[4 * i]
      && (unsigned __int8)CMapCheck::StrStrLo(Source, (&off_3D89BAC)[4 * i]) )
    {
      return dword_3D89BB8[4 * i];
    }
  }
  return 0;
}


// address=[0x1496d10]
// Decompiled from CMapCheck *__thiscall CMapCheck::CMapCheck(CMapCheck *this)
 CMapCheck::CMapCheck(void) {
  
  IMapCheck::IMapCheck(this);
  *(_DWORD *)this = &CMapCheck::_vftable_;
  return this;
}


// address=[0x1496b80]
// Decompiled from bool __cdecl CMapCheck::StrStrLo(wchar_t *Source, wchar_t *SubStr)
static bool __cdecl CMapCheck::StrStrLo(wchar_t const *,wchar_t const *) {
  
  wchar_t Destination[1024]; // [esp+Ch] [ebp-804h] BYREF

  if ( !Source || !*Source )
    return 0;
  if ( !SubStr || !*SubStr )
    return 1;
  j__wcsncpy(Destination, Source, 0x3FFu);
  Destination[1023] = 0;
  j___wcslwr(Destination);
  return wcsstr(Destination, SubStr) != 0;
}


