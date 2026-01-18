#include "DName.h"

// Definitions for class DName

// address=[0x3080430]
// Decompiled from DName *__thiscall DName::DName(DName *this, char **a2, char a3)
 DName::DName(char const * & a2, char a3) {
  
  int v4; // [esp+4h] [ebp-10h]
  char *v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]

  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  if ( *a2 )
  {
    if ( **a2 )
    {
      v6 = 0;
      v5 = *a2;
      while ( **a2 && **a2 != a3 )
      {
        if ( **a2 != 95
          && **a2 != 36
          && **a2 != 60
          && **a2 != 62
          && **a2 != 45
          && (**a2 < 97 || **a2 > 122)
          && (**a2 < 65 || **a2 > 90)
          && (**a2 < 48 || **a2 > 57)
          && ((unsigned __int8)**a2 < 0x80u || (unsigned __int8)**a2 == 255)
          && !UnDecorator::doNoIdentCharCheck() )
        {
          *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 2;
          return this;
        }
        ++v6;
        ++*a2;
      }
      DName::doPchar(this, v5, v6);
      if ( **a2 )
      {
        v4 = *(*a2)++;
        if ( v4 != a3 )
        {
          *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 3;
          *(_DWORD *)this = 0;
        }
      }
      else if ( !DName::status(this) )
      {
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 1;
      }
    }
    else
    {
      *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 1;
    }
  }
  else
  {
    *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 2;
  }
  return this;
}


// address=[0x30807a0]
// Decompiled from DName *__thiscall DName::DName(DName *this, const struct DName *a2)
 DName::DName(class DName const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  return this;
}


// address=[0x30807d0]
// Decompiled from DName *__thiscall DName::DName(DName *this, char a2)
 DName::DName(char a2) {
  
  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  if ( a2 )
    DName::doPchar(this, &a2, 1);
  return this;
}


// address=[0x30808e0]
// Decompiled from DName *__thiscall DName::DName(DName *this, struct DName *a2)
 DName::DName(class DName * a2) {
  
  unsigned __int8 v3; // [esp+0h] [ebp-10h]
  pDNameNode *v4; // [esp+4h] [ebp-Ch]
  pDNameNode *v5; // [esp+8h] [ebp-8h]

  if ( a2 )
  {
    v5 = (pDNameNode *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v5 )
      v4 = pDNameNode::pDNameNode(v5, a2);
    else
      v4 = 0;
    *(_DWORD *)this = v4;
    if ( *(_DWORD *)this )
      v3 = 0;
    else
      v3 = 3;
    *((_DWORD *)this + 1) = v3 | *((_DWORD *)this + 1) & 0xFFFFFF00;
  }
  else
  {
    *((_DWORD *)this + 1) &= 0xFFFFFF00;
    *(_DWORD *)this = 0;
  }
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  return this;
}


// address=[0x3080a60]
// Decompiled from DName *__thiscall DName::DName(DName *this, char *a2)
 DName::DName(char const * a2) {
  
  unsigned int v3; // [esp+0h] [ebp-8h]

  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  if ( !a2 )
    return this;
  v3 = und_strlen(a2);
  if ( v3 )
    DName::doPchar(this, a2, v3);
  return this;
}


// address=[0x3080b90]
// Decompiled from _DWORD *__thiscall DName::DName(_DWORD *this, int a2)
 DName::DName(enum DNameStatus a2) {
  
  unsigned __int8 v3; // [esp+0h] [ebp-8h]

  this[1] &= ~0x100u;
  this[1] &= ~0x200u;
  this[1] &= ~0x400u;
  this[1] &= ~0x800u;
  this[1] &= ~0x1000u;
  this[1] &= ~0x2000u;
  this[1] &= ~0x4000u;
  this[1] &= ~0x8000u;
  if ( a2 == 2 || a2 == 3 )
    v3 = a2;
  else
    v3 = 0;
  this[1] = v3 | this[1] & 0xFFFFFF00;
  *this = 0;
  if ( a2 != 1 )
    return this;
  *this = DNameStatusNode::make(1);
  if ( !*this )
    this[1] = this[1] & 0xFFFFFF00 | 3;
  return this;
}


// address=[0x3080cf0]
// Decompiled from DName *__thiscall DName::DName(DName *this)
 DName::DName(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  return this;
}


