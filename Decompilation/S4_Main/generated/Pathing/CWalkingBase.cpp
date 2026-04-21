#if FALSE
#include "CWalkingBase.h"

// Definitions for class CWalkingBase

// address=[0x15f6660]
// Decompiled from CWalking *__thiscall CWalkingBase::~CWalkingBase(CWalkingBase *this)
 CWalkingBase::~CWalkingBase(void) {
  
  this->__vftable = (CWalking_vtbl *)&CWalkingBase::_vftable_;
  CWalkingBase::DetachWalking(this);
  return CWalking::~CWalking(this);
}


// address=[0x15f66b0]
// Decompiled from void __thiscall CWalkingBase::Store(CWalkingBase *this, struct std::ostream *a2)
void  CWalkingBase::Store(std::ostream & a2) {
  
  int v2; // [esp+0h] [ebp-10h] BYREF
  __int16 v4; // [esp+8h] [ebp-8h] BYREF
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = 929995208;
  operator^<int>(a2, &v2);
  v5 = 1;
  operator^<short>(a2, &v5);
  v4 = this->GetWalkingType(this);
  operator^<short>(a2, &v4);
  operator^<int>(a2, &this->m_sData.m_uFlags);
  operator^<int>(a2, &this->m_sData.m_iWalkState);
  operator^<int>(a2, &this->m_sData.field_8);
  operator^<int>(a2, &this->m_sData.m_iWalkToXY);
  operator^<int>(a2, &this->m_sData.m_iWalkTo2XY);
  operator^<int>(a2, &this->m_sData.m_iLeaderWalkToXY);
  operator^<int>(a2, &this->m_sData.m_iIdleWalkToXY);
  operator^<int>(a2, &this->m_sData.m_iWalkToIndex);
  operator^<int>(a2, &this->m_sData.field_20);
  operator^<int>(a2, &this->m_sData.m_iFineWaypoint);
  operator^<int>(a2, &this->m_sData.m_iCoarseWaypointXY);
  operator^<int>(a2, &this->m_sData.m_iEntityFlags);
  operator^<int>(a2, &this->m_sData.field_34);
  operator^<int>(a2, &this->m_sData.field_38);
  operator^<int>(a2, &this->m_sData.field_3C);
  operator^<int>(a2, &this->m_sData.field_40);
  v2 = 1726811097;
  operator^<int>(a2, &v2);
}


