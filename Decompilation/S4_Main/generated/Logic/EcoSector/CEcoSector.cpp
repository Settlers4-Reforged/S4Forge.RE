#include "all_headers.h"

// Definitions for class CEcoSector

// address=[0x130ee50]
// Decompiled from int __thiscall CEcoSector::GetUniqueId(pairNode *this)
int  CEcoSector::GetUniqueId(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x130f230]
// Decompiled from int __thiscall CEcoSector::Owner(CEcoSector *this)
int  CEcoSector::Owner(void)const {
  
  return *((unsigned __int8 *)this + 18);
}


// address=[0x13466a0]
// Decompiled from int __thiscall CEcoSector::ExtraMinCarrierForRecruitment(CEcoSector *this)
int  CEcoSector::ExtraMinCarrierForRecruitment(void)const {
  
  return *((unsigned __int8 *)this + 30);
}


// address=[0x1346890]
// Decompiled from int __thiscall CEcoSector::MinCarrier(CEcoSector *this)
int  CEcoSector::MinCarrier(void)const {
  
  return *((unsigned __int16 *)this + 16);
}


// address=[0x1400680]
// Decompiled from int __cdecl CEcoSector::New(int a1)
static class CPersistence * __cdecl CEcoSector::New(std::istream &) {
  
  if ( operator new(0x3C4u) )
    return CEcoSector::CEcoSector(a1);
  else
    return 0;
}


// address=[0x14299b0]
// Decompiled from int __thiscall CEcoSector::NrOfSettler(CEcoSector *this, unsigned int a2)
int  CEcoSector::NrOfSettler(int)const {
  
  if ( a2 > 0x42
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1130, "0<=_iSettlerType && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int16 *)this + a2 + 18);
}


// address=[0x1429a00]
// Decompiled from __int16 __thiscall CEcoSector::ChangeNrOfSettler(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangeNrOfSettler(int,int) {
  
  __int16 result; // ax
  int v5; // [esp+8h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 67)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1143, "0 < _iSettlerType && _iSettlerType < SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  v5 = a3 + *((unsigned __int16 *)this + a2 + 18);
  if ( v5 < 0 && BBSupportDbgReportF(2, "Logic\\EcoSector.cpp", 1149, "iNewAmount < 0! Settler type %i.", a2) == 1 )
    __debugbreak();
  if ( v5 >= 0 )
  {
    if ( v5 > 0xFFFF )
      LOWORD(v5) = -1;
  }
  else
  {
    LOWORD(v5) = 0;
  }
  result = v5;
  *((_WORD *)this + a2 + 18) = v5;
  return result;
}


// address=[0x1429ab0]
// Decompiled from int __thiscall CEcoSector::GetSettlerOffer(CEcoSector *this, int a2)
int  CEcoSector::GetSettlerOffer(int)const {
  
  return *((unsigned __int16 *)this + a2 + 85);
}


// address=[0x1429ad0]
// Decompiled from _DWORD *__thiscall CEcoSector::SetSettlerOffer(unsigned __int16 *this, int a2, int a3)
void  CEcoSector::SetSettlerOffer(int,int) {
  
  int v3; // eax
  IAnimatedEntity *v4; // eax
  _DWORD *result; // eax
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  unsigned __int8 *SettlerPtr; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  SettlerPtr = CSettlerMgr::GetSettlerPtr(a3);
  if ( IEntity::FlagBits(SettlerPtr, Offered)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 921, "!pSettler->FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  if ( CSettlerMgr::SettlerWarriorType(a2)
    && BBSupportDbgReport(
         2,
         "Logic\\EcoSector.cpp",
         922,
         "CSettlerMgr::SettlerWarriorType(_iSettlerType) == WARRIOR_TYPE_NONE") == 1 )
  {
    __debugbreak();
  }
  v6 = 0;
  for ( i = this[a2 + 85]; i; i = IAnimatedEntity::Next(v3) )
  {
    if ( a3 == i && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 932, "_iSettlerId != iActSettler") == 1 )
      __debugbreak();
    if ( debug )
    {
      if ( DEBUG_FLAGS[dword_3EFEB2C] )
        ++v6;
    }
    v3 = CSettlerMgr::operator[](i);
  }
  IAnimatedEntity::SetPrevious((IAnimatedEntity *)SettlerPtr, 0);
  v7 = this[a2 + 85];
  if ( this[a2 + 85] )
  {
    v4 = (IAnimatedEntity *)CSettlerMgr::operator[](v7);
    IAnimatedEntity::SetPrevious(v4, a3);
  }
  IAnimatedEntity::SetNext(SettlerPtr, v7);
  this[a2 + 85] = a3;
  result = IEntity::SetFlagBits(SettlerPtr, Offered);
  if ( !debug )
    return result;
  result = (_DWORD *)dword_3EFEB2C;
  if ( DEBUG_FLAGS[dword_3EFEB2C] )
    return (_DWORD *)BBSupportTracePrintF(
                       0,
                       "CEcoSector::SetSettlerOffer(): offer %s nr %u to ecosector %u list - now %u entries",
                       (&off_36A114C)[2 * a2],
                       a3,
                       this[8],
                       v6);
  return result;
}


// address=[0x1429c80]
// Decompiled from void __thiscall CEcoSector::SetSettlerOfferIncDisplay(CEcoSector *this, int a2, int a3)
void  CEcoSector::SetSettlerOfferIncDisplay(int,int) {
  
  if ( !CMapObjectMgr::ValidEntityId(a3)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 983, "g_pMapObjectMgr->ValidEntityId(_iSettlerId)") == 1 )
  {
    __debugbreak();
  }
  CEcoSector::SetSettlerOffer((unsigned __int16 *)this, a2, a3);
  CEcoSector::ChangeNrOfSettler(this, a2, 1);
}


// address=[0x1429ce0]
// Decompiled from int __thiscall CEcoSector::GetSettlerOutOfOffer(CEcoSector *this, int a2)
void  CEcoSector::GetSettlerOutOfOffer(int) {
  
  int v2; // eax
  _WORD *v3; // eax
  __int16 v4; // si
  int v5; // eax
  IAnimatedEntity *v6; // eax
  int result; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp-8h] [ebp-1Ch]
  int v11; // [esp-4h] [ebp-18h]
  int v12; // [esp-4h] [ebp-18h]
  int v14; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  unsigned __int16 *v16; // [esp+10h] [ebp-4h]

  v16 = (unsigned __int16 *)CSettlerMgr::operator[](a2);
  if ( !IEntity::FlagBits(v16, Offered)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1009, "rActSettler.FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::WarriorType()
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1011, "rActSettler.WarriorType() == WARRIOR_TYPE_NONE") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Previous(v16) )
  {
    v11 = IAnimatedEntity::Next(v16);
    v2 = IAnimatedEntity::Previous(v16);
    v3 = (_WORD *)CSettlerMgr::operator[](v2);
    IAnimatedEntity::SetNext(v3, v11);
  }
  else
  {
    v4 = IAnimatedEntity::Next(v16);
    *((_WORD *)this + IEntity::Type(v16) + 85) = v4;
  }
  if ( IAnimatedEntity::Next(v16) )
  {
    v12 = IAnimatedEntity::Previous(v16);
    v5 = IAnimatedEntity::Next(v16);
    v6 = (IAnimatedEntity *)CSettlerMgr::operator[](v5);
    IAnimatedEntity::SetPrevious(v6, v12);
  }
  IAnimatedEntity::SetNext(v16, 0);
  IAnimatedEntity::SetPrevious((IAnimatedEntity *)v16, 0);
  IEntity::ClearFlagBits(v16, Offered);
  v14 = 0;
  result = *((unsigned __int16 *)this + IEntity::Type(v16) + 85);
  for ( i = result; i; i = result )
  {
    if ( a2 == i && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1040, "_iSettlerId != iActSettler") == 1 )
      __debugbreak();
    if ( debug )
    {
      if ( DEBUG_FLAGS[dword_3EFEB2C] )
        ++v14;
    }
    v8 = CSettlerMgr::operator[](i);
    result = IAnimatedEntity::Next(v8);
  }
  if ( !debug )
    return result;
  result = dword_3EFEB2C;
  if ( !DEBUG_FLAGS[dword_3EFEB2C] )
    return result;
  v10 = *((unsigned __int16 *)this + 8);
  v9 = IEntity::Type(v16);
  return BBSupportTracePrintF(
           0,
           "CEcoSector::GetSettlerOutOfOffer(): get %s nr %u out of ecosector %u list - still %u entries",
           (&off_36A114C)[2 * v9],
           a2,
           v10,
           v14);
}


// address=[0x1429ed0]
// Decompiled from void __thiscall CEcoSector::GetSettlerOutOfOfferDecDisplay(CEcoSector *this, unsigned int a2)
void  CEcoSector::GetSettlerOutOfOfferDecDisplay(int) {
  
  int v2; // eax
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-4h]

  if ( !CMapObjectMgr::ValidEntityId(a2)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1068, "g_pMapObjectMgr->ValidEntityId(_iSettlerId)") == 1 )
  {
    __debugbreak();
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1071, "pSettler!= NULL") == 1 )
    __debugbreak();
  if ( SettlerPtr )
  {
    CEcoSector::GetSettlerOutOfOffer(this, a2);
    v2 = IEntity::Type((unsigned __int16 *)SettlerPtr);
    CEcoSector::ChangeNrOfSettler(this, v2, -1);
  }
}


// address=[0x1429f70]
// Decompiled from CEcoSector *__thiscall CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(CEcoSector *this, int a2, int a3)
void  CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(int,int) {
  
  CEcoSector *result; // eax
  unsigned __int16 *v4; // [esp+0h] [ebp-Ch]

  CEcoSector::GetSettlerOutOfOffer(this, a2);
  v4 = (unsigned __int16 *)CSettlerMgr::operator[](a2);
  if ( IEntity::Type(v4) != 1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1090, "rSettler.Type() == SETTLER_CARRIER") == 1 )
  {
    __debugbreak();
  }
  if ( !CSettler::SetNextSettlerType((CSettler *)v4, a3)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1094, "bSetNextSettlerTypeOk") == 1 )
  {
    __debugbreak();
  }
  result = this;
  ++*((_WORD *)this + 17);
  return result;
}


// address=[0x142a020]
// Decompiled from _WORD *__thiscall sub_182A020(_WORD *this, int a2)
void  CEcoSector::ResetCarrierNextSettlerTypeAndDecrementOrder(int) {
  
  _WORD *result; // eax
  int v3; // [esp+0h] [ebp-8h]

  v3 = CSettlerMgr::operator[](a2);
  if ( IEntity::Type(v3) != 1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1109, "rSettler.Type() == SETTLER_CARRIER") == 1 )
  {
    __debugbreak();
  }
  CSettler::SetNextSettlerType(0);
  if ( !this[17] && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1113, "m_uOrderedCarrier > 0") == 1 )
    __debugbreak();
  result = (_WORD *)(unsigned __int16)this[17];
  if ( !this[17] )
    return result;
  result = this;
  --this[17];
  return result;
}


// address=[0x142a0c0]
// Decompiled from int __thiscall CEcoSector::OrderWorker(CEcoSector *this, int a2, int a3)
int  CEcoSector::OrderWorker(int,int) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CSettler *v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // eax
  void *v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  CSettler *v18; // eax
  int v19; // eax
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // eax
  int v22; // eax
  unsigned __int8 *v23; // eax
  CSettler *v24; // eax
  int v25; // esi
  int v26; // eax
  int v27; // [esp-8h] [ebp-ACh]
  int v28; // [esp-8h] [ebp-ACh]
  int v29; // [esp-8h] [ebp-ACh]
  int v30; // [esp-4h] [ebp-A8h]
  int v31; // [esp-4h] [ebp-A8h]
  int v32; // [esp-4h] [ebp-A8h]
  int v33; // [esp-4h] [ebp-A8h]
  int v34; // [esp-4h] [ebp-A8h]
  int v35; // [esp-4h] [ebp-A8h]
  int v36; // [esp-4h] [ebp-A8h]
  _BYTE v37[24]; // [esp+Ch] [ebp-98h] BYREF
  _BYTE v38[24]; // [esp+24h] [ebp-80h] BYREF
  _BYTE v39[24]; // [esp+3Ch] [ebp-68h] BYREF
  CEntityEvent *v40; // [esp+54h] [ebp-50h]
  CEntityEvent *v41; // [esp+58h] [ebp-4Ch]
  int GoodOffer; // [esp+5Ch] [ebp-48h]
  CEntityEvent *v43; // [esp+60h] [ebp-44h]
  CEntityEvent *v44; // [esp+64h] [ebp-40h]
  int SettlerInfo; // [esp+68h] [ebp-3Ch]
  CEntityEvent *v46; // [esp+6Ch] [ebp-38h]
  CEntityEvent *v47; // [esp+70h] [ebp-34h]
  int v48; // [esp+74h] [ebp-30h]
  int v49; // [esp+78h] [ebp-2Ch]
  int v50; // [esp+7Ch] [ebp-28h]
  int v51; // [esp+80h] [ebp-24h]
  int v52; // [esp+84h] [ebp-20h]
  int NearestPile; // [esp+88h] [ebp-1Ch]
  CEcoSector *v54; // [esp+8Ch] [ebp-18h]
  _DWORD *v55; // [esp+90h] [ebp-14h]
  int NearestSettler; // [esp+94h] [ebp-10h]
  int v57; // [esp+A0h] [ebp-4h]

  v54 = this;
  if ( CSettlerMgr::SettlerWarriorType(a3)
    && BBSupportDbgReportF(
         2,
         "Logic\\EcoSector.cpp",
         1794,
         "WARNIG: Please don't call a soldier or specialist using OrderWorker!") == 1 )
  {
    __debugbreak();
  }
  if ( CSettlerMgr::SettlerWarriorType(a3) )
    return 0;
  v4 = CBuildingMgr::operator[](a2);
  v5 = CBuilding::EnsignWorldIdx(v4);
  v48 = CWorldManager::EcoSectorId(v5);
  if ( !v48 && BBSupportDbgReportF(2, "Logic\\EcoSector.cpp", 1802, "NO_ECOSECTOR under building!") == 1 )
    __debugbreak();
  v55 = (_DWORD *)CBuildingMgr::operator[](a2);
  v30 = IEntity::Y(v55);
  v6 = IEntity::X(v55);
  NearestSettler = CEcoSector::GetNearestSettler(v54, a3, v6, v30);
  if ( NearestSettler )
  {
    CEcoSector::GetSettlerOutOfOffer(v54, NearestSettler);
    v7 = (CSettler *)CSettlerMgr::operator[](NearestSettler);
    CSettler::AttachToBuilding(v7, a2);
    v51 = CSettlerMgr::operator[](NearestSettler);
    v47 = CEntityEvent::CEntityEvent((CEntityEvent *)v39, 1u, 0, a2, 0, 0);
    v46 = v47;
    v57 = 0;
    (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v51 + 80))(v51, v47);
    v57 = -1;
    CEntityEvent::~CEntityEvent(v39);
    return NearestSettler;
  }
  else
  {
    v8 = CEcoSector::MinCarrier(v54);
    v9 = CEcoSector::NrOfSettler(v54, 1);
    if ( v8 < v9 - CEcoSector::NumberOfCarriersWithJobOrder(v54) )
    {
      v12 = IEntity::Race(v55);
      SettlerInfo = CSettlerMgr::GetSettlerInfo(v12, a3);
      v52 = *(unsigned __int8 *)(SettlerInfo + 5);
      if ( v52 )
      {
        GoodOffer = CEcoSector::GetGoodOffer(v54, v52);
        v34 = IEntity::Y(v55);
        v19 = IEntity::X(v55);
        NearestPile = CPileMgr::GetNearestPile((CPileMgr *)&g_cPileMgr, GoodOffer, v19, v34);
        if ( NearestPile )
        {
          v20 = CPileMgr::operator[](NearestPile);
          v35 = IEntity::Y(v20);
          v21 = CPileMgr::operator[](NearestPile);
          v22 = IEntity::X(v21);
          NearestSettler = CEcoSector::GetNearestSettler(v54, 1, v22, v35);
          if ( NearestSettler )
          {
            CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v54, NearestSettler, a3);
            v23 = CPileMgr::operator[](NearestPile);
            CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v23, NearestSettler, 1, 2);
            v24 = (CSettler *)CSettlerMgr::operator[](NearestSettler);
            CSettler::AttachToBuilding(v24, a2);
            v49 = CSettlerMgr::operator[](NearestSettler);
            v41 = CEntityEvent::CEntityEvent((CEntityEvent *)v37, 0x17u, 0, a3, NearestPile, a2);
            v40 = v41;
            v57 = 2;
            (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v49 + 80))(v49, v41);
            v57 = -1;
            CEntityEvent::~CEntityEvent(v37);
            return NearestSettler;
          }
          else
          {
            return 0;
          }
        }
        else
        {
          v25 = CEcoSector::Owner(v54);
          if ( v25 != CPlayerManager::GetLocalPlayerId() )
            return 0;
          v36 = IEntity::OwnerId((unsigned __int8 *)v55);
          v29 = IEntity::Y(v55);
          v26 = IEntity::X(v55);
          CEcoSector::MissingToolWarning(v54, v52, a3, v26, v29, v36);
          return 0;
        }
      }
      else
      {
        v13 = (void *)CBuildingMgr::operator[](a2);
        v32 = IEntity::Y(v13);
        v14 = (_DWORD *)CBuildingMgr::operator[](a2);
        v15 = IEntity::X(v14);
        NearestSettler = CEcoSector::GetNearestSettler(v54, 1, v15, v32);
        if ( NearestSettler )
        {
          CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v54, NearestSettler, a3);
          v18 = (CSettler *)CSettlerMgr::operator[](NearestSettler);
          CSettler::AttachToBuilding(v18, a2);
          v50 = CSettlerMgr::operator[](NearestSettler);
          v44 = CEntityEvent::CEntityEvent((CEntityEvent *)v38, 0x16u, 0, a3, a2, 0);
          v43 = v44;
          v57 = 1;
          (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v50 + 80))(v50, v44);
          v57 = -1;
          CEntityEvent::~CEntityEvent(v38);
        }
        else
        {
          v16 = IEntity::OwnerId((unsigned __int8 *)v55);
          if ( v16 == CPlayerManager::GetLocalPlayerId() )
          {
            v33 = IEntity::Y(v55);
            v28 = IEntity::X(v55);
            v17 = IEntity::OwnerId((unsigned __int8 *)v55);
            CTextMsgHandler::AddWarningMsg(2459, v17, v28, v33);
          }
        }
        return NearestSettler;
      }
    }
    else
    {
      if ( a3 == 2 || a3 == 3 )
        return 0;
      v10 = IEntity::OwnerId((unsigned __int8 *)v55);
      if ( v10 != CPlayerManager::GetLocalPlayerId() )
        return 0;
      v31 = IEntity::Y(v55);
      v27 = IEntity::X(v55);
      v11 = IEntity::OwnerId((unsigned __int8 *)v55);
      CTextMsgHandler::AddWarningMsg(2459, v11, v27, v31);
      return 0;
    }
  }
}


