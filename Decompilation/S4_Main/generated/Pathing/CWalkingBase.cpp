#include "all_headers.h"

// Definitions for class CWalkingBase

// address=[0x15f6660]
// Decompiled from CWalking *__thiscall CWalkingBase::~CWalkingBase(CWalkingBase *this)
 CWalkingBase::~CWalkingBase(void) {
  
  *(_DWORD *)this = &CWalkingBase::_vftable_;
  CWalkingBase::DetachWalking(this);
  return CWalking::~CWalking(this);
}


// address=[0x15f66b0]
// Decompiled from int __thiscall CWalkingBase::Store(int *this, int a2)
void  CWalkingBase::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-10h] BYREF
  int *v4; // [esp+4h] [ebp-Ch]
  __int16 v5; // [esp+8h] [ebp-8h] BYREF
  __int16 v6; // [esp+Ch] [ebp-4h] BYREF

  v4 = this;
  v3 = 929995208;
  operator^<int>(a2, &v3);
  v6 = 1;
  operator^<short>(a2, &v6);
  v5 = (*(int (__thiscall **)(int *))(*v4 + 60))(v4);
  operator^<short>(a2, &v5);
  operator^<int>(a2, v4 + 12);
  operator^<int>(a2, v4 + 2);
  operator^<int>(a2, v4 + 3);
  operator^<int>(a2, v4 + 4);
  operator^<int>(a2, v4 + 5);
  operator^<int>(a2, v4 + 6);
  operator^<int>(a2, v4 + 7);
  operator^<int>(a2, v4 + 8);
  operator^<int>(a2, v4 + 9);
  operator^<int>(a2, v4 + 10);
  operator^<int>(a2, v4 + 11);
  operator^<int>(a2, v4 + 13);
  operator^<int>(a2, v4 + 14);
  operator^<int>(a2, v4 + 15);
  operator^<int>(a2, v4 + 16);
  operator^<int>(a2, v4 + 17);
  v3 = 1726811097;
  return operator^<int>(a2, &v3);
}


// address=[0x15f6860]
// Decompiled from int __thiscall CWalkingBase::Init(CWalkingBase *this, int a2, int a3)
void  CWalkingBase::Init(int,int) {
  
  int result; // eax
  unsigned int v5; // [esp+14h] [ebp+Ch]

  if ( (a3 & 0xBC000) != 0
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 524, "(_iFlags & WALK_FLAG_STRICT_INTERNAL_USE_MASK) == 0") == 1 )
  {
    __debugbreak();
  }
  v5 = a3 & 0xFFF43060;
  if ( a2 < 0 )
  {
    *((_DWORD *)this + 4) = -1;
    *((_DWORD *)this + 8) = 0;
    *((_DWORD *)this + 2) = a2 != -1;
  }
  else
  {
    *((_DWORD *)this + 4) = a2;
    *((_DWORD *)this + 8) = CWorldManager::Index(a2);
    *((_DWORD *)this + 2) = 8;
  }
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 5) = *((_DWORD *)this + 4);
  *((_DWORD *)this + 12) = *((_DWORD *)this + 13) | v5;
  *((_DWORD *)this + 9) = 0;
  result = v5 & 0x40000;
  if ( (v5 & 0x40000) != 0 )
    return result;
  result = *((_DWORD *)this + 4);
  *((_DWORD *)this + 6) = result;
  return result;
}


// address=[0x15f6950]
// Decompiled from void __thiscall CWalkingBase::Init(CWalkingBase *this, struct CWalking *a2, int a3)
void  CWalkingBase::Init(class CWalking *,int) {
  
  (*(void (__thiscall **)(CWalkingBase *, int, int))(*(_DWORD *)this + 8))(this, -1, a3);
  CWalkingBase::AttachWalking(this, a2);
}


// address=[0x15f6980]
// Decompiled from CWalkingBase *__thiscall CWalkingBase::InitIfLeader(CWalkingBase *this, int a2, int a3)
void  CWalkingBase::InitIfLeader(int,int) {
  
  CWalkingBase *result; // eax
  int v4; // [esp+0h] [ebp-8h]

  *((_DWORD *)this + 6) = a2;
  if ( !*((_DWORD *)this + 47) )
    return (CWalkingBase *)(*(int (__thiscall **)(CWalkingBase *, int, int))(*(_DWORD *)this + 8))(this, a2, a3);
  result = this;
  v4 = *((_DWORD *)this + 2);
  if ( v4 > 0 && v4 <= 5 )
    return (CWalkingBase *)(*(int (__thiscall **)(CWalkingBase *, int, int))(*(_DWORD *)this + 8))(
                             this,
                             -1,
                             a3 | 0x40000);
  return result;
}