// address=[0x15f6860]
// Decompiled from void __thiscall CWalkingBase::Init(CWalkingBase *this, int a2, int _iFlags)
void  CWalkingBase::Init(int a2, int _iFlags) {
  
  unsigned int _iFlagsa; // [esp+14h] [ebp+Ch]

  if ( (_iFlags & 0xBC000) != 0
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 524, "(_iFlags & WALK_FLAG_STRICT_INTERNAL_USE_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  _iFlagsa = _iFlags & 0xFFF43060;
  if ( a2 < 0 )
  {
    this->m_sData.m_iWalkToXY = -1;
    this->m_sData.m_iWalkToIndex = 0;
    this->m_sData.m_iWalkState = a2 != -1;
  }
  else
  {
    this->m_sData.m_iWalkToXY = a2;
    this->m_sData.m_iWalkToIndex = CWorldManager::Index(a2);
    this->m_sData.m_iWalkState = 8;
  }
  this->m_sData.field_40 = 0;
  this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
  this->m_sData.m_uFlags = this->m_sData.m_iEntityFlags | _iFlagsa;
  this->m_sData.field_20 = 0;
  if ( (_iFlagsa & 0x40000) == 0 )
    this->m_sData.m_iLeaderWalkToXY = this->m_sData.m_iWalkToXY;
}


// address=[0x15f6950]
// Decompiled from void __thiscall CWalkingBase::Init(CWalkingBase *this, struct CWalkingBase *a2, int a3)
void  CWalkingBase::Init(class CWalking * a2, int a3) {
  
  this->InitB(this, -1, a3);
  CWalkingBase::AttachWalking(this, a2);
}


// address=[0x15f6980]
// Decompiled from void __thiscall CWalkingBase::InitIfLeader(CWalkingBase *this, int a2, int a3)
void  CWalkingBase::InitIfLeader(int a2, int a3) {
  
  int m_iWalkState; // [esp+0h] [ebp-8h]

  this->m_sData.m_iLeaderWalkToXY = a2;
  if ( this->m_sData.m_pLatestWalking )
  {
    m_iWalkState = this->m_sData.m_iWalkState;
    if ( m_iWalkState > 0 && m_iWalkState <= 5 )
      this->InitB(this, -1, a3 | 0x40000);
  }
  else
  {
    this->InitB(this, a2, a3);
  }
}


// address=[0x15f69f0]
// Decompiled from int __thiscall CWalkingBase::Walk(CWalkingBase *this, int a2)
int  CWalkingBase::Walk(int a2) {
  
  struct type_info *pTypeId; // eax
  const char *pTypeName; // eax
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  __int16 v11; // ax
  int v12; // eax
  int v13; // eax
  struct type_info *v14; // eax
  const char *v15; // eax
  struct type_info *v16; // eax
  const char *v17; // eax
  struct CEvn_Event *v18; // [esp+Ch] [ebp-12Ch]
  struct CEvn_Event *v19; // [esp+10h] [ebp-128h]
  int v20; // [esp+18h] [ebp-120h]
  int v21; // [esp+1Ch] [ebp-11Ch]
  int v22; // [esp+34h] [ebp-104h]
  int iMapObjectId; // [esp+44h] [ebp-F4h]
  int v24; // [esp+48h] [ebp-F0h]
  int v25; // [esp+4Ch] [ebp-ECh]
  int v26; // [esp+50h] [ebp-E8h]
  int m_iWalkToXY; // [esp+60h] [ebp-D8h]
  int v28; // [esp+6Ch] [ebp-CCh]
  int Path; // [esp+80h] [ebp-B8h]
  int v30; // [esp+8Ch] [ebp-ACh]
  char v31; // [esp+90h] [ebp-A8h]
  struct CWalkingBase *v32; // [esp+98h] [ebp-A0h]
  bool v33; // [esp+A0h] [ebp-98h]
  int v34; // [esp+B8h] [ebp-80h]
  int v35; // [esp+BCh] [ebp-7Ch]
  int v36; // [esp+C0h] [ebp-78h]
  int v37; // [esp+C4h] [ebp-74h]
  int iDbgCurrentX; // [esp+C8h] [ebp-70h]
  int iDbgCurrentY; // [esp+CCh] [ebp-6Ch]
  int iIndex; // [esp+D0h] [ebp-68h]
  int m_iFineWaypoint; // [esp+D4h] [ebp-64h]
  int j; // [esp+D8h] [ebp-60h]
  int v43; // [esp+DCh] [ebp-5Ch]
  IMovingEntity *v44; // [esp+E0h] [ebp-58h]
  CWalkingBase *i; // [esp+E4h] [ebp-54h]
  char v46; // [esp+EBh] [ebp-4Dh]
  int v47; // [esp+ECh] [ebp-4Ch]
  char v48; // [esp+F1h] [ebp-47h]
  char v49; // [esp+F2h] [ebp-46h]
  char v50; // [esp+F3h] [ebp-45h]
  CEvn_Event v52; // [esp+F8h] [ebp-40h] BYREF
  CEvn_Event v53; // [esp+110h] [ebp-28h] BYREF
  int v54; // [esp+134h] [ebp-4h]

  iDbgCurrentX = Y16X16::UnpackXFast(a2);
  iDbgCurrentY = Y16X16::UnpackYFast(a2);
  if ( !CWorldManager::InWorld(iDbgCurrentX, iDbgCurrentY)
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 796, "g_cWorld.InWorld(iDbgCurrentX, iDbgCurrentY)") == 1 )
  {
    __debugbreak();
  }
  iIndex = CWorldManager::Index(iDbgCurrentX, iDbgCurrentY);
  iMapObjectId = CWorldManager::MapObjectId(iIndex);
  if ( !this->IsNotBlocked(this, iIndex) || this->SectorId(this, iIndex) <= 0 )
  {
    pTypeId = typeid(this);
    pTypeName = type_info::name(pTypeId);
    BBSupportTracePrintF(0, "Walk() [%s]: Invalid current position!", pTypeName);
    BBSupportTracePrintF(0, "  WalkState: %i.", this->m_sData.m_iWalkState);
    CWalkingBase::DbgPrintElementInfo(this, "  Current:   ", a2);
    CWalkingBase::DbgPrintElementInfo(this, "  WalkTo:    ", this->m_sData.m_iWalkToXY);
    CWalkingBase::DbgPrintElementInfo(this, "  WalkTo2:   ", this->m_sData.m_iWalkTo2XY);
    BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", iDbgCurrentX, iDbgCurrentY, iMapObjectId);
    CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, iMapObjectId, 0, 0);
    g_pTiling->DbgCheckTiling(g_pTiling, 0);
    v18 = CEvn_Event::CEvn_Event(&v52, 0xDu, 0x70u, 0, 0);
    v54 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v18);
    v54 = -1;
    CEvn_Event::~CEvn_Event(&v52);
    if ( BBSupportDbgReport(
           1,
           "Pathing\\Walking.cpp",
           818,
           "Invalid walk position! Dietmar: I need the trace file. [Ignore --> Pause]") == 1 )
      __debugbreak();
  }
  if ( this->m_sData.m_iLeaderWalkToXY != this->m_sData.m_iWalkToXY && this->m_sData.m_pLatestWalking == 0 )
  {
    v4 = CWalkingBase::Flags(this);
    this->InitB(this, this->m_sData.m_iLeaderWalkToXY, v4 & 0xFFF43060);
  }
  if ( this->m_sData.m_iWalkState > 5u )
  {
    this->m_sData.m_uFlags &= ~0x20000u;
    if ( !CWorldManager::InWorldPackedXY(this->m_sData.m_iWalkToXY)
      && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 843, "g_cWorld.InWorldPackedXY(m_sData.m_iWalkToXY)") == 1 )
    {
      __debugbreak();
    }
    CWalkingBase::GoalCheck(this, a2);
  }
  v49 = 0;
  v48 = 0;
  v50 = 0;
  v37 = 0;
  while ( v37 < 32 )
  {
    switch ( this->m_sData.m_iWalkState )
    {
      case 0:
        return this->IdleWalk(this, (Y16X16 *)a2, 0) | 0x10;
      case 1:
        this->m_sData.field_40 = 0;
        this->m_sData.m_iWalkState = 2;
        return 72;
      case 2:
        return this->IdleWalk(this, (Y16X16 *)a2, 0) | 0x50;
      case 3:
        this->m_sData.field_40 = 0;
        if ( this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0 )
          CWalkingBase::GroupLeaderWalking(this, this->m_sData.m_iWalkTo2XY, 0);
        if ( (this->m_sData.m_uFlags & 0x40000) != 0 )
        {
          this->m_sData.m_iWalkState = 0;
          return 24;
        }
        else
        {
          if ( (this->m_sData.m_uFlags & 0x4000) != 0 )
            this->m_sData.m_iWalkState = 4;
          else
            this->m_sData.m_iWalkState = 5;
          return 40;
        }
      case 4:
        return 40;
      case 5:
        return this->IdleWalk(this, (Y16X16 *)a2, 0) | 0x30;
      case 6:
        if ( v50 )
          goto LABEL_50;
        if ( (int)++this->m_sData.field_20 <= 16 )
        {
          if ( (int)this->m_sData.field_20 > 2 )
          {
            v33 = Y16X16::DistanceFast(a2, this->m_sData.m_iWalkToXY) <= 3;
            if ( (CWalkingBase::Flags(this) & 0x2000) != 0 && v33 )
              this->m_sData.m_iWalkState = 3;
            else
              this->m_sData.m_iWalkState = 9;
            goto LABEL_16;
          }
          if ( Y16X16::DistanceFast(a2, this->m_sData.m_iFineWaypoint) == 1 )
          {
            v22 = CWorldManager::Index(this->m_sData.m_iFineWaypoint);
            v36 = CWorldManager::OccupyingEntityId(v22);
            if ( v36 )
            {
              v44 = (IMovingEntity *)CMapObjectMgr::EntityPtr(v36);
              if ( v44 )
              {
                if ( !j____RTDynamicCast(
                        (void **)&v44->__vftable,
                        0,
                        &IEntity__RTTI_Type_Descriptor_,
                        &IMovingEntity__RTTI_Type_Descriptor_,
                        0)
                  && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 961, "dynamic_cast<IMovingEntity*>(pEntity) != 0") == 1 )
                {
                  __debugbreak();
                }
                v32 = (struct CWalkingBase *)IMovingEntity::Walking(v44);
                if ( v32 )
                {
                  if ( v32->m_sData.m_iWalkState == 6 && v32->m_sData.m_iFineWaypoint == a2 )
                  {
                    this->m_sData.m_iWalkState = 9;
                    goto LABEL_16;
                  }
                }
              }
            }
          }
          v50 = 1;
LABEL_50:
          if ( this->m_sData.m_iFineWaypoint == a2 )
          {
            this->m_sData.field_20 = 0;
            if ( CDirCache::Count(&this->m_sData.m_cDirCache) <= 0 )
            {
              this->m_sData.m_iWalkState = 9;
              goto LABEL_16;
            }
            v47 = CDirCache::Back(&this->m_sData.m_cDirCache);
            this->m_sData.m_iFineWaypoint = a2 + Y16X16::NeighborModifier(v47);
            CDirCache::PopBack(&this->m_sData.m_cDirCache);
          }
          else
          {
            if ( Y16X16::DistanceFast(a2, this->m_sData.m_iFineWaypoint) != 1 )
            {
              this->m_sData.m_iWalkState = 9;
              goto LABEL_16;
            }
            v47 = Y16X16::DirectionFast(a2, this->m_sData.m_iFineWaypoint);
          }
          if ( v47 < 0 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1018, "iDir >= 0") == 1 )
            __debugbreak();
          if ( this->m_sData.m_iFineWaypoint != a2 + Y16X16::NeighborModifier(v47)
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1019,
                 "m_sData.m_iFineWaypointXY == _iCurrentXY + Y16X16::NeighborModifier(iDir)") == 1 )
          {
            __debugbreak();
          }
          if ( this->m_sData.m_iWalkingType == 4 )
          {
            v6 = CWorldManager::Index(this->m_sData.m_iFineWaypoint);
            if ( this->IsNotBlocked(this, v6) )
            {
              v7 = CWorldManager::Index(this->m_sData.m_iFineWaypoint);
              v31 = CWaterFlags::WaterFlags(v7);
              v43 = (v31 & 0xF0) >> 4;
              if ( v43 )
                this->m_sData.m_iWalkState = 9;
              if ( v43 > 2 )
              {
                v8 = Y16X16::NeighborModifier(v47 + 3);
                v9 = CWorldManager::Index(a2 + v8);
                CWaterFlags::WaterFlags(v9);
                if ( (v31 & 0xF0) >> 4 < v43 + 2 )
                {
                  if ( Y16X16::DistanceFast(a2, this->m_sData.m_iWalkToXY) > 3 )
                  {
                    v30 = this->m_sData.field_34 + 1;
                    this->m_sData.field_34 = v30;
                    if ( v30 >= 2 && v43 <= 7 )
                      return v47;
                    else
                      return 136;
                  }
                  else
                  {
                    this->m_sData.m_iWalkState = 3;
                    return 40;
                  }
                }
                else
                {
                  this->m_sData.field_34 = 0;
                  return v47;
                }
              }
              else
              {
                this->m_sData.field_34 = 0;
                return v47;
              }
            }
            else
            {
              if ( "Waypoint blocked --> WALK_NO_PATH"
                && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1073, "!\"Waypoint blocked --> WALK_NO_PATH\"") == 1 )
              {
                __debugbreak();
              }
              this->m_sData.m_iWalkState = 1;
              return 72;
            }
          }
          else
          {
            v10 = CWorldManager::Index(this->m_sData.m_iFineWaypoint);
            if ( this->IsNotBlocked(this, v10) )
              return v47;
            if ( v49 )
            {
              CTrace::Print(">>>>>> CWalking::Walk(): Waypoint blocked! <<<<<<");
              this->m_sData.m_iWalkState = 7;
            }
            else
            {
              v49 = 1;
              this->m_sData.m_iWalkState = 9;
            }
            goto LABEL_16;
          }
        }
        else
        {
          this->m_sData.field_20 = 0;
          this->m_sData.m_iWalkState = 7;
          return this->IdleWalk(this, (Y16X16 *)a2, 0);
        }
      case 7:
        this->m_sData.m_iWalkState = 8;
        CWalkingBase::GoalCheck(this, a2);
        if ( this->m_sData.m_iWalkState != 8 )
          CTrace::Print(
            "### CWalkingBase::Walk(): STATE_EX_GOAL_CHECK has changed walk state! New state %i. ###",
            this->m_sData.m_iWalkState);
        goto LABEL_16;
      case 8:
        v11 = CWalkingBase::Flags(this);
        Path = CAStarTiling::FindPath(a2, this->m_sData.m_iWalkTo2XY, &this->m_sData.m_cCoarseWaypoints, v11);
        if ( Path )
        {
          if ( ((Path < 0) & ((CWalkingBase::Flags(this) & 0x40) != 0)) != 0 )
          {
            this->m_sData.m_iWalkToXY = CWaypoints::Goal(&this->m_sData.m_cCoarseWaypoints);
            this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
            this->m_sData.m_iWalkToIndex = CWorldManager::Index(this->m_sData.m_iWalkToXY);
          }
          if ( CWaypoints::CachedWaypointsCount(&this->m_sData.m_cCoarseWaypoints) <= 0
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1152,
                 "m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0") == 1 )
          {
            __debugbreak();
          }
          this->m_sData.m_iCoarseWaypointXY = CWaypoints::Back(&this->m_sData.m_cCoarseWaypoints);
          CWaypoints::PopBack(&this->m_sData.m_cCoarseWaypoints);
          if ( CWaypoints::CachedWaypointsCount(&this->m_sData.m_cCoarseWaypoints) <= 0
            && this->m_sData.m_iCoarseWaypointXY != this->m_sData.m_iWalkTo2XY
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1163,
                 "(m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0) || (m_sData.m_iCoarseWaypointXY == m_sData.m_iWalkToXY2)") == 1 )
          {
            __debugbreak();
          }
          this->m_sData.m_iWalkState = 9;
        }
        else
        {
          this->m_sData.m_iWalkState = 1;
        }
        goto LABEL_16;
      case 9:
        if ( !this->m_sData.field_40 )
          goto LABEL_113;
        if ( this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0 )
        {
          if ( (int)this->m_sData.field_40 < 0 || Y16X16::DistanceFast(this->m_sData.field_40, a2) <= 2 )
          {
            v35 = 0;
            v34 = 0;
            for ( i = this->m_sData.m_pNextWalking; i; i = i->m_sData.m_pNextWalking )
            {
              if ( ((int (__thiscall *)(CWalkingBase *, _DWORD))i->State)(i, 0) >= 6 )
                ++v34;
              ++v35;
            }
            if ( v34 > v35 / 4 )
            {
              this->m_sData.field_40 = -1;
              return this->IdleWalk(this, (Y16X16 *)a2, 0) | 0x10;
            }
          }
        }
        else
        {
          this->m_sData.field_40 = 0;
        }
