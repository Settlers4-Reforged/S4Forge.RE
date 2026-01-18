#include "CUnique.h"

// Definitions for class CUnique

// address=[0x14035b0]
// Decompiled from int __cdecl CUnique::GetObjectPtr(int a1)
class CUnique * __cdecl CUnique::GetObjectPtr(std::istream & a1) {
  
  char v2; // [esp+0h] [ebp-4h]

  v2 = CPersistence::LOAD_ID(a1);
  return CUnique::GetObjectPtr(v2);
}


// address=[0x14035e0]
// Decompiled from int __cdecl CUnique::GetObjectA(int a1)
class CUnique & __cdecl CUnique::GetObjectA(std::istream & a1) {
  
  char v2; // [esp+0h] [ebp-4h]

  v2 = CPersistence::LOAD_ID(a1);
  return CUnique::GetObjectA(v2);
}


// address=[0x1403610]
// Decompiled from int __cdecl CUnique::GetObjectA(char a1)
class CUnique & __cdecl CUnique::GetObjectA(unsigned long a1) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-1Ch] BYREF
  int v3; // [esp+10h] [ebp-10h]
  int v4; // [esp+1Ch] [ebp-4h]

  std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::find(
    v2,
    &a1);
  v4 = 0;
  v3 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator*(v2)
                 + 4);
  v4 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v2);
  return v3;
}


// address=[0x1403680]
// Decompiled from int __cdecl CUnique::GetObjectPtr(char a1)
class CUnique * __cdecl CUnique::GetObjectPtr(unsigned long a1) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+1Ch] [ebp-20h]
  int v5; // [esp+20h] [ebp-1Ch]
  std::_Iterator_base12 *v6; // [esp+24h] [ebp-18h]
  std::_Iterator_base12 *v7; // [esp+28h] [ebp-14h]
  char v8; // [esp+2Fh] [ebp-Dh]
  int v9; // [esp+38h] [ebp-4h]

  std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::find(
    v3,
    &a1);
  v9 = 0;
  v7 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::end(v2);
  v6 = v7;
  LOBYTE(v9) = 1;
  v8 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator==(v7);
  LOBYTE(v9) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v2);
  if ( v8 )
  {
    v5 = 0;
    v9 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v3);
    return v5;
  }
  else
  {
    v4 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator*(v3)
                   + 4);
    v9 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v3);
    return v4;
  }
}


// address=[0x1403760]
// Decompiled from int __cdecl CUnique::GetNextObjectPtr(char a1)
class CUnique * __cdecl CUnique::GetNextObjectPtr(unsigned long a1) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v4[12]; // [esp+1Ch] [ebp-44h] BYREF
  _BYTE v5[12]; // [esp+28h] [ebp-38h] BYREF
  int v6; // [esp+34h] [ebp-2Ch]
  int v7; // [esp+38h] [ebp-28h]
  std::_Iterator_base12 *v8; // [esp+3Ch] [ebp-24h]
  std::_Iterator_base12 *v9; // [esp+40h] [ebp-20h]
  int v10; // [esp+44h] [ebp-1Ch]
  std::_Iterator_base12 *v11; // [esp+48h] [ebp-18h]
  std::_Iterator_base12 *v12; // [esp+4Ch] [ebp-14h]
  char v13; // [esp+52h] [ebp-Eh]
  char v14; // [esp+53h] [ebp-Dh]
  int v15; // [esp+5Ch] [ebp-4h]

  std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::find(
    v5,
    &a1);
  v15 = 0;
  v12 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::end(v4);
  v11 = v12;
  LOBYTE(v15) = 1;
  v14 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator==(v12);
  LOBYTE(v15) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v4);
  if ( v14 )
  {
    v10 = 0;
    v15 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v5);
    return v10;
  }
  else
  {
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator++(
      v3,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v3);
    v9 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::end(v2);
    v8 = v9;
    LOBYTE(v15) = 2;
    v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator==(v9);
    LOBYTE(v15) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v2);
    if ( v13 )
    {
      v7 = 0;
      v15 = -1;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v5);
      return v7;
    }
    else
    {
      v6 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator*(v5)
                     + 4);
      v15 = -1;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v5);
      return v6;
    }
  }
}


// address=[0x14038b0]
// Decompiled from int CUnique::GetFirstObjectPtr()
class CUnique * __cdecl CUnique::GetFirstObjectPtr(void) {
  
  _BYTE v1[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v2[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v3; // [esp+1Ch] [ebp-20h]
  int v4; // [esp+20h] [ebp-1Ch]
  std::_Iterator_base12 *v5; // [esp+24h] [ebp-18h]
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-14h]
  char v7; // [esp+2Fh] [ebp-Dh]
  int v8; // [esp+38h] [ebp-4h]

  std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::begin(v2);
  v8 = 0;
  v6 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::end(v1);
  v5 = v6;
  LOBYTE(v8) = 1;
  v7 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator==(v6);
  LOBYTE(v8) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v1);
  if ( v7 )
  {
    v4 = 0;
    v8 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v2);
    return v4;
  }
  else
  {
    v3 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::operator*(v2)
                   + 4);
    v8 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,CUnique *>>>>(v2);
    return v3;
  }
}


// address=[0x1403990]
// Decompiled from int __cdecl CUnique::Init(int a1)
void __cdecl CUnique::Init(std::istream & a1) {
  
  int result; // eax

  result = (unsigned __int8)std::ios_base::operator bool(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1);
  if ( !(_BYTE)result )
    return result;
  result = CPersistence::LOAD_ID(a1);
  CUnique::_NextObjID = result;
  return result;
}


// address=[0x14039c0]
// Decompiled from struct std::ostream *__cdecl CUnique::Exit(struct std::ostream *a1)
void __cdecl CUnique::Exit(std::ostream & a1) {
  
  return operator^<unsigned long>(a1, (const unsigned int *)&CUnique::_NextObjID);
}


// address=[0x14039e0]
// Decompiled from struct CUnique *__thiscall CUnique::CUnique(struct CUnique *this, int a2)
 CUnique::CUnique(std::istream & a2) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CUnique::_vftable_;
  *((_DWORD *)this + 1) = CPersistence::LOAD_ID(a2);
  CUnique::_add(*((_DWORD *)this + 1), this);
  return this;
}


// address=[0x1403a30]
// Decompiled from struct std::ostream *__thiscall CUnique::Store(CUnique *this, struct std::ostream *a2)
void  CUnique::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  CUnique *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  CPersistence::Store(this, a2);
  v3 = CUnique::ObjectID(v4);
  return operator^<unsigned long>(a2, (const unsigned int *)&v3);
}


// address=[0x1407c30]
// Decompiled from int __thiscall CUnique::ObjectID(CUnique *this)
unsigned long  CUnique::ObjectID(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1403a70]
// Decompiled from _DWORD *__cdecl CUnique::_add(char a1, struct CUnique *a2)
void __cdecl CUnique::_add(unsigned long a1, class CUnique * a2) {
  
  _DWORD *result; // eax

  result = (_DWORD *)std::map<unsigned long,CUnique *>::operator[](&a1);
  *result = a2;
  return result;
}


// address=[0x1403a90]
// Decompiled from int __cdecl CUnique::_remove(char a1)
void __cdecl CUnique::_remove(unsigned long a1) {
  
  return std::_Tree<std::_Tmap_traits<unsigned long,CUnique *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,CUnique *>>,0>>::erase(&a1);
}


// address=[0x3d89404]
// [Decompilation failed for static unsigned long CUnique::_NextObjID]

