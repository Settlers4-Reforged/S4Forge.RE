#ifndef CTROJANCATAPULT_H
#define CTROJANCATAPULT_H

class CTrojanCatapult : public CCatapult {
public:
    // address=[0x1402660]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x153f150]
    static void * __cdecl operator new(unsigned int);

    // address=[0x153f170]
    static void __cdecl operator delete(void *);

    // address=[0x153f1b0]
     CTrojanCatapult(std::istream &);

    // address=[0x153f270]
    virtual void  Store(std::ostream &);

    // address=[0x153fae0]
    virtual  ~CTrojanCatapult(void);

    // address=[0x153fd60]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8b878]
    static unsigned long m_iClassID;

protected:
    // address=[0x153f2b0]
     CTrojanCatapult(int,int,int,int,int,int,bool);

};


#endif // CTROJANCATAPULT_H