// address=[0x3080de0]
// Decompiled from DName *__thiscall DName::DName(DName *this, unsigned __int64 a2)
 DName::DName(__int64 a2) {
  
  char *v3; // [esp+0h] [ebp-28h]
  char v4; // [esp+7h] [ebp-21h]
  char v6; // [esp+Ch] [ebp-1Ch] BYREF
  char v7; // [esp+21h] [ebp-7h] BYREF

  v3 = &v7;
  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  v7 = 0;
  v4 = 0;
  if ( (a2 & 0x8000000000000000uLL) != 0LL )
  {
    v4 = 1;
    a2 = -(__int64)a2;
  }
  do
  {
    *--v3 = a2 % 0xA + 48;
    a2 /= 0xAuLL;
  }
  while ( a2 );
  if ( v4 )
    *--v3 = 45;
  DName::doPchar(this, v3, 21 - (v3 - &v6));
  return this;
}


// address=[0x3080fc0]
// Decompiled from DName *__thiscall DName::DName(DName *this, unsigned __int64 a2)
 DName::DName(unsigned __int64 a2) {
  
  char *v3; // [esp+0h] [ebp-24h]
  char v5; // [esp+8h] [ebp-1Ch] BYREF
  char v6; // [esp+1Ch] [ebp-8h] BYREF

  v3 = &v6;
  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  v6 = 0;
  do
  {
    *--v3 = a2 % 0xA + 48;
    a2 /= 0xAuLL;
  }
  while ( a2 );
  DName::doPchar(this, v3, 20 - (v3 - &v5));
  return this;
}


// address=[0x30814b0]
// Decompiled from _DWORD *__thiscall DName::operator=(_DWORD *this, _DWORD *a2)
class DName &  DName::operator=(class DName const & a2) {
  
  *this = *a2;
  this[1] = a2[1];
  return this;
}


// address=[0x30814e0]
// Decompiled from DName *__thiscall DName::operator=(DName *this, char a2)
class DName &  DName::operator=(char a2) {
  
  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  if ( a2 )
    DName::doPchar(this, &a2, 1);
  return this;
}


// address=[0x30815f0]
// Decompiled from pDNameNode **__thiscall DName::operator=(pDNameNode **this, struct DName *a2)
class DName &  DName::operator=(class DName * a2) {
  
  pDNameNode *v3; // [esp+0h] [ebp-Ch]
  pDNameNode *v4; // [esp+4h] [ebp-8h]

  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFF00);
  *this = 0;
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFEFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFDFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFBFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFF7FF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFEFFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFDFFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFBFFF);
  this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFF7FFF);
  if ( a2 )
  {
    v4 = (pDNameNode *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v4 )
      v3 = pDNameNode::pDNameNode(v4, a2);
    else
      v3 = 0;
    *this = v3;
    if ( !*this )
      this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFF00 | 3);
  }
  else
  {
    this[1] = (pDNameNode *)((unsigned int)this[1] & 0xFFFFFF00 | 3);
  }
  return this;
}


// address=[0x3081770]
// Decompiled from DName *__thiscall DName::operator=(DName *this, char *a2)
class DName &  DName::operator=(char const * a2) {
  
  int v2; // eax

  *((_DWORD *)this + 1) &= 0xFFFFFF00;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) &= ~0x100u;
  *((_DWORD *)this + 1) &= ~0x200u;
  *((_DWORD *)this + 1) &= ~0x400u;
  *((_DWORD *)this + 1) &= ~0x800u;
  *((_DWORD *)this + 1) &= ~0x1000u;
  *((_DWORD *)this + 1) &= ~0x2000u;
  *((_DWORD *)this + 1) &= ~0x4000u;
  *((_DWORD *)this + 1) &= ~0x8000u;
  v2 = und_strlen(a2);
  DName::doPchar(this, a2, v2);
  return this;
}


// address=[0x3081880]
// Decompiled from _DWORD *__thiscall DName::operator=(_DWORD *this, int a2)
class DName &  DName::operator=(enum DNameStatus a2) {
  
  this[1] &= ~0x100u;
  this[1] &= ~0x200u;
  this[1] &= ~0x400u;
  this[1] &= ~0x800u;
  this[1] &= ~0x1000u;
  this[1] &= ~0x2000u;
  this[1] &= ~0x4000u;
  this[1] &= ~0x8000u;
  this[1] = (unsigned __int8)a2 | this[1] & 0xFFFFFF00;
  if ( a2 == 1 )
  {
    *this = DNameStatusNode::make(1);
    if ( !*this )
      this[1] = this[1] & 0xFFFFFF00 | 3;
  }
  else
  {
    *this = 0;
  }
  return this;
}


// address=[0x3081e50]
// Decompiled from DName *__thiscall DName::operator+(const struct DName *this, DName *a2, DName *a3)
class DName  DName::operator+(class DName const & a2)const {
  
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF
  const struct DName *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  DName::DName((DName *)v4, this);
  DName::operator+=(a3);
  DName::DName(a2, (const struct DName *)v4);
  return a2;
}


