#include "S4.h"

// Definitions for class S4

// address=[0x16a7240]
// Decompiled from void __thiscall TMap<unsigned char>::LoadMap(void **this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<unsigned char>::LoadMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  void **v5; // [esp+4h] [ebp-8h]
  void *Src; // [esp+8h] [ebp-4h]

  v5 = this;
  Src = (void *)S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !Src
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  j__memcpy(*v5, Src, a4 * a4);
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x16a72d0]
// Decompiled from void __thiscall TMap<unsigned short>::LoadMap(void **this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<unsigned short>::LoadMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  void **v5; // [esp+4h] [ebp-8h]
  void *Src; // [esp+8h] [ebp-4h]

  v5 = this;
  Src = (void *)S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !Src
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  j__memcpy(*v5, Src, 2 * a4 * a4);
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x16a7370]
// Decompiled from void __thiscall TMap<T_GFX_MAP_ELEMENT>::LoadMap(void **this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<struct T_GFX_MAP_ELEMENT>::LoadMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  void **v5; // [esp+4h] [ebp-8h]
  void *Src; // [esp+8h] [ebp-4h]

  v5 = this;
  Src = S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !Src
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  j__memcpy(*v5, Src, 4 * a4 * a4);
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x16a7410]
// Decompiled from char __thiscall TSparseMap<unsigned char>::LoadMap(void *this, S4::CMapFile *a2, unsigned __int16 a3)
bool  TSparseMap<unsigned char>::LoadMap(class S4::CMapFile & a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  void *v5; // [esp+4h] [ebp-8h]
  _DWORD *v6; // [esp+8h] [ebp-4h]

  v5 = this;
  TSparseMap<unsigned char>::Destruct(this);
  TSparseMap<unsigned char>::Construct(v4, v5);
  v6 = S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !v6
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TSparseMap.h",
         477,
         "pBuffer != NULL") == 1 )
  {
    __debugbreak();
  }
  while ( !(unsigned __int8)TSparseMap<unsigned char>::SSaveData::IsBufferEnd(v6) )
  {
    TSparseMap<unsigned char>::Set(v6[1], v6[2], v6);
    v6 += 3;
  }
  S4::CMapFile::CloseChunk(a2, a3, 0);
  return 1;
}


// address=[0x16a7580]
// Decompiled from int __thiscall TMap<unsigned char>::SaveMap(void **this, int a2, __int16 a3, int a4)
void  TMap<unsigned char>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int result; // eax

  result = (int)this;
  if ( *this )
    return S4::CMapFile::SaveChunk(a3, 0, a4 * a4, *this, 0);
  return result;
}


// address=[0x16a75d0]
// Decompiled from int __thiscall TMap<unsigned short>::SaveMap(void **this, int a2, __int16 a3, int a4)
void  TMap<unsigned short>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int result; // eax

  result = (int)this;
  if ( *this )
    return S4::CMapFile::SaveChunk(a3, 0, 2 * a4 * a4, *this, 0);
  return result;
}


// address=[0x16a7620]
// Decompiled from int __thiscall TMap<T_GFX_MAP_ELEMENT>::SaveMap(void **this, int a2, __int16 a3, int a4)
void  TMap<struct T_GFX_MAP_ELEMENT>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int result; // eax

  result = (int)this;
  if ( *this )
    return S4::CMapFile::SaveChunk(a3, 0, 4 * a4 * a4, *this, 0);
  return result;
}


// address=[0x16a7670]
// Decompiled from char __thiscall TSparseMap<unsigned char>::SaveMap(_DWORD *this, int a2, __int16 a3)
bool  TSparseMap<unsigned char>::SaveMap(class S4::CMapFile & a2, int a3) {
  
  int v3; // eax
  void *v5; // [esp-8h] [ebp-60h]
  char v6; // [esp-4h] [ebp-5Ch]
  int v7; // [esp+0h] [ebp-58h]
  int v8; // [esp+0h] [ebp-58h]
  int v9; // [esp+0h] [ebp-58h]
  _DWORD v10[4]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-44h] BYREF
  _BYTE v12[12]; // [esp+20h] [ebp-38h] BYREF
  _DWORD *v13; // [esp+2Ch] [ebp-2Ch]
  std::_Iterator_base12 *v14; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v15; // [esp+34h] [ebp-24h]
  int v16; // [esp+38h] [ebp-20h]
  int v17; // [esp+3Ch] [ebp-1Ch]
  _DWORD *v18; // [esp+40h] [ebp-18h]
  int i; // [esp+44h] [ebp-14h]
  char v20; // [esp+4Ah] [ebp-Eh]
  char v21; // [esp+4Bh] [ebp-Dh]
  int v22; // [esp+54h] [ebp-4h]

  v18 = this;
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>();
  v22 = 0;
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::reserve(v18[7] + 1);
  v16 = 0;
  std::vector<TSparseMap<unsigned char>::TNode *,std::allocator<TSparseMap<unsigned char>::TNode *>>::begin(v12);
  LOBYTE(v22) = 1;
  while ( 1 )
  {
    v15 = (std::_Iterator_base12 *)std::vector<TSparseMap<unsigned char>::TNode *,std::allocator<TSparseMap<unsigned char>::TNode *>>::end(v11);
    v14 = v15;
    LOBYTE(v22) = 2;
    v21 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator!=(v15);
    LOBYTE(v22) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>(v11);
    if ( !v21 )
      break;
    for ( i = *(_DWORD *)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator*(v12)
                        + 4); *(_DWORD *)(i + 4); i = *(_DWORD *)(i + 4) )
    {
      std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::emplace_back<>(v10);
      v17 = std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::back(
              v7,
              v10[0]);
      *(_BYTE *)v17 = *(_BYTE *)(i + 8);
      *(_DWORD *)(v17 + 4) = *(_DWORD *)i;
      *(_DWORD *)(v17 + 8) = v16;
    }
    ++v16;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator++(v12);
  }
  LOBYTE(v22) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>(v12);
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::emplace_back<>(v10);
  v13 = (_DWORD *)std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::back(
                    v7,
                    v10[0]);
  TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(v13);
  v5 = (void *)std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::front(
                 0,
                 v8);
  v3 = std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::size(v10);
  S4::CMapFile::SaveChunk(a3, 0, 12 * v3, v5, v6);
  v20 = 1;
  v22 = -1;
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::~vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>(
    v9,
    v10[0]);
  return v20;
}


