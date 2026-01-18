#include "SAI_ECO_POSS_BUILD_PLACE.h"

// Definitions for class SAI_ECO_POSS_BUILD_PLACE

// address=[0x1345720]
// Decompiled from _WORD *__thiscall SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(_WORD *this, _WORD *a2)
 SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(struct SAI_ECO_POSS_BUILD_PLACE && a2) {
  
  *this = *a2;
  std::vector<int>::vector<int>(a2 + 2);
  std::vector<signed char>::vector<signed char>(a2 + 10);
  return this;
}


// address=[0x1345770]
// Decompiled from SAI_ECO_POSS_BUILD_PLACE *__thiscall SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(  SAI_ECO_POSS_BUILD_PLACE *this,  const struct SAI_ECO_POSS_BUILD_PLACE *a2)
 SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(struct SAI_ECO_POSS_BUILD_PLACE const &) {
  
  *(_WORD *)this = *(_WORD *)a2;
  std::vector<int>::vector<int>((char *)a2 + 4);
  std::vector<signed char>::vector<signed char>((char *)a2 + 20);
  return this;
}


// address=[0x1345810]
// Decompiled from SAI_ECO_POSS_BUILD_PLACE *__thiscall SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(SAI_ECO_POSS_BUILD_PLACE *this)
 SAI_ECO_POSS_BUILD_PLACE::SAI_ECO_POSS_BUILD_PLACE(void) {
  
  std::vector<int>::vector<int>((char *)this + 4);
  std::vector<signed char>::vector<signed char>((char *)this + 20);
  return this;
}


// address=[0x1345e40]
// Decompiled from int __thiscall SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE(SAI_ECO_POSS_BUILD_PLACE *this)
 SAI_ECO_POSS_BUILD_PLACE::~SAI_ECO_POSS_BUILD_PLACE(void) {
  
  std::vector<signed char>::~vector<signed char>(this);
  return std::vector<int>::~vector<int>();
}


