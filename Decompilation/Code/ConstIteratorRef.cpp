#include "ConstIteratorRef.h"

// Definitions for class ConstIteratorRef

// address=[0x14f35c0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Node::ConstIteratorRef::ConstIteratorRef(
        _DWORD *this,
        int a2,
        char a3,
        int a4,
        int a5)

 AdvXMLParser::Node::ConstIteratorRef::ConstIteratorRef(class std::vector<class AdvXMLParser::Node *,class std::allocator<class AdvXMLParser::Node *> > const &,class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > >) {
  
  *this = a2;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>((struct std::_Iterator_base12 *)&a3);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(&a3);
  return this;
}


// address=[0x14f37a0]
// Decompiled from void __thiscall AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef(CDaoIndexFieldInfo *this)

 AdvXMLParser::Node::ConstIteratorRef::~ConstIteratorRef(void) {
  
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>((char *)this + 4);
}


