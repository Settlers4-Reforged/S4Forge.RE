#include "CGrid.h"

// Definitions for class CGrid

// address=[0x2fc5520]
// Decompiled from CGrid *__thiscall CGrid::CGrid(CGrid *this, int a2)
 CGrid::CGrid(int) {
  
  *((_DWORD *)this + 1) = a2;
  *(_DWORD *)this = operator new[](*((_DWORD *)this + 1) * *((_DWORD *)this + 1));
  memset(*(void **)this, 0, *((_DWORD *)this + 1) * *((_DWORD *)this + 1));
  return this;
}


// address=[0x2fc5580]
// Decompiled from int __thiscall CGrid::~CGrid(void **this)
 CGrid::~CGrid(void) {
  
  return operator delete[](*this);
}


// address=[0x2fc55b0]
// Decompiled from int __thiscall CGrid::getElement(CGrid *this, int a2, int a3)
int  CGrid::getElement(int,int) {
  
  if ( a2 >= *((_DWORD *)this + 1) || a3 >= *((_DWORD *)this + 1) )
    return -1;
  else
    return *(unsigned __int8 *)(*(_DWORD *)this + a2 + *((_DWORD *)this + 1) * a3);
}


// address=[0x2fc55f0]
// Decompiled from char __thiscall CGrid::setElement(CGrid *this, int a2, int a3, char a4)
void  CGrid::setElement(int,int,int) {
  
  char result; // al

  result = (char)this;
  if ( a2 >= *((_DWORD *)this + 1) )
    return result;
  result = a3;
  if ( a3 >= *((_DWORD *)this + 1) )
    return result;
  result = a4;
  *(_BYTE *)(*(_DWORD *)this + a2 + *((_DWORD *)this + 1) * a3) = a4;
  return result;
}


// address=[0x2fc5630]
// Decompiled from int __thiscall CGrid::getElement(CGrid *this, int a2)
int  CGrid::getElement(int) {
  
  if ( a2 >= *((_DWORD *)this + 1) * *((_DWORD *)this + 1) )
    return -1;
  else
    return *(unsigned __int8 *)(*(_DWORD *)this + a2);
}


// address=[0x2fc5660]
// Decompiled from void __thiscall CGrid::setElement(CGrid *this, int a2, int a3)
void  CGrid::setElement(int,int) {
  
  ;
}


// address=[0x2fc5670]
// Decompiled from int __thiscall CGrid::getSize(CGrid *this)
int  CGrid::getSize(void) {
  
  return *((_DWORD *)this + 1);
}


