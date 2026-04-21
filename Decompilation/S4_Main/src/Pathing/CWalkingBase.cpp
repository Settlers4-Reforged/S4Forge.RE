#include "CWalkingBase.h"

#include <iostream>

#include "CTile.h"
#include "CWaterFlags.h"
#include "CBB/CBBSupport.h"
#include "Defines/Walking.h"
#include "Logic/Events/IEventEngine.h"
#include "MapObjects/CMapObjectMgr.h"
#include "World/CWorldManager.h"
#include "World/helper.h"
#include "ITiling.h"
#include "Collections/CLinkList.h"
#include "Debug/CTrace.h"
#include "Logic/Events/CEvn_Event.h"
#include "MapObjects/SSurroundingPoint8.h"

// Definitions for class CWalkingBase

class IMovingEntity;
// address=[0x15f6660]
// Decompiled from CWalking *__thiscall CWalkingBase::~CWalkingBase(CWalkingBase *this)
CWalkingBase::~CWalkingBase(void) {
  CWalkingBase::DetachWalking();
}


// address=[0x15f66b0]
// Decompiled from void __thiscall CWalkingBase::Store(CWalkingBase *this, struct std::ostream *a2)
void CWalkingBase::Store(std::ostream &a2) {
  a2 << 929995208;
  a2 << 1;
  a2 << this->GetWalkingType();
  a2 << this->m_sData.m_uFlags;
  a2 << this->m_sData.m_iWalkState;
  a2 << this->m_sData.field_8;
  a2 << this->m_sData.m_iWalkToXY;
  a2 << this->m_sData.m_iWalkTo2XY;
  a2 << this->m_sData.m_iLeaderWalkToXY;
  a2 << this->m_sData.m_iIdleWalkToXY;
  a2 << this->m_sData.m_iWalkToIndex;
  a2 << this->m_sData.field_20;
  a2 << this->m_sData.m_iFineWaypointXY;
  a2 << this->m_sData.m_iCoarseWaypointXY;
  a2 << this->m_sData.m_iEntityFlags;
  a2 << this->m_sData.field_34;
  a2 << this->m_sData.field_38;
  a2 << this->m_sData.field_3C;
  a2 << this->m_sData.field_40;
  a2 << 0x66ED0BD9;
}


// address=[0x15f6860]
// Decompiled from void __thiscall CWalkingBase::Init(CWalkingBase *this, int a2, int _iFlags)
void CWalkingBase::Init(int a2, int _iFlags) {
  // [esp+14h] [ebp+Ch]

  BB_ASSERT((_iFlags & WALK_FLAG_STRICT_INTERNAL_USE_MASK) == 0)

  unsigned int _iFlagsa = _iFlags & 0xFFF43060;
  if(a2 < 0) {
    this->m_sData.m_iWalkToXY = -1;
    this->m_sData.m_iWalkToIndex = 0;
    this->m_sData.m_iWalkState = a2 != -1;
  } else {
    this->m_sData.m_iWalkToXY = a2;
    this->m_sData.m_iWalkToIndex = CWorldManager::Index(a2);
    this->m_sData.m_iWalkState = 8;
  }
  this->m_sData.field_40 = 0;
  this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
  this->m_sData.m_uFlags = this->m_sData.m_iEntityFlags | _iFlagsa;
  this->m_sData.field_20 = 0;
  if((_iFlagsa & 0x40000) == 0)
    this->m_sData.m_iLeaderWalkToXY = this->m_sData.m_iWalkToXY;
}


// address=[0x15f6950]
// Decompiled from void __thiscall CWalkingBase::Init(CWalkingBase *this, struct CWalkingBase *a2, int a3)
void CWalkingBase::Init(class CWalking *a2, int a3) {
  this->Init(-1, a3);
  CWalkingBase::AttachWalking(dynamic_cast<CWalkingBase *>(a2));
}


// address=[0x15f6980]
// Decompiled from void __thiscall CWalkingBase::InitIfLeader(CWalkingBase *this, int a2, int a3)
void CWalkingBase::InitIfLeader(int a2, int a3) {
  this->m_sData.m_iLeaderWalkToXY = a2;
  if(this->m_sData.m_pLatestWalking) {
    int iWalkState = this->m_sData.m_iWalkState;
    if(iWalkState > 0 && iWalkState <= 5)
      this->Init(-1, a3 | 0x40000);
  } else {
    this->Init(a2, a3);
  }
}


