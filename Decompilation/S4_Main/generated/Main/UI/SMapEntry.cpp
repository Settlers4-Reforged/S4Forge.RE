#include "SMapEntry.h"

// Definitions for class SMapEntry

// address=[0x14c0670]
// Decompiled from CLanLobbyMapSettings::SMapEntry *__thiscall CLanLobbyMapSettings::SMapEntry::SMapEntry(CLanLobbyMapSettings::SMapEntry *this)
 CLanLobbyMapSettings::SMapEntry::SMapEntry(void) {
  
  std::string::string(&this->std__string0);
  std::wstring::wstring(&this->std__wstring1C);
  std::string::string(&this->std__string60);
  return this;
}


// address=[0x14c06f0]
// Decompiled from void __thiscall CLanLobbyMapSettings::SMapEntry::~SMapEntry(CLanLobbyMapSettings::SMapEntry *this)
 CLanLobbyMapSettings::SMapEntry::~SMapEntry(void) {
  
  std::string::~string((char *)this + 96);
  std::wstring::~wstring((char *)this + 28);
  std::string::~string(this);
}


