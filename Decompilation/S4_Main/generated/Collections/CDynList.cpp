#include "CDynList.h"

// Definitions for class CDynList

// address=[0x2f3bb50]
// Decompiled from int __thiscall CDynList::FirstEntry(CDynList *this)
class CDynListEntry *  CDynList::FirstEntry(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x2f3c7e0]
// Decompiled from CDynList *__thiscall CDynList::CDynList(CDynList *this)
 CDynList::CDynList(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}


// address=[0x2f3c810]
// Decompiled from void __thiscall CDynList::~CDynList(CDynList *this)
 CDynList::~CDynList(void) {
  
  CDynList::ClearDynList(this);
}


// address=[0x2f3c850]
// Decompiled from int __thiscall CDynList::addElement(CDynList *this, struct CDynListEntry *a2)
int  CDynList::addElement(class CDynListEntry * a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = *(_DWORD *)this;
  if ( *(_DWORD *)this )
  {
    while ( *(_DWORD *)(v3 + 4) )
      v3 = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v3 + 4) = a2;
    *((_DWORD *)a2 + 1) = 0;
    *((_DWORD *)this + 2) = a2;
  }
  else
  {
    *(_DWORD *)this = a2;
    *((_DWORD *)this + 2) = a2;
    *((_DWORD *)a2 + 1) = 0;
  }
  CDynList::resize(this);
  return 1;
}


// address=[0x2f3c8d0]
// Decompiled from int __thiscall CDynList::insertElementAt(CDynList *this, struct CDynListEntry *a2, int a3)
int  CDynList::insertElementAt(class CDynListEntry * a2, int a3) {
  
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  v5 = *(_DWORD *)this;
  v4 = *(_DWORD *)this;
  *((_DWORD *)a2 + 1) = 0;
  if ( *((_DWORD *)this + 1) > a3 )
  {
    while ( v5 )
    {
      if ( *(_DWORD *)(v5 + 8) == a3 )
      {
        *((_DWORD *)a2 + 1) = v5;
        if ( a3 )
          *(_DWORD *)(v4 + 4) = a2;
        else
          *(_DWORD *)this = a2;
        break;
      }
      v4 = v5;
      v5 = *(_DWORD *)(v5 + 4);
    }
    CDynList::resize(this);
    return *((_DWORD *)this + 1);
  }
  else
  {
    CDynList::addElement(this, a2);
    CDynList::resize(this);
    return *((_DWORD *)this + 1);
  }
}


// address=[0x2f3c980]
// Decompiled from int __thiscall CDynList::elementAt(CDynList *this, int a2)
class CDynListEntry *  CDynList::elementAt(int a2) {
  
  int v3; // [esp+4h] [ebp-4h]

  if ( *((_DWORD *)this + 2) && *(_DWORD *)(*((_DWORD *)this + 2) + 8) <= a2 )
    v3 = *((_DWORD *)this + 2);
  else
    v3 = *(_DWORD *)this;
  while ( v3 )
  {
    if ( a2 == *(_DWORD *)(v3 + 8) )
      return v3;
    v3 = *(_DWORD *)(v3 + 4);
  }
  return 0;
}


// address=[0x2f3c9f0]
// Decompiled from int __thiscall CDynList::resize(CDynList *this)
int  CDynList::resize(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  v3 = 0;
  v2 = *(_DWORD *)this;
  if ( *(_DWORD *)this )
  {
    v3 = 1;
    *(_DWORD *)(v2 + 8) = 0;
    while ( *(_DWORD *)(v2 + 4) )
    {
      v2 = *(_DWORD *)(v2 + 4);
      *(_DWORD *)(v2 + 8) = v3++;
    }
  }
  *((_DWORD *)this + 1) = v3;
  return v3;
}


