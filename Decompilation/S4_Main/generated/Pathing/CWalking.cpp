#if FALSE
#include "CWalking.h"

// Definitions for class CWalking

// address=[0x14d8690]
// Decompiled from unsigned __int8 __thiscall CWalking::IsFree(CWalking *this, int a2)
bool  CWalking::IsFree(int a2) {
  
  if ( this->IsNotBlocked(this, a2) )
    return this->IsNotOccupied(this, a2);
  else
    return 0;
}


// address=[0x15f6110]
// Decompiled from CWalkingNormal *__cdecl CWalking::Create(int a1, int a2)
class CWalking * __cdecl CWalking::Create(enum T_WALKING_TYPE a1, int a2) {
  
  CWalkingNormal *result; // eax
  CWalkingNormal *v3; // [esp+14h] [ebp-30h]
  CWalkingShip *v4; // [esp+18h] [ebp-2Ch]
  CWalkingNormal *v5; // [esp+1Ch] [ebp-28h]
  CWalkingCatapult *v6; // [esp+20h] [ebp-24h]
  CWalkingNormal *v7; // [esp+24h] [ebp-20h]
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
// Decompiled from CWalkingBase *__cdecl CWalking::Create(struct std::istream *a1)
class CWalking * __cdecl CWalking::Create(std::istream & a1) {
  
  CWalkingBase::SData *Data; // eax
  CWalkingBase::SData *v3; // eax
  CWalkingBase::SData *v4; // eax
  CWalkingBase::SData *v5; // eax
  CWalkingBase::SData *v6; // eax
  CWalkingBase::SData *v7; // eax
  CWalkingBase::SData *v8; // eax
  CWalkingBase::SData *v9; // eax
  CWalkingBase::SData *v10; // eax
  CWalkingBase::SData *v11; // eax
  CWalkingBase::SData *v12; // eax
  CWalkingBase::SData *v13; // eax
  CWalkingBase::SData *v14; // eax
  CWalkingBase::SData *v15; // eax
  CWalkingBase::SData *v16; // eax
  CWalkingBase::SData *v17; // eax
  int pExceptionObject; // [esp+4h] [ebp-1Ch] BYREF
  int ControllID; // [esp+8h] [ebp-18h] BYREF
  int a2; // [esp+Ch] [ebp-14h] BYREF
  int v21; // [esp+10h] [ebp-10h] BYREF
  CWalkingBase *pNewWalking; // [esp+14h] [ebp-Ch]
  __int16 v23; // [esp+18h] [ebp-8h] BYREF
  __int16 v24; // [esp+1Ch] [ebp-4h] BYREF

  operator^<int>(a1, &a2);
  a2 = 929995208;
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
  operator^<int>(a1, &v21);
  pNewWalking = (CWalkingBase *)CWalking::Create(v23, v21 & 0xF);
  if ( !pNewWalking && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2476, "pNewWalking!=NULL") == 1 )
    __debugbreak();
  if ( !pNewWalking )
    return 0;
  Data = CWalkingBase::GetData(pNewWalking);
  Data->m_uFlags = v21;
  v3 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v3->m_iWalkState);
  v4 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v4->field_8);
  v5 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v5->m_iWalkToXY);
  v6 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v6->m_iWalkTo2XY);
  v7 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v7->m_iLeaderWalkToXY);
  v8 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v8->m_iIdleWalkToXY);
  v9 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v9->m_iWalkToIndex);
  v10 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v10->field_20);
  v11 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v11->m_iFineWaypoint);
  v12 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v12->m_iCoarseWaypointXY);
  v13 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v13->m_iEntityFlags);
  v14 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v14->field_34);
  v15 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v15->field_38);
  v16 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v16->field_3C);
  v17 = CWalkingBase::GetData(pNewWalking);
  operator^<int>(a1, &v17->field_40);
  ControllID = 0;
  operator^<int>(a1, &ControllID);
  if ( ControllID != 0x66ED0BD9 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 2501, "ControllID== 0x66ED0BD9") == 1 )
    __debugbreak();
  return pNewWalking;
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


#endif // Already implemented
