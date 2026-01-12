#include "CPlayerGameData.h"

// Definitions for class CPlayerGameData

// address=[0x1470ac0]
// Decompiled from const char *__thiscall CPlayerGameData::MagicData(type_info *this)
class CPlayerMagicData &  CPlayerGameData::MagicData(void) {
  
  return (char *)this + 8;
}


// address=[0x1473250]
// Decompiled from int __thiscall CPlayerGameData::Clear(CPlayerGameData *this)
void  CPlayerGameData::Clear(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-24h] BYREF
  int v3; // [esp+10h] [ebp-18h]
  int v4; // [esp+14h] [ebp-14h]
  CPlayerGameData *v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+24h] [ebp-4h]

  v5 = this;
  CPlayerGameData::SetFlags(this, 0);
  CPlayerMagicData::Clear((CPlayerGameData *)((char *)v5 + 8));
  CPlayerStatisticData::Clear((CPlayerGameData *)((char *)v5 + 120));
  std::list<unsigned short>::clear((char *)v5 + 128);
  v4 = std::list<unsigned short>::begin(v2);
  v3 = v4;
  v6 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(v4);
  v6 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v2);
}


// address=[0x1473300]
// Decompiled from int __thiscall CPlayerGameData::AddEcoSectorId(CPlayerGameData *this, __int16 a2)
void  CPlayerGameData::AddEcoSectorId(int) {
  
  char v3; // [esp-20h] [ebp-78h] BYREF
  int v4; // [esp-1Ch] [ebp-74h]
  int v5; // [esp-18h] [ebp-70h]
  char v6; // [esp-14h] [ebp-6Ch] BYREF
  int v7; // [esp-10h] [ebp-68h]
  int v8; // [esp-Ch] [ebp-64h]
  __int16 *v9; // [esp-8h] [ebp-60h]
  std::_Iterator_base12 *v10; // [esp-4h] [ebp-5Ch]
  _BYTE v11[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v12[12]; // [esp+10h] [ebp-48h] BYREF
  int v13; // [esp+1Ch] [ebp-3Ch]
  char *v14; // [esp+20h] [ebp-38h]
  int v15; // [esp+24h] [ebp-34h]
  char *v16; // [esp+28h] [ebp-30h]
  int v17; // [esp+2Ch] [ebp-2Ch]
  int v18; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v19; // [esp+34h] [ebp-24h]
  std::_Iterator_base12 *v20; // [esp+38h] [ebp-20h]
  BOOL v21; // [esp+3Ch] [ebp-1Ch]
  CPlayerGameData *v22; // [esp+40h] [ebp-18h]
  int v23; // [esp+44h] [ebp-14h]
  __int16 v24; // [esp+48h] [ebp-10h] BYREF
  bool v25; // [esp+4Ah] [ebp-Eh]
  char v26; // [esp+4Bh] [ebp-Dh]
  int v27; // [esp+54h] [ebp-4h]

  v22 = this;
  v23 = 0;
  v20 = (std::_Iterator_base12 *)std::list<unsigned short>::end(v11);
  v19 = v20;
  v27 = 0;
  v23 |= 1u;
  v10 = v20;
  v9 = &a2;
  v16 = &v6;
  v15 = std::list<unsigned short>::end(&v6);
  v14 = &v3;
  v13 = std::list<unsigned short>::begin(&v3);
  v18 = std::find<std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>,int>(
          v12,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9);
  v17 = v18;
  v27 = 1;
  v23 |= 2u;
  v26 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator==(v10);
  v21 = !v26
     && BBSupportDbgReport(
          2,
          "Logic\\PlayerGameData.cpp",
          127,
          "std::find(m_lEcoSectorId.begin(), m_lEcoSectorId.end(), _iESId) == m_lEcoSectorId.end()") == 1;
  v25 = v21;
  v27 = 0;
  if ( (v23 & 2) != 0 )
  {
    v23 &= ~2u;
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v12);
  }
  v27 = -1;
  if ( (v23 & 1) != 0 )
  {
    v23 &= ~1u;
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v11);
  }
  if ( v25 )
    __debugbreak();
  v24 = a2;
  return std::list<unsigned short>::push_back(&v24);
}


