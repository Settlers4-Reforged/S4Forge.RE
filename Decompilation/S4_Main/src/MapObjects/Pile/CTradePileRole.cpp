#include "CTradePileRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CPile.h"
#include "CPileMgr.h"
#include "Debug/DebugFlags.h"
#include "Defines/Buildings.h"
#include "Script/CGameScriptManager.h"
#include "World/CWorldManager.h"

#include <iostream>

// Definitions for class CTradePileRole

int s_iTradePileRoleDebugSection = GetAvailableSection();

class CBuilding;
// address=[0x14023e0]
// Decompiled from CTradePileRole *__cdecl CTradePileRole::New(int a1)
class CPersistence *__cdecl CTradePileRole::New(std::istream &_rStream) {
    return new CTradePileRole(_rStream);
}

// address=[0x1560480]
// Decompiled from int __cdecl CTradePileRole::Load(int a1)
class CTradePileRole *__cdecl CTradePileRole::Load(std::istream &_rStream) {
    return dynamic_cast<CTradePileRole *>(CPersistence::New(_rStream));
}

// address=[0x1561a70]
// Decompiled from void __thiscall CTradePileRole::Increase(CTradePileRole *this, struct CPile *_pPile, int a3)
void CTradePileRole::Increase(class CPile *_pPile, int _iAmount) {

    int BuildingId; // eax
    CBuilding *v4;  // eax
    int v5;         // eax
    CBuilding *v6;  // eax
    int v7;         // eax
    int v8;         // esi
    int v9;         // [esp-8h] [ebp-10h]
    int v10;        // [esp-4h] [ebp-Ch]

    BB_ASSERT(_pPile)
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN || CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_3) {
        g_cBuildingMgr[_pPile->GetBuildingId()].GoodArrive(_pPile->GetGoodType());
    }
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_2) {
        CGameScriptManager::SendGameEvent(g_pScriptMgr, 0x11u, g_cBuildingMgr[_pPile->GetBuildingId()].Type(), _pPile->GetGoodType(), 1);
        if(_pPile->Amount() - _iAmount == _pPile->AmountLeaving() && !_pPile->GetOfferFlag()) {
            _pPile->Offer(1, 0);
            _pPile->SetOfferFlag(1u);
        }
    }
}

// address=[0x1561b70]
// Decompiled from void __thiscall CTradePileRole::Decrease(CTradePileRole *this, struct CPile *_pPile, int a3)
void CTradePileRole::Decrease(class CPile *_pPile, int a3) {
    BB_ASSERT(_pPile)
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN) {
        class CTradingBuildingRole *pBuildingRole = dynamic_cast<CTradingBuildingRole *>(g_cBuildingMgr.GetBuildingPtr(_pPile->GetBuildingId())->Role());
        pBuildingRole->GoodLeft(_pPile->GetGoodType());
        if(!_pPile->Amount() && !CTradePileRole::GetExpectedAmount() && !_pPile->AmountComing()) {
            if(_pPile->GetOfferFlag()) {
                _pPile->CancelOffer(0, 0);
                _pPile->SetOfferFlag(0);
            }
            this->m_iRoleType = TRADEPILE_FREE;
            _pPile->SetGoodType(0);
        }
    }
    if(this->m_iRoleType == TRADEPILE_EXPORT_RESERVES && _pPile->Amount() <= 0) {
        this->m_iReserveAmount = 0;
        this->m_iRoleType = TRADEPILE_FREE;
        _pPile->SetGoodType(0);
    }
}