// address=[0x3081ea0]
// Decompiled from DName *__thiscall DName::operator+(const struct DName *this, DName *a2, char a3)
class DName  DName::operator+(char a2)const {
  
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF
  const struct DName *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  DName::DName((DName *)v4, this);
  DName::operator+=(a3);
  DName::DName(a2, (const struct DName *)v4);
  return a2;
}


// address=[0x3081ef0]
// Decompiled from DName *__thiscall DName::operator+(const struct DName *this, DName *a2, struct DName *a3)
class DName  DName::operator+(class DName * a2)const {
  
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF
  const struct DName *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  DName::DName((DName *)v4, this);
  DName::operator+=(a3);
  DName::DName(a2, (const struct DName *)v4);
  return a2;
}


// address=[0x3081f40]
// Decompiled from DName *__thiscall DName::operator+(const struct DName *this, DName *a2, char *a3)
class DName  DName::operator+(char const * a2)const {
  
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF
  const struct DName *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  DName::DName((DName *)v4, this);
  DName::operator+=(a3);
  DName::DName(a2, (const struct DName *)v4);
  return a2;
}


// address=[0x3081f90]
// Decompiled from DName *__thiscall DName::operator+(const struct DName *this, DName *a2, int a3)
class DName  DName::operator+(enum DNameStatus a2)const {
  
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF
  const struct DName *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  DName::DName((DName *)v4, this);
  DName::operator+=(a3);
  DName::DName(a2, (const struct DName *)v4);
  return a2;
}


// address=[0x3081fe0]
// Decompiled from DName *__thiscall DName::operator+=(DName *this, struct DNameNode **a2)
class DName &  DName::operator+=(class DName const & a2) {
  
  int v2; // eax

  if ( !DName::isValid(this) )
    return this;
  if ( DName::isEmpty((DName *)a2) )
  {
    v2 = DName::status(a2);
    DName::operator+=(v2);
  }
  else if ( DName::isEmpty(this) )
  {
    DName::operator=(this, a2);
  }
  else
  {
    DName::append(this, *a2);
  }
  return this;
}


// address=[0x3082060]
// Decompiled from DName *__thiscall DName::operator+=(DName *this, char a2)
class DName &  DName::operator+=(char a2) {
  
  struct DNameNode *v3; // [esp+0h] [ebp-Ch]
  charNode *v4; // [esp+4h] [ebp-8h]

  if ( !DName::isValid(this) || !a2 )
    return this;
  if ( DName::isEmpty(this) )
  {
    DName::operator=(this, a2);
  }
  else
  {
    v4 = (charNode *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v4 )
    {
      v3 = charNode::charNode(v4, a2);
      DName::append(this, v3);
    }
    else
    {
      DName::append(this, 0);
    }
  }
  return this;
}


// address=[0x3082100]
// Decompiled from DName *__thiscall DName::operator+=(DName *this, struct DName *a2)
class DName &  DName::operator+=(class DName * a2) {
  
  int v2; // eax
  struct DNameNode *v4; // [esp+0h] [ebp-Ch]
  pDNameNode *v5; // [esp+4h] [ebp-8h]

  if ( !DName::isValid(this) || !a2 )
    return this;
  if ( DName::isEmpty(this) )
  {
    DName::operator=(a2);
  }
  else if ( DName::status(a2) && DName::status(a2) != 1 )
  {
    v2 = DName::status(a2);
    DName::operator+=(v2);
  }
  else
  {
    v5 = (pDNameNode *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v5 )
    {
      v4 = pDNameNode::pDNameNode(v5, a2);
      DName::append(this, v4);
    }
    else
    {
      DName::append(this, 0);
    }
  }
  return this;
}


// address=[0x30821e0]
// Decompiled from DName *__thiscall DName::operator+=(DName *this, char *a2)
class DName &  DName::operator+=(char const * a2) {
  
  int v2; // eax
  struct DNameNode *v4; // [esp+0h] [ebp-Ch]
  pcharNode *v5; // [esp+4h] [ebp-8h]

  if ( !DName::isValid(this) || !a2 || !*a2 )
    return this;
  if ( DName::isEmpty(this) )
  {
    DName::operator=(a2);
  }
  else
  {
    v5 = (pcharNode *)operator new(0xCu, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v5 )
    {
      v2 = und_strlen(a2);
      v4 = pcharNode::pcharNode(v5, a2, v2);
      DName::append(this, v4);
    }
    else
    {
      DName::append(this, 0);
    }
  }
  return this;
}


