#include "all_headers.h"

// Definitions for class IFilterEntry

// address=[0x2f3b310]
// Decompiled from IFilterEntry *__thiscall IFilterEntry::IFilterEntry(IFilterEntry *this)
 IFilterEntry::IFilterEntry(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &IFilterEntry::_vftable_;
  return this;
}


// address=[0x2f3b660]
// Decompiled from void __thiscall IFilterEntry::~IFilterEntry(IFilterEntry *this)
 IFilterEntry::~IFilterEntry(void) {
  
  *(_DWORD *)this = &IFilterEntry::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


