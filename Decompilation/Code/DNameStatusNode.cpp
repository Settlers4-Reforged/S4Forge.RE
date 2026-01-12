#include "DNameStatusNode.h"

// Definitions for class DNameStatusNode

// address=[0x3088000]
// Decompiled from char __thiscall DNameStatusNode::getLastChar(DNameStatusNode *this)

char  DNameStatusNode::getLastChar(void)const {
  
  if ( *((_DWORD *)this + 1) == 1 )
    return asc_3AF6CA8[3];
  else
    return 0;
}


// address=[0x308a5e0]
// Decompiled from char *__thiscall DNameStatusNode::getString(DNameStatusNode *this, char *a2, char *a3)

char *  DNameStatusNode::getString(char *,char *)const {
  
  if ( *((_DWORD *)this + 1) == 1 )
    return (char *)getStringHelper(a2, (int)a3, " ?? ", 4u);
  else
    return a2;
}


// address=[0x308cf70]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall DNameStatusNode::length(DNameStatusNode *this)

int  DNameStatusNode::length(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x308d0a0]
// Decompiled from char *__cdecl DNameStatusNode::make(unsigned int a1)

static class DNameStatusNode * __cdecl DNameStatusNode::make(enum DNameStatus) {
  
  if ( (DNameStatusNode::make_::_2_::_local_static_guard_ & 1) == 0 )
  {
    DNameStatusNode::make_::_2_::_local_static_guard_ |= 1u;
    DNameStatusNode::DNameStatusNode(&DNameStatusNode::make_::_2_::nodes, 0);
    DNameStatusNode::DNameStatusNode(&unk_4731F24, 1);
    DNameStatusNode::DNameStatusNode(&unk_4731F30, 2);
    DNameStatusNode::DNameStatusNode(&unk_4731F3C, 3);
  }
  if ( a1 >= 4 )
    return (char *)&DNameStatusNode::make_::_2_::nodes + 36;
  else
    return (char *)&DNameStatusNode::make_::_2_::nodes + 12 * a1;
}


// address=[0x3081170]
// Decompiled from DNameNode *__thiscall DNameStatusNode::DNameStatusNode(DNameNode *this, int a2)

 DNameStatusNode::DNameStatusNode(enum DNameStatus) {
  
  int v3; // [esp+0h] [ebp-8h]

  DNameNode::DNameNode(this);
  *(_DWORD *)this = &DNameStatusNode::_vftable_;
  *((_DWORD *)this + 1) = a2;
  if ( *((_DWORD *)this + 1) == 1 )
    v3 = 4;
  else
    v3 = 0;
  *((_DWORD *)this + 2) = v3;
  return this;
}