// address=[0x142a580]
// Decompiled from int __thiscall CEcoSector::CallWorker(CEcoSector *this, int a2, int a3)
int  CEcoSector::CallWorker(int,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSettler *v6; // eax
  int v8; // [esp-4h] [ebp-48h]
  _BYTE v9[24]; // [esp+4h] [ebp-40h] BYREF
  CEntityEvent *v10; // [esp+1Ch] [ebp-28h]
  CEntityEvent *v11; // [esp+20h] [ebp-24h]
  int v12; // [esp+24h] [ebp-20h]
  int v13; // [esp+28h] [ebp-1Ch]
  CEcoSector *v14; // [esp+2Ch] [ebp-18h]
  _DWORD *v15; // [esp+30h] [ebp-14h]
  int NearestSettler; // [esp+34h] [ebp-10h]
  int v17; // [esp+40h] [ebp-4h]

  v14 = this;
  if ( CSettlerMgr::SettlerWarriorType(a3)
    && BBSupportDbgReportF(
         2,
         "Logic\\EcoSector.cpp",
         1749,
         "WARNIG: Please don't call a soldier or specialist using CallWorker!") == 1 )
  {
    __debugbreak();
  }
  v3 = CBuildingMgr::operator[](a2);
  v4 = CBuilding::EnsignWorldIdx(v3);
  v12 = CWorldManager::EcoSectorId(v4);
  if ( !v12 && BBSupportDbgReportF(2, "Logic\\EcoSector.cpp", 1752, "NO_ECOSECTOR under building!") == 1 )
    __debugbreak();
  v15 = (_DWORD *)CBuildingMgr::operator[](a2);
  v8 = IEntity::Y(v15);
  v5 = IEntity::X(v15);
  NearestSettler = CEcoSector::GetNearestSettler(v14, a3, v5, v8);
  if ( !NearestSettler )
    return 0;
  CEcoSector::GetSettlerOutOfOffer(v14, NearestSettler);
  v6 = (CSettler *)CSettlerMgr::operator[](NearestSettler);
  CSettler::AttachToBuilding(v6, a2);
  v13 = CSettlerMgr::operator[](NearestSettler);
  v11 = CEntityEvent::CEntityEvent((CEntityEvent *)v9, 1u, 0, a2, 0, 0);
  v10 = v11;
  v17 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v13 + 80))(v13, v11);
  v17 = -1;
  CEntityEvent::~CEntityEvent(v9);
  return NearestSettler;
}


// address=[0x142a6f0]
// Decompiled from int __thiscall CEcoSector::GetNearestSettler(CEcoSector *this, int a2, int a3, int a4)
int  CEcoSector::GetNearestSettler(int,int,int) {
  
  int v4; // eax
  int v6; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+4h] [ebp-14h]
  unsigned int v9; // [esp+8h] [ebp-10h]
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  _DWORD *v12; // [esp+14h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 67)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1706, "_iSettlerType>0 && _iSettlerType<SETTLER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1707, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = -1;
  v8 = 0;
  for ( i = CEcoSector::GetSettlerOffer(this, a2); i; i = IAnimatedEntity::Next(v12) )
  {
    v12 = (_DWORD *)CSettlerMgr::operator[](i);
    if ( !CSettler::Strike((CSettler *)v12) )
    {
      v6 = a4 - IEntity::Y(v12);
      v4 = IEntity::X(v12);
      v10 = Grid::Distance((Grid *)(a3 - v4), v6);
      if ( v10 < v9 )
      {
        v9 = v10;
        v8 = i;
      }
    }
  }
  return v8;
}


// address=[0x142a7f0]
// Decompiled from bool __thiscall CEcoSector::HaveFreeCarrier(CEcoSector *this)
bool  CEcoSector::HaveFreeCarrier(void)const {
  
  return *((_WORD *)this + 86) != 0;
}


// address=[0x142a830]
// Decompiled from int __thiscall CEcoSector::NrOfGoods(CEcoSector *this, int a2)
int  CEcoSector::NrOfGoods(int)const {
  
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // eax
  CEcoSector *v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v5 = this;
  v6 = 0;
  for ( i = *((unsigned __int16 *)this + a2 + 152); i; i = IAnimatedEntity::Next(v3) )
  {
    v2 = CPileMgr::operator[](i);
    v6 += (*(int (__thiscall **)(unsigned __int8 *, CEcoSector *, unsigned __int8 *))(*(_DWORD *)v2 + 40))(v2, v5, v2);
    v3 = CPileMgr::operator[](i);
  }
  return v6;
}


// address=[0x142a8a0]
// Decompiled from int __thiscall CEcoSector::GetGoodOffer(CEcoSector *this, int a2)
int  CEcoSector::GetGoodOffer(int)const {
  
  return *((unsigned __int16 *)this + a2 + 152);
}


// address=[0x142a8c0]
// Decompiled from _DWORD *__thiscall CEcoSector::SetGoodOffer(unsigned __int16 *this, int a2, int a3)
void  CEcoSector::SetGoodOffer(int,int) {
  
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( debug && DEBUG_FLAGS[dword_3EFEB2C] )
    BBSupportTracePrintF(0, "SetGoodOffer: es: %u good: %u, pileId: %u", this[8], a2, a3);
  v8 = CPileMgr::operator[](a3);
  if ( IEntity::FlagBits(v8, Offered)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1250, "!rPile.FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  for ( i = this[a2 + 152]; i; i = IAnimatedEntity::Next(v3) )
  {
    if ( i == a3 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1258, "iActPile != _iPileId") == 1 )
      __debugbreak();
    v3 = CPileMgr::operator[](i);
  }
  v4 = CPileMgr::operator[](a3);
  IAnimatedEntity::SetPrevious((IAnimatedEntity *)v4, 0);
  v9 = this[a2 + 152];
  if ( this[a2 + 152] )
  {
    v5 = CPileMgr::operator[](v9);
    IAnimatedEntity::SetPrevious((IAnimatedEntity *)v5, a3);
  }
  v6 = CPileMgr::operator[](a3);
  IAnimatedEntity::SetNext(v6, v9);
  this[a2 + 152] = a3;
  return IEntity::SetFlagBits(v8, Offered);
}


// address=[0x142aa20]
// Decompiled from int __thiscall CEcoSector::GetPileOutOfOffer(CEcoSector *this, int a2, int a3)
void  CEcoSector::GetPileOutOfOffer(int,int) {
  
  int v3; // eax
  unsigned __int8 *v4; // eax
  __int16 v5; // si
  int v6; // eax
  unsigned __int8 *v7; // eax
  int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp-4h] [ebp-10h]
  unsigned __int8 *v12; // [esp+8h] [ebp-4h]

  if ( debug && DEBUG_FLAGS[dword_3EFEB2C] )
    BBSupportTracePrintF(0, "GetPileOutOfOffer: es: %u good: %u, pileId: %u", *((unsigned __int16 *)this + 8), a2, a3);
  v12 = CPileMgr::operator[](a3);
  if ( !IEntity::FlagBits(v12, Offered)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1310, "rActPile.FlagBits(ENTITY_FLAG_OFFERED)") == 1 )
  {
    __debugbreak();
  }
  if ( IAnimatedEntity::Previous(v12) )
  {
    v9 = IAnimatedEntity::Next(v12);
    v3 = IAnimatedEntity::Previous(v12);
    v4 = CPileMgr::operator[](v3);
    IAnimatedEntity::SetNext(v4, v9);
  }
  else
  {
    v5 = IAnimatedEntity::Next(v12);
    *((_WORD *)this + (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 60))(v12) + 152) = v5;
  }
  if ( IAnimatedEntity::Next(v12) )
  {
    v10 = IAnimatedEntity::Previous(v12);
    v6 = IAnimatedEntity::Next(v12);
    v7 = CPileMgr::operator[](v6);
    IAnimatedEntity::SetPrevious((IAnimatedEntity *)v7, v10);
  }
  IAnimatedEntity::SetNext(v12, 0);
  IAnimatedEntity::SetPrevious((IAnimatedEntity *)v12, 0);
  return IEntity::ClearFlagBits(v12, Offered);
}


// address=[0x142ab50]
// Decompiled from int __stdcall CEcoSector::RequestGood(__int16 a1, int a2)
void  CEcoSector::RequestGood(int,enum PILE_TYPES) {
  
  __int16 v3; // [esp+6h] [ebp-2h] BYREF

  v3 = a1;
  std::vector<std::deque<unsigned short>>::operator[](a2);
  return std::deque<unsigned short>::push_back(&v3);
}


// address=[0x142ab90]
// Decompiled from int __thiscall CEcoSector::CleanUpBuildingNeed(void *this, int a2)
void  CEcoSector::CleanUpBuildingNeed(int) {
  
  int result; // eax
  int v3; // eax
  char v4; // [esp-Ch] [ebp-7Ch] BYREF
  int v5; // [esp-8h] [ebp-78h]
  _BYTE *v6; // [esp-4h] [ebp-74h]
  _BYTE v7[12]; // [esp+4h] [ebp-6Ch] BYREF
  _BYTE v8[12]; // [esp+10h] [ebp-60h] BYREF
  _BYTE v9[12]; // [esp+1Ch] [ebp-54h] BYREF
  _BYTE v10[12]; // [esp+28h] [ebp-48h] BYREF
  int v11; // [esp+34h] [ebp-3Ch]
  int v12; // [esp+38h] [ebp-38h]
  char *v13; // [esp+3Ch] [ebp-34h]
  int v14; // [esp+40h] [ebp-30h]
  int v15; // [esp+44h] [ebp-2Ch]
  std::_Iterator_base12 *v16; // [esp+48h] [ebp-28h]
  std::_Iterator_base12 *v17; // [esp+4Ch] [ebp-24h]
  int v18; // [esp+50h] [ebp-20h]
  int v19; // [esp+54h] [ebp-1Ch]
  void *v20; // [esp+58h] [ebp-18h]
  int i; // [esp+5Ch] [ebp-14h]
  char v22; // [esp+63h] [ebp-Dh]
  int v23; // [esp+6Ch] [ebp-4h]

  v20 = this;
  if ( !a2 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2773, "_iBuildingId!=0") == 1 )
    __debugbreak();
  result = 0;
  for ( i = 0; i < 43; ++i )
  {
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v10);
    v23 = 0;
    v6 = v9;
    std::vector<std::deque<unsigned short>>::operator[](i);
    v19 = std::deque<unsigned short>::begin(v6);
    v18 = v19;
    LOBYTE(v23) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator=(v19);
    LOBYTE(v23) = 0;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
    v3 = std::vector<std::deque<unsigned short>>::operator[](i);
    v14 = std::deque<unsigned short>::size(v3);
    while ( 1 )
    {
      v6 = v8;
      std::vector<std::deque<unsigned short>>::operator[](i);
      v17 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v6);
      v16 = v17;
      LOBYTE(v23) = 2;
      v22 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v17);
      LOBYTE(v23) = 0;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v8);
      if ( !v22 )
        break;
      if ( *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v10) == a2 )
      {
        CTrace::Print("CleanUpBuildingNeed  erase building %u", a2);
        v13 = &v4;
        v15 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v10);
        v12 = v15;
        LOBYTE(v23) = 3;
        std::vector<std::deque<unsigned short>>::operator[](i);
        LOBYTE(v23) = 0;
        v11 = std::deque<unsigned short>::erase(v7, v4, v5, v6);
        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v7);
        break;
      }
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v10);
    }
    v23 = -1;
    result = std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v10);
  }
  return result;
}


// address=[0x142ad60]
// Decompiled from int __thiscall CEcoSector::RequestGoodToVehicle(CEcoSector *this, int a2, int a3)
int  CEcoSector::RequestGoodToVehicle(int,int) {
  
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  int v9; // [esp-4h] [ebp-4Ch]
  int v10; // [esp-4h] [ebp-4Ch]
  _BYTE v11[24]; // [esp+4h] [ebp-44h] BYREF
  CEntityEvent *v12; // [esp+1Ch] [ebp-2Ch]
  CEntityEvent *v13; // [esp+20h] [ebp-28h]
  int GoodOffer; // [esp+24h] [ebp-24h]
  int v15; // [esp+28h] [ebp-20h]
  CEcoSector *v16; // [esp+2Ch] [ebp-1Ch]
  _DWORD *v17; // [esp+30h] [ebp-18h]
  int NearestPile; // [esp+34h] [ebp-14h]
  int NearestSettler; // [esp+38h] [ebp-10h]
  int v20; // [esp+44h] [ebp-4h]

  v16 = this;
  v17 = (_DWORD *)CVehicleMgr::operator[](a2);
  GoodOffer = CEcoSector::GetGoodOffer(v16, a3);
  v9 = IEntity::Y(v17);
  v3 = IEntity::X(v17);
  NearestPile = CPileMgr::GetNearestPile((CPileMgr *)&g_cPileMgr, GoodOffer, v3, v9);
  if ( NearestPile <= 0 )
    return -1;
  v4 = CPileMgr::operator[](NearestPile);
  v10 = IEntity::Y(v4);
  v5 = CPileMgr::operator[](NearestPile);
  v6 = IEntity::X(v5);
  NearestSettler = CEcoSector::GetNearestSettler(v16, 1, v6, v10);
  if ( !NearestSettler )
    return -1;
  CEcoSector::GetSettlerOutOfOffer(v16, NearestSettler);
  v7 = CPileMgr::operator[](NearestPile);
  CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v7, NearestSettler, 1, 2);
  (*(void (__thiscall **)(_DWORD *, int))(*v17 + 164))(v17, NearestSettler);
  v15 = CSettlerMgr::operator[](NearestSettler);
  v13 = CEntityEvent::CEntityEvent((CEntityEvent *)v11, 0xBu, 0, 1, NearestPile, a2);
  v12 = v13;
  v20 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v15 + 80))(v15, v13);
  v20 = -1;
  CEntityEvent::~CEntityEvent(v11);
  return NearestSettler;
}


// address=[0x142aed0]
// Decompiled from char __thiscall CEcoSector::TransportGood(CEcoSector *this, int a2, int a3)
bool  CEcoSector::TransportGood(int,int) {
  
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // [esp-4h] [ebp-44h]
  int v7; // [esp-4h] [ebp-44h]
  _BYTE v8[24]; // [esp+4h] [ebp-3Ch] BYREF
  CEntityEvent *v9; // [esp+1Ch] [ebp-24h]
  CEntityEvent *v10; // [esp+20h] [ebp-20h]
  int v11; // [esp+24h] [ebp-1Ch]
  CEcoSector *v12; // [esp+28h] [ebp-18h]
  unsigned __int8 *v13; // [esp+2Ch] [ebp-14h]
  int NearestSettler; // [esp+30h] [ebp-10h]
  int v15; // [esp+3Ch] [ebp-4h]

  v12 = this;
  if ( a2 == a3 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1666, "_iSrcPileId!=_iDestPileId") == 1 )
    __debugbreak();
  if ( a2 == a3 )
    return 0;
  if ( !a2 || !a3 )
    return 0;
  v13 = CPileMgr::operator[](a2);
  v6 = IEntity::Y(v13);
  v4 = IEntity::X(v13);
  NearestSettler = CEcoSector::GetNearestSettler(v12, 1, v4, v6);
  if ( !NearestSettler )
    return 0;
  CEcoSector::GetSettlerOutOfOffer(v12, NearestSettler);
  v11 = CSettlerMgr::operator[](NearestSettler);
  v10 = CEntityEvent::CEntityEvent((CEntityEvent *)v8, 0xAu, 0, 0, a2, a3);
  v9 = v10;
  v15 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v11 + 80))(v11, v10);
  v15 = -1;
  CEntityEvent::~CEntityEvent(v8);
  CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v13, NearestSettler, 1, 2);
  v7 = NearestSettler;
  v5 = CPileMgr::operator[](a3);
  CPile::AttachAndIncAmountComing((CPile *)v5, v7);
  return 1;
}


// address=[0x142b020]
// Decompiled from char __thiscall CEcoSector::RequestSpace(CEcoSector *this, struct CPile *a2)
void  CEcoSector::RequestSpace(class CPile *) {
  
  int NearestStoragePile; // eax
  int v3; // eax
  int v6; // [esp+4h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3314, "_pPile != 0") == 1 )
    __debugbreak();
  LOBYTE(NearestStoragePile) = 0;
  if ( !a2 )
    return NearestStoragePile;
  NearestStoragePile = CEcoSector::GetNearestStoragePile(this, a2);
  v6 = NearestStoragePile;
  if ( !NearestStoragePile )
    return NearestStoragePile;
  v3 = IEntity::ID();
  LOBYTE(NearestStoragePile) = CEcoSector::TransportGood(this, v3, v6);
  return NearestStoragePile;
}


// address=[0x142b090]
// Decompiled from int __thiscall CEcoSector::GetFullPile(CEcoSector *this, int a2)
int  CEcoSector::GetFullPile(int) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp+0h] [ebp-8h]

  v2 = std::vector<std::vector<unsigned short>>::operator[](a2);
  if ( !std::vector<unsigned short>::size(v2) )
    return 0;
  std::vector<std::vector<unsigned short>>::operator[](a2);
  v5 = *(unsigned __int16 *)std::vector<unsigned short>::back();
  v3 = std::vector<std::vector<unsigned short>>::operator[](a2);
  std::vector<unsigned short>::pop_back(v3);
  return v5;
}


