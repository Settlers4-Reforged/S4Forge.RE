#include "CAITaskForceEx.h"

#include "../LoadSave/IS4Chunk.h"
#include "AI/IAIEnvironment.h"
#include "Pathing/CAStarTiling.h"
#include "Pathing/CWaypoints.h"

#include "CAIEntityInfo.h"
#include "CBB/CBBSupport.h"
#include "MapObjects/IEntity.h"

// Definitions for class CAITaskForceEx

// address=[0x132a540]
// Decompiled from void __thiscall CAITaskForceEx::ClearWaypoints(CAITaskForceEx *this)
void CAITaskForceEx::ClearWaypoints(void) {
    this->m_iWaypointsXY[0] = -1;
    this->m_iWaypointsXY[1] = -1;
    this->m_iWaypointsXY[2] = -1;
}

// address=[0x132a590]
// Decompiled from void __thiscall CAITaskForceEx::PopWaypoint(CAITaskForceEx *this)
void CAITaskForceEx::PopWaypoint(void) {
    this->m_iWaypointsXY[0] = this->m_iWaypointsXY[1];
    this->m_iWaypointsXY[1] = this->m_iWaypointsXY[2];
    this->m_iWaypointsXY[2] = -1;
}

// address=[0x132a600]
// Decompiled from bool __thiscall CAITaskForceEx::CheckWaypoint(CAITaskForceEx *this)
bool CAITaskForceEx::CheckWaypoint(void) {
    // [esp+4h] [ebp-20h]
    // [esp+8h] [ebp-1Ch]
    // [esp+Ch] [ebp-18h]
    // [esp+10h] [ebp-14h] BYREF
    // [esp+14h] [ebp-10h] BYREF
    // [esp+1Ch] [ebp-8h]

    int uWaypoint = this->WaypointXY();
    if(uWaypoint <= 0)
        return 0;
    int iX = IAIEnvironment::UnpackXFast(uWaypoint);
    int iY = IAIEnvironment::UnpackYFast(uWaypoint);
    int iSectorId = IAIEnvironment::WorldSectorId(iX, iY);
    if(iSectorId <= 0)
        return 0;
    int a1 = 0;
    int a2 = 0;
    return this->GetPositionOfFirstEntity(a1, a2) && iSectorId == IAIEnvironment::WorldSectorId(a1, a2);
}

// address=[0x132a6c0]
// Decompiled from char __thiscall CAITaskForceEx::CheckDestination(CAITaskForceEx *this)
bool CAITaskForceEx::CheckDestination(void) {
    int v1;      // eax
    int iDestXY; // eax MAPDST
    int v4;      // eax
    int v6;      // eax
    // [esp+0h] [ebp-1Ch] BYREF
    // [esp+4h] [ebp-18h] BYREF
    BOOL v9;  // [esp+8h] [ebp-14h]
    BOOL v10; // [esp+Ch] [ebp-10h]
    // [esp+10h] [ebp-Ch]

    if((this->Flags() & 0x2000) == 0)
        return 1;
    if(this->m_iDestinationXY < 0)
        this->m_iDestinationXY = this->CmdGoal();
    if(this->m_iDestinationXY < 0)
        return 0;
    if(!IAIEnvironment::WorldInWorldPackedXY(this->m_iDestinationXY) && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 501, "g_pAIEnv->WorldInWorldPackedXY(m_iDestinationXY)") == 1) {
        __debugbreak();
    }
    if(!IAIEnvironment::WorldIsBlockedLandPackedXY(this->m_iDestinationXY))
        return 1;
    if(!IAIEnvironment::WorldInWorldPackedXY(this->CmdGoal()) && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 507, "g_pAIEnv->WorldInWorldPackedXY(CmdGoal())") == 1) {
        __debugbreak();
    }
    int iDestX = IAIEnvironment::UnpackXFast(this->CmdGoal());
    int iDestY = IAIEnvironment::UnpackYFast(this->CmdGoal());
    int iDistanceToUnblockedXY = IAIEnvironment::GetNearestNoneBlockedPosition(iDestX, iDestY);
    if(iDistanceToUnblockedXY >= 0 && iDistanceToUnblockedXY < 16) {
        this->m_iDestinationXY = IAIEnvironment::PackXYFast(iDestX, iDestY);
        return 1;
    } else {
        this->m_iDestinationXY = this->CmdGoal();
        return 0;
    }
}

