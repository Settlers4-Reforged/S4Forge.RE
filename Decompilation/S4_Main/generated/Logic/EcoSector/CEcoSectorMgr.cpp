#include "CEcoSectorMgr.h"

// Definitions for class CEcoSectorMgr

// address=[0x130a3d0]
// Decompiled from int __thiscall CEcoSectorMgr::GetEcoSectorPtr(CEcoSectorMgr *this, int a2)
class CEcoSector *  CEcoSectorMgr::GetEcoSectorPtr(int a2) {
  
  if ( a2 <= 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         247,
         (const char *)&dword_366FF60[1]) == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 0x4000
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         248,
         "_iEcoSectorId < MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > *((_DWORD *)this + 3)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         249,
         "_iEcoSectorId <= m_sData.m_iMaxLastUsedId") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 5);
}


// address=[0x130ec00]
// Decompiled from int __thiscall CEcoSectorMgr::GetEcoSectorPtrEx(CEcoSectorMgr *this, unsigned int a2)
class CEcoSector *  CEcoSectorMgr::GetEcoSectorPtrEx(int a2) {
  
  if ( a2 >= 0x4000 )
    return 0;
  else
    return *((_DWORD *)this + a2 + 5);
}


// address=[0x130ec30]
// Decompiled from struct CEcoSector *__thiscall CEcoSectorMgr::GetEcoSectorPtrEx(CEcoSectorMgr *this, int a2, int a3)
class CEcoSector *  CEcoSectorMgr::GetEcoSectorPtrEx(int a2, int a3) {
  
  struct CEcoSector *EcoSectorPtr; // [esp+8h] [ebp-4h]

  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtrEx(this, a2);
  if ( EcoSectorPtr && CEcoSector::GetUniqueId(EcoSectorPtr) == a3 )
    return EcoSectorPtr;
  else
    return 0;
}


// address=[0x130f120]
// Decompiled from int __thiscall CEcoSectorMgr::LastUsedEcoSectorId(CEcoSectorMgr *this)
int  CEcoSectorMgr::LastUsedEcoSectorId(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1326e00]
// Decompiled from int __thiscall CEcoSectorMgr::EntryPtr(CEcoSectorMgr *this, int a2)
class CEcoSector *  CEcoSectorMgr::EntryPtr(int a2) {
  
  if ( a2 <= 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         294,
         (const char *)&dword_366FF60[1]) == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 0x4000
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         295,
         "_iEcoSectorId < MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > *((_DWORD *)this + 3)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         296,
         "_iEcoSectorId <= m_sData.m_iMaxLastUsedId") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + a2 + 5);
}


// address=[0x1346370]
// Decompiled from int __thiscall CEcoSectorMgr::operator[](_DWORD *this, int a2)
class CEcoSector &  CEcoSectorMgr::operator[](int a2) {
  
  if ( a2 <= 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         230,
         (const char *)&dword_366FF60[1]) == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 0x4000
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         231,
         "_iEcoSectorId < MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > this[3]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         232,
         "_iEcoSectorId <= m_sData.m_iMaxLastUsedId") == 1 )
  {
    __debugbreak();
  }
  if ( !this[a2 + 5]
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\EcoSectorMgr.h",
         233,
         "m_sData.m_vEcoSectors[_iEcoSectorId] != 0") == 1 )
  {
    __debugbreak();
  }
  return this[a2 + 5];
}


// address=[0x1441b90]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::CEcoSectorMgr(CEcoSectorMgr *this)
 CEcoSectorMgr::CEcoSectorMgr(void) {
  
  int i; // [esp+0h] [ebp-8h]

  _vec_ctor(
    (char *)this + 65596,
    0x10u,
    9u,
    std::vector<unsigned short>::vector<unsigned short>,
    std::vector<unsigned short>::~vector<unsigned short>);
  memset(this, 0, 0x1003Cu);
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0x10000000;
  for ( i = 0; i < 9; ++i )
    std::vector<unsigned short>::clear();
  return this;
}


