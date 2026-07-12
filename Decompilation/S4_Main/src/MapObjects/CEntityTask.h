#ifndef CENTITYTASK_H
#define CENTITYTASK_H

#include "LoadSave/CPersistence.h"
#include "defines.h"

class CEntityTask : public CPersistence {
  public:
    // address=[0x14007c0]
    static CPersistence *__cdecl New(std::istream &a1);

    // address=[0x14d7e80]
    CEntityTask(CEntityTask const &_rCloneSource);

    // address=[0x14d8620]
    virtual unsigned long ClassID(void) const;

    // address=[0x14dfb60]
    CEntityTask(int _iTask, int _iJobNr, int _iX, int _iY, int _iDuration, int _iFrameCount, int _iDir, bool _bForward, bool _bVisible, int _iEntity, unsigned int a12, unsigned int a13, unsigned int _iTrigger);

    // address=[0x154c2d0]
    CEntityTask(std::istream &a2);

    // address=[0x154c440]
    virtual void Store(std::ostream &a1);

    // address=[0x154ecd0]
    CEntityTask(CEntityTask &&a2);

    // address=[0x1568830]
    static CEntityTask *__cdecl Load(std::istream &a1);

    // address=[0x3d8bb24]
    static unsigned long m_iClassID;

    // Type information members
  public:
    __int8 m_iTask;
    __int8 m_iEntity;
    char m_iDir;
    char m_iDuration;
    char m_iFrameCount;
    unsigned __int8 m_iTrigger;
    __int16 m_iX;
    __int16 m_iY;
    __int16 m_iJobNr;
    unsigned __int16 m_uData9;
    unsigned __int16 m_uData10;
    bool m_bVisible;
    bool m_bForward;
};

#endif // CENTITYTASK_H