// address=[0x132a840]
// Decompiled from char __thiscall CAITaskForceEx::FindWaypoints(CAITaskForceEx *this)
bool CAITaskForceEx::FindWaypoints(void) {
    // eax
    // eax
    // [esp-4h] [ebp-80h]
    // [esp+0h] [ebp-7Ch]
    // [esp+4h] [ebp-78h]
    // [esp+14h] [ebp-68h]
    // [esp+18h] [ebp-64h]

    this->ClearWaypoints();
    if(!this->CheckDestination())
        return 0;
    CAIEntityInfo *Entity = this->FirstEntity();
    if(!Entity)
        return 0;
    int v2 = Entity->EntityId();
    int iXY = IAIEnvironment::EntityPackedPosition(v2);
    __int16 iOwner = this->OwnerId() | 0x80;
    int iDestXY = this->DestinationXY();
    CWaypoints cWaypoints{}; // [esp+20h] [ebp-5Ch] BYREF
    if(!CAStarTiling::FindPath(iXY, iDestXY, cWaypoints, iOwner))
        return 0;
    for(int i = 0; ((i < 3) & (cWaypoints.CachedWaypointsCount() > 0)) != 0; ++i) {
        this->m_iWaypointsXY[i] = cWaypoints.Back();
        cWaypoints.PopBack();
    }
    if(this->m_iWaypointsXY[0] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 590, "m_iWaypointsXY[0] >= 0") == 1) {
        __debugbreak();
    }
    return 1;
}

// address=[0x132a990]
// Decompiled from char __thiscall CAITaskForceEx::SetDestinationXY(CAITaskForceEx *this, int a2)
bool CAITaskForceEx::SetDestinationXY(int a2) {
    this->m_iDestinationXY = a2;
    this->ClearWaypoints();
    return 1;
}

// address=[0x132a9b0]
// Decompiled from void __thiscall CAITaskForceEx::Execute(CAITaskForceEx *this)
void CAITaskForceEx::Execute(void) {
    DWORD v1;               // esi
    int v2;                 // eax
    int v3;                 // eax
    int v4;                 // [esp+Ch] [ebp-28h]
    int iNumEntitiesHalved; // [esp+14h] [ebp-20h]
    int v6;                 // [esp+18h] [ebp-1Ch]
    int v7;                 // [esp+20h] [ebp-14h]
    CAIEntityInfo *pEntity; // [esp+28h] [ebp-Ch]
    bool Waypoints;         // [esp+33h] [ebp-1h]

    this->SetWaitCounter(8u);
    switch(this->State()) {
    case 0:
        this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_1);
        return;
    case 100:
        goto LABEL_2;
    case 101:
        if((this->Flags() & 0x10000) != 0) {
            iNumEntitiesHalved = this->NumberOfEntities() / 2;
            v6 = 128;
        } else {
            iNumEntitiesHalved = 0;
            v6 = 3;
        }
        v7 = 0;
        pEntity = this->FirstEntity();
        break;
    case 102:
        this->FindWaypoints();
        this->InitGroupWalk();
        this->SetWaitCounter(0x20u);
        this->SetState(101);
        this->ClearStateFlagBit(0x10000u);
        return;
    case 104:
        if(!this->GoalIsEntity() && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 860, "GoalIsEntity()") == 1) {
            __debugbreak();
        }
        if((IAIEnvironment::EntityFlags(this->CmdGoal()) & ENTITY_FLAG_READY) == 0)
            goto LABEL_34;

        for(CAIEntityInfo *i = this->FirstEntity(); i; i = i->Next())
            i->EntityId(); // Don't know... but seems to be just an empty call here
        return;
    case 105:
        if(!this->GoalIsEntity() && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 887, "GoalIsEntity()") == 1) {
            __debugbreak();
        }
        if((IAIEnvironment::EntityFlags(this->CmdGoal()) & ENTITY_FLAG_READY) != 0)
            return;
        goto LABEL_34;
    case 106:
        if(!this->EscortInitWalk())
        LABEL_34:
            this->SetState(0);
        return;
    default:
        return;
    }
    while(pEntity) {
        if(IAIEnvironment::MovingEntityWalkingState(pEntity->EntityId()) >= v6 && ++v7 >= iNumEntitiesHalved)
            return;
        pEntity = pEntity->Next();
    }
    this->SetStateFlagBit(0x10000u);
    v1 = this->WaypointXY();
    if(v1 == this->DestinationXY()) {
        this->ClearWaypoints();
        this->ActivateNextState();
    } else {
        Waypoints = true;
        this->PopWaypoint();
        if(!this->CheckWaypoint())
            Waypoints = this->FindWaypoints();
        if(Waypoints) {
            this->InitGroupWalk();
            this->SetWaitCounter(0x20u);
        } else {
        LABEL_2:
            this->ActivateNextState();
        }
    }
}

