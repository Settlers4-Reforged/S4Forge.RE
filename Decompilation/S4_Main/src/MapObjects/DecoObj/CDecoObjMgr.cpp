#include "CDecoObjMgr.h"

#include <algorithm>
#include <sstream>
#include <strstream>

#include "CDecoObject.h"
#include "CHive.h"
#include "CMushroom.h"
#include "CPlant.h"
#include "CShadowHerb.h"
#include "IDecoObject.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CConfigManager/CConfigManager.h"
#include "CConfigManager/CConfigManagerPtr.h"
#include "Defines/Goods.h"
#include "Defines/Map.h"
#include "Defines/Object.h"
#include "Defines/World.h"
#include "Logic/CRandom16.h"
#include "Main/CS4DefineNames.h"
#include "MapObjects/IAnimatedEntity.h"
#include "MapObjects/IEntity.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/CSpiralOffsets.h"
#include "Pathing/ITiling.h"
#include "World/CWorldManager.h"
#include "World/helper.h"
#include "XMLParser/AdvXMLParser.h"

// Definitions for class CDecoObjMgr

// address=[0x40f2320]
CDecoObjMgr g_cDecoObjMgr{};

// address=[0x1326ec0]
// Decompiled from IEntity *__cdecl CDecoObjMgr::GetDecoObjPtr(int a1)
IDecoObject * __cdecl CDecoObjMgr::GetDecoObjPtr(int a1) {
  // [esp+8h] [ebp-4h]

  IEntity *v3 = CMapObjectMgr::EntityPtr(a1);
  if(v3 && v3->ObjType() == DECO_OBJ_2)
    return dynamic_cast<IDecoObject *>(v3);
  else
    return nullptr;
}


// address=[0x1486f90]
// Decompiled from int __thiscall CDecoObjMgr::GetXMLVersion(CDecoObjMgr *this)
int CDecoObjMgr::GetXMLVersion(void) const {
  return this->m_iXmlVersion;
}


// address=[0x15423a0]
// Decompiled from uint __thiscall CDecoObjMgr::Alloc(CDecoObjMgr *this, uint a2)
void *CDecoObjMgr::Alloc(unsigned int a2) {
  return this->m_cAllocator.allocate(/*a2*/);
}


// address=[0x1542400]
// Decompiled from void __thiscall CDecoObjMgr::Dealloc(CDecoObjMgr *this, uint *a2)
void CDecoObjMgr::Dealloc(void *a2) {
  this->m_cAllocator.deallocate(a2);
}


// address=[0x1542430]
// Decompiled from int __thiscall CDecoObjMgr::GetTotalBuildingRings(CDecoObjMgr *this, int a2)
int CDecoObjMgr::GetTotalBuildingRings(int a2) {
  return this->m_aBuildingRings[a2].m_uTotalRings;
}


// address=[0x1542490]
// Decompiled from CDecoObjMgr *__thiscall CDecoObjMgr::CDecoObjMgr(CDecoObjMgr *this)
CDecoObjMgr::CDecoObjMgr(void) : m_cAllocator(84, 32, 0) { //TODO: this could be wrong wrt allocator
  this->m_iXmlVersion = 0;
  this->m_bHasLoaded = 0;
  memset(this->m_aBuildingRings, 0, sizeof(this->m_aBuildingRings));
  CDecoObjMgr::Clear();
}


// address=[0x15425c0]
// Decompiled from void __thiscall CDecoObjMgr::~CDecoObjMgr(CDecoObjMgr *this)
CDecoObjMgr::~CDecoObjMgr(void) = default;


// address=[0x15425e0]
// Decompiled from void *__thiscall CDecoObjMgr::Clear(CDecoObjMgr *this)
void CDecoObjMgr::Clear(void) {
  memset(this->m_vInstanceId, 0, sizeof(this->m_vInstanceId));
}


// address=[0x1542610]
// Decompiled from void __thiscall CDecoObjMgr::LoadInfo(CDecoObjMgr *this)
void CDecoObjMgr::LoadInfo(void) {
  if(!this->m_bHasLoaded)
    CDecoObjMgr::ReadObjectInfos();
  this->m_bHasLoaded = 1;
}


// address=[0x1542640]
// Decompiled from char __thiscall CDecoObjMgr::IsAddDecoObjOk(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  bool a5,  int _iExtraBuildingRings)
bool CDecoObjMgr::IsAddDecoObjOk(int _iX, int _iY, int _iDecoType, bool a5, int _iExtraBuildingRings) {
  int  iTotalRings; // [esp+Ch] [ebp-30h] BYREF
  int  iTotalBlockingOrRepellingRings; // [esp+2Ch] [ebp-10h] BYREF
  bool v21; // [esp+3Bh] [ebp-1h] BYREF

  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  BB_ASSERT(_iExtraBuildingRings >= 0)

  if(!CWorldManager::InWorld(_iX, _iY))
    return 0;
  if(CWorldManager::FlagBits(_iX, _iY, 0x7Bu))
    return 0;
  if(!a5 && CWorldManager::ObjectId(_iX, _iY))
    return 0;
  CDecoObjMgr::GetDecoObjectFlagsInfo(_iDecoType, v21, iTotalBlockingOrRepellingRings, iTotalRings);
  if(v21) {
    BB_ASSERT(iTotalBlockingOrRepellingRings == 1)
  } else {
    int v11 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
    for(int i = 0; i < v11; ++i) {
      unsigned int v16 = _iX + CSpiralOffsets::DeltaX(i);
      unsigned int v17 = _iY + CSpiralOffsets::DeltaY(i);
      if(!CWorldManager::InWorld(v16, v17))
        return 0;
      int v15 = CWorldManager::Index(v16, v17);
      if(CWorldManager::MapObjectId(v15))
        return 0;
      if(CWorldManager::FlagBits(v15, 0x7Bu))
        return 0;
    }
  }
  int v9 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
  int v8 = CSpiralOffsets::First(_iExtraBuildingRings + iTotalRings);
  for(int j = v9; j < v8; ++j) {
    unsigned int v13 = _iX + CSpiralOffsets::DeltaX(j);
    unsigned int v14 = _iY + CSpiralOffsets::DeltaY(j);
    if(!CWorldManager::InWorld(v13, v14))
      return 0;
    int v7 = CWorldManager::Index(v13, v14);
    if(CWorldManager::FlagBits(v7, 0x7Bu))
      return 0;
  }
  return 1;
}


// address=[0x15428b0]
// Decompiled from int __thiscall CDecoObjMgr::AddDecoObj(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoType,  int _iAmount,  int _iGrownState)
int CDecoObjMgr::AddDecoObj(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState) {
  // [esp+4h] [ebp-8h]

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  int v7 = CDecoObjMgr::Create(_iX, _iY, _iDecoType, _iAmount, _iGrownState, 0, 0);
  CDecoObjMgr::SetFlagsForObject(_iX, _iY, _iDecoType, 0);
  return v7;
}


