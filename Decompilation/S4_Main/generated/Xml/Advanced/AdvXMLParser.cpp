#include "AdvXMLParser.h"

// Definitions for class AdvXMLParser

// address=[0x14f33d0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::ConstIterator<AdvXMLParser::Element>::ConstIterator<AdvXMLParser::Element>(  _DWORD *this,  _DWORD *a2)
 AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::ConstIterator<class AdvXMLParser::Element>(struct AdvXMLParser::Node::ConstIteratorRef const & a2) {
  
  *this = *a2;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>((struct std::_Iterator_base12 *)(a2 + 1));
  AdvXMLParser::ConstIterator<AdvXMLParser::Element>::FirstValid();
  return this;
}


// address=[0x14f36f0]
// Decompiled from void __thiscall AdvXMLParser::ConstIterator<AdvXMLParser::Element>::~ConstIterator<AdvXMLParser::Element>(  CDaoIndexFieldInfo *this)
 AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::~ConstIterator<class AdvXMLParser::Element>(void) {
  
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(
    (char *)this + 4,
    this);
}


// address=[0x14f3bb0]
// Decompiled from bool __thiscall AdvXMLParser::ConstIterator<AdvXMLParser::Element>::operator<(_DWORD *this, int a2)
bool  AdvXMLParser::ConstIterator<class AdvXMLParser::Element>::operator<(struct AdvXMLParser::ConstIterator<class AdvXMLParser::Element> const & a2) {
  
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(
           this + 1,
           (std::_Iterator_base12 *)(a2 + 4));
}


