#include "CRandom16Ex.h"

// Definitions for class CRandom16Ex

// address=[0x13613e0]
// Decompiled from CRandom16Ex *__thiscall CRandom16Ex::CRandom16Ex(CRandom16Ex *this, int a2)
CRandom16Ex::CRandom16Ex(unsigned int a2) : CRandom16(a2) {
    this->m_uIteration = 0;
}


// address=[0x1361420]
// Decompiled from void __thiscall CRandom16Ex::Init(CRandom16Ex *this, int a2, int a3)
void CRandom16Ex::Init(unsigned int a2, unsigned int a3) {
    this->m_uSeed = a2;
    this->m_uIteration = a3;
}