// address=[0x1473470]
// Decompiled from int __thiscall CPlayerGameData::DeleteEcoSectorId(CPlayerGameData *this, __int16 a2)
void  CPlayerGameData::DeleteEcoSectorId(int) {
  
  __int16 v3; // [esp+6h] [ebp-2h] BYREF

  v3 = a2;
  return std::list<unsigned short>::remove(&v3);
}


// address=[0x14734a0]
// Decompiled from int __thiscall CPlayerGameData::ResetIterator(CPlayerGameData *this)
void  CPlayerGameData::ResetIterator(void)const {
  
  _BYTE v2[12]; // [esp+4h] [ebp-24h] BYREF
  int v3; // [esp+10h] [ebp-18h]
  int v4; // [esp+14h] [ebp-14h]
  CPlayerGameData *v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+24h] [ebp-4h]

  v5 = this;
  v4 = std::list<unsigned short>::begin(v2);
  v3 = v4;
  v6 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(v4);
  v6 = -1;
  return std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v2);
}


// address=[0x1473520]
// Decompiled from int __thiscall CPlayerGameData::GetNextEcoSectorId(CPlayerGameData *this)
int  CPlayerGameData::GetNextEcoSectorId(void)const {
  
  _BYTE v2[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-3Ch] BYREF
  int v4; // [esp+1Ch] [ebp-30h]
  int v5; // [esp+20h] [ebp-2Ch]
  int v6; // [esp+24h] [ebp-28h]
  std::_Iterator_base12 *v7; // [esp+28h] [ebp-24h]
  std::_Iterator_base12 *v8; // [esp+2Ch] [ebp-20h]
  BOOL v9; // [esp+30h] [ebp-1Ch]
  int v10; // [esp+34h] [ebp-18h]
  CPlayerGameData *v11; // [esp+38h] [ebp-14h]
  bool v12; // [esp+3Fh] [ebp-Dh]
  int v13; // [esp+48h] [ebp-4h]

  v11 = this;
  v10 = 0;
  v9 = !std::list<unsigned short>::size((char *)this + 128)
    || (v8 = (std::_Iterator_base12 *)std::list<unsigned short>::end(v3),
        v7 = v8,
        v13 = 0,
        v10 |= 1u,
        (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator==(v8));
  v12 = v9;
  v13 = -1;
  if ( (v10 & 1) != 0 )
  {
    v10 &= ~1u;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  }
  if ( v12 )
  {
    v6 = std::list<unsigned short>::begin(v2);
    v5 = v6;
    v13 = 1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(v6);
    v13 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v2);
    return 0;
  }
  else
  {
    v4 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*((char *)v11 + 140);
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++((char *)v11 + 140);
    return v4;
  }
}


// address=[0x1473660]
// Decompiled from void __thiscall CPlayerGameData::Load(CPlayerGameData *this, struct IS4Chunk *a2)
void  CPlayerGameData::Load(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1982022950, 1982022950);
  CPlayerGameData::LoadDataBlock(this, a2, (char *)this + 8, 0x70u);
  CPlayerGameData::LoadDataBlock(this, a2, (char *)this + 120, 8u);
}


// address=[0x14736b0]
// Decompiled from void __thiscall CPlayerGameData::Save(CPlayerGameData *this, struct IS4Chunk *a2)
void  CPlayerGameData::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1982022950);
  CPlayerGameData::SaveDataBlock(this, a2, (char *)this + 8, 0x70u);
  CPlayerGameData::SaveDataBlock(this, a2, (char *)this + 120, 8u);
}


// address=[0x1473700]
// Decompiled from int __thiscall CPlayerGameData::PostLoadInit(CPlayerGameData *this, int a2)
void  CPlayerGameData::PostLoadInit(int) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  std::list<unsigned short>::clear((char *)this + 128);
  result = CEcoSectorMgr::GetFirstESForPlayer((CEcoSectorMgr *)g_cESMgr, a2);
  for ( i = result; i > 0; i = result )
  {
    CPlayerGameData::AddEcoSectorId(this, i);
    result = CEcoSectorMgr::GetNextESForPlayer((CEcoSectorMgr *)g_cESMgr, a2, i);
  }
  return result;
}


