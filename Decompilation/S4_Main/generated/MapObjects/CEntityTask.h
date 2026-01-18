#ifndef CENTITYTASK_H
#define CENTITYTASK_H

#include "defines.h"

class CEntityTask : public CPersistence {
public:
    // address=[0x14007c0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14d7e80]
     CEntityTask(class CEntityTask const & cloneSource);

    // address=[0x14d8620]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14dfb60]
     CEntityTask(int a2, int a3, int a4, int a5, int a6, int a7, int a8, bool a9, bool a10, int a11, unsigned int a12, unsigned int a13, unsigned int a14);

    // address=[0x154c2d0]
     CEntityTask(std::istream & a2);

    // address=[0x154c440]
    virtual void  Store(std::ostream & a2);

    // address=[0x154ecd0]
     CEntityTask(class CEntityTask && a2);

    // address=[0x1568830]
    static class CEntityTask * __cdecl Load(std::istream & a1);

    // address=[0x3d8bb24]
    static unsigned long m_iClassID;

};


#endif // CENTITYTASK_H
