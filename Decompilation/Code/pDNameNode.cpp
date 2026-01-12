#include "pDNameNode.h"

// Definitions for class pDNameNode

// address=[0x3081300]
// Decompiled from pDNameNode *__thiscall pDNameNode::pDNameNode(pDNameNode *this, struct DName *a2)

 pDNameNode::pDNameNode(class DName *) {
  
  struct DName *v3; // [esp+0h] [ebp-8h]

  DNameNode::DNameNode(this);
  *(_DWORD *)this = &pDNameNode::_vftable_;
  if ( a2 && (DName::status(a2) == 2 || DName::status(a2) == 3) )
    v3 = 0;
  else
    v3 = a2;
  *((_DWORD *)this + 1) = v3;
  return this;
}


// address=[0x3088060]
// Decompiled from char __thiscall pDNameNode::getLastChar(DName **this)

char  pDNameNode::getLastChar(void)const {
  
  if ( this[1] )
    return DName::getLastChar(this[1]);
  else
    return 0;
}


// address=[0x308a660]
// Decompiled from char *__thiscall pDNameNode::getString(DName **this, char *a2, char *a3)

char *  pDNameNode::getString(char *,char *)const {
  
  if ( this[1] )
    return DName::getString(this[1], a2, a3);
  else
    return a2;
}


// address=[0x308cfb0]
// Decompiled from int __thiscall pDNameNode::length(DName **this)

int  pDNameNode::length(void)const {
  
  if ( this[1] )
    return DName::length(this[1]);
  else
    return 0;
}


