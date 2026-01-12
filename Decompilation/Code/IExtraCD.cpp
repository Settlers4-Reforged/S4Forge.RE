#include "IExtraCD.h"

// Definitions for class IExtraCD

// address=[0x1481500]
// Decompiled from CMissionCD *IExtraCD::CreateMissionCDObject()
static class IExtraCD * __cdecl IExtraCD::CreateMissionCDObject(void) {
  
  CMissionCD *C; // [esp+Ch] [ebp-10h]

  C = (CMissionCD *)operator new(0xCu);
  if ( !C )
    return 0;
  *(_DWORD *)C = 0;
  *((_DWORD *)C + 1) = 0;
  *((_DWORD *)C + 2) = 0;
  return CMissionCD::CMissionCD(C);
}


// address=[0x1481580]
// Decompiled from CAddOn *IExtraCD::CreateAddOnCDObject()
static class IExtraCD * __cdecl IExtraCD::CreateAddOnCDObject(void) {
  
  CAddOn *C; // [esp+Ch] [ebp-10h]

  C = (CAddOn *)operator new(0xCu);
  if ( !C )
    return 0;
  *(_DWORD *)C = 0;
  *((_DWORD *)C + 1) = 0;
  *((_DWORD *)C + 2) = 0;
  return CAddOn::CAddOn(C);
}


// address=[0x1481600]
// Decompiled from CMissionCD2 *IExtraCD::CreateMissionCD2Object()
static class IExtraCD * __cdecl IExtraCD::CreateMissionCD2Object(void) {
  
  CMissionCD2 *C; // [esp+Ch] [ebp-10h]

  C = (CMissionCD2 *)operator new(0xCu);
  if ( !C )
    return 0;
  *(_DWORD *)C = 0;
  *((_DWORD *)C + 1) = 0;
  *((_DWORD *)C + 2) = 0;
  return CMissionCD2::CMissionCD2(C);
}


// address=[0x1481680]
// Decompiled from CMissionCD3 *IExtraCD::CreateMissionCD3Object()
static class IExtraCD * __cdecl IExtraCD::CreateMissionCD3Object(void) {
  
  CMissionCD3 *C; // [esp+Ch] [ebp-10h]

  C = (CMissionCD3 *)operator new(0xCu);
  if ( !C )
    return 0;
  *(_DWORD *)C = 0;
  *((_DWORD *)C + 1) = 0;
  *((_DWORD *)C + 2) = 0;
  return CMissionCD3::CMissionCD3(C);
}


// address=[0x1481fb0]
// Decompiled from IExtraCD *__thiscall IExtraCD::IExtraCD(IExtraCD *this)
 IExtraCD::IExtraCD(void) {
  
  *(_DWORD *)this = &IExtraCD::_vftable_;
  return this;
}


// address=[0x1482050]
// Decompiled from IExtraCD *__thiscall IExtraCD::~IExtraCD(IExtraCD *this)
 IExtraCD::~IExtraCD(void) {
  
  IExtraCD *result; // eax

  result = this;
  *(_DWORD *)this = &IExtraCD::_vftable_;
  return result;
}


