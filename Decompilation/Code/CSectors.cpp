#include "CSectors.h"

// Definitions for class CSectors

// address=[0x15e79a0]
// Decompiled from CSectors *__thiscall CSectors::Init(CSectors *this)

void  CSectors::Init(void) {
  
  CSectors *result; // eax

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 40961) = 1;
  j__memset((char *)this + 4, 0, 0x8000u);
  j__memset((char *)this + 32772, -1, 0x20000u);
  *((_BYTE *)this + 4) = 1;
  result = this;
  *((_DWORD *)this + 8193) = 0;
  return result;
}


// address=[0x15e7a20]
// Decompiled from int __thiscall CSectors::NewSector(CSectors *this, unsigned __int8 a2)

int  CSectors::NewSector(unsigned char) {
  
  if ( *(int *)this >= 32766
    && BBSupportDbgReport(2, "Pathing\\Tiling.cpp", 5927, "m_iSectorCount < SECTORS_MAX - 2") == 1 )
  {
    __debugbreak();
  }
  ++*(_DWORD *)this;
  while ( *((_BYTE *)this + *((_DWORD *)this + 40961) + 4) )
    *((_DWORD *)this + 40961) = ((unsigned __int16)*((_DWORD *)this + 40961) + 1) & 0x7FFF;
  *((_BYTE *)this + *((_DWORD *)this + 40961) + 4) = a2 | 1;
  *((_DWORD *)this + *((_DWORD *)this + 40961) + 8193) = 0;
  return *((_DWORD *)this + 40961);
}


// address=[0x15e7ad0]
// Decompiled from CSectors *__thiscall CSectors::DeleteSector(CSectors *this, CSectors *a2)

void  CSectors::DeleteSector(int) {
  
  CSectors *result; // eax

  result = this;
  if ( *(_DWORD *)this <= 0 || (int)a2 <= 0 )
    return result;
  --*(_DWORD *)this;
  *((_BYTE *)this + (_DWORD)a2 + 4) = 0;
  result = a2;
  *((_DWORD *)this + (_DWORD)a2 + 8193) = -1;
  return result;
}


// address=[0x15e7b40]
// Decompiled from // public: int __thiscall CSectors::CountSectors(unsigned char)const 
int __thiscall CSectors::CountSectors(_BYTE *this, unsigned __int8 a2)

int  CSectors::CountSectors(unsigned char)const {
  
  int v3; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 0x8000; ++i )
    v3 += (unsigned __int8)(a2 & this[i + 4]) == a2;
  return v3;
}


// address=[0x15f3ed0]
// Decompiled from CSectors *__thiscall CSectors::CSectors(CSectors *this)

 CSectors::CSectors(void) {
  
  CSectors::Init(this);
  return this;
}


// address=[0x15f4620]
// Decompiled from int __thiscall CSectors::IncSectorSize(CSectors *this, int a2)

void  CSectors::IncSectorSize(int) {
  
  int result; // eax

  result = a2;
  ++*((_DWORD *)this + a2 + 8193);
  return result;
}


// address=[0x15f5660]
// Decompiled from int __thiscall CSectors::SectorSize(CSectors *this, int a2)

int  CSectors::SectorSize(int)const {
  
  return *((_DWORD *)this + a2 + 8193);
}