// address=[0x1561c90]
// Decompiled from void __thiscall CTradePileRole::Empty(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::Empty(class CPile *_pPile) {
    if(!CTradePileRole::GetExpectedAmount() && !_pPile->AmountComing()) {
        if(_pPile->GetOfferFlag()) {
            _pPile->CancelOffer(0, 0);
            _pPile->SetOfferFlag(0);
        }
        this->m_iRoleType = TRADEPILE_FREE;
        _pPile->SetGoodType(0);
        int iBuildingId = _pPile->GetBuildingId();
        if(iBuildingId > 0) {
            CBuilding *pBuilding = g_cBuildingMgr[iBuildingId];
            if(pBuilding->Type() == BUILDING_STORAGEAREA) {
                g_cESMgr[pBuilding->EcoSectorId()].RegisterFreeStoragePile(iBuildingId, _pPile->EntityId());
            }
        }
    }
}

// address=[0x1561d60]
// Decompiled from void __thiscall CTradePileRole::Init(CTradePileRole *this, CPile *a2)
void CTradePileRole::Init(class CPile *_pPile) {
    if(debug && DEBUG_FLAGS[s_iTradePileRoleDebugSection]) {
        BBSupportTracePrintF(0, "Pile %u init as tradePile", _pPile->ID());
    }
    this->m_uPileId = _pPile->ID();
    _pPile->SetRoleType(4u);
    _pPile->SetNext(0);
    _pPile->SetPrevious(0);
    _pPile->SetOfferFlag(0);
    this->m_iRoleType = TRADEPILE_FREE;
}

// address=[0x1561de0]
// Decompiled from void __thiscall CTradePileRole::LogicUpdate(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::LogicUpdate(class CPile *_pPile) {
    if((CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN || CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_3) && !_pPile->GetOfferFlag()) {
        if(CTradePileRole::GetExpectedAmount()) {
            int iES = CWorldManager::EcoSectorId(_pPile->WorldIdx());
            struct CBuilding *pBuilding = g_cBuildingMgr.GetBuildingPtr(_pPile->GetBuildingId());
            if(pBuilding->FlagBits(4096)) {
                g_cESMgr[iES].RequestGood(_pPile->GetBuildingId(), _pPile->GetGoodType());
            }
        }
        _pPile->RegisterForLogicUpdate(31);
    }
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_2) {
        struct CBuilding *pBuilding = g_cBuildingMgr.GetBuildingPtr(_pPile->GetBuildingId());
        if(pBuilding && pBuilding->Type() != BUILDING_STORAGEAREA && pBuilding->FlagBits(4096)) {
            if(_pPile->Amount() - _pPile->AmountLeaving() >= 1) {
                g_cESMgr[g_cWorld.EcoSectorId(_pPile->WorldIdx())].RequestSpace(_pPile);
            }
        }

        _pPile->RegisterForLogicUpdate(31);
    }
}

// address=[0x1561f40]
// Decompiled from void __thiscall CTradePileRole::Occupied(CTradePileRole *this, struct CPile *a2, int a3)
void CTradePileRole::Occupied(class CPile *_pPile, int _iES) {
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN) {
        if(_pPile->Amount() > _pPile->AmountLeaving() && !_pPile->GetOfferFlag()) {
            _pPile->Offer(_pPile->Amount() - _pPile->AmountLeaving(), _iES);
            _pPile->SetOfferFlag(1u);
        }
    }
}

// address=[0x1561fc0]
// Decompiled from char __thiscall CTradePileRole::SetFree(CTradePileRole *this, CPile *a2, int a3)
bool CTradePileRole::SetFree(class CPile *_pPile, int a3) {
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN) {
        if(_pPile->Amount() == _pPile->AmountLeaving()) {
            if(_pPile->GetOfferFlag()) {
                _pPile->CancelOffer(0, 0);
                _pPile->SetOfferFlag(0);
            }
        }
    }
    if(CTradePileRole::GetTradeRoleType() != TRADEPILE_UNKNOWN_2)
        return 0;

    _pPile->CancelOffer(_pPile->Amount(), a3);
    _pPile->SetOfferFlag(0);
    return 0;
}

