#include "CFindEnemyBuildings.h"

#include "Defines/AI.h"
#include "MapObjects/IEntity.h"
#include "Pathing/CAlliances.h"
#include "Pathing/CWarMapNode.h"

// Definitions for class CFindEnemyBuildings

// address=[0x15af9c0]
// Decompiled from _DWORD __thiscall CFindEnemyBuildings::BuildingId(CFindEnemyBuildings *this)
int CFindEnemyBuildings::BuildingId(void) const {

    return this->m_iBuildingId;
}

// address=[0x15af9e0]
// Decompiled from IEntity *__thiscall CFindEnemyBuildings::BuildingPtr(CFindEnemyBuildings *this)
class CBuilding *CFindEnemyBuildings::BuildingPtr(void) const {
    return this->m_pBuilding;
}

// address=[0x15dee30]
// Decompiled from CFindEnemyBuildings *__thiscall CFindEnemyBuildings::CFindEnemyBuildings(  CFindEnemyBuildings *this,  unsigned int _iX,  unsigned int _iY,  unsigned int _iMaxDistance,  int _iOwner,  bool _bOnlyTowers)
CFindEnemyBuildings::CFindEnemyBuildings(int _iX, int _iY, int _iMaxDistance, int _iOwner, bool _bOnlyTowers) : m_cVWList(_iX, _iY, _iMaxDistance) {
    this->m_iCenterX = _iX;
    this->m_iCenterY = _iY;
    this->m_iMaxDistance = _iMaxDistance;
    this->m_iEnemyBits = CAlliances::PlayerEnemyBits(_iOwner);
    this->m_bOnlyTowers = _bOnlyTowers;
    this->m_iVWIndex = 0;
    this->m_iBuildingId = 0;
    this->m_pBuilding = 0;
}

// address=[0x15deec0]
// Decompiled from char __thiscall CFindEnemyBuildings::NextBuilding(CFindEnemyBuildings *this)
bool CFindEnemyBuildings::NextBuilding(void) {
    int iInitialNodeId; // [esp+20h] [ebp-10h]
    if(this->m_pBuilding) {
        iInitialNodeId = this->m_pBuilding->WarMapNode()->Next();
    } else {
        iInitialNodeId = 0;
    }
    int iWarMapId = iInitialNodeId;

    while(1) {
        while(iWarMapId) {
            struct CBuilding *pBuilding = g_cBuildingMgr.GetBuildingPtr(iWarMapId);
            if((this->m_iEnemyBits & CAlliances::PlayerBit(pBuilding->OwnerId())) != 0) {
                if((pBuilding->Flags() & ENTITY_FLAG_Ready) != 0 && (!this->m_bOnlyTowers || pBuilding->WarriorType() == AI_WARRIOR_TYPE_TOWER_BUILDING)) {
                    if(Grid::DistanceInline(pBuilding->X() - this->m_iCenterX, pBuilding->Y() - this->m_iCenterY) <= this->m_iMaxDistance) {
                        this->m_iBuildingId = iWarMapId;
                        this->m_pBuilding = pBuilding;
                        return 1;
                    }
                }
            }

            iWarMapId = pBuilding->WarMapNode()->Next();
        }
        if(this->m_iVWIndex >= this->m_cVWList.Size())
            break;

        iWarMapId = CWarMap::FirstEntityIdVW(2, this->m_cVWList[this->m_iVWIndex].m_iV, this->m_cVWList[this->m_iVWIndex].m_iW);
        ++this->m_iVWIndex;
    }

    this->m_iBuildingId = 0;
    this->m_pBuilding = 0;
    return 0;
}
