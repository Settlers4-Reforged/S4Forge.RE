#include "IS4ChunkObject.h"

// Definitions for class IS4ChunkObject

// address=[0x1310290]
// Decompiled from IS4ChunkObject *__thiscall IS4ChunkObject::IS4ChunkObject(IS4ChunkObject *this)
 IS4ChunkObject::IS4ChunkObject(void) {
  
  this->__vftable = (IS4ChunkObject_vtbl *)IS4ChunkObject::_vftable_;
  return this;
}


// address=[0x14600c0]
// Decompiled from IS4ChunkObject *__thiscall IS4ChunkObject::IS4ChunkObject(  IS4ChunkObject *this,  const struct boost::exception_detail::clone_base *a2)
 IS4ChunkObject::IS4ChunkObject(class IS4ChunkObject const &) {
  
  *(_DWORD *)this = IS4ChunkObject::_vftable_;
  return this;
}


// address=[0x1486c50]
// Decompiled from void *__thiscall IS4ChunkObject::operator=(void *this, int a2)
class IS4ChunkObject &  IS4ChunkObject::operator=(class IS4ChunkObject const &) {
  
  return this;
}


