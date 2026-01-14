#include "all_headers.h"

// Definitions for class CAIWatchTowers

// address=[0x132f0e0]
// Decompiled from CAIWatchTowers *__thiscall CAIWatchTowers::CAIWatchTowers(CAIWatchTowers *this)
 CAIWatchTowers::CAIWatchTowers(void) {
  
  IAIWatchTowers::IAIWatchTowers(this);
  *(_DWORD *)this = CAIWatchTowers::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 204) = CAIWatchTowers::DefaultCallback;
  return this;
}


// address=[0x132f120]
// Decompiled from CAIWatchTowers *__thiscall CAIWatchTowers::Init(CAIWatchTowers *this)
void  CAIWatchTowers::Init(void) {
  
  CAIWatchTower *v1; // eax
  CAIWatchTowers *result; // eax

  if ( *((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 363, "!m_bInitialized") == 1 )
    __debugbreak();
  v1 = CAIWatchTowers::WatchTower(this, 0);
  CAIWatchTower::Done(v1);
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 205) = 0;
  result = this;
  *((_DWORD *)this + 206) = 0;
  *((_BYTE *)this + 4) = 1;
  return result;
}


// address=[0x132f1a0]
// Decompiled from CAIWatchTowers *__thiscall CAIWatchTowers::Done(CAIWatchTowers *this)
void  CAIWatchTowers::Done(void) {
  
  CAIWatchTowers *result; // eax

  result = this;
  if ( *((_BYTE *)this + 4) )
    *((_BYTE *)this + 4) = 0;
  return result;
}


// address=[0x132f1c0]
// Decompiled from int __thiscall CAIWatchTowers::AddWatchTower(CAIWatchTowers *this, int a2, int a3, int a4)
int  CAIWatchTowers::AddWatchTower(int,int,int) {
  
  CAIWatchTower *v4; // eax
  int v6; // [esp+0h] [ebp-8h]

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 396, "m_bInitialized") == 1 )
    __debugbreak();
  v6 = CAIWatchTowers::PushUndef(this);
  v4 = CAIWatchTowers::WatchTower(this, v6);
  CAIWatchTower::Init(v4, a2, a3, a4);
  return v6;
}


// address=[0x132f230]
// Decompiled from void __thiscall CAIWatchTowers::DelWatchTower(CAIWatchTowers *this, int a2)
void  CAIWatchTowers::DelWatchTower(int) {
  
  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 410, "m_bInitialized") == 1 )
    __debugbreak();
  if ( CAIWatchTowers::ValidUsedWatchTower(this, a2) )
  {
    CAIWatchTowers::Remove(this, a2);
  }
  else if ( "DelWatchTower called with invalid or unused watch tower id" )
  {
    if ( BBSupportDbgReport(
           2,
           "AI\\AI_WatchTower.cpp",
           418,
           "!\"DelWatchTower called with invalid or unused watch tower id\"") == 1 )
      __debugbreak();
  }
}


// address=[0x132f2c0]
// Decompiled from void (__cdecl **__thiscall CAIWatchTowers::RegisterCallback(  void (__cdecl **this)(int, int),  void (__cdecl *a2)(int, int)))(int, int)
void  CAIWatchTowers::RegisterCallback(void (__cdecl*)(int,int)) {
  
  void (__cdecl **result)(int, int); // eax

  result = this;
  if ( this[204] != CAIWatchTowers::DefaultCallback )
  {
    result = (void (__cdecl **)(int, int))BBSupportDbgReport(
                                            2,
                                            "AI\\AI_WatchTower.cpp",
                                            475,
                                            "m_pCallback == DefaultCallback");
    if ( result == (void (__cdecl **)(int, int))1 )
      __debugbreak();
  }
  if ( a2 )
  {
    this[204] = 0;
  }
  else
  {
    result = this;
    this[204] = CAIWatchTowers::DefaultCallback;
  }
  return result;
}


// address=[0x132f320]
// Decompiled from CAIWatchTowers *__thiscall CAIWatchTowers::UnregisterCallback(CAIWatchTowers *this)
void  CAIWatchTowers::UnregisterCallback(void) {
  
  CAIWatchTowers *result; // eax

  result = this;
  *((_DWORD *)this + 204) = CAIWatchTowers::DefaultCallback;
  return result;
}


// address=[0x132f340]
// Decompiled from int __thiscall CAIWatchTowers::CalculateAndCallback(CAIWatchTowers *this)
void  CAIWatchTowers::CalculateAndCallback(void) {
  
  int v1; // edx
  int result; // eax
  CAIWatchTowerEx *v3; // eax

  if ( !*((_BYTE *)this + 4) && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 429, "m_bInitialized") == 1 )
    __debugbreak();
  v1 = *((_DWORD *)this + 206) - CAIWatchTowers::Count(this);
  result = (int)this;
  *((_DWORD *)this + 206) = v1;
  while ( *((int *)this + 206) < 0 )
  {
    *((_DWORD *)this + 206) += 15;
    *((_DWORD *)this + 205) = CAIWatchTowers::NextUsedWatchTower(this, *((_DWORD *)this + 205));
    v3 = CAIWatchTowers::WatchTower(this, *((_DWORD *)this + 205));
    result = CAIWatchTowerEx::Calculate(v3);
    if ( (result & 2) != 0 )
      result = (*((int (__cdecl **)(_DWORD, int))this + 204))(*((_DWORD *)this + 205), result);
  }
  return result;
}


