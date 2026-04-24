#include "CPlayerMagicData.h"

// Definitions for class CPlayerMagicData

// address=[0x1470ae0]
// Decompiled from int __thiscall CPlayerMagicData::ManaAmount(CPlayerMagicData *this)
int  CPlayerMagicData::ManaAmount(void)const {
  
  return this->m_iManaAmount ^ 0x27356334;
}


// address=[0x1470b70]
// Decompiled from unsigned int __thiscall CPlayerMagicData::MaxNumberOfBigTemples(CPlayerMagicData *this)
int  CPlayerMagicData::MaxNumberOfBigTemples(void)const {
  
  return this->m_iMaxNumberOfBigTemples ^ 0x83476350;
}


// address=[0x1470db0]
// Decompiled from DWORD __thiscall CPlayerMagicData::SpellCategoryCost(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::SpellCategoryCost(int a2)const {
  
  return this->m_aSpellCategoryCost[a2] ^ (-1824038075 * (a2 + 1));
}


// address=[0x1470de0]
// Decompiled from DWORD __thiscall CPlayerMagicData::SpellCategoryCounter(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::SpellCategoryCounter(int a2)const {
  
  return this->m_aSpellCategoryCounter[a2] ^ (945190039 * (17 - a2));
}


// address=[0x1470e30]
// Decompiled from int __thiscall CPlayerMagicData::TotalAmountOfCollectedMana(CPlayerMagicData *this)
int  CPlayerMagicData::TotalAmountOfCollectedMana(void)const {
  
  return this->m_iTotalAmountOfCollectedMana ^ 0x17A65B3C;
}


// address=[0x1470920]
// Decompiled from void __thiscall CPlayerMagicData::ClearManaAmountChangedFlag(CPlayerMagicData *this)
void  CPlayerMagicData::ClearManaAmountChangedFlag(void) {
  
  this->m_iFlags &= ~1u;
}


// address=[0x1470b00]
// Decompiled from bool __thiscall CPlayerMagicData::ManaAmountChanged(CPlayerMagicData *this)
bool  CPlayerMagicData::ManaAmountChanged(void)const {
  
  return (this->m_iFlags & 1) != 0;
}


// address=[0x1470b40]
// Decompiled from void *__thiscall CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(CPlayerMagicData *this)
void  CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(void) {
  
  return memset(this->m_aMaxSpellCastNumbers, -1, sizeof(this->m_aMaxSpellCastNumbers));
}


// address=[0x1470b90]
// Decompiled from DWORD __thiscall CPlayerMagicData::MaxSpellCastNumber(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::MaxSpellCastNumber(int a2)const {
  
  return this->m_aMaxSpellCastNumbers[a2];
}


// address=[0x1470c90]
// Decompiled from void __thiscall CPlayerMagicData::SetManaAmount(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetManaAmount(int a2) {
  
  this->m_iFlags |= 1u;
  this->m_iManaAmount = a2 ^ 0x27356334;
}


// address=[0x1470cd0]
// Decompiled from void __thiscall CPlayerMagicData::SetManaAmountChangedFlag(CPlayerMagicData *this)
void  CPlayerMagicData::SetManaAmountChangedFlag(void) {
  
  this->m_iFlags |= 1u;
}


// address=[0x1470cf0]
// Decompiled from void __thiscall CPlayerMagicData::SetMaxSpellCastNumber(CPlayerMagicData *this, int a2, DWORD a3)
void  CPlayerMagicData::SetMaxSpellCastNumber(int a2, int a3) {
  
  this->m_aMaxSpellCastNumbers[a2] = a3;
}


// address=[0x1470d10]
// Decompiled from void __thiscall CPlayerMagicData::SetSpellCategoryCost(CPlayerMagicData *this, int a2, int a3)
void  CPlayerMagicData::SetSpellCategoryCost(int a2, int a3) {
  
  this->m_aSpellCategoryCost[a2] = a3 ^ (-1824038075 * (a2 + 1));
}


// address=[0x1470d40]
// Decompiled from void __thiscall CPlayerMagicData::SetSpellCategoryCounter(CPlayerMagicData *this, int a2, int a3)
void  CPlayerMagicData::SetSpellCategoryCounter(int a2, int a3) {
  
  this->m_aSpellCategoryCounter[a2] = a3 ^ (945190039 * (17 - a2));
}


// address=[0x1470d80]
// Decompiled from void __thiscall CPlayerMagicData::SetTotalAmountOfCollectedMana(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetTotalAmountOfCollectedMana(int a2) {
  
  this->m_iTotalAmountOfCollectedMana = a2 ^ 0x17A65B3C;
}


// address=[0x14731d0]
// Decompiled from void __thiscall CPlayerMagicData::Clear(CPlayerMagicData *this)
void  CPlayerMagicData::Clear(void) {
  
  int i; // [esp+0h] [ebp-8h]

  this->m_iFlags = 1;
  CPlayerMagicData::SetManaAmount(this, 0);
  CPlayerMagicData::SetTotalAmountOfCollectedMana(this, 0);
  CPlayerMagicData::SetMaxNumberOfBigTemples(this, 0);
  for ( i = 0; i < 8; ++i )
  {
    CPlayerMagicData::SetSpellCategoryCost(this, i, 0);
    CPlayerMagicData::SetSpellCategoryCounter(this, i, 0);
  }
  CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(this);
}


// address=[0x1474cd0]
// Decompiled from void __thiscall CPlayerMagicData::SetMaxNumberOfBigTemples(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetMaxNumberOfBigTemples(int a2) {
  
  this->m_iMaxNumberOfBigTemples = a2 ^ 0x83476350;
}


