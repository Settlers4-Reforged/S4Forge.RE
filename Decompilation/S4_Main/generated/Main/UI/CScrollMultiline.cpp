#include "CScrollMultiline.h"

// Definitions for class CScrollMultiline

// address=[0x1377dc0]
// Decompiled from void __thiscall CScrollMultiline::~CScrollMultiline(CScrollMultiline *this)
 CScrollMultiline::~CScrollMultiline(void) {
  
  ;
}


// address=[0x13da4c0]
// Decompiled from CScrollMultiline *__thiscall CScrollMultiline::CScrollMultiline(  CScrollMultiline *this,  int a2,  int a3,  int a4,  int a5,  int a6)
 CScrollMultiline::CScrollMultiline(int a2, int a3, int a4, int a5, int a6) {
  
  int i; // [esp+0h] [ebp-8h]

  for ( i = 0; i < 500; ++i )
    *((_DWORD *)this + i) = 0;
  *((_DWORD *)this + 502) = a2;
  *((_DWORD *)this + 503) = a3;
  *((_DWORD *)this + 504) = a4;
  *((_DWORD *)this + 505) = a5;
  *((_DWORD *)this + 506) = a6;
  return this;
}


// address=[0x13da540]
// Decompiled from char __thiscall CScrollMultiline::ScrollUp(CScrollMultiline *this)
void  CScrollMultiline::ScrollUp(void) {
  
  char result; // al

  result = (char)this;
  if ( *((int *)this + 501) <= 0 )
    return result;
  --*((_DWORD *)this + 501);
  return IGuiEngine::SetText(
           (void *)g_pGUIEngine,
           *((_DWORD *)this + 504),
           *((_DWORD *)this + 505),
           *((char **)this + *((_DWORD *)this + 501)));
}


// address=[0x13da5a0]
// Decompiled from char __thiscall CScrollMultiline::ScrollDown(CScrollMultiline *this)
void  CScrollMultiline::ScrollDown(void) {
  
  char result; // al

  result = (char)this;
  if ( *((_DWORD *)this + 501) > *((_DWORD *)this + 500) - *((_DWORD *)this + 506) )
    return result;
  ++*((_DWORD *)this + 501);
  return IGuiEngine::SetText(
           (void *)g_pGUIEngine,
           *((_DWORD *)this + 504),
           *((_DWORD *)this + 505),
           *((char **)this + *((_DWORD *)this + 501)));
}


// address=[0x13da610]
// Decompiled from char __thiscall CScrollMultiline::SetText(_DWORD *this, int a2)
void  CScrollMultiline::SetText(char const * a2) {
  
  this[507] = a2;
  CScrollMultiline::SplitText(this);
  this[501] = 0;
  return IGuiEngine::SetText((void *)g_pGUIEngine, this[504], this[505], (char *)this[this[501]]);
}


