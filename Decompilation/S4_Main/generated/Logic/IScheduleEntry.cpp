#include "IScheduleEntry.h"

// Definitions for class IScheduleEntry

// address=[0x2f4f510]
// Decompiled from IScheduleEntry *__thiscall IScheduleEntry::IScheduleEntry(IScheduleEntry *this)
 IScheduleEntry::IScheduleEntry(void) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &IScheduleEntry::_vftable_;
  return this;
}


// address=[0x2f4f540]
// Decompiled from void __thiscall IScheduleEntry::~IScheduleEntry(IScheduleEntry *this)
 IScheduleEntry::~IScheduleEntry(void) {
  
  *(_DWORD *)this = &IScheduleEntry::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