// address=[0x1441c30]
// Decompiled from void __thiscall CEcoSectorMgr::~CEcoSectorMgr(CEcoSectorMgr *this)
 CEcoSectorMgr::~CEcoSectorMgr(void) {
  
  CEcoSectorMgr::Clear(this);
  `eh vector destructor iterator'((char *)this + 65596, 0x10u, 9u, std::vector<unsigned short>::~vector<unsigned short>);
}


// address=[0x1441c90]
// Decompiled from int __thiscall CEcoSectorMgr::OrderDiggerAndBuilderAtStartUp(CEcoSectorMgr *this)
void  CEcoSectorMgr::OrderDiggerAndBuilderAtStartUp(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-10h]
  CEcoSector *v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 2);
  for ( i = 1; ; ++i )
  {
    result = i;
    if ( i > v2 )
      break;
    v3 = (CEcoSector *)*((_DWORD *)this + i + 5);
    if ( v3 )
      CEcoSector::OrderDiggerAndBuilderAtStartUp(v3);
  }
  return result;
}


// address=[0x1441ce0]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::Clear(CEcoSectorMgr *this)
void  CEcoSectorMgr::Clear(void) {
  
  CEcoSectorMgr *result; // eax
  CEcoSector *v2; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]
  int j; // [esp+10h] [ebp-4h]

  for ( i = 1; i < 0x4000; ++i )
  {
    if ( *((_DWORD *)this + i + 5) )
    {
      v2 = (CEcoSector *)*((_DWORD *)this + i + 5);
      if ( v2 )
        delete v2;
      *((_DWORD *)this + i + 5) = 0;
    }
  }
  memset(this, 0, 0x1003Cu);
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  result = this;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0x10000000;
  for ( j = 0; j < 9; ++j )
    result = (CEcoSectorMgr *)std::vector<unsigned short>::clear();
  return result;
}


// address=[0x1441dc0]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::Update(CEcoSectorMgr *this)
void  CEcoSectorMgr::Update(void) {
  
  CEcoSectorMgr *result; // eax

  ++*((_DWORD *)this + 16389);
  result = this;
  if ( *((int *)this + 16389) < 32 )
    return result;
  result = (CEcoSectorMgr *)CEcoSectorMgr::UpdateStrikeSettlers((char *)this);
  *((_DWORD *)this + 16389) = 0;
  return result;
}


// address=[0x1441e10]
// Decompiled from int __thiscall CEcoSectorMgr::GetNrStrikingCarriers(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::GetNrStrikingCarriers(int a2) {
  
  return std::vector<unsigned short>::size((char *)this + 16 * a2 + 65596);
}


// address=[0x1441e40]
// Decompiled from int __thiscall CEcoSectorMgr::GetNrOfStrikingCarriersInEcoSector(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::GetNrOfStrikingCarriersInEcoSector(int a2) {
  
  unsigned __int16 *v3; // eax
  int v4; // eax
  int NrStrikingCarriers; // [esp+0h] [ebp-1Ch]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+18h] [ebp-4h]

  v7 = *((_DWORD *)this + a2 + 5);
  if ( !v7 )
    return 0;
  v8 = 0;
  v6 = CEcoSector::Owner(v7);
  NrStrikingCarriers = CEcoSectorMgr::GetNrStrikingCarriers(this, v6);
  for ( i = 0; i < NrStrikingCarriers; ++i )
  {
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 16 * v6 + 65596, i);
    if ( !CSettlerMgr::GetSettlerPtr(*v3) && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 229, "pSettler") == 1 )
      __debugbreak();
    v4 = IEntity::WorldIdx();
    if ( CWorldManager::EcoSectorId(v4) == a2 )
      ++v8;
  }
  return v8;
}


// address=[0x1441f20]
// Decompiled from int __thiscall CEcoSectorMgr::GetNrOfInitialFreeBeds(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::GetNrOfInitialFreeBeds(int a2) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "Logic\\EcoSectorMgr.cpp",
         1602,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 1 || a2 > 8 )
    return 0;
  else
    return *((_DWORD *)this + a2 + 16390);
}


// address=[0x1441f80]
// Decompiled from int __thiscall CEcoSectorMgr::GetNrOfCurrentTotalBeds(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::GetNrOfCurrentTotalBeds(int a2) {
  
  int NumberOfBuildings; // esi
  int v3; // esi
  int v4; // edi
  int v5; // esi
  int v6; // edi
  int v9; // [esp+10h] [ebp-4h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "Logic\\EcoSectorMgr.cpp",
         1621,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 1 || a2 > 8 )
    return 0;
  v9 = CPlayerManager::Race(a2);
  NumberOfBuildings = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a2, 40, 1u);
  v3 = *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v9, 40) + 496) * NumberOfBuildings;
  v4 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a2, 41, 1u);
  v5 = *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v9, 41) + 496) * v4 + v3;
  v6 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, a2, 42, 1u);
  return *((_DWORD *)this + a2 + 16390) + *(_DWORD *)(CBuildingInfoMgr::GetBuildingInfo(v9, 42) + 496) * v6 + v5;
}


// address=[0x1442080]
// Decompiled from unsigned int __thiscall CEcoSectorMgr::RemoveCarrierFromStrikeSettlers(CEcoSectorMgr *this, int a2, int a3)
void  CEcoSectorMgr::RemoveCarrierFromStrikeSettlers(int a2, int a3) {
  
  unsigned int result; // eax
  int v4; // eax
  _WORD *v5; // esi
  unsigned int i; // [esp+4h] [ebp-8h]

  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 16 * a2 + 65596);
    if ( i >= result )
      break;
    if ( *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 16 * a2 + 65596, i) == a3 )
    {
      v4 = std::vector<unsigned short>::size((char *)this + 16 * a2 + 65596);
      v5 = (_WORD *)std::vector<unsigned short>::operator[]((char *)this + 16 * a2 + 65596, v4 - 1);
      *(_WORD *)std::vector<unsigned short>::operator[]((char *)this + 16 * a2 + 65596, i) = *v5;
      return std::vector<unsigned short>::pop_back((char *)this + 16 * a2 + 65596);
    }
  }
  return result;
}


// address=[0x1442150]
// Decompiled from int __thiscall CEcoSectorMgr::CalculateInitialFreeBeds(CEcoSectorMgr *this)
void  CEcoSectorMgr::CalculateInitialFreeBeds(void) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-4h]

  for ( i = 1; ; ++i )
  {
    result = CPlayerManager::LastPlayerId();
    if ( i > result )
      break;
    *((_DWORD *)this + i + 16390) = 10
                                  * ((CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, i, 1) + 9)
                                   / 10)
                                  + 10;
  }
  return result;
}


// address=[0x14421b0]
// Decompiled from int __thiscall CEcoSectorMgr::UpdateStrikeSettlers(CEcoSectorMgr *this)
void  CEcoSectorMgr::UpdateStrikeSettlers(void) {
  
  int result; // eax
  void *v2; // eax
  int v3; // esi
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char v9[24]; // [esp+8h] [ebp-90h] BYREF
  char v10[24]; // [esp+20h] [ebp-78h] BYREF
  int v11; // [esp+38h] [ebp-60h]
  CEntityEvent *v12; // [esp+3Ch] [ebp-5Ch]
  CEntityEvent *v13; // [esp+40h] [ebp-58h]
  CEntityEvent *v14; // [esp+44h] [ebp-54h]
  CEntityEvent *v15; // [esp+48h] [ebp-50h]
  int v16; // [esp+4Ch] [ebp-4Ch]
  int NrOfCurrentTotalBeds; // [esp+50h] [ebp-48h]
  int NumberOfSettlers; // [esp+54h] [ebp-44h]
  int SettlerOffer; // [esp+58h] [ebp-40h]
  int v20; // [esp+5Ch] [ebp-3Ch]
  int v21; // [esp+60h] [ebp-38h]
  CPlayerGameData *v22; // [esp+64h] [ebp-34h]
  int k; // [esp+68h] [ebp-30h]
  __int16 v24; // [esp+6Eh] [ebp-2Ah] BYREF
  int j; // [esp+70h] [ebp-28h]
  CEcoSectorMgr *v26; // [esp+74h] [ebp-24h]
  unsigned __int16 *EcoSectorPtr; // [esp+78h] [ebp-20h]
  unsigned __int8 *SettlerPtr; // [esp+7Ch] [ebp-1Ch]
  int v29; // [esp+80h] [ebp-18h]
  int i; // [esp+84h] [ebp-14h]
  char v31; // [esp+8Bh] [ebp-Dh]
  int v32; // [esp+94h] [ebp-4h]

  v26 = this;
  for ( i = 1; ; ++i )
  {
    result = CPlayerManager::LastPlayerId();
    if ( i > result )
      break;
    v2 = (void *)CPlayerManager::PlayerInfo(i);
    v11 = CPlayerInfo::Race(v2);
    NumberOfSettlers = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, i, 1);
    NrOfCurrentTotalBeds = CEcoSectorMgr::GetNrOfCurrentTotalBeds(v26, i);
    v3 = NumberOfSettlers - NrOfCurrentTotalBeds;
    v29 = v3 - std::vector<unsigned short>::size((char *)v26 + 16 * i + 65596);
    if ( v29 >= 0 )
    {
      if ( v29 > 0 )
      {
        v22 = CPlayerManager::PlayerGameData(i);
        v31 = 1;
        while ( v31 && v29 )
        {
          v31 = 0;
          CPlayerGameData::ResetIterator(v22);
          for ( j = CPlayerGameData::GetNextEcoSectorId(v22); j && v29; j = CPlayerGameData::GetNextEcoSectorId(v22) )
          {
            EcoSectorPtr = (unsigned __int16 *)CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, j);
            if ( !EcoSectorPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1560, "pEcoSector") == 1 )
              __debugbreak();
            if ( EcoSectorPtr )
            {
              v7 = CEcoSector::Owner(EcoSectorPtr);
              if ( v7 == i )
              {
                SettlerOffer = CEcoSector::GetSettlerOffer((CEcoSector *)EcoSectorPtr, 1);
                if ( SettlerOffer )
                {
                  SettlerPtr = CSettlerMgr::GetSettlerPtr(SettlerOffer);
                  if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1575, "pSettler") == 1 )
                    __debugbreak();
                  v13 = CEntityEvent::CEntityEvent((CEntityEvent *)v9, 0x1Bu, 0, 1, 0, 0);
                  v12 = v13;
                  v32 = 1;
                  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(
                    SettlerPtr,
                    v13);
                  v32 = -1;
                  CEntityEvent::~CEntityEvent(v9);
                  v8 = IEntity::ID();
                  CEcoSector::GetSettlerOutOfOffer((CEcoSector *)EcoSectorPtr, v8);
                  v24 = IEntity::ID();
                  std::vector<unsigned short>::push_back(&v24);
                  --v29;
                  v31 = 1;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v29 = -v29;
      v4 = std::vector<unsigned short>::size((char *)v26 + 16 * i + 65596);
      if ( v4 >= v29 )
        v21 = v29;
      else
        v21 = std::vector<unsigned short>::size((char *)v26 + 16 * i + 65596);
      v16 = v21;
      for ( k = 0; k < v16 && v29; ++k )
      {
        v5 = std::vector<unsigned short>::size((char *)v26 + 16 * i + 65596);
        v20 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)v26 + 16 * i + 65596, v5 - 1);
        SettlerPtr = CSettlerMgr::GetSettlerPtr(v20);
        if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1524, "pSettler") == 1 )
          __debugbreak();
        if ( SettlerPtr )
        {
          v15 = CEntityEvent::CEntityEvent((CEntityEvent *)v10, 0x1Bu, 0, 0, 0, 0);
          v14 = v15;
          v32 = 0;
          (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v15);
          v32 = -1;
          CEntityEvent::~CEntityEvent(v10);
          v6 = IEntity::WorldIdx();
          j = CWorldManager::EcoSectorId(v6);
          EcoSectorPtr = (unsigned __int16 *)CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, j);
          if ( !EcoSectorPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1532, "pEcoSector!= NULL") == 1 )
            __debugbreak();
          if ( EcoSectorPtr )
            CEcoSector::SetSettlerOffer(EcoSectorPtr, 1, v20);
          std::vector<unsigned short>::pop_back((char *)v26 + 16 * i + 65596);
          --v29;
        }
      }
    }
  }
  return result;
}


// address=[0x14425c0]
// Decompiled from int __thiscall CEcoSectorMgr::NotifyCreateEcoSector(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::NotifyCreateEcoSector(int a2) {
  
  if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
    BBSupportTracePrintF(0, "CEcoSectorMgr -NotifyCreateEcoSector owner %u", a2);
  return CEcoSectorMgr::NewEcoSector(this, a2);
}


// address=[0x1442610]
// Decompiled from void __thiscall CEcoSectorMgr::NotifyChangeEcoSector(_DWORD *this, int a2, int a3, int a4)
void  CEcoSectorMgr::NotifyChangeEcoSector(int a2, int a3, int a4) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CPile *v7; // eax
  int v8; // eax
  int v9; // eax
  CPile *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  CPile *v16; // eax
  CEcoSector *v17; // eax
  CEcoSector *v18; // eax
  int v19; // eax
  _DWORD *v20; // eax
  CEcoSector *v21; // eax
  unsigned __int16 *v22; // eax
  int v23; // [esp-8h] [ebp-50h]
  int v24; // [esp-8h] [ebp-50h]
  int v25; // [esp-8h] [ebp-50h]
  _WORD *v27; // [esp+10h] [ebp-38h]
  int v28; // [esp+14h] [ebp-34h]
  int v29; // [esp+1Ch] [ebp-2Ch]
  int v30; // [esp+20h] [ebp-28h]
  int v31; // [esp+24h] [ebp-24h]
  int v32; // [esp+28h] [ebp-20h]
  int v33; // [esp+2Ch] [ebp-1Ch]
  CEcoSector *v34; // [esp+30h] [ebp-18h]
  int v35; // [esp+34h] [ebp-14h]
  int v36; // [esp+38h] [ebp-10h]
  int v37; // [esp+3Ch] [ebp-Ch]
  unsigned __int16 *v38; // [esp+40h] [ebp-8h]
  unsigned __int16 *v39; // [esp+44h] [ebp-4h]

  if ( !a3
    && !a4
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 722, "! (_iOldEcoSectorId==0 && _iNewEcoSectorId == 0)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 == a4 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 723, "_iOldEcoSectorId != _iNewEcoSectorId") == 1 )
    __debugbreak();
  if ( a3 )
  {
    v4 = CEcoSectorMgr::operator[](a3);
    v32 = CEcoSector::Owner(v4);
  }
  else
  {
    v32 = 0;
  }
  if ( a4 )
  {
    v5 = CEcoSectorMgr::operator[](a4);
    v31 = CEcoSector::Owner(v5);
  }
  else
  {
    v31 = 0;
  }
  (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 12, a2, a3, a4);
  if ( a4 )
  {
    if ( a3 )
    {
      v11 = CEcoSectorMgr::operator[](a4);
      CEcoSector::IncSize(v11);
      v12 = CEcoSectorMgr::operator[](a3);
      CEcoSector::DecSize(v12);
      if ( v32 != v31 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 857, "iOldOwner == iNewOwner") == 1 )
        __debugbreak();
      v13 = CEcoSectorMgr::operator[](a3);
      v14 = CEcoSector::Owner(v13);
      v15 = CEcoSectorMgr::operator[](a4);
      if ( v14 == CEcoSector::Owner(v15) )
      {
        if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
          BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector same owner");
        v29 = CWorldManager::PileId(a2);
        if ( v29 )
        {
          v16 = (CPile *)CPileMgr::operator[](v29);
          CPile::NotifyChangeEcoSector(v16, a3, a4);
        }
        if ( *this )
        {
          if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
            BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector merge sector");
        }
        else
        {
          if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
            BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector split sector");
          v37 = CWorldManager::SettlerId(a2);
          if ( v37 )
          {
            if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
              BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector find Settler %u split es - update es", v37);
            v38 = (unsigned __int16 *)CSettlerMgr::operator[](v37);
            if ( IEntity::OwnerId((unsigned __int8 *)v38) == v32 && !IEntity::WarriorType() )
            {
              v28 = CSettler::Role(v38);
              if ( (*(int (__thiscall **)(int))(*(_DWORD *)v28 + 72))(v28) != 18 )
              {
                v23 = IEntity::Type(v38);
                v17 = (CEcoSector *)CEcoSectorMgr::operator[](a4);
                CEcoSector::ChangeNrOfSettler(v17, v23, 1);
                v24 = IEntity::Type(v38);
                v18 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
                CEcoSector::ChangeNrOfSettler(v18, v24, -1);
              }
              if ( CSettler::GetNextSettlerType(v38) )
              {
                if ( !*(_WORD *)(CEcoSectorMgr::operator[](a3) + 34)
                  && BBSupportDbgReport(
                       2,
                       "Logic\\EcoSectorMgr.cpp",
                       913,
                       "g_cESMgr[_iOldEcoSectorId].m_uOrderedCarrier > 0") == 1 )
                {
                  __debugbreak();
                }
                v27 = (_WORD *)(CEcoSectorMgr::operator[](a3) + 34);
                --*v27;
                v19 = CEcoSectorMgr::operator[](a4);
                ++*(_WORD *)(v19 + 34);
              }
              v20 = (_DWORD *)CSettlerMgr::operator[](v37);
              if ( IEntity::FlagBits(v20, Offered) )
              {
                v21 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
                CEcoSector::GetSettlerOutOfOffer(v21, v37);
                v25 = IEntity::Type(v38);
                v22 = (unsigned __int16 *)CEcoSectorMgr::operator[](a4);
                CEcoSector::SetSettlerOffer(v22, v25, v37);
              }
            }
          }
        }
      }
    }
    else
    {
      v9 = CEcoSectorMgr::operator[](a4);
      CEcoSector::IncSize(v9);
      v33 = CWorldManager::PileId(a2);
      if ( v33 )
      {
        if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
          BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector find pile %u on newES!=0 - occupy it", v33);
        v10 = (CPile *)CPileMgr::operator[](v33);
        CPile::Occupied(v10, a4);
      }
    }
  }
  else
  {
    v6 = CEcoSectorMgr::operator[](a3);
    CEcoSector::DecSize(v6);
    v35 = CWorldManager::PileId(a2);
    if ( v35 )
    {
      if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
        BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector find pile %u on newES=0 - set it free", v35);
      v7 = (CPile *)CPileMgr::operator[](v35);
      CPile::SetFree(v7, a3);
    }
    v36 = CWorldManager::SettlerId(a2);
    if ( v36 )
    {
      if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
        BBSupportTracePrintF(0, "CEcoSectorMgr - NotifyChangeEcoSector find settler %u on newES=0 - check free", v36);
      v39 = (unsigned __int16 *)CSettlerMgr::operator[](v36);
      if ( !IEntity::WarriorType() )
      {
        v34 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
        if ( IEntity::FlagBits(v39, Offered) )
          CEcoSector::GetSettlerOutOfOffer(v34, v36);
        v30 = CSettler::Role(v39);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v30 + 72))(v30) != 18 )
        {
          v8 = IEntity::Type(v39);
          CEcoSector::ChangeNrOfSettler(v34, v8, -1);
        }
        if ( CSettler::GetNextSettlerType(v39) )
        {
          CEcoSector::ResetCarrierNextSettlerTypeAndDecrementOrder(v34, v36);
          if ( CSettler::GetNextSettlerType(v39) )
          {
            if ( BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 818, "rSettler.GetNextSettlerType() == 0") == 1 )
              __debugbreak();
          }
        }
        IEntity::SetFlagBits(v39, (EntityFlag)0x80u);
      }
    }
  }
}


// address=[0x1442c00]
// Decompiled from void __thiscall CEcoSectorMgr::NotifyDeleteEcoSector(CEcoSectorMgr *this, int a2)
void  CEcoSectorMgr::NotifyDeleteEcoSector(int a2) {
  
  CEcoSectorMgr::DeleteEcoSector(this, a2);
}


// address=[0x1442c20]
// Decompiled from unsigned int __thiscall CEcoSectorMgr::SeparateEconomy(CEcoSectorMgr *this, unsigned int a2, unsigned int a3)
void  CEcoSectorMgr::SeparateEconomy(int a2, int a3) {
  
  int v3; // eax
  CEcoSector *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int NrOfSoldierOrder; // eax
  unsigned __int8 *v9; // eax
  unsigned int result; // eax
  unsigned __int8 *v11; // eax
  int v12; // [esp-8h] [ebp-30h]
  int UniqueId; // [esp-4h] [ebp-2Ch]
  int NrOfWeaponOrder; // [esp-4h] [ebp-2Ch]
  int NrOfToolOrder; // [esp-4h] [ebp-2Ch]
  int v16; // [esp+4h] [ebp-24h]
  pairNode *v17; // [esp+8h] [ebp-20h]
  int FirstBuildingId; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+14h] [ebp-14h]
  CEcoSector *v21; // [esp+18h] [ebp-10h]
  CBuildingSiteRole *v22; // [esp+1Ch] [ebp-Ch]
  CEcoSector *v23; // [esp+20h] [ebp-8h]
  int j; // [esp+24h] [ebp-4h]
  unsigned int k; // [esp+24h] [ebp-4h]
  unsigned int m; // [esp+24h] [ebp-4h]

  BBSupportTracePrintF(0, "Ecosector Split: %u separates from %u", a3, a2);
  if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
    BBSupportTracePrintF(0, "CEcoSectorMgr - SeparateEconomy actES %u  newES %u", a2, a3);
  v23 = (CEcoSector *)CEcoSectorMgr::operator[](a2);
  v17 = (pairNode *)CEcoSectorMgr::operator[](a3);
  UniqueId = CEcoSector::GetUniqueId(v17);
  v12 = CAIEvent::Pack(a2, a3);
  v3 = CEcoSector::Owner(v23);
  (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 16, v3, v12, UniqueId);
  v4 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
  if ( CEcoSector::BuildingSitesWithPrio(v4)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1104, "g_cESMgr[_iNewEcoSectorId].BuildingSitesWithPrio() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( CEcoSector::BuildingSitesWithPrio(v23) )
  {
    CEcoSector::ResetBuildingSitesWithPrio(v23);
    for ( i = 1; i < 83; ++i )
    {
      v5 = CEcoSector::Owner(v23);
      FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v5, i);
      while ( FirstBuildingId )
      {
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
        if ( BuildingPtr )
        {
          if ( IEntity::FlagBits(BuildingPtr, (EntityFlag)&dword_F29144[220079]) )
          {
            v16 = CBuilding::EcoSectorId(BuildingPtr);
            if ( v16 == a2 || v16 == a3 )
            {
              v22 = (CBuildingSiteRole *)CBuilding::Role(BuildingPtr);
              v21 = (CEcoSector *)CEcoSectorMgr::operator[](v16);
              if ( CBuildingSiteRole::HavePriority(v22) )
                CEcoSector::ChangeBuildingSitesWithPrio(v21, 1);
              if ( CBuildingSiteRole::HaveDiggerPriority(v22) )
              {
                v6 = CBuildingSiteRole::MaxNeededDigger(v22);
                CEcoSector::ChangePrioDigger(v21, 1, v6);
              }
              if ( CBuildingSiteRole::HaveBuilderPriority(v22) )
              {
                v7 = CBuildingSiteRole::MaxNeededBuilder(v22);
                CEcoSector::ChangePrioBuilder(v21, 1, v7);
              }
              if ( CBuildingSiteRole::HaveBoardPriority(v22) )
                CEcoSector::ChangePrioBoards(v21, 1);
              if ( CBuildingSiteRole::HaveStonePriority(v22) )
                CEcoSector::ChangePrioStone(v21, 1);
            }
          }
          FirstBuildingId = IAnimatedEntity::Next(BuildingPtr);
        }
        else
        {
          FirstBuildingId = 0;
        }
      }
    }
  }
  for ( j = 0; j < 10; ++j )
  {
    NrOfSoldierOrder = CEcoSector::GetNrOfSoldierOrder(v23, j);
    CEcoSector::TakeSoldierOrder(v17, g_vSoldierProductionMap[2 * j], NrOfSoldierOrder);
  }
  for ( k = 0; k < std::vector<unsigned char>::size((char *)v23 + 916); ++k )
  {
    NrOfWeaponOrder = CEcoSector::GetNrOfWeaponOrder(v23, k);
    v9 = (unsigned __int8 *)std::vector<unsigned char>::operator[](k);
    CEcoSector::TakeWeaponOrder(v17, *v9, NrOfWeaponOrder);
  }
  for ( m = 0; ; ++m )
  {
    result = std::vector<unsigned char>::size((char *)v23 + 880);
    if ( m >= result )
      break;
    NrOfToolOrder = CEcoSector::GetNrOfToolOrder(v23, m);
    v11 = (unsigned __int8 *)std::vector<unsigned char>::operator[](m);
    CEcoSector::TakeToolOrder(v17, *v11, NrOfToolOrder);
  }
  return result;
}


// address=[0x1442f60]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::NotifyEcoSectorMerge(CEcoSectorMgr *this, int a2, int a3)
void  CEcoSectorMgr::NotifyEcoSectorMerge(int a2, int a3) {
  
  CEcoSectorMgr *result; // eax

  CEcoSectorMgr::DBG_CheckEcoSectors(this);
  result = this;
  *(_DWORD *)this = 1;
  return result;
}


// address=[0x1442f80]
// Decompiled from _DWORD *__thiscall CEcoSectorMgr::ConnectEconomy(CEcoSectorMgr *this, int a2, int a3)
void  CEcoSectorMgr::ConnectEconomy(int a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  unsigned int v10; // eax
  _DWORD *v11; // eax
  unsigned __int8 *v12; // eax
  _DWORD *result; // eax
  _DWORD *v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp-4h] [ebp-4Ch]
  int v19; // [esp-4h] [ebp-4Ch]
  int v20; // [esp-4h] [ebp-4Ch]
  int v21; // [esp-4h] [ebp-4Ch]
  int v22; // [esp-4h] [ebp-4Ch]
  int v23; // [esp-4h] [ebp-4Ch]
  int v24; // [esp+0h] [ebp-48h]
  int v25; // [esp+4h] [ebp-44h]
  int v27; // [esp+14h] [ebp-34h]
  int n; // [esp+1Ch] [ebp-2Ch]
  _DWORD *k; // [esp+20h] [ebp-28h]
  unsigned __int8 *v30; // [esp+24h] [ebp-24h]
  unsigned __int16 *v31; // [esp+28h] [ebp-20h]
  int ii; // [esp+2Ch] [ebp-1Ch]
  unsigned int j; // [esp+30h] [ebp-18h]
  unsigned int m; // [esp+30h] [ebp-18h]
  int NrOfSoldierOrder; // [esp+34h] [ebp-14h] BYREF
  int NrOfWeaponOrder; // [esp+38h] [ebp-10h] BYREF
  CEcoSector *v37; // [esp+3Ch] [ebp-Ch]
  unsigned __int16 *v38; // [esp+40h] [ebp-8h]
  int i; // [esp+44h] [ebp-4h]

  BBSupportTracePrintF(0, "Ecosector: Merge %u to %u", a3, a2);
  *(_DWORD *)this = 0;
  v38 = (unsigned __int16 *)CEcoSectorMgr::operator[](a2);
  v37 = (CEcoSector *)CEcoSectorMgr::operator[](a3);
  if ( debug && DEBUG_FLAGS[dword_3F0EC00] )
    BBSupportTracePrintF(0, "CEcoSectorMgr - ConnectEconomy actES %u  delES %u", a2, a3);
  v3 = CEcoSector::Owner(v38);
  (*(void (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 15, v3, a2, a3);
  v4 = CEcoSector::BuildingSitesWithPrio(v37);
  CEcoSector::ChangeBuildingSitesWithPrio((CEcoSector *)v38, v4);
  v18 = CEcoSector::NeededPrioDigger(v37);
  v5 = CEcoSector::NrOfBuildingsWithDiggerPrio(v37);
  CEcoSector::ChangePrioDigger((CEcoSector *)v38, v5, v18);
  v19 = CEcoSector::NeededPrioBuilder(v37);
  v6 = CEcoSector::NrOfBuildingsWithBuilderPrio(v37);
  CEcoSector::ChangePrioBuilder((CEcoSector *)v38, v6, v19);
  v7 = CEcoSector::PrioBoards(v37);
  CEcoSector::ChangePrioBoards((CEcoSector *)v38, v7);
  v8 = CEcoSector::PrioStone(v37);
  CEcoSector::ChangePrioStone((CEcoSector *)v38, v8);
  for ( i = 0; i < 10; ++i )
  {
    NrOfSoldierOrder = CEcoSector::GetNrOfSoldierOrder((CEcoSector *)v38, i);
    NrOfWeaponOrder = CEcoSector::GetNrOfSoldierOrder(v37, i);
    v9 = (_DWORD *)BB::Max<int>(&NrOfSoldierOrder, &NrOfWeaponOrder);
    if ( *v9 == NrOfWeaponOrder && NrOfWeaponOrder != NrOfSoldierOrder )
    {
      if ( i == 9 )
        v27 = 15;
      else
        v27 = i;
      CEcoSector::TakeSoldierOrder((CEcoSector *)v38, g_vSoldierProductionMap[2 * v27], *v9 - NrOfSoldierOrder);
    }
  }
  for ( i = 0; ; ++i )
  {
    v10 = std::vector<unsigned char>::size(v38 + 458);
    if ( i >= v10 )
      break;
    NrOfSoldierOrder = CEcoSector::GetNrOfWeaponOrder((CEcoSector *)v38, i);
    NrOfWeaponOrder = CEcoSector::GetNrOfWeaponOrder(v37, i);
    v11 = (_DWORD *)BB::Max<int>(&NrOfSoldierOrder, &NrOfWeaponOrder);
    if ( *v11 == NrOfWeaponOrder && NrOfWeaponOrder != NrOfSoldierOrder )
    {
      v20 = *v11 - NrOfSoldierOrder;
      v12 = (unsigned __int8 *)std::vector<unsigned char>::operator[](i);
      CEcoSector::TakeWeaponOrder((CEcoSector *)v38, *v12, v20);
    }
  }
  for ( i = 0; ; ++i )
  {
    result = (_DWORD *)std::vector<unsigned char>::size(v38 + 440);
    if ( i >= (unsigned int)result )
      break;
    NrOfSoldierOrder = CEcoSector::GetNrOfToolOrder((CEcoSector *)v38, i);
    NrOfWeaponOrder = CEcoSector::GetNrOfToolOrder(v37, i);
    v14 = (_DWORD *)BB::Max<int>(&NrOfSoldierOrder, &NrOfWeaponOrder);
    if ( *v14 == NrOfWeaponOrder )
    {
      v21 = *v14 - NrOfSoldierOrder;
      v15 = (unsigned __int8 *)std::vector<unsigned char>::operator[](i);
      CEcoSector::TakeToolOrder((CEcoSector *)v38, *v15, v21);
    }
  }
  for ( j = 0; j < 0x43; ++j )
  {
    result = (_DWORD *)CEcoSector::GetSettlerOffer(v37, j);
    for ( k = result; k; k = (_DWORD *)v25 )
    {
      v31 = (unsigned __int16 *)CSettlerMgr::operator[](k);
      v25 = IAnimatedEntity::Next(v31);
      IEntity::ClearFlagBits(v31, Offered);
      v22 = IEntity::ID();
      v16 = IEntity::Type(v31);
      result = CEcoSector::SetSettlerOffer(v38, v16, v22);
    }
  }
  for ( m = 0; m < 0x2B; ++m )
  {
    result = (_DWORD *)CEcoSector::GetGoodOffer(v37, m);
    for ( n = (int)result; n; n = v24 )
    {
      v30 = CPileMgr::operator[](n);
      v24 = IAnimatedEntity::Next(v30);
      IEntity::ClearFlagBits(v30, Offered);
      v23 = IEntity::ID();
      v17 = IEntity::Type((unsigned __int16 *)v30);
      result = CEcoSector::SetGoodOffer(v38, v17, v23);
    }
  }
  for ( ii = 0; ii < 67; ++ii )
  {
    v38[ii + 18] += *((_WORD *)v37 + ii + 18);
    result = (_DWORD *)(ii + 1);
  }
  return result;
}


// address=[0x1443370]
// Decompiled from _DWORD *__thiscall CEcoSectorMgr::OfferSettler(CEcoSectorMgr *this, int a2, int a3, int a4)
void  CEcoSectorMgr::OfferSettler(int a2, int a3, int a4) {
  
  _DWORD *result; // eax
  unsigned __int16 *EcoSectorPtr; // [esp+4h] [ebp-4h]

  EcoSectorPtr = (unsigned __int16 *)CEcoSectorMgr::GetEcoSectorPtr(this, a2);
  if ( EcoSectorPtr )
    return CEcoSector::SetSettlerOffer(EcoSectorPtr, a3, a4);
  result = (_DWORD *)BBSupportDbgReportF(
                       1,
                       "Logic\\EcoSectorMgr.cpp",
                       646,
                       "CEcoSectorMgr::OfferSettler(): Invalid eco-sector id %i!",
                       a2);
  if ( result == (_DWORD *)1 )
    __debugbreak();
  return result;
}


// address=[0x14433d0]
// Decompiled from _DWORD *__thiscall CEcoSectorMgr::OfferGood(CEcoSectorMgr *this, int a2, int a3, int a4)
void  CEcoSectorMgr::OfferGood(int a2, int a3, int a4) {
  
  _DWORD *result; // eax
  unsigned __int16 *EcoSectorPtr; // [esp+4h] [ebp-4h]

  EcoSectorPtr = (unsigned __int16 *)CEcoSectorMgr::GetEcoSectorPtr(this, a2);
  if ( EcoSectorPtr )
    return CEcoSector::SetGoodOffer(EcoSectorPtr, a3, a4);
  result = (_DWORD *)BBSupportDbgReportF(
                       1,
                       "Logic\\EcoSectorMgr.cpp",
                       668,
                       "CEcoSectorMgr::OfferGood(): Invalid eco-sector id %i!",
                       a2);
  if ( result == (_DWORD *)1 )
    __debugbreak();
  return result;
}


// address=[0x1443430]
// Decompiled from void __thiscall CEcoSectorMgr::InitTransport(CEcoSectorMgr *this)
void  CEcoSectorMgr::InitTransport(void) {
  
  CEcoSector *v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  sub_1445200(dword_3F0EBFC);
  for ( i = 1; i < 0x4000; ++i )
  {
    v2 = (CEcoSector *)*((_DWORD *)this + i + 5);
    if ( v2 )
      CEcoSector::InitTransport(v2);
  }
}


// address=[0x1443490]
// Decompiled from int __thiscall CEcoSectorMgr::RecruiteSpecialist(CEcoSectorMgr *this)
void  CEcoSectorMgr::RecruiteSpecialist(void) {
  
  int result; // eax
  CEcoSector *v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 1; i < 0x4000; ++i )
  {
    v3 = (CEcoSector *)*((_DWORD *)this + i + 5);
    if ( v3 )
      CEcoSector::RecruiteSpecialist(v3);
    result = i + 1;
  }
  return result;
}


// address=[0x14434e0]
// Decompiled from int __thiscall CEcoSectorMgr::RecruiteWorker(CEcoSectorMgr *this)
void  CEcoSectorMgr::RecruiteWorker(void) {
  
  int result; // eax
  CEcoSector *v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 1; i < 0x4000; ++i )
  {
    v3 = (CEcoSector *)*((_DWORD *)this + i + 5);
    if ( v3 )
      CEcoSector::RecruiteWorker(v3);
    result = i + 1;
  }
  return result;
}


// address=[0x1443530]
// Decompiled from unsigned int __cdecl CEcoSectorMgr::FillGoodAmount(void **a1, unsigned __int8 a2, char a3)
void __cdecl CEcoSectorMgr::FillGoodAmount(class CInfoExchange * a1, bool a2, bool a3) {
  
  unsigned int result; // eax
  CEvn_Event *v4; // [esp+4h] [ebp-50h]
  int LocalPlayerId; // [esp+10h] [ebp-44h]
  unsigned int v6; // [esp+14h] [ebp-40h]
  int LocalPlayerEcoSectorPtrAtCenter; // [esp+18h] [ebp-3Ch]
  int j; // [esp+1Ch] [ebp-38h]
  int i; // [esp+20h] [ebp-34h]
  int k; // [esp+24h] [ebp-30h]
  unsigned int v11; // [esp+28h] [ebp-2Ch]
  CEvn_Event v12; // [esp+2Ch] [ebp-28h] BYREF
  int v13; // [esp+50h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1676, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  result = j____RTDynamicCast(
             a1,
             0,
             &CInfoExchange__RTTI_Type_Descriptor_,
             &CGoodsStatisticInfo__RTTI_Type_Descriptor_,
             0);
  v11 = result;
  if ( !result )
  {
    result = BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1680, "pMenu != 0");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !v11 )
    return result;
  *(_BYTE *)(v11 + 8) = a3;
  if ( a3 )
  {
    LocalPlayerEcoSectorPtrAtCenter = CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter();
    if ( LocalPlayerEcoSectorPtrAtCenter )
    {
      for ( i = 1; i < 43; ++i )
      {
        *(_DWORD *)(v11 + 8 * i + 4) = i;
        *(_DWORD *)(v11 + 8 * i + 8) = CEcoSector::GetNumberOfGoods(LocalPlayerEcoSectorPtrAtCenter, i, 2);
      }
    }
    else
    {
      for ( j = 1; j < 43; ++j )
      {
        *(_DWORD *)(v11 + 8 * j + 4) = j;
        *(_DWORD *)(v11 + 8 * j + 8) = 0;
      }
    }
  }
  else
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    for ( k = 1; k < 43; ++k )
    {
      *(_DWORD *)(v11 + 8 * k + 4) = k;
      *(_DWORD *)(v11 + 8 * k + 8) = CStatistic::GetGood((CStatistic *)&g_cStatistic, LocalPlayerId, k);
    }
  }
  *(_DWORD *)(v11 + 4) = 32;
  result = a2;
  if ( a2 )
    v6 = 604;
  else
    v6 = 602;
  if ( !g_pEvnEngine )
  {
    result = BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1725, "g_pEvnEngine != NULL");
    if ( result == 1 )
      __debugbreak();
  }
  if ( !g_pEvnEngine )
    return result;
  v4 = CEvn_Event::CEvn_Event(&v12, v6, 0, v11, 0);
  v13 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v4);
  v13 = -1;
  return (unsigned int)CEvn_Event::~CEvn_Event(&v12);
}


// address=[0x1443770]
// Decompiled from _DWORD *__cdecl CEcoSectorMgr::FillTransportPrio(struct CInfoExchange *a1, bool a2)
void __cdecl CEcoSectorMgr::FillTransportPrio(class CInfoExchange * a1, bool a2, bool a3) {
  
  unsigned int v3; // [esp+8h] [ebp-34h]
  char *LocalPlayerEcoSectorPtrAtCenter; // [esp+Ch] [ebp-30h]
  CEvn_Event v5; // [esp+14h] [ebp-28h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1937, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  CPlayerManager::GetLocalPlayerId();
  *((_DWORD *)a1 + 1) = 33;
  LocalPlayerEcoSectorPtrAtCenter = (char *)CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter();
  if ( LocalPlayerEcoSectorPtrAtCenter )
  {
    CEcoSector::FillTransportPrio(LocalPlayerEcoSectorPtrAtCenter, (int)a1);
    *((_BYTE *)a1 + 8) = 1;
  }
  else
  {
    *((_BYTE *)a1 + 8) = 0;
  }
  v3 = 604;
  if ( !a2 )
    v3 = 602;
  CEvn_Event::CEvn_Event(&v5, v3, 0, (unsigned int)a1, 0);
  v6 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1963, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v5);
  v6 = -1;
  return CEvn_Event::~CEvn_Event(&v5);
}


// address=[0x14438a0]
// Decompiled from _DWORD *__cdecl CEcoSectorMgr::ChangeTransportPrio(int a1, int a2)
void __cdecl CEcoSectorMgr::ChangeTransportPrio(enum PILE_TYPES a1, int a2, bool a3, bool a4) {
  
  _DWORD *result; // eax
  _DWORD v3[6]; // [esp+10h] [ebp-28h] BYREF
  int v4; // [esp+34h] [ebp-4h]

  CPlayerManager::GetLocalPlayerId();
  result = (_DWORD *)CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter();
  if ( !result )
    return result;
  CEcoSector::ChangeTransportPrio(result, a1, a2);
  CEvn_Event::CEvn_Event((CEvn_Event *)v3, 604u, 0, (unsigned int)&g_cTransportpriorityInfo, 0);
  v4 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1987, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
  v4 = -1;
  return CEvn_Event::~CEvn_Event(v3);
}


// address=[0x1443980]
// Decompiled from struct CEcoSector *__cdecl CEcoSectorMgr::ChangeTransportPrio(int a1, int a2, int a3)
void __cdecl CEcoSectorMgr::ChangeTransportPrio(enum PILE_TYPES a1, int a2, int a3) {
  
  struct CEcoSector *result; // eax
  struct CEcoSector *v4; // [esp+8h] [ebp-2Ch]
  _DWORD v5[6]; // [esp+Ch] [ebp-28h] BYREF
  int v6; // [esp+30h] [ebp-4h]

  result = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, a3);
  v4 = result;
  if ( !result )
  {
    result = (struct CEcoSector *)BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1998, "pEcoSector!=NULL");
    if ( result == (struct CEcoSector *)1 )
      __debugbreak();
  }
  if ( !v4 )
    return result;
  CEcoSector::ChangeTransportPrio(v4, a1, a2);
  CEvn_Event::CEvn_Event((CEvn_Event *)v5, 604u, 0, (unsigned int)&g_cTransportpriorityInfo, 0);
  v6 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2010, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, v5);
  v6 = -1;
  return (struct CEcoSector *)CEvn_Event::~CEvn_Event(v5);
}


// address=[0x1443a90]
// Decompiled from void __cdecl CEcoSectorMgr::FillGoodDistribution(struct CInfoExchange *a1)
void __cdecl CEcoSectorMgr::FillGoodDistribution(class CInfoExchange * a1, bool a2, bool a3) {
  
  int LocalPlayerId; // [esp+8h] [ebp-38h]
  int v2; // [esp+Ch] [ebp-34h]
  CEcoSector *LocalPlayerEcoSectorPtrAtCenter; // [esp+10h] [ebp-30h]
  _DWORD v4[6]; // [esp+18h] [ebp-28h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1870, "_pInfoExchange != NULL") == 1 )
    __debugbreak();
  if ( a1 )
  {
    v2 = -1;
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    *((_DWORD *)a1 + 1) = 34;
    *((_DWORD *)a1 + 3) = CPlayerManager::Race(LocalPlayerId);
    LocalPlayerEcoSectorPtrAtCenter = (CEcoSector *)CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter();
    if ( LocalPlayerEcoSectorPtrAtCenter )
    {
      v2 = CEcoSector::EcoSectorId(LocalPlayerEcoSectorPtrAtCenter);
      if ( v2 != *((_DWORD *)a1 + 16) )
      {
        if ( CEcoSector::Owner(LocalPlayerEcoSectorPtrAtCenter) == LocalPlayerId )
          CEcoSector::FillGoodDistribution(LocalPlayerEcoSectorPtrAtCenter, a1);
        else
          *((_DWORD *)a1 + 2) = 0;
      }
    }
    else
    {
      *((_DWORD *)a1 + 2) = 0;
    }
    if ( *((_DWORD *)a1 + 16) != v2 )
    {
      *((_DWORD *)a1 + 16) = v2;
      CEvn_Event::CEvn_Event((CEvn_Event *)v4, 0x25Cu, 0, (unsigned int)a1, 0);
      v5 = 0;
      if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1911, "g_pEvnEngine != NULL") == 1 )
        __debugbreak();
      if ( g_pEvnEngine )
        IEventEngine::SendAMessage(g_pEvnEngine, v4);
      v5 = -1;
      CEvn_Event::~CEvn_Event(v4);
    }
  }
}


// address=[0x1443c10]
// Decompiled from int __cdecl CEcoSectorMgr::ChangeGoodDistributionPrio(int a1, int a2, int a3, unsigned __int8 a4)
void __cdecl CEcoSectorMgr::ChangeGoodDistributionPrio(enum PILE_TYPES a1, enum BUILDING_TYPES a2, int a3, signed char a4) {
  
  int result; // eax
  struct CEcoSector *EcoSectorPtr; // [esp+0h] [ebp-4h]

  if ( (a1 <= 0 || a1 >= 43)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1846, "_GoodType > GOOD_NO_GOOD && _GoodType<GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a2 <= 0 || a2 >= 83)
    && BBSupportDbgReport(
         2,
         "Logic\\EcoSectorMgr.cpp",
         1847,
         "_BuildingType > BUILDING_NO_BUILDING && _BuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, a3);
  if ( !EcoSectorPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1851, "pSector!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( EcoSectorPtr )
    return CEcoSector::ChangeBuildingSupplyPrio(EcoSectorPtr, a1, a2, a4);
  return result;
}


// address=[0x1443cd0]
// Decompiled from int CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter()
int __cdecl CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter(void) {
  
  int v0; // eax
  _DWORD v2[4]; // [esp+0h] [ebp-24h] BYREF
  int LocalPlayerId; // [esp+10h] [ebp-14h]
  int v4; // [esp+14h] [ebp-10h]
  int v5; // [esp+18h] [ebp-Ch]
  int v6; // [esp+1Ch] [ebp-8h] BYREF
  int v7; // [esp+20h] [ebp-4h] BYREF

  v5 = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  CStateGame::GetCenterWorldCoordinate((CStateGame *)g_pGame, &v6, &v7);
  if ( !(unsigned __int8)CWorldManager::InWorld(v6, v7) )
    return v5;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v2, v6, v7, 15);
  while ( CSpiralWalk::NextXY(v2, &v6, &v7) )
  {
    v4 = CWorldManager::Index(v6, v7);
    v0 = ITiling::OwnerId(v4);
    if ( v0 == LocalPlayerId )
    {
      v5 = CWorldManager::EcoSectorId(v6, v7);
      if ( v5 )
        break;
    }
  }
  return v5;
}


// address=[0x1443d80]
// Decompiled from struct CEcoSector *CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter()
class CEcoSector * __cdecl CEcoSectorMgr::GetLocalPlayerEcoSectorPtrAtCenter(void) {
  
  struct CEcoSector *EcoSectorPtr; // [esp+0h] [ebp-8h]
  int LocalPlayerEcoSectorIdAtCenter; // [esp+4h] [ebp-4h]

  LocalPlayerEcoSectorIdAtCenter = CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter();
  if ( LocalPlayerEcoSectorIdAtCenter <= 0 )
    return 0;
  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, LocalPlayerEcoSectorIdAtCenter);
  if ( !EcoSectorPtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2126, "pEcoSector != 0") == 1 )
    __debugbreak();
  return EcoSectorPtr;
}


// address=[0x1443de0]
// Decompiled from void __thiscall CEcoSectorMgr::Store(CEcoSectorMgr *this, struct S4::CMapFile *a2)
void  CEcoSectorMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-150h] BYREF
  _DWORD v5[42]; // [esp+10h] [ebp-140h] BYREF
  _BYTE v6[12]; // [esp+B8h] [ebp-98h] BYREF
  _BYTE v7[12]; // [esp+C4h] [ebp-8Ch] BYREF
  _BYTE v8[12]; // [esp+D0h] [ebp-80h] BYREF
  int v9; // [esp+DCh] [ebp-74h]
  _BYTE v10[12]; // [esp+E0h] [ebp-70h] BYREF
  unsigned int v11; // [esp+ECh] [ebp-64h]
  size_t Size; // [esp+F0h] [ebp-60h]
  void *Src; // [esp+F4h] [ebp-5Ch]
  __int16 *v14; // [esp+F8h] [ebp-58h]
  __int16 *v15; // [esp+FCh] [ebp-54h]
  std::_Iterator_base12 *v16; // [esp+100h] [ebp-50h]
  std::_Iterator_base12 *v17; // [esp+104h] [ebp-4Ch]
  int v18; // [esp+108h] [ebp-48h]
  int v19; // [esp+10Ch] [ebp-44h]
  int v20; // [esp+110h] [ebp-40h] BYREF
  BOOL v21; // [esp+118h] [ebp-38h]
  int v22; // [esp+11Ch] [ebp-34h] BYREF
  int v23; // [esp+120h] [ebp-30h]
  int v24; // [esp+124h] [ebp-2Ch] BYREF
  int j; // [esp+128h] [ebp-28h]
  int i; // [esp+12Ch] [ebp-24h]
  int v27; // [esp+130h] [ebp-20h]
  int k; // [esp+134h] [ebp-1Ch]
  bool v29; // [esp+13Ah] [ebp-16h]
  char v30; // [esp+13Bh] [ebp-15h]
  _DWORD *v31; // [esp+13Ch] [ebp-14h]
  int *v32; // [esp+140h] [ebp-10h]
  int v33; // [esp+14Ch] [ebp-4h]

  v32 = &v4;
  v31 = this;
  v27 = 0;
  CEcoSectorMgr::CalculateStoreWorldIndices(this);
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v33 = 0;
  v11 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v33) = 1;
  Serial::StoreVersion(v5, 3);
  operator^<int>((int)v5, v31);
  operator^<int>((int)v5, v31 + 1);
  operator^<int>((int)v5, v31 + 2);
  operator^<int>((int)v5, v31 + 3);
  operator^<int>((int)v5, v31 + 4);
  v24 = 0;
  for ( i = 1; i <= v31[2]; ++i )
  {
    if ( v31[i + 5] )
      ++v24;
  }
  operator^<int>((int)v5, &v24);
  for ( j = 1; j <= v31[2]; ++j )
  {
    v23 = v31[j + 5];
    if ( v23 )
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v23 + 4))(v23, v5);
  }
  operator^<int>((int)v5, v31 + 16389);
  StoreArray<int>(v5, v31 + 16390, 36);
  v20 = 9;
  operator^<int>((int)v5, &v20);
  for ( k = 0; k < 9; ++k )
  {
    v22 = std::vector<unsigned short>::size(&v31[4 * k + 16399]);
    operator^<int>((int)v5, &v22);
    v9 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v10);
    LOBYTE(v33) = 2;
    v19 = std::vector<unsigned short>::begin(v8);
    v18 = v19;
    LOBYTE(v33) = 3;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator=(v19);
    LOBYTE(v33) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v8);
    while ( 1 )
    {
      v17 = (std::_Iterator_base12 *)std::vector<unsigned short>::end(v6);
      v16 = v17;
      LOBYTE(v33) = 4;
      v27 |= 1u;
      v30 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=(v17);
      v21 = v30 && v22 > 0;
      v29 = v21;
      v33 = 2;
      if ( (v27 & 1) != 0 )
      {
        v27 &= ~1u;
        std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v6);
      }
      if ( !v29 )
        break;
      v15 = (__int16 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v10);
      v14 = v15;
      operator^<unsigned short>((int)v5, v15);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v7, 0);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v7);
    }
    LOBYTE(v33) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v10);
  }
  std::ostream::put(0);
  v33 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(180, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v11);
  v33 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x1444230]
// Decompiled from void __thiscall CEcoSectorMgr::Load(char *this, S4::CMapFile *a2)
void  CEcoSectorMgr::Load(class S4::CMapFile & a2) {
  
  int v2; // [esp+0h] [ebp-128h] BYREF
  _DWORD v3[42]; // [esp+10h] [ebp-118h] BYREF
  unsigned int v4; // [esp+B8h] [ebp-70h]
  int v5; // [esp+BCh] [ebp-6Ch] BYREF
  int v6; // [esp+C0h] [ebp-68h]
  int v7; // [esp+C4h] [ebp-64h]
  int Version; // [esp+C8h] [ebp-60h]
  int v9; // [esp+CCh] [ebp-5Ch] BYREF
  int pExceptionObject; // [esp+D4h] [ebp-54h] BYREF
  int v11; // [esp+D8h] [ebp-50h] BYREF
  char *Str; // [esp+DCh] [ebp-4Ch]
  int k; // [esp+E0h] [ebp-48h]
  int v14; // [esp+E4h] [ebp-44h] BYREF
  int i; // [esp+E8h] [ebp-40h]
  char v16[4]; // [esp+ECh] [ebp-3Ch] BYREF
  int j; // [esp+F0h] [ebp-38h]
  char *v18; // [esp+F4h] [ebp-34h]
  _BYTE v19[28]; // [esp+F8h] [ebp-30h] BYREF
  int *v20; // [esp+118h] [ebp-10h]
  int v21; // [esp+124h] [ebp-4h]

  v20 = &v2;
  v18 = this;
  v9 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xB4u, 0, &v9, 0);
  if ( Str )
  {
    std::string::string(v19, Str);
    v21 = 0;
    std::istringstream::istringstream(v19, 1, 1);
    LOBYTE(v21) = 1;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    Version = Serial::LoadVersion(v3);
    LOBYTE(v21) = 2;
    if ( Version != 3 )
    {
      BBSupportTracePrintF(3, "Unknown file format version for CEcoSectorMgr!");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<int>((int)v3, (int)v18);
    operator^<int>((int)v3, (int)(v18 + 4));
    operator^<int>((int)v3, (int)(v18 + 8));
    operator^<int>((int)v3, (int)(v18 + 12));
    operator^<int>((int)v3, (int)(v18 + 16));
    v11 = 0;
    operator^<int>((int)v3, (int)&v11);
    for ( i = 0; i < v11; ++i )
      CPersistence::New(v3, v2);
    operator^<int>((int)v3, (int)(v18 + 65556));
    LoadArray<int>(v3, v18 + 65560, 36);
    v14 = 0;
    operator^<int>((int)v3, (int)&v14);
    if ( v14 > 9 )
    {
      v7 = BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 522, "iPlayerMax <= PLAYER_MAX");
      if ( v7 == 1 )
        __debugbreak();
    }
    LOBYTE(v21) = 3;
    for ( j = 0; j < v14; ++j )
    {
      if ( std::vector<unsigned short>::size(&v18[16 * j + 65596]) )
      {
        v6 = BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 529, "m_vStrikeSettlers[i].size()==0");
        if ( v6 == 1 )
          __debugbreak();
      }
      operator^<int>((int)v3, (int)&v5);
      for ( k = 0; k < v5; ++k )
      {
        operator^<unsigned short>(v3, v16);
        std::vector<unsigned short>::push_back(v16);
      }
    }
    v21 = 1;
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    LOBYTE(v21) = 0;
    std::istringstream::`vbase destructor'(v3);
    v21 = -1;
    std::string::~string(v19);
  }
}


