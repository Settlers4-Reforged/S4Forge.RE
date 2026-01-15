#include "IA_ColorReduction.h"

// Definitions for class IA_ColorReduction

// address=[0x2fd1bb0]
// Decompiled from IA_ColorReduction *__thiscall IA_ColorReduction::IA_ColorReduction(IA_ColorReduction *this)
 IA_ColorReduction::IA_ColorReduction(void) {
  
  memset(this, 0, 0x50u);
  *(_DWORD *)this = 16;
  return this;
}


// address=[0x2fd1be0]
// Decompiled from void *__thiscall IA_ColorReduction::~IA_ColorReduction(void **this)
 IA_ColorReduction::~IA_ColorReduction(void) {
  
  IA_ColorReduction::DeleteTree((IA_ColorReduction *)this);
  if ( this[19] )
    operator delete[](this[19]);
  return memset(this, 0, 0x50u);
}


// address=[0x2fd1c50]
// Decompiled from bool __thiscall IA_ColorReduction::InitTree(void **this)
bool  IA_ColorReduction::InitTree(void) {
  
  struct IA_ColorReduction_Node *Node; // [esp+4h] [ebp-8h]

  IA_ColorReduction::DeleteTree((IA_ColorReduction *)this);
  if ( this[19] )
    operator delete[](this[19]);
  memset(this, 0, 0x50u);
  *this = (void *)16;
  Node = IA_ColorReduction::MakeNode((IA_ColorReduction *)this, 0);
  this[2] = Node;
  return Node != 0;
}


// address=[0x2fd1cc0]
// Decompiled from char __thiscall IA_ColorReduction::BuildTree(IA_ColorReduction *this, unsigned __int8 **const a2, unsigned int a3)
bool  IA_ColorReduction::BuildTree(unsigned char * * const,unsigned int) {
  
  int v4; // [esp+0h] [ebp-20h]
  unsigned __int8 *v5; // [esp+4h] [ebp-1Ch]
  unsigned __int8 *v6; // [esp+8h] [ebp-18h]
  unsigned __int8 *v7; // [esp+Ch] [ebp-14h]
  _BYTE v8[4]; // [esp+10h] [ebp-10h] BYREF
  IA_ColorReduction *v9; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  char v11; // [esp+1Fh] [ebp-1h]

  v9 = this;
  IA_ColorReduction_Color::IA_ColorReduction_Color((IA_ColorReduction_Color *)v8);
  v11 = 1;
  if ( !*((_DWORD *)v9 + 2) )
    return 0;
  if ( v11 != 1 )
    return v11;
  v4 = (int)*a2;
  v5 = a2[1];
  v6 = a2[2];
  v7 = a2[3];
  for ( i = 0; i < a3; ++i )
  {
    IA_ColorReduction_Color::SetValues((IA_ColorReduction_Color *)v8, *(_BYTE *)(i + v4), v5[i], v6[i], v7[i]);
    if ( !IA_ColorReduction::InsertNode(
            v9,
            *((struct IA_ColorReduction_Node **)v9 + 2),
            (struct IA_ColorReduction_Color *)v8) )
    {
      IA_ColorReduction::DeleteNode(v9, *((struct IA_ColorReduction_Node **)v9 + 2));
      return 0;
    }
  }
  return v11;
}


// address=[0x2fd1dc0]
// Decompiled from struct IA_ColorReduction_Node **__thiscall IA_ColorReduction::DeleteTree(struct IA_ColorReduction_Node **this)
void  IA_ColorReduction::DeleteTree(void) {
  
  struct IA_ColorReduction_Node **result; // eax

  if ( this[2] )
    IA_ColorReduction::DeleteNode((IA_ColorReduction *)this, this[2]);
  result = this;
  this[2] = 0;
  return result;
}


// address=[0x2fd1df0]
// Decompiled from IA_ColorReduction *__thiscall IA_ColorReduction::ReduceIt(IA_ColorReduction *this, unsigned int a2)
void  IA_ColorReduction::ReduceIt(unsigned int) {
  
  IA_ColorReduction *result; // eax

  while ( 1 )
  {
    result = this;
    if ( *((_DWORD *)this + 1) <= a2 )
      break;
    IA_ColorReduction::ReduceTree(this);
  }
  return result;
}