// address=[0x1562050]
// Decompiled from void __thiscall CTradePileRole::NotifyChangeEcoSector(CTradePileRole *this, struct CPile *a2, int a3, int a4)
void CTradePileRole::NotifyChangeEcoSector(class CPile *_pPile, int a3, int a4) {
    IPileRole::NotifyChangeEcoSector(_pPile, a3, a4);
    CBuilding &rBuilding = g_cBuildingMgr[_pPile->GetBuildingId()];
    if(rBuilding.Type() == BUILDING_STORAGEAREA) {
        class CStorageBuildingRole *v5 = dynamic_cast<CStorageBuildingRole *>(rBuilding.Role());
        v5->NotifyChangeEcoSector(_pPile, a3, a4);
    }
}

// address=[0x15620c0]
// Decompiled from void __thiscall CTradePileRole::SubjectDie(CTradePileRole *this, struct CPile *_pPile, int a1)
void CTradePileRole::SubjectDie(class CPile *_pPile, int _iBuildingId) {
    BB_ASSERT(_pPile->AmountLeaving() == 0)
    BB_ASSERT(_pPile->AmountComing() == 0)

    if(_iBuildingId > 0) {
        CBuilding &rBuilding = g_cBuildingMgr[_iBuildingId];
        if(rBuilding.Type() == BUILDING_STORAGEAREA) {
            class CStorageBuildingRole *pBuildingRole = dynamic_cast<CStorageBuildingRole *>(rBuilding.Role());
            pBuildingRole->UnregisterPile(_pPile->ID());
        }
    }
    if(_pPile->GetOfferFlag() == 1 && _pPile->Amount() > 0) {

        _pPile->CancelOffer(_pPile->Amount(), 0);
        _pPile->SetOfferFlag(0);
    }

    _pPile->ChangeRole(PILE_ANYWHERE);
}

// address=[0x15621c0]
// Decompiled from void __thiscall CTradePileRole::SubjectStopped(CTradePileRole *this, CPile *a2)
void CTradePileRole::SubjectStopped(class CPile *_pPile) {
    _pPile->NotifyTargetDieAndDetachAllObservers();
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN && _pPile->Amount() > 0 && !_pPile->GetOfferFlag()) {
        _pPile->Offer(_pPile->Amount(), 0);
        _pPile->SetOfferFlag(1u);
    }
}

// address=[0x1562230]
// Decompiled from void __thiscall CTradePileRole::SubjectStarted(CTradePileRole *this, CPile *a2)
void CTradePileRole::SubjectStarted(class CPile *_pPile) {
    _pPile->NotifyTargetDieAndDetachAllObservers();
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN && _pPile->GetOfferFlag()) {
        _pPile->CancelOffer(_pPile->Amount(), 0);
        _pPile->SetOfferFlag(0);
    }
    _pPile->RegisterForLogicUpdate(1);
}

// address=[0x1562290]
// Decompiled from char __thiscall CTradePileRole::ChangeGoodTypeUnforseen(CTradePileRole *this, struct CPile *a2, int a3)
bool CTradePileRole::ChangeGoodTypeUnforseen(class CPile *_pPile, int _iGood) {

    // eax
    // eax
    // eax
    // [esp+0h] [ebp-18h]
    // [esp+4h] [ebp-14h]
    // [esp+Ch] [ebp-Ch]
    // [esp+10h] [ebp-8h]
    // [esp+17h] [ebp-1h]

    int iCurrentGood = _pPile->GetGoodType();
    char bChanged = IPileRole::ExecuteChangeGoodTypeUnforseen(_pPile, _iGood);
    CBuilding &rBuilding = g_cBuildingMgr[_pPile->GetBuildingId()];
    if(rBuilding.Type() == BUILDING_STORAGEAREA) {
        class CStorageBuildingRole *pStorageRole = dynamic_cast<CStorageBuildingRole *>(rBuilding.Role());
        pStorageRole->ExecuteUnforseenGoodTypeChange(_pPile->ID(), iCurrentGood, _iGood);
    }

    if(rBuilding.Type() != BUILDING_MARKETPLACE)
        return bChanged;

    class CTradingBuildingRole *pTradeRole = dynamic_cast<CTradingBuildingRole *>(rBuilding.Role());
    pTradeRole->ExecuteUnforseenGoodTypeChange(_pPile->ID(), iCurrentGood, _iGood);
    return bChanged;
}

