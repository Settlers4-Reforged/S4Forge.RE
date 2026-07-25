#include "ISettlerRole.h"

#include <iostream>

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CFleeRole.h"
#include "CSettler.h"
#include "CSettlerMgr.h"
#include "Defines/AI.h"
#include "Defines/Object.h"
#include "Defines/Settlers.h"
#include "Defines/Tasks.h"
#include "Defines/World.h"
#include "Main/CGameStateHandler.h"
#include "MapObjects/CEntityTask.h"
#include "MapObjects/CEntityToDoListMgr.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/CSpiralOffsets.h"
#include "MapObjects/IAnimatedEntity.h"
#include "MapObjects/Pile/CPile.h"
#include "MapObjects/Pile/CPileMgr.h"
#include "Pathing/CWalking.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class ISettlerRole

class CBuilding;
class CEcoSector;

// address=[0x1351b50]
// Decompiled from int __thiscall ISettlerRole::GetTask(ISettlerRole *this)
int ISettlerRole::GetTask(void) const {
    return this->m_iTask;
}

// address=[0x1563710]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::~ISettlerRole(ISettlerRole *this)
ISettlerRole::~ISettlerRole(void) = default;

// address=[0x15637d0]
// Decompiled from void *__thiscall ISettlerRole::ClearGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int ISettlerRole::ClearGroupFlagBits(int a2) {
    return 0;
}

// address=[0x15637f0]
// Decompiled from int __thiscall ISettlerRole::Decrease(ISettlerRole *this, int a2)
int ISettlerRole::Decrease(int a2) {
    return a2;
}

// address=[0x1563810]
// Decompiled from int __thiscall ISettlerRole::GetGroupFlags(ISettlerRole *this)
int ISettlerRole::GetGroupFlags(void) const {
    return 0;
}

// address=[0x1563840]
// Decompiled from int __thiscall ISettlerRole::GetWarriorBehavior(ISettlerRole *this)
class CWarriorBehavior *ISettlerRole::GetWarriorBehavior(void) {
    return 0;
}

// address=[0x1563850]
// Decompiled from int __thiscall ISettlerRole::HomeEntityId(ISettlerRole *this)
int ISettlerRole::HomeEntityId(void) const {
    return this->m_uHomeEntityId;
}

// address=[0x1563930]
// Decompiled from char __thiscall ISettlerRole::IsUnEmployed(ISettlerRole *this)
bool ISettlerRole::IsUnEmployed(void) const {
    return 0;
}

// address=[0x1563940]
// Decompiled from void __thiscall ISettlerRole::SetBuilding(ISettlerRole *this, WORD a2)
void ISettlerRole::SetBuilding(int a2) {
    this->m_uHomeEntityId = a2;
}

// address=[0x15639a0]
// Decompiled from void __thiscall ISettlerRole::SetEntity(ISettlerRole *this, WORD a2)
void ISettlerRole::SetEntity(int a2) {
    this->m_uEntityId = a2;
}

// address=[0x15639e0]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlagBits(std::_Ref_count_base *this, const struct type_info *a2)
int ISettlerRole::SetGroupFlagBits(int a2) {
    return 0;
}

// address=[0x1563a00]
// Decompiled from void *__thiscall ISettlerRole::SetGroupFlags(std::_Ref_count_base *this, const struct type_info *a2)
int ISettlerRole::SetGroupFlags(int a2) {
    return 0;
}

// address=[0x1563a20]
// Decompiled from void __thiscall ISettlerRole::UpdateJob(ISettlerRole *this, struct CSettler *a2)
void ISettlerRole::UpdateJob(class CSettler *a2) {
}

// address=[0x15671a0]
// Decompiled from int __thiscall ISettlerRole::SourcePileId(ISettlerRole *this)
int ISettlerRole::SourcePileId(void) const {
    return this->m_uSourcePileId;
}

