#include "all_headers.h"

// Definitions for class CAIWatchTower

// address=[0x132eec0]
// Decompiled from void __thiscall CAIWatchTower::Init(CAIWatchTower *this, int a2, int a3, int a4)
void  CAIWatchTower::Init(int,int,int) {
  
  if ( !IAIEnvironment::WorldInWorld(a2, a3)
    && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 196, "g_pAIEnv->WorldInWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)this = IAIEnvironment::PackXYFast(a2, a3);
  CAIWatchTower::SetAllianceIdAndClearValue(this, a4);
}


// address=[0x132ef30]
// Decompiled from CAIWatchTower *__thiscall CAIWatchTower::Done(CAIWatchTower *this)
void  CAIWatchTower::Done(void) {
  
  CAIWatchTower *result; // eax

  result = this;
  *(_DWORD *)this = -1;
  return result;
}


// address=[0x132f820]
// Decompiled from int __thiscall CAIWatchTower::AllianceId(CAIWatchTower *this)
int  CAIWatchTower::AllianceId(void)const {
  
  return HIBYTE(*((_DWORD *)this + 1));
}


// address=[0x132f8a0]
// Decompiled from int __thiscall CAIWatchTower::PackedXY(CAIWatchTower *this)
int  CAIWatchTower::PackedXY(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x132f940]
// Decompiled from bool __thiscall CAIWatchTower::Used(CAIWatchTower *this)
bool  CAIWatchTower::Used(void)const {
  
  return *(_DWORD *)this != -1;
}


// address=[0x132f9f0]
// Decompiled from unsigned int __thiscall CAIWatchTower::Value(CAIWatchTower *this)
int  CAIWatchTower::Value(void)const {
  
  return ((unsigned int)&dword_F29144[220078] + 3) & *((_DWORD *)this + 1);
}


// address=[0x132ef50]
// Decompiled from unsigned int __thiscall CAIWatchTower::SetValue(CAIWatchTower *this, int a2)
void  CAIWatchTower::SetValue(int) {
  
  unsigned int result; // eax

  if ( (a2 & 0xFF000000) != 0 && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 166, "(_iValue & 0xFF000000) == 0") == 1 )
    __debugbreak();
  result = a2 | *((_DWORD *)this + 1) & 0xFF000000;
  *((_DWORD *)this + 1) = result;
  return result;
}


// address=[0x132f8c0]
// Decompiled from CAIWatchTower *__thiscall CAIWatchTower::SetAllianceIdAndClearValue(CAIWatchTower *this, int a2)
void  CAIWatchTower::SetAllianceIdAndClearValue(int) {
  
  CAIWatchTower *result; // eax

  if ( (a2 & 0xFFFFFF00) != 0
    && BBSupportDbgReport(2, "AI\\AI_WatchTower.cpp", 184, "(_iAllianceId & 0xFFFFFF00) == 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 1) = a2 << 24;
  return result;
}


