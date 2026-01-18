#include "CGuiMsgList.h"

// Definitions for class CGuiMsgList

// address=[0x13b8320]
// Decompiled from CGuiMsgList *__thiscall CGuiMsgList::CGuiMsgList(CGuiMsgList *this)
 CGuiMsgList::CGuiMsgList(void) {
  
  *((_DWORD *)this + 25216) = -1;
  *((_DWORD *)this + 25217) = 0;
  *((_DWORD *)this + 25218) = 0;
  *((_DWORD *)this + 25219) = 0;
  return this;
}


// address=[0x13b8370]
// Decompiled from char __thiscall CGuiMsgList::AddListItem(int *this, int a2, char *Str)
bool  CGuiMsgList::AddListItem(int a2, char const * Str) {
  
  if ( this[25217] >= 200 )
    return 0;
  this[this[25217] + 25016] = a2;
  if ( j__strlen(Str) > 0x1F4 )
    return 0;
  j__strcpy_0((char *)&this[125 * this[25217]++ + 16], Str);
  return 1;
}


// address=[0x13b8400]
// Decompiled from char __thiscall CGuiMsgList::SetListindex(_DWORD *this, int a2)
bool  CGuiMsgList::SetListindex(int a2) {
  
  if ( a2 >= this[25217] )
    this[25216] = this[25217] - 1;
  else
    this[25216] = a2;
  return 1;
}


// address=[0x13b8440]
// Decompiled from char __thiscall CGuiMsgList::SetTopindex(CGuiMsgList *this, int a2)
bool  CGuiMsgList::SetTopindex(int a2) {
  
  int j; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  for ( i = 0; i < *((_DWORD *)this + 25218); ++i )
  {
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 4 * i), *((_DWORD *)this + 4 * i + 1), 0);
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 4 * i), *((_DWORD *)this + 4 * i + 2), 0);
  }
  if ( !*((_DWORD *)this + 25217) )
    return 1;
  if ( a2 >= *((_DWORD *)this + 25217) )
  {
    *((_DWORD *)this + 25219) = *((_DWORD *)this + 25217) - 1;
  }
  else
  {
    if ( a2 < 0 )
      a2 = 0;
    *((_DWORD *)this + 25219) = a2;
  }
  v4 = *((_DWORD *)this + 25219);
  for ( j = *((_DWORD *)this + 25218) - 1; j >= 0 && v4 >= 0; j = CGuiMsgList::SetListentry(this, v4--, j) )
    ;
  return 1;
}


// address=[0x13b8560]
// Decompiled from char __thiscall CGuiMsgList::ShowLastMessage(CGuiMsgList *this)
bool  CGuiMsgList::ShowLastMessage(void) {
  
  return 1;
}


// address=[0x13b8570]
// Decompiled from char __thiscall CGuiMsgList::RemoveListItem(CGuiMsgList *this, int a2)
bool  CGuiMsgList::RemoveListItem(int a2) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]

  if ( a2 >= *((_DWORD *)this + 25217) )
    return 0;
  v3 = *((_DWORD *)this + 25217) - 1;
  if ( a2 < v3 )
  {
    for ( i = a2; i < v3; ++i )
    {
      *((_BYTE *)this + 500 * i + 64) = *((_BYTE *)this + 500 * i + 564);
      *((_DWORD *)this + i + 25016) = *((_DWORD *)this + i + 25017);
    }
  }
  --*((_DWORD *)this + 25217);
  if ( a2 >= *((_DWORD *)this + 25219) )
    CGuiMsgList::SetTopindex(this, *((_DWORD *)this + 25219));
  else
    CGuiMsgList::SetTopindex(this, *((_DWORD *)this + 25219) - 1);
  return 1;
}


// address=[0x13b8670]
// Decompiled from char __thiscall CGuiMsgList::Clear(CGuiMsgList *this)
bool  CGuiMsgList::Clear(void) {
  
  *((_DWORD *)this + 25217) = 0;
  *((_DWORD *)this + 25216) = -1;
  return 1;
}


// address=[0x13b86a0]
// Decompiled from char __thiscall CGuiMsgList::SetOutputControls(CGuiMsgList *this, int a2, struct CGuiMsgList::SControl *a3)
bool  CGuiMsgList::SetOutputControls(int a2, struct CGuiMsgList::SControl * a3) {
  
  _DWORD *v3; // edx
  _DWORD *v4; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 25218); ++i )
  {
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 4 * i), *((_DWORD *)this + 4 * i + 1), 0);
    IGuiEngine::SetControlVisibility((void *)g_pGUIEngine, *((_DWORD *)this + 4 * i), *((_DWORD *)this + 4 * i + 2), 0);
  }
  for ( j = 0; j < a2; ++j )
  {
    v3 = (_DWORD *)((char *)a3 + 16 * j);
    v4 = (_DWORD *)((char *)this + 16 * j);
    *v4 = *v3;
    v4[1] = v3[1];
    v4[2] = v3[2];
    v4[3] = v3[3];
  }
  *((_DWORD *)this + 25218) = a2;
  return 1;
}


