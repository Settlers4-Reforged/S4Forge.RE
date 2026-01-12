#ifndef CVIKINGWARSHIP_H
#define CVIKINGWARSHIP_H

class CVikingWarShip : public CWarShip {
public:
    // address=[0x1402840]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15a1b30]
     CVikingWarShip(std::istream &);

    // address=[0x15a1bf0]
    virtual void  Store(std::ostream &);

    // address=[0x15a2460]
    virtual  ~CVikingWarShip(void);

    // address=[0x15a2700]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15a2740]
    virtual void  IncreaseAmmo(int);

    // address=[0x3d8bfec]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1c30]
     CVikingWarShip(int,int,int,int,int,int,bool);

    // address=[0x15a1c80]
    virtual bool  EnoughAmmo(void)const;

    // address=[0x15a1cf0]
    virtual unsigned int  AmmoAmount(void)const;

    // address=[0x15a1d50]
    virtual void  DecreaseAmmo(void);

};


#endif // CVIKINGWARSHIP_H