// address=[0x14445d0]
// Decompiled from int __thiscall CEcoSectorMgr::GetNearestPileIDOfferGood(CEcoSectorMgr *this, int a2, int a3, int a4, int a5)
int  CEcoSectorMgr::GetNearestPileIDOfferGood(int a2, int a3, int a4, int a5) {
  
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v9; // [esp-4h] [ebp-28h]
  int v10; // [esp+4h] [ebp-20h]
  int v11; // [esp+8h] [ebp-1Ch]
  int v12; // [esp+Ch] [ebp-18h]
  int j; // [esp+14h] [ebp-10h]
  CEcoSector *v15; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  struct CPile *PilePtr; // [esp+20h] [ebp-4h]

  v10 = 0;
  v11 = 0xFFFF;
  for ( i = 1; i <= *((_DWORD *)this + 2); ++i )
  {
    v15 = (CEcoSector *)*((_DWORD *)this + i + 5);
    if ( v15 && CEcoSector::Owner(v15) == a2 )
    {
      for ( j = CEcoSector::GetGoodOffer(v15, a5); j; j = IAnimatedEntity::Next(PilePtr) )
      {
        PilePtr = CPileMgr::GetPilePtr(j);
        if ( !PilePtr && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2060, "pPile!=NULL") == 1 )
          __debugbreak();
        if ( PilePtr )
        {
          v5 = IEntity::WorldIdx();
          v6 = CWorldManager::SectorId(v5);
          if ( v6 == CWorldManager::SectorId(a3, a4) )
          {
            v9 = a4 - IEntity::Y(PilePtr);
            v7 = IEntity::X(PilePtr);
            v12 = Grid::Distance((Grid *)(a3 - v7), v9);
            if ( v12 < v11 )
            {
              v11 = v12;
              v10 = j;
            }
          }
        }
      }
    }
  }
  return v10;
}


