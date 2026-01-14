#include "all_headers.h"

// Definitions for class pairNode

// address=[0x3081380]
// Decompiled from pairNode *__thiscall pairNode::pairNode(pairNode *this, struct DNameNode *a2, struct DNameNode *a3)
 pairNode::pairNode(class DNameNode *,class DNameNode *) {
  
  DNameNode::DNameNode(this);
  *(_DWORD *)this = &pairNode::_vftable_;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = -1;
  return this;
}


// address=[0x30880a0]
// Decompiled from char __thiscall pairNode::getLastChar(pairNode *this)
char  pairNode::getLastChar(void)const {
  
  char v3; // [esp+13h] [ebp-1h]

  v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 4))(*((_DWORD *)this + 2));
  if ( !v3 )
    return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 4))(*((_DWORD *)this + 1));
  return v3;
}


// address=[0x308a6b0]
// Decompiled from char *__thiscall pairNode::getString(pairNode *this, char *a2, char *a3)
char *  pairNode::getString(char *,char *)const {
  
  unsigned int v4; // [esp+Ch] [ebp-8h]

  v4 = (*(int (__thiscall **)(_DWORD, char *, char *))(**((_DWORD **)this + 1) + 8))(*((_DWORD *)this + 1), a2, a3);
  if ( v4 >= (unsigned int)a3 )
    return (char *)v4;
  else
    return (char *)(*(int (__thiscall **)(_DWORD, unsigned int, char *))(**((_DWORD **)this + 2) + 8))(
                     *((_DWORD *)this + 2),
                     v4,
                     a3);
}


// address=[0x308cff0]
// Decompiled from int __thiscall pairNode::length(pairNode *this)
int  pairNode::length(void)const {
  
  int v1; // esi

  if ( *((int *)this + 3) >= 0 )
    return *((_DWORD *)this + 3);
  v1 = (***((int (__thiscall ****)(_DWORD))this + 1))(*((_DWORD *)this + 1));
  *((_DWORD *)this + 3) = (***((int (__thiscall ****)(_DWORD))this + 2))(*((_DWORD *)this + 2)) + v1;
  return *((_DWORD *)this + 3);
}


