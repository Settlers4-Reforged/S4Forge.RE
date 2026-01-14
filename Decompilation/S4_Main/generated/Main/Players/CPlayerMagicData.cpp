#include "all_headers.h"

// Definitions for class CPlayerMagicData

// address=[0x1470ae0]
// Decompiled from int __thiscall CPlayerMagicData::ManaAmount(CPlayerMagicData *this)
int  CPlayerMagicData::ManaAmount(void)const {
  
  return *((_DWORD *)this + 1) ^ 0x27356334;
}


// address=[0x1470b70]
// Decompiled from unsigned int __thiscall CPlayerMagicData::MaxNumberOfBigTemples(CPlayerMagicData *this)
int  CPlayerMagicData::MaxNumberOfBigTemples(void)const {
  
  return *((_DWORD *)this + 3) ^ 0x83476350;
}


// address=[0x1470db0]
// Decompiled from int __thiscall CPlayerMagicData::SpellCategoryCost(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::SpellCategoryCost(int)const {
  
  return *((_DWORD *)this + a2 + 4) ^ (-1824038075 * (a2 + 1));
}


// address=[0x1470de0]
// Decompiled from int __thiscall CPlayerMagicData::SpellCategoryCounter(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::SpellCategoryCounter(int)const {
  
  return *((_DWORD *)this + a2 + 12) ^ (945190039 * (17 - a2));
}


// address=[0x1470e30]
// Decompiled from int __thiscall CPlayerMagicData::TotalAmountOfCollectedMana(CPlayerMagicData *this)
int  CPlayerMagicData::TotalAmountOfCollectedMana(void)const {
  
  return *((_DWORD *)this + 2) ^ 0x17A65B3C;
}


// address=[0x1470920]
// Decompiled from CPlayerMagicData *__thiscall CPlayerMagicData::ClearManaAmountChangedFlag(CPlayerMagicData *this)
void  CPlayerMagicData::ClearManaAmountChangedFlag(void) {
  
  CPlayerMagicData *result; // eax

  result = this;
  *(_DWORD *)this &= ~1u;
  return result;
}


// address=[0x1470b00]
// Decompiled from bool __thiscall CPlayerMagicData::ManaAmountChanged(CPlayerMagicData *this)
bool  CPlayerMagicData::ManaAmountChanged(void)const {
  
  return (*(_DWORD *)this & 1) != 0;
}


// address=[0x1470b40]
// Decompiled from void *__thiscall CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(CPlayerMagicData *this)
void  CPlayerMagicData::MarkMaxSpellCastNumbersAsInvalid(void) {
  
  return memset((char *)this + 80, -1, 0x20u);
}


// address=[0x1470b90]
// Decompiled from int __thiscall CPlayerMagicData::MaxSpellCastNumber(CPlayerMagicData *this, int a2)
int  CPlayerMagicData::MaxSpellCastNumber(int)const {
  
  return *((_DWORD *)this + a2 + 20);
}


// address=[0x1470c90]
// Decompiled from int __thiscall CPlayerMagicData::SetManaAmount(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetManaAmount(int) {
  
  int result; // eax

  *(_DWORD *)this |= 1u;
  result = a2 ^ 0x27356334;
  *((_DWORD *)this + 1) = a2 ^ 0x27356334;
  return result;
}


// address=[0x1470cd0]
// Decompiled from CPlayerMagicData *__thiscall CPlayerMagicData::SetManaAmountChangedFlag(CPlayerMagicData *this)
void  CPlayerMagicData::SetManaAmountChangedFlag(void) {
  
  CPlayerMagicData *result; // eax

  result = this;
  *(_DWORD *)this |= 1u;
  return result;
}


// address=[0x1470cf0]
// Decompiled from int __thiscall CPlayerMagicData::SetMaxSpellCastNumber(CPlayerMagicData *this, int a2, int a3)
void  CPlayerMagicData::SetMaxSpellCastNumber(int,int) {
  
  int result; // eax

  result = a2;
  *((_DWORD *)this + a2 + 20) = a3;
  return result;
}


// address=[0x1470d10]
// Decompiled from CPlayerMagicData *__thiscall CPlayerMagicData::SetSpellCategoryCost(CPlayerMagicData *this, int a2, int a3)
void  CPlayerMagicData::SetSpellCategoryCost(int,int) {
  
  CPlayerMagicData *result; // eax

  result = this;
  *((_DWORD *)this + a2 + 4) = a3 ^ (-1824038075 * (a2 + 1));
  return result;
}


// address=[0x1470d40]
// Decompiled from CPlayerMagicData *__thiscall CPlayerMagicData::SetSpellCategoryCounter(CPlayerMagicData *this, int a2, int a3)
void  CPlayerMagicData::SetSpellCategoryCounter(int,int) {
  
  CPlayerMagicData *result; // eax

  result = this;
  *((_DWORD *)this + a2 + 12) = a3 ^ (945190039 * (17 - a2));
  return result;
}


// address=[0x1470d80]
// Decompiled from int __thiscall CPlayerMagicData::SetTotalAmountOfCollectedMana(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetTotalAmountOfCollectedMana(int) {
  
  int result; // eax

  result = a2 ^ 0x17A65B3C;
  *((_DWORD *)this + 2) = a2 ^ 0x17A65B3C;
  return result;
}


// address=[0x14731d0]
// Decompiled from void __thiscall CPlayerMagicData::Clear(CPlayerMagicData *this)
void  CPlayerMagicData::Clear(void) {
  
  int i; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = 1;
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
// Decompiled from unsigned int __thiscall CPlayerMagicData::SetMaxNumberOfBigTemples(CPlayerMagicData *this, int a2)
void  CPlayerMagicData::SetMaxNumberOfBigTemples(int) {
  
  unsigned int result; // eax

  result = a2 ^ 0x83476350;
  *((_DWORD *)this + 3) = a2 ^ 0x83476350;
  return result;
}