// address=[0x15897e0]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::ISettlerRole(ISettlerRole *this)
ISettlerRole::ISettlerRole(void) : CPersistence() {
    this->m_iTask = 0;
    this->m_uSettlerWalk = 0;
    this->m_iWalkspeed = 1;
    this->m_uCycleFrames = 1;
    this->m_uTick = 0;
    this->m_bForward = 1;
    this->unk_0B = 0;
    this->m_uToDoCount = 0;
    this->m_iDestinationOffsetX = 0;
    this->m_iDestinationOffsetY = 0;
    this->m_uAttachedSettlerId = 0;
    this->m_uSourcePileId = 0;
    this->m_iDestinationPosition = 0;
    this->m_iStartPosition = 0;
    this->m_uHomeEntityId = 0;
    this->m_uEntityId = 0;
    this->m_fOffsetX = 0.0;
    this->m_fOffsetY = 0.0;
}

// address=[0x15898a0]
// Decompiled from void __thiscall ISettlerRole::Go(ISettlerRole *this, CSettler *settler)
void ISettlerRole::Go(CSettler *_pSettler) {
    this->m_uSettlerWalk = _pSettler->Walk();
    if((this->m_uSettlerWalk & 0x20) != 0) {
        this->GetNextJob(_pSettler);
    } else if((this->m_uSettlerWalk & 0x40) != 0) {
        this->SetFree(_pSettler, -1);
    } else if((this->m_uSettlerWalk & 0xFu) >= 6) {
        _pSettler->RegisterForLogicUpdate(1);
    } else {
        _pSettler->m_iDistance = -1;
        this->m_iWalkspeed = 9;
        if(_pSettler->Type() == SETTLER_CARRIER || _pSettler->Type() == SETTLER_DONKEY) {
            int iMoveCost = CWorldManager::MoveCostsBits(CWorldManager::Index(_pSettler->PackedXY()));
            if(iMoveCost == 1) {
                this->m_iWalkspeed = 8;
            } else if(!iMoveCost) {
                this->m_iWalkspeed = 7;
            }
        }
        _pSettler->RegisterForLogicUpdate(this->m_iWalkspeed);
    }
}

// address=[0x15899a0]
// Decompiled from void __thiscall ISettlerRole::LogicUpdate(ISettlerRole *this, struct CSettler *pSettler)
void ISettlerRole::LogicUpdate(class CSettler *_pSettler) {

    if(this->m_iTask != WAIT) {
        this->LogicUpdateJob(_pSettler);
        return;
    }

    _pSettler->m_iDistance = 0;
    this->m_uCycleFrames = 1;

    _pSettler->m_pWalking->Init(-1, 0);
    this->m_uSettlerWalk = _pSettler->WalkDir(_pSettler->m_pWalking->Walk(_pSettler->m_uPackedXY));
    if((this->m_uSettlerWalk & 0xFu) >= 6) {
        _pSettler->m_iFrame = 0;
        _pSettler->RegisterForLogicUpdate(g_pGame->Rand() % 4 + 1);
    } else {
        this->m_uCycleFrames = _pSettler->m_cCurrentToDoItemIter->m_iFrameCount;
        BB_ASSERT(m_uCycleFrames > 0)

        int iCycleFramesEx = this->m_uCycleFrames > 1u ? this->m_uCycleFrames - 1 : 1;
        BB_ASSERT(iCycleFramesEx > 0)

        _pSettler->m_iFrame = 0;
        _pSettler->m_iDistance = -1;
        _pSettler->RegisterForLogicUpdate(iCycleFramesEx);
    }
}