// address=[0x30822a0]
// Decompiled from DName *__thiscall DName::operator+=(DName *this, int a2)
class DName &  DName::operator+=(enum DNameStatus a2) {
  
  struct DNameNode *v2; // eax

  if ( !DName::isValid(this) )
    return this;
  if ( DName::isEmpty(this) || a2 == 2 || a2 == 3 )
  {
    DName::operator=(a2);
  }
  else if ( a2 )
  {
    v2 = (struct DNameNode *)DNameStatusNode::make(a2);
    DName::append(this, v2);
  }
  return this;
}


// address=[0x30823d0]
// Decompiled from _DWORD *__thiscall DName::operator|=(_DWORD *this, DName *a2)
class DName &  DName::operator|=(class DName const & a2) {
  
  if ( DName::status(this) != 3 && !DName::isValid(a2) )
    this[1] = (unsigned __int8)DName::status(a2) | this[1] & 0xFFFFFF00;
  return this;
}


// address=[0x30849a0]
// Decompiled from char *__thiscall DName::dbGetString(DName *this)
char *  DName::dbGetString(void)const {
  
  DName::getString(this, byte_4731EB8, 80);
  return byte_4731EB8;
}


// address=[0x3087fb0]
// Decompiled from char __thiscall DName::getLastChar(DName *this)
char  DName::getLastChar(void)const {
  
  if ( DName::isEmpty(this) )
    return 0;
  else
    return (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this + 4))(*(_DWORD *)this);
}


// address=[0x308a4d0]
// Decompiled from char *__thiscall DName::getString(DName *this, char *a2, char *a3)
char *  DName::getString(char * a2, char * a3)const {
  
  if ( DName::isEmpty(this) )
    return a2;
  else
    return (char *)(*(int (__thiscall **)(_DWORD, char *, char *))(**(_DWORD **)this + 8))(*(_DWORD *)this, a2, a3);
}


// address=[0x308a530]
// Decompiled from char *__thiscall DName::getString(DName *this, char *a2, int a3)
char *  DName::getString(char * a2, int a3)const {
  
  if ( DName::isEmpty(this) )
  {
    if ( a2 )
      *a2 = 0;
  }
  else
  {
    if ( !a2 )
    {
      a3 = DName::length(this) + 1;
      a2 = (char *)operator new(a3, (struct _HeapManager *)&unk_4731E94, 0);
    }
    if ( a2 )
      *DName::getString(this, a2, &a2[a3 - 1]) = 0;
  }
  return a2;
}


// address=[0x308cd00]
// Decompiled from int __thiscall DName::isArray(DName *this)
int  DName::isArray(void)const {
  
  return (*((_DWORD *)this + 1) >> 11) & 1;
}


// address=[0x308cd20]
// Decompiled from int __thiscall DName::isComArray(DName *this)
int  DName::isComArray(void)const {
  
  return (*((_DWORD *)this + 1) >> 14) & 1;
}


// address=[0x308cd40]
// Decompiled from BOOL __thiscall DName::isEmpty(DName *this)
int  DName::isEmpty(void)const {
  
  return *(_DWORD *)this == 0;
}


// address=[0x308cdc0]
// Decompiled from int __thiscall DName::isNoTE(DName *this)
int  DName::isNoTE(void)const {
  
  return (*((_DWORD *)this + 1) >> 12) & 1;
}


// address=[0x308cde0]
// Decompiled from int __thiscall DName::isPinPtr(DName *this)
int  DName::isPinPtr(void)const {
  
  return (*((_DWORD *)this + 1) >> 13) & 1;
}


// address=[0x308ce00]
// Decompiled from int __thiscall DName::isPtrRef(DName *this)
int  DName::isPtrRef(void)const {
  
  return (*((_DWORD *)this + 1) >> 8) & 1;
}


// address=[0x308ce20]
// Decompiled from BOOL __thiscall DName::isUDC(DName *this)
int  DName::isUDC(void)const {
  
  return !DName::isEmpty(this) && ((*((_DWORD *)this + 1) >> 9) & 1) != 0;
}


// address=[0x308ce70]
// Decompiled from BOOL __thiscall DName::isUDTThunk(DName *this)
int  DName::isUDTThunk(void)const {
  
  return !DName::isEmpty(this) && ((*((_DWORD *)this + 1) >> 10) & 1) != 0;
}


// address=[0x308cec0]
// Decompiled from int __thiscall DName::isVCallThunk(DName *this)
int  DName::isVCallThunk(void)const {
  
  return (*((_DWORD *)this + 1) >> 15) & 1;
}


