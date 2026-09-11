#include "CSaboteurRole.h"

// Definitions for class CSaboteurRole

// address=[0x1401b20]
// Decompiled from int __cdecl CSaboteurRole::New(int a1)
class CPersistence * __cdecl CSaboteurRole::New(std::istream & a1) {
  
  if ( operator new(0x68u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CSaboteurRole::CSaboteurRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x157c490]
// Decompiled from int __thiscall CSaboteurRole::Init(_DWORD *this, CPropertySet *a2)
void  CSaboteurRole::Init(class CSettler * a2) {
  
  int result; // eax

  result = CSoldierRole::Init(a2);
  *(this + 25) = 0;
  return result;
}


// address=[0x157c4c0]
// Decompiled from int __thiscall CSaboteurRole::LogicUpdate(ISelectableSettlerRole *this, struct CSettler *a2)
void  CSaboteurRole::LogicUpdate(class CSettler * a2) {
  
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-24h]
  int v7; // [esp-4h] [ebp-20h]
  int v8; // [esp+4h] [ebp-18h]
  unsigned int TickCounter; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v11; // [esp+18h] [ebp-4h]

  TickCounter = CGameData::GetTickCounter(g_pGameData);
  if ( TickCounter >= *((_DWORD *)this + 25) )
  {
    *((_DWORD *)this + 25) = ISelectableSettlerRole::ThiefCheckMasquerade(this, a2) + TickCounter;
  }
  if ( this->m_iTask == 16 )
  {
    this->m_iTask = 27;
    v11 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(this->m_uEntityId);
    if ( v11 != 0 && IEntity::FlagBits((IEntity *)v11, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0 && IEntity::FlagBits((IEntity *)v11, ENTITY_FLAG_VulnerableMask) != 0 && CStateGame::Rand(g_pGame) < g_uSaboteurHitChange )
    {
      v2 = IEntity::OwnerId((IEntity *)v11);
      if ( v2 == CPlayerManager::GetLocalPlayerId() )
      {
        v7 = IEntity::Y(v11);
        v6 = IEntity::X(v11);
        v3 = IEntity::OwnerId((IEntity *)v11);
        CTextMsgHandler::AddWarningMsg(2448, v3, v6, v7);
      }
      v8 = *(unsigned __int8 *)(*((_DWORD *)this + 24) + 3);
      v4 = IEntity::OwnerId(a2);
      (*(void (__thiscall **)(unsigned __int8 *, int, int))(*(_DWORD *)v11 + 28))(v11, v8, v4);
    }
  }
  return ((int (__thiscall *)(ISettlerRole *, struct CSettler *))ISettlerRole::LogicUpdate)(this, a2);
}


// address=[0x157c5f0]
// Decompiled from _DWORD *__thiscall CSaboteurRole::CSaboteurRole(_DWORD *this, struct std::istream *a2)
 CSaboteurRole::CSaboteurRole(std::istream & a2) {
  
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int Version; // [esp+Ch] [ebp-14h]
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ((void (__stdcall *)(struct std::istream *))CSoldierRole::CSoldierRole)(a2);
  v6 = 0;
  *v5 = &CSaboteurRole::_vftable_;
  v5[12] = &CSaboteurRole::`vftable';
  Version = Serial::LoadVersion(a2);
  if ( Version == 2 )
  {
    v5[25] = 0;
  }
  else
  {
    if ( Version != 3 )
    {
      BBSupportTracePrintF(3, "Unknown file format version for CSaboteurRole!");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned int>(a2, v5 + 25);
  }
  return v5;
}


// address=[0x157c6d0]
// Decompiled from int __thiscall CSaboteurRole::Store(int *this, struct std::ostream *a2)
void  CSaboteurRole::Store(std::ostream & a2) {
  
  ((void (__stdcall *)(struct std::ostream *))CSoldierRole::Store)(a2);
  Serial::StoreVersion(a2, 3);
  return operator^<unsigned int>(a2, (unsigned int *)this + 25);
}


// address=[0x157c8f0]
// Decompiled from int __thiscall CSaboteurRole::ClassID(CSaboteurRole *this)
unsigned long  CSaboteurRole::ClassID(void)const {
  
  return CSaboteurRole::m_iClassID;
}


// address=[0x157c910]
// Decompiled from int __thiscall CSaboteurRole::GetSettlerRole(CMFCButton *this)
int  CSaboteurRole::GetSettlerRole(void)const {
  
  return 10;
}


// address=[0x1588840]
// Decompiled from int __cdecl CSaboteurRole::Load(struct std::istream *a1)
class CSaboteurRole * __cdecl CSaboteurRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSaboteurRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bef8]
// [Decompilation failed for static unsigned long CSaboteurRole::m_iClassID]

// address=[0x157c720]
// Decompiled from int __thiscall CSaboteurRole::WarriorTaskAttack(_DWORD *this, struct IEntity *a2, int a3, int a4)
void  CSaboteurRole::WarriorTaskAttack(class IMovingEntity & a2, int a3, enum T_WARRIOR_ATTACK a4) {
  
  *(this + 13) = CGameData::GetTickCounter(g_pGameData) + 45;
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Ownerless) != 0 )
  {
    ISelectableSettlerRole::ThiefExpose((ISelectableSettlerRole *)(this - 12), a2);
  }
  return CSoldierRole::WarriorTaskAttack(this, a2, a3, a4);
}


// address=[0x157c780]
// Decompiled from CSaboteurRole *__thiscall CSaboteurRole::CSaboteurRole(CSaboteurRole *this)
 CSaboteurRole::CSaboteurRole(void) {
  
  CSoldierRole::CSoldierRole((CSoldierRole *)this);
  *(_DWORD *)this = &CSaboteurRole::_vftable_;
  *((_DWORD *)this + 12) = &CSaboteurRole::`vftable';
  *((_DWORD *)this + 25) = 0;
  return this;
}


// address=[0x157c880]
// Decompiled from void __thiscall CSaboteurRole::~CSaboteurRole(CSoldierRole *this)
 CSaboteurRole::~CSaboteurRole(void) {
  
  this->ISelectableSettlerRole::ISettlerRole::CPersistence::__vftable = (CSoldierRole_vtbl *)&CSaboteurRole::_vftable_;
  this->CWarriorBehavior::__vftable = (CWarriorBehavior_vtbl *)&CSaboteurRole::`vftable';
  CSoldierRole::~CSoldierRole(this);
}


