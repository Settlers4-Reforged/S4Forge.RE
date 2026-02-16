#include "PathSplitResult.h"

// Definitions for class PathSplitResult

// address=[0x134e750]
// Decompiled from void __thiscall FilePaths::PathSplitResult::~PathSplitResult(FilePaths::PathSplitResult *this)
FilePaths::PathSplitResult::~PathSplitResult(void) = default;

// address=[0x2eff700]
// Decompiled from FilePaths::PathSplitResult *__thiscall FilePaths::PathSplitResult::PathSplitResult(  FilePaths::PathSplitResult *this,  FilePaths::PathSplitResult *a2)
FilePaths::PathSplitResult::PathSplitResult(FilePaths::PathSplitResult &&a2)
{
  this->m_swpDrive = std::move(a2.m_swpDrive);
  this->m_vSplits = std::move(a2.m_vSplits);
  this->m_swpOut = std::move(a2.m_swpOut);
  this->m_bSplit = a2.m_bSplit;
}

// address=[0x2eff760]
// Decompiled from FilePaths::PathSplitResult *__thiscall FilePaths::PathSplitResult::PathSplitResult(FilePaths::PathSplitResult *this)
FilePaths::PathSplitResult::PathSplitResult(void) = default;