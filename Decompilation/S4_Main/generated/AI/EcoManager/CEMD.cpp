#include "CEMD.h"

// Definitions for class CEMD

// address=[0x1345630]
// Decompiled from CEcoManager::CEMD *__thiscall CEcoManager::CEMD::CEMD(CEcoManager::CEMD *this)
 CEcoManager::CEMD::CEMD(void) {
  
  _vec_ctor(
    (char *)this + 760,
    0xA10u,
    0x53u,
    CAI_Ecosector_Grid_Iterator::CAI_Ecosector_Grid_Iterator,
    CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator);
  _vec_ctor(
    (char *)this + 214568,
    0x10u,
    0x53u,
    std::vector<SAI_ECO_POSS_BUILD_PLACE>::vector<SAI_ECO_POSS_BUILD_PLACE>,
    std::vector<SAI_ECO_POSS_BUILD_PLACE>::~vector<SAI_ECO_POSS_BUILD_PLACE>);
  _vec_ctor(
    (char *)this + 215896,
    0x10u,
    0x53u,
    std::vector<SPOSS_BUILD_PLACE>::vector<SPOSS_BUILD_PLACE>,
    std::vector<SPOSS_BUILD_PLACE>::~vector<SPOSS_BUILD_PLACE>);
  return this;
}


// address=[0x1345d80]
// Decompiled from void __thiscall CEcoManager::CEMD::~CEMD(CEcoManager::CEMD *this)
 CEcoManager::CEMD::~CEMD(void) {
  
  `eh vector destructor iterator'(
    (char *)this + 215896,
    0x10u,
    0x53u,
    std::vector<SPOSS_BUILD_PLACE>::~vector<SPOSS_BUILD_PLACE>);
  `eh vector destructor iterator'(
    (char *)this + 214568,
    0x10u,
    0x53u,
    std::vector<SAI_ECO_POSS_BUILD_PLACE>::~vector<SAI_ECO_POSS_BUILD_PLACE>);
  `eh vector destructor iterator'(
    (char *)this + 760,
    0xA10u,
    0x53u,
    CAI_Ecosector_Grid_Iterator::~CAI_Ecosector_Grid_Iterator);
}