// address=[0x15f69f0]
// Decompiled from int __thiscall CWalkingBase::Walk(CWalkingBase *this, Y16X16 *a2)
int  CWalkingBase::Walk(int) {
  
  void *v2; // eax
  const char *v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  Y16X16 *v12; // eax
  Y16X16 *v13; // eax
  void *v14; // eax
  const char *v15; // eax
  void *v16; // eax
  const char *v17; // eax
  int v18; // [esp+0h] [ebp-138h]
  CEvn_Event *v19; // [esp+Ch] [ebp-12Ch]
  CEvn_Event *v20; // [esp+10h] [ebp-128h]
  int v21; // [esp+18h] [ebp-120h]
  int v22; // [esp+1Ch] [ebp-11Ch]
  int v23; // [esp+34h] [ebp-104h]
  int v24; // [esp+44h] [ebp-F4h]
  int v25; // [esp+48h] [ebp-F0h]
  int v26; // [esp+4Ch] [ebp-ECh]
  int v27; // [esp+50h] [ebp-E8h]
  int v28; // [esp+60h] [ebp-D8h]
  int v29; // [esp+6Ch] [ebp-CCh]
  int Path; // [esp+80h] [ebp-B8h]
  int v31; // [esp+8Ch] [ebp-ACh]
  char v32; // [esp+90h] [ebp-A8h]
  struct CWalking *v33; // [esp+98h] [ebp-A0h]
  bool v34; // [esp+A0h] [ebp-98h]
  int v35; // [esp+B8h] [ebp-80h]
  int v36; // [esp+BCh] [ebp-7Ch]
  int v37; // [esp+C0h] [ebp-78h]
  int v38; // [esp+C4h] [ebp-74h]
  int v39; // [esp+C8h] [ebp-70h]
  int v40; // [esp+CCh] [ebp-6Ch]
  int v41; // [esp+D0h] [ebp-68h]
  int v42; // [esp+D4h] [ebp-64h]
  int j; // [esp+D8h] [ebp-60h]
  int v44; // [esp+DCh] [ebp-5Ch]
  void **v45; // [esp+E0h] [ebp-58h]
  _DWORD *i; // [esp+E4h] [ebp-54h]
  char v47; // [esp+EBh] [ebp-4Dh]
  int v48; // [esp+ECh] [ebp-4Ch]
  char v49; // [esp+F1h] [ebp-47h]
  char v50; // [esp+F2h] [ebp-46h]
  char v51; // [esp+F3h] [ebp-45h]
  CEvn_Event v53; // [esp+F8h] [ebp-40h] BYREF
  CEvn_Event v54; // [esp+110h] [ebp-28h] BYREF
  int v55; // [esp+134h] [ebp-4h]

  v39 = Y16X16::UnpackXFast((int)a2);
  v40 = Y16X16::UnpackYFast((int)a2);
  if ( !(unsigned __int8)CWorldManager::InWorld(v39, v40)
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 796, "g_cWorld.InWorld(iDbgCurrentX, iDbgCurrentY)") == 1 )
  {
    __debugbreak();
  }
  v41 = CWorldManager::Index(v39, v40);
  v24 = CWorldManager::MapObjectId(v41);
  if ( !(*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v41)
    || (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v41) <= 0 )
  {
    v2 = (void *)typeid(this);
    v3 = (const char *)type_info::name(v2);
    BBSupportTracePrintF(0, "Walk() [%s]: Invalid current position!", v3);
    BBSupportTracePrintF(0, "  WalkState: %i.", *((_DWORD *)this + 2));
    CWalkingBase::DbgPrintElementInfo(this, "  Current:   ", a2);
    CWalkingBase::DbgPrintElementInfo(this, "  WalkTo:    ", *((_DWORD *)this + 4));
    CWalkingBase::DbgPrintElementInfo(this, "  WalkTo2:   ", *((_DWORD *)this + 5));
    BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", v39, v40, v24);
    CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v24, 0, 0);
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)g_pTiling + 72))(g_pTiling, 0);
    v19 = CEvn_Event::CEvn_Event(&v53, 0xDu, 0x70u, 0, 0);
    v55 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v19);
    v55 = -1;
    CEvn_Event::~CEvn_Event(&v53);
    if ( BBSupportDbgReport(
           1,
           "Pathing\\Walking.cpp",
           818,
           "Invalid walk position! Dietmar: I need the trace file. [Ignore --> Pause]") == 1 )
      __debugbreak();
  }
  if ( *((_DWORD *)this + 6) != *((_DWORD *)this + 4) && *((_DWORD *)this + 47) == 0 )
  {
    v4 = CWalkingBase::Flags(this);
    (*(void (__thiscall **)(CWalkingBase *, _DWORD, unsigned int))(*(_DWORD *)this + 8))(
      this,
      *((_DWORD *)this + 6),
      v4 & 0xFFF43060);
  }
  if ( *((_DWORD *)this + 2) > 5u )
  {
    *((_DWORD *)this + 12) &= ~0x20000u;
    if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(*((_DWORD *)this + 4))
      && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 843, "g_cWorld.InWorldPackedXY(m_sData.m_iWalkToXY)") == 1 )
    {
      __debugbreak();
    }
    CWalkingBase::GoalCheck(this, a2);
  }
  v50 = 0;
  v49 = 0;
  v51 = 0;
  v38 = 0;
  while ( v38 < 32 )
  {
    switch ( *((_DWORD *)this + 2) )
    {
      case 0:
        return (*(int (__thiscall **)(CWalkingBase *, Y16X16 *, _DWORD))(*(_DWORD *)this + 16))(this, a2, 0) | 0x10;
      case 1:
        *((_DWORD *)this + 17) = 0;
        *((_DWORD *)this + 2) = 2;
        return 72;
      case 2:
        return (*(int (__thiscall **)(CWalkingBase *, Y16X16 *, _DWORD))(*(_DWORD *)this + 16))(this, a2, 0) | 0x50;
      case 3:
        *((_DWORD *)this + 17) = 0;
        if ( *((_DWORD *)this + 45) == 0 && *((_DWORD *)this + 46) != 0 )
          CWalkingBase::GroupLeaderWalking(this, *((_DWORD *)this + 5), 0);
        if ( (*((_DWORD *)this + 12) & 0x40000) != 0 )
        {
          *((_DWORD *)this + 2) = 0;
          return 24;
        }
        else
        {
          if ( (*((_DWORD *)this + 12) & 0x4000) != 0 )
            *((_DWORD *)this + 2) = 4;
          else
            *((_DWORD *)this + 2) = 5;
          return 40;
        }
      case 4:
        return 40;
      case 5:
        return (*(int (__thiscall **)(CWalkingBase *, Y16X16 *, _DWORD))(*(_DWORD *)this + 16))(this, a2, 0) | 0x30;
      case 6:
        if ( v51 )
          goto LABEL_50;
        if ( (int)++*((_DWORD *)this + 9) <= 16 )
        {
          if ( *((int *)this + 9) > 2 )
          {
            v34 = Y16X16::DistanceFast(a2, *((_DWORD *)this + 4)) <= 3;
            if ( (CWalkingBase::Flags(this) & 0x2000) != 0 && v34 )
              *((_DWORD *)this + 2) = 3;
            else
              *((_DWORD *)this + 2) = 9;
            goto LABEL_16;
          }
          if ( Y16X16::DistanceFast(a2, *((_DWORD *)this + 10)) == 1 )
          {
            v23 = CWorldManager::Index(*((_DWORD *)this + 10));
            v37 = CWorldManager::OccupyingEntityId(v23);
            if ( v37 )
            {
              v45 = (void **)CMapObjectMgr::EntityPtr(v37);
              if ( v45 )
              {
                if ( !j____RTDynamicCast(
                        v45,
                        0,
                        &IEntity__RTTI_Type_Descriptor_,
                        &IMovingEntity__RTTI_Type_Descriptor_,
                        0)
                  && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 961, "dynamic_cast<IMovingEntity*>(pEntity) != 0") == 1 )
                {
                  __debugbreak();
                }
                v33 = IMovingEntity::Walking((IMovingEntity *)v45);
                if ( v33 )
                {
                  if ( *((_DWORD *)v33 + 2) == 6 && *((Y16X16 **)v33 + 10) == a2 )
                  {
                    *((_DWORD *)this + 2) = 9;
                    goto LABEL_16;
                  }
                }
              }
            }
          }
          v51 = 1;
LABEL_50:
          if ( *((Y16X16 **)this + 10) == a2 )
          {
            *((_DWORD *)this + 9) = 0;
            if ( CDirCache::Count((CWalkingBase *)((char *)this + 160)) <= 0 )
            {
              *((_DWORD *)this + 2) = 9;
              goto LABEL_16;
            }
            v48 = CDirCache::Back((CWalkingBase *)((char *)this + 160));
            *((_DWORD *)this + 10) = (char *)a2 + Y16X16::NeighborModifier((Y16X16 *)v48);
            CDirCache::PopBack((CWalkingBase *)((char *)this + 160));
          }
          else
          {
            if ( Y16X16::DistanceFast(a2, *((_DWORD *)this + 10)) != 1 )
            {
              *((_DWORD *)this + 2) = 9;
              goto LABEL_16;
            }
            v48 = Y16X16::DirectionFast(a2, *((_DWORD *)this + 10));
          }
          if ( v48 < 0 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1018, "iDir >= 0") == 1 )
            __debugbreak();
          if ( *((Y16X16 **)this + 10) != (Y16X16 *)((char *)a2 + Y16X16::NeighborModifier((Y16X16 *)v48))
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1019,
                 "m_sData.m_iFineWaypointXY == _iCurrentXY + Y16X16::NeighborModifier(iDir)") == 1 )
          {
            __debugbreak();
          }
          if ( *((_DWORD *)this + 1) == 4 )
          {
            v6 = CWorldManager::Index(*((_DWORD *)this + 10));
            if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v6) )
            {
              v7 = CWorldManager::Index(*((_DWORD *)this + 10));
              v32 = CWaterFlags::WaterFlags(v7);
              v44 = (v32 & 0xF0) >> 4;
              if ( v44 )
                *((_DWORD *)this + 2) = 9;
              if ( v44 > 2 )
              {
                v8 = Y16X16::NeighborModifier((Y16X16 *)(v48 + 3));
                v9 = CWorldManager::Index((int)a2 + v8);
                CWaterFlags::WaterFlags(v9);
                if ( (v32 & 0xF0) >> 4 < v44 + 2 )
                {
                  if ( (int)Y16X16::DistanceFast(a2, *((_DWORD *)this + 4)) > 3 )
                  {
                    v31 = *((_DWORD *)this + 14) + 1;
                    *((_DWORD *)this + 14) = v31;
                    if ( v31 >= 2 && v44 <= 7 )
                      return v48;
                    else
                      return 136;
                  }
                  else
                  {
                    *((_DWORD *)this + 2) = 3;
                    return 40;
                  }
                }
                else
                {
                  *((_DWORD *)this + 14) = 0;
                  return v48;
                }
              }
              else
              {
                *((_DWORD *)this + 14) = 0;
                return v48;
              }
            }
            else
            {
              if ( "Waypoint blocked --> WALK_NO_PATH"
                && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1073, "!\"Waypoint blocked --> WALK_NO_PATH\"") == 1 )
              {
                __debugbreak();
              }
              *((_DWORD *)this + 2) = 1;
              return 72;
            }
          }
          else
          {
            v10 = CWorldManager::Index(*((_DWORD *)this + 10));
            if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v10) )
              return v48;
            if ( v50 )
            {
              CTrace::Print(">>>>>> CWalking::Walk(): Waypoint blocked! <<<<<<");
              *((_DWORD *)this + 2) = 7;
            }
            else
            {
              v50 = 1;
              *((_DWORD *)this + 2) = 9;
            }
            goto LABEL_16;
          }
        }
        else
        {
          *((_DWORD *)this + 9) = 0;
          *((_DWORD *)this + 2) = 7;
          return (*(int (__thiscall **)(CWalkingBase *, Y16X16 *, _DWORD))(*(_DWORD *)this + 16))(this, a2, 0);
        }
      case 7:
        *((_DWORD *)this + 2) = 8;
        CWalkingBase::GoalCheck(this, a2);
        if ( *((_DWORD *)this + 2) != 8 )
          CTrace::Print(
            "### CWalkingBase::Walk(): STATE_EX_GOAL_CHECK has changed walk state! New state %i. ###",
            *((_DWORD *)this + 2));
        goto LABEL_16;
      case 8:
        v11 = CWalkingBase::Flags(this);
        Path = CAStarTiling::FindPath(a2, *((_DWORD *)this + 5), (CWalkingBase *)((char *)this + 72), v11);
        if ( Path )
        {
          if ( ((Path < 0) & ((CWalkingBase::Flags(this) & 0x40) != 0)) != 0 )
          {
            *((_DWORD *)this + 4) = CWaypoints::Goal((CWalkingBase *)((char *)this + 72));
            *((_DWORD *)this + 5) = *((_DWORD *)this + 4);
            *((_DWORD *)this + 8) = CWorldManager::Index(*((_DWORD *)this + 4));
          }
          if ( CWaypoints::CachedWaypointsCount((CWalkingBase *)((char *)this + 72)) <= 0
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1152,
                 "m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0") == 1 )
          {
            __debugbreak();
          }
          *((_DWORD *)this + 11) = CWaypoints::Back((char *)this + 72, v18);
          CWaypoints::PopBack((char *)this + 72);
          if ( CWaypoints::CachedWaypointsCount((CWalkingBase *)((char *)this + 72)) <= 0
            && *((_DWORD *)this + 11) != *((_DWORD *)this + 5)
            && BBSupportDbgReport(
                 2,
                 "Pathing\\Walking.cpp",
                 1163,
                 "(m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0) || (m_sData.m_iCoarseWaypointXY == m_sData.m_iWalkToXY2)") == 1 )
          {
            __debugbreak();
          }
          *((_DWORD *)this + 2) = 9;
        }
        else
        {
          *((_DWORD *)this + 2) = 1;
        }
        goto LABEL_16;
      case 9:
        if ( !*((_DWORD *)this + 17) )
          goto LABEL_113;
        if ( *((_DWORD *)this + 45) == 0 && *((_DWORD *)this + 46) != 0 )
        {
          if ( *((int *)this + 17) < 0 || (int)Y16X16::DistanceFast(*((Y16X16 **)this + 17), a2) <= 2 )
          {
            v36 = 0;
            v35 = 0;
            for ( i = (_DWORD *)*((_DWORD *)this + 46); i; i = (_DWORD *)i[46] )
            {
              if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*i + 52))(i, 0) >= 6 )
                ++v35;
              ++v36;
            }
            if ( v35 > v36 / 4 )
            {
              *((_DWORD *)this + 17) = -1;
              return (*(int (__thiscall **)(CWalkingBase *, Y16X16 *, _DWORD))(*(_DWORD *)this + 16))(this, a2, 0) | 0x10;
            }
          }
        }
        else
        {
          *((_DWORD *)this + 17) = 0;
        }
