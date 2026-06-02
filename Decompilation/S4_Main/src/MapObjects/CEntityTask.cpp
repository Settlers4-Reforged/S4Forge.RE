#include "CEntityTask.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include <iostream>

// Definitions for class CEntityTask

// address=[0x14007c0]
// Decompiled from CEntityTask *__cdecl CEntityTask::New(int a1)
CPersistence *__cdecl CEntityTask::New(std::istream &a1) {
    return new CEntityTask(a1);
}

// address=[0x14d7e80]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, CEntityTask *cloneSource)
CEntityTask::CEntityTask(CEntityTask const &_rCloneSource) : CPersistence() {
    this->m_uData0 = _rCloneSource.m_uData0;
    this->m_uData1 = _rCloneSource.m_uData1;
    this->m_iData2 = _rCloneSource.m_iData2;
    this->m_iData3 = _rCloneSource.m_iData3;
    this->m_iData4 = _rCloneSource.m_iData4;
    this->m_uData5 = _rCloneSource.m_uData5;
    this->m_iData6 = _rCloneSource.m_iData6;
    this->m_iData7 = _rCloneSource.m_iData7;
    this->m_uData8 = _rCloneSource.m_uData8;
    this->m_uData9 = _rCloneSource.m_uData9;
    this->m_uData10 = _rCloneSource.m_uData10;
    this->m_bData11 = _rCloneSource.m_bData11;
    this->m_bData12 = _rCloneSource.m_bData12;
}

// address=[0x14d8620]
// Decompiled from int __thiscall CEntityTask::ClassID(CEntityTask *this)
unsigned long CEntityTask::ClassID(void) const {
    return m_iClassID;
}

// address=[0x14dfb60]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(  CEntityTask *this,  unsigned __int8 a2,  unsigned __int16 a3,  __int16 a4,  __int16 a5,  char a6,  char a7,  char a8,  bool a9,  bool a10,  unsigned __int8 a11, unsigned __int16 a12,  unsigned __int16 a13,  unsigned __int8 a14)
CEntityTask::CEntityTask(int a2, int a3, int a4, int a5, int a6, int a7, int a8, bool a9, bool a10, int a11, unsigned int a12, unsigned int a13, unsigned int a14) : CPersistence() {
    this->m_uData0 = a2;
    this->m_uData1 = a11;
    this->m_iData2 = a8;
    this->m_iData3 = a6;
    this->m_iData4 = a7;
    this->m_uData5 = a14;
    this->m_iData6 = a4;
    this->m_iData7 = a5;
    this->m_uData8 = a3;
    this->m_uData9 = a12;
    this->m_uData10 = a13;
    this->m_bData11 = a10;
    this->m_bData12 = a9;
}

// address=[0x154c2d0]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(CEntityTask *this, int a2)
CEntityTask::CEntityTask(std::istream &a2) : CPersistence() {
    unsigned __int8 fileFormatVersion; // [esp+0h] [ebp-8h] BYREF
    a2 >> fileFormatVersion;
    if(fileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityTask");
        throw CS4InvalidMapException();
    }
    a2 >> this->m_uData0; // unsigned char
    static_assert(sizeof(this->m_uData0) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_uData1; // unsigned char
    static_assert(sizeof(this->m_uData1) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_iData2; // signed char
    static_assert(sizeof(this->m_iData2) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_iData3; // signed char
    static_assert(sizeof(this->m_iData3) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_iData4; // signed char
    static_assert(sizeof(this->m_iData4) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_uData5; // unsigned char
    static_assert(sizeof(this->m_uData5) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_iData6; // short
    static_assert(sizeof(this->m_iData6) == sizeof(short), "must match with original binary");
    a2 >> this->m_iData7; // short
    static_assert(sizeof(this->m_iData7) == sizeof(short), "must match with original binary");
    a2 >> this->m_uData8; // unsigned short
    static_assert(sizeof(this->m_uData8) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_uData9; // unsigned short
    static_assert(sizeof(this->m_uData9) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_uData10; // unsigned short
    static_assert(sizeof(this->m_uData10) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_bData11; // bool
    static_assert(sizeof(this->m_bData11) == sizeof(bool), "must match with original binary");
    a2 >> this->m_bData12; // bool
    static_assert(sizeof(this->m_bData12) == sizeof(bool), "must match with original binary");
}

// address=[0x154c440]
// Decompiled from void __thiscall CEntityTask::Store(CEntityTask *this, struct std::ostream *a1)
void CEntityTask::Store(std::ostream &a1) {
    CPersistence::Store(a1);
    int fileFormatVersion = 1;
    a1 << fileFormatVersion;

    a1 << this->m_uData0;
    static_assert(sizeof(this->m_uData0) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_uData1;
    static_assert(sizeof(this->m_uData1) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_iData2;
    static_assert(sizeof(this->m_iData2) == sizeof(signed char), "must match with original binary");
    a1 << this->m_iData3;
    static_assert(sizeof(this->m_iData3) == sizeof(signed char), "must match with original binary");
    a1 << this->m_iData4;
    static_assert(sizeof(this->m_iData4) == sizeof(signed char), "must match with original binary");
    a1 << this->m_uData5;
    static_assert(sizeof(this->m_uData5) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_iData6;
    static_assert(sizeof(this->m_iData6) == sizeof(short), "must match with original binary");
    a1 << this->m_iData7;
    static_assert(sizeof(this->m_iData7) == sizeof(short), "must match with original binary");
    a1 << this->m_uData8;
    static_assert(sizeof(this->m_uData8) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_uData9;
    static_assert(sizeof(this->m_uData9) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_uData10;
    static_assert(sizeof(this->m_uData10) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_bData11;
    static_assert(sizeof(this->m_bData11) == sizeof(bool), "must match with original binary");
    a1 << this->m_bData12;
    static_assert(sizeof(this->m_bData12) == sizeof(bool), "must match with original binary");
}

// address=[0x154ecd0]
// Decompiled from int __thiscall CEntityTask::CEntityTask(int this, struct boost::exception_detail::clone_base *a2)
CEntityTask::CEntityTask(CEntityTask &&a2) : CPersistence(a2) {
    this->m_uData0 = a2.m_uData0;
    this->m_uData1 = a2.m_uData1;
    this->m_iData2 = a2.m_iData2;
    this->m_iData3 = a2.m_iData3;
    this->m_iData4 = a2.m_iData4;
    this->m_uData5 = a2.m_uData5;
    this->m_iData6 = a2.m_iData6;
    this->m_iData7 = a2.m_iData7;
    this->m_uData8 = a2.m_uData8;
    this->m_uData9 = a2.m_uData9;
    this->m_uData10 = a2.m_uData10;
    this->m_bData11 = a2.m_bData11;
    this->m_bData12 = a2.m_bData12;
}

// address=[0x1568830]
// Decompiled from struct CEntityTask *__cdecl CEntityTask::Load(struct std::istream *a1)
CEntityTask *__cdecl CEntityTask::Load(std::istream &a1) {
    return dynamic_cast<CEntityTask *>(CPersistence::New(a1));
}

// address=[0x3d8bb24]
// [Decompilation failed for static unsigned long CEntityTask::m_iClassID]
