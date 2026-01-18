#ifndef CSHADOWHERB_H
#define CSHADOWHERB_H

#include "defines.h"

class CShadowHerb : public IDecoObject {
public:
    // address=[0x1401c60]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x154abc0]
     CShadowHerb(int a2, int a3, int a4, int a5, int a6);

    // address=[0x154ace0]
    virtual void  LogicUpdate(void);

    // address=[0x154ae90]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x154af50]
    virtual void  Decrease(int a2);

    // address=[0x154af60]
    virtual int  Increase(int a2);

    // address=[0x154af80]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x154afa0]
    static void __cdecl operator delete(void * a1);

    // address=[0x154afe0]
    virtual int  ConvertToDarkOrGreen(bool a2);

    // address=[0x154b000]
     CShadowHerb(std::istream & a2);

    // address=[0x154b100]
    virtual void  Store(std::ostream & a2);

    // address=[0x154b2f0]
    virtual  ~CShadowHerb(void);

    // address=[0x154b3b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bb1c]
    static unsigned long m_iClassID;

};


#endif // CSHADOWHERB_H