// address=[0x1562340]
// Decompiled from void __thiscall CTradePileRole::SetTradeRoleType(CTradePileRole *this, int a2)
void CTradePileRole::SetTradeRoleType(enum CTradePileRole::TRADEPILE_ROLE _tRole) {
    if(this->m_iRoleType == 4)
        this->m_iReserveAmount = 0;
    this->m_iRoleType = _tRole;
    if(this->m_iRoleType == PILE_DELIVER || this->m_iRoleType == PILE_ANYWHERE) {
        CPile &rPile = g_cPileMgr[this->m_uPileId];
        if(rPile.GetOfferFlag()) {
            if(rPile.Amount() > rPile.AmountLeaving()) {
                rPile.CancelOffer(rPile.Amount(), 0);
                rPile.SetOfferFlag(0);
            }
        }
    }

    if(this->m_iRoleType == PILE_STORAGE) {
        CPile &rPile = g_cPileMgr[this->m_uPileId];
        if(rPile.Amount()) {
            if(!rPile.GetOfferFlag()) {
                rPile.Offer(1, 0);
                rPile.SetOfferFlag(1u);
            }
        }
    }
}

// address=[0x1562440]
// Decompiled from int __thiscall CTradePileRole::GetTradeRoleType(CTradePileRole *this)
int CTradePileRole::GetTradeRoleType(void) {

    return this->m_iRoleType;
}

// address=[0x1562460]
// Decompiled from void __thiscall CTradePileRole::SetExpectedAmount(CTradePileRole *this, int a2)
void CTradePileRole::SetExpectedAmount(int a2) {

    this->m_iExpectedAmount = a2;
}

// address=[0x1562480]
// Decompiled from int __thiscall CTradePileRole::GetExpectedAmount(CTradePileRole *this)
int CTradePileRole::GetExpectedAmount(void) {

    return this->m_iExpectedAmount;
}

// address=[0x15624a0]
// Decompiled from void __thiscall CTradePileRole::IncAmoutLeaving(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::IncAmoutLeaving(class CPile *_pPile) {
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_2) {
        if(_pPile->Amount() == _pPile->AmountLeaving()) {
            if(_pPile->GetOfferFlag()) {
                _pPile->CancelOffer(0, 0);
                _pPile->SetOfferFlag(0);
            }
        }
    }
}

// address=[0x1562500]
// Decompiled from void __thiscall CTradePileRole::DecAmountLeaving(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::DecAmountLeaving(class CPile *_pPile) {
    if(CTradePileRole::GetTradeRoleType() == TRADEPILE_UNKNOWN_2) {
        if(_pPile->Amount() == _pPile->AmountLeaving() && !_pPile->GetOfferFlag()) {
            _pPile->Offer(0, 0);
            _pPile->SetOfferFlag(1u);
        }
    }
}

// address=[0x1562560]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::IncAmountComing(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::IncAmountComing(class CPile *_pPile) {
    if(this->m_iExpectedAmount > 0)
        --this->m_iExpectedAmount;
}

// address=[0x1562590]
// Decompiled from void __thiscall CTradePileRole::DecAmountComing(CTradePileRole *this, struct CPile *a2)
void CTradePileRole::DecAmountComing(class CPile *_pPile) {
    if(this->m_iExpectedAmount < (CPile::MAX_PILE_AMOUNT - _pPile->Amount() - _pPile->AmountComing()))
        ++this->m_iExpectedAmount;
}

