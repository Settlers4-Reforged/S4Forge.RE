#include "CGuiChatMsgList.h"

// Definitions for class CGuiChatMsgList

// address=[0x139fea0]
// Decompiled from CGuiChatMsgList *__thiscall CGuiChatMsgList::CGuiChatMsgList(CGuiChatMsgList *this)
 CGuiChatMsgList::CGuiChatMsgList(void) {
  
  *((_DWORD *)this + 10030) = -1;
  *((_DWORD *)this + 10031) = 0;
  *((_DWORD *)this + 10032) = 0;
  *((_DWORD *)this + 10033) = 0;
  return this;
}


// address=[0x139fef0]
// Decompiled from char __thiscall CGuiChatMsgList::AddListItem(int *this, char *Str)
bool  CGuiChatMsgList::AddListItem(char const *) {
  
  if ( this[10031] >= 200 )
    CGuiChatMsgList::RemoveListItem((CGuiChatMsgList *)this, 0);
  if ( j__strlen(Str) > 0xC8 )
    return 0;
  j__strcpy_0((char *)&this[50 * this[10031]++ + 30], Str);
  return 1;
}


// address=[0x139ff70]
// Decompiled from char __thiscall CGuiChatMsgList::SetListindex(_DWORD *this, int a2)
bool  CGuiChatMsgList::SetListindex(int) {
  
  if ( a2 >= this[10031] )
    this[10030] = this[10031] - 1;
  else
    this[10030] = a2;
  return 1;
}


// address=[0x139ffb0]
// Decompiled from char __thiscall CGuiChatMsgList::SetTopindex(CGuiChatMsgList *this, int a2)
bool  CGuiChatMsgList::SetTopindex(int) {
  
  int j; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  for ( i = 0; i < *((_DWORD *)this + 10032); ++i )
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 3 * i), *((_DWORD *)this + 3 * i + 1), 0);
  if ( a2 >= *((_DWORD *)this + 10031) )
  {
    *((_DWORD *)this + 10033) = *((_DWORD *)this + 10031) - 1;
  }
  else
  {
    if ( a2 < 0 )
      a2 = 0;
    *((_DWORD *)this + 10033) = a2;
  }
  v4 = *((_DWORD *)this + 10033);
  for ( j = *((_DWORD *)this + 10032) - 1; j >= 0 && v4 >= 0; j = CGuiChatMsgList::SetListentry(this, v4--, j) )
    ;
  return 1;
}


// address=[0x13a0090]
// Decompiled from char __thiscall CGuiChatMsgList::RemoveListItem(CGuiChatMsgList *this, int a2)
bool  CGuiChatMsgList::RemoveListItem(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  if ( a2 >= *((_DWORD *)this + 10031) )
    return 0;
  v3 = *((_DWORD *)this + 10031) - 1;
  if ( a2 < v3 )
  {
    for ( i = a2; i < v3; ++i )
      j__strcpy_0((char *)this + 200 * i + 120, (const char *)this + 200 * i + 320);
  }
  --*((_DWORD *)this + 10031);
  if ( a2 >= *((_DWORD *)this + 10033) )
    CGuiChatMsgList::SetTopindex(this, *((_DWORD *)this + 10033));
  else
    CGuiChatMsgList::SetTopindex(this, *((_DWORD *)this + 10033) - 1);
  return 1;
}


// address=[0x13a0160]
// Decompiled from char __thiscall CGuiChatMsgList::Clear(CGuiChatMsgList *this)
bool  CGuiChatMsgList::Clear(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 200; ++i )
    j__strcpy_0((char *)this + 200 * i + 120, &byte_368FC5F);
  *((_DWORD *)this + 10031) = 0;
  *((_DWORD *)this + 10030) = -1;
  return 1;
}


