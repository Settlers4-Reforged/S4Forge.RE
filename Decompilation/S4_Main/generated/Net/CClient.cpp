#include "CClient.h"

// Definitions for class CClient

// address=[0x15b1b00]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this)
 CClient::CClient(void) {
  
  *(_DWORD *)this = &CClient::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 3) = -1;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = -1;
  return this;
}


// address=[0x15b1b60]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this, const struct CClient *a2)
 CClient::CClient(class CClient const & a2) {
  
  *(_DWORD *)this = &CClient::_vftable_;
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 5);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 6);
  *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 4) = *((_BYTE *)a2 + 4);
  return this;
}


// address=[0x15b1bd0]
// Decompiled from CClient *__thiscall CClient::CClient(CClient *this, int a2, int a3, int a4)
 CClient::CClient(long a2, int a3, int a4) {
  
  *(_DWORD *)this = &CClient::_vftable_;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = a4;
  *((_DWORD *)this + 5) = timeGetTime();
  *((_DWORD *)this + 6) = timeGetTime();
  *((_DWORD *)this + 8) = a3;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 4) = 0;
  return this;
}


// address=[0x15b1c40]
// Decompiled from CClient *__thiscall CClient::~CClient(CClient *this)
 CClient::~CClient(void) {
  
  CClient *result; // eax

  result = this;
  *(_DWORD *)this = &CClient::_vftable_;
  return result;
}


// address=[0x15b1c60]
// Decompiled from bool __thiscall CClient::operator==(_DWORD *this, int a2)
bool  CClient::operator==(unsigned int a2) {
  
  return this[3] == a2;
}


// address=[0x15b3530]
// Decompiled from int __thiscall CClient::operator=(int this, int a2)
class CClient &  CClient::operator=(class CClient const & a2) {
  
  *(_BYTE *)(this + 4) = *(_BYTE *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  return this;
}


// address=[0x15b3b30]
// Decompiled from int __thiscall CClient::GetIP(CClient *this)
long  CClient::GetIP(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x15b3b50]
// Decompiled from int __thiscall CClient::GetLastPingTime(CClient *this)
unsigned int  CClient::GetLastPingTime(void) {
  
  return *((_DWORD *)this + 5);
}


// address=[0x15b3b70]
// Decompiled from int __thiscall CClient::GetPeerId(pairNode *this)
unsigned int  CClient::GetPeerId(void) {
  
  return *((_DWORD *)this + 3);
}


// address=[0x15c4df0]
// Decompiled from CClient *__thiscall CClient::SetLastAckTime(CClient *this, unsigned int a2)
void  CClient::SetLastAckTime(unsigned int a2) {
  
  CClient *result; // eax

  result = this;
  *((_DWORD *)this + 4) = a2;
  return result;
}


