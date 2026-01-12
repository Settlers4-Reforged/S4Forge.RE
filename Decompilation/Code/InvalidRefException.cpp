#include "InvalidRefException.h"

// Definitions for class InvalidRefException

// address=[0x2f17460]
// Decompiled from AdvXMLParser::Exception *__thiscall AdvXMLParser::InvalidRefException::InvalidRefException(
        AdvXMLParser::Exception *this,
        int a2)

 AdvXMLParser::InvalidRefException::InvalidRefException(std::string const &) {
  
  AdvXMLParser::Exception::Exception(this);
  *(_DWORD *)this = &AdvXMLParser::InvalidRefException::_vftable_;
  std::string::string(a2);
  return this;
}


// address=[0x2f1c6d0]
// Decompiled from boost::exception_detail::clone_base *__thiscall AdvXMLParser::InvalidRefException::InvalidRefException(
        boost::exception_detail::clone_base *this,
        struct boost::exception_detail::clone_base *a2)

 AdvXMLParser::InvalidRefException::InvalidRefException(class AdvXMLParser::InvalidRefException const &) {
  
  AdvXMLParser::Exception::Exception(this, a2);
  *(_DWORD *)this = &AdvXMLParser::InvalidRefException::_vftable_;
  std::string::string((char *)a2 + 4);
  return this;
}


// address=[0x2f1cde0]
// Decompiled from void __thiscall AdvXMLParser::InvalidRefException::~InvalidRefException(CMapStringToString::CPair *this)

 AdvXMLParser::InvalidRefException::~InvalidRefException(void) {
  
  std::string::~string((char *)this + 4);
  AdvXMLParser::Exception::~Exception(this);
}