LABEL_113:
        if ( *((_DWORD *)this + 11) == *((_DWORD *)this + 5) )
          goto LABEL_119;
        v47 = CWaypoints::GoalCached((CWalkingBase *)((char *)this + 72));
        v29 = CWaypoints::CachedWaypointsCount((CWalkingBase *)((char *)this + 72));
        if ( v29 && (v29 >= 2 || v47 != 0) )
        {
          if ( CWalkingBase::NextCoarseWaypoint(this, (int)a2) )
          {
LABEL_119:
            if ( *((_DWORD *)this + 11) == *((_DWORD *)this + 5) )
              v28 = *((_DWORD *)this + 4);
            else
              v28 = *((_DWORD *)this + 11);
            if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, Y16X16 *, int, char *))(*(_DWORD *)this + 68))(
                   this,
                   a2,
                   v28,
                   (char *)this + 160) )
            {
              if ( CDirCache::Count((CWalkingBase *)((char *)this + 160)) <= 0
                && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1251, "m_sData.m_cFineWaypoints.Count() > 0") == 1 )
              {
                __debugbreak();
              }
              v12 = (Y16X16 *)CDirCache::Back((CWalkingBase *)((char *)this + 160));
              *((_DWORD *)this + 10) = (char *)a2 + Y16X16::NeighborModifier(v12);
              CDirCache::PopBack((CWalkingBase *)((char *)this + 160));
              if ( *((_DWORD *)this + 45) == 0 && *((_DWORD *)this + 46) != 0 )
              {
                v22 = CDirCache::Count((CWalkingBase *)((char *)this + 160));
                v42 = *((_DWORD *)this + 10);
                for ( j = 0; j < v22; ++j )
                {
                  v13 = (Y16X16 *)CDirCache::operator[]((_BYTE *)this + 160, j);
                  v42 += Y16X16::NeighborModifier(v13);
                }
                *((_DWORD *)this + 17) = v42;
                CWalkingBase::GroupLeaderWalking(this, v42, 0x40000);
              }
              if ( Y16X16::DistanceFast(a2, *((_DWORD *)this + 10)) != 1
                && BBSupportDbgReport(
                     2,
                     "Pathing\\Walking.cpp",
                     1272,
                     "Y16X16::DistanceFast(_iCurrentXY, m_sData.m_iFineWaypointXY) == 1") == 1 )
              {
                __debugbreak();
              }
              *((_DWORD *)this + 2) = 6;
            }
            else
            {
              v26 = Y16X16::UnpackXFast((int)a2);
              v27 = Y16X16::UnpackYFast((int)a2);
              v21 = CWorldManager::Index(v26, v27);
              v25 = CWorldManager::MapObjectId(v21);
              v14 = (void *)typeid(this);
              v15 = (const char *)type_info::name(v14);
              BBSupportTracePrintF(0, "Walk() [%s]: FindPathAStar64() failed!", v15);
              CWalkingBase::DbgPrintElementInfo(this, "  Current:  ", a2);
              CWalkingBase::DbgPrintElementInfo(this, "  Waypoint: ", v28);
              CWalkingBase::DbgPrintElementInfo(this, "  WalkTo:   ", *((_DWORD *)this + 4));
              CWalkingBase::DbgPrintElementInfo(this, "  WalkTo2:  ", *((_DWORD *)this + 5));
              BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", v26, v27, v25);
              CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v25, 0, 0);
              (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)g_pTiling + 72))(g_pTiling, 0);
              if ( v49 )
              {
                v20 = CEvn_Event::CEvn_Event(&v54, 0xDu, 0x70u, 0, 0);
                v55 = 1;
                IEventEngine::SendAMessage(g_pEvnEngine, v20);
                v55 = -1;
                CEvn_Event::~CEvn_Event(&v54);
                if ( BBSupportDbgReport(
                       1,
                       "Pathing\\Walking.cpp",
                       1315,
                       "FindPathAStar64 failed! Dietmar: I need the trace file. [Ignore --> Pause]") == 1 )
                  __debugbreak();
                *((_DWORD *)this + 2) = 1;
              }
              else
              {
                BBSupportTracePrintF(0, "FindPathAStar64 failed once [may be ignored]");
                v49 = 1;
                *((_DWORD *)this + 2) = 7;
              }
            }
          }
          else
          {
            *((_DWORD *)this + 2) = 8;
          }
        }
        else
        {
          *((_DWORD *)this + 2) = 8;
        }
