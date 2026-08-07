#if FALSE
#include "CPlayerGameData.h"

// Definitions for class CPlayerGameData

// address=[0x1470ac0]
// Decompiled from CPlayerMagicData *__thiscall CPlayerGameData::MagicData(CPlayerGameData *this)
class CPlayerMagicData &  CPlayerGameData::MagicData(void) {
  
  return &this->m_cMagicData;
}


// address=[0x1473250]
// Decompiled from void __thiscall CPlayerGameData::Clear(CPlayerGameData *this)
void  CPlayerGameData::Clear(void) {
  
  _BYTE v1[12]; // [esp+4h] [ebp-24h] BYREF
  int v2; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int v5; // [esp+24h] [ebp-4h]

  CPlayerGameData::SetFlags(this, 0);
  CPlayerMagicData::Clear(&this->m_cMagicData);
  CPlayerStatisticData::Clear(&this->m_cStatisticData);
  std::list<unsigned short>::clear(&this->m_lEcoSectorId);
  v3 = std::list<unsigned short>::begin(&this->m_lEcoSectorId, (int)v1);
  v2 = v3;
  v5 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(v3);
  v5 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v1);
}


// address=[0x1473300]
// Decompiled from void __thiscall CPlayerGameData::AddEcoSectorId(CPlayerGameData *this, __int16 a2)
void  CPlayerGameData::AddEcoSectorId(int a2) {
  
  int v2[3]; // [esp-20h] [ebp-78h] BYREF
  int v3[3]; // [esp-14h] [ebp-6Ch] BYREF
  __int16 *v4; // [esp-8h] [ebp-60h]
  std::_Iterator_base12 *v5; // [esp-4h] [ebp-5Ch]
  _BYTE v6[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-48h] BYREF
  int v8; // [esp+1Ch] [ebp-3Ch]
  int *v9; // [esp+20h] [ebp-38h]
  int v10; // [esp+24h] [ebp-34h]
  int *v11; // [esp+28h] [ebp-30h]
  int v12; // [esp+2Ch] [ebp-2Ch]
  int v13; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+34h] [ebp-24h]
  std::_Iterator_base12 *v15; // [esp+38h] [ebp-20h]
  BOOL v16; // [esp+3Ch] [ebp-1Ch]
  int v18; // [esp+44h] [ebp-14h]
  __int16 v19; // [esp+48h] [ebp-10h] BYREF
  bool v20; // [esp+4Ah] [ebp-Eh]
  char v21; // [esp+4Bh] [ebp-Dh]
  int v22; // [esp+54h] [ebp-4h]

  v18 = 0;
  v15 = (std::_Iterator_base12 *)std::list<unsigned short>::end(&this->m_lEcoSectorId, (int)v6);
  v14 = v15;
  v22 = 0;
  v18 |= 1u;
  v5 = v15;
  v4 = &a2;
  v11 = v3;
  v10 = std::list<unsigned short>::end(&this->m_lEcoSectorId, (int)v3);
  v9 = v2;
  v8 = std::list<unsigned short>::begin(&this->m_lEcoSectorId, (int)v2);
  v13 = std::find<std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>,int>((int)v7, v2[0], v2[1], v2[2], v3[0], v3[1], v3[2], (int)v4);
  v12 = v13;
  v22 = 1;
  v18 |= 2u;
  v21 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator==(v5);
  v16 = !v21 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 127, "std::find(m_lEcoSectorId.begin(), m_lEcoSectorId.end(), _iESId) == m_lEcoSectorId.end()") == 1;
  v20 = v16;
  v22 = 0;
  if ( (v18 & 2) != 0 )
  {
    v18 &= ~2u;
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v7);
  }
  v22 = -1;
  if ( (v18 & 1) != 0 )
  {
    v18 &= ~1u;
    std::_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v6);
  }
  if ( v20 )
  {
    __debugbreak();
  }
  v19 = a2;
  std::list<unsigned short>::push_back(&this->m_lEcoSectorId, (int)&v19);
}