// address=[0x2fd1e20]
// Decompiled from unsigned int __thiscall IA_ColorReduction::MapColors(  struct IA_ColorReduction_Node **this,  unsigned __int8 **const a2,  unsigned __int8 *a3,  unsigned int a4)
void  IA_ColorReduction::MapColors(unsigned char * * const,unsigned char *,unsigned int) {
  
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-20h]
  unsigned __int8 *v6; // [esp+4h] [ebp-1Ch]
  unsigned __int8 *v7; // [esp+8h] [ebp-18h]
  unsigned __int8 *v8; // [esp+Ch] [ebp-14h]
  _BYTE v10[4]; // [esp+14h] [ebp-Ch] BYREF
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 v12; // [esp+1Fh] [ebp-1h]

  IA_ColorReduction_Color::IA_ColorReduction_Color((IA_ColorReduction_Color *)v10);
  v5 = (int)*a2;
  v6 = a2[1];
  v7 = a2[2];
  v8 = a2[3];
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= a4 )
      break;
    IA_ColorReduction_Color::SetValues((IA_ColorReduction_Color *)v10, *(_BYTE *)(i + v5), v6[i], v7[i], v8[i]);
    v12 = IA_ColorReduction::QuantizeColor((IA_ColorReduction *)this, this[2], (struct IA_ColorReduction_Color *)v10);
    a3[i] = v12;
  }
  return result;
}


// address=[0x2fd1ef0]
// Decompiled from IA_ColorReduction *__thiscall IA_ColorReduction::InitPalette(  IA_ColorReduction *this,  unsigned __int8 **const a2,  unsigned int a3)
void  IA_ColorReduction::InitPalette(unsigned char * * const,unsigned int) {
  
  unsigned __int8 Blue; // al
  unsigned __int8 Green; // al
  unsigned __int8 Red; // al
  unsigned __int8 Alpha; // al
  IA_ColorReduction *result; // eax
  unsigned int v8; // [esp+10h] [ebp-24h] BYREF
  void *v9; // [esp+14h] [ebp-20h]
  unsigned int v10; // [esp+18h] [ebp-1Ch]
  void *v11; // [esp+1Ch] [ebp-18h]
  IA_ColorReduction *v12; // [esp+20h] [ebp-14h]
  unsigned int i; // [esp+24h] [ebp-10h]
  int v14; // [esp+30h] [ebp-4h]

  v12 = this;
  v8 = 0;
  v10 = a3;
  v11 = operator new[](4 * a3);
  v14 = 0;
  if ( v11 )
  {
    `vector constructor iterator'(
      v11,
      4u,
      v10,
      (void *(__thiscall *)(void *))IA_ColorReduction_Color::IA_ColorReduction_Color);
    v9 = v11;
  }
  else
  {
    v9 = 0;
  }
  v14 = -1;
  *((_DWORD *)v12 + 19) = v9;
  for ( i = 0; i < a3; ++i )
  {
    IA_ColorReduction_Color::SetRed((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i), 0);
    IA_ColorReduction_Color::SetGreen((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i), 0);
    IA_ColorReduction_Color::SetBlue((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i), 0);
  }
  IA_ColorReduction::FillPalette(v12, *((struct IA_ColorReduction_Node **)v12 + 2), &v8);
  for ( i = 0; i < v8; ++i )
  {
    Blue = IA_ColorReduction_Color::GetBlue((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i));
    (*a2)[i] = Blue;
    Green = IA_ColorReduction_Color::GetGreen((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i));
    a2[1][i] = Green;
    Red = IA_ColorReduction_Color::GetRed((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i));
    a2[2][i] = Red;
    Alpha = IA_ColorReduction_Color::GetAlpha((IA_ColorReduction_Color *)(*((_DWORD *)v12 + 19) + 4 * i));
    a2[3][i] = Alpha;
  }
  operator delete[](*((void **)v12 + 19));
  result = v12;
  *((_DWORD *)v12 + 19) = 0;
  return result;
}


// address=[0x2fd20e0]
// Decompiled from bool __thiscall IA_ColorReduction::InsertNode(  IA_ColorReduction *this,  struct IA_ColorReduction_Node *a2,  struct IA_ColorReduction_Color *a3)
bool  IA_ColorReduction::InsertNode(class IA_ColorReduction_Node *,class IA_ColorReduction_Color &) {
  
  int Child; // [esp+0h] [ebp-14h]
  int Level; // [esp+4h] [ebp-10h]
  struct IA_ColorReduction_Node *Node; // [esp+Ch] [ebp-8h]
  char v8; // [esp+13h] [ebp-1h]

  v8 = 1;
  Level = IA_ColorReduction_Node::GetLevel(a2);
  IA_ColorReduction_Node::AddColor(a2, a3);
  if ( IA_ColorReduction_Node::IsLeaf(a2) || Level >= *(_DWORD *)this )
    return v8;
  Child = IA_ColorReduction_Node::FindChild(a2, a3);
  Node = IA_ColorReduction_Node::GetChild(a2, Child);
  if ( !Node )
  {
    Node = IA_ColorReduction::MakeNode(this, Level + 1);
    if ( !Node )
      return 0;
    IA_ColorReduction_Node::SetChild(a2, Child, Node);
    IA_ColorReduction_Node::IncNumChild(a2);
  }
  if ( (int)IA_ColorReduction_Node::GetNumChild(a2) > 1 && !IA_ColorReduction_Node::IsReducible(a2) )
    IA_ColorReduction::MakeReducible(this, a2);
  return IA_ColorReduction::InsertNode(this, Node, a3);
}


// address=[0x2fd21d0]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction::MakeNode(IA_ColorReduction *this, int a2)
class IA_ColorReduction_Node *  IA_ColorReduction::MakeNode(int) {
  
  IA_ColorReduction_Node *C; // [esp+Ch] [ebp-18h]
  bool v5; // [esp+16h] [ebp-Eh]

  v5 = a2 >= *(_DWORD *)this;
  if ( a2 >= *(_DWORD *)this )
    ++*((_DWORD *)this + 1);
  C = (IA_ColorReduction_Node *)operator new(0x6Cu);
  if ( C )
    return IA_ColorReduction_Node::IA_ColorReduction_Node(C, a2, v5);
  else
    return 0;
}


// address=[0x2fd2290]
// Decompiled from void __thiscall IA_ColorReduction::DeleteNode(IA_ColorReduction *this, struct IA_ColorReduction_Node *a2)
void  IA_ColorReduction::DeleteNode(class IA_ColorReduction_Node *) {
  
  struct IA_ColorReduction_Node *Child; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  if ( a2 )
  {
    if ( IA_ColorReduction_Node::IsLeaf(a2) )
    {
      --*((_DWORD *)this + 1);
    }
    else
    {
      for ( i = 0; i < 16; ++i )
      {
        Child = IA_ColorReduction_Node::GetChild(a2, i);
        if ( Child )
        {
          IA_ColorReduction::DeleteNode(this, Child);
          IA_ColorReduction_Node::SetChild(a2, i, 0);
          IA_ColorReduction_Node::DecNumChild(a2);
        }
      }
    }
    IA_ColorReduction_Node::`scalar deleting destructor'(a2, 1u);
  }
}