LABEL_16:
        ++v38;
        break;
      default:
        if ( "Walk(): Invalid walk state!"
          && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1325, "!\"Walk(): Invalid walk state!\"") == 1 )
        {
          __debugbreak();
        }
        *((_DWORD *)this + 2) = 1;
        goto LABEL_16;
    }
  }
  v16 = (void *)typeid(this);
  v17 = (const char *)type_info::name(v16);
  BBSupportTracePrintF(3, "### Walk() [%s]: LoopCount >= 32! ###", v17);
  *((_DWORD *)this + 2) = 7;
  return 8;
}


// address=[0x15f7bc0]
// Decompiled from int __thiscall CWalkingBase::IdleWalk(CWalkingBase *this, Y16X16 *a2, int a3)
int  CWalkingBase::IdleWalk(int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-D4h]
  int v6; // [esp+4h] [ebp-D0h]
  __int64 v7; // [esp+10h] [ebp-C4h]
  int v8; // [esp+18h] [ebp-BCh]
  int v9; // [esp+1Ch] [ebp-B8h]
  int v10; // [esp+20h] [ebp-B4h]
  int v11; // [esp+24h] [ebp-B0h]
  int v12; // [esp+28h] [ebp-ACh]
  int v13; // [esp+2Ch] [ebp-A8h]
  int v14; // [esp+30h] [ebp-A4h]
  int v15; // [esp+34h] [ebp-A0h]
  int v16; // [esp+38h] [ebp-9Ch]
  int v17; // [esp+3Ch] [ebp-98h]
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
  v15 = CWorldManager::Index((int)a2);
  for ( i = 0; i < 6; ++i )
  {
    v19 = v15 + CWorldManager::NeighborRelIndex(i);
    if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v19) )
    {
      if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 24))(this, v19) )
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
    *((_DWORD *)this + 7) = -1;
    if ( (CWalkingBase::Flags(this) & 0x20000) != 0
      && v40[Grid::TurnLeft(*((Grid **)this + 3))] == 2
      && v40[*((_DWORD *)this + 3)] == 2
      && v40[*((_DWORD *)this + 3) + 1] == 2 )
    {
      *((_DWORD *)this + 12) &= ~0x20000u;
      return *((_DWORD *)this + 3);
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
            if ( CWorldManager::InWorld(v23)
              && (*(unsigned __int8 (__thiscall **)(CWalkingBase *, unsigned int))(*(_DWORD *)this + 20))(this, v23) )
            {
              if ( (*(unsigned __int8 (__thiscall **)(CWalkingBase *, unsigned int))(*(_DWORD *)this + 24))(this, v23) )
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
            v29 = CStateGame::Rand(g_pGame) % (unsigned int)v29;
          for ( ii = 0; ii < 6; ++ii )
          {
            if ( v29 < v40[ii] )
            {
              *((_DWORD *)this + 12) |= 0x20000u;
              *((_DWORD *)this + 3) = ii;
              return ii;
            }
          }
        }
      }
      *((_DWORD *)this + 12) &= ~0x20000u;
      return 8;
    }
  }
  else
  {
    v3 = CWorldManager::Index((int)a2);
    v9 = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v3);
    if ( (*((_DWORD *)this + 12) & 0x20000) == 0 )
      *((_DWORD *)this + 7) = -1;
    *((_DWORD *)this + 12) &= ~0x20000u;
    if ( (unsigned __int8)CWorldManager::InWorldPackedXY(*((_DWORD *)this + 7)) )
    {
      v11 = CWorldManager::Index(*((_DWORD *)this + 7));
      v10 = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v11);
      if ( CWorldManager::MoveCostsBits(v11) == 7 || v10 <= 0 || v9 != v10 )
        *((_DWORD *)this + 7) = -1;
    }
    else
    {
      *((_DWORD *)this + 7) = -1;
    }
    if ( *((int *)this + 7) < 0 )
    {
      v6 = Y16X16::UnpackXFast((int)a2);
      v5 = Y16X16::UnpackYFast((int)a2);
      v16 = -1;
      v8 = -1;
      for ( jj = 0; jj < SurroundingHexPointsCount(15); ++jj )
      {
        v12 = v6 + SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * jj]);
        v17 = v5 + SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * jj]);
        if ( (unsigned __int8)CWorldManager::InWorld(v12, v17) )
        {
          v13 = CWorldManager::Index(v12, v17);
          if ( (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v13) == v9
            && (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 24))(this, v13)
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
      *((_DWORD *)this + 7) = Y16X16::PackXYFast(v16, v8);
    }
    v30 = Y16X16::DirectionFast(a2, *((_DWORD *)this + 7));
    v27 = v40[Grid::TurnLeft((Grid *)v30)];
    v26 = v40[Grid::TurnLeft((Grid *)v30)];
    if ( v40[v30] < v27 || v40[v30] < v26 )
    {
      if ( v27 == v26 )
        CStateGame::Rand(g_pGame);
      v30 = Grid::TurnLeft((Grid *)v30);
    }
    if ( (int)v40[v30] <= 0 )
      v30 = 8;
    if ( v30 == 8 )
      *((_DWORD *)this + 7) = -1;
    return v30;
  }
}


