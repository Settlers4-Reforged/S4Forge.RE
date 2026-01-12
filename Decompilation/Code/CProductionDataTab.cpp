#include "CProductionDataTab.h"

// Definitions for class CProductionDataTab

// address=[0x2f3bba0]
// Decompiled from int __thiscall CProductionDataTab::GetMaxDistance(void *this, int a2, int a3)

int  CProductionDataTab::GetMaxDistance(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 8);
}


// address=[0x2f4c730]
// Decompiled from bool __thiscall CProductionDataTab::BuildingMustBeControl(void *this, int a2, int a3)

bool  CProductionDataTab::BuildingMustBeControl(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 56) != 0;
}


// address=[0x2f4c930]
// Decompiled from int __thiscall CProductionDataTab::GetInputTypePile(void *this, int a2, int a3, int a4)

enum PILE_TYPES  CProductionDataTab::GetInputTypePile(enum BUILDING_TYPES,int,int) {
  
  if ( a3 )
    return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a4) + 28);
  else
    return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a4) + 24);
}


// address=[0x2f4c980]
// Decompiled from int __thiscall CProductionDataTab::GetMaxBuildingInGroup(void *this, int a2, int a3)

int  CProductionDataTab::GetMaxBuildingInGroup(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 20);
}


// address=[0x2f4c9b0]
// Decompiled from int __thiscall CProductionDataTab::GetOutputTypePile(void *this, int a2, int a3)

enum PILE_TYPES  CProductionDataTab::GetOutputTypePile(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 32);
}


// address=[0x2f53a90]
// Decompiled from int __thiscall CProductionDataTab::GetNeededSettler(void *this, int a2)

enum SETTLER_TYPES  CProductionDataTab::GetNeededSettler(enum BUILDING_TYPES) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, 0) + 44);
}


// address=[0x2f53ac0]
// Decompiled from int __thiscall CProductionDataTab::GetTool(void *this, int a2)

enum PILE_TYPES  CProductionDataTab::GetTool(enum BUILDING_TYPES) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, 0) + 36);
}