// address=[0x1589b30]
// Decompiled from void __thiscall ISettlerRole::Update(ISettlerRole *this, CSettler *_pSettler)
void ISettlerRole::Update(class CSettler *_pSettler) {
    int m_iRandom;         // esi
    T_AI_WARRIOR_TYPE v10; // [esp+Ch] [ebp-20h]

    SJobSoundInfo sJobSoundInfo{};
    __int16 TickCounter = g_pGame->GetTickCounter();
    this->m_uTick = TickCounter - _pSettler->LastUpdateTick();
    if(this->m_uTick) {
        DWORD v3 = g_pGame->GetTickCounter();
        _pSettler->SetLastUpdateTick(v3);
        int v16 = this->m_iTask - 1;
        switch(v16) {
        case 0:
        case 2:
        case 12:
        case 15:
        case 24:
        case 27:
        case 28:
        case 29:
        case 30:
            if(this->m_bForward) {
                _pSettler->m_iFrame = (this->m_uTick + _pSettler->Frame()) % this->m_uCycleFrames;
            } else {
                unsigned int m_uCycleFrames = this->m_uCycleFrames;
                unsigned int m_iFrame = _pSettler->m_iFrame;
                unsigned int v14 = this->m_uTick % m_uCycleFrames;
                if(m_iFrame < v14)
                    _pSettler->m_iFrame = (m_uCycleFrames + m_iFrame - v14) % this->m_uCycleFrames;
                else
                    _pSettler->m_iFrame = m_iFrame - v14;
            }

            CEntityToDoListMgr::GetJobSoundInfo(_pSettler->m_iJobPart, sJobSoundInfo);
            if(sJobSoundInfo.m_iId > 0 && sJobSoundInfo.m_iFrame == _pSettler->m_iFrame) {
                if(sJobSoundInfo.m_iRandom == 100 || (m_iRandom = sJobSoundInfo.m_iRandom, m_iRandom >= rand() % 100)) {
                    if(g_pFogging->IsPositionVisible(_pSettler->X(), _pSettler->Y())) {
                        g_pSoundManager->PlayEnvironmentSound(sJobSoundInfo.m_iId, _pSettler->X(), _pSettler->Y(), 0);
                    }
                }
            }

            if(((1 << _pSettler->WarriorType()) & 0x3C) != 0)
                g_pLogic->SetWarAction();
            break;
        case 5:
            if((this->m_uSettlerWalk & 8) != 0) {
                _pSettler->m_iFrame = 0;
            } else {
                _pSettler->m_iFrame = (this->m_uTick + _pSettler->m_iFrame) % this->m_uCycleFrames;
                if(!_pSettler->m_iFrame)
                    _pSettler->m_iFrame = 1;
                _pSettler->DecDistance((this->m_uTick << 8) / this->m_iWalkspeed);
            }
            break;
        case 16:
            if((this->m_uSettlerWalk & 8) != 0) {
                _pSettler->m_iFrame = 0;
            } else {
                int v13;
                _pSettler->m_iFrame = (this->m_uTick + _pSettler->m_iFrame) % this->m_uCycleFrames;
                if(!_pSettler->m_iFrame)
                    _pSettler->m_iFrame = 1;
                if(this->m_uCycleFrames > 1u)
                    v13 = this->m_uCycleFrames - 1;
                else
                    v13 = 1;
                int v11 = v13;
                _pSettler->DecDistance((this->m_uTick << 8) / v13);
            }
            break;
        default:
            this->UpdateJob(_pSettler);
            break;
        }
    }
}

// address=[0x1589e30]
// Decompiled from void __thiscall ISettlerRole::NewDestination(ISettlerRole *this, IEntity *a2, DWORD a3, int a4)
void ISettlerRole::NewDestination(class CSettler *_pSettler, int _iXY, int a4) {
    this->m_iStartPosition = _pSettler->PackedXY();
    this->m_iDestinationPosition = _iXY;
}

// address=[0x1589e60]
// Decompiled from int __thiscall ISettlerRole::NewDestination(ISettlerRole *this, struct CSettler *a2, int a3, int a4, int a5)
void ISettlerRole::NewDestination(class CSettler *_pSettler, int _iX, int _iY, int a5) {
    this->m_iStartPosition = _pSettler->PackedXY();
    this->m_iDestinationPosition = Y16X16::PackXYFast(_iX, _iY);
}

