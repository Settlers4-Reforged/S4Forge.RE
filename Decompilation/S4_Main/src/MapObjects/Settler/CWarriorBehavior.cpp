#include "CWarriorBehavior.h"

#include "CBB/CBBSupport.h"
#include "CSettler.h"
#include "Defines/AI.h"
#include "Defines/Object.h"
#include "Defines/Races.h"
#include "Defines/Settlers.h"
#include "Main/CGameStateHandler.h"
#include "Main/Players/CPlayerManager.h"
#include "MapObjects/Building/CBuildingInfoMgr.h"
#include "MapObjects/Building/CFindEnemyBuildings.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/CSpiralOffsets.h"
#include "MapObjects/CTmpEntitiesRef.h"
#include "MapObjects/IMovingEntity.h"
#include "MapObjects/SSurroundingPoint8.h"
#include "Pathing/CAlliances.h"
#include "Pathing/CWalking.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class CWarriorBehavior
struct CWarriorProperties {
    bool (CWarriorBehavior::*m_fpInfluenceCheck)(IMovingEntity &);
    bool (CWarriorBehavior::*m_fpTargetAndDistanceCheck)(IMovingEntity &, int a3);
    int (CWarriorBehavior::*m_fpAttackCheck)(IMovingEntity &);
    int (CWarriorBehavior::*m_fpAttackScan)(IMovingEntity &, int *);
    int m_iAttackType;
    int m_uScanMask;
    int m_uU1;
    int m_iRadiusFirst;
    int m_iRadiusLast;
    int m_iScanRadiusLast;
    int m_iRanges[15];
} s_sWarriorProperties[21] = {
    {
        // 0 AI_WARRIOR_TYPE_NONE
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 1 AI_WARRIOR_TYPE_DARK_TRIBE
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 2 AI_WARRIOR_TYPE_SWORDMAN
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck1,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        33659907,
        0,
        1,
        1,
        13,
        { 0, 0, 6, 6, 5, 4, 5, 2, 3, 3, 0, 0, 0, 6, 1 },
    },
    {
        // 3 AI_WARRIOR_TYPE_BOWMAN
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheckBowman,
        &CWarriorBehavior::WarriorAttackScanBowman,
        0,
        0x202B003,
        0,
        4,
        13,
        15,
        { 0, 0, 6, 6, 5, 4, 5, 2, 3, 3, 0, 0, 6, 0, 1 },
    },
    {
        // 4 AI_WARRIOR_TYPE_FIGHTER_UNIQUE
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 5 AI_WARRIOR_TYPE_SQUAD_LEADER
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck1,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0x201BC03,
        0,
        1,
        1,
        13,
        { 0, 0, 6, 6, 5, 4, 5, 2, 3, 3, 0, 0, 0, 0, 1 },
    },
    {
        // 6 AI_WARRIOR_TYPE_PRIEST
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 7 AI_WARRIOR_TYPE_MISC_UNIT
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 8 AI_WARRIOR_TYPE_VEHICLE_WAR
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0x202E0FF,
        0,
        1,
        20,
        20,
        { 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 6, 2, 3, 0, 0 },
    },
    {
        // 9 AI_WARRIOR_TYPE_VEHICLE_MISC
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 10 AI_WARRIOR_TYPE_SHIP_WAR
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0x202E0FF,
        0,
        1,
        20,
        30,
        { 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 8, 2, 3, 0, 0 },
    },
    {
        // 11 UNK
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 12 AI_WARRIOR_TYPE_TOWER_BUILDING
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 13 UNK
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck1,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0x201FF03,
        0,
        1,
        1,
        1,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 14 AI_WARRIOR_TYPE_DONKEY
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0,
        0,
        0,
        0,
        0,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 15: SETTLER_MEDIC_01, SETTLER_MEDIC_02, SETTLER_MEDIC_03
        &CWarriorBehavior::WarriorCheckMedic,
        &CWarriorBehavior::WarriorValidLastTargetMedic,
        &CWarriorBehavior::WarriorAttackCheckMedic,
        &CWarriorBehavior::WarriorAttackScanMedic,
        1,
        0x201BF03,
        0,
        1,
        1,
        13,
        { 0, 0, 6, 6, 5, 4, 5, 2, 0, 0, 0, 0, 0, 6, 1 },
    },
    {
        // 16 SETTLER_AXEWARRIOR_01, SETTLER_AXEWARRIOR_02 SETTLER_AXEWARRIOR_03
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorValidLastTargetAxeWarrior,
        &CWarriorBehavior::WarriorAttackCheckAxeWarrior,
        &CWarriorBehavior::WarriorAttackScanAxeWarrior,
        4,
        0x201BC03,
        0,
        1,
        2,
        13,
        { 0, 0, 6, 6, 5, 4, 5, 2, 3, 3, 0, 0, 0, 6, 1 },
    },
    {
        // 17 SETTLER_BLOWGUNWARRIOR_01, SETTLER_BLOWGUNWARRIOR_02, SETTLER_BLOWGUNWARRIOR_03
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        3,
        0x202BF03,
        0,
        3,
        8,
        13,
        { 0, 0, 6, 6, 5, 4, 5, 2, 0, 0, 0, 0, 0, 0, 1 },
    },
    {
        // 18 SETTLER_SHAMAN
        &CWarriorBehavior::WarriorCheckOwner9,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        4,
        0x200FFFE,
        0,
        1,
        3,
        10,
        { 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 19 SETTLER_SABOTEUR
        &CWarriorBehavior::WarriorCheckSaboteur,
        &CWarriorBehavior::WarriorValidLastTargetSaboteur,
        &CWarriorBehavior::WarriorAttackCheckSaboteur,
        &CWarriorBehavior::WarriorAttackScanSaboteur,
        4,
        0x200FFFE,
        0,
        1,
        3,
        10,
        { 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    },
    {
        // 20 SETTLER_BACKPACKCATAPULTIST_01, SETTLER_BACKPACKCATAPULTIST_02, SETTLER_BACKPACKCATAPULTIST_03
        &CWarriorBehavior::WarriorCheckInflu1,
        &CWarriorBehavior::WarriorCheckTargetAndDistance,
        &CWarriorBehavior::WarriorAttackCheck15,
        &CWarriorBehavior::WarriorAttackScan15,
        3,
        0x202BF03,
        0,
        4,
        10,
        15,
        { 0, 0, 6, 6, 5, 4, 5, 2, 0, 0, 0, 0, 0, 0, 1 },
    },

};

// address=[0x1592e10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationXY(CWarriorBehavior *this)
int CWarriorBehavior::WarriorDestinationXY(void) const {

    return this->m_sWarriorBehaviorData.m_iDestinationXYOrId;
}

// address=[0x15ac3a0]
// Decompiled from CWarriorBehavior *__thiscall CWarriorBehavior::CWarriorBehavior(CWarriorBehavior *this)
CWarriorBehavior::CWarriorBehavior(void) {
    memset(&this->m_sWarriorBehaviorData, 0, sizeof(this->m_sWarriorBehaviorData));
    this->m_sWarriorBehaviorData.m_pProperties = &s_sWarriorProperties[0];
}

// address=[0x15ac3e0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorInit(CWarriorBehavior *this, struct IMovingEntity *a2, int a3, int a4)
void CWarriorBehavior::WarriorInit(IMovingEntity &_rEntity, int a3, int a4) {
    int iWarriorPropertyId = _rEntity.WarriorType();
    int iType = _rEntity.Type();
    if(iWarriorPropertyId == AI_WARRIOR_TYPE_FIGHTER_UNIQUE || iType == SETTLER_SABOTEUR) {
        switch(iType) {
        case SETTLER_MEDIC_01:
        case SETTLER_MEDIC_02:
        case SETTLER_MEDIC_03:
            iWarriorPropertyId = 15;
            break;
        case SETTLER_AXEWARRIOR_01:
        case SETTLER_AXEWARRIOR_02:
        case SETTLER_AXEWARRIOR_03:
            iWarriorPropertyId = 16;
            break;
        case SETTLER_BLOWGUNWARRIOR_01:
        case SETTLER_BLOWGUNWARRIOR_02:
        case SETTLER_BLOWGUNWARRIOR_03:
            iWarriorPropertyId = 17;
            break;
        case SETTLER_SABOTEUR:
            iWarriorPropertyId = 19;
            break;
        case SETTLER_SHAMAN:
            iWarriorPropertyId = 18;
            break;
        case SETTLER_BACKPACKCATAPULTIST_01:
        case SETTLER_BACKPACKCATAPULTIST_02:
        case SETTLER_BACKPACKCATAPULTIST_03:
            iWarriorPropertyId = 20;
            break;
        default:
            BB_REPORTF("CWarriorBehavior::WarriorInit(): Unsupported settler type %i of warrior type FIGHTER_UNIQUE", iType)
            break;
        }
    }
    this->m_sWarriorBehaviorData.m_pProperties = &s_sWarriorProperties[iWarriorPropertyId];
    if((a4 & 0x700000) == 0)
        a3 = -1;
    this->m_sWarriorBehaviorData.m_iDestinationXYOrId = a3;
    unsigned int iFlags = _rEntity.OwnerId() | a4 & 0xFFFFFFF0;
    this->m_sWarriorBehaviorData.m_iFlags = iFlags;
    char v7 = 0;
    int v8 = iFlags & 0x700000;
    if((iFlags & 0x700000) > 0x500000) {
        if(v8 == 0x600000) {
            v7 = 7;
        } else if(v8 == 0x700000) {
            this->m_sWarriorBehaviorData.m_uLastTargetId = a3;
            this->m_sWarriorBehaviorData.m_uState = 5;
            this->m_sWarriorBehaviorData.m_iU01 = 0;
            this->m_sWarriorBehaviorData.m_iNextFullUpdate = 0;
            this->m_sWarriorBehaviorData.m_iDestinationXYOrId = 0;
            return;
        }
    } else {
        switch(v8) {
        case 0x500000:
            v7 = 6;
            break;
        case 0x100000:
            v7 = 1;
            break;
        case 0x200000:
        case 0x300000:
            v7 = 4;
            break;
        }
    }
    this->m_sWarriorBehaviorData.m_uState = v7;
    this->m_sWarriorBehaviorData.m_iU01 = 0;
    this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
    this->m_sWarriorBehaviorData.m_iNextFullUpdate = 0;
    CWarriorBehavior::WarriorInitWalk(_rEntity, a3);
}

// address=[0x15ac600]
// Decompiled from void __thiscall CWarriorBehavior::WarriorLogicUpdate(  CWarriorBehavior *this,  struct IMovingEntity *a2,  unsigned int a3,  char a4)
void CWarriorBehavior::WarriorLogicUpdate(IMovingEntity &_rEntity, unsigned int a3, int a4) {
    int v4;               // esi
    int v5;               // eax
    int v6;               // esi
    int v7;               // eax
    int v8;               // eax
    T_AI_WARRIOR_TYPE v9; // [esp+Ch] [ebp-50h]
    int iDestinationXY;   // [esp+14h] [ebp-48h]
    int v11;              // [esp+18h] [ebp-44h]
    int v12;              // [esp+24h] [ebp-38h] BYREF
    BOOL v13;             // [esp+28h] [ebp-34h]
    BOOL v14;             // [esp+2Ch] [ebp-30h]
    int v15;              // [esp+30h] [ebp-2Ch]
    int m_uLastTargetId;  // [esp+34h] [ebp-28h]
    int v18;              // [esp+3Ch] [ebp-20h]
    int iDistance;        // [esp+40h] [ebp-1Ch]
    int v20;              // [esp+44h] [ebp-18h]
    int v21;              // [esp+48h] [ebp-14h]
    int v22;              // [esp+4Ch] [ebp-10h]
                          // [esp+50h] [ebp-Ch]
    bool IsFullUpdate;    // [esp+5Bh] [ebp-1h]

    unsigned int uState = this->m_sWarriorBehaviorData.m_uState;

    if(uState > 4) {
        if(uState <= 8) {
            switch(uState) {
            case 6:
                if(CWarriorBehavior::WarriorIsFullUpdate(a3))
                    goto LABEL_54;
                m_uLastTargetId = this->m_sWarriorBehaviorData.m_uLastTargetId;
                if(!m_uLastTargetId) {
                    this->WarriorTaskWalkOneStep(_rEntity);
                    return;
                }
                if(!CWarriorBehavior::WarriorCheckTargetAndDistance(_rEntity, m_uLastTargetId)) {
                LABEL_54:
                    CWarriorBehavior::WarriorSetNextFullUpdate(a3, 0x1Eu);
                    if((this->*m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck)(_rEntity) && (v15 = CWarriorBehavior::WarriorAttackCheck(_rEntity), v15 > 0)) {
                        this->m_sWarriorBehaviorData.m_uLastTargetId = v15;
                        CWarriorBehavior::WarriorAttackTarget(_rEntity, v15);
                    } else {
                        this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
                        this->WarriorTaskWalkOneStep(_rEntity);
                    }
                } else {
                    CWarriorBehavior::WarriorAttackTarget(_rEntity, m_uLastTargetId);
                }
                return;
            case 7: {
                if((this->*m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck)(_rEntity) && (v18 = CWarriorBehavior::WarriorAttackCheck(_rEntity), v18 > 0)) {
                    this->m_sWarriorBehaviorData.m_uLastTargetId = v18;
                    CWarriorBehavior::WarriorAttackTarget(_rEntity, v18);
                    return;
                }
                v11 = CWarriorBehavior::WarriorDestinationId();
                if(v11 > 0) {
                    auto &rDestinationEntity = CMapObjectMgr::Entity(v11);
                    if((rDestinationEntity.Flags() & ENTITY_FLAG_READY) == 0)
                        return;

                    iDestinationXY = rDestinationEntity.PackedXY();
                    if(Y16X16::DistanceFast(iDestinationXY, _rEntity.PackedXY()) <= this->m_sWarriorBehaviorData.m_pProperties->m_uU1 + s_sWarriorProperties[rDestinationEntity.WarriorType()].m_uU1 + 1) {
                        this->WarriorTaskIdleWalk(_rEntity);
                    } else {
                        CWarriorBehavior::WarriorPseudoInitWalk(_rEntity, iDestinationXY);
                        this->WarriorTaskWalkOneStep(_rEntity);
                    }
                } else {
                    this->m_sWarriorBehaviorData.m_iDestinationXYOrId = -1;
                    this->m_sWarriorBehaviorData.m_uState = 8;
                }
            }
                return;
            default:
                BB_REPORT("CWarriorBehavior::WarriorLogicUpdate(): Invalid state!");
                [[fallthrough]];
            case 8:
                this->m_sWarriorBehaviorData.m_uState = 0;
                this->WarriorTaskFinished(_rEntity);
                return;
            }
        }
    }

    if(uState == 4) {
        if((this->WarriorTaskWalkOneStep(_rEntity) & 0x70) != 0)
            this->m_sWarriorBehaviorData.m_uState = 8;

        return;
    }

    if(uState > 1) {
        BB_REPORT("CWarriorBehavior::WarriorLogicUpdate(): Invalid state!");
        return;
    }

    IsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(a3);
    if(!IsFullUpdate) {
        v21 = this->m_sWarriorBehaviorData.m_uLastTargetId;
        if(v21) {
            if((a4 & 0x10) != 0) {
                this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
            } else {
                if((this->*m_sWarriorBehaviorData.m_pProperties->m_fpTargetAndDistanceCheck)(_rEntity, v21)) {
                    this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
                    CWarriorBehavior::WarriorAttackTarget(_rEntity, v21);
                    return;
                }
                IsFullUpdate = (this->m_sWarriorBehaviorData.m_iU01 & 2) == 0;
            }
        }
    }

    if(IsFullUpdate) {
        this->m_sWarriorBehaviorData.m_iU01 &= ~2u;
        CWarriorBehavior::WarriorSetNextFullUpdate(a3, 0x1Eu);
        if((this->*m_sWarriorBehaviorData.m_pProperties->m_fpInfluenceCheck)(_rEntity)) {
            if((a4 & 0x10) == 0) {
                v20 = CWarriorBehavior::WarriorAttackCheck(_rEntity);
                if(v20 > 0) {
                    this->m_sWarriorBehaviorData.m_uLastTargetId = v20;
                    CWarriorBehavior::WarriorAttackTarget(_rEntity, v20);
                    return;
                }
                v22 = (this->*m_sWarriorBehaviorData.m_pProperties->m_fpAttackScan)(_rEntity, &v12);
                v14 = v22 == 0;
                v13 = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst > 1;
                if(v13 && v14)
                    v22 = CWarriorBehavior::WarriorEvadeScan15a(_rEntity, &v12);
                if(v22 > 0) {
                    this->m_sWarriorBehaviorData.m_iU01 |= 2u;
                    this->m_sWarriorBehaviorData.m_uLastTargetId = v22;
                    iDistance = CWarriorBehavior::WarriorPseudoInitWalk(_rEntity, v12);
                    if(iDistance <= 8) {
                        BB_ASSERT(iDistance > 0);
                        CWarriorBehavior::WarriorSetNextFullUpdate(a3, 4 * iDistance - 4);
                    }
                }
            }
        }
    }

    if(this->m_sWarriorBehaviorData.m_uLastTargetId != 0 && (this->m_sWarriorBehaviorData.m_iU01 & 2) == 0) {
        this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
        v4 = CWarriorBehavior::WarriorDestinationXY();
        if(v4 != CWarriorBehavior::WarriorWalkDestinationXY(_rEntity)) {
            v5 = CWarriorBehavior::WarriorDestinationXY();
            CWarriorBehavior::WarriorInitWalk(_rEntity, v5);
        }
    }

    if((this->WarriorTaskWalkOneStep(_rEntity) & 0x70) != 0 && CWarriorBehavior::WarriorDestinationXY() != -1) {
        v6 = CWarriorBehavior::WarriorDestinationXY();
        if(v6 == CWarriorBehavior::WarriorWalkDestinationXY(_rEntity)) {
            this->m_sWarriorBehaviorData.m_uState = 8;
        } else {
            v7 = CWarriorBehavior::WarriorDestinationXY();
            CWarriorBehavior::WarriorInitWalk(_rEntity, v7);
        }
    }
}

// address=[0x15acbd0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleLogicUpdate(  CWarriorBehavior *this,  struct IMovingEntity *a2,  unsigned int a3,  char a4)
void CWarriorBehavior::WarriorVehicleLogicUpdate(IMovingEntity &_rEntity, unsigned int a3, int a4) {

    int iBits;                      // [esp+8h] [ebp-60h] BYREF
    int iScanMask;                  // [esp+Ch] [ebp-5Ch] BYREF
    BOOL v10;                       // [esp+10h] [ebp-58h]
    BOOL v11;                       // [esp+14h] [ebp-54h]
    unsigned int iDistanceToTarget; // [esp+18h] [ebp-50h]
    unsigned int dword4;            // [esp+1Ch] [ebp-4Ch]
                                    // [esp+24h] [ebp-44h]
    int AttackWayPoint;             // [esp+28h] [ebp-40h]
                                    // [esp+2Fh] [ebp-39h]
    unsigned int v19;               // [esp+34h] [ebp-34h]
    int iMIEntityId;                // [esp+38h] [ebp-30h]
    IEntity *pTarget;               // [esp+3Ch] [ebp-2Ch]
    int iLastTargetId;              // [esp+48h] [ebp-20h]
    bool bIsFullUpdate;             // [esp+4Eh] [ebp-1Ah]
                                    // [esp+4Fh] [ebp-19h]
    SWarriorScanResult v28;         // [esp+54h] [ebp-14h] BYREF

    void (__thiscall CWarriorBehavior::*fpOneStep)(IMovingEntity &); // [esp+40h] [ebp-28h]
    bool v26 = (a4 & 3) == 0;
    switch(this->m_sWarriorBehaviorData.m_uState) {
    case 0:
    case 1:
    case 7: {
        if(this->m_sWarriorBehaviorData.m_uState) {
            if(this->m_sWarriorBehaviorData.m_uState == 1)
                fpOneStep = &CWarriorBehavior::WarriorVehicleMoveWalkOneStep;
            else
                fpOneStep = &CWarriorBehavior::WarriorVehicleEscortWalkOneStep;
        } else {
            fpOneStep = &CWarriorBehavior::WarriorVehicleIdleWalkOneStep;
        }
        if((a4 & 2) != 0) {
            this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
            (this->*fpOneStep)(_rEntity);
            return;
        }
        bIsFullUpdate = CWarriorBehavior::WarriorIsFullUpdate(a3);
        iLastTargetId = this->m_sWarriorBehaviorData.m_uLastTargetId;
        if(iLastTargetId) {
            pTarget = CMapObjectMgr::EntityPtr(iLastTargetId);
            CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iBits, iScanMask);
            if(pTarget && CWarriorBehavior::WarriorCheckTarget(*pTarget, iBits, iScanMask)) {
                iDistanceToTarget = Y16X16::DistanceFast(_rEntity.PackedXY(), pTarget->PackedXY());
                v19 = this->m_sWarriorBehaviorData.m_pProperties->m_iRanges[pTarget->WarriorType()];
                v19 += iDistanceToTarget > CWarriorBehavior::WarriorProperties().m_iRadiusLast ? 0 : 10;
            } else {
                iLastTargetId = 0;
                bIsFullUpdate = 1;
            }
        }
        if((a4 & 1) != 0) {
            if(iLastTargetId)
                this->WarriorTaskIdleWalk(_rEntity);
            else
                (this->*fpOneStep)(_rEntity);
            return;
        }
        if(bIsFullUpdate) {
            this->WarriorVehicleAttackScan31(_rEntity, v28);
            iMIEntityId = v28.m_iEntityId;
            if(v28.m_iEntityId) {
                CWarriorBehavior::WarriorSetNextFullUpdate(a3, 0x14u);
                dword4 = v28.m_iOtherDistance;
                if(v28.m_iOtherDistance > 10u) {
                    if(iLastTargetId) {
                        v11 = v19 >= dword4;
                        v10 = iDistanceToTarget <= 2 * v28.m_iDistance;
                        if(v10 && v11)
                            iMIEntityId = iLastTargetId;
                    }
                    this->m_sWarriorBehaviorData.m_uLastTargetId = iMIEntityId;
                    CWarriorBehavior::WarriorVehicleAttackTarget(_rEntity, iMIEntityId);
                    return;
                }
            } else {
                CWarriorBehavior::WarriorSetNextFullUpdate(a3, 0x28u);
            }
        LABEL_36:
            this->m_sWarriorBehaviorData.m_uLastTargetId = 0;
            (this->*fpOneStep)(_rEntity);
            return;
        }
        if(!iLastTargetId || v19 <= 0xA)
            goto LABEL_36;
        BB_ASSERT(m_sWarriorBehaviorData.m_uLastTargetId == iLastTargetId)
        CWarriorBehavior::WarriorVehicleAttackTarget(_rEntity, iLastTargetId);
        return;
    }
    case 4:
        CWarriorBehavior::WarriorVehicleMoveWalkOneStep(_rEntity);
        return;
    case 5: {
        if(!CMapObjectMgr::ValidUsedEntityId(this->m_sWarriorBehaviorData.m_uLastTargetId))
            goto LABEL_39;
        IEntity &rTargetEntity = CMapObjectMgr::Entity(this->m_sWarriorBehaviorData.m_uLastTargetId);
        if(!this->m_sWarriorBehaviorData.m_iDestinationXYOrId)
            this->m_sWarriorBehaviorData.m_iDestinationXYOrId = CWarriorBehavior::FindAttackWayPoint(_rEntity, rTargetEntity);
        if(this->m_sWarriorBehaviorData.m_iDestinationXYOrId > 0) {
            this->m_sWarriorBehaviorData.m_iU01 |= 1u;
            CWarriorBehavior::WarriorInitWalk(_rEntity, this->m_sWarriorBehaviorData.m_iDestinationXYOrId);
        }
        if(!CWarriorBehavior::WarriorIsFullUpdate(a3))
            goto LABEL_51;
        if(!CMapObjectMgr::ValidUsedEntityId(this->m_sWarriorBehaviorData.m_uLastTargetId) || !rTargetEntity.FlagBits(ENTITY_FLAG_READY)) {
            goto LABEL_39;
        }
        AttackWayPoint = CWarriorBehavior::FindAttackWayPoint(_rEntity, rTargetEntity);
        if(AttackWayPoint && AttackWayPoint != this->m_sWarriorBehaviorData.m_iDestinationXYOrId) {
            this->m_sWarriorBehaviorData.m_iDestinationXYOrId = AttackWayPoint;
            this->m_sWarriorBehaviorData.m_iU01 |= 1u;
            CWarriorBehavior::WarriorInitWalk(_rEntity, this->m_sWarriorBehaviorData.m_iDestinationXYOrId);
        }
    LABEL_51:
        if(this->m_sWarriorBehaviorData.m_iDestinationXYOrId > 0 && (a4 & 2) == 0) {
            if(CWarriorBehavior::IsTargetInAtackRange(_rEntity, rTargetEntity)) {
                if((a4 & 1) != 0)
                    this->WarriorTaskIdleWalk(_rEntity);
                else
                    CWarriorBehavior::WarriorVehicleAttackTarget(_rEntity, this->m_sWarriorBehaviorData.m_uLastTargetId);
            } else {
                CWarriorBehavior::WarriorVehicleMoveWalkOneStep(_rEntity);
            }
        } else {
        LABEL_39:
            this->WarriorTaskFinished(_rEntity);
        }
        return;
    }
    default:
        BB_REPORT("CWarriorBehavior::WarriorLogicUpdate(): Invalid state!")
        [[fallthrough]];
    case 8:
        this->m_sWarriorBehaviorData.m_uState = 0;
        this->WarriorTaskFinished(_rEntity);
        return;
    }
}

// address=[0x15ad0e0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckTargetAndDistance(CWarriorBehavior *this, struct IEntity *a2, int a3)
bool CWarriorBehavior::WarriorCheckTargetAndDistance(IMovingEntity &_rEntity, int _iEntityId) {
    int iBits;     // [esp+14h] [ebp-24h] BYREF
    int iScanMask; // [esp+18h] [ebp-20h] BYREF
    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iBits, iScanMask);
    if(!CWarriorBehavior::WarriorCheckTarget(_iEntityId, iBits, iScanMask))
        return 0;
    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    IEntity &pTargetEntity = CMapObjectMgr::Entity(_iEntityId);
    int iTargetX = pTargetEntity.X();
    int iTargetY = pTargetEntity.Y();
    int iDistance = Grid::Distance(iTargetX - iX, iTargetY - iY);
    int iRadiusFirst = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst;
    int iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
    BOOL bIsCatapult = pTargetEntity.ObjType() == CATAPULT_OBJ;
    return iDistance <= iRadiusLast + bIsCatapult && iDistance >= (int)iRadiusFirst;
}