// address=[0x142b100]
// Decompiled from char __thiscall CEcoSector::RegisterFreeStoragePile(CEcoSector *this, int a2, int a3)
bool  CEcoSector::RegisterFreeStoragePile(int,int) {
  
  _DWORD v4[2]; // [esp+0h] [ebp-10h] BYREF
  int RegisteredFreeStoragePile; // [esp+8h] [ebp-8h]
  CEcoSector *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  RegisteredFreeStoragePile = CEcoSector::GetRegisteredFreeStoragePile(this, a2, a3);
  if ( RegisteredFreeStoragePile != -1 )
    return 0;
  v4[0] = a2;
  v4[1] = a3;
  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::push_back(v4);
  return 1;
}


// address=[0x142b150]
// Decompiled from char __thiscall CEcoSector::UnregisterFreeStoragePile(CEcoSector *this, int a2, int a3)
bool  CEcoSector::UnregisterFreeStoragePile(int,int) {
  
  int v4; // eax
  int *v5; // eax
  int v6; // esi
  int v7; // edi
  _DWORD *v8; // eax
  int RegisteredFreeStoragePile; // [esp+8h] [ebp-8h]

  RegisteredFreeStoragePile = CEcoSector::GetRegisteredFreeStoragePile(this, a2, a3);
  if ( RegisteredFreeStoragePile == -1 )
    return 0;
  v4 = std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::size((char *)this + 424);
  v5 = (int *)std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::operator[](v4 - 1);
  v6 = *v5;
  v7 = v5[1];
  v8 = (_DWORD *)std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::operator[](RegisteredFreeStoragePile);
  *v8 = v6;
  v8[1] = v7;
  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::pop_back((char *)this + 424);
  return 1;
}


// address=[0x142b1d0]
// Decompiled from char __thiscall CEcoSector::RegisterGoodStoragePile(CEcoSector *this, int a2, int a3, int a4)
bool  CEcoSector::RegisterGoodStoragePile(int,int,int) {
  
  _DWORD v5[3]; // [esp+8h] [ebp-10h] BYREF

  if ( CEcoSector::GetRegisteredGoodStoragePile(this, a2, a3, a4) != -1 )
    return 0;
  v5[0] = a2;
  v5[1] = a3;
  v5[2] = a4;
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::push_back(v5);
  return 1;
}


// address=[0x142b240]
// Decompiled from char __thiscall CEcoSector::UnregisterGoodStoragePile(CEcoSector *this, int a2, int a3, int a4)
bool  CEcoSector::UnregisterGoodStoragePile(int,int,int) {
  
  int v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int RegisteredGoodStoragePile; // [esp+4h] [ebp-8h]

  RegisteredGoodStoragePile = CEcoSector::GetRegisteredGoodStoragePile(this, a2, a3, a4);
  if ( RegisteredGoodStoragePile == -1 )
    return 0;
  v5 = std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::size((char *)this + 440);
  v6 = (_DWORD *)std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::operator[](v5 - 1);
  v7 = (_DWORD *)std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::operator[](RegisteredGoodStoragePile);
  *v7 = *v6;
  v7[1] = v6[1];
  v7[2] = v6[2];
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::pop_back((char *)this + 440);
  return 1;
}


// address=[0x142b2d0]
// Decompiled from char __thiscall CEcoSector::RegisterGoodStorage(CEcoSector *this, int a2, int a3)
bool  CEcoSector::RegisterGoodStorage(int,int) {
  
  _DWORD v4[2]; // [esp+0h] [ebp-10h] BYREF
  int RegisteredGoodStorage; // [esp+8h] [ebp-8h]
  CEcoSector *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  RegisteredGoodStorage = CEcoSector::GetRegisteredGoodStorage(this, a2, a3);
  if ( RegisteredGoodStorage != -1 )
    return 0;
  v4[0] = a2;
  v4[1] = a3;
  std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::push_back(v4);
  return 1;
}


// address=[0x142b320]
// Decompiled from char __thiscall CEcoSector::UnregisterGoodStorage(CEcoSector *this, int a2, int a3)
bool  CEcoSector::UnregisterGoodStorage(int,int) {
  
  int v4; // eax
  int *v5; // eax
  int v6; // esi
  int v7; // edi
  _DWORD *v8; // eax
  int RegisteredGoodStorage; // [esp+8h] [ebp-8h]

  RegisteredGoodStorage = CEcoSector::GetRegisteredGoodStorage(this, a2, a3);
  if ( RegisteredGoodStorage == -1 )
    return 0;
  v4 = std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::size((char *)this + 456);
  v5 = (int *)std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](v4 - 1);
  v6 = *v5;
  v7 = v5[1];
  v8 = (_DWORD *)std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](RegisteredGoodStorage);
  *v8 = v6;
  v8[1] = v7;
  std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::pop_back((char *)this + 456);
  return 1;
}


// address=[0x142b3a0]
// Decompiled from int __thiscall CEcoSector::GetNearestStoragePile(CEcoSector *this, struct CPile *a2)
int  CEcoSector::GetNearestStoragePile(class CPile &) {
  
  int v2; // esi
  int *v3; // eax
  int v4; // eax
  Grid *v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp-Ch] [ebp-40h]
  int v10; // [esp-8h] [ebp-3Ch]
  int v11; // [esp-4h] [ebp-38h]
  CStorageBuildingRole *v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+8h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-28h]
  unsigned __int8 *v15; // [esp+10h] [ebp-24h]
  CStorageBuildingRole *v16; // [esp+14h] [ebp-20h]
  unsigned __int8 *BuildingPtr; // [esp+18h] [ebp-1Ch]
  unsigned __int8 *v18; // [esp+18h] [ebp-1Ch]
  int v19; // [esp+1Ch] [ebp-18h]
  int NextFreePile; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  int v22; // [esp+28h] [ebp-Ch]

  v13 = 0xFFFF;
  v22 = 0;
  v19 = 0;
  for ( i = 0; i < std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::size((char *)this + 456); ++i )
  {
    v2 = std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](i);
    if ( *(_DWORD *)(v2 + 4) == (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2) )
    {
      v3 = (int *)std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](i);
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v3);
      if ( !BuildingPtr && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1516, "pBuilding") == 1 )
        __debugbreak();
      v16 = (CStorageBuildingRole *)CBuilding::Role(BuildingPtr);
      v4 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
      NextFreePile = (*(int (__thiscall **)(CStorageBuildingRole *, int))(*(_DWORD *)v16 + 56))(v16, v4);
      if ( NextFreePile || (NextFreePile = CStorageBuildingRole::GetNextFreePile(v16)) != 0 )
      {
        v15 = CPileMgr::operator[](NextFreePile);
        v11 = IEntity::Y(v15);
        v10 = IEntity::X(v15);
        v9 = IEntity::Y(a2);
        v5 = (Grid *)IEntity::X(a2);
        v14 = Grid::Distance(v5, v9, v10, v11);
        if ( v14 < v13 )
        {
          v13 = v14;
          v22 = NextFreePile;
          v19 = *(_DWORD *)std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](i);
        }
      }
    }
  }
  if ( !v22 || CEcoSector::GetRegisteredFreeStoragePile(this, v19, v22) == -1 )
    return v22;
  CEcoSector::UnregisterFreeStoragePile(this, v19, v22);
  v6 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
  CEcoSector::RegisterGoodStoragePile(this, v19, v22, v6);
  v18 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v19);
  if ( !v18 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1550, "pBuilding") == 1 )
    __debugbreak();
  v12 = (CStorageBuildingRole *)CBuilding::Role(v18);
  v7 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
  if ( !CStorageBuildingRole::ReserveFreePile(v12, v7, v22)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 1553, "bRes == true") == 1 )
  {
    __debugbreak();
  }
  return v22;
}


// address=[0x142b600]
// Decompiled from void __thiscall CEcoSector::ChangeMinMaxValues(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangeMinMaxValues(int,int) {
  
  int v3; // [esp+8h] [ebp-8h]

  if ( a2 == 1 )
  {
    v3 = a3 + *((unsigned __int16 *)this + 16);
    if ( v3 > 5 )
    {
      if ( v3 < 999 )
      {
        if ( v3 > CEcoSector::NrOfSettler(this, 1) )
          *((_WORD *)this + 16) = CEcoSector::NrOfSettler(this, 1);
        else
          *((_WORD *)this + 16) = v3;
      }
      else
      {
        *((_WORD *)this + 16) = 999;
      }
    }
    else
    {
      *((_WORD *)this + 16) = 5;
    }
  }
  else if ( a2 > 1 && a2 <= 3 )
  {
    CEcoSector::ChangeWorkerDeltaAmount(this, a2, a3);
  }
  else if ( BBSupportDbgReportF(2, "Logic\\EcoSector.cpp", 2526, "Wrong type for ChangeMinMaxValues") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x142b6e0]
// Decompiled from CEcoSector *__thiscall CEcoSector::SetExtraMinCarrierForRecruitment(CEcoSector *this, int a2)
void  CEcoSector::SetExtraMinCarrierForRecruitment(int) {
  
  CEcoSector *result; // eax

  if ( a2 >= 0 )
  {
    if ( a2 > 99 )
      LOBYTE(a2) = 99;
  }
  else
  {
    LOBYTE(a2) = 0;
  }
  result = this;
  *((_BYTE *)this + 30) = a2;
  return result;
}


// address=[0x142b720]
// Decompiled from bool __thiscall CEcoSector::CarrierForJobOrderAvailable(CEcoSector *this, bool a2)
bool  CEcoSector::CarrierForJobOrderAvailable(bool) {
  
  int v3; // [esp+14h] [ebp-8h]

  if ( a2 )
    v3 = *((unsigned __int8 *)this + 30);
  else
    v3 = 0;
  return *((unsigned __int16 *)this + 19) > v3 + *((unsigned __int16 *)this + 17) + *((unsigned __int16 *)this + 16);
}


// address=[0x142b7a0]
// Decompiled from int __thiscall CEcoSector::WorkerDeltaAmount(CEcoSector *this, int a2)
int  CEcoSector::WorkerDeltaAmount(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; dword_3D894C8[2 * i] && dword_3D894C8[2 * i] != a2; ++i )
    ;
  if ( dword_3D894CC[2 * i] == -1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2440, "g_vWorkerProductionMap[k].m_iIdx != -1") == 1 )
  {
    __debugbreak();
  }
  if ( dword_3D894CC[2 * i] == -1 )
    return 0;
  else
    return *((char *)this + dword_3D894CC[2 * i] + 677);
}


// address=[0x142b840]
// Decompiled from int __thiscall CEcoSector::ChangeWorkerDeltaAmount(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangeWorkerDeltaAmount(int,int) {
  
  int result; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-14h]
  _BYTE *v6; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; dword_3D894C8[2 * i] && dword_3D894C8[2 * i] != a2; ++i )
    ;
  if ( dword_3D894CC[2 * i] == -1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2466, "g_vWorkerProductionMap[k].m_iIdx != -1") == 1 )
  {
    __debugbreak();
  }
  result = i;
  if ( dword_3D894CC[2 * i] == -1 )
    return result;
  v6 = (char *)this + dword_3D894CC[2 * i] + 677;
  v5 = (char)*v6;
  v4 = CEcoSector::NrOfSettler(this, a2);
  result = CEcoSector::ChangeValue(this, v4, v5, a3);
  *v6 = result;
  return result;
}


// address=[0x142b900]
// Decompiled from int __thiscall CEcoSector::SpecialistWishes(CEcoSector *this, int a2)
int  CEcoSector::SpecialistWishes(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; dword_3D89498[2 * i] && dword_3D89498[2 * i] != a2; ++i )
    ;
  if ( dword_3D8949C[2 * i] == -1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2114, "g_vSpecialistProductionMap[k].m_iIdx != -1") == 1 )
  {
    __debugbreak();
  }
  if ( dword_3D8949C[2 * i] == -1 )
    return 0;
  else
    return *((char *)this + dword_3D8949C[2 * i] + 672);
}


// address=[0x142b9a0]
// Decompiled from int __thiscall CEcoSector::ChangeSpecialistWish(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangeSpecialistWish(int,int) {
  
  int result; // eax
  int v4; // eax
  int NumberOfSettlers; // eax
  int v6; // [esp-Ch] [ebp-18h]
  int v7; // [esp-8h] [ebp-14h]
  _BYTE *v8; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; dword_3D89498[2 * i] && dword_3D89498[2 * i] != a2; ++i )
    ;
  if ( dword_3D8949C[2 * i] == -1
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2139, "g_vSpecialistProductionMap[k].m_iIdx != -1") == 1 )
  {
    __debugbreak();
  }
  result = i;
  if ( dword_3D8949C[2 * i] == -1 )
    return result;
  v8 = (char *)this + dword_3D8949C[2 * i] + 672;
  v7 = (char)*v8;
  v6 = dword_3D89498[2 * i];
  v4 = CEcoSector::Owner(this);
  NumberOfSettlers = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, v4, v6);
  result = CEcoSector::ChangeValue(this, NumberOfSettlers, v7, a3);
  *v8 = result;
  return result;
}


