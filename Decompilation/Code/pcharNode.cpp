#include "pcharNode.h"

// Definitions for class pcharNode

// address=[0x30813d0]
// Decompiled from pcharNode *__thiscall pcharNode::pcharNode(pcharNode *this, char *a2, unsigned int a3)

 pcharNode::pcharNode(char const *,int) {
  
  DNameNode::DNameNode(this);
  *(_DWORD *)this = &pcharNode::_vftable_;
  if ( a3 && a2 )
  {
    *((_DWORD *)this + 1) = operator new(a3, (struct _HeapManager *)&unk_4731E94, 0);
    *((_DWORD *)this + 2) = a3;
    if ( *((_DWORD *)this + 1) )
      und_memcpy(*((char **)this + 1), a2, a3);
    else
      *((_DWORD *)this + 2) = 0;
  }
  else
  {
    *((_DWORD *)this + 1) = 0;
    *((_DWORD *)this + 2) = 0;
  }
  return this;
}


// address=[0x3088120]
// Decompiled from char __thiscall pcharNode::getLastChar(pcharNode *this)

char  pcharNode::getLastChar(void)const {
  
  if ( *((_DWORD *)this + 2) )
    return *(_BYTE *)(*((_DWORD *)this + 1) + *((_DWORD *)this + 2) - 1);
  else
    return 0;
}


// address=[0x308a750]
// Decompiled from char *__thiscall pcharNode::getString(pcharNode *this, char *a2, char *a3)

char *  pcharNode::getString(char *,char *)const {
  
  return (char *)getStringHelper(a2, (int)a3, *((char **)this + 1), *((_DWORD *)this + 2));
}


// address=[0x308d080]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall pcharNode::length(pcharNode *this)

int  pcharNode::length(void)const {
  
  return *((_DWORD *)this + 2);
}


