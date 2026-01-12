#ifndef CTREE_H
#define CTREE_H

class CTree : public IDecoObject {
public:
    // address=[0x14025c0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15a2e10]
     CTree(int,int,int,int,int);

    // address=[0x15a2f50]
     CTree(class CTree const &,int,int,int);

    // address=[0x15a3040]
    virtual void  LogicUpdate(void);

    // address=[0x15a3310]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x15a33e0]
    virtual int  GetGoodType(void)const;

    // address=[0x15a33f0]
    virtual void  Decrease(int);

    // address=[0x15a3500]
    virtual int  Increase(int);

    // address=[0x15a3520]
    virtual void  Take(int);

    // address=[0x15a3540]
    virtual int  ConvertToDarkOrGreen(bool);

    // address=[0x15a35d0]
    static void * __cdecl operator new(unsigned int);

    // address=[0x15a35f0]
    static void __cdecl operator delete(void *);

    // address=[0x15a3630]
     CTree(std::istream &);

    // address=[0x15a3730]
    virtual void  Store(std::ostream &);

    // address=[0x15a3a20]
    virtual  ~CTree(void);

    // address=[0x15a3ab0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8c014]
    static unsigned long m_iClassID;

};


#endif // CTREE_H