// address=[0x142ba70]
// Decompiled from void __thiscall CEcoSector::InitTransport(CEcoSector *this)
void  CEcoSector::InitTransport(void) {
  
  int Priority; // eax
  int v2; // eax
  int *v3; // eax
  unsigned int *v4; // eax
  int v5; // eax
  _DWORD *v6; // eax
  unsigned __int16 *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  unsigned __int16 *v11; // eax
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // esi
  unsigned __int8 *v16; // eax
  int v17; // esi
  unsigned __int8 *v18; // eax
  int v19; // eax
  int v20; // eax
  CBuilding *v21; // eax
  CBuilding *v22; // eax
  int v23; // esi
  unsigned __int8 *v24; // eax
  int v25; // eax
  unsigned __int16 *v26; // eax
  char v27; // [esp-Ch] [ebp-680h] BYREF
  int v28; // [esp-8h] [ebp-67Ch]
  _BYTE *v29; // [esp-4h] [ebp-678h]
  int v30; // [esp+0h] [ebp-674h]
  int v31; // [esp+4h] [ebp-670h]
  _BYTE v32[12]; // [esp+8h] [ebp-66Ch] BYREF
  _BYTE v33[12]; // [esp+14h] [ebp-660h] BYREF
  _BYTE v34[12]; // [esp+20h] [ebp-654h] BYREF
  _BYTE v35[12]; // [esp+2Ch] [ebp-648h] BYREF
  _BYTE v36[12]; // [esp+38h] [ebp-63Ch] BYREF
  _BYTE v37[12]; // [esp+44h] [ebp-630h] BYREF
  _BYTE v38[12]; // [esp+50h] [ebp-624h] BYREF
  _BYTE v39[12]; // [esp+5Ch] [ebp-618h] BYREF
  _BYTE v40[12]; // [esp+68h] [ebp-60Ch] BYREF
  _BYTE v41[12]; // [esp+74h] [ebp-600h] BYREF
  char *v42; // [esp+80h] [ebp-5F4h]
  int v43; // [esp+84h] [ebp-5F0h]
  int v44; // [esp+88h] [ebp-5ECh]
  int v45; // [esp+8Ch] [ebp-5E8h]
  int v46; // [esp+90h] [ebp-5E4h]
  std::_Iterator_base12 *v47; // [esp+94h] [ebp-5E0h]
  int v48; // [esp+98h] [ebp-5DCh]
  int v49; // [esp+9Ch] [ebp-5D8h]
  int v50; // [esp+A0h] [ebp-5D4h]
  _BYTE v51[12]; // [esp+A4h] [ebp-5D0h] BYREF
  struct std::_Iterator_base12 *v52; // [esp+B0h] [ebp-5C4h]
  struct std::_Iterator_base12 *v53; // [esp+B4h] [ebp-5C0h]
  int v54; // [esp+B8h] [ebp-5BCh]
  std::_Iterator_base12 *v55; // [esp+BCh] [ebp-5B8h]
  std::_Iterator_base12 *v56; // [esp+C0h] [ebp-5B4h]
  int PileIdWithNeedForGood; // [esp+C4h] [ebp-5B0h]
  int v58; // [esp+C8h] [ebp-5ACh]
  CPile *v59; // [esp+CCh] [ebp-5A8h]
  int GoodOffer; // [esp+D0h] [ebp-5A4h]
  std::_Iterator_base12 *v61; // [esp+D4h] [ebp-5A0h]
  std::_Iterator_base12 *v62; // [esp+D8h] [ebp-59Ch]
  int v63; // [esp+DCh] [ebp-598h]
  int v64; // [esp+E0h] [ebp-594h]
  std::_Iterator_base12 *v65; // [esp+E4h] [ebp-590h]
  _BYTE v66[16]; // [esp+E8h] [ebp-58Ch] BYREF
  int v67; // [esp+F8h] [ebp-57Ch]
  unsigned __int8 *v68; // [esp+FCh] [ebp-578h]
  int PileIdWithGood; // [esp+100h] [ebp-574h]
  int v70; // [esp+104h] [ebp-570h]
  BOOL v71; // [esp+108h] [ebp-56Ch]
  BOOL v72; // [esp+10Ch] [ebp-568h]
  BOOL v73; // [esp+110h] [ebp-564h]
  unsigned int v74; // [esp+114h] [ebp-560h]
  int v75; // [esp+118h] [ebp-55Ch]
  _BYTE v76[12]; // [esp+11Ch] [ebp-558h] BYREF
  unsigned int v77; // [esp+128h] [ebp-54Ch]
  unsigned int v78; // [esp+12Ch] [ebp-548h]
  unsigned __int8 *BuildingPtr; // [esp+130h] [ebp-544h]
  int NumberOfSupplyBuildings; // [esp+134h] [ebp-540h]
  int v81; // [esp+138h] [ebp-53Ch]
  int v82; // [esp+13Ch] [ebp-538h]
  int v83; // [esp+140h] [ebp-534h]
  int v84; // [esp+144h] [ebp-530h]
  unsigned int v85; // [esp+148h] [ebp-52Ch]
  CBuilding *v86; // [esp+14Ch] [ebp-528h]
  int NearestPile; // [esp+150h] [ebp-524h]
  char v88; // [esp+155h] [ebp-51Fh]
  bool v89; // [esp+156h] [ebp-51Eh]
  bool v90; // [esp+157h] [ebp-51Dh]
  int v91; // [esp+158h] [ebp-51Ch]
  bool v92; // [esp+15Eh] [ebp-516h]
  char v93; // [esp+15Fh] [ebp-515h]
  int v94; // [esp+160h] [ebp-514h]
  int v95; // [esp+164h] [ebp-510h]
  int i; // [esp+168h] [ebp-50Ch]
  char v97; // [esp+16Fh] [ebp-505h]
  int j; // [esp+170h] [ebp-504h]
  char v99; // [esp+177h] [ebp-4FDh]
  CEcoSector *v100; // [esp+178h] [ebp-4FCh]
  char v101; // [esp+17Fh] [ebp-4F5h]
  int v102; // [esp+180h] [ebp-4F4h]
  _DWORD v103[300]; // [esp+184h] [ebp-4F0h]
  _DWORD v104[12]; // [esp+634h] [ebp-40h] BYREF
  int v105; // [esp+670h] [ebp-4h]

  v100 = this;
  v91 = 0;
  v102 = 0;
  v82 = 1;
  v101 = 0;
  while ( v82 < 43 )
  {
    v93 = 0;
    if ( v102 != 10 || !v101 )
      v102 = 1;
    v97 = 0;
    while ( !v97 && v102 < 43 )
    {
      Priority = CGoodTransportPriority::GetPriority((char *)v100 + 572, v102);
      if ( Priority == v82 )
        v97 = 1;
      else
        ++v102;
    }
    if ( v97 )
    {
      if ( v102 < 43 )
      {
        v2 = std::vector<std::deque<unsigned short>>::operator[](v102);
        if ( std::deque<unsigned short>::size(v2) )
        {
          NumberOfSupplyBuildings = CBuildingSupplyPriority::GetNumberOfSupplyBuildings((char *)v100 + 556, v102, v104);
          v84 = -1;
          v85 = -1;
          v77 = 0;
          v29 = v41;
          std::vector<std::deque<unsigned short>>::operator[](v102);
          v53 = (struct std::_Iterator_base12 *)std::deque<unsigned short>::begin(v29);
          v52 = v53;
          v105 = 0;
          std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v53);
          LOBYTE(v105) = 2;
          std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v41);
          if ( NumberOfSupplyBuildings )
          {
            std::vector<int>::vector<int>(v66);
            LOBYTE(v105) = 3;
            std::vector<int>::resize(NumberOfSupplyBuildings);
            v77 = -1;
            for ( i = 0; i < NumberOfSupplyBuildings; ++i )
            {
              v78 = v104[2 * i];
              v93 = 1;
              *(_DWORD *)std::vector<int>::operator[](i) = -1;
              if ( i < NumberOfSupplyBuildings )
              {
                if ( !v104[2 * i + 1] )
                  goto LABEL_25;
                if ( v78 > 0x2A
                  && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3032, "dp_type>=0 && dp_type<=DP_MAX") == 1 )
                {
                  __debugbreak();
                }
                v67 = v104[2 * i + 1];
                if ( v67 )
                {
                  v50 = ((*((unsigned __int16 *)v100 + v78 + 236) << 8) + 128) / v67;
                  v3 = (int *)std::vector<int>::operator[](i);
                  *v3 = v50;
                }
                else
                {
LABEL_25:
                  *(_DWORD *)std::vector<int>::operator[](i) = -1;
                }
              }
              v4 = (unsigned int *)std::vector<int>::operator[](i);
              if ( *v4 < v77 && *(_DWORD *)std::vector<int>::operator[](i) != -1 )
              {
                v99 = 0;
                v75 = v104[2 * i];
                v29 = v40;
                std::vector<std::deque<unsigned short>>::operator[](v102);
                v49 = std::deque<unsigned short>::begin(v29);
                v48 = v49;
                LOBYTE(v105) = 4;
                std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator=(v49);
                LOBYTE(v105) = 3;
                std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v40);
                v81 = *(unsigned __int16 *)std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v76);
                v5 = std::vector<std::deque<unsigned short>>::operator[](v102);
                v45 = std::deque<unsigned short>::size(v5);
                while ( 1 )
                {
                  v29 = v39;
                  std::vector<std::deque<unsigned short>>::operator[](v102);
                  v47 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v29);
                  v65 = v47;
                  LOBYTE(v105) = 5;
                  v91 |= 1u;
                  v73 = (unsigned __int8)std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v47)
                     && !v99;
                  v90 = v73;
                  v105 = 3;
                  if ( (v91 & 1) != 0 )
                  {
                    v91 &= ~1u;
                    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v39);
                  }
                  if ( !v90 )
                    break;
                  v81 = *(unsigned __int16 *)std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v76);
                  if ( v75 == 84
                    && (v29 = (_BYTE *)_enc_textbss_begin,
                        v6 = (_DWORD *)CBuildingMgr::operator[](v81),
                        IEntity::FlagBits(v6, (EntityFlag)v29)) )
                  {
                    v99 = 1;
                  }
                  else
                  {
                    v7 = (unsigned __int16 *)CBuildingMgr::operator[](v81);
                    v8 = IEntity::Type(v7);
                    if ( v8 == v75 )
                    {
                      v29 = (_BYTE *)_enc_textbss_begin;
                      v9 = (_DWORD *)CBuildingMgr::operator[](v81);
                      if ( IEntity::FlagBits(v9, (EntityFlag)v29) )
                        v99 = 1;
                    }
                  }
                  std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(
                    v38,
                    0);
                  std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v38);
                }
                if ( v99 )
                {
                  v77 = *(_DWORD *)std::vector<int>::operator[](i);
                  v85 = v78;
                  v84 = v75;
                }
              }
            }
            LOBYTE(v105) = 2;
            std::vector<int>::~vector<int>(v30, v31);
          }
          v43 = 100;
          v94 = 0;
          v29 = v37;
          std::vector<std::deque<unsigned short>>::operator[](v102);
          v64 = std::deque<unsigned short>::begin(v29);
          v63 = v64;
          LOBYTE(v105) = 6;
          std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator=(v64);
          LOBYTE(v105) = 2;
          std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v37);
          v95 = 0;
          while ( 1 )
          {
            v29 = v32;
            std::vector<std::deque<unsigned short>>::operator[](v102);
            v62 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v29);
            v61 = v62;
            LOBYTE(v105) = 7;
            v91 |= 2u;
            v72 = (unsigned __int8)std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v62)
               && v94 != 100;
            v89 = v72;
            v105 = 2;
            if ( (v91 & 2) != 0 )
            {
              v91 &= ~2u;
              std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v32);
            }
            if ( !v89 )
              break;
            v95 = *(unsigned __int16 *)std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v76);
            BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v95);
            if ( !BuildingPtr && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3128, "pBuilding!= NULL") == 1 )
              __debugbreak();
            if ( !BuildingPtr )
            {
              v105 = -1;
              std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v76);
              return;
            }
            v70 = IEntity::Type((unsigned __int16 *)BuildingPtr);
            v71 = IEntity::FlagBits(BuildingPtr, (EntityFlag)0x1000u) != 0;
            v92 = v71;
            if ( v84 == -1 && !v93 || v70 == 33 && v92 || v70 == 32 && v92 )
            {
              v103[v94++ + 200] = v95;
            }
            else if ( v84 == 84
                   && (v29 = (_BYTE *)_enc_textbss_begin,
                       v10 = (_DWORD *)CBuildingMgr::operator[](v95),
                       IEntity::FlagBits(v10, (EntityFlag)v29)) )
            {
              v103[v94++ + 200] = v95;
            }
            else
            {
              v11 = (unsigned __int16 *)CBuildingMgr::operator[](v95);
              v12 = IEntity::Type(v11);
              if ( v12 == v84 )
              {
                v29 = (_BYTE *)_enc_textbss_begin;
                v13 = (_DWORD *)CBuildingMgr::operator[](v95);
                if ( IEntity::FlagBits(v13, (EntityFlag)v29) )
                  v103[v94++ + 200] = v95;
              }
            }
            std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v36, 0);
            std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v36);
          }
          if ( v102 != 10 || v101 )
          {
            std::vector<std::deque<unsigned short>>::operator[](v102);
            std::deque<unsigned short>::clear(v30, v31);
          }
          if ( v94 )
          {
            NearestPile = 0;
            for ( j = 0; j < v94; ++j )
            {
              v95 = v103[j + 200];
              if ( v95 )
              {
                v86 = (CBuilding *)CBuildingMgr::operator[](v95);
                PileIdWithGood = CBuilding::GetPileIdWithGood(v86, v102);
                if ( PileIdWithGood )
                {
                  v59 = (CPile *)CPileMgr::operator[](PileIdWithGood);
                  GoodOffer = CEcoSector::GetGoodOffer(v100, v102);
                  v29 = (_BYTE *)IEntity::Y(v86);
                  v14 = IEntity::X(v86);
                  NearestPile = CPileMgr::GetNearestPile((CPileMgr *)&g_cPileMgr, GoodOffer, v14, (int)v29);
                  if ( NearestPile )
                  {
                    v15 = IEntity::Y(v86);
                    v16 = CPileMgr::operator[](NearestPile);
                    v29 = (_BYTE *)(v15 - IEntity::Y(v16));
                    v17 = IEntity::X(v86);
                    v18 = CPileMgr::operator[](NearestPile);
                    v19 = IEntity::X(v18);
                    v58 = Grid::Distance((Grid *)(v17 - v19), v29);
                    if ( (unsigned __int8)CBuilding::IsBuildUp(v86) == 1 )
                    {
                      v20 = CPile::CalcUrgent(v59);
                      v103[j + 100] = (v20 << 16) / v58;
                    }
                    else
                    {
                      v103[j + 100] = 0x10000;
                    }
                    v103[j] = NearestPile;
                  }
                  else
                  {
                    v103[j + 100] = 0;
                  }
                }
              }
              else
              {
                v103[j + 100] = 0;
              }
            }
            v74 = 0;
            for ( j = 0; j < v94; ++j )
            {
              if ( v103[j + 100] > v74 )
              {
                v29 = (_BYTE *)v102;
                v21 = (CBuilding *)CBuildingMgr::operator[](v103[j + 200]);
                PileIdWithNeedForGood = CBuilding::GetPileIdWithNeedForGood(v21, (int)v29);
                if ( PileIdWithNeedForGood == v103[j] )
                {
                  BBSupportTracePrintF(0, " ------------- Ilegal transport from pile A to pile A found");
                }
                else
                {
                  v74 = v103[j + 100];
                  NearestPile = v103[j];
                  v95 = v103[j + 200];
                }
              }
            }
            if ( v74 )
            {
              v29 = (_BYTE *)v102;
              v22 = (CBuilding *)CBuildingMgr::operator[](v95);
              v83 = CBuilding::GetPileIdWithNeedForGood(v22, (int)v29);
              v68 = CPileMgr::operator[](v83);
              v23 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v68 + 40))(v68);
              v24 = CPileMgr::operator[](v83);
              if ( CPile::AmountComing((CPile *)v24) + v23 < 8
                && v83
                && CEcoSector::TransportGood(v100, NearestPile, v83) == 1 )
              {
                if ( v102 == 10 && !v101 )
                {
                  v25 = std::vector<std::deque<unsigned short>>::operator[](v102);
                  if ( std::deque<unsigned short>::size(v25) )
                  {
                    v29 = v51;
                    std::vector<std::deque<unsigned short>>::operator[](v102);
                    std::deque<unsigned short>::begin(v29);
                    LOBYTE(v105) = 8;
                    while ( 1 )
                    {
                      v29 = v34;
                      std::vector<std::deque<unsigned short>>::operator[](v102);
                      v56 = (std::_Iterator_base12 *)std::deque<unsigned short>::end(v29);
                      v55 = v56;
                      LOBYTE(v105) = 9;
                      v88 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v56);
                      LOBYTE(v105) = 8;
                      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v34);
                      if ( !v88 )
                        break;
                      v26 = (unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v51);
                      if ( *v26 == v95 )
                      {
                        v42 = &v27;
                        v54 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>((struct std::_Iterator_base12 *)v51);
                        v46 = v54;
                        LOBYTE(v105) = 10;
                        std::vector<std::deque<unsigned short>>::operator[](v102);
                        LOBYTE(v105) = 8;
                        v44 = std::deque<unsigned short>::erase(v33, v27, v28, v29);
                        std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v33);
                        break;
                      }
                      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(
                        v35,
                        0);
                      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v35);
                    }
                    LOBYTE(v105) = 2;
                    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v51);
                  }
                }
                if ( v85 <= 0x29 )
                  ++*((_WORD *)v100 + v85 + 236);
              }
            }
          }
          v105 = -1;
          std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v76);
        }
      }
    }
    if ( v102 == 10 && !v101 )
    {
      v101 = 1;
    }
    else
    {
      if ( v102 == 10 )
      {
        std::vector<std::deque<unsigned short>>::operator[](10);
        std::deque<unsigned short>::clear(v30, v31);
      }
      ++v82;
      v101 = 0;
    }
  }
}


// address=[0x142c9d0]
// Decompiled from int CEcoSector::ResetGoodNeed()
void  CEcoSector::ResetGoodNeed(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 43; ++i )
    result = i + 1;
  return result;
}


// address=[0x142ca00]
// Decompiled from void __thiscall CEcoSector::RecruiteSpecialist(CEcoSector *this)
void  CEcoSector::RecruiteSpecialist(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // esi
  int v10; // eax
  int NextSettlerType; // eax
  int v12; // [esp-Ch] [ebp-C8h]
  int v13; // [esp-4h] [ebp-C0h]
  int v14; // [esp-4h] [ebp-C0h]
  int v15; // [esp-4h] [ebp-C0h]
  _BYTE v16[24]; // [esp+Ch] [ebp-B0h] BYREF
  _BYTE v17[24]; // [esp+24h] [ebp-98h] BYREF
  _BYTE v18[12]; // [esp+3Ch] [ebp-80h] BYREF
  _BYTE v19[12]; // [esp+48h] [ebp-74h] BYREF
  CEntityEvent *v20; // [esp+54h] [ebp-68h]
  CEntityEvent *v21; // [esp+58h] [ebp-64h]
  CEntityEvent *v22; // [esp+5Ch] [ebp-60h]
  CEntityEvent *v23; // [esp+60h] [ebp-5Ch]
  int v24; // [esp+64h] [ebp-58h]
  int GoodOffer; // [esp+68h] [ebp-54h]
  int SettlerInfo; // [esp+6Ch] [ebp-50h]
  int v27; // [esp+70h] [ebp-4Ch]
  int v28; // [esp+74h] [ebp-48h]
  BOOL v29; // [esp+78h] [ebp-44h]
  int v30; // [esp+7Ch] [ebp-40h]
  unsigned __int8 *SettlerPtr; // [esp+80h] [ebp-3Ch]
  int v32; // [esp+84h] [ebp-38h]
  CPropertySet *v33; // [esp+88h] [ebp-34h]
  int NearestPile; // [esp+8Ch] [ebp-30h]
  int i; // [esp+90h] [ebp-2Ch]
  _BYTE *v36; // [esp+94h] [ebp-28h]
  bool v37; // [esp+9Bh] [ebp-21h]
  _BYTE *v38; // [esp+9Ch] [ebp-20h]
  int v39; // [esp+A0h] [ebp-1Ch]
  int FirstSettlerId; // [esp+A4h] [ebp-18h]
  CEcoSector *v41; // [esp+A8h] [ebp-14h]
  char v42; // [esp+AFh] [ebp-Dh]
  int v43; // [esp+B8h] [ebp-4h]

  v41 = this;
  for ( i = 0; i < 5; ++i )
  {
    FirstSettlerId = 0;
    v39 = dword_3D89498[2 * i];
    v36 = (char *)v41 + i + 672;
    if ( *v36 )
    {
      if ( (char)*v36 >= 0 )
      {
        v30 = *((char *)v41 + i + 672);
        v3 = CInputProcessor::Selection();
        v29 = std::vector<unsigned short>::size(v3) == 0;
        v37 = v29;
        while ( v30 > 0 )
        {
          v4 = CEcoSector::MinCarrier(v41);
          v5 = CEcoSector::NrOfSettler(v41, 1);
          if ( v4 >= v5 - CEcoSector::NumberOfCarriersWithJobOrder(v41) )
            return;
          NearestPile = 0;
          FirstSettlerId = *((unsigned __int16 *)v41 + 86);
          if ( FirstSettlerId )
          {
            v38 = (_BYTE *)CSettlerMgr::operator[](FirstSettlerId);
            v14 = v39;
            v6 = IEntity::Race(v38);
            SettlerInfo = CSettlerMgr::GetSettlerInfo(v6, v14);
            v28 = *(unsigned __int8 *)(SettlerInfo + 5);
            if ( v28 )
            {
              GoodOffer = CEcoSector::GetGoodOffer(v41, v28);
              v15 = IEntity::Y(v38);
              v7 = IEntity::X(v38);
              NearestPile = CPileMgr::GetNearestPile((CPileMgr *)&g_cPileMgr, GoodOffer, v7, v15);
              if ( !NearestPile )
                break;
              v12 = IEntity::ID();
              v8 = CPileMgr::operator[](NearestPile);
              CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v8, v12, 1, 2);
            }
            v9 = *((unsigned __int8 *)v41 + 18);
            if ( v9 == CPlayerManager::GetLocalPlayerId() )
            {
              if ( v37 )
              {
                CInputProcessor::AddToSelection(FirstSettlerId);
              }
              else
              {
                v42 = 1;
                v10 = CInputProcessor::Selection();
                if ( !std::vector<unsigned short>::size(v10)
                  && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2306, "g_cInputProcessor.Selection().size() != 0") == 1 )
                {
                  __debugbreak();
                }
                CInputProcessor::Selection();
                std::vector<unsigned short>::begin(v19);
                v43 = 0;
                CInputProcessor::Selection();
                std::vector<unsigned short>::end(v18);
                LOBYTE(v43) = 1;
                while ( (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v18) )
                {
                  v24 = *(unsigned __int16 *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator*(v19);
                  SettlerPtr = CSettlerMgr::GetSettlerPtr(v24);
                  if ( !SettlerPtr )
                  {
                    v42 = 0;
                    break;
                  }
                  if ( IEntity::Type((unsigned __int16 *)SettlerPtr) != 1
                    || (NextSettlerType = CSettler::GetNextSettlerType(SettlerPtr), NextSettlerType != v39) )
                  {
                    v42 = 0;
                    break;
                  }
                  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::operator++(v19);
                }
                if ( v42 == 1 )
                  CInputProcessor::AddToSelection(FirstSettlerId);
                LOBYTE(v43) = 0;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v18);
                v43 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned short>>>(v19);
              }
            }
            CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v41, FirstSettlerId, v39);
            v32 = v39 - 46;
            switch ( v39 )
            {
              case '.':
              case '/':
              case '1':
              case '2':
                if ( !NearestPile && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2349, "bestpile != 0") == 1 )
                  __debugbreak();
                v23 = CEntityEvent::CEntityEvent((CEntityEvent *)v17, 0x15u, 0, v39, NearestPile, 0);
                v22 = v23;
                v43 = 2;
                (*(void (__thiscall **)(_BYTE *, CEntityEvent *))(*(_DWORD *)v38 + 80))(v38, v23);
                v43 = -1;
                CEntityEvent::~CEntityEvent(v17);
                break;
              default:
                v21 = CEntityEvent::CEntityEvent((CEntityEvent *)v16, 0x14u, 0, v39, 0, 0);
                v20 = v21;
                v43 = 3;
                (*(void (__thiscall **)(_BYTE *, CEntityEvent *))(*(_DWORD *)v38 + 80))(v38, v21);
                v43 = -1;
                CEntityEvent::~CEntityEvent(v16);
                break;
            }
            CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 18, v39);
            CEcoSector::ChangeSpecialistWish(v41, v39, -1);
          }
          --v30;
        }
      }
      else
      {
        v13 = v39;
        v1 = CEcoSector::Owner(v41);
        FirstSettlerId = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v1, v13);
        while ( FirstSettlerId && (char)*v36 < 0 )
        {
          v33 = (CPropertySet *)CSettlerMgr::operator[](FirstSettlerId);
          FirstSettlerId = IAnimatedEntity::Next(v33);
          v2 = IEntity::WorldIdx();
          v27 = CWorldManager::EcoSectorId(v2);
          if ( v27 == *((unsigned __int16 *)v41 + 8) && !IEntity::FlagBits(v33, OnBoard) )
          {
            CSettler::ChangeType(v33, 1, 1, 0);
            ++*v36;
          }
        }
        *v36 = 0;
      }
    }
  }
}


