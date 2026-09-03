#include "ISelectableSettlerRole.h"

#include "CBB/CBBSupport.h"
#include "CSettler.h"
#include "CSettlerMgr.h"
#include "Logic/Events/CEntityEvent.h"
#include "MapObjects/CEntityTask.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/Ship/CFerryShip.h"
#include "Pathing/CAlliances.h"
#include "Pathing/CScanner.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

#include <iostream>

// Definitions for class ISelectableSettlerRole

// address=[0x157c980]
// Decompiled from void __thiscall ISelectableSettlerRole::ISelectableSettlerRole(  ISelectableSettlerRole *this,  struct std::istream *_rStream)
ISelectableSettlerRole::ISelectableSettlerRole(std::istream &_rStream) : ISettlerRole(_rStream) {
    Serial::LoadVersion(_rStream);
    _rStream >> this->m_iGroupFlags;
}

// address=[0x157ca10]
// Decompiled from void __thiscall ISelectableSettlerRole::Store(ISelectableSettlerRole *this, struct std::ostream *_rStream)
void ISelectableSettlerRole::Store(std::ostream &_rStream) {
    ISettlerRole::Store(_rStream);

    Serial::StoreVersion(_rStream, 1);
    _rStream << this->m_iGroupFlags;

    static_assert(std::is_same_v<decltype(this->m_iGroupFlags), unsigned short>, "Correct type as original");
}

// address=[0x157ca50]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlags(ISelectableSettlerRole *this)
int ISelectableSettlerRole::GetGroupFlags(void) const {

    return this->m_iGroupFlags;
}

// address=[0x157ca70]
// Decompiled from void __thiscall ISelectableSettlerRole::SetGroupFlags(ISelectableSettlerRole *this, unsigned int _iFlags)
int ISelectableSettlerRole::SetGroupFlags(int _iFlags) {
    BB_ASSERT((_iFlags >= 0) && (_iFlags <= 0xFFFF))
    this->m_iGroupFlags = _iFlags;
}

// address=[0x157cac0]
// Decompiled from void __thiscall ISelectableSettlerRole::SetGroupFlagBits(ISelectableSettlerRole *this, unsigned int _iFlagBits)
int ISelectableSettlerRole::SetGroupFlagBits(int _iFlagBits) {
    BB_ASSERT((_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF))
    this->m_iGroupFlags |= _iFlagBits;
}

// address=[0x157cb20]
// Decompiled from void __thiscall ISelectableSettlerRole::ClearGroupFlagBits(ISelectableSettlerRole *this, unsigned int _iFlagBits)
int ISelectableSettlerRole::ClearGroupFlagBits(int _iFlagBits) {
    BB_ASSERT((_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF))
    this->m_iGroupFlags &= ~(_WORD)_iFlagBits;
}

// address=[0x1592df0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetPrimaryGroupId(ISelectableSettlerRole *this)
int ISelectableSettlerRole::GetPrimaryGroupId(void) const {
    return (this->m_iGroupFlags & 0xF000) >> 12;
}

// address=[0x157c930]
// Decompiled from ISelectableSettlerRole *__thiscall ISelectableSettlerRole::ISelectableSettlerRole(ISelectableSettlerRole *this)
ISelectableSettlerRole::ISelectableSettlerRole(void) {
    this->m_iGroupFlags = 0;
}

// address=[0x157c960]
// Decompiled from ISettlerRole *__thiscall ISelectableSettlerRole::~ISelectableSettlerRole(ISelectableSettlerRole *this)
ISelectableSettlerRole::~ISelectableSettlerRole(void) = default;

// address=[0x157cb80]
// Decompiled from char __thiscall ISelectableSettlerRole::TakeCommonJob(ISettlerRole *this, struct CSettler *arg0)
bool ISelectableSettlerRole::TakeCommonJob(class CSettler *_pSettler) {
    const auto &rTask = _pSettler->GetActualTask();
    if(rTask.m_iTask != 7)
        return 0;
    int v3 = _pSettler->JobPart();
    int a2 = _pSettler->Frame();
    ISettlerRole::InitCommonTaskValues(_pSettler, rTask);
    if(v3 == _pSettler->JobPart() && a2 >= 1 && a2 < this->m_uCycleFrames)
        _pSettler->SetFrame(a2);
    else
        _pSettler->SetFrame(1u);
    _pSettler->WalkToXY(this->m_iDestinationPosition, 0);
    _pSettler->SetDisplacementCosts(5);
    this->m_iTask = 6;
    if(_pSettler->EventQueueEmpty()) {
        this->Go(_pSettler);
    } else {
        this->m_uSettlerWalk = -120;
        _pSettler->RegisterForLogicUpdate(1);
    }
    return 1;
}