// address=[0x132ace0]
// Decompiled from void __thiscall CAITaskForceEx::InitWalk(CAITaskForceEx *this, bool a2)
void CAITaskForceEx::InitWalk(bool a2) {
    // al
    // [esp+0h] [ebp-2Ch]
    int v4; // [esp+4h] [ebp-28h]
    int v5; // [esp+8h] [ebp-24h]
    // [esp+Ch] [ebp-20h]
    // [esp+10h] [ebp-1Ch]
    // [esp+14h] [ebp-18h]
    // [esp+1Ch] [ebp-10h]
    // [esp+20h] [ebp-Ch]
    // [esp+24h] [ebp-8h]
    // [esp+28h] [ebp-4h]

    CAIEntityInfo *pEntity = this->FirstEntity();
    if(pEntity && this->WaypointXY() > 0) {
        int iX0 = this->WaypointX();
        int iY0 = this->WaypointY();
        if(!IAIEnvironment::WorldInWorld(iX0, iY0) && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 631, "g_pAIEnv->WorldInWorld(iX0, iY0)") == 1) {
            __debugbreak();
        }
        if(IAIEnvironment::WorldIsBlockedLand(iX0, iY0) && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 632, "!g_pAIEnv->WorldIsBlockedLand(iX0, iY0)") == 1) {
            __debugbreak();
        }
        int iSectorId = IAIEnvironment::WorldSectorId(iX0, iY0);
        if(iSectorId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 636, "iSectorId > 0") == 1)
            __debugbreak();
        int v13 = 0;
        while(pEntity) {
            unsigned int v7 = iX0 + 2 * g_sSurroundingHexPoints8[v13].X();
            unsigned int v8 = iY0 + 2 * g_sSurroundingHexPoints8[v13].Y();
            for(bool i = IAIEnvironment::WorldInWorld(v7, v8);
                !i || IAIEnvironment::WorldSectorId(v7, v8) != iSectorId;
                i = IAIEnvironment::WorldInWorld(v7, v8)) {
                if(v13 < 37)
                    v5 = v13 + 1;
                else
                    v5 = 0;
                v13 = v5;
                v7 = iX0 + 2 * g_sSurroundingHexPoints8[v5].X();
                v8 = iY0 + 2 * g_sSurroundingHexPoints8[v5].Y();
            }
            if(v13 < 37)
                v4 = v13 + 1;
            else
                v4 = 0;
            v13 = v4;
            int v3 = pEntity->EntityId();
            IAIEnvironment::MovingEntitySendMoveCommand(v3, v7, v8, a2);
            pEntity = pEntity->Next();
        }
    }
}

// address=[0x132aef0]
// Decompiled from void __thiscall CAITaskForceEx::InitGroupWalk(CAITaskForceEx *this)
void CAITaskForceEx::InitGroupWalk(void) {
    this->InitWalk(this->Class() != AI_TASK_FORCE_CLASS_GROUP);
}