// address=[0x15AEB60]
bool __cdecl MedicCanHeal(int _iAlliance, int _iEntityId) {
    if(_iEntityId <= 0)
        return 0;

    IEntity *pEntity = CMapObjectMgr::EntityPtr(_iEntityId);

    if(pEntity->ObjType() != SETTLER_OBJ)
        return 0;
    if(!pEntity->FlagBits(ENTITY_FLAG_READY))
        return 0;
    if((_iAlliance & CAlliances::PlayerBit(pEntity->OwnerId())) == 0)
        return 0;
    if(pEntity->Hitpoints() >= pEntity->MaxHitpoints())
        return 0;

    return 1;
}

// address=[0x15ad1f0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorValidLastTargetMedic(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
bool CWarriorBehavior::WarriorValidLastTargetMedic(IMovingEntity &_rEntity, int _iTargetId) { // TODO: probably best to change this to CSettler&
    CSettler &rSettler = dynamic_cast<CSettler &>(_rEntity);
    class CSoldierRole *pRole = dynamic_cast<CSoldierRole *>(&rSettler.Role());
    if(!pRole || pRole->GetNumberOfHealings() <= 0)
        return 0;

    return MedicCanHeal(CAlliances::PlayerAllyBits(_rEntity.OwnerId()), _iTargetId) || CWarriorBehavior::WarriorCheckTargetAndDistance(_rEntity, _iTargetId);
}

