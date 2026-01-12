#include "CAIResourceData.h"

// Definitions for class CAIResourceData

// address=[0x131c910]
// Decompiled from int __thiscall CAIResourceData::Flags1(CAIResourceData *this)

int  CAIResourceData::Flags1(void)const {
  
  return *((unsigned __int8 *)this + 39);
}


// address=[0x131c930]
// Decompiled from int __thiscall CAIResourceData::Flags9(CAIResourceData *this)

int  CAIResourceData::Flags9(void)const {
  
  return *((unsigned __int8 *)this + 40);
}


// address=[0x131c990]
// Decompiled from int __thiscall CAIResourceData::GroundInfo1(CAIResourceData *this, int a2)

int  CAIResourceData::GroundInfo1(int)const {
  
  return *((unsigned __int8 *)this + a2 + 32);
}


// address=[0x131c9e0]
// Decompiled from int __thiscall CAIResourceData::ResourceAmount1(CAIResourceData *this, int a2)

int  CAIResourceData::ResourceAmount1(int)const {
  
  return *((unsigned __int16 *)this + a2);
}


// address=[0x131ca00]
// Decompiled from int __thiscall CAIResourceData::ResourceAmount9(CAIResourceData *this, int a2)

int  CAIResourceData::ResourceAmount9(int)const {
  
  return *((unsigned __int16 *)this + a2 + 8);
}