LABEL_113:
        if ( this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY )
          goto LABEL_119;
        v46 = CWaypoints::GoalCached(&this->m_sData.m_cCoarseWaypoints);
        v28 = CWaypoints::CachedWaypointsCount(&this->m_sData.m_cCoarseWaypoints);
        if ( v28 && (v28 >= 2 || v46 != 0) )
        {
          if ( CWalkingBase::NextCoarseWaypoint(this, a2) )
          {
LABEL_119:
            if ( this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY )
              m_iWalkToXY = this->m_sData.m_iWalkToXY;
            else
              m_iWalkToXY = this->m_sData.m_iCoarseWaypointXY;
            if ( ((unsigned __int8 (__thiscall *)(CWalkingBase *, int, int, CDirCache *))this->FindPathAStar64)(
                   this,
                   a2,
                   m_iWalkToXY,
                   &this->m_sData.m_cDirCache) )
            {
              if ( CDirCache::Count(&this->m_sData.m_cDirCache) <= 0
                && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1251, "m_sData.m_cFineWaypoints.Count() > 0") == 1 )
              {
                __debugbreak();
              }
              v12 = CDirCache::Back(&this->m_sData.m_cDirCache);
              this->m_sData.m_iFineWaypoint = a2 + Y16X16::NeighborModifier(v12);
              CDirCache::PopBack(&this->m_sData.m_cDirCache);
              if ( this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0 )
              {
                v21 = CDirCache::Count(&this->m_sData.m_cDirCache);
                m_iFineWaypoint = this->m_sData.m_iFineWaypoint;
                for ( j = 0; j < v21; ++j )
                {
                  v13 = CDirCache::operator[](&this->m_sData.m_cDirCache.m_iCount, j);
                  m_iFineWaypoint += Y16X16::NeighborModifier(v13);
                }
                this->m_sData.field_40 = m_iFineWaypoint;
                CWalkingBase::GroupLeaderWalking(this, m_iFineWaypoint, 0x40000);
              }
              if ( Y16X16::DistanceFast(a2, this->m_sData.m_iFineWaypoint) != 1
                && BBSupportDbgReport(
                     2,
                     "Pathing\\Walking.cpp",
                     1272,
                     "Y16X16::DistanceFast(_iCurrentXY, m_sData.m_iFineWaypointXY) == 1") == 1 )
              {
                __debugbreak();
              }
              this->m_sData.m_iWalkState = 6;
            }
            else
            {
              v25 = Y16X16::UnpackXFast(a2);
              v26 = Y16X16::UnpackYFast(a2);
              v20 = CWorldManager::Index(v25, v26);
              v24 = CWorldManager::MapObjectId(v20);
              v14 = typeid(this);
              v15 = type_info::name(v14);
              BBSupportTracePrintF(0, "Walk() [%s]: FindPathAStar64() failed!", v15);
              CWalkingBase::DbgPrintElementInfo(this, "  Current:  ", a2);
              CWalkingBase::DbgPrintElementInfo(this, "  Waypoint: ", m_iWalkToXY);
              CWalkingBase::DbgPrintElementInfo(this, "  WalkTo:   ", this->m_sData.m_iWalkToXY);
              CWalkingBase::DbgPrintElementInfo(this, "  WalkTo2:  ", this->m_sData.m_iWalkTo2XY);
              BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", v25, v26, v24);
              CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v24, 0, 0);
              g_pTiling->DbgCheckTiling(g_pTiling, 0);
              if ( v48 )
              {
                v19 = CEvn_Event::CEvn_Event(&v53, 0xDu, 0x70u, 0, 0);
                v54 = 1;
                IEventEngine::SendAMessage(g_pEvnEngine, v19);
                v54 = -1;
                CEvn_Event::~CEvn_Event(&v53);
                if ( BBSupportDbgReport(
                       1,
                       "Pathing\\Walking.cpp",
                       1315,
                       "FindPathAStar64 failed! Dietmar: I need the trace file. [Ignore --> Pause]") == 1 )
                  __debugbreak();
                this->m_sData.m_iWalkState = 1;
              }
              else
              {
                BBSupportTracePrintF(0, "FindPathAStar64 failed once [may be ignored]");
                v48 = 1;
                this->m_sData.m_iWalkState = 7;
              }
            }
          }
          else
          {
            this->m_sData.m_iWalkState = 8;
          }
        }
        else
        {
          this->m_sData.m_iWalkState = 8;
        }
