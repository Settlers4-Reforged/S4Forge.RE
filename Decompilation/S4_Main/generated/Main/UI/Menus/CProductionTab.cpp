#include "CProductionTab.h"

// Definitions for class CProductionTab

// address=[0x2f3bbd0]
// Decompiled from int __stdcall CProductionTab::GetProdBuildingByProdIndex(int a1, int a2, int a3)
enum BUILDING_TYPES  CProductionTab::GetProdBuildingByProdIndex(int,int,int) {
  
  return CProductionTab::m_aProductionEntry[8 * a1 + 3 + a2];
}


// address=[0x2f3bc00]
// Decompiled from int __stdcall CProductionTab::GetProdIdForGoodType(int a1, int a2)
int  CProductionTab::GetProdIdForGoodType(enum PILE_TYPES,int) {
  
  return CProductionTab::m_aRaceAndGoodToProdIdMap[43 * a2 + a1];
}


// address=[0x2f53d00]
// Decompiled from CProductionTab *__thiscall CProductionTab::CProductionTab(CProductionTab *this)
 CProductionTab::CProductionTab(void) {
  
  if ( CProductionTab::m_iNumberOfEntries )
    return this;
  memset(CProductionTab::m_aRaceAndGoodToProdIdMap, 0, 0x35Cu);
  CProductionTab::m_iNumberOfEntries = 1;
  CProductionTab::PT(this, "Holzproduktion", 5, 7, 1, 3, 0, 0, 0);
  CProductionTab::PT(this, "Steinproduktion", 5, 32, 4, 0, 0, 0, 0);
  CProductionTab::PT(this, "Waffenproduktion", 5, 34, 17, 20, 22, 0, 0);
  CProductionTab::PT(this, "Eisenproduktion", 5, 20, 17, 20, 0, 0, 0);
  CProductionTab::PT(this, "Goldproduktion", 5, 14, 16, 19, 0, 0, 0);
  CProductionTab::PT(this, "Fischproduktion", 5, 11, 6, 0, 0, 0, 0);
  CProductionTab::PT(this, "Brotproduktion", 5, 9, 11, 9, 10, 0, 0);
  CProductionTab::PT(this, "Ziegenproduktion", 2, 24, 11, 12, 8, 0, 0);
  CProductionTab::PT(this, "Schweineproduktion", 1, 24, 11, 12, 8, 0, 0);
  CProductionTab::PT(this, "Schafproduktion", 0, 24, 11, 12, 8, 0, 0);
  CProductionTab::PT(this, &unk_3AC387C, 4, 24, 11, 12, 8, 0, 0);
  CProductionTab::PT(this, "Alcoholproduktion", 2, 35, 36, 37, 0, 0, 0);
  CProductionTab::PT(this, "Alcoholproduktion", 0, 37, 35, 0, 0, 0, 0);
  CProductionTab::PT(this, "Alcoholproduktion", 1, 23, 38, 39, 0, 0, 0);
  CProductionTab::PT(this, "Alcoholproduktion", 4, 41, 82, 81, 0, 0, 0);
  CProductionTab::PT(this, "Munitionsproduktion", 2, 2, 18, 28, 0, 0, 0);
  CProductionTab::PT(this, "Munitionsproduktion", 0, 2, 4, 28, 0, 0, 0);
  CProductionTab::PT(this, "Munitionsproduktion", 1, 2, 28, 0, 0, 0, 0);
  CProductionTab::PT(this, "Munitionsproduktion", 4, 2, 1, 3, 17, 18, 28);
  CProductionTab::PT(this, "Baumstammproduktion", 5, 22, 1, 0, 0, 0, 0);
  CProductionTab::PT(this, "End", 0, 0, 0, 0, 0, 0, 0);
  return this;
}


// address=[0x2f53f80]
// Decompiled from void __thiscall CProductionTab::~CProductionTab(CProductionTab *this)
 CProductionTab::~CProductionTab(void) {
  
  ;
}


// address=[0x2f53f90]
// Decompiled from int __thiscall CProductionTab::GetAlternateProdForProdId(void *this, int a2, int a3)
int  CProductionTab::GetAlternateProdForProdId(enum PILE_TYPES,int) {
  
  int ProdIdForGoodType; // [esp+4h] [ebp-8h]

  ProdIdForGoodType = CProductionTab::GetProdIdForGoodType(this, a2, a3);
  if ( CProductionTab::m_aProductionEntry[8 * ProdIdForGoodType + 10] == a2
    && CProductionTab::m_aProductionEntry[8 * ProdIdForGoodType + 9] == a3 )
  {
    return ProdIdForGoodType + 1;
  }
  else
  {
    return 0;
  }
}


// address=[0x4687274]
// [Decompilation failed for static int CProductionTab::m_iNumberOfEntries]

// address=[0x4688c70]
// [Decompilation failed for static int (* CProductionTab::m_aRaceAndGoodToProdIdMap)[43]]

// address=[0x4688fd0]
// [Decompilation failed for static struct CProductionTab::SProductionEntry * CProductionTab::m_aProductionEntry]

// address=[0x2f53ff0]
// Decompiled from int __stdcall CProductionTab::PT(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
void  CProductionTab::PT(char const *,int,enum PILE_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES,enum BUILDING_TYPES) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( a2 == 5 )
  {
    for ( i = 0; i < 5; ++i )
      CProductionTab::m_aRaceAndGoodToProdIdMap[43 * i + a3] = CProductionTab::m_iNumberOfEntries;
  }
  else
  {
    CProductionTab::m_aRaceAndGoodToProdIdMap[43 * a2 + a3] = CProductionTab::m_iNumberOfEntries;
  }
  CProductionTab::m_aProductionEntry[8 * CProductionTab::m_iNumberOfEntries] = a1;
  dword_4688FD4[8 * CProductionTab::m_iNumberOfEntries] = a2;
  dword_4688FD8[8 * CProductionTab::m_iNumberOfEntries] = a3;
  dword_4688FDC[8 * CProductionTab::m_iNumberOfEntries] = a4;
  dword_4688FDC[8 * CProductionTab::m_iNumberOfEntries + 1] = a5;
  dword_4688FDC[8 * CProductionTab::m_iNumberOfEntries + 2] = a6;
  dword_4688FDC[8 * CProductionTab::m_iNumberOfEntries + 3] = a7;
  result = 16;
  dword_4688FDC[8 * CProductionTab::m_iNumberOfEntries++ + 4] = a8;
  return result;
}


