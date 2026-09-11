#include "SEnvironmentInfo.h"

// Definitions for class SEnvironmentInfo

// address=[0x1481020]
// Decompiled from SEnvironmentInfo *__thiscall SEnvironmentInfo::SEnvironmentInfo(SEnvironmentInfo *this)
 SEnvironmentInfo::SEnvironmentInfo(void) {
  
  ((void (__cdecl *)())std::string::string)();
  ((void (__cdecl *)())std::string::string)();
  return this;
}


// address=[0x1481050]
// Decompiled from void __thiscall SEnvironmentInfo::~SEnvironmentInfo(SEnvironmentInfo *this)
 SEnvironmentInfo::~SEnvironmentInfo(void) {
  
  std::string::~string(&this->gpuGap[1]);
  std::string::~string(&this->sOSAdditionalInfo);
}


