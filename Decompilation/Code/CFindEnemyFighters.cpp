#include "CFindEnemyFighters.h"

// Definitions for class CFindEnemyFighters

// address=[0x15de990]
// Decompiled from // public: __thiscall CFindEnemyFighters::CFindEnemyFighters(int,int,int,int,int)
CVWList *__thiscall CFindEnemyFighters::CFindEnemyFighters(CVWList *this, int a2, int a3, int a4, int a5, int a6)

 CFindEnemyFighters::CFindEnemyFighters(int,int,int,int,int) {
  
  CVWList::CVWList(this, a2, a3, a4);
  *((_DWORD *)this + 56) = a2;
  *((_DWORD *)this + 57) = a3;
  *((_DWORD *)this + 58) = a4;
  *((_DWORD *)this + 59) = a5;
  *((_DWORD *)this + 60) = CAlliances::AllianceId(a6);
  *((_DWORD *)this + 61) = CAlliances::PlayerEnemyBits(a6);
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 64) = 0;
  return this;
}


// address=[0x15dea40]
// Decompiled from // public: bool __thiscall CFindEnemyFighters::NextFighter(void)
char __thiscall CFindEnemyFighters::NextFighter(int this)

bool  CFindEnemyFighters::NextFighter(void) {
  
  struct CPtrList *v1; // eax
  int v2; // eax
  struct CPtrList *v4; // eax
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-10h]
  int EntityIdVW; // [esp+20h] [ebp-Ch]
  unsigned __int8 *v11; // [esp+24h] [ebp-8h]

  if ( *(_DWORD *)(this + 256) )
  {
    v1 = IEntity::WarMapNode(*(CPropertySet **)(this + 256));
    v9 = CWarMapNode::Next(v1);
  }
  else
  {
    v9 = 0;
  }
  EntityIdVW = v9;
  while ( 1 )
  {
    while ( EntityIdVW )
    {
      v11 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(EntityIdVW);
      v2 = IEntity::OwnerId(v11);
      if ( (*(_DWORD *)(this + 244) & CAlliances::PlayerBit(v2)) != 0
        && (*(_DWORD *)(this + 236) & (1 << IEntity::WarriorType())) != 0 )
      {
        v5 = IEntity::X(v11);
        v6 = IEntity::Y(v11);
        if ( Grid::DistanceInline((Grid *)(v5 - *(_DWORD *)(this + 224)), v6 - *(_DWORD *)(this + 228)) <= *(_DWORD *)(this + 232) )
        {
          *(_DWORD *)(this + 252) = EntityIdVW;
          *(_DWORD *)(this + 256) = v11;
          return 1;
        }
      }
      v4 = IEntity::WarMapNode((CPropertySet *)v11);
      EntityIdVW = CWarMapNode::Next(v4);
    }
    if ( *(_DWORD *)(this + 248) >= CVWList::Size((CVWList *)this) )
      break;
    v7 = *(_DWORD *)CVWList::operator[](*(_DWORD *)(this + 248));
    v8 = *(_DWORD *)(CVWList::operator[](*(_DWORD *)(this + 248)) + 4);
    ++*(_DWORD *)(this + 248);
    if ( (int)CInfluMap::EnemyValueVW(v7, v8, *(_DWORD *)(this + 240)) < 16 )
      EntityIdVW = 0;
    else
      EntityIdVW = CWarMap::FirstEntityIdVW(0, v7, v8);
  }
  *(_DWORD *)(this + 252) = 0;
  *(_DWORD *)(this + 256) = 0;
  return 0;
}


