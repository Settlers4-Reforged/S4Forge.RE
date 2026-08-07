#if FALSE
#include "CFindEnemyBuildings.h"

// Definitions for class CFindEnemyBuildings

// address=[0x15af9c0]
// Decompiled from _DWORD __thiscall CFindEnemyBuildings::BuildingId(CFindEnemyBuildings *this)
int  CFindEnemyBuildings::BuildingId(void)const {
  
  return this->m_iBuildingId;
}


// address=[0x15af9e0]
// Decompiled from IEntity *__thiscall CFindEnemyBuildings::BuildingPtr(CFindEnemyBuildings *this)
class CBuilding *  CFindEnemyBuildings::BuildingPtr(void)const {
  
  return this->m_pBuilding;
}


// address=[0x15dee30]
// Decompiled from CFindEnemyBuildings *__thiscall CFindEnemyBuildings::CFindEnemyBuildings(CFindEnemyBuildings *this, unsigned int _iX, unsigned int _iY, unsigned int _iMaxDistance, int _iOwner, bool _bOnlyTowers)
 CFindEnemyBuildings::CFindEnemyBuildings(int _iX, int _iY, int _iMaxDistance, int _iOwner, bool _bOnlyTowers) {
  
  CVWList::CVWList(&this->m_cVWList, _iX, _iY, _iMaxDistance);
  this->m_iCenterX = _iX;
  this->m_iCenterY = _iY;
  this->m_iMaxDistance = _iMaxDistance;
  this->m_iEnemyBits = CAlliances::PlayerEnemyBits(_iOwner);
  this->m_bOnlyTowers = _bOnlyTowers;
  this->m_iVWIndex = 0;
  this->m_iBuildingId = 0;
  this->m_pBuilding = 0;
  return this;
}


// address=[0x15deec0]
// Decompiled from char __thiscall CFindEnemyBuildings::NextBuilding(CFindEnemyBuildings *this)
bool  CFindEnemyBuildings::NextBuilding(void) {
  
  CWarMapNode *v1; // eax
  char iOwner; // al
  CWarMapNode *v4; // eax
  int m_iV; // [esp+0h] [ebp-30h]
  int m_iW; // [esp+4h] [ebp-2Ch]
  int iX; // [esp+Ch] [ebp-24h]
  int iY; // [esp+10h] [ebp-20h]
  T_AI_WARRIOR_TYPE v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+20h] [ebp-10h]
  int iWarMapId; // [esp+24h] [ebp-Ch]
  struct CBuilding *pBuilding; // [esp+28h] [ebp-8h]

  if ( this->m_pBuilding )
  {
    v1 = IEntity::WarMapNode(this->m_pBuilding);
    v11 = CWarMapNode::Next(v1);
  }
  else
  {
    v11 = 0;
  }
  iWarMapId = v11;
  while ( 1 )
  {
    while ( iWarMapId )
    {
      pBuilding = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, iWarMapId);
      iOwner = IEntity::OwnerId(pBuilding);
      if ( (this->m_iEnemyBits & CAlliances::PlayerBit(iOwner)) != 0 )
      {
        v10 = IEntity::Flags(pBuilding);
        v9 = IEntity::WarriorType(pBuilding);
        if ( (v10 & ENTITY_FLAG_Ready) != 0 && (!this->m_bOnlyTowers || v9 == AI_WARRIOR_TYPE_TOWER_BUILDING) )
        {
          iX = IEntity::X(pBuilding);
          iY = IEntity::Y(pBuilding);
          if ( Grid::DistanceInline(iX - this->m_iCenterX, iY - this->m_iCenterY) <= this->m_iMaxDistance )
          {
            this->m_iBuildingId = iWarMapId;
            this->m_pBuilding = pBuilding;
            return 1;
          }
        }
      }
      v4 = IEntity::WarMapNode(pBuilding);
      iWarMapId = CWarMapNode::Next(v4);
    }
    if ( this->m_iVWIndex >= CVWList::Size(&this->m_cVWList) )
    {
      break;
    }
    m_iV = CVWList::operator[](&this->m_cVWList, this->m_iVWIndex)->m_iV;
    m_iW = CVWList::operator[](&this->m_cVWList, this->m_iVWIndex)->m_iW;
    iWarMapId = CWarMap::FirstEntityIdVW(2, m_iV, m_iW);
    ++this->m_iVWIndex;
  }
  this->m_iBuildingId = 0;
  this->m_pBuilding = 0;
  return 0;
}


#endif // Already implemented