// address=[0x132af30]
// Decompiled from char __thiscall CAITaskForceEx::FindSneakUpPosition(CAITaskForceEx *this)
bool CAITaskForceEx::FindSneakUpPosition(void) {
    // eax
    // ax
    // eax
    // [esp+4h] [ebp-88h]
    // [esp+8h] [ebp-84h]
    // [esp+Ch] [ebp-80h]
    // [esp+14h] [ebp-78h] MAPDST
    // [esp+18h] [ebp-74h]
    // [esp+20h] [ebp-6Ch]
    // [esp+24h] [ebp-68h]
    // [esp+2Fh] [ebp-5Dh]

    this->SetDestinationXY(-1);
    CAIEntityInfo *pEntity = this->FirstEntity();
    if(!pEntity)
        return 0;
    if(!this->GoalIsPosition() && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 281, "GoalIsPosition()") == 1) {
        __debugbreak();
    }

    int iXY = IAIEnvironment::EntityPackedPosition(pEntity->EntityId());
    int iDestXY = this->CmdGoal();
    int iOwnerId = this->OwnerId();
    CWaypoints v15{};
    if(!CAStarTiling::FindPath(iDestXY, iXY, v15, iOwnerId | 0xA0))
        return 0;
    if(v15.CachedWaypointsCount() <= 0)
        return 0;
    int v12 = 0;
    int v5 = IAIEnvironment::AlliancesPlayerEnemyBits(this->OwnerId());
    char v14 = 0;
    while(v15.CachedWaypointsCount() > 0) {
        int v11 = v15.Back();
        v15.PopBack();
        v12 += IAIEnvironment::GridDistancePackedXY(iDestXY, v11);
        iDestXY = v11;
        char v6 = IAIEnvironment::WorldOwnerIdPackedXY(v11);
        if((IAIEnvironment::AlliancesPlayerBit(v6) & v5) == 0) {
            if(v14) {
                if(v12 > 45)
                    break;
            } else {
                v14 = 1;
            }
        }
    }
    if(v12 <= 0)
        return 0;
    this->SetDestinationXY(iDestXY);
    return 1;
}

// address=[0x132b0f0]
// Decompiled from void __thiscall CAITaskForceEx::Load(CAITaskForceEx *this, struct IS4Chunk *a2)
void CAITaskForceEx::Load(IS4Chunk &a2) {
    a2.LoadSignature(-1516371456);
    a2.LoadUnsigned32(1, 1);
    CAITaskForce::Load(a2);
    a2.LoadSignature(-1516371454);
    this->m_iDestinationXY = a2.LoadUnsigned32();
    a2.LoadUnsigned32(12, 12);
    a2.Load(this->m_iWaypointsXY, 12);
    a2.LoadSignature(-1516371455);
}

// address=[0x132b190]
// Decompiled from void __thiscall CAITaskForceEx::Save(CAITaskForceEx *this, struct IS4Chunk *a2)
void CAITaskForceEx::Save(class IS4Chunk &a2) {
    a2.SaveSignature(-1516371456);
    a2.SaveUnsigned32(1);
    CAITaskForce::Save(a2);
    a2.SaveSignature(-1516371454);
    a2.SaveUnsigned32(this->m_iDestinationXY);
    a2.SaveUnsigned32(12);
    a2.Save(&this->m_iWaypointsXY, 0xCu);
    a2.SaveSignature(-1516371455);
}

// address=[0x132e950]
// Decompiled from int __thiscall CAITaskForceEx::DestinationX(CAITaskForceEx *this)
int CAITaskForceEx::DestinationX(void) const {
    return IAIEnvironment::UnpackXFast(this->m_iDestinationXY);
}

// address=[0x132e970]
// Decompiled from int __thiscall CAITaskForceEx::DestinationXY(CAITaskForceEx *this)
int CAITaskForceEx::DestinationXY(void) const {
    return this->m_iDestinationXY;
}

// address=[0x132e990]
// Decompiled from int __thiscall CAITaskForceEx::DestinationY(CAITaskForceEx *this)
int CAITaskForceEx::DestinationY(void) const {
    return IAIEnvironment::UnpackYFast(this->m_iDestinationXY);
}

// address=[0x132ed00]
// Decompiled from bool __thiscall CAITaskForceEx::WaypointAvailable(CAITaskForceEx *this)
bool CAITaskForceEx::WaypointAvailable(void) const {
    return this->m_iWaypointsXY[0] >= 0;
}

// address=[0x132ed40]
// Decompiled from int __thiscall CAITaskForceEx::WaypointX(CAITaskForceEx *this)
int CAITaskForceEx::WaypointX(void) const {
    return IAIEnvironment::UnpackXFast(this->m_iWaypointsXY[0]);
}

// address=[0x132ed70]
// Decompiled from DWORD __thiscall CAITaskForceEx::WaypointXY(CAITaskForceEx *this)
int CAITaskForceEx::WaypointXY(void) const {
    return this->m_iWaypointsXY[0];
}

