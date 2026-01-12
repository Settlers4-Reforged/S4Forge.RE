#ifndef _TNODE_H
#define _TNODE_H

namespace  {

class TNode {
public:
    // address=[0x14600e0]
     TSparseMap<unsigned char>TNode(void);

    // address=[0x1460180]
    static void * __cdecl TSparseMap<unsigned char>operator new(unsigned int);

    // address=[0x14601a0]
    static void __cdecl TSparseMap<unsigned char>operator delete(void *);

private:
    // address=[0x1460c10]
    static class TheAllocator<class TSparseMap<unsigned char>::TNode> & __cdecl TSparseMap<unsigned char>_allocator(void);

};

} // namespace 

#endif // _TNODE_H
