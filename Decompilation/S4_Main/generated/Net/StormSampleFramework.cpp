#include "StormSampleFramework.h"

// Definitions for class StormSampleFramework

// address=[0x1683070]
// Decompiled from StormSampleFramework *__thiscall StormSampleFramework::StormSampleFramework(  StormSampleFramework *this,  struct StormManager *a2,  bool a3)
 StormSampleFramework::StormSampleFramework(class StormManager & a2, bool a3) {
  
  SampleFrameworkApplication::SampleFrameworkApplication(this);
  *(_DWORD *)this = StormSampleFramework::_vftable_;
  *((_DWORD *)this + 1) = a2;
  return this;
}


// address=[0x1685010]
// Decompiled from StormSampleFramework *__thiscall StormSampleFramework::~StormSampleFramework(StormSampleFramework *this)
 StormSampleFramework::~StormSampleFramework(void) {
  
  StormSampleFramework *result; // eax

  result = this;
  *(_DWORD *)this = StormSampleFramework::_vftable_;
  return result;
}


