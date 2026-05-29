#if FALSE
#include "CBuildingFlagsWalk.h"

// Definitions for class CBuildingFlagsWalk

// address=[0x14eaf90]
// Decompiled from CBuildingFlagsWalk *__thiscall CBuildingFlagsWalk::CBuildingFlagsWalk(  CBuildingFlagsWalk *this,  int a2,  int a3,  int a4,  int a5,  std::vector *a6)
 CBuildingFlagsWalk::CBuildingFlagsWalk(int a2, int a3, int a4, int a5, class std::vector<unsigned int,class std::allocator<unsigned int> > const & a6) {
  
  this->m_v0 = a6;
  this->m_iU0 = a2 - a4 - 1;
  this->m_iU1 = a3 - a5;
  CBuildingFlagsWalk::Init(this);
  return this;
}


// address=[0x14eb380]
// Decompiled from int __thiscall CBuildingFlagsWalk::CurrentX(CBuildingFlagsWalk *this)
int  CBuildingFlagsWalk::CurrentX(void)const {
  
  return this->m_iCurrentX;
}


// address=[0x14eb3a0]
// Decompiled from int __thiscall CBuildingFlagsWalk::CurrentY(CBuildingFlagsWalk *this)
int  CBuildingFlagsWalk::CurrentY(void)const {
  
  return this->m_iCurrentY;
}


// address=[0x14eb430]
// Decompiled from void __thiscall CBuildingFlagsWalk::Init(CBuildingFlagsWalk *this)
void  CBuildingFlagsWalk::Init(void) {
  
  this->m_iCurrentX = this->m_iU0;
  this->m_iCurrentY = this->m_iU1;
  if ( std::vector<unsigned int>::size(this->m_v0) )
    this->m_pFirst = *(_DWORD *)std::vector<unsigned int>::operator[](this->m_v0, 0);
  else
    this->m_pFirst = 0;
  this->m_iSteps = 1;
}


// address=[0x14eb5b0]
// Decompiled from char __thiscall CBuildingFlagsWalk::NextPosition(CBuildingFlagsWalk *this)
bool  CBuildingFlagsWalk::NextPosition(void) {
  
  DWORD m_iCurrentX; // [esp+0h] [ebp-Ch]
  signed int i; // [esp+4h] [ebp-8h]

  while ( !this->m_pFirst )
  {
    if ( this->m_iSteps >= std::vector<unsigned int>::size(this->m_v0) )
    {
      this->m_pFirst = 0;
      return 0;
    }
    this->m_iCurrentX = this->m_iU0;
    ++this->m_iCurrentY;
    this->m_pFirst = *(_DWORD *)std::vector<unsigned int>::operator[](this->m_v0, this->m_iSteps);
    ++this->m_iSteps;
  }
  m_iCurrentX = this->m_iCurrentX;
  for ( i = this->m_pFirst; i >= 0; i *= 2 )
    ++m_iCurrentX;
  this->m_iCurrentX = m_iCurrentX + 1;
  this->m_pFirst = 2 * i;
  return 1;
}


#endif // Already implemented