// address=[0x1473470]
// Decompiled from void __thiscall CPlayerGameData::DeleteEcoSectorId(CPlayerGameData *this, __int16 a2)
void  CPlayerGameData::DeleteEcoSectorId(int a2) {
  
  __int16 v2; // [esp+6h] [ebp-2h] BYREF

  v2 = a2;
  std::list<unsigned short>::remove(&this->m_lEcoSectorId, (unsigned __int16 *)&v2);
}


// address=[0x14734a0]
// Decompiled from void __thiscall CPlayerGameData::ResetIterator(CPlayerGameData *this)
void  CPlayerGameData::ResetIterator(void)const {
  
  _BYTE v1[12]; // [esp+4h] [ebp-24h] BYREF
  int v2; // [esp+10h] [ebp-18h]
  int v3; // [esp+14h] [ebp-14h]
  int v5; // [esp+24h] [ebp-4h]

  v3 = std::list<unsigned short>::begin(&this->m_lEcoSectorId, (int)v1);
  v2 = v3;
  v5 = 0;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(&this->m_iEcoSectorIterator, v3);
  v5 = -1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v1);
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
  bool v12; // [esp+3Fh] [ebp-Dh]
  int v13; // [esp+48h] [ebp-4h]

  v10 = 0;
  v9 = !std::list<unsigned short>::size(&this->m_lEcoSectorId) || (v8 = (std::_Iterator_base12 *)std::list<unsigned short>::end(v3), v7 = v8, v13 = 0, v10 |= 1u, (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator==(v8));
  v12 = v9;
  v13 = -1;
  if ( (v10 & 1) != 0 )
  {
    v10 &= ~1u;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v3);
  }
  if ( v12 )
  {
    v6 = std::list<unsigned short>::begin(&this->m_lEcoSectorId, (int)v2);
    v5 = v6;
    v13 = 1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator=(&this->m_iEcoSectorIterator, v6);
    v13 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(v2);
    return 0;
  }
  else
  {
    v4 = *(unsigned __int16 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator*(&this->m_iEcoSectorIterator);
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::operator++(&this->m_iEcoSectorIterator);
    return v4;
  }
}


// address=[0x1473660]
// Decompiled from void *__thiscall CPlayerGameData::Load(CPlayerGameData *this, struct IS4Chunk *a2)
void  CPlayerGameData::Load(class IS4Chunk & a2) {
  
  a2->LoadUnsigned32(1982022950, 1982022950);
  CPlayerGameData::LoadDataBlock(this, a2, (char *)&this->m_cMagicData, 0x70u);
  return CPlayerGameData::LoadDataBlock(this, a2, (char *)&this->m_cStatisticData, 8u);
}


// address=[0x14736b0]
// Decompiled from void __thiscall CPlayerGameData::Save(CPlayerGameData *this, struct IS4Chunk *a2)
void  CPlayerGameData::Save(class IS4Chunk & a2) {
  
  a2->SaveUnsigned32(1982022950);
  CPlayerGameData::SaveDataBlock(this, a2, &this->m_cMagicData, 0x70u);
  CPlayerGameData::SaveDataBlock(this, a2, &this->m_cStatisticData, 8u);
}


// address=[0x1473700]
// Decompiled from void __thiscall CPlayerGameData::PostLoadInit(CPlayerGameData *this, int a2)
void  CPlayerGameData::PostLoadInit(int a2) {
  
  int i; // [esp+4h] [ebp-4h]

  std::list<unsigned short>::clear(&this->m_lEcoSectorId);
  for ( i = CEcoSectorMgr::GetFirstESForPlayer((CEcoSectorMgr *)g_cESMgr, a2);
        i > 0;
        i = CEcoSectorMgr::GetNextESForPlayer((CEcoSectorMgr *)g_cESMgr, a2, i) )
  {
    CPlayerGameData::AddEcoSectorId(this, i);
  }
}


