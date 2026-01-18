#include "BB_SIV_ChunkHeader.h"

// Definitions for class BB_SIV_ChunkHeader

// address=[0x2fd2960]
// Decompiled from BB_SIV_ChunkHeader *__thiscall BB_SIV_ChunkHeader::BB_SIV_ChunkHeader(BB_SIV_ChunkHeader *this)
 BB_SIV_ChunkHeader::BB_SIV_ChunkHeader(void) {
  
  memset(this, 0, 0x14u);
  return this;
}


// address=[0x2fd2980]
// Decompiled from bool __thiscall BB_SIV_ChunkHeader::Load(void *this, FILE *Stream)
bool  BB_SIV_ChunkHeader::Load(struct _iobuf * Stream) {
  
  return j__fread(this, 0x14u, 1u, Stream) == 1;
}


// address=[0x2fd29c0]
// Decompiled from bool __thiscall BB_SIV_ChunkHeader::Save(const void *this, FILE *Stream)
bool  BB_SIV_ChunkHeader::Save(struct _iobuf * Stream) {
  
  return j__fwrite(this, 0x14u, 1u, Stream) == 1;
}


