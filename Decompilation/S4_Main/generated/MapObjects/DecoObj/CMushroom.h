#ifndef CMUSHROOM_H
#define CMUSHROOM_H

#include "defines.h"

class CMushroom : public IDecoObject {
public:
    // address=[0x1549690]
     CMushroom(int a2, int a3, int a4, int a5, int a6);

    // address=[0x15497e0]
     CMushroom(class CMushroom const & a2, int a3, int a4, int a5);

    // address=[0x15498d0]
    virtual  ~CMushroom(void);

    // address=[0x15498f0]
    virtual void  LogicUpdate(void);

    // address=[0x1549a60]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1549b00]
    virtual void  Decrease(int a2);

    // address=[0x1549be0]
    virtual int  Increase(int a2);

    // address=[0x1549c00]
    static void * __cdecl operator new(unsigned int a1);

    // address=[0x1549c20]
    static void __cdecl operator delete(void * a1);

    // address=[0x1549c60]
     CMushroom(std::istream & a2);

    // address=[0x1549d60]
    virtual void  Store(std::ostream & a2);

    // address=[0x154a020]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bb14]
    static unsigned long m_iClassID;

};


#endif // CMUSHROOM_H