// address=[0x1498020]
// Decompiled from CPlayerGameData *__thiscall CPlayerGameData::CPlayerGameData(CPlayerGameData *this)
 CPlayerGameData::CPlayerGameData(void) {
  
  *(_DWORD *)this = CPlayerGameData::_vftable_;
  std::list<unsigned short>::list<unsigned short>((char *)this + 128);
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>((char *)this + 140);
  CPlayerGameData::Clear(this);
  return this;
}


// address=[0x14982b0]
// Decompiled from int __thiscall CPlayerGameData::~CPlayerGameData(CPlayerGameData *this)
 CPlayerGameData::~CPlayerGameData(void) {
  
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>((char *)this + 140);
  return std::list<unsigned short>::~list<unsigned short>(this);
}


// address=[0x14eb7b0]
// Decompiled from void __thiscall CPlayerGameData::SetPlayerLostFlag(CPlayerGameData *this)
void  CPlayerGameData::SetPlayerLostFlag(void) {
  
  unsigned int v1; // eax

  v1 = CPlayerGameData::Flags(this);
  CPlayerGameData::SetFlags(this, v1 | 1);
}


// address=[0x1508240]
// Decompiled from char *__thiscall CPlayerGameData::StaticData(CPlayerGameData *this)
class CPlayerStatisticData &  CPlayerGameData::StaticData(void) {
  
  return (char *)this + 120;
}


// address=[0x160dad0]
// Decompiled from bool __thiscall CPlayerGameData::PlayerLost(CPlayerGameData *this)
bool  CPlayerGameData::PlayerLost(void)const {
  
  return (CPlayerGameData::Flags(this) & 1) != 0;
}


// address=[0x1473760]
// Decompiled from void *__thiscall CPlayerGameData::LoadDataBlock(CPlayerGameData *this, struct IS4Chunk *a2, char *a3, unsigned int a4)
void  CPlayerGameData::LoadDataBlock(class IS4Chunk &,void *,unsigned int) {
  
  void *result; // eax
  unsigned int v5; // [esp+4h] [ebp-4h]

  if ( !a3 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 62, "_pData != 0") == 1 )
    __debugbreak();
  if ( !a4 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 63, "_uSize > 0") == 1 )
    __debugbreak();
  v5 = (*(int (__thiscall **)(struct IS4Chunk *, int, unsigned int))(*(_DWORD *)a2 + 4))(a2, 1, a4);
  result = (void *)(**(int (__thiscall ***)(struct IS4Chunk *, char *, unsigned int))a2)(a2, a3, v5);
  if ( v5 < a4 )
    return memset(&a3[v5], 0, a4 - v5);
  return result;
}


// address=[0x1473800]
// Decompiled from int __thiscall CPlayerGameData::SaveDataBlock(CPlayerGameData *this, struct IS4Chunk *a2, void *a3, unsigned int a4)
void  CPlayerGameData::SaveDataBlock(class IS4Chunk &,void *,unsigned int) {
  
  if ( !a3 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 78, "_pData != 0") == 1 )
    __debugbreak();
  if ( !a4 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 79, "_uSize > 0") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(struct IS4Chunk *, unsigned int))(*(_DWORD *)a2 + 20))(a2, a4);
  return (*(int (__thiscall **)(struct IS4Chunk *, void *, unsigned int))(*(_DWORD *)a2 + 16))(a2, a3, a4);
}


// address=[0x1474ca0]
// Decompiled from int __thiscall CPlayerGameData::SetFlags(CPlayerGameData *this, unsigned int a2)
void  CPlayerGameData::SetFlags(unsigned int) {
  
  int result; // eax

  result = a2 + 1398813903;
  *((_DWORD *)this + 1) = a2 + 1398813903;
  return result;
}


// address=[0x14eb410]
// Decompiled from int __thiscall CPlayerGameData::Flags(CPlayerGameData *this)
unsigned int  CPlayerGameData::Flags(void)const {
  
  return *((_DWORD *)this + 1) - 1398813903;
}