// address=[0x1542970]
// Decompiled from int __thiscall CDecoObjMgr::AddReef(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  int _iAmount,  int _iGrownState)
int CDecoObjMgr::AddReef(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState) {
  // [esp+0h] [ebp-14h]
  // [esp+4h] [ebp-10h]
  ; // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  int v7 = CDecoObjMgr::Create(_iX, _iY, _iDecoType, _iAmount, _iGrownState, 0, nullptr);
  int v8 = CWorldManager::Index(_iX, _iY);
  int v11 = CWorldManager::ObjectId(v8);
  if(!v11)
    return v7;
  IDecoObject *DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v11);
  if(!DecoObjPtr)
    return v7;
  if(DecoObjPtr->Type() == _iDecoType)
    CDecoObjMgr::SetFlagsForObject(_iX, _iY, _iDecoType, 1);
  else
    BBSupportTracePrintF(3, "Reef couldn't be set!");
  return v7;
}


// address=[0x1542a80]
// Decompiled from int __thiscall CDecoObjMgr::AddDecoObjWithoutFlags(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iType,  unsigned int _iAmount,  int _iGrownState)
int CDecoObjMgr::AddDecoObjWithoutFlags(int _iX, int _iY, int _iDecoType, int _iAmount, TGROWN_STATE _iGrownState) {
  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  BB_ASSERT(_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT)

  return CDecoObjMgr::Create(_iX, _iY, _iDecoType, _iAmount, _iGrownState, 0, 0);
}


// address=[0x1542b50]
// Decompiled from int __thiscall CDecoObjMgr::AddLoadedDecoObj(  CDecoObjMgr *this,  int _iX,  int _iY,  T_OBJECT_TYPE _iType,  unsigned int _iAmount,  int _iSlot,  char a7,  int _pInStream)
int CDecoObjMgr::AddLoadedDecoObj(int _iX, int _iY, int _iDecoType, int _iAmount, int _iSlot, bool bIsStaticInstance, std::istream *_pInStream) {
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  BB_ASSERT(_iAmount>=0 && _iAmount<MAX_RESOURCE_AMOUNT)
  if(bIsStaticInstance)
    return CDecoObjMgr::Create(_iX, _iY, _iDecoType, _iAmount, GROW2, _iSlot, _pInStream);
  else
    return CDecoObjMgr::Create(_iX, _iY, _iDecoType, _iAmount, GROW1, _iSlot, _pInStream);
}


// address=[0x1542c20]
// Decompiled from void __thiscall CDecoObjMgr::Delete(CDecoObjMgr *this, int _iEntityId)
void CDecoObjMgr::Delete(int _iEntityId) {
  if(_iEntityId) {
    BB_ASSERT(GetDecoObjPtr( _iEntityId ) != 0)
    BB_ASSERT(GetDecoObjPtr( _iEntityId )->IsStaticInstance() == false)

    IEntity &    v7 = CMapObjectMgr::Entity(_iEntityId);
    int          v5 = v7.Type();
    unsigned int v4 = v7.Y();
    unsigned int v3 = v7.X();
    CDecoObjMgr::ClearFlagsForObject(v3, v4, v5, 0);
    g_pMapObjectMgr->Destroy(_iEntityId);
  }
}


// address=[0x1542cf0]
// Decompiled from void __thiscall CDecoObjMgr::DeleteWithoutFlags(CDecoObjMgr *this, int _iEntityId)
void CDecoObjMgr::DeleteWithoutFlags(int _iEntityId) {
  // [esp+8h] [ebp-4h]

  if(_iEntityId) {
    IDecoObject *pDecoObj = (IDecoObject *) CDecoObjMgr::GetDecoObjPtr(_iEntityId);
    BB_ASSERT(pDecoObj != 0)

    if(pDecoObj) {
      BB_ASSERT(pDecoObj->IsStaticInstance() == false)
      g_pMapObjectMgr->Entity(_iEntityId);
      g_pMapObjectMgr->Destroy(_iEntityId);
    }
  }
}


// address=[0x1542da0]
// Decompiled from int __thiscall CDecoObjMgr::RemoveDecoObject(CDecoObjMgr *this, unsigned int _iX, unsigned int _iY, bool a4)
int CDecoObjMgr::RemoveDecoObject(int _iX, int _iY, bool a4) {
  // eax
  // [esp+4h] [ebp-Ch]
  // [esp+Ch] [ebp-4h]

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))

  int iWorldIdx = CWorldManager::Index(_iX, _iY);
  int v7 = CWorldManager::ObjectId(iWorldIdx);
  if(!v7)
    return 0;
  IDecoObject *DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v7);
  if(!DecoObjPtr)
    return -1;
  if(DecoObjPtr->IsStaticInstance()) {
    CWorldManager::SetObjectId(iWorldIdx, 0);
    CDecoObjMgr::ClearFlagsForObject(_iX, _iY, DecoObjPtr->Type(), 0);
  } else if(!a4) {
    CDecoObjMgr::Delete(v7);
    BB_ASSERT(g_cWorld.ObjectId( iWorldIdx ) == 0)
  }
  CWorldManager::SetResource(iWorldIdx, 0, 0);
  return 1;
}


// address=[0x1542ed0]
// Decompiled from int __thiscall CDecoObjMgr::RemoveReef(CDecoObjMgr *this, unsigned int _iX, unsigned int _iY, bool a4)
int CDecoObjMgr::RemoveReef(int _iX, int _iY, bool a4) {
  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))

  int iWorldIdx = CWorldManager::Index(_iX, _iY);
  int v7 = CWorldManager::ObjectId(iWorldIdx);
  if(!v7)
    return 0;
  IDecoObject *DecoObjPtr = CDecoObjMgr::GetDecoObjPtr(v7);
  if(!DecoObjPtr)
    return -1;
  if(DecoObjPtr->IsStaticInstance()) {
    CWorldManager::SetObjectId(iWorldIdx, 0);
    int v4 = DecoObjPtr->Type();
    CDecoObjMgr::ClearFlagsForObject(_iX, _iY, v4, 1);
  } else if(!a4) {
    CDecoObjMgr::Delete(v7);
    BB_ASSERT(g_cWorld.ObjectId( iWorldIdx ) == 0)
  }
  CWorldManager::SetResource(iWorldIdx, 0, 0);
  return 1;
}


// address=[0x1543000]
// Decompiled from int __thiscall CDecoObjMgr::GetDecoObjectFlagsInfo(  CDecoObjMgr *this,  T_OBJECT_TYPE _iDecoType,  BYTE *a3,  int *_rTotalBlockingOrRepellingRing,  int *_rTotalRings)
void CDecoObjMgr::GetDecoObjectFlagsInfo(int _iDecoType, bool &a3, int &_rTotalBlockingOrRepellingRing, int &_rTotalRings) {
  // eax
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)

  a3 = this->m_aBuildingRings[_iDecoType].m_uUnknown;
  _rTotalBlockingOrRepellingRing = this->m_aBuildingRings[_iDecoType].m_uTotalBlockingOrRepellingRings;
  _rTotalRings = this->m_aBuildingRings[_iDecoType].m_uTotalRings;
}


