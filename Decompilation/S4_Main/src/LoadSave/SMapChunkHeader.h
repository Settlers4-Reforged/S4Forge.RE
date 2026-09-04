#ifndef SMAPCHUNKHEADER_H
#define SMAPCHUNKHEADER_H

#include "Defines/Map.h"
#include "defines.h"

struct SMapChunkHeader {
    T_S4_MAP_CHUNK m_iChunkId;
    unsigned __int16 m_iSetup;
    DWORD m_iSize;
    int m_iDecompressedSize;
    int a7;
    int a8;
    int m_iNumberOfPlayers;
};

static_assert(offsetof(SMapChunkHeader, m_iSize) == 0x4, "Offset of m_iSize must match with original.");

bool __cdecl ReadChunk(void *, int, int);

#endif // SMAPCHUNKHEADER_H