// address=[0x1589ea0]
// Decompiled from char __thiscall ISettlerRole::SearchPosition(int this, _DWORD *a2, int a3)
bool ISettlerRole::SearchPosition(class CSettler *_pSettler, int _iSearchIndex) {
    CSettlerMgr::SSettlerInfos *v6; // eax
    CSettlerMgr::SSettlerInfos *v8; // eax

    int iIterations = 0;
    int iX = _pSettler->X();
    int iY = _pSettler->Y();

    const auto &rInfo = CSettlerMgr::GetSettlerInfo(_pSettler->Race(), _pSettler->Type());
    int iOffsetX = rInfo.m_vSearches[_iSearchIndex].m_iOffsetX;
    int iOffsetY = rInfo.m_vSearches[_iSearchIndex].m_iOffsetY;
    auto pSearchFkt = rInfo.m_vSearches[_iSearchIndex].m_pSearchFkt;
    BB_ASSERT(pSearchFkt != nullptr);

    while(iIterations < 500) {
        unsigned int iSearchX = iX + CSpiralOffsets::DeltaX(iIterations);
        unsigned int iSearchY = iY + CSpiralOffsets::DeltaY(iIterations);
        if(CWorldManager::InWorld(iSearchX, iSearchY)) {
            int iFound = pSearchFkt(iSearchX, iSearchY, 0);
            if(iFound > 0) {
                this->m_iDestinationPosition = Y16X16::PackXYFast(iOffsetX + iSearchX, iOffsetY + iSearchY);
                this->m_uEntityId = iFound;
                return true;
            }
            if(iFound < 0) {
                this->m_iDestinationPosition = Y16X16::PackXYFast(iOffsetX + iSearchX, iOffsetY + iSearchY);
                this->m_uEntityId = 0;
                return true;
            }
        }
        ++iIterations;
    }

    return false;
}

// address=[0x158a0a0]
// Decompiled from char __thiscall ISettlerRole::ESChanged(ISettlerRole *this, struct CSettler *a2)
bool ISettlerRole::ESChanged(class CSettler *_pSettler) {
    ISettlerRole *pDbgOrgThis = this;
    ISettlerRole *pDbgOrgRole = &_pSettler->Role();

    BB_ASSERT(pDbgOrgThis == pDbgOrgRole)

    BB_ASSERT(pDbgOrgThis->GetSettlerRole() != FLEE_ROLE)

    bool bFreed = this->SetFree(_pSettler, -1);
    ISettlerRole *pDbgRoleAfterFree = &_pSettler->Role();
    if(bFreed) {
        BB_ASSERT(pDbgRoleAfterFree != pDbgOrgThis)

        BB_ASSERT(pDbgRoleAfterFree->GetSettlerRole() == FLEE_ROLE)
    } else {
        BB_ASSERT(pDbgRoleAfterFree == pDbgOrgThis)

        CEcoSector *pEcoSector = g_cESMgr.EntryPtr(CWorldManager::EcoSectorId(_pSettler->X(), _pSettler->Y()));
        if(pEcoSector) {
            if(pEcoSector->Owner() == _pSettler->OwnerId()) {
                pEcoSector->ChangeNrOfSettler(_pSettler->Type(), 1);
            }
        }
    }
    return 0;
}

