#include "Exception.h"

// Definitions for class Exception

// address=[0x2f17420]
// Decompiled from AdvXMLParser::Exception *__thiscall AdvXMLParser::Exception::Exception(AdvXMLParser::Exception *this)
 AdvXMLParser::Exception::Exception(void) {
  
  *(_DWORD *)this = &AdvXMLParser::Exception::_vftable_;
  return this;
}


// address=[0x2f17440]
// Decompiled from AdvXMLParser::Exception *__thiscall AdvXMLParser::Exception::~Exception(AdvXMLParser::Exception *this)
 AdvXMLParser::Exception::~Exception(void) {
  
  AdvXMLParser::Exception *result; // eax

  result = this;
  *(_DWORD *)this = &AdvXMLParser::Exception::_vftable_;
  return result;
}


// address=[0x2f1c6b0]
// Decompiled from boost::exception_detail::clone_base *__thiscall AdvXMLParser::Exception::Exception(  boost::exception_detail::clone_base *this,  const struct boost::exception_detail::clone_base *a2)
 AdvXMLParser::Exception::Exception(class AdvXMLParser::Exception const &) {
  
  *(_DWORD *)this = &AdvXMLParser::Exception::_vftable_;
  return this;
}


