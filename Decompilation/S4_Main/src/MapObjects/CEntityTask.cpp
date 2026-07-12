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
    this->m_iTask = _rCloneSource.m_iTask;
    this->m_iEntity = _rCloneSource.m_iEntity;
    this->m_iDir = _rCloneSource.m_iDir;
    this->m_iDuration = _rCloneSource.m_iDuration;
    this->m_iFrameCount = _rCloneSource.m_iFrameCount;
    this->m_iTrigger = _rCloneSource.m_iTrigger;
    this->m_iX = _rCloneSource.m_iX;
    this->m_iY = _rCloneSource.m_iY;
    this->m_iJobNr = _rCloneSource.m_iJobNr;
    this->m_uData9 = _rCloneSource.m_uData9;
    this->m_uData10 = _rCloneSource.m_uData10;
    this->m_bVisible = _rCloneSource.m_bVisible;
    this->m_bForward = _rCloneSource.m_bForward;
}

// address=[0x14d8620]
// Decompiled from int __thiscall CEntityTask::ClassID(CEntityTask *this)
unsigned long CEntityTask::ClassID(void) const {
    return m_iClassID;
}

// address=[0x14dfb60]
// Decompiled from CEntityTask *__thiscall CEntityTask::CEntityTask(  CEntityTask *this,  unsigned __int8 a2,  unsigned __int16 a3,  __int16 a4,  __int16 a5,  char a6,  char a7,  char a8,  bool a9,  bool a10,  unsigned __int8 a11, unsigned __int16 a12,  unsigned __int16 a13,  unsigned __int8 a14)
CEntityTask::CEntityTask(int a2, int a3, int a4, int a5, int a6, int a7, int a8, bool a9, bool a10, int a11, unsigned int a12, unsigned int a13, unsigned int a14) : CPersistence() {
    this->m_iTask = a2;
    this->m_iEntity = a11;
    this->m_iDir = a8;
    this->m_iDuration = a6;
    this->m_iFrameCount = a7;
    this->m_iTrigger = a14;
    this->m_iX = a4;
    this->m_iY = a5;
    this->m_iJobNr = a3;
    this->m_uData9 = a12;
    this->m_uData10 = a13;
    this->m_bVisible = a10;
    this->m_bForward = a9;
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
    a2 >> this->m_iTask; // unsigned char
    static_assert(sizeof(this->m_iTask) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_iEntity; // unsigned char
    static_assert(sizeof(this->m_iEntity) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_iDir; // signed char
    static_assert(sizeof(this->m_iDir) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_iDuration; // signed char
    static_assert(sizeof(this->m_iDuration) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_iFrameCount; // signed char
    static_assert(sizeof(this->m_iFrameCount) == sizeof(signed char), "must match with original binary");
    a2 >> this->m_iTrigger; // unsigned char
    static_assert(sizeof(this->m_iTrigger) == sizeof(unsigned char), "must match with original binary");
    a2 >> this->m_iX; // short
    static_assert(sizeof(this->m_iX) == sizeof(short), "must match with original binary");
    a2 >> this->m_iY; // short
    static_assert(sizeof(this->m_iY) == sizeof(short), "must match with original binary");
    a2 >> this->m_iJobNr; // unsigned short
    static_assert(sizeof(this->m_iJobNr) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_uData9; // unsigned short
    static_assert(sizeof(this->m_uData9) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_uData10; // unsigned short
    static_assert(sizeof(this->m_uData10) == sizeof(unsigned short), "must match with original binary");
    a2 >> this->m_bVisible; // bool
    static_assert(sizeof(this->m_bVisible) == sizeof(bool), "must match with original binary");
    a2 >> this->m_bForward; // bool
    static_assert(sizeof(this->m_bForward) == sizeof(bool), "must match with original binary");
}

// address=[0x154c440]
// Decompiled from void __thiscall CEntityTask::Store(CEntityTask *this, struct std::ostream *a1)
void CEntityTask::Store(std::ostream &a1) {
    CPersistence::Store(a1);
    int fileFormatVersion = 1;
    a1 << fileFormatVersion;

    a1 << this->m_iTask;
    static_assert(sizeof(this->m_iTask) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_iEntity;
    static_assert(sizeof(this->m_iEntity) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_iDir;
    static_assert(sizeof(this->m_iDir) == sizeof(signed char), "must match with original binary");
    a1 << this->m_iDuration;
    static_assert(sizeof(this->m_iDuration) == sizeof(signed char), "must match with original binary");
    a1 << this->m_iFrameCount;
    static_assert(sizeof(this->m_iFrameCount) == sizeof(signed char), "must match with original binary");
    a1 << this->m_iTrigger;
    static_assert(sizeof(this->m_iTrigger) == sizeof(unsigned char), "must match with original binary");
    a1 << this->m_iX;
    static_assert(sizeof(this->m_iX) == sizeof(short), "must match with original binary");
    a1 << this->m_iY;
    static_assert(sizeof(this->m_iY) == sizeof(short), "must match with original binary");
    a1 << this->m_iJobNr;
    static_assert(sizeof(this->m_iJobNr) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_uData9;
    static_assert(sizeof(this->m_uData9) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_uData10;
    static_assert(sizeof(this->m_uData10) == sizeof(unsigned short), "must match with original binary");
    a1 << this->m_bVisible;
    static_assert(sizeof(this->m_bVisible) == sizeof(bool), "must match with original binary");
    a1 << this->m_bForward;
    static_assert(sizeof(this->m_bForward) == sizeof(bool), "must match with original binary");
}

// address=[0x154ecd0]
// Decompiled from int __thiscall CEntityTask::CEntityTask(int this, struct boost::exception_detail::clone_base *a2)
CEntityTask::CEntityTask(CEntityTask &&a2) : CPersistence(a2) {
    this->m_iTask = a2.m_iTask;
    this->m_iEntity = a2.m_iEntity;
    this->m_iDir = a2.m_iDir;
    this->m_iDuration = a2.m_iDuration;
    this->m_iFrameCount = a2.m_iFrameCount;
    this->m_iTrigger = a2.m_iTrigger;
    this->m_iX = a2.m_iX;
    this->m_iY = a2.m_iY;
    this->m_iJobNr = a2.m_iJobNr;
    this->m_uData9 = a2.m_uData9;
    this->m_uData10 = a2.m_uData10;
    this->m_bVisible = a2.m_bVisible;
    this->m_bForward = a2.m_bForward;
}

// address=[0x1568830]
// Decompiled from struct CEntityTask *__cdecl CEntityTask::Load(struct std::istream *a1)
CEntityTask *__cdecl CEntityTask::Load(std::istream &a1) {
    return dynamic_cast<CEntityTask *>(CPersistence::New(a1));
}

// address=[0x3d8bb24]
// [Decompilation failed for static unsigned long CEntityTask::m_iClassID]
