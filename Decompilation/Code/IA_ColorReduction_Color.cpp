#include "IA_ColorReduction_Color.h"

// Definitions for class IA_ColorReduction_Color

// address=[0x2fd3640]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::IA_ColorReduction_Color(IA_ColorReduction_Color *this)
 IA_ColorReduction_Color::IA_ColorReduction_Color(void) {
  
  memset(this, 0, 4u);
  return this;
}


// address=[0x2fd3660]
// Decompiled from _BYTE *__thiscall IA_ColorReduction_Color::IA_ColorReduction_Color_0(_BYTE *this, char a2, char a3, char a4)
 IA_ColorReduction_Color::IA_ColorReduction_Color(unsigned char,unsigned char,unsigned char) {
  
  *this = a2;
  this[1] = a3;
  this[2] = a4;
  return this;
}


// address=[0x2fd3690]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::SetValues(  IA_ColorReduction_Color *this,  char a2,  char a3,  char a4,  unsigned __int8 a5)
void  IA_ColorReduction_Color::SetValues(unsigned char,unsigned char,unsigned char,unsigned char) {
  
  IA_ColorReduction_Color *result; // eax

  *(_BYTE *)this = a2;
  *((_BYTE *)this + 1) = a3;
  *((_BYTE *)this + 2) = a4;
  result = this;
  *((_BYTE *)this + 3) = a5;
  return result;
}


// address=[0x2fd36c0]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::SetRed(IA_ColorReduction_Color *this, unsigned __int8 a2)
void  IA_ColorReduction_Color::SetRed(unsigned char) {
  
  IA_ColorReduction_Color *result; // eax

  result = this;
  *(_BYTE *)this = a2;
  return result;
}


// address=[0x2fd36e0]
// Decompiled from char __thiscall IA_ColorReduction_Color::GetRed(IA_ColorReduction_Color *this)
unsigned char  IA_ColorReduction_Color::GetRed(void) {
  
  return *(_BYTE *)this;
}


// address=[0x2fd36f0]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::SetGreen(  IA_ColorReduction_Color *this,  unsigned __int8 a2)
void  IA_ColorReduction_Color::SetGreen(unsigned char) {
  
  IA_ColorReduction_Color *result; // eax

  result = this;
  *((_BYTE *)this + 1) = a2;
  return result;
}


// address=[0x2fd3710]
// Decompiled from char __thiscall IA_ColorReduction_Color::GetGreen(IA_ColorReduction_Color *this)
unsigned char  IA_ColorReduction_Color::GetGreen(void) {
  
  return *((_BYTE *)this + 1);
}


// address=[0x2fd3730]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::SetBlue(IA_ColorReduction_Color *this, unsigned __int8 a2)
void  IA_ColorReduction_Color::SetBlue(unsigned char) {
  
  IA_ColorReduction_Color *result; // eax

  result = this;
  *((_BYTE *)this + 2) = a2;
  return result;
}


// address=[0x2fd3750]
// Decompiled from char __thiscall IA_ColorReduction_Color::GetBlue(IA_ColorReduction_Color *this)
unsigned char  IA_ColorReduction_Color::GetBlue(void) {
  
  return *((_BYTE *)this + 2);
}


// address=[0x2fd3770]
// Decompiled from IA_ColorReduction_Color *__thiscall IA_ColorReduction_Color::SetAlpha(  IA_ColorReduction_Color *this,  unsigned __int8 a2)
void  IA_ColorReduction_Color::SetAlpha(unsigned char) {
  
  IA_ColorReduction_Color *result; // eax

  result = this;
  *((_BYTE *)this + 3) = a2;
  return result;
}


// address=[0x2fd3790]
// Decompiled from char __thiscall IA_ColorReduction_Color::GetAlpha(IA_ColorReduction_Color *this)
unsigned char  IA_ColorReduction_Color::GetAlpha(void) {
  
  return *((_BYTE *)this + 3);
}


