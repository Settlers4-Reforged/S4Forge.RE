#ifndef CAIEVENT_H
#define CAIEVENT_H

#include "defines.h"

class CAIEvent {
public:
    // address=[0x13095e0]
    static int __cdecl Pack(unsigned int _uDataA, unsigned int _uDataB);

    // address=[0x1310220]
    CAIEvent(int _iType, int _iData1, int _iData2, int _iData3);

    // address=[0x13140a0]
    static unsigned int __cdecl UnpackA(int _iDataA);

    // address=[0x13140b0]
    static unsigned int __cdecl UnpackB(int _iDataB);

    // address=[0x1319600]
    int Data1(void) const;

    // address=[0x1319620]
    int Data2(void) const;

    // address=[0x1319640]
    int Data3(void) const;

    // address=[0x1319b30]
    int Type(void) const;

    // Type information members
public:
    int m_iType;
    int m_iData1;
    int m_iData2;
    int m_iData3;
};

#endif // CAIEVENT_H
