#ifndef ALLOCMEM_H
#define ALLOCMEM_H

#include "defines.h"

//NOTE: this implementation seems to differ _slightly_

class MemoryAllocator {
public:
    ~MemoryAllocator();

    MemoryAllocator(uint unit_size, uint block_size = 16);

    MemoryAllocator(uint unit_size, uint block_size, bool debug);

    void *allocate();

    void deallocate(void *);

    bool is_debug() const { return _debug; }

private:
    struct Free {
        Free *next;
    };

    uint   _requested_size;    // memory units requested for allocation
    uint   _allocated_size;    // memory units to be allocated
    uint   _block_size;        // The number of units in blocks
    void **_allocated_blocks;    // Array of pointers to blocks
    uint   _num_allocated_blocks;  // Number of allocated blocks
    Free * _free;                 // Linked list of free units
    bool   _debug;

    void more();// throw(char *);

    void *debug_check(void *&);// throw(char *);

    void *debug_correct(void *&);
};


inline void *MemoryAllocator::allocate() {
    if(!_free)
        more();
    void *storage = _free;
    _free = _free->next;
    return _debug ? debug_correct(storage) : storage;
}

inline void MemoryAllocator::deallocate(void *storage) {
    if(_debug)
        debug_check(storage);
    Free *new_free = (Free *) storage;
    new_free->next = _free;
    _free = new_free;
}

#endif // ALLOCMEM_H