// address=[0x142ced0]
// Decompiled from void __thiscall CEcoSector::RecruiteWorker(CEcoSector *this)
void  CEcoSector::RecruiteWorker(void) {
  
  int v1; // esi
  int v2; // edi
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // [esp-Ch] [ebp-6Ch]
  int v7; // [esp-4h] [ebp-64h]
  int v8; // [esp-4h] [ebp-64h]
  _BYTE v9[24]; // [esp+Ch] [ebp-54h] BYREF
  CEntityEvent *v10; // [esp+24h] [ebp-3Ch]
  CEntityEvent *v11; // [esp+28h] [ebp-38h]
  int GoodOffer; // [esp+2Ch] [ebp-34h]
  int SettlerInfo; // [esp+30h] [ebp-30h]
  CPropertySet *v14; // [esp+34h] [ebp-2Ch]
  int v15; // [esp+38h] [ebp-28h]
  int NearestPile; // [esp+3Ch] [ebp-24h]
  _BYTE *v17; // [esp+40h] [ebp-20h]
  int i; // [esp+44h] [ebp-1Ch]
  int v19; // [esp+48h] [ebp-18h]
  int v20; // [esp+4Ch] [ebp-14h]
  CEcoSector *v21; // [esp+50h] [ebp-10h]
  int v22; // [esp+5Ch] [ebp-4h]

  v21 = this;
  v20 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( *((_BYTE *)v21 + i + 677) )
    {
      v19 = dword_3D894C8[2 * i];
      if ( *((char *)v21 + i + 677) >= 0 )
      {
        v1 = CEcoSector::MinCarrier(v21);
        v2 = CEcoSector::NrOfSettler(v21, 1);
        if ( v1 >= v2 - CEcoSector::NumberOfCarriersWithJobOrder(v21) )
          return;
        NearestPile = 0;
        v20 = *((unsigned __int16 *)v21 + 86);
        if ( v20 )
        {
          v17 = (_BYTE *)CSettlerMgr::operator[](v20);
          v7 = v19;
          v3 = IEntity::Race(v17);
          SettlerInfo = CSettlerMgr::GetSettlerInfo(v3, v7);
          v15 = *(unsigned __int8 *)(SettlerInfo + 5);
          if ( v15 )
          {
            GoodOffer = CEcoSector::GetGoodOffer(v21, v15);
            v8 = IEntity::Y(v17);
            v4 = IEntity::X(v17);
            NearestPile = CPileMgr::GetNearestPile((CPileMgr *)&g_cPileMgr, GoodOffer, v4, v8);
            if ( !NearestPile )
              continue;
            v6 = IEntity::ID();
            v5 = CPileMgr::operator[](NearestPile);
            CPile::AttachAndIncAmountLeaving((unsigned __int16 *)v5, v6, 1, 2);
          }
          CEcoSector::GetCarrierOutOfOfferAndSetNextSettlerType(v21, v20, v19);
          v11 = CEntityEvent::CEntityEvent((CEntityEvent *)v9, 0x15u, 0, v19, NearestPile, 0);
          v10 = v11;
          v22 = 0;
          (*(void (__thiscall **)(_BYTE *, CEntityEvent *))(*(_DWORD *)v17 + 80))(v17, v11);
          v22 = -1;
          CEntityEvent::~CEntityEvent(v9);
          CGameScriptManager::SendGameEvent((CGameScriptManager *)g_pScriptMgr, 18, v19);
          CEcoSector::ChangeWorkerDeltaAmount(v21, v19, -1);
        }
      }
      else
      {
        v20 = *((unsigned __int16 *)v21 + v19 + 85);
        if ( v20 )
        {
          v14 = (CPropertySet *)CSettlerMgr::operator[](v20);
          CEcoSector::GetSettlerOutOfOffer(v21, v20);
          CSettler::ChangeType(v14, 1, 1, 0);
          CEcoSector::ChangeWorkerDeltaAmount(v21, v19, 1);
        }
      }
    }
  }
}


// address=[0x142d120]
// Decompiled from int __thiscall CEcoSector::FillGoodDistribution(CEcoSector *this, struct CGoodDistributionInfo *a2)
void  CEcoSector::FillGoodDistribution(class CGoodDistributionInfo *) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-Ch]
  int sum; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2844, "_pInfoExchange!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  result = CBuildingSupplyPriority::GetNumberOfSupplyBuildings(
             (char *)this + 556,
             *((_DWORD *)a2 + 15),
             (char *)a2 + 16);
  v4 = result;
  *((_DWORD *)a2 + 2) = result;
  sum = 0;
  for ( i = 0; i < v4; ++i )
  {
    result = i;
    sum += *((_DWORD *)a2 + 2 * i + 5);
  }
  if ( sum == 100 )
    return result;
  if ( BBSupportDbgReportF(0, "Logic\\EcoSector.cpp", 2860, "sum!=100") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x142d1f0]
// Decompiled from int __thiscall CEcoSector::ChangeGoodDistribution(int this, int a2)
void  CEcoSector::ChangeGoodDistribution(class CGoodDistributionInfo *) {
  
  int result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2872, "_pInfoExchange!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( a2 )
    return CBuildingSupplyPriority::ChangePriority((void *)(this + 556), *(_DWORD *)(a2 + 60), a2 + 16);
  return result;
}


// address=[0x142d250]
// Decompiled from int __thiscall sub_182D250(char *this, int a2)
void  CEcoSector::FillTransportPrio(class CTransportpriorityInfo *) {
  
  int result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 2932, "_pInfoExchange != NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  CGoodTransportPriority::GetSortedGoods(a2 + 16);
  result = CGoodTransportPriority::GetNumberOfPriorities(this + 572);
  *(_DWORD *)(a2 + 12) = result;
  return result;
}


// address=[0x142d2c0]
// Decompiled from void __thiscall CEcoSector::ChangeTransportPrio(char *this, int a2, int a3)
void  CEcoSector::ChangeTransportPrio(enum PILE_TYPES,int) {
  
  CGoodTransportPriority::ChangePriority(this + 572, a2, a3);
  UpdateGuiDlgTransportpriority();
}


// address=[0x142d2f0]
// Decompiled from int __thiscall CEcoSector::ChangeBuildingSupplyPrio(char *this, int a2, int a3, char a4)
void  CEcoSector::ChangeBuildingSupplyPrio(enum PILE_TYPES,enum BUILDING_TYPES,signed char) {
  
  return CBuildingSupplyPriority::ChangePriority(this + 556, a2, a3, a4);
}


// address=[0x142d330]
// Decompiled from int __thiscall CEcoSector::GetNumberOfGoods(unsigned __int16 *this, int a2, int a3)
int  CEcoSector::GetNumberOfGoods(int,enum CEcoSector::T_STATISTIC_GOOD_CATEGORY) {
  
  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3326, "(_iGoodType > GOOD_NO_GOOD) && (_iGoodType < GOOD_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a2 <= 0 || a2 >= 43 )
    return 0;
  if ( !a3 )
    return this[a2 + 340];
  if ( a3 == 1 )
    return this[a2 + 383];
  return this[a2 + 383] + this[a2 + 340];
}


// address=[0x142d3e0]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangeNumberOfGoodsPile(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangeNumberOfGoodsPile(int,int) {
  
  CEcoSector *result; // eax
  __int16 v4; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3359, "(_iGoodType > GOOD_NO_GOOD) && (_iGoodType < GOOD_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a2 <= 0 || a2 >= 43 )
    return result;
  v6 = a3 + *((unsigned __int16 *)this + a2 + 340);
  if ( v6 < 0 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3369, "iNewAmount >= 0") == 1 )
    __debugbreak();
  if ( v6 >= 0x8000 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3370, "iNewAmount < 32768") == 1 )
    __debugbreak();
  if ( v6 < 0 )
    v4 = 0;
  else
    v4 = v6;
  result = this;
  *((_WORD *)this + a2 + 340) = v4;
  return result;
}


// address=[0x142d4c0]
// Decompiled from _WORD *__thiscall CEcoSector::ChangeNumberOfGoodsCarrier(_WORD *this, int a2, int a3)
void  CEcoSector::ChangeNumberOfGoodsCarrier(int,int) {
  
  _WORD *result; // eax
  __int16 v4; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3379, "(_iGoodType > GOOD_NO_GOOD) && (_iGoodType < GOOD_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a2 <= 0 || a2 >= 43 )
    return result;
  v6 = a3 + (unsigned __int16)this[a2 + 383];
  if ( v6 < 0 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3389, "iNewAmount >= 0") == 1 )
    __debugbreak();
  if ( v6 >= 0x8000 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3390, "iNewAmount < 32768") == 1 )
    __debugbreak();
  if ( v6 < 0 )
    v4 = 0;
  else
    v4 = v6;
  result = this;
  this[a2 + 383] = v4;
  return result;
}


// address=[0x142d5a0]
// Decompiled from void __thiscall CEcoSector::OrderDiggerAndBuilderAtStartUp(CEcoSector *this)
void  CEcoSector::OrderDiggerAndBuilderAtStartUp(void) {
  
  int v1; // [esp+20h] [ebp-1Ch]
  int v2; // [esp+28h] [ebp-14h]
  int v3; // [esp+30h] [ebp-Ch]
  int v4; // [esp+34h] [ebp-8h]

  if ( *((unsigned __int16 *)this + 19) - *((unsigned __int16 *)this + 17) - *((unsigned __int16 *)this + 16) > 0 )
  {
    if ( *((unsigned __int16 *)this + 21) >= 5u )
      v2 = 0;
    else
      v2 = 5 - *((unsigned __int16 *)this + 21);
    v4 = v2;
    if ( *((unsigned __int16 *)this + 20) >= 5u )
      v1 = 0;
    else
      v1 = 5 - *((unsigned __int16 *)this + 20);
    v3 = v1;
    if ( v2 > *((unsigned __int16 *)this + 358) )
      v4 = *((unsigned __int16 *)this + 358);
    if ( v1 > *((unsigned __int16 *)this + 371) )
      v3 = *((unsigned __int16 *)this + 371);
    if ( v4 > 0 )
      CEcoSector::ChangeWorkerDeltaAmount(this, 3, v4);
    if ( v3 > 0 )
      CEcoSector::ChangeWorkerDeltaAmount(this, 2, v3);
  }
}


// address=[0x142d6d0]
// Decompiled from int __fastcall CEcoSector::TakeSoldierOrder(CEcoSector *this, int a2, int a3, int a4)
void  CEcoSector::TakeSoldierOrder(int,int) {
  
  int result; // eax
  int i; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  _BYTE *v7; // [esp+10h] [ebp-4h]

  if ( a3 == 67 )
  {
    if ( !a4 )
    {
      for ( i = 0; i < 10; ++i )
      {
        *((_BYTE *)this + i + 852) = 0;
        result = i + 1;
      }
    }
  }
  else
  {
    for ( j = 0; g_vSoldierProductionMap[2 * j] && g_vSoldierProductionMap[2 * j] != a3; ++j )
      ;
    result = j;
    if ( g_vSoldierProductionMap[2 * j] != -1 )
    {
      result = (int)this;
      v7 = (char *)this + dword_3D8AE1C[2 * j] + 852;
      if ( a4 )
      {
        if ( a4 == 100 )
        {
          *v7 = 100;
        }
        else if ( a4 <= 0 )
        {
          result = a4 + (char)*v7;
          if ( result >= 0 )
          {
            result = a4 + (char)*v7;
            *v7 = result;
          }
          else
          {
            *v7 = 0;
          }
        }
        else
        {
          result = a4 + (char)*v7;
          if ( result <= 100 )
          {
            result = a4 + (char)*v7;
            *v7 = result;
          }
          else
          {
            *v7 = 100;
          }
        }
      }
      else
      {
        result = (int)this + dword_3D8AE1C[2 * j] + 852;
        *v7 = 0;
      }
    }
  }
  return result;
}


// address=[0x142d7f0]
// Decompiled from char *__thiscall CEcoSector::TakeWeaponOrder(CEcoSector *this, int a2, int a3)
void  CEcoSector::TakeWeaponOrder(int,int) {
  
  char *result; // eax
  int i; // [esp+8h] [ebp-8h]
  unsigned __int8 v6; // [esp+Fh] [ebp-1h]
  char v7; // [esp+Fh] [ebp-1h]

  for ( i = 0;
        i < std::vector<unsigned char>::size((char *)this + 916)
     && *(unsigned __int8 *)std::vector<unsigned char>::operator[](i) != a2;
        ++i )
  {
    ;
  }
  result = (char *)std::vector<unsigned char>::operator[](i);
  if ( !*result )
    return result;
  v6 = *(_BYTE *)std::vector<unsigned char>::operator[](i);
  if ( a3 )
  {
    if ( a3 == 100 )
    {
      v7 = 100;
    }
    else if ( a3 <= 0 )
    {
      if ( a3 + v6 >= 0 )
        v7 = a3 + v6;
      else
        v7 = 0;
    }
    else if ( a3 + v6 <= 100 )
    {
      v7 = a3 + v6;
    }
    else
    {
      v7 = 100;
    }
  }
  else
  {
    v7 = 0;
  }
  result = (char *)std::vector<unsigned char>::operator[](i);
  *result = v7;
  return result;
}


// address=[0x142d8f0]
// Decompiled from BOOL __thiscall CEcoSector::SetWeaponAutoProduction(CEcoSector *this, bool a2)
void  CEcoSector::SetWeaponAutoProduction(bool) {
  
  BOOL result; // eax
  char v3; // [esp+4h] [ebp-4h]

  result = a2;
  if ( a2 )
    v3 = 100;
  else
    v3 = 0;
  *((_BYTE *)this + 896) = v3;
  return result;
}


// address=[0x142d930]
// Decompiled from _BYTE *__thiscall CEcoSector::SetWeaponPercentage(CEcoSector *this, unsigned int a2)
void  CEcoSector::SetWeaponPercentage(unsigned int) {
  
  _BYTE *result; // eax

  *(_BYTE *)std::vector<unsigned char>::operator[](0) = a2;
  *(_BYTE *)std::vector<unsigned char>::operator[](1) = BYTE1(a2);
  *(_BYTE *)std::vector<unsigned char>::operator[](2) = BYTE2(a2);
  result = (_BYTE *)std::vector<unsigned char>::size((char *)this + 932);
  if ( result != (_BYTE *)4 )
    return result;
  result = (_BYTE *)std::vector<unsigned char>::operator[](3);
  *result = HIBYTE(a2);
  return result;
}


// address=[0x142d9d0]
// Decompiled from int __thiscall CEcoSector::WeaponPercentage(CEcoSector *this, int a2)
int  CEcoSector::WeaponPercentage(int) {
  
  return *(unsigned __int8 *)std::vector<unsigned char>::operator[](a2);
}