// address=[0x13da090]
// Decompiled from unsigned __int8 *__thiscall CScrollMultiline::GetWrapPointer(int *this, char *Str)
unsigned char *  CScrollMultiline::GetWrapPointer(unsigned char * Str) {
  
  char *v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+4h] [ebp-1Ch]
  char *v5; // [esp+8h] [ebp-18h]
  const unsigned __int8 *Str1; // [esp+Ch] [ebp-14h]
  unsigned __int8 *Str1a; // [esp+Ch] [ebp-14h]
  size_t Count; // [esp+10h] [ebp-10h]
  size_t Counta; // [esp+10h] [ebp-10h]
  unsigned __int8 *Ptr; // [esp+18h] [ebp-8h]
  unsigned __int8 *Ptra; // [esp+18h] [ebp-8h]
  const unsigned __int8 *Pos; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *Posb; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *Posa; // [esp+1Ch] [ebp-4h]

  IGuiEngine::SetText((void *)g_pGUIEngine, this[502], this[503], Str);
  Count = IGuiEngine::GetWrapPosition((IGuiEngine *)g_pGUIEngine, this[502], this[503]);
  if ( CGameSettings::GetLanguage() == 6 || CGameSettings::GetLanguage() == 7 )
  {
    if ( Count )
    {
      v5 = &Str[j__strlen(Str)];
      Ptr = j___mbsninc((const unsigned __int8 *)Str, Count);
      if ( j___mbsncmp(Ptr, "\n", 1u) && j___mbsncmp(Ptr, " ", 1u) )
      {
        if ( Ptr + 1 < (unsigned __int8 *)v5 && !j___mbsncmp(Ptr, "\n", 1u) )
          Ptr = j___mbsinc(Ptr);
        return CScrollMultiline::GetCRLFWrapPointer((CScrollMultiline *)this, (unsigned __int8 *)Str, Ptr);
      }
      else
      {
        Ptra = j___mbsinc(Ptr);
        return CScrollMultiline::GetCRLFWrapPointer((CScrollMultiline *)this, (unsigned __int8 *)Str, Ptra);
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v4 = Count;
    Counta = Count - 1;
    if ( v4 <= 0 )
    {
      return 0;
    }
    else
    {
      v3 = &Str[j__strlen(Str)];
      Pos = j___mbsninc((const unsigned __int8 *)Str, Counta);
      if ( !j___mbsncmp(Pos, "\n", 1u) || !j___mbsncmp(Pos, " ", 1u) )
        goto LABEL_20;
      if ( Pos + 1 >= (const unsigned __int8 *)v3 )
        goto LABEL_22;
      Str1 = j___mbsinc(Pos);
      if ( !j___mbsncmp(Str1, " ", 1u) )
      {
        Str1a = j___mbsinc(Str1);
        return CScrollMultiline::GetCRLFWrapPointer((CScrollMultiline *)this, (unsigned __int8 *)Str, Str1a);
      }
      if ( j___mbsncmp(Pos, "\n", 1u) )
      {
LABEL_22:
        while ( Pos > (const unsigned __int8 *)Str && j___mbsncmp(Pos, " ", 1u) )
          Pos = j___mbsdec((const unsigned __int8 *)Str, Pos);
        if ( j___mbsncmp(Pos, " ", 1u) )
          Posa = j___mbsninc((const unsigned __int8 *)Str, Counta);
        else
          Posa = j___mbsinc(Pos);
        return CScrollMultiline::GetCRLFWrapPointer((CScrollMultiline *)this, (unsigned __int8 *)Str, Posa);
      }
      else
      {
LABEL_20:
        Posb = j___mbsinc(Pos);
        return CScrollMultiline::GetCRLFWrapPointer((CScrollMultiline *)this, (unsigned __int8 *)Str, Posb);
      }
    }
  }
}


// address=[0x13da3c0]
// Decompiled from unsigned __int8 *__thiscall CScrollMultiline::GetCRLFWrapPointer(  CScrollMultiline *this,  unsigned __int8 *a2,  unsigned __int8 *a3)
unsigned char *  CScrollMultiline::GetCRLFWrapPointer(unsigned char * a2, unsigned char * a3) {
  
  unsigned __int8 *v3; // eax

  while ( a2 < a3 && j___mbsncmp(a2, "\r", 1u) )
    a2 = j___mbsinc(a2);
  if ( j___mbsncmp(a2, "\r", 1u) )
    return a2;
  v3 = j___mbsinc(a2);
  return j___mbsinc(v3);
}


// address=[0x13da440]
// Decompiled from CScrollMultiline *__thiscall CScrollMultiline::SplitText(char **this)
void  CScrollMultiline::SplitText(void) {
  
  CScrollMultiline *result; // eax
  char *Str; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  result = (CScrollMultiline *)this;
  this[500] = 0;
  Str = this[507];
  for ( i = 0; i < 500; ++i )
  {
    ++this[500];
    this[i] = Str;
    result = (CScrollMultiline *)CScrollMultiline::GetWrapPointer(Str);
    Str = (char *)result;
    if ( !result )
      break;
    result = (CScrollMultiline *)(i + 1);
  }
  return result;
}