// address=[0x1543080]
// Decompiled from int __thiscall CDecoObjMgr::SetFlagsForObject(CDecoObjMgr *this, int a2, int a3, int a4, bool a5)
void CDecoObjMgr::SetFlagsForObject(int _iX, int _iY, int _iDecoType, bool _bReefs) {
  int result; // eax
  // [esp+0h] [ebp-48h]
  // [esp+4h] [ebp-44h]
  int iTotalRings; // [esp+8h] [ebp-40h] BYREF
  // [esp+Ch] [ebp-3Ch]
  // [esp+10h] [ebp-38h]
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h]
  int v13; // [esp+1Ch] [ebp-2Ch]
  // [esp+20h] [ebp-28h]
  // [esp+24h] [ebp-24h]
  // [esp+28h] [ebp-20h]
  // [esp+2Ch] [ebp-1Ch]
  int iTotalBlockingOrRepellingRings; // [esp+30h] [ebp-18h] BYREF
  // [esp+34h] [ebp-14h]
  // [esp+38h] [ebp-10h]
  // [esp+3Ch] [ebp-Ch]
  int  j; // [esp+40h] [ebp-8h]
  bool v23; // [esp+47h] [ebp-1h] BYREF


  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)
  CDecoObjMgr::GetDecoObjectFlagsInfo(_iDecoType, v23, iTotalBlockingOrRepellingRings, iTotalRings);
  if(v23) {
    BB_ASSERT(iTotalBlockingOrRepellingRings == 1)
    BB_ASSERT(g_cWorld.FlagBits( _iX, _iY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0)
    CWorldManager::SetFlagBits(_iX, _iY, 2);
    CWorldManager::SetFlagBits(_iX, _iY, 64);
  } else {
    int v9 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
    for(int i = 0; i < v9; ++i) {
      int iWorkX = _iX + CSpiralOffsets::DeltaX(i);
      int iWorkY = _iY + CSpiralOffsets::DeltaY(i);
      BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))
      BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0)
      CWorldManager::SetBlockedPosition(iWorkX, iWorkY);
      CWorldManager::SetFlagBits(iWorkX, iWorkY, 64);
      if(_bReefs) g_pTiling->SetBlockedWater(iWorkX, iWorkY);
    }
  }
  int v7 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
  int v6 = CSpiralOffsets::First(iTotalRings);
  for(j = v7; ; ++j) {
    if(j >= v6)
      break;
    int iWorkX = _iX + CSpiralOffsets::DeltaX(j);
    int iWorkY = _iY + CSpiralOffsets::DeltaY(j);
    BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))
    BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, _bReefs?REEF_CHECK_FLAGS_MASK:DECO_OBJ_CHECK_FLAGS_MASK ) == 0)
    CWorldManager::SetFlagBits(iWorkX, iWorkY, 64);
  }
  if(_bReefs) {
    for(j = 0; j < 100; ++j) {
      int iWorkX = _iX + CSpiralOffsets::DeltaX(j);
      int iWorkY = _iY + CSpiralOffsets::DeltaY(j);
      BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))
      BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, FLAG_REPELLING_LAND | FLAG_BUILDING | FLAG_DIG | FLAG_WORK ) == 0)
      g_pTiling->SetBlockedWater(iWorkX, iWorkY);
    }
  }
}


// address=[0x15434b0]
// Decompiled from void __thiscall CDecoObjMgr::ClearFlagsForObject(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  int _iDecoType,  bool a5)
void CDecoObjMgr::ClearFlagsForObject(int _iX, int _iY, int _iDecoType, bool a5) {
  // [esp+0h] [ebp-3Ch]
  // [esp+4h] [ebp-38h]
  int v7; // [esp+8h] [ebp-34h] BYREF
  // [esp+Ch] [ebp-30h]
  int iTotalBlockingOrRepellingRings; // [esp+24h] [ebp-18h] BYREF
  int iWorkX; // [esp+28h] [ebp-14h] MAPDST
  int iWorkY; // [esp+2Ch] [ebp-10h] MAPDST
  // [esp+30h] [ebp-Ch]
  int  j; // [esp+34h] [ebp-8h]
  bool v19; // [esp+3Bh] [ebp-1h] BYREF

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(_iDecoType > 0 && _iDecoType < OBJECT_MAX)

  CDecoObjMgr::GetDecoObjectFlagsInfo(_iDecoType, v19, iTotalBlockingOrRepellingRings, v7);
  if(v19) {
    BB_ASSERT(iTotalBlockingOrRepellingRings == 1)

    BB_ASSERT(g_cWorld.FlagBits( _iX, _iY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0)
    CWorldManager::ClearFlagBits(_iX, _iY, FLAG_REPELLING_LAND);
    CWorldManager::ClearFlagBits(_iX, _iY, 64);
  } else {
    int v8 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
    for(int i = 0; i < v8; ++i) {
      iWorkX = _iX + CSpiralOffsets::DeltaX(i);
      iWorkY = _iY + CSpiralOffsets::DeltaY(i);
      BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))

      BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0)
      CWorldManager::ClearBlockedPosition(iWorkX, iWorkY);
      CWorldManager::ClearFlagBits(iWorkX, iWorkY, 64);
      if(a5)
        g_pTiling->ClearBlockedWater(iWorkX, iWorkY);
    }
  }
  int v6 = CSpiralOffsets::First(iTotalBlockingOrRepellingRings);
  int v5 = CSpiralOffsets::First(v7);
  for(j = v6; j < v5; ++j) {
    iWorkX = _iX + CSpiralOffsets::DeltaX(j);
    iWorkY = _iY + CSpiralOffsets::DeltaY(j);
    BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))
    BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, DECO_OBJ_CHECK_FLAGS_MASK ) != 0)
    CWorldManager::ClearFlagBits(iWorkX, iWorkY, 64);
  }
  if(a5) {
    for(j = 0; j < 100; ++j) {
      iWorkX = _iX + CSpiralOffsets::DeltaX(j);
      iWorkY = _iY + CSpiralOffsets::DeltaY(j);
      BB_ASSERT(g_cWorld.InWorld( iWorkX, iWorkY ))
      BB_ASSERT(g_cWorld.FlagBits( iWorkX, iWorkY, FLAG_REPELLING_LAND | FLAG_BUILDING | FLAG_DIG | FLAG_WORK ) == 0)
      g_pTiling->ClearBlockedWater(iWorkX, iWorkY);
    }
  }
}


// address=[0x15438a0]
// Decompiled from T_OBJECT_TYPE __thiscall CDecoObjMgr::GetObjectType(CDecoObjMgr *this, int _iFarmerType, int _iRace, char _iGround)
int CDecoObjMgr::GetObjectType(int _iFarmerType, int _iRace, int _iGround) {
  unsigned int v5; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-14h]
  // [esp+10h] [ebp-Ch]

  switch(_iFarmerType) {
    case 0:
      return OBJECT_GRAPE;
    case 1:
      return OBJECT_AGAVE;
    case 2: {
      if(_iRace == 2) {
        if((_iGround & 0xF0) == 0x40)
          return (g_pGameData->Rand() & 1) + 11;
        return (g_pGameData->Rand() & 1) + 13;
      }
      if(_iRace == 4) {
        int v7;
        if((_iGround & 0xF0) == 0x40)
          return (g_pGameData->Rand() & 1) + 11;
        char v8 = g_pGameData->Rand();
        if((v8 & 6) != 0)
          v7 = 15;
        else
          v7 = 17;
        return v7 + (v8 & 1);
      } else {
        return (g_pGameData->Rand() & 1) + 9;
      }
    }
    case 3:
      v5 = g_pGameData->Rand();
      if(v5 >= CRandom16::PercentValue(0x32u))
        return OBJECT_WHEAT2;
      else
        return OBJECT_WHEAT1;
    case 4:
      v6 = g_pGameData->Rand();
      if(v6 < CRandom16::PercentValue(0x1Eu))
        return OBJECT_MUSHROOM_DARK1;
      if(v6 >= CRandom16::PercentValue(0x46u))
        return OBJECT_MUSHROOM_DARK3;
      return OBJECT_MUSHROOM_DARK2;
    case 5:
      return OBJECT_SHADOWHERB;
    case 6:
      return OBJECT_HIVE;
    case 7:
      return OBJECT_SUNFLOWER;
    default:
      return 0;
  }
}