// address=[0x142da00]
// Decompiled from void __thiscall CEcoSector::TakeToolOrder(CEcoSector *this, int a2, int a3)
void  CEcoSector::TakeToolOrder(int,int) {
  
  int i; // [esp+8h] [ebp-8h]
  unsigned __int8 v5; // [esp+Fh] [ebp-1h]
  char v6; // [esp+Fh] [ebp-1h]

  if ( a2 )
  {
    for ( i = 0;
          i < std::vector<unsigned char>::size((char *)this + 880)
       && *(unsigned __int8 *)std::vector<unsigned char>::operator[](i) != a2;
          ++i )
    {
      ;
    }
    if ( i < std::vector<unsigned char>::size((char *)this + 880) )
    {
      v5 = *(_BYTE *)std::vector<unsigned char>::operator[](i);
      if ( a3 )
      {
        if ( a3 == 100 )
        {
          v6 = 100;
        }
        else if ( a3 <= 0 )
        {
          if ( a3 + v5 >= 0 )
            v6 = a3 + v5;
          else
            v6 = 0;
        }
        else if ( a3 + v5 <= 100 )
        {
          v6 = a3 + v5;
        }
        else
        {
          v6 = 100;
        }
      }
      else
      {
        v6 = 0;
      }
      *(_BYTE *)std::vector<unsigned char>::operator[](i) = v6;
    }
  }
}


// address=[0x142db00]
// Decompiled from int __cdecl CEcoSector::GetSettlerCountEcoSectorId(const struct CSettler *a1)
static int __cdecl CEcoSector::GetSettlerCountEcoSectorId(class CSettler const *) {
  
  int v2; // [esp+4h] [ebp-1Ch]
  int v3; // [esp+8h] [ebp-18h]
  int v4; // [esp+Ch] [ebp-14h]
  int v5; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]
  int v7; // [esp+1Ch] [ebp-4h]

  v5 = 0;
  if ( !a1 )
    return v5;
  if ( IEntity::WarriorType() )
    return v5;
  v3 = IEntity::WorldIdx();
  v6 = IEntity::Flags(a1);
  v7 = CSettler::Role(a1);
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 72))(v7);
  IEntity::Type((unsigned __int16 *)a1);
  if ( (_UNKNOWN *)(((unsigned int)&loc_200007C + 4) & v6) != (_UNKNOWN *)((char *)&loc_1FFFFFF + 1) || v4 == 18 )
    return v5;
  v2 = ITiling::EcoSectorId(v3);
  if ( (v6 & 0x8000) == 0 )
    return v2;
  return v5;
}


// address=[0x142dba0]
// Decompiled from int __thiscall CEcoSector::DbgCheckEcoSector(CEcoSector *this, int a2)
int  CEcoSector::DbgCheckEcoSector(int) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp+0h] [ebp-208h]
  int v6; // [esp+4h] [ebp-204h]
  int SettlerCountEcoSectorId; // [esp+8h] [ebp-200h]
  int UsedId; // [esp+Ch] [ebp-1FCh]
  int v9; // [esp+14h] [ebp-1F4h]
  int v10; // [esp+18h] [ebp-1F0h]
  int v11; // [esp+1Ch] [ebp-1ECh]
  const struct CSettler *SettlerPtr; // [esp+20h] [ebp-1E8h]
  int v13; // [esp+24h] [ebp-1E4h]
  int i; // [esp+28h] [ebp-1E0h]
  struct CPile *PilePtr; // [esp+30h] [ebp-1D8h]
  int v17; // [esp+34h] [ebp-1D4h]
  int k; // [esp+38h] [ebp-1D0h]
  int j; // [esp+3Ch] [ebp-1CCh]
  _DWORD v20[70]; // [esp+40h] [ebp-1C8h] BYREF
  _DWORD v21[43]; // [esp+158h] [ebp-B0h] BYREF

  v17 = 0;
  v13 = CEcoSector::EcoSectorId(this);
  if ( (*(int (__thiscall **)(void *, int))(*(_DWORD *)g_pTiling + 40))(g_pTiling, v13) <= 20 )
    return v17;
  v11 = CEcoSector::Owner(this);
  memset(v20, 0, sizeof(v20));
  memset(v21, 0, sizeof(v21));
  UsedId = CMapObjectMgr::LastUsedId();
  for ( i = 7; i <= UsedId; ++i )
  {
    SettlerPtr = (const struct CSettler *)CSettlerMgr::GetSettlerPtr(i);
    if ( SettlerPtr )
    {
      if ( IEntity::OwnerId((unsigned __int8 *)SettlerPtr) == v11 )
      {
        SettlerCountEcoSectorId = CEcoSector::GetSettlerCountEcoSectorId(SettlerPtr);
        if ( SettlerCountEcoSectorId == v13 )
        {
          v10 = IEntity::Type((unsigned __int16 *)SettlerPtr);
          ++v20[v10];
        }
      }
    }
    PilePtr = CPileMgr::GetPilePtr(i);
    if ( PilePtr )
    {
      v2 = IEntity::PackedXY(PilePtr);
      v3 = CWorldManager::Index(v2);
      v6 = ITiling::EcoSectorId(v3);
      if ( v6 == v13 )
      {
        v9 = (*(int (__thiscall **)(struct CPile *, int, int, int))(*(_DWORD *)PilePtr + 60))(
               PilePtr,
               v5,
               v6,
               SettlerCountEcoSectorId);
        v5 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
        v21[v9] += v5;
      }
    }
  }
  for ( j = 1; j < 67; ++j )
  {
    if ( *((unsigned __int16 *)this + j + 18) != v20[j] )
    {
      ++v17;
      BBSupportTracePrintF(
        0,
        "Wrong number of settlers of type %i in eco-sector %i of owner %i, (is %i, should be %i)!",
        j,
        v13,
        v11,
        *((unsigned __int16 *)this + j + 18),
        v20[j]);
    }
  }
  for ( k = 1; k < 43; ++k )
  {
    if ( *((unsigned __int16 *)this + k + 340) != v21[k] )
    {
      ++v17;
      BBSupportTracePrintF(
        0,
        "Wrong amount of pile goods of type %i in eco-sector %i of owner %i, (is %i, should be %i)!",
        k,
        v13,
        v11,
        *((unsigned __int16 *)this + k + 340),
        v21[k]);
    }
  }
  if ( v17 )
  {
    if ( byte_3D894EF && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 3871, "iErrorCount == 0") == 1 )
      __debugbreak();
    byte_3D894EF = 0;
  }
  else
  {
    byte_3D894EF = 1;
  }
  return v17;
}


// address=[0x142eb00]
// Decompiled from struct CEcoSector *__thiscall CEcoSector::CEcoSector(struct CEcoSector *this, int a2)
 CEcoSector::CEcoSector(std::istream &) {
  
  _BYTE v3[16]; // [esp+4h] [ebp-B0h] BYREF
  _BYTE v4[16]; // [esp+14h] [ebp-A0h] BYREF
  _BYTE v5[16]; // [esp+24h] [ebp-90h] BYREF
  int pExceptionObject; // [esp+34h] [ebp-80h] BYREF
  int v7; // [esp+38h] [ebp-7Ch] BYREF
  int v8; // [esp+3Ch] [ebp-78h] BYREF
  int v9; // [esp+40h] [ebp-74h] BYREF
  int v10; // [esp+44h] [ebp-70h] BYREF
  int v11; // [esp+48h] [ebp-6Ch]
  int v12; // [esp+4Ch] [ebp-68h] BYREF
  int v13; // [esp+50h] [ebp-64h] BYREF
  int v14; // [esp+54h] [ebp-60h] BYREF
  int v15; // [esp+58h] [ebp-5Ch] BYREF
  int v16; // [esp+5Ch] [ebp-58h]
  int v17; // [esp+60h] [ebp-54h] BYREF
  int v18; // [esp+64h] [ebp-50h] BYREF
  int v19; // [esp+68h] [ebp-4Ch] BYREF
  int v20; // [esp+6Ch] [ebp-48h] BYREF
  int v21; // [esp+70h] [ebp-44h]
  int v22; // [esp+74h] [ebp-40h] BYREF
  int ii; // [esp+78h] [ebp-3Ch]
  int Version; // [esp+7Ch] [ebp-38h]
  int m; // [esp+80h] [ebp-34h]
  int j; // [esp+84h] [ebp-30h]
  __int16 v27; // [esp+8Ah] [ebp-2Ah] BYREF
  __int16 v28; // [esp+8Ch] [ebp-28h] BYREF
  __int16 v29; // [esp+8Eh] [ebp-26h] BYREF
  int n; // [esp+90h] [ebp-24h]
  int k; // [esp+94h] [ebp-20h]
  int i; // [esp+98h] [ebp-1Ch]
  char v33; // [esp+9Eh] [ebp-16h] BYREF
  unsigned __int8 v34; // [esp+9Fh] [ebp-15h] BYREF
  char v35; // [esp+A0h] [ebp-14h] BYREF
  unsigned __int8 v36; // [esp+A1h] [ebp-13h] BYREF
  char v37; // [esp+A2h] [ebp-12h] BYREF
  unsigned __int8 v38; // [esp+A3h] [ebp-11h] BYREF
  struct CEcoSector *v39; // [esp+A4h] [ebp-10h]
  int v40; // [esp+B0h] [ebp-4h]

  v39 = this;
  CPersistence::CPersistence(this);
  *(_DWORD *)v39 = &CEcoSector::_vftable_;
  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>();
  v40 = 10;
  std::vector<std::vector<unsigned short>>::vector<std::vector<unsigned short>>();
  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>();
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>();
  std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::vector<CEcoSector::SECO_STORAGE_GOOD_REG>();
  CBuildingSupplyPriority::CBuildingSupplyPriority(a2);
  CGoodTransportPriority::CGoodTransportPriority(a2);
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  v22 = 0;
  operator^<int>(a2, (int)&v22);
  if ( v22 != -823895864 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 271, "iControllID == 0xCEE458C8") == 1 )
    __debugbreak();
  Version = Serial::LoadVersion(a2);
  switch ( Version )
  {
    case 5:
      operator^<int>(a2, (int)v39 + 12);
      operator^<unsigned int>(a2, (char *)v39 + 4);
      operator^<unsigned char>(a2, (char *)v39 + 18);
      operator^<unsigned char>(a2, (char *)v39 + 19);
      operator^<unsigned char>(a2, (char *)v39 + 20);
      operator^<signed char>(a2, (char *)v39 + 21);
      operator^<signed char>(a2, (char *)v39 + 22);
      operator^<short>(a2, (char *)v39 + 24);
      operator^<short>(a2, (char *)v39 + 26);
      operator^<unsigned char>(a2, (char *)v39 + 28);
      operator^<unsigned char>(a2, (char *)v39 + 29);
      operator^<unsigned char>(a2, (char *)v39 + 30);
      operator^<unsigned short>(a2, (char *)v39 + 32);
      operator^<unsigned short>(a2, (char *)v39 + 34);
      operator^<int>(a2, (int)v39 + 8);
      if ( *((int *)v39 + 2) < 0 )
        v21 = 0;
      else
        v21 = CWorldManager::EcoSectorId(*((_DWORD *)v39 + 2));
      *((_WORD *)v39 + 8) = v21;
      if ( !*((_WORD *)v39 + 8) && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 301, "m_iEcoSectorId > 0") == 1 )
        __debugbreak();
      *((_DWORD *)v39 + 2) = -1;
      LoadArray<unsigned short>(a2, (char *)v39 + 36, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 170, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 304, 86);
      std::vector<std::deque<unsigned short>>::resize(43);
      for ( i = 0; i < 43; ++i )
      {
        v20 = 0;
        operator^<int>(a2, (int)&v20);
        for ( j = 0; j < v20; ++j )
        {
          v19 = 0;
          operator^<int>(a2, (int)&v19);
          v29 = v19;
          std::vector<std::deque<unsigned short>>::operator[](i);
          std::deque<unsigned short>::push_back(&v29);
        }
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 472, 84);
      LoadArray<signed char>(a2, (char *)v39 + 672, 5);
      LoadArray<signed char>(a2, (char *)v39 + 677, 2);
      v18 = 0;
      operator^<int>(a2, (int)&v18);
      for ( i = 0; i < v18; ++i )
      {
        std::vector<unsigned short>::vector<unsigned short>(v5);
        LOBYTE(v40) = 11;
        LoadVector<unsigned short>(a2, v5);
        std::vector<std::vector<unsigned short>>::push_back(v5);
        LOBYTE(v40) = 10;
        std::vector<unsigned short>::~vector<unsigned short>(v5);
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 680, 86);
      LoadArray<unsigned short>(a2, (char *)v39 + 766, 86);
      LoadArray<signed char>(a2, (char *)v39 + 852, 10);
      operator^<unsigned char>(a2, &v38);
      for ( i = 0; i < v38; ++i )
      {
        operator^<unsigned char>(a2, &v37);
        std::vector<unsigned char>::push_back(&v37);
      }
      operator^<unsigned char>(a2, &v38);
      for ( i = 0; i < v38; ++i )
      {
        operator^<unsigned char>(a2, &v37);
        std::vector<unsigned char>::push_back(&v37);
      }
      operator^<unsigned char>(a2, &v38);
      for ( i = 0; i < v38; ++i )
      {
        operator^<unsigned char>(a2, &v37);
        std::vector<unsigned char>::push_back(&v37);
      }
      operator^<unsigned char>(a2, &v38);
      for ( i = 0; i < v38; ++i )
      {
        operator^<unsigned char>(a2, &v37);
        std::vector<unsigned char>::push_back(&v37);
      }
      operator^<unsigned char>(a2, &v38);
      for ( i = 0; i < v38; ++i )
      {
        operator^<unsigned char>(a2, &v37);
        std::vector<unsigned char>::push_back(&v37);
      }
      v17 = 0;
      operator^<int>(a2, (int)&v17);
      if ( v17 != 1073196093 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 381, "iControllID == 0x3FF7AC3D") == 1 )
        __debugbreak();
      break;
    case 6:
      operator^<int>(a2, (int)v39 + 12);
      operator^<unsigned int>(a2, (char *)v39 + 4);
      operator^<unsigned char>(a2, (char *)v39 + 18);
      operator^<unsigned char>(a2, (char *)v39 + 19);
      operator^<unsigned char>(a2, (char *)v39 + 20);
      operator^<signed char>(a2, (char *)v39 + 21);
      operator^<signed char>(a2, (char *)v39 + 22);
      operator^<short>(a2, (char *)v39 + 24);
      operator^<short>(a2, (char *)v39 + 26);
      operator^<unsigned char>(a2, (char *)v39 + 28);
      operator^<unsigned char>(a2, (char *)v39 + 29);
      operator^<unsigned char>(a2, (char *)v39 + 30);
      operator^<unsigned short>(a2, (char *)v39 + 32);
      operator^<unsigned short>(a2, (char *)v39 + 34);
      operator^<int>(a2, (int)v39 + 8);
      if ( *((int *)v39 + 2) < 0 )
        v16 = 0;
      else
        v16 = CWorldManager::EcoSectorId(*((_DWORD *)v39 + 2));
      *((_WORD *)v39 + 8) = v16;
      if ( !*((_WORD *)v39 + 8) && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 411, "m_iEcoSectorId > 0") == 1 )
        __debugbreak();
      *((_DWORD *)v39 + 2) = -1;
      LoadArray<unsigned short>(a2, (char *)v39 + 36, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 170, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 304, 86);
      std::vector<std::deque<unsigned short>>::resize(43);
      for ( k = 0; k < 43; ++k )
      {
        v15 = 0;
        operator^<int>(a2, (int)&v15);
        for ( m = 0; m < v15; ++m )
        {
          v14 = 0;
          operator^<int>(a2, (int)&v14);
          v28 = v14;
          std::vector<std::deque<unsigned short>>::operator[](k);
          std::deque<unsigned short>::push_back(&v28);
        }
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 472, 84);
      LoadArray<signed char>(a2, (char *)v39 + 672, 5);
      LoadArray<signed char>(a2, (char *)v39 + 677, 2);
      v13 = 0;
      operator^<int>(a2, (int)&v13);
      for ( k = 0; k < v13; ++k )
      {
        std::vector<unsigned short>::vector<unsigned short>(v4);
        LOBYTE(v40) = 12;
        LoadVector<unsigned short>(a2, v4);
        std::vector<std::vector<unsigned short>>::push_back(v4);
        LOBYTE(v40) = 10;
        std::vector<unsigned short>::~vector<unsigned short>(v4);
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 680, 86);
      LoadArray<unsigned short>(a2, (char *)v39 + 766, 86);
      LoadArray<signed char>(a2, (char *)v39 + 852, 10);
      operator^<unsigned char>(a2, &v36);
      for ( k = 0; k < v36; ++k )
      {
        operator^<unsigned char>(a2, &v35);
        std::vector<unsigned char>::push_back(&v35);
      }
      operator^<unsigned char>(a2, &v36);
      for ( k = 0; k < v36; ++k )
      {
        operator^<unsigned char>(a2, &v35);
        std::vector<unsigned char>::push_back(&v35);
      }
      operator^<unsigned char>(a2, &v36);
      for ( k = 0; k < v36; ++k )
      {
        operator^<unsigned char>(a2, &v35);
        std::vector<unsigned char>::push_back(&v35);
      }
      operator^<unsigned char>(a2, (char *)v39 + 896);
      operator^<unsigned char>(a2, &v36);
      for ( k = 0; k < v36; ++k )
      {
        operator^<unsigned char>(a2, &v35);
        std::vector<unsigned char>::push_back(&v35);
      }
      operator^<unsigned char>(a2, &v36);
      for ( k = 0; k < v36; ++k )
      {
        operator^<unsigned char>(a2, &v35);
        std::vector<unsigned char>::push_back(&v35);
      }
      v12 = 0;
      operator^<int>(a2, (int)&v12);
      if ( v12 != 1073196093 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 494, "iControllID == 0x3FF7AC3D") == 1 )
        __debugbreak();
      break;
    case 7:
      operator^<int>(a2, (int)v39 + 12);
      operator^<unsigned int>(a2, (char *)v39 + 4);
      operator^<unsigned char>(a2, (char *)v39 + 18);
      operator^<unsigned char>(a2, (char *)v39 + 19);
      operator^<unsigned char>(a2, (char *)v39 + 20);
      operator^<signed char>(a2, (char *)v39 + 21);
      operator^<signed char>(a2, (char *)v39 + 22);
      operator^<short>(a2, (char *)v39 + 24);
      operator^<short>(a2, (char *)v39 + 26);
      operator^<unsigned char>(a2, (char *)v39 + 28);
      operator^<unsigned char>(a2, (char *)v39 + 29);
      operator^<unsigned char>(a2, (char *)v39 + 30);
      operator^<unsigned short>(a2, (char *)v39 + 32);
      operator^<unsigned short>(a2, (char *)v39 + 34);
      operator^<int>(a2, (int)v39 + 8);
      if ( *((int *)v39 + 2) < 0 )
        v11 = 0;
      else
        v11 = CWorldManager::EcoSectorId(*((_DWORD *)v39 + 2));
      *((_WORD *)v39 + 8) = v11;
      if ( !*((_WORD *)v39 + 8) && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 523, "m_iEcoSectorId > 0") == 1 )
        __debugbreak();
      *((_DWORD *)v39 + 2) = -1;
      LoadArray<unsigned short>(a2, (char *)v39 + 36, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 170, 134);
      LoadArray<unsigned short>(a2, (char *)v39 + 304, 86);
      std::vector<std::deque<unsigned short>>::resize(43);
      for ( n = 0; n < 43; ++n )
      {
        v10 = 0;
        operator^<int>(a2, (int)&v10);
        for ( ii = 0; ii < v10; ++ii )
        {
          v9 = 0;
          operator^<int>(a2, (int)&v9);
          v27 = v9;
          std::vector<std::deque<unsigned short>>::operator[](n);
          std::deque<unsigned short>::push_back(&v27);
        }
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 472, 84);
      LoadArray<signed char>(a2, (char *)v39 + 672, 5);
      LoadArray<signed char>(a2, (char *)v39 + 677, 2);
      v8 = 0;
      operator^<int>(a2, (int)&v8);
      for ( n = 0; n < v8; ++n )
      {
        std::vector<unsigned short>::vector<unsigned short>(v3);
        LOBYTE(v40) = 13;
        LoadVector<unsigned short>(a2, v3);
        std::vector<std::vector<unsigned short>>::push_back(v3);
        LOBYTE(v40) = 10;
        std::vector<unsigned short>::~vector<unsigned short>(v3);
      }
      LoadArray<unsigned short>(a2, (char *)v39 + 680, 86);
      LoadArray<unsigned short>(a2, (char *)v39 + 766, 86);
      LoadArray<signed char>(a2, (char *)v39 + 852, 10);
      operator^<unsigned char>(a2, &v34);
      for ( n = 0; n < v34; ++n )
      {
        operator^<unsigned char>(a2, &v33);
        std::vector<unsigned char>::push_back(&v33);
      }
      operator^<unsigned char>(a2, &v34);
      for ( n = 0; n < v34; ++n )
      {
        operator^<unsigned char>(a2, &v33);
        std::vector<unsigned char>::push_back(&v33);
      }
      operator^<unsigned char>(a2, &v34);
      for ( n = 0; n < v34; ++n )
      {
        operator^<unsigned char>(a2, &v33);
        std::vector<unsigned char>::push_back(&v33);
      }
      operator^<unsigned char>(a2, (char *)v39 + 896);
      operator^<unsigned char>(a2, &v34);
      for ( n = 0; n < v34; ++n )
      {
        operator^<unsigned char>(a2, &v33);
        std::vector<unsigned char>::push_back(&v33);
      }
      operator^<unsigned char>(a2, &v34);
      for ( n = 0; n < v34; ++n )
      {
        operator^<unsigned char>(a2, &v33);
        std::vector<unsigned char>::push_back(&v33);
      }
      v7 = 0;
      operator^<int>(a2, (int)&v7);
      if ( v7 != 1073196093 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 605, "iControllID == 0x3FF7AC3D") == 1 )
        __debugbreak();
      operator^<unsigned int>(a2, (char *)v39 + 948);
      operator^<unsigned int>(a2, (char *)v39 + 952);
      operator^<unsigned int>(a2, (char *)v39 + 956);
      operator^<unsigned int>(a2, (char *)v39 + 960);
      break;
    default:
      BBSupportTracePrintF(3, "Unknown fileFormatVersion for CEcoSector");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  if ( *((_WORD *)v39 + 8) )
    CEcoSectorMgr::RegisterEcoSector((CEcoSectorMgr *)g_cESMgr, *((unsigned __int16 *)v39 + 8), v39, 0);
  return v39;
}