// address=[0x15f69f0]
// Decompiled from int __thiscall CWalkingBase::Walk(CWalkingBase *this, int a2)
int CWalkingBase::Walk(int _iCurrentXY) {
  struct type_info *pTypeId; // eax
  const char *      pTypeName; // eax
  int               v4; // eax
  int               v6; // eax
  int               v7; // eax
  int               v8; // eax
  int               v9; // eax
  int               v10; // eax
  __int16           v11; // ax
  int               v12; // eax
  int               v13; // eax
  struct type_info *v14; // eax
  const char *      v15; // eax
  struct type_info *v16; // eax
  const char *      v17; // eax

  int              v20; // [esp+18h] [ebp-120h]
  int              v21; // [esp+1Ch] [ebp-11Ch]
  int              v22; // [esp+34h] [ebp-104h]
  int              iMapObjectId; // [esp+44h] [ebp-F4h]
  int              v24; // [esp+48h] [ebp-F0h]
  int              v25; // [esp+4Ch] [ebp-ECh]
  int              v26; // [esp+50h] [ebp-E8h]
  int              m_iWalkToXY; // [esp+60h] [ebp-D8h]
  int              v28; // [esp+6Ch] [ebp-CCh]
  int              Path; // [esp+80h] [ebp-B8h]
  int              v30; // [esp+8Ch] [ebp-ACh]
  char             v31; // [esp+90h] [ebp-A8h]
  struct CWalking *v32; // [esp+98h] [ebp-A0h]
  bool             v33; // [esp+A0h] [ebp-98h]
  int              v34; // [esp+B8h] [ebp-80h]
  int              v35; // [esp+BCh] [ebp-7Ch]
  int              v36; // [esp+C0h] [ebp-78h]
  int              v37; // [esp+C4h] [ebp-74h]
  int              iDbgCurrentX; // [esp+C8h] [ebp-70h]
  int              iDbgCurrentY; // [esp+CCh] [ebp-6Ch]
  int              iIndex; // [esp+D0h] [ebp-68h]
  int              iFineWaypoint; // [esp+D4h] [ebp-64h]
  int              j; // [esp+D8h] [ebp-60h]
  int              v43; // [esp+DCh] [ebp-5Ch]
  IEntity *        pEntity; // [esp+E0h] [ebp-58h]
  CWalkingBase *   i; // [esp+E4h] [ebp-54h]
  char             v46; // [esp+EBh] [ebp-4Dh]
  int              iDir; // [esp+ECh] [ebp-4Ch]
  char             bFailedFindPathAlready; // [esp+F1h] [ebp-47h]
  char             v49; // [esp+F2h] [ebp-46h]
  char             v50; // [esp+F3h] [ebp-45h]

  int v54; // [esp+134h] [ebp-4h]

  iDbgCurrentX = Y16X16::UnpackXFast(_iCurrentXY);
  iDbgCurrentY = Y16X16::UnpackYFast(_iCurrentXY);
  BB_ASSERT(g_cWorld.InWorld(iDbgCurrentX, iDbgCurrentY))

  iIndex = CWorldManager::Index(iDbgCurrentX, iDbgCurrentY);
  iMapObjectId = CWorldManager::MapObjectId(iIndex);
  if(!this->IsNotBlocked(iIndex) || this->SectorId(iIndex) <= 0) {
    BBSupportTracePrintF(0, "Walk() [%s]: Invalid current position!", typeid(this).name());
    BBSupportTracePrintF(0, "  WalkState: %i.", this->m_sData.m_iWalkState);
    CWalkingBase::DbgPrintElementInfo("  Current:   ", _iCurrentXY);
    CWalkingBase::DbgPrintElementInfo("  WalkTo:    ", this->m_sData.m_iWalkToXY);
    CWalkingBase::DbgPrintElementInfo("  WalkTo2:   ", this->m_sData.m_iWalkTo2XY);
    BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", iDbgCurrentX, iDbgCurrentY, iMapObjectId);
    g_pMapObjectMgr->DbgPrintEntity(iMapObjectId, 0, 0);
    g_pTiling->DbgCheckTiling(0);
    CEvn_Event v18 = CEvn_Event(0xDu, 0x70u, 0, 0);
    g_pEvnEngine->SendAMessage(v18);
    BB_REPORT("Invalid walk position! Dietmar: I need the trace file. [Ignore --> Pause]")
  }
  if(this->m_sData.m_iLeaderWalkToXY != this->m_sData.m_iWalkToXY && this->m_sData.m_pLatestWalking == 0) {
    this->Init(this->m_sData.m_iLeaderWalkToXY, CWalkingBase::Flags() & 0xFFF43060);
  }
  if(this->m_sData.m_iWalkState > 5u) {
    this->m_sData.m_uFlags &= ~0x20000u;
    BB_ASSERT(g_cWorld.InWorldPackedXY(m_sData.m_iWalkToXY))
    CWalkingBase::GoalCheck(_iCurrentXY);
  }
  v49 = 0;
  bFailedFindPathAlready = 0;
  v50 = 0;
  v37 = 0;
  while(v37 < 32) {
    switch(this->m_sData.m_iWalkState) {
      case 0:
        return this->IdleWalk(_iCurrentXY, 0) | 0x10;
      case 1:
        this->m_sData.field_40 = 0;
        this->m_sData.m_iWalkState = 2;
        return 72;
      case 2:
        return this->IdleWalk(_iCurrentXY, 0) | 0x50;
      case 3:
        this->m_sData.field_40 = 0;
        if(this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0)
          CWalkingBase::GroupLeaderWalking(this->m_sData.m_iWalkTo2XY, 0);
        if((this->m_sData.m_uFlags & 0x40000) != 0) {
          this->m_sData.m_iWalkState = 0;
          return 24;
        } else {
          if((this->m_sData.m_uFlags & 0x4000) != 0)
            this->m_sData.m_iWalkState = 4;
          else
            this->m_sData.m_iWalkState = 5;
          return 40;
        }
      case 4:
        return 40;
      case 5:
        return this->IdleWalk(_iCurrentXY, 0) | 0x30;
      case 6:
        if(v50)
          goto LABEL_50;
        if((int) ++this->m_sData.field_20 <= 16) {
          if((int) this->m_sData.field_20 > 2) {
            v33 = Y16X16::DistanceFast(_iCurrentXY, this->m_sData.m_iWalkToXY) <= 3;
            if((CWalkingBase::Flags() & 0x2000) != 0 && v33)
              this->m_sData.m_iWalkState = 3;
            else
              this->m_sData.m_iWalkState = 9;
            goto LABEL_16;
          }
          if(Y16X16::DistanceFast(_iCurrentXY, this->m_sData.m_iFineWaypointXY) == 1) {
            v22 = CWorldManager::Index(this->m_sData.m_iFineWaypointXY);
            v36 = CWorldManager::OccupyingEntityId(v22);
            if(v36) {
              pEntity = CMapObjectMgr::EntityPtr(v36);
              if(pEntity) {
                BB_ASSERT(dynamic_cast<IMovingEntity*>(pEntity) != 0)
                CWalkingBase *v32 = (CWalkingBase *) (dynamic_cast<IMovingEntity *>(pEntity)->Walking());
                if(v32) {
                  if(v32->m_sData.m_iWalkState == 6 && v32->m_sData.m_iFineWaypointXY == _iCurrentXY) {
                    this->m_sData.m_iWalkState = 9;
                    goto LABEL_16;
                  }
                }
              }
            }
          }
          v50 = 1;
        LABEL_50:
          if(this->m_sData.m_iFineWaypointXY == _iCurrentXY) {
            this->m_sData.field_20 = 0;
            if(this->m_sData.m_cFineWaypoints.Count() <= 0) {
              this->m_sData.m_iWalkState = 9;
              goto LABEL_16;
            }
            iDir = this->m_sData.m_cFineWaypoints.Back();
            this->m_sData.m_iFineWaypointXY = _iCurrentXY + Y16X16::NeighborModifier(iDir);
            this->m_sData.m_cFineWaypoints.PopBack();
          } else {
            if(Y16X16::DistanceFast(_iCurrentXY, this->m_sData.m_iFineWaypointXY) != 1) {
              this->m_sData.m_iWalkState = 9;
              goto LABEL_16;
            }
            iDir = Y16X16::DirectionFast(_iCurrentXY, this->m_sData.m_iFineWaypointXY);
          }
          BB_ASSERT(iDir >= 0)
          BB_ASSERT(m_sData.m_iFineWaypointXY == _iCurrentXY + Y16X16::NeighborModifier(iDir))
          if(this->m_sData.m_iWalkingType == 4) {
            v6 = CWorldManager::Index(this->m_sData.m_iFineWaypointXY);
            if(this->IsNotBlocked(v6)) {
              v7 = CWorldManager::Index(this->m_sData.m_iFineWaypointXY);
              v31 = CWaterFlags::WaterFlags(v7);
              v43 = (v31 & 0xF0) >> 4;
              if(v43)
                this->m_sData.m_iWalkState = 9;
              if(v43 > 2) {
                v8 = Y16X16::NeighborModifier(iDir + 3);
                v9 = CWorldManager::Index(_iCurrentXY + v8);
                CWaterFlags::WaterFlags(v9);
                if((v31 & 0xF0) >> 4 < v43 + 2) {
                  if(Y16X16::DistanceFast(_iCurrentXY, this->m_sData.m_iWalkToXY) > 3) {
                    v30 = this->m_sData.field_34 + 1;
                    this->m_sData.field_34 = v30;
                    if(v30 >= 2 && v43 <= 7)
                      return iDir;
                    else
                      return 136;
                  } else {
                    this->m_sData.m_iWalkState = 3;
                    return 40;
                  }
                } else {
                  this->m_sData.field_34 = 0;
                  return iDir;
                }
              } else {
                this->m_sData.field_34 = 0;
                return iDir;
              }
            } else {
              BB_REPORT("Waypoint blocked --> WALK_NO_PATH")
              this->m_sData.m_iWalkState = 1;
              return 72;
            }
          } else {
            v10 = CWorldManager::Index(this->m_sData.m_iFineWaypointXY);
            if(this->IsNotBlocked(v10))
              return iDir;
            if(v49) {
              CTrace::Print(">>>>>> CWalking::Walk(): Waypoint blocked! <<<<<<");
              this->m_sData.m_iWalkState = 7;
            } else {
              v49 = 1;
              this->m_sData.m_iWalkState = 9;
            }
            goto LABEL_16;
          }
        } else {
          this->m_sData.field_20 = 0;
          this->m_sData.m_iWalkState = 7;
          return this->IdleWalk(_iCurrentXY, 0);
        }
      case 7:
        this->m_sData.m_iWalkState = 8;
        CWalkingBase::GoalCheck(_iCurrentXY);
        if(this->m_sData.m_iWalkState != 8)
          CTrace::Print(
            "### CWalkingBase::Walk(): STATE_EX_GOAL_CHECK has changed walk state! New state %i. ###",
            this->m_sData.m_iWalkState);
        goto LABEL_16;
      case 8:
        v11 = this->Flags();
        Path = CAStarTiling::FindPath(_iCurrentXY, this->m_sData.m_iWalkTo2XY, &this->m_sData.m_cCoarseWaypoints, v11);
        if(Path) {
          if(((Path < 0) & ((this->Flags() & 0x40) != 0)) != 0) {
            this->m_sData.m_iWalkToXY = this->m_sData.m_cCoarseWaypoints.Goal();
            this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
            this->m_sData.m_iWalkToIndex = CWorldManager::Index(this->m_sData.m_iWalkToXY);
          }
          BB_ASSERT(m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0)
          this->m_sData.m_iCoarseWaypointXY = this->m_sData.m_cCoarseWaypoints.Back();
          this->m_sData.m_cCoarseWaypoints.PopBack();
          BB_ASSERT((m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0) || (m_sData.m_iCoarseWaypointXY == m_sData.m_iWalkTo2XY))
          this->m_sData.m_iWalkState = 9;
        } else {
          this->m_sData.m_iWalkState = 1;
        }
        goto LABEL_16;
      case 9:
        if(!this->m_sData.field_40)
          goto LABEL_113;
        if(this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0) {
          if((int) this->m_sData.field_40 < 0 || Y16X16::DistanceFast(this->m_sData.field_40, _iCurrentXY) <= 2) {
            v35 = 0;
            v34 = 0;
            for(i = this->m_sData.m_pNextWalking; i; i = i->m_sData.m_pNextWalking) {
              if(i->State(0) >= 6)
                ++v34;
              ++v35;
            }
            if(v34 > v35 / 4) {
              this->m_sData.field_40 = -1;
              return this->IdleWalk(_iCurrentXY, 0) | 0x10;
            }
          }
        } else {
          this->m_sData.field_40 = 0;
        }
      LABEL_113:
        if(this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY)
          goto LABEL_119;
        v46 = this->m_sData.m_cCoarseWaypoints.GoalCached();
        v28 = this->m_sData.m_cCoarseWaypoints.CachedWaypointsCount();
        if(v28 && (v28 >= 2 || v46 != 0)) {
          if(this->NextCoarseWaypoint(_iCurrentXY)) {
          LABEL_119:
            if(this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY)
              m_iWalkToXY = this->m_sData.m_iWalkToXY;
            else
              m_iWalkToXY = this->m_sData.m_iCoarseWaypointXY;
            if(this->FindPathAStar64(
              _iCurrentXY,
              m_iWalkToXY,
              this->m_sData.m_cFineWaypoints)) {
              BB_ASSERT(this->m_sData.m_cFineWaypoints.Count() > 0)
              v12 = this->m_sData.m_cFineWaypoints.Back();
              this->m_sData.m_iFineWaypointXY = _iCurrentXY + Y16X16::NeighborModifier(v12);
              this->m_sData.m_cFineWaypoints.PopBack();
              if(this->m_sData.m_pPrevWalking == 0 && this->m_sData.m_pNextWalking != 0) {
                v21 = this->m_sData.m_cFineWaypoints.Count();
                iFineWaypoint = this->m_sData.m_iFineWaypointXY;
                for(j = 0; j < v21; ++j) {
                  iFineWaypoint += Y16X16::NeighborModifier(this->m_sData.m_cFineWaypoints[j]);
                }
                this->m_sData.field_40 = iFineWaypoint;
                this->GroupLeaderWalking(iFineWaypoint, 0x40000);
              }
              BB_ASSERT(Y16X16::DistanceFast(_iCurrentXY, m_sData.m_iFineWaypointXY) == 1)
              this->m_sData.m_iWalkState = 6;
            } else {
              v25 = Y16X16::UnpackXFast(_iCurrentXY);
              v26 = Y16X16::UnpackYFast(_iCurrentXY);
              v20 = CWorldManager::Index(v25, v26);
              v24 = CWorldManager::MapObjectId(v20);
              BBSupportTracePrintF(0, "Walk() [%s]: FindPathAStar64() failed!", typeid(this).name());
              this->DbgPrintElementInfo("  Current:  ", _iCurrentXY);
              this->DbgPrintElementInfo("  Waypoint: ", m_iWalkToXY);
              this->DbgPrintElementInfo("  WalkTo:   ", this->m_sData.m_iWalkToXY);
              this->DbgPrintElementInfo("  WalkTo2:  ", this->m_sData.m_iWalkTo2XY);
              BBSupportTracePrintF(0, "  Map object id @ (%i, %i) is %i.", v25, v26, v24);
              g_pMapObjectMgr->DbgPrintEntity(v24, 0, 0);
              g_pTiling->DbgCheckTiling(0);
              if(bFailedFindPathAlready) {
                CEvn_Event v19 = CEvn_Event(0xDu, 0x70u, 0, 0);
                g_pEvnEngine->SendAMessage(v19);

                BB_REPORT("FindPathAStar64 failed! Dietmar: I need the trace file. [Ignore --> Pause]")
                this->m_sData.m_iWalkState = 1;
              } else {
                BBSupportTracePrintF(0, "FindPathAStar64 failed once [may be ignored]");
                bFailedFindPathAlready = 1;
                this->m_sData.m_iWalkState = 7;
              }
            }
          } else {
            this->m_sData.m_iWalkState = 8;
          }
        } else {
          this->m_sData.m_iWalkState = 8;
        }
      LABEL_16:
        ++v37;
        break;
      default:
        if("Walk(): Invalid walk state!"
           && BBSupportDbgReport(2, "Pathing\\Walking.cpp", 1325, "!\"Walk(): Invalid walk state!\"") == 1) {
          __debugbreak();
        }
        this->m_sData.m_iWalkState = 1;
        goto LABEL_16;
    }
  }
  BBSupportTracePrintF(3, "### Walk() [%s]: LoopCount >= 32! ###", typeid(this).name());
  this->m_sData.m_iWalkState = 7;
  return 8;
}


