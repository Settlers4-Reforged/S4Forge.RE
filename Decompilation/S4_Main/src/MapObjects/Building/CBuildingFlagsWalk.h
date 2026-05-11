#ifndef CBUILDINGFLAGSWALK_H
#define CBUILDINGFLAGSWALK_H

#include "defines.h"

class CBuildingFlagsWalk {
public:
    // address=[0x14eaf90]
    CBuildingFlagsWalk(int a2, int a3, int a4, int a5, class std::vector<unsigned int, class std::allocator<unsigned int>> const &a6);

    // address=[0x14eb380]
    int CurrentX(void) const;

    // address=[0x14eb3a0]
    int CurrentY(void) const;

    // address=[0x14eb430]
    void Init(void);

    // address=[0x14eb5b0]
    bool NextPosition(void);

    // Type information members
public:
    std::vector<unsigned int> const &m_v0;

    DWORD m_iU0;
    DWORD m_iU1;
    DWORD m_pFirst;
    DWORD m_iSteps;
    int   m_iCurrentX;
    int   m_iCurrentY;
};


#endif // CBUILDINGFLAGSWALK_H
