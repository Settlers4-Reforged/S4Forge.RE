#ifndef CTROJANWARSHIP_H
#define CTROJANWARSHIP_H

class CTrojanWarShip : public CWarShip {
public:
    // address=[0x1402700]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15a1d70]
     CTrojanWarShip(std::istream &);

    // address=[0x15a1e30]
    virtual void  Store(std::ostream &);

    // address=[0x15a2440]
    virtual  ~CTrojanWarShip(void);

    // address=[0x15a26e0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bff0]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1e70]
     CTrojanWarShip(int,int,int,int,int,int,bool);

};


#endif // CTROJANWARSHIP_H
