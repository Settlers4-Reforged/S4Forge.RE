#include "TNode.h"

// Definitions for class TNode

// address=[0x14600e0]
// Decompiled from _DWORD *__thiscall TSparseMap<unsigned char>::TNode::TNode(_DWORD *this)

 TSparseMap<unsigned char>::TNode::TNode(void) {
  
  *this = 0;
  this[1] = 0;
  *((_BYTE *)this + 8) = 0;
  return this;
}


// address=[0x1460180]
// Decompiled from unsigned int __cdecl TSparseMap<unsigned char>::TNode::operator new(int a1)

static void * __cdecl TSparseMap<unsigned char>::TNode::operator new(unsigned int) {
  
  unsigned int *v1; // eax
  unsigned int v3; // [esp-4h] [ebp-4h]

  v1 = (unsigned int *)TSparseMap<unsigned char>::TNode::_allocator(a1);
  return MemoryAllocator::allocate(v1, v3);
}


// address=[0x14601a0]
// Decompiled from // MFC 3.1-14.0 32bit
void __cdecl TSparseMap<unsigned char>::TNode::operator delete(void *a1)

static void __cdecl TSparseMap<unsigned char>::TNode::operator delete(void *) {
  
  MemoryAllocator *v1; // eax
  void *v2; // [esp-4h] [ebp-14h]

  v1 = (MemoryAllocator *)TSparseMap<unsigned char>::TNode::_allocator(a1);
  MemoryAllocator::deallocate(v1, v2);
}


// address=[0x1460c10]
// Decompiled from void *TSparseMap<unsigned char>::TNode::_allocator()

static class TheAllocator<class TSparseMap<unsigned char>::TNode> & __cdecl TSparseMap<unsigned char>::TNode::_allocator(void) {
  
  if ( TSparseMap_unsigned_char_::TNode::_allocator_::_2_::_TSS0 <= *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
                                                                                + _tls_index)
                                                                              + 20296) )
    return &TSparseMap_unsigned_char_::TNode::_allocator_::_2_::m_allocator;
  j___Init_thread_header(&TSparseMap_unsigned_char_::TNode::_allocator_::_2_::_TSS0);
  if ( TSparseMap_unsigned_char_::TNode::_allocator_::_2_::_TSS0 != -1 )
    return &TSparseMap_unsigned_char_::TNode::_allocator_::_2_::m_allocator;
  TheAllocator<TSparseMap<unsigned char>::TNode>::TheAllocator<TSparseMap<unsigned char>::TNode>(16, 0);
  j__atexit(`TSparseMap<unsigned char>::TNode::_allocator'::`2'::`dynamic atexit destructor for 'm_allocator'');
  j___Init_thread_footer(&TSparseMap_unsigned_char_::TNode::_allocator_::_2_::_TSS0);
  return &TSparseMap_unsigned_char_::TNode::_allocator_::_2_::m_allocator;
}


