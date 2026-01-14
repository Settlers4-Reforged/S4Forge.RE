#include "all_headers.h"

// Definitions for class IFSNode

// address=[0x135df30]
// Decompiled from void *__thiscall IFSNode::Adopt(std::_Ref_count_base *this, const struct type_info *a2)
class IFSNode *  IFSNode::Adopt(class IFSNode *) {
  
  return 0;
}


// address=[0x135df50]
// Decompiled from void *__thiscall IFSNode::GetChild(std::_Ref_count_base *this, const struct type_info *a2)
class IFSNode *  IFSNode::GetChild(int) {
  
  return 0;
}


// address=[0x135e0c0]
// Decompiled from void __thiscall IFSNode::Orphan(IFSNode *this, struct IFSNode *a2)
void  IFSNode::Orphan(class IFSNode *) {
  
  ;
}


// address=[0x135cc00]
// Decompiled from IFSNode *__thiscall IFSNode::IFSNode(IFSNode *this)
 IFSNode::IFSNode(void) {
  
  *(_DWORD *)this = IFSNode::_vftable_;
  return this;
}


// address=[0x135d4e0]
// Decompiled from IFSNode *__thiscall IFSNode::~IFSNode(IFSNode *this)
 IFSNode::~IFSNode(void) {
  
  IFSNode *result; // eax

  result = this;
  *(_DWORD *)this = IFSNode::_vftable_;
  return result;
}


