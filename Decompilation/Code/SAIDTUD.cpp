#include "SAIDTUD.h"

// Definitions for class SAIDTUD

// address=[0x1334f50]
// Decompiled from CAIDarkTribe::SAIDTUD *__thiscall CAIDarkTribe::SAIDTUD::SAIDTUD(CAIDarkTribe::SAIDTUD *this)

 CAIDarkTribe::SAIDTUD::SAIDTUD(void) {
  
  std::vector<SAIDTOCCUPIEDELEMENT>::vector<SAIDTOCCUPIEDELEMENT>();
  std::vector<int>::vector<int>((char *)this + 8208);
  std::vector<int>::vector<int>((char *)this + 8224);
  std::vector<int>::vector<int>((char *)this + 8240);
  std::list<int>::list<int>((char *)this + 8256);
  CAIVWVector::CAIVWVector((CAIDarkTribe::SAIDTUD *)((char *)this + 8268));
  return this;
}


// address=[0x1335470]
// Decompiled from int __thiscall CAIDarkTribe::SAIDTUD::~SAIDTUD(CAIDarkTribe::SAIDTUD *this)

 CAIDarkTribe::SAIDTUD::~SAIDTUD(void) {
  
  int v3; // [esp+0h] [ebp-4h]

  CAIVWVector::~CAIVWVector((CAIDarkTribe::SAIDTUD *)((char *)this + 8268));
  std::list<int>::~list<int>(this);
  std::vector<int>::~vector<int>();
  std::vector<int>::~vector<int>();
  std::vector<int>::~vector<int>();
  return std::vector<SAIDTOCCUPIEDELEMENT>::~vector<SAIDTOCCUPIEDELEMENT>(v3);
}


