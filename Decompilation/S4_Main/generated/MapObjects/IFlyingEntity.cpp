#include "IFlyingEntity.h"

// Definitions for class IFlyingEntity

// address=[0x12fd150]
// Decompiled from int __thiscall IFlyingEntity::FlyingFlagBits(IFlyingEntity *this, int a2)
int  IFlyingEntity::FlyingFlagBits(int a2)const {
  
  return a2 & *((__int16 *)this + 40);
}


// address=[0x154ee80]
// Decompiled from IFlyingEntity *__thiscall IFlyingEntity::IFlyingEntity(IFlyingEntity *this, int a2, int a3, __int16 a4, __int16 a5)
 IFlyingEntity::IFlyingEntity(int a2, int a3, int a4, int a5) {
  
  int v6; // [esp+4h] [ebp-14h]

  IAnimatedEntity::IAnimatedEntity(this, a2);
  *(_DWORD *)this = &IFlyingEntity::_vftable_;
  CObserverList::CObserverList((char *)this + 84);
  *((_BYTE *)this + 82) = 0;
  *((_WORD *)this + 40) = 2;
  *((_DWORD *)this + 17) = a3;
  *((_DWORD *)this + 5) |= 0x8000u;
  *((_BYTE *)this + 10) = 64;
  *((_WORD *)this + 38) = a4;
  *((_WORD *)this + 39) = a5;
  v6 = CLogic::Effects((DWORD *)g_pLogic);
  *((_DWORD *)this + 18) = (*(int (__cdecl **)(_DWORD))(*(_DWORD *)v6 + 40))(*((_DWORD *)this + 17));
  return this;
}


// address=[0x154ef70]
// Decompiled from _DWORD *__thiscall IFlyingEntity::IFlyingEntity(_DWORD *this, int a2)
 IFlyingEntity::IFlyingEntity(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-14h] BYREF
  _DWORD *v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  v4 = this;
  IAnimatedEntity::IAnimatedEntity(a2);
  v5 = 0;
  *v4 = &IFlyingEntity::_vftable_;
  CObserverList::CObserverList(a2);
  LOBYTE(v5) = 1;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
    return v4;
  operator^<signed char>(a2, (char *)v4 + 82);
  operator^<unsigned int>(a2, v4 + 17);
  operator^<unsigned int>(a2, v4 + 18);
  operator^<unsigned short>(a2, v4 + 19);
  operator^<unsigned short>(a2, (char *)v4 + 78);
  operator^<short>(a2, v4 + 20);
  return v4;
}


// address=[0x154f080]
// Decompiled from int __thiscall IFlyingEntity::Store(char *this, struct std::ostream *a2)
void  IFlyingEntity::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  char *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IAnimatedEntity::Store(a2);
  CObserverList::Store(a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<signed char>(a2, v4 + 82);
  operator^<unsigned int>(a2, (int *)v4 + 17);
  operator^<unsigned int>(a2, (int *)v4 + 18);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 38);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 39);
  return operator^<short>((int)a2, (__int16 *)v4 + 40);
}


// address=[0x154f140]
// Decompiled from int __thiscall IFlyingEntity::FlyTo(IFlyingEntity *this, __int16 a2, __int16 a3)
void  IFlyingEntity::FlyTo(int a2, int a3) {
  
  *((_WORD *)this + 38) = a2;
  *((_WORD *)this + 39) = a3;
  IFlyingEntity::SetFlyingFlagBits(this, 1);
  return IAnimatedEntity::RegisterForLogicUpdate(1);
}


// address=[0x154f180]
// Decompiled from void __thiscall IFlyingEntity::Delete(IFlyingEntity *this)
void  IFlyingEntity::Delete(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-3Ch]
  _BYTE v5[24]; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v6; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v7; // [esp+20h] [ebp-14h]
  unsigned __int16 *v8; // [esp+24h] [ebp-10h]
  int v9; // [esp+30h] [ebp-4h]

  v8 = (unsigned __int16 *)this;
  v4 = IAnimatedEntity::AttackerPlayerId();
  v1 = IEntity::EntityId(v8);
  v7 = CEntityEvent::CEntityEvent((CEntityEvent *)v5, 9u, 0, v1, v4, 0);
  v6 = v7;
  v9 = 0;
  CObserverList::NotifyAndDetachAllObservers((CObserverList *)(v8 + 42), v7);
  v9 = -1;
  CEntityEvent::~CEntityEvent(v5);
  v2 = IEntity::ID();
  CTrace::Print("FlyingEntity: DetachAllObservers for ID %i called!", v2);
  v3 = IEntity::ID();
  CFlyingMgr::CheckOutFlyingEntity((CFlyingMgr *)g_cFlyingMgr, v3);
}


// address=[0x154f230]
// Decompiled from void __thiscall IFlyingEntity::Attach(IFlyingEntity *this, int a2)
void  IFlyingEntity::Attach(int a2) {
  
  int v2; // eax

  v2 = IEntity::EntityId((unsigned __int16 *)this);
  CObserverList::Attach((IFlyingEntity *)((char *)this + 84), v2, a2);
}


// address=[0x154f260]
// Decompiled from int __thiscall IFlyingEntity::Detach(IFlyingEntity *this, int a2)
void  IFlyingEntity::Detach(int a2) {
  
  IFlyingEntity::DetachWithoutNotify(this, a2);
  return (*(int (__thiscall **)(IFlyingEntity *, int))(*(_DWORD *)this + 120))(this, a2);
}


// address=[0x154f290]
// Decompiled from int __thiscall IFlyingEntity::Notify(IFlyingEntity *this, const struct CEntityEvent *a2)
void  IFlyingEntity::Notify(class CEntityEvent const & a2)const {
  
  return CObserverList::NotifyAllObservers((char *)this + 84, (int)a2);
}


// address=[0x154f3e0]
// Decompiled from void __thiscall IFlyingEntity::~IFlyingEntity(IFlyingEntity *this)
 IFlyingEntity::~IFlyingEntity(void) {
  
  *(_DWORD *)this = &IFlyingEntity::_vftable_;
  CObserverList::~CObserverList((IFlyingEntity *)((char *)this + 84));
  IAnimatedEntity::~IAnimatedEntity(this);
}


// address=[0x154f460]
// Decompiled from IFlyingEntity *__thiscall IFlyingEntity::SetFlyingFlagBits(IFlyingEntity *this, __int16 a2)
void  IFlyingEntity::SetFlyingFlagBits(int a2) {
  
  IFlyingEntity *result; // eax

  result = this;
  *((_WORD *)this + 40) |= a2;
  return result;
}


// address=[0x1554fe0]
// Decompiled from IFlyingEntity *__thiscall IFlyingEntity::ClearFlyingFlagBits(IFlyingEntity *this, __int16 a2)
void  IFlyingEntity::ClearFlyingFlagBits(int a2) {
  
  IFlyingEntity *result; // eax

  result = this;
  *((_WORD *)this + 40) &= ~a2;
  return result;
}


// address=[0x154f2b0]
// Decompiled from void __thiscall IFlyingEntity::DetachWithoutNotify(IFlyingEntity *this, int a2)
void  IFlyingEntity::DetachWithoutNotify(int a2) {
  
  CObserverList::Detach((IFlyingEntity *)((char *)this + 84), a2);
}


// address=[0x154f450]
// Decompiled from void __thiscall IFlyingEntity::NotifyDetach(IFlyingEntity *this, int a2)
void  IFlyingEntity::NotifyDetach(int a2) {
  
  ;
}