// address=[0x15f8420]
// Decompiled from int __thiscall CWalkingBase::DestinationXY(CWalkingBase *this)
int  CWalkingBase::DestinationXY(void)const {
  
  return *((_DWORD *)this + 4);
}


// address=[0x15f8440]
// Decompiled from int __thiscall CWalkingBase::State(CWalkingBase *this, int a2)
int  CWalkingBase::State(int)const {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]

  switch ( *((_DWORD *)this + 2) )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = *((_DWORD *)this + 2) + 1;
      break;
    case 6:
      if ( *((_DWORD *)this + 5) == *((_DWORD *)this + 11) )
      {
        v6 = Y16X16::DistanceFast(*((Y16X16 **)this + 4), *((_DWORD *)this + 10));
        if ( v6 <= 14 )
          v4 = v6 + 1;
        else
          v4 = 15;
        result = 16 * v4;
      }
      else
      {
        v5 = Y16X16::DistanceFast(*((Y16X16 **)this + 4), *((_DWORD *)this + 11));
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
  
  return *((_DWORD *)this + 13) & 0xF;
}


// address=[0x15f85a0]
// Decompiled from bool __thiscall CWalkingBase::IsNotBlocked(CWalkingBase *this, int a2)
bool  CWalkingBase::IsNotBlocked(int) {
  
  return (unsigned __int8)CWorldManager::IsBlockedLand(a2) == 0;
}