LABEL_16:
        ++v37;
        break;
      default:
        if ( "Walk(): Invalid walk state!"
          && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1325, "!\"Walk(): Invalid walk state!\"") == 1 )
        {
          __debugbreak();
        }
        this->m_sData.m_iWalkState = 1;
        goto LABEL_16;
    }
  }
  v16 = typeid(this);
  v17 = type_info::name(v16);
  BBSupportTracePrintF(3, "### Walk() [%s]: LoopCount >= 32! ###", v17);
  this->m_sData.m_iWalkState = 7;
  return 8;
}


// address=[0x15f7bc0]
// Decompiled from int __thiscall CWalkingBase::IdleWalk(CWalkingBase *this, int a2, int a3)
int  CWalkingBase::IdleWalk(int a2, int a3) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-D4h]
  int v6; // [esp+4h] [ebp-D0h]
  __int64 v7; // [esp+10h] [ebp-C4h]
  int v8; // [esp+18h] [ebp-BCh]
  int v9; // [esp+1Ch] [ebp-B8h]
  int v10; // [esp+20h] [ebp-B4h]
  int v11; // [esp+24h] [ebp-B0h]
  unsigned int v12; // [esp+28h] [ebp-ACh]
  int v13; // [esp+2Ch] [ebp-A8h]
  int v14; // [esp+30h] [ebp-A4h]
  int v15; // [esp+34h] [ebp-A0h]
  int v16; // [esp+38h] [ebp-9Ch]
  unsigned int v17; // [esp+3Ch] [ebp-98h]
  int v18; // [esp+40h] [ebp-94h]
  int v19; // [esp+44h] [ebp-90h]
  int v20; // [esp+48h] [ebp-8Ch]
  int v21; // [esp+4Ch] [ebp-88h]
  int v22; // [esp+50h] [ebp-84h]
  unsigned int v23; // [esp+54h] [ebp-80h]
  int v24; // [esp+58h] [ebp-7Ch]
  int v25; // [esp+5Ch] [ebp-78h]
  int v26; // [esp+60h] [ebp-74h]
  int v27; // [esp+64h] [ebp-70h]
  int jj; // [esp+68h] [ebp-6Ch]
  signed int v29; // [esp+6Ch] [ebp-68h]
  int v30; // [esp+70h] [ebp-64h]
  int i; // [esp+78h] [ebp-5Ch]
  int j; // [esp+78h] [ebp-5Ch]
  int k; // [esp+78h] [ebp-5Ch]
  int m; // [esp+78h] [ebp-5Ch]
  int n; // [esp+78h] [ebp-5Ch]
  int ii; // [esp+78h] [ebp-5Ch]
  int v38; // [esp+7Ch] [ebp-58h]
  _DWORD v39[13]; // [esp+80h] [ebp-54h]
  _DWORD v40[7]; // [esp+B4h] [ebp-20h]

  v21 = 0;
  v20 = 0;
  v18 = 0;
  v25 = 0;
  v15 = CWorldManager::Index(a2);
  for ( i = 0; i < 6; ++i )
  {
    v19 = v15 + CWorldManager::NeighborRelIndex(i);
    if ( this->IsNotBlocked(this, v19) )
    {
      if ( this->IsNotOccupied(this, v19) )
      {
        if ( CWorldManager::MoveCostsBits(v19) >= 7 )
        {
          v40[i] = 1;
        }
        else
        {
          v40[i] = 4;
          ++v20;
        }
        ++v21;
      }
      else
      {
        v40[i] = 0;
        ++v25;
      }
    }
    else
    {
      v40[i] = 0;
      ++v18;
    }
  }
  v40[6] = v40[0];
  if ( v25 && (v18 || v25 > 2) || CWorldManager::MoveCostsBits(v15) != 7 )
  {
    this->m_sData.m_iIdleWalkToXY = -1;
    if ( (CWalkingBase::Flags(this) & 0x20000) != 0
      && v40[Grid::TurnLeft(this->m_sData.field_8)] == 2
      && v40[this->m_sData.field_8] == 2
      && v40[this->m_sData.field_8 + 1] == 2 )
    {
      this->m_sData.m_uFlags &= ~0x20000u;
      return this->m_sData.field_8;
    }
    else
    {
      if ( v21 >= 1 )
      {
        HIDWORD(v7) = v25 >= 1;
        LODWORD(v7) = (a3 & 0x10000000) != 0;
        if ( v7 )
        {
          for ( j = 7; j < 19; ++j )
          {
            v23 = v15 + CWorldManager::SurroundingHexPointRelIndex(j);
            v22 = j - 6;
            if ( CWorldManager::InWorld(v23) && this->IsNotBlocked(this, v23) )
            {
              if ( this->IsNotOccupied(this, v23) )
              {
                if ( CWorldManager::MoveCostsBits(v23) >= 7 )
                  v39[v22 - 1] = 1;
                else
                  v39[v22 - 1] = 2;
              }
              else
              {
                v39[v22 - 1] = 0;
              }
            }
            else
            {
              v39[v22 - 1] = 0;
            }
          }
          v38 = v39[11];
          v39[12] = v39[0];
          if ( v20 >= 3 && v20 < v21 )
          {
            for ( k = 0; k <= 6; ++k )
            {
              if ( v40[k] == 1 )
                v40[k] = 0;
            }
          }
          v24 = v40[5];
          for ( m = 0; m < 6; ++m )
          {
            v14 = v40[m];
            v40[m] = v14 * (v39[2 * m + 1] + v39[2 * m] + v39[2 * m - 1] + v40[m + 1] + v24 + 2 * v14);
            v24 = v14;
          }
          v29 = 0;
          for ( n = 0; n < 6; ++n )
          {
            if ( (int)v40[n] > 0 )
            {
              v29 += v40[n];
              v40[n] = v29;
            }
          }
          if ( v29 > 0 )
            v29 = CStateGame::Rand(g_pGame) % v29;
          for ( ii = 0; ii < 6; ++ii )
          {
            if ( v29 < v40[ii] )
            {
              this->m_sData.m_uFlags |= 0x20000u;
              this->m_sData.field_8 = ii;
              return ii;
            }
          }
        }
      }
      this->m_sData.m_uFlags &= ~0x20000u;
      return 8;
    }
  }
  else
  {
    v3 = CWorldManager::Index(a2);
    v9 = this->SectorId(this, v3);
    if ( (this->m_sData.m_uFlags & 0x20000) == 0 )
      this->m_sData.m_iIdleWalkToXY = -1;
    this->m_sData.m_uFlags &= ~0x20000u;
    if ( CWorldManager::InWorldPackedXY(this->m_sData.m_iIdleWalkToXY) )
    {
      v11 = CWorldManager::Index(this->m_sData.m_iIdleWalkToXY);
      v10 = this->SectorId(this, v11);
      if ( CWorldManager::MoveCostsBits(v11) == 7 || v10 <= 0 || v9 != v10 )
        this->m_sData.m_iIdleWalkToXY = -1;
    }
    else
    {
      this->m_sData.m_iIdleWalkToXY = -1;
    }
    if ( this->m_sData.m_iIdleWalkToXY < 0 )
    {
      v6 = Y16X16::UnpackXFast(a2);
      v5 = Y16X16::UnpackYFast(a2);
      v16 = -1;
      v8 = -1;
      for ( jj = 0; jj < SurroundingHexPointsCount(15); ++jj )
      {
        v12 = v6 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * jj]);
        v17 = v5 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * jj]);
        if ( CWorldManager::InWorld(v12, v17) )
        {
          v13 = CWorldManager::Index(v12, v17);
          if ( this->SectorId(this, v13) == v9
            && this->IsNotOccupied(this, v13)
            && CWorldManager::MoveCostsBits(v13) < 7 )
          {
            v16 = v12;
            v8 = v17;
            break;
          }
        }
      }
      if ( v16 < 0 )
        return 8;
      this->m_sData.m_iIdleWalkToXY = Y16X16::PackXYFast(v16, v8);
    }
    v30 = Y16X16::DirectionFast(a2, this->m_sData.m_iIdleWalkToXY);
    v27 = v40[Grid::TurnLeft(v30)];
    v26 = v40[Grid::TurnLeft(v30)];
    if ( v40[v30] < v27 || v40[v30] < v26 )
    {
      if ( v27 == v26 )
        CStateGame::Rand(g_pGame);
      v30 = Grid::TurnLeft(v30);
    }
    if ( (int)v40[v30] <= 0 )
      v30 = 8;
    if ( v30 == 8 )
      this->m_sData.m_iIdleWalkToXY = -1;
    return v30;
  }
}