// address=[0x158a230]
// Decompiled from char __thiscall ISettlerRole::SetFree(ISettlerRole *this, CSettler *settler, int a3)
bool ISettlerRole::SetFree(class CSettler *_pSettler, int a3) {
    ISettlerRole::DetachFromPile(_pSettler, OBSERVER_TARGET_SECONDARY, 0);
    ISettlerRole::DetachFromPile(_pSettler, OBSERVER_TARGET_PILE_SRC, 0);
    ISettlerRole::DetachFromPile(_pSettler, OBSERVER_TARGET_PILE_SRC_2, 0);
    ISettlerRole::DetachFromPile(_pSettler, OBSERVER_TARGET_PILE_SRC_3, 0);
    if(this->m_uHomeEntityId) {
        BB_ASSERT(_pSettler->FlagBits(ENTITY_FLAG_ATTACHED))

        if(CMapObjectMgr::Entity(this->m_uHomeEntityId).ObjType() == BUILDING_OBJ) {
            CBuilding *pBuilding = g_cBuildingMgr[this->m_uHomeEntityId];
            pBuilding->InhabitantFlee(_pSettler->ID());
        }

        CMapObjectMgr::Entity(this->m_uHomeEntityId).Detach(_pSettler->ID());
        this->m_uHomeEntityId = 0;
    }
    BB_ASSERT(_pSettler->FlagBits(ENTITY_FLAG_ATTACHED) == 0)

    if(this->m_iDestinationPosition) {
        int v6 = CWorldManager::Index(this->m_iDestinationPosition);
        CWorldManager::ClearFlagBits(v6, 32);
    }

    CWorldManager::EcoSectorId(_pSettler->WorldIdx());
    if(_pSettler->WarriorType()) {
        _pSettler->TakeWaitList();
        return 0;
    }

    if(CWorldManager::OwnerId(_pSettler->WorldIdx()) == _pSettler->OwnerId()) {
        if(!_pSettler->FlagBits(ENTITY_FLAG_Offered)) {
            unsigned __int16 *pEcoSector = g_cESMgr[CWorldManager::EcoSectorId(_pSettler->WorldIdx())];
            pEcoSector->SetSettlerOffer(_pSettler->Type(), _pSettler->ID());
        }

        _pSettler->TakeWaitList();
        return 0;
    }

    std::unique_ptr<ISettlerRole> pRole(new CFleeRole());
    _pSettler->NewRole(std::move(pRole));
    return 1;
}

// address=[0x158a4d0]
// Decompiled from void __thiscall ISettlerRole::SetObserverTarget(ISettlerRole *this, int observerTargetType, WORD target)
void ISettlerRole::SetObserverTarget(enum T_OBSERVER_TARGET observerTargetType, int target) {
    if(!observerTargetType) {
        this->m_uHomeEntityId = target;
        return;
    }

    if(observerTargetType == 2) {
        this->m_uSourcePileId = target;
    } else {
        BB_REPORT("ISettlerRole::SetObserverTarget(): Invalid target type!")
    }
}

// address=[0x158a530]
// Decompiled from int __thiscall ISettlerRole::GetObserverTarget(ISettlerRole *this, int a2)
int ISettlerRole::GetObserverTarget(T_OBSERVER_TARGET a2) {
    if(!a2)
        return this->m_uHomeEntityId;
    if(a2 == 2)
        return this->m_uSourcePileId;
    return 0;
}