// address=[0x1498020]
// Decompiled from CPlayerGameData *__thiscall CPlayerGameData::CPlayerGameData(CPlayerGameData *this)
 CPlayerGameData::CPlayerGameData(void) {
  
  this->field_0 = (DWORD)&CPlayerGameData::_vftable_;
  std::list<unsigned short>::list<unsigned short>(&this->m_lEcoSectorId);
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(&this->m_iEcoSectorIterator);
  CPlayerGameData::Clear(this);
  return this;
}


// address=[0x14982b0]
// Decompiled from int __thiscall CPlayerGameData::~CPlayerGameData(CPlayerGameData *this)
 CPlayerGameData::~CPlayerGameData(void) {
  
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<unsigned short>>>(&this->m_iEcoSectorIterator);
  return std::list<unsigned short>::~list<unsigned short>(this);
}


// address=[0x14eb7b0]
// Decompiled from void __thiscall CPlayerGameData::SetPlayerLostFlag(CPlayerGameData *this)
void  CPlayerGameData::SetPlayerLostFlag(void) {
  
  int v1; // eax

  v1 = CPlayerGameData::Flags(this);
  CPlayerGameData::SetFlags(this, v1 | 1);
}


// address=[0x1508240]
// Decompiled from CPlayerStatisticData *__thiscall CPlayerGameData::StaticData(CPlayerGameData *this)
class CPlayerStatisticData &  CPlayerGameData::StaticData(void) {
  
  return &this->m_cStatisticData;
}


// address=[0x160dad0]
// Decompiled from bool __thiscall CPlayerGameData::PlayerLost(CPlayerGameData *this)
bool  CPlayerGameData::PlayerLost(void)const {
  
  return (CPlayerGameData::Flags(this) & 1) != 0;
}


// address=[0x1473760]
// Decompiled from void __thiscall CPlayerGameData::LoadDataBlock(CPlayerGameData *this, struct IS4Chunk *a2, void *_pData, unsigned int _uSize)
void  CPlayerGameData::LoadDataBlock(class IS4Chunk & a2, void * _pData, unsigned int _uSize) {
  
  unsigned int v4; // [esp+4h] [ebp-4h]

  if ( !_pData && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 62, "_pData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !_uSize && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 63, "_uSize > 0") == 1 )
  {
    __debugbreak();
  }
  v4 = a2->LoadUnsigned32(1, _uSize);
  a2->Load(_pData, v4);
  if ( v4 < _uSize )
  {
    memset((char *)_pData + v4, 0, _uSize - v4);
  }
}


// address=[0x1473800]
// Decompiled from void __thiscall CPlayerGameData::SaveDataBlock(CPlayerGameData *this, struct IS4Chunk *a2, void *a3, size_t a4)
void  CPlayerGameData::SaveDataBlock(class IS4Chunk & a2, void * a3, unsigned int a4) {
  
  if ( !a3 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 78, "_pData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !a4 && BBSupportDbgReport(2, "Logic\\PlayerGameData.cpp", 79, "_uSize > 0") == 1 )
  {
    __debugbreak();
  }
  a2->SaveUnsigned32(a4);
  a2->Save(a3, a4);
}


// address=[0x1474ca0]
// Decompiled from void __thiscall CPlayerGameData::SetFlags(CPlayerGameData *this, unsigned int a2)
void  CPlayerGameData::SetFlags(unsigned int a2) {
  
  this->m_iFlags = a2 + 0x536034CF;
}


// address=[0x14eb410]
// Decompiled from DWORD __thiscall CPlayerGameData::Flags(CPlayerGameData *this)
unsigned int  CPlayerGameData::Flags(void)const {
  
  return this->m_iFlags - 0x536034CF;
}


#endif // Already implemented
