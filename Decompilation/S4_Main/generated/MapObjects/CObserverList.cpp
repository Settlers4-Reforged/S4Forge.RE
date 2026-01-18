#include "CObserverList.h"

// Definitions for class CObserverList

// address=[0x14eafe0]
// Decompiled from CObserverList *__thiscall CObserverList::CObserverList(CObserverList *this)
 CObserverList::CObserverList(void) {
  
  std::list<unsigned short>::list<unsigned short>(this);
  return this;
}


// address=[0x14eb0e0]
// Decompiled from int __thiscall CObserverList::~CObserverList(CObserverList *this)
 CObserverList::~CObserverList(void) {
  
  return std::list<unsigned short>::~list<unsigned short>(this);
}


// address=[0x14eb6c0]
// Decompiled from void __thiscall CObserverList::NotifyAndDetachAllObservers(CObserverList *this, const struct CEntityEvent *a2)
void  CObserverList::NotifyAndDetachAllObservers(class CEntityEvent const & a2) {
  
  CObserverList::NotifyAllObservers(this, (int)a2);
  CObserverList::DetachAllObservers(this);
}


// address=[0x1559aa0]
// Decompiled from int __thiscall CObserverList::Attach(CObserverList *this, int a2, int a3)
void  CObserverList::Attach(int a2, int a3) {
  
  int result; // eax
  _DWORD *v5; // [esp+4h] [ebp-8h]
  __int16 v6; // [esp+Ah] [ebp-2h] BYREF

  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 29, "_iObserverId > 0") == 1 )
    __debugbreak();
  if ( CObserverList::IsInList(this, a3)
    && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 31, "!IsInList(_iObserverId)") == 1 )
  {
    __debugbreak();
  }
  v6 = a3;
  std::list<unsigned short>::push_back(&v6);
  v5 = (_DWORD *)CMapObjectMgr::EntityPtr(a3);
  if ( !v5 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 37, "pObserver != 0") == 1 )
    __debugbreak();
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*v5 + 72))(v5, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\ObserverList.cpp",
         39,
         "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(v5, EntityFlag_Attached)
    && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 40, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*v5 + 68))(v5, 0, a2);
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*v5 + 72))(v5, 0) != a2
    && BBSupportDbgReport(
         2,
         "MapObjects\\ObserverList.cpp",
         44,
         "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) == _iTargetId") == 1 )
  {
    __debugbreak();
  }
  result = IEntity::FlagBits(v5, EntityFlag_Attached);
  if ( result )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 45, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) != 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1559c20]
// Decompiled from int __thiscall CObserverList::Detach(CObserverList *this, int a2)
void  CObserverList::Detach(int a2) {
  
  int result; // eax
  _DWORD *v4; // [esp+4h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 55, "_iObserverId > 0") == 1 )
    __debugbreak();
  if ( !CObserverList::Remove(this, a2) && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 59, "bRemoveOk") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CMapObjectMgr::EntityPtr(a2);
  if ( !v4 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 63, "pObserver != 0") == 1 )
    __debugbreak();
  if ( !(*(int (__thiscall **)(_DWORD *, _DWORD))(*v4 + 72))(v4, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\ObserverList.cpp",
         65,
         "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(v4, EntityFlag_Attached)
    && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 66, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v4 + 68))(v4, 0, 0);
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*v4 + 72))(v4, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\ObserverList.cpp",
         70,
         "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) == 0") == 1 )
  {
    __debugbreak();
  }
  result = IEntity::FlagBits(v4, EntityFlag_Attached);
  if ( !result )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 71, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) == 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x1559d80]
// Decompiled from int __thiscall CObserverList::NotifyAllObservers(void *this, int a2)
void  CObserverList::NotifyAllObservers(class CEntityEvent const & a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-30h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-24h] BYREF
  struct IEntity *v6; // [esp+28h] [ebp-18h]
  int v7; // [esp+2Ch] [ebp-14h]
  void *v8; // [esp+30h] [ebp-10h]
  int v9; // [esp+3Ch] [ebp-4h]

  v8 = this;
  std::list<unsigned short>::begin(v3);
  v9 = 0;
  std::list<unsigned short>::end(v4);
  LOBYTE(v9) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  LOBYTE(v9) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v4) )
  {
    v7 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v5);
    if ( v7 <= 0 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 159, "iEntityId > 0") == 1 )
      __debugbreak();
    v6 = CMapObjectMgr::Entity(v7);
    ((void (__thiscall *)(struct IEntity *, int))v6->CPersistence[1].GetNamedEntity)(v6, a2);
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v5);
  }
  LOBYTE(v9) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
  LOBYTE(v9) = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
  v9 = -1;
  return std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
}