// address=[0x15f8420]
// Decompiled from int __thiscall CWalkingBase::DestinationXY(CWalkingBase *this)
int  CWalkingBase::DestinationXY(void)const {
  
  return this->m_sData.m_iWalkToXY;
}


// address=[0x15f8440]
// Decompiled from int __thiscall CWalkingBase::State(CWalkingBase *this, int a2)
int  CWalkingBase::State(int a2)const {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]

  switch ( this->m_sData.m_iWalkState )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = this->m_sData.m_iWalkState + 1;
      break;
    case 6:
      if ( this->m_sData.m_iWalkTo2XY == this->m_sData.m_iCoarseWaypointXY )
      {
        v6 = Y16X16::DistanceFast(this->m_sData.m_iWalkToXY, this->m_sData.m_iFineWaypoint);
        if ( v6 <= 14 )
          v4 = v6 + 1;
        else
          v4 = 15;
        result = 16 * v4;
      }
      else
      {
        v5 = Y16X16::DistanceFast(this->m_sData.m_iWalkToXY, this->m_sData.m_iCoarseWaypointXY);
        if ( v5 <= 14 )
          v3 = v5 + 1;
        else
          v3 = 15;
        result = v3 << 8;
      }
      break;
    case 7:
      result = 4096;
      break;
    case 8:
      result = 0x2000;
      break;
    case 9:
      result = 0x4000;
      break;
    default:
      if ( "CWalkingBase::State(): Invalid walk mode!"
        && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1681, "!\"CWalkingBase::State(): Invalid walk mode!\"") == 1 )
      {
        __debugbreak();
      }
      result = 0;
      break;
  }
  return result;
}