// address=[0x158a570]
// Decompiled from ISettlerRole *__thiscall ISettlerRole::ISettlerRole(ISettlerRole *this, struct std::istream *a1)
ISettlerRole::ISettlerRole(std::istream &_rStream) : CPersistence() {

    int pExceptionObject;      // [esp+0h] [ebp-Ch] BYREF
    unsigned int iFileVersion; // [esp+4h] [ebp-8h] BYREF

    _rStream >> iFileVersion;
    if(iFileVersion) {
        _rStream >> this->m_iTask;
        _rStream >> this->m_uSettlerWalk;
        _rStream >> this->m_iWalkspeed;
        _rStream >> this->m_uCycleFrames;
        _rStream >> this->m_uTick;
        _rStream >> this->m_bForward;
        _rStream >> this->unk_0B;
        _rStream >> this->m_iDestinationOffsetX;
        _rStream >> this->m_iDestinationOffsetY;
        _rStream >> this->m_uAttachedSettlerId;
        _rStream >> this->m_iDestinationPosition;
        _rStream >> this->m_iStartPosition;
        _rStream >> this->m_uHomeEntityId;
        _rStream >> this->m_uEntityId;
        _rStream >> this->m_fOffsetX;
        _rStream >> this->m_fOffsetY;
    }
    if(iFileVersion >= 2) {
        _rStream >> this->m_uSourcePileId;
        _rStream >> this->m_uToDoCount;
    }
    if(!iFileVersion || iFileVersion >= 3) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for ISettlerRole");
        throw CS4InvalidMapException();
    }

    static_assert(std::is_same_v<decltype(this->m_iTask), signed char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iTask), signed char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uSettlerWalk), unsigned char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iWalkspeed), signed char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uCycleFrames), unsigned char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uTick), unsigned short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_bForward), unsigned char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->unk_0B), unsigned char>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iDestinationOffsetX), short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iDestinationOffsetY), short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uAttachedSettlerId), unsigned short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iDestinationPosition), int>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_iStartPosition), int>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uHomeEntityId), unsigned short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uEntityId), unsigned short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_fOffsetX), float>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_fOffsetY), float>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uSourcePileId), unsigned short>, "Correct type as original");
    static_assert(std::is_same_v<decltype(this->m_uToDoCount), unsigned char>, "Correct type as original");

    return;
}

// address=[0x158a740]
// Decompiled from int __thiscall ISettlerRole::Store(struct CPersistence *this, struct std::ostream *a2)
void ISettlerRole::Store(std::ostream &_rStream) {

    CPersistence::Store(_rStream);

    unsigned iFileVersion = 2;
    _rStream << iFileVersion;
    _rStream << this->m_iTask;
    _rStream << this->m_uSettlerWalk;
    _rStream << this->m_iWalkspeed;
    _rStream << this->m_uCycleFrames;
    _rStream << this->m_uTick;
    _rStream << this->m_bForward;
    _rStream << this->unk_0B;
    _rStream << this->m_iDestinationOffsetX;
    _rStream << this->m_iDestinationOffsetY;
    _rStream << this->m_uAttachedSettlerId;
    _rStream << this->m_iDestinationPosition;
    _rStream << this->m_iStartPosition;
    _rStream << this->m_uHomeEntityId;
    _rStream << this->m_uEntityId;
    _rStream << this->m_fOffsetX;
    _rStream << this->m_fOffsetY;
    _rStream << this->m_uSourcePileId;
    _rStream << this->m_uToDoCount;
}

// address=[0x158a8d0]
// Decompiled from int __thiscall ISettlerRole::GetKindOfSelection(ISettlerRole *this, struct CSettler *a2)
int ISettlerRole::GetKindOfSelection(class CSettler *a2) const {

    return 1;
}

// address=[0x158a8f0]
// Decompiled from int __thiscall ISettlerRole::MarkPileAsUnused(void *this, int a2)
void ISettlerRole::MarkPileAsUnused(T_OBSERVER_TARGET _tObserverTarget) {
    if(_tObserverTarget) {
        BB_ASSERT(GetObserverTarget(_tObserverTarget) == 0)
        this->SetObserverTarget(_tObserverTarget, ENTITY_ID_UNUSED);
        BB_ASSERT(GetObserverTarget(_tObserverTarget) == ENTITY_ID_UNUSED)
    } else {
        BB_REPORTF("ISettlerRole::MarkPileAsUnused(): Invalid type %i!", 0)
    }
}

