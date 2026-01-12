#ifndef CDECOOBJECT_H
#define CDECOOBJECT_H

class CDecoObject : public IDecoObject {
public:
    // address=[0x1400360]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1541b70]
     CDecoObject(int,int,int,int,int,int);

    // address=[0x1541c80]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1541e20]
    static void * __cdecl operator new(unsigned int);

    // address=[0x1541e40]
    static void __cdecl operator delete(void *);

    // address=[0x1541e80]
     CDecoObject(std::istream &);

    // address=[0x1541f80]
    virtual void  Store(std::ostream &);

    // address=[0x15422d0]
    virtual  ~CDecoObject(void);

    // address=[0x15423c0]
    virtual int  Amount(void)const;

    // address=[0x15423e0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1542420]
    virtual void  Decrease(int);

    // address=[0x1542460]
    virtual int  Increase(int);

    // address=[0x1542480]
    virtual void  LogicUpdate(void);

    // address=[0x3d8bad0]
    static unsigned long m_iClassID;

};


#endif // CDECOOBJECT_H