// address=[0x15f85e0]
// Decompiled from bool __thiscall CWalkingBase::IsNotOccupied(CWalkingBase *this, int a2)
bool  CWalkingBase::IsNotOccupied(int) {
  
  return CWorldManager::OccupyingEntityId(a2) == 0;
}


// address=[0x15f8620]
// Decompiled from int __thiscall CWalkingBase::SectorId(CWalkingBase *this, int a2)
int  CWalkingBase::SectorId(int) {
  
  return ITiling::SectorId(a2);
}


// address=[0x15f8640]
// Decompiled from int __thiscall CWalkingBase::TileId(CWalkingBase *this, int a2)
int  CWalkingBase::TileId(int) {
  
  return ITiling::NormalTileId(a2);
}


// address=[0x15f8660]
// Decompiled from int __thiscall CWalkingBase::GetNextWaypoint(CWalkingBase *this)
int  CWalkingBase::GetNextWaypoint(void) {
  
  int result; // eax

  switch ( *((_DWORD *)this + 2) )
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
      result = *((_DWORD *)this + 11);
      break;
    case 7:
      result = -1;
      break;
    case 8:
      result = -1;
      break;
    case 9:
      result = *((_DWORD *)this + 11);
      break;
    default:
      result = -1;
      break;
  }
  return result;
}


// address=[0x15faee0]
// Decompiled from CWalkingBase *__thiscall CWalkingBase::CWalkingBase(CWalkingBase *this, int a2, int a3)
 CWalkingBase::CWalkingBase(int,int) {
  
  CWalking::CWalking(this);
  *(_DWORD *)this = &CWalkingBase::_vftable_;
  memset((char *)this + 4, 0, 0xBCu);
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = 1;
  *((_DWORD *)this + 13) = a3;
  return this;
}


// address=[0x15fb220]
// Decompiled from char *__thiscall CWalkingBase::GetData(CWalkingBase *this)
struct CWalkingBase::SData &  CWalkingBase::GetData(void) {
  
  return (char *)this + 4;
}


// address=[0x15f86e0]
// Decompiled from char __thiscall CWalkingBase::FindPathAStar64(CWalkingBase *this, int a2, int a3, struct CDirCache *a4)
bool  CWalkingBase::FindPathAStar64(int,int,class CDirCache &) {
  
  return CAStar64::FindPath((CAStar64 *)&g_cAStar64Normal, a2, a3, a4);
}


// address=[0x15f8710]
// Decompiled from int __thiscall CWalkingBase::FindNearest(CWalkingBase *this, int a2, int a3, int a4)
int  CWalkingBase::FindNearest(int,int,int) {
  
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+14h] [ebp-64h]
  _BYTE v10[88]; // [esp+1Ch] [ebp-5Ch] BYREF

  v4 = CWorldManager::Index(a2);
  v8 = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v4);
  v5 = CWorldManager::Index(a3);
  if ( (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v5) == v8 || v8 == 0 )
    return a3;
  v6 = CWalkingBase::Flags(this);
  if ( CAStarTiling::FindPath(a2, a3, (struct CWaypoints *)v10, v6 | 0x40) )
    return CWaypoints::Goal((CWaypoints *)v10);
  else
    return a3;
}