// address=[0x15ad2a0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetAxeWarrior(  CWarriorBehavior *this,  struct IMovingEntity *a2,  int a3)
bool CWarriorBehavior::WarriorValidLastTargetAxeWarrior(IMovingEntity &a2, int a3) {
    return 0;
}

// address=[0x15ad2b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorValidLastTargetSaboteur(  CWarriorBehavior *this,  struct IMovingEntity *a2,  int a3)
bool CWarriorBehavior::WarriorValidLastTargetSaboteur(IMovingEntity &a2, int a3) {
    return 0;
}

// address=[0x15ad2c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck1(CWarriorBehavior *this, struct IEntity *a2)
int CWarriorBehavior::WarriorAttackCheck1(IMovingEntity &_rEntity) {
    int iBits;     // [esp+18h] [ebp-30h] BYREF
    int iScanMask; // [esp+1Ch] [ebp-2Ch] BYREF

    CWarriorBehavior *v16 = this;
    int iX = _rEntity.X();
    int iY = _rEntity.Y();

    BB_ASSERT(g_cWorld.InInnerWorld1(iX, iY))

    int iIdx = _rEntity.WorldIdx();
    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iBits, iScanMask);
    int iFoundEntityId = -1;
    int iFurthestTargetRange = 0;
    for(int i = 1; i < 7; ++i) {
        int iId = CWorldManager::MapObjectId(iIdx + CWorldManager::SurroundingHexPointRelIndex(i));
        if(!iId)
            continue;

        if(iId <= 6) {
            iFoundEntityId -= iFoundEntityId < 0;
            continue;
        }

        auto &pEntity = CMapObjectMgr::Entity(iId);
        if((iBits & CAlliances::PlayerBit(pEntity.OwnerId())) == 0 || !WarriorTargetAllowableAndVulnerable(pEntity, iScanMask))
            continue;

        int iRange = this->m_sWarriorBehaviorData.m_pProperties->m_iRanges[pEntity.WarriorType()];
        if(iRange > iFurthestTargetRange) {
            iFoundEntityId = iId;
            iFurthestTargetRange = iRange;
        }
    }
    if(iFoundEntityId != -2)
        return iFoundEntityId;

    for(int j = 7; j < 19; ++j) {
        int iId = CWorldManager::MapObjectId(iIdx + CWorldManager::SurroundingHexPointRelIndex(j));
        if(CWarriorBehavior::WarriorCheckTarget(iId, iBits, iScanMask))
            return iId;
    }

    return -1;
}