// address=[0x15625e0]
// Decompiled from int __thiscall CTradePileRole::ReservesGood(CTradePileRole *this, int _iAmount, int a3, CPile *pPile)
int CTradePileRole::ReservesGood(int _iAmount, enum PILE_TYPES a3, class CPile *pPile) {

    // eax
    // [esp+0h] [ebp-8h]

    BB_ASSERT(_iAmount >= 0)
    BB_ASSERT(pPile != NULL)
    if(!pPile)
        return _iAmount;

    BB_ASSERT(this->GetTradeRoleType() == TRADEPILE_EXPORT_RESERVES)

    int iSpaceLeft = pPile->Amount() - this->m_iReserveAmount;
    if(iSpaceLeft <= 0)
        return 0;
    if(iSpaceLeft < _iAmount) {
        this->m_iReserveAmount = pPile->Amount();
        return iSpaceLeft;
    } else {
        this->m_iReserveAmount += _iAmount;
        return _iAmount;
    }
}

// address=[0x15626d0]
// Decompiled from int __thiscall CTradePileRole::GetReserveAmount(CTradePileRole *this)
int CTradePileRole::GetReserveAmount(void) {
    BB_ASSERT(m_iRoleType == TRADEPILE_EXPORT_RESERVES)
    return this->m_iReserveAmount;
}

// address=[0x1562710]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::CTradePileRole(CTradePileRole *this, struct std::istream *a1)
CTradePileRole::CTradePileRole(std::istream &_rStream) : IPileRole(_rStream) {
    this->m_iReserveAmount = 0;

    unsigned int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    if(iFileFormatVersion) {
        _rStream >> this->m_iRoleType;
        _rStream >> this->m_iExpectedAmount;
        if(iFileFormatVersion == 1)
            return;
    }
    if(iFileFormatVersion < 2) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTradePileRole");
        throw CS4InvalidMapException();
    }

    _rStream >> this->m_iReserveAmount;
}

// address=[0x1562810]
// Decompiled from void __thiscall CTradePileRole::Store(CTradePileRole *this, struct std::ostream *a2)
void CTradePileRole::Store(std::ostream &_rStream) {

    IPileRole::Store(_rStream);
    unsigned int iFileFormatVersion = 2;
    _rStream << iFileFormatVersion;
    _rStream << this->m_iRoleType;
    _rStream << this->m_iExpectedAmount;
    _rStream << this->m_iReserveAmount;

    static_assert(std::is_same_v<decltype(this->m_iRoleType), int>, "types must be the same");
    static_assert(std::is_same_v<decltype(this->m_iExpectedAmount), int>, "types must be the same");
    static_assert(std::is_same_v<decltype(this->m_iReserveAmount), int>, "types must be the same");
}

// address=[0x1562d70]
// Decompiled from int __thiscall CTradePileRole::ClassID(CTradePileRole *this)
unsigned long CTradePileRole::ClassID(void) const {

    return CTradePileRole::m_iClassID;
}

// address=[0x3d8bea0]
// [Decompilation failed for static unsigned long CTradePileRole::m_iClassID]

// address=[0x1562940]
unsigned int __cdecl SetupDebug(unsigned int a1) {
    unsigned int result; // eax
    if(a1 > 0xFE)
        return result; // FIXME

    DEBUG_FLAGS[a1] = 1;
    return a1;
}

// address=[0x1562890]
// Decompiled from CTradePileRole *__thiscall CTradePileRole::CTradePileRole(CTradePileRole *this)
CTradePileRole::CTradePileRole(void) : IPileRole() {
    this->m_iReserveAmount = 0;
    SetupDebug(s_iTradePileRoleDebugSection);
    this->m_iRoleType = TRADEPILE_FREE;
    this->m_iExpectedAmount = 0;
}

// address=[0x1562920]
// Decompiled from IPileRole *__thiscall CTradePileRole::~CTradePileRole(CTradePileRole *this)
CTradePileRole::~CTradePileRole(void) = default;
