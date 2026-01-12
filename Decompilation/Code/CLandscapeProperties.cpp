#include "CLandscapeProperties.h"

// Definitions for class CLandscapeProperties

// address=[0x141d960]
// Decompiled from bool __thiscall CLandscapeProperties::IsBlockedLand(CLandscapeProperties *this, int a2)
bool  CLandscapeProperties::IsBlockedLand(int) {
  
  return (*((_BYTE *)this + a2) & 0x10) != 0;
}


// address=[0x141d9a0]
// Decompiled from bool __cdecl CLandscapeProperties::IsWater(int a1)
static bool __cdecl CLandscapeProperties::IsWater(int) {
  
  return a1 <= 8;
}


// address=[0x15f5960]
// Decompiled from int __thiscall CLandscapeProperties::TileType(CLandscapeProperties *this, int a2)
unsigned int  CLandscapeProperties::TileType(int) {
  
  return *((unsigned __int8 *)this + a2) << 28;
}


// address=[0x16a5e60]
// Decompiled from CLandscapeProperties *__thiscall CLandscapeProperties::CLandscapeProperties(CLandscapeProperties *this)
 CLandscapeProperties::CLandscapeProperties(void) {
  
  *((_BYTE *)this + 16) = 1;
  *(_BYTE *)this = 18;
  *((_BYTE *)this + 1) = 18;
  *((_BYTE *)this + 2) = 18;
  *((_BYTE *)this + 3) = 18;
  *((_BYTE *)this + 4) = 18;
  *((_BYTE *)this + 5) = 18;
  *((_BYTE *)this + 6) = 18;
  *((_BYTE *)this + 7) = 18;
  *((_BYTE *)this + 48) = 1;
  *((_BYTE *)this + 8) = 18;
  *((_BYTE *)this + 32) = 5;
  *((_BYTE *)this + 17) = 5;
  *((_BYTE *)this + 33) = 5;
  *((_BYTE *)this + 129) = 17;
  *((_BYTE *)this + 35) = 5;
  *((_BYTE *)this + 24) = 1;
  *((_BYTE *)this + 25) = 1;
  *((_BYTE *)this + 18) = 1;
  *((_BYTE *)this + 128) = 17;
  *((_BYTE *)this + 80) = 17;
  *((_BYTE *)this + 81) = 17;
  *((_BYTE *)this + 21) = 1;
  *((_BYTE *)this + 64) = 1;
  *((_BYTE *)this + 65) = 1;
  *((_BYTE *)this + 20) = 1;
  *((_BYTE *)this + 144) = 1;
  *((_BYTE *)this + 145) = 1;
  *((_BYTE *)this + 23) = 1;
  *((_BYTE *)this + 96) = 1;
  *((_BYTE *)this + 97) = 1;
  *((_BYTE *)this + 98) = 1;
  *((_BYTE *)this + 99) = 1;
  *((_BYTE *)this + 28) = 1;
  *((_BYTE *)this + 29) = 1;
  return this;
}


// address=[0x16a7200]
// Decompiled from bool __thiscall CLandscapeProperties::IsSlowType(CLandscapeProperties *this, int a2)
bool  CLandscapeProperties::IsSlowType(int) {
  
  return (*((_BYTE *)this + a2) & 4) != 0;
}