// address=[0x1444720]
// Decompiled from int __thiscall CEcoSectorMgr::DBG_CheckEcoSectors(CEcoSectorMgr *this)
void  CEcoSectorMgr::DBG_CheckEcoSectors(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v2 = *((_DWORD *)this + 2);
  for ( i = 1; ; ++i )
  {
    result = i;
    if ( i > v2 )
      break;
    if ( *((_DWORD *)this + i + 5) )
      CEcoSector::DbgCheckEcoSector(*((CEcoSector **)this + i + 5), 0);
  }
  return result;
}


// address=[0x1444770]
// Decompiled from int __thiscall CEcoSectorMgr::GetFirstESForPlayer(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::GetFirstESForPlayer(int a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 1; i <= *((_DWORD *)this + 2); ++i )
  {
    v3 = *((_DWORD *)this + i + 5);
    if ( v3 && CEcoSector::Owner(v3) == a2 )
      return i;
  }
  return 0;
}


// address=[0x14447d0]
// Decompiled from int __thiscall CEcoSectorMgr::GetNextESForPlayer(CEcoSectorMgr *this, int a2, int a3)
int  CEcoSectorMgr::GetNextESForPlayer(int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = a3 + 1; i <= *((_DWORD *)this + 2); ++i )
  {
    v4 = *((_DWORD *)this + i + 5);
    if ( v4 && CEcoSector::Owner(v4) == a2 )
      return i;
  }
  return 0;
}