// address=[0x1559e90]
// Decompiled from int __thiscall CObserverList::NotifyAllObservers(  CObserverList *this,  const struct CEntityEvent *a2,  struct INotifyFilter *a3)
void  CObserverList::NotifyAllObservers(class CEntityEvent const & a2, class INotifyFilter & a3)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-30h] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-24h] BYREF
  int v7; // [esp+28h] [ebp-18h]
  CObserverList *v8; // [esp+2Ch] [ebp-14h]
  struct IEntity *v9; // [esp+30h] [ebp-10h]
  int v10; // [esp+3Ch] [ebp-4h]

  v8 = this;
  std::list<unsigned short>::begin(v4);
  v10 = 0;
  std::list<unsigned short>::end(v5);
  LOBYTE(v10) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
  LOBYTE(v10) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v5) )
  {
    v7 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v6);
    if ( v7 <= 0 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 181, "iEntityId > 0") == 1 )
      __debugbreak();
    v9 = CMapObjectMgr::Entity(v7);
    if ( (**(unsigned __int8 (__thiscall ***)(struct INotifyFilter *, struct IEntity *))a3)(a3, v9) )
      ((void (__thiscall *)(struct IEntity *, const struct CEntityEvent *))v9->CPersistence[1].GetNamedEntity)(v9, a2);
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v6);
  }
  LOBYTE(v10) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v6);
  LOBYTE(v10) = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
  v10 = -1;
  return std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
}


// address=[0x1559fb0]
// Decompiled from int __thiscall CObserverList::DetachAllObservers(CObserverList *this)
void  CObserverList::DetachAllObservers(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v4[12]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v5[12]; // [esp+28h] [ebp-44h] BYREF
  _BYTE v6[12]; // [esp+34h] [ebp-38h] BYREF
  int v7; // [esp+40h] [ebp-2Ch]
  int v8; // [esp+44h] [ebp-28h]
  int v9; // [esp+48h] [ebp-24h]
  int v10; // [esp+4Ch] [ebp-20h]
  _DWORD *v11; // [esp+50h] [ebp-1Ch]
  void *v12; // [esp+54h] [ebp-18h]
  int v13; // [esp+58h] [ebp-14h]
  _DWORD *v14; // [esp+5Ch] [ebp-10h]
  int v15; // [esp+68h] [ebp-4h]

  v12 = this;
  v10 = std::list<unsigned short>::begin(v3);
  v9 = v10;
  v15 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v10);
  LOBYTE(v15) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  v8 = std::list<unsigned short>::end(v2);
  v7 = v8;
  LOBYTE(v15) = 3;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v8);
  LOBYTE(v15) = 5;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v2);
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
  LOBYTE(v15) = 6;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v5) )
  {
    v13 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v6);
    if ( v13 )
      v11 = (_DWORD *)CMapObjectMgr::EntityPtr(v13);
    else
      v11 = 0;
    v14 = v11;
    if ( v11 )
    {
      if ( !(*(int (__thiscall **)(_DWORD *, _DWORD))(*v14 + 72))(v14, 0)
        && BBSupportDbgReport(
             2,
             "MapObjects\\ObserverList.cpp",
             92,
             "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) != 0") == 1 )
      {
        __debugbreak();
      }
      if ( !IEntity::FlagBits(v14, EntityFlag_Attached)
        && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 93, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v14 + 68))(v14, 0, 0);
      if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*v14 + 72))(v14, 0)
        && BBSupportDbgReport(
             2,
             "MapObjects\\ObserverList.cpp",
             97,
             "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) == 0") == 1 )
      {
        __debugbreak();
      }
      if ( IEntity::FlagBits(v14, EntityFlag_Attached) )
      {
        if ( BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 98, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
          __debugbreak();
      }
    }
    else if ( BBSupportDbgReportF(
                1,
                "MapObjects\\ObserverList.cpp",
                102,
                "CObserverList::DetachAllObservers(): Invalid entity id %i in list!",
                v13) == 1 )
    {
      __debugbreak();
    }
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v6);
  }
  LOBYTE(v15) = 5;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v6);
  std::list<unsigned short>::clear(v12);
  LOBYTE(v15) = 2;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
  v15 = -1;
  return std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
}


