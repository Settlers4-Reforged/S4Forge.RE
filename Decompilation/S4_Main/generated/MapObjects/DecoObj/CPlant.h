#ifndef CPLANT_H
#define CPLANT_H

#include "defines.h"

class CPlant : public IDecoObject {
public:
    // address=[0x14016c0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x154a040]
     CPlant(int a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x154a1a0]
     CPlant(class CPlant const & a2, int a3, int a4, int a5);

    // address=[0x154a2a0]
    virtual  ~CPlant(void);

    // address=[0x154a2c0]
    virtual void  LogicUpdate(void);

    // address=[0x154a490]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x154a540]
    virtual void  Take(int a2);

    // address=[0x154a6c0]
    virtual void  Decrease(int a2);

    // address=[0x154a6d0]
    virtual int  Increase(int a2);

    // address=[0x154a6f0]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x154a710]
    static void __cdecl operator delete(void * a1);

    // address=[0x154a750]
     CPlant(std::istream & a2);

    // address=[0x154a860]
    virtual void  Store(std::ostream & a2);

    // address=[0x154ab80]
    virtual unsigned long  ClassID(void)const;

    // address=[0x154aba0]
    virtual int  GetGoodType(void)const;

    // address=[0x3d8bb18]
    static unsigned long m_iClassID;

};


#endif // CPLANT_H
