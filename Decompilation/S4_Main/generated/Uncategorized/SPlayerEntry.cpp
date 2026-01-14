#include "all_headers.h"

// Definitions for class SPlayerEntry

// address=[0x14b7e50]
// Decompiled from CLanLobbyGameSettings::SPlayerEntry *__thiscall CLanLobbyGameSettings::SPlayerEntry::SPlayerEntry(  CLanLobbyGameSettings::SPlayerEntry *this)
 CLanLobbyGameSettings::SPlayerEntry::SPlayerEntry(void) {
  
  std::wstring::wstring((char *)this + 8);
  *(_BYTE *)this = 1;
  *((_DWORD *)this + 1) = 0;
  std::wstring::operator=((char *)this + 8, (wchar_t *)&word_3746B00);
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 64) = 0;
  return this;
}


// address=[0x14bcda0]
// Decompiled from void __thiscall CLanLobbyGameSettings::SPlayerEntry::~SPlayerEntry(CDHtmlElementEventSink *this)
 CLanLobbyGameSettings::SPlayerEntry::~SPlayerEntry(void) {
  
  std::wstring::~wstring((char *)this + 8);
}