// address=[0x155a1e0]
// Decompiled from int __thiscall CObserverList::DetachAllNonePileObservers(CObserverList *this)
void  CObserverList::DetachAllNonePileObservers(void) {
  
  char v2; // [esp-Ch] [ebp-6Ch] BYREF
  int v3; // [esp-8h] [ebp-68h]
  int v4; // [esp-4h] [ebp-64h]
  _BYTE v5[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-44h] BYREF
  int v8; // [esp+28h] [ebp-38h]
  char *v9; // [esp+2Ch] [ebp-34h]
  int v10; // [esp+30h] [ebp-30h]
  int v11; // [esp+34h] [ebp-2Ch]
  std::_Iterator_base12 *v12; // [esp+38h] [ebp-28h]
  std::_Iterator_base12 *v13; // [esp+3Ch] [ebp-24h]
  unsigned __int8 *v14; // [esp+40h] [ebp-20h]
  int v15; // [esp+44h] [ebp-1Ch]
  CObserverList *v16; // [esp+48h] [ebp-18h]
  unsigned __int8 *v17; // [esp+4Ch] [ebp-14h]
  char v18; // [esp+53h] [ebp-Dh]
  int v19; // [esp+5Ch] [ebp-4h]

  v16 = this;
  std::list<unsigned short>::begin(v7);
  v19 = 0;
  while ( 1 )
  {
    v13 = (std::_Iterator_base12 *)std::list<unsigned short>::end(v6);
    v12 = v13;
    LOBYTE(v19) = 1;
    v18 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=(v13);
    LOBYTE(v19) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v6);
    if ( !v18 )
      break;
    v15 = *(unsigned __int16 *)std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v7);
    if ( v15 )
      v14 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v15);
    else
      v14 = 0;
    v17 = v14;
    if ( !v14 || IEntity::ObjType(v17) == 16 )
    {
      if ( !v17
        && BBSupportDbgReportF(
             2,
             "MapObjects\\ObserverList.cpp",
             138,
             "CObserverList::DetachAllObservers(): Invalid entity id %i in list!",
             v15) == 1 )
      {
        __debugbreak();
      }
      std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v7, 0);
    }
    else
    {
      if ( !(*(int (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v17 + 72))(v17, 0)
        && BBSupportDbgReport(
             2,
             "MapObjects\\ObserverList.cpp",
             126,
             "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) != 0") == 1 )
      {
        __debugbreak();
      }
      if ( !IEntity::FlagBits(v17, EntityFlag_Attached)
        && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 127, "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) != 0") == 1 )
      {
        __debugbreak();
      }
      (*(void (__thiscall **)(unsigned __int8 *, _DWORD, _DWORD))(*(_DWORD *)v17 + 68))(v17, 0, 0);
      if ( (*(int (__thiscall **)(unsigned __int8 *, _DWORD))(*(_DWORD *)v17 + 72))(v17, 0)
        && BBSupportDbgReport(
             2,
             "MapObjects\\ObserverList.cpp",
             131,
             "pObserver->GetObserverTarget(OBSERVER_TARGET_PRIMARY) == 0") == 1 )
      {
        __debugbreak();
      }
      if ( IEntity::FlagBits(v17, EntityFlag_Attached) )
      {
        if ( BBSupportDbgReport(
               2,
               "MapObjects\\ObserverList.cpp",
               132,
               "pObserver->FlagBits(ENTITY_FLAG_ATTACHED) == 0") == 1 )
          __debugbreak();
      }
      v9 = &v2;
      v8 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v7);
      v11 = std::list<unsigned short>::erase(v5, v2, v3, v4);
      v10 = v11;
      LOBYTE(v19) = 2;
      std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(v11);
      LOBYTE(v19) = 0;
      std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
    }
  }
  v19 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v7);
}


// address=[0x155a420]
// Decompiled from char __thiscall CObserverList::IsInList(CObserverList *this, int a2)
bool  CObserverList::IsInList(int a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-30h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-24h] BYREF
  int v6; // [esp+28h] [ebp-18h]
  CObserverList *v7; // [esp+2Ch] [ebp-14h]
  char v8; // [esp+32h] [ebp-Eh]
  char v9; // [esp+33h] [ebp-Dh]
  int v10; // [esp+3Ch] [ebp-4h]

  v7 = this;
  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 199, "_iObserverId > 0") == 1 )
    __debugbreak();
  if ( a2 > 0xFFFF && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 200, "_iObserverId <= 0xFFFF") == 1 )
    __debugbreak();
  std::list<unsigned short>::begin(v3);
  v10 = 0;
  std::list<unsigned short>::end(v4);
  LOBYTE(v10) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  LOBYTE(v10) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v4) )
  {
    v6 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v5);
    if ( v6 == a2 )
    {
      v9 = 1;
      LOBYTE(v10) = 1;
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
      LOBYTE(v10) = 0;
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
      v10 = -1;
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
      return v9;
    }
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v5);
  }
  LOBYTE(v10) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
  v8 = 0;
  LOBYTE(v10) = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
  v10 = -1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  return v8;
}


