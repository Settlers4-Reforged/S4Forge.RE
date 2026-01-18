#include "CFindEnemyBuildings.h"

// Definitions for class CFindEnemyBuildings

// address=[0x15af9c0]
// Decompiled from struct CMFCToolBar *__thiscall CFindEnemyBuildings::BuildingId(CMFCCustomizeButton *this)
int  CFindEnemyBuildings::BuildingId(void)const {
  
  return (struct CMFCToolBar *)*((_DWORD *)this + 62);
}


// address=[0x15af9e0]
// Decompiled from int __thiscall CFindEnemyBuildings::BuildingPtr(CFindEnemyBuildings *this)
class CBuilding *  CFindEnemyBuildings::BuildingPtr(void)const {
  
  return *((_DWORD *)this + 63);
}


// address=[0x15dee30]
// Decompiled from CFindEnemyBuildings *__thiscall CFindEnemyBuildings::CFindEnemyBuildings(  CFindEnemyBuildings *this,  int a2,  int a3,  int a4,  int a5,  bool a6)
 CFindEnemyBuildings::CFindEnemyBuildings(int a2, int a3, int a4, int a5, bool a6) {
  
  CVWList::CVWList(this, a2, a3, a4);
  *((_DWORD *)this + 56) = a2;
  *((_DWORD *)this + 57) = a3;
  *((_DWORD *)this + 58) = a4;
  *((_DWORD *)this + 59) = CAlliances::PlayerEnemyBits(a5);
  *((_BYTE *)this + 240) = a6;
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 63) = 0;
  return this;
}


// address=[0x15deec0]
// Decompiled from char __thiscall CFindEnemyBuildings::NextBuilding(CPropertySet **this)
bool  CFindEnemyBuildings::NextBuilding(void) {
  
  struct CPtrList *v1; // eax
  int v2; // eax
  struct CPtrList *v4; // eax
  int v5; // [esp+0h] [ebp-30h]
  int v6; // [esp+4h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+20h] [ebp-10h]
  int EntityIdVW; // [esp+24h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+28h] [ebp-8h]

  if ( this[63] )
  {
    v1 = IEntity::WarMapNode(this[63]);
    v11 = CWarMapNode::Next(v1);
  }
  else
  {
    v11 = 0;
  }
  EntityIdVW = v11;
  while ( 1 )
  {
    while ( EntityIdVW )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, EntityIdVW);
      v2 = IEntity::OwnerId(BuildingPtr);
      if ( ((unsigned int)this[59] & CAlliances::PlayerBit(v2)) != 0 )
      {
        v10 = IEntity::Flags(BuildingPtr);
        v9 = IEntity::WarriorType();
        if ( (((unsigned int)&loc_1FFFFFF + 1) & v10) != 0 && (!*((_BYTE *)this + 240) || v9 == 12) )
        {
          v7 = IEntity::X(BuildingPtr);
          v8 = IEntity::Y(BuildingPtr);
          if ( Grid::DistanceInline((Grid *)(v7 - (_DWORD)this[56]), v8 - (_DWORD)this[57]) <= (int)this[58] )
          {
            this[62] = (CPropertySet *)EntityIdVW;
            this[63] = (CPropertySet *)BuildingPtr;
            return 1;
          }
        }
      }
      v4 = IEntity::WarMapNode((CPropertySet *)BuildingPtr);
      EntityIdVW = CWarMapNode::Next(v4);
    }
    if ( (int)this[61] >= CVWList::Size((CVWList *)this) )
      break;
    v5 = *(_DWORD *)CVWList::operator[](this[61]);
    v6 = *(_DWORD *)(CVWList::operator[](this[61]) + 4);
    EntityIdVW = CWarMap::FirstEntityIdVW(2, v5, v6);
    this[61] = (CPropertySet *)((char *)this[61] + 1);
  }
  this[62] = 0;
  this[63] = 0;
  return 0;
}


