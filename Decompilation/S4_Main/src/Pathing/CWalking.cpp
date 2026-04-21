#include "CWalking.h"

#include "CWalkingNormal.h"
#include "CWalkingShip.h"
#include "CWalkingCatapult.h"
#include "CWalkingWorker.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"

#include "iostream"
#include "Defines/Walking.h"

// Definitions for class CWalking

// address=[0x14d8690]
// Decompiled from unsigned __int8 __thiscall CWalking::IsFree(CWalking *this, int a2)
bool CWalking::IsFree(int a2) {
  if(this->IsNotBlocked(a2))
    return this->IsNotOccupied(a2);
  else
    return 0;
}


// address=[0x15f6110]
// Decompiled from CWalkingNormal *__cdecl CWalking::Create(int a1, int a2)
CWalking * __cdecl CWalking::Create(enum T_WALKING_TYPE a1, int a2) {
  switch(a1) {
    case WALKING_TYPE_NORMAL:
      return new CWalkingNormal(a2);
    case WALKING_TYPE_WORKER:
      return new CWalkingWorker(a2);
    case WALKING_TYPE_CATAPULT:
      return new CWalkingCatapult();
    case WALKING_TYPE_SHIP:
      return new CWalkingShip();
    default:
      BB_REPORTF("CWalking::Create(): Invalid WalkingType %i!", a1)
      return nullptr;
  }
}


// address=[0x15f62c0]
// Decompiled from CWalkingBase *__cdecl CWalking::Create(int a1)
class CWalking * __cdecl CWalking::Create(std::istream &_rStream) {
  int     pExceptionObject; // [esp+4h] [ebp-1Ch] BYREF
  int     ControllID; // [esp+8h] [ebp-18h] BYREF
  int     a2; // [esp+Ch] [ebp-14h] BYREF
  int     v21; // [esp+10h] [ebp-10h] BYREF
  __int16 v23; // [esp+18h] [ebp-8h] BYREF

  //TODO: Huh?
  _rStream >> a2;
  a2 = 929995208;
  __int16 v24 = 1;
  _rStream >> v24;
  if(v24 != 1) {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWalking");
    throw new CS4InvalidMapException();
  }
  v23 = -1;
  _rStream >> v23;
  v21 = -1;
  _rStream >> v21;

  auto *pNewWalking = dynamic_cast<CWalkingBase *>(CWalking::Create(static_cast<T_WALKING_TYPE>(v23), v21 & 0xF));
  BB_ASSERT(pNewWalking != NULL)
  if(!pNewWalking)
    return 0;

  pNewWalking->GetData().m_uFlags = v21;
  _rStream >> pNewWalking->GetData().m_iWalkState;
  _rStream >> pNewWalking->GetData().field_8;
  _rStream >> pNewWalking->GetData().m_iWalkToXY;
  _rStream >> pNewWalking->GetData().m_iWalkTo2XY;
  _rStream >> pNewWalking->GetData().m_iLeaderWalkToXY;
  _rStream >> pNewWalking->GetData().m_iIdleWalkToXY;
  _rStream >> pNewWalking->GetData().m_iWalkToIndex;
  _rStream >> pNewWalking->GetData().field_20;
  _rStream >> pNewWalking->GetData().m_iFineWaypointXY;
  _rStream >> pNewWalking->GetData().m_iCoarseWaypointXY;
  _rStream >> pNewWalking->GetData().m_iEntityFlags;
  _rStream >> pNewWalking->GetData().field_34;
  _rStream >> pNewWalking->GetData().field_38;
  _rStream >> pNewWalking->GetData().field_3C;
  _rStream >> pNewWalking->GetData().field_40;
  ControllID = 0;
  _rStream >> ControllID;
  BB_ASSERT(ControllID == 0x66ED0BD9)

  return pNewWalking;
}


// address=[0x15faec0]
// Decompiled from CWalking *__thiscall CWalking::CWalking(CWalking *this)
CWalking::CWalking(void) = default;


// address=[0x15faf50]
// Decompiled from CWalking *__thiscall CWalking::~CWalking(CWalking *this)
CWalking::~CWalking(void) = default;