// address=[0x155a6b0]
// Decompiled from void *__thiscall CObserverList::CObserverList(void *this, int a2)
 CObserverList::CObserverList(std::istream & a2) {
  
  _DWORD v3[2]; // [esp+4h] [ebp-28h] BYREF
  int Version; // [esp+Ch] [ebp-20h]
  int pExceptionObject; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int i; // [esp+14h] [ebp-18h]
  void *v7; // [esp+18h] [ebp-14h]
  _BYTE v8[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  std::list<unsigned short>::list<unsigned short>(this);
  v9 = 0;
  std::list<unsigned short>::clear(v7);
  Version = Serial::LoadVersion(a2);
  v3[1] = Version;
  if ( Version != 1 )
  {
    BBSupportTracePrintF(3, "Unknown file format version for CObserverList!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned int>(a2, v3);
  for ( i = 0; i < v3[0]; ++i )
  {
    operator^<unsigned short>(a2, v8);
    std::list<unsigned short>::push_back(v8);
  }
  v9 = -1;
  return v7;
}


// address=[0x155a7a0]
// Decompiled from int __thiscall CObserverList::Store(void *this, struct std::ostream *a2)
void  CObserverList::Store(std::ostream & a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-64h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-58h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-4Ch] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-40h] BYREF
  _BYTE v7[12]; // [esp+34h] [ebp-34h] BYREF
  int v8; // [esp+40h] [ebp-28h]
  int v9; // [esp+44h] [ebp-24h]
  int v10; // [esp+48h] [ebp-20h]
  int v11; // [esp+4Ch] [ebp-1Ch]
  int v12; // [esp+50h] [ebp-18h] BYREF
  void *v13; // [esp+54h] [ebp-14h]
  __int16 v14; // [esp+58h] [ebp-10h] BYREF
  int v15; // [esp+64h] [ebp-4h]

  v13 = this;
  Serial::StoreVersion(a2, 1);
  v12 = std::list<unsigned short>::size(v13);
  operator^<unsigned int>(a2, &v12);
  v11 = std::list<unsigned short>::begin(v4);
  v10 = v11;
  v15 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v11);
  LOBYTE(v15) = 2;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v4);
  v9 = std::list<unsigned short>::end(v3);
  v8 = v9;
  LOBYTE(v15) = 3;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v9);
  LOBYTE(v15) = 5;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
  LOBYTE(v15) = 6;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v6) )
  {
    v14 = *(_WORD *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v7);
    operator^<unsigned short>((int)a2, &v14);
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v7);
  }
  LOBYTE(v15) = 5;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v7);
  LOBYTE(v15) = 2;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v6);
  v15 = -1;
  return std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v5);
}


// address=[0x155a570]
// Decompiled from char __thiscall CObserverList::Remove(CObserverList *this, int a2)
bool  CObserverList::Remove(int a2) {
  
  int v2; // edx
  char v4; // [esp-Ch] [ebp-64h] BYREF
  int v5; // [esp-8h] [ebp-60h]
  int v6; // [esp-4h] [ebp-5Ch]
  _BYTE v7[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v8[12]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v9[12]; // [esp+1Ch] [ebp-3Ch] BYREF
  _BYTE v10[12]; // [esp+28h] [ebp-30h] BYREF
  int v11; // [esp+34h] [ebp-24h]
  int v12; // [esp+38h] [ebp-20h]
  char *v13; // [esp+3Ch] [ebp-1Ch]
  int v14; // [esp+40h] [ebp-18h]
  CObserverList *v15; // [esp+44h] [ebp-14h]
  char v16; // [esp+4Ah] [ebp-Eh]
  char v17; // [esp+4Bh] [ebp-Dh]
  int v18; // [esp+54h] [ebp-4h]

  v15 = this;
  v17 = 0;
  std::list<unsigned short>::begin(v8);
  v18 = 0;
  std::list<unsigned short>::end(v9);
  LOBYTE(v18) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v8);
  LOBYTE(v18) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator!=((std::_Iterator_base12 *)v9) )
  {
    v2 = *(unsigned __int16 *)std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(v10);
    v14 = v2;
    if ( v2 == a2 )
    {
      v13 = &v4;
      v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v10);
      v11 = std::list<unsigned short>::erase(v7, v4, v5, v6);
      std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v7);
      v17 = 1;
      break;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(v10, v2);
  }
  LOBYTE(v18) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v10);
  if ( CObserverList::IsInList(v15, a2)
    && BBSupportDbgReport(2, "MapObjects\\ObserverList.cpp", 244, "!IsInList(_iObserverId)") == 1 )
  {
    __debugbreak();
  }
  v16 = 1;
  LOBYTE(v18) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v9);
  v18 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v8);
  return v16;
}