// address=[0x15f7bc0]
// Decompiled from int __thiscall CWalkingBase::IdleWalk(CWalkingBase *this, int a2, int a3)
int CWalkingBase::IdleWalk(int a2, int a3) {
  // eax
  // [esp+0h] [ebp-D4h]
  // [esp+4h] [ebp-D0h]
  __int64 v7; // [esp+10h] [ebp-C4h]
  // [esp+18h] [ebp-BCh]
  // [esp+1Ch] [ebp-B8h]
  // [esp+20h] [ebp-B4h]
  // [esp+24h] [ebp-B0h]
  // [esp+28h] [ebp-ACh]
  // [esp+2Ch] [ebp-A8h]
  // [esp+30h] [ebp-A4h]
  // [esp+34h] [ebp-A0h]
  // [esp+38h] [ebp-9Ch]
  // [esp+3Ch] [ebp-98h]
  // [esp+40h] [ebp-94h]
  // [esp+44h] [ebp-90h]
  // [esp+48h] [ebp-8Ch]
  // [esp+4Ch] [ebp-88h]
  // [esp+50h] [ebp-84h]
  // [esp+54h] [ebp-80h]
  // [esp+58h] [ebp-7Ch]
  // [esp+5Ch] [ebp-78h]
  // [esp+60h] [ebp-74h]
  // [esp+64h] [ebp-70h]
  // [esp+68h] [ebp-6Ch]
  // [esp+6Ch] [ebp-68h]
  // [esp+70h] [ebp-64h]
  // [esp+78h] [ebp-5Ch]
  // [esp+78h] [ebp-5Ch]
  // [esp+78h] [ebp-5Ch]
  // [esp+78h] [ebp-5Ch]
  // [esp+78h] [ebp-5Ch]
  // [esp+78h] [ebp-5Ch]
  // [esp+7Ch] [ebp-58h]
  _DWORD v39[13]; // [esp+80h] [ebp-54h]
  _DWORD v40[7]; // [esp+B4h] [ebp-20h]

  int v21 = 0;
  int v20 = 0;
  int v18 = 0;
  int v25 = 0;
  int v15 = CWorldManager::Index(a2);
  for(int i = 0; i < 6; ++i) {
    int v19 = v15 + CWorldManager::NeighborRelIndex(i);
    if(this->IsNotBlocked(v19)) {
      if(this->IsNotOccupied(v19)) {
        if(CWorldManager::MoveCostsBits(v19) >= 7) {
          v40[i] = 1;
        } else {
          v40[i] = 4;
          ++v20;
        }
        ++v21;
      } else {
        v40[i] = 0;
        ++v25;
      }
    } else {
      v40[i] = 0;
      ++v18;
    }
  }
  v40[6] = v40[0];
  if(v25 && (v18 || v25 > 2) || CWorldManager::MoveCostsBits(v15) != 7) {
    this->m_sData.m_iIdleWalkToXY = -1;
    if((CWalkingBase::Flags() & 0x20000) != 0
       && v40[Grid::TurnLeft(this->m_sData.field_8)] == 2
       && v40[this->m_sData.field_8] == 2
       && v40[this->m_sData.field_8 + 1] == 2) {
      this->m_sData.m_uFlags &= ~0x20000u;
      return this->m_sData.field_8;
    } else {
      if(v21 >= 1) {
        if(v25 >= 1 && (a3 & 0x10000000) != 0) {
          for(int j = 7; j < 19; ++j) {
            unsigned int v23 = v15 + CWorldManager::SurroundingHexPointRelIndex(j);
            int          v22 = j - 6;
            if(CWorldManager::InWorld(v23) && this->IsNotBlocked(v23)) {
              if(this->IsNotOccupied(v23)) {
                if(CWorldManager::MoveCostsBits(v23) >= 7)
                  v39[v22 - 1] = 1;
                else
                  v39[v22 - 1] = 2;
              } else {
                v39[v22 - 1] = 0;
              }
            } else {
              v39[v22 - 1] = 0;
            }
          }
          int v38 = v39[11];
          v39[12] = v39[0];
          if(v20 >= 3 && v20 < v21) {
            for(int k = 0; k <= 6; ++k) {
              if(v40[k] == 1)
                v40[k] = 0;
            }
          }
          int v24 = v40[5];
          for(int m = 0; m < 6; ++m) {
            int v14 = v40[m];
            v40[m] = v14 * (v39[2 * m + 1] + v39[2 * m] + v39[2 * m - 1] + v40[m + 1] + v24 + 2 * v14);
            v24 = v14;
          }
          signed int v29 = 0;
          for(int n = 0; n < 6; ++n) {
            if((int) v40[n] > 0) {
              v29 += v40[n];
              v40[n] = v29;
            }
          }
          if(v29 > 0)
            v29 = g_pGame->Rand() % v29;
          for(int ii = 0; ii < 6; ++ii) {
            if(v29 < v40[ii]) {
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
  } else {
    int v3 = CWorldManager::Index(a2);
    int v9 = this->SectorId(v3);
    if((this->m_sData.m_uFlags & 0x20000) == 0)
      this->m_sData.m_iIdleWalkToXY = -1;
    this->m_sData.m_uFlags &= ~0x20000u;
    if(CWorldManager::InWorldPackedXY(this->m_sData.m_iIdleWalkToXY)) {
      int v11 = CWorldManager::Index(this->m_sData.m_iIdleWalkToXY);
      int v10 = this->SectorId(v11);
      if(CWorldManager::MoveCostsBits(v11) == 7 || v10 <= 0 || v9 != v10)
        this->m_sData.m_iIdleWalkToXY = -1;
    } else {
      this->m_sData.m_iIdleWalkToXY = -1;
    }
    if(this->m_sData.m_iIdleWalkToXY < 0) {
      int v6 = Y16X16::UnpackXFast(a2);
      int v5 = Y16X16::UnpackYFast(a2);
      int v16 = -1;
      int v8 = -1;
      for(int jj = 0; jj < SurroundingHexPointsCount(15); ++jj) {
        unsigned int v12 = v6 + g_sSurroundingHexPoints8[jj].X();
        unsigned int v17 = v5 + g_sSurroundingHexPoints8[jj].Y();
        if(CWorldManager::InWorld(v12, v17)) {
          int v13 = CWorldManager::Index(v12, v17);
          if(this->SectorId(v13) == v9
             && this->IsNotOccupied(v13)
             && CWorldManager::MoveCostsBits(v13) < 7) {
            v16 = v12;
            v8 = v17;
            break;
          }
        }
      }
      if(v16 < 0)
        return 8;
      this->m_sData.m_iIdleWalkToXY = Y16X16::PackXYFast(v16, v8);
    }
    int v30 = Y16X16::DirectionFast(a2, this->m_sData.m_iIdleWalkToXY);
    int v27 = v40[Grid::TurnLeft(v30)];
    int v26 = v40[Grid::TurnLeft(v30)];
    if(v40[v30] < v27 || v40[v30] < v26) {
      if(v27 == v26)
        g_pGame->Rand();
      v30 = Grid::TurnLeft(v30);
    }
    if((int) v40[v30] <= 0)
      v30 = 8;
    if(v30 == 8)
      this->m_sData.m_iIdleWalkToXY = -1;
    return v30;
  }
}


// address=[0x15f8420]
// Decompiled from int __thiscall CWalkingBase::DestinationXY(CWalkingBase *this)
int CWalkingBase::DestinationXY(void) const {
  return this->m_sData.m_iWalkToXY;
}


// address=[0x15f8440]
// Decompiled from int __thiscall CWalkingBase::State(CWalkingBase *this, int a2)
int CWalkingBase::State(int a2) const {
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  // [esp+Ch] [ebp-Ch]
  // [esp+10h] [ebp-8h]

  switch(this->m_sData.m_iWalkState) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      result = this->m_sData.m_iWalkState + 1;
      break;
    case 6:
      if(this->m_sData.m_iWalkTo2XY == this->m_sData.m_iCoarseWaypointXY) {
        int v6 = Y16X16::DistanceFast(this->m_sData.m_iWalkToXY, this->m_sData.m_iFineWaypointXY);
        if(v6 <= 14)
          v4 = v6 + 1;
        else
          v4 = 15;
        result = 16 * v4;
      } else {
        int v5 = Y16X16::DistanceFast(this->m_sData.m_iWalkToXY, this->m_sData.m_iCoarseWaypointXY);
        if(v5 <= 14)
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
      BB_REPORT("CWalkingBase::State(): Invalid walk mode!")
      result = 0;
      break;
  }
  return result;
}


// address=[0x15f8580]
// Decompiled from int __thiscall CWalkingBase::OwnerId(CWalkingBase *this)
int CWalkingBase::OwnerId(void) const {
  return this->m_sData.m_iEntityFlags & 0xF;
}


// address=[0x15f85a0]
// Decompiled from bool __thiscall CWalkingBase::IsNotBlocked(CWalkingBase *this, int a2)
bool CWalkingBase::IsNotBlocked(int a2) {
  return !CWorldManager::IsBlockedLand(a2);
}


// address=[0x15f85e0]
// Decompiled from bool __thiscall CWalkingBase::IsNotOccupied(CWalkingBase *this, int a2)
bool CWalkingBase::IsNotOccupied(int a2) {
  return CWorldManager::OccupyingEntityId(a2) == 0;
}


// address=[0x15f8620]
// Decompiled from int __thiscall CWalkingBase::SectorId(CWalkingBase *this, int a2)
int CWalkingBase::SectorId(int a2) {
  return ITiling::SectorId(a2);
}


// address=[0x15f8640]
// Decompiled from int __thiscall CWalkingBase::TileId(CWalkingBase *this, int a2)
int CWalkingBase::TileId(int a2) {
  return ITiling::NormalTileId(a2);
}


// address=[0x15f8660]
// Decompiled from int __thiscall CWalkingBase::GetNextWaypoint(CWalkingBase *this)
int CWalkingBase::GetNextWaypoint(void) {
  int result; // eax

  switch(this->m_sData.m_iWalkState) {
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
CWalkingBase::CWalkingBase(int a2, int a3) : CWalking(), m_sData() {
  memset(&this->m_sData, 0, sizeof(this->m_sData));
  this->m_sData.m_iWalkingType = a2;
  this->m_sData.m_iWalkState = 1;
  this->m_sData.m_iEntityFlags = a3;
}


// address=[0x15fb220]
// Decompiled from CWalkingBase::SData *__thiscall CWalkingBase::GetData(CWalkingBase *this)
struct CWalkingBase::SData &CWalkingBase::GetData(void) {
  return this->m_sData;
}


// address=[0x15f86e0]
// Decompiled from char __thiscall CWalkingBase::FindPathAStar64(CWalkingBase *this, int a2, int a3, struct CDirCache *a4)
bool CWalkingBase::FindPathAStar64(int a2, int a3, class CDirCache &a4) {
  return g_cAStar64Normal->FindPath(a2, a3, a4);
}


// address=[0x15f8710]
// Decompiled from int __thiscall CWalkingBase::FindNearest(CWalkingBase *this, int a2, int a3, int a4)
int CWalkingBase::FindNearest(int a2, int a3, int a4) {
  // eax
  // eax
  // ax
  // [esp+14h] [ebp-64h]
  struct CWaypoints cWaypoints; // [esp+1Ch] [ebp-5Ch] BYREF

  int v4 = CWorldManager::Index(a2);
  int v8 = this->SectorId(v4);
  int v5 = CWorldManager::Index(a3);
  if(this->SectorId(v5) == v8 || v8 == 0)
    return a3;
  __int16 v6 = CWalkingBase::Flags();
  if(CAStarTiling::FindPath(a2, a3, &cWaypoints, v6 | 0x40))
    return cWaypoints.Goal();
  else
    return a3;
}


// address=[0x15f87f0]
// Decompiled from void __thiscall CWalkingBase::GoalCheck(CWalkingBase *this, int a2)
void CWalkingBase::GoalCheck(int a2) {
  // eax
  // eax
  // eax
  // [esp-4h] [ebp-38h]
  // [esp+0h] [ebp-34h]
  // [esp+4h] [ebp-30h]
  // [esp+8h] [ebp-2Ch]
  // [esp+Ch] [ebp-28h]
  // [esp+10h] [ebp-24h]
  // [esp+1Ch] [ebp-18h]
  // [esp+20h] [ebp-14h]
  // [esp+24h] [ebp-10h]
  // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]

  int v2 = CWorldManager::Index(a2);
  int v13 = this->SectorId(v2);
  if(v13) {
    if((CWalkingBase::Flags() & 0x1000) != 0) {
      if(Y16X16::DistanceFast(a2, this->m_sData.m_iWalkToXY) > 1) {
        if(v13 == this->SectorId(this->m_sData.m_iWalkToIndex)) {
          this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY;
        } else {
          int v3 = CWorldManager::Index(this->m_sData.m_iWalkTo2XY);
          if(v13 != this->SectorId(v3)) {
            for(i = 0; i < 6; ++i) {
              int v4 = CWorldManager::NeighborRelIndex(i);
              if(v13 == this->SectorId(this->m_sData.m_iWalkToIndex + v4)) {
                this->m_sData.m_iWalkTo2XY = this->m_sData.m_iWalkToXY + Y16X16::NeighborModifier(i);
                break;
              }
            }
            if(i >= 6)
              this->m_sData.m_iWalkState = 1;
          }
        }
      } else {
        this->m_sData.m_iWalkState = 3;
      }
    } else if(a2 == this->m_sData.m_iWalkToXY) {
      this->m_sData.m_iWalkState = 3;
    } else if((CWalkingBase::Flags() & 0x40) == 0 && v13 != this->SectorId(this->m_sData.m_iWalkToIndex)) {
      this->m_sData.m_iWalkState = 1;
    }
  } else {
    int  v11 = Y16X16::UnpackXFast(a2);
    int  v12 = Y16X16::UnpackYFast(a2);
    int  v14 = CWorldManager::Index(v11, v12);
    BOOL IsBlockedLand = CWorldManager::IsBlockedLand(v14);
    int  v7 = CWorldManager::OwnerId(v14);
    int  v8 = CWorldManager::SectorId(v14);
    int  v9 = CWorldManager::EcoSectorId(v14);
    int  v10 = CWorldManager::OccupyingEntityId(v14);
    int  v5 = this->IsNotBlocked(v14);
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
void CWalkingBase::DbgPrintElementInfo(char const *a2, int a3) {
  // [esp+0h] [ebp-2Ch]
  // [esp+4h] [ebp-28h]
  // [esp+8h] [ebp-24h]
  // [esp+Ch] [ebp-20h]
  // [esp+10h] [ebp-1Ch]
  // [esp+14h] [ebp-18h]
  // [esp+18h] [ebp-14h]
  // [esp+1Ch] [ebp-10h]
  // [esp+20h] [ebp-Ch]
  // [esp+28h] [ebp-4h]

  unsigned int v11 = (__int16) Y16X16::UnpackXFast(a3);
  unsigned int v12 = (__int16) Y16X16::UnpackYFast(a3);
  if(!CWorldManager::InWorld(v11, v12))
    return BBSupportTracePrintF(0, "%s( %4i, %4i ) - Not in world.", a2, v11, v12);
  int v14 = CWorldManager::Index(v11, v12);
  int v4 = this->IsNotBlocked(v14);
  int v5 = this->SectorId(v14);
  int v6 = CWorldManager::Flags(v14);
  int v7 = ITiling::OwnerId(v14);
  int v8 = ITiling::SectorId(v14);
  int v9 = ITiling::CatapultSectorId(v14);
  int v10 = ITiling::EcoSectorId(v14);
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
void CWalkingBase::AttachWalking(class CWalkingBase *_pWalking) {
  BB_ASSERT(_pWalking != 0)
  BB_ASSERT(_pWalking != this)
  BB_ASSERT(_pWalking->m_sData.m_pPrevWalking == 0)
  if(this->m_sData.m_pLatestWalking != _pWalking) {
    this->DetachWalking();
    this->m_sData.m_pPrevWalking = _pWalking;
    this->m_sData.m_pNextWalking = _pWalking->m_sData.m_pNextWalking;
    this->m_sData.m_pLatestWalking = _pWalking;
    if(_pWalking->m_sData.m_pNextWalking)
      _pWalking->m_sData.m_pNextWalking->m_sData.m_pPrevWalking = this;
    _pWalking->m_sData.m_pNextWalking = this;
    if(_pWalking->m_sData.m_iWalkToXY >= 0)
      _pWalking->m_sData.m_iWalkState = 8;
    this->m_sData.m_iWalkingType = _pWalking->GetWalkingType();
  }
}


// address=[0x15f8c90]
// Decompiled from _DWORD *__thiscall CWalkingBase::DetachWalking(CWalkingBase *this)
class CWalking *CWalkingBase::DetachWalking(void) {
  CWalkingBase *pNextWalking; // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]
  // [esp+8h] [ebp-8h]

  this->m_sData.m_iWalkToXY = this->m_sData.m_iLeaderWalkToXY;
  if(this->m_sData.m_pPrevWalking) {
    BB_ASSERT(m_sData.m_pPrevWalking->m_sData.m_pNextWalking == this)
    if(this->m_sData.m_pNextWalking) {
      BB_ASSERT(m_sData.m_pNextWalking->m_sData.m_pPrevWalking == this)
      this->m_sData.m_pPrevWalking->m_sData.m_pNextWalking = this->m_sData.m_pNextWalking;
      this->m_sData.m_pNextWalking->m_sData.m_pPrevWalking = this->m_sData.m_pPrevWalking;
    } else {
      this->m_sData.m_pPrevWalking->m_sData.m_pNextWalking = 0;
    }
    this->m_sData.m_pPrevWalking = 0;
    this->m_sData.m_pNextWalking = 0;
    this->m_sData.m_pLatestWalking = 0;
    return 0;
  } else {
    CWalkingBase *m_pNextWalking = this->m_sData.m_pNextWalking;
    this->m_sData.m_pPrevWalking = 0;
    this->m_sData.m_pNextWalking = 0;
    this->m_sData.m_pLatestWalking = 0;
    if(!m_pNextWalking)
      return m_pNextWalking;
    m_pNextWalking->m_sData.m_pPrevWalking = 0;
    m_pNextWalking->m_sData.m_pLatestWalking = 0;
    for(CWalkingBase *pWalking = m_pNextWalking->m_sData.m_pNextWalking; pWalking; pWalking = pNextWalking) {
      pNextWalking = pWalking->m_sData.m_pNextWalking;
      BB_ASSERT((pNextWalking == 0) || (pNextWalking->m_sData.m_pPrevWalking == pWalking))
      pWalking->m_sData.m_pLatestWalking = m_pNextWalking;
    }
    return m_pNextWalking;
  }
}


// address=[0x15f8e70]
// Decompiled from _DWORD *__thiscall CWalkingBase::GroupLeaderWalking(CWalkingBase *this, int a2, int a3)
void CWalkingBase::GroupLeaderWalking(int a2, int a3) {
  int iX = Y16X16::UnpackXFast(a2);
  int iY = Y16X16::UnpackYFast(a2);
  int iSectorIdx = CWorldManager::SectorId(iX, iY);
  if(iSectorIdx) {
    CWalkingBase *m_pNextWalking = this->m_sData.m_pNextWalking;
    int           v16 = 1;
    int           v7 = 0;
    int           v10 = 0;
    while(m_pNextWalking) {
      unsigned int v14 = iX + 2 * CSpiralOffsets::DeltaX(v16);
      unsigned int v15 = iY + 2 * CSpiralOffsets::DeltaY(v16);
      while(1) {
        if(CWorldManager::InWorld(v14, v15)) {
          int v3 = CWorldManager::Index(v14, v15);
          if(CWorldManager::SectorId(v3) == iSectorIdx) {
            int v4 = CWorldManager::Index(v14, v15);
            if(!CWorldManager::IsBlockedLand(v4))
              break;
          }
        }
        if(++v16 > 4000)
          v16 = 1;
        v14 = iX + 2 * CSpiralOffsets::DeltaX(v16);
        v15 = iY + 2 * CSpiralOffsets::DeltaY(v16);
        if(++v10 > 200000 && BBSupportDbgReport(1, "Pathing\\Walking.cpp", 629, "Endless loop detected!") == 1)
          __debugbreak();
      }
      unsigned int v6 = (a3 | CWalkingBase::Flags()) & 0xFFF43060;
      int          v5 = Y16X16::PackXYFast(v14, v15);
      m_pNextWalking->Init(v5, v6);
      if(++v16 > 4000)
        v16 = 1;
      ++v7;
      m_pNextWalking = m_pNextWalking->m_sData.m_pNextWalking;
    }
  } else {
    BB_REPORT("CWalkingBase::GroupLeaderWalking(): Invalid waypoint!")
  }
}


// address=[0x15fb200]
// Decompiled from int __thiscall CWalkingBase::Flags(CWalkingBase *this)
int CWalkingBase::Flags(void) {
  return this->m_sData.m_uFlags;
}


// address=[0x15fb2b0]
// Decompiled from char __thiscall CWalkingBase::IsNeighborTile(CWalkingBase *this, int a2, int a3)
bool CWalkingBase::IsNeighborTile(int _iTileA, int _iTileB) {
  CTile const &    v5 = ITiling::Tile(_iTileA);
  CLinkList const &v4 = v5.LinkList();
  return v4.SearchForLinkTileId(_iTileB);
}


// address=[0x15fb300]
// Decompiled from char __thiscall CWalkingBase::NextCoarseWaypoint(CWalkingBase *this, int a2)
bool CWalkingBase::NextCoarseWaypoint(int _iXY) {
  // eax
  // [esp+4h] [ebp-20h]
  // [esp+8h] [ebp-1Ch]
  // [esp+Ch] [ebp-18h]
  // [esp+10h] [ebp-14h]
  // [esp+14h] [ebp-10h]
  // [esp+18h] [ebp-Ch]
  // [esp+1Ch] [ebp-8h]

  BB_ASSERT(m_sData.m_cCoarseWaypoints.CachedWaypointsCount() > 0)

  int iX = Y16X16::UnpackXFast(_iXY);
  int iY = Y16X16::UnpackYFast(_iXY);
  int iIdx = CWorldManager::Index(iX, iY);
  int iCurrentSectorId = this->SectorId(iIdx);
  int iTargetTileId = this->TileId(iIdx);
  BB_ASSERT(iCurrentSectorId > 0)

  while(1) {
    int iWaypointIdx = CWorldManager::Index(this->m_sData.m_iCoarseWaypointXY);
    int iWaypointTileId = this->TileId(iWaypointIdx);
    if(this->SectorId(iWaypointIdx) != iCurrentSectorId)
      return 0;
    if(iWaypointTileId != iTargetTileId && !CWalkingBase::IsNeighborTile(iWaypointTileId, iTargetTileId))
      return 1;
    this->m_sData.m_iCoarseWaypointXY = this->m_sData.m_cCoarseWaypoints.Back();
    this->m_sData.m_cCoarseWaypoints.PopBack();
    if(this->m_sData.m_iCoarseWaypointXY == this->m_sData.m_iWalkTo2XY)
      break;
    if(this->m_sData.m_cCoarseWaypoints.CachedWaypointsCount() <= 0)
      return 0;
  }

  BB_ASSERT(SectorId(g_cWorld.Index(m_sData.m_iCoarseWaypointXY)) == iCurrentSectorId)
  return 1;
}


