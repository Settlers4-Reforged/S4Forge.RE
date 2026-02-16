#include "PathSplitResult.h"

// Definitions for class PathSplitResult

// address=[0x134e750]
// Decompiled from void __thiscall FilePaths::PathSplitResult::~PathSplitResult(FilePaths::PathSplitResult *this)
 FilePaths::PathSplitResult::~PathSplitResult(void) {
  
  void *v2; // [esp+0h] [ebp-4h]

  std::wstring::~wstring((char *)this + 44);
  std::vector<std::wstring>::~vector<std::wstring>(this);
  std::wstring::~wstring(v2);
}


// address=[0x2eff700]
// Decompiled from _BYTE *__thiscall FilePaths::PathSplitResult::PathSplitResult(_BYTE *this, _BYTE *a2)
 FilePaths::PathSplitResult::PathSplitResult(struct FilePaths::PathSplitResult && a2) {
  
  std::wstring::wstring(this, a2);
  std::vector<std::wstring>::vector<std::wstring>(a2 + 28);
  std::wstring::wstring(this + 44, a2 + 44);
  this[72] = a2[72];
  return this;
}


// address=[0x2eff760]
// Decompiled from char *__thiscall FilePaths::PathSplitResult::PathSplitResult(FilePaths::PathSplitResult *this)
 FilePaths::PathSplitResult::PathSplitResult(void) {
  
  char *v3; // [esp+0h] [ebp-4h]

  std::wstring::wstring(this);
  std::vector<std::wstring>::vector<std::wstring>(this);
  std::wstring::wstring(v3 + 44);
  v3[72] = 0;
  return v3;
}