// address=[0x2f54120]
// Decompiled from CProductionDataTab *__thiscall CProductionDataTab::CProductionDataTab(CProductionDataTab *this)

 CProductionDataTab::CProductionDataTab(void) {
  
  if ( CProductionDataTab::m_iNumberOfEntries )
    return this;
  j__memset(&CProductionDataTab::m_aBuildingTypeToTabIndexMap, 0, 0x67Cu);
  CProductionDataTab::m_iNumberOfEntries = 1;
  CProductionDataTab::PDT(this, 5, 1, 70, 20, 8000, 2, 0, 0, 22, 4, 112, 4, 22, 0, 1);
  CProductionDataTab::PDT(this, 5, 2, 20, 5, 10, 1, 0, 0, 0, 0, -1, 6, 50, 0, 1);
  CProductionDataTab::PDT(this, 5, 3, 70, 0, 8000, 3, 22, 0, 7, 28, -1, 12, 51, 0, 1);
  CProductionDataTab::PDT(this, 5, 4, 40, 0, 8000, 1, 0, 0, 32, 25, 96, 5, 20, 0, 1);
  CProductionDataTab::PDT(this, 5, 5, 200, 0, 8000, 2, 0, 0, 36, 0, -1, 10, 83, 0, 1);
  CProductionDataTab::PDT(this, 5, 6, 20, 0, 8000, 1, 0, 0, 11, 27, 0, 9, 42, 0, 1);
  CProductionDataTab::PDT(this, 2, 8, 140, 0, 8000, 2, 13, 0, 24, 4, -1, 18, 91, 0, 1);
  CProductionDataTab::PDT(this, 1, 8, 140, 0, 8000, 2, 26, 0, 24, 4, -1, 18, 91, 0, 1);
  CProductionDataTab::PDT(this, 0, 8, 140, 0, 8000, 2, 30, 0, 24, 4, -1, 18, 91, 0, 1);
  CProductionDataTab::PDT(this, 4, 8, 140, 0, 8000, 2, 39, 0, 24, 4, -1, 18, 91, 0, 1);
  CProductionDataTab::PDT(this, 5, 7, 20, 10, 8000, 1, 0, 0, 24, 8, 112, 11, 40, 0, 1);
  CProductionDataTab::PDT(this, 5, 9, 40, 0, 8000, 1, 16, 0, 12, 0, -1, 16, 111, 0, 1);
  CProductionDataTab::PDT(this, 5, 10, 140, 0, 8000, 5, 12, 36, 9, 0, -1, 17, 30, 0, 1);
  CProductionDataTab::PDT(this, 5, 11, 40, 0, 8000, 5, 0, 0, 16, 29, -3, 7, 25, 0, 1);
  CProductionDataTab::PDT(this, 2, 12, 40, 0, 8000, 3, 16, 36, 13, 0, -1, 8, 40, 0, 1);
  CProductionDataTab::PDT(this, 1, 12, 40, 0, 8000, 3, 16, 36, 26, 0, -1, 8, 40, 0, 1);
  CProductionDataTab::PDT(this, 0, 12, 40, 0, 8000, 3, 16, 36, 30, 0, -1, 8, 40, 0, 1);
  CProductionDataTab::PDT(this, 4, 12, 40, 0, 8000, 3, 16, 36, 30, 0, -1, 8, 40, 0, 1);
  CProductionDataTab::PDT(this, 5, 14, 80, 0, 8000, 1, 0, 0, 32, 25, 80, 14, 50, 0, 1);
  CProductionDataTab::PDT(this, 5, 15, 200, 0, 8000, 3, 0, 0, 21, 25, 32, 14, 59, 0, 1);
  CProductionDataTab::PDT(this, 5, 16, 200, 0, 8000, 5, 0, 0, 15, 25, 48, 14, 71, 0, 1);
  CProductionDataTab::PDT(this, 5, 17, 200, 0, 8000, 5, 0, 0, 10, 25, 16, 14, 77, 0, 1);
  CProductionDataTab::PDT(this, 5, 18, 20, 0, 8000, 5, 0, 0, 33, 25, 64, 14, 67, 0, 1);
  CProductionDataTab::PDT(this, 5, 19, 200, 0, 8000, 3, 15, 10, 14, 0, -1, 13, 43, 0, 1);
  CProductionDataTab::PDT(this, 5, 20, 60, 0, 8000, 3, 10, 21, 20, 0, -1, 13, 48, 0, 1);
  CProductionDataTab::PDT(this, 5, 21, 80, 0, 8000, 1, 10, 21, 0, 18, -1, 15, 50, 0, 1);
  CProductionDataTab::PDT(this, 5, 22, 200, 0, 8000, 3, 20, 10, 34, 18, -1, 15, 37, 0, 1);
  CProductionDataTab::PDT(this, 5, 24, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 25, 20, 0, 8000, 3, 22, 0, 10, 0, -1, 21, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 28, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 22, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 31, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 19, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 32, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 33, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 0, 35, 20, 0, 8000, 5, 0, 0, 37, 0, -2, 24, 17, 0, 1);
  CProductionDataTab::PDT(this, 2, 36, 70, 0, 8000, 5, 0, 0, 1, 0, -6, 27, 500, 0, 1);
  CProductionDataTab::PDT(this, 2, 37, 70, 0, 8000, 5, 1, 36, 35, 0, -1, 28, 500, 0, 1);
  CProductionDataTab::PDT(this, 1, 38, 70, 0, 8000, 3, 0, 0, 19, 0, -4, 25, 500, 0, 1);
  CProductionDataTab::PDT(this, 1, 39, 70, 0, 8000, 3, 19, 36, 23, 0, -1, 26, 500, 0, 1);
  CProductionDataTab::PDT(this, 4, 82, 70, 0, 8000, 5, 0, 0, 42, 0, -4, 64, 500, 0, 1);
  CProductionDataTab::PDT(this, 4, 81, 70, 0, 8000, 5, 42, 0, 41, 0, -1, 65, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 40, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 41, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 42, 20, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 43, 200, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 44, 200, 0, 8000, 1, 0, 0, 0, 0, -1, 0, 500, 0, 1);
  CProductionDataTab::PDT(this, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0);
  return this;
}


// address=[0x2f54910]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CProductionDataTab::~CProductionDataTab(CProductionDataTab *this)

 CProductionDataTab::~CProductionDataTab(void) {
  
  ;
}


// address=[0x2f54920]
// Decompiled from int __stdcall CProductionDataTab::GoodTypeProducedBy(int a1, int a2, int a3)

enum BUILDING_TYPES  CProductionDataTab::GoodTypeProducedBy(enum PILE_TYPES,int,int) {
  
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( !a1 )
    return 0;
  for ( i = 1; dword_46878FC[15 * i]; ++i )
  {
    if ( dword_4687918[15 * i] == a1 )
    {
      if ( v4 == a2 )
        return dword_46878FC[15 * i];
      ++v4;
    }
  }
  return 0;
}


// address=[0x2f549a0]
// Decompiled from int __stdcall CProductionDataTab::GetBuildingForResource(int a1, int a2)

enum BUILDING_TYPES  CProductionDataTab::GetBuildingForResource(int,int) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( a1 == -1 )
    return 0;
  for ( i = 1; dword_46878FC[15 * i]; ++i )
  {
    if ( dword_4687920[15 * i] == a1 )
      return dword_46878FC[15 * i];
  }
  return 0;
}


// address=[0x2f54a00]
// Decompiled from int __thiscall CProductionDataTab::GetResourceForBuilding(void *this, int a2, int a3)

int  CProductionDataTab::GetResourceForBuilding(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 40);
}


// address=[0x2f54a20]
// Decompiled from int __thiscall CProductionDataTab::SetProdTabValue(void *this, int a2, int a3, int a4)