// address=[0x15f8580]
// Decompiled from int __thiscall CWalkingBase::OwnerId(CWalkingBase *this)
int  CWalkingBase::OwnerId(void)const {
  
  return this->m_sData.m_iEntityFlags & 0xF;
}


// address=[0x15f85a0]
// Decompiled from bool __thiscall CWalkingBase::IsNotBlocked(CWalkingBase *this, int a2)
bool  CWalkingBase::IsNotBlocked(int a2) {
  
  return !CWorldManager::IsBlockedLand(a2);
}


// address=[0x15f85e0]
// Decompiled from bool __thiscall CWalkingBase::IsNotOccupied(CWalkingBase *this, int a2)
bool  CWalkingBase::IsNotOccupied(int a2) {
  
  return CWorldManager::OccupyingEntityId(a2) == 0;
}


// address=[0x15f8620]
// Decompiled from int __thiscall CWalkingBase::SectorId(CWalkingBase *this, int a2)
int  CWalkingBase::SectorId(int a2) {
  
  return ITiling::SectorId(a2);
}


// address=[0x15f8640]
// Decompiled from int __thiscall CWalkingBase::TileId(CWalkingBase *this, int a2)
int  CWalkingBase::TileId(int a2) {
  
  return ITiling::NormalTileId(a2);
}


// address=[0x15f8660]
// Decompiled from int __thiscall CWalkingBase::GetNextWaypoint(CWalkingBase *this)
int  CWalkingBase::GetNextWaypoint(void) {
  
  int result; // eax

  switch ( this->m_sData.m_iWalkState )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = -1;
      break;
    case 6:
      result = this->m_sData.m_iCoarseWaypointXY;
      break;
    case 7:
      result = -1;
      break;
    case 8:
      result = -1;
      break;
    case 9:
      result = this->m_sData.m_iCoarseWaypointXY;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}


// address=[0x15faee0]
// Decompiled from CWalkingBase *__thiscall CWalkingBase::CWalkingBase(CWalkingBase *this, int a2, int a3)
 CWalkingBase::CWalkingBase(int a2, int a3) {
  
  CWalking::CWalking(this);
  this->__vftable = (CWalking_vtbl *)&CWalkingBase::_vftable_;
  memset(&this->m_sData, 0, sizeof(this->m_sData));
  this->m_sData.m_iWalkingType = a2;
  this->m_sData.m_iWalkState = 1;
  this->m_sData.m_iEntityFlags = a3;
  return this;
}


// address=[0x15fb220]
// Decompiled from CWalkingBase::SData *__thiscall CWalkingBase::GetData(CWalkingBase *this)
struct CWalkingBase::SData &  CWalkingBase::GetData(void) {
  
  return &this->m_sData;
}


// address=[0x15f86e0]
// Decompiled from char __thiscall CWalkingBase::FindPathAStar64(  CWalkingBase *this,  unsigned int a2,  unsigned int a3,  struct CDirCache *a4)
bool  CWalkingBase::FindPathAStar64(int a2, int a3, class CDirCache & a4) {
  
  return CAStar64::FindPath((CAStar64 *)&g_cAStar64Normal, a2, a3, a4);
}


// address=[0x15f8710]
// Decompiled from int __thiscall CWalkingBase::FindNearest(CWalkingBase *this, int a2, int a3, int a4)
int  CWalkingBase::FindNearest(int a2, int a3, int a4) {
  
  int v4; // eax
  int v5; // eax
  __int16 v6; // ax
  int v8; // [esp+14h] [ebp-64h]
  struct CWaypoints v10; // [esp+1Ch] [ebp-5Ch] BYREF

  v4 = CWorldManager::Index(a2);
  v8 = this->SectorId(this, v4);
  v5 = CWorldManager::Index(a3);
  if ( this->SectorId(this, v5) == v8 || v8 == 0 )
    return a3;
  v6 = CWalkingBase::Flags(this);
  if ( CAStarTiling::FindPath(a2, a3, &v10, v6 | 0x40) )
    return CWaypoints::Goal(&v10);
  else
    return a3;
}


