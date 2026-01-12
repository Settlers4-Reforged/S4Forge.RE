#ifndef CVIKINGCATAPULT_H
#define CVIKINGCATAPULT_H

class CVikingCatapult : public CCatapult {
public:
    // address=[0x14027a0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x153eeb0]
    static void * __cdecl operator new(unsigned int);

    // address=[0x153eed0]
    static void __cdecl operator delete(void *);

    // address=[0x153ef10]
     CVikingCatapult(std::istream &);

    // address=[0x153efd0]
    virtual void  Store(std::ostream &);

    // address=[0x153fb00]
    virtual  ~CVikingCatapult(void);

    // address=[0x153fd80]
    virtual unsigned long  ClassID(void)const;

    // address=[0x153fdf0]
    virtual void  IncreaseAmmo(int);

    // address=[0x3d8b874]
    static unsigned long m_iClassID;

protected:
    // address=[0x153f010]
     CVikingCatapult(int,int,int,int,int,int,bool);

    // address=[0x153f060]
    virtual bool  EnoughAmmo(void)const;

    // address=[0x153f0d0]
    virtual unsigned int  AmmoAmount(void)const;

    // address=[0x153f130]
    virtual void  DecreaseAmmo(void);

};


#endif // CVIKINGCATAPULT_H
