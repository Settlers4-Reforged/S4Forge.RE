#include "GenerateContext.h"

// Definitions for class GenerateContext

// address=[0x2f2c9d0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::GenerateContext::GenerateContext(_DWORD *this, int a2, const char *a3, int a4)
 AdvXMLParser::GenerateContext::GenerateContext(std::string & a2, char const * a3, unsigned long a4) {
  
  const char *v5; // [esp+0h] [ebp-8h]

  *this = a4;
  if ( a3 )
    v5 = a3;
  else
    v5 = "  ";
  this[1] = v5;
  this[2] = a2;
  this[3] = 0;
  *((_BYTE *)this + 16) = 0;
  *((_BYTE *)this + 17) = 0;
  return this;
}


// address=[0x2f2ca30]
// Decompiled from _DWORD *__thiscall AdvXMLParser::GenerateContext::GenerateContext_0(_DWORD *this, int a2)
 AdvXMLParser::GenerateContext::GenerateContext(class AdvXMLParser::GenerateContext const & a2) {
  
  *this = *(_DWORD *)a2;
  this[1] = *(_DWORD *)(a2 + 4);
  this[2] = *(_DWORD *)(a2 + 8);
  this[3] = *(_DWORD *)(a2 + 12);
  *((_BYTE *)this + 16) = *(_BYTE *)(a2 + 16);
  *((_BYTE *)this + 17) = *(_BYTE *)(a2 + 17);
  return this;
}


// address=[0x2f2ca90]
// Decompiled from _DWORD *__thiscall AdvXMLParser::GenerateContext::operator_(_DWORD *this, int a2)
void  AdvXMLParser::GenerateContext::operator=(class AdvXMLParser::GenerateContext const & a2) {
  
  _DWORD *result; // eax

  *this = *(_DWORD *)a2;
  this[1] = *(_DWORD *)(a2 + 4);
  std::string::operator=(*(_DWORD *)(a2 + 8));
  this[3] = *(_DWORD *)(a2 + 12);
  *((_BYTE *)this + 16) = *(_BYTE *)(a2 + 16);
  result = this;
  *((_BYTE *)this + 17) = *(_BYTE *)(a2 + 17);
  return result;
}


// address=[0x2f2caf0]
// Decompiled from AdvXMLParser::GenerateContext *__thiscall AdvXMLParser::GenerateContext::GenerateStartTagIndentation(  AdvXMLParser::GenerateContext *this)
void  AdvXMLParser::GenerateContext::GenerateStartTagIndentation(void) {
  
  AdvXMLParser::GenerateContext *result; // eax

  ++*((_DWORD *)this + 3);
  result = this;
  if ( (*(_DWORD *)this & 1) != 0 )
    return result;
  AdvXMLParser::GenerateContext::GenerateNewLine(this);
  AdvXMLParser::GenerateContext::GenerateIndentation(this);
  *((_BYTE *)this + 16) = 0;
  return result;
}


// address=[0x2f2cb30]
// Decompiled from AdvXMLParser::GenerateContext *__thiscall AdvXMLParser::GenerateContext::GenerateEndTagIndentation(  AdvXMLParser::GenerateContext *this)
void  AdvXMLParser::GenerateContext::GenerateEndTagIndentation(void) {
  
  AdvXMLParser::GenerateContext *result; // eax

  if ( *((int *)this + 3) <= 0 && BBSupportDbgReport(2, "Source\\Xml\\writer.cpp", 83, "m_nLevel > 0") == 1 )
    __debugbreak();
  result = (AdvXMLParser::GenerateContext *)(*(_DWORD *)this & 1);
  if ( result )
    return result;
  if ( *((_BYTE *)this + 16) )
  {
    AdvXMLParser::GenerateContext::GenerateNewLine(this);
    AdvXMLParser::GenerateContext::GenerateIndentation(this);
  }
  --*((_DWORD *)this + 3);
  result = this;
  *((_BYTE *)this + 16) = 1;
  return result;
}


// address=[0x2f2cba0]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::EndTag(AdvXMLParser::GenerateContext *this)
void  AdvXMLParser::GenerateContext::EndTag(void) {
  
  int result; // eax

  if ( *((int *)this + 3) <= 0 && BBSupportDbgReport(2, "Source\\Xml\\writer.cpp", 100, "m_nLevel > 0") == 1 )
    __debugbreak();
  result = *((_DWORD *)this + 3) - 1;
  *((_DWORD *)this + 3) = result;
  *((_BYTE *)this + 16) = 1;
  return result;
}


// address=[0x2f2cbf0]
// Decompiled from AdvXMLParser::GenerateContext *__fastcall AdvXMLParser::GenerateContext::GenerateNewLine(  AdvXMLParser::GenerateContext *this)
void  AdvXMLParser::GenerateContext::GenerateNewLine(void) {
  
  AdvXMLParser::GenerateContext *result; // eax

  result = this;
  if ( (*(_DWORD *)this & 1) != 0 )
    return result;
  result = (AdvXMLParser::GenerateContext *)*((unsigned __int8 *)this + 17);
  if ( *((_BYTE *)this + 17) )
    return result;
  result = (AdvXMLParser::GenerateContext *)std::string::operator+=(10);
  *((_BYTE *)this + 17) = 1;
  return result;
}


// address=[0x2f2d730]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::operator+=(_BYTE *this, int a2)
void  AdvXMLParser::GenerateContext::operator+=(std::string const & a2) {
  
  this[17] = 0;
  return std::string::operator+=(a2);
}


// address=[0x2f2d760]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::operator+=(_BYTE *this, char a2)
void  AdvXMLParser::GenerateContext::operator+=(char a2) {
  
  this[17] = 0;
  return std::string::operator+=(a2);
}


// address=[0x2f2d790]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::operator+=(_BYTE *this, char *Str)
void  AdvXMLParser::GenerateContext::operator+=(char const * Str) {
  
  this[17] = 0;
  return std::string::operator+=(Str);
}


// address=[0x2f2d860]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::MustPreserve(AdvXMLParser::GenerateContext *this)
bool  AdvXMLParser::GenerateContext::MustPreserve(void)const {
  
  return *(_DWORD *)this & 1;
}


// address=[0x2f2cc30]
// Decompiled from int __thiscall AdvXMLParser::GenerateContext::GenerateIndentation(AdvXMLParser::GenerateContext *this)
void  AdvXMLParser::GenerateContext::GenerateIndentation(void) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-8h]

  if ( (*(_DWORD *)this & 1) != 0
    && BBSupportDbgReport(2, "Source\\Xml\\writer.cpp", 57, "(m_nOptions & GENERATE_PRESERVE) == 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 17) = 0;
  for ( i = 0; ; ++i )
  {
    result = *((_DWORD *)this + 3) - 1;
    if ( i >= result )
      break;
    std::string::operator+=(*((char **)this + 1));
  }
  return result;
}