// address=[0x15f87f0]
// Decompiled from void __thiscall CWalkingBase::GoalCheck(CWalkingBase *this, int a2)
void  CWalkingBase::GoalCheck(int a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-38h]
  BOOL IsBlockedLand; // [esp+0h] [ebp-34h]
  int v7; // [esp+4h] [ebp-30h]
  int v8; // [esp+8h] [ebp-2Ch]
  int v9; // [esp+Ch] [ebp-28h]
  int v10; // [esp+10h] [ebp-24h]
  int v11; // [esp+1Ch] [ebp-18h]
  int v12; // [esp+20h] [ebp-14h]
  int v13; // [esp+24h] [ebp-10h]
  int v14; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]

  v2 = CWorldManager::Index(a2);
  v13 = this->SectorId(this, v2);
  if ( v13 )
  {
    if ( (CWalkingBase::Flags(this) & 0x1000) != 0 )
    {
      if ( Y16X16::DistanceFast(a2, this->m_sData.m_iWalkToXY) > 1 )
      {
        if ( v13 == this->SectorId(this, this->m_sData.m_iWalkToIndex) )
        {
          this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
        }
        else
        {
          v3 = CWorldManager::Index(this->m_sData.m_iWalkTo2XY);
          if ( v13 != this->SectorId(this, v3) )
          {
            for ( i = 0; i < 6; ++i )
            {
              v4 = CWorldManager::NeighborRelIndex(i);
              if ( v13 == this->SectorId(this, this->m_sData.m_iWalkToIndex + v4) )
              {
                this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY + Y16X16::NeighborModifier(i);
                break;
              }
            }
            if ( i >= 6 )
              this->m_sData.m_iWalkState = 1;
          }
        }
      }
      else
      {
        this->m_sData.m_iWalkState = 3;
      }
    }
    else if ( a2 == this->m_sData.m_iWalkToXY )
    {
      this->m_sData.m_iWalkState = 3;
    }
    else if ( (CWalkingBase::Flags(this) & 0x40) == 0 && v13 != this->SectorId(this, this->m_sData.m_iWalkToIndex) )
    {
      this->m_sData.m_iWalkState = 1;
    }
  }
  else
  {
    v11 = Y16X16::UnpackXFast(a2);
    v12 = Y16X16::UnpackYFast(a2);
    v14 = CWorldManager::Index(v11, v12);
    IsBlockedLand = CWorldManager::IsBlockedLand(v14);
    v7 = CWorldManager::OwnerId(v14);
    v8 = CWorldManager::SectorId(v14);
    v9 = CWorldManager::EcoSectorId(v14);
    v10 = CWorldManager::OccupyingEntityId(v14);
    v5 = this->IsNotBlocked(this, v14);
    CTrace::Print(
      "### CWalkingBase::GoalCheck(): Current sector id is 0! (%i, %i), is blocked land %i, owner %i, sector %i, eco-sect"
      "or %i, entity %i, not blocked %i. ###",
      v11,
      v12,
      IsBlockedLand,
      v7,
      v8,
      v9,
      v10,
      v5);
    this->m_sData.m_iWalkState = 1;
  }
}


// address=[0x15f8a40]
// Decompiled from int __thiscall CWalkingBase::DbgPrintElementInfo(CWalkingBase *this, const char *a2, int a3)
void  CWalkingBase::DbgPrintElementInfo(char const * a2, int a3) {
  
  int v4; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  int v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  unsigned int v11; // [esp+1Ch] [ebp-10h]
  unsigned int v12; // [esp+20h] [ebp-Ch]
  int v14; // [esp+28h] [ebp-4h]

  v11 = (__int16)Y16X16::UnpackXFast(a3);
  v12 = (__int16)Y16X16::UnpackYFast(a3);
  if ( !CWorldManager::InWorld(v11, v12) )
    return BBSupportTracePrintF(0, "%s( %4i, %4i ) - Not in world.", a2, v11, v12);
  v14 = CWorldManager::Index(v11, v12);
  v4 = this->IsNotBlocked(this, v14);
  v5 = this->SectorId(this, v14);
  v6 = CWorldManager::Flags(v14);
  v7 = ITiling::OwnerId(v14);
  v8 = ITiling::SectorId(v14);
  v9 = ITiling::CatapultSectorId(v14);
  v10 = ITiling::EcoSectorId(v14);
  return BBSupportTracePrintF(
           0,
           "%s( %4i, %4i ) - INB %i, SId %2i - flags 0x%02x, owner %i, sector %2i, catapult sector %2i, eco-sector %2i.",
           a2,
           v11,
           v12,
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10);
}


// address=[0x15f8b70]
// Decompiled from void __thiscall CWalkingBase::AttachWalking(CWalkingBase *this, struct CWalkingBase *a2)
void  CWalkingBase::AttachWalking(class CWalkingBase * a2) {
  
  if ( !a2 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 430, "_pWalking != 0") == 1 )
    __debugbreak();
  if ( a2 == this && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 431, "_pWalking != this") == 1 )
    __debugbreak();
  if ( a2->m_sData.m_pPrevWalking
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 432, "_pWalking->m_sData.m_pPrevWalking == 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sData.m_pLatestWalking != a2 )
  {
    this->DetachWalking(this);
    this->m_sData.m_pPrevWalking = a2;
    this->m_sData.m_pNextWalking = a2->m_sData.m_pNextWalking;
    this->m_sData.m_pLatestWalking = a2;
    if ( a2->m_sData.m_pNextWalking )
      a2->m_sData.m_pNextWalking->m_sData.m_pPrevWalking = this;
    a2->m_sData.m_pNextWalking = this;
    if ( a2->m_sData.m_iWalkToXY >= 0 )
      a2->m_sData.m_iWalkState = 8;
    this->m_sData.m_iWalkingType = a2->GetWalkingType(a2);
  }
}


// address=[0x15f8c90]
// Decompiled from _DWORD *__thiscall CWalkingBase::DetachWalking(CWalkingBase *this)
class CWalking *  CWalkingBase::DetachWalking(void) {
  
  int v2; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-8h]

  this->m_sData.m_iWalkToXY = this->m_sData.m_iLeaderWalkToXY;
  if ( this->m_sData.m_pPrevWalking )
  {
    if ( *(CWalkingBase **)(this->m_sData.m_pPrevWalking + 184) != this
      && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 372, "m_sData.m_pPrevWalking->m_sData.m_pNextWalking == this") == 1 )
    {
      __debugbreak();
    }
    if ( this->m_sData.m_pNextWalking )
    {
      if ( *(CWalkingBase **)(this->m_sData.m_pNextWalking + 180) != this
        && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 376, "m_sData.m_pNextWalking->m_sData.m_pPrevWalking == this") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this->m_sData.m_pPrevWalking + 184) = this->m_sData.m_pNextWalking;
      *(_DWORD *)(this->m_sData.m_pNextWalking + 180) = this->m_sData.m_pPrevWalking;
    }
    else
    {
      *(_DWORD *)(this->m_sData.m_pPrevWalking + 184) = 0;
    }
    this->m_sData.m_pPrevWalking = 0;
    this->m_sData.m_pNextWalking = 0;
    this->m_sData.m_pLatestWalking = 0;
    return 0;
  }
  else
  {
    v4 = (_DWORD *)this->m_sData.m_pNextWalking;
    this->m_sData.m_pPrevWalking = 0;
    this->m_sData.m_pNextWalking = 0;
    this->m_sData.m_pLatestWalking = 0;
    if ( !v4 )
      return v4;
    v4[45] = 0;
    v4[47] = 0;
    for ( i = v4[46]; i; i = v2 )
    {
      v2 = *(_DWORD *)(i + 184);
      if ( v2
        && *(_DWORD *)(v2 + 180) != i
        && BBSupportDbgReport(
             2,
             "Pathing\\Walking.cpp",
             411,
             "(pNextWalking == 0) || (pNextWalking->m_sData.m_pPrevWalking == pWalking)") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(i + 188) = v4;
    }
    return v4;
  }
}


