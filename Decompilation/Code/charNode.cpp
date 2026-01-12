#include "charNode.h"

// Definitions for class charNode

// address=[0x30812c0]
// Decompiled from charNode *__thiscall charNode::charNode(charNode *this, char a2)

 charNode::charNode(char) {
  
  DNameNode::DNameNode(this);
  *(_DWORD *)this = &charNode::_vftable_;
  *((_BYTE *)this + 4) = a2;
  return this;
}


// address=[0x3088040]
// Decompiled from // Microsoft VisualC 14/net runtime
char __thiscall charNode::getLastChar(charNode *this)

char  charNode::getLastChar(void)const {
  
  return *((_BYTE *)this + 4);
}


// address=[0x308a620]
// Decompiled from char *__thiscall charNode::getString(charNode *this, char *a2, char *a3)

char *  charNode::getString(char *,char *)const {
  
  if ( a2 < a3 )
    *a2++ = *((_BYTE *)this + 4);
  return a2;
}


// address=[0x308cf90]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall charNode::length(charNode *this)

int  charNode::length(void)const {
  
  return 1;
}


