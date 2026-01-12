#include "CEcoSectorAI.h"

// Definitions for class CEcoSectorAI

// address=[0x2f34860]
// Decompiled from IAIEcoSectorAI *__thiscall CEcoSectorAI::CEcoSectorAI(IAIEcoSectorAI *this)
 CEcoSectorAI::CEcoSectorAI(void) {
  
  IAIEcoSectorAI::IAIEcoSectorAI(this);
  *(_DWORD *)this = CEcoSectorAI::_vftable_;
  *((_DWORD *)this + 8) = 0;
  return this;
}


// address=[0x2f34890]
// Decompiled from CEcoSectorAI *__thiscall CEcoSectorAI::CEcoSectorAI(  CEcoSectorAI *this,  struct IAIEcoManager *a2,  struct IAISectorAI *a3,  int a4,  int a5)
 CEcoSectorAI::CEcoSectorAI(class IAIEcoManager *,class IAISectorAI *,int,int) {
  
  CSchedule *v6; // [esp+14h] [ebp-30h]
  CSchedule *v7; // [esp+18h] [ebp-2Ch]
  CProductionDataTab *v8; // [esp+1Ch] [ebp-28h]
  CProductionDataTab *v9; // [esp+20h] [ebp-24h]
  CProductionTab *v10; // [esp+24h] [ebp-20h]
  CProductionTab *v11; // [esp+28h] [ebp-1Ch]
  CReserveDatabase *v12; // [esp+2Ch] [ebp-18h]
  CReserveDatabase *C; // [esp+30h] [ebp-14h]

  IAIEcoSectorAI::IAIEcoSectorAI(this);
  *(_DWORD *)this = CEcoSectorAI::_vftable_;
  *((_DWORD *)this + 8) = 0;
  C = (CReserveDatabase *)operator new(0x1Cu);
  if ( C )
    v12 = CReserveDatabase::CReserveDatabase(C);
  else
    v12 = 0;
  *((_DWORD *)this + 3) = v12;
  v11 = (CProductionTab *)operator new(1u);
  if ( v11 )
    v10 = CProductionTab::CProductionTab(v11);
  else
    v10 = 0;
  *((_DWORD *)this + 4) = v10;
  v9 = (CProductionDataTab *)operator new(1u);
  if ( v9 )
    v8 = CProductionDataTab::CProductionDataTab(v9);
  else
    v8 = 0;
  *((_DWORD *)this + 5) = v8;
  *((_DWORD *)this + 6) = a2;
  *((_DWORD *)this + 7) = a3;
  v7 = (CSchedule *)operator new(0x7Cu);
  if ( v7 )
    v6 = CSchedule::CSchedule(v7, this, a4, a5);
  else
    v6 = 0;
  *((_DWORD *)this + 1) = v6;
  CSchedule::Settings(*((CSchedule **)this + 1));
  return this;
}


// address=[0x2f34a20]
// Decompiled from CReserveDatabase *__thiscall CEcoSectorAI::~CEcoSectorAI(CReserveDatabase **this)
 CEcoSectorAI::~CEcoSectorAI(void) {
  
  CReserveDatabase *result; // eax

  *this = (CReserveDatabase *)CEcoSectorAI::_vftable_;
  if ( this[3] )
    CReserveDatabase::`scalar deleting destructor'(this[3], 1u);
  if ( this[4] )
    CProductionTab::`scalar deleting destructor'(this[4], 1u);
  if ( this[5] )
    CProductionDataTab::`scalar deleting destructor'(this[5], 1u);
  result = this[1];
  if ( result )
    return (CReserveDatabase *)CSchedule::`scalar deleting destructor'(this[1], 1u);
  return result;
}


// address=[0x2f34af0]
// Decompiled from CEcoSectorAI *__thiscall CEcoSectorAI::Release(CEcoSectorAI *this)
void  CEcoSectorAI::Release(void) {
  
  CEcoSectorAI *result; // eax

  result = this;
  if ( this )
    return (CEcoSectorAI *)CEcoSectorAI::`scalar deleting destructor'(this, 1u);
  return result;
}


// address=[0x2f34b30]
// Decompiled from int CEcoSectorAI::ReadConfigFile()
void  CEcoSectorAI::ReadConfigFile(void) {
  
  int result; // eax
  int i; // [esp+10h] [ebp-8h]

  for ( i = 0; i < 83; ++i )
    result = i + 1;
  return result;
}


// address=[0x2f34bb0]
// Decompiled from bool __thiscall CEcoSectorAI::Execute(CSchedule **this)
void  CEcoSectorAI::Execute(void) {
  
  return CSchedule::trigger(this[1]);
}


// address=[0x2f34bd0]
// Decompiled from int __thiscall CEcoSectorAI::PutUpBuilding(CSchedule **this, int a2, int a3, int a4, int a5)
enum T_AI_BUILD_RESULT  CEcoSectorAI::PutUpBuilding(int,int,int,int) {
  
  int v6; // [esp+10h] [ebp-1Ch]
  struct IScheduleEntry *v8; // [esp+18h] [ebp-14h]
  CMainProblemSolveEvent *C; // [esp+1Ch] [ebp-10h]

  v6 = CReserveDatabase::PackPosition(this[3], a3, a4);
  C = (CMainProblemSolveEvent *)operator new(0x70u);
  if ( C )
    v8 = CMainProblemSolveEvent::CMainProblemSolveEvent(C, -1, 9, a2, v6, 0, 0);
  else
    v8 = 0;
  CSchedule::NewSchedEntry(this[1], v8);
  return 1;
}


// address=[0x2f34c90]
// Decompiled from int __thiscall CEcoSectorAI::Flags(CEcoSectorAI *this)
int  CEcoSectorAI::Flags(void) {
  
  return *((_DWORD *)this + 8);
}


// address=[0x2f34cb0]
// Decompiled from void __thiscall CEcoSectorAI::SetFlags(CPaneContainer *this, int a2)
void  CEcoSectorAI::SetFlags(int) {
  
  *((_DWORD *)this + 8) = a2;
}