// address=[0x13a01d0]
// Decompiled from char __thiscall CGuiChatMsgList::SetOutputControls(CGuiChatMsgList *this, int a2, struct CGuiChatMsgList::SControl *a3)
bool  CGuiChatMsgList::SetOutputControls(int,struct CGuiChatMsgList::SControl *) {
  
  _DWORD *v3; // edx
  _DWORD *v4; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 10032); ++i )
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 3 * i), *((_DWORD *)this + 3 * i + 1), 0);
  for ( j = 0; j < a2; ++j )
  {
    v3 = (_DWORD *)((char *)a3 + 12 * j);
    v4 = (_DWORD *)((char *)this + 12 * j);
    *v4 = *v3;
    v4[1] = v3[1];
    v4[2] = v3[2];
  }
  *((_DWORD *)this + 10032) = a2;
  return 1;
}


// address=[0x13a0270]
// Decompiled from int __thiscall CGuiChatMsgList::SetListentry(CGuiChatMsgList *this, int a2, int a3)
int  CGuiChatMsgList::SetListentry(int,int) {
  
  signed int Count; // [esp+0h] [ebp-E0h]
  size_t Counta; // [esp+0h] [ebp-E0h]
  char v6; // [esp+7h] [ebp-D9h]
  const unsigned __int8 *Ptr; // [esp+8h] [ebp-D8h]
  unsigned __int8 *Ptra; // [esp+8h] [ebp-D8h]
  int v10; // [esp+10h] [ebp-D0h]
  char Destination[200]; // [esp+14h] [ebp-CCh] BYREF

  v10 = a3;
  j__strcpy_0(Destination, (const char *)this + 200 * a2 + 120);
  IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)this + 3 * v10), *((_DWORD *)this + 3 * v10 + 1), Destination);
  IGuiEngine::SetControlVisibility(
    (void *)g_pGUIEngine,
    *((_DWORD *)this + 3 * v10),
    *((_DWORD *)this + 3 * v10 + 1),
    1);
  *((_DWORD *)this + 3 * a3 + 2) = a2;
  Count = IGuiEngine::GetWrapPosition(
            (IGuiEngine *)g_pGUIEngine,
            *((_DWORD *)this + 3 * v10),
            *((_DWORD *)this + 3 * v10 + 1));
  if ( Count <= 0 )
    return v10 - 1;
  Counta = Count - 1;
  for ( Ptr = j___mbsninc((const unsigned __int8 *)Destination, Counta);
        Ptr > (const unsigned __int8 *)Destination && j___mbsncmp(Ptr, &byte_3690324, 1u);
        Ptr = j___mbsdec((const unsigned __int8 *)Destination, Ptr) )
  {
    ;
  }
  if ( j___mbsncmp(Ptr, &byte_369038C, 1u) )
    Ptra = j___mbsninc((const unsigned __int8 *)Destination, Counta);
  else
    Ptra = j___mbsinc(Ptr);
  v6 = *Ptra;
  *Ptra = 0;
  if ( a3 <= 0 )
  {
    *Ptra = v6;
    IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)this + 3 * a3), *((_DWORD *)this + 3 * a3 + 1), (char *)Ptra);
  }
  else
  {
    IGuiEngine::SetText(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 3 * a3 - 3),
      *((_DWORD *)this + 3 * a3 - 2),
      Destination);
    IGuiEngine::SetControlVisibility(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 3 * a3 - 3),
      *((_DWORD *)this + 3 * a3 - 2),
      1);
    *((_DWORD *)this + 3 * a3 - 1) = a2;
    *Ptra = v6;
    IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)this + 3 * a3), *((_DWORD *)this + 3 * a3 + 1), (char *)Ptra);
    v10 = a3 - 1;
  }
  return v10 - 1;
}


// address=[0x13a40f0]
// Decompiled from void __thiscall CGuiChatMsgList::~CGuiChatMsgList(CGuiChatMsgList *this)
 CGuiChatMsgList::~CGuiChatMsgList(void) {
  
  ;
}


// address=[0x13a4120]
// Decompiled from int __thiscall CGuiChatMsgList::GetTopindex(CGuiChatMsgList *this)
int  CGuiChatMsgList::GetTopindex(void) {
  
  return *((_DWORD *)this + 10033);
}


// address=[0x13a4230]
// Decompiled from int __thiscall CGuiChatMsgList::Listcount(CGuiChatMsgList *this)
int  CGuiChatMsgList::Listcount(void) {
  
  return *((_DWORD *)this + 10031);
}