// address=[0x15f87f0]
// Decompiled from int __thiscall CWalkingBase::GoalCheck(CWalkingBase *this, Y16X16 *a2)
void  CWalkingBase::GoalCheck(int) {
  
  int v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // eax
  int IsBlockedLand; // [esp+0h] [ebp-34h]
  int v7; // [esp+4h] [ebp-30h]
  int v8; // [esp+8h] [ebp-2Ch]
  int v9; // [esp+Ch] [ebp-28h]
  int v10; // [esp+10h] [ebp-24h]
  int v11; // [esp+14h] [ebp-20h]
  int v12; // [esp+1Ch] [ebp-18h]
  int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]

  v2 = CWorldManager::Index((int)a2);
  v14 = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v2);
  if ( v14 )
  {
    if ( (CWalkingBase::Flags(this) & 0x1000) != 0 )
    {
      result = Y16X16::DistanceFast(a2, *((_DWORD *)this + 4));
      if ( result > 1 )
      {
        if ( v14 == (*(int (__thiscall **)(CWalkingBase *, _DWORD))(*(_DWORD *)this + 28))(this, *((_DWORD *)this + 8)) )
        {
          result = (int)this;
          *((_DWORD *)this + 5) = *((_DWORD *)this + 4);
        }
        else
        {
          v4 = CWorldManager::Index(*((_DWORD *)this + 5));
          result = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v4);
          if ( v14 != result )
          {
            for ( i = 0; i < 6; ++i )
            {
              v5 = CWorldManager::NeighborRelIndex(i);
              if ( v14 == (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(
                            this,
                            *((_DWORD *)this + 8) + v5) )
              {
                result = *((_DWORD *)this + 4) + Y16X16::NeighborModifier((Y16X16 *)i);
                *((_DWORD *)this + 5) = result;
                break;
              }
              result = i + 1;
            }
            if ( i >= 6 )
              *((_DWORD *)this + 2) = 1;
          }
        }
      }
      else
      {
        *((_DWORD *)this + 2) = 3;
      }
    }
    else if ( a2 == *((Y16X16 **)this + 4) )
    {
      result = (int)this;
      *((_DWORD *)this + 2) = 3;
    }
    else
    {
      result = CWalkingBase::Flags(this) & 0x40;
      if ( !result )
      {
        result = (*(int (__thiscall **)(CWalkingBase *, _DWORD))(*(_DWORD *)this + 28))(this, *((_DWORD *)this + 8));
        if ( v14 != result )
          *((_DWORD *)this + 2) = 1;
      }
    }
  }
  else
  {
    v12 = Y16X16::UnpackXFast((int)a2);
    v13 = Y16X16::UnpackYFast((int)a2);
    v15 = CWorldManager::Index(v12, v13);
    IsBlockedLand = (unsigned __int8)CWorldManager::IsBlockedLand(v15);
    v7 = CWorldManager::OwnerId(v15);
    v8 = CWorldManager::SectorId(v15);
    v9 = CWorldManager::EcoSectorId(v15);
    v10 = CWorldManager::OccupyingEntityId(v15);
    v11 = (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v15);
    CTrace::Print(
      "### CWalkingBase::GoalCheck(): Current sector id is 0! (%i, %i), is blocked land %i, owner %i, sector %i, eco-sect"
      "or %i, entity %i, not blocked %i. ###",
      v12,
      v13,
      IsBlockedLand,
      v7,
      v8,
      v9,
      v10,
      v11);
    result = (int)this;
    *((_DWORD *)this + 2) = 1;
  }
  return result;
}


// address=[0x15f8a40]
// Decompiled from int __thiscall CWalkingBase::DbgPrintElementInfo(CWalkingBase *this, const char *a2, int a3)
void  CWalkingBase::DbgPrintElementInfo(char const *,int) {
  
  int v4; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  unsigned int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+Ch] [ebp-20h]
  int v8; // [esp+10h] [ebp-1Ch]
  int v9; // [esp+14h] [ebp-18h]
  int v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+20h] [ebp-Ch]
  int v14; // [esp+28h] [ebp-4h]

  v11 = (__int16)Y16X16::UnpackXFast(a3);
  v12 = (__int16)Y16X16::UnpackYFast(a3);
  if ( !(unsigned __int8)CWorldManager::InWorld(v11, v12) )
    return BBSupportTracePrintF(0, "%s( %4i, %4i ) - Not in world.", a2, v11, v12);
  v14 = CWorldManager::Index(v11, v12);
  v4 = (*(unsigned __int8 (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 20))(this, v14);
  v5 = (*(int (__thiscall **)(CWalkingBase *, int))(*(_DWORD *)this + 28))(this, v14);
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
// Decompiled from struct CWalkingBase *__thiscall CWalkingBase::AttachWalking(CWalkingBase *this, struct CWalkingBase *a2)
void  CWalkingBase::AttachWalking(class CWalkingBase *) {
  
  struct CWalkingBase *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 430, "_pWalking != 0") == 1 )
    __debugbreak();
  if ( a2 == this && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 431, "_pWalking != this") == 1 )
    __debugbreak();
  if ( *((_DWORD *)a2 + 45)
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 432, "_pWalking->m_sData.m_pPrevWalking == 0") == 1 )
  {
    __debugbreak();
  }
  result = (struct CWalkingBase *)*((_DWORD *)this + 47);
  if ( result == a2 )
    return result;
  (*(void (__thiscall **)(CWalkingBase *))(*(_DWORD *)this + 48))(this);
  *((_DWORD *)this + 45) = a2;
  *((_DWORD *)this + 46) = *((_DWORD *)a2 + 46);
  *((_DWORD *)this + 47) = a2;
  if ( *((_DWORD *)a2 + 46) )
    *(_DWORD *)(*((_DWORD *)a2 + 46) + 180) = this;
  *((_DWORD *)a2 + 46) = this;
  if ( *((int *)a2 + 4) >= 0 )
    *((_DWORD *)a2 + 2) = 8;
  result = (struct CWalkingBase *)(*(int (__thiscall **)(struct CWalkingBase *))(*(_DWORD *)a2 + 60))(a2);
  *((_DWORD *)this + 1) = result;
  return result;
}


