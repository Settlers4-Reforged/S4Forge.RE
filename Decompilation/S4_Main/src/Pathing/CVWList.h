#ifndef CVWLIST_H
#define CVWLIST_H

#include "defines.h"

class CVWList {
public:
    struct SVW {
        int m_iV;
        int m_iW;
    };

    // address=[0x1334ec0]
    CVWList(int iX, int iY, int iRadius);

    // address=[0x1335b10]
    SVW const &CVWList::operator[](int a2) const;

    // address=[0x1336840]
    int Size(void) const;

    // address=[0x15de830]
    void CalculateOverlappingSquares(int _iX, int _iY, int _iRadius);

protected:
    // address=[0x15e2cf0]
    void PushEx(int &a2, int a3, int a4);

    // Type information members
public:
    int m_iSize;
    int m_iU;
    SVW m_aVW[27];
};


#endif // CVWLIST_H