// address=[0x2fd2350]
// Decompiled from void __thiscall IA_ColorReduction::MakeReducible(IA_ColorReduction *this, struct IA_ColorReduction_Node *a2)
void  IA_ColorReduction::MakeReducible(class IA_ColorReduction_Node *) {
  
  int Level; // [esp+4h] [ebp-8h]
  struct IA_ColorReduction_Node *v4; // [esp+8h] [ebp-4h]

  Level = IA_ColorReduction_Node::GetLevel(a2);
  v4 = (struct IA_ColorReduction_Node *)*((_DWORD *)this + Level + 3);
  IA_ColorReduction_Node::SetNext(a2, v4);
  if ( v4 )
    IA_ColorReduction_Node::SetPrev(v4, a2);
  *((_DWORD *)this + Level + 3) = a2;
  IA_ColorReduction_Node::SetReducible(a2, 1);
}


// address=[0x2fd23b0]
// Decompiled from int __thiscall IA_ColorReduction::ReduceTree(IA_ColorReduction *this)
void  IA_ColorReduction::ReduceTree(void) {
  
  int result; // eax
  struct IA_ColorReduction_Node *Child; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  IA_ColorReduction_Node *Reducible; // [esp+Ch] [ebp-4h]

  Reducible = IA_ColorReduction::GetReducible(this);
  for ( i = 0; i < 16; ++i )
  {
    Child = IA_ColorReduction_Node::GetChild(Reducible, i);
    if ( Child )
    {
      IA_ColorReduction::DeleteNode(this, Child);
      IA_ColorReduction_Node::SetChild(Reducible, i, 0);
      IA_ColorReduction_Node::DecNumChild(Reducible);
    }
  }
  IA_ColorReduction_Node::SetLeaf(Reducible, 1);
  ++*((_DWORD *)this + 1);
  result = IA_ColorReduction_Node::GetLevel(Reducible);
  if ( result >= *(_DWORD *)this - 1 )
    return result;
  result = IA_ColorReduction_Node::GetLevel(Reducible) + 1;
  *(_DWORD *)this = result;
  return result;
}


