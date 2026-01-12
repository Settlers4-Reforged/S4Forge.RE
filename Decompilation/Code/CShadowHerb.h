#ifndef CSHADOWHERB_H
#define CSHADOWHERB_H

class CShadowHerb : public IDecoObject {
public:
    // address=[0x1401c60]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x154abc0]
     CShadowHerb(int,int,int,int,int);

    // address=[0x154ace0]
    virtual void  LogicUpdate(void);

    // address=[0x154ae90]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x154af50]
    virtual void  Decrease(int);

    // address=[0x154af60]
    virtual int  Increase(int);

    // address=[0x154af80]
    static void * __cdecl operator new(unsigned int);

    // address=[0x154afa0]
    static void __cdecl operator delete(void *);

    // address=[0x154afe0]
    virtual int  ConvertToDarkOrGreen(bool);

    // address=[0x154b000]
     CShadowHerb(std::istream &);

    // address=[0x154b100]
    virtual void  Store(std::ostream &);

    // address=[0x154b2f0]
    virtual  ~CShadowHerb(void);

    // address=[0x154b3b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bb1c]
    static unsigned long m_iClassID;

};


#endif // CSHADOWHERB_H