// address=[0x132f420]
// Decompiled from int __thiscall CAIWatchTowers::CalculateAll(CAIWatchTowers *this)
void  CAIWatchTowers::CalculateAll(void) {
  
  int result; // eax
  CAIWatchTower *v2; // eax
  CAIWatchTowerEx *v3; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = CAIWatchTowers::First(this); ; ++i )
  {
    result = CAIWatchTowers::Last(this);
    if ( i > result )
      break;
    v2 = CAIWatchTowers::WatchTower(this, i);
    if ( CAIWatchTower::Used(v2) )
    {
      v3 = CAIWatchTowers::WatchTower(this, i);
      CAIWatchTowerEx::Calculate(v3);
    }
  }
  return result;
}


// address=[0x132f480]
// Decompiled from int __thiscall CAIWatchTowers::NextUsedWatchTower(CAIWatchTowers *this, int a2)
int  CAIWatchTowers::NextUsedWatchTower(int) {
  
  CAIWatchTower *v2; // eax
  CAIWatchTower *v4; // eax
  int v6; // [esp+Ch] [ebp+8h]

  while ( a2 < CAIWatchTowers::Last(this) )
  {
    v2 = CAIWatchTowers::WatchTower(this, ++a2);
    if ( CAIWatchTower::Used(v2) )
      return a2;
  }
  v6 = CAIWatchTowers::First(this);
  while ( v6 < CAIWatchTowers::Last(this) )
  {
    v4 = CAIWatchTowers::WatchTower(this, ++v6);
    if ( CAIWatchTower::Used(v4) )
      return v6;
  }
  if ( !"No used watch tower found" )
    return 0;
  if ( BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 293, "!\"No used watch tower found\"") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x132f540]
// Decompiled from int __thiscall CAIWatchTowers::PushUndef(CAIWatchTowers *this)
int  CAIWatchTowers::PushUndef(void) {
  
  int v1; // ecx

  ++*((_DWORD *)this + 2);
  v1 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 3) = v1 + 1;
  return v1 + 1;
}


// address=[0x132f580]
// Decompiled from char __thiscall CAIWatchTowers::Remove(CAIWatchTowers *this, int a2)
void  CAIWatchTowers::Remove(int) {
  
  char result; // al

  result = CAIWatchTowers::ValidIndex(this, a2);
  if ( !result )
    return result;
  if ( *((int *)this + 2) <= 0 && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 318, "m_iCount > 0") == 1 )
    __debugbreak();
  CAIWatchTower::Done((CAIWatchTowers *)((char *)this + 8 * a2 + 16));
  result = (char)this;
  --*((_DWORD *)this + 2);
  return result;
}


// address=[0x132f5f0]
// Decompiled from bool __thiscall CAIWatchTowers::ValidIndex(CAIWatchTowers *this, unsigned int a2)
bool  CAIWatchTowers::ValidIndex(int)const {
  
  return a2 <= *((_DWORD *)this + 2);
}


// address=[0x132f620]
// Decompiled from void CAIWatchTowers::DefaultCallback()
static void __cdecl CAIWatchTowers::DefaultCallback(int,int) {
  
  ;
}


// address=[0x132f840]
// Decompiled from int __thiscall CAIWatchTowers::Count(CAIWatchTowers *this)
int  CAIWatchTowers::Count(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x132f860]
// Decompiled from int __thiscall CAIWatchTowers::First(CAIWatchTowers *this)
int  CAIWatchTowers::First(void)const {
  
  return 1;
}


// address=[0x132f880]
// Decompiled from int __thiscall CAIWatchTowers::Last(pairNode *this)
int  CAIWatchTowers::Last(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x132f980]
// Decompiled from bool __thiscall CAIWatchTowers::ValidUsedWatchTower(CAIWatchTowers *this, int a2)
bool  CAIWatchTowers::ValidUsedWatchTower(int)const {
  
  CAIWatchTower *v2; // eax
  char v4; // [esp+0h] [ebp-8h]

  v4 = 0;
  if ( !CAIWatchTowers::ValidIndex(this, a2) )
    return v4;
  v2 = CAIWatchTowers::WatchTower(this, a2);
  if ( CAIWatchTower::Used(v2) )
    return 1;
  return v4;
}


// address=[0x132fa10]
// Decompiled from char *__thiscall CAIWatchTowers::WatchTower(CAIWatchTowers *this, int a2)
class CAIWatchTowerEx &  CAIWatchTowers::WatchTower(int) {
  
  return (char *)this + 8 * a2 + 16;
}


// address=[0x132fa30]
// Decompiled from char *__thiscall CAIWatchTowers::WatchTower(CAIWatchTowers *this, int a2)
class CAIWatchTower const &  CAIWatchTowers::WatchTower(int)const {
  
  return (char *)this + 8 * a2 + 16;
}


