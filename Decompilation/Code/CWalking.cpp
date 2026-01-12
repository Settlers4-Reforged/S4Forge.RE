#include "CWalking.h"

// Definitions for class CWalking

// address=[0x14d8690]
// Decompiled from char __thiscall CWalking::IsFree(CWalking *this, int a2)

bool  CWalking::IsFree(int) {
  
  if ( (*(unsigned __int8 (__thiscall **)(CWalking *, int))(*(_DWORD *)this + 20))(this, a2) )
    return (*(int (__thiscall **)(CWalking *, int))(*(_DWORD *)this + 24))(this, a2);
  else
    return 0;
}


// address=[0x15f6110]
// Decompiled from CWalkingNormal *__cdecl CWalking::Create(int a1, int a2)

static class CWalking * __cdecl CWalking::Create(enum T_WALKING_TYPE,int) {
  
  CWalkingNormal *result; // eax
  CWalkingShip *v3; // [esp+14h] [ebp-30h]
  CWalkingShip *v4; // [esp+18h] [ebp-2Ch]
  CWalkingCatapult *v5; // [esp+1Ch] [ebp-28h]
  CWalkingCatapult *v6; // [esp+20h] [ebp-24h]
  CWalkingWorker *v7; // [esp+24h] [ebp-20h]
  CWalkingWorker *v8; // [esp+28h] [ebp-1Ch]
  CWalkingNormal *v9; // [esp+2Ch] [ebp-18h]
  CWalkingNormal *C; // [esp+30h] [ebp-14h]

  switch ( a1 )
  {
    case 0:
      C = (CWalkingNormal *)operator new(0xC0u);
      if ( C )
        v9 = CWalkingNormal::CWalkingNormal(C, a2);
      else
        v9 = 0;
      result = v9;
      break;
    case 1:
      v8 = (CWalkingWorker *)operator new(0xC0u);
      if ( v8 )
        v7 = CWalkingWorker::CWalkingWorker(v8, a2);
      else
        v7 = 0;
      result = v7;
      break;
    case 3:
      v6 = (CWalkingCatapult *)operator new(0xC0u);
      if ( v6 )
        v5 = CWalkingCatapult::CWalkingCatapult(v6);
      else
        v5 = 0;
      result = v5;
      break;
    case 4:
      v4 = (CWalkingShip *)operator new(0xC0u);
      if ( v4 )
        v3 = CWalkingShip::CWalkingShip(v4);
      else
        v3 = 0;
      result = v3;
      break;
    default:
      if ( BBSupportDbgReportF(1, "Pathing\\Walking.cpp", 2445, "CWalking::Create(): Invalid WalkingType %i!", a1) == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x15f62c0]
// Decompiled from CWalkingBase *__cdecl CWalking::Create(int a1)

static class CWalking * __cdecl CWalking::Create(std::istream &) {
  
  struct CWalkingBase::SData *Data; // eax
  struct CWalkingBase::SData *v3; // eax
  struct CWalkingBase::SData *v4; // eax
  struct CWalkingBase::SData *v5; // eax
  struct CWalkingBase::SData *v6; // eax
  struct CWalkingBase::SData *v7; // eax
  struct CWalkingBase::SData *v8; // eax
  struct CWalkingBase::SData *v9; // eax
  struct CWalkingBase::SData *v10; // eax
  struct CWalkingBase::SData *v11; // eax
  struct CWalkingBase::SData *v12; // eax
  struct CWalkingBase::SData *v13; // eax
  struct CWalkingBase::SData *v14; // eax
  struct CWalkingBase::SData *v15; // eax
  struct CWalkingBase::SData *v16; // eax
  struct CWalkingBase::SData *v17; // eax
  int pExceptionObject; // [esp+4h] [ebp-1Ch] BYREF
  int v19; // [esp+8h] [ebp-18h] BYREF
  int v20; // [esp+Ch] [ebp-14h] BYREF
  int v21; // [esp+10h] [ebp-10h] BYREF
  CWalkingBase *v22; // [esp+14h] [ebp-Ch]
  __int16 v23; // [esp+18h] [ebp-8h] BYREF
  __int16 v24; // [esp+1Ch] [ebp-4h] BYREF

  operator^<int>(a1, (int)&v20);
  v20 = 929995208;
  v24 = 1;
  operator^<short>(a1, &v24);
  if ( v24 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWalking");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v23 = -1;
  operator^<short>(a1, &v23);
  v21 = -1;
  operator^<int>(a1, (int)&v21);
  v22 = (CWalkingBase *)CWalking::Create(v23, v21 & 0xF);
  if ( !v22 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2476, "pNewWalking!=NULL") == 1 )
    __debugbreak();
  if ( !v22 )
    return 0;
  Data = CWalkingBase::GetData(v22);
  *((_DWORD *)Data + 11) = v21;
  v3 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v3 + 4);
  v4 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v4 + 8);
  v5 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v5 + 12);
  v6 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v6 + 16);
  v7 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v7 + 20);
  v8 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v8 + 24);
  v9 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v9 + 28);
  v10 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v10 + 32);
  v11 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v11 + 36);
  v12 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v12 + 40);
  v13 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v13 + 48);
  v14 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v14 + 52);
  v15 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v15 + 56);
  v16 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v16 + 60);
  v17 = CWalkingBase::GetData(v22);
  operator^<int>(a1, (int)v17 + 64);
  v19 = 0;
  operator^<int>(a1, (int)&v19);
  if ( v19 != 1726811097 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2501, "ControllID== 0x66ED0BD9") == 1 )
    __debugbreak();
  return v22;
}


// address=[0x15faec0]
// Decompiled from CWalking *__thiscall CWalking::CWalking(CWalking *this)

 CWalking::CWalking(void) {
  
  *(_DWORD *)this = CWalking::_vftable_;
  return this;
}


// address=[0x15faf50]
// Decompiled from CWalking *__thiscall CWalking::~CWalking(CWalking *this)

 CWalking::~CWalking(void) {
  
  CWalking *result; // eax

  result = this;
  *(_DWORD *)this = CWalking::_vftable_;
  return result;
}


