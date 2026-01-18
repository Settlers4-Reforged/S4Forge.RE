#include "CFindBuildings.h"

// Definitions for class CFindBuildings

// address=[0x1470890]
// Decompiled from int __thiscall CFindBuildings::BuildingPtr(CFindBuildings *this)
class CBuilding *  CFindBuildings::BuildingPtr(void)const {
  
  return *((_DWORD *)this + 61);
}


// address=[0x15dec30]
// Decompiled from CFindBuildings *__thiscall CFindBuildings::CFindBuildings(CFindBuildings *this, int a2, int a3, int a4)
 CFindBuildings::CFindBuildings(int a2, int a3, int a4) {
  
  CVWList::CVWList(this, a2, a3, a4);
  *((_DWORD *)this + 56) = a2;
  *((_DWORD *)this + 57) = a3;
  *((_DWORD *)this + 58) = a4;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  return this;
}


// address=[0x15deca0]
// Decompiled from char __thiscall CFindBuildings::NextBuilding(CPropertySet **this)
bool  CFindBuildings::NextBuilding(void) {
  
  struct CPtrList *v1; // eax
  struct CPtrList *v3; // eax
  int v4; // [esp+0h] [ebp-28h]
  int v5; // [esp+4h] [ebp-24h]
  int v6; // [esp+Ch] [ebp-1Ch]
  int v7; // [esp+10h] [ebp-18h]
  int v8; // [esp+18h] [ebp-10h]
  int EntityIdVW; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+20h] [ebp-8h]

  if ( this[61] )
  {
    v1 = IEntity::WarMapNode(this[61]);
    v8 = CWarMapNode::Next(v1);
  }
  else
  {
    v8 = 0;
  }
  EntityIdVW = v8;
  while ( 1 )
  {
    while ( EntityIdVW )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, EntityIdVW);
      if ( (((unsigned int)&loc_1FFFFFF + 1) & IEntity::Flags(BuildingPtr)) != 0 )
      {
        v6 = IEntity::X(BuildingPtr);
        v7 = IEntity::Y(BuildingPtr);
        if ( Grid::DistanceInline((Grid *)(v6 - (_DWORD)this[56]), v7 - (_DWORD)this[57]) <= (int)this[58] )
        {
          this[60] = (CPropertySet *)EntityIdVW;
          this[61] = (CPropertySet *)BuildingPtr;
          return 1;
        }
      }
      v3 = IEntity::WarMapNode((CPropertySet *)BuildingPtr);
      EntityIdVW = CWarMapNode::Next(v3);
    }
    if ( (int)this[59] >= CVWList::Size((CVWList *)this) )
      break;
    v4 = *(_DWORD *)CVWList::operator[](this[59]);
    v5 = *(_DWORD *)(CVWList::operator[](this[59]) + 4);
    EntityIdVW = CWarMap::FirstEntityIdVW(2, v4, v5);
    this[59] = (CPropertySet *)((char *)this[59] + 1);
  }
  this[60] = 0;
  this[61] = 0;
  return 0;
}


