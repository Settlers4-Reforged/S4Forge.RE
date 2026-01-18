#include "IA_ColorReduction_Node.h"

// Definitions for class IA_ColorReduction_Node

// address=[0x2fd3800]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::IA_ColorReduction_Node(  IA_ColorReduction_Node *this,  int a2,  bool a3)
 IA_ColorReduction_Node::IA_ColorReduction_Node(int a2, bool a3) {
  
  memset(this, 0, 0x6Cu);
  *(_DWORD *)this = a2;
  *((_BYTE *)this + 4) = a3;
  return this;
}


// address=[0x2fd3840]
// Decompiled from void __thiscall IA_ColorReduction_Node::~IA_ColorReduction_Node(IA_ColorReduction_Node *this)
 IA_ColorReduction_Node::~IA_ColorReduction_Node(void) {
  
  ;
}


// address=[0x2fd3850]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetColorCount(IA_ColorReduction_Node *this)
unsigned long  IA_ColorReduction_Node::GetColorCount(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2fd3870]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::AddColor(  IA_ColorReduction_Node *this,  struct IA_ColorReduction_Color *a2)
void  IA_ColorReduction_Node::AddColor(class IA_ColorReduction_Color & a2) {
  
  IA_ColorReduction_Node *result; // eax

  *((_DWORD *)this + 3) += IA_ColorReduction_Color::GetRed(a2);
  *((_DWORD *)this + 4) += IA_ColorReduction_Color::GetGreen(a2);
  *((_DWORD *)this + 5) += IA_ColorReduction_Color::GetBlue(a2);
  *((_DWORD *)this + 6) += IA_ColorReduction_Color::GetAlpha(a2);
  result = this;
  ++*((_DWORD *)this + 2);
  return result;
}


// address=[0x2fd38f0]
// Decompiled from _DWORD *__thiscall IA_ColorReduction_Node::GetColor(_DWORD *this, _DWORD *a2)
class IA_ColorReduction_Color  IA_ColorReduction_Node::GetColor(void a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  _DWORD *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IA_ColorReduction_Color::IA_ColorReduction_Color((IA_ColorReduction_Color *)&v3);
  IA_ColorReduction_Color::SetRed((IA_ColorReduction_Color *)&v3, v4[3] / v4[2]);
  IA_ColorReduction_Color::SetGreen((IA_ColorReduction_Color *)&v3, v4[4] / v4[2]);
  IA_ColorReduction_Color::SetBlue((IA_ColorReduction_Color *)&v3, v4[5] / v4[2]);
  IA_ColorReduction_Color::SetAlpha((IA_ColorReduction_Color *)&v3, v4[6] / v4[2]);
  *a2 = v3;
  return a2;
}


// address=[0x2fd3970]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::SetColorIndex(IA_ColorReduction_Node *this, int a2)
void  IA_ColorReduction_Node::SetColorIndex(int a2) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  *((_DWORD *)this + 7) = a2;
  return result;
}


// address=[0x2fd3990]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetColorIndex(IA_ColorReduction_Node *this)
int  IA_ColorReduction_Node::GetColorIndex(void) {
  
  return *((_DWORD *)this + 7);
}


// address=[0x2fd39b0]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::SetNext(  IA_ColorReduction_Node *this,  struct IA_ColorReduction_Node *a2)
void  IA_ColorReduction_Node::SetNext(class IA_ColorReduction_Node * a2) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  *((_DWORD *)this + 25) = a2;
  return result;
}


// address=[0x2fd39d0]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetNext(IA_ColorReduction_Node *this)
class IA_ColorReduction_Node *  IA_ColorReduction_Node::GetNext(void) {
  
  return *((_DWORD *)this + 25);
}


// address=[0x2fd39f0]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::SetPrev(  IA_ColorReduction_Node *this,  struct IA_ColorReduction_Node *a2)
void  IA_ColorReduction_Node::SetPrev(class IA_ColorReduction_Node * a2) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  *((_DWORD *)this + 26) = a2;
  return result;
}


// address=[0x2fd3a10]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetPrev(IA_ColorReduction_Node *this)
class IA_ColorReduction_Node *  IA_ColorReduction_Node::GetPrev(void) {
  
  return *((_DWORD *)this + 26);
}


// address=[0x2fd3a30]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetNumChild(IA_ColorReduction_Node *this)
int  IA_ColorReduction_Node::GetNumChild(void) {
  
  return *((_DWORD *)this + 8);
}


