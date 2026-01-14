#include "all_headers.h"

// Definitions for class ParsingException

// address=[0x14f37c0]
// Decompiled from void __thiscall AdvXMLParser::ParsingException::~ParsingException(AdvXMLParser::ParsingException *this)
 AdvXMLParser::ParsingException::~ParsingException(void) {
  
  AdvXMLParser::Exception::~Exception(this);
}


// address=[0x14f3ef0]
// Decompiled from int __thiscall AdvXMLParser::ParsingException::GetLine(AdvXMLParser::ParsingException *this)
int  AdvXMLParser::ParsingException::GetLine(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2f27ef0]
// Decompiled from boost::exception_detail::clone_base *__thiscall AdvXMLParser::ParsingException::ParsingException(  boost::exception_detail::clone_base *this,  struct boost::exception_detail::clone_base *a2)
 AdvXMLParser::ParsingException::ParsingException(class AdvXMLParser::ParsingException const &) {
  
  AdvXMLParser::Exception::Exception(this, a2);
  *(_DWORD *)this = &AdvXMLParser::ParsingException::_vftable_;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  return this;
}


// address=[0x2f27f50]
// Decompiled from AdvXMLParser::Exception *__thiscall AdvXMLParser::ParsingException::ParsingException(  AdvXMLParser::Exception *this,  int a2,  int a3,  int a4)
 AdvXMLParser::ParsingException::ParsingException(enum AdvXMLParser::PARSER_ERROR,int,int) {
  
  AdvXMLParser::Exception::Exception(this);
  *(_DWORD *)this = &AdvXMLParser::ParsingException::_vftable_;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = a4;
  return this;
}