// address=[0x15ad4a0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck15(CWarriorBehavior *this, struct IEntity *a2)
int CWarriorBehavior::WarriorAttackCheck15(IMovingEntity &_rEntity) {

    // eax
    // eax
    // eax
    T_AI_WARRIOR_TYPE v6; // [esp+0h] [ebp-44h]
    int iEnemyBits;       // [esp+4h] [ebp-40h] BYREF
    int iEnemyScanMask;   // [esp+8h] [ebp-3Ch] BYREF
                          // [esp+Ch] [ebp-38h]
                          // [esp+10h] [ebp-34h]
                          // [esp+14h] [ebp-30h]
                          // [esp+18h] [ebp-2Ch]
                          // [esp+1Ch] [ebp-28h]
                          // [esp+20h] [ebp-24h]
                          // [esp+24h] [ebp-20h]
                          // [esp+28h] [ebp-1Ch]
                          // [esp+2Ch] [ebp-18h]
                          // [esp+30h] [ebp-14h]
                          // [esp+34h] [ebp-10h]
                          // [esp+3Ch] [ebp-8h]
                          // [esp+40h] [ebp-4h]

    int iRadiusFirst = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst;
    int iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
    if(iRadiusFirst <= 0)
        return -1;
    BB_ASSERT(iRadiusLast <= 15)
    BB_ASSERT(iRadiusFirst <= iRadiusLast)

    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    WarriorGetEnemyBitsAndScanMask(_rEntity, iEnemyBits, iEnemyScanMask);

    int iFinalHexSurroundCount = SurroundingHexPointsCount(iRadiusLast);
    int iFoundEntity = -1;
    int iFurthestRange = 0;
    for(int i = SurroundingHexPointsCount(iRadiusFirst - 1); i < iFinalHexSurroundCount; ++i) {
        int iHexX = g_sSurroundingHexPoints8[i].X();
        int iHexY = g_sSurroundingHexPoints8[i].Y();
        unsigned int iSearchX = iX + iHexX;
        int iSearchY = iY + iHexY;
        if(CWorldManager::InWorld(iSearchX, iSearchY)) {
            int iEntityId = CWorldManager::MapObjectId(iSearchX, iSearchY);
            if(CWarriorBehavior::WarriorCheckTarget(iEntityId, iEnemyBits, iEnemyScanMask)) {
                auto &rEntity = CMapObjectMgr::Entity(iEntityId);
                int iRange = this->m_sWarriorBehaviorData.m_pProperties->m_iRanges[rEntity.WarriorType()];
                if(iRange > iFurthestRange) {
                    iFoundEntity = iEntityId;
                    iFurthestRange = iRange;
                    if(iRange >= 8)
                        return iFoundEntity;

                    // TODO: constants
                    if(iFurthestRange >= 4 && i + 200 < iFinalHexSurroundCount)
                        iFinalHexSurroundCount = i + 200;
                }
            }
        }
    }
    return iFoundEntity;
}