// address=[0x1444830]
// Decompiled from int __thiscall CEcoSectorMgr::GetFreeSlot(CEcoSectorMgr *this)
int  CEcoSectorMgr::GetFreeSlot(void) {
  
  int v2; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  if ( (*((int *)this + 1) < 1 || *((int *)this + 1) > 0x4000)
    && BBSupportDbgReport(
         2,
         "Logic\\EcoSectorMgr.cpp",
         248,
         "m_sData.m_iMinFreeId >= 1 && m_sData.m_iMinFreeId <= MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 1) <= 0 )
    v2 = 1;
  else
    v2 = *((_DWORD *)this + 1);
  for ( i = v2; i < 0x4000; ++i )
  {
    if ( !*((_DWORD *)this + i + 5) )
    {
      *((_DWORD *)this + 1) = i;
      return i;
    }
  }
  *((_DWORD *)this + 1) = 0x4000;
  return -1;
}


// address=[0x14448e0]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::RegisterEcoSector(CEcoSectorMgr *this, int a2, struct CEcoSector *a3, bool a4)
void  CEcoSectorMgr::RegisterEcoSector(int a2, class CEcoSector * a3, bool a4) {
  
  CEcoSectorMgr *result; // eax

  if ( !a3 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 294, "_pEcoSector != NULL") == 1 )
    __debugbreak();
  if ( (a2 <= 0 || a2 >= 0x4000)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 295, "_iEcoSectorId > 0 && _iEcoSectorId < MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + a2 + 5)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 296, "m_sData.m_vEcoSectors[_iEcoSectorId] == NULL") == 1 )
  {
    __debugbreak();
  }
  if ( a4 )
  {
    if ( *((_DWORD *)a3 + 3)
      && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 302, "_pEcoSector->m_iUniqueId == 0") == 1 )
    {
      __debugbreak();
    }
    if ( *((int *)this + 4) < 0x10000000
      && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 303, "m_sData.m_iCurrentUniqueId >= 0x10000000") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)a3 + 3) = (*((_DWORD *)this + 4))++;
  }
  else if ( *((int *)a3 + 3) < 0x10000000
         && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 309, "_pEcoSector->m_iUniqueId >= 0x10000000") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > *((_DWORD *)this + 2) )
  {
    *((_DWORD *)this + 2) = a2;
    if ( a2 > *((_DWORD *)this + 3) )
      *((_DWORD *)this + 3) = a2;
  }
  result = this;
  *((_DWORD *)this + a2 + 5) = a3;
  return result;
}