// address=[0x1543a60]
// Decompiled from int __thiscall CDecoObjMgr::ChangeToStaticInstance(  CDecoObjMgr *this,  unsigned int _iX,  unsigned int _iY,  T_OBJECT_TYPE _iDecoType,  unsigned int a5)
void CDecoObjMgr::ChangeToStaticInstance(int _iX, int _iY, int _iDecoType, int a5) {
  // eax
  IEntity *v6; // eax
  ; // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))

  int          iOldEntityId = CWorldManager::ObjectId(_iX, _iY);
  IDecoObject *pDecoObj = CDecoObjMgr::GetDecoObjPtr(iOldEntityId);
  BB_ASSERT(iOldEntityId != 0)
  BB_ASSERT(pDecoObj != 0)
  if(pDecoObj) {
    BB_ASSERT(GetDecoObjPtr( iOldEntityId )->IsStaticInstance() == false)
    BB_ASSERT(GetDecoObjPtr( iOldEntityId )->Type() == _iDecoType)
  }
  CDecoObjMgr::DeleteWithoutFlags(iOldEntityId);
  BB_ASSERT(g_cWorld.ObjectId( _iX, _iY ) == 0)
  CDecoObjMgr::AddDecoObjWithoutFlags(_iX, _iY, _iDecoType, a5, GROW2);
  BB_ASSERT(g_cWorld.ObjectId( _iX, _iY ) != 0)
}


// address=[0x1543c20]
// Decompiled from int __stdcall CDecoObjMgr::ConvertGreenToDark(int a1)
int CDecoObjMgr::ConvertGreenToDark(int a1) const {
  return 23;
}


// address=[0x1543c40]
// Decompiled from int __stdcall CDecoObjMgr::ConvertDarkToGreen(int a1)
int CDecoObjMgr::ConvertDarkToGreen(int a1) const {
  return 23;
}


// address=[0x1543c60]
// Decompiled from int __stdcall CDecoObjMgr::GetThisDecoObj(unsigned int _iX, unsigned int _iY, int _iRadius, int *_rX, int *_rY)
int CDecoObjMgr::GetThisDecoObj(int _iX, int _iY, int _iRadius, int &_rX, int &_rY) {
  IEntity *DecoObjPtr; // eax
  // [esp+4h] [ebp-14h]
  // [esp+8h] [ebp-10h]
  // [esp+Ch] [ebp-Ch]
  // [esp+10h] [ebp-8h]
  // [esp+14h] [ebp-4h]

  BB_ASSERT(g_cWorld.InWorld( _iX, _iY ))
  BB_ASSERT(g_cWorld.FlagBits( _iX, _iY, FLAG_DECO_OBJECT ))
  int v7 = CSpiralOffsets::Last(_iRadius);
  for(int i = 1; i < v7; ++i) {
    int iX = _iX + CSpiralOffsets::DeltaX(i);
    int iY = _iY + CSpiralOffsets::DeltaY(i);
    if(CWorldManager::FlagBits(iX, iY, 0x40u)) {
      int iObjectId = CWorldManager::ObjectId(iX, iY);
      if(iObjectId) {
        BB_ASSERT(GetDecoObjPtr( iObjectId ))
        if(CDecoObjMgr::GetDecoObjPtr(iObjectId)->Type() != OBJECT_SHADOWHERB) {
          _rX = iX;
          _rY = iY;
          return iObjectId;
        }
      }
    }
  }
  return 0;
}


// address=[0x1543dd0]
// Decompiled from bool __thiscall CDecoObjMgr::IsFlower(CDecoObjMgr *this, int _iDecoType)
bool CDecoObjMgr::IsFlower(int _iDecoType) {
  return _iDecoType == OBJECT_FLOWER1
         || _iDecoType == OBJECT_FLOWER2
         || _iDecoType == OBJECT_FLOWER3
         || _iDecoType == OBJECT_FLOWER4
         || _iDecoType == OBJECT_FLOWER5;
}


// address=[0x1543e20]
// Decompiled from bool __thiscall CDecoObjMgr::IsGeologistSign(CDecoObjMgr *this, int a2)
bool CDecoObjMgr::IsGeologistSign(int a2) {
  int iObjId = CWorldManager::ObjectId(a2);
  if(!iObjId)
    return 0;

  IEntity *pEntity = CMapObjectMgr::EntityPtr(iObjId);
  if(pEntity->ObjType() == DECO_OBJ_2
     && pEntity->Type() >= OBJECT_SHIELD_EMPTY
     && pEntity->Type() <= OBJECT_SHIELD_SULFUR3) {
    return 1;
  }
  return 0;
}