// address=[0x308cee0]
// Decompiled from BOOL __thiscall DName::isValid(DName *this)
int  DName::isValid(void)const {
  
  return (char)*((_DWORD *)this + 1) <= 1;
}


// address=[0x308cf20]
// Decompiled from int __thiscall DName::length(DName *this)
int  DName::length(void)const {
  
  if ( DName::isEmpty(this) )
    return 0;
  else
    return (***(int (__thiscall ****)(_DWORD))this)(*(_DWORD *)this);
}


// address=[0x308d130]
// Decompiled from void __thiscall DName::setIsArray(DName *this)
void  DName::setIsArray(void) {
  
  *((_DWORD *)this + 1) |= 0x800u;
}


// address=[0x308d160]
// Decompiled from void __thiscall DName::setIsComArray(DName *this)
void  DName::setIsComArray(void) {
  
  *((_DWORD *)this + 1) |= 0x4000u;
}


// address=[0x308d190]
// Decompiled from void __thiscall DName::setIsNoTE(DName *this)
void  DName::setIsNoTE(void) {
  
  *((_DWORD *)this + 1) |= 0x1000u;
}


// address=[0x308d1c0]
// Decompiled from void __thiscall DName::setIsPinPtr(DName *this)
void  DName::setIsPinPtr(void) {
  
  *((_DWORD *)this + 1) |= 0x2000u;
}


// address=[0x308d1f0]
// Decompiled from void __thiscall DName::setIsUDC(DName *this)
void  DName::setIsUDC(void) {
  
  if ( !DName::isEmpty(this) )
    *((_DWORD *)this + 1) |= 0x200u;
}


// address=[0x308d230]
// Decompiled from void __thiscall DName::setIsVCallThunk(DName *this)
void  DName::setIsVCallThunk(void) {
  
  *((_DWORD *)this + 1) |= 0x8000u;
}


// address=[0x308d260]
// Decompiled from struct DName *__thiscall DName::setPtrRef(DName *this)
class DName &  DName::setPtrRef(void) {
  
  *((_DWORD *)this + 1) |= 0x100u;
  return this;
}


// address=[0x308d290]
// Decompiled from int __thiscall DName::status(_DWORD *this)
enum DNameStatus  DName::status(void)const {
  
  return (char)this[1];
}


// address=[0x3082540]
// Decompiled from struct DNameNode **__thiscall DName::append(struct DNameNode **this, struct DNameNode *a2)
void  DName::append(class DNameNode * a2) {
  
  struct DNameNode **result; // eax
  pairNode *v3; // [esp+0h] [ebp-Ch]
  pairNode *v4; // [esp+4h] [ebp-8h]

  if ( a2 )
  {
    v4 = (pairNode *)operator new(0x10u, (struct _HeapManager *)&unk_4731E94, 0);
    if ( v4 )
      v3 = pairNode::pairNode(v4, *this, a2);
    else
      v3 = 0;
    result = this;
    *this = v3;
    if ( !*this )
    {
      result = this;
      this[1] = (struct DNameNode *)((unsigned int)this[1] & 0xFFFFFF00 | 3);
    }
  }
  else
  {
    result = this;
    this[1] = (struct DNameNode *)((unsigned int)this[1] & 0xFFFFFF00 | 3);
  }
  return result;
}


// address=[0x3084b90]
// Decompiled from void __thiscall DName::doPchar(DName *this, char *a2, int a3)
void  DName::doPchar(char const * a2, int a3) {
  
  pcharNode *v3; // eax
  pcharNode *v4; // [esp+0h] [ebp-18h]
  charNode *v5; // [esp+8h] [ebp-10h]
  charNode *v6; // [esp+Ch] [ebp-Ch]

  if ( *(_DWORD *)this )
  {
    DName::operator=(3);
  }
  else if ( a2 && a3 )
  {
    if ( a3 == 1 )
    {
      v6 = (charNode *)operator new(8u, (struct _HeapManager *)&unk_4731E94, 0);
      if ( v6 )
        v5 = charNode::charNode(v6, *a2);
      else
        v5 = 0;
      *(_DWORD *)this = v5;
      if ( !*(_DWORD *)this )
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 3;
    }
    else
    {
      v3 = (pcharNode *)operator new(0xCu, (struct _HeapManager *)&unk_4731E94, 0);
      if ( v3 )
        v4 = pcharNode::pcharNode(v3, a2, a3);
      else
        v4 = 0;
      *(_DWORD *)this = v4;
      if ( !*(_DWORD *)this )
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 3;
    }
  }
  else
  {
    *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFF00 | 2;
  }
}