// address=[0x1444a50]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::DestroyEcoSector(CEcoSectorMgr *this, int a2)
void  CEcoSectorMgr::DestroyEcoSector(int a2) {
  
  CEcoSectorMgr *result; // eax
  CEcoSector *v3; // [esp+18h] [ebp-Ch]
  int v4; // [esp+1Ch] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 0x4000)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 337, "(_iEcoSectorId > 0) && (_iEcoSectorId < MAX_ENTRIES)") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + a2 + 5)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 338, "m_sData.m_vEcoSectors[_iEcoSectorId] != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (CEcoSector *)*((_DWORD *)this + a2 + 5);
  CEcoSector::Owner(v3);
  if ( CEcoSector::EcoSectorId(v3) != a2
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 344, "pEcoSector->EcoSectorId() == _iEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  if ( v3 )
    delete v3;
  *((_DWORD *)this + a2 + 5) = 0;
  if ( a2 < *((_DWORD *)this + 1) )
    *((_DWORD *)this + 1) = a2;
  if ( *((int *)this + 2) < 0
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 355, "m_sData.m_iLastUsedId >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 5)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 356, "m_sData.m_vEcoSectors[0] == NULL") == 1 )
  {
    __debugbreak();
  }
  v4 = *((_DWORD *)this + 2);
  if ( v4 < 0 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 360, "iLastUsedId >= 0") == 1 )
    __debugbreak();
  while ( *((_DWORD *)this + v4 + 5) == 0 && v4 > 0 )
    --v4;
  if ( v4 < 0 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 367, "iLastUsedId >= 0") == 1 )
    __debugbreak();
  result = this;
  *((_DWORD *)this + 2) = v4;
  return result;
}