// address=[0x15ad6a0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckBowman(CWarriorBehavior *this, struct IEntity *a2)
int CWarriorBehavior::WarriorAttackCheckBowman(IMovingEntity &_rEntity) {

    int iAttackCheck15FoundId = CWarriorBehavior::WarriorAttackCheck15(_rEntity);
    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    int iFoundFlyingId = -1;
    int iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;

    int iPlayerBit = CAlliances::PlayerBit(_rEntity.OwnerId());
    for(int i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i) {
        if(CPlayerManager::Race(i) == 3 && (iPlayerBit & CAlliances::PlayerAllyBits(i)) == 0) {
            int iNearestFlyingId = g_cFlyingMgr.GetNearestEntity(i, 1, iX, iY, 0);
            if(iNearestFlyingId) {
                IEntity *pNearestFlying = g_cFlyingMgr[iNearestFlyingId];
                if((pNearestFlying->Flags() & ENTITY_FLAG_READY) != 0) {
                    int iDistance = Grid::Distance(pNearestFlying->X() - iX, pNearestFlying->Y() - iY);
                    if(iDistance < iRadiusLast) {
                        iRadiusLast = iDistance;
                        iFoundFlyingId = iNearestFlyingId;
                    }
                }
            }
        }
    }
    if(iFoundFlyingId == -1)
        return iAttackCheck15FoundId;

    int iTargetRange = 0;
    if(iAttackCheck15FoundId != -1) {
        iTargetRange = this->m_sWarriorBehaviorData.m_pProperties->m_iRanges[g_pMapObjectMgr->Entity(iAttackCheck15FoundId).WarriorType()];
    }
    if(iTargetRange <= 3)
        return iFoundFlyingId;

    return iAttackCheck15FoundId;
}

// address=[0x15ad840]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckMedic(CWarriorBehavior *this, struct IEntity *a2)
int CWarriorBehavior::WarriorAttackCheckMedic(IMovingEntity &_rEntity) {
    int iAllyBits = CAlliances::PlayerAllyBits(_rEntity.OwnerId());
    int iIdx = CWorldManager::Index(_rEntity.X(), _rEntity.Y());
    ISettlerRole &rRole = dynamic_cast<CSettler &>(_rEntity).Role();

    CSoldierRole *pSoldierRole = dynamic_cast<CSoldierRole *>(&rRole);
    if(pSoldierRole && pSoldierRole.GetNumberOfHealings() > 0) {
        for(int i = 1; i < 19; ++i) {
            int iTargetId = CWorldManager::MapObjectId(iIdx + CWorldManager::SurroundingHexPointRelIndex(i));
            if(iTargetId > 0) {
                auto pTargetEntity = CMapObjectMgr::EntityPtr(iTargetId);
                if(pTargetEntity->ObjType() == 1) {
                    int v3 = pTargetEntity->OwnerId();
                    if((iAllyBits & CAlliances::PlayerBit(v3)) != 0) {
                        int v4 = pTargetEntity->Hitpoints();
                        if(v4 < pTargetEntity->MaxHitpoints())
                            return iTargetId;
                    }
                }
            }
        }
    }
    return CWarriorBehavior::WarriorAttackCheck1(_rEntity);
}

// address=[0x015AEBE0]
char __cdecl FindShortestDistanceToBuildingBuilder(int _iX, int _iY, int Number, IEntity *_pBuilding, int *_pShortestDistanceToBuilder, int *_pBuilderPosition) {
    bool bFoundBuilder = 0;
    int iRace = _pBuilding->Race();
    int iType = _pBuilding->Type();
    auto &rBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(iRace, iType);
    int iBuildingX = _pBuilding->X();
    int iBuildingY = _pBuilding->Y();
    int iBuilderNumber = rBuildingInfo.m_iBuilderNumber;
    int iMinDistance = std::abs(Number);
    for(int i = 0; i < iBuilderNumber; ++i) {
        int iBuilderX = rBuildingInfo.m_vBuilder[i].m_iXOffset + iBuildingX;
        int iBuilderY = rBuildingInfo.m_vBuilder[i].m_iYOffset + iBuildingY;
        int iDistanceToBuilder = Grid::DistanceInline(iBuilderX - _iX, iBuilderY - _iY);
        if(!iDistanceToBuilder) {
            *_pShortestDistanceToBuilder = 0;
            *_pBuilderPosition = Y16X16::PackXYFast(iBuilderX, iBuilderY);
            return 1;
        }
        if(iDistanceToBuilder <= iMinDistance) {
            int iFinalDistance = iDistanceToBuilder;
            if(Number < 0) {
                int iBuilderIdx = CWorldManager::Index(iBuilderX, iBuilderY);
                if(CWorldManager::MapObjectId(iBuilderIdx) > 0)
                    iFinalDistance = iDistanceToBuilder + 8;
                for(int j = 0; j < 6; ++j) {
                    int v7 = iBuilderIdx + CWorldManager::NeighborRelIndex(j);
                    if(CWorldManager::MapObjectId(v7) > 0)
                        iFinalDistance += 2;
                }
            }
            if(iFinalDistance < *_pShortestDistanceToBuilder) {
                *_pShortestDistanceToBuilder = iFinalDistance;
                *_pBuilderPosition = Y16X16::PackXYFast(iBuilderX, iBuilderY);
                bFoundBuilder = 1;
            }
        }
    }
    return bFoundBuilder;
}

int __cdecl FindNearestEnemyBuilding(IEntity &_pEntity, unsigned int _iMaxDistance, int a3, bool _bOnlyTowers, int *_pBuilderPosition) {
    int iShortestDistanceToBuilder; // [esp+0h] [ebp-120h] BYREF
    int iBuilderPosition;           // [esp+Ch] [ebp-114h] BYREF

    int iX = _pEntity.X();
    int iY = _pEntity.Y();
    int iOwner = _pEntity.OwnerId();
    CFindEnemyBuildings cFindEnemyBuildings(iX, iY, _iMaxDistance, iOwner, _bOnlyTowers);
    int iBuildingId = 0;
    iShortestDistanceToBuilder = 0x4000;
    iBuilderPosition = 0;
    while(cFindEnemyBuildings.NextBuilding()) {
        class CBuilding *pBuilding = cFindEnemyBuildings.BuildingPtr();
        if(pBuilding->Race() != RACE_DARK) {
            if(FindShortestDistanceToBuildingBuilder(iX, iY, a3, pBuilding, &iShortestDistanceToBuilder, &iBuilderPosition))
                iBuildingId = cFindEnemyBuildings.BuildingId();
        }
    }
    if(_pBuilderPosition)
        *_pBuilderPosition = iBuilderPosition;
    return iBuildingId;
}

// address=[0x15ad980]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckAxeWarrior(CWarriorBehavior *this, struct IEntity *a1)
int CWarriorBehavior::WarriorAttackCheckAxeWarrior(class IMovingEntity &_rEntity) {
    int iNearestEnemyBuilding = FindNearestEnemyBuilding(_rEntity, 0xFu, 2, 1, 0);
    if(iNearestEnemyBuilding <= 0)
        return CWarriorBehavior::WarriorAttackCheck15(_rEntity);
    else
        return iNearestEnemyBuilding;
}

// address=[0x15ad9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)
int CWarriorBehavior::WarriorAttackCheckSaboteur(class IMovingEntity &_rEntity) {
    int v4 = FindNearestEnemyBuilding(_rEntity, 15, 0, 0, 0);
    if(v4 <= 0)
        return -1;
    else
        return v4;
}

