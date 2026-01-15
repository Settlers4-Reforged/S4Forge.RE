#include "CFilter.h"

// Definitions for class CFilter

// address=[0x2f393d0]
// Decompiled from CFilter *__thiscall CFilter::CFilter(CFilter *this, int a2)
 CFilter::CFilter(int) {
  
  CDynList *v3; // [esp+8h] [ebp-18h]
  CDynList *C; // [esp+Ch] [ebp-14h]

  *(_DWORD *)this = &CFilter::_vftable_;
  C = (CDynList *)operator new(0xCu);
  if ( C )
    v3 = CDynList::CDynList(C);
  else
    v3 = 0;
  *((_DWORD *)this + 1) = v3;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = 0;
  return this;
}


// address=[0x2f39480]
// Decompiled from void *__thiscall CFilter::~CFilter(CFilter *this)
 CFilter::~CFilter(void) {
  
  void *result; // eax

  *(_DWORD *)this = &CFilter::_vftable_;
  result = (void *)*((_DWORD *)this + 1);
  if ( result )
    return delete *((CDynList **)this + 1);
  return result;
}


// address=[0x2f394d0]
// Decompiled from char __userpurge CFilter::AddFilterEntry@<al>(CDynList **this@<ecx>, double a2@<st0>, struct IFilterEntry *a3)
bool  CFilter::AddFilterEntry(class IFilterEntry *) {
  
  int v4; // [esp+10h] [ebp-24h]
  struct CDynListEntry *v5; // [esp+14h] [ebp-20h]
  int v6; // [esp+18h] [ebp-1Ch]
  int v7; // [esp+20h] [ebp-14h]
  struct CDynListEntry *Entry; // [esp+28h] [ebp-Ch]
  char v10; // [esp+33h] [ebp-1h]

  v6 = 1;
  v10 = 0;
  Entry = CDynList::FirstEntry(this[1]);
  v5 = CDynList::FirstEntry(this[1]);
  (*(void (__thiscall **)(struct IFilterEntry *))(*(_DWORD *)a3 + 8))(a3);
  v4 = (int)a2;
  if ( (int)a2 >= (int)this[4] )
  {
    while ( Entry )
    {
      v7 = (int)((double (__thiscall *)(struct CDynListEntry *))*(_DWORD *)(*(_DWORD *)Entry + 8))(Entry);
      if ( v7 < v4 && !v10 )
      {
        *((_DWORD *)a3 + 1) = Entry;
        if ( Entry == *(struct CDynListEntry **)this[1] )
          *(_DWORD *)this[1] = a3;
        else
          *((_DWORD *)v5 + 1) = a3;
        ++*((_DWORD *)this[1] + 1);
        v10 = 1;
      }
      v5 = Entry;
      Entry = (struct CDynListEntry *)*((_DWORD *)Entry + 1);
      if ( v6 > (int)this[3] )
      {
        this[4] = (CDynList *)v7;
        if ( !v10 && a3 )
          (**(void (__thiscall ***)(struct IFilterEntry *, int))a3)(a3, 1);
        return v10;
      }
      ++v6;
    }
    if ( !v10 )
    {
      if ( *(_DWORD *)this[1] )
        *((_DWORD *)v5 + 1) = a3;
      else
        *(_DWORD *)this[1] = a3;
      ++*((_DWORD *)this[1] + 1);
      v10 = 1;
    }
    if ( *((_DWORD *)this[1] + 1) <= (int)this[3] )
      this[2] = (CDynList *)*((_DWORD *)this[1] + 1);
    return v10;
  }
  else
  {
    if ( a3 )
      (**(void (__thiscall ***)(struct IFilterEntry *, int))a3)(a3, 1);
    return 0;
  }
}


// address=[0x2f396b0]
// Decompiled from struct CDynListEntry *__thiscall CFilter::GetFilterEntry(CDynList **this, int a2)
class IFilterEntry *  CFilter::GetFilterEntry(int) {
  
  int v3; // [esp+4h] [ebp-8h]
  struct CDynListEntry *Entry; // [esp+8h] [ebp-4h]

  Entry = CDynList::FirstEntry(this[1]);
  v3 = 0;
  while ( Entry )
  {
    if ( v3 == a2 )
      return Entry;
    ++v3;
    Entry = (struct CDynListEntry *)*((_DWORD *)Entry + 1);
  }
  return 0;
}


