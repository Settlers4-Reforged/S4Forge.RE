#include "all_headers.h"

// Definitions for class std

// address=[0x1548320]
// Decompiled from int TArgv<unsigned int,std::vector<unsigned int>>::~TArgv<unsigned int,std::vector<unsigned int>>()
 TArgv<unsigned int,class std::vector<unsigned int,class std::allocator<unsigned int> > >::~TArgv<unsigned int,class std::vector<unsigned int,class std::allocator<unsigned int> > >(void) {
  
  return std::vector<unsigned int>::~vector<unsigned int>();
}


// address=[0x2d73a20]
// Decompiled from void *__thiscall SIMPL_NS::EalStdAllocator<std::_Container_proxy,1111490559>::EalStdAllocator<std::_Container_proxy,1111490559>(  void *this,  int a2)
 SIMPL_NS::EalStdAllocator<struct std::_Container_proxy,1111490559>::EalStdAllocator<struct std::_Container_proxy,1111490559><struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *> >(class SIMPL_NS::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559> const &) {
  
  return this;
}


// address=[0x2db17c0]
// Decompiled from void *__thiscall SIMPL_NS::EalStdAllocator<std::_Tree_node<std::pair<int const,unsigned __int64>,void *>,1111490559>::EalStdAllocator<std::_Tree_node<std::pair<int const,unsigned __int64>,void *>,1111490559>(  void *this)
 SIMPL_NS::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559>::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559>(void) {
  
  return this;
}


// address=[0x2e03b80]
// Decompiled from _DWORD *__stdcall SIMPL_NS::EalStdAllocator<std::_Container_proxy,1111490559>::construct(void *a1, _DWORD *a2)
void  SIMPL_NS::EalStdAllocator<struct std::_Container_proxy,1111490559>::construct(struct std::_Container_proxy *,struct std::_Container_proxy const &) {
  
  _DWORD *result; // eax
  _DWORD *v3; // [esp+4h] [ebp-8h]

  result = operator new(8u, a1);
  v3 = result;
  if ( !result )
    return result;
  result = (_DWORD *)a2[1];
  *v3 = *a2;
  v3[1] = result;
  return result;
}


// address=[0x2e03c40]
// Decompiled from void __stdcall SIMPL_NS::EalStdAllocator<std::_Tree_node<std::pair<int const,unsigned __int64>,void *>,1111490559>::deallocate(  void *a1,  int a2)
void  SIMPL_NS::EalStdAllocator<struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *>,1111490559>::deallocate(struct std::_Tree_node<struct std::pair<int const ,unsigned __int64>,void *> *,unsigned int) {
  
  if ( a1 )
    SimplFree(a1);
}


// address=[0x2e03c80]
// Decompiled from void __stdcall SIMPL_NS::EalStdAllocator<std::_Container_proxy,1111490559>::deallocate(void *a1, int a2)
void  SIMPL_NS::EalStdAllocator<struct std::_Container_proxy,1111490559>::deallocate(struct std::_Container_proxy *,unsigned int) {
  
  if ( a1 )
    SimplFree(a1);
}


// address=[0x2e05280]
// Decompiled from void __stdcall SIMPL_NS::EalStdAllocator<std::_Container_proxy,1111490559>::destroy(int a1)
void  SIMPL_NS::EalStdAllocator<struct std::_Container_proxy,1111490559>::destroy(struct std::_Container_proxy *) {
  
  ;
}