// address=[0x158a9c0]
// Decompiled from int __thiscall ISettlerRole::DetachFromPile(ISettlerRole *this, CSettler *a2, int a3, char a4)
void ISettlerRole::DetachFromPile(class CSettler *_pSettler, T_OBSERVER_TARGET _tObserverTarget, bool _bChangeAmount) {
    BB_ASSERT(_pSettler != 0)
    if(_tObserverTarget) {
        int iObserver = this->GetObserverTarget(_tObserverTarget);
        if(iObserver) {
            if(iObserver != 0xFFFF) {
                int iSettlerId = _pSettler->EntityId();
                BB_ASSERT(iSettlerId > 0)
                if(iSettlerId <= 0 && BBSupportDbgReport(2, "MapObjects\\Settler\\SettlerRole.cpp", 955, "iSettlerId > 0") == 1)
                    __debugbreak();
                CPile &rPile = g_cPileMgr[iObserver];
                if(_bChangeAmount)
                    rPile.ChangeAmountAndDetach(iSettlerId);
                else
                    rPile.Detach(iSettlerId);

                BB_ASSERT(GetObserverTarget(_tObserverTarget) == 0)
            }
            this->SetObserverTarget(_tObserverTarget, 0);
        }

        BB_ASSERT(!_bChangeAmount)
    } else {
        BB_REPORTF("ISettlerRole::DetachFromPile(): Invalid type %i!", 0)
    }
}

// address=[0x158ab30]
// Decompiled from int __thiscall ISettlerRole::GetNextSettlerType(ISettlerRole *this)
int ISettlerRole::GetNextSettlerType(void) {

    return 0;
}

// address=[0x158ab40]
// Decompiled from char __thiscall ISettlerRole::SetNextSettlerType(ISettlerRole *this, int a2)
bool ISettlerRole::SetNextSettlerType(int a2) {

    return 0;
}

// address=[0x158ab50]
// Decompiled from int __thiscall ISettlerRole::SettlerWalk(ISettlerRole *this, struct CSettler *a2)
int ISettlerRole::SettlerWalk(class CSettler *_pSettler) {
    return _pSettler->Walk();
}

// address=[0x158ab70]
// Decompiled from char __thiscall ISettlerRole::SearchRestingPlace(ISettlerRole *this, struct CSettler *a2, int a3)
bool ISettlerRole::SearchRestingPlace(class CSettler *_pSettler, int _iDistance) {
    BB_ASSERT(_iDistance > 1)

    int iLastOffset = CSpiralOffsets::Last(_iDistance);
    int iFirstOffset = CSpiralOffsets::First(_iDistance - 1);
    int iX = _pSettler->X();
    int iY = _pSettler->Y();
    for(int i = iLastOffset; i >= iFirstOffset; --i) {
        int iSpiralX = iX + CSpiralOffsets::DeltaX(i);
        int iSpiralY = iY + CSpiralOffsets::DeltaY(i);
        if(CWorldManager::InWorld(iSpiralX, iSpiralY)) {
            if(CWorldManager::EcoSectorId(iX, iY) == CWorldManager::EcoSectorId(iSpiralX, iSpiralY) && !CWorldManager::FlagBits(iSpiralX, iSpiralY, 0x77u)) {
                this->m_iStartPosition = Y16X16::PackXYFast(iSpiralX, iSpiralY);
                return 1;
            }
        }
    }
    return 0;
}

// address=[0x158aca0]
// Decompiled from char __thiscall ISettlerRole::CheckHome(ISettlerRole *this, struct CSettler *a2)
bool ISettlerRole::CheckHome(class CSettler *a2) {
    if(this->m_uHomeEntityId)
        return 1;

    this->SetFree(a2, -1);
    return 0;
}

