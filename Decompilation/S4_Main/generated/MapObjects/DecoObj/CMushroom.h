#ifndef CMUSHROOM_H
#define CMUSHROOM_H

class CMushroom : public IDecoObject {
public:
    // address=[0x1549690]
     CMushroom(int,int,int,int,int);

    // address=[0x15497e0]
     CMushroom(class CMushroom const &,int,int,int);

    // address=[0x15498d0]
    virtual  ~CMushroom(void);

    // address=[0x15498f0]
    virtual void  LogicUpdate(void);

    // address=[0x1549a60]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1549b00]
    virtual void  Decrease(int);

    // address=[0x1549be0]
    virtual int  Increase(int);

    // address=[0x1549c00]
    static void * __cdecl operator new(unsigned int);

    // address=[0x1549c20]
    static void __cdecl operator delete(void *);

    // address=[0x1549c60]
     CMushroom(std::istream &);

    // address=[0x1549d60]
    virtual void  Store(std::ostream &);

    // address=[0x154a020]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bb14]
    static unsigned long m_iClassID;

};


#endif // CMUSHROOM_H