// address=[0x15ada00]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScan15(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int CWarriorBehavior::WarriorAttackScan15(IMovingEntity &_rEntity, int *_pPackedXY) {
    int iEnemyBits;        // [esp+0h] [ebp-34h] BYREF
    int iEnemyScanMask;    // [esp+4h] [ebp-30h] BYREF
    int iTargetId;         // [esp+1Ch] [ebp-18h]
    unsigned int iTargetX; // [esp+24h] [ebp-10h]
    int iTargetY;          // [esp+28h] [ebp-Ch]

    int iX = _rEntity.X();
    int iY = _rEntity.Y();

    int iStartRadius = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst + 1;
    int iLastRadius = this->m_sWarriorBehaviorData.m_pProperties->m_iScanRadiusLast;
    BB_ASSERT(iLastRadius <= 15)

    int iStartHexSurroundCount = SurroundingHexPointsCount(iStartRadius - 1);
    int iLastHexSurroundCount = SurroundingHexPointsCount(iLastRadius);
    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iEnemyBits, iEnemyScanMask);
    for(int i = iStartHexSurroundCount;; ++i) {
        if(i >= iLastHexSurroundCount)
            return 0;
        iTargetX = iX + g_sSurroundingHexPoints8[i].X();
        iTargetY = iY + g_sSurroundingHexPoints8[i].Y();
        if(CWorldManager::InWorld(iTargetX, iTargetY)) {
            iTargetId = CWorldManager::MapObjectId(iTargetX, iTargetY);
            if(CWarriorBehavior::WarriorCheckTarget(iTargetId, iEnemyBits, iEnemyScanMask))
                break;
        }
    }
    if(_pPackedXY)
        *_pPackedXY = Y16X16::PackXYFast(iTargetX, iTargetY);
    return iTargetId;
}

// address=[0x15adb50]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanBowman(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int CWarriorBehavior::WarriorAttackScanBowman(IMovingEntity &_rEntity, int *_pPackedXY) {
    int v9 = CWarriorBehavior::WarriorAttackScan15(_rEntity, _pPackedXY);
    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    int iFoundId = -1;
    int iShortestDistance = this->m_sWarriorBehaviorData.m_pProperties->m_iScanRadiusLast;

    int iPlayerBit = CAlliances::PlayerBit(_rEntity.OwnerId());
    for(int i = 1; i <= CPlayerManager::NumberOfPlayers(); ++i) {

        if(CPlayerManager::Race(i) == RACE_DARK && (iPlayerBit & CAlliances::PlayerAllyBits(i)) == 0) {
            int iNearestEntityId = g_cFlyingMgr.GetNearestEntity(i, 1, iX, iY, 0);
            if(iNearestEntityId) {
                IEntity &rFlying = g_cFlyingMgr[iNearestEntityId];
                if((rFlying.Flags() & ENTITY_FLAG_READY) != 0) {
                    int iDistance = Grid::Distance(rFlying.X() - iX, rFlying.Y() - iY);
                    if(iDistance < iShortestDistance) {
                        iShortestDistance = iDistance;
                        iFoundId = iNearestEntityId;
                        *_pPackedXY = Y16X16::PackXYFast(rFlying.X(), rFlying.Y());
                    }
                }
            }
        }
    }
    if(iFoundId != -1)
        return iFoundId;
    return v9;
}

// address=[0x15adcd0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanMedic(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int CWarriorBehavior::WarriorAttackScanMedic(IMovingEntity &_rEntity, int *_pPackedXY) {
    int iEnemyBits;        // [esp+4h] [ebp-40h] BYREF
    int iEnemyScanMask;    // [esp+8h] [ebp-3Ch] BYREF
    unsigned int iTargetX; // [esp+30h] [ebp-14h]
    int iTargetY;          // [esp+34h] [ebp-10h]
    int iTargetId;         // [esp+3Ch] [ebp-8h]

    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    int iAllyBits = CAlliances::PlayerAllyBits(_rEntity.OwnerId());
    int iInitialRadius = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst + 1;
    int iScanRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iScanRadiusLast;
    BB_ASSERT(iScanRadiusLast <= 15);

    int iInitialHexSurrounding = SurroundingHexPointsCount(iInitialRadius - 1);
    int iLastHexSurrounding = SurroundingHexPointsCount(iScanRadiusLast);

    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iEnemyBits, iEnemyScanMask);

    CSoldierRole *pSoldierRole = dynamic_cast<CSoldierRole *>(&dynamic_cast<CSettler &>(_rEntity).Role());
    for(int i = iInitialHexSurrounding;; ++i) {
        if(i >= iLastHexSurrounding)
            return 0;

        iTargetX = iX + g_sSurroundingHexPoints8[i].X();
        iTargetY = iY + g_sSurroundingHexPoints8[i].Y();
        if(CWorldManager::InWorld(iTargetX, iTargetY)) {
            iTargetId = CWorldManager::MapObjectId(iTargetX, iTargetY);
            if(iTargetId > 0 && (CWarriorBehavior::WarriorCheckTarget(iTargetId, iEnemyBits, iEnemyScanMask) || pSoldierRole && pSoldierRole->GetNumberOfHealings() > 0 && MedicCanHeal(iAllyBits, iTargetId))) {
                break;
            }
        }
    }
    if(_pPackedXY)
        *_pPackedXY = Y16X16::PackXYFast(iTargetX, iTargetY);
    return iTargetId;
}

// address=[0x15ade90]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanAxeWarrior(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int CWarriorBehavior::WarriorAttackScanAxeWarrior(IMovingEntity &_rEntity, int *_pBuilderXY) {
    int NearestEnemyBuilding = FindNearestEnemyBuilding(_rEntity, 0x15u, 8, 1, _pBuilderXY);
    if(NearestEnemyBuilding <= 0)
        return CWarriorBehavior::WarriorAttackScan15(_rEntity, _pBuilderXY);
    else
        return NearestEnemyBuilding;
}

// address=[0x15adee0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackScanSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2, int *a3)
int CWarriorBehavior::WarriorAttackScanSaboteur(IMovingEntity &_rEntity, int *_pBuilderXY) {
    return FindNearestEnemyBuilding(_rEntity, 0x15u, -12, 0, _pBuilderXY);
}

// address=[0x15adf10]
// Decompiled from int __thiscall CWarriorBehavior::WarriorEvadeScan15a(CWarriorBehavior *this, struct IEntity *a2, int *a3)
int CWarriorBehavior::WarriorEvadeScan15a(IMovingEntity &_rEntity, int *_pPackedXY) {
    int iSpiralX;   // [esp+18h] [ebp-40h] BYREF
    int iSpiralY;   // [esp+1Ch] [ebp-3Ch] BYREF
                    // [esp+20h] [ebp-38h]
    int iEnemyBits; // [esp+24h] [ebp-34h] BYREF
    int iScanMask;  // [esp+28h] [ebp-30h] BYREF
                    // [esp+2Ch] [ebp-2Ch]
                    // [esp+30h] [ebp-28h]
    int v15;        // [esp+34h] [ebp-24h]
                    // [esp+38h] [ebp-20h]
    // [esp+3Ch] [ebp-1Ch]
    // [esp+40h] [ebp-18h]
    // [esp+48h] [ebp-10h]
    // [esp+4Ch] [ebp-Ch]
    // [esp+50h] [ebp-8h]
    int i; // [esp+54h] [ebp-4h]

    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    int iScanRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusFirst - 1;
    BB_ASSERT(iScanRadiusLast >= 1)

    int v14 = SurroundingHexPointsCount(0);
    int v13 = SurroundingHexPointsCount(iScanRadiusLast);
    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_rEntity, iEnemyBits, iScanMask);
    for(i = v14;; ++i) {
        if(i >= v13)
            return 0;
        int iTargetX = iX + g_sSurroundingHexPoints8[i].X();
        int iTargetY = iY + g_sSurroundingHexPoints8[i].Y();
        if(CWorldManager::InWorld(iTargetX, iTargetY)) {
            v15 = CWorldManager::MapObjectId(iTargetX, iTargetY);
            if(CWarriorBehavior::WarriorCheckTarget(v15, iEnemyBits, iScanMask))
                break;
        }
    }
    int iSectorId = CWorldManager::SectorId(iX, iY);
    int uPadding = g_sSurroundingHexPoints8[i].m_uPadding;
    DWORD uIdx = (uPadding + g_pGame->Rand() % 3 + 2) % 6;

    CSectorSpiralWalk cSpiralWalk(
        iX + 6 * g_sNeighborPoints[uIdx].x,
        iY + 6 * g_sNeighborPoints[uIdx].y,
        4,
        iSectorId);
    if(!cSpiralWalk.NextXY(&iSpiralX, &iSpiralY))
        return 0;
    if(_pPackedXY)
        *_pPackedXY = Y16X16::PackXYFast(iSpiralX, iSpiralY);
    return v15;
}