// address=[0x15f8e70]
// Decompiled from _DWORD *__thiscall CWalkingBase::GroupLeaderWalking(CWalkingBase *this, int a2, int a3)
void  CWalkingBase::GroupLeaderWalking(int a2, int a3) {
  
  _DWORD *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // [esp-4h] [ebp-2Ch]
  int v8; // [esp+0h] [ebp-28h]
  _DWORD *v10; // [esp+8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-1Ch]
  int v12; // [esp+10h] [ebp-18h]
  int v13; // [esp+14h] [ebp-14h]
  _DWORD *v14; // [esp+18h] [ebp-10h]
  unsigned int v15; // [esp+1Ch] [ebp-Ch]
  unsigned int v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h]

  v13 = Y16X16::UnpackXFast(a2);
  v12 = Y16X16::UnpackYFast(a2);
  result = (_DWORD *)CWorldManager::SectorId(v13, v12);
  v10 = result;
  if ( result )
  {
    v14 = *(_DWORD **)this->m_sData.m_pNextWalking;
    v17 = 1;
    v8 = 0;
    v11 = 0;
    while ( v14 )
    {
      v15 = v13 + 2 * CSpiralOffsets::DeltaX(v17);
      v16 = v12 + 2 * CSpiralOffsets::DeltaY(v17);
      while ( 1 )
      {
        if ( CWorldManager::InWorld(v15, v16) )
        {
          v4 = CWorldManager::Index(v15, v16);
          if ( (_DWORD *)CWorldManager::SectorId(v4) == v10 )
          {
            v5 = CWorldManager::Index(v15, v16);
            if ( !CWorldManager::IsBlockedLand(v5) )
              break;
          }
        }
        if ( ++v17 > 4000 )
          v17 = 1;
        v15 = v13 + 2 * CSpiralOffsets::DeltaX(v17);
        v16 = v12 + 2 * CSpiralOffsets::DeltaY(v17);
        if ( ++v11 > 200000 && BBSupportDbgReport(1, "Pathing\\Walking.cpp", 629, "Endless loop detected!") == 1 )
          __debugbreak();
      }
      v7 = (a3 | CWalkingBase::Flags(this)) & 0xFFF43060;
      v6 = Y16X16::PackXYFast(v15, v16);
      (*(void (__thiscall **)(_DWORD *, int, unsigned int))(*v14 + 8))(v14, v6, v7);
      if ( ++v17 > 4000 )
        v17 = 1;
      ++v8;
      result = v14;
      v14 = (_DWORD *)v14[46];
    }
  }
  else
  {
    result = (_DWORD *)BBSupportDbgReport(
                         1,
                         "Pathing\\Walking.cpp",
                         642,
                         "CWalkingBase::GroupLeaderWalking(): Invalid waypoint!");
    if ( result == (_DWORD *)1 )
      __debugbreak();
  }
  return result;
}


// address=[0x15fb200]
// Decompiled from int __thiscall CWalkingBase::Flags(CWalkingBase *this)
int  CWalkingBase::Flags(void) {
  
  return this->m_sData.m_uFlags;
}


// address=[0x15fb2b0]
// Decompiled from char __thiscall CWalkingBase::IsNeighborTile(CWalkingBase *this, int a2, int a3)
bool  CWalkingBase::IsNeighborTile(int a2, int a3) {
  
  CLinkList *v4; // [esp+4h] [ebp-8h]
  CTile *v5; // [esp+8h] [ebp-4h]

  v5 = ITiling::Tile(a2);
  v4 = CTile::LinkList(v5);
  return CLinkList::SearchForLinkTileId(v4, a3);
}


// address=[0x15fb300]
// Decompiled from char __thiscall CWalkingBase::NextCoarseWaypoint(CWalkingBase *this, int a2)
bool  CWalkingBase::NextCoarseWaypoint(int a2) {
  
  int v3; // eax
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int iCurrentSectorId; // [esp+1Ch] [ebp-8h]

  if ( CWaypoints::CachedWaypointsCount(&this->m_sData.m_cCoarseWaypoints) <= 0
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 734, "m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0") == 1 )
  {
    __debugbreak();
  }
  v4 = Y16X16::UnpackXFast(a2);
  v5 = Y16X16::UnpackYFast(a2);
  v9 = CWorldManager::Index(v4, v5);
  iCurrentSectorId = this->SectorId(this, v9);
  v7 = this->TileId(this, v9);
  if ( iCurrentSectorId <= 0 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 744, "iCurrentSectorId > 0") == 1 )
    __debugbreak();
  while ( 1 )
  {
    v8 = CWorldManager::Index(this->m_sData.m_iCoarseWaypointXY);
    v6 = this->TileId(this, v8);
    if ( this->SectorId(this, v8) != iCurrentSectorId )
      return 0;
    if ( v6 != v7 && !CWalkingBase::IsNeighborTile(this, v6, v7) )
      return 1;
    this->m_sData.m_iCoarseWaypointXY = CWaypoints::Back(&this->m_sData.m_cCoarseWaypoints);
    CWaypoints::PopBack(&this->m_sData.m_cCoarseWaypoints);
    if ( this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY )
      break;
    if ( CWaypoints::CachedWaypointsCount(&this->m_sData.m_cCoarseWaypoints) <= 0 )
      return 0;
  }
  v3 = CWorldManager::Index(this->m_sData.m_iCoarseWaypointXY);
  if ( this->SectorId(this, v3) != iCurrentSectorId
    && BBSupportDbgReport(
         2,
         "Pathing\\Walking.cpp",
         768,
         "SectorId(g_cWorld.Index(m_sData.m_iCoarseWaypointXY)) == iCurrentSectorId") == 1 )
  {
    __debugbreak();
  }
  return 1;
}


#endif // Already implemented