// address=[0x1444c50]
// Decompiled from int __thiscall CEcoSectorMgr::CalculateStoreWorldIndices(_DWORD *this)
void  CEcoSectorMgr::CalculateStoreWorldIndices(void) {
  
  int v1; // ecx
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  Squares *v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // [esp+4h] [ebp-1002Ch]
  CEcoSector *v9; // [esp+8h] [ebp-10028h]
  int v10; // [esp+Ch] [ebp-10024h]
  int k; // [esp+14h] [ebp-1001Ch]
  struct CTile *v13; // [esp+18h] [ebp-10018h]
  int j; // [esp+1Ch] [ebp-10014h]
  int i; // [esp+20h] [ebp-10010h]
  int m; // [esp+24h] [ebp-1000Ch]
  int v17; // [esp+28h] [ebp-10008h]
  _DWORD v18[16384]; // [esp+2Ch] [ebp-10004h] BYREF

  memset(v18, 255, sizeof(v18));
  v2 = CWorldManager::Width(v1);
  if ( v2 != CWorldManager::Height(v4, v3)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2164, "g_cWorld.Width() == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  v5 = (Squares *)CWorldManager::Width(0);
  v10 = Squares::XYToVW(v5);
  for ( i = 0; i < v10; ++i )
  {
    for ( j = 0; j < v10; ++j )
    {
      for ( k = ITiling::FirstTileOfSquareVW(j, i); k > 0; k = CTile::NextSquareTile(v13) )
      {
        v13 = (struct CTile *)ITiling::Tile(k);
        v17 = CTile::EcoSectorId(v13);
        if ( v17 > 0 )
        {
          if ( v17 >= 0x4000
            && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2182, "iEcoSectorId < MAX_ENTRIES") == 1 )
          {
            __debugbreak();
          }
          if ( v17 > this[2]
            && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2183, "iEcoSectorId <= m_sData.m_iLastUsedId") == 1 )
          {
            __debugbreak();
          }
          if ( (int)v18[v17] < 0 )
          {
            v6 = CTile::CenterXY(v13);
            v18[v17] = CWorldManager::Index(v6);
            if ( ITiling::EcoSectorId(v18[v17]) != v17
              && BBSupportDbgReport(
                   2,
                   "Logic\\EcoSectorMgr.cpp",
                   2189,
                   "g_pTiling->EcoSectorId(iStoreWorldIndices[iEcoSectorId]) == iEcoSectorId") == 1 )
            {
              __debugbreak();
            }
          }
        }
      }
    }
  }
  v8 = this[2];
  for ( m = 1; ; ++m )
  {
    result = m;
    if ( m > v8 )
      break;
    v9 = (CEcoSector *)this[m + 5];
    if ( v9 )
    {
      if ( (int)v18[m] < 0
        && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2206, "iStoreWorldIndices[iEcoSectorId] >= 0") == 1 )
      {
        __debugbreak();
      }
      CEcoSector::SetWorldIdxForStore(v9, v18[m]);
    }
    else if ( (int)v18[m] >= 0
           && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 2212, "iStoreWorldIndices[iEcoSectorId] < 0") == 1 )
    {
      __debugbreak();
    }
  }
  return result;
}


