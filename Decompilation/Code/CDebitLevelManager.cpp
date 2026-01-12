#include "CDebitLevelManager.h"

// Definitions for class CDebitLevelManager

// address=[0x2f58b30]
// Decompiled from CDebitLevelManager *__thiscall CDebitLevelManager::CDebitLevelManager(CDebitLevelManager *this, struct CSchedule *a2)

 CDebitLevelManager::CDebitLevelManager(class CSchedule *) {
  
  *((_DWORD *)this + 200) = 0;
  *((_DWORD *)this + 201) = a2;
  return this;
}


// address=[0x2f58b60]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CDebitLevelManager::~CDebitLevelManager(CDebitLevelManager *this)

 CDebitLevelManager::~CDebitLevelManager(void) {
  
  ;
}


// address=[0x2f58b70]
// Decompiled from char __thiscall CDebitLevelManager::AddDebitLevel(
        _DWORD *this,
        int a2,
        int a3,
        unsigned __int8 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10)

bool  CDebitLevelManager::AddDebitLevel(int,enum PILE_TYPES,bool,int,int,int,int,int,int) {
  
  int i; // [esp+0h] [ebp-Ch]
  int v12; // [esp+4h] [ebp-8h]

  v12 = this[200];
  for ( i = 0; i < this[200]; ++i )
  {
    if ( this[10 * i] == a2 && this[10 * i + 1] == a3 && LOBYTE(this[10 * i + 2]) == a4 && this[10 * i + 3] == a5 )
    {
      v12 = i;
      --this[200];
    }
  }
  this[10 * v12] = a2;
  this[10 * v12 + 1] = a3;
  LOBYTE(this[10 * v12 + 2]) = a4;
  this[10 * v12 + 3] = a5;
  this[10 * v12 + 4] = a6;
  this[10 * v12 + 5] = a7;
  this[10 * v12 + 6] = a8;
  this[10 * v12 + 7] = a9;
  this[10 * v12 + 8] = a10;
  ++this[200];
  if ( v12 >= 20
    && BBSupportDbgReport(2, "Source\\EcoAI_MaterialControl.cpp", 2189, "iDebitIndex < MAX_DEBIT_LEVEL") == 1 )
  {
    __debugbreak();
  }
  if ( (int)this[200] >= 20
    && BBSupportDbgReport(2, "Source\\EcoAI_MaterialControl.cpp", 2190, "m_iLastDebitLevelEntry < MAX_DEBIT_LEVEL") == 1 )
  {
    __debugbreak();
  }
  return 1;
}


// address=[0x2f58d00]
// Decompiled from int __thiscall CDebitLevelManager::GetDebitValue(CDebitLevelManager *this, int a2, int a3, unsigned __int8 a4, int a5)

int  CDebitLevelManager::GetDebitValue(int,enum PILE_TYPES,bool,int) {
  
  int v6; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v6 = 0;
  for ( i = 0; i < *((_DWORD *)this + 200); ++i )
  {
    if ( *((_DWORD *)this + 10 * i) == a2
      && *((_DWORD *)this + 10 * i + 1) == a3
      && *((unsigned __int8 *)this + 40 * i + 8) == a4 )
    {
      if ( a5 > *((_DWORD *)this + 10 * i + 5)
        && !CDebitLevelManager::DebitPreCondition(this, *((_DWORD *)this + 10 * i + 6)) )
      {
        v6 = *((_DWORD *)this + 10 * i + 4);
      }
      if ( a5 < *((_DWORD *)this + 10 * i + 7)
        && CDebitLevelManager::DebitException(this, *((const struct type_info **)this + 10 * i + 8)) == (void *)1 )
      {
        return 0;
      }
    }
  }
  return v6;
}


// address=[0x2f58df0]
// Decompiled from int __thiscall CDebitLevelManager::DebitPreCondition(CDebitLevelManager *this, int a2)

int  CDebitLevelManager::DebitPreCondition(int) {
  
  int result; // eax
  struct IAIEcoManager *EcoSector; // [esp+0h] [ebp-Ch]

  switch ( a2 )
  {
    case 0:
      result = 0;
      break;
    case 2:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 3) <= 1
        || CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 4) <= 1 )
      {
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      }
      result = 0;
      break;
    case 3:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 24) <= 0 )
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      result = 0;
      break;
    case 4:
      if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 19) <= 0 )
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      result = 0;
      break;
    case 5:
      if ( CSchedule::GetNumberOfBuildingType(*((_DWORD *)this + 201), 17) <= 0 )
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      result = 0;
      break;
    case 6:
      if ( CSchedule::GetNumberOfBuildingType(*((_DWORD *)this + 201), 15) <= 0 )
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      result = 0;
      break;
    case 7:
      if ( CSchedule::GetNumberOfBuildingType(*((_DWORD *)this + 201), 16) <= 0 )
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      result = 0;
      break;
    case 8:
      EcoSector = CSchedule::GetEcoSector(*((CSchedule **)this + 201));
      if ( (*(int (__thiscall **)(struct IAIEcoManager *, int))(*(_DWORD *)EcoSector + 152))(EcoSector, 45) <= 0 )
      {
        if ( CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 44) <= 0 )
          goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
    case 9:
      if ( *(_DWORD *)(*((_DWORD *)this + 201) + 24) == 2
        && CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 37) > 0 )
      {
        result = 0;
      }
      else if ( *(_DWORD *)(*((_DWORD *)this + 201) + 24)
             || CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 35) <= 0 )
      {
        if ( *(_DWORD *)(*((_DWORD *)this + 201) + 24) == 1
          && CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 39) > 0 )
        {
          result = 0;
        }
        else
        {
          if ( *(_DWORD *)(*((_DWORD *)this + 201) + 24) != 4
            || CSchedule::GetNumberOfBuildingTypeAtWork(*((_DWORD *)this + 201), 81) <= 0 )
          {
            goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
          }
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
      break;
    case 10:
      if ( CSchedule::GetNumberOfBuildingType(*((_DWORD *)this + 201), 44) <= 0
        || CSchedule::GetNumberOfBuildingType(*((_DWORD *)this + 201), 43) <= 0 )
      {
        goto CDebitLevelManager__DebitPreCondition___def_3358E0C;
      }
      result = 0;
      break;
    default:
CDebitLevelManager__DebitPreCondition___def_3358E0C:
      result = 1;
      break;
  }
  return result;
}


// address=[0x2f59050]
// Decompiled from void *__thiscall CDebitLevelManager::DebitException(std::_Ref_count_base *this, const struct type_info *a2)

int  CDebitLevelManager::DebitException(int) {
  
  return 0;
}