// address=[0x15ae0f0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleAttackScan31(  CWarriorBehavior *this,  struct IMovingEntity *_pEntity,  struct CWarriorBehavior::SWarriorScanResult *a3)
void CWarriorBehavior::WarriorVehicleAttackScan31(IMovingEntity &_pEntity, CWarriorBehavior::SWarriorScanResult &_rResult) {
    CWarMapNode *pNode;         // eax
    CWarMapNode *pNodeIter;     // eax
    CWarriorProperties *rProps; // eax
    int iEnemyBits;             // [esp+44h] [ebp-140h] BYREF
    int iEnemyScanMask;         // [esp+48h] [ebp-13Ch] BYREF
    __int64 v24;                // [esp+50h] [ebp-134h]
    int v25;                    // [esp+58h] [ebp-12Ch]

    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(_pEntity, iEnemyBits, iEnemyScanMask);
    int iRadiusLast = this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast;
    int iX = _pEntity.X();
    int iY = _pEntity.Y();
    CVWList cVWList(iX, iY, 31u);
    CTmpEntitiesRef v23{};
    int iFoundEntityId = 0;
    int v42 = 0;
    int iFoundDistance = 0x4000;
    int v27 = 0x4000;
    for(int i = 0; i < cVWList.Size(); ++i) {

        for(int j = CWarMap::FirstEntityIdVW(1, cVWList[i].m_iV, cVWList[i].m_iW); j; j = pNode->Next()) {
            IEntity &rTarget = v23[j];
            if(CWarriorBehavior::WarriorCheckTarget(rTarget, iEnemyBits, iEnemyScanMask)) {
                int v40 = Grid::Distance(rTarget.X() - iX, rTarget.Y() - iY);
                int iRange = this->m_sWarriorBehaviorData.m_pProperties->m_iRanges[rTarget.WarriorType()];
                if(iRange >= 4 && v40 < v27)
                    v27 = v40;
                if(v40 > iRadiusLast)
                    v25 = 0;
                else
                    v25 = 10;
                if(v25 + iRange > v42 && v40 < iFoundDistance) {
                    iFoundEntityId = j;
                    v42 = v25 + iRange;
                    iFoundDistance = v40;
                }
            }
            pNode = rTarget.WarMapNode();
        }
    }
    int v19 = CWarriorBehavior::WarriorProperties().m_iRanges[AI_WARRIOR_TYPE_TOWER_BUILDING];
    if(v42 < v19 + 10) {
        int iClosestEntityId = 0;
        int iShortestDistance = 0x4000;
        for(int k = 0; k < cVWList.Size(); ++k) {
            for(int iEntityIdIter = CWarMap::FirstEntityIdVW(2, cVWList[k].m_iV, cVWList[k].m_iW);
                iEntityIdIter;
                iEntityIdIter = pNodeIter->Next()) {
                IEntity &rFoundEntity = v23[iEntityIdIter];
                if(CWarriorBehavior::WarriorCheckTarget(rFoundEntity, iEnemyBits, iEnemyScanMask)) {
                    int v9 = rFoundEntity.X();
                    int v10 = rFoundEntity.Y();
                    int iDistance = Grid::Distance(v9 - iX, v10 - iY);
                    if(iDistance < iShortestDistance) {
                        iClosestEntityId = iEntityIdIter;
                        iShortestDistance = iDistance;
                    }
                }
                pNodeIter = rFoundEntity.WarMapNode();
            }
        }
        if(iClosestEntityId > 0) {
            int v18 = iShortestDistance > CWarriorBehavior::WarriorProperties().m_iRadiusLast ? 0 : 10;
            if(v18 + v19 > v42) {
                iFoundEntityId = iClosestEntityId;
                v42 = v18 + v19;
                iFoundDistance = iShortestDistance;
            }
        }
    }
    _rResult.m_iEntityId = iFoundEntityId;
    _rResult.m_iOtherDistance = v42;
    _rResult.m_iDistance = iFoundDistance;
    _rResult.dwordC = v27;
}

// address=[0x15ae660]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleIdleWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void CWarriorBehavior::WarriorVehicleIdleWalkOneStep(IMovingEntity &a2) {
    this->WarriorTaskIdleWalk(a2);
}

// address=[0x15ae680]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleMoveWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void CWarriorBehavior::WarriorVehicleMoveWalkOneStep(IMovingEntity &a2) {
    if((this->m_sWarriorBehaviorData.m_iU01 & 1) != 0) {
        this->m_sWarriorBehaviorData.m_iU01 &= ~1u;
        int v2 = CWarriorBehavior::WarriorDestinationXY();
        CWarriorBehavior::WarriorInitWalk(a2, v2);
    }
    if((this->WarriorTaskWalkOneStep(a2) & 0x70) != 0)
        this->m_sWarriorBehaviorData.m_uState = 8;
}

// address=[0x15ae6f0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleEscortWalkOneStep(CWarriorBehavior *this, struct IMovingEntity *a2)
void CWarriorBehavior::WarriorVehicleEscortWalkOneStep(IMovingEntity &_rEntity) {
    int iDestId = CWarriorBehavior::WarriorDestinationId();
    auto &rDestEntity = CMapObjectMgr::Entity(iDestId);
    if(iDestId > 0 && (rDestEntity.Flags() & ENTITY_FLAG_READY) != 0) {
        int iDestXY = rDestEntity.PackedXY();
        // rDestEntity.WarriorType(); // NOTE: huh?
        int iXY = _rEntity.PackedXY();
        if(Y16X16::DistanceFast(iDestXY, iXY) <= 9) {
            this->WarriorTaskIdleWalk(_rEntity);
        } else {
            CWarriorBehavior::WarriorPseudoInitWalk(_rEntity, iDestXY);
            this->WarriorTaskWalkOneStep(_rEntity);
        }
    } else {
        this->WarriorTaskFinished(_rEntity);
    }
}

// address=[0x15ae7b0]
// Decompiled from bool __thiscall CWarriorBehavior::IsValidTarget(CWarriorBehavior *this, struct IEntity *a2, struct IEntity *a3)
bool CWarriorBehavior::IsValidTarget(IMovingEntity const &a2, IEntity const &a3) {
    int iBits;     // [esp+0h] [ebp-Ch] BYREF
    int iScanMask; // [esp+4h] [ebp-8h] BYREF
    CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(a2, iBits, iScanMask);
    return CWarriorBehavior::WarriorCheckTarget(a3, iBits, iScanMask);
}

// address=[0x15ae7f0]
// Decompiled from BOOL __thiscall CWarriorBehavior::IsTargetInAtackRange(  CWarriorBehavior *this,  struct IMovingEntity *_rEntity,  struct IEntity *_rTarget)
bool CWarriorBehavior::IsTargetInAtackRange(IMovingEntity const &_rEntity, IEntity const &_rTarget) {
    int iDistance = Grid::Distance(_rTarget.X() - _rEntity.X(), _rTarget.Y() - _rEntity.Y());
    int iRadiusFirst = CWarriorBehavior::WarriorProperties().m_iRadiusFirst;
    int iRadiusLast = CWarriorBehavior::WarriorProperties().m_iRadiusLast;
    return iDistance <= (_rTarget.ObjType() == CATAPULT_OBJ) + iRadiusLast && iDistance >= iRadiusFirst;
}

// address=[0x15ae8c0]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckInflu1(CWarriorBehavior *this, IEntity *_rEntity)
bool CWarriorBehavior::WarriorCheckInflu1(IMovingEntity &_rEntity) {
    return CInfluMap::EnemyValueXY(_rEntity.X(), _rEntity.Y(), CAlliances::AllianceId(_rEntity.OwnerId())) > 0;
}

// address=[0x15ae930]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorCheckOwner9(CWarriorBehavior *this, IEntity *_rEntity)
bool CWarriorBehavior::WarriorCheckOwner9(IMovingEntity &_rEntity) {
    int iEnemyBits = CAlliances::PlayerEnemyBits(_rEntity.OwnerId());
    return (iEnemyBits & COwnerMap::OwnerBits9XY(_rEntity.X(), _rEntity.Y())) != 0;
}

// address=[0x15ae9a0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorCheckMedic(CWarriorBehavior *this, struct IMovingEntity *a2)
bool CWarriorBehavior::WarriorCheckMedic(IMovingEntity &a2) {

    return 1;
}

// address=[0x15ae9b0]
// Decompiled from char __thiscall CWarriorBehavior::WarriorCheckSaboteur(CWarriorBehavior *this, struct IMovingEntity *a2)
bool CWarriorBehavior::WarriorCheckSaboteur(IMovingEntity &a2) {

    return 1;
}

// address=[0x15afe80]
// Decompiled from void __thiscall CWarriorBehavior::WarriorVehicleAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void CWarriorBehavior::WarriorVehicleAttackTarget(IMovingEntity &a2, int a3) {

    this->m_sWarriorBehaviorData.m_iU01 |= 1u;
    CWarriorBehavior::WarriorAttackTarget(a2, a3);
}

