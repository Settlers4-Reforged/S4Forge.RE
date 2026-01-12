#include "Bookmark.h"

// Definitions for class Bookmark

// address=[0x2f1e530]
// Decompiled from void __thiscall AdvXMLParser::Bookmark::GetSubString(void **this, void *a2, int a3)
void  AdvXMLParser::Bookmark::GetSubString(std::string &,int) {
  
  void *v3; // [esp+0h] [ebp-28h]
  _BYTE v5[28]; // [esp+8h] [ebp-20h] BYREF

  if ( a3 + *((_DWORD *)*this + 2) < (unsigned int)this[1]
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\xml\\Reader.inl",
         155,
         "m_reader.m_szSourceCurrent + nNumEndSkip >= m_szSourceCurrent") == 1 )
  {
    __debugbreak();
  }
  v3 = (void *)std::string::string(this[1], *((_DWORD *)*this + 2) - (_DWORD)this[1] - a3);
  std::string::operator=(a2, v3);
  std::string::~string(v5);
}


// address=[0x2f1e5f0]
// Decompiled from int __thiscall AdvXMLParser::Bookmark::Reset(AdvXMLParser::Bookmark *this)
void  AdvXMLParser::Bookmark::Reset(void) {
  
  int result; // eax

  *((_DWORD *)this + 1) = *(_DWORD *)(*(_DWORD *)this + 8);
  *((_DWORD *)this + 2) = *(_DWORD *)(*(_DWORD *)this + 16);
  result = *(_DWORD *)this;
  *((_DWORD *)this + 3) = *(_DWORD *)(*(_DWORD *)this + 20);
  return result;
}


// address=[0x2f27ea0]
// Decompiled from AdvXMLParser::Bookmark *__thiscall AdvXMLParser::Bookmark::Bookmark(  AdvXMLParser::Bookmark *this,  struct AdvXMLParser::Parser *a2)
 AdvXMLParser::Bookmark::Bookmark(class AdvXMLParser::Parser &) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 4);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 5);
  return this;
}


// address=[0x2f286d0]
// Decompiled from int __thiscall AdvXMLParser::Bookmark::Restore(AdvXMLParser::Bookmark *this)
void  AdvXMLParser::Bookmark::Restore(void) {
  
  int result; // eax

  *(_DWORD *)(*(_DWORD *)this + 8) = *((_DWORD *)this + 1);
  *(_DWORD *)(*(_DWORD *)this + 16) = *((_DWORD *)this + 2);
  result = *(_DWORD *)this;
  *(_DWORD *)(*(_DWORD *)this + 20) = *((_DWORD *)this + 3);
  return result;
}