void  CProductionDataTab::SetProdTabValue(enum BUILDING_TYPES,int,int) {
  
  int result; // eax
  int v5; // [esp+8h] [ebp-4h]

  result = CProductionDataTab::GetProdDataTabIndex(this, a2, 0);
  v5 = result;
  switch ( a3 )
  {
    case 0:
      result *= 60;
      dword_4687900[15 * v5] = a4;
      break;
    case 1:
      result = a4;
      dword_4687904[15 * v5] = a4;
      break;
    case 2:
      dword_4687908[15 * result] = a4;
      break;
    case 3:
      result *= 60;
      dword_468790C[15 * v5] = a4;
      break;
    case 4:
      result = a4;
      dword_4687928[15 * v5] = a4;
      break;
    case 5:
      dword_468792C[15 * result] = a4;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x2f5a2c0]
// Decompiled from int __thiscall CProductionDataTab::GetMaxWorkLoad(void *this, int a2, int a3)

int  CProductionDataTab::GetMaxWorkLoad(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 16);
}


// address=[0x2f5a2f0]
// Decompiled from int __thiscall CProductionDataTab::GetMinWorkLoad(void *this, int a2, int a3)

int  CProductionDataTab::GetMinWorkLoad(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 12);
}


// address=[0x2f5a320]
// Decompiled from int __thiscall CProductionDataTab::GetNeededFixTicks(void *this, int a2, int a3)

int  CProductionDataTab::GetNeededFixTicks(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 48);
}


// address=[0x2f5a350]
// Decompiled from int __thiscall CProductionDataTab::GetNeededVarTicks(void *this, int a2, int a3)

int  CProductionDataTab::GetNeededVarTicks(enum BUILDING_TYPES,int) {
  
  return *(_DWORD *)(CProductionDataTab::GetBuildData(this, a2, a3) + 52);
}


// address=[0x46878f8]
// [Decompilation failed for static struct CProductionDataTab::SProductionDataEntry * CProductionDataTab::m_aProductionDataEntry]

// address=[0x2f3bb70]
// Decompiled from int *__stdcall CProductionDataTab::GetBuildData(int a1, int a2)

struct CProductionDataTab::SProductionDataEntry const *  CProductionDataTab::GetBuildData(enum BUILDING_TYPES,int) {
  
  return &CProductionDataTab::m_aProductionDataEntry[15 * CProductionDataTab::m_aBuildingTypeToTabIndexMap[83 * a2 + a1]];
}


// address=[0x2f54ad0]
// Decompiled from int __stdcall CProductionDataTab::PDT(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15)

void  CProductionDataTab::PDT(int,enum BUILDING_TYPES,int,int,int,int,enum PILE_TYPES,enum PILE_TYPES,enum PILE_TYPES,enum PILE_TYPES,int,enum SETTLER_TYPES,int,int,int) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( a1 == 5 )
  {
    for ( i = 0; i < 5; ++i )
      CProductionDataTab::m_aBuildingTypeToTabIndexMap[83 * i + a2] = CProductionDataTab::m_iNumberOfEntries;
  }
  else
  {
    CProductionDataTab::m_aBuildingTypeToTabIndexMap[83 * a1 + a2] = CProductionDataTab::m_iNumberOfEntries;
  }
  CProductionDataTab::m_aProductionDataEntry[15 * CProductionDataTab::m_iNumberOfEntries] = a1;
  dword_46878FC[15 * CProductionDataTab::m_iNumberOfEntries] = a2;
  dword_4687900[15 * CProductionDataTab::m_iNumberOfEntries] = a3;
  dword_4687904[15 * CProductionDataTab::m_iNumberOfEntries] = a4;
  dword_4687908[15 * CProductionDataTab::m_iNumberOfEntries] = a5;
  dword_468790C[15 * CProductionDataTab::m_iNumberOfEntries] = a6;
  dword_4687910[15 * CProductionDataTab::m_iNumberOfEntries] = a7;
  dword_4687914[15 * CProductionDataTab::m_iNumberOfEntries] = a8;
  dword_4687918[15 * CProductionDataTab::m_iNumberOfEntries] = a9;
  dword_468791C[15 * CProductionDataTab::m_iNumberOfEntries] = a10;
  dword_4687920[15 * CProductionDataTab::m_iNumberOfEntries] = a11;
  dword_4687924[15 * CProductionDataTab::m_iNumberOfEntries] = a12;
  dword_4687928[15 * CProductionDataTab::m_iNumberOfEntries] = a13;
  dword_468792C[15 * CProductionDataTab::m_iNumberOfEntries] = a14;
  result = a15;
  dword_4687930[15 * CProductionDataTab::m_iNumberOfEntries++] = a15;
  return result;
}


// address=[0x2f55000]
// Decompiled from // MFC 3.1-14.0 32bit
int __stdcall CProductionDataTab::GetProdDataTabIndex(int a1, int a2)

int  CProductionDataTab::GetProdDataTabIndex(enum BUILDING_TYPES,int) {
  
  return 0;
}


// address=[0x4687270]
// [Decompilation failed for static int CProductionDataTab::m_iNumberOfEntries]

// address=[0x4687278]
// [Decompilation failed for static int (* CProductionDataTab::m_aBuildingTypeToTabIndexMap)[83]]

