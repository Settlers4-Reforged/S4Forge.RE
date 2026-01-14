#ifndef CROMANWARSHIP_H
#define CROMANWARSHIP_H

class CRomanWarShip : public CWarShip {
public:
    // address=[0x1401a80]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15a1890]
     CRomanWarShip(std::istream &);

    // address=[0x15a1950]
    virtual void  Store(std::ostream &);

    // address=[0x15a2420]
    virtual  ~CRomanWarShip(void);

    // address=[0x15a26c0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bfe4]
    static unsigned long m_iClassID;

protected:
    // address=[0x15a1990]
     CRomanWarShip(int,int,int,int,int,int,bool);

};


#endif // CROMANWARSHIP_H