// address=[0x1543e90]
// Decompiled from void __thiscall CDecoObjMgr::Rod(CDecoObjMgr *this, int a2, bool a3)
void CDecoObjMgr::Rod(int a2, bool a3) {
  IEntity *v3; // [esp+48h] [ebp-88h]
  CPlant * v4; // [esp+50h] [ebp-80h]
  IEntity *v5; // [esp+54h] [ebp-7Ch]
  CPlant * v6; // [esp+5Ch] [ebp-74h]
  IEntity *v7; // [esp+60h] [ebp-70h]
  CPlant * v8; // [esp+68h] [ebp-68h]
  IEntity *v9; // [esp+6Ch] [ebp-64h]
  CPlant * v10; // [esp+74h] [ebp-5Ch]
  IEntity *v11; // [esp+78h] [ebp-58h]
  CPlant * v12; // [esp+80h] [ebp-50h]
  // [esp+84h] [ebp-4Ch]
  int v14; // [esp+88h] [ebp-48h]
  int v15; // [esp+8Ch] [ebp-44h]
  int v16; // [esp+90h] [ebp-40h]
  int v17; // [esp+94h] [ebp-3Ch]
  // [esp+98h] [ebp-38h]
  // [esp+9Ch] [ebp-34h]
  // [esp+ACh] [ebp-24h]
  // [esp+B0h] [ebp-20h]
  // [esp+B4h] [ebp-1Ch]
  // [esp+C0h] [ebp-10h]

  int v13 = CWorldManager::ObjectId(a2);
  if(v13) {
    IEntity *pEntity = CMapObjectMgr::EntityPtr(v13);
    if(pEntity->ObjType() == DECO_OBJ_2) {
      BB_ASSERT(dynamic_cast<IDecoObject*>(pEntity))
      auto *pDecoEntity = dynamic_cast<IDecoObject *>(pEntity);
      if(pDecoEntity->IsStaticInstance()) {
        int iJobPart = pDecoEntity->JobPart();
        int iX = CWorldManager::X(a2);
        int iY = CWorldManager::Y(a2);

        int iTakeAmount = 0;
        switch(pDecoEntity->Type()) {
          case OBJECT_GRAPE:
            if(iJobPart == OBJECT_GRAPE_CUT)
              break;
            iTakeAmount = 1;
            break;
          case OBJECT_WHEAT1:
            if(iJobPart == OBJECT_WHEAT1_ROT)
              break;
            iTakeAmount = 2;
            break;
          case OBJECT_WHEAT2:
            if(iJobPart == OBJECT_WHEAT2_ROT)
              break;
            iTakeAmount = 2;
            break;
          case OBJECT_AGAVE:
            if(iJobPart == OBJECT_AGAVE_ROT)
              break;
            iTakeAmount = 1;
            break;
          case OBJECT_SUNFLOWER:
            iTakeAmount = 2;
            break;
          default:
            return;
        }

        if(iTakeAmount) {
          int iFreeSlot = CMapObjectMgr::GetFreeSlot();
          BB_ASSERT(iFreeSlot != -1)
          if(iFreeSlot == -1)
            return;

          const auto cNewPlant = new CPlant(*dynamic_cast<CPlant *>(pDecoEntity), iFreeSlot, iX, iY);
          cNewPlant->Take(iTakeAmount);
        } else {
          CDecoObjMgr::RemoveDecoObject(iX, iY, 0);
        }

        return;
      }
      if(a3) {
        int iJobPart = pDecoEntity->JobPart();
        switch(pDecoEntity->Type()) {
          case OBJECT_GRAPE:
            if(iJobPart != OBJECT_GRAPE_GROWNUP)
              pEntity->Take(OBJECT_GRAPE_CUT - iJobPart);
            break;
          case OBJECT_WHEAT1:
            if(iJobPart != OBJECT_WHEAT1_GROWNUP)
              pEntity->Take(OBJECT_WHEAT1_ROT - iJobPart);
            break;
          case OBJECT_WHEAT2:
            if(iJobPart != OBJECT_WHEAT2_GROWNUP)
              pEntity->Take(OBJECT_WHEAT2_ROT - iJobPart);
            break;
          case OBJECT_AGAVE:
            if(iJobPart != OBJECT_AGAVE_GROWNUP)
              pEntity->Take(OBJECT_AGAVE_ROT - iJobPart);
            break;
          case OBJECT_HIVE:
            if(iJobPart != OBJECT_HIVE_FULL)
              pEntity->Take(OBJECT_HIVE_ROT2 - iJobPart);
            break;
          case OBJECT_SUNFLOWER:
            if(iJobPart != OBJECT_SUNFLOWER_GROWNUP)
              pEntity->Take(OBJECT_SUNFLOWER_ROT - iJobPart);
            break;
          default:
            return;
        }
      }
    }
  }
}


// address=[0x1544590]
// Decompiled from void __thiscall CDecoObjMgr::Store(CDecoObjMgr *this, struct S4::CMapFile *a2)
void CDecoObjMgr::Store(class S4::CMapFile &a2) {
  int i; // [esp+F4h] [ebp-14h]

  std::ostrstream sChunk{};
  //std::ostrstream::ostrstream(v4, 0, 0x40000LL, 2, 1);
  int v23 = 0;
  int iVersion = 1;
  sChunk << iVersion;
  sChunk << this->m_bHasLoaded;
  unsigned int iDecoCount = 0;
  int          iLastId = CMapObjectMgr::LastUsedId();
  for(i = 0; i <= iLastId; ++i) {
    IEntity *v11 = CMapObjectMgr::EntityPtr(i);
    IEntity *v16 = v11;
    if(v11) {
      int v10 = v16->ObjType();
      if(v10 == DECO_OBJ_2)
        ++iDecoCount;
    }
  }
  sChunk << iDecoCount;

  for(i = 0; i <= iLastId; ++i) {
    IEntity *pEntity = CMapObjectMgr::EntityPtr(i);
    if(pEntity) {
      int iObjectType = pEntity->ObjType();
      if(iObjectType == DECO_OBJ_2) {
        bool bIsStaticInstance = dynamic_cast<IDecoObject *>(pEntity)->IsStaticInstance();
        sChunk << bIsStaticInstance;
        pEntity->Store(sChunk);
      }
    }
  }
  sChunk.put(0);
  sChunk.freeze(true);

  //char * v2 = std::ostrstream::rdbuf((std::ostrstream *) v4);
  size_t uSize = sChunk.rdbuf()->pcount();//std::strstreambuf::pcount((std::strstreambuf *) v2);
  void * pSrc = sChunk.str();

  a2.SaveChunk(MAP_CHUNK_SAVE_DECOOBJECTS, 0, uSize, pSrc, false);
  sChunk.freeze(false);
}


// address=[0x1544810]
// Decompiled from void __thiscall CDecoObjMgr::Load(CDecoObjMgr *this, struct S4::CMapFile *arg0)
void CDecoObjMgr::Load(class S4::CMapFile &a2) {
  BBSupportTracePrintF(0, "DecoObjMgr load");
  CDecoObjMgr::Clear();
  int   a4 = 0;
  char *pData = (char *) a2.LoadChunk(MAP_CHUNK_SAVE_DECOOBJECTS, 0, a4, 0);
  if(pData) {
    std::istringstream sChunk(pData);

    int iFileVersion;
    sChunk >> iFileVersion;
    if(iFileVersion != 1) {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDecoObjMgr");
      throw CS4InvalidMapException();
    }
    sChunk >> this->m_bHasLoaded;
    unsigned int iCount = 0;
    sChunk >> iCount;
    for(unsigned int i = 0; i < iCount; ++i) {
      /*
    CDecoObjMgr:
  sChunk << bIsStaticInstance;
    CPersistence:
  classId = this->ClassID();
  a2 << classId;
    IEntity:
  outputFile << IEntity::FILE_FORMAT_VERSION;
  outputFile << this->m_nEntityId;
  outputFile << this->m_nType;
  outputFile << this->m_uPackedXY;
  outputFile << this->m_cHealth;
  outputFile << this->m_objType;
  outputFile << this->m_packedTribePlayer.m_cPacked;
  outputFile << this->m_iFlags;
  outputFile << this->m_iUniqueId;
    IAnimatedEntity:
  int iFileVersion = 1;
  _rStream << iFileVersion;
  _rStream << this->m_cFrame;
  _rStream << this->m_cAttackerPlayerId;
  _rStream << this->m_wJobPart;
  _rStream << this->m_wPrevEntity;
  _rStream << this->m_wNextEntity;
  _rStream << this->m_uLastUpdateTick;
  _rStream << this->m_uLastLogicUpdate;
    IDecoObject:
  unsigned int fileFormatVersion = 1;
  a2 << fileFormatVersion;
  a2 << this->m_bStaticInstance;
    CDecoObject:
  unsigned int fileFormatVersion = 1;
  a1 << fileFormatVersion;
  a1 << this->m_uU1;
  a1 << this->m_iPhases;
  a1 << this->m_uCycleFrames;
  a1 << this->m_uTickCounter;
       */
      bool bIsStaticInstance;
      sChunk >> bIsStaticInstance;
      unsigned long uClassId;
      sChunk >> uClassId;

      long long    iEntityStartPos = sChunk.tellg();
      unsigned int iIEntityVersion;
      sChunk >> iIEntityVersion;

      static_assert(sizeof(IEntity::m_iEntityId) == sizeof(unsigned short));
      unsigned short iEntityId;
      sChunk >> iEntityId;
      unsigned short iType;
      sChunk >> iType;
      int iPackedXY;
      sChunk >> iPackedXY;
      unsigned char iHealth;
      sChunk >> iHealth;
      unsigned char iObjType;
      sChunk >> iObjType;
      // TODO: Find out the significance of this:
      // BOOL v20 = (iObjType & 0x1000000) == 0;
      // stream[43] = v20;
      // stream[42] = &v4;
      sChunk.seekg(iEntityStartPos);

      const int iX = Y16X16::UnpackXFast(iPackedXY);
      const int iY = Y16X16::UnpackYFast(iPackedXY);
      AddLoadedDecoObj(iX, iY, iType, iHealth, iEntityId, bIsStaticInstance, &sChunk);
    }
  }
}