// address=[0x142fd30]
// Decompiled from int __thiscall sub_182FD30(_DWORD *this, int a2)
void  CEcoSector::Store(std::ostream &) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  _BYTE v9[12]; // [esp+4h] [ebp-84h] BYREF
  _BYTE v10[12]; // [esp+10h] [ebp-78h] BYREF
  _BYTE v11[12]; // [esp+1Ch] [ebp-6Ch] BYREF
  int v12; // [esp+28h] [ebp-60h]
  int v13; // [esp+2Ch] [ebp-5Ch] BYREF
  int v14; // [esp+30h] [ebp-58h]
  _DWORD v15[2]; // [esp+34h] [ebp-54h] BYREF
  int v16; // [esp+3Ch] [ebp-4Ch]
  int v17; // [esp+40h] [ebp-48h]
  int v18; // [esp+44h] [ebp-44h]
  int v19; // [esp+48h] [ebp-40h] BYREF
  int v20; // [esp+4Ch] [ebp-3Ch]
  int v21; // [esp+50h] [ebp-38h] BYREF
  BOOL v22; // [esp+54h] [ebp-34h]
  BOOL v23; // [esp+58h] [ebp-30h]
  BOOL v24; // [esp+5Ch] [ebp-2Ch]
  BOOL v25; // [esp+60h] [ebp-28h]
  BOOL v26; // [esp+64h] [ebp-24h]
  int v27; // [esp+68h] [ebp-20h] BYREF
  int v28; // [esp+6Ch] [ebp-1Ch]
  int i; // [esp+70h] [ebp-18h]
  _DWORD *v30; // [esp+74h] [ebp-14h]
  char v31; // [esp+7Ah] [ebp-Eh]
  unsigned __int8 v32; // [esp+7Bh] [ebp-Dh] BYREF
  int v33; // [esp+84h] [ebp-4h]

  v30 = this;
  CPersistence::Store(a2);
  (*(void (__thiscall **)(_DWORD *, int))(v30[139] + 4))(v30 + 139, a2);
  (*(void (__thiscall **)(_DWORD *, int))(v30[143] + 4))(v30 + 143, a2);
  v21 = -823895864;
  operator^<int>(a2, &v21);
  v12 = 7;
  Serial::StoreVersion(a2, 7);
  operator^<int>(a2, v30 + 3);
  operator^<unsigned int>(a2, v30 + 1);
  operator^<unsigned char>(a2, (char *)v30 + 18);
  operator^<unsigned char>(a2, (char *)v30 + 19);
  operator^<unsigned char>(a2, v30 + 5);
  operator^<signed char>(a2, (char *)v30 + 21);
  operator^<signed char>(a2, (char *)v30 + 22);
  operator^<short>(a2, v30 + 6);
  operator^<short>(a2, (char *)v30 + 26);
  operator^<unsigned char>(a2, v30 + 7);
  operator^<unsigned char>(a2, (char *)v30 + 29);
  operator^<unsigned char>(a2, (char *)v30 + 30);
  operator^<unsigned short>(a2, v30 + 8);
  operator^<unsigned short>(a2, (char *)v30 + 34);
  operator^<int>(a2, v30 + 2);
  if ( (int)v30[2] < 0 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 675, "m_iStoreWorldIdx >= 0") == 1 )
    __debugbreak();
  if ( (int)v30[2] < 0 )
    v28 = 0;
  else
    v28 = ITiling::EcoSectorId(v30[2]);
  v20 = v28;
  if ( !*((_WORD *)v30 + 8) && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 677, "m_iEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int16 *)v30 + 8) != v20
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 678, "m_iEcoSectorId == iEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  v30[2] = -1;
  StoreArray<unsigned short>(a2, v30 + 9, 134);
  StoreArray<unsigned short>(a2, (char *)v30 + 170, 134);
  StoreArray<unsigned short>(a2, v30 + 76, 86);
  for ( i = 0; i < 43; ++i )
  {
    v2 = std::vector<std::deque<unsigned short>>::operator[](i);
    v19 = std::deque<unsigned short>::size(v2);
    operator^<int>(a2, &v19);
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v11);
    v33 = 0;
    std::vector<std::deque<unsigned short>>::operator[](i);
    v18 = std::deque<unsigned short>::begin(v10);
    v17 = v18;
    LOBYTE(v33) = 1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator=(v18);
    LOBYTE(v33) = 0;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v10);
    while ( 1 )
    {
      std::vector<std::deque<unsigned short>>::operator[](i);
      v16 = std::deque<unsigned short>::end(v9);
      v15[1] = v16;
      LOBYTE(v33) = 2;
      v31 = std::_Deque_const_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator!=(v16);
      LOBYTE(v33) = 0;
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v9);
      if ( !v31 )
        break;
      v15[0] = *(unsigned __int16 *)std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator*(v11);
      operator^<int>(a2, v15);
      std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::operator++(v11);
    }
    v33 = -1;
    std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>::~_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<unsigned short>>>(v11);
  }
  StoreArray<unsigned short>(a2, v30 + 118, 84);
  StoreArray<signed char>(a2, v30 + 168, 5);
  StoreArray<signed char>(a2, (char *)v30 + 677, 2);
  v27 = std::vector<std::vector<unsigned short>>::size(v30 + 102);
  operator^<int>(a2, &v27);
  for ( i = 0; i < v27; ++i )
  {
    v14 = std::vector<std::vector<unsigned short>>::operator[](i);
    StoreVector<unsigned short>(a2, v14);
  }
  StoreArray<unsigned short>(a2, v30 + 170, 86);
  StoreArray<unsigned short>(a2, (char *)v30 + 766, 86);
  StoreArray<signed char>(a2, v30 + 213, 10);
  v26 = (unsigned int)std::vector<unsigned char>::size(v30 + 225) < 0x100;
  if ( !v26
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 723, "static_cast<UINT32>(m_vWeaponOrder.size() < 256)") == 1 )
  {
    __debugbreak();
  }
  v32 = std::vector<unsigned char>::size(v30 + 225);
  operator^<unsigned char>(a2, &v32);
  for ( i = 0; i < v32; ++i )
  {
    v3 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v3);
  }
  v25 = (unsigned int)std::vector<unsigned char>::size(v30 + 229) < 0x100;
  if ( !v25
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 731, "static_cast<UINT32>(m_vWeaponTranslater.size() < 256)") == 1 )
  {
    __debugbreak();
  }
  v32 = std::vector<unsigned char>::size(v30 + 229);
  operator^<unsigned char>(a2, &v32);
  for ( i = 0; i < v32; ++i )
  {
    v4 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v4);
  }
  v24 = (unsigned int)std::vector<unsigned char>::size(v30 + 233) < 0x100;
  if ( !v24
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 740, "static_cast<UINT32>(m_vWeaponPercentages.size() < 256)") == 1 )
  {
    __debugbreak();
  }
  v32 = std::vector<unsigned char>::size(v30 + 233);
  operator^<unsigned char>(a2, &v32);
  for ( i = 0; i < v32; ++i )
  {
    v5 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v5);
  }
  operator^<unsigned char>(a2, v30 + 224);
  v23 = (unsigned int)std::vector<unsigned char>::size(v30 + 216) < 0x100;
  if ( !v23 && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 750, "static_cast<UINT32>(m_vToolOrder.size() < 256)") == 1 )
    __debugbreak();
  v32 = std::vector<unsigned char>::size(v30 + 216);
  operator^<unsigned char>(a2, &v32);
  for ( i = 0; i < v32; ++i )
  {
    v6 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v6);
  }
  v22 = (unsigned int)std::vector<unsigned char>::size(v30 + 220) < 0x100;
  if ( !v22
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 758, "static_cast<UINT32>(m_vToolTranslater.size() < 256)") == 1 )
  {
    __debugbreak();
  }
  v32 = std::vector<unsigned char>::size(v30 + 220);
  operator^<unsigned char>(a2, &v32);
  for ( i = 0; i < v32; ++i )
  {
    v7 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v7);
  }
  v13 = 1073196093;
  operator^<int>(a2, &v13);
  operator^<unsigned int>(a2, v30 + 237);
  operator^<unsigned int>(a2, v30 + 238);
  operator^<unsigned int>(a2, v30 + 239);
  return operator^<unsigned int>(a2, v30 + 240);
}


// address=[0x1439a60]
// Decompiled from int __thiscall CEcoSector::ClassID(CEcoSector *this)
unsigned long  CEcoSector::ClassID(void)const {
  
  return CEcoSector::m_iClassID;
}


// address=[0x1439a80]
// Decompiled from int __thiscall CEcoSector::EcoSectorId(CEcoSector *this)
int  CEcoSector::EcoSectorId(void)const {
  
  return *((unsigned __int16 *)this + 8);
}


// address=[0x1439c50]
// Decompiled from int __thiscall CEcoSector::NumberOfCarriersWithJobOrder(CEcoSector *this)
int  CEcoSector::NumberOfCarriersWithJobOrder(void)const {
  
  return *((unsigned __int16 *)this + 17);
}


// address=[0x1447350]
// Decompiled from int __thiscall CEcoSector::BuildingSitesWithPrio(CEcoSector *this)
int  CEcoSector::BuildingSitesWithPrio(void)const {
  
  return *((unsigned __int8 *)this + 20);
}


// address=[0x1447370]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangeBuildingSitesWithPrio(CEcoSector *this, int a2)
void  CEcoSector::ChangeBuildingSitesWithPrio(int) {
  
  CEcoSector *result; // eax

  if ( a2 + *((unsigned __int8 *)this + 20) < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\EcoSector.h",
         243,
         "m_uBuildingSiteWithPrio + _iDelta >= 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_BYTE *)this + 20) += a2;
  return result;
}


// address=[0x14473d0]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangePrioBoards(CEcoSector *this, char a2)
void  CEcoSector::ChangePrioBoards(int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_BYTE *)this + 28) += a2;
  return result;
}


// address=[0x1447400]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangePrioBuilder(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangePrioBuilder(int,int) {
  
  CEcoSector *result; // eax

  if ( a2 + *((char *)this + 22) < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\EcoSector.h",
         262,
         "m_iNrOfBuildingsWithBuilderPrio + _iDeltaBuildingSites >= 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 22) += a2;
  if ( a3 + *((__int16 *)this + 13) < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\EcoSector.h",
         265,
         "m_iNeededPrioBuilder + _iDeltaBuilder >= 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_WORD *)this + 13) += a3;
  return result;
}


// address=[0x14474b0]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangePrioDigger(CEcoSector *this, int a2, int a3)
void  CEcoSector::ChangePrioDigger(int,int) {
  
  CEcoSector *result; // eax

  if ( a2 + *((char *)this + 21) < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\EcoSector.h",
         251,
         "m_iNrOfBuildingsWithDiggerPrio + _iDeltaBuildingSites >= 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 21) += a2;
  if ( a3 + *((__int16 *)this + 12) < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\EcoSector.h",
         254,
         "m_iNeededPrioDigger + _iDeltaDigger >= 0") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_WORD *)this + 12) += a3;
  return result;
}


// address=[0x1447560]
// Decompiled from CEcoSector *__thiscall CEcoSector::ChangePrioStone(CEcoSector *this, char a2)
void  CEcoSector::ChangePrioStone(int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_BYTE *)this + 29) += a2;
  return result;
}


// address=[0x1447590]
// Decompiled from int __thiscall CEcoSector::GetNrOfSoldierOrder(CEcoSector *this, int a2)
int  CEcoSector::GetNrOfSoldierOrder(int)const {
  
  return *((char *)this + a2 + 852);
}


// address=[0x14475b0]
// Decompiled from int __thiscall CEcoSector::GetNrOfToolOrder(CEcoSector *this, int a2)
int  CEcoSector::GetNrOfToolOrder(int)const {
  
  return *(unsigned __int8 *)std::vector<unsigned char>::operator[](a2);
}


// address=[0x14475e0]
// Decompiled from int __thiscall CEcoSector::GetNrOfWeaponOrder(CEcoSector *this, int a2)
int  CEcoSector::GetNrOfWeaponOrder(int)const {
  
  return *(unsigned __int8 *)std::vector<unsigned char>::operator[](a2);
}


// address=[0x14476f0]
// Decompiled from int __thiscall CEcoSector::NeededPrioBuilder(CEcoSector *this)
int  CEcoSector::NeededPrioBuilder(void)const {
  
  return *((__int16 *)this + 13);
}


// address=[0x1447710]
// Decompiled from int __thiscall CEcoSector::NeededPrioDigger(CEcoSector *this)
int  CEcoSector::NeededPrioDigger(void)const {
  
  return *((__int16 *)this + 12);
}


// address=[0x1447730]
// Decompiled from int __thiscall CEcoSector::NrOfBuildingsWithBuilderPrio(CEcoSector *this)
int  CEcoSector::NrOfBuildingsWithBuilderPrio(void)const {
  
  return *((char *)this + 22);
}


// address=[0x1447750]
// Decompiled from int __thiscall CEcoSector::NrOfBuildingsWithDiggerPrio(CEcoSector *this)
int  CEcoSector::NrOfBuildingsWithDiggerPrio(void)const {
  
  return *((char *)this + 21);
}


// address=[0x1447820]
// Decompiled from int __thiscall CEcoSector::PrioBoards(CEcoSector *this)
int  CEcoSector::PrioBoards(void)const {
  
  return *((unsigned __int8 *)this + 28);
}


// address=[0x1447840]
// Decompiled from int __thiscall CEcoSector::PrioStone(CEcoSector *this)
int  CEcoSector::PrioStone(void)const {
  
  return *((unsigned __int8 *)this + 29);
}


// address=[0x14478b0]
// Decompiled from int __thiscall CEcoSector::Size(CEcoSector *this)
int  CEcoSector::Size(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1473090]
// Decompiled from CEcoSector *__thiscall CEcoSector::SetProducedArmors(CEcoSector *this, unsigned int a2)
void  CEcoSector::SetProducedArmors(unsigned int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_DWORD *)this + 239) = a2;
  return result;
}


