#include "CAIChambers.h"

// Definitions for class CAIChambers

// address=[0x1314700]
// Decompiled from CAIChambers *__thiscall CAIChambers::CAIChambers(CAIChambers *this, int a2)

 CAIChambers::CAIChambers(int) {
  
  *(_DWORD *)this = IAIEnvironment::UnpackXFast(a2);
  *((_DWORD *)this + 1) = IAIEnvironment::UnpackYFast(a2);
  j__memset((char *)this + 8, 0, 0x140u);
  *((_DWORD *)this + 3242) = -1;
  return this;
}


// address=[0x1314770]
// Decompiled from CAIChambers *__thiscall CAIChambers::Push(CAIChambers *this, int a2, int a3)

void  CAIChambers::Push(int,int) {
  
  int v3; // eax
  CAIChambers *result; // eax
  int v5; // [esp-4h] [ebp-18h]
  CAIChambers *v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch]

  if ( !IAIEnvironment::WorldInWorldPackedXY(a2)
    && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 265, "g_pAIEnv->WorldInWorldPackedXY(_iXY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "AI\\AI_Military.cpp", 266, "_iValue > 0") == 1 )
    __debugbreak();
  v5 = *((_DWORD *)this + 1) - IAIEnvironment::UnpackYFast(a2);
  v3 = IAIEnvironment::UnpackXFast(a2);
  v8 = IAIEnvironment::GridDistance(*(_DWORD *)this - v3, v5);
  if ( v8 >= 312 )
    v7 = 38;
  else
    v7 = v8 >> 3;
  result = this;
  if ( *((int *)this + v7 + 2) >= 40 )
    return result;
  v6 = (CAIChambers *)*((_DWORD *)this + v7 + 2);
  *((_DWORD *)this + v7 + 2) = (char *)v6 + 1;
  result = v6;
  *((_DWORD *)this + 40 * v7 + (_DWORD)v6 + 82) = a3;
  return result;
}


// address=[0x1314880]
// Decompiled from int __thiscall CAIChambers::PushTaskForce(CAIChambers *this, struct CAITaskForce *a2)

void  CAIChambers::PushTaskForce(class CAITaskForce &) {
  
  int result; // eax
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = CAITaskForce::FirstEntity(a2);
  for ( i = result; i; i = result )
  {
    v5 = CAIEntityInfo::EntityId(i);
    v4 = IAIEnvironment::EntityPackedPosition(v5);
    CAIChambers::Push(this, v4, v5);
    result = CAIEntityInfo::Next(i);
  }
  return result;
}


// address=[0x13148e0]
// Decompiled from int __thiscall CAIChambers::PushTaskForceEx(CAIChambers *this, struct CAITaskForce *a2, int a3)

void  CAIChambers::PushTaskForceEx(class CAITaskForce &,int) {
  
  int result; // eax
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  result = CAITaskForce::FirstEntity(a2);
  for ( i = result; i; i = result )
  {
    v6 = CAIEntityInfo::EntityId(i);
    v5 = IAIEnvironment::EntityPackedPosition(v6);
    if ( (a3 & (1 << IAIEnvironment::EntityWarriorType(v6))) != 0 )
      CAIChambers::Push(this, v5, v6);
    result = CAIEntityInfo::Next(i);
  }
  return result;
}


// address=[0x1314960]
// Decompiled from int __thiscall CAIChambers::Next(CAIChambers *this)

int  CAIChambers::Next(void) {
  
  int v2; // eax
  int v3; // [esp+4h] [ebp-8h]

  v3 = *((_DWORD *)this + 3283) + 1;
  *((_DWORD *)this + 3283) = v3;
  if ( v3 < *((_DWORD *)this + *((_DWORD *)this + 3282) + 2) )
    return *((_DWORD *)this + 40 * *((_DWORD *)this + 3282) + *((_DWORD *)this + 3283) + 82);
  *((_DWORD *)this + 3283) = 0;
  while ( 1 )
  {
    v2 = *((_DWORD *)this + 3282) + 1;
    *((_DWORD *)this + 3282) = v2;
    if ( v2 >= 79 )
      break;
    if ( *((int *)this + *((_DWORD *)this + 3282) + 2) > 0 )
      return *((_DWORD *)this + 40 * *((_DWORD *)this + 3282) + 82);
  }
  return -1;
}


// address=[0x1321b60]
// Decompiled from void *__thiscall CAIChambers::Clear(CAIChambers *this)

void  CAIChambers::Clear(void) {
  
  return j__memset((char *)this + 8, 0, 0x140u);
}


// address=[0x1321b90]
// Decompiled from int __thiscall CAIChambers::Current(CAIChambers *this)

int  CAIChambers::Current(void) {
  
  return *((_DWORD *)this + 40 * *((_DWORD *)this + 3282) + *((_DWORD *)this + 3283) + 82);
}


// address=[0x1321bd0]
// Decompiled from int __thiscall CAIChambers::First(CAIChambers *this)

int  CAIChambers::First(void) {
  
  *((_DWORD *)this + 3282) = 0;
  *((_DWORD *)this + 3283) = -1;
  return CAIChambers::Next(this);
}