// address=[0x2f3ca60]
// Decompiled from int __thiscall CDynList::delElement(CDynList *this, int a2)
int  CDynList::delElement(int a2) {
  
  int v3; // [esp+18h] [ebp-Ch]
  int v4; // [esp+1Ch] [ebp-8h]

  v3 = *(_DWORD *)this;
  *((_DWORD *)this + 2) = 0;
  if ( *(_DWORD *)(*(_DWORD *)this + 8) == a2 )
  {
    v4 = *(_DWORD *)this;
    *(_DWORD *)this = *(_DWORD *)(*(_DWORD *)this + 4);
    if ( v4 )
LABEL_3:
      (**(void (__thiscall ***)(int, int))v4)(v4, 1);
  }
  else
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)(v3 + 4) )
        return 0;
      v4 = *(_DWORD *)(v3 + 4);
      if ( *(_DWORD *)(v4 + 8) == a2 )
        break;
      v3 = *(_DWORD *)(v3 + 4);
    }
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(v4 + 4);
    if ( v4 )
      goto LABEL_3;
  }
  CDynList::resize(this);
  return 1;
}


// address=[0x2f3cb60]
// Decompiled from int __thiscall CDynList::delElement(CDynList *this, struct CDynListEntry *a2)
int  CDynList::delElement(class CDynListEntry * a2) {
  
  return CDynList::delElement(this, *((_DWORD *)a2 + 2));
}


// address=[0x2f3cb80]
// Decompiled from CDynList *__thiscall CDynList::ClearDynList(CDynList *this)
void  CDynList::ClearDynList(void) {
  
  CDynList *result; // eax
  int v2; // [esp+0h] [ebp-1Ch]
  int v3; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]

  v3 = 0;
  for ( i = *(_DWORD *)this; i; i = v2 )
  {
    ++v3;
    v2 = *(_DWORD *)(i + 4);
    (**(void (__thiscall ***)(int, int))i)(i, 1);
  }
  if ( v3 != *((_DWORD *)this + 1)
    && BBSupportDbgReport(2, "Source\\DynList.cpp", 230, "iDbgCounter == m_iNumberOfElements") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)this = 0;
  result = this;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return result;
}


// address=[0x2f3cc30]
// Decompiled from int __thiscall CDynList::sort(CDynList *this, int a2)
int  CDynList::sort(int a2) {
  
  float v3; // [esp+0h] [ebp-20h]
  float v4; // [esp+8h] [ebp-18h]
  _DWORD *v5; // [esp+Ch] [ebp-14h]
  _DWORD *v7; // [esp+14h] [ebp-Ch]
  _DWORD *v8; // [esp+18h] [ebp-8h]
  char v9; // [esp+1Fh] [ebp-1h]

  v9 = 1;
  if ( !*(_DWORD *)this || !*(_DWORD *)(*(_DWORD *)this + 4) )
    return 0;
  while ( v9 )
  {
    v9 = 0;
    v5 = *(_DWORD **)this;
    v8 = *(_DWORD **)this;
    while ( v8[1] )
    {
      v7 = (_DWORD *)v8[1];
      v4 = ((double (__thiscall *)(_DWORD *, int))*(_DWORD *)(*v8 + 4))(v8, a2);
      v3 = ((double (__thiscall *)(_DWORD *, int))*(_DWORD *)(*v7 + 4))(v7, a2);
      if ( v4 <= v3 )
      {
        v5 = v8;
        v8 = (_DWORD *)v8[1];
      }
      else
      {
        if ( v8 == *(_DWORD **)this )
          *(_DWORD *)this = v7;
        else
          v5[1] = v7;
        v8[1] = v7[1];
        v7[1] = v8;
        v9 = 1;
        v5 = v7;
      }
    }
  }
  CDynList::resize(this);
  return 0;
}


// address=[0x2f404e0]
// Decompiled from BOOL __thiscall CDynList::isEmpty(CDynList *this)
int  CDynList::isEmpty(void) {
  
  return *((_DWORD *)this + 1) == 0;
}


// address=[0x2f40520]
// Decompiled from int __thiscall CDynList::size(CDynList *this)
int  CDynList::size(void) {
  
  return *((_DWORD *)this + 1);
}


