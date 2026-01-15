#include "CPlaylist.h"

// Definitions for class CPlaylist

// address=[0x2fd8e60]
// Decompiled from CPlaylist *__thiscall CPlaylist::CPlaylist(CPlaylist *this)
 CPlaylist::CPlaylist(void) {
  
  CPlaylist *v2; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &CPlaylist::_vftable_;
  std::vector<CPlaylist::SEntry *>::vector<CPlaylist::SEntry *>(this);
  *((_DWORD *)v2 + 5) = 0;
  *((_DWORD *)v2 + 6) = 0;
  *((_DWORD *)v2 + 7) = 0;
  *((_DWORD *)v2 + 8) = 0;
  *((_DWORD *)v2 + 9) = 0;
  return v2;
}


// address=[0x2fd8ec0]
// Decompiled from void __thiscall CPlaylist::~CPlaylist(CHandleMap *this)
 CPlaylist::~CPlaylist(void) {
  
  *(_DWORD *)this = &CPlaylist::_vftable_;
  CPlaylist::FreeMemory(this);
  std::vector<CPlaylist::SEntry *>::~vector<CPlaylist::SEntry *>();
}


// address=[0x2fd8f20]
// Decompiled from int __thiscall CPlaylist::Init(CPlaylist *this, int a2)
void  CPlaylist::Init(int) {
  
  int result; // eax

  CPlaylist::FreeMemory(this);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  result = a2;
  *((_DWORD *)this + 8) = a2;
  return result;
}


// address=[0x2fd8f60]
// Decompiled from int __thiscall CPlaylist::AddTitle(_DWORD *this, int a2, int a3)
void  CPlaylist::AddTitle(std::string const *,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-10h]
  CPlaylist::SEntry *v5; // [esp+4h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v5 = (CPlaylist::SEntry *)operator new(0x20u);
  if ( v5 )
    v4 = CPlaylist::SEntry::SEntry(v5);
  else
    v4 = 0;
  v7 = v4;
  std::string::operator=(a2);
  *(_DWORD *)(v4 + 28) = a3;
  std::vector<CPlaylist::SEntry *>::push_back(&v7);
  result = this[5] + 1;
  this[5] = result;
  return result;
}


// address=[0x2fd8fd0]
// Decompiled from CPlaylist *__thiscall CPlaylist::TitleEnded(CPlaylist *this)
void  CPlaylist::TitleEnded(void) {
  
  CPlaylist *result; // eax

  if ( *((int *)this + 5) <= 1 )
    ++*((_DWORD *)this + 6);
  else
    *((_DWORD *)this + 6) += j__rand() % (*((_DWORD *)this + 5) - 1) + 1;
  result = (CPlaylist *)*((_DWORD *)this + 6);
  if ( (int)result < *((_DWORD *)this + 5) )
    return result;
  result = (CPlaylist *)(*((_DWORD *)this + 6) - *((_DWORD *)this + 5));
  *((_DWORD *)this + 6) = result;
  if ( !*((_DWORD *)this + 8) )
    return result;
  result = this;
  ++*((_DWORD *)this + 7);
  return result;
}


// address=[0x2fd9050]
// Decompiled from int __thiscall CPlaylist::GetStreamPos(_DWORD *this)
int  CPlaylist::GetStreamPos(void) {
  
  return AIL_stream_position(this[11]);
}


// address=[0x2fd9070]
// Decompiled from int __thiscall CPlaylist::SetStreamPos(_DWORD *this, int a2)
void  CPlaylist::SetStreamPos(int) {
  
  return AIL_set_stream_position(this[11], a2);
}


// address=[0x2fd9090]
// Decompiled from int __thiscall CPlaylist::StoreStreamPos(CPlaylist *this)
void  CPlaylist::StoreStreamPos(void) {
  
  int result; // eax

  result = AIL_stream_position(*((_DWORD *)this + 11));
  *((_DWORD *)this + 9) = result;
  return result;
}


// address=[0x2fd90b0]
// Decompiled from int __thiscall CPlaylist::ResumeOnLastPos(CPlaylist *this)
void  CPlaylist::ResumeOnLastPos(void) {
  
  return AIL_set_stream_position(*((_DWORD *)this + 11), *((_DWORD *)this + 9));
}


// address=[0x2fd90d0]
// Decompiled from int __thiscall CPlaylist::GetPlayingTitleNum(CPlaylist *this)
int  CPlaylist::GetPlayingTitleNum(void) {
  
  return *((_DWORD *)this + 6);
}


// address=[0x2fd90f0]
// Decompiled from int __thiscall CPlaylist::GetTitle(_DWORD *this, int a2)
char const *  CPlaylist::GetTitle(int) {
  
  void **v2; // eax

  if ( a2 >= this[5] )
    return 0;
  v2 = (void **)std::vector<CPlaylist::SEntry *>::operator[](a2);
  return std::string::c_str(*v2);
}


