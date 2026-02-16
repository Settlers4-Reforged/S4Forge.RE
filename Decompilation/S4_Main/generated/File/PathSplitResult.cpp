#if FALSE
#include "PathSplitResult.h"

// Definitions for class PathSplitResult

// address=[0x134e750]
// Decompiled from void __thiscall FilePaths::PathSplitResult::~PathSplitResult(FilePaths::PathSplitResult *this)
 FilePaths::PathSplitResult::~PathSplitResult(void) {
  
  std::wstring::~wstring(&this->m_swpDirectoryName);
  std::vector<std::wstring>::~vector<std::wstring>(&this->m_vSplits);
  std::wstring::~wstring(&this->m_swpDrive);
}


// address=[0x2eff700]
// Decompiled from FilePaths::PathSplitResult *__thiscall FilePaths::PathSplitResult::PathSplitResult(  FilePaths::PathSplitResult *this,  FilePaths::PathSplitResult *a2)
 FilePaths::PathSplitResult::PathSplitResult(struct FilePaths::PathSplitResult && a2) {
  
  std::wstring::wstring(&this->m_swpDrive, &a2->m_swpDrive);
  std::vector<std::wstring>::vector<std::wstring>(&this->m_vSplits, (int)&a2->m_vSplits);
  std::wstring::wstring(&this->m_swpDirectoryName, &a2->m_swpDirectoryName);
  this->m_bSplit = a2->m_bSplit;
  return this;
}


// address=[0x2eff760]
// Decompiled from FilePaths::PathSplitResult *__thiscall FilePaths::PathSplitResult::PathSplitResult(FilePaths::PathSplitResult *this)
 FilePaths::PathSplitResult::PathSplitResult(void) {
  
  std::wstring::wstring(this);
  std::vector<std::wstring>::vector<std::wstring>(&this->m_vSplits);
  std::wstring::wstring(&this->m_swpDirectoryName);
  this->m_bSplit = 0;
  return this;
}


#endif // Already implemented