// address=[0x153fdd0]
// Decompiled from CWarriorBehavior::SWarriorBehaviorData *__thiscall CWarriorBehavior::GetWarriorBehaviorData(CWarriorBehavior *this)
CWarriorBehavior::SWarriorBehaviorData &CWarriorBehavior::GetWarriorBehaviorData(void) {
    return this->m_sWarriorBehaviorData;
}

// address=[0x15ae9c0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorPseudoInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
int CWarriorBehavior::WarriorPseudoInitWalk(IMovingEntity &_rEntity, int _iTargetXY) {

    int v3; // eax
    int v5;

    int iX = _rEntity.X();
    int iY = _rEntity.Y();
    int iDestinationXY = CWarriorBehavior::WarriorWalkDestinationXY(_rEntity);
    int iTargetX = Y16X16::UnpackXFast(_iTargetXY);
    int iTargetY = Y16X16::UnpackYFast(_iTargetXY);
    int iDistance = Grid::Distance(iTargetX - iX, iTargetY - iY);
    if(iDestinationXY < 0 || iDistance <= 4 || (v5 = iTargetY - Y16X16::UnpackYFast(iDestinationXY), v3 = Y16X16::UnpackXFast(iDestinationXY), Grid::Distance(iTargetX - v3, v5) > 2)) {
        CWarriorBehavior::WarriorInitWalk(_rEntity, _iTargetXY);
    }
    return iDistance;
}

// address=[0x15aea80]
// Decompiled from int __thiscall CWarriorBehavior::FindAttackWayPoint(CWarriorBehavior *this, IEntity *a2, struct IEntity *a3)
int CWarriorBehavior::FindAttackWayPoint(IMovingEntity &_rEntity, IEntity &_rWaypointEntity) {
    int iLastSpiralOffset = CSpiralOffsets::Last(this->m_sWarriorBehaviorData.m_pProperties->m_iRadiusLast);
    for(int i = 0; i <= iLastSpiralOffset; ++i) {
        unsigned int iX = CSpiralOffsets::DeltaX(i) + _rWaypointEntity.X();
        unsigned int iY = CSpiralOffsets::DeltaY(i) + _rWaypointEntity.Y();
        if(CWorldManager::InWorld(iX, iY)) {
            if(g_cVehicleMgr.IsPositionFreeForVehicle(iX, iY, _rEntity.Type()))
                return Y16X16::PackXYFast(iX, iY);
        }
    }
    return 0;
}

// address=[0x15afa60]
// Decompiled from int __thiscall CWarriorBehavior::WarriorAttackCheck(CWarriorBehavior *this, struct IMovingEntity *a2)
int CWarriorBehavior::WarriorAttackCheck(IMovingEntity &a2) {

    return (this->*m_sWarriorBehaviorData.m_pProperties->m_fpAttackCheck)(a2);
}

// address=[0x15afa90]
// Decompiled from void __thiscall CWarriorBehavior::WarriorAttackTarget(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void CWarriorBehavior::WarriorAttackTarget(IMovingEntity &_rEntity, int a3) {
    this->WarriorTaskAttack(_rEntity, a3, static_cast<T_WARRIOR_ATTACK>(this->m_sWarriorBehaviorData.m_pProperties->m_iAttackType));
}

// address=[0x15afad0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(struct IEntity *_rEntity, int _iPlayer, int a3)
bool __cdecl CWarriorBehavior::WarriorCheckTarget(IEntity const &_rEntity, int _iPlayer, int a3) {
    char v3 = _rEntity.OwnerId();
    return (_iPlayer & CAlliances::PlayerBit(v3)) != 0 && CWarriorBehavior::WarriorTargetAllowableAndVulnerable(_rEntity, a3);
}

// address=[0x15afb20]1
// Decompiled from bool __cdecl CWarriorBehavior::WarriorCheckTarget(int a1, int a2, int a3)
bool __cdecl CWarriorBehavior::WarriorCheckTarget(int a1, int a2, int a3) {
    if(!a1)
        return 0;
    IEntity &v4 = CMapObjectMgr::Entity(a1);
    return CWarriorBehavior::WarriorCheckTarget(v4, a2, a3);
}

// address=[0x15afb70]
// Decompiled from int __thiscall CWarriorBehavior::WarriorDestinationId(CWarriorBehavior *this)
int CWarriorBehavior::WarriorDestinationId(void) const {

    return this->m_sWarriorBehaviorData.m_iDestinationXYOrId;
}

// address=[0x15afb90]
// Decompiled from void __thiscall CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(  CWarriorBehavior *this,  struct IEntity *a2,  int *_rBits,  int *_rScanMask)
void CWarriorBehavior::WarriorGetEnemyBitsAndScanMask(IEntity const &_rEntity, int &_rBits, int &_rScanMask) {
    _rBits = CAlliances::PlayerEnemyBits(_rEntity.OwnerId());
    _rScanMask = this->m_sWarriorBehaviorData.m_pProperties->m_uScanMask;
    BB_ASSERT((_rScanMask & ENTITY_FLAG_READY) != 0)
}

// address=[0x15afc10]
// Decompiled from void __thiscall CWarriorBehavior::WarriorInitWalk(CWarriorBehavior *this, struct IMovingEntity *a2, int a3)
void CWarriorBehavior::WarriorInitWalk(IMovingEntity &a2, int a3) {
    int v3 = this->m_sWarriorBehaviorData.m_iFlags & 0x1060 | 0x2000;
    CWalking *v4 = a2.Walking();
    v4->Init(a3, v3);
}

// address=[0x15afc70]
// Decompiled from bool __thiscall CWarriorBehavior::WarriorIsFullUpdate(CWarriorBehavior *this, unsigned int a2)
bool CWarriorBehavior::WarriorIsFullUpdate(unsigned int a2) const {

    return a2 >= this->m_sWarriorBehaviorData.m_iNextFullUpdate;
}

// address=[0x15afcb0]
// Decompiled from CWarriorProperties *__thiscall CWarriorBehavior::WarriorProperties(CWarriorBehavior *this)
CWarriorProperties const &CWarriorBehavior::WarriorProperties(void) const {
    return *this->m_sWarriorBehaviorData.m_pProperties;
}

// address=[0x15afcd0]
// Decompiled from void __thiscall CWarriorBehavior::WarriorSetNextFullUpdate(CWarriorBehavior *this, unsigned int a2, unsigned int a3)
void CWarriorBehavior::WarriorSetNextFullUpdate(unsigned int a2, unsigned int a3) {

    this->m_sWarriorBehaviorData.m_iNextFullUpdate = a3 + a2;
}

// address=[0x15afcf0]
// Decompiled from bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(IEntity *_rTarget, int a2)
bool __cdecl CWarriorBehavior::WarriorTargetAllowableAndVulnerable(IEntity const &_rTarget, int a2) {

    // [esp+4h] [ebp-18h]
    // [esp+8h] [ebp-14h]
    // [esp+10h] [ebp-Ch]
    // [esp+1Bh] [ebp-1h]

    bool bResult = 0;
    if(_rTarget.Type() == 1 && _rTarget.ObjType() == DECO_OBJ)
        return (_rTarget.Flags() & 0x2000000) != 0;
    int v4 = _rTarget.Flags() & 0x2030100 ^ 0x2030100;
    int v3 = 1 << _rTarget.WarriorType();
    if((_rTarget.WarriorType() || _rTarget.ObjType() == SETTLER_OBJ) && (_rTarget.Flags() & 0x8000000) == 0) {
        bResult = (a2 & (v3 | v4)) == 0;
    }
    if(!bResult)
        return bResult;

    BB_ASSERT(!bResult || ((_rTarget.FlagBits(ENTITY_FLAG_READY) != 0) && ((_rTarget.FlagBits(ENTITY_FLAG_VULNERABLE_MASK) != 0) ^ (_rTarget.WarriorType() == AI_WARRIOR_TYPE_NONE))))
    return bResult;
}

// address=[0x15afec0]
// Decompiled from int __thiscall CWarriorBehavior::WarriorWalkDestinationXY(CWarriorBehavior *this, struct IMovingEntity *_rEntity)
int CWarriorBehavior::WarriorWalkDestinationXY(IMovingEntity &_rEntity) {
    CWalking *pWalking = _rEntity.Walking();
    return pWalking->DestinationXY();
}