// address=[0x2fd2460]
// Decompiled from IA_ColorReduction_Node *__thiscall IA_ColorReduction::GetReducible(IA_ColorReduction *this)
class IA_ColorReduction_Node *  IA_ColorReduction::GetReducible(void) {
  
  unsigned int ColorCount; // esi
  IA_ColorReduction_Node *Prev; // [esp+4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-10h]
  struct IA_ColorReduction_Node *Next; // [esp+10h] [ebp-Ch]
  IA_ColorReduction_Node *j; // [esp+14h] [ebp-8h]
  IA_ColorReduction_Node *v8; // [esp+18h] [ebp-4h]

  v8 = 0;
  for ( i = *(_DWORD *)this - 1; !*((_DWORD *)this + i + 3); --i )
    ;
  for ( j = (IA_ColorReduction_Node *)*((_DWORD *)this + i + 3); j; j = IA_ColorReduction_Node::GetNext(j) )
  {
    if ( v8 )
    {
      ColorCount = IA_ColorReduction_Node::GetColorCount(j);
      if ( ColorCount < IA_ColorReduction_Node::GetColorCount(v8) )
        v8 = j;
    }
    else
    {
      v8 = j;
    }
  }
  Next = IA_ColorReduction_Node::GetNext(v8);
  Prev = IA_ColorReduction_Node::GetPrev(v8);
  if ( Prev )
  {
    IA_ColorReduction_Node::SetNext(Prev, Next);
    if ( Next )
      IA_ColorReduction_Node::SetPrev(Next, Prev);
  }
  else
  {
    *((_DWORD *)this + i + 3) = Next;
    if ( Next )
      IA_ColorReduction_Node::SetPrev(Next, 0);
  }
  IA_ColorReduction_Node::SetNext(v8, 0);
  IA_ColorReduction_Node::SetPrev(v8, 0);
  IA_ColorReduction_Node::SetReducible(v8, 1);
  return v8;
}


// address=[0x2fd2560]
// Decompiled from void __thiscall IA_ColorReduction::FillPalette(  IA_ColorReduction *this,  struct IA_ColorReduction_Node *a2,  unsigned int *a3)
void  IA_ColorReduction::FillPalette(class IA_ColorReduction_Node *,unsigned int *) {
  
  _DWORD *Color; // eax
  struct IA_ColorReduction_Node *Child; // eax
  _BYTE v5[4]; // [esp+0h] [ebp-Ch] BYREF
  IA_ColorReduction *v6; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v6 = this;
  if ( a2 )
  {
    if ( IA_ColorReduction_Node::IsLeaf(a2) || IA_ColorReduction_Node::GetLevel(a2) == *(_DWORD *)v6 )
    {
      Color = (_DWORD *)IA_ColorReduction_Node::GetColor(a2, v5);
      *(_DWORD *)(*((_DWORD *)v6 + 19) + 4 * *a3) = *Color;
      IA_ColorReduction_Node::SetColorIndex(a2, *a3);
      ++*a3;
    }
    else
    {
      for ( i = 0; i < 16; ++i )
      {
        Child = IA_ColorReduction_Node::GetChild(a2, i);
        IA_ColorReduction::FillPalette(v6, Child, a3);
      }
    }
  }
}


// address=[0x2fd2610]
// Decompiled from int __thiscall IA_ColorReduction::QuantizeColor(  IA_ColorReduction *this,  struct IA_ColorReduction_Node *a2,  struct IA_ColorReduction_Color *a3)
int  IA_ColorReduction::QuantizeColor(class IA_ColorReduction_Node *,class IA_ColorReduction_Color &) {
  
  int Child; // eax
  struct IA_ColorReduction_Node *v5; // eax

  if ( IA_ColorReduction_Node::IsLeaf(a2) || IA_ColorReduction_Node::GetLevel(a2) == *(_DWORD *)this )
    return IA_ColorReduction_Node::GetColorIndex(a2);
  Child = IA_ColorReduction_Node::FindChild(a2, a3);
  v5 = IA_ColorReduction_Node::GetChild(a2, Child);
  return IA_ColorReduction::QuantizeColor(this, v5, a3);
}