// address=[0x132ed90]
// Decompiled from int __thiscall CAITaskForceEx::WaypointY(CAITaskForceEx *this)
int CAITaskForceEx::WaypointY(void) const {
    return IAIEnvironment::UnpackYFast(this->m_iWaypointsXY[0]);
}

// address=[0x13192a0]
// Decompiled from void __thiscall CAITaskForceEx::~CAITaskForceEx(CAITaskForceEx *this)
CAITaskForceEx::~CAITaskForceEx(void) = default;

// address=[0x132a140]
// Decompiled from CAITaskForceEx *__thiscall CAITaskForceEx::CAITaskForceEx(  CAITaskForceEx *this,  int iOwnerId,  int tClass,  int tType,  int iFlags)
CAITaskForceEx::CAITaskForceEx(int iOwnerId, enum T_AI_TASK_FORCE_CLASS tClass, enum T_AI_TASK_FORCE_TYPE tType, int iFlags) : CAITaskForce(iOwnerId, tClass, tType, iFlags) {}

// address=[0x132b230]
// Decompiled from char __thiscall CAITaskForceEx::EscortInitWalk(CAITaskForceEx *this)
bool CAITaskForceEx::EscortInitWalk(void) {
    int iAssociatedSectorId;  // eax
    int v3;                   // eax
    int iDestOwnerId;         // eax
    int iXYAssociated;        // eax
    int v6;                   // eax
    int iDestOwnerAllianceId; // [esp+0h] [ebp-2Ch]
    int v10;                  // [esp+Ch] [ebp-20h]
    int iDestX;               // [esp+10h] [ebp-1Ch]
    int iDestY;               // [esp+14h] [ebp-18h]
    int iThisSectorId;        // [esp+18h] [ebp-14h]
    // [esp+1Ch] [ebp-10h]

    CAITaskForce *pAssociatedTaskForce = this->AssociatedTaskForce();
    if(!pAssociatedTaskForce) {
        this->SetDestinationXY(-1);
        return 0;
    }

    int iXAssociated, iYAssociated;
    if(!pAssociatedTaskForce->GetPositionOfFirstEntity(iXAssociated, iYAssociated)) {
        this->SetDestinationXY(-1);
        return 0;
    }

    int iX; // [esp+4h] [ebp-28h] BYREF
    int iY; // [esp+8h] [ebp-24h] BYREF
    if(!this->GetPositionOfFirstEntity(iX, iY) || (iThisSectorId = IAIEnvironment::WorldSectorId(iX, iY),
                                                   iAssociatedSectorId = IAIEnvironment::WorldSectorId(iXAssociated, iYAssociated),
                                                   iAssociatedSectorId != iThisSectorId)) {
        this->SetDestinationXY(-1);
        return 0;
    }
    if((this->Flags() & 0x8000000) != 0) {
        this->ClearInternalFlagBit(0x8000000u);
        this->SetDestinationXY(-1);
    }
    if(this->DestinationXY() <= 0)
        goto LABEL_17;
    iDestX = this->DestinationX();
    iDestY = this->DestinationY();
    v3 = IAIEnvironment::WorldSectorId(iDestX, iDestY);
    if(v3 != iThisSectorId)
        goto LABEL_17;
    v10 = IAIEnvironment::GridDistance(iXAssociated - iDestX, iYAssociated - iDestY);
    if(v10 <= 6)
        return 1;
    if(v10 <= 12) {
        iDestOwnerId = this->OwnerId();
        iDestOwnerAllianceId = IAIEnvironment::AlliancesAllianceId(iDestOwnerId);
        if(!CInfluMap::EnemyValueXY(iXAssociated, iYAssociated, iDestOwnerAllianceId))
            return 1;
    }
LABEL_17:
    iXYAssociated = IAIEnvironment::PackXYFast(iXAssociated, iYAssociated);
    this->SetDestinationXY(iXYAssociated);
    this->m_iWaypointsXY[0] = this->DestinationXY();
    this->InitWalk(1);
    return 1;
}

// address=[0x132eac0]
// Decompiled from int __thiscall CAITaskForceEx::SetCommandAndClearStuff(CAITaskForceEx *this, unsigned int a2, int a3, int a4)
void CAITaskForceEx::SetCommandAndClearStuff(int a2, int a3, int a4) {
    this->SetCommand(a2, a3, a4);
    this->SetDestinationXY(-1);
    this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 0, 0);
    this->SetWaitCounter(0);
}