// address=[0x157cc70]
// Decompiled from int __thiscall ISelectableSettlerRole::Decrease(ISelectableSettlerRole *this, int a2)
int ISelectableSettlerRole::Decrease(int a2) {
    int v3; // [esp+8h] [ebp-10h]
    if(a2 <= 0)
        return 0;
    IEntity *pEntity = g_pMapObjectMgr->EntityPtr(this->m_uAttachedSettlerId);
    if(!pEntity)
        return a2;
    if((pEntity->UniqueId() & 0x20000000) != 0)
        return 0;
    if(pEntity->FlagBits((EntityFlag)0x200000))
        a2 = (a2 * g_pMagicShieldDmgDecrease256) >> 8;
    if(pEntity->Race() == 3) {
        --a2;
    } else if(pEntity->Type() == 44) {
        IEntity *v4 = CMapObjectMgr::EntityPtr(this->m_uAttachedSettlerId);
        a2 -= CSettlerMgr::GetSettlerInfo(v4 ? v4->Race() : 0, 44).m_bArmor;
    }
    if(a2 <= 0)
        return 1;
    return a2;
}

// address=[0x157cd70]
// Decompiled from char __thiscall ISelectableSettlerRole::ProcessGoToPosFerry(  ISelectableSettlerRole *this,  CSettler *a2,  const struct CEntityEvent *a3)
bool ISelectableSettlerRole::ProcessGoToPosFerry(class CSettler *_pSettler, class CEntityEvent const *a3) {
    int m_iDataC = a3->m_iDataC;
    if(m_iDataC <= 0)
        return 0;
    int v10 = Y16X16::UnpackXFast(m_iDataC);
    int v11 = Y16X16::UnpackYFast(m_iDataC);
    const CFerryShip *pFerryShipAtPos = CVehicleMgr::GetFerryShipAt(v10, v11);
    if(pFerryShipAtPos) {
        if(pFerryShipAtPos->OwnerId() == _pSettler->OwnerId()) {
            if(!pFerryShipAtPos->Request(_pSettler->EntityId()))
                return 1;
        }
    }

    if(ISettlerRole::HomeEntityId() <= 0)
        return 0;

    IEntity *iFerryEntity = CMapObjectMgr::EntityPtr(HomeEntityId());
    CFerryShip *pFerry = dynamic_cast<CFerryShip *>(iFerryEntity);
    if(!pFerry)
        return 0;
    pFerry->EntityOrderCanceled(_pSettler->EntityId());
    pFerry->Detach(_pSettler->EntityId());
    return 0;
}

// address=[0x157ce70]
// Decompiled from int __thiscall ISelectableSettlerRole::ThiefCheckMasquerade(ISelectableSettlerRole *this, CSettler *_pSettler)
unsigned int ISelectableSettlerRole::ThiefCheckMasquerade(class CSettler *_pSettler) {
    int iAllianceHere = CAlliances::AllianceId(CWorldManager::OwnerId(CWorldManager::Index(_pSettler->PackedXY())));
    int iSettlerAlliance = CAlliances::AllianceId(_pSettler->OwnerId());
    if(_pSettler->FlagBits(ENTITY_FLAG_Ownerless)) {
        if(CScanner::FindAnyEnemyFighter(_pSettler->X(), _pSettler->Y(), 6, 60, _pSettler->OwnerId()))
            ISelectableSettlerRole::ThiefExpose(_pSettler);
    } else if(iAllianceHere == iSettlerAlliance || !iAllianceHere) {
        if(!CScanner::FindAnyEnemyFighter(_pSettler->X(), _pSettler->Y(), 15, 60, _pSettler->OwnerId()))
            ISelectableSettlerRole::ThiefDisguise(_pSettler);
    }
    if(_pSettler->FlagBits(ENTITY_FLAG_Ownerless))
        return 15;
    else
        return 45;
}

// address=[0x157cfa0]
// Decompiled from void __thiscall ISelectableSettlerRole::ThiefExpose(ISelectableSettlerRole *this, struct IEntity *a2)
void ISelectableSettlerRole::ThiefExpose(class IEntity *_pSettler) {
    _pSettler->ClearFlagBits(ENTITY_FLAG_Ownerless);
    _pSettler->SetFlagBits(ENTITY_FLAG_VULNERABLE_MASK);
}

// address=[0x157cfd0]
// Decompiled from void __thiscall ISelectableSettlerRole::ThiefDisguise(ISelectableSettlerRole *this, struct IEntity *a2)
void ISelectableSettlerRole::ThiefDisguise(class IEntity *_pSettler) {
    _pSettler->SetFlagBits(ENTITY_FLAG_Ownerless);
    _pSettler->ClearFlagBits(ENTITY_FLAG_VULNERABLE_MASK);
}

// address=[0x15921c0]
// Decompiled from int __thiscall ISelectableSettlerRole::GetGroupFlagsEx(ISelectableSettlerRole *this)
int ISelectableSettlerRole::GetGroupFlagsEx(void) const {
    return this->m_iGroupFlags;
}