// address=[0x2fd3a50]
// Decompiled from int __thiscall IA_ColorReduction_Node::SetChild(  IA_ColorReduction_Node *this,  int a2,  struct IA_ColorReduction_Node *a3)
void  IA_ColorReduction_Node::SetChild(int a2, class IA_ColorReduction_Node * a3) {
  
  int result; // eax

  result = a2;
  *((_DWORD *)this + a2 + 9) = a3;
  return result;
}


// address=[0x2fd3a70]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetChild(IA_ColorReduction_Node *this, int a2)
class IA_ColorReduction_Node *  IA_ColorReduction_Node::GetChild(int a2) {
  
  return *((_DWORD *)this + a2 + 9);
}


// address=[0x2fd3a90]
// Decompiled from int __thiscall IA_ColorReduction_Node::FindChild(IA_ColorReduction_Node *this, struct IA_ColorReduction_Color *a2)
int  IA_ColorReduction_Node::FindChild(class IA_ColorReduction_Color & a2) {
  
  char Red; // al
  int v3; // esi
  char Green; // al
  int v5; // esi
  char Blue; // al
  int v7; // esi
  char Alpha; // al
  int v10; // [esp-4h] [ebp-Ch]
  int v11; // [esp-4h] [ebp-Ch]
  int v12; // [esp-4h] [ebp-Ch]
  int v13; // [esp-4h] [ebp-Ch]

  v10 = 15 - *(_DWORD *)this;
  Red = IA_ColorReduction_Color::GetRed(a2);
  v3 = 8 * IA_ColorReduction_Node::TestBit(this, Red, v10);
  v11 = 15 - *(_DWORD *)this;
  Green = IA_ColorReduction_Color::GetGreen(a2);
  v5 = (4 * IA_ColorReduction_Node::TestBit(this, Green, v11)) | v3;
  v12 = 15 - *(_DWORD *)this;
  Blue = IA_ColorReduction_Color::GetBlue(a2);
  v7 = (2 * IA_ColorReduction_Node::TestBit(this, Blue, v12)) | v5;
  v13 = 15 - *(_DWORD *)this;
  Alpha = IA_ColorReduction_Color::GetAlpha(a2);
  return v7 | IA_ColorReduction_Node::TestBit(this, Alpha, v13);
}


// address=[0x2fd3b30]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::IncNumChild(IA_ColorReduction_Node *this)
void  IA_ColorReduction_Node::IncNumChild(void) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  ++*((_DWORD *)this + 8);
  return result;
}


// address=[0x2fd3b50]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::DecNumChild(IA_ColorReduction_Node *this)
void  IA_ColorReduction_Node::DecNumChild(void) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  --*((_DWORD *)this + 8);
  return result;
}


// address=[0x2fd3b70]
// Decompiled from int __thiscall IA_ColorReduction_Node::GetLevel(IA_ColorReduction_Node *this)
int  IA_ColorReduction_Node::GetLevel(void) {
  
  return *(_DWORD *)this;
}


// address=[0x2fd3b80]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::SetLeaf(IA_ColorReduction_Node *this, bool a2)
void  IA_ColorReduction_Node::SetLeaf(bool a2) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  *((_BYTE *)this + 4) = a2;
  return result;
}


// address=[0x2fd3ba0]
// Decompiled from char __thiscall IA_ColorReduction_Node::IsLeaf(IA_ColorReduction_Node *this)
bool  IA_ColorReduction_Node::IsLeaf(void) {
  
  return *((_BYTE *)this + 4);
}


// address=[0x2fd3bc0]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction_Node::SetReducible(IA_ColorReduction_Node *this, bool a2)
void  IA_ColorReduction_Node::SetReducible(bool a2) {
  
  IA_ColorReduction_Node *result; // eax

  result = this;
  *((_BYTE *)this + 5) = a2;
  return result;
}


// address=[0x2fd3be0]
// Decompiled from char __thiscall IA_ColorReduction_Node::IsReducible(IA_ColorReduction_Node *this)
bool  IA_ColorReduction_Node::IsReducible(void) {
  
  return *((_BYTE *)this + 5);
}


// address=[0x2fd3c00]
// Decompiled from BOOL __thiscall IA_ColorReduction_Node::TestBit(IA_ColorReduction_Node *this, unsigned __int8 a2, int a3)
int  IA_ColorReduction_Node::TestBit(unsigned char a2, int a3) {
  
  return ((1 << a3) & a2) > a3;
}


