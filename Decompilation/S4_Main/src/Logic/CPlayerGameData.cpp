#include "CPlayerGameData.h"

#include "CBB/CBBSupport.h"
#include "LoadSave/IS4Chunk.h"

// Definitions for class CPlayerGameData

// address=[0x1470ac0]
// Decompiled from CPlayerMagicData *__thiscall CPlayerGameData::MagicData(CPlayerGameData *this)
class CPlayerMagicData &CPlayerGameData::MagicData(void) {
  return this->m_cMagicData;
}


// address=[0x1473250]
// Decompiled from void __thiscall CPlayerGameData::Clear(CPlayerGameData *this)
void CPlayerGameData::Clear(void) {
  CPlayerGameData::SetFlags(0);
  this->m_cMagicData.Clear();
  this->m_cStatisticData.Clear();
  this->m_lEcoSectorId.clear();
  this->m_iEcoSectorIterator = this->m_lEcoSectorId.begin();
}


// address=[0x1473300]
// Decompiled from void __thiscall CPlayerGameData::AddEcoSectorId(CPlayerGameData *this, __int16 a2)
void CPlayerGameData::AddEcoSectorId(int _iESId) {
  BB_ASSERT(std::find(m_lEcoSectorId.begin(), m_lEcoSectorId.end(), _iESId) == m_lEcoSectorId.end())
  this->m_lEcoSectorId.push_back(_iESId);
}


// address=[0x1473470]
// Decompiled from void __thiscall CPlayerGameData::DeleteEcoSectorId(CPlayerGameData *this, __int16 a2)
void CPlayerGameData::DeleteEcoSectorId(int _iESId) {
  this->m_lEcoSectorId.remove(_iESId);
}


// address=[0x14734a0]
// Decompiled from void __thiscall CPlayerGameData::ResetIterator(CPlayerGameData *this)
void CPlayerGameData::ResetIterator(void) const {
  *this->m_iEcoSectorIterator = *this->m_lEcoSectorId.begin(); // TODO: the function is const, but technically isnt because of this?
}


// address=[0x1473520]
// Decompiled from int __thiscall CPlayerGameData::GetNextEcoSectorId(CPlayerGameData *this)
int CPlayerGameData::GetNextEcoSectorId(void) const {
  if(this->m_lEcoSectorId.empty() || this->m_iEcoSectorIterator == this->m_lEcoSectorId.end()) {
    return 0;
  }

  const unsigned short iESId = *this->m_iEcoSectorIterator;
  (*this->m_iEcoSectorIterator)++; // TODO: the function is const, but technically isnt because of this?
  return iESId;
}


// address=[0x1473660]
// Decompiled from void *__thiscall CPlayerGameData::Load(CPlayerGameData *this, struct IS4Chunk *a2)
void CPlayerGameData::Load(IS4Chunk &a2) {
  a2.LoadUnsigned32(1982022950, 1982022950);
  static_assert(sizeof(this->m_cMagicData) == 0x70, "Size of m_cMagicData is expected to be 0x70 bytes");
  static_assert(sizeof(this->m_cStatisticData) == 8, "Size of m_cStatisticData is expected to be 8 bytes");
  this->LoadDataBlock(a2, &this->m_cMagicData, sizeof(this->m_cMagicData));
  this->LoadDataBlock(a2, &this->m_cStatisticData, sizeof(this->m_cStatisticData));
}


// address=[0x14736b0]
// Decompiled from void __thiscall CPlayerGameData::Save(CPlayerGameData *this, struct IS4Chunk *a2)
void CPlayerGameData::Save(IS4Chunk &a2) {
  a2.SaveUnsigned32(1982022950);
  this->SaveDataBlock(a2, &this->m_cMagicData, sizeof(this->m_cMagicData));
  this->SaveDataBlock(a2, &this->m_cStatisticData, sizeof(this->m_cStatisticData));
}


// address=[0x1473700]
// Decompiled from void __thiscall CPlayerGameData::PostLoadInit(CPlayerGameData *this, int a2)
void CPlayerGameData::PostLoadInit(int a2) {
  // [esp+4h] [ebp-4h]

  this->m_lEcoSectorId.clear();
  for(int i = g_cESMgr.GetFirstESForPlayer(a2); i > 0; i = g_cESMgr.GetNextESForPlayer(a2, i)) {
    CPlayerGameData::AddEcoSectorId(i);
  }
}


// address=[0x1498020]
// Decompiled from CPlayerGameData *__thiscall CPlayerGameData::CPlayerGameData(CPlayerGameData *this)
CPlayerGameData::CPlayerGameData(void) : m_lEcoSectorId(), m_iEcoSectorIterator(m_lEcoSectorId.begin()) {
  CPlayerGameData::Clear();
}


// address=[0x14982b0]
// Decompiled from int __thiscall CPlayerGameData::~CPlayerGameData(CPlayerGameData *this)
CPlayerGameData::~CPlayerGameData(void) = default;


// address=[0x14eb7b0]
// Decompiled from void __thiscall CPlayerGameData::SetPlayerLostFlag(CPlayerGameData *this)
void CPlayerGameData::SetPlayerLostFlag(void) {
  CPlayerGameData::SetFlags(CPlayerGameData::Flags() | 1);
}


// address=[0x1508240]
// Decompiled from CPlayerStatisticData *__thiscall CPlayerGameData::StaticData(CPlayerGameData *this)
class CPlayerStatisticData &CPlayerGameData::StaticData(void) {
  return this->m_cStatisticData;
}


// address=[0x160dad0]
// Decompiled from bool __thiscall CPlayerGameData::PlayerLost(CPlayerGameData *this)
bool CPlayerGameData::PlayerLost(void) const {
  return (CPlayerGameData::Flags() & 1) != 0;
}


// address=[0x1473760]
// Decompiled from void __thiscall CPlayerGameData::LoadDataBlock(  CPlayerGameData *this,  struct IS4Chunk *a2,  char *_pData,  unsigned int _uSize)
void CPlayerGameData::LoadDataBlock(class IS4Chunk &a2, void *_pData, unsigned int _uSize) {
  BB_ASSERT(_pData != 0)
  BB_ASSERT(_uSize > 0);

  unsigned int iLoadedDataSize = a2.LoadUnsigned32(1, _uSize);
  a2.Load(_pData, iLoadedDataSize);
  if(iLoadedDataSize < _uSize)
    memset(static_cast<char *>(_pData) + iLoadedDataSize, 0, _uSize - iLoadedDataSize);
}


// address=[0x1473800]
// Decompiled from void __thiscall CPlayerGameData::SaveDataBlock(CPlayerGameData *this, struct IS4Chunk *a2, void *a3, size_t a4)
void CPlayerGameData::SaveDataBlock(class IS4Chunk &a2, void *_pData, unsigned int _uSize) {
  BB_ASSERT(_pData != 0)
  BB_ASSERT(_uSize > 0);
  a2.SaveUnsigned32(_uSize);
  a2.Save(_pData, _uSize);
}


// address=[0x1474ca0]
// Decompiled from void __thiscall CPlayerGameData::SetFlags(CPlayerGameData *this, unsigned int a2)
void CPlayerGameData::SetFlags(unsigned int a2) {
  this->m_iFlags = a2 + 0x536034CF;
}


// address=[0x14eb410]
// Decompiled from DWORD __thiscall CPlayerGameData::Flags(CPlayerGameData *this)
unsigned int CPlayerGameData::Flags(void) const {
  return this->m_iFlags - 0x536034CF;
}


