#ifndef CSAVEDPLAYER_H
#define CSAVEDPLAYER_H

#include "defines.h"

class CSavedPlayer {
public:
    // address=[0x13eb720]
    void  Load(class IS4Chunk & a2);

    // address=[0x13eb7f0]
    void  Save(class IS4Chunk & a2);

    // Type information members
public:
    DWORD m_uType;
    wchar_t m_swName[32];
    DWORD m_uColor;
    DWORD m_uStartX;
    DWORD m_uStartY;
    DWORD m_uTeam;

};


#endif // CSAVEDPLAYER_H