// address=[0x2fd9130]
// Decompiled from int __thiscall CPlaylist::GetActiveTitle(CPlaylist *this)
char const *  CPlaylist::GetActiveTitle(void) {
  
  void **v1; // eax

  if ( !*((_DWORD *)this + 5) )
    return 0;
  v1 = (void **)std::vector<CPlaylist::SEntry *>::operator[](*((_DWORD *)this + 6));
  return std::string::c_str(*v1);
}


// address=[0x2fd9170]
// Decompiled from CPlaylist *__thiscall CPlaylist::SetTrackID(CPlaylist *this, unsigned int a2)
void  CPlaylist::SetTrackID(unsigned int) {
  
  CPlaylist *result; // eax

  result = this;
  *((_DWORD *)this + 10) = a2;
  return result;
}


// address=[0x2fd9190]
// Decompiled from int __thiscall CPlaylist::GetTrackID(CPlaylist *this)
unsigned int  CPlaylist::GetTrackID(void) {
  
  return *((_DWORD *)this + 10);
}


// address=[0x2fd91b0]
// Decompiled from CPlaylist *__thiscall CPlaylist::SetTitle(CPlaylist *this, int a2)
void  CPlaylist::SetTitle(int) {
  
  CPlaylist *result; // eax

  result = this;
  if ( a2 < *((_DWORD *)this + 5) )
  {
    result = this;
    *((_DWORD *)this + 6) = a2;
  }
  else
  {
    *((_DWORD *)this + 6) = 0;
  }
  return result;
}


// address=[0x2fd91e0]
// Decompiled from void __thiscall CPlaylist::SetHandle(CMFCCaptionButton *this, int a2)
void  CPlaylist::SetHandle(struct _STREAM *) {
  
  *((_DWORD *)this + 11) = a2;
}


// address=[0x2fd9200]
// Decompiled from int __thiscall CPlaylist::GetFadeInTime(CPlaylist *this, int a2)
int  CPlaylist::GetFadeInTime(int) {
  
  if ( a2 < *((_DWORD *)this + 5) )
    return *(_DWORD *)(*(_DWORD *)std::vector<CPlaylist::SEntry *>::operator[](a2) + 28);
  else
    return 0;
}


// address=[0x2fd9240]
// Decompiled from int __thiscall CPlaylist::SkipTitle(CPlaylist *this)
void  CPlaylist::SkipTitle(void) {
  
  _BYTE v2[4]; // [esp+0h] [ebp-14h] BYREF
  _BYTE v3[4]; // [esp+4h] [ebp-10h] BYREF
  _BYTE v4[4]; // [esp+8h] [ebp-Ch] BYREF
  int v5; // [esp+Ch] [ebp-8h] BYREF
  CPlaylist *v6; // [esp+10h] [ebp-4h]

  v6 = this;
  AIL_stream_info(*((_DWORD *)this + 11), v2, v3, &v5, v4);
  return AIL_set_stream_position(*((_DWORD *)v6 + 11), v5 - 200);
}


// address=[0x2fd8d30]
// Decompiled from int __thiscall CPlaylist::FreeMemory(CPlaylist *this)
void  CPlaylist::FreeMemory(void) {
  
  _DWORD v2[4]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE v3[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-44h] BYREF
  int v6; // [esp+28h] [ebp-38h]
  _DWORD *v7; // [esp+2Ch] [ebp-34h]
  int v8; // [esp+30h] [ebp-30h]
  int v9; // [esp+34h] [ebp-2Ch]
  void *v10; // [esp+38h] [ebp-28h]
  CPlaylist::SEntry *v11; // [esp+3Ch] [ebp-24h]
  std::_Iterator_base12 *v12; // [esp+40h] [ebp-20h]
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-1Ch]
  CPlaylist::SEntry *v14; // [esp+48h] [ebp-18h]
  CPlaylist *v15; // [esp+4Ch] [ebp-14h]
  char v16; // [esp+53h] [ebp-Dh]
  int v17; // [esp+5Ch] [ebp-4h]

  v15 = this;
  std::vector<CPlaylist::SEntry *>::begin(v5);
  v17 = 0;
  while ( 1 )
  {
    v13 = (std::_Iterator_base12 *)std::vector<CPlaylist::SEntry *>::end(v4);
    v12 = v13;
    LOBYTE(v17) = 1;
    v16 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::operator!=(v13);
    LOBYTE(v17) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>(v4);
    if ( !v16 )
      break;
    v11 = *(CPlaylist::SEntry **)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::operator*(v5);
    v14 = v11;
    if ( v11 )
      v10 = CPlaylist::delete v14;
    else
      v10 = 0;
    v7 = v2;
    v6 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>((struct std::_Iterator_base12 *)v5);
    v9 = std::vector<CPlaylist::SEntry *>::erase(v3, v2[0], v2[1], v2[2]);
    v8 = v9;
    LOBYTE(v17) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::operator=(v9);
    LOBYTE(v17) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>(v3);
  }
  *((_DWORD *)v15 + 5) = 0;
  v17 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CPlaylist::SEntry *>>>(v5);
}