// address=[0x13b8780]
// Decompiled from int __thiscall CGuiMsgList::SetListentry(CGuiMsgList *this, int a2, int a3)
int  CGuiMsgList::SetListentry(int a2, int a3) {
  
  int i; // [esp+4h] [ebp-9E4h]
  int v5; // [esp+8h] [ebp-9E0h]
  int Count; // [esp+Ch] [ebp-9DCh]
  char v7; // [esp+13h] [ebp-9D5h]
  unsigned __int8 *Source; // [esp+14h] [ebp-9D4h]
  char *Sourcea; // [esp+14h] [ebp-9D4h]
  int v11; // [esp+1Ch] [ebp-9CCh]
  char Str[2000]; // [esp+20h] [ebp-9C8h] BYREF
  char Destination[500]; // [esp+7F0h] [ebp-1F8h] BYREF

  v11 = a3;
  v5 = 0;
  j__strcpy_0(Destination, (const char *)this + 500 * a2 + 64);
  do
  {
    IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)this + 4 * a3), *((_DWORD *)this + 4 * a3 + 1), Destination);
    Count = IGuiEngine::GetWrapPosition(
              (IGuiEngine *)g_pGUIEngine,
              *((_DWORD *)this + 4 * a3),
              *((_DWORD *)this + 4 * a3 + 1));
    if ( Count <= 0 )
    {
      j__strcpy_0(&Str[500 * v5], Destination);
    }
    else
    {
      for ( Source = j___mbsninc((const unsigned __int8 *)Destination, --Count);
            Source > (unsigned __int8 *)Destination && j___mbsncmp(Source, " ", 1u);
            Source = j___mbsdec((const unsigned __int8 *)Destination, Source) )
      {
        ;
      }
      if ( j___mbsncmp(Source, " ", 1u) )
        Sourcea = (char *)j___mbsninc((const unsigned __int8 *)Destination, Count);
      else
        Sourcea = (char *)j___mbsinc(Source);
      v7 = *Sourcea;
      *Sourcea = 0;
      j__strcpy_0(&Str[500 * v5], Destination);
      *Sourcea = v7;
      if ( a3 <= 0 )
      {
        IGuiEngine::SetControlVisibility(
          (void *)g_pGUIEngine,
          *((_DWORD *)this + 4 * a3),
          *((_DWORD *)this + 4 * a3 + 2),
          0);
        IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)this + 4 * a3), *((_DWORD *)this + 4 * a3 + 1), Sourcea);
      }
      j__strcpy_0(Destination, Sourcea);
    }
    ++v5;
  }
  while ( Count >= 0 && v5 < 4 );
  for ( i = 0; i < v5; ++i )
  {
    IGuiEngine::SetText(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 4 * v11),
      *((_DWORD *)this + 4 * v11 + 1),
      &Str[500 * (v5 - 1 - i)]);
    IGuiEngine::SetControlVisibility(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 4 * v11),
      *((_DWORD *)this + 4 * v11 + 1),
      1);
    IGuiEngine::SetImages(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 4 * v11),
      *((_DWORD *)this + 4 * v11 + 2),
      *((_DWORD *)this + a2 + 25016),
      0);
    IGuiEngine::SetControlVisibility(
      (void *)g_pGUIEngine,
      *((_DWORD *)this + 4 * v11),
      *((_DWORD *)this + 4 * v11 + 2),
      v5 - 1 == i);
    *((_DWORD *)this + 4 * v11-- + 3) = a2;
    if ( v11 < 0 )
      break;
  }
  return v11;
}


// address=[0x13b9e80]
// Decompiled from void __thiscall CGuiMsgList::~CGuiMsgList(CGuiMsgList *this)
 CGuiMsgList::~CGuiMsgList(void) {
  
  ;
}


// address=[0x13b9ed0]
// Decompiled from int __thiscall CGuiMsgList::GetListindexFromControlindex(CGuiMsgList *this, int a2)
int  CGuiMsgList::GetListindexFromControlindex(int a2) {
  
  return *((_DWORD *)this + 4 * a2 + 3);
}


// address=[0x13b9ef0]
// Decompiled from int __thiscall CGuiMsgList::GetTopindex(CGuiMsgList *this)
int  CGuiMsgList::GetTopindex(void) {
  
  return *((_DWORD *)this + 25219);
}


// address=[0x13b9f10]
// Decompiled from int __thiscall CGuiMsgList::Listcount(CGuiMsgList *this)
int  CGuiMsgList::Listcount(void) {
  
  return *((_DWORD *)this + 25217);
}