// address=[0x1544b00]
// Decompiled from int __thiscall CDecoObjMgr::Create(  CDecoObjMgr *this,  int _iX,  int _iY,  int _iDecoType,  int _iAmount,  int _iGrownState,  int _iSlot,  int _pInStream)
int CDecoObjMgr::Create(int _iX, int _iY, int _iDecoType, int _iAmount, enum CDecoObjMgr::TGROWN_STATE _iGrownState, int _iSlot, std::istream *_pInStream) {
  IDecoObject *DecoObjPtr; // eax
  int          ObjectFirstJob; // [esp+60h] [ebp-128h]
  int          v26; // [esp+68h] [ebp-120h]
  int          v27; // [esp+70h] [ebp-118h]
  int          v28; // [esp+7Ch] [ebp-10Ch]
  CMushroom *  v35; // [esp+B0h] [ebp-D8h]
  CPlant *     v43; // [esp+E8h] [ebp-A0h]
  CStone *     v47; // [esp+100h] [ebp-88h]
  __int32      iIdNext; // [esp+118h] [ebp-70h]
  CTree *      v55; // [esp+134h] [ebp-54h]
  __int32      iId0; // [esp+160h] [ebp-28h]
  int          iIdx; // [esp+168h] [ebp-20h]
  char         iGoodType; // [esp+16Ch] [ebp-1Ch]
  char         v62; // [esp+173h] [ebp-15h]
  int          iGetId; // [esp+174h] [ebp-14h]

  if(_iSlot)
    iGetId = _iSlot;
  else
    iGetId = CMapObjectMgr::GetFreeSlot();

  switch(_iDecoType) {
    case OBJECT_TREE01A:
    case OBJECT_TREE01B:
    case OBJECT_TREE02A:
    case OBJECT_TREE02B:
    case OBJECT_TREE03A:
    case OBJECT_TREE03B:
    case OBJECT_TREE04A:
    case OBJECT_TREE04B:
    case OBJECT_TREE05A:
    case OBJECT_TREE05B:
    case OBJECT_TREE06A:
    case OBJECT_TREE06B:
    case OBJECT_TREE07A:
    case OBJECT_TREE07B:
    case OBJECT_TREE08A:
    case OBJECT_TREE08B:
    case OBJECT_TREE09A:
    case OBJECT_TREE09B:
    case OBJECT_TREE10A:
    case OBJECT_TREE10B:
    case OBJECT_TREE11A:
    case OBJECT_TREE11B:
      if(_iGrownState == 1) {
        if(!this->m_vInstanceId[_iDecoType].count) {
          v28 = g_pGfxManager->GetObjectFirstJob(_iDecoType) + 3;
          this->m_vInstanceId[_iDecoType].m_uFrameCount = g_pGfxManager->GetObjectFrameCount(v28);
        }
        if((char) this->m_vInstanceId[_iDecoType].count >= (char) this->m_vInstanceId[_iDecoType].m_uFrameCount) {
          if(++this->m_vInstanceId[_iDecoType].m_uCurrentFrame >= this->m_vInstanceId[_iDecoType].m_uFrameCount)
            this->m_vInstanceId[_iDecoType].m_uCurrentFrame = 0;
          if(_pInStream) {
            v55 = new CTree(_pInStream);
            if(v55->IsStaticInstance()) {
              g_pMapObjectMgr->Destroy(v55->ID());
              CWorldManager::SetObjectId(
                _iX,
                _iY,
                this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].m_uCurrentFrame]);
            } else {
              CWorldManager::SetObjectId(_iX, _iY, v55->ID());
            }
          } else {
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].m_uCurrentFrame]);
          }
        } else {
          if(_iSlot) {
            BB_ASSERT(_pInStream != 0)
            new CTree(_pInStream);
          } else {
            new CTree(_iX, _iY, _iDecoType, iGetId, 3);
          }

          BB_ASSERT(DecoObjPtr->IsStaticInstance());
          this->m_vInstanceId[_iDecoType].id[(char) this->m_vInstanceId[_iDecoType].count++] = iGetId;
        }
        CWorldManager::SetResource(_iX, _iY, 112, 1);
      } else {
        if(_iSlot) {
          BB_ASSERT(_pInStream != 0)
          new CTree(_pInStream);
        } else {
          new CTree(_iX, _iY, _iDecoType, iGetId, 0);
        }
        BB_ASSERT(!GetDecoObjPtr( iGetId)->IsStaticInstance());
      }
      break;
    case OBJECT_MINESET1:
    case OBJECT_DARKMINESET1:
      iIdx = _iAmount - 1;
      BB_ASSERT(iIdx >= 0)
      if(!this->m_vInstanceId[_iDecoType].count)
        this->m_vInstanceId[_iDecoType].m_uFrameCount = 15;
      if(this->m_vInstanceId[_iDecoType].id[iIdx]) {
        if(_pInStream) {
          *v47 = new CStone(_pInStream);
          if(v47->IsStaticInstance()) {
            g_pMapObjectMgr->Destroy(v47->ID());
            CWorldManager::SetObjectId(_iX, _iY, this->m_vInstanceId[_iDecoType].id[iIdx]);
          } else {
            CWorldManager::SetObjectId(_iX, _iY, v47->ID());
          }
        } else {
          CWorldManager::SetObjectId(_iX, _iY, this->m_vInstanceId[_iDecoType].id[iIdx]);
        }
      } else {
        if(_iSlot) {
          BB_ASSERT(_pInStream != 0)
          new CStone(_pInStream);
        } else {
          new CStone(_iX, _iY, _iDecoType, _iAmount, iGetId);
        }
        if(CDecoObjMgr::GetDecoObjPtr(iGetId)->IsStaticInstance()) {
          this->m_vInstanceId[_iDecoType].id[iIdx] = iGetId;
          ++this->m_vInstanceId[_iDecoType].count;
        }
      }
      if(_iDecoType != OBJECT_DARKMINESET1)
        CWorldManager::SetResource(_iX, _iY, OBJECT_STONEDARKISH4, _iAmount);
      break;
    case OBJECT_STONEMINE1_00:
    case OBJECT_STONEMINE1_01:
    case OBJECT_STONEMINE1_02:
    case OBJECT_STONEMINE1_03:
    case OBJECT_STONEMINE1_04:
    case OBJECT_STONEMINE1_05:
    case OBJECT_STONEMINE1_06:
    case OBJECT_STONEMINE1_07:
    case OBJECT_STONEMINE1_08:
    case OBJECT_STONEMINE1_09:
    case OBJECT_STONEMINE1_10:
    case OBJECT_STONEMINE1_11:
    case OBJECT_STONEMINE1_12:
      iId0 = _iDecoType - OBJECT_STONEMINE1_00;
      iIdNext = _iDecoType - OBJECT_STONEMINE1_00 + 1;
      if(!this->m_vInstanceId[OBJECT_MINESET1].count)
        this->m_vInstanceId[OBJECT_MINESET1].m_uFrameCount = 12;
      if(this->m_vInstanceId[OBJECT_MINESET1].id[iId0]) {
        CWorldManager::SetObjectId(_iX, _iY, this->m_vInstanceId[OBJECT_MINESET1].id[iId0]);
      } else {
        if(!_iSlot) {
          new CStone(_iX, _iY, OBJECT_MINESET1, iIdNext, iGetId);
        }
        BB_ASSERT(GetDecoObjPtr( iGetId)->IsStaticInstance())
        this->m_vInstanceId[OBJECT_MINESET1].id[iId0] = iGetId;
        this->m_vInstanceId[OBJECT_MINESET1].count = this->m_vInstanceId[41].count + 1;
      }
      CWorldManager::SetResource(_iX, _iY, 96, iIdNext);
      break;
    case OBJECT_GRAPE:
    case OBJECT_WHEAT1:
    case OBJECT_WHEAT2:
    case OBJECT_AGAVE:
    case OBJECT_SUNFLOWER:
      iGoodType = 0;
      switch(_iDecoType) {
        case OBJECT_GRAPE:
          iGoodType = GOOD_WINE;
          break;
        case OBJECT_WHEAT1:
        case OBJECT_WHEAT2:
          iGoodType = GOOD_GRAIN;
          break;
        case OBJECT_AGAVE:
          iGoodType = GOOD_AGAVE;
          break;
        case OBJECT_SUNFLOWER:
          iGoodType = GOOD_SUNFLOWER;
          break;
        default:
          break;
      }
      if(_iGrownState == 1) {
        if(!this->m_vInstanceId[_iDecoType].count) {
          v27 = g_pGfxManager->GetObjectFirstJob(_iDecoType) + 3;
          this->m_vInstanceId[_iDecoType].m_uFrameCount = g_pGfxManager->GetObjectFrameCount(v27);
        }
        if((char) this->m_vInstanceId[_iDecoType].count >= (char) this->m_vInstanceId[_iDecoType].m_uFrameCount) {
          if(++this->m_vInstanceId[_iDecoType].m_uCurrentFrame >= this->m_vInstanceId[_iDecoType].m_uFrameCount)
            this->m_vInstanceId[_iDecoType].m_uCurrentFrame = 0;
          if(!_pInStream)
            goto LABEL_212;

          v43 = new CPlant(*_pInStream);
          if(v43->IsStaticInstance()) {
            g_pMapObjectMgr->Destroy(v43->ID());
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].m_uCurrentFrame]);
          } else {
            CWorldManager::SetObjectId(_iX, _iY, v43->ID());
          }
        } else {
          if(_iSlot) {
            BB_ASSERT(_pInStream != 0)
            new CPlant(*_pInStream);
          } else {
            new CPlant(_iX, _iY, _iDecoType, iGetId, iGoodType, 3);
          }
          BB_ASSERT(m_vInstanceId[_iDecoType].id[ m_vInstanceId[_iDecoType].count ] == 0)

          this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].count++] = iGetId;
        }
      } else {
        if(_pInStream) {
          new CPlant(*_pInStream);
        } else {
          BB_ASSERT(iGetId != 0)
          new CPlant(_iX, _iY, _iDecoType, iGetId, iGoodType, 0);
        }
        BB_ASSERT(!GetDecoObjPtr( iGetId)->IsStaticInstance())
      }
      break;
    case OBJECT_MUSHROOM_DARK1:
    case OBJECT_MUSHROOM_DARK2:
    case OBJECT_MUSHROOM_DARK3:
      if(_iGrownState == GROW1) {
        if(!this->m_vInstanceId[_iDecoType].count) {
          v26 = g_pGfxManager->GetObjectFirstJob(_iDecoType) + 3;
          this->m_vInstanceId[_iDecoType].m_uFrameCount = g_pGfxManager->GetObjectFrameCount(v26);
        }
        if(this->m_vInstanceId[_iDecoType].count >= (char) this->m_vInstanceId[_iDecoType].m_uFrameCount) {
          if(++this->m_vInstanceId[_iDecoType].m_uCurrentFrame >= this->m_vInstanceId[_iDecoType].m_uFrameCount)
            this->m_vInstanceId[_iDecoType].m_uCurrentFrame = 0;
          if(!_pInStream)
            goto LABEL_212;

          v35 = new CMushroom(*_pInStream);
          if(v35->IsStaticInstance()) {
            g_pMapObjectMgr->Destroy(v35->ID());
            CWorldManager::SetObjectId(
              _iX,
              _iY,
              this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].m_uCurrentFrame]);
          } else {
            CWorldManager::SetObjectId(_iX, _iY, v35->ID());
          }
        } else {
          if(_iSlot) {
            BB_ASSERT(_pInStream != 0)
            new CMushroom(*_pInStream);
          } else {
            new CMushroom(_iX, _iY, _iDecoType, iGetId, 3);
          }
          BB_ASSERT(GetDecoObjPtr( iGetId)->IsStaticInstance())
          this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].count++] = iGetId;
        }
      } else {
        if(_pInStream) {
          new CMushroom(*_pInStream);
        } else {
          BB_ASSERT(iGetId != 0)
          new CMushroom(_iX, _iY, _iDecoType, iGetId, 0);
        }
        BB_ASSERT(!GetDecoObjPtr( iGetId)->IsStaticInstance())
      }
      break;
    case OBJECT_SHADOWHERB:
      if(_iSlot) {
        BB_ASSERT(_pInStream != 0)
        new CShadowHerb(*_pInStream);
      } else {
        new CShadowHerb(_iX, _iY, _iDecoType, iGetId, 0);
      }
      break;
    case OBJECT_HIVE:
      if(_iSlot) {
        BB_ASSERT(_pInStream != 0)
        new CHive(*_pInStream);
      } else {
        new CHive(_iX, _iY, _iDecoType, iGetId, 0);
      }
      break;
    default:
      if(!this->m_vInstanceId[_iDecoType].count) {
        ObjectFirstJob = g_pGfxManager->GetObjectFirstJob(_iDecoType);
        this->m_vInstanceId[_iDecoType].m_uFrameCount = g_pGfxManager->GetObjectFrameCount(ObjectFirstJob);
      }
      if(this->m_vInstanceId[_iDecoType].count >= this->m_vInstanceId[_iDecoType].m_uFrameCount) {
        if(this->m_vInstanceId[_iDecoType].m_uCurrentFrame >= this->m_vInstanceId[_iDecoType].m_uFrameCount - 1)
          this->m_vInstanceId[_iDecoType].m_uCurrentFrame = 0;
        if(this->m_vInstanceId[_iDecoType].m_uFrameCount <= 1) {
        LABEL_212:
          CWorldManager::SetObjectId(
            _iX,
            _iY,
            this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].m_uCurrentFrame]);
        } else {
          v62 = this->m_vInstanceId[_iDecoType].m_uCurrentFrame + 1;
          this->m_vInstanceId[_iDecoType].m_uCurrentFrame = v62;
          CWorldManager::SetObjectId(_iX, _iY, this->m_vInstanceId[_iDecoType].id[v62]);
        }
      } else {
        if(_iSlot) {
          BB_ASSERT(_pInStream != 0)
          new CDecoObject(*_pInStream);
        } else {
          new CDecoObject(_iX, _iY, _iDecoType, iGetId, this->m_vInstanceId[_iDecoType].count, this->m_aBuildingRings[_iDecoType].m_bHasPingPong);
        }

        BB_ASSERT(GetDecoObjPtr( iGetId)->IsStaticInstance())
        this->m_vInstanceId[_iDecoType].id[this->m_vInstanceId[_iDecoType].count++] = iGetId;
      }
      break;
  }
  return iGetId;
}

