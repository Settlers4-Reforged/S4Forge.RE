#ifndef CROMANCATAPULT_H
#define CROMANCATAPULT_H

class CRomanCatapult : public CCatapult {
public:
    // address=[0x14019e0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x153eb50]
    static void * __cdecl operator new(unsigned int);

    // address=[0x153eb70]
    static void __cdecl operator delete(void *);

    // address=[0x153ebb0]
     CRomanCatapult(std::istream &);

    // address=[0x153ec70]
    virtual void  Store(std::ostream &);

    // address=[0x153fac0]
    virtual  ~CRomanCatapult(void);

    // address=[0x153fd40]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8b838]
    static unsigned long m_iClassID;

protected:
    // address=[0x153ecb0]
     CRomanCatapult(int,int,int,int,int,int,bool);

};


#endif // CROMANCATAPULT_H
