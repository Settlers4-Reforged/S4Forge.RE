#include "S4.h"

// Definitions for class S4

// address=[0x16a7240]
// Decompiled from void __thiscall TMap<unsigned char>::LoadMap(TMap *this, S4::CMapFile *_rMapFile, unsigned __int16 a3, int _iSize)
void  TMap<unsigned char>::LoadMap(class S4::CMapFile & _rMapFile, int a3, int _iSize) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  void *pChunk; // [esp+8h] [ebp-4h]

  pChunk = S4::CMapFile::LoadChunk(_rMapFile, a3, 0, &v4, 0);
  if ( !pChunk
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  memcpy(this->m_pData, pChunk, _iSize * _iSize);
  S4::CMapFile::CloseChunk(_rMapFile, a3, 0);
}


// address=[0x16a72d0]
// Decompiled from void __thiscall TMap<unsigned short>::LoadMap(TMap *this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<unsigned short>::LoadMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  TMap *v5; // [esp+4h] [ebp-8h]
  void *Src; // [esp+8h] [ebp-4h]

  v5 = this;
  Src = S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !Src
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  memcpy(v5->m_pData, Src, 2 * a4 * a4);
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x16a7370]
// Decompiled from void __thiscall TMap<T_GFX_MAP_ELEMENT>::LoadMap(TMap *this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<struct T_GFX_MAP_ELEMENT>::LoadMap(class S4::CMapFile & a2, int a3, int a4) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  TMap *v5; // [esp+4h] [ebp-8h]
  void *Src; // [esp+8h] [ebp-4h]

  v5 = this;
  Src = S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !Src
    && BBSupportDbgReport(2, "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TMap.h", 82, "pChunk != NULL") == 1 )
  {
    __debugbreak();
  }
  memcpy(v5->m_pData, Src, 4 * a4 * a4);
  S4::CMapFile::CloseChunk(a2, a3, 0);
}


// address=[0x16a7410]
// Decompiled from char __thiscall TSparseMap<unsigned char>::LoadMap(TSparseMap *this, S4::CMapFile *a2, unsigned __int16 a3)
bool  TSparseMap<unsigned char>::LoadMap(class S4::CMapFile & a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  TSparseMap::SSaveData *v6; // [esp+8h] [ebp-4h]

  TSparseMap<unsigned char>::Destruct(this);
  TSparseMap<unsigned char>::Construct(this);
  v6 = (TSparseMap::SSaveData *)S4::CMapFile::LoadChunk(a2, a3, 0, &v4, 0);
  if ( !v6
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\world\\TSparseMap.h",
         477,
         "pBuffer != NULL") == 1 )
  {
    __debugbreak();
  }
  while ( !TSparseMap<unsigned char>::SSaveData::IsBufferEnd(v6) )
  {
    TSparseMap<unsigned char>::Set(this, v6->m_iX, v6->m_iY, v6);
    ++v6;
  }
  S4::CMapFile::CloseChunk(a2, a3, 0);
  return 1;
}


// address=[0x16a7580]
// Decompiled from void __thiscall TMap<unsigned char>::SaveMap(TMap *this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<unsigned char>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  if ( this->m_pData )
    S4::CMapFile::SaveChunk(a2, a3, 0, a4 * a4, this->m_pData, 0);
}


// address=[0x16a75d0]
// Decompiled from void __thiscall TMap<unsigned short>::SaveMap(TMap *this, S4::CMapFile *a2, unsigned __int16 a3, int a4)
void  TMap<unsigned short>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  if ( this->m_pData )
    S4::CMapFile::SaveChunk(a2, a3, 0, 2 * a4 * a4, this->m_pData, 0);
}


// address=[0x16a7620]
// Decompiled from void __thiscall TMap<T_GFX_MAP_ELEMENT>::SaveMap(TMap *this, S4::CMapFile *a2, __int16 a3, int a4)
void  TMap<struct T_GFX_MAP_ELEMENT>::SaveMap(class S4::CMapFile & a2, int a3, int a4) {
  
  if ( this->m_pData )
    S4::CMapFile::SaveChunk(a2, a3, 0, 4 * a4 * a4, this->m_pData, 0);
}


// address=[0x16a7670]
// Decompiled from char __thiscall TSparseMap<unsigned char>::SaveMap(TSparseMap *this, S4::CMapFile *_rMapFile, unsigned __int16 a3)
bool  TSparseMap<unsigned char>::SaveMap(class S4::CMapFile & _rMapFile, int a3) {
  
  int v3; // eax
  const void *v5; // [esp-8h] [ebp-60h]
  _DWORD vec[4]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v7[12]; // [esp+14h] [ebp-44h] BYREF
  _DWORD v8[3]; // [esp+20h] [ebp-38h] BYREF
  _DWORD *v9; // [esp+2Ch] [ebp-2Ch]
  std::_Iterator_base12 *end; // [esp+34h] [ebp-24h] MAPDST
  int v12; // [esp+38h] [ebp-20h]
  TSparseMap::SSaveData *v13; // [esp+3Ch] [ebp-1Ch]
  TSparseMap::TNode *i; // [esp+44h] [ebp-14h]
  char v16; // [esp+4Ah] [ebp-Eh]
  bool v17; // [esp+4Bh] [ebp-Dh]
  int exceptionBlock; // [esp+54h] [ebp-4h]

  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>(vec);
  exceptionBlock = 0;
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::reserve(
    vec,
    this->m_uSetNodes + 1);
  v12 = 0;
  std::vector<TSparseMap<unsigned char>::TNode *,std::allocator<TSparseMap<unsigned char>::TNode *>>::begin(
    this,
    (int)v8);
  LOBYTE(exceptionBlock) = 1;
  while ( 1 )
  {
    end = (std::_Iterator_base12 *)std::vector<TSparseMap<unsigned char>::TNode *,std::allocator<TSparseMap<unsigned char>::TNode *>>::end(
                                     this,
                                     (int)v7);
    LOBYTE(exceptionBlock) = 2;
    v17 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator!=(
            v8,
            end);
    LOBYTE(exceptionBlock) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>(v7);
    if ( !v17 )
      break;
    for ( i = *(TSparseMap::TNode **)(*(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator*(v8)
                                    + 4); i->m_pNextNode; i = i->m_pNextNode )
    {
      std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::emplace_back<>(vec);
      v13 = (TSparseMap::SSaveData *)std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::back(vec);
      LOBYTE(v13->m_iData) = i->m_iValue;
      v13->m_iX = i->m_iHeight;
      v13->m_iY = v12;
    }
    ++v12;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::operator++(v8);
  }
  LOBYTE(exceptionBlock) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<TSparseMap<unsigned char>::TNode *>>>(v8);
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::emplace_back<>(vec);
  v9 = (_DWORD *)std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::back(vec);
  TSparseMap<unsigned char>::SSaveData::SetAsBufferEnd(v9);
  v5 = (const void *)std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::front(vec);
  v3 = std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::size(vec);
  S4::CMapFile::SaveChunk(_rMapFile, a3, 0, 12 * v3, v5, 0);
  v16 = 1;
  exceptionBlock = -1;
  std::vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>::~vector<TSparseMap<unsigned char>::SSaveData,std::allocator<TSparseMap<unsigned char>::SSaveData>>();
  return v16;
}


