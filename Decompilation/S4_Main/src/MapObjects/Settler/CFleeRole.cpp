#include "CFleeRole.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "CSettler.h"
#include "CSettlerMgr.h"
#include "Defines/Job.h"
#include "Defines/Walking.h"
#include "ISettlerRole.h"
#include "MapObjects/CEntityTask.h"
#include "MapObjects/CSpiralOffsets.h"
#include "MapObjects/IEntity.h"
#include "Pathing/CScanner.h"
#include "Pathing/CWalkingNormal.h"
#include "Pathing/ITiling.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

#include <iostream>

// Definitions for class CFleeRole

class CEcoSector;
// address=[0x1400a40]
// Decompiled from CFleeRole *__cdecl CFleeRole::New(int a1)
class CPersistence *__cdecl CFleeRole::New(std::istream &a1) {
    return new CFleeRole(a1);
}

// address=[0x156d370]
// Decompiled from CWalkingNormal *__thiscall CFleeRole::InitWalking(CFleeRole *this, IEntity *a2)
class CWalking *CFleeRole::InitWalking(CSettler *a2) {
    int v2 = a2->OwnerId();
    CWalking *v4 = CWalking::Create(WALKING_TYPE_NORMAL, v2);
    v4->Init(-1, 0);
    return v4;
}

// address=[0x156d3b0]
// Decompiled from void __thiscall CFleeRole::LogicUpdate(CFleeRole *this, CSettler *pSettler)
void CFleeRole::LogicUpdate(class CSettler *_pSettler) {
    int iSettlerWorldIdx = CWorldManager::Index(_pSettler->X(), _pSettler->Y());
    int iSettlerPosSectorOwner = ITiling::OwnerId(iSettlerWorldIdx);
    if(iSettlerPosSectorOwner == _pSettler->OwnerId()) {
        CEcoSector &rEcoSector = g_cESMgr.operator[](ITiling::EcoSectorId(iSettlerWorldIdx));

        BB_ASSERT(rEcoSector.Owner() == _pSettler->OwnerId())
        rEcoSector.ChangeNrOfSettler(_pSettler->Type(), 1);
        std::unique_ptr<ISettlerRole> pSettlerRole(g_cSettlerMgr.CreateSettlerRole(_pSettler->Race(), _pSettler->Type()));
        _pSettler->NewRole(std::move(pSettlerRole));
        if(!_pSettler->FlagBits(EntityFlag_Offered)) {
            rEcoSector.SetSettlerOffer(_pSettler->Type(), _pSettler->EntityId());
        }
        _pSettler->TakeWaitList();

        return;
    }

    this->m_uSettlerWalk = ISettlerRole::SettlerWalk(_pSettler);
    if((this->m_uSettlerWalk & 0x70) != 0) {
        int iNearestLandX = _pSettler->X();
        int iNearestLandY = _pSettler->Y();
        char iNearestPlayerLand = 0;
        bool bFoundPlayerLand = 0;
        if(this->m_iWalkspeed < 5) {
            iNearestPlayerLand = CScanner::FindNearestPlayerLand(_pSettler->OwnerId(), iNearestLandX, iNearestLandY);
            if(!iNearestPlayerLand) {
                bFoundPlayerLand = 1;
                int iSectorId = ITiling::SectorId(iSettlerWorldIdx);
                BB_ASSERT(iSectorId > 0);

                int iX = _pSettler->X();
                int iY = _pSettler->Y();
                for(int i = 0; i < 64; ++i) {
                    unsigned __int8 v22 = static_cast<unsigned __int8>(g_pGame->Rand() + 0x80);
                    iNearestLandX = iX + CSpiralOffsets::DeltaX(v22);
                    iNearestLandY = iY + CSpiralOffsets::DeltaY(v22);
                    if(CWorldManager::InWorld(iNearestLandX, iNearestLandY) && CWorldManager::SectorId(iNearestLandX, iNearestLandY) == iSectorId) {
                        iNearestPlayerLand = 1;
                        break;
                    }
                }
            }
        }
        if(iNearestPlayerLand) {
            int iWalkStyle = bFoundPlayerLand ? 0x2000 : 0;
            _pSettler->SetFrame(1u);
            _pSettler->WalkToXY(Y16X16::PackXYFast(iNearestLandX, iNearestLandY), iWalkStyle);
            _pSettler->SetDisplacementCosts(5);
            _pSettler->RegisterForLogicUpdate(1);
            ++this->m_iWalkspeed;
        } else {
            g_cSettlerMgr.DeleteSettler(_pSettler->EntityId());
        }
    } else if((this->m_uSettlerWalk & 8) != 0) {
        _pSettler->RegisterForLogicUpdate(1);
    } else {
        _pSettler->RegisterForLogicUpdate(9);
    }
}

// address=[0x156d730]
// Decompiled from void __thiscall CFleeRole::UpdateJob(CFleeRole *this, struct CSettler *a2)
void CFleeRole::UpdateJob(class CSettler *a2) {
}