// address=[0x15f8c90]
// Decompiled from _DWORD *__thiscall CWalkingBase::DetachWalking(CWalkingBase *this)
class CWalking *  CWalkingBase::DetachWalking(void) {
  
  int v2; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-8h]

  *((_DWORD *)this + 4) = *((_DWORD *)this + 6);
  if ( *((_DWORD *)this + 45) )
  {
    if ( *(CWalkingBase **)(*((_DWORD *)this + 45) + 184) != this
      && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 372, "m_sData.m_pPrevWalking->m_sData.m_pNextWalking == this") == 1 )
    {
      __debugbreak();
    }
    if ( *((_DWORD *)this + 46) )
    {
      if ( *(CWalkingBase **)(*((_DWORD *)this + 46) + 180) != this
        && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 376, "m_sData.m_pNextWalking->m_sData.m_pPrevWalking == this") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(*((_DWORD *)this + 45) + 184) = *((_DWORD *)this + 46);
      *(_DWORD *)(*((_DWORD *)this + 46) + 180) = *((_DWORD *)this + 45);
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)this + 45) + 184) = 0;
    }
    *((_DWORD *)this + 45) = 0;
    *((_DWORD *)this + 46) = 0;
    *((_DWORD *)this + 47) = 0;
    return 0;
  }
  else
  {
    v4 = (_DWORD *)*((_DWORD *)this + 46);
    *((_DWORD *)this + 45) = 0;
    *((_DWORD *)this + 46) = 0;
    *((_DWORD *)this + 47) = 0;
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
// Decompiled from int __thiscall CWalkingBase::GroupLeaderWalking(CWalkingBase *this, int a2, int a3)
void  CWalkingBase::GroupLeaderWalking(int,int) {
  
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // [esp-4h] [ebp-2Ch]
  int v8; // [esp+0h] [ebp-28h]
  int v10; // [esp+8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-1Ch]
  int v12; // [esp+10h] [ebp-18h]
  int v13; // [esp+14h] [ebp-14h]
  _DWORD *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-Ch]
  int v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h]

  v13 = Y16X16::UnpackXFast(a2);
  v12 = Y16X16::UnpackYFast(a2);
  result = CWorldManager::SectorId(v13, v12);
  v10 = result;
  if ( result )
  {
    v14 = (_DWORD *)*((_DWORD *)this + 46);
    v17 = 1;
    v8 = 0;
    v11 = 0;
    while ( v14 )
    {
      v15 = v13 + 2 * CSpiralOffsets::DeltaX(v17);
      v16 = v12 + 2 * CSpiralOffsets::DeltaY(v17);
      while ( 1 )
      {
        if ( (unsigned __int8)CWorldManager::InWorld(v15, v16) )
        {
          v4 = CWorldManager::Index(v15, v16);
          if ( CWorldManager::SectorId(v4) == v10 )
          {
            v5 = CWorldManager::Index(v15, v16);
            if ( !(unsigned __int8)CWorldManager::IsBlockedLand(v5) )
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
      result = (int)v14;
      v14 = (_DWORD *)v14[46];
    }
  }
  else
  {
    result = BBSupportDbgReport(1, "Pathing\\Walking.cpp", 642, "CWalkingBase::GroupLeaderWalking(): Invalid waypoint!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x15fb200]
// Decompiled from int __thiscall CWalkingBase::Flags(CPaneContainer *this)
int  CWalkingBase::Flags(void) {
  
  return *((_DWORD *)this + 12);
}


// address=[0x15fb2b0]
// Decompiled from char __thiscall CWalkingBase::IsNeighborTile(CWalkingBase *this, int a2, int a3)
bool  CWalkingBase::IsNeighborTile(int,int) {
  
  CLinkList *v4; // [esp+4h] [ebp-8h]
  struct CTile *v5; // [esp+8h] [ebp-4h]

  v5 = (struct CTile *)ITiling::Tile(a2);
  v4 = (CLinkList *)CTile::LinkList(v5);
  return CLinkList::SearchForLinkTileId(v4, a3);
}


// address=[0x15fb300]
// Decompiled from char __thiscall CWalkingBase::NextCoarseWaypoint(_DWORD *this, int a2)
bool  CWalkingBase::NextCoarseWaypoint(int) {
  
  int v3; // eax
  int v4; // [esp+0h] [ebp-24h]
  int v5; // [esp+4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]

  if ( CWaypoints::CachedWaypointsCount((pairNode *)(this + 18)) <= 0
    && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 734, "m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0") == 1 )
  {
    __debugbreak();
  }
  v5 = Y16X16::UnpackXFast(a2);
  v6 = Y16X16::UnpackYFast(a2);
  v10 = CWorldManager::Index(v5, v6);
  v11 = (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v10);
  v8 = (*(int (__thiscall **)(_DWORD *, int))(*this + 64))(this, v10);
  if ( v11 <= 0 && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 744, "iCurrentSectorId > 0") == 1 )
    __debugbreak();
  while ( 1 )
  {
    v9 = CWorldManager::Index(this[11]);
    v7 = (*(int (__thiscall **)(_DWORD *, int))(*this + 64))(this, v9);
    v4 = (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v9);
    if ( v4 != v11 )
      return 0;
    if ( v7 != v8 && !CWalkingBase::IsNeighborTile((CWalkingBase *)this, v7, v8) )
      return 1;
    this[11] = CWaypoints::Back(this + 18, v4);
    CWaypoints::PopBack(this + 18);
    if ( this[11] == this[5] )
      break;
    if ( CWaypoints::CachedWaypointsCount((pairNode *)(this + 18)) <= 0 )
      return 0;
  }
  v3 = CWorldManager::Index(this[11]);
  if ( (*(int (__thiscall **)(_DWORD *, int))(*this + 28))(this, v3) != v11
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