// address=[0x14730b0]
// Decompiled from CEcoSector *__thiscall CEcoSector::SetProducedBows(CEcoSector *this, unsigned int a2)
void  CEcoSector::SetProducedBows(unsigned int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_DWORD *)this + 238) = a2;
  return result;
}


// address=[0x14730d0]
// Decompiled from CEcoSector *__thiscall CEcoSector::SetProducedSpecial(CEcoSector *this, unsigned int a2)
void  CEcoSector::SetProducedSpecial(unsigned int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_DWORD *)this + 240) = a2;
  return result;
}


// address=[0x14730f0]
// Decompiled from CEcoSector *__thiscall CEcoSector::SetProducedSwords(CEcoSector *this, unsigned int a2)
void  CEcoSector::SetProducedSwords(unsigned int) {
  
  CEcoSector *result; // eax

  result = this;
  *((_DWORD *)this + 237) = a2;
  return result;
}


// address=[0x14e80e0]
// Decompiled from char *__thiscall CEcoSector::DecNrOfSoldierOrder(CEcoSector *this, int a2)
void  CEcoSector::DecNrOfSoldierOrder(int) {
  
  char *result; // eax

  result = (char *)this + a2;
  --*((_BYTE *)this + a2 + 852);
  return result;
}


// address=[0x15185a0]
// Decompiled from _BYTE *__thiscall CEcoSector::DecNrOfToolOrder(CEcoSector *this, int a2)
void  CEcoSector::DecNrOfToolOrder(int) {
  
  _BYTE *result; // eax

  result = (_BYTE *)std::vector<unsigned char>::operator[](a2);
  --*result;
  return result;
}


// address=[0x15185e0]
// Decompiled from _BYTE *__thiscall CEcoSector::DecNrOfWeaponOrder(CEcoSector *this, int a2)
void  CEcoSector::DecNrOfWeaponOrder(int) {
  
  _BYTE *result; // eax

  result = (_BYTE *)std::vector<unsigned char>::operator[](a2);
  --*result;
  return result;
}


// address=[0x1518620]
// Decompiled from int __thiscall CEcoSector::GetArmorsCounter(CMFCTasksPane *this)
unsigned int  CEcoSector::GetArmorsCounter(void) {
  
  return *((_DWORD *)this + 239);
}


// address=[0x1518640]
// Decompiled from int __thiscall CEcoSector::GetBowsCounter(CMFCTasksPane *this)
unsigned int  CEcoSector::GetBowsCounter(void) {
  
  return *((_DWORD *)this + 238);
}


// address=[0x1518660]
// Decompiled from int __thiscall CEcoSector::GetSpecialCounter(CMFCTasksPane *this)
unsigned int  CEcoSector::GetSpecialCounter(void) {
  
  return *((_DWORD *)this + 240);
}


// address=[0x1518680]
// Decompiled from int __thiscall CEcoSector::GetSwordsCounter(CMFCTasksPane *this)
unsigned int  CEcoSector::GetSwordsCounter(void) {
  
  return *((_DWORD *)this + 237);
}


// address=[0x15186a0]
// Decompiled from CEcoSector *__thiscall CEcoSector::IncArmorsCounter(CEcoSector *this)
void  CEcoSector::IncArmorsCounter(void) {
  
  CEcoSector *result; // eax

  result = this;
  ++*((_DWORD *)this + 239);
  return result;
}


// address=[0x15186d0]
// Decompiled from CEcoSector *__thiscall CEcoSector::IncBowsCounter(CEcoSector *this)
void  CEcoSector::IncBowsCounter(void) {
  
  CEcoSector *result; // eax

  result = this;
  ++*((_DWORD *)this + 238);
  return result;
}


// address=[0x1518700]
// Decompiled from CEcoSector *__thiscall CEcoSector::IncSpecialCounter(CEcoSector *this)
void  CEcoSector::IncSpecialCounter(void) {
  
  CEcoSector *result; // eax

  result = this;
  ++*((_DWORD *)this + 240);
  return result;
}


// address=[0x1518730]
// Decompiled from CEcoSector *__thiscall CEcoSector::IncSwordsCounter(CEcoSector *this)
void  CEcoSector::IncSwordsCounter(void) {
  
  CEcoSector *result; // eax

  result = this;
  ++*((_DWORD *)this + 237);
  return result;
}


// address=[0x1518760]
// Decompiled from int __thiscall CEcoSector::WeaponAutoProduction(CEcoSector *this)
int  CEcoSector::WeaponAutoProduction(void)const {
  
  return *((unsigned __int8 *)this + 896);
}


// address=[0x3d89494]
// [Decompilation failed for static unsigned long CEcoSector::m_iClassID]

// address=[0x142df50]
// Decompiled from CEcoSector *__thiscall CEcoSector::IncSize(CEcoSector *this)
void  CEcoSector::IncSize(void) {
  
  CEcoSector *result; // eax

  result = this;
  ++*((_DWORD *)this + 1);
  return result;
}


// address=[0x142df70]
// Decompiled from CEcoSector *__thiscall CEcoSector::DecSize(CEcoSector *this)
void  CEcoSector::DecSize(void) {
  
  CEcoSector *result; // eax

  result = this;
  --*((_DWORD *)this + 1);
  return result;
}


// address=[0x142df90]
// Decompiled from CEcoSector *__thiscall CEcoSector::CEcoSector(CEcoSector *this, int a2, int a3)
 CEcoSector::CEcoSector(int,int) {
  
  int v3; // eax
  unsigned __int8 v4; // al
  int v5; // eax
  int v6; // eax
  int v8; // [esp+8h] [ebp-2Ch]
  int BuildingInfo; // [esp+Ch] [ebp-28h]
  int k; // [esp+10h] [ebp-24h]
  int j; // [esp+14h] [ebp-20h]
  int i; // [esp+18h] [ebp-1Ch]
  char v14; // [esp+23h] [ebp-11h] BYREF
  char v15; // [esp+24h] [ebp-10h] BYREF
  char v16; // [esp+25h] [ebp-Fh] BYREF
  char v17; // [esp+26h] [ebp-Eh] BYREF
  char v18; // [esp+27h] [ebp-Dh] BYREF
  int v19; // [esp+30h] [ebp-4h]

  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CEcoSector::_vftable_;
  std::vector<std::deque<unsigned short>>::vector<std::deque<unsigned short>>();
  v19 = 10;
  std::vector<std::vector<unsigned short>>::vector<std::vector<unsigned short>>();
  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>();
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>();
  std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::vector<CEcoSector::SECO_STORAGE_GOOD_REG>();
  v3 = CPlayerManager::Race(a2);
  CBuildingSupplyPriority::CBuildingSupplyPriority((CEcoSector *)((char *)this + 556), v3);
  v4 = CPlayerManager::Race(a2);
  CGoodTransportPriority::CGoodTransportPriority((CEcoSector *)((char *)this + 572), v4);
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  std::vector<unsigned char>::vector<unsigned char>();
  *((_DWORD *)this + 237) = 0;
  *((_DWORD *)this + 238) = 0;
  *((_DWORD *)this + 239) = 0;
  *((_DWORD *)this + 240) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_WORD *)this + 8) = a3;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = -1;
  *((_BYTE *)this + 18) = a2;
  *((_BYTE *)this + 19) = 0;
  *((_BYTE *)this + 20) = 0;
  *((_BYTE *)this + 28) = 0;
  *((_BYTE *)this + 29) = 0;
  *((_BYTE *)this + 21) = 0;
  *((_BYTE *)this + 22) = 0;
  *((_WORD *)this + 12) = 0;
  *((_WORD *)this + 13) = 0;
  *((_BYTE *)this + 30) = 0;
  *((_WORD *)this + 16) = 5;
  *((_WORD *)this + 17) = 0;
  *((_BYTE *)this + 896) = 100;
  memset((char *)this + 36, 0, 0x86u);
  memset((char *)this + 170, 0, 0x86u);
  memset((char *)this + 304, 0, 0x56u);
  memset((char *)this + 472, 0, 0x54u);
  memset((char *)this + 672, 0, 5u);
  memset((char *)this + 677, 0, 2u);
  memset((char *)this + 680, 0, 0x56u);
  memset((char *)this + 766, 0, 0x56u);
  std::vector<std::deque<unsigned short>>::resize(43);
  memset((char *)this + 852, 0, 0xAu);
  v5 = CPlayerManager::Race(*((unsigned __int8 *)this + 18));
  BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v5, 22);
  for ( i = 0; i < *(char *)(BuildingInfo + 57); ++i )
  {
    if ( !*(_BYTE *)(BuildingInfo + 16 * i + 63) )
    {
      v18 = *(_BYTE *)(BuildingInfo + 16 * i + 62);
      std::vector<unsigned char>::push_back(&v18);
      v17 = 0;
      std::vector<unsigned char>::push_back(&v17);
      v16 = 0;
      std::vector<unsigned char>::push_back(&v16);
    }
  }
  if ( std::vector<unsigned char>::size((char *)this + 932) == 4 )
  {
    byte_3F1E8D8[0] = 50;
    byte_3F1E8D8[12] = 50;
    byte_3F1E8D8[24] = 0;
    byte_3F1E8D8[36] = 0;
  }
  else
  {
    byte_3F1E8D8[0] = 50;
    byte_3F1E8D8[12] = 50;
    byte_3F1E8D8[24] = 0;
  }
  for ( j = 0; j < std::vector<unsigned char>::size((char *)this + 932); ++j )
    *(_BYTE *)std::vector<unsigned char>::operator[](j) = byte_3F1E8D8[12 * j];
  v6 = CPlayerManager::Race(*((unsigned __int8 *)this + 18));
  v8 = CBuildingInfoMgr::GetBuildingInfo(v6, 21);
  for ( k = 0; k < *(char *)(v8 + 57); ++k )
  {
    if ( !*(_BYTE *)(v8 + 16 * k + 63) )
    {
      v15 = *(_BYTE *)(v8 + 16 * k + 62);
      std::vector<unsigned char>::push_back(&v15);
      v14 = 0;
      std::vector<unsigned char>::push_back(&v14);
    }
  }
  CEcoSectorMgr::RegisterEcoSector((CEcoSectorMgr *)g_cESMgr, a3, this, 1);
  BBSupportTracePrintF(
    0,
    "CEcoSector::CEcoSector(): owner %i, eco-sector %i, unique id 0x%08x.",
    a2,
    *((unsigned __int16 *)this + 8),
    *((_DWORD *)this + 3));
  return this;
}


// address=[0x142e4a0]
// Decompiled from int __thiscall CEcoSector::~CEcoSector(CEcoSector *this)
 CEcoSector::~CEcoSector(void) {
  
  *(_DWORD *)this = &CEcoSector::_vftable_;
  BBSupportTracePrintF(
    0,
    "CEcoSector::~CEcoSector(): owner %i, eco-sector %i, unique id 0x%08x.",
    *((unsigned __int8 *)this + 18),
    *((unsigned __int16 *)this + 8),
    *((_DWORD *)this + 3));
  *((_DWORD *)this + 3) = -1;
  std::vector<unsigned char>::~vector<unsigned char>();
  std::vector<unsigned char>::~vector<unsigned char>();
  std::vector<unsigned char>::~vector<unsigned char>();
  std::vector<unsigned char>::~vector<unsigned char>();
  std::vector<unsigned char>::~vector<unsigned char>();
  CBuildingSupplyPriority::~CBuildingSupplyPriority((CEcoSector *)((char *)this + 556));
  std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::~vector<CEcoSector::SECO_STORAGE_GOOD_REG>();
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::~vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>();
  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::~vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>();
  std::vector<std::vector<unsigned short>>::~vector<std::vector<unsigned short>>();
  return std::vector<std::deque<unsigned short>>::~vector<std::deque<unsigned short>>();
}


// address=[0x142e5b0]
// Decompiled from int __thiscall CEcoSector::SetWorldIdxForStore(CEcoSector *this, int a2)
void  CEcoSector::SetWorldIdxForStore(int) {
  
  int v3; // [esp+4h] [ebp-8h]

  *((_DWORD *)this + 2) = a2;
  if ( a2 < 0 )
    v3 = 0;
  else
    v3 = ITiling::EcoSectorId(a2);
  if ( !*((_WORD *)this + 8) && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 815, "m_iEcoSectorId > 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int16 *)this + 8) != v3
    && BBSupportDbgReport(2, "Logic\\EcoSector.cpp", 816, "m_iEcoSectorId == iEcoSectorId") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x142e650]
// Decompiled from CEcoSector *__thiscall CEcoSector::ResetBuildingSitesWithPrio(CEcoSector *this)
void  CEcoSector::ResetBuildingSitesWithPrio(void) {
  
  CEcoSector *result; // eax

  *((_BYTE *)this + 20) = 0;
  *((_BYTE *)this + 21) = 0;
  *((_BYTE *)this + 22) = 0;
  *((_WORD *)this + 12) = 0;
  result = this;
  *((_WORD *)this + 13) = 0;
  *((_BYTE *)this + 28) = 0;
  *((_BYTE *)this + 29) = 0;
  return result;
}


// address=[0x142e690]
// Decompiled from char __thiscall CEcoSector::MissingToolWarning(CEcoSector *this, int a2, int a3, int a4, int a5, int a6)
void  CEcoSector::MissingToolWarning(int,int,int,int,int) {
  
  char result; // al

  result = a2;
  switch ( a2 )
  {
    case 4:
      result = CTextMsgHandler::AddWarningMsg(2453, a6, a4, a5);
      break;
    case 8:
      result = CTextMsgHandler::AddWarningMsg(313, a6, a4, a5);
      break;
    case 18:
      if ( a3 != 3 )
        result = CTextMsgHandler::AddWarningMsg(2454, a6, a4, a5);
      break;
    case 25:
      result = CTextMsgHandler::AddWarningMsg(2455, a6, a4, a5);
      break;
    case 27:
      result = CTextMsgHandler::AddWarningMsg(2456, a6, a4, a5);
      break;
    case 28:
      result = CTextMsgHandler::AddWarningMsg(2457, a6, a4, a5);
      break;
    case 29:
      result = CTextMsgHandler::AddWarningMsg(2458, a6, a4, a5);
      break;
    case 31:
      if ( a3 != 2 )
        result = CTextMsgHandler::AddWarningMsg(2460, a6, a4, a5);
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x142e800]
// Decompiled from int __thiscall CEcoSector::ChangeValue(CEcoSector *this, int a2, int a3, int a4)
int  CEcoSector::ChangeValue(int,int,int) {
  
  if ( !a4 )
    return 0;
  if ( a4 == 100 )
    return 99;
  if ( a4 <= 0 )
  {
    if ( a4 + a3 + a2 >= 0 )
      return a4 + a3;
    else
      return -a2;
  }
  else if ( a4 + a3 < 100 )
  {
    return a4 + a3;
  }
  else
  {
    return 99;
  }
}


// address=[0x142e880]
// Decompiled from int __thiscall CEcoSector::GetRegisteredFreeStoragePile(CEcoSector *this, int a2, int a3)
int  CEcoSector::GetRegisteredFreeStoragePile(int,int) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::size((char *)this + 424) )
    return -1;
  for ( i = 0; i < std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::size((char *)this + 424); ++i )
  {
    if ( *(_DWORD *)std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::operator[](i) == a2
      && *(_DWORD *)(std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::operator[](i) + 4) == a3 )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x142e910]
// Decompiled from int __thiscall CEcoSector::GetRegisteredGoodStoragePile(CEcoSector *this, int a2, int a3, int a4)
int  CEcoSector::GetRegisteredGoodStoragePile(int,int,int) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::size((char *)this + 440) )
    return -1;
  for ( i = 0; i < std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::size((char *)this + 440); ++i )
  {
    if ( *(_DWORD *)std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::operator[](i) == a2
      && *(_DWORD *)(std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::operator[](i) + 4) == a3
      && *(_DWORD *)(std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::operator[](i) + 8) == a4 )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x142e9c0]
// Decompiled from int __thiscall CEcoSector::GetRegisteredGoodStorage(CEcoSector *this, int a2, int a3)
int  CEcoSector::GetRegisteredGoodStorage(int,int) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::size((char *)this + 456) )
    return -1;
  for ( i = 0; i < std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::size((char *)this + 456); ++i )
  {
    if ( *(_DWORD *)std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](i) == a2
      && *(_DWORD *)(std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::operator[](i) + 4) == a3 )
    {
      return i;
    }
  }
  return -1;
}


// address=[0x142ea50]
// Decompiled from int __thiscall CEcoSector::ClearAllStorageRegistrations(void *this)
void  CEcoSector::ClearAllStorageRegistrations(void) {
  
  int v2; // [esp+0h] [ebp-4h]
  int v3; // [esp+0h] [ebp-4h]

  std::vector<CEcoSector::SECO_FREE_STORAGE_PILE_REG>::clear(this);
  std::vector<CEcoSector::SECO_GOOD_STORAGE_PILE_REG>::clear(v2);
  return std::vector<CEcoSector::SECO_STORAGE_GOOD_REG>::clear(v3);
}


// address=[0x142ea90]
// Decompiled from void __thiscall CEcoSector::ReregisterAllStorageRegistrations(int this)
void  CEcoSector::ReregisterAllStorageRegistrations(void) {
  
  CStorageBuildingRole *v1; // eax
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]
  int FirstBuildingId; // [esp+8h] [ebp-8h]

  FirstBuildingId = CBuildingMgr::GetFirstBuildingId(
                      (CBuildingMgr *)g_cBuildingMgr,
                      *(unsigned __int8 *)(this + 18),
                      34);
  while ( FirstBuildingId )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
    if ( CBuilding::EcoSectorId(BuildingPtr) == *(unsigned __int16 *)(this + 16) )
    {
      v1 = (CStorageBuildingRole *)CBuilding::Role(BuildingPtr);
      CStorageBuildingRole::RegisterPilesAndStorageAtEcosector(v1, *(unsigned __int16 *)(this + 16));
    }
  }
}