wchar_t aGamedataObject[] = L"GameData\\ObjectInfo.xml";

// address=[0x1546340]
// Decompiled from void __thiscall CDecoObjMgr::ReadObjectInfos(CDecoObjMgr *this)
void CDecoObjMgr::ReadObjectInfos(void) {
  long  iFileSize = 0;
  char *pFileBuffer = (char *) AdvXMLParser::Parser::OpenXMLFile(aGamedataObject, iFileSize);
  if(!pFileBuffer) return;

  using namespace AdvXMLParser;
  auto cParser = Parser();
  auto pDocument = std::unique_ptr<Document>(cParser.Parse(pFileBuffer, iFileSize));

  const Element &        rRoot = pDocument->GetRoot();
  ConstIterator<Element> rIt = rRoot.Begin();
  ConstIterator<Element> rEnd = rRoot.End();

  while(rIt < rEnd) {
    const Element &    rElement = *rIt;
    const std::string &rName = rElement.GetName();
    if(rName == "ObjectXMLVersion") {
      this->m_iXmlVersion = std::atoi(rElement.GetValue().c_str());
      ++rIt;
      continue;
    }

    const Attribute &  rIdAttr = rElement["id"];
    const std::string &sId = rIdAttr.GetValue();

    IConfigManager *pConfigManager = CConfigManagerPtr::GetInstance();
    signed int      iDecoObjectType = pConfigManager->GetDefineValue(sId.c_str());
    if(iDecoObjectType < 0) {
      BBSupportTracePrintF(0, "### CDecoObjMgr::ReadObjectInfos(): Unknown object \"%s\"!", sId.c_str() ? sId.c_str() : "");
      ++rIt;
      continue;
    }

    if(iDecoObjectType > 0 && iDecoObjectType < OBJECT_MAX) {
      Ring *pRings = &this->m_aBuildingRings[iDecoObjectType];

      int iBlocking = atoi(rElement("blocking", 0).GetValue().c_str());
      int iBuilding = atoi(rElement("building", 0).GetValue().c_str());
      int iRepellents = atoi(rElement("repellent", 0).GetValue().c_str());
      int iPingPongs = atoi(rElement("pingPong", 0).GetValue().c_str());

      int  iTotalBlockingRings = iBlocking;
      int  iAdditionalBuildingRings = iBuilding;
      int  iTotalRepellingRings = iRepellents;
      bool bIsResource = iDecoObjectType == OBJECT_WHEAT1
                         || iDecoObjectType == OBJECT_WHEAT2
                         || iDecoObjectType == OBJECT_GRAPE
                         || iDecoObjectType == OBJECT_SUNFLOWER
                         || iDecoObjectType == OBJECT_AGAVE;
      BOOL iIsResource = bIsResource;
      iTotalRepellingRings = iIsResource;
      // NOTE: Unused:
      //v83 = iDecoObjectType == OBJECT_SHADOWHERB;
      //v76 = iDecoObjectType == OBJECT_SHADOWHERB;
      if(iDecoObjectType == OBJECT_SHADOWHERB)
        iAdditionalBuildingRings = 1;
      if(iTotalBlockingRings != iBlocking) {
        BB_REPORTF("Invalid blocking rings: %s (%i)", CS4DefineNames::GetObjectName(iDecoObjectType), iDecoObjectType);
      }
      if(iAdditionalBuildingRings != iBuilding) {
        BB_REPORTF("Invalid building rings: %s (%i)", CS4DefineNames::GetObjectName(iDecoObjectType), iDecoObjectType);
      }
      if(iTotalRepellingRings != iRepellents) {
        BB_REPORTF("Invalid repelling rings: %s (%i)", CS4DefineNames::GetObjectName(iDecoObjectType), iDecoObjectType);
      }
      if(iPingPongs != iPingPongs) { // NOTE: assembly indicates that this was always X != X
        BB_REPORTF("Invalid ping pong: %s (%i)", CS4DefineNames::GetObjectName(iDecoObjectType), iDecoObjectType);
      }
      BB_ASSERT(iTotalBlockingRings >= 0)
      BB_ASSERT(iAdditionalBuildingRings >= 0)
      BB_ASSERT(iTotalRepellingRings >= 0)
      BB_ASSERT(( ( iTotalBlockingRings + iAdditionalBuildingRings ) == 0 ) || ( iAdditionalBuildingRings >= 1 ))
      BB_ASSERT(( iDecoObjectType < OBJECT_TREE01A ) || ( iDecoObjectType > OBJECT_TREE11B ) || ( ( iTotalBlockingRings == 1 ) && ( iAdditionalBuildingRings == 1 ) ))
      BB_ASSERT(( iDecoObjectType < OBJECT_DARKTREE01A ) || ( iDecoObjectType > OBJECT_DARKTREE09B ) || ( ( iTotalBlockingRings == 1 ) && ( iAdditionalBuildingRings == 1 ) ))

      if(iTotalBlockingRings <= 0 && iTotalRepellingRings > 0) {
        pRings->m_uUnknown = 1;
        pRings->m_uTotalBlockingRings = 0;
        pRings->m_uRepellingRings = 1;
        pRings->m_uTotalBlockingOrRepellingRings = 1;
        pRings->m_uTotalRings = iAdditionalBuildingRings + 1;
      } else {
        pRings->m_uUnknown = 0;
        pRings->m_uTotalBlockingRings = iTotalBlockingRings;
        pRings->m_uRepellingRings = 0;
        pRings->m_uTotalBlockingOrRepellingRings = iTotalBlockingRings;
        pRings->m_uTotalRings = iAdditionalBuildingRings + iTotalBlockingRings;
      }
      pRings->m_uU5 = 0;
      pRings->m_uU6 = 0;
      BOOL v63 = iPingPongs != 0;
      pRings->m_bHasPingPong = v63;
    }
  }

  delete[] pFileBuffer;
}