// address=[0x1444f60]
// Decompiled from int __thiscall CEcoSectorMgr::NewEcoSector(CEcoSectorMgr *this, int a2)
int  CEcoSectorMgr::NewEcoSector(int a2) {
  
  CPlayerGameData *v2; // eax
  pairNode *v4; // [esp+8h] [ebp-20h]
  CEcoSector *C; // [esp+Ch] [ebp-1Ch]
  int FreeSlot; // [esp+18h] [ebp-10h]

  FreeSlot = CEcoSectorMgr::GetFreeSlot(this);
  BBSupportTracePrintF(0, "CEcoSectorMgr::NewEcoSector(): owner %i.", a2);
  if ( *((_DWORD *)this + FreeSlot + 5)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1029, "m_sData.m_vEcoSectors[iEcoSectorId] == 0") == 1 )
  {
    __debugbreak();
  }
  C = (CEcoSector *)operator new(0x3C4u);
  if ( C )
    v4 = CEcoSector::CEcoSector(C, a2, FreeSlot);
  else
    v4 = 0;
  if ( !v4 && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1033, "pNewEcoSector != 0") == 1 )
    __debugbreak();
  if ( *((pairNode **)this + FreeSlot + 5) != v4
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1034, "m_sData.m_vEcoSectors[iEcoSectorId] == pNewEcoSector") == 1 )
  {
    __debugbreak();
  }
  v2 = CPlayerManager::PlayerGameData(a2);
  CPlayerGameData::AddEcoSectorId(v2, FreeSlot);
  CEcoSector::GetUniqueId(v4);
  (*(void (__cdecl **)(int))(*(_DWORD *)off_3D7A3D8 + 44))(13);
  return FreeSlot;
}


// address=[0x14450d0]
// Decompiled from CEcoSectorMgr *__thiscall CEcoSectorMgr::DeleteEcoSector(CEcoSectorMgr *this, int a2)
void  CEcoSectorMgr::DeleteEcoSector(int a2) {
  
  CEcoSectorMgr *result; // eax
  CPlayerGameData *v3; // eax
  int UniqueId; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  pairNode *v7; // [esp+Ch] [ebp-4h]

  BBSupportTracePrintF(0, "CEcoSectorMgr::DeleteEcoSector(): eco-sector %i", a2);
  if ( (a2 <= 0 || a2 >= 0x4000)
    && BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1053, "(_iEcoSectorId > 0) && (_iEcoSectorId < MAX_ENTRIES)") == 1 )
  {
    __debugbreak();
  }
  result = this;
  if ( !*((_DWORD *)this + a2 + 5) )
  {
    result = (CEcoSectorMgr *)BBSupportDbgReport(
                                2,
                                "Logic\\EcoSectorMgr.cpp",
                                1054,
                                "m_sData.m_vEcoSectors[_iEcoSectorId] != 0");
    if ( result == (CEcoSectorMgr *)1 )
      __debugbreak();
  }
  if ( a2 <= 0 || a2 >= 0x4000 )
    return result;
  result = this;
  v7 = (pairNode *)*((_DWORD *)this + a2 + 5);
  if ( !v7 )
    return result;
  if ( CEcoSector::Size(v7) )
  {
    if ( BBSupportDbgReport(2, "Logic\\EcoSectorMgr.cpp", 1065, "pEcoSector->Size() == 0") == 1 )
      __debugbreak();
  }
  v5 = CEcoSector::Owner(v7);
  UniqueId = CEcoSector::GetUniqueId(v7);
  CEcoSectorMgr::DestroyEcoSector(this, a2);
  v3 = CPlayerManager::PlayerGameData(v5);
  CPlayerGameData::DeleteEcoSectorId(v3, a2);
  return (CEcoSectorMgr *)(*(int (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)off_3D7A3D8 + 44))(
                            off_3D7A3D8,
                            14,
                            v5,
                            a2,
                            UniqueId);
}


