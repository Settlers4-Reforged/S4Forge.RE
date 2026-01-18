#ifndef CSTONE_H
#define CSTONE_H

#include "defines.h"

class CStone : public IDecoObject {
public:
    // address=[0x14020c0]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x15a2750]
     CStone(int a2, int a3, int a4, int a5, int a6);

    // address=[0x15a2810]
     CStone(class CStone const & a2, int a3, int a4, int a5);

    // address=[0x15a28a0]
    virtual  ~CStone(void);

    // address=[0x15a2910]
    virtual void  LogicUpdate(void);

    // address=[0x15a2920]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x15a2980]
    virtual int  GetGoodType(void)const;

    // address=[0x15a2990]
    virtual void  Take(int a2);

    // address=[0x15a2ad0]
    virtual int  ConvertToDarkOrGreen(bool a2);

    // address=[0x15a2af0]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x15a2b10]
    static void __cdecl operator delete(void * a1);

    // address=[0x15a2b50]
     CStone(std::istream & a2);

    // address=[0x15a2c00]
    virtual void  Store(std::ostream & a2);

    // address=[0x15a2dd0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15a2df0]
    virtual void  Decrease(int a1);

    // address=[0x15a2e00]
    virtual void  Update(void);

    // address=[0x3d8c010]
    static unsigned long m_iClassID;

};


#endif // CSTONE_H