// address=[0x158ace0]
// Decompiled from void __thiscall ISettlerRole::InitCommonTaskValues(  ISettlerRole *this,  struct CSettler *a2,  const struct CEntityTask *a3)
void ISettlerRole::InitCommonTaskValues(class CSettler *_pSettler, class CEntityTask const &_rTask) {
    if(!_rTask.m_iTask || _rTask.m_iTask == 1 || _rTask.m_iTask == 29 || _rTask.m_iTask == 2 || _rTask.m_iTask == 5 || _rTask.m_iTask == 4 || _rTask.m_iTask == 30) {
        _pSettler->SetFlagBits((EntityFlag)2048);
        _pSettler->m_iDistance = 0;
        this->m_iDestinationOffsetX = _rTask.m_iX;
        this->m_iDestinationOffsetY = _rTask.m_iY;
    } else {
        _pSettler->ClearFlagBits((EntityFlag)2048);
        _pSettler->m_iDistance = 0;
        this->m_iDestinationOffsetX = _rTask.m_iX;
        this->m_iDestinationOffsetY = _rTask.m_iY;
    }
    if(_rTask.m_iDir >= 0)
        _pSettler->m_iDirection = _rTask.m_iDir;
    if(_rTask.m_bVisible)
        _pSettler->SetFlagBits(ENTITY_FLAG_Visible);
    else
        _pSettler->ClearFlagBits(ENTITY_FLAG_Visible);
    if(_rTask.m_iTrigger) {
        BB_ASSERT(m_uHomeEntityId != 0)
        if(this->m_uHomeEntityId) {
            struct CBuilding *pBuilding = g_cBuildingMgr.GetBuildingPtr(this->m_uHomeEntityId);
            BB_ASSERT(pBuilding != NULL)
            if(pBuilding) {
                pBuilding->Role()->TakeJobTrigger(_rTask.m_iTrigger);
            }
        }
    }
    this->m_uSettlerWalk = 72;
    this->m_iTask = _rTask.m_iTask;
    this->m_iWalkspeed = _rTask.m_iDuration;
    this->m_uCycleFrames = _rTask.m_iFrameCount;
    if(this->m_uCycleFrames <= 1u) {
        BBSupportTracePrintF(
            3,
            "ISettlerRole::InitCommonTaskValues(): Invalid number of frames (%i) for settler type %s, job %s!",
            this->m_uCycleFrames,
            s_sSettlerDefines[_pSettler->Type()].m_spName,
            s_sSettlerJobDefines[_rTask.m_iJobNr].m_spName);
    }
    BB_ASSERT(m_uCycleFrames >= 1)

    if(_rTask.m_uData9)
        this->m_uEntityId = _rTask.m_uData9;
    if(_rTask.m_iEntity)
        this->unk_0B = _rTask.m_iEntity;
    _pSettler->m_iFrame = 0;
    _pSettler->m_iJobPart = _rTask.m_iJobNr;
    this->m_bForward = _rTask.m_bForward;
    if(this->m_bForward)
        _pSettler->SetFrame(0);
    else
        _pSettler->SetFrame(this->m_uCycleFrames - 1);
}

// address=[0x158afa0]
// Decompiled from void __thiscall ISettlerRole::NewDestinationEx(  ISettlerRole *this,  CSettler *pSettler,  void *a3,  int a4,  int a5,  char a6)
void ISettlerRole::NewDestinationEx(class CSettler *pSettler, class std::list<class CEntityTask, class std::allocator<class CEntityTask>> &_rTaskList, int a4, int a5, int a6) {

    if(_rTaskList.size()) {
        const auto &ActualTask = pSettler->GetActualTask();
        if(ActualTask.m_iTask != 17 && (a6 & 2) != 0) {
            if(_rTaskList.back().m_iTask == 17)
                _rTaskList.pop_back();
        } else {
            _rTaskList.clear();
        }
    }

    int iJob = g_pGfxManager->GetSettlerFirstJob(pSettler->Race(), pSettler->Type());
    unsigned int iFrameCount = g_pGfxManager->GetSettlerJobFrameCount(pSettler->Race(), iJob, 2u);
    _rTaskList.push_back(CEntityTask(7, iJob, a4, a5, -1, iFrameCount, -1, 1, 1, 0, 0, 0, 0));
    _rTaskList.push_back(CEntityTask(17, iJob, a6 & 1, 0, -1, iFrameCount, -1, 1, 1, 0, 0, 0, 0));
    pSettler->SetToDoList(&_rTaskList);
    if(_rTaskList.size() == 2) {
        pSettler->ResetToDoList();
        this->TakeJob(pSettler);
    }
}