// address=[0x156d740]
// Decompiled from void __stdcall CFleeRole::PostLoadInit(IEntity *a1)
void CFleeRole::PostLoadInit(class CSettler *a1) {
    CWarMap::AddEntity(a1);
}

// address=[0x156d760]
// Decompiled from char __thiscall CFleeRole::SetFree(CFleeRole *this, struct CSettler *a2, int a3)
bool CFleeRole::SetFree(class CSettler *a2, int a3) {
    return 0;
}

// address=[0x156d770]
// Decompiled from char __thiscall CFleeRole::ESChanged(CFleeRole *this, struct CSettler *a2)
bool CFleeRole::ESChanged(class CSettler *a2) {
    return 0;
}

// address=[0x156d780]
// Decompiled from CFleeRole *__thiscall CFleeRole::CFleeRole(CFleeRole *this, struct std::istream *a2)
CFleeRole::CFleeRole(std::istream &_rStream) : ISettlerRole(_rStream) {
    unsigned int fileFormatVersion;

    _rStream >> fileFormatVersion;
    if(fileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFleeRole");
        throw CS4InvalidMapException();
    }
}

// address=[0x156d830]
// Decompiled from void __thiscall CFleeRole::Store(CFleeRole *this, struct std::ostream *a2)
void CFleeRole::Store(std::ostream &_rStream) {
    ISettlerRole::Store(_rStream);
    unsigned int fileFormatVersion = 1;
    _rStream << fileFormatVersion;
}

// address=[0x156dbc0]
// Decompiled from int __thiscall CFleeRole::ClassID(CFleeRole *this)
unsigned long CFleeRole::ClassID(void) const {

    return CFleeRole::m_iClassID;
}

// address=[0x156dbe0]
// Decompiled from int __thiscall CFleeRole::GetSettlerRole(CFleeRole *this)
int CFleeRole::GetSettlerRole(void) const {
    return FLEE_ROLE;
}

// address=[0x156dc00]
// Decompiled from void __thiscall CFleeRole::LogicUpdateJob(CFleeRole *this, struct CSettler *a2)
void CFleeRole::LogicUpdateJob(class CSettler *a2) {
}

// address=[0x15885c0]
// Decompiled from int __cdecl CFleeRole::Load(struct std::istream *a1)
class CFleeRole *__cdecl CFleeRole::Load(std::istream &_rStream) {
    return dynamic_cast<CFleeRole *>(CPersistence::New(_rStream));
}

// address=[0x3d8bebc]
// [Decompilation failed for static unsigned long CFleeRole::m_iClassID]

// address=[0x156d870]
// Decompiled from CFleeRole *__thiscall CFleeRole::CFleeRole(CFleeRole *this)
CFleeRole::CFleeRole(void) : ISettlerRole() {}

// address=[0x156d890]
// Decompiled from void __thiscall CFleeRole::~CFleeRole(_AFX_OLE_STATE *this)
CFleeRole::~CFleeRole(void) = default;

// address=[0x156d8b0]
// Decompiled from void __thiscall CFleeRole::GetNextJob(CFleeRole *this, struct CSettler *a2)
void CFleeRole::GetNextJob(class CSettler *_pSettler) {
    this->TakeJob(_pSettler);
}

// address=[0x156d8d0]
// Decompiled from void __thiscall CFleeRole::TakeJob(CFleeRole *this, IMovingEntity *a2)
void CFleeRole::TakeJob(class CSettler *_pSettler) {
    const CEntityTask &pActualTask = _pSettler->GetActualTask();
    ISettlerRole::InitCommonTaskValues(_pSettler, pActualTask);
    if(this->m_iTask == 17)
        _pSettler->SetDisplacementCosts(0);
}

// address=[0x156d910]
// Decompiled from void __thiscall CFleeRole::Init(ISettlerRole *this, IAnimatedEntity *a1)
void CFleeRole::Init(class CSettler *_pSettler) {
    BB_ASSERT(_pSettler->FlagBits(EntityFlag_Attached | EntityFlag_Offered) == 0)
    BB_ASSERT(HomeEntityId() == 0)

    CWarMap::AddEntity(_pSettler);
    this->InitWalking(_pSettler);
    _pSettler->TakeWaitList();
    _pSettler->RegisterForLogicUpdate(1);
    this->m_iWalkspeed = 1;
}

// address=[0x156d9b0]
// Decompiled from void __thiscall CFleeRole::ConvertEventIntoGoal(CFleeRole *this, IAnimatedEntity *a2, struct CEntityEvent *a3)
void CFleeRole::ConvertEventIntoGoal(class CSettler *_pSettler, class CEntityEvent *a3) {
    if(!_pSettler->FlagBits(EntityFlag_Registered))
        _pSettler->RegisterForLogicUpdate(1);
}
