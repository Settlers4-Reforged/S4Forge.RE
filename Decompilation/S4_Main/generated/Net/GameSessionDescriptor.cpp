#include "GameSessionDescriptor.h"

// Definitions for class GameSessionDescriptor

// address=[0x1308e60]
// Decompiled from int __thiscall GameSessionDescriptor::SetPeerCount(GameSessionDescriptor *this, unsigned int a2)
void  GameSessionDescriptor::SetPeerCount(unsigned long) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-24h] BYREF
  GameSessionDescriptor *v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+24h] [ebp-4h]

  v4 = this;
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>(a2);
  v5 = 0;
  storm::DataNumber<unsigned long,8,0>::operator=(v3);
  v5 = -1;
  return storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>(v3);
}


// address=[0x1308f70]
// Decompiled from int __thiscall GameSessionDescriptor::SetSaveId(GameSessionDescriptor *this, int a2)
void  GameSessionDescriptor::SetSaveId(long) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-24h] BYREF
  GameSessionDescriptor *v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+24h] [ebp-4h]

  v4 = this;
  storm::DataNumber<long,8,0>::DataNumber<long,8,0>(a2);
  v5 = 0;
  storm::DataNumber<long,8,0>::operator=(v3);
  v5 = -1;
  return storm::DataNumber<long,8,0>::~DataNumber<long,8,0>(v3);
}


// address=[0x15c4ac0]
// Decompiled from int __thiscall GameSessionDescriptor::GetPeerCount(GameSessionDescriptor *this)
unsigned long  GameSessionDescriptor::GetPeerCount(void)const {
  
  return storm::DataNumber<unsigned long,8,0>::Get((char *)this + 684, this);
}


// address=[0x15c4c80]
// Decompiled from int __thiscall GameSessionDescriptor::GetTickCount(GameSessionDescriptor *this)
unsigned long  GameSessionDescriptor::GetTickCount(void)const {
  
  return storm::DataNumber<unsigned long,8,0>::Get((char *)this + 744, this);
}


// address=[0x160e800]
// Decompiled from unsigned int __thiscall GameSessionDescriptor::GetMaxSlots(GameSessionDescriptor *this, unsigned int *a2)
void  GameSessionDescriptor::GetMaxSlots(unsigned long &)const {
  
  unsigned int result; // eax

  result = storm::DataNumber<unsigned long,8,0>::Get((char *)this + 704, this);
  *a2 = result;
  return result;
}


// address=[0x160e820]
// Decompiled from int __thiscall GameSessionDescriptor::SetMaxSlots(GameSessionDescriptor *this, unsigned int a2)
void  GameSessionDescriptor::SetMaxSlots(unsigned long) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-2Ch] BYREF
  GameSessionDescriptor *v4; // [esp+18h] [ebp-18h]
  int v5; // [esp+1Ch] [ebp-14h]
  int v6; // [esp+20h] [ebp-10h]
  int v7; // [esp+2Ch] [ebp-4h]

  v4 = this;
  v6 = storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>(a2);
  v5 = v6;
  storm::DataNumber<unsigned long,8,0>::operator=(v6);
  v7 = -1;
  return storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>(v3);
}


// address=[0x160e8a0]
// Decompiled from unsigned int __thiscall GameSessionDescriptor::GetFreeSlots(GameSessionDescriptor *this, unsigned int *a2)
void  GameSessionDescriptor::GetFreeSlots(unsigned long &)const {
  
  unsigned int result; // eax

  result = storm::DataNumber<unsigned long,8,0>::Get((char *)this + 724, this);
  *a2 = result;
  return result;
}


// address=[0x160e8c0]
// Decompiled from int __thiscall GameSessionDescriptor::SetFreeSlots(GameSessionDescriptor *this, unsigned int a2)
void  GameSessionDescriptor::SetFreeSlots(unsigned long) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-2Ch] BYREF
  GameSessionDescriptor *v4; // [esp+18h] [ebp-18h]
  int v5; // [esp+1Ch] [ebp-14h]
  int v6; // [esp+20h] [ebp-10h]
  int v7; // [esp+2Ch] [ebp-4h]

  v4 = this;
  v6 = storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>(a2);
  v5 = v6;
  storm::DataNumber<unsigned long,8,0>::operator=(v6);
  v7 = -1;
  return storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>(v3);
}


// address=[0x16110a0]
// Decompiled from const char *GameSessionDescriptor::GetClassTypeName()
static char const * __cdecl GameSessionDescriptor::GetClassTypeName(void) {
  
  return "GameSessionDescriptor";
}


// address=[0x16110f0]
// Decompiled from int GameSessionDescriptor::GetClassTypeStaticCrc()
static unsigned long __cdecl GameSessionDescriptor::GetClassTypeStaticCrc(void) {
  
  return 1812608079;
}


// address=[0x161ff10]
// Decompiled from int __thiscall GameSessionDescriptor::GetSaveId(GameSessionDescriptor *this)
long  GameSessionDescriptor::GetSaveId(void)const {
  
  return storm::DataNumber<long,8,0>::Get((char *)this + 664, this);
}


// address=[0x1682600]
// Decompiled from GameSessionDescriptor *__thiscall GameSessionDescriptor::GameSessionDescriptor(GameSessionDescriptor *this)
 GameSessionDescriptor::GameSessionDescriptor(void) {
  
  storm::SimpleSessionDescriptor_Matchmaking::SimpleSessionDescriptor_Matchmaking(this);
  *(_DWORD *)this = &GameSessionDescriptor::_vftable_;
  storm::DataWStringSized<255,1>::DataWStringSized<255,1>();
  storm::DataWStringSized<255,1>::DataWStringSized<255,1>();
  storm::DataNumber<long,8,0>::DataNumber<long,8,0>();
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>();
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>();
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>();
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>();
  return this;
}


// address=[0x1684a60]
// Decompiled from void __thiscall GameSessionDescriptor::~GameSessionDescriptor(GameSessionDescriptor *this)
 GameSessionDescriptor::~GameSessionDescriptor(void) {
  
  storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>((char *)this + 744);
  storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>((char *)this + 724);
  storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>((char *)this + 704);
  storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>((char *)this + 684);
  storm::DataNumber<long,8,0>::~DataNumber<long,8,0>((char *)this + 664);
  storm::DataWStringSized<255,1>::~DataWStringSized<255,1>((GameSessionDescriptor *)((char *)this + 620));
  storm::DataWStringSized<255,1>::~DataWStringSized<255,1>((GameSessionDescriptor *)((char *)this + 576));
  storm::SimpleSessionDescriptor_Matchmaking::~SimpleSessionDescriptor_Matchmaking(this);
}


// address=[0x168cfb0]
// Decompiled from int __thiscall GameSessionDescriptor::SetTickCount(GameSessionDescriptor *this, unsigned int a2)
void  GameSessionDescriptor::SetTickCount(unsigned long) {
  
  _BYTE v3[20]; // [esp+4h] [ebp-24h] BYREF
  GameSessionDescriptor *v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+24h] [ebp-4h]

  v4 = this;
  storm::DataNumber<unsigned long,8,0>::DataNumber<unsigned long,8,0>(a2);
  v5 = 0;
  storm::DataNumber<unsigned long,8,0>::operator=(v3);
  v5 = -1;
  return storm::DataNumber<unsigned long,8,0>::~DataNumber<unsigned long,8,0>(v3);
}


