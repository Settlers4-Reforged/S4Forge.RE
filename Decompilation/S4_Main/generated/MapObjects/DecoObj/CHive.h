#ifndef CHIVE_H
#define CHIVE_H

#include "defines.h"

class CHive : public IDecoObject {
public:
    // address=[0x15488d0]
     CHive(int _iX, int _iY, int _iDecoObjectType, int _iId, int _iPhases);

    // address=[0x1548a60]
     CHive(class CHive const & a2, int a3, int a4, int a5);

    // address=[0x1548b50]
    virtual  ~CHive(void);

    // address=[0x1548b70]
    virtual void  LogicUpdate(void);

    // address=[0x1548eb0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1548f50]
    virtual void  Decrease(int a2);

    // address=[0x1549060]
    virtual int  Increase(int a2);

    // address=[0x1549080]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x15490a0]
    static void __cdecl operator delete(void * a1);

    // address=[0x15490e0]
    bool  IsFlowerInSurrounding(void);

    // address=[0x15491c0]
     CHive(std::istream & a2);

    // address=[0x15492d0]
    virtual void  Store(std::ostream & a1);

    // address=[0x1549670]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bb10]
    static unsigned long m_iClassID;

    // Type information members
public:
    bool m_uU1;
    BYTE m_iPhases;
    BYTE m_uCycleFrames;
    BYTE m_iGoodType;
    int m_uU5;
    int m_uU6;

};


#endif // CHIVE_H
